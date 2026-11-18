#!/usr/bin/env python3
"""Replace raw byte-offset accesses with struct fields (Phase 5: the code must not depend on
32-bit layouts).

  *(f32 *)((u8 *)actor + 0x14)  ->  actor->unk14       (field of exactly that type at 0x14)
  (Vec3f *)((s32)p + 0x2C)      ->  &p->position
  ((T *)((u8 *)p + 8))->x       ->  p->sub.x

Only bases whose type is a pointer to a complete struct qualify, and only fields whose type is
exactly the accessed type (arrays: elements, nested structs: recursion). The source is parsed
as the N64 build sees it (MIPS, no BT_NATIVE), so offsets are the IDO layout. Nested cases need
another pass; the tool repeats until nothing changes.

  offsets.py scan [FILES]           count candidates by base kind, write build/offsets.tsv
  offsets.py apply [FILES]          rewrite, log edits to build/offsets_edits.jsonl
  offsets.py revert FILE:FUNC ...   undo the logged edits inside these functions (byte-exact)
  offsets.py pad                    split byte-array padding in headers into the typed fields that
                                    remaining accesses need (layout unchanged); then apply
  offsets.py keep                   after reverting: record the remaining candidates' functions
                                    in offsets_ido_keep.txt (IDO needs the raw form there)

  offsets.py infer                  parameter types from direct callers (after scan); apply then
                                    rewrites those accesses as ((Type *)argN)->field
  offsets.py genstruct              structs for objects only reached through raw offsets (per file
                                    and argN), then apply
  offsets.py layouts [FILES]        list matching generated layouts across files for type review
  offsets.py unions                 generated structs: other types at a field's offset become union
                                    members, accesses into padding split it (after scan); then apply
  offsets.py extend [FILES]         extend generated pointer-only views to observed fields and add
                                    typed alternatives for their pointer fields; then apply
  offsets.py verify [TREE]          the whole N64 loop below in a scratch clone (default build/n64verify)
  offsets.py check [TREE]           after any codemod: make check there, list functions that differ from HEAD

Workflow: apply -> N64 build -> n64_objdiff.py lists changed functions -> revert them -> repeat
until make check is OK -> keep -> port.py gate.
"""
import collections
import json
from multiprocessing import Pool
import os
from pathlib import Path
import re

import place_decls
import subprocess
import sys

sys.path.insert(0, '/opt/homebrew/opt/llvm/lib/python3.11/site-packages')
import clang.cindex as ci  # noqa: E402

ci.Config.set_library_file('/opt/homebrew/opt/llvm/lib/libclang.dylib')
K, T = ci.CursorKind, ci.TypeKind
ROOT = Path(__file__).resolve().parents[3]
EDITS = ROOT / 'build' / 'offsets_edits.jsonl'
# Functions whose raw offset form IDO needs for matching (found by n64_objdiff.py); apply skips them.
KEEP = Path(__file__).resolve().parent / 'offsets_ido_keep.txt'
# (file, function, base text) -> 'Type *' from offsets.py infer: a parameter that every direct caller
# passes as the same struct pointer.
INFERRED_TSV = ROOT / 'build' / 'offsets_types.tsv'
INFERRED = {}
# Structs that parameters reached only through function-pointer tables may have (offsets.py infer --fit).
FIT_TYPES = ['Actor', 'PlayerState', 'ActorMarker', 'Prop', 'SynthVoice', 'MusicPlayer']
if INFERRED_TSV.exists():
    for _l in INFERRED_TSV.read_text().splitlines()[1:]:
        _f, _fn, _b, _t = _l.split('\t')
        INFERRED[(_f, _fn, _b)] = _t
ARGS = ['--target=mips-unknown-none-elf', '-m32', '-I', 'include', '-I', 'lib/ultralib/include', '-I', 'src',
        '-DBUILD_VERSION=VERSION_J', '-D_FINALROM', '-DF3DEX_GBI_2', '-D_LANGUAGE_C', '-w',
        '-Wno-int-conversion', '-Wno-incompatible-pointer-types', '-Wno-implicit-function-declaration',
        '-Wno-return-mismatch', '-Wno-implicit-int', '-ferror-limit=0']
BYTE = {T.CHAR_S, T.SCHAR, T.UCHAR, T.CHAR_U, T.VOID}
SIMPLE = re.compile(r'^[A-Za-z_]\w*(?:(?:->|\.)\w+|\[\w+\])*$')


def strip(c):
    while c.kind in (K.PAREN_EXPR, K.UNEXPOSED_EXPR):
        ch = list(c.get_children())
        if len(ch) != 1:
            break
        c = ch[0]
    return c


def operand(c):
    ch = [x for x in c.get_children() if x.kind != K.TYPE_REF]
    return ch[-1] if ch else None


def literal(c, src):
    text = src[c.extent.start.offset:c.extent.end.offset].rstrip('uUlL')
    try:
        return int(text, 0)
    except ValueError:
        return None


def bare(t):
    return re.sub(r'\b(const|volatile)\s+', '', t.get_canonical().spelling)


def field_path(rec, off, want):
    """C path ('.a.b[3]') to a field of type want at byte offset off inside record type rec."""
    for f in rec.get_fields():
        if f.is_bitfield():
            continue
        fo = f.get_field_offsetof() // 8
        ft = f.type.get_canonical()
        size = ft.get_size()
        if size <= 0 or not fo <= off < fo + size:
            continue
        if off == fo and bare(ft) == want:
            return '.' + f.spelling
        if ft.kind == T.CONSTANTARRAY:
            et = ft.element_type.get_canonical()
            es = et.get_size()
            i, rest = divmod(off - fo, es)
            if rest == 0 and bare(et) == want:
                return '.%s[%d]' % (f.spelling, i)
            if et.kind == T.RECORD:
                sub = field_path(et, rest, want)
                if sub:
                    return '.%s[%d]%s' % (f.spelling, i, sub)
        elif ft.kind == T.RECORD:
            sub = field_path(ft, off - fo, want)
            if sub:  # members of an anonymous struct/union are named directly
                return sub if not f.spelling or '(anonymous' in f.spelling else '.' + f.spelling + sub
    return None


# Types a header can always name (ultratypes.h): new fields from split padding use only these.
PLAIN = re.compile(r'^(?:u8|s8|u16|s16|u32|s32|u64|s64|f32|f64|void)(?:\s*\*+)?$|^(?:u8|s8|u16|s16|u32|s32|f32)$')
BYTE_ARRAY = re.compile(r'^(u8|s8|char|unsigned char|signed char)\s+(\w+)\s*\[\s*(0x[0-9A-Fa-f]+|\d+)\s*\]$')


def find_pad(rec, off, size, align):
    """Innermost unnamed-type byte array (u8 pad[N]) that fully holds [off, off+size) and may take a
    field of that size/alignment without changing the layout: (field cursor, offset in the
    field, offset of the field in its record, that record's field names)."""
    for f in rec.get_fields():
        if f.is_bitfield():
            continue
        fo = f.get_field_offsetof() // 8
        ft = f.type.get_canonical()
        fs = ft.get_size()
        if fs <= 0 or not fo <= off < fo + fs:
            continue
        if ft.kind == T.RECORD:
            return find_pad(ft, off - fo, size, align)
        if ft.kind == T.CONSTANTARRAY and ft.element_type.get_canonical().get_size() == 1 and \
                off + size <= fo + fs and off % align == 0 and align <= rec.get_align():
            return f, off - fo, fo, {g.spelling for g in rec.get_fields()}
        return None
    return None


def why(rec, off, want):
    """Short class of what sits at off instead of a field of type want."""
    for f in rec.get_fields():
        if f.is_bitfield():
            continue
        fo = f.get_field_offsetof() // 8
        ft = f.type.get_canonical()
        fs = ft.get_size()
        if fs <= 0 or not fo <= off < fo + fs:
            continue
        if ft.kind == T.RECORD:
            return why(ft, off - fo, want)
        if ft.kind == T.CONSTANTARRAY:
            et = ft.element_type.get_canonical()
            if et.kind == T.RECORD:
                return why(et, (off - fo) % et.get_size(), want)
            if et.get_size() == 1:
                return 'byte array (padding?)'
            return 'array element of another type' if (off - fo) % et.get_size() == 0 else 'inside an array element'
        if off != fo:
            return 'inside a field'
        if ft.kind == T.POINTER and want.endswith('*'):
            return 'pointer field of another pointer type'
        if ft.get_size() == T and False:
            return ''
        return 'field of another type (%s vs %s)' % ('same size' if ft.get_size() == 0 else ft.kind.name.lower(), want)
    return 'beyond the fields or in a bitfield'


def candidates(path):
    """(start, end, old, new, function, kind) for each rewritable access; plus base-kind counts."""
    src = Path(path).read_text(errors='surrogateescape')
    data = src.encode('utf-8', 'surrogateescape')
    if len(data) != len(src):  # byte offsets below index the text: needs plain ASCII files
        return [], collections.Counter({'non-ascii file': 1}), []
    tu = ci.Index.create().parse(path, ARGS)
    out, stats, pads = [], collections.Counter(), []

    current = [None]
    cache = {}

    def records():
        """Struct types visible in this file by spelling ('Actor', 'struct player_state_s')."""
        if not cache:
            for d in tu.cursor.get_children():
                if d.kind in (K.TYPEDEF_DECL, K.STRUCT_DECL) and d.type.get_canonical().kind == T.RECORD:
                    t = d.type.get_canonical()
                    if t.get_size() > 0:
                        cache.setdefault(d.type.spelling, t)
            cache.setdefault('', None)
        return cache

    def visit(c, parent, func):
        if c.kind == K.FUNCTION_DECL:
            func = c.spelling
        current[0] = func
        if c.kind == K.CALL_EXPR and c.location.file and c.location.file.name == path and c.spelling:
            for i, a in enumerate(c.get_arguments()):  # struct pointer arguments, for parameter types
                at = strip(a)
                while at.kind == K.CSTYLE_CAST_EXPR and operand(at) is not None:
                    at = strip(operand(at))  # (void *)actor still tells the caller's type
                t = at.type.get_canonical()
                if t.kind == T.POINTER and t.get_pointee().get_canonical().kind == T.RECORD:
                    pads.append(('CALL', c.spelling, i, at.type.spelling, func))
        if c.kind == K.CSTYLE_CAST_EXPR and c.type.get_canonical().kind == T.POINTER and \
                c.location.file and c.location.file.name == path:
            r = rewrite(c, parent)
            if r:
                kind, item = r
                stats[kind] += 1
                if item:
                    out.append(item + (func,))
        for ch in c.get_children():
            visit(ch, c, func)

    def rewrite(c, parent):
        add = strip(operand(c) or c)
        if add.kind != K.BINARY_OPERATOR or add.binary_operator != ci.BinaryOperator.Add:
            return None
        ops = [strip(x) for x in add.get_children()]
        lits = [o for o in ops if o.kind == K.INTEGER_LITERAL]
        if len(ops) != 2 or len(lits) != 1:
            return None
        inner = ops[1] if ops[0] is lits[0] else ops[0]
        off = literal(lits[0], src)
        if inner.kind != K.CSTYLE_CAST_EXPR or off is None:
            return None
        it = inner.type.get_canonical()
        if not (it.kind in (T.INT, T.UINT, T.LONG, T.ULONG) or
                (it.kind == T.POINTER and it.get_pointee().get_canonical().kind in BYTE)):
            return None  # pointer to wider type: the literal is scaled, not a byte offset
        base = strip(operand(inner))
        bt = base.type.get_canonical()
        rec = bt.get_pointee().get_canonical() if bt.kind == T.POINTER else None
        btext = src[base.extent.start.offset:base.extent.end.offset]
        cast = None
        if (rec is None or rec.kind != T.RECORD) and (path_name, current[0], btext) in INFERRED:
            cast = INFERRED[(path_name, current[0], btext)]  # parameter type from the callers
            rec = records().get(cast[:-1].strip())
        if rec is None or rec.kind != T.RECORD:
            # work list for type inference: what the base is and how it is declared
            ref = base.referenced
            origin = ref.kind.name.lower() if ref is not None and base.kind == K.DECL_REF_EXPR else base.kind.name.lower()
            pads.append(('BASE', current[0], src[base.extent.start.offset:base.extent.end.offset][:60],
                         base.type.spelling, origin, off, c.type.get_pointee().spelling))
            if origin == 'parm_decl' and FIT_TYPES:  # which candidate structs hold this access exactly
                want = bare(c.type.get_canonical().get_pointee())
                fits = [n for n in FIT_TYPES if records().get(n) is not None and field_path(records()[n], off, want)]
                pads.append(('FIT', current[0], btext, off, ' '.join(fits)))
            if rec is None:
                return ('base ' + bt.kind.name.lower(), None)
            return ('base pointer to ' + rec.kind.name.lower(), None)
        if rec.get_size() <= 0:
            return ('incomplete struct', None)
        pt = c.type.get_canonical().get_pointee()
        path = field_path(rec, off, bare(pt))
        if not path:
            pad = find_pad(rec, off, pt.get_canonical().get_size(), max(pt.get_canonical().get_align(), 1))
            ty = re.sub(r'\b(const|volatile)\s+', '', c.type.get_pointee().spelling)
            name = rec.get_declaration().spelling
            if name.startswith('Obj') and (off >= rec.get_size() or pt.kind == T.POINTER):
                pads.append(('VIEW', name, off, ty))
            if pad and pt.get_canonical().get_size() > 0 and PLAIN.match(ty):
                f, rel, fo, names = pad
                loc = f.extent
                if loc.start.file:
                    header = os.path.relpath(loc.start.file.name, ROOT)
                    pads.append((header, loc.start.offset, loc.end.offset, f.spelling, fo, rel,
                                 ty,
                                 pt.get_canonical().get_size(), tuple(sorted(names))))
            return ('no field: ' + why(rec, off, bare(pt)), None)
        if base.location.file is None or base.location.file.name != path_name or not btext:
            return ('macro', None)
        if cast:
            lv = '((%s)%s)->%s' % (cast, btext, path[1:])
        elif btext.startswith('&') and SIMPLE.match(btext[1:].strip()):  # &object: object.field
            lv = btext[1:].strip() + path
        else:
            lv = (btext if SIMPLE.match(btext) else '(%s)' % btext) + '->' + path[1:]
        s, e = c.extent.start.offset, c.extent.end.offset
        if parent is not None and parent.kind == K.PAREN_EXPR:
            s, e = parent.extent.start.offset, parent.extent.end.offset
        # context: *C -> lvalue; C->m -> lvalue.m; otherwise &lvalue
        return ('rewritten', (s, e, lv))

    path_name = path
    visit(tu.cursor, None, None)
    # Context is easier on the text: '*' right before the cast (with optional parens) or '->' after.
    items = []
    for s, e, lv, func in sorted(out):
        before = src[:s].rstrip()
        after = src[e:]
        if before.endswith('*') and not re.search(r'[\w)\]]\s*\*$', before):
            # unary '*': walk back over it (and an enclosing '(' pair is left as is)
            star = len(before) - 1
            items.append((star, e, src[star:e], lv, func))
        elif re.match(r'\s*\[', after):  # ((T *)(p + 0x17C))[i]: index from that field
            items.append((s, e, src[s:e], '(&' + lv + ')', func))
        elif re.match(r'\s*->\s*\w', after):
            m = re.match(r'\s*->\s*', after)
            items.append((s, e + m.end(), src[s:e + m.end()], lv + '.', func))
        else:
            items.append((s, e, src[s:e], '&' + lv, func))
    chosen, last = [], -1
    for it in sorted(items):  # drop overlaps (nested cases: next pass)
        if it[0] >= last:
            chosen.append(it)
            last = it[1]
    return chosen, stats, pads


def work(path):
    try:
        return path, candidates(path)
    except Exception as e:  # noqa: BLE001 (one bad file must not stop the run)
        return path, ([], collections.Counter({'parse failure: %s' % type(e).__name__: 1}), [])


def split_pads(results):
    """Split byte-array padding in the headers into typed fields where accesses need them. Layout
    stays identical (size and alignment checked); arrays whose name the code uses stay."""
    want = collections.defaultdict(set)  # (header, start, end, name, field offset) -> {(rel, type, size)}
    names = {}
    for _, (_, _, pads) in results:
        for header, s, e, name, fo, rel, ty, size, existing in (x for x in pads if len(x) == 9):
            want[(header, s, e, name, fo)].add((rel, ty, size))
            names[(header, s, e, name, fo)] = set(existing)
    code = '\n'.join(p.read_text(errors='replace') for p in (ROOT / 'src').rglob('*.[ch]')) + \
        '\n'.join(p.read_text(errors='replace') for p in (ROOT / 'include').rglob('*.h'))
    by_header = collections.defaultdict(list)
    skipped = collections.Counter()
    for key, fields in want.items():
        header, s, e, name, fo = key
        text = (ROOT / header).read_text()[s:e]
        m = BYTE_ARRAY.match(text.strip())
        if not m or m.group(2) != name:
            skipped['declaration not a plain byte array'] += 1
            continue
        if re.search(r'(->|\.)\s*%s\b' % re.escape(name), code):
            skipped['padding array used by name'] += 1
            continue
        total, elem = int(m.group(3), 0), m.group(1)
        segs, pos, taken = [], 0, set(names[key])
        for rel, ty, size in sorted(fields):
            if rel < pos:  # overlaps the previous new field (different types at one offset)
                continue
            fname = 'unk%X' % (fo + rel)
            if fname in taken:
                continue
            if rel > pos:
                segs.append('%s %s[0x%X]' % (elem, 'pad%X' % (fo + pos), rel - pos))
            segs.append('%s %s' % (ty, fname))
            taken.add(fname)
            pos = rel + size
        if pos < total:
            segs.append('%s %s[0x%X]' % (elem, 'pad%X' % (fo + pos), total - pos))
        if not any(' unk' in x for x in segs):
            continue
        by_header[header].append((s, e, '; '.join(segs)))
    n = 0
    for header, edits in by_header.items():
        p = ROOT / header
        text = p.read_text()
        for s, e, new in sorted(edits, reverse=True):
            text = text[:s] + new + text[e:]
            n += 1
        p.write_text(text)
    print('pad: %d padding arrays split in %d headers; skipped %s' % (n, len(by_header), dict(skipped)))


def game_files(args):
    os.chdir(ROOT)
    return args or sorted(str(p.relative_to(ROOT)) for p in (ROOT / 'src').rglob('*.c'))


def apply_edits(path, items, log):
    src = Path(path).read_text()
    for s, e, old, new, func in sorted(items, reverse=True):
        assert src[s:e] == old
        src = src[:s] + new + src[e:]
        log.write(json.dumps({'file': path, 'func': func, 'old': old, 'new': new}) + '\n')
    Path(path).write_text(src)


def restore_head(f, func, edits):
    """Line by line, put back HEAD's text of func wherever the line equals HEAD's once the logged
    edits are applied to both (raw and field forms of the same access count as equal). Lines that
    differ in other ways (port changes) stay. Every definition of func counts (`#ifdef BT_NATIVE`
    variants come first). False when a definition cannot be lined up with HEAD."""
    p = ROOT / f
    text = p.read_text()
    head = subprocess.run(['git', 'show', 'HEAD:' + f], cwd=ROOT, capture_output=True, text=True).stdout
    spans, hspans = bodies(text, func), bodies(head, func)
    if not spans or len(spans) != len(hspans):
        return False

    def norm(line):
        for e in edits:  # oldest first, as apply wrote them
            line = line.replace(e['old'], e['new'])
        return line
    for (lo, hi), (hlo, hhi) in reversed(list(zip(spans, hspans))):
        lo += re.match(place_decls.PREFIX, text[lo:hi]).end()
        cur, old = text[lo:hi].split('\n'), head[hlo:hhi].split('\n')
        if len(cur) != len(old):
            return False
        out = [a if b == a or norm(a) == norm(b) else b for a, b in zip(old, cur)]
        text = text[:lo] + '\n'.join(out) + text[hi:]
    p.write_text(text)
    return True


def bodies(text, func):
    """Byte ranges of every definition of func (header to closing brace)."""
    out = []
    # braces in comments and strings don't count; nor in later #if branches, unless the definition
    # sits in one (a header written once per branch would count its brace twice)
    first, every = place_decls.blank(text), place_decls.blank(text, branches=False)
    for m in re.finditer(r'^' + place_decls.PREFIX + r'[A-Za-z_][^;\n{}()=]*?\b%s\s*\([^;{}]*\)\s*\{'
                         % re.escape(func or '#'), text, re.M):  # a generated one-line struct may precede it
        depth, i = 0, m.end() - 1
        code = first if first[i] == '{' else every
        while i < len(text):
            depth += {'{': 1, '}': -1}.get(code[i], 0)
            if depth == 0:
                break
            i += 1
        if depth:
            return []
        out.append((m.start(), i + 1))
    return out


def infer():
    """Parameter types from callers (needs a scan first): argN of F gets type R when every direct
    call of F passes a pointer to the struct R there (casts stripped)."""
    import csv
    calls = collections.defaultdict(collections.Counter)
    for r in csv.DictReader((ROOT / 'build' / 'offsets_calls.tsv').open(), delimiter='\t'):
        calls[(r['callee'], int(r['arg']))][r['arg_type'].replace('struct player_state_s *', 'PlayerState *')] += 1
    out = set()
    for r in csv.DictReader((ROOT / 'build' / 'offsets_bases.tsv').open(), delimiter='\t'):
        m = re.match(r'arg(\d+)$', r['base'])
        if r['origin'] != 'parm_decl' or not m:
            continue
        c = calls.get((r['function'], int(m.group(1))))
        if c and len(c) == 1:
            out.add((r['file'], r['function'], r['base'], next(iter(c))))
    if '--fit' in sys.argv:
        # no typed caller: one struct must hold every access of the parameter exactly, at >= 3 offsets
        typed = {(f, fn, b) for f, fn, b, _ in out}
        groups = collections.defaultdict(list)
        for r in csv.DictReader((ROOT / 'build' / 'offsets_fits.tsv').open(), delimiter='\t'):
            groups[(r['file'], r['function'], r['base'])].append((int(r['offset']), set(r['fits'].split())))
        for key, acc in groups.items():
            if key in typed or len({o for o, _ in acc}) < 3:
                continue
            common = set.intersection(*(f for _, f in acc))
            if len(common) == 1:
                out.add(key + (next(iter(common)) + ' *',))
    if INFERRED_TSV.exists():  # keep genstruct's entries: their structs now exist in the sources
        out |= {tuple(l.split('\t')) for l in INFERRED_TSV.read_text().splitlines()[1:] if '\tObj' in l}
    INFERRED_TSV.write_text('file\tfunction\tbase\ttype\n' + ''.join('\t'.join(x) + '\n' for x in sorted(out)))
    print('infer: %d parameters typed from their callers -> %s' % (len(out), INFERRED_TSV))


SIZES = {'u8': 1, 's8': 1, 'u16': 2, 's16': 2, 'u32': 4, 's32': 4, 'f32': 4, 'f64': 8}
GEN_FIELD = re.compile(r'^(?:(?:u8|s8|u16|s16|u32|s32|f32|f64|void)\s*\*+|struct \w+ \*+|u8|s8|u16|s16|u32|s32|f32|f64)$')
# function pointers over plain types: s32 (*)(s32, void *, s32) -> s32 (*unk248)(s32, void *, s32)
FN_FIELD = re.compile(r'^(?:void|u8|s8|u16|s16|u32|s32|f32|f64)(?: \*+)? \(\*\)\((?:void|(?:(?:u8|s8|u16|s16|u32|s32|f32|f64|void)(?: \*+)?(?:, )?)+)\)$')


def genstruct():
    """Structs for objects only reached through raw offsets (needs a scan): per file and parameter
    argN (no caller type), per function and named parameter or local, and per file and global
    `&D_…`, one struct holding every access at its offset with exactly the accessed type (plain
    types, pointers, function pointers), padding between. Groups with two types at one offset, or overlapping fields, stay for
    agents. Writes the typedef after the file's includes and an offsets_types.tsv entry per function,
    so apply rewrites the accesses as ((Name *)argN)->unkXX."""
    import csv
    typed = {}
    if INFERRED_TSV.exists():
        for r in csv.DictReader(INFERRED_TSV.open(), delimiter='\t'):
            typed[(r['file'], r['function'], r['base'])] = r['type']
    groups = collections.defaultdict(list)
    for r in csv.DictReader((ROOT / 'build' / 'offsets_bases.tsv').open(), delimiter='\t'):
        f, fn, base = r['file'], r['function'], r['base']
        if (f, fn, base) in typed:
            continue
        if r['origin'] == 'parm_decl' and re.fullmatch(r'arg\d', base):
            key = base  # one struct per file and argN, shared by the file's functions
        elif r['origin'] in ('parm_decl', 'var_decl') and re.fullmatch(r'\w+', base):
            key = '%s_%s' % (fn, base)  # a named parameter or local: one struct per function
        elif r['origin'] == 'unary_operator' and re.fullmatch(r'&D_\w+', base):
            key = base[1:]  # a global reached through offsets: one struct per file and symbol
        else:
            continue
        groups[(f, key)].append((int(r['offset'], 16), re.sub(r'\s+', ' ', r['access_type'].strip()), fn, base))
    rows, made, skipped = [], 0, collections.Counter()
    for (f, base), acc in sorted(groups.items()):
        types = collections.defaultdict(collections.Counter)
        for off, ty, _, _ in acc:
            types[off][ty] += 1
        fields, end, ok = [], 0, True
        for off in sorted(types):
            ty = types[off].most_common(1)[0][0]  # other types at this offset stay raw accesses
            fnptr = FN_FIELD.match(ty)
            if not GEN_FIELD.match(ty) and not fnptr:
                continue
            size = 4 if '*' in ty else SIZES[ty]
            if off < end or off % size:  # overlaps the previous field or misaligned: stays raw
                continue
            if off > end:
                fields.append('u8 pad%X[0x%X];' % (end, off - end))
            fields.append(ty.replace('(*)', '(*unk%X)' % off, 1) + ';' if fnptr else '%s unk%X;' % (ty, off))
            end = off + size
        if not fields:
            skipped['no field type a struct can name'] += 1
            continue
        name = 'Obj%s_%s' % (re.sub(r'\W', '_', Path(f).stem), base)
        base = acc[0][3]
        text = (ROOT / f).read_text()
        while re.search(r'\b%s\b' % name, text):  # an earlier round's struct: these accesses did not fit it
            name += '_'
        # one line, placed by place_decls.py: as1 schedules by line number, so no line may move
        decl = ('typedef struct { %s } %s; /* offsets.py genstruct: fields from raw offsets on %s; '
                'rename once understood */ ' % (' '.join(fields), name, base))
        (ROOT / f).write_text(decl + text)
        place_decls.place(ROOT / f, keep_unused=True)
        made += 1
        rows += [(f, fn, b, name + ' *') for fn, b in sorted({(fn, b) for _, _, fn, b in acc})]
    with INFERRED_TSV.open('a') as out:
        for r in rows:
            out.write('\t'.join(r) + '\n')
    print('genstruct: %d structs written, %d functions typed; skipped %s' % (made, len(rows), dict(skipped)))


def layouts(files):
    """Group generated declarations by their complete fields, including union members and padding."""
    declaration = re.compile(r'typedef struct \{ ((?:[^{}\n]|\{[^{}\n]*\})*) \} (Obj\w+); '
                             r'/\* offsets.py genstruct: fields from raw offsets on ([^;]+);')
    groups = collections.defaultdict(list)
    for path in files:
        for fields, name, base in declaration.findall(Path(path).read_text()):
            groups[' '.join(fields.split())].append((path, name, base))
    for fields, views in sorted(groups.items()):
        if len({path for path, _, _ in views}) > 1:
            yield fields, views


def unions(views=None):
    """Generated structs whose remaining raw accesses read another type at a field's offset, or
    reach into padding (needs a scan): the type joins the field in an anonymous union
    (`union { s32 unk20; u8 *unk20_u8p; };`, IDO accepts it; layout unchanged), or the padding
    splits around a new field. Then apply."""
    import csv
    typed = {}
    want = collections.defaultdict(set)
    if views is not None:
        for f, (_, _, records) in views:
            for row in records:
                if row[0] == 'VIEW':
                    _, name, off, ty = row
                    want[(f, name)].add((off, ty))
    else:
        for r in csv.DictReader(INFERRED_TSV.open(), delimiter='\t'):
            if r['type'].startswith('Obj'):
                typed[(r['file'], r['function'], r['base'])] = r['type'][:-1].strip()
        for r in csv.DictReader((ROOT / 'build' / 'offsets_bases.tsv').open(), delimiter='\t'):
            name = typed.get((r['file'], r['function'], r['base']))
            if name:
                want[(r['file'], name)].add((int(r['offset'], 16), re.sub(r'\s+', ' ', r['access_type'].strip())))
    changed, added = set(), 0
    for (f, name), accs in sorted(want.items()):
        text = (ROOT / f).read_text()
        m = re.search(r'typedef struct \{ ((?:[^{}\n]|\{[^{}\n]*\})*) \} %s; ' % re.escape(name), text)
        if not m:
            continue
        if views is not None:
            if not text[m.end():].startswith('/* offsets.py genstruct:'):
                continue
            rest = text[:m.start()] + text[m.end():]
            # Only direct member selections can grow. A cast used in pointer arithmetic also depends on sizeof.
            selection = r'\(\s*\(\s*%s\s*\*\s*\)\s*&?\s*\w+\s*\)\s*->' % re.escape(name)
            if re.search(r'\b%s\b' % re.escape(name), re.sub(selection, '', rest)):
                continue
        # elements: [offset, size, members] with members [(type, name)]; padding has members None
        elems = []
        for part in re.findall(r'(?:union \{[^{}]*\}|[^;{}])+;', m.group(1)):
            part = part.strip()[:-1].strip()
            if part.startswith('union'):
                mems = [x.strip() for x in part[part.index('{') + 1:part.rindex('}')].split(';') if x.strip()]
            else:
                mems = [part]
            pm = re.match(r'u8 pad([0-9A-F]+)\[0x([0-9A-F]+)\]$', mems[0])
            if pm:
                elems.append([int(pm.group(1), 16), int(pm.group(2), 16), None])
                continue
            parsed = []
            for x in mems:
                fm = re.search(r'unk([0-9A-F]+)(?:_\w+)?\b', x)
                ty = re.sub(r'\(\*unk\w+\)', '(*)', x) if '(*unk' in x else x[:fm.start()].strip()
                parsed.append((ty, fm.group(0)))
            off = int(re.search(r'unk([0-9A-F]+)', parsed[0][1]).group(1), 16)
            size = max(4 if '*' in t or t in ('BtIntPtr', 'BtUIntPtr', 'BtFnWord') else SIZES.get(t, 0) for t, _ in parsed)
            elems.append([off, size, parsed])
        if not elems or any(size <= 0 for _, size, _ in elems):
            continue
        original_count = added
        for off, ty in sorted(accs):
            if not (GEN_FIELD.match(ty) or FN_FIELD.match(ty)):
                continue
            size = 4 if '*' in ty else SIZES[ty]
            e = next((e for e in elems if e[0] <= off < e[0] + e[1]), None)
            if off % size:
                continue
            if e is None:
                end = elems[-1][0] + elems[-1][1]
                if views is None or off < end:
                    continue
                if off > end:
                    elems.append([end, off - end, None])
                elems.append([off, size, [(ty, 'unk%X' % off)]])
                added += 1
                changed.add(f)
                continue
            tag = 'fn' if FN_FIELD.match(ty) else ty.replace(' ', '').replace('*', 'p')
            if e[2] is None:  # padding: split it around the new field
                if off + size > e[0] + e[1]:
                    continue
                i = elems.index(e)
                parts = [[e[0], off - e[0], None], [off, size, [(ty, 'unk%X' % off)]],
                         [off + size, e[0] + e[1] - off - size, None]]
                elems[i:i + 1] = [x for x in parts if x[1] > 0]
            elif e[0] == off and size <= e[1] and ty not in (t for t, _ in e[2]):
                stem = 'unk%X_%s' % (off, tag)
                names = {member for _, member in e[2]}
                member_name = stem
                suffix = 2
                while member_name in names:
                    member_name = stem + str(suffix)
                    suffix += 1
                e[2].append((ty, member_name))
            else:
                continue
            added += 1
            changed.add(f)

        if added == original_count:
            continue
        def member(ty, nm):
            return ty.replace('(*)', '(*%s)' % nm, 1) + ';' if FN_FIELD.match(ty) else '%s %s;' % (ty, nm)
        out = []
        for off, size, mems in elems:
            if mems is None:
                out.append('u8 pad%X[0x%X];' % (off, size))
            elif len(mems) == 1:
                out.append(member(*mems[0]))
            else:
                out.append('union { %s };' % ' '.join(member(*x) for x in mems))
        text = text[:m.start(1)] + ' '.join(out) + text[m.end(1):]
        (ROOT / f).write_text(text)
    print('%s: %d fields or union members added in %d files' % ('extend' if views is not None else 'unions', added, len(changed)))


def docker_make(tree, flags=''):
    log = tree.parent / (tree.name + '.log')
    with log.open('w') as f:
        r = subprocess.run(['docker', 'run', '--rm', '--platform', 'linux/amd64', '--mount',
                            'type=bind,source=%s,target=/work' % tree, '--workdir', '/work',
                            '--user', '%d:%d' % (os.getuid(), os.getgid()), '--env', 'HOME=/tmp',
                            '--network', 'none', 'banjo-tooie-decomp:local', 'sh', '-c',
                            '[ -d asm ] || python3 tools/splat/split.py baserom.us.yaml >/dev/null 2>&1; make %s -j8 check' % flags],
                           stdout=f, stderr=subprocess.STDOUT)
    return r.returncode == 0 and log.read_text().rstrip().endswith('OK'), log


def sync(tree):
    # tracked and new (untracked, not ignored) files: a new header must reach the clone too
    files = subprocess.run(['git', 'ls-files', '-z', '--cached', '--others', '--exclude-standard'], cwd=ROOT,
                           capture_output=True, check=True).stdout
    subprocess.run(['rsync', '-a', '--from0', '--files-from=-', './', str(tree) + '/'], cwd=ROOT, input=files, check=True)
    # a fresh clone also needs what git does not list: submodules, toolchain, extracted ROM parts
    for p in subprocess.run(['git', 'submodule', '--quiet', 'foreach', 'echo $sm_path'], cwd=ROOT, capture_output=True,
                            text=True).stdout.split() + ['tools/ido', 'tools/ido7.1', 'tools/n64crc', 'tools/overlay_processor',
                                                         'tools/rom_compressor', 'tools/rom_decompressor', 'tools/syscall_builder',
                                                         'baserom.us.z64', 'decompressed.us.z64', 'assets/overlays']:
        if not (tree / p).exists() or ((tree / p).is_dir() and not any((tree / p).iterdir())):
            (tree / p).parent.mkdir(parents=True, exist_ok=True)
            subprocess.run(['rm', '-rf', str(tree / p)], check=True)
            subprocess.run(['cp', '-cR', str(ROOT / p), str(tree / p)], check=True)
    # rsync keeps the sources' old mtimes; objects built since then would look up to date
    changed = subprocess.run(['git', 'diff', '--name-only', 'HEAD'], cwd=ROOT, capture_output=True,
                             text=True, check=True).stdout.split()
    changed += subprocess.run(['git', 'ls-files', '--others', '--exclude-standard', 'include', 'src'], cwd=ROOT,
                              capture_output=True, text=True, check=True).stdout.split()
    if changed:
        subprocess.run(['touch'] + [str(tree / f) for f in changed if (tree / f).exists()], check=True)


def verify(tree):
    """N64 check of the logged rewrites: build HEAD's sources as the base, then the working tree;
    revert every function whose object code changed; repeat until make check is OK; record the
    rejected functions (keep). Needs the decomp Docker image and baserom.us.z64."""
    tree = tree.resolve()
    edits = [json.loads(l) for l in EDITS.read_text().splitlines()] if EDITS.exists() else []
    files = sorted({e['file'] for e in edits})
    if not files:
        print('verify: no logged edits')
        return
    tree.mkdir(parents=True, exist_ok=True)
    sync(tree)
    # base objects: the committed sources (HEAD matches); uncommitted changes outside the
    # rewritten functions must not change code, which the final make check confirms
    changed = subprocess.run(['git', 'diff', '--name-only', 'HEAD'], cwd=ROOT, capture_output=True,
                             text=True, check=True).stdout.split()
    for f in changed:
        head = subprocess.run(['git', 'show', 'HEAD:' + f], cwd=ROOT, capture_output=True, check=True).stdout
        (tree / f).write_bytes(head)
    ok, log = docker_make(tree)
    if not ok:
        sys.exit('verify: HEAD does not match; see %s' % log)
    subprocess.run(['rm', '-rf', str(tree / 'build.base')], check=True)
    subprocess.run(['cp', '-cR', str(tree / 'build'), str(tree / 'build.base')], check=True)
    rejected = set()
    try:
        for round_ in range(1, 8):
            sync(tree)
            ok, log = docker_make(tree)
            # every C file that differs from HEAD, also ones whose edits were all reverted
            live = subprocess.run(['git', 'diff', '--name-only', 'HEAD', '--', 'src/*.c'], cwd=ROOT,
                                  capture_output=True, text=True, check=True).stdout.split()
            bad = subprocess.run([sys.executable, str(Path(__file__).with_name('n64_objdiff.py')), str(tree),
                                  'build.base', 'build'] + live, capture_output=True, text=True, check=True).stdout.split()
            print('verify round %d: make check %s, %d functions differ' % (round_, 'OK' if ok else 'FAIL', len(bad)))
            if ok and not bad:
                break
            if not bad:
                sys.exit('verify: make check fails outside the rewritten functions; see %s' % log)
            rejected |= {b for b in bad if not b.endswith(':<data>')}
            before = EDITS.read_text()
            sys.argv = [sys.argv[0], 'revert'] + bad
            main()
            if EDITS.read_text() == before:  # e.g. a declaration placed on the function's line, a header change
                sys.exit('verify: these functions differ but carry no logged edit: %s' % ' '.join(bad))
        else:
            sys.exit('verify: make check still fails after %d rounds; see %s' % (round_, log))
    finally:  # also when stopping early, so the next apply does not rewrite them again
        old = set(KEEP.read_text().split()) if KEEP.exists() else set()
        KEEP.write_text(''.join(x + '\n' for x in sorted(old | rejected)))
    print('verify: %d functions newly rejected by IDO, %d in %s' % (len(rejected), len(old | rejected), KEEP.name))


def main():
    cmd, args = sys.argv[1], sys.argv[2:]
    if cmd == 'layouts':
        for fields, views in layouts(game_files(args)):
            print(fields)
            for path, name, base in views:
                print(f'  {path}\t{name}\t{base}')
        return
    if cmd == 'infer':
        return infer()
    if cmd == 'genstruct':
        return genstruct()
    if cmd == 'unions':
        return unions()
    if cmd == 'verify':
        return verify(Path(args[0]) if args else ROOT / 'build' / 'n64verify')
    if cmd == 'check':  # any codemod: make check plus the functions that differ from HEAD's objects
        tree = (Path(args[0]) if args else ROOT / 'build' / 'n64verify').resolve()
        if not (tree / 'build.base').exists():
            sys.exit('check: run verify once first (it builds HEAD into %s/build.base)' % tree)
        sync(tree)
        ok, log = docker_make(tree)
        live = subprocess.run(['git', 'diff', '--name-only', 'HEAD', '--', 'src/*.c'], cwd=ROOT,
                              capture_output=True, text=True, check=True).stdout.split()
        diff = subprocess.run([sys.executable, str(Path(__file__).with_name('n64_objdiff.py')), str(tree),
                               'build.base', 'build', '--linked'] + live, capture_output=True, text=True, check=True).stdout
        log.with_suffix('.objdiff').write_text(diff)
        # Moving asm data into C changes object ownership; make check still verifies every ROM byte.
        bad = [item for item in diff.split() if not item.endswith(':<data>')]
        data_count = sum(item.endswith(':<data>') for item in diff.split())
        print('check: make check %s, %d functions differ from HEAD, %d object data sections differ%s' % (
            'OK' if ok else 'FAIL (%s)' % log, len(bad), data_count, ''.join('\n  ' + b for b in bad[:40])))
        return 0 if ok and not bad else 1
    if cmd == 'revert':
        wanted = {tuple(a.split(':', 1)) for a in args}
        edits = [json.loads(l) for l in EDITS.read_text().splitlines()]
        keep = [e for e in edits if (e['file'], e['func']) not in wanted]
        for f, func in sorted(wanted):
            mine = [e for e in edits if (e['file'], e['func']) == (f, func)]
            # this function's own edits first: other functions may map the same raw text differently
            others = [e for e in edits if e['file'] == f and e['func'] != func]
            if not restore_head(f, func, [e for e in edits if (e['file'], e['func']) == (f, func)] + others):
                print('revert: %s:%s not found or not aligned with HEAD; left as is' % (f, func))
        EDITS.write_text(''.join(json.dumps(e) + '\n' for e in keep))
        print('reverted %d edits' % (len(edits) - len(keep)))
        return
    files = game_files(args)
    keep = set(KEEP.read_text().split()) if KEEP.exists() and cmd != 'keep' else set()
    found = set()
    edited_files = set()
    total = collections.Counter()
    rows = []
    passes = 0
    while True:
        passes += 1
        with Pool(os.cpu_count()) as pool:
            results = pool.map(work, files)
        if cmd == 'extend':
            return unions(results)
        changed = 0
        with EDITS.open('a') as log:
            for path, (items, stats, _) in results:
                kept = sum(1 for i in items if '%s:%s' % (path, i[4]) in keep)
                if kept:
                    stats['rewritten'] -= kept
                    stats['IDO needs the raw form (offsets_ido_keep.txt)'] += kept
                    stats += collections.Counter()  # drop zero counts
                if passes == 1:
                    total.update(stats)
                    rows += ['%s\t%s\t%d' % (path, k, n) for k, n in stats.items()]
                items = [i for i in items if '%s:%s' % (path, i[4]) not in keep]
                if cmd == 'keep':
                    found.update('%s:%s' % (path, i[4]) for i in items)
                if cmd == 'apply' and items:
                    apply_edits(path, items, log)
                    edited_files.add(path)
                    changed += len(items)
        if cmd == 'pad':
            split_pads(results)
            break
        if passes == 1:
            with (ROOT / 'build' / 'offsets_bases.tsv').open('w') as f:
                f.write('file\tfunction\tbase\tbase_type\torigin\toffset\taccess_type\n')
                for path, (_, _, pads) in results:
                    for x in pads:
                        if x[0] == 'BASE':
                            f.write('%s\t%s\t%s\t%s\t%s\t0x%X\t%s\n' % ((path,) + x[1:]))
            with (ROOT / 'build' / 'offsets_fits.tsv').open('w') as f:
                f.write('file\tfunction\tbase\toffset\tfits\n')
                for path, (_, _, pads) in results:
                    for x in pads:
                        if x[0] == 'FIT':
                            f.write('%s\t%s\t%s\t%d\t%s\n' % ((path,) + x[1:]))
            with (ROOT / 'build' / 'offsets_calls.tsv').open('w') as f:
                f.write('file\tcallee\targ\targ_type\tcaller\n')
                for path, (_, _, pads) in results:
                    for x in pads:
                        if x[0] == 'CALL':
                            f.write('%s\t%s\t%d\t%s\t%s\n' % ((path,) + x[1:]))
            (ROOT / 'build' / 'offsets.tsv').write_text('file\tkind\tcount\n' + '\n'.join(rows) + '\n')
            for k, n in total.most_common():
                print('%6d %s' % (n, k))
        if cmd == 'keep':  # after a matching N64 build: every rewrite still possible was rejected by IDO
            found |= set(KEEP.read_text().split()) if KEEP.exists() else set()
            KEEP.write_text('\n'.join(sorted(found)) + '\n')
            print('%d functions keep their raw offsets -> %s' % (len(found), KEEP))
        if cmd != 'apply' or not changed:
            break
        print('pass %d: %d rewrites' % (passes, changed))
        files = sorted({p for p, (items, _, _) in results if items})
    if cmd == 'apply':  # cast rewrites may now use a generated struct above its declaration
        for f in map(Path, sorted(edited_files)):
            if 'offsets.py genstruct' in f.read_text(errors='replace'):
                place_decls.place(f)


if __name__ == '__main__':
    sys.exit(main())
