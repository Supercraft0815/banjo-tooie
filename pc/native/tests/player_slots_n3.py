#!/usr/bin/env python3
"""Exercise all component sizes with the LP64 player allocator and matrix path."""
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path
import argparse
import re
import subprocess
import sys
import tempfile

ROOT = Path(__file__).resolve().parents[3]


def size_providers():
    table = (ROOT / 'src/core2/player_component_sizes.inc').read_text()
    names = {name.lstrip('_') for name in re.findall(r'\{\s*-1,\s*(\w+)\s*}', table)}
    pattern = re.compile(r'\b(' + '|'.join(sorted(names)) + r')\s*\([^;{}]*\)\s*\{')
    found = {}
    for directory in ('src/core2', 'src/overlays/ba'):
        for source in (ROOT / directory).rglob('*.c'):
            for match in pattern.finditer(source.read_text()):
                name = match[1]
                if name in found:
                    raise ValueError(f'duplicate size provider {name}')
                found[name] = source
    if len(names) != 86 or set(found) != names:
        raise ValueError(f'incomplete component size table: {sorted(names - found.keys())}')
    return set(found.values())


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--cc', default='clang')
    parser.add_argument('--aliases', type=Path, default=ROOT / 'build/ilp32/gen/overlay_aliases.h')
    parser.add_argument('--sanitize', action='store_true')
    args = parser.parse_args()
    flags = ['-fno-builtin', '-fno-strict-aliasing', '-fwrapv', '-ffunction-sections', '-fdata-sections',
             '-DBT_NATIVE=1', '-D_LANGUAGE_C', '-DBUILD_VERSION=VERSION_J', '-D_FINALROM', '-DF3DEX_GBI_2',
             '-include', str(args.aliases), '-include', str(ROOT / 'pc/native/include/native_prototypes.h')]
    if sys.byteorder == 'little':
        flags.append('-DBT_NATIVE_LITTLE_ENDIAN=1')
    for directory in ('pc/native/include', 'include', 'lib/ultralib/include', 'src'):
        flags.extend(['-I', str(ROOT / directory)])
    if args.sanitize:
        flags.extend(['-fsanitize=address,undefined', '-fno-sanitize-recover=all'])
    sources = size_providers() | {ROOT / 'src/core2' / name for name in ('1ECD170.c', '1ECBCC0.c', '1EC8070.c')}
    # The provider objects also contain unported functions. The linker discards those functions.
    legacy_flags = ['-Wno-implicit-function-declaration', '-Wno-implicit-int', '-Wno-return-mismatch',
                    '-Wno-int-conversion', '-Wno-incompatible-pointer-types']
    doubles = {'1E72180.c': ['-Dfunc_80098C48=test_unused_init', '-Dfunc_80098E64=test_unused_reset'],
               '1E7D460.c': ['-Dfunc_800A4C88=test_unused_camera']}
    with tempfile.TemporaryDirectory(prefix='bt-player-components-') as directory:
        out = Path(directory)

        def compile_unit(item):
            index, source = item
            obj = out / f'{index}.o'
            cmd = [args.cc, *flags, *legacy_flags, *doubles.get(source.name, []), '-c', source, '-o', obj]
            result = subprocess.run(cmd, capture_output=True, text=True)
            if result.returncode:
                raise RuntimeError(f'{source}\n{result.stderr}')
            return obj

        with ThreadPoolExecutor(max_workers=4) as pool:
            objects = list(pool.map(compile_unit, enumerate(sorted(sources))))
        dead = '-Wl,-dead_strip' if sys.platform == 'darwin' else '-Wl,--gc-sections'
        exe = out / 'player_slots'
        subprocess.run([args.cc, *flags, dead, ROOT / 'pc/native/tests/player_slots_n3.c',
                        *objects, '-o', exe], check=True)
        subprocess.run([exe], check=True)


if __name__ == '__main__':
    main()
