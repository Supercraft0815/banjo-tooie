#!/usr/bin/env python3
"""Compare BT_TRACE JSONL files: python3 pc/native/wasm/trace_tools.py A B."""
import argparse
import hashlib
import itertools
import json
from pathlib import Path
import re
import sys


def map_defines(out):
    symbols = {}
    for line in (out / 'game.map').read_text().splitlines():
        match = re.fullmatch(r'([0-9a-f]{8})\s+[0-9a-f]+\s+[0-9a-f]+\s+(\S+)', line)
        if match:
            symbols[match[2]] = int(match[1], 16)
    names = ['D_80135490', 'D_80136EE0', 'D_80132DC2', 'D_8011B990',
             'D_8012C780', 'D_8012C78C', 'widescreen_enabled']
    lines = [f'#define TRACE_{name} 0x{symbols[name]:08x}u' for name in names]
    for i in range(3):
        address = symbols.get(f'D_8012C770.{i}')
        if address is None:
            address = symbols['D_8012C770'] + i * 4
        lines.append(f'#define TRACE_FLAGS_{i} 0x{address:08x}u')
    return lines


def trace_header(out, here, host_flags, from_gen=False):
    """Resolve this build's globals, including arrays split by LLVM's global optimizer."""
    if from_gen:
        header = out / 'gen' / 'trace_symbols.h'
        lines = [line for line in header.read_text().splitlines() if not line.startswith('#define BT_TRACE_BUILD ')]
        digest = hashlib.sha256('\n'.join(lines).encode())
        for path in sorted([*(out / 'gen').glob('*.[ch]'), *(out / 'gen').glob('*.bin')]):
            if path != header:
                digest.update(path.name.encode())
                digest.update(path.read_bytes())
    else:
        lines = map_defines(out)
        digest = hashlib.sha256((out / 'game.wasm').read_bytes())
    digest.update(json.dumps(host_flags).encode())
    for path in [here / 'build.py', Path(__file__), *sorted((here / 'host').rglob('*.[ch]'))]:
        digest.update(path.name.encode())
        digest.update(path.read_bytes())
    lines.append(f'#define BT_TRACE_BUILD "{digest.hexdigest()}"')
    return '\n'.join(lines) + '\n'


def first_difference(left, right, path=''):
    if type(left) is not type(right):
        return path, left, right
    if isinstance(left, dict):
        # The aggregate hash is last, so diagnostics name the underlying state field.
        for key in dict.fromkeys([*left, *right]):
            field = f'{path}.{key}' if path else key
            if key not in left or key not in right:
                return field, left.get(key), right.get(key)
            diff = first_difference(left[key], right[key], field)
            if diff:
                return diff
    elif isinstance(left, list):
        if len(left) != len(right):
            return path + '.length', len(left), len(right)
        for i, (a, b) in enumerate(zip(left, right)):
            diff = first_difference(a, b, f'{path}[{i}]')
            if diff:
                return diff
    elif left != right:
        return path, left, right
    return None


def read_trace(stream):
    header = json.loads(next(stream))
    fields = {'format', 'clock', 'build', 'rom', 'eeprom', 'BT_PRESS', 'BT_SCALE', 'BT_MUTE'}
    if not isinstance(header, dict) or header.keys() != fields:
        raise ValueError('incomplete trace header')
    if header['format'] != 'bt-trace-1' or header['clock'] != 'vclock-build-local':
        raise ValueError('unsupported trace header')
    return header


def read_retrace(line, count):
    row = json.loads(line)
    fields = {'retrace', 'ticks', 'framebuffer', 'map', 'players', 'actors', 'flags', 'state'}
    if not isinstance(row, dict) or row.keys() != fields:
        raise ValueError(f'incomplete retrace {count}')
    if type(row['retrace']) is not int or row['retrace'] != count:
        raise ValueError(f'missing or out-of-order retrace {count}')
    return row


def compare(left, right, cross_build=False):
    a, b = read_trace(left), read_trace(right)
    if cross_build:  # diagnostic: two builds of the same run configuration (port.py gate)
        a, b = dict(a, build=None), dict(b, build=None)
    diff = first_difference(a, b)
    if diff:
        raise ValueError(f'incompatible traces: {diff[0]}: {diff[1]!r} != {diff[2]!r}')
    count = 0
    for count, (a, b) in enumerate(itertools.zip_longest(left, right), 1):
        if a is None or b is None:
            print(f'Retrace {count}: trace ended early ({"left" if a is None else "right"})')
            return 1
        a, b = read_retrace(a, count), read_retrace(b, count)
        diff = first_difference(a, b)
        if diff:
            print(f'Retrace {count}, {diff[0]}: {diff[1]!r} != {diff[2]!r}')
            return 1
    if not count:
        raise ValueError('trace contains no retraces')
    print(f'Identical: {count} retraces (same {"run configuration" if cross_build else "build and run configuration"})')
    return 0


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('left', type=Path)
    parser.add_argument('right', type=Path)
    parser.add_argument('--cross-build', action='store_true', help='allow different build identities')
    args = parser.parse_args()
    try:
        with args.left.open() as left, args.right.open() as right:
            return compare(left, right, args.cross_build)
    except (OSError, ValueError, StopIteration, RecursionError) as error:
        print(f'Invalid trace: {error}', file=sys.stderr)
        return 2


if __name__ == '__main__':
    sys.exit(main())
