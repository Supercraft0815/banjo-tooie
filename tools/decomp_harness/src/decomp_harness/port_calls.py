"""`decomp-agent port-calls`: Codex workers turn FixCalls adaptations into source fixes.

FixCalls (pc/native/wasm/fixcalls) patches IDO calling habits in the native port's IR and lists
every patch in build/ilp32/widened.txt. A worker gets one source file with its items, in a private
APFS clone, and checks itself with ./port-check. The parent validates serialized in its own lane
(a clone of the checkout under .decomp-agent/port-calls/lane): line counts, the N64 token view
of every affected unit, `make check`, ILP32 build, the file's items gone and none new, no new
traps, `port.py gate` identical to the stored references. A failing batch is bisected. Accepted
files are copied into the checkout; nothing is committed.
"""
from __future__ import annotations

import concurrent.futures
from dataclasses import dataclass, field
import hashlib
import importlib.util
import json
import os
from pathlib import Path
import re
import shutil
import subprocess
import sys
import threading
import time
import uuid

from .build import Builder, object_path
from .common import HarnessError, atomic_write, command, locked, run_logged, save_json

HERE = Path(__file__).resolve().parent
# FixCalls gives these callers an undefined value today: a fix changes behaviour, so a human decides.
EXCLUDED = {'VOIDSTORE'}
KINDS = {
    'ARGS': 'ARGS f have want: the definition of f takes `have` parameters, callers pass `want`. IDO '
            'passes the extra arguments on in a0..a3 and the body (or a call in it) relies on them; '
            'FixCalls adds the missing parameters. Fix: name them natively, e.g. `void f(BT_PARAM_OR_VOID(s32 bt_a0))` '
            'for `void f(void)`, `void f(BT_NATIVE_ONLY(s32 bt_a0))` for `void f()`, or '
            '`void f(BT_IDO_ONLY(s32 a) BT_PASS2(s32 a, s32 bt_a1))` to add one after existing ones, '
            'and pass them where the body relies on the registers (BT_PASS2 / BT_NATIVE_ONLY in the call).',
    'UNDEFRET': 'UNDEFRET f: f has a return type but a path ends without `return`; IDO callers read v0 '
                '(f0 for floats), so FixCalls returns the result of the last call before that end that '
                'yields a value of the same register class (looking back through straight-line code), '
                'else 0. Fix: `BT_NATIVE_ONLY(return) g(...);` on that call, or `BT_NATIVE_ONLY(return 0;)`.',
    'RET': 'RET f: f is void but callers use its result; IDO leaves the last call\'s v0 in place, so '
           'FixCalls makes f return the value of the call directly before each return (0 elsewhere). '
           'Fix: give f that return type natively (`BT_IDO_ONLY(void) BT_NATIVE_ONLY(T) f(...)`, the same in '
           'its declarations) and `BT_NATIVE_ONLY(return) g(...);`.',
    'RETCLASS': 'RETCLASS g in f: f calls g with a declaration whose return register class (int vs float) '
                'differs from g\'s definition as FixCalls leaves it (a void g that RET widens returns its last '
                'call\'s type). FixCalls reinterprets the same 32 bits, never converts the number. Fix: declare g '
                'natively with the definition\'s type and reinterpret where f needs the other class, e.g. '
                '`((union { s32 i; f32 f; }){ .i = g(x) }).f`; a plain `f32 v = g()` with an s32 declaration is a '
                'numeric conversion and changes behaviour. Often cleaner: fix g itself (its own item) so it '
                'returns the right type natively. Never drop the call or the use of its result.',
    'IRDIFF': 'IRDIFF f: f no longer does what FixCalls made of the code before any native fix (the '
              'reference in .port-base/reference-ir). Shown: its canonical IR lines that differ (- reference, '
              '+ now). Pointer/int/float reinterpretations of the same bits are already ignored; what is left is '
              'real: a numeric conversion (sitofp) where the bits were reused, `ret 0` where the last call\'s result '
              'came back (or the reverse), a dropped store or call, a different branch. Fix the source until '
              './port-check --build reports no difference for f. The cause may be a declaration or definition '
              'this file uses: fix it where it lives (this file, or its header).',
    'REGMAP': 'REGMAP g in f: f passes float/int arguments to g in positions whose O32 registers differ '
              'from g\'s definition; FixCalls remaps them. Fix the declaration f uses or the call, natively only.',
}
N64_PP = ['clang', '-E', '-undef', '-w', '-I', 'include', '-I', 'lib/ultralib/include', '-I', 'src',
          '-DBUILD_VERSION=VERSION_J', '-D_FINALROM', '-DF3DEX_GBI_2', '-D_LANGUAGE_C',
          '-D_MIPS_SZLONG=32', '-D_MIPS_SZINT=32', '-D__sgi', '-Dmips', '-D_MIPS_SIM=1']
TOKEN = re.compile(r'"(?:\\.|[^"\\])*"|\'(?:\\.|[^\'\\])*\'|[A-Za-z_]\w*|\d[\w.]*|\S')
SYNC = ('src', 'include', 'pc', 'lib', 'tools', 'asm', 'assets')


def parse_items(lines, files):
    """({source: [item]}, [unassigned or excluded item]). "g in f" kinds belong to the caller f."""
    work, rest = {}, []
    for line in sorted({l.strip() for l in lines if l.strip()}):
        p = line.split()
        kind = p[0] if p[0].isupper() else 'ARGS'
        owner = p[0] if kind == 'ARGS' else p[3] if kind in ('REGMAP', 'RETCLASS') and len(p) == 4 else p[1]
        source = files.get(owner, '')
        if kind in EXCLUDED or not source.endswith('.c'):
            rest.append(line)
        else:
            work.setdefault(source, []).append(line)
    return work, rest


def n64_tokens(root: Path, unit):
    """What IDO's front end sees: preprocessed lines (with line markers) as token lists."""
    r = subprocess.run(N64_PP + [unit], cwd=root, capture_output=True, text=True)
    if r.returncode:
        return [['preprocessor error:', r.stderr[-500:]]]
    return [TOKEN.findall(line) for line in r.stdout.splitlines()]


def first_difference(a, b):
    for i, (x, y) in enumerate(zip(a, b)):
        if x != y:
            return 'preprocessed line %d: %r became %r' % (i + 1, ' '.join(x)[:200], ' '.join(y)[:200])
    return '' if len(a) == len(b) else 'preprocessed length %d became %d' % (len(a), len(b))


def view_hash(root, unit):
    return hashlib.sha256(json.dumps(n64_tokens(root, unit)).encode()).hexdigest()


def n64_views(root, units):
    with concurrent.futures.ThreadPoolExecutor(os.cpu_count() or 4) as pool:
        return dict(zip(units, pool.map(lambda u: view_hash(root, u), units)))


def changed_files(work: Path, base: Path):
    """C sources and headers under src/ and include/ whose bytes differ from base (or are new)."""
    out = []
    for top in ('src', 'include'):
        for dirpath, dirs, names in os.walk(work / top):
            dirs[:] = [d for d in dirs if d != '__pycache__']
            for name in names:
                p = Path(dirpath, name)
                rel = str(p.relative_to(work))
                q = base / rel
                if not q.is_file() or q.read_bytes() != p.read_bytes():
                    out.append(rel)
    return sorted(out)


def bisect(validate, batch, blame=lambda: []):
    """(accepted, [(candidate, reason)]): the whole batch, else each half on its own.
    blame() names the candidates a failure provably comes from; only those are dropped and the
    rest is validated again in full, which saves the halving rounds."""
    reason = validate(batch)
    if reason is None:
        return list(batch), []
    if len(batch) == 1:
        return [], [(batch[0], reason)]
    guilty = [c for c in batch if c in blame()]
    if guilty and len(guilty) < len(batch):
        ok, bad = bisect(validate, [c for c in batch if c not in guilty], blame)
        return ok, [(c, reason) for c in guilty] + bad
    half = len(batch) // 2
    a, ra = bisect(validate, batch[:half], blame)
    b, rb = bisect(validate, batch[half:], blame)
    return a + b, ra + rb


def allowed(path, source):
    """Files a worker may change: its source and headers (include/ or next to sources under src/)."""
    return path == source or (path.endswith('.h') and path.startswith(('include/', 'src/')))


def item_functions(item):
    """Every function an item names (ARGS 'f have want', 'KIND f', 'KIND g in f')."""
    return [w for w in item.split()[(1 if item.split()[0].isupper() else 0):] if w != 'in' and not w.isdigit()]


def lines_of(path: Path):
    return {l.strip() for l in path.read_text().splitlines() if l.strip()} if path.exists() else set()


def clone(source: Path, target: Path, build=('ilp32', 'reference', 'us')):
    """APFS copy-on-write clone (macOS) of what a build needs: no .git, no harness state."""
    target.mkdir(parents=True)
    copy = ['cp', '-cRp'] if sys.platform == 'darwin' else ['cp', '-Rp']
    for p in source.iterdir():
        if not p.name.startswith('.') and p.name != 'build' and p.suffix not in ('.zip', '.n64'):
            command(copy + [str(p), str(target)], timeout=900)
    (target / 'build').mkdir()
    for name in build:
        if (source / 'build' / name).exists():
            command(copy + [str(source / 'build' / name), str(target / 'build')], timeout=900)


def clone_tree(source: Path, target: Path):
    command((['cp', '-cRp'] if sys.platform == 'darwin' else ['cp', '-Rp']) + [str(source), str(target)], timeout=900)


def load_module(path: Path):
    spec = importlib.util.spec_from_file_location('bt_' + path.stem + '_' + uuid.uuid4().hex[:6], path)
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    return module


@dataclass
class Candidate:
    source: str
    items: list
    files: dict          # path -> new text
    base: dict           # path -> checkout bytes the worker started from
    directory: Path
    fixed: list = field(default_factory=list)


class Lane:
    """The trusted, serialized validation tree. Only this class writes the checkout."""

    def __init__(self, root: Path, config, control, base: Path, cases):
        self.root, self.config, self.control, self.cases = root, config, control, cases
        self.path = base / 'lane'
        self.builder = Builder(self.path, config, control)
        self.widened = self.traps = set()
        self.views = {}
        self.files = {}    # function -> defining source, for blaming new FixCalls items
        self.blamed = []   # candidates the last failed check provably comes from
        self.reference = base / 'reference-ir'  # FixCalls semantics before any native fix
        self.irdiff = {}   # function -> canonical IR lines that differ from the reference

    def sync(self, log: Path):
        if not self.path.exists():
            clone(self.root, self.path)
            return
        touched = []
        for name in SYNC:
            out = command(['rsync', '-a', '--delete', '--itemize-changes', '--exclude', '__pycache__',
                           f'{self.root / name}/', f'{self.path / name}/'], timeout=900).stdout.decode()
            touched += [self.path / name / l.split(' ', 1)[1] for l in out.splitlines() if l.startswith('>f')]
        for p in self.root.iterdir():
            if p.is_file() and not p.name.startswith('.') and p.suffix not in ('.zip', '.n64'):
                q = self.path / p.name
                if not q.exists() or q.read_bytes() != p.read_bytes():
                    shutil.copyfile(p, q)
                    touched.append(q)
        for p in touched:  # copied mtimes may predate lane objects built from other content
            os.utime(p)
        atomic_write(log, ''.join(f'{p}\n' for p in touched))

    def units(self):
        return sorted(str(p.relative_to(self.path)) for p in (self.path / 'src').rglob('*.c'))

    def ilp32(self, log):
        return run_logged([sys.executable, 'pc/native/wasm/build.py'], self.path, log,
                          self.config['build_timeout'], self.control)

    def make_check(self, sources, log):
        for s in sources:  # inside the container, like every build output (see Builder.save_baseline)
            self.builder.invoke(['rm', '-f', object_path(s)], log.with_suffix('.rm.log'))
        return self.builder.regression(log)

    def gate(self, log):
        args = ['--full'] if self.cases == 'full' else ['--case', self.cases]
        rc = run_logged([sys.executable, 'pc/native/wasm/port.py', 'gate', '--exe', 'build/ilp32/bt_game', *args],
                        self.path, log, self.config['build_timeout'], self.control)
        for d in (self.path / 'build').glob('gate-*'):
            shutil.rmtree(d, ignore_errors=True)
        return rc

    def baseline(self, directory: Path):
        if self.ilp32(directory / 'ilp32.log'):
            raise HarnessError(f'ILP32 baseline build fails in the lane; see {directory}/ilp32.log')
        if not self.make_check([], directory / 'make-check.log'):
            raise HarnessError(f'N64 baseline make check fails in the lane; see {directory}/make-check.log')
        if self.gate(directory / 'gate.log'):
            raise HarnessError(f'Baseline gate fails (stale references?); see {directory}/gate.log')
        self.widened = lines_of(self.path / 'build/ilp32/widened.txt')
        self.traps = lines_of(self.path / 'build/ilp32/traps.txt')
        self.views = n64_views(self.path, self.units())
        self.irdiff = self.ir_differences()

    def ir_differences(self):
        return load_module(self.path / 'pc/native/wasm/ir_equiv.py').differing(self.reference, self.path)

    def accepted(self):
        """Functions whose IR differs from the reference on purpose (reference-ir/accepted.txt, `name  # why`)."""
        path = self.reference / 'accepted.txt'
        return {l.split('#')[0].strip() for l in lines_of(path) if l.split('#')[0].strip()} if path.exists() else set()

    def ir_items(self, irdiff=None):
        """IRDIFF work items: changed functions, minus accepted ones and new native-only functions."""
        irdiff = self.irdiff if irdiff is None else irdiff
        return {'IRDIFF ' + f for f, r in irdiff.items()
                if f not in self.accepted() and r != ['defined in the new build only']}

    def validate(self, batch, directory: Path):
        """None when the whole batch passes (and stays applied), else why; the lane is then restored."""
        directory.mkdir(parents=True, exist_ok=True)
        changed = {p: t for c in batch for p, t in c.files.items()}
        old = {p: (self.path / p).read_bytes() for p in changed}
        for p, t in changed.items():
            atomic_write(self.path / p, t)
        try:
            result = self.check(batch, changed, old, directory)
        except BaseException:
            self.restore(old)
            raise
        if result is None:
            return None
        self.restore(old)
        atomic_write(directory / 'reason.txt', result)
        return result

    def restore(self, old):
        for p, data in old.items():
            atomic_write(self.path / p, data)

    def check(self, batch, changed, old, directory):
        self.blamed = []
        owners = lambda paths: [c for c in batch if set(c.files) & set(paths)]
        bad = [p for p, t in changed.items() if old[p].count(b'\n') != t.encode().count(b'\n')]
        if bad:
            self.blamed = owners(bad)
            return f'{bad[0]}: line count changed; never add or remove lines.'
        headers = [p for p in changed if p.endswith('.h')]
        units = self.units() if headers else [p for p in changed if p.endswith('.c')]
        views = n64_views(self.path, units)
        moved = [u for u in units if views[u] != self.views.get(u)]
        if moved:
            self.blamed = owners(moved) if not headers else []
            return 'IDO would see different tokens in: ' + ', '.join(moved[:10])
        if not self.make_check([p for p in changed if p.endswith('.c')], directory / 'make-check.log'):
            return 'make check failed (N64 ROM differs).'
        if self.ilp32(directory / 'ilp32.log'):
            return 'ILP32 build failed:\n' + (directory / 'ilp32.log').read_text(errors='replace')[-3000:]
        widened = lines_of(self.path / 'build/ilp32/widened.txt')
        traps = lines_of(self.path / 'build/ilp32/traps.txt')
        new = sorted(widened - self.widened)
        if new:
            if not any(p.endswith('.h') for p in changed):  # a header may move items into any file
                for i in new:  # only when exactly one candidate owns the functions the item names
                    who = owners([self.files.get(f) for f in item_functions(i)])
                    self.blamed += who if len(who) == 1 and who[0] not in self.blamed else []
            return 'New FixCalls items: ' + '; '.join(new[:20])
        if traps - self.traps:
            return 'New traps: ' + '; '.join(sorted(traps - self.traps)[:20])
        irdiff = self.ir_differences()
        moved = {f: r for f, r in irdiff.items() if self.irdiff.get(f) != r}
        moved.update({f: ['an accepted deviation (reference-ir/accepted.txt) went back to the reference']
                      for f in self.accepted() & set(self.irdiff) - set(irdiff)})
        if moved:  # what any fix must keep: every function as FixCalls made it of the old code
            self.blamed = [c for c in owners([self.files.get(f) for f in moved]) if not headers]
            return ('Behaviour differs from FixCalls on the old code (canonical IR, - reference, + now) in:\n' +
                    '\n'.join(f + ':\n' + '\n'.join('    ' + l for l in r[:12]) for f, r in sorted(moved.items())[:12]))
        left = widened | self.ir_items(irdiff)
        for c in batch:
            c.fixed = [i for i in c.items if i not in left]
        self.blamed = [c for c in batch if not c.fixed]
        if self.blamed:
            return f'{self.blamed[0].source}: none of its items disappeared from widened.txt.'
        if self.gate(directory / 'gate.log'):
            text = (directory / 'gate.log').read_text(errors='replace')
            return 'Gate failed (game behaviour changed): ' + '\n'.join(l for l in text.splitlines() if 'FAIL' in l)[-2000:]
        self.widened, self.traps, self.irdiff = widened, traps, irdiff
        self.views.update(views)
        return None

    def publish(self, candidate):
        for p, base in candidate.base.items():
            target = self.root / p
            if (target.read_bytes() if target.exists() else b'') != base:
                raise HarnessError(f'{p} changed in the checkout during the run; stopped before overwriting it. '
                                   'The next run resyncs the lane.')
        for p, t in candidate.files.items():
            atomic_write(self.root / p, t)


def callers(lane: Path, name, limit=8):
    pattern = re.compile(r'\b%s\s*\(' % re.escape(name))
    out = []
    for p in sorted((lane / 'src').rglob('*.c')):
        for n, line in enumerate(p.read_text(errors='replace').splitlines(), 1):
            if pattern.search(line) and not re.match(r'^[A-Za-z_].*\)\s*\{', line):
                out.append(f'{p.relative_to(lane)}:{n}: {line.strip()[:120]}')
                if len(out) >= limit:
                    return out
    return out


def prompt(lane: Path, source, items, feedback, irdiff=None):
    text = (lane / source).read_text(errors='replace').splitlines()
    parts = [f'Assigned file: {source}', '', 'Items (from build/ilp32/widened.txt):']
    for item in items:
        p = item.split()
        kind = p[0] if p[0].isupper() else 'ARGS'
        name = p[0] if kind == 'ARGS' else p[3] if kind in ('REGMAP', 'RETCLASS') else p[1]
        where = [str(n) for n, l in enumerate(text, 1) if re.search(r'\b%s\s*\(' % re.escape(name), l) and l.rstrip().endswith('{')]
        parts.append(f'- {item}   (definition line {", ".join(where) or "?"})')
        if kind == 'RET':
            parts += ['    uses: ' + c for c in callers(lane, p[1])]
        if kind == 'IRDIFF':
            parts += ['    ' + l for l in (irdiff or {}).get(p[1], [])[:24]]
    parts += ['', 'What each kind means and how to fix it:']
    parts += [f'- {KINDS[k]}' for k in sorted({(i.split()[0] if i.split()[0].isupper() else 'ARGS') for i in items})]
    if feedback:
        parts += ['', 'The previous attempt for this file was rejected:', feedback[-3000:]]
    return '\n'.join(parts) + '\n'


class Port:
    def __init__(self, root: Path, config, control, args):
        self.root, self.config, self.control, self.args = root, config, control, args
        self.base = root / '.decomp-agent/port-calls'
        self.state_path = self.base / 'state.json'
        self.state = json.loads(self.state_path.read_text()) if self.state_path.exists() else {'files': {}}
        stages = ([config['easy_model']] if config['easy_model']['enabled'] else []) + config['routing'][:1]
        self.stages = [s for s in stages if s.get('provider', 'codex') == 'codex'] or [{'model': args.model, 'effort': 'medium'}]
        self.lock = threading.Lock()  # workers record from their threads
        self.flags = None

    def save(self):
        save_json(self.state_path, self.state)

    def queue(self, tree: Path, widened):
        files = load_module(tree / 'pc/native/wasm/port.py').function_files()
        work, rest = parse_items(widened, files)
        entry = lambda f: self.state['files'].get(f, {})
        todo = [f for f in sorted(work, key=lambda f: (len(work[f]), f))
                if (not self.args.file or f == self.args.file)
                and (self.args.retry or entry(f).get('attempts', 0) < self.args.attempts)]
        return work, rest, todo

    def run(self):
        self.base.mkdir(parents=True, exist_ok=True, mode=0o700)
        if self.args.dry_run:
            work, rest, todo = self.queue(self.root, lines_of(self.root / 'build/ilp32/widened.txt'))
            return {'files': len(work), 'items': sum(map(len, work.values())), 'queued': todo[:self.args.max_files or None],
                    'not_assigned': rest, 'model_runs': 0}
        with locked(self.base):
            run_dir = self.base / 'runs' / time.strftime('%Y%m%d-%H%M%S')
            lane = Lane(self.root, self.config, self.control, self.base, self.args.gate)
            lane.sync(run_dir / 'sync.log')
            lane.baseline(run_dir / 'baseline')
            work, rest, todo = self.queue(lane.path, lane.widened | lane.ir_items())
            lane.files = load_module(lane.path / 'pc/native/wasm/port.py').function_files()
            self.flags = load_module(lane.path / 'pc/native/wasm/build.py').GUEST_FLAGS
            todo = todo[:self.args.max_files or None]
            from .codex import CodexRunner
            runner = CodexRunner()
            runner.instructions = HERE / 'port-instructions.md'
            accepted_files, rejected = [], []
            while todo and not self.control.stopped():
                batch, todo = todo[:self.args.batch], todo[self.args.batch:]
                with concurrent.futures.ThreadPoolExecutor(self.config['concurrency']) as pool:
                    found = list(pool.map(lambda f: self.work(runner, lane, f, work[f][:getattr(self.args, 'max_items', None) or None], run_dir), batch))
                candidates = [c for c in found if c]
                ok, bad = bisect(lambda b: lane.validate(b, run_dir / ('validate-' + uuid.uuid4().hex[:8])),
                                 candidates, lambda: lane.blamed) if candidates else ([], [])
                for c in ok:
                    lane.publish(c)
                    self.record(c.source, 'accepted', fixed=c.fixed, left=[i for i in c.items if i not in c.fixed])
                    accepted_files.append(c.source)
                    work[c.source] = [i for i in work[c.source] if i not in c.fixed]
                    if work[c.source] and c.source not in todo:  # progress was made; the rest of a big file follows
                        todo.append(c.source)
                for c, reason in bad:
                    self.record(c.source, 'rejected', feedback=reason)
                    rejected.append(c.source)
                    if self.state['files'][c.source]['attempts'] < self.args.attempts:
                        todo.append(c.source)
            return {'accepted': accepted_files, 'rejected': rejected, 'items_left': len(lane.widened),
                    'run': str(run_dir), 'stopped': self.control.stopped()}

    def record(self, source, outcome, **extra):
        with self.lock:
            entry = self.state['files'].setdefault(source, {'attempts': 0, 'history': []})
            if outcome == 'accepted':  # items it left get fresh attempts
                entry.pop('feedback', None)
                entry['attempts'] = 0
            elif outcome == 'conflict':  # the checkout moved on: not the worker's fault
                entry['attempts'] -= 1
            else:
                entry['feedback'] = extra.get('feedback', '')
            entry['status'] = outcome
            entry['history'].append({'time': time.time(), 'outcome': outcome, **extra})
            self.save()

    def work(self, runner, lane: Lane, source, items, run_dir: Path):
        """One worker attempt on one file in a private clone; a Candidate or None."""
        with self.lock:
            entry = self.state['files'].setdefault(source, {'attempts': 0, 'history': []})
            stage = self.stages[min(entry['attempts'], len(self.stages) - 1)]
            entry['attempts'] += 1
            attempt, feedback = entry['attempts'], entry.get('feedback', '')
        if getattr(self.args, 'model', None):
            stage = {**stage, 'model': self.args.model}
        if getattr(self.args, 'effort', None):
            stage = {**stage, 'effort': self.args.effort}
        directory = run_dir / source.replace('/', '__')
        directory = directory.with_name(f'{directory.name}-{attempt}')
        work = self.base / 'work' / uuid.uuid4().hex[:12]
        try:
            clone(lane.path, work, build=('ilp32',))
            (work / 'build/us').mkdir()  # build.py reads the N64 link map, nothing else from build/us
            shutil.copy2(lane.path / 'build/us/banjotooie_decompressed.map', work / 'build/us')
            meta = {'lane': str(lane.path), 'harness': str(HERE.parent), 'source': source, 'items': items,
                    'baseline': sorted(lane.widened), 'irdiff': lane.irdiff, 'units': lane.units(),
                    'native_flags': native_flags(self.flags, lane.path, work)}
            (work / '.port-base').mkdir()
            clone_tree(lane.reference, work / '.port-base/reference-ir')
            atomic_write(work / '.port-base/meta.json', json.dumps(meta))
            shutil.copy(HERE / 'port_check.py', work / 'port-check')
            os.chmod(work / 'port-check', 0o755)
            result = runner.run(cwd=work, prompt=prompt(lane.path, source, items, feedback, lane.irdiff),
                                model=stage['model'], effort=stage['effort'], directory=directory,
                                timeout=getattr(self.args, 'worker_timeout', None) or self.config['worker_timeout'], control=self.control,
                                schema=HERE / 'worker.schema.json')
            changed = changed_files(work, lane.path)
            message = result.message if isinstance(result.message, dict) else {}
            outcome = {'model': stage['model'], 'effort': stage['effort'], 'worker': result.outcome,
                       'summary': message.get('summary', ''), 'blocker': message.get('blocker', ''), 'changed': changed}
            save_json(directory / 'outcome.json', outcome)
            allowed_files = [p for p in changed if allowed(p, source)]
            if result.outcome != 'ok':
                why = f'worker {result.outcome}: {result.error[-500:]}'
            elif changed != allowed_files:
                why = 'changed files outside the assignment: ' + ', '.join(sorted(set(changed) - set(allowed_files)))
            elif not changed:
                why = 'no change' + (': ' + outcome['blocker'] if outcome['blocker'] else '')
            else:
                why = None
            if why:
                self.record(source, 'rejected' if changed else 'blocked', feedback=why, worker=outcome)
                return None
            files = {p: (work / p).read_text() for p in changed}
            base = {p: (self.root / p).read_bytes() if (self.root / p).exists() else b'' for p in changed}
            if any(base[p] != ((lane.path / p).read_bytes() if (lane.path / p).exists() else b'') for p in changed):
                self.record(source, 'conflict')
                return None
            for p, t in files.items():
                atomic_write(directory / 'files' / p, t)
            return Candidate(source, items, files, base, directory)
        finally:
            shutil.rmtree(work, ignore_errors=True)


def native_flags(flags, lane: Path, work: Path):
    """The lane's guest compile flags for a worker clone; generated headers stay the lane's."""
    gen = str(lane / 'build/ilp32/gen')
    return [f if f.startswith(gen) else f.replace(str(lane), str(work)) for f in flags]
