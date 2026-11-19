#!/usr/bin/env python3
"""Project Clang-checked N64/ILP32 bitfield declarations back to C source.

Pass game translation units to include their headers. The default inspects every game
unit and prints planned changes. --apply updates the sources after checking all spans.
"""
import argparse
from collections import defaultdict
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path
import re
import subprocess
import sys

import bitfields
import build

TOKEN = re.compile(r'/\*.*?\*/|//[^\n]*|[A-Za-z_]\w*|0[xX][\da-fA-F]+|\d+|[^\s]', re.S)


def tokens(source):
    return [m for m in TOKEN.finditer(source) if not m[0].startswith(('/*', '//'))]


def replacements(source, runs):
    starts = [0]
    for line in source.splitlines(keepends=True):
        starts.append(starts[-1] + len(line))
    edits = []
    for (first, last, old), new in runs.items():
        wanted = [m[0] for m in tokens(old)]
        if wanted == [m[0] for m in tokens(new)]:
            continue
        offset = starts[first - 1]
        window = tokens(source[offset:starts[last]])
        actual = [m[0] for m in window]
        hits = [i for i, token in enumerate(actual) if token == wanted[0] and actual[i:i + len(wanted)] == wanted]
        if len(hits) != 1:
            raise ValueError(f'lines {first}–{last}: expected one source span, found {len(hits)}')
        matched = window[hits[0]:hits[0] + len(wanted)]
        ends = [i for i, t in enumerate(wanted) if t == ';']
        native = [s.strip() for s in new.split(';') if s.strip()]
        if not ends or ends[-1] != len(wanted) - 1 or ',' in wanted or len(native) < len(ends):
            raise ValueError(f'lines {first}–{last}: cannot pair the member declarations')
        begin = 0
        for member, end in enumerate(ends):
            left = offset + matched[begin].start()
            right = offset + matched[end].start()
            original = source[left:right]
            replacement = '; '.join(native[member:]) if member == len(ends) - 1 else native[member]
            # Mark the first member even when it is identical, so repeat runs recognize this record.
            if member == 0 or wanted[begin:end] != [m[0] for m in tokens(replacement)]:
                edits.append((left, right, f'BT_BITFIELD_ORDER({original}, {replacement})'))
            begin = end + 1
    if not edits:
        return source
    original_lines = source.splitlines(keepends=True)
    limit = len(source)
    for left, right, value in sorted(edits, reverse=True):
        if right > limit:
            raise ValueError('overlapping bitfield declarations')
        source = source[:left] + value + source[right:]
        limit = left
    return ''.join(re.sub(r'[ \t]+(?=\r?\n?$)', '', line) if line != old else line
                   for old, line in zip(original_lines, source.splitlines(keepends=True), strict=True))


def scan(unit):
    pre = subprocess.run([build.CLANG, *build.GUEST_FLAGS, '-E', str(unit)],
                         capture_output=True, text=True, check=True).stdout
    if not bitfields.BITFIELD.search(pre):
        return [], []

    def dump(source):
        # Legacy declarations can produce diagnostics after Clang has emitted its layouts.
        result = subprocess.run([build.CLANG, '--target=wasm32-unknown-unknown', '-w', '-fsyntax-only',
                                 '-x', 'cpp-output', '-Xclang', '-fdump-record-layouts-complete', '-'],
                                input=source, capture_output=True, text=True)
        if '*** Dumping AST Record Layout' not in result.stdout:
            raise ValueError(f'{unit}: missing Clang record layouts\n{result.stderr[:500]}')
        return result.stdout

    runs = []
    _, notes = bitfields.rewrite(pre, dump, tuple(str(build.ROOT / d) + '/' for d in ('src', 'include')), runs)
    return runs, notes


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('units', type=Path, nargs='*')
    parser.add_argument('-j', type=int, default=2)
    parser.add_argument('--apply', action='store_true')
    args = parser.parse_args()
    if args.j < 1:
        parser.error('-j must be positive')
    files = defaultdict(dict)
    notes = set()
    try:
        units = args.units or sorted((build.ROOT / 'src').rglob('*.c'))
        with ThreadPoolExecutor(max_workers=args.j) as pool:
            for rows, diagnostics in pool.map(scan, units):
                notes.update(diagnostics)
                for path, first, last, old, new in rows:
                    key = first, last, old
                    if files[Path(path)].setdefault(key, new) != new:
                        raise ValueError(f'{path}:{first}: translation units disagree about the layout')
        changes = {}
        for path, runs in sorted(files.items()):
            original = path.read_text()
            updated = replacements(original, runs)
            if original != updated:
                changes[path] = original, updated
                print(path.relative_to(build.ROOT))
        if args.apply:
            for path, (original, updated) in changes.items():
                if path.read_text() != original:
                    raise ValueError(f'{path} changed during scan')
                path.write_text(updated)
        for note in sorted(notes):
            print(note, file=sys.stderr)
        print(f'{len(changes)} source files changed' if args.apply else f'{len(changes)} source files would change')
    except (OSError, ValueError, subprocess.SubprocessError) as exc:
        parser.exit(1, f'bitfield conversion failed: {exc}\n')


if __name__ == '__main__':
    main()
