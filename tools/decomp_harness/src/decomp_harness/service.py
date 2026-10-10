"""Compile-and-diff loop for sandboxed workers, served by the trusted parent.

The worker never gets a compiler, Docker or the trusted checkout. Its `./decomp-compile`
drops the current source into `.decomp-ipc/`; the parent guards it like a final
candidate, compiles the object (a private build lane when parallel, else the trusted
workspace under the gate, then restored) and answers with a compact instruction diff.
"""
from __future__ import annotations

import os
import re
import stat
import threading
import uuid

from .common import HarnessError, atomic_write
from .guard import IPC, candidate_guard, split_targets
from .matching import instructions, render, score
from .scanner import global_asms

SCRIPT = '''#!/usr/bin/env python3
"""Compile the current source with the trusted IDO toolchain and print the diff."""
import pathlib, sys, time
root = pathlib.Path(__file__).resolve().parent
ipc = root / {ipc!r}
number = 1 + max((int(p.name[8:-2]) for p in ipc.glob('request-*.c')), default=0)
tmp = ipc / ('.request-%d' % number)
tmp.write_bytes((root / {source!r}).read_bytes())
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


def install(worker, source, timeout):
    """Before the worker manifest: the script itself must stay unchanged."""
    script = worker/'decomp-compile'
    script.write_text(SCRIPT.format(ipc=IPC, source=source, timeout=int(timeout)))
    script.chmod(0o755)
    (worker/IPC).mkdir(mode=0o700)


class CompileService(threading.Thread):
    def __init__(self, loop, worker, targets, directory, limit):
        super().__init__(daemon=True, name='decomp-compile')
        self.loop, self.targets, self.directory, self.limit = loop, targets, directory, limit
        self.function = targets[0].function
        self.original = targets[0].original
        self.count = 0
        self.done = set()
        self.halt = threading.Event()
        # A directory descriptor: later symlink swaps by the worker cannot redirect our I/O.
        self.fd = os.open(worker/IPC, os.O_RDONLY | os.O_DIRECTORY | os.O_NOFOLLOW)

    def stop(self):
        self.halt.set()
        self.join(timeout=30)
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
                    reply = self.answer(self.read(name), number)
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
            candidate_guard(original, text, symbol)
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

    def answer(self, text, number):
        self.count += 1
        if self.count > self.limit:
            return 'Compile budget for this session is exhausted. Stop editing and finish now with your best version.'
        try:
            candidate, changed = self.combined(text)
        except (HarnessError, UnicodeError) as e:
            return f'Rejected before compiling: {e}'
        log = self.directory/f'compile-{number}.log'
        dumps = self.loop.object_dumps(self.targets[0], candidate.encode(), [t.function['symbol'] for t in changed],
                                       log, self.directory/f'restore-{number}.log')
        if dumps is None:
            noise = ('python3 ', 'tools/', 'mips-linux-gnu-', 'make: Entering', 'make: Leaving')
            lines = [l for l in log.read_text(errors='replace').splitlines() if not l.startswith(noise)]
            return 'Compile error:\n' + '\n'.join(lines[-30:])[-3000:]
        parts = []
        for target in changed:
            symbol = target.function['symbol']
            comparison = score(target.reference, instructions(dumps[symbol], symbol, target.length))
            head = f'== {symbol} ==\n' if len(self.targets) > 1 else ''
            if comparison['different_instructions'] == 0:
                parts.append(head + 'OBJECT MATCH: 0 differing instructions. Keep this C; the parent verifies the full ROM.')
            else:
                parts.append(head + render(comparison))
        remaining = self.limit - self.count
        return '\n'.join(parts) + f'\n[{remaining} compile requests left in this session]'
