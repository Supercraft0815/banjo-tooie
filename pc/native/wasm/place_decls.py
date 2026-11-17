#!/usr/bin/env python3
"""Place one-line generated declarations (offsets.py genstruct) without changing line numbers:
each is appended to the last top-level line ending in `;` or `}` before its first use (in a preprocessor branch
that encloses the use), else put in front of the top-level declaration that first uses it. Unused ones are
dropped. as1 schedules by line number, so the line count of every file must stay as it is; a
declaration on a function's first line changes IDO's code for it, hence the `;` line first.

  place_decls.py FILE...
"""
import re
import sys
from pathlib import Path

# one level of braces inside: anonymous unions (offsets.py unions)
BODY = r'\{(?:[^{}\n]|\{[^{}\n]*\})*\}'
DECL = re.compile(r'typedef struct ' + BODY + r' (\w+); /\* offsets\.py genstruct[^*]*\*/ ?')
PREFIX = r'(?:typedef struct ' + BODY + r' \w+; /\*[^*\n]*\*/ )*'  # generated decls in front of a definition


def blank(text, branches=True):
    """text with comments, string/char literals and every non-first #if branch replaced by spaces
    (same length and newlines), so braces can be counted on it; branches=False keeps the #if branches."""
    text = re.sub(r'//[^\n]*|/\*.*?\*/|"(?:\\.|[^"\\\n])*"|\'(?:\\.|[^\'\\\n])*\'',
                  lambda m: re.sub(r'[^\n]', ' ', m.group(0)), text, flags=re.S)
    if not branches:
        return text
    out, stack = [], []  # stack: per open #if, whether the current branch is a later one
    for line in text.split('\n'):
        s = line.strip()
        if re.match(r'#\s*if', s):
            stack.append(False)
        elif re.match(r'#\s*el', s) and stack:
            stack[-1] = True
        elif re.match(r'#\s*endif', s) and stack:
            stack.pop()
        elif any(stack):
            line = ' ' * len(line)
        out.append(line)
    return '\n'.join(out)


def place(path, keep_unused=False):
    """keep_unused: a declaration nothing uses yet (genstruct, before apply) goes in front of the
    first top-level declaration; apply places it again once its uses exist."""
    lines = path.read_text().split('\n')
    n = len(lines)
    decls = []
    for i, l in enumerate(lines):
        decls += [(m.group(1), m.group(0).rstrip()) for m in DECL.finditer(l)]
        lines[i] = DECL.sub('', l)
    code = blank('\n'.join(lines), branches=False).split('\n')
    depth, top, semi = 0, [], []  # top-level starts, top-level lines ending in `;` or `}`
    ended = True  # the previous significant line ended a declaration (or was a directive)
    stack, branch, depths = [], [], []  # branch[i]: preprocessor branches line i sits in, outermost first
    for i, l in enumerate(code):
        s = l.strip()
        cont = i > 0 and lines[i - 1].rstrip().endswith('\\')
        branch.append(tuple(stack))
        if s.startswith('#') or cont:
            # each #if branch starts at the depth before it; after #endif the first branch's depth
            # holds (branches that differ only in a function header open one brace each)
            if re.match(r'#\s*if', s):
                stack.append(i)
                depths.append([depth, None])
            elif re.match(r'#\s*el', s) and stack:
                stack[-1] = i
                if depths[-1][1] is None:
                    depths[-1][1] = depth
                depth = depths[-1][0]
            elif re.match(r'#\s*endif', s) and stack:
                stack.pop()
                first = depths.pop()[1]
                depth = depth if first is None else first
            ended = True
            continue
        if not s:
            continue
        if depth == 0 and ended:
            top.append(i)
        depth += l.count('{') - l.count('}')
        ended = depth == 0 and s.endswith((';', '}'))
        if ended and s.endswith('}'):
            semi.append(i)  # end of a function or initializer: appending there is safe too
        if depth == 0 and re.search(r';\s*(/\*.*\*/\s*)?$', l):
            semi.append(i)
    if depth != 0:
        sys.exit('%s: braces do not balance (%d); place its declarations by hand' % (path, depth))
    for name, d in decls:
        use = next((i for i, l in enumerate(lines) if re.search(r'\b%s\b' % name, l)), None)
        if use is None and keep_unused and top:
            use = top[0]
        elif use is None:
            print('%s: dropped unused %s' % (path, name))
            continue
        def visible(i):  # line i's branches enclose the use, so a declaration there is seen by it
            return branch[use][:len(branch[i])] == branch[i]
        at = max((i for i in semi if i < use and visible(i)), default=None)
        if at is not None:
            lines[at] = lines[at] + ' ' + d
        else:
            at = max(i for i in top if i <= use and visible(i))
            lines[at] = d + ' ' + lines[at]
    assert len(lines) == n
    path.write_text('\n'.join(lines))


if __name__ == '__main__':
    for f in sys.argv[1:]:
        place(Path(f))
