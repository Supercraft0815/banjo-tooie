from __future__ import annotations

import hashlib
from concurrent.futures import ThreadPoolExecutor, wait, FIRST_COMPLETED
from dataclasses import dataclass
import json
import os
from pathlib import Path
import shutil
import signal
import tempfile
import time
import threading
import uuid

from .build import Builder, snapshot, verify_rom
from .codex import CodexRunner, Redactor
from .common import HarnessError, atomic_write, command, git, save_json, validate_stage
from .context import context_pack, worker_prompt
from .guard import (candidate_guard, manifest, publish, recover_publications, repository_stamp,
                    source_diff, verify_worker_changes, worker_copy, dispose_worker)
from .matching import instructions, score
from .scanner import scan
from .scheduler import advance, next_function, route, resources
from .state import State
from .patterns import candidates, candidate_source, remember, seed_matches


def new_run(root, prefix):
    path = root/'.decomp-agent/runs'/(prefix+'-'+uuid.uuid4().hex[:12])
    path.mkdir(parents=True, mode=0o700)
    return path


def runner_for(provider):
    if provider == 'codex':
        return CodexRunner()
    if provider == 'claude':
        from .claude import ClaudeRunner
        return ClaudeRunner()
    raise HarnessError('Unknown CLI provider; no fallback')


def configured_models(config):
    models = list(config['routing'])
    if config['easy_model']['enabled']:
        models.insert(0, config['easy_model'])
    return models


def probe_models(root, state, config, control, models, force=False, live_first=False):
    verified, auth, runners = {}, {}, {}
    for index, item in enumerate(models):
        item = {'model': item, 'effort': 'medium'} if isinstance(item, str) else item
        model, provider = item['model'], item.get('provider', 'codex')
        if provider == 'claude' and not config['claude_enabled']:
            raise HarnessError('Claude is disabled; explicitly configure claude_enabled=true')
        key = model if provider == 'codex' else provider+':'+model
        if key in verified:
            continue
        if provider not in runners:
            runners[provider] = runner_for(provider)
            auth[provider] = runners[provider].authenticate()
        runner = runners[provider]
        cached = state.meta('probe:'+key)
        if not (force or live_first and index == 0) and cached and cached['version'] == runner.version and cached['account'] == runner.auth_id and time.time()-cached['time'] < config['probe_cache_hours']*3600:
            verified[key] = {**cached, 'cached': True}
            continue
        directory = new_run(root, 'probe')
        with tempfile.TemporaryDirectory(prefix='decomp-probe-') as folder:
            run_id = state.start_run(None, 'probe', model, item['effort'], directory, folder)
            state.finish_run(run_id, provider=provider)
            result = runner.run(cwd=Path(folder), prompt='Reply with exactly OK. Do not call tools or read files.',
                                model=model, effort=item['effort'], directory=directory, timeout=90,
                                control=control, read_only=True,
                                on_start=lambda pid: state.finish_run(run_id, pid=pid))
        state.finish_run(run_id, ended=time.time(), outcome=result.outcome, exit_code=result.exit_code,
                         usage=json.dumps(result.usage), error=result.error)
        if result.outcome != 'ok' or result.message != 'OK':
            raise HarnessError(f'{provider}/{model}: subscription probe failed ({result.outcome}). See {directory}. No provider/API fallback; configure an explicitly available model.')
        verified[key] = {'time': time.time(), 'version': runner.version, 'account': runner.auth_id}
        state.set_meta('probe:'+key, verified[key])
    return auth, verified


def recover_workers(state):
    """Stop identifiable orphan process groups, never an unrelated reused PID."""
    for row in state.db.execute('SELECT * FROM runs WHERE ended IS NULL AND pid IS NOT NULL').fetchall():
        p = command(['ps', '-p', str(row['pid']), '-o', 'command='], check=False)
        command_line = p.stdout.decode(errors='replace')
        if row['path'] not in command_line or not any(name in command_line for name in ('codex', 'claude')):
            continue
        try:
            os.killpg(row['pid'], signal.SIGTERM)
        except ProcessLookupError:
            continue
        for _ in range(20):
            if command(['ps', '-p', str(row['pid']), '-o', 'command='], check=False).returncode:
                break
            time.sleep(0.1)
        else:
            try:
                os.killpg(row['pid'], signal.SIGKILL)
            except ProcessLookupError:
                pass


def initialize_knowledge(state):
    state.note('IDO compiler stack registers', 'IDO 5.3 uses -O2 -mips2 -G 0. Preserve signedness, expression order, declaration order and float literal types; they affect register allocation and instruction selection.', 'repository Makefile')
    state.note('GLOBAL_ASM validation relocations', 'Object scores are guidance. Relocations, padding, rodata and overlay headers are accepted only after make check and an independent full decompressed-ROM hash match.', 'harness invariant')


def save_guarded_candidate(worker, before, original, function, directory):
    verify_worker_changes(worker, before, function['source'])
    candidate = (worker/function['source']).read_bytes()
    if Redactor()(candidate.decode()) != candidate.decode():
        raise HarnessError('Credential-like material in recovered candidate')
    candidate_guard(original.decode(), candidate.decode(), function['symbol'])
    atomic_write(directory/'source-after.c', candidate)
    save_json(directory/'candidate-guard.json', {'base_sha': hashlib.sha256(original).hexdigest(),
                                                'candidate_sha': hashlib.sha256(candidate).hexdigest()})


def recover_candidates(root, state):
    """Salvage an edit after a parent crash, only with its persisted file manifest."""
    for row in state.db.execute('SELECT * FROM runs WHERE ended IS NULL AND worker IS NOT NULL AND function_id IS NOT NULL').fetchall():
        worker, directory = Path(row['worker']), Path(row['path'])
        record = directory/'worker-before.json'
        function = state.get(row['function_id'])
        try:
            if (worker/'.harness-worker').read_text() != function['id'] or not record.is_file():
                continue
            original = (root/function['source']).read_bytes()
            if hashlib.sha256(original).hexdigest() != function['base_sha']:
                continue
            before = {k: tuple(v) for k, v in json.loads(record.read_text()).items()}
            save_guarded_candidate(worker, before, original, function, directory)
        except (HarnessError, OSError, ValueError, UnicodeError):
            continue


@dataclass(frozen=True)
class Target:
    function: dict
    original: bytes
    reference_dump: str
    reference: list


class Loop:
    def __init__(self, root, state, config, control, args):
        self.root, self.state, self.config, self.control, self.args = root, state, config, control, args
        self.calls = self.examined = self.matched = self.local_matches = 0
        self.workspace = self.expected_stamp = None
        self.runners = {}
        self.coordinator = self
        # ponytail: one compiler/publication gate; shard only if builds become the bottleneck.
        self.gate = threading.RLock()
        self.count_lock = threading.Lock()
        self.probe_lock = threading.Lock()
        self.probed = set()
        self.abort = threading.Event()

    def budget_reached(self):
        c = self.coordinator
        return self.control.stopped() or (self.args.max_attempts is not None and c.calls >= self.args.max_attempts)

    def claim_attempt(self):
        c = self.coordinator
        with c.count_lock:
            if self.budget_reached():
                return None
            c.calls += 1
            return c.calls

    def check_repository(self):
        stamp = repository_stamp(self.root)
        if self.coordinator.expected_stamp is not None and stamp != self.coordinator.expected_stamp:
            raise HarnessError('Repository changed outside the harness; candidates retained, no publication')
        return stamp

    def get_runner(self, provider):
        if provider == 'claude' and not self.config['claude_enabled']:
            raise HarnessError('Claude is disabled; no provider fallback')
        if provider not in self.runners:
            self.runners[provider] = runner_for(provider)
        return self.runners[provider]

    def run(self):
        recover_workers(self.state)
        recover_candidates(self.root, self.state)
        recover_publications(self.root, self.state)
        self.state.recover()
        self.state.sync(scan(self.root))
        verify_rom(self.root)
        verify_rom(self.root, True)
        if not self.args.local_only:
            self.get_runner('codex').authenticate()
        if git(self.root, 'symbolic-ref', '--short', 'HEAD') in ('main', 'master'):
            raise HarnessError('Create a dedicated decomp branch before running')
        if not git(self.root, 'config', 'user.name', check=False) or not git(self.root, 'config', 'user.email', check=False):
            raise HarnessError('Configure git user.name and user.email before automatic match commits')
        baseline_stamp = repository_stamp(self.root)
        self.workspace = snapshot(self.root)
        self.state.set_meta('last_build_workspace', str(self.workspace))
        self.builder = Builder(self.workspace, self.config, self.control)
        try:
            baseline_log = self.root/'.decomp-agent/logs/run-baseline.log'
            print(f'Checking isolated baseline (make check). Build output: {baseline_log}', flush=True)
            if not self.builder.regression(baseline_log):
                raise HarnessError(f'Baseline does not match; no model usage. See {baseline_log}')
            if repository_stamp(self.root) != baseline_stamp:
                raise HarnessError('Repository changed during baseline build; restart against the new state')
            self.expected_stamp = baseline_stamp
            initialize_knowledge(self.state)
            seed_matches(self.root, self.state)
            if self.config['concurrency'] == 1:
                self.process_queue()
            else:
                self.process_parallel()
        finally:
            shutil.rmtree(self.workspace)
        return {'functions': self.examined, 'model_worker_runs': self.calls, 'matched': self.matched,
                'local_matches': self.local_matches, 'concurrency': self.config['concurrency'],
                'interrupted': self.control.stopped()}

    def select_function(self, seen, busy=()):
        if self.args.max_functions is not None and self.examined >= self.args.max_functions:
            return None
        if self.examined and (self.args.stop_after_current or (self.root/'.decomp-agent/stop-after-current').exists()):
            return None
        function = next_function(self.state, self.args.difficulty, seen, busy)
        if self.args.function:
            function = self.state.get(self.args.function) if not seen else None
            if function and function['status'] != 'pending':
                raise HarnessError(f"{function['symbol']} is {function['status']}; use retry first")
        return function

    def process_queue(self):
        seen = set()
        while not self.budget_reached():
            self.check_repository()
            function = self.select_function(seen)
            if not function:
                break
            seen.add(function['id'])
            self.examined += 1
            self.process_function(function)
        (self.root/'.decomp-agent/stop-after-current').unlink(missing_ok=True)

    def process_parallel(self):
        # SQLite connections are thread-owned. Only the gate holder builds/publishes.
        seen, active = set(), {}
        with ThreadPoolExecutor(max_workers=self.config['concurrency'], thread_name_prefix='decomp') as pool:
            try:
                while active or not self.budget_reached():
                    while len(active) < self.config['concurrency'] and not self.budget_reached():
                        busy = set().union(*(resources(f) for f in active.values())) if active else set()
                        with self.gate:
                            self.check_repository()
                            function = self.select_function(seen, busy)
                        if not function:
                            break
                        seen.add(function['id'])
                        self.examined += 1
                        active[pool.submit(self.parallel_function, function)] = function
                    if not active:
                        break
                    done, _ = wait(active, timeout=0.2, return_when=FIRST_COMPLETED)
                    for future in done:
                        active.pop(future)
                        future.result()
            except BaseException:
                self.abort.set()
                raise
            finally:
                if self.control.stopped():
                    self.abort.set()
        (self.root/'.decomp-agent/stop-after-current').unlink(missing_ok=True)

    def parallel_function(self, function):
        from .common import Control
        state = State(self.root/'.decomp-agent/state.db')
        control = Control()
        control.stopped = lambda: self.control.stopped() or self.abort.is_set()
        child = Loop(self.root, state, self.config, control, self.args)
        child.coordinator, child.gate = self, self.gate
        child.workspace = self.workspace
        child.builder = Builder(self.workspace, self.config, control)
        try:
            child.process_function(function)
        finally:
            state.close()

    def process_function(self, function):
        identity, source = function['id'], function['source']
        with self.gate:
            self.check_repository()
            original = (self.root/source).read_bytes()
            source_sha = hashlib.sha256(original).hexdigest()
            if git(self.root, 'status', '--porcelain=v1', '--', source):
                self.state.transition(identity, 'blocked', last_error='Uncommitted target changes; untouched. Commit them, then retry.')
                return
            if json.loads(function['features']).get('kind') != 'function':
                self.state.transition(identity, 'blocked', last_error='No function ASM; run init --setup and scan')
                return
            self.state.transition(identity, 'analyzing')
            if function['base_sha'] != source_sha:
                self.state.update(identity, best_source=None, best_score=None, best_run=None, base_sha=source_sha)
            reference_dump = self.builder.disassemble(source, function['symbol'])
            reference = instructions(reference_dump, function['symbol'])
            target = Target(function, original, reference_dump, reference)
        try:
            if self.resume_candidate(self.state.get(identity), target):
                self.count_match()
                return
            if self.config['local_patterns'] and not self.args.no_local:
                if self.try_local(self.state.get(identity), target):
                    self.count_match(local=True)
                    return
            if self.args.local_only:
                self.state.transition(identity, 'pending', last_error='No local candidate matched; normal run may use a model')
                return
            self.improve(identity, target)
        except BaseException:
            if self.state.get(identity)['status'] in ('analyzing', 'attempting', 'improving'):
                self.state.transition(identity, 'pending', last_error='Interrupted/error; persisted candidate will be revalidated')
            raise

    def improve(self, identity, target):
        while not self.budget_reached():
            function = self.state.get(identity)
            stage, routing = route(function, self.config, self.args.model)
            if self.args.provider:
                routing['provider'] = self.args.provider
            validate_stage(routing, self.config['claude_enabled'])
            self.state.update(identity, stage=stage)
            key = (routing.get('provider', 'codex'), routing['model'])
            with self.coordinator.probe_lock:
                if key not in self.coordinator.probed:
                    probe_models(self.root, self.state, self.config, self.control, [routing],
                                 force=not self.coordinator.probed)
                    self.coordinator.probed.add(key)
            if self.budget_reached():
                break
            result = self.attempt_with_retries(function, routing, target)
            if result == 'matched':
                self.count_match()
                return
            if result == 'stop':
                return
            if result == 'budget':
                break
            new_stage, used, total, exhausted = advance(self.state.get(identity), self.state.history(identity, 12), self.config, stage)
            self.state.update(identity, stage=new_stage, stage_attempts=used, cycle_attempts=total,
                              initial_done=int(stage == -2 and new_stage != -2 or function.get('initial_done', 0)))
            if exhausted:
                self.state.transition(identity, 'blocked', last_error='Escalation/stagnation budget exhausted; inspect best attempt and retry')
                return
            self.state.transition(identity, 'improving')
        self.state.transition(identity, 'pending', last_error='Run budget/interruption; next run resumes persisted best candidate')

    def count_match(self, local=False):
        with self.coordinator.count_lock:
            self.coordinator.matched += 1
            self.coordinator.local_matches += int(local)

    def try_local(self, function, target):
        original = target.original
        for origin, code in candidates(self.root, function, self.state):
            if self.control.stopped():
                break
            candidate = candidate_source(original.decode(), function['symbol'], code)
            key = hashlib.sha256(candidate + (function['asm_sha'] or '').encode()).hexdigest()
            if self.state.db.execute('SELECT 1 FROM local_trials WHERE function_id=? AND candidate_sha=?', (function['id'], key)).fetchone():
                continue
            directory = new_run(self.root, 'local')
            run_id = self.state.start_run(function['id'], 'local', origin, 'none', directory)
            self.state.finish_run(run_id, provider='local')
            self.state.transition(function['id'], 'attempting', model='local')
            atomic_write(directory/'source-before.c', original)
            atomic_write(directory/'source-after.c', candidate)
            atomic_write(directory/'source.diff', source_diff(original.decode(), candidate.decode(), function['source']))
            self.state.finish_run(run_id, outcome='ok')
            print(f"{function['symbol']}: local {origin} (no model usage)", flush=True)
            outcome = self.accept_candidate(target, candidate, directory)
            self.state.finish_run(run_id, ended=time.time())
            with self.state.db:
                self.state.db.execute('INSERT OR REPLACE INTO local_trials VALUES (?,?,?)', (function['id'], key, outcome))
            if outcome == 'matched':
                return True
            if outcome == 'stop':
                break
        return False

    def attempt_with_retries(self, function, routing, target):
        for _ in range(self.config['technical_retries']+1):
            if self.budget_reached():
                return 'budget'
            result = self.attempt(self.state.get(function['id']), routing, target)
            if result != 'technical':
                return result
        self.state.transition(function['id'], 'pending', last_error='Technical CLI failure; safely resumable on next run')
        raise HarnessError('Technical CLI retries exhausted; stopping to avoid wasting usage')

    def resume_candidate(self, function, target):
        original = target.original
        history = self.state.history(function['id'], 1)
        if not history or history[0]['outcome'] not in ('ok', 'matched', 'interrupted'):
            return False
        directory = self.root/'.decomp-agent/runs'/history[0]['id']
        path = directory/'source-after.c'
        if not path.exists() or function['base_sha'] != hashlib.sha256(original).hexdigest():
            return False
        candidate = path.read_bytes()
        if history[0]['outcome'] == 'interrupted':
            guard = directory/'candidate-guard.json'
            if not guard.is_file():
                return False
            proof = json.loads(guard.read_text())
            if proof != {'base_sha': hashlib.sha256(original).hexdigest(), 'candidate_sha': hashlib.sha256(candidate).hexdigest()}:
                return False
        try:
            candidate_guard(original.decode(), candidate.decode(), function['symbol'])
        except (HarnessError, UnicodeError):
            return False
        print(f"Revalidating persisted candidate for {function['symbol']} without inference...", flush=True)
        self.state.transition(function['id'], 'attempting')
        return self.accept_candidate(target, candidate, directory) == 'matched'

    def attempt(self, function, routing, target):
        original = target.original
        identity, source = function['id'], function['source']
        provider = routing.get('provider', 'codex')
        runner = self.get_runner(provider)
        directory = new_run(self.root, 'attempt')
        native = self.config['build']['backend'] == 'native'
        with self.gate:
            stamp = self.check_repository()
            worker = worker_copy(self.workspace, function, native, worktree=self.config['concurrency'] > 1)
        try:
            atomic_write(worker/source, function['best_source'] or original)
            before = manifest(worker)
            save_json(directory/'worker-before.json', before)
            pack = context_pack(self.root, function, self.state, self.config)
            atomic_write(self.root/'.decomp-agent/context'/f"{hashlib.sha256(identity.encode()).hexdigest()[:16]}.txt", pack)
            prompt = worker_prompt(function, pack, native)
            atomic_write(directory/'source-before.c', (worker/source).read_bytes())
            save_json(directory/'git-before.json', stamp)
            save_json(directory/'metadata.json', {'function': identity, **routing, 'provider': provider,
                                                'started': time.time(), 'worker': str(worker)})
            number = self.claim_attempt()
            if number is None:
                return 'budget'
            self.state.transition(identity, 'attempting')
            run_id = self.state.start_run(identity, 'worker', routing['model'], routing['effort'], directory, worker)
            self.state.finish_run(run_id, provider=provider)
            print(f"{function['symbol']}: {provider}/{routing['model']} {routing['effort']} (worker run {number})", flush=True)
            result = runner.run(cwd=worker, prompt=prompt, model=routing['model'], effort=routing['effort'],
                                directory=directory, timeout=self.config['worker_timeout'], control=self.control,
                                schema=Path(__file__).with_name('worker.schema.json'),
                                on_start=lambda pid: self.state.finish_run(run_id, pid=pid))
            self.state.finish_run(run_id, ended=time.time(), outcome=result.outcome, exit_code=result.exit_code,
                                  usage=json.dumps(result.usage), error=result.error)
            if (worker/source).is_file() and not (worker/source).is_symlink():
                attempted = runner.redact((worker/source).read_text(errors='replace'))
                atomic_write(directory/'source-after.c', attempted)
                atomic_write(directory/'source.diff', source_diff(original.decode(), attempted, source))
            with self.gate:
                save_json(directory/'git-after.json', self.check_repository())
            if result.outcome in ('auth_error', 'quota_error', 'model_error', 'interrupted'):
                if result.outcome == 'interrupted':
                    try:
                        candidate = (worker/source).read_text()
                        if runner.redact(candidate) == candidate:
                            save_guarded_candidate(worker, before, original, function, directory)
                    except (HarnessError, OSError, UnicodeError) as e:
                        save_json(directory/'candidate-guard.json', {'rejected': runner.redact(str(e))})
                self.state.transition(identity, 'pending', last_error=result.outcome)
                raise HarnessError(f'{provider} {result.outcome}; run can resume, no fallback')
            if result.outcome in ('technical_error', 'timeout'):
                return 'technical'
            if result.outcome != 'ok':
                self.state.update(identity, last_error='Agent output invalid')
                return 'improve'
            try:
                verify_worker_changes(worker, before, source)
                candidate = (worker/source).read_bytes()
                if runner.redact(candidate.decode()) != candidate.decode():
                    raise HarnessError('Candidate contains credential material; rejected without persistence')
                candidate_guard(original.decode(), candidate.decode(), function['symbol'])
            except (HarnessError, UnicodeError) as e:
                self.state.finish_run(run_id, outcome='guard_rejected', error=str(e))
                self.state.transition(identity, 'needs_human', last_error=str(e))
                return 'stop'
            return self.accept_candidate(target, candidate, directory, result.message)
        finally:
            dispose_worker(worker)

    def accept_candidate(self, target, candidate, directory, message=None):
        function, original, run_id = target.function, target.original, directory.name
        with self.gate:
            self.check_repository()
            replacement = candidate_guard(original.decode(), candidate.decode(), function['symbol'])
            atomic_write(directory/'source-after.c', candidate)
            try:
                comparison = self.validate(target, candidate, directory)
                if comparison is None:
                    self.state.finish_run(run_id, outcome='compile_error', error='See compiler.log')
                    self.state.update(function['id'], last_error=(directory/'compiler.log').read_text(errors='replace')[-3000:])
                    return 'improve'
                previous = self.state.get(function['id'])['best_score']
                comparison['delta'] = comparison['score'] - (previous if previous is not None else 0)
                save_json(directory/'comparison.json', comparison)
                self.state.finish_run(run_id, outcome='matched' if comparison['exact'] else 'nonmatching',
                                      score=comparison['score'], delta=comparison['delta'],
                                      differences=comparison['different_instructions'], first_diff=json.dumps(comparison['first_diff']),
                                      last_diffs=json.dumps(comparison['last_diffs']))
                if previous is None or comparison['score'] > previous or comparison['exact']:
                    self.state.update(function['id'], best_source=candidate, best_score=comparison['score'], best_run=run_id)
                print(f"  {function['symbol']}: score {comparison['score']:.2f}, diff instructions {comparison['different_instructions']}, ROM exact={comparison['exact']}", flush=True)
                if not comparison['exact']:
                    return 'improve'
                if self.control.stopped():
                    self.state.transition(function['id'], 'pending', last_error='Validated match retained; interrupted before publication')
                    return 'stop'
                self.check_repository()
                commit = publish(self.root, self.state, function, original, candidate)
                self.coordinator.expected_stamp = repository_stamp(self.root)
                atomic_write(directory/'commit.txt', commit+'\n')
                remember(self.root, self.state, function, replacement, commit)
                if isinstance(message, dict):
                    for note in message.get('knowledge', [])[:4]:
                        if isinstance(note, str):
                            self.state.note(function['segment']+' IDO '+function['symbol'], note, commit)
                self.state.note(function['segment']+' '+function['symbol'], 'Matched source pattern:\n'+replacement[:900], commit)
                return 'matched'
            finally:
                if self.state.get(function['id'])['status'] != 'matched':
                    atomic_write(self.workspace/function['source'], original)
                    if not self.control.stopped():
                        self.builder.build(directory/'restore-baseline.log', function['source'])
                        if not self.builder.regression(directory/'restore-check.log'):
                            raise HarnessError('Could not restore isolated baseline; stopping')

    def validate(self, target, candidate, directory):
        function = target.function
        atomic_write(self.workspace/function['source'], candidate)
        atomic_write(directory/'expected.asm', target.reference_dump)
        if self.builder.object_build(function['source'], directory/'compiler.log'):
            return None
        dump = self.builder.disassemble(function['source'], function['symbol'])
        atomic_write(directory/'actual.asm', dump)
        comparison = score(target.reference, instructions(dump, function['symbol']))
        comparison['exact'] = self.builder.regression(directory/'regression.log')
        return comparison
