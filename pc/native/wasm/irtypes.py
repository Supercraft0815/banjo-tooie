"""Element layout of asm data labels, taken from their C declarations.

splat writes most data as .word, so the asm does not say whether a label holds
words, halfwords or bytes. The big-endian bytes only come out right on a
little-endian machine when each element is stored with its own width. The C
code that uses a label declares its type (`extern s16 D_80800212[][3];`), and
the compiled bitcode keeps that type on the external declaration. This module
reads those declarations and turns each type into scalar units (offset, size).

shortcut: bitfields come out as their storage units (byte order fixed, bit order
not), and a label no C file declares keeps the asm directive widths; type the
data in C when that matters.
"""
import re

DECL = re.compile(r'^@("?[\w.$]+"?) = external (?:\w+ )*?(?:global|constant) (.+?)(?:, align \d+)?$')
TYPEDEF = re.compile(r'^(%[\w.$"]+) = type (.+)$')
SCALARS = {'i8': 1, 'i16': 2, 'i32': 4, 'i64': 8, 'float': 4, 'double': 8, 'ptr': 4, 'half': 2}


def parse_type(s, i=0):
    """(type tree, next index). Trees: ('s', size) | ('a', n, T) | ('t', packed, [T]) | ('n', name)."""
    while s[i] == ' ':
        i += 1
    if s[i] == '[':
        m = re.compile(r'\[(\d+) x ').match(s, i)
        t, i = parse_type(s, m.end())
        assert s[i] == ']', s
        return ('a', int(m.group(1)), t), i + 1
    if s.startswith('<{', i) or s[i] == '{':
        packed = s[i] == '<'
        i += 2 if packed else 1
        fields = []
        while True:
            while s[i] == ' ':
                i += 1
            if s[i] == '}':
                return ('t', packed, fields), i + (2 if packed else 1)
            t, i = parse_type(s, i)
            fields.append(t)
            while s[i] == ' ':
                i += 1
            if s[i] == ',':
                i += 1
    if s[i] == '%':
        m = re.compile(r'%("[^"]*"|[\w.$]+)').match(s, i)
        return ('n', m.group(0)), m.end()
    m = re.compile(r'[\w]+').match(s, i)
    name = m.group(0)
    if name not in SCALARS:
        raise ValueError('type %r in %r' % (name, s))
    return ('s', SCALARS[name]), m.end()


def layout(t, named):
    """(size, align) of a type tree under the wasm32 data layout (N64 o32 sizes and alignments)."""
    if t[0] == 's':
        return t[1], t[1]
    if t[0] == 'a':
        size, align = layout(t[2], named)
        return size * t[1], align
    if t[0] == 'n':
        return layout(named[t[1]], named)
    off, align = 0, 1
    for f in t[2]:
        size, a = layout(f, named)
        if not t[1]:
            off = (off + a - 1) // a * a
            align = max(align, a)
        off += size
    return (off + align - 1) // align * align, align


def units(t, named, base, out):
    """Appends (offset, size) of every scalar in the type."""
    if t[0] == 's':
        out.append((base, t[1]))
    elif t[0] == 'n':
        units(named[t[1]], named, base, out)
    elif t[0] == 'a':
        size, _ = layout(t[2], named)
        for k in range(t[1]):
            units(t[2], named, base + k * size, out)
    else:
        off = 0
        for f in t[2]:
            size, a = layout(f, named)
            if not t[1]:
                off = (off + a - 1) // a * a
            units(f, named, base + off, out)
            off += size


def declarations(ir_lines):
    """{label: (pattern units, pattern size, repeats)} for the external globals in one module's IR."""
    named, decls = {}, []
    for line in ir_lines:
        m = TYPEDEF.match(line)
        if m:
            if m.group(2) != 'opaque':
                named[m.group(1)] = parse_type(m.group(2))[0]
            continue
        m = DECL.match(line)
        if m:
            decls.append((m.group(1).strip('"'), m.group(2)))
    out = {}
    for name, ts in decls:
        try:
            t = parse_type(ts)[0]
            # A [0 x T] (unsized array) repeats T up to the next label.
            repeat = t[0] == 'a' and t[1] == 0
            elem = t[2] if repeat else t
            u = []
            units(elem, named, 0, u)
            out[name] = (tuple(u), layout(elem, named)[0], repeat)
        except (KeyError, ValueError, AttributeError):
            continue  # opaque or unusual type: the asm widths stay
    return out


def score(decl):
    """Prefers the most informative declaration: anything over plain bytes, structs over scalars."""
    u, size, repeat = decl
    return (any(s > 1 for _, s in u), len(set(s for _, s in u)) > 1 or size > max(s for _, s in u), size)


def merge(per_module):
    """{label: decl} choosing, per label, the best declaration over all modules."""
    best = {}
    for decls in per_module:
        for name, d in decls.items():
            if d[0] and (name not in best or score(d) > score(best[name])):
                best[name] = d
    return best


def label_units(decl, start, end):
    """{address: size} for a label declared with decl, covering [start, end)."""
    u, size, repeat = decl
    out = {}
    reps = max(1, (end - start) // size) if repeat and size else 1
    for k in range(reps):
        for off, s in u:
            a = start + k * size + off
            if a + s <= end:
                out[a] = s
    return out


if __name__ == '__main__':
    named_ir = ['%struct.S = type { i16, i8, i32, [2 x i8] }',
                '@D_A = external global [0 x [3 x i16]], align 2',
                '@D_B = external global %struct.S, align 4',
                '@D_C = external local_unnamed_addr global i8, align 1']
    d = declarations(named_ir)
    assert d['D_A'] == (((0, 2), (2, 2), (4, 2)), 6, True), d['D_A']
    assert d['D_B'] == (((0, 2), (2, 1), (4, 4), (8, 1), (9, 1)), 12, False), d['D_B']
    assert label_units(d['D_A'], 0x100, 0x10C) == {0x100: 2, 0x102: 2, 0x104: 2, 0x106: 2, 0x108: 2, 0x10A: 2}
    assert merge([{'D_C': d['D_C']}, {'D_C': d['D_A']}])['D_C'] == d['D_A']
    print('ok')
