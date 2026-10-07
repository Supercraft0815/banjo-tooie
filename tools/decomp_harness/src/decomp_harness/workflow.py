from __future__ import annotations

import hashlib
import json
import os
from pathlib import Path
import shutil
import signal
import tempfile
import time
import uuid

from .build import Builder, snapshot, verify_rom
from .codex import CodexRunner
from .common import HarnessError, atomic_write, command, digest, git, save_json
from .context import context_pack, worker_prompt
from .guard import (candidate_guard, manifest, publish, recover_publications, repository_stamp,
                    source_diff, verify_worker_changes, worker_copy)
from .matching import instructions, score
from .scanner import scan
from .scheduler import advance, next_function, route


def new_run(root, prefix):
    path = root/'.decomp-agent/runs'/(prefix+'-'+uuid.uuid4().hex[:12])
    path.mkdir(parents=True, mode=0o700)
    return path


def probe_models(root, state, config, control, models, force=False, live_first=False):
    runner = CodexRunner()
    auth = runner.authenticate()
    verified = {}
    for index, model in enumerate(dict.fromkeys(models)):
        cache_key = 'probe:'+model
        cached = state.meta(cache_key)
        if not (force or live_first and index == 0) and cached and cached['version'] == runner.version and cached['account'] == runner.auth_id and time.time()-cached['time'] < config['probe_cache_hours']*3600:
            verified[model] = {**cached, 'cached': True}
            continue
        directory = new_run(root, 'probe')
        with tempfile.TemporaryDirectory(prefix='decomp-probe-') as folder:
            run_id = state.start_run(None, 'probe', model, 'medium', directory, folder)
            result = runner.run(cwd=Path(folder), prompt='Reply with exactly OK. Do not call tools or read files.',
                                model=model, effort='medium', directory=directory, timeout=90,
                                control=control, read_only=True,
                                on_start=lambda pid: state.finish_run(run_id, pid=pid))
        state.finish_run(run_id, ended=time.time(), outcome=result.outcome, exit_code=result.exit_code,
                         usage=json.dumps(result.usage), error=result.error)
        if result.outcome != 'ok' or result.message != 'OK':
            raise HarnessError(f'{model}: Codex ChatGPT probe failed ({result.outcome}). See {directory}. No model/API fallback. Configure an explicitly available model in .decomp-agent/config.toml.')
        verified[model] = {'time': time.time(), 'version': runner.version, 'account': runner.auth_id}
        state.set_meta(cache_key, verified[model])
    return auth, verified


def recover_workers(state):
    """Stop identifiable orphan process groups, never an unrelated reused PID."""
    for row in state.db.execute('SELECT * FROM runs WHERE ended IS NULL AND pid IS NOT NULL').fetchall():
        p = command(['ps', '-p', str(row['pid']), '-o', 'command='], check=False)
        command_line = p.stdout.decode(errors='replace')
        if row['path'] not in command_line or 'codex' not in command_line:
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


class Loop:
    def __init__(self, root, state, config, control, args):
        self.root, self.state, self.config, self.control, self.args = root, state, config, control, args
        self.calls = 0
        self.examined = 0
        self.matched = 0
        self.workspace = None
        self.expected_stamp = None
        self.runner = CodexRunner()

    def budget_reached(self):
        return self.control.stopped() or (self.args.max_attempts is not None and self.calls >= self.args.max_attempts)

    def run(self):
        recover_workers(self.state)
        recover_publications(self.root, self.state)
        self.state.recover()
        self.state.sync(scan(self.root))
        verify_rom(self.root)
        verify_rom(self.root, True)
        self.runner.authenticate()
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
            print('Checking isolated baseline (make check)...', flush=True)
            if not self.builder.regression(baseline_log):
                raise HarnessError(f'Baseline does not match; no Codex usage. See {baseline_log}')
            if repository_stamp(self.root) != baseline_stamp:
                raise HarnessError('Repository changed during baseline build; restart against the new state')
            self.expected_stamp = baseline_stamp
            initialize_knowledge(self.state)
            self.process_queue()
        finally:
            # Remove only the path created above, never a user-supplied path.
            shutil.rmtree(self.workspace)
        return {'functions': self.examined, 'codex_worker_runs': self.calls, 'matched': self.matched,
                'interrupted': self.control.stopped()}

    def process_queue(self):
        seen = set()
        while not self.budget_reached():
            if self.expected_stamp is not None and repository_stamp(self.root) != self.expected_stamp:
                raise HarnessError('Repository changed between functions; restart to build a fresh baseline')
            if self.args.max_functions is not None and self.examined >= self.args.max_functions:
                break
            if self.examined and (self.args.stop_after_current or (self.root/'.decomp-agent/stop-after-current').exists()):
                break
            function = next_function(self.state, self.args.difficulty, seen)
            if self.args.function:
                function = self.state.get(self.args.function) if not seen else None
                if function and function['status'] != 'pending':
                    raise HarnessError(f"{function['symbol']} is {function['status']}; use retry first")
            if not function:
                break
            seen.add(function['id'])
            self.examined += 1
            self.process_function(function)
            if self.state.get(function['id'])['status'] == 'matched':
                self.expected_stamp = repository_stamp(self.root)
        (self.root/'.decomp-agent/stop-after-current').unlink(missing_ok=True)

    def process_function(self, function):
        identity, source = function['id'], function['source']
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
        try:
            if self.resume_candidate(self.state.get(identity), original, reference_dump, reference):
                self.matched += 1
                return
            while not self.budget_reached():
                function = self.state.get(identity)
                stage, routing = route(function, self.config, self.args.model)
                self.state.update(identity, stage=stage)
                probe_models(self.root, self.state, self.config, self.control, [routing['model']], force=self.calls == 0)
                if self.budget_reached():
                    break
                result = self.attempt_with_retries(function, routing, original, reference_dump, reference)
                if result == 'matched':
                    self.matched += 1
                    return
                if result == 'stop':
                    return
                if result == 'budget':
                    break
                stage, used, total, exhausted = advance(self.state.get(identity), self.state.history(identity, 12), self.config, stage)
                self.state.update(identity, stage=stage, stage_attempts=used, cycle_attempts=total)
                if exhausted:
                    self.state.transition(identity, 'blocked', last_error='Escalation/stagnation budget exhausted; inspect best attempt and retry')
                    return
                self.state.transition(identity, 'improving')
            self.state.transition(identity, 'pending', last_error='Run budget/interruption; next run resumes persisted best candidate')
        finally:
            if self.state.get(identity)['status'] != 'matched':
                atomic_write(self.workspace/source, original)
                if not self.control.stopped():
                    self.builder.build(self.root/'.decomp-agent/logs/restore-baseline.log', source)
                    if not self.builder.regression(self.root/'.decomp-agent/logs/restore-check.log'):
                        raise HarnessError('Could not restore isolated baseline; stopping')

    def attempt_with_retries(self, function, routing, original, reference_dump, reference):
        for _ in range(self.config['technical_retries']+1):
            if self.budget_reached():
                return 'budget'
            result = self.attempt(self.state.get(function['id']), routing, original, reference_dump, reference)
            if result != 'technical':
                return result
        self.state.transition(function['id'], 'pending', last_error='Technical CLI failure; safely resumable on next run')
        raise HarnessError('Technical CLI retries exhausted; stopping to avoid wasting usage')

    def resume_candidate(self, function, original, reference_dump, reference):
        history = self.state.history(function['id'], 1)
        if not history or history[0]['outcome'] not in ('ok', 'matched'):
            return False
        directory = self.root/'.decomp-agent/runs'/history[0]['id']
        path = directory/'source-after.c'
        if not path.exists() or function['base_sha'] != hashlib.sha256(original).hexdigest():
            return False
        candidate = path.read_bytes()
        try:
            candidate_guard(original.decode(), candidate.decode(), function['symbol'])
        except (HarnessError, UnicodeError):
            return False
        print(f"Revalidating persisted candidate for {function['symbol']} without Codex...", flush=True)
        comparison = self.validate(function, candidate, directory, reference_dump, reference)
        if comparison is None:
            self.state.finish_run(history[0]['id'], outcome='compile_error', error='Resumed candidate did not compile')
            return False
        save_json(directory/'comparison.json', comparison)
        self.state.finish_run(history[0]['id'], outcome='matched' if comparison['exact'] else 'nonmatching', score=comparison['score'])
        if function['best_score'] is None or comparison['score'] > function['best_score']:
            self.state.update(function['id'], best_source=candidate, best_score=comparison['score'], best_run=history[0]['id'])
        if comparison['exact'] and not self.control.stopped():
            publish(self.root, self.state, function, original, candidate)
            return True
        return False

    def attempt(self, function, routing, original, reference_dump, reference):
        identity, source = function['id'], function['source']
        directory = new_run(self.root, 'attempt')
        stamp = repository_stamp(self.root)
        save_json(directory/'git-before.json', stamp)
        native = self.config['build']['backend'] == 'native'
        worker = worker_copy(self.workspace, function, native)
        try:
            atomic_write(worker/source, function['best_source'] or original)
            before = manifest(worker)
            pack = context_pack(self.root, function, self.state, self.config)
            atomic_write(self.root/'.decomp-agent/context'/f"{hashlib.sha256(identity.encode()).hexdigest()[:16]}.txt", pack)
            prompt = worker_prompt(function, pack, native)
            atomic_write(directory/'source-before.c', (worker/source).read_bytes())
            self.state.transition(identity, 'attempting')
            run_id = self.state.start_run(identity, 'worker', routing['model'], routing['effort'], directory, worker)
            save_json(directory/'metadata.json', {'function': identity, **routing, 'started': time.time(), 'worker': str(worker)})
            self.calls += 1
            print(f"{function['symbol']}: {routing['model']} {routing['effort']} (worker run {self.calls})", flush=True)
            result = self.runner.run(cwd=worker, prompt=prompt, model=routing['model'], effort=routing['effort'],
                                     directory=directory, timeout=self.config['worker_timeout'], control=self.control,
                                     schema=Path(__file__).with_name('worker.schema.json'),
                                     on_start=lambda pid: self.state.finish_run(run_id, pid=pid))
            self.state.finish_run(run_id, ended=time.time(), outcome=result.outcome, exit_code=result.exit_code,
                                  usage=json.dumps(result.usage), error=result.error)
            after_stamp = repository_stamp(self.root)
            save_json(directory/'git-after.json', after_stamp)
            if (worker/source).is_file() and not (worker/source).is_symlink():
                attempted = self.runner.redact((worker/source).read_text(errors='replace'))
                atomic_write(directory/'source-after.c', attempted)
                atomic_write(directory/'source.diff', source_diff(original.decode(), attempted, source))
            if after_stamp != stamp:
                self.state.transition(identity, 'needs_human', last_error='Repository changed during worker; candidate quarantined')
                raise HarnessError('Concurrent repository changes detected; no publication')
            if result.outcome in ('auth_error', 'quota_error', 'model_error', 'interrupted'):
                self.state.transition(identity, 'pending', last_error=result.outcome)
                raise HarnessError(f'Codex {result.outcome}; run can resume, no fallback')
            if result.outcome in ('technical_error', 'timeout'):
                return 'technical'
            if result.outcome != 'ok':
                self.state.update(identity, last_error='Agent output invalid')
                return 'improve'
            try:
                verify_worker_changes(worker, before, source)
                candidate = (worker/source).read_bytes()
                if self.runner.redact(candidate.decode()) != candidate.decode():
                    raise HarnessError('Candidate contains credential material; rejected without persistence')
                replacement = candidate_guard(original.decode(), candidate.decode(), function['symbol'])
            except (HarnessError, UnicodeError) as e:
                self.state.finish_run(run_id, outcome='guard_rejected', error=str(e))
                self.state.transition(identity, 'needs_human', last_error=str(e))
                return 'stop'
            atomic_write(directory/'source-after.c', candidate)
            atomic_write(directory/'source.diff', source_diff(original.decode(), candidate.decode(), source))
            comparison = self.validate(function, candidate, directory, reference_dump, reference)
            if comparison is None:
                self.state.finish_run(run_id, outcome='compile_error', error='See compiler.log')
                self.state.update(identity, last_error=(directory/'compiler.log').read_text(errors='replace')[-3000:])
                return 'improve'
            previous = function['best_score']
            comparison['delta'] = comparison['score'] - (previous if previous is not None else 0)
            save_json(directory/'comparison.json', comparison)
            self.state.finish_run(run_id, outcome='matched' if comparison['exact'] else 'nonmatching',
                                  score=comparison['score'], delta=comparison['delta'],
                                  differences=comparison['different_instructions'], first_diff=json.dumps(comparison['first_diff']),
                                  last_diffs=json.dumps(comparison['last_diffs']))
            if previous is None or comparison['score'] > previous or comparison['exact']:
                self.state.update(identity, best_source=candidate, best_score=comparison['score'], best_run=run_id)
            print(f"  score {comparison['score']:.2f}, diff instructions {comparison['different_instructions']}, ROM exact={comparison['exact']}", flush=True)
            if not comparison['exact']:
                return 'improve'
            if self.control.stopped():
                self.state.transition(identity, 'pending', last_error='Validated match retained; interrupted before publication')
                return 'stop'
            if repository_stamp(self.root) != stamp:
                raise HarnessError('Repository changed during validation; no publication')
            commit = publish(self.root, self.state, function, original, candidate)
            atomic_write(directory/'commit.txt', commit+'\n')
            if isinstance(result.message, dict):
                for note in result.message.get('knowledge', [])[:4]:
                    if isinstance(note, str):
                        self.state.note(function['segment']+' IDO '+function['symbol'], self.runner.redact(note), commit)
            self.state.note(function['segment']+' '+function['symbol'], 'Matched source pattern:\n'+replacement[:900], commit)
            return 'matched'
        finally:
            shutil.rmtree(worker)

    def validate(self, function, candidate, directory, reference_dump, reference):
        atomic_write(self.workspace/function['source'], candidate)
        atomic_write(directory/'expected.asm', reference_dump)
        if self.builder.object_build(function['source'], directory/'compiler.log'):
            return None
        dump = self.builder.disassemble(function['source'], function['symbol'])
        atomic_write(directory/'actual.asm', dump)
        comparison = score(reference, instructions(dump, function['symbol']))
        # Always verify the full output; normalized equality is never sufficient.
        comparison['exact'] = self.builder.regression(directory/'regression.log')
        return comparison
