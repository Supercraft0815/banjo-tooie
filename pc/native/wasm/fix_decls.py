#!/usr/bin/env python3
"""Resolves declarations that conflict with a typed prototype in native builds.

The decomp code declares callees locally, often K&R style or as `extern s32`
for a function whose address it takes. Where a typed prototype or the
definition is visible as well, clang rejects one of them ("conflicting types",
"redefinition ... as different kind of symbol"). For each such pair this
script hides the local one-line declaration in native builds:

    #ifndef BT_NATIVE
        s32 func_800CA364(s32);
    #endif

When the declaration is needed because the definition comes later in the file,
it becomes the definition's own prototype instead. The N64 build is unchanged.

    python3 pc/native/wasm/fix_decls.py [--dry-run]

Reads the compile logs of the last pc/native/wasm/build.py run.
"""
import pathlib
import re
import sys

ROOT = pathlib.Path(__file__).resolve().parents[3]
LOC = r"^(.*?):(\d+):\d+: "
ERR = re.compile(LOC + r"error: (?:conflicting types for|redefinition of|redeclaration of) '(\w+)'")
NOTE = re.compile(LOC + r"note: previous (?:declaration|definition) is here")


def is_declaration(line, names):
    s = line.strip()
    if not s.endswith(';') or '{' in s or '=' in s:
        return False
    return any(re.search(r'(^|[\s*(])%s\s*(\(|;|\[|\))' % re.escape(n), s) for n in names)


def definition(lines, name):
    """(line index, prototype text) of name's definition in the file, or None."""
    for i, line in enumerate(lines):
        if re.match(r'^[A-Za-z_][\w\s\*]*\b%s\s*\(' % re.escape(name), line) and not line.rstrip().endswith(';'):
            text, j = line, i
            while text.count('(') > text.count(')') and j + 1 < len(lines):
                j += 1
                text += ' ' + lines[j].strip()
            depth, end = 0, None
            for k, c in enumerate(text):
                if c == '(':
                    depth += 1
                elif c == ')':
                    depth -= 1
                    if depth == 0:
                        end = k
                        break
            if end is not None:
                proto = text[:end + 1].strip()
                params = proto[proto.index('(') + 1:-1].strip()
                if params and all(re.fullmatch(r'\w+', x.strip()) for x in params.split(',')) and params != 'void':
                    proto = proto[:proto.index('(')] + '()'  # K&R definition: identifiers only
                return i, proto + ';'
    return None


CALL = re.compile(r"^(.*?):(\d+):(\d+): error: too (?:few|many) arguments to function call")
DECLARED = re.compile(r"^(.*?):(\d+):(\d+): note: '(\w+)' declared here")


def return_type(line, name, col=None):
    """Return type in front of name's declaration; col (1-based) picks it on a one-line body."""
    if col:
        line = re.split(r'[;{}]', line[:col - 1])[-1] + line[col - 1:]
    m = re.match(r'^\s*(?:extern\s+|static\s+)*(.*?)\b_?%s\s*\(' % re.escape(name), line)
    return m.group(1).strip() if m else None


def fix_calls(dry):
    """K&R calls whose argument count differs from the visible prototype go through an
    unprototyped function pointer in native builds (the line is duplicated under BT_NATIVE)."""
    sites = {}  # path -> {line index: [(name, column, return type)]}
    for log in (ROOT / 'build' / 'ilp32' / 'obj').glob('*/*.log'):
        out = log.read_text().splitlines()
        for k, line in enumerate(out):
            m = CALL.match(line)
            if not m or not m.group(1).startswith(str(ROOT / 'src')):
                continue
            note = next((DECLARED.match(x) for x in out[k + 1:k + 6] if DECLARED.match(x)), None)
            if not note:
                continue
            decl = pathlib.Path(note.group(1)).read_text().split('\n')[int(note.group(2)) - 1]
            ret = return_type(decl, note.group(4), int(note.group(3)))
            if ret is None:
                continue
            sites.setdefault(m.group(1), {}).setdefault(int(m.group(2)) - 1, []).append((note.group(4), int(m.group(3)), ret))
    count = 0
    for path, at in sorted(sites.items()):
        lines = pathlib.Path(path).read_text().split('\n')
        for i in sorted(at, reverse=True):
            line = lines[i]
            if line.rstrip().endswith('\\') or (i and lines[i - 1].rstrip().endswith('\\')):
                continue
            native = line
            for name, col, ret in sorted(set(at[i]), key=lambda x: -x[1]):
                pos = native.rfind(name + '(', 0, col)
                if pos > 0 and native[pos - 1] == '_':
                    pos, name = pos - 1, '_' + name  # the overlay alias spelling
                if pos < 0 or native[pos - 1:pos].isalnum() or native[pos - 1:pos] == '_':
                    continue
                native = native[:pos] + '((%s (*)())%s)' % (ret, name) + native[pos + len(name):]
            if native != line:
                lines[i:i + 1] = ['#ifdef BT_NATIVE', native, '#else', line, '#endif']
                count += 1
        if not dry:
            pathlib.Path(path).write_text('\n'.join(lines))
    print('%d call lines rewritten' % count)


def main():
    dry = '--dry-run' in sys.argv
    fix_calls(dry)
    pairs = []  # (file, line, name, note file, note line)
    for log in (ROOT / 'build' / 'ilp32' / 'obj').glob('*/*.log'):
        out = log.read_text().splitlines()
        for k, line in enumerate(out):
            m = ERR.match(line)
            if not m:
                continue
            note = next((NOTE.match(x) for x in out[k + 1:k + 6] if NOTE.match(x)), None)
            pairs.append((m.group(1), int(m.group(2)), m.group(3),
                          note.group(1) if note else None, int(note.group(2)) if note else 0))
    files = {}

    def lines_of(path):
        if path not in files:
            files[path] = pathlib.Path(path).read_text().split('\n')
        return files[path]

    edits = {}  # path -> {line index: replacement lines}
    left = []
    for path, no, name, npath, nno in pairs:
        names = {name, '_' + name}
        # The local declaration may be the reported line or the earlier one the note points at.
        for p, n in ((path, no), (npath, nno)):
            if not p or not n or not (p.startswith(str(ROOT / 'src')) or p.startswith(str(ROOT / 'include'))):
                continue
            lines = lines_of(p)
            i = n - 1
            if i in edits.get(p, {}) or (i and lines[i - 1].strip() in ('#ifndef BT_NATIVE', '#ifdef BT_NATIVE')):
                break
            if not is_declaration(lines[i], names):
                continue
            if p.startswith(str(ROOT / 'include')):
                # A shared header: callers see the definition's prototype natively.
                d = definition(lines_of(path), name)
                if not d:
                    continue
                spelled = next(x for x in ('_' + name, name) if re.search(r'\b%s\s*\(' % x, lines[i]))
                proto = re.sub(r'\b%s\s*\(' % name, spelled + '(', d[1], count=1)
                edits.setdefault(p, {})[i] = ['#ifdef BT_NATIVE', proto, '#else', lines[i], '#endif']
                break
            d = definition(lines, name)
            if d and d[0] > i:
                repl = ['#ifdef BT_NATIVE', '    ' + d[1], '#else', lines[i], '#endif']
            else:
                repl = ['#ifndef BT_NATIVE', lines[i], '#endif']
            edits.setdefault(p, {})[i] = repl
            break
        else:
            left.append('%s:%d %s' % (pathlib.Path(path).relative_to(ROOT), no, name))
    for p, e in sorted(edits.items()):
        lines = lines_of(p)
        for i in sorted(e, reverse=True):
            lines[i:i + 1] = e[i]
        if not dry:
            pathlib.Path(p).write_text('\n'.join(lines))
    for l in left:
        print('manual:', l)
    print('%d declarations fixed in %d files, %d left for manual work' %
          (sum(len(e) for e in edits.values()), len(edits), len(left)))


if __name__ == '__main__':
    main()
