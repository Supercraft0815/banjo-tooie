#!/usr/bin/env python3
"""Gives definitions the register parameters they pass through, in native builds.

IDO code defines `void f() { g(); }` and calls it as `f(a, b)`: g receives a and b
because they are still in a0/a1. The FixCalls pass adds such pass-through parameters
in IR (build/ilp32/widened.txt lists them), but clang has already dropped the extra
arguments of calls in the same file as the definition, since the definition says f
takes fewer. For each listed function with such a call, this script adds the missing
parameters to the definition under BT_NATIVE, so clang keeps the arguments:

    #ifdef BT_NATIVE
    void f(s32 bt_a0, s32 bt_a1) { g(); }
    #else
    void f() { g(); }
    #endif

    python3 pc/native/wasm/fix_passthrough.py [--dry-run]

Run it after pc/native/wasm/build.py, then build again. The N64 build is unchanged.
"""
import pathlib
import re
import sys

from fix_decls import ROOT, definition


def arg_count(text, i):
    """Number of arguments of the call whose '(' is at text[i], or None."""
    depth, n, empty = 0, 1, True
    for j in range(i, len(text)):
        c = text[j]
        if c in '([{':
            depth += 1
        elif c in ')]}':
            depth -= 1
            if depth == 0:
                return 0 if empty else n
        elif c == ',' and depth == 1:
            n += 1
        elif not c.isspace() and depth >= 1:
            empty = False
    return None


def longest_call(text, name, skip):
    """Most arguments any call of name in text passes (lines in skip are not calls)."""
    most = 0
    for m in re.finditer(r'(?<![\w.])%s\s*\(' % re.escape(name), text):
        line = text.count('\n', 0, m.start())
        if line in skip:
            continue
        start = text.rfind('\n', 0, m.start()) + 1
        if re.match(r'\s*(extern\s+|static\s+)*[A-Za-z_][\w\s\*]*\b%s\s*\([^)]*\)\s*;' % re.escape(name), text[start:]):
            continue  # a declaration
        n = arg_count(text, m.end() - 1)
        most = max(most, n or 0)
    return most


def live(lines):
    """lines with the ones inside `#if 0` blanked, so dead copies are not taken for the definition."""
    out, stack = [], []
    for line in lines:
        s = line.strip()
        if re.match(r'#\s*if', s):
            stack.append(s.split()[0] == '#if' and s.split()[1:2] == ['0'])
        elif re.match(r'#\s*(else|elif)', s) and stack:
            stack[-1] = False if stack[-1] else stack[-1]
        elif re.match(r'#\s*endif', s) and stack:
            stack.pop()
        out.append('' if any(stack) else line)
    return out


def main(dry):
    widened = [l.split() for l in (ROOT / 'build' / 'ilp32' / 'widened.txt').read_text().splitlines() if l.strip()]
    sources = [p for p in (ROOT / 'src').rglob('*') if p.suffix in ('.c', '.inc')]
    texts = {p: p.read_text(errors='replace') for p in sources}
    edits = {}  # path -> {line index: new line}
    for name, old, new in widened:
        old, new = int(old), int(new)
        for path, text in texts.items():
            if name + '(' not in text:
                continue
            lines = text.split('\n')
            found = definition(live(lines), name)
            if not found:
                continue
            i, proto = found
            line = lines[i]
            if line.rstrip().endswith('\\') or lines[i - 1].strip() == '#else' or longest_call(text, name, {i}) <= old:
                continue
            m = re.search(r'\b%s\s*\(([^()]*)\)' % re.escape(name), line)
            if not m or (m.group(1).strip() and all(re.fullmatch(r'\w+', x.strip()) for x in m.group(1).split(',')) and m.group(1).strip() != 'void'):
                print('skipped (multi-line or K&R header): %s in %s' % (name, path.relative_to(ROOT)))
                continue
            params = [p.strip() for p in m.group(1).split(',') if p.strip() and p.strip() != 'void']
            params += ['s32 bt_a%d' % k for k in range(len(params), new)]
            edits.setdefault(path, {})[i] = line[:m.start(1)] + ', '.join(params) + line[m.end(1):]
    for path, at in sorted(edits.items()):
        lines = texts[path].split('\n')
        for i in sorted(at, reverse=True):
            lines[i:i + 1] = ['#ifdef BT_NATIVE', at[i], '#else', lines[i], '#endif']
        if not dry:
            path.write_text('\n'.join(lines))
        print('%s: %d definitions' % (path.relative_to(ROOT), len(at)))
    print('%d definitions %s' % (sum(len(a) for a in edits.values()), 'to change' if dry else 'changed'))


if __name__ == '__main__':
    sys.path.insert(0, str(pathlib.Path(__file__).parent))
    main('--dry-run' in sys.argv)
