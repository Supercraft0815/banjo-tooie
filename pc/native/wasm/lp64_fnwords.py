#!/usr/bin/env python3
"""Phase-5 codemod: tables that store function addresses as `u32`/`s32` words become `BtFnWord`
(u32 under IDO, so the N64 bytes stay identical; pointer-sized natively). Finds the tables from
the LP64 compile errors ("initializer element is not a compile-time constant") and repeats until
every game file compiles for LP64. Idempotent.

  python3 pc/native/wasm/lp64_fnwords.py     # then: make check (N64), port.py gate (native)
"""
from concurrent.futures import ThreadPoolExecutor
import os
import re
import subprocess

import build
import hazards64

ERROR = re.compile(r'^(.+?):(\d+):\d+: error: initializer element is not a compile-time constant')
DECL = re.compile(r'^(\s*(?:static\s+)?)(?:u32|s32)(\s+(\w+)\s*\[[^\]]*\]\s*=)')
CAST = re.compile(r'\((?:u32|s32)\)\s*')


def errors(src):
    r = subprocess.run([build.CLANG] + hazards64.FLAGS + [str(build.ROOT / src)], capture_output=True, text=True)
    return {(m.group(1), int(m.group(2))) for m in map(ERROR.match, r.stderr.splitlines()) if m}


def fix(path, error_lines):
    lines = open(path).read().split('\n')
    names = set()
    for n in sorted(error_lines):
        i = n - 1
        while i >= 0 and not DECL.match(lines[i]):
            if lines[i].rstrip().endswith(';'):
                raise SystemExit('%s:%d: no u32/s32 table declaration above the error' % (path, n))
            i -= 1
        m = DECL.match(lines[i])
        if m:
            names.add(m.group(3))
            lines[i] = DECL.sub(r'\1BtFnWord\2', lines[i], 1)
        j = i
        while True:  # casts inside this initializer
            lines[j] = CAST.sub('(BtFnWord)', lines[j]) if j > i or '{' in lines[j] else lines[j]
            if '};' in lines[j]:
                break
            j += 1
    for k, line in enumerate(lines):  # declarations of the same tables elsewhere in the file
        for name in names:
            lines[k] = re.sub(r'^(\s*extern\s+)(?:u32|s32)(\s+%s\s*\[)' % name, r'\1BtFnWord\2', lines[k])
    open(path, 'w').write('\n'.join(lines))
    return len(names)


def main():
    srcs = [s for s in build.sources() if s.startswith('src/')]
    total = 0
    for _ in range(5):
        with ThreadPoolExecutor(os.cpu_count()) as ex:
            found = [e for es in ex.map(errors, srcs) for e in es]
        if not found:
            break
        by_file = {}
        for path, line in found:
            by_file.setdefault(path, set()).add(line)
        total += sum(fix(p, ls) for p, ls in by_file.items())
        srcs = sorted({os.path.relpath(p, build.ROOT) for p in by_file})
    print('lp64_fnwords: %d tables retyped; %d files still fail' % (total, len(found)))
    return 1 if found else 0


if __name__ == '__main__':
    raise SystemExit(main())
