#!/usr/bin/env python3
"""Phase 1: asm .bss labels become typed C definitions in the native build.

The N64 build keeps its bss in asm (IDO orders bss by its own rules), so the definitions sit
under BT_NATIVE at the end of a C file that declares the label, with that file's own type:

    #ifdef BT_NATIVE
    /* bss_to_c.py: native definitions of asm .bss labels */
    f32 D_80127630[3] BT_DATA(4, bss_core2bss1_0_2, 0x1230);
    #endif

BT_DATA keeps each asm file's labels one block at their N64 offsets (bt-datagroup), because
code reaches neighbours through a label. A label whose declared type is larger than the gap to
the next label covers those labels (the pass makes them aliases into it). Labels without a
usable declaration go to pc/native/bss_untyped.c as byte arrays. Skipped: bss files that touch
asm .data/.rodata of their module still built from asm (same block in data.py).

    bss_to_c.py scan      numbers only
    bss_to_c.py apply     write the definitions; reverts to the next candidate where clang objects
    bss_to_c.py revert    remove them again
then build.py, port.py gate, make check.
"""
import collections
import hashlib
from multiprocessing import Pool
import os
from pathlib import Path
import re
import subprocess
import sys

import build
import data
import offsets

ci, K, T = offsets.ci, offsets.K, offsets.T
ROOT = offsets.ROOT
FLAGS = [f for f in build.GUEST_FLAGS if f not in ('-flto', '-Xclang', '-disable-llvm-passes')] + [
    '-resource-dir', subprocess.run([build.CLANG, '-print-resource-dir'], capture_output=True, text=True).stdout.strip()]
MARK = '/* bss_to_c.py: native definitions of asm .bss labels */'
BLOCK = re.compile(r'\n\n#ifdef BT_NATIVE\n' + re.escape(MARK) + r'\n.*?\n#endif\n', re.S)
UNTYPED = ROOT / 'pc' / 'native' / 'bss_untyped.c'
OWN = ROOT / 'build' / 'bss_to_c.txt'  # labels this script defined: the build's objects have them, yet they are its work
NAMES = set()


def remaining():
    """{label: (group, offset, extent, block alignment, block size)} of asm .bss labels that no C
    object defines. data.py aligns a file's block like its N64 address (up to 16) and reserves all of it."""
    tag = build.flags_hash(build.GUEST_FLAGS + [hashlib.sha1((build.HERE / 'bitfields.py').read_bytes()).hexdigest()])
    defs, _ = build.nm([build.OUT / 'obj' / tag / (s.replace('/', '__') + '.o') for s in build.sources()])
    defs = {n for n, k in defs.items() if k.upper() in 'DBRCV'} - set(OWN.read_text().split() if OWN.exists() else [])
    parsed = [(p, s, l, i) for p in build.data_files() for s, l, i in data.parse_file(p)
              if s in ('data', 'rodata', 'bss') and (l or i)]
    spans = collections.defaultdict(list)  # touching sections of one module are one block in data.py
    for p, s, l, i in parsed:
        q = Path(p)
        spans[(str(q.parent), q.name.split('.')[0] if 'overlays' in q.parts else '')].append((data.span(l, i), s, l))
    out, skipped = {}, 0
    for p, s, labels, items in parsed:
        q = Path(p)
        if s != 'bss' or not any(n not in defs for n in labels):
            continue
        (base, end), mod = data.span(labels, items), spans[(str(q.parent), q.name.split('.')[0] if 'overlays' in q.parts else '')]
        if any(s2 != 'bss' and (e2 == base or b2 == end) and any(n not in defs for n in l2) for (b2, e2), s2, l2 in mod):
            skipped += sum(n not in defs for n in labels)
            continue
        group = 'bss_' + re.sub(r'\W', '_', q.name.split('.')[0] if 'overlays' not in q.parts else
                                '%s_%s' % (q.parent.name, q.name.split('.')[0]))
        order = sorted(labels.items(), key=lambda kv: kv[1])
        for k, (name, addr) in enumerate(order):
            nxt = next((a for _, a in order[k + 1:] if a > addr), end)
            if name not in defs:
                out[name] = (group, addr - base, nxt - addr, min(16, base & -base), end - base)
    return out, skipped


def init(names):
    NAMES.update(names)


def collect(path):
    """[(label, this file, at file scope, definition text with %s for an open array bound, size,
    element size, alignment)] for the declarations of NAMES this translation unit sees"""
    try:
        tu = ci.Index.create().parse(str(ROOT / path), FLAGS)
    except ci.TranslationUnitLoadError:
        return []
    out = []
    for c in tu.cursor.walk_preorder():
        if c.kind != K.VAR_DECL or c.spelling not in NAMES or c.is_definition():
            continue
        toks = [x.spelling for x in c.get_tokens() if x.kind != ci.TokenKind.COMMENT]
        if not toks or ',' in toks or '=' in toks or '{' in toks or toks[0] == c.spelling or c.spelling not in toks:
            continue  # several declarators share the type, or the type is defined in the declaration
        t = c.type.get_canonical()
        el = t.element_type.get_size() if t.kind in (T.CONSTANTARRAY, T.INCOMPLETEARRAY) else 0
        text = ' '.join(x for x in toks if x != 'extern')
        if t.kind == T.INCOMPLETEARRAY:
            i = toks.index(c.spelling)
            if toks[i + 1:i + 3] != ['[', ']'] or el <= 0:
                continue
            text = ' '.join([x for x in toks[:i + 2] if x != 'extern'] + ['%s'] + toks[i + 2:])
        elif t.get_size() <= 0:
            continue  # incomplete struct
        out.append((c.spelling, path, c.semantic_parent.kind == K.TRANSLATION_UNIT, text, t.get_size(), el,
                    max(t.get_align(), 1)))
    return out


def candidates(labels):
    """{label: [(file, definition line)]}, best first"""
    files = [s for s in build.sources() if s.startswith('src/')]
    with Pool(os.cpu_count(), init, (set(labels),)) as pool:
        decls = {d for ds in pool.map(collect, files, chunksize=8) for d in ds}
    by = collections.defaultdict(list)
    for name, f, top, text, size, el, align in decls:
        group, off, extent = labels[name][:3]
        if '%s' in text:  # T x[]: as many elements as fit
            if el > extent:
                continue
            text, size = text % (extent // el), extent // el * el
        # fits best: the largest type inside the gap; else the smallest one running over later labels
        rank = (0, -size) if size <= extent else (1, size)
        by[name].append((rank, not top, f, '%s BT_DATA(%d, %s, 0x%X);' % (text, max(align, 4), group, off), size))
    return {n: sorted(set(v)) for n, v in by.items()}


def untyped(name, labels):
    group, off, extent = labels[name][:3]
    return 'u8 %s[%d] BT_DATA(4, %s, 0x%X);' % (name, max(extent, 1), group, off)


def write(choice, labels):
    """choice: {label: (file, line, size) or None}; rewrites the blocks of every file"""
    by = collections.defaultdict(list)
    first, last = {}, {}  # per group: its lowest label, and where its last object ends
    for name, c in choice.items():
        group, off, extent, align, span = labels[name]
        first[group] = min(first.get(group, (off, name)), (off, name))
        last[group] = (max(last.get(group, (0,))[0], off + (c[2] if c else max(extent, 1))), span)
    for name, c in choice.items():
        group, off, extent, align, span = labels[name]
        line = c[1] if c else untyped(name, labels)
        if first[group][1] == name:  # the block's alignment, as data.py gave the asm file's block
            line = re.sub(r'BT_DATA\((\d+)', lambda m: 'BT_DATA(%d' % max(int(m.group(1)), align), line)
        by[c[0] if c else None].append(((group, off), line))
    for group, (end, span) in last.items():  # code may run past the last label's type: keep the file's size
        if end < span:
            by[None].append(((group, span - 1), 'u8 %s__end[1] BT_DATA(1, %s, 0x%X);' % (group, group, span - 1)))
    for f in {p for p in map(str, (ROOT / 'src').rglob('*.c')) if MARK in Path(p).read_text(errors='replace')} | \
            {str(ROOT / f) for f in by if f}:
        p = Path(f)
        text = BLOCK.sub('\n', p.read_text('latin-1'))
        lines = [l for _, l in sorted(by.get(os.path.relpath(f, ROOT), []))]
        if lines:
            text = text.rstrip('\n') + '\n\n#ifdef BT_NATIVE\n%s\n#include "bt_data.h"\n%s\n#endif\n' % (MARK, '\n'.join(lines))
        p.write_text(text, 'latin-1')
    if by.get(None):
        UNTYPED.write_text('%s\n/* labels without a declaration the definition could use; regenerate with bss_to_c.py apply */\n'
                           '#include "common.h"\n\n%s\n' % (MARK, '\n'.join(l for _, l in sorted(by[None]))))
    elif UNTYPED.exists():
        UNTYPED.unlink()


def errors(f):
    """(line, message) of clang's errors for file f as the native build compiles it"""
    r = subprocess.run([build.CLANG, '-fsyntax-only', '-ferror-limit=0'] + FLAGS + [str(ROOT / f)],
                       capture_output=True, text=True)
    return [(int(m.group(1)), m.group(2)) for m in
            re.finditer(r'^%s:(\d+):\d+: (?:fatal )?error: (.*)$' % re.escape(str(ROOT / f)), r.stderr, re.M)]


def apply():
    labels, skipped = remaining()
    own = sorted(labels)
    if os.environ.get('BT_BSS_GROUPS'):  # "lo:hi" of the sorted groups, to halve a gate failure
        lo, hi = map(int, os.environ['BT_BSS_GROUPS'].split(':'))
        keep = set(sorted({v[0] for v in labels.values()})[lo:hi])
        print('  groups %d:%d: %s' % (lo, hi, ' '.join(sorted(keep))[:300]))
        labels = {n: v for n, v in labels.items() if v[0] in keep}
    skip = set(os.environ.get('BT_BSS_SKIP', '').split())  # groups to leave in asm
    labels = {n: v for n, v in labels.items() if v[0] not in skip}
    cands = candidates(labels)
    choice = {n: cands[n][0][2:5] if n in cands else None for n in labels}
    tried = collections.defaultdict(int)
    for round_ in range(1, 12):
        write(choice, labels)
        files = sorted({c[0] for c in choice.values() if c} | ({'pc/native/bss_untyped.c'} if UNTYPED.exists() else set()))
        with Pool(os.cpu_count()) as pool:
            errs = dict(zip(files, pool.map(errors, files)))
        bad, why = set(), collections.Counter()
        for f, es in errs.items():
            src = (ROOT / f).read_text('latin-1').split('\n')
            for line, msg in es:
                hit = [n for n in labels if re.search(r'\b%s\b' % n, src[line - 1] + ' ' + msg)]
                if not hit:
                    sys.exit('apply: %s:%d: %s (not caused by a definition?)' % (f, line, msg))
                bad |= set(hit)
                why[re.sub(r"'[^']*'", 'T', msg)] += 1
        if not bad:
            break
        for n in bad:  # the next declaration, or bytes
            tried[n] += 1
            choice[n] = cands[n][tried[n]][2:5] if tried[n] < len(cands.get(n, [])) else None
        print('  round %d: %d definitions rejected by clang, trying their next declaration (%s)'
              % (round_, len(bad), '; '.join('%d %s' % (v, k) for k, v in why.most_common(4))))
    else:
        sys.exit('apply: clang still objects')
    OWN.write_text(''.join(n + '\n' for n in own))
    sizes = {n: choice[n][2] for n in labels if choice[n]}
    print('apply: %d labels typed in %d files (%d cover later labels), %d as bytes in %s; %d left in asm (module data not in C yet)'
          % (len(sizes), len({c[0] for c in choice.values() if c}), sum(sizes[n] > labels[n][2] for n in sizes),
             len(labels) - len(sizes), UNTYPED.relative_to(ROOT), skipped))


def main():
    cmd = sys.argv[1] if len(sys.argv) > 1 else 'scan'
    if cmd == 'apply':
        return apply()
    if cmd == 'revert':  # rebuild before the next apply: the objects still define the labels
        OWN.unlink(missing_ok=True)
        return write({}, {})
    labels, skipped = remaining()
    cands = candidates(labels)
    fit = sum(1 for n in labels if n in cands and cands[n][0][0][0] == 0)
    print('scan: %d bss labels in %d asm files; %d with a fitting declaration, %d whose type runs over later labels, '
          '%d without usable declaration; %d skipped (module data still asm)'
          % (len(labels), len({v[0] for v in labels.values()}), fit, len(cands) - fit, len(labels) - len(cands), skipped))


if __name__ == '__main__':
    main()
