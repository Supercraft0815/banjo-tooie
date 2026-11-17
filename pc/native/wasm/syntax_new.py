#!/usr/bin/env python3
"""clang errors that the working tree has and HEAD does not, for the changed C files, parsed as the
N64 build sees them (offsets.ARGS). Codemods run it before the N64 check: IDO accepts many forms
clang rejects (K&R prototypes, incomplete enums), so only new errors count.

  syntax_new.py [FILES]     default: every src/*.c that differs from HEAD; exit 1 on new errors
"""
from concurrent.futures import ThreadPoolExecutor
import collections
import os
import re
import subprocess
import sys

import offsets

CLANG = '/opt/homebrew/opt/llvm/bin/clang'


def errors(f, text):
    r = subprocess.run([CLANG, '-fsyntax-only', '-Wno-everything', '-iquote', os.path.dirname(f)] + offsets.ARGS +
                       ['-x', 'c', '-'], input=text, capture_output=True, text=True, cwd=offsets.ROOT)
    # location-free messages, so a line that moved or a renamed type still pairs with HEAD's
    return collections.Counter(re.sub(r"'[^']*'", 'T', l.split(' error: ', 1)[1]) for l in r.stderr.splitlines()
                               if ' error: ' in l and l.startswith('<stdin>'))


NATIVE_ARGS = ['--target=wasm32-unknown-unknown', '-DBT_NATIVE=1', '-DBT_NATIVE_LITTLE_ENDIAN=1', '-DBT_ILP32=1',
               '-DBUILD_VERSION=VERSION_J', '-DF3DEX_GBI_2', '-D_FINALROM', '-D_LANGUAGE_C',
               '-isystem', 'pc/native/wasm/guest/include', '-I', 'pc/native/include', '-I', 'include',
               '-I', 'lib/ultralib/include', '-I', 'src'] + \
              (['-include', 'build/ilp32/gen/overlay_aliases.h'] if (offsets.ROOT / 'build/ilp32/gen/overlay_aliases.h').exists() else [])


def native_errors(f, text):
    """error messages (with names) of text as the native build compiles file f"""
    r = subprocess.run([CLANG, '-fsyntax-only', '-w', '-Wno-implicit-function-declaration', '-Wno-int-conversion',
                        '-Wno-incompatible-pointer-types', '-Wno-return-mismatch', '-Wno-implicit-int',  # as build.py
                        '-iquote', os.path.dirname(f)] + NATIVE_ARGS +
                       ['-x', 'c', '-'], input=text, capture_output=True, text=True, cwd=offsets.ROOT)
    return collections.Counter(l.split(' error: ', 1)[1] for l in r.stderr.splitlines()
                               if ' error: ' in l and l.startswith('<stdin>'))


def new_errors(f):
    head = subprocess.run(['git', 'show', 'HEAD:' + f], cwd=offsets.ROOT, capture_output=True, text=True).stdout
    now = (offsets.ROOT / f).read_text()
    extra = errors(f, now) - errors(f, head)
    if not extra:
        return []
    r = subprocess.run([CLANG, '-fsyntax-only', '-Wno-everything'] + offsets.ARGS + [f], capture_output=True,
                       text=True, cwd=offsets.ROOT)
    return [l for l in r.stderr.splitlines() if ' error: ' in l and
            re.sub(r"'[^']*'", 'T', l.split(' error: ', 1)[1]) in extra]


def main():
    files = sys.argv[1:] or subprocess.run(['git', 'diff', '--name-only', 'HEAD', '--', 'src/*.c'], cwd=offsets.ROOT,
                                           capture_output=True, text=True).stdout.split()
    with ThreadPoolExecutor(os.cpu_count()) as ex:
        errs = [e for es in ex.map(new_errors, files) for e in es]
    print('\n'.join(errs))
    print('syntax_new: %d new clang errors in %d files' % (len(errs), len(files)))
    return 1 if errs else 0


if __name__ == '__main__':
    sys.exit(main())
