#!/usr/bin/env python3
"""Phase-5 codemod: 32-bit integers that carry pointers become pointer-sized integers.

`BtIntPtr`/`BtUIntPtr` (include/common.h) are s32/u32 under IDO, so the N64 build cannot change,
and intptr_t/uintptr_t natively. Each round compiles every game file for LP64 with libclang, takes
the pointer/int diagnostics, finds the integer a pointer passes through and retypes its
declaration in place (the type token only: no line moves):

  (s32)actor                          explicit cast          -> (BtIntPtr)actor
  s32 temp; temp = (BtIntPtr)p;       destination variable   -> BtIntPtr temp
  f(actor) with f(s32 arg0)           parameter              -> every declaration of f
  return (BtIntPtr)p; in s32 g()      return type            -> every declaration of g
  (Actor *)temp_v0                    source variable        -> BtIntPtr temp_v0

Struct fields, globals, array elements, constants and function-pointer calls are not retyped
(their layout may come from the ROM or other files); they go to build/lp64_words_left.tsv for
agents. Repeats until a round finds nothing new.

  lp64_words.py [--rounds N] [--dry] [FILES]     then: hazards64.py, make check, port.py gate
"""
import argparse
import collections
from multiprocessing import Pool
import os
from pathlib import Path
import re
import sys

import hazards64
import offsets  # libclang setup

ci, K, T = offsets.ci, offsets.K, offsets.T
ROOT = offsets.ROOT
import subprocess  # noqa: E402
# libclang does not know its builtin headers (stdarg.h) without the compiler's resource directory
FLAGS = [f for f in hazards64.FLAGS if f != '-fsyntax-only'] + [
    '-resource-dir', subprocess.run([hazards64.build.CLANG, '-print-resource-dir'], capture_output=True,
                                    text=True).stdout.strip()]
LEFT = ROOT / 'build' / 'lp64_words_left.tsv'
# s32/u32 only: they are long/unsigned long under IDO like BtIntPtr; `int` -> long changes IDO's code
# (gcskyDll_entrypoint_0), so `int` declarations stay for agents
SIGNED = {('s32',)}
UNSIGNED = {('u32',)}
QUAL = {'static', 'extern', 'register', 'volatile', 'const', 'inline'}
NEW = {'BtIntPtr', 'BtUIntPtr'}
P2I = re.compile(r'incompatible pointer to integer conversion|cast to smaller integer type')
I2P = re.compile(r'incompatible integer to pointer conversion|from smaller integer type')


def editable(f):
    # game code, its headers and the native modules built into the guest (not the wasm host)
    return f is not None and f.startswith(('src/', 'include/', 'pc/native/')) and not f.startswith('pc/native/wasm/')


def rel(loc):
    return os.path.relpath(loc.file.name, ROOT) if loc.file else None


TEXT = {}


def type_edit(c, end_loc, shared=False, cast=False):
    """(file, start, end, old, new) retyping the integer type tokens of declaration c that sit
    before end_loc (its name), or a reason string. shared: c may share its type with other
    declarators (`s32 a, *b;`), which must then all be plain."""
    if end_loc is None:  # unnamed parameter: all of its tokens
        toks = [t for t in c.get_tokens() if t.extent.end.offset <= c.extent.end.offset]
        end_loc = c.extent.start
    else:
        toks = [t for t in c.get_tokens() if t.location.offset < end_loc.offset and rel(t.location) == rel(end_loc)]
    toks = [t for t in toks if t.spelling not in QUAL]
    if cast and len(toks) >= 2 and toks[0].spelling == '(' and toks[-1].spelling == ')':
        toks = toks[1:-1]
    spell = tuple(t.spelling for t in toks)
    if spell and spell[0] in NEW:
        return None  # done already
    new = 'BtIntPtr' if spell in SIGNED else 'BtUIntPtr' if spell in UNSIGNED else None
    f = rel(toks[0].location) if toks else None
    if new is None and shared and ',' in spell:  # `s32 a, b;` and b is wanted
        head = spell[:spell.index(',') - 1]
        new = 'BtIntPtr' if head in SIGNED else 'BtUIntPtr' if head in UNSIGNED else None
        toks, spell = toks[:len(head)], head
    if new is None:
        return 'type %s' % (' '.join(spell) or '?')
    if not editable(f):
        return 'outside src/include'
    if shared:
        text = TEXT.setdefault(f, (ROOT / f).read_text(errors='replace'))
        stmt = text[toks[0].extent.start.offset:text.find(';', toks[0].extent.start.offset)]
        if ',' in stmt and re.search(r'[*\[(]', stmt):
            return 'shared declaration'
    return (f, toks[0].extent.start.offset, toks[-1].extent.end.offset, ' '.join(spell), new)


def generated(field):
    """a field of a struct offsets.py genstruct wrote (file-local, no ROM layout behind it yet)"""
    f = rel(field.location)
    if not editable(f):
        return False
    text = TEXT.setdefault(f, (ROOT / f).read_text(errors='replace'))
    lo = text.rfind('\n', 0, field.location.offset) + 1
    return 'offsets.py genstruct' in text[lo:text.find('\n', field.location.offset)]


def strip(c):
    while c is not None and c.kind in (K.UNEXPOSED_EXPR, K.PAREN_EXPR):
        ch = list(c.get_children())
        if len(ch) != 1:
            break
        c = ch[0]
    return c


def is_int32(t):
    t = t.get_canonical()
    return t.kind in (T.INT, T.UINT, T.LONG, T.ULONG) and t.get_size() == 4


def analyse(path):
    """Requests from one translation unit: ('edit', edit), ('ret', func), ('param', func, i),
    ('left', file, line, reason); and the function declarations it sees: ('fdecl', name, ret
    edit or reason, [param edits or reasons], file, offset)."""
    out = []
    try:
        tu = ci.Index.create().parse(str(ROOT / path), FLAGS)
    except ci.TranslationUnitLoadError:
        return [('left', path, 0, 'parse failure')]
    at = collections.defaultdict(list)  # (line, col) -> [chain], outermost first
    fdecls = {}

    def visit(c, chain):
        loc = c.location
        if c.kind == K.FUNCTION_DECL and editable(rel(loc)):
            key = (rel(loc), loc.offset)
            if key not in fdecls:
                params = [x for x in c.get_children() if x.kind == K.PARM_DECL]
                fdecls[key] = ('fdecl', c.spelling, type_edit(c, loc),
                               [type_edit(p, p.location if p.spelling else None) for p in params],
                               key[0], key[1], c.type.kind == T.FUNCTIONNOPROTO)
        if c.extent.start.file and rel(c.extent.start) == path:
            at[(c.extent.start.line, c.extent.start.column)].append(chain + [c])
            if c.kind in (K.BINARY_OPERATOR, K.COMPOUND_ASSIGNMENT_OPERATOR, K.CONDITIONAL_OPERATOR):
                # clang puts the caret of a binary expression on its operator
                lhs = next(c.get_children(), None)
                op = next((t for t in c.get_tokens() if lhs is not None and
                           t.extent.start.offset >= lhs.extent.end.offset), None)
                if op is not None:
                    at[(op.location.line, op.location.column)].append(chain + [c])
        for ch in c.get_children():
            visit(ch, chain + [c])

    for top in tu.cursor.get_children():
        if top.location.file and (rel(top.location) == path or top.kind == K.FUNCTION_DECL):
            visit(top, [tu.cursor])
    out += list(fdecls.values())

    def left(c, why):
        out.append(('left', path, c.extent.start.line if c is not None else 0, why))

    def retype_decl(d, where):
        fn = d.semantic_parent
        if d.kind == K.PARM_DECL and fn is not None and fn.kind == K.FUNCTION_DECL:
            # every declaration of the function changes together (prototypes in headers)
            idx = [x.spelling for x in fn.get_arguments()].index(d.spelling)
            out.append(('param', fn.spelling, idx))
        elif d.kind == K.VAR_DECL and fn is not None and fn.kind == K.FUNCTION_DECL:
            if d.storage_class == ci.StorageClass.STATIC:
                return left(where, 'static local %s' % d.spelling)
            e = type_edit(d, d.location, shared=True)
            if isinstance(e, tuple):
                out.append(('edit', e))
            elif e:
                left(where, '%s: %s' % (d.spelling, e))
        elif d.kind == K.VAR_DECL:
            left(where, 'global %s' % d.spelling)
        elif d.kind == K.FIELD_DECL and generated(d):
            e = type_edit(d, d.location)
            if isinstance(e, tuple):
                out.append(('edit', e))
            elif e:
                left(where, 'field %s: %s' % (d.spelling, e))
        elif d.kind == K.FUNCTION_DECL:
            out.append(('ret', d.spelling))
        else:
            left(where, d.kind.name.lower())

    def source(e, where, depth=0):
        """integer expression e carries a pointer: retype where it comes from"""
        e = strip(e)
        if e is None or depth > 6:
            return
        if e.kind == K.BINARY_OPERATOR and e.binary_operator == ci.BinaryOperator.Assign:
            return source(list(e.get_children())[1], where, depth + 1)  # caret on the `=`
        if e.kind == K.CSTYLE_CAST_EXPR:
            if is_int32(e.type):
                ed = type_edit_cast(e)
                if isinstance(ed, tuple):
                    out.append(('edit', ed))
                kids = [x for x in e.get_children() if x.kind != K.TYPE_REF]
                if kids and is_int32(strip(kids[-1]).type):
                    source(kids[-1], where, depth + 1)
            return
        if e.kind in (K.DECL_REF_EXPR, K.MEMBER_REF_EXPR) and e.referenced is not None:
            return retype_decl(e.referenced, where)
        if e.kind == K.CALL_EXPR:
            ref = e.referenced
            if ref is not None and ref.kind == K.FUNCTION_DECL:
                out.append(('ret', ref.spelling))
            else:
                left(where, 'call through pointer')
            return
        if e.kind == K.BINARY_OPERATOR and e.binary_operator in (ci.BinaryOperator.Add, ci.BinaryOperator.Sub,
                                                                ci.BinaryOperator.Or, ci.BinaryOperator.And):
            for x in e.get_children():
                sx = strip(x)
                if not is_int32(x.type) or sx.kind == K.INTEGER_LITERAL or (
                        sx.kind == K.BINARY_OPERATOR and sx.binary_operator in (
                            ci.BinaryOperator.Mul, ci.BinaryOperator.Shl, ci.BinaryOperator.Div)):
                    continue  # constants and index arithmetic carry no pointer
                source(x, where, depth + 1)
            return
        if e.kind == K.CONDITIONAL_OPERATOR:
            for x in list(e.get_children())[1:]:
                source(x, where, depth + 1)
            return
        if e.kind == K.INTEGER_LITERAL:
            return left(where, 'constant address')
        left(where, e.kind.name.lower())

    def type_edit_cast(e):
        kids = [x for x in e.get_children() if x.kind != K.TYPE_REF]
        if not kids:
            return None
        return type_edit(e, kids[-1].extent.start, cast=True)

    def destination(chain, where):
        """the outermost expression at the caret (chain[-1]) is converted to an integer: retype what
        receives it"""
        k = len(chain) - 1
        while k > 1 and chain[k - 1].kind in (K.UNEXPOSED_EXPR, K.PAREN_EXPR):
            k -= 1  # implicit casts and parentheses around the converted expression
        e, p = chain[k], chain[k - 1]
        if e.kind == K.BINARY_OPERATOR and e.binary_operator == ci.BinaryOperator.Assign:
            e, p = list(e.get_children())[1], e  # caret on the `=`: the right side is converted
        if p.kind == K.CALL_EXPR:
            args = list(p.get_arguments())
            idx = next((i for i, a in enumerate(args) if a == e), None)
            ref = p.referenced
            if idx is not None and ref is not None and ref.kind == K.FUNCTION_DECL:
                out.append(('param', ref.spelling, idx))
            else:
                left(where, 'call argument (pointer or unknown callee)')
        elif p.kind == K.BINARY_OPERATOR and p.binary_operator == ci.BinaryOperator.Assign:
            lhs = strip(next(p.get_children()))
            if lhs.kind in (K.DECL_REF_EXPR, K.MEMBER_REF_EXPR) and lhs.referenced is not None:
                retype_decl(lhs.referenced, where)
            else:
                left(where, 'assignment to %s' % lhs.kind.name.lower())
        elif p.kind == K.VAR_DECL:
            retype_decl(p, where)
        elif p.kind == K.RETURN_STMT:
            fn = next((x for x in reversed(chain) if x.kind == K.FUNCTION_DECL), None)
            if fn is not None:
                out.append(('ret', fn.spelling))
        else:
            left(where, 'context %s' % p.kind.name.lower())

    for d in tu.diagnostics:
        loc = d.location
        if d.option not in hazards64.WARNINGS or not loc.file or rel(loc) != path:
            continue
        chains = at.get((loc.line, loc.column))
        if not chains and d.option == '-Wshorten-64-to-32':
            continue  # pointer differences and sizeof: no pointer travels through an int
        if not chains:
            out.append(('left', path, loc.line, 'no expression at caret'))
            continue
        msg = d.spelling
        outer = min(chains, key=len)  # outermost expression starting at the caret
        if d.option == '-Wshorten-64-to-32':
            mentions = any(t in msg for t in ("'long'", "'unsigned long'", 'BtIntPtr', 'BtUIntPtr')) and \
                'long long' not in msg and 'sizeof' not in ' '.join(x.spelling for x in outer[-1].get_tokens())
            if mentions and uses_new(outer[-1]):
                destination(outer, outer[-1])
            continue
        if 'cast' in d.option or msg.startswith('cast to'):
            casts = [ch for ch in chains if ch[-1].kind == K.CSTYLE_CAST_EXPR]
            if not casts:
                out.append(('left', path, loc.line, 'cast not found'))
                continue
            cast = max(casts, key=len)[-1]  # innermost cast at the caret
            if P2I.search(msg):
                if is_int32(cast.type):
                    ed = type_edit_cast(cast)
                    if isinstance(ed, tuple):
                        out.append(('edit', ed))
                    elif ed:
                        left(cast, 'cast ' + ed)
                else:
                    left(cast, 'cast to %s' % cast.type.spelling)
            elif I2P.search(msg):
                kids = [x for x in cast.get_children() if x.kind != K.TYPE_REF]
                if kids:
                    source(kids[-1], cast)
            continue
        if d.option == '-Wint-conversion':
            if msg.startswith('incompatible pointer to integer'):
                destination(outer, outer[-1])
            elif msg.startswith('incompatible integer to pointer'):
                source(outer[-1], outer[-1])
            continue
        out.append(('left', path, loc.line, d.option))
    return out


def uses_new(c):
    if c.type.spelling in NEW:
        return True
    return any(uses_new(x) for x in c.get_children())


def round_(files, dry):
    with Pool(os.cpu_count()) as pool:
        results = pool.map(analyse, files)
    funcs = collections.defaultdict(dict)  # name -> {(file, offset): fdecl}
    edits, left, rets, params = set(), [], set(), set()
    for res in results:
        for r in res:
            if r[0] == 'fdecl':
                funcs[r[1]][(r[4], r[5])] = r
            elif r[0] == 'edit':
                edits.add(r[1])
            elif r[0] == 'ret':
                rets.add(r[1])
            elif r[0] == 'param':
                params.add((r[1], r[2]))
            else:
                left.append(r[1:])
    def fine(e):
        # a declaration with a pointer there (another file's prototype says `Actor *`): BtIntPtr is
        # passed in the same register with the same size, so only the integer ones change
        # (arrays are pointers as parameters; uintptr_t is pointer-sized; a K&R-style declaration
        # with fewer parameters says nothing about this one)
        return isinstance(e, tuple) or e is None or e == 'missing' or (e.startswith('type ') and (
            e.endswith(('*', ']')) or e in ('type uintptr_t', 'type intptr_t', 'type BtFnWord')))

    for name in sorted(rets):  # every declaration of the function or none
        decls = funcs.get(name, {}).values()
        es = [d[2] for d in decls]
        if decls and all(fine(e) for e in es):
            edits |= {e for e in es if isinstance(e, tuple)}
        elif decls:
            left.append(('?', 0, 'return type of %s: %s' % (name, [e for e in es if isinstance(e, str)][0])))
        else:
            left.append(('?', 0, 'return type of %s: no declaration in src/include' % name))
    for name, i in sorted(params):
        decls = [d for d in funcs.get(name, {}).values() if not d[6]]  # K&R declarations carry no types
        es = [d[3][i] if i < len(d[3]) else 'missing' for d in decls]
        if decls and all(fine(e) for e in es):
            edits |= {e for e in es if isinstance(e, tuple)}
        elif decls:
            left.append(('?', 0, 'parameter %d of %s: %s' % (i, name, [e for e in es if isinstance(e, str)][0])))
    for name, decls in funcs.items():  # declarations that missed an earlier round's retype
        decls = list(decls.values())
        slots = [[d[2] for d in decls]]  # return type, then each parameter (K&R declarations have none)
        typed = [d for d in decls if not d[6]]
        for i in range(max((len(d[3]) for d in typed), default=0)):
            slots.append([d[3][i] if i < len(d[3]) else 'missing' for d in typed])
        for es in slots:
            if None in es and all(isinstance(e, tuple) or e is None for e in es):
                edits |= {e for e in es if e}
    by_file = collections.defaultdict(list)
    for e in edits:
        by_file[e[0]].append(e)
    if not dry:
        for f, es in by_file.items():
            data = (ROOT / f).read_bytes()
            for _, s, e, old, new in sorted(set(es), key=lambda x: -x[1]):
                if data[s:e].split() != old.encode().split():
                    sys.exit('%s:%d: expected %r, found %r' % (f, s, old, data[s:e]))
                data = data[:s] + new.encode() + data[e:]
            (ROOT / f).write_bytes(data)
    return edits, left, sorted(by_file)


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('--rounds', type=int, default=12)
    ap.add_argument('--dry', action='store_true')
    ap.add_argument('files', nargs='*')
    args = ap.parse_args()
    files = args.files or [s for s in hazards64.build.sources() if editable(s)]
    total = 0
    for n in range(1, args.rounds + 1):
        edits, left, changed = round_(files, args.dry)
        total += len(edits)
        print('round %d: %d retypes in %d files, %d places left' % (n, len(edits), len(changed), len(left)))
        if not edits or args.dry:
            break
    LEFT.write_text('file\tline\treason\n' + ''.join('%s\t%s\t%s\n' % x for x in sorted(set(left), key=str)))
    reasons = collections.Counter(re.sub(r' \w+$|: .*| of \w+', '', x[2]) for x in left)
    print('lp64_words: %d retypes; left %d -> %s' % (total, len(left), LEFT))
    for k, v in reasons.most_common(12):
        print('%6d %s' % (v, k))


if __name__ == '__main__':
    main()
