"""Compile-and-diff loop for sandboxed workers, served by the trusted parent.

The worker never gets a compiler, Docker or the trusted checkout. Its `./decomp-compile`
drops the current source into `.decomp-ipc/`; the parent guards it like a final
candidate, compiles the object (a private build lane when parallel, else the trusted
workspace under the gate, then restored) and answers with a compact instruction diff.
"""
from __future__ import annotations

import os
import hashlib
import json
import re
import stat
import threading
import uuid

from .common import HarnessError, atomic_write, save_json
from .guard import IPC, split_targets, verify_worker_changes
from .matching import instructions, render, score
from .scanner import global_asms
from .repairs import guard_candidate, guard_support, save_support

SCRIPT = '''#!/usr/bin/env python3
"""Compile the current source with the trusted IDO toolchain and print the diff."""
import json, pathlib, sys, time
root = pathlib.Path(__file__).resolve().parent
ipc = root / {ipc!r}
number = 1 + max((int(p.name[8:-2]) for p in ipc.glob('request-*.c')), default=0)
tmp = ipc / ('.request-%d' % number)
tmp.write_text(json.dumps(dict(source=(root / {source!r}).read_text(),
                              support=dict((p, (root/p).read_text()) for p in {support!r}))))
tmp.rename(ipc / ('request-%d.c' % number))
answer = ipc / ('response-%d.txt' % number)
deadline = time.time() + {timeout}
while not answer.exists():
    if time.time() > deadline:
        sys.exit('No answer from the trusted compiler; finish with your best edit.')
    time.sleep(0.25)
print(answer.read_text())
'''
REQUEST = re.compile(r'request-(\d+)\.c')
LIMIT = 1024 * 1024


def install(worker, source, timeout, support=()):
    """Before the worker manifest: the script itself must stay unchanged."""
    script = worker/'decomp-compile'
    script.write_text(SCRIPT.format(ipc=IPC, source=source, timeout=int(timeout), support=list(support)))
    script.chmod(0o755)
    (worker/IPC).mkdir(mode=0o700)


class CompileService(threading.Thread):
    def __init__(self, loop, worker, targets, directory, limit, redact=lambda text: text):
        super().__init__(daemon=True, name='decomp-compile')
        self.loop, self.targets, self.directory, self.limit = loop, targets, directory, limit
        self.function = targets[0].function
        self.original = targets[0].original
        self.count = 0
        self.redact, self.best = redact, None
        self.done = set()
        self.halt = threading.Event()
        # A directory descriptor: later symlink swaps by the worker cannot redirect our I/O.
        self.fd = os.open(worker/IPC, os.O_RDONLY | os.O_DIRECTORY | os.O_NOFOLLOW)

    def stop(self):
        self.halt.set()
        self.join()
        os.close(self.fd)

    def run(self):
        while not self.halt.wait(0.2):
            try:
                names = sorted((n for n in os.listdir(self.fd) if REQUEST.fullmatch(n) and n not in self.done),
                               key=lambda n: int(REQUEST.fullmatch(n)[1]))
            except OSError:
                return
            for name in names:
                self.done.add(name)
                number = REQUEST.fullmatch(name)[1]
                try:
                    reply = self.redact(self.answer(self.read(name), number))
                except Exception as e:  # The worker must always get an answer, never a hang.
                    reply = f'Internal harness error, not caused by your C: {type(e).__name__}: {e}'[:2000]
                atomic_write(self.directory/f'compile-{number}.txt', reply)
                self.write(f'response-{number}.txt', reply)

    def read(self, name):
        fd = os.open(name, os.O_RDONLY | os.O_NOFOLLOW, dir_fd=self.fd)
        try:
            info = os.fstat(fd)
            if not stat.S_ISREG(info.st_mode) or info.st_size > LIMIT:
                raise HarnessError('request is not a regular file below 1 MiB')
            return os.read(fd, LIMIT).decode()
        finally:
            os.close(fd)

    def write(self, name, text):
        temporary = f'.answer-{uuid.uuid4().hex}'
        fd = os.open(temporary, os.O_WRONLY | os.O_CREAT | os.O_EXCL | os.O_NOFOLLOW, 0o644, dir_fd=self.fd)
        try:
            os.write(fd, text.encode())
        finally:
            os.close(fd)
        os.replace(temporary, name, src_dir_fd=self.fd, dst_dir_fd=self.fd)

    def combined(self, text):
        """The guarded, unmarked candidate plus the targets it actually defines."""
        original = self.original.decode()
        if len(self.targets) == 1:
            symbol = self.function['symbol']
            guard_candidate(original, text, symbol)
            return text, [self.targets[0]]
        edits = split_targets(original, text, {t.function['symbol'] for t in self.targets})
        macros = {m['symbol']: m for m in global_asms(original)}
        result, position = [], 0
        for symbol in sorted((s for s, code in edits.items() if code), key=lambda s: macros[s]['start']):
            result += [original[position:macros[symbol]['start']], edits[symbol]]
            position = macros[symbol]['end']
        changed = [t for t in self.targets if edits[t.function['symbol']]]
        if not changed:
            raise HarnessError('No target directive has been replaced by C yet')
        return ''.join(result + [original[position:]]), changed

    def request(self, text):
        if self.redact(text) != text:
            raise HarnessError('Credential material rejected before compiling or persistence')
        request = json.loads(text) if text.lstrip().startswith('{') else {'source': text, 'support': {}}
        scope = self.targets[0].support if len(self.targets) == 1 else {}
        support = {p: value.encode() for p, value in request['support'].items()
                   if p not in scope or value.encode() != scope[p]}
        guard_support(scope, support)
        candidate, changed = self.combined(request['source'])
        return candidate, changed, scope, support

    def answer(self, text, number):
        self.count += 1
        if self.count > self.limit:
            return 'Compile budget for this session is exhausted. Stop editing and finish now with your best version.'
        try:
            candidate, changed, scope, support = self.request(text)
        except (HarnessError, UnicodeError, ValueError, KeyError, TypeError, AttributeError) as e:
            return f'Rejected before compiling: {e}'
        atomic_write(self.directory/f'compile-{number}.c', candidate)
        save_support(self.directory/f'compile-{number}', scope, support)
        fingerprint = json.dumps([self.loop.coordinator.expected_stamp, self.loop.config['build'],
                                  self.function['id'], self.original.decode(), candidate,
                                  {p: v.decode() for p, v in scope.items()},
                                  {p: v.decode() for p, v in support.items()}], sort_keys=True)
        key = hashlib.sha256(('probe-v1'+fingerprint).encode()).hexdigest()
        cache = self.loop.root/'.decomp-agent/probes'/f'{key}.json'
        if cache.is_file():
            feedback = json.loads(cache.read_text())
            self.record(number, candidate, support, feedback)
            return feedback['reply'] + '\n[Already compiled against this baseline; cached result. Try a different hypothesis.]'
        log = self.directory/f'compile-{number}.log'
        dumps = self.loop.object_dumps(self.targets[0], candidate.encode(), [t.function['symbol'] for t in changed],
                                       log, self.directory/f'restore-{number}.log', support)
        if dumps is None:
            noise = ('python3 ', 'tools/', 'mips-linux-gnu-', 'make: Entering', 'make: Leaving')
            lines = [l for l in log.read_text(errors='replace').splitlines() if not l.startswith(noise)]
            feedback = {'reply': 'Compile error:\n' + '\n'.join(lines[-30:])[-3000:], 'score': -1, 'plausible': False}
            save_json(cache, feedback)
            self.record(number, candidate, support, feedback)
            return feedback['reply']
        parts, comparisons = [], []
        for target in changed:
            symbol = target.function['symbol']
            comparison = score(target.reference, instructions(dumps[symbol], symbol, target.length))
            comparisons.append(comparison)
            head = f'== {symbol} ==\n' if len(self.targets) > 1 else ''
            if comparison['different_instructions'] == 0:
                parts.append(head + 'OBJECT MATCH: 0 differing instructions. Keep this C; the parent verifies the full ROM.')
            elif comparison['relocation_only']:
                parts.append(head + 'LINK CHECK READY: only relocation address bits/symbols differ. Keep this C and finish; '
                             'the parent linker and full ROM hash decide whether these are aliases.\n' + render(comparison))
            else:
                parts.append(head + render(comparison))
        feedback = {'reply': '\n'.join(parts), 'score': sum(c['score'] for c in comparisons)/len(comparisons),
                    'plausible': all(c['different_instructions'] == 0 or c['relocation_only'] for c in comparisons)}
        save_json(cache, feedback)
        self.record(number, candidate, support, feedback)
        left = self.limit - self.count
        if feedback['plausible'] or not left:
            return feedback['reply'] + f'\n[{left} compile requests left in this session]'
        return (feedback['reply'] + f'\n[Not matched; {left} compile requests left. Do not finish yet: '
                'check the diff against the IDO quirk list and compile a different hypothesis.]')

    def record(self, number, candidate, support, feedback):
        save_json(self.directory/f'compile-{number}.json', feedback)
        if len(self.targets) == 1 and feedback['score'] >= 0:
            rank = (feedback['plausible'], feedback['score'])
            if self.best is None or rank > self.best[0]:
                self.best = (rank, candidate, support)

    def retain_best(self, worker, before):
        """A last experiment or format failure must not discard a better tested C body."""
        if self.best is None:
            return
        _, candidate, support = self.best
        try:
            verify_worker_changes(worker, before, self.function['source'], self.targets[0].support)
        except HarnessError:
            return
        if self.redact(candidate) != candidate:
            return
        atomic_write(worker/self.function['source'], candidate)
        for path, original in self.targets[0].support.items():
            atomic_write(worker/path, support.get(path, original))
        return True
