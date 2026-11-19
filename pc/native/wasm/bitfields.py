"""Big-endian bitfield order for the little-endian guest.

IDO allocates bitfields from the most significant bit of their storage unit, clang on wasm32
from the least significant one. Data keeps its N64 value in each unit (asm data and assets are
converted per unit), so every field must sit at the same bits of the unit's value. This pass
rewrites the bitfield members of each record in a preprocessed file (.i): each field is mirrored
inside its unit, A' = 2u + s - A - W (A: allocation bit offset, W: width, u: unit start bit,
s: unit bits), and the members are emitted in A' order with unnamed padding. A unit that also
holds ordinary members (u8 x; u32 a : 4;) shrinks to u16 or u8, the bytes the field owns.

Offsets come from clang's record layout dump; a second dump of the rewritten file checks that
ordinary members kept their offsets and every field landed at A'. Records written for the native
port already (inside #if ... BT_NATIVE ... in the original source) are left alone, as are records
from outside src/ and include/.
"""
import re
import subprocess

BITFIELD = re.compile(r':\s*\d')
SIZES = {'char': 1, 'short': 2, 'int': 4, 'long': 4, 'u8': 1, 's8': 1, 'u16': 2, 's16': 2, 'u32': 4,
         's32': 4, 'unsigned': 4, 'signed': 4, 'bool': 1, '_Bool': 1, 'uint8_t': 1, 'int8_t': 1,
         'uint16_t': 2, 'int16_t': 2, 'uint32_t': 4, 'int32_t': 4}


def type_size(t):
    words = t.replace('const', '').replace('volatile', '').split()
    if not words:
        return None
    if words[-1] in ('char', 'short', 'int', 'long') or words[0] in ('unsigned', 'signed'):
        return SIZES.get(words[-1] if words[-1] != 'unsigned' and words[-1] != 'signed' else 'int')
    return SIZES.get(words[-1])


# ---------------------------------------------------------------- clang record layout dump

def parse_dump(text):
    """Records as {'header', 'fields': [(name, type, byte, bitstart, bitend or None)], 'size'}."""
    records, cur = [], None
    for line in text.splitlines():
        if line.startswith('*** Dumping AST Record Layout'):
            cur = None
            continue
        if '|' not in line:
            continue
        left, right = line.split('|', 1)
        right = right[1:] if right.startswith(' ') else right
        left = left.strip()
        if cur is None:
            if left == '0' and re.match(r'(struct|union) ', right):
                cur = {'header': right.strip(), 'fields': [], 'size': None, 'union': right.startswith('union')}
                records.append(cur)
            continue
        if not left:
            m = re.search(r'sizeof=(\d+)', right)
            if m and cur['size'] is None:
                cur['size'] = int(m.group(1))
                cur = None
            continue
        indent = len(right) - len(right.lstrip(' '))
        if indent != 2:
            continue
        body = right.strip()
        m = re.match(r'(\d+)(?::(\d+)-(\d+))?$', left)
        if not m:
            continue
        if ')' in body and '(unnamed' in body:
            name = body[body.rindex(')') + 1:].strip()
            typ = body[:body.rindex(')') + 1]
        elif right.endswith(' '):
            name, typ = '', body  # unnamed bitfield: the dump ends the line after the type
        else:
            typ, _, name = body.rpartition(' ')
        byte = int(m.group(1))
        if m.group(2) is not None:
            cur['fields'].append((name, typ.strip(), byte, int(m.group(2)), int(m.group(3))))
        else:
            cur['fields'].append((name, typ.strip(), byte, None, None))
    return records


# ---------------------------------------------------------------- preprocessed source

def line_origins(text):
    """For each line of a .i file: (original file, original line), from the # line markers."""
    out, f, n = [], '', 0
    for line in text.split('\n'):
        m = re.match(r'# (\d+) "([^"]*)"', line)
        if m:
            out.append((None, 0))
            f, n = m.group(2), int(m.group(1))
            continue
        out.append((f, n))
        n += 1
    return out


def native_lines(path, cache):
    """Line numbers of a source file inside a conditional that mentions BT_NATIVE."""
    if path in cache:
        return cache[path]
    gated, stack = set(), []
    try:
        with open(path, errors='replace') as source:
            lines = source.read().split('\n')
    except OSError:
        lines = []
    # a conditional that names BT_ILP32 switches ILP32 to the original code, so its active branch is not gated
    native = lambda s: 'BT_NATIVE' in s and 'BT_ILP32' not in s
    for i, line in enumerate(lines, 1):
        s = line.strip()
        if re.match(r'#\s*if', s):
            stack.append(native(s))
        elif re.match(r'#\s*elif', s) and stack:
            stack[-1] = stack[-1] or native(s)
        elif re.match(r'#\s*endif', s) and stack:
            stack.pop()
        if any(stack) or 'BT_BITFIELD_ORDER(' in line:
            gated.add(i)
    cache[path] = gated
    return gated


def match_brace(text, i):
    depth = 0
    for j in range(i, len(text)):
        c = text[j]
        if c == '{':
            depth += 1
        elif c == '}':
            depth -= 1
            if depth == 0:
                return j
    return -1


def statements(text, start, end):
    """Depth-1 statements of a record body as (start, end) spans, end at the ';'."""
    out, depth, s = [], 0, start
    for j in range(start, end):
        c = text[j]
        if c in '{([':
            depth += 1
        elif c in '})]':
            depth -= 1
        elif c == ';' and depth == 0:
            out.append((s, j))
            s = j + 1
    return out


def split_top(s, sep=','):
    parts, depth, cur = [], 0, ''
    for c in s:
        if c in '([{':
            depth += 1
        elif c in ')]}':
            depth -= 1
        if c == sep and depth == 0:
            parts.append(cur)
            cur = ''
        else:
            cur += c
    parts.append(cur)
    return parts


def member_names(stmt):
    """Declared names of one member statement (bitfield flag per name) and its base type."""
    stmt = ' '.join(stmt.split())
    if '{' in stmt:
        tail = stmt[stmt.rindex('}') + 1:].strip()
        names = [n.strip() for n in split_top(tail)] if tail else ['']
        return [(re.sub(r'\[.*', '', n).strip('* '), False) for n in names], None
    m = re.match(r'^((?:(?:const|volatile|unsigned|signed|struct|union|enum)\s+)*[A-Za-z_]\w*'
                 r'(?:\s+(?:int|char|short|long))*)\s*(.*)$', stmt)
    if not m:
        return None, None
    base, rest = m.group(1), m.group(2)
    if not rest:
        return [('', False)], base
    out = []
    for d in split_top(rest):
        d = d.strip()
        bf = bool(re.search(r'^[\w\s]*:', d)) and BITFIELD.search(d) is not None
        if bf:
            name = d.split(':', 1)[0].strip()
        elif '(' in d:
            n = re.search(r'\(\s*\*+\s*(\w+)', d)
            name = n.group(1) if n else ''
        else:
            name = re.sub(r'\[.*', '', d).strip('* ').split()[-1] if d.strip('* ') else ''
        out.append((name, bf))
    return out, base


# ---------------------------------------------------------------- rewriting

def plan_record(rec):
    """New bitfield placement for one record: {field index: (unit bytes, A', W)} or None."""
    fields, size = rec['fields'], rec['size']
    owned = bytearray(size or 0)  # 1 = byte holds an ordinary member
    for i, (name, typ, byte, b0, b1) in enumerate(fields):
        if b0 is None:
            nxt = size
            for f in fields[i + 1:]:
                if f[2] > byte or f[3] is not None:
                    nxt = f[2]
                    break
            for k in range(byte, max(byte + 1, nxt)):
                if k < len(owned):
                    owned[k] = 1
    bits = []
    for name, typ, byte, b0, b1 in fields:
        if b0 is not None:
            if type_size(typ) is None:
                return None
            bits.append((byte * 8 + b0, type_size(typ)))
    plan = {}
    for i, (name, typ, byte, b0, b1) in enumerate(fields):
        if b0 is None:
            continue
        a, w = byte * 8 + b0, b1 - b0 + 1
        decl = type_size(typ)
        for s in (4, 2, 1):
            u = a - a % (s * 8)
            # a narrow field shares a wider unit with the wider fields around it (u32 x : 31; u8 y : 1;)
            if s > decl and not any(u <= b < u + s * 8 and d >= s for b, d in bits):
                continue
            u = a - a % (s * 8)
            if a + w > u + s * 8:
                continue
            if any(owned[k] for k in range(u // 8, min(len(owned), u // 8 + s))):
                continue
            plan[i] = (s, 2 * u + s * 8 - a - w, w)
            break
        else:
            return None
    return plan


def pad(cursor, end, base):
    """Unnamed bitfields of the declared type from bit `cursor` to `end`, never crossing its units."""
    out, s = [], type_size(base) * 8
    while cursor < end:
        room = min(end - cursor, s - cursor % s)
        out.append('%s : %d;' % (base, room))
        cursor += room
    return ' '.join(out)


def emit_run(items, cursor):
    """Declarations for (A', W, base type, name, unit bytes) items starting at bit `cursor`. The declared
    types stay (they set the record's alignment); padding never crosses their units."""
    out, unit, last = [], None, None
    for a, w, base, name, ubytes in sorted(items):
        here = (a - a % (ubytes * 8), ubytes * 8)
        if unit and here != unit:
            # fill and fence the finished unit: clang merges neighbouring units into one wider access
            # (u8 a : 1; u8 b : 1 -> i16), whose byte swap breaks the per-unit big-endian view
            out.append(pad(cursor, unit[0] + unit[1], last))
            out.append('char : 0;')
            cursor = unit[0] + unit[1]
        unit, last = here, base
        out.append(pad(cursor, a, base))
        out.append('%s %s : %d;' % (base, name, w))
        cursor = a + w
    return ' '.join(o for o in out if o)


def mirror(text, dump, roots, skip=(), source_runs=None):
    """Rewritten .i text and notes about records left as they were."""
    records = parse_dump(dump)
    origins = line_origins(text)
    starts = [0]
    for line in text.split('\n'):
        starts.append(starts[-1] + len(line) + 1)
    def origin(pos):
        lo, hi = 0, len(starts) - 1
        while lo < hi:
            mid = (lo + hi + 1) // 2
            if starts[mid] <= pos:
                lo = mid
            else:
                hi = mid - 1
        return origins[lo] if lo < len(origins) else (None, 0)
    gate_cache, notes, edits = {}, [], []
    # clang dumps records in the order their definitions end; same-signature records pair up in order
    by_sig = {}
    for rid, r in enumerate(records):
        if any(f[3] is not None for f in r['fields']):
            by_sig.setdefault(tuple(f[0] for f in r['fields']), []).append(rid)
    found = []
    for m in re.finditer(r'\b(struct|union)\b(\s+\w+)?\s*\{', text):
        close_at = match_brace(text, m.end() - 1)
        if close_at >= 0:
            found.append((close_at, m))
    for close_at, m in sorted(found, key=lambda x: x[0]):
        open_at = m.end() - 1
        stmts = statements(text, open_at + 1, close_at)
        members = []
        for s, e in stmts:
            names, base = member_names(text[s:e])
            if names is None:
                members = None
                break
            for n, bf in names:
                members.append((n, bf, base, s, e))
        if not members or not any(bf for _, bf, _, _, _ in members):
            continue
        f, line = origin(open_at)
        first_bf = next(s for _, bf, _, s, _ in members if bf)
        # the statement span starts after the previous ';' or '{': take the line of its first token
        bf_file, bf_line = origin(re.compile(r'\s*').match(text, first_bf).end())
        if not bf_file or not any(bf_file.startswith(r) for r in roots):
            continue
        if bf_line in native_lines(bf_file, gate_cache):
            continue
        sig = tuple(n for n, _, _, _, _ in members)
        cands = by_sig.get(sig)
        if not cands:
            notes.append('%s:%d: record not found in the layout dump' % (f, line))
            continue
        rid = cands.pop(0)
        rec = records[rid]
        if rid in skip:
            continue
        if m.group(1) == 'union' or rec['union']:
            notes.append('%s:%d: union with bitfields left as is' % (f, line))
            continue
        if len(rec['fields']) != len(members):
            notes.append('%s:%d: member count differs from the layout dump' % (f, line))
            continue
        plan = plan_record(rec)
        if plan is None:
            notes.append('%s:%d: bitfield units not mirrorable' % (f, line))
            continue
        # runs: consecutive bitfield statements (a statement is all bitfields or none)
        i = 0
        while i < len(members):
            if not members[i][1]:
                i += 1
                continue
            j = i
            while j < len(members) and members[j][1]:
                j += 1
            items = []
            for k in range(i, j):
                name, _, base, _, _ = members[k]
                ubytes, a, w = plan[k]
                items.append((a, w, base, name, ubytes))
            # clang placed the first field where the run starts; check() catches the exceptions
            cursor = rec['fields'][i][2] * 8 + rec['fields'][i][3]
            span_s, span_e = members[i][3], members[j - 1][4] + 1
            old = text[span_s:span_e]
            native = emit_run(items, cursor)
            if source_runs is not None:
                first = re.compile(r'\s*').match(text, span_s).end()
                path, first_line = origin(first)
                last_path, last_line = origin(span_e - 1)
                if path != last_path:
                    raise ValueError(f'bitfield declarations cross files at {path}:{first_line}')
                source_runs.append((path, first_line, last_line, text[first:span_e], native))
            edits.append((span_s, span_e, native + '\n' * old.count('\n')))
            i = j
    for s, e, new in sorted(edits, reverse=True):
        text = text[:s] + new + text[e:]
    return text, notes


def check(old_dump, new_dump):
    """Problems where the rewritten layouts differ from the plan."""
    old, new = parse_dump(old_dump), parse_dump(new_dump)
    if len(old) != len(new):
        return [(-1, 'record count %d -> %d' % (len(old), len(new)))]
    problems = []
    for rid, (r, n) in enumerate(zip(old, new)):
        if not any(f[3] is not None for f in r['fields']):
            continue
        if n['size'] != r['size']:
            problems.append((rid, '%s: size %s -> %s' % (r['header'], r['size'], n['size'])))
            continue
        plan = plan_record(r)
        if plan is None:
            continue
        nf = {f[0]: f for f in n['fields'] if f[0]}
        for i, f in enumerate(r['fields']):
            g = nf.get(f[0])
            if not f[0] or g is None:
                continue
            if f[3] is None:
                if g[2] != f[2]:
                    problems.append((rid, '%s: %s moved %d -> %d' % (r['header'], f[0], f[2], g[2])))
            elif g[3] is not None and plan.get(i) and g[2] * 8 + g[3] not in (plan[i][1], f[2] * 8 + f[3]):
                problems.append((rid, '%s: %s at bit %d, planned %d' % (r['header'], f[0], g[2] * 8 + g[3], plan[i][1])))
    return problems


def rewrite(text, dump_fn, roots, source_runs=None):
    """mirror() plus the layout check; records that fail it keep their original declaration."""
    d0 = dump_fn(text)
    if '*** Dumping' not in d0:
        return text, ['layout dump failed']
    selected = [] if source_runs is not None else None
    new, notes = mirror(text, d0, roots, source_runs=selected)
    probs = check(d0, dump_fn(new))
    if probs:
        bad = {rid for rid, _ in probs}
        notes += ['%s (left as is)' % msg for _, msg in probs]
        if -1 in bad:
            return text, notes
        if selected is not None:
            selected.clear()
        new, _ = mirror(text, d0, roots, bad, selected)
        left = check(d0, dump_fn(new))
        if left:
            return text, notes + ['still wrong after fallback: %s (file left as is)' % left[0][1]]
    if source_runs is not None:
        source_runs.extend(selected)
    return new, notes


def selftest(clang):
    src = '''typedef unsigned int u32; typedef unsigned char u8; typedef short s16;
struct A { u32 a : 4; unsigned int : 3; u32 b : 9; u32 c : 16; };
struct B { u8 x; u32 a : 4; u32 b : 4; u8 y; s16 z; };
struct C { u8 pad[0x70]; u32 p : 28; u32 q : 1; u32 r : 3; u32 t; };
struct D { u32 index : 23; u32 active : 1; u8 count : 8; u8 data[16]; };
struct F { u8 pad[0x70]; u8 pad70 : 7; u8 active : 1; u8 toggle : 1; u8 pad71 : 7; u8 rest[10]; };
int toggle_of(struct F *p) { return p->toggle; }
struct E {
#ifdef BT_NATIVE_LITTLE_ENDIAN
    u32 low : 8; u32 high : 24;
#endif
};
'''
    import tempfile, os
    root = tempfile.mkdtemp()
    os.mkdir(os.path.join(root, 'src'))
    path = os.path.join(root, 'src', 't.c')  # a real file: native_lines reads the #if structure
    open(path, 'w').write(src)
    pre = subprocess.run([clang, '--target=wasm32-unknown-unknown', '-DBT_NATIVE_LITTLE_ENDIAN', '-E', path],
                         capture_output=True, text=True).stdout
    def dump(t):
        return subprocess.run([clang, '--target=wasm32-unknown-unknown', '-fsyntax-only', '-x', 'cpp-output',
                               '-Xclang', '-fdump-record-layouts-complete', '-'], input=t,
                              capture_output=True, text=True).stdout
    d0 = dump(pre)
    new, notes = mirror(pre, d0, (os.path.join(root, 'src'),))
    d1 = dump(new)
    assert not notes, notes
    assert not check(d0, d1), check(d0, d1)
    lay = {r['header']: {f[0]: f for f in r['fields']} for r in parse_dump(d1)}
    a = lay['struct A']
    assert (a['a'][2] * 8 + a['a'][3], a['b'][2] * 8 + a['b'][3], a['c'][2] * 8 + a['c'][3]) == (28, 16, 0)
    b = lay['struct B']  # the unit is shared with x and y: the fields stay in byte 1
    assert (b['x'][2], b['y'][2], b['z'][2]) == (0, 2, 4)
    assert (b['a'][2] * 8 + b['a'][3], b['b'][2] * 8 + b['b'][3]) == (12, 8)
    c = lay['struct C']
    assert (c['p'][2] * 8 + c['p'][3], c['q'][2] * 8 + c['q'][3], c['r'][2] * 8 + c['r'][3], c['t'][2]) == \
        (0x70 * 8 + 4, 0x70 * 8 + 3, 0x70 * 8, 0x74)
    d = lay['struct D']  # count is the low byte of the N64 word
    assert (d['count'][2] * 8 + d['count'][3], d['active'][2] * 8 + d['active'][3], d['index'][2] * 8 + d['index'][3],
            d['data'][2]) == (0, 8, 9, 4)
    e = lay['struct E']  # written for the native port already: left alone
    assert (e['low'][2] * 8 + e['low'][3], e['high'][2] * 8 + e['high'][3]) == (0, 8)
    f = lay['struct F']  # one unit per byte, each accessed on its own
    assert (f['active'][2] * 8 + f['active'][3], f['toggle'][2] * 8 + f['toggle'][3]) == (0x70 * 8, 0x71 * 8 + 7)
    ir = subprocess.run([clang, '--target=wasm32-unknown-unknown', '-O1', '-S', '-emit-llvm', '-x', 'cpp-output',
                         '-', '-o', '-'], input=new, capture_output=True, text=True).stdout
    body = ir[ir.index('@toggle_of'):]
    assert 'load i8' in body[:body.index('\n}')], body
    print('bitfields: ok')


if __name__ == '__main__':
    import sys
    selftest(sys.argv[1] if len(sys.argv) > 1 else '/opt/homebrew/opt/llvm/bin/clang')
