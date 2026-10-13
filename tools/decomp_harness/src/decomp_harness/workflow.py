from __future__ import annotations

import hashlib
from concurrent.futures import ThreadPoolExecutor, wait, FIRST_COMPLETED
from contextlib import ExitStack, nullcontext
from dataclasses import dataclass, replace, field
import json
import queue
import os
from pathlib import Path
import shutil
import signal
import tempfile
import time
import threading
import uuid

from .build import Builder, clone, verify_rom
from . import cache
from .codex import CodexRunner, Redactor
from .common import HarnessError, atomic_write, command, git, save_json, validate_stage
from .context import context_pack, worker_prompt
from .guard import (candidate_guard, manifest, mark_targets, publish, recover_publications, repository_stamp,
                    source_diff, split_targets, verify_worker_changes, worker_copy, dispose_worker)
from .local_tools import m2c_candidates, m2c_draft, run_permuter
from .matching import instructions, score, worth_rom_check
from . import service
from .repairs import repair_scope, guard_candidate, save_support, load_support, recheck_key, worker_candidate, seed_worker, rebase_source
from .scanner import scan
from .scheduler import advance, next_function, route, resources
from .state import State
from .patterns import untried_candidates, candidate_source, local_plan, m2c_key, quirk_candidates, trial_key, remember, seed_matches, refresh_solutions


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


def save_guarded_candidate(worker, before, original, function, directory, scope=None):
    scope = scope or {}
    candidate, support = worker_candidate(worker, before, function, original, scope, Redactor())
    save_support(directory, scope, support)
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
            saved = directory/'support-before.json'
            scope = {p: text.encode() for p, text in json.loads(saved.read_text()).items()} if saved.is_file() else {}
            if any((root/p).read_bytes() != value for p, value in scope.items()):
                continue
            save_guarded_candidate(worker, before, original, function, directory, scope)
        except (HarnessError, OSError, ValueError, UnicodeError):
            continue


@dataclass(frozen=True)
class Target:
    function: dict
    original: bytes
    reference_dump: str
    reference: list
    baseline_saved: bool = False
    length: int | None = None
    support: dict = field(default_factory=dict)


class Loop:
    def __init__(self, root, state, config, control, args):
        self.root, self.state, self.config, self.control, self.args = root, state, config, control, args
        self.calls = self.examined = self.matched = self.local_matches = 0
        self.workspace = self.expected_stamp = None
        self.runners = {}
        self.coordinator = self
        # Repository snapshots/commits use the short gate. ROM builds use their own
        # serial gate so private probes and scheduling can continue during linking.
        self.gate = threading.RLock()
        self.publication_gate = threading.RLock()
        self.baseline_builder = None
        self.lanes = None
        self.published, self.lane_seen = [], {}
        self.count_lock = threading.Lock()
        self.probe_lock = threading.Lock()
        self.probed = set()
        self.abort = threading.Event()
        self.local_queue = None
        self.local_scan = None

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
        initialize_knowledge(self.state)
        seed_matches(self.root, self.state)
        if self.args.local_only:
            self.local_scan = local_plan(self.root, self.state, self.args.difficulty, self.args.function,
                                         m2c=self.config['m2c'] and (self.root/'tools/m2c/m2c.py').is_file())
            self.local_queue = self.local_scan.pop('plan')
            print(f"Local scan: {self.local_scan['scanned_functions']} functions, "
                  f"{len(self.local_queue)} with untried local/resumable candidates (no model usage).", flush=True)
        if self.local_queue == [] or self.budget_reached() or (self.root/'.decomp-agent/stop-after-current').exists():
            (self.root/'.decomp-agent/stop-after-current').unlink(missing_ok=True)
            return self.result()
        verify_rom(self.root)
        verify_rom(self.root, True)
        if not self.args.local_only:
            self.get_runner('codex').authenticate()
        if git(self.root, 'symbolic-ref', '--short', 'HEAD') in ('main', 'master'):
            raise HarnessError('Create a dedicated decomp branch before running')
        if not git(self.root, 'config', 'user.name', check=False) or not git(self.root, 'config', 'user.email', check=False):
            raise HarnessError('Configure git user.name and user.email before automatic match commits')
        baseline_stamp = repository_stamp(self.root)
        self.workspace, warm = cache.prepare(self.root, self.config)
        self.state.set_meta('last_build_workspace', str(self.workspace))
        self.builder = Builder(self.workspace, self.config, self.control)
        try:
            self.builder.start()
            baseline_log = self.root/'.decomp-agent/logs/run-baseline.log'
            print(f"Checking isolated baseline (make check; {'verified build cache' if warm else 'fresh build'}). "
                  f'Build output: {baseline_log}', flush=True)
            if not self.builder.regression(baseline_log):
                raise HarnessError(f'Baseline does not match; no model usage. See {baseline_log}')
            if repository_stamp(self.root) != baseline_stamp:
                raise HarnessError('Repository changed during baseline build; restart against the new state')
            self.expected_stamp = baseline_stamp
            if self.config['concurrency'] == 1:
                self.process_queue()
            else:
                self.process_parallel()
            if not self.control.stopped():
                self.check_repository()
                cache.retain(self.root, self.workspace, self.config)
        finally:
            self.builder.close()
            if self.workspace.exists():
                shutil.rmtree(self.workspace)
        return self.result()

    def result(self):
        return {'functions': self.examined, 'model_worker_runs': self.calls, 'matched': self.matched,
                'local_matches': self.local_matches, 'concurrency': self.config['concurrency'],
                'local_scan': self.local_scan,
                'interrupted': self.control.stopped()}

    def select_function(self, seen, busy=()):
        if self.args.max_functions is not None and self.examined >= self.args.max_functions:
            return None
        if (self.examined and self.args.stop_after_current) or (self.root/'.decomp-agent/stop-after-current').exists():
            return None
        if self.local_queue is not None:
            choice = next((f for f in self.local_queue if f['function'] not in seen and not resources(f) & set(busy)), None)
            return self.state.get(choice['function']) if choice else None
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
        # SQLite connections are thread-owned. The immutable reference never sees
        # candidate writes; only publication_gate owns the mutable ROM workspace.
        seen, active = set(), {}
        self.lanes = queue.Queue()
        self.published, self.lane_seen = [], {}
        print(f"Cloning {self.config['concurrency']} private build lanes for parallel compiles...", flush=True)
        try:
            with ExitStack() as cleanup:
                for index in range(self.config['concurrency'] + 1):
                    lane = clone(self.workspace)
                    cleanup.callback(shutil.rmtree, lane, ignore_errors=True)
                    builder = Builder(lane, self.config, self.control)
                    cleanup.callback(builder.close)
                    builder.start()
                    if index == 0:
                        self.baseline_builder = builder
                    else:
                        self.lanes.put((lane, builder))
                self.run_pool(seen, active)
        finally:
            self.lanes = self.baseline_builder = None
        (self.root/'.decomp-agent/stop-after-current').unlink(missing_ok=True)

    def run_pool(self, seen, active):
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

    def parallel_function(self, function):
        from .common import Control
        state = State(self.root/'.decomp-agent/state.db')
        control = Control()
        control.stopped = lambda: self.control.stopped() or self.abort.is_set()
        child = Loop(self.root, state, self.config, control, self.args)
        child.coordinator, child.gate = self, self.gate
        child.workspace = self.workspace
        child.builder = self.builder
        try:
            child.process_function(function)
        finally:
            state.close()

    def process_function(self, function):
        target = self.prepare(function)
        if target is None:
            return
        identity = function['id']
        try:
            if self.local_stages(target):
                return
            if self.args.local_only:
                self.state.transition(identity, 'pending', last_error='No local candidate matched; normal run may use a model')
                return
            self.improve(identity, target)
        except BaseException:
            self.release(identity, 'Interrupted/error; persisted candidate will be revalidated')
            raise

    def prepare(self, function):
        """Under the gate: claim the function and record its baseline object and reference."""
        identity, source = function['id'], function['source']
        with self.gate:
            self.check_repository()
            original = (self.root/source).read_bytes()
            source_sha = hashlib.sha256(original).hexdigest()
            if git(self.root, 'status', '--porcelain=v1', '--', source):
                self.state.transition(identity, 'blocked', last_error='Uncommitted target changes; untouched. Commit them, then retry.')
                return None
            if json.loads(function['features']).get('kind') != 'function':
                self.state.transition(identity, 'blocked', last_error='No function ASM; run init --setup and scan')
                return None
            isa64 = json.loads(function['features']).get('isa64_ops', [])
            if isa64:
                self.state.transition(identity, 'blocked', last_error='Toolchain/ABI prerequisite: target uses '
                                      + ', '.join(isa64) + '; current C flags are -mips2. Resolve per-file compiler/ABI before retrying.')
                return None
            self.state.transition(identity, 'analyzing')
            if function['base_sha'] != source_sha:
                candidate = rebase_source(original.decode(), function['best_source'], function['symbol'])
                self.state.update(identity, best_source=candidate, best_score=None, best_run=None, base_sha=source_sha)
            length = (function['size'] or 0) // 4 or None
            baseline = self.coordinator.baseline_builder
            reference_dump = (baseline or self.builder).disassemble(source, function['symbol'])
            reference = instructions(reference_dump, function['symbol'], length)
            saved = False if baseline else self.builder.save_baseline(source, self.root/'.decomp-agent/logs/baseline-object.log')
            scope = repair_scope(self.root, function)
            return Target(self.state.get(identity), original, reference_dump, reference, saved, length, scope)

    def share(self, files):
        """Under the gate: lanes are cloned once, so every later publication must reach them.

        A lane that kept an old header compiled C the trusted tree then refused (and the
        reverse), which looked like an object match that was never ROM-exact."""
        self.published.append(files)
        if self.baseline_builder:
            # Worker copies are taken from this tree, under the same gate.
            for path, value in files.items():
                atomic_write(self.baseline_builder.root/path, value)

    def catch_up(self, lane):
        """Holding the lane: apply the publications it has not seen yet."""
        published = self.published[:]
        for files in published[self.lane_seen.get(lane, 0):]:
            for path, value in files.items():
                atomic_write(lane/path, value)
        self.lane_seen[lane] = len(published)

    def release(self, identity, message):
        if self.state.get(identity)['status'] in ('analyzing', 'attempting', 'improving'):
            self.state.transition(identity, 'pending', last_error=message)

    def local_stages(self, target):
        """Every inference-free route before a model run; True when matched."""
        identity = target.function['id']
        if self.resume_candidate(self.state.get(identity), target):
            self.count_match()
            return True
        if self.recheck_best(self.state.get(identity), target):
            self.count_match(local=True)
            return True
        if not self.config['local_patterns'] or self.args.no_local:
            return False
        if self.try_local(self.state.get(identity), target):
            self.count_match(local=True)
            return True
        if self.try_m2c(target) or self.try_quirks(target) or self.try_permuter(target):
            self.count_match(local=True)
            return True
        return False

    def improve(self, identity, target):
        batch = None
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
            batch = self.companions(function, stage, routing) if batch is None else []
            if (self.root/function['source']).read_bytes() != target.original:
                # Companions matched locally were published into this file: refresh the snapshot.
                self.state.transition(identity, 'pending')
                target = self.prepare(self.state.get(identity))
                if target is None:
                    return
                self.state.transition(identity, 'attempting')
            try:
                result = self.attempt_with_retries(function, routing, target, batch)
            finally:
                for companion in batch:
                    self.release(companion.function['id'], 'Batch interrupted; resumable')
            if result == 'matched':
                self.count_match()
                return
            if result == 'stop':
                return
            if result == 'budget':
                break
            if batch:
                # Published companions changed the source used by further attempts.
                self.state.transition(identity, 'pending')
                target = self.prepare(self.state.get(identity))
                if target is None:
                    return
                self.state.transition(identity, 'attempting')
            if result == 'improve' and self.try_permuter(target):
                self.count_match(local=True)
                return
            if self.escalate(identity, stage):
                return
            self.state.transition(identity, 'improving')
        self.state.transition(identity, 'pending', last_error='Run budget/interruption; next run resumes persisted best candidate')

    def escalate(self, identity, stage):
        """Record one finished model attempt; True when the function is now blocked."""
        function = self.state.get(identity)
        new_stage, used, total, exhausted = advance(function, self.state.history(identity, 12), self.config, stage)
        self.state.update(identity, stage=new_stage, stage_attempts=used, cycle_attempts=total,
                          initial_done=int(stage == -2 and new_stage != -2 or function.get('initial_done', 0)))
        if exhausted:
            self.state.transition(identity, 'blocked', last_error='Escalation/stagnation budget exhausted; inspect best attempt and retry')
        return exhausted

    def companions(self, function, stage, routing):
        """Fresh tiny functions of the same file share one worker session (one CLI overhead)."""
        limit, size = self.config['batch_size'], self.config['batch_max_bytes']
        if (limit < 2 or self.args.function or function['difficulty'] != 'easy' or (function['size'] or 0) > size
                or function['cycle_attempts'] or function['best_source'] is not None):
            return []
        rows = self.state.db.execute("""SELECT * FROM functions WHERE source=? AND id!=? AND status='pending'
            AND present=1 AND difficulty='easy' AND size<=? AND cycle_attempts=0 AND best_source IS NULL
            ORDER BY size, id""", (function['source'], function['id'], size)).fetchall()
        batch = []
        for row in rows:
            if len(batch) >= limit-1 or self.budget_reached():
                break
            target = self.prepare(dict(row))
            if target is None:
                continue
            try:
                if self.local_stages(target):
                    continue
            except BaseException:
                self.release(row['id'], 'Interrupted/error; persisted candidate will be revalidated')
                raise
            if self.state.get(row['id'])['best_source'] is not None:
                self.release(row['id'], 'Has a local candidate; continues individually')
                continue
            self.state.update(row['id'], stage=stage)
            batch.append(replace(target, function=self.state.get(row['id'])))
        return batch

    def count_match(self, local=False):
        with self.coordinator.count_lock:
            self.coordinator.matched += 1
            self.coordinator.local_matches += int(local)

    def local_trial(self, function, target, origin, candidate, key):
        directory = new_run(self.root, 'local')
        run_id = self.state.start_run(function['id'], 'local', origin, 'none', directory)
        self.state.finish_run(run_id, provider='local')
        self.state.transition(function['id'], 'attempting', model='local')
        original = target.original
        atomic_write(directory/'source-before.c', original)
        atomic_write(directory/'source-after.c', candidate)
        atomic_write(directory/'source.diff', source_diff(original.decode(), candidate.decode(), function['source']))
        self.state.finish_run(run_id, outcome='ok')
        print(f"{function['symbol']}: local {origin} (no model usage)", flush=True)
        outcome = self.accept_candidate(target, candidate, directory)
        self.state.finish_run(run_id, ended=time.time())
        with self.state.db:
            self.state.db.execute('INSERT OR REPLACE INTO local_trials VALUES (?,?,?)', (function['id'], key, outcome))
        return outcome

    def tried(self, function, key):
        return self.state.db.execute('SELECT 1 FROM local_trials WHERE function_id=? AND candidate_sha=?',
                                     (function['id'], key)).fetchone() is not None

    def try_local(self, function, target):
        original = target.original
        for origin, code in list(untried_candidates(self.root, function, self.state, original.decode())):
            if self.control.stopped():
                break
            candidate = candidate_source(original.decode(), function['symbol'], code)
            outcome = self.local_trial(function, target, origin, candidate, trial_key(candidate, function))
            if outcome == 'matched':
                return True
            if outcome == 'stop':
                break
        return False

    def draft(self, function):
        if not self.config['m2c']:
            return None
        try:
            return m2c_draft(self.root, self.workspace, self.builder, function, self.root/'.decomp-agent/m2c')
        except (HarnessError, OSError):
            return None

    def try_m2c(self, target):
        """A clean m2c translation is compiled; a near miss becomes the model's start."""
        function = self.state.get(target.function['id'])
        if function['best_source'] is not None or self.control.stopped() or not self.config['m2c']:
            return False
        marker = m2c_key(function, target.original.decode())
        if self.tried(function, marker):
            return False
        draft = self.draft(function)
        matched = False
        for code in m2c_candidates(draft, function['symbol']) if draft else ():
            try:
                candidate = candidate_source(target.original.decode(), function['symbol'], code)
            except HarnessError:
                continue
            key = trial_key(candidate, function)
            if self.tried(function, key):
                continue
            if self.local_trial(function, target, 'm2c', candidate, key) == 'matched':
                matched = True
                break
            if self.state.get(function['id'])['best_source'] is not None or self.control.stopped():
                break  # It compiled: the near miss is now the model's starting point.
        if not matched and not self.control.stopped() and (self.workspace/'tools/m2c/m2c.py').is_file():
            with self.state.db:
                self.state.db.execute('INSERT OR REPLACE INTO local_trials VALUES (?,?,?)', (function['id'], marker, 'm2c-done'))
        return matched

    def try_quirks(self, target):
        """Mechanical IDO-quirk rewrites of the best candidate, chosen from its saved diff."""
        for _ in range(3):  # A fixed frame can expose a scheduling difference, and so on.
            function = self.state.get(target.function['id'])
            if self.control.stopped():
                return False
            for origin, candidate, key in list(quirk_candidates(self.root, function, target.original.decode(), self.state)):
                outcome = self.local_trial(function, target, origin, candidate, key)
                if outcome == 'matched':
                    return True
                if outcome == 'stop':
                    return False
            if self.state.get(function['id'])['best_run'] == function['best_run']:
                return False
        return False

    def try_permuter(self, target):
        """Token-free search on a near miss before more model escalation."""
        function = self.state.get(target.function['id'])
        seconds, best = self.config['permuter_seconds'], function['best_source']
        if (not seconds or best is None or self.control.stopped()
                or (function['best_score'] or 0) < self.config['permuter_min_score'] or function['best_score'] >= 100):
            return False
        key = 'permuter:' + trial_key(best, function)
        if self.tried(function, key):
            return False
        directory = new_run(self.root, 'local')
        run_id = self.state.start_run(function['id'], 'local', 'permuter', 'none', directory)
        self.state.finish_run(run_id, provider='local')
        print(f"{function['symbol']}: permuter {seconds}s from score {function['best_score']:.2f} (no model usage)", flush=True)
        outcome = 'improve'
        try:
            found = run_permuter(self.builder, self.workspace, function, best, target.original, self.gate, seconds, directory)
            candidate = candidate_source(target.original.decode(), function['symbol'], found[1]) if found else None
        except (HarnessError, OSError) as e:
            candidate = None
            self.state.finish_run(run_id, error=str(e)[:2000])
        if candidate and candidate != best:
            self.state.transition(function['id'], 'attempting', model='local')
            atomic_write(directory/'source-before.c', target.original)
            atomic_write(directory/'source.diff', source_diff(target.original.decode(), candidate.decode(), function['source']))
            outcome = self.accept_candidate(target, candidate, directory)
        self.state.finish_run(run_id, ended=time.time(), outcome=outcome if candidate else 'no_improvement')
        with self.state.db:
            self.state.db.execute('INSERT OR REPLACE INTO local_trials VALUES (?,?,?)', (function['id'], key, outcome))
        return outcome == 'matched'

    def attempt_with_retries(self, function, routing, target, batch=()):
        for _ in range(self.config['technical_retries']+1):
            if self.budget_reached():
                return 'budget'
            result = self.attempt(self.state.get(function['id']), routing, target, batch)
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
            guard_candidate(original.decode(), candidate.decode(), function['symbol'])
            load_support(directory, target.support)
        except (HarnessError, UnicodeError):
            return False
        print(f"Revalidating persisted candidate for {function['symbol']} without inference...", flush=True)
        self.state.transition(function['id'], 'attempting')
        return self.accept_candidate(target, candidate, directory) == 'matched'

    def recheck_best(self, function, target):
        """Replay saved work once against the current guard/linker policy, without inference."""
        if not function['best_source']:
            return False
        key = recheck_key(function, target.original, target.support)
        if self.tried(function, key):
            return False
        try:
            guard_candidate(target.original.decode(), function['best_source'].decode(), function['symbol'])
            support = load_support(self.root/'.decomp-agent/runs'/function['best_run'], target.support) if function['best_run'] else {}
        except (HarnessError, UnicodeError) as error:
            self.state.update(function['id'], last_error=str(error))
            return False
        directory = new_run(self.root, 'recheck')
        save_support(directory, target.support, support)
        self.state.start_run(function['id'], 'local', None, None, directory)
        self.state.transition(function['id'], 'attempting')
        result = self.accept_candidate(target, function['best_source'], directory)
        self.state.finish_run(directory.name, ended=time.time())
        with self.state.db:
            self.state.db.execute('INSERT OR REPLACE INTO local_trials VALUES (?,?,?)', (function['id'], key, result))
        return result == 'matched'

    def attempt(self, function, routing, target, batch=()):
        targets = [target, *batch]
        original = target.original
        identity, source = function['id'], function['source']
        provider = routing.get('provider', 'codex')
        runner = self.get_runner(provider)
        directory = new_run(self.root, 'attempt')
        # Claude workers only get Read/Edit tools; the compile loop needs a shell command.
        compiles = self.config['worker_compiles'] if provider == 'codex' else 0
        with self.gate:
            stamp = self.check_repository()
            baseline = self.coordinator.baseline_builder
            worker = worker_copy(baseline.root if baseline else self.workspace, function,
                                 worktree=self.config['concurrency'] > 1)
        compiler = None
        try:
            if batch:
                atomic_write(worker/source, mark_targets(original.decode(), [t.function['symbol'] for t in targets]))
            else:
                seed_worker(worker, self.root, function, original, target.support)
            if compiles:
                service.install(worker, source, self.config['worker_timeout'], () if batch else target.support)
            before = manifest(worker)
            save_json(directory/'worker-before.json', before)
            save_json(directory/'support-before.json', {p: value.decode() for p, value in target.support.items()} if not batch else {})
            share = max(5000, self.config['context_chars'] // len(targets))
            pack = '\n\n'.join(context_pack(self.root, self.state.get(t.function['id']), self.state, self.config,
                                             budget=None if not batch else share, shared=not index,
                                             draft=self.draft(t.function))
                                for index, t in enumerate(targets))
            atomic_write(self.root/'.decomp-agent/context'/f"{hashlib.sha256(identity.encode()).hexdigest()[:16]}.txt", pack)
            prompt = worker_prompt(function, pack, compiles, [t.function for t in batch], target.support if not batch else ())
            atomic_write(directory/'source-before.c', (worker/source).read_bytes())
            save_json(directory/'git-before.json', stamp)
            save_json(directory/'metadata.json', {'function': identity, **routing, 'provider': provider,
                                                'started': time.time(), 'worker': str(worker),
                                                'batch': [t.function['id'] for t in batch]})
            number = self.claim_attempt()
            if number is None:
                return 'budget'
            self.state.transition(identity, 'attempting')
            run_id = self.state.start_run(identity, 'worker', routing['model'], routing['effort'], directory, worker)
            self.state.finish_run(run_id, provider=provider)
            members = []
            for companion in batch:
                folder = new_run(self.root, 'attempt')
                save_json(folder/'metadata.json', {'function': companion.function['id'], 'batch_run': directory.name})
                self.state.transition(companion.function['id'], 'attempting')
                member = self.state.start_run(companion.function['id'], 'worker', routing['model'], routing['effort'], folder)
                self.state.finish_run(member, provider=provider, error=f'Batched with {directory.name}')
                members.append((companion, folder, member))
            names = ', '.join(t.function['symbol'] for t in targets)
            print(f"{names}: {provider}/{routing['model']} {routing['effort']} (worker run {number})", flush=True)
            if compiles:
                compiler = service.CompileService(self, worker, targets, directory, compiles, runner.redact)
                compiler.start()
            result = runner.run(cwd=worker, prompt=prompt, model=routing['model'], effort=routing['effort'],
                                directory=directory, timeout=self.config['worker_timeout'], control=self.control,
                                schema=Path(__file__).with_name('worker.schema.json'),
                                on_start=lambda pid: self.state.finish_run(run_id, pid=pid))
            tested = False
            if compiler:
                compiler.stop()
                tested = compiler.retain_best(worker, before)
                compiler = None
            if isinstance(result.message, dict):
                save_json(directory/'worker-summary.json', json.loads(runner.redact(json.dumps(result.message))))
                if result.message.get('blocker'):
                    self.state.update(identity, last_error=runner.redact(result.message['blocker'])[:3000])
            self.state.finish_run(run_id, ended=time.time(), outcome=result.outcome, exit_code=result.exit_code,
                                  usage=json.dumps(result.usage), error=result.error)
            for _, _, member in members:
                self.state.finish_run(member, ended=time.time(), outcome=result.outcome)
            if (worker/source).is_file() and not (worker/source).is_symlink():
                attempted = runner.redact((worker/source).read_text(errors='replace'))
                atomic_write(directory/'source-after.c', attempted)
                atomic_write(directory/'source.diff', source_diff(original.decode(), attempted, source))
            with self.gate:
                save_json(directory/'git-after.json', self.check_repository())
            if result.outcome in ('auth_error', 'quota_error', 'model_error', 'interrupted'):
                if result.outcome == 'interrupted' and not batch:
                    try:
                        candidate = (worker/source).read_text()
                        if runner.redact(candidate) == candidate:
                            save_guarded_candidate(worker, before, original, function, directory, target.support)
                    except (HarnessError, OSError, UnicodeError) as e:
                        save_json(directory/'candidate-guard.json', {'rejected': runner.redact(str(e))})
                self.state.transition(identity, 'pending', last_error=result.outcome)
                raise HarnessError(f'{provider} {result.outcome}; run can resume, no fallback')
            if result.outcome in ('technical_error', 'timeout'):
                return 'technical'
            if result.outcome != 'ok' and not tested:
                self.state.update(identity, last_error='Agent output invalid')
                self.finish_batch(members, routing, stage_of(function), 'Agent output invalid')
                return 'improve'
            try:
                if not batch:
                    text, support = worker_candidate(worker, before, function, original, target.support, runner.redact)
                    save_support(directory, target.support, support)
                else:
                    verify_worker_changes(worker, before, source)
                    text = (worker/source).read_bytes()
                    if runner.redact(text.decode()) != text.decode():
                        raise HarnessError('Candidate contains credential material; rejected without persistence')
            except (HarnessError, UnicodeError) as e:
                self.state.finish_run(run_id, outcome='guard_rejected', error=str(e))
                self.state.transition(identity, 'needs_human', last_error=str(e))
                self.finish_batch(members, routing, stage_of(function), 'Batch worker violated the guard')
                return 'stop'
            if not batch:
                return self.accept_candidate(target, text, directory, result.message)
            return self.accept_batch(targets, text.decode(), [directory, *(f for _, f, _ in members)],
                                     result.message, members, stage_of(function))
        finally:
            if compiler:
                compiler.stop()
            dispose_worker(worker)

    def accept_batch(self, targets, text, directories, message, members, stage):
        """Validate and publish each edited target on its own, in file order."""
        try:
            edits = split_targets(targets[0].original.decode(), text, {t.function['symbol'] for t in targets})
        except HarnessError as e:
            edits = {}
            self.state.update(targets[0].function['id'], last_error=f'Batch edit rejected: {e}')
        results = {}
        for index, (target, directory) in enumerate(zip(targets, directories)):
            function = self.state.get(target.function['id'])
            code = edits.get(function['symbol'])
            if not code or self.control.stopped():
                results[function['id']] = 'improve'
                continue
            source = function['source']
            current = (self.root/source).read_bytes()
            # Earlier batch members may already be published: rebase on the new file/object.
            with self.coordinator.publication_gate, self.gate:
                saved = self.builder.save_baseline(source, directory/'baseline-object.log')
            rebased = replace(target, function=function, original=current, baseline_saved=saved)
            try:
                candidate = candidate_source(current.decode(), function['symbol'], code)
            except HarnessError as e:
                self.state.update(function['id'], last_error=str(e))
                results[function['id']] = 'improve'
                continue
            atomic_write(directory/'source-before.c', current)
            atomic_write(directory/'source.diff', source_diff(current.decode(), candidate.decode(), source))
            results[function['id']] = self.accept_candidate(rebased, candidate, directory, message if not index else None)
            if results[function['id']] == 'stop':
                break
        self.finish_batch(members, None, stage, None, results)
        return results.get(targets[0].function['id'], 'improve')

    def finish_batch(self, members, routing, stage, error, results=None):
        for companion, _, _ in members:
            identity = companion.function['id']
            outcome = (results or {}).get(identity, 'improve')
            if outcome == 'matched':
                self.count_match()
                continue
            if self.state.get(identity)['status'] not in ('analyzing', 'attempting', 'improving'):
                continue
            if not self.escalate(identity, stage):
                self.state.transition(identity, 'pending', last_error=error or 'Batch attempt did not match; continues individually')

    def accept_candidate(self, target, candidate, directory, message=None):
        function, original, run_id = target.function, target.original, directory.name
        replacement = guard_candidate(original.decode(), candidate.decode(), function['symbol'])
        support = load_support(directory, target.support)
        atomic_write(directory/'source-after.c', candidate)
        comparison = self.validate(target, candidate, directory, support)
        if comparison is None:
            self.state.finish_run(run_id, outcome='compile_error', error='See compiler.log')
            self.state.update(function['id'], last_error=(directory/'compiler.log').read_text(errors='replace')[-3000:])
            return 'improve'
        with self.coordinator.publication_gate if comparison['rom_checked'] else nullcontext():
            saved = False
            if comparison['rom_checked']:
                with self.gate:
                    self.check_repository()
                    for path in support:
                        if (self.root/path).read_bytes() != target.support[path]:
                            raise HarnessError('Dependency changed during search; candidate retained for revalidation')
                saved = self.builder.save_baseline(function['source'], directory/'baseline-object.log')
            try:
                # Only plausible matches pay for the full link + ROM hash; it stays mandatory for those.
                exact = comparison['rom_checked'] and self.rom_check(target, candidate, directory)
                if exact is None:
                    # Not a ROM difference: hand the worker the compiler's message instead.
                    self.state.finish_run(run_id, outcome='compile_error', error='See rom-object.log')
                    self.state.update(function['id'], last_error='Trusted ROM build could not compile the candidate:\n'
                                      + (directory/'rom-object.log').read_text(errors='replace')[-3000:])
                    return 'improve'
                comparison['exact'] = exact
                with self.gate:
                    return self.finish_candidate(target, candidate, directory, comparison, replacement, message)
            finally:
                if comparison['rom_checked'] and self.state.get(function['id'])['status'] != 'matched':
                    for path in support:
                        atomic_write(self.workspace/path, target.support[path])
                    if support:
                        self.builder.invalidate(support, directory/'restore-support.log')
                    self.builder.restore(function['source'], original, saved, directory/'restore.log')
                    if support and not self.control.stopped():
                        if not self.builder.regression(directory/'restore-baseline.log'):
                            raise HarnessError('Dependency rollback could not rebuild an exact baseline; stopping before another attempt')

    def finish_candidate(self, target, candidate, directory, comparison, replacement, message):
        """Under the repository gate, persist evidence and publish only a ROM-exact result."""
        function, original, run_id = target.function, target.original, directory.name
        self.check_repository()
        previous = self.state.get(function['id'])['best_score']
        comparison['delta'] = comparison['score'] - (previous if previous is not None else 0)
        save_json(directory/'comparison.json', comparison)
        key = recheck_key({**function, 'best_source': candidate}, original, target.support)
        with self.state.db:
            self.state.db.execute('INSERT OR REPLACE INTO local_trials VALUES (?,?,?)',
                                  (function['id'], key, 'matched' if comparison['exact'] else 'nonmatching'))
        self.state.finish_run(run_id, outcome='matched' if comparison['exact'] else 'nonmatching',
                              score=comparison['score'], delta=comparison['delta'],
                              differences=comparison['different_instructions'], first_diff=json.dumps(comparison['first_diff']),
                              last_diffs=json.dumps(comparison['last_diffs']))
        if previous is None or comparison['score'] > previous or comparison['exact']:
            self.state.update(function['id'], best_source=candidate, best_score=comparison['score'], best_run=run_id)
        print(f"  {function['symbol']}: score {comparison['score']:.2f}, diff instructions {comparison['different_instructions']}, "
              f"ROM {'exact' if comparison['exact'] else 'not exact' if comparison['rom_checked'] else 'check skipped'}", flush=True)
        if not comparison['exact']:
            return 'improve'
        if self.control.stopped():
            self.state.transition(function['id'], 'pending', last_error='Validated match retained; interrupted before publication')
            return 'stop'
        support = load_support(directory, target.support)
        commit = publish(self.root, self.state, function, original, candidate,
                         {p: (target.support[p], value) for p, value in support.items()})
        self.coordinator.expected_stamp = repository_stamp(self.root)
        self.coordinator.share({function['source']: candidate, **support})
        atomic_write(directory/'commit.txt', commit+'\n')
        remember(self.root, self.state, function, replacement, commit)
        refresh_solutions(self.root, self.state, [function['source'], *support], commit)
        if isinstance(message, dict):
            for note in message.get('knowledge', [])[:4]:
                if isinstance(note, str):
                    self.state.note(function['segment']+' IDO '+function['symbol'], note, commit)
        self.state.note(function['segment']+' '+function['symbol'], 'Matched source pattern:\n'+replacement[:900], commit)
        return 'matched'

    def object_dumps(self, target, candidate, symbols, log, restore_log, support=None):
        """Compile a candidate; None on a compile error, else {symbol: objdump}.

        Parallel runs use a private lane (never linked, so no restore); otherwise the
        trusted workspace under the gate, returned to its baseline afterwards."""
        source, lanes = target.function['source'], self.coordinator.lanes
        support = {**target.support, **(support or {})}
        if lanes is None:
            with self.gate:
                try:
                    return self.compile_in(self.workspace, self.builder, source, candidate, symbols, log, support)
                finally:
                    self.builder.restore(source, target.original, target.baseline_saved, restore_log)
        lane, builder = lanes.get()
        try:
            self.coordinator.catch_up(lane)
            return self.compile_in(lane, builder, source, candidate, symbols, log, support)
        finally:
            lanes.put((lane, builder))

    @staticmethod
    def compile_in(workspace, builder, source, candidate, symbols, log, support=None):
        atomic_write(workspace/source, candidate)
        before = {p: (workspace/p).read_bytes() for p, value in (support or {}).items()
                  if (workspace/p).read_bytes() != value}
        try:
            for path in before:
                atomic_write(workspace/path, support[path])
            if builder.object_build(source, log):
                return None
            return {symbol: builder.disassemble(source, symbol) for symbol in symbols}
        finally:
            for path, value in before.items():
                atomic_write(workspace/path, value)

    def validate(self, target, candidate, directory, support=None):
        """Object comparison only; the caller runs the ROM check under the gate."""
        symbol = target.function['symbol']
        atomic_write(directory/'expected.asm', target.reference_dump)
        dumps = self.object_dumps(target, candidate, [symbol], directory/'compiler.log', directory/'probe-restore.log', support)
        if dumps is None:
            return None
        atomic_write(directory/'actual.asm', dumps[symbol])
        comparison = score(target.reference, instructions(dumps[symbol], symbol, target.length))
        comparison['rom_checked'] = worth_rom_check(comparison)
        return comparison

    def rom_check(self, target, candidate, directory):
        """Under the gate: the candidate in the trusted workspace, then `make check`.
        None when it does not even compile there."""
        source = target.function['source']
        support = load_support(directory, target.support)
        for path, value in support.items():
            atomic_write(self.workspace/path, value)
        if support:
            self.builder.invalidate(support, directory/'invalidate.log')
        atomic_write(self.workspace/source, candidate)
        if self.builder.object_build(source, directory/'rom-object.log'):
            return None
        return self.builder.regression(directory/'regression.log')


def stage_of(function):
    return function['stage']
