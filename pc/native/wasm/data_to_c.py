#!/usr/bin/env python3
"""Phase-1 codemod: move a module's asm `.data` into its C file, with the C types.

For each splat subsegment `[ROM, data, NAME]` whose C file declares every label of
asm/data/<dir>/NAME.data.s, the label's type comes from that declaration (libclang, N64 view)
and the initializer from the ROM bytes of the asm file: integers, floats (round-trip exact),
pointers as `&symbol` from the relocations, nested structs and arrays. The definitions go after
the last line of the C file (no function line moves, as1 schedules by line), and the yaml entry
becomes `[ROM, .data, NAME]`. Modules are refused when a byte cannot be expressed in the
declared type (a pointer stored in an integer, a raw non-zero address, padding that is not
zero, bitfields, unions with more than their first member set), when a label has no declaration,
or when native code reaches the module's data through a neighbouring label (xsym groups).

  data_to_c.py scan               -> build/data_to_c.tsv (module, status or reason)
  data_to_c.py apply [NAME ...]   write definitions and yaml for the modules scan accepts
  data_to_c.py constants         -> stub_constants.txt (stub-valued words in integer fields, for data.py)
  data_to_c.py verify TREE        in the Docker clone: re-split, build, compare each migrated
                                  object's .data (bytes and relocations) with the asm object of
                                  HEAD's build; revert modules that differ; make check
"""
import bisect
import collections
import json
from multiprocessing import Pool
import os
from pathlib import Path
import re
import struct
import subprocess
import sys

import data
import lp64_words
import offsets
import syntax_new

ci, K, T = offsets.ci, offsets.K, offsets.T
ROOT = offsets.ROOT
YAML = ROOT / 'baserom.us.yaml'
REPORT = ROOT / 'build' / 'data_to_c.tsv'
LOG = ROOT / 'build' / 'data_to_c.jsonl'  # applied modules: yaml line and C text appended
MARK = '/* data_to_c.py: from asm/data/%s.data.s */'
SUB = re.compile(r'^(\s*- \[)(0x[0-9A-Fa-f]+), data, (\w+)\](.*)$')
INT_KINDS = {T.CHAR_S: 1, T.SCHAR: 1, T.CHAR_U: 0, T.UCHAR: 0, T.SHORT: 1, T.USHORT: 0, T.INT: 1, T.UINT: 0,
             T.LONG: 1, T.ULONG: 0, T.LONGLONG: 1, T.ULONGLONG: 0, T.BOOL: 0}


class Refuse(Exception):
    pass


def modules():
    """[(yaml line index, rom, name, asm path, c path)] for asm .data subsegments with a C file."""
    out = []
    for i, line in enumerate(YAML.read_text().split('\n')):
        m = SUB.match(line)
        if not m:
            continue
        rom, name = int(m.group(2), 16), m.group(3)
        for asm in ROOT.glob('asm/data/**/%s.data.s' % name):
            items = [it for _, _, its in data.parse_file(asm) for it in its]
            first = re.search(r'/\*\s*([0-9A-Fa-f]+)\s+[0-9A-Fa-f]+', asm.read_text())
            if not first or int(first.group(1), 16) != rom:
                continue
            rel = asm.relative_to(ROOT / 'asm' / 'data').with_suffix('').with_suffix('')
            c = ROOT / 'src' / (str(rel) + '.c')
            if c.exists():
                out.append((i, rom, name, asm, c))
    return out


def const_offsets(asm):
    """offsets in the .data block of the words stub_constants.txt lists for this asm file"""
    path = os.path.relpath(asm, ROOT)
    if not any(f == path for f, _ in data.CONSTANTS):
        return set()
    _, labels, items = [b for b in data.parse_file(asm) if b[0] == 'data'][0]
    base = data.span(labels, items)[0]
    return {a - base for f, a in data.CONSTANTS if f == path}


def image(asm, raw_stubs=None):
    """labels {name: offset}, bytes, relocations {offset: (symbol, addend)} of the .data block."""
    blocks = [b for b in data.parse_file(asm) if b[0] == 'data']
    if len(blocks) != 1:
        raise Refuse('%d data blocks' % len(blocks))
    _, labels, items = blocks[0]
    base, end = data.span(labels, items)
    buf, rel = bytearray(end - base), {}
    for addr, size, kind, value in items:
        o = addr - base
        if kind == 'word':
            text, raw = value
            m = data.SYMREF.fullmatch(text)
            if m and not re.fullmatch(r'0x[0-9A-Fa-f]+|\d+', text):
                rel[o] = (m.group(1), int(m.group(2), 0) if m.group(2) else 0)
            buf[o:o + 4] = int(raw, 16).to_bytes(4, 'big') if raw else int(text, 0).to_bytes(4, 'big')
        elif kind == 'float':
            buf[o:o + 4] = int(value[1], 16).to_bytes(4, 'big')
        elif kind == 'double':
            buf[o:o + 8] = value.to_bytes(8, 'big')
        elif kind == 'short':
            buf[o:o + 2] = value.to_bytes(2, 'big')
        elif kind == 'byte':
            buf[o] = value
        elif kind in ('asciz', 'ascii'):
            buf[o:o + len(value)] = value
        elif kind != 'space':
            raise Refuse('item ' + kind)
        if raw_stubs is not None and kind in ('word', 'float') and addr % 4 == 0 and o not in rel:
            stub = data.STUBS.get(int.from_bytes(buf[o:o + 4], 'big'))
            if stub:
                raw_stubs[o] = stub
    return {n: a - base for n, a in labels.items()}, bytes(buf), rel


def float_text(bits, double):
    v = struct.unpack('>d' if double else '>f', bits)[0]
    if v != v or v in (float('inf'), float('-inf')):
        raise Refuse('nan/inf')
    for digits in range(6, 18):
        t = '%.*g' % (digits, v)
        if struct.pack('>d' if double else '>f', float(t)) == bits:
            break
    if not re.search(r'[.e]', t):
        t += '.0'
    return t + ('' if double else 'f')


def header_protos():
    """{function: its one-line prototype} from the game headers"""
    out = {}
    for h in sorted((ROOT / 'include').rglob('*.h')):
        for m in re.finditer(r'^(?!typedef|#|extern\b|static\b)[A-Za-z_][\w \t*]*?\b(\w+)\([^;{}\n]*\);[ \t]*$',
                             h.read_text(errors='replace'), re.M):
            out.setdefault(m.group(1), m.group(0).strip())
    return out


HEADER_PROTOS = header_protos()
NEED = '\0need'  # key in names: declarations the appended block must add
BLOCK = '\0block'  # key in names: {symbol: file-scope redeclaration} for block-scope-only declarations
FIELD = '\0field'  # key in names: lp64_words.type_edit edits for struct fields whose words hold addresses
GENERIC = '\0generic'  # key in names: declare unknown functions as `void f();`, not by their header line
RAW_STUBS = '\0stubs'  # assembly word offsets that name exact syscall entry stubs
SRC = '\0src'  # key in names: the C file's text (a function called without declaration is `int f()`)


def redeclaration(x):
    t = x.type
    if x.kind == K.FUNCTION_DECL:
        toks = [y.spelling for y in x.get_tokens()]
        return None if not toks or toks[0] == x.spelling else ' '.join(toks) + ';'
    if t.kind in (T.CONSTANTARRAY, T.INCOMPLETEARRAY) and '(' not in t.element_type.spelling:
        return 'extern %s %s[];' % (t.element_type.spelling, x.spelling)
    if '(' not in t.spelling and '[' not in t.spelling:
        return 'extern %s %s;' % (t.spelling, x.spelling)
    return None


def symbol(sym, add, names, cast):
    redecl = names.get(BLOCK, {}).pop(sym, None)
    if redecl:  # declared only inside a function: not visible at the end of the file
        names.setdefault(NEED, []).append(redecl)
    if sym not in names:  # no declaration in this TU: the appended block declares it
        is_fn = bool(re.match(r'(func_|_?\w+_entrypoint_\d+$)', sym))
        if not is_fn and not re.match(r'[DR]_\w+$', sym):
            raise Refuse('symbol %s not declared here' % sym)
        names[sym] = ('function', False) if is_fn else ('var', True)
        generic = ('int %s();' if re.search(r'\b%s\s*\(' % sym, names.get(SRC, '')) else 'void %s();') % sym
        names.setdefault(NEED, []).append((generic if names.get(GENERIC) else HEADER_PROTOS.get(sym, generic)) if is_fn
                                          else 'extern u8 %s[];' % sym)
    kind, is_array = names[sym]
    if kind == 'function':
        if add:
            raise Refuse('function plus offset')
        return '(%s)%s' % (cast, sym)
    ref = ('' if is_array else '&') + sym
    return '(%s)%s' % (cast, ref) if not add else '(%s)((u8 *)%s + 0x%X)' % (cast, ref, add)


STUB_NAMES = set(data.STUBS.values())  # overlay entry stubs; a word equal to one may be a constant
WORDS = {'BtFnWord', 'BtIntPtr', 'BtUIntPtr'}  # pointer-sized natively, u32/s32 under IDO


CORE = []  # (start, end, label) of core1/core2 .data labels, for raw addresses splat did not name


def core_label(v):
    """(label, start) of the core data label whose bytes hold address v, or None"""
    if not CORE:
        for f in sorted((ROOT / 'asm' / 'data').glob('core[12]/*.data.s')):
            for kind, labels, items in data.parse_file(f):
                if kind == 'data' and labels:
                    end = data.span(labels, items)[1]
                    ls = sorted((a, n) for n, a in labels.items())
                    CORE.extend((a, ls[i + 1][0] if i + 1 < len(ls) else end, n) for i, (a, n) in enumerate(ls))
        CORE.sort()
    i = bisect.bisect_right(CORE, (v, 1 << 33)) - 1
    return (CORE[i][2], CORE[i][0]) if i >= 0 and CORE[i][0] <= v < CORE[i][1] else None


def init(t, buf, o, rel, names, retype, field=None):
    """C initializer for type t at byte offset o. retype: a list when t is the label's own type or
    its array element; an s32/u32 there that holds an address is noted, its declarations become
    BtIntPtr/BtUIntPtr (same type under IDO). field: the struct field t belongs to; its s32/u32
    type is noted the same way (names[FIELD], applied by `fields`)."""
    spelled, t0 = t.spelling, t
    t = t.get_canonical()
    size = t.get_size()
    if size <= 0:
        raise Refuse('incomplete type')
    if t.kind in INT_KINDS or t.kind == T.ENUM:
        if o in rel and size == 4 and spelled in WORDS:
            return symbol(*rel[o], names, spelled)
        if o in rel and size == 4 and spelled in ('s32', 'u32') and retype is not None:
            retype.append(spelled)
            return symbol(*rel[o], names, 'BtIntPtr' if spelled == 's32' else 'BtUIntPtr')
        if o in rel and size == 4 and spelled in ('s32', 'u32') and field is not None:
            e = lp64_words.type_edit(field, field.location)
            if isinstance(e, tuple):
                names.setdefault(FIELD, set()).add(e)
                return symbol(*rel[o], names, e[4])
        if any(x in rel for x in range(o - 3, o + size)):
            raise Refuse('pointer in an integer')  # constants list these for data.py when it is a flags half
        signed = INT_KINDS.get(t.kind, 1)
        v = int.from_bytes(buf[o:o + size], 'big', signed=bool(signed))
        return str(v) if signed or v < 10 else '0x%X' % v
    if t.kind in (T.FLOAT, T.DOUBLE):
        if any(x in rel for x in range(o, o + size)):
            raise Refuse('pointer in a float')
        return float_text(buf[o:o + size], t.kind == T.DOUBLE)
    if t.kind == T.POINTER:
        if o in rel:
            return symbol(*rel[o], names, t.spelling)
        v = int.from_bytes(buf[o:o + 4], 'big')
        if t.get_pointee().kind in (T.FUNCTIONPROTO, T.FUNCTIONNOPROTO) and o in names.get(RAW_STUBS, {}):
            return symbol(names[RAW_STUBS][o], 0, names, t.spelling)
        lab = core_label(v)
        if lab:  # splat left an address inside a core table raw: the label plus offset (no overlay reloc)
            return symbol(lab[0], v - lab[1], names, t.spelling)
        if v:
            raise Refuse('raw address 0x%08X' % v)
        return '0'
    if t.kind == T.CONSTANTARRAY:
        et = t.element_type.get_canonical()
        es = et.get_size()
        el = (t0 if t0.kind == T.CONSTANTARRAY else t).element_type  # keeps the typedef (s32, BtFnWord)
        sub = retype if et.kind not in (T.RECORD, T.CONSTANTARRAY) else None
        return '{ %s }' % ', '.join(init(el, buf, o + i * es, rel, names, sub, field if et.kind != T.RECORD else None)
                                    for i in range(t.element_count))
    if t.kind == T.RECORD:
        fields = list(t.get_fields())
        decl = t.get_declaration()
        if decl.kind == K.UNION_DECL:
            fields = fields[:1]
        parts, covered = [], set()
        for f in fields:
            if f.is_bitfield():
                raise Refuse('bitfield')
            fo = f.get_field_offsetof() // 8
            parts.append(init(f.type, buf, o + fo, rel, names, None, f))
            covered |= set(range(o + fo, o + fo + f.type.get_canonical().get_size()))
        stray = [x for x in range(o, o + size) if x not in covered and (buf[x] or x in rel)]
        if stray:
            raise Refuse('padding not zero')
        return '{ %s }' % ', '.join(parts)
    raise Refuse('type ' + t.kind.name.lower())


def native_defs():
    """labels the native modules (pc/native, *_native.inc) define themselves"""
    out = set()
    files = [p for p in (ROOT / 'pc' / 'native').rglob('*') if p.suffix in ('.c', '.inc') and 'wasm' not in p.parts]
    for p in files + list((ROOT / 'src').rglob('*_native.inc')):
        out |= set(re.findall(r'^[^\n(;]*?\b([DR]_\w+)\s*(?:\[[^\]]*\]\s*)?=', p.read_text(errors='replace'), re.M))
    return out


NATIVE = native_defs()
CANDIDATES = ('ActorData', 'ActorDataX')  # struct types a `u8 x[]` blob holding addresses may really be
CHARS = {T.UCHAR, T.CHAR_S, T.SCHAR, T.CHAR_U}


def readonly_object(decl):
    # Canonical array types carry the element qualifier. Pointers to const
    # data remain writable unless the pointer object itself is const.
    t = decl.type.get_canonical()
    return (t.is_const_qualified() and not t.is_volatile_qualified()
            and not any(child.kind.is_attribute() for child in decl.get_children()))


def plan(mod, generic=False, native=False):
    """(module name, status, C text to append) for one module. native: definitions for the native
    build only (the N64 keeps the asm file), so IDO's placement rules do not apply: explicit
    BT_DATA offsets replace alignment and gaps, and bytes after a label's type become `<label>__tail`."""
    i, rom, name, asm, c = mod
    names = {}
    try:
        raw_stubs = {}
        labels, buf, rel = image(asm, raw_stubs)
        for o in const_offsets(asm):
            raw_stubs.pop(o, None)
            rel.pop(o, None)  # a flag that only equals a core address: the raw number (no overlay reloc either)
        if not labels:
            raise Refuse('no labels')
        if 'data_to_c.py' in c.read_text():
            raise Refuse('done')
        tu = ci.Index.create().parse(str(c), offsets.ARGS)
        decls, names, typedefs = collections.defaultdict(list), {GENERIC: generic, BLOCK: {}, SRC: c.read_text(), RAW_STUBS: raw_stubs}, {}
        file_scope = set()

        def visit(x, top=True):
            if x.kind in (K.VAR_DECL, K.FUNCTION_DECL):
                if top:
                    file_scope.add(x.spelling)
                elif x.spelling not in file_scope and (x.kind == K.FUNCTION_DECL or
                                                      x.storage_class == ci.StorageClass.EXTERN):
                    names[BLOCK].setdefault(x.spelling, redeclaration(x))
            if x.kind == K.VAR_DECL:
                decls[x.spelling].append(x)
                names.setdefault(x.spelling, ('var', x.type.get_canonical().kind in (
                    T.CONSTANTARRAY, T.INCOMPLETEARRAY)))
            elif x.kind == K.FUNCTION_DECL:
                names.setdefault(x.spelling, ('function', False))
            elif x.kind == K.TYPEDEF_DECL and x.spelling in CANDIDATES:
                typedefs.setdefault(x.spelling, x.type)
            for ch in x.get_children():
                visit(ch, x.kind == K.TRANSLATION_UNIT)
        visit(tu.cursor, False)
        own = [x.spelling for x in tu.cursor.walk_preorder() if x.kind == K.VAR_DECL and x.is_definition()
               and (x.storage_class == ci.StorageClass.STATIC or x.semantic_parent.kind == K.TRANSLATION_UNIT)
               and x.location.file and x.location.file.name == str(c) and not readonly_object(x)
               and '=' in [y.spelling for y in x.get_tokens()]]
        if own and not native:  # its own .data comes first in the object and would move the appended definitions
            raise Refuse('C file defines data itself (%s)' % own[0])
        for sym in file_scope:
            names[BLOCK].pop(sym, None)
        for sym, r in list(names[BLOCK].items()):
            if r is None:
                names.pop(sym, None)  # cannot redeclare: symbol() refuses it as undeclared
                del names[BLOCK][sym]
        order = sorted(labels.items(), key=lambda kv: kv[1])
        k = 1
        while k < len(order):  # a label inside the previous one's element that nothing names: part of it
            (a, ao), (b, bo) = order[k - 1], order[k]
            ta = max((d.type.get_canonical() for d in decls.get(a, [])), key=lambda t: t.get_size(), default=None)
            need = ta and (ta.element_type.get_canonical().get_size() if ta.kind == T.INCOMPLETEARRAY else ta.get_size())
            if need and bo - ao < need and not decls.get(b) and dead(b, asm) and not any(r[0] == b for r in rel.values()):
                del order[k]
            else:
                k += 1
        text, retypes = [], []
        group = re.sub(r'\W', '_', str(asm.relative_to(ROOT / 'asm' / 'data').with_suffix('').with_suffix('')))
        for k, (lab, off) in enumerate(order):
            nxt = order[k + 1][1] if k + 1 < len(order) else len(buf)
            ds = decls.get(lab)
            if lab in NATIVE:
                if native:
                    continue
                raise Refuse('%s is defined by a native module too' % lab)
            if not ds:
                if any(off <= r < nxt for r in rel) or lab_files(lab):
                    raise Refuse('%s has no declaration in %s' % (lab, c.name))
                # reached only through this module's own data: its bytes, type unknown (Phase 4 names it)
                if off % 4 and not native:
                    raise Refuse('%s misaligned for an array' % lab)
                text.append('u8 %s[%d] BT_DATA(4, %s, 0x%X) = { %s };' % (lab, nxt - off, group, off,
                                                                      ', '.join('0x%02X' % b for b in buf[off:nxt])))
                continue
            if any(d.is_definition() and d.storage_class != ci.StorageClass.EXTERN for d in ds):
                raise Refuse('%s already defined' % lab)
            d = max(ds, key=lambda d: d.type.get_canonical().get_size())  # a sized one beats `T x[]`
            t = d.type.get_canonical()
            toks = [x.spelling for x in d.get_tokens()]
            depth, top = 0, []  # commas inside a function pointer's parameter list are fine
            for x in toks:
                depth += (x == '(') - (x == ')')
                top.append(x if depth == 0 else '')
            if ',' in top or '=' in toks:
                raise Refuse('%s: declaration shares a line' % lab)
            spelling = ' '.join(x for x in toks if x not in ('extern', 'static', 'volatile'))
            if '{' in toks:  # `extern struct Tag { ... } lab[];`: the definition names the tag only
                m = re.match(r'((?:const )?(?:struct|union) \w+) \{.*\} (?=\S)', spelling)
                if not m:
                    raise Refuse('%s: declared with an anonymous struct' % lab)
                spelling = m.group(1) + ' ' + spelling[m.end():]
            if toks[0] == lab:  # second declarator of `T a[], b[];`: its extent starts at the name
                base = d.type.element_type if d.type.kind in (T.CONSTANTARRAY, T.INCOMPLETEARRAY) else d.type
                if '(' in base.spelling or d.type.kind not in (T.CONSTANTARRAY, T.INCOMPLETEARRAY):
                    raise Refuse('%s: declaration shares a line' % lab)
                spelling = base.spelling + ' ' + spelling
            tentative = t.kind == T.CONSTANTARRAY and re.search(r'\[\s*\]', ' '.join(toks))  # `T x[];` reads as [1]
            blob = (t.kind == T.INCOMPLETEARRAY or tentative) and t.element_type.get_canonical().kind in CHARS \
                and any(off <= r < nxt for r in rel) and re.match(r'[us]8 ', spelling) and cast_only(lab)
            if blob:  # a byte array with addresses inside: the struct it really is, retyped everywhere
                for cand, ct in typedefs.items():
                    cs = ct.get_canonical().get_size()
                    n, rem = divmod(nxt - off, cs)
                    if rem and (k + 1 < len(order) or rem >= 16 or not n):
                        continue  # only the last label may end in the section's 16-byte padding
                    try:
                        value = '{ %s }' % ', '.join(init(ct, buf, off + j * cs, rel, names, None) for j in range(n))
                    except Refuse:
                        continue
                    old_t = spelling.split()[0]
                    spelling = cand + re.sub(r'\[\s*\]', '[%d]' % n, spelling, count=1)[len(old_t):]
                    retypes.append((lab, old_t, cand))
                    size, rt = n * cs, []
                    break
                else:
                    raise Refuse('%s: byte array with addresses, no struct fits' % lab)
            elif t.kind == T.INCOMPLETEARRAY or tentative:
                es = t.element_type.get_canonical().get_size()
                rem = (nxt - off) % es if es > 0 else 0
                # zero bytes after the last whole element: the next label's alignment or, after the
                # last label, the section's 16-byte padding (the tail and gap checks below decide)
                if es <= 0 or nxt - off < es or (rem and k + 1 == len(order) and rem >= 16 and not native):
                    raise Refuse('%s: size 0x%X is no multiple of the element' % (lab, nxt - off))
                n = (nxt - off) // es
                spelling = re.sub(r'\[\s*\]', '[%d]' % n, spelling, count=1)
                rt = []
                value = '{ %s }' % ', '.join(init(d.type.element_type, buf, off + j * es, rel, names, rt)
                                            for j in range(n))
                size = n * es
            else:
                rt = []
                size = t.get_size()
                m = re.fullmatch(r'(\w+) %s' % lab, spelling)
                if off + size < nxt and (any(buf[off + size:nxt]) or any(off + size <= r < nxt for r in rel)) \
                        and m and size > 0 and (nxt - off) % size == 0 and t.kind not in (T.CONSTANTARRAY, T.RECORD) \
                        and address_only(lab, m.group(1)):
                    # only `&lab` is used: an array of the declared type keeps every address and stride
                    n = (nxt - off) // size
                    value = '{ %s }' % ', '.join(init(d.type, buf, off + j * size, rel, names, rt) for j in range(n))
                    new_t = m.group(1) if not rt else 'BtIntPtr' if rt[0] == 's32' else 'BtUIntPtr'
                    if rt and m.group(1) != rt[0]:
                        raise Refuse('%s: address in a %s declared through a typedef' % (lab, m.group(1)))
                    spelling, size, rt = '%s %s[%d]' % (new_t, lab, n), n * size, []
                    retypes.append((lab, m.group(1), new_t, n))
                else:
                    value = init(d.type, buf, off, rel, names, rt)
            if rt:  # the label's s32/u32 words hold addresses: BtIntPtr in every declaration
                old_t = rt[0]
                new_t = 'BtIntPtr' if old_t == 's32' else 'BtUIntPtr'
                if not re.match(r'%s\b' % old_t, spelling):
                    raise Refuse('%s: address in a %s declared through a typedef' % (lab, old_t))
                spelling = new_t + spelling[len(old_t):]
                retypes.append((lab, old_t, new_t))
            align = ido_align(t, spelling)
            if off % align and not native:
                raise Refuse('%s misaligned for its type' % lab)
            tail = buf[off + size:nxt]
            if off + size > nxt or (any(tail) and not native) or any(x in rel for x in range(off + size, nxt)):
                raise Refuse('%s: type covers 0x%X of 0x%X bytes' % (lab, size, nxt - off))
            if any(tail):  # native: data no label names, reached through this one
                text.append('u8 %s__tail[%d] BT_DATA(4, %s, 0x%X) = { %s };' % (
                    lab, len(tail), group, off + size, ', '.join('0x%02X' % b for b in tail)))
            gap = nxt - off - size  # zero bytes the next definition's alignment must reproduce
            pad = None
            if gap and k + 1 < len(order) and not native:
                na = max(decls_align(decls.get(order[k + 1][0])), 1)
                if (off + size + na - 1) // na * na != nxt:
                    if (off + size) % 4 or gap % 4 or nxt % na:
                        raise Refuse('%s: gap of 0x%X bytes' % (lab, gap))
                    # zero words no label names (the tail check saw them): a padding variable keeps them
                    pad = 'u8 %s__gap[%d] BT_DATA(4, %s, 0x%X) = { 0 };' % (lab, gap, group, off + size)
            elif gap and not native and (off + size + 15) // 16 != (nxt + 15) // 16:  # the last label: the
                if (off + size) % 4:  # object's .data would end a 16-byte line early and move the next module
                    raise Refuse('%s: gap of 0x%X bytes' % (lab, gap))
                pad = 'u8 %s__gap[%d] BT_DATA(4, %s, 0x%X) = { 0 };' % (lab, gap, group, off + size)
            text.append('%s BT_DATA(%d, %s, 0x%X) = %s;' % (spelling, align, group, off, value))
            if pad:
                text.append(pad)
        text = [MARK % asm.relative_to(ROOT / 'asm' / 'data').with_suffix('').with_suffix('')] + names.get(NEED, []) + text
        if native:
            text = ['#ifdef BT_NATIVE'] + text + ['#endif']
        return name, 'ok', '\n'.join(text), retypes, sorted(names.get(FIELD, ()))
    except Refuse as e:
        return name, str(e), None, [], sorted(names.get(FIELD, ()))
    except Exception as e:  # noqa: BLE001
        return name, 'error %s: %s' % (type(e).__name__, e), None, [], sorted(names.get(FIELD, ()))


def ido_align(t, spelling=''):
    """IDO puts every variable on at least 4 bytes (an s16[5] after an s16[3] skips 2, so does an s16)"""
    return max(t.get_canonical().get_align(), 4)


def decls_align(ds):
    return max((ido_align(d.type) for d in ds or []), default=1)


def xsym_modules():
    """label groups native code reaches through a neighbour (xsym_report.py)"""
    p = ROOT / 'build' / 'ilp32-xsym' / 'xsym_groups.tsv'
    return [set(line.split('\t')[0].split()) for line in (p.read_text().splitlines()[1:] if p.exists() else [])]


def plan_native(mod):
    return plan(mod, native=True)


def scan(native=False):
    mods = modules()
    with Pool(os.cpu_count()) as pool:
        res = pool.map(plan_native if native else plan, mods)
    xs = xsym_modules()
    rows = []
    for mod, (name, status, text, _, _) in zip(mods, res):
        defined = set(re.findall(r'(\w+)\s*(?:\[\d*\]\s*)*BT_DATA', text or ''))
        labs = set(image(mod[3])[0])
        if status == 'ok' and any(len(g & defined) > 1 or g & labs and not g <= labs for g in xs):  # one object: fine
            status = 'xsym group (native code reaches it through a neighbour)'
        rows.append((str(mod[4].relative_to(ROOT)), name, status))
    if not native:
        REPORT.write_text('c_file\tmodule\tstatus\n' + ''.join('\t'.join(r) + '\n' for r in rows))
    c = collections.Counter(re.sub(r'^\w+(?=:)|0x[0-9A-F]+|\b[DR]_\w+|\w+\.c\b', '…', s) for _, _, s in rows)
    print('data_to_c: %d modules, %d ok -> %s' % (len(rows), sum(s == 'ok' for *_, s in rows), REPORT))
    for k, v in c.most_common(15):
        print('%6d %s' % (v, k))
    return mods, res, rows


def dead(lab, asm):
    """no source, header, native file or other asm file names lab; its own asm file only defines it"""
    if lab_files(lab) or asm.read_text().count(lab) != 1:
        return False
    return subprocess.run(['grep', '-rlw', '--exclude-dir=nonmatchings', '--exclude-dir=matchings', lab, 'asm'],
                          cwd=ROOT, capture_output=True, text=True  # asm is not in git; C replaced those functions
                          ).stdout.split() == [str(asm.relative_to(ROOT))]


def lab_files(lab):
    return subprocess.run(['git', 'grep', '-l', '-w', lab, '--', 'src', 'include', 'pc/native', ':!pc/native/wasm'],
                          cwd=ROOT, capture_output=True, text=True).stdout.split()


def address_only(lab, old_t):
    """every mention of lab in every file is a declaration `old_t lab` or an address `&lab`"""
    for f in lab_files(lab):
        t = (ROOT / f).read_text()
        for m in re.finditer(r'\b%s\b' % re.escape(lab), t):
            pre = t[max(0, m.start() - 80):m.start()]
            if not (re.search(r'\b%s\s+$' % old_t, pre) and t[m.end():].lstrip()[:1] == ';'
                    or re.search(r'(?<!&)&\s*$', pre)):
                return False
    return True


def cast_only(lab):
    """every use of the byte array lab is cast or has its address taken (no `u8 *` comparisons)"""
    for f in lab_files(lab):
        t = (ROOT / f).read_text()
        for m in re.finditer(r'\b%s\b' % re.escape(lab), t):
            pre = t[max(0, m.start() - 80):m.start()]
            if not re.search(r'(\b(?:[us]8|%s)\s+|\)\s*|(?<!&)&\s*)$' % '|'.join(CANDIDATES), pre):
                return False
    return True


def retype_text(text, retypes, back=False):
    for r in retypes:
        lab, old_t, new_t = r[:3]
        if len(r) == 3:
            a, b = (new_t, old_t) if back else (old_t, new_t)
            text = re.sub(r'\b%s(\s+%s)\b' % (a, re.escape(lab)), b + r'\1', text)
        elif not back:  # arrayed: `old_t lab;` becomes `new_t lab[n];`, `&lab` becomes `lab`
            text = re.sub(r'\b%s(\s+%s)(?=\s*;)' % (old_t, re.escape(lab)), r'%s\1[%d]' % (new_t, r[3]), text)
            text = re.sub(r'(?<!&)&\s*(%s)\b' % re.escape(lab), r'\1', text)
        else:
            text = re.sub(r'\b%s(\s+%s)\[%d\]' % (new_t, re.escape(lab), r[3]), old_t + r'\1', text)
            text = re.sub(r'\b%s\b' % re.escape(lab), lambda m: m.group(0) if re.search(
                r'\b%s\s+$' % old_t, text[max(0, m.start() - 80):m.start()]) else '&' + m.group(0), text)
    return text


def retype_everywhere(retypes, skip=None, back=False):
    """every declaration of these labels in game, header and native files (not the wasm host)"""
    changed = []
    for lab in {r[0] for r in retypes}:
        for f in lab_files(lab):
            p = ROOT / f
            if p == skip:
                continue
            t = p.read_text()
            n = retype_text(t, [r for r in retypes if r[0] == lab], back)
            if n != t:
                p.write_text(n)
                changed.append(f)
    return changed


def fields():
    """struct fields declared s32/u32 whose asm data holds an address become BtIntPtr/BtUIntPtr
    (the same type under IDO); repeats until the modules' data shows no further one"""
    total, files = 0, set()
    for _ in range(6):
        with Pool(os.cpu_count()) as pool:
            res = pool.map(plan_native, modules())
        edits = sorted({tuple(e) for r in res for e in r[4]})
        if not edits:
            break
        for f in {e[0] for e in edits}:
            text = (ROOT / f).read_bytes()  # libclang counts bytes
            for _, start, end, old, new in sorted((e for e in edits if e[0] == f), key=lambda e: -e[1]):
                assert b' '.join(text[start:end].split()) == old.encode(), (f, start, text[start:end])
                text = text[:start] + new.encode() + text[end:]
            (ROOT / f).write_bytes(text)
        total, files = total + len(edits), files | {e[0] for e in edits}
    print('fields: %d struct fields retyped in %d files' % (total, len(files)))


def native_view(f, src, src2, added):
    """added, with each generic `void f();` that conflicts with a native prototype kept to the N64 build"""
    base = syntax_new.native_errors(f, src)
    for _ in range(20):
        extra = syntax_new.native_errors(f, src2 + added) - base
        if not extra:
            return added
        names = {m.group(1) for e in extra for m in [re.match(r"conflicting types for '(\w+)'", e)] if m}
        lines = added.split('\n')
        hit = [i for i, l in enumerate(lines) if any(re.match(r'void _?%s\(\);$' % n, l) for n in names)]
        if not hit:
            return None
        for i in hit:
            lines[i] = '#ifndef BT_NATIVE\n%s\n#endif' % lines[i]  # natively a header declares it already
        added = '\n'.join(lines)
    return None


def block_types(t, seen):
    """declarations of the function-local types t is built from (arrays, pointers, typedefs, fields)"""
    while True:
        if t.kind in (T.CONSTANTARRAY, T.INCOMPLETEARRAY):
            t = t.element_type
        elif t.kind == T.POINTER:
            t = t.get_pointee()
        elif t.kind == T.ELABORATED:
            t = t.get_named_type()
        else:
            break
    d, out = t.get_declaration(), []
    if d.kind == K.NO_DECL_FOUND or d.hash in seen:
        return out
    seen.add(d.hash)
    if d.semantic_parent and d.semantic_parent.kind == K.FUNCTION_DECL:
        out.append(d)
    if d.kind == K.TYPEDEF_DECL:
        out += block_types(d.underlying_typedef_type, seen)
    elif d.kind in (K.STRUCT_DECL, K.UNION_DECL):
        for f in t.get_canonical().get_fields():
            out += block_types(f.type, seen)
    return out


def hoist(c, labels):
    """the function-local types the labels are declared with, moved to file scope without moving a
    line (as1 schedules by line): each definition joined into one line on the blank line before its
    function (else in front of the function's first line), its old lines left empty.
    (new text, [(line index, old, new)]) or None: nothing to move, a tag defined twice differently,
    a declaration that also declares a variable, a comment or directive inside."""
    raw = c.read_bytes()
    tu = ci.Index.create().parse(str(c), offsets.ARGS)
    found, seen = [], set()
    for x in tu.cursor.walk_preorder():
        if x.kind == K.VAR_DECL and x.spelling in labels and x.location.file and x.location.file.name == str(c):
            found += block_types(x.type, seen)
    stmts = {}
    for d in found:
        p = d.semantic_parent
        outer = next((y for y in p.walk_preorder() if y.kind == K.TYPEDEF_DECL and y.extent.start.offset
                      <= d.extent.start.offset and d.extent.end.offset <= y.extent.end.offset and y != d), d)
        a, b = outer.extent.start.offset, outer.extent.end.offset
        rest = raw[b:]
        semi = b + len(rest) - len(rest.lstrip())
        if raw[semi:semi + 1] == b';':
            end = semi + 1
            while raw[end:end + 1] in (b' ', b'\t'):  # the space before the next statement on the line
                end += 1
            stmts[a] = (a, end, p.extent.start.line - 1, raw[a:semi + 1])
        elif outer.kind in (K.STRUCT_DECL, K.UNION_DECL) and outer.spelling and b'{' in raw[a:b]:
            # `struct X { ... } var;`: the body goes, `struct X var;` stays
            end = b
            while raw[end:end + 1] in (b' ', b'\t'):
                end += 1
            stmts[a] = (raw.index(b'{', a), end, p.extent.start.line - 1, raw[a:b] + b';')
        else:
            return None
    if not stmts:
        return None
    by_text = {}
    for *_, t in stmts.values():
        t = t.decode()
        if '//' in t or '/*' in t or re.search(r'^\s*#', t, re.M):
            return None
        m = re.match(r'(?:typedef\s+)?(?:struct|union)\s+(\w+)', t)
        name = m.group(1) if m else t.split()[-1].rstrip(';')
        if by_text.setdefault(name, ' '.join(t.split())) != ' '.join(t.split()):
            return None
    out = raw
    for a, b, *_ in sorted(stmts.values(), reverse=True):
        out = out[:a] + b'\n' * raw[a:b].count(b'\n') + out[b:]
    old, lines = raw.decode().split('\n'), out.decode().split('\n')
    lines = [l.rstrip() if l != o else l for l, o in zip(lines, old)]
    per_fn, done = collections.defaultdict(list), set()
    for a, b, fl, t in sorted(stmts.values()):
        t = ' '.join(t.decode().split())
        if t not in done:  # the same type in several functions: once, before the first
            done.add(t)
            per_fn[fl].append(t)
    for fl, ts in per_fn.items():
        if fl > 0 and not lines[fl - 1].strip():
            lines[fl - 1] = ' '.join(ts)
        else:
            lines[fl] = ' '.join(ts) + ' ' + lines[fl]
    return '\n'.join(lines), [(i, o, n) for i, (o, n) in enumerate(zip(old, lines)) if o != n]


def apply(names, native=False):
    """native: for modules IDO's placement keeps in asm, definitions under BT_NATIVE; yaml unchanged"""
    mods, res, rows = scan(native)
    ok = {(r[0], r[1]) for r in rows if r[2] == 'ok'}  # module names repeat across overlays
    lines = YAML.read_text().split('\n')
    done = 0
    with LOG.open('a') as log:
        for (i, rom, name, asm, c), (_, status, text, retypes, _) in zip(mods, res):
            if (str(c.relative_to(ROOT)), name) not in ok or (names and name not in names):
                continue
            src = c.read_text()
            added = ('' if src.endswith('\n') else '\n') + text + '\n'
            src2 = retype_text(src, retypes)
            # a type declared inside a function is not visible at file scope, nor the same type there
            base = syntax_new.errors(str(c.relative_to(ROOT)), src)
            if syntax_new.errors(str(c.relative_to(ROOT)), src2 + added) - base:
                _, st, text, retypes, _ = plan((i, rom, name, asm, c), generic=True, native=native)  # header lines may need unseen types
                added = ('' if src.endswith('\n') else '\n') + (text or '') + '\n'
                src2 = retype_text(src, retypes)
            hoisted = []
            if text is None or syntax_new.errors(str(c.relative_to(ROOT)), src2 + added) - base:
                h = hoist(c, set(image(asm)[0]))  # function-local types: to file scope, line-neutral
                if h and not syntax_new.errors(str(c.relative_to(ROOT)), h[0]) - base:
                    c.write_text(h[0])
                    for generic in (False, True):
                        _, st, text, retypes, _ = plan((i, rom, name, asm, c), generic=generic, native=native)
                        added = ('' if h[0].endswith('\n') else '\n') + (text or '') + '\n'
                        src2 = retype_text(h[0], retypes)
                        if text is not None and not syntax_new.errors(str(c.relative_to(ROOT)), src2 + added) - base:
                            src, hoisted = h[0], h[1]
                            break
                    else:
                        c.write_text(src)
            if text is None or syntax_new.errors(str(c.relative_to(ROOT)), src2 + added) - base:
                print('data_to_c: %s: the definitions do not compile at file scope; left in asm' % c.relative_to(ROOT))
                continue
            saved = {f: (ROOT / f).read_text() for lab in {r[0] for r in retypes} for f in lab_files(lab)}
            others = retype_everywhere(retypes, skip=c)  # headers the native view includes see the new types
            added = native_view(str(c.relative_to(ROOT)), src, src2, added)
            if added is None:
                for f in others:
                    (ROOT / f).write_text(saved[f])
                if hoisted:
                    c.write_text('\n'.join(dict((k, o) for k, o, _ in hoisted).get(k, l)
                                           for k, l in enumerate(src.split('\n'))))
                print('data_to_c: %s: the definitions do not compile natively; left in asm' % c.relative_to(ROOT))
                continue
            c.write_text(src2 + added)
            old = lines[i]
            if not native:
                lines[i] = SUB.sub(r'\1\2, .data, \3]\4', old)
            log.write(json.dumps({'module': name, 'c': str(c.relative_to(ROOT)), 'yaml_old': old,
                                  'yaml_new': lines[i], 'added': added, 'retypes': retypes, 'hoisted': hoisted,
                                  'retyped_files': others + [str(c.relative_to(ROOT))] * bool(retypes)}) + '\n')
            done += 1
    YAML.write_text('\n'.join(lines))
    print('data_to_c: %d modules moved to C' % done)


def revert(names):
    entries = [json.loads(l) for l in LOG.read_text().splitlines()] if LOG.exists() else []
    lines = YAML.read_text().split('\n')
    keep = []
    for e in entries:
        if e['module'] not in names and e['c'] not in names:
            keep.append(e)
            continue
        c = ROOT / e['c']
        src = c.read_text()
        assert src.count(e['added']) == 1, e['c']  # bss_to_c.py may have appended after it
        c.write_text(src.replace(e['added'], ''))
        rts = [tuple(r) for r in e.get('retypes', [])]
        for f in e.get('retyped_files', []):
            (ROOT / f).write_text(retype_text((ROOT / f).read_text(), rts, back=True))
        if e.get('hoisted'):
            ls = c.read_text().split('\n')
            for k, o, n in e['hoisted']:
                assert ls[k] == n, (e['c'], k)
                ls[k] = o
            c.write_text('\n'.join(ls))
        if e['yaml_new'] != e['yaml_old']:
            lines[lines.index(e['yaml_new'])] = e['yaml_old']
    YAML.write_text('\n'.join(lines))
    LOG.write_text(''.join(json.dumps(e) + '\n' for e in keep))
    print('data_to_c: %d modules back to asm' % (len(entries) - len(keep)))


def objdump(tree, objs):
    script = 'for o in "$@"; do echo "@@@ $o"; mips-linux-gnu-objdump -s -j .data "$o" 2>/dev/null | ' \
             'grep -v "file format"; mips-linux-gnu-objdump -r -j .data "$o" 2>/dev/null | grep -v "file format"; done'
    r = subprocess.run(['docker', 'run', '--rm', '--platform', 'linux/amd64', '--network', 'none', '--mount',
                        'type=bind,source=%s,target=/work' % tree, '--workdir', '/work', 'banjo-tooie-decomp:local',
                        'sh', '-c', script, 'sh'] + objs, capture_output=True, text=True)
    out, cur = {}, None
    for line in r.stdout.splitlines():
        if line.startswith('@@@ '):
            cur = line[4:]
            out[cur] = []
        elif cur and line.strip():
            out[cur].append(line)
    return out


def dump_norm(lines, consts):
    """(bytes, relocations) of an objdump -s/-r listing; the stub_constants words read as zero"""
    buf, rels = bytearray(), []
    for l in lines or []:
        m = re.match(r'^ ([0-9a-f]{4,}) ((?:[0-9a-f]{2,8} ?){1,4})', l)
        if m:
            o = int(m.group(1), 16)
            raw = bytes.fromhex(''.join(m.group(2).split()))
            buf[o:o + len(raw)] = raw
            continue
        m = re.match(r'^([0-9a-f]{8}) (R_\w+)\s+(\S+)', l)
        if m and int(m.group(1), 16) not in consts:
            rels.append(m.groups())
    for o in consts:
        if o + 4 <= len(buf):
            buf[o:o + 4] = bytes(4)
    return bytes(buf), rels


def matching_literal_stubs(new_lines, old_lines):
    """Offsets where an R_MIPS_32 names exactly the original literal callback address."""
    new_bytes, new_rels = dump_norm(new_lines, set())
    old_bytes, old_rels = dump_norm(old_lines, set())
    relocated = {int(offset, 16) for offset, _, _ in old_rels}
    matches = set()
    for offset, kind, symbol in new_rels:
        o = int(offset, 16)
        if kind == 'R_MIPS_32' and o % 4 == 0 and o not in relocated and o + 4 <= len(old_bytes):
            address = int.from_bytes(old_bytes[o:o + 4], 'big')
            if new_bytes[o:o + 4] == bytes(4) and data.STUBS.get(address) == symbol:
                matches.add(o)
    return matches


def verify(tree):
    tree = tree.resolve()
    entries = [json.loads(l) for l in LOG.read_text().splitlines()] if LOG.exists() else []
    if not entries:
        sys.exit('verify: nothing applied')
    if not (tree / 'build.base').exists():
        sys.exit('verify: run offsets.py verify once (HEAD objects in %s/build.base)' % tree)
    offsets.sync(tree)
    subprocess.run(['rm', '-rf', str(tree / 'asm')], check=True)  # re-split for the new yaml
    ok, log = offsets.docker_make(tree)
    if (tree / 'banjotooie.ld').exists():  # the native build reads its asm data list from it
        (ROOT / 'banjotooie.ld').write_text((tree / 'banjotooie.ld').read_text())
    bad, pairs = [], []
    for e in entries:
        rel = Path(e['c'])
        asm_rel = Path('asm/data') / (str(rel.relative_to('src').with_suffix('')) + '.data.s')
        pairs.append((e, asm_rel, 'build/us/%s.o' % rel, 'build.base/us/%s.o' % asm_rel))
    d = objdump(tree, [x for _, _, new, old in pairs for x in (new, old)])  # one container for all
    for e, asm_rel, new, old in pairs:
        a, b = d.get(new), d.get(old)
        consts = const_offsets(ROOT / asm_rel)
        consts |= {int(o, 16) for o, _, sym in dump_norm(a, set())[1] if core_label(int(sym.split('+')[0][2:10], 16)
                   if re.match(r'D_80[0-3][0-9A-F]{5}\b', sym) else 0)}
        consts |= matching_literal_stubs(a, b)
        norm = [dump_norm(x, consts) for x in (a, b)]
        if not a or norm[0] != norm[1]:
            bad.append(e['c'])
    print('verify: make check %s; %d of %d modules differ from their asm data: %s' % (
        'OK' if ok else 'FAIL (%s)' % log, len(bad), len(entries), ' '.join(bad[:30])))
    return bad, ok


CONSTANTS = ROOT / 'pc' / 'native' / 'wasm' / 'stub_constants.txt'


FLAG_WORDS = (0x24, 0x3C)  # the descriptor words func_80102FA0 tests as flags (unk24/26, unk3C/3E)


def leaf(t, off):
    """the scalar type at byte offset off of type t (first member of a union), or None"""
    t = t.get_canonical()
    if t.kind == T.RECORD:
        fields = list(t.get_fields())
        if t.get_declaration().kind == K.UNION_DECL:
            fields = fields[:1]
        for f in fields:
            fo, fs = f.get_field_offsetof() // 8, f.type.get_canonical().get_size()
            if fo <= off < fo + fs and not f.is_bitfield():
                return leaf(f.type, off - fo)
        return None
    if t.kind in (T.CONSTANTARRAY, T.INCOMPLETEARRAY):
        es = t.element_type.get_canonical().get_size()
        return leaf(t.element_type, off % es) if es > 0 else None
    return t


def module_constants(asm):
    """[(asm path, vram, symbol)]: words splat read as a symbol (or data.py would take for an overlay
    stub) that land in an integer field narrower than a word of an actor descriptor: flags whose
    value only equals an address. Natively they must stay the raw N64 number."""
    rel_asm = asm.relative_to(ROOT / 'asm' / 'data').with_suffix('').with_suffix('')
    c = ROOT / 'src' / (str(rel_asm) + '.c')
    if not c.exists() and '_' in c.stem:  # a data subsegment named after its C file (jollyroger_tail)
        c = c.with_name(c.stem.rsplit('_', 1)[0] + '.c')
    try:
        labels, buf, rel = image(asm)
    except Refuse:
        return []
    absl = {n: a for _, ls, _ in data.parse_file(asm) for n, a in ls.items()}
    stubs = {o: sym if not add else '%s+0x%X' % (sym, add) for o, (sym, add) in rel.items()}  # a flags half holds none
    stubs.update({o: data.STUBS[v] for o in range(0, len(buf) - 3, 4) if o not in rel
                  for v in [int.from_bytes(buf[o:o + 4], 'big')] if v in data.STUBS})
    if not stubs or not c.exists():
        return []
    tu = ci.Index.create().parse(str(c), offsets.ARGS)
    decls, typedefs = {}, {}
    for x in tu.cursor.walk_preorder():
        if x.kind == K.VAR_DECL:
            if x.spelling not in decls or x.type.get_canonical().get_size() > decls[x.spelling].get_canonical().get_size():
                decls[x.spelling] = x.type
        elif x.kind == K.TYPEDEF_DECL and x.spelling in CANDIDATES:
            typedefs.setdefault(x.spelling, x.type)
    order = sorted(labels.items(), key=lambda kv: kv[1])
    out = []
    for k, (lab, off) in enumerate(order):
        nxt = order[k + 1][1] if k + 1 < len(order) else len(buf)
        t = decls.get(lab)
        if t is None:
            continue
        ct = t.get_canonical()
        if ct.kind in (T.CONSTANTARRAY, T.INCOMPLETEARRAY) and ct.element_type.get_canonical().kind in CHARS:
            t = next((td for td in typedefs.values() if (nxt - off) % td.get_canonical().get_size() == 0), None)
            if t is None:
                continue
        el = t.get_canonical()
        while el.kind in (T.CONSTANTARRAY, T.INCOMPLETEARRAY):
            el = el.element_type.get_canonical()
        if el.kind != T.RECORD or el.spelling.split()[-1] not in CANDIDATES:
            continue  # only types whose integer fields are known to be integers (actor descriptors)
        for o in sorted(x for x in stubs if off <= x < nxt):
            lt = leaf(t, o - off)
            if (o - off) % el.get_size() not in FLAG_WORDS:
                continue
            if lt is not None and lt.get_canonical().kind in INT_KINDS and lt.get_canonical().get_size() < 4:
                out.append(('asm/data/%s.data.s' % rel_asm, absl[lab] - off + o, stubs[o]))
    return out


def constants():
    files = sorted((ROOT / 'asm' / 'data').rglob('*.data.s'))
    with Pool(os.cpu_count()) as pool:
        rows = [r for rs in pool.map(module_constants, files) for r in rs]
    CONSTANTS.write_text('# data_to_c.py constants: words equal to an overlay stub address that the C type\n'
                         '# says are integers (actor descriptor flags); data.py keeps them raw\n' +
                         ''.join('%s 0x%08X %s\n' % r for r in rows))
    print('data_to_c: %d stub-valued constants -> %s' % (len(rows), CONSTANTS))


def main():
    cmd, args = (sys.argv[1], sys.argv[2:]) if len(sys.argv) > 1 else ('scan', [])
    if cmd == 'scan':
        scan()
    elif cmd == 'constants':
        constants()
    elif cmd == 'apply':
        apply(set(args) - {'--native'}, '--native' in args)
    elif cmd == 'scan-native':
        scan(True)
    elif cmd == 'fields':
        fields()
    elif cmd == 'revert':
        revert(set(args))
    elif cmd == 'verify':
        bad, ok = verify(Path(args[0]))
        return 1 if bad or not ok else 0
    else:
        sys.exit(__doc__)
    return 0


if __name__ == '__main__':
    sys.exit(main())
