#!/usr/bin/env python3
"""Phase-2 work list: declarations that disagree with the function's definition.

IDO passed everything in registers, so `void f(s32)` in one file and `void f(f32 x) {}` in
another worked on the N64; natively (and in wasm) only FixCalls makes such calls work. libclang
reads every game file as the native LP64 build sees it and compares each declaration of a
function with its definition, parameter by parameter (canonical types):

  float   int vs float, or float vs double: another register class, wrong value natively
  arity   different parameter count (K&R `f()` declarations do not count)
  ret     return type of another class (void vs value, int vs float)
  size    integer of another size, or integer vs pointer (same register, value truncated)
  ok      pointer vs pointer, sign only

  protos.py            -> build/protos.tsv (function, kind, definition, declaration, where)
  protos.py fix        rewrites each such declaration to the definition's signature (same line
                       count), then reverts the ones clang rejects in the N64 or the native view
  protos.py n64 [TREE] make check in the Docker clone against TREE/build.pre (objects built before
                       `fix`); reverts the declarations used by functions whose code changed and
                       records them in protos_ido_keep.txt, until the ROM matches
"""
import collections
import json
from multiprocessing import Pool
import os
from pathlib import Path
import re
import subprocess
import sys

import lp64_words as L

ci, K, T = L.ci, L.K, L.T
ROOT = L.ROOT
OUT = ROOT / 'build' / 'protos.tsv'
FLOAT = {T.FLOAT, T.DOUBLE}
EDITS = ROOT / 'build' / 'protos_edits.jsonl'
KEEP = Path(__file__).resolve().parent / 'protos_ido_keep.txt'  # "file name": IDO needs this declaration as it is


def cls(t):
    t = t.get_canonical()
    if t.kind in FLOAT:
        return 'f%d' % t.get_size()
    if t.kind == T.VOID:
        return 'void'
    if t.kind in (T.POINTER, T.CONSTANTARRAY, T.INCOMPLETEARRAY, T.FUNCTIONPROTO):
        return 'ptr'
    if t.kind in (T.RECORD,):
        return 'rec'
    return 'i%d' % max(t.get_size(), 0)


BASIC = re.compile(r'^(?:(?:const|volatile|unsigned|signed|void|char|short|int|long|float|double|u8|s8|u16|s16|u32|s32|'
                   r'u64|s64|f32|f64|BtIntPtr|BtUIntPtr)\b|[\s*]|\[\w*\])*$')


def portable(t):
    """t's spelling if every file knows it, else a type of the same register class and size"""
    if BASIC.match(t.spelling):
        return t.spelling
    c = t.get_canonical()
    if c.kind in (T.POINTER, T.CONSTANTARRAY, T.INCOMPLETEARRAY):
        return 'void *'
    if c.kind == T.ENUM:
        return 's32'
    return {T.UCHAR: 'u8', T.CHAR_U: 'u8', T.SCHAR: 's8', T.CHAR_S: 's8', T.USHORT: 'u16', T.SHORT: 's16',
            T.INT: 's32', T.UINT: 'u32', T.FLOAT: 'f32', T.DOUBLE: 'f64'}.get(c.kind)


def portable_sig(c):
    t = c.type
    if t.kind != T.FUNCTIONPROTO or t.is_function_variadic():
        return None
    parts = [portable(t.get_result())] + [portable(a.type) for a in c.get_arguments()]
    if None in parts:
        return None
    args = ', '.join(('%s %s' % (p, a.spelling)).replace('* ', '*').strip() for p, a in zip(parts[1:], c.get_arguments()))
    return '%s %s(%s)' % (parts[0], c.spelling, args or 'void')


def collect(path):
    try:
        tu = ci.Index.create().parse(str(ROOT / path), L.FLAGS)
    except ci.TranslationUnitLoadError:
        return []
    out = []

    def visit(c):
        if c.kind == K.FUNCTION_DECL:
            loc = c.location
            f = L.rel(loc)
            if f and L.editable(f):
                t = c.type
                params = [cls(p) for p in t.argument_types()] if t.kind == T.FUNCTIONPROTO else None
                ext, sig, alt = c.extent, None, None
                if c.is_definition():
                    body = [ch for ch in c.get_children() if ch.kind == K.COMPOUND_STMT]
                    if body:
                        sig = (ROOT / f).read_bytes()[ext.start.offset:body[0].extent.start.offset].decode('latin-1')
                        alt = portable_sig(c)
                out.append((c.spelling, c.is_definition(), cls(t.get_result()), params,
                            '%s:%d' % (f, loc.line), t.spelling, ext.start.offset, ext.end.offset, sig, alt))
        for ch in c.get_children():
            if ch.kind in (K.FUNCTION_DECL, K.COMPOUND_STMT, K.DECL_STMT) or c.kind == K.TRANSLATION_UNIT:
                visit(ch)
    visit(tu.cursor)
    return out


def kind(a, b):
    """how much a declaration class b differs from definition class a"""
    if a == b:
        return 'ok'
    if a.startswith('f') or b.startswith('f'):
        return 'float'
    if 'void' in (a, b) or 'rec' in (a, b):
        return 'ret'
    return 'ok' if {a, b} == {'ptr', 'i8'} else 'size'  # BtIntPtr next to a pointer is fine


def kinds(dret, dparams, ret, params):
    out = set()
    r = kind(dret, ret)
    if r != 'ok':
        out.add('ret' if r in ('ret', 'float') else r)
    if params is not None and dparams is not None:
        if len(params) != len(dparams):
            out.add('arity')
        out |= {kind(a, b) for a, b in zip(dparams, params)} - {'ok'}
    return out


def parse_all():
    files = [s for s in L.hazards64.build.sources() if L.editable(s)]
    with Pool(os.cpu_count()) as pool:
        return [d for ds in pool.map(collect, files) for d in ds]


def plan():
    """[(file, start, end, line, name, new text)] for every declaration unlike its definition"""
    decls = parse_all()
    defs = collections.defaultdict(dict)  # name -> {file: (ret, params, signature)}
    for name, is_def, ret, params, where, _, _, _, sig, alt in decls:
        if is_def and sig is not None:
            sig = ' '.join(re.sub(r'/\*.*?\*/', ' ', sig, flags=re.S).split())
            if '//' not in sig and '#' not in sig and sig.endswith(')') and re.search(r'\b%s ?\(' % name, sig):
                defs[name][where.split(':')[0]] = (ret, params, sig, alt)
    keep = set(KEEP.read_text().splitlines()) if KEEP.exists() else set()
    starts = collections.Counter(k[:2] for k in {(d[4].split(':')[0], d[6], d[0]) for d in decls})  # several declarators
    out = {}
    for name, is_def, ret, params, where, _, start, end, _, _ in decls:
        f, line = where.split(':')
        ds = defs.get(name)
        if is_def or not ds or '%s %s' % (f, name) in keep or starts[(f, start)] > 1:
            continue
        cands = [ds[f]] if f in ds else [d for d in ds.values() if not d[2].startswith('static ')]
        if len({d[2] for d in cands}) != 1:
            continue
        dret, dparams, sig, alt = cands[0]
        if not kinds(dret, dparams, ret, params):
            continue
        src = (ROOT / f).read_bytes()
        old = src[start:end].decode('latin-1')
        m = re.search(r'\b(_?%s)\s*\(' % name, old)  # `_x_entrypoint_N`: overlay_aliases.h maps the stub's name
        if not m or not src[end:].lstrip().startswith(b';') or '#' in old:
            continue  # from a macro, several declarators, or a preprocessor line inside
        sig, alt = [x and re.sub(r'\b%s\b' % name, m.group(1), x) for x in (sig, alt)]
        pre = 'extern ' if old.startswith('extern ') and not sig.startswith(('static ', 'extern ')) else ''
        if sig.startswith('static ') and alt:
            alt = 'static ' + alt
        out[(f, start)] = (f, start, end, int(line), name, old, pre + sig + '\n' * old.count('\n'),
                           alt and alt != sig and pre + alt + '\n' * old.count('\n'))
    return sorted(out.values())


N64_ARGS = ['-fsyntax-only', '-Wno-everything', '-ferror-limit=0'] + L.offsets.ARGS
ERR = re.compile(r'^(.+?):(\d+):\d+: (?:fatal )?error: (.*)$')


def diag(job):
    """clang errors of one file in the N64 view (IDO's sources) or the native view: (file, line, message)"""
    f, native, root = job
    import syntax_new
    args = (['-fsyntax-only', '-w', '-ferror-limit=0', '-Wno-implicit-function-declaration', '-Wno-int-conversion',
             '-Wno-incompatible-pointer-types', '-Wno-return-mismatch', '-Wno-implicit-int'] + syntax_new.NATIVE_ARGS
            ) if native else N64_ARGS
    r = subprocess.run([syntax_new.CLANG] + args + [f], capture_output=True, text=True, cwd=root)
    return [(m.group(1), int(m.group(2)), m.group(3)) for m in map(ERR.match, r.stderr.splitlines()) if m]


BASE = ROOT / 'build' / 'protos_base.json'  # clang's errors before `fix`


def diag_all(root=ROOT):
    """{"file view": errors} for every game file in both views of the tree at root"""
    n64 = subprocess.run(['git', 'ls-files', 'src/*.c'], cwd=ROOT, capture_output=True, text=True).stdout.split()
    js = [(f, False, str(root)) for f in n64] + [(f, True, str(root)) for f in L.hazards64.build.sources() if L.editable(f)]
    with Pool(os.cpu_count()) as pool:
        return {'%s %d' % j[:2]: [list(e) for e in es] for j, es in zip(js, pool.map(diag, js, chunksize=4))}


def uses(e, text):
    return re.search(r'\b_?%s\b' % e['name'], text)


def load():
    return [json.loads(l) for l in EDITS.read_text().splitlines()] if EDITS.exists() else []


def save(edits):
    EDITS.write_text(''.join(json.dumps(e) + '\n' for e in edits))


def revert(edits, bad, why, retry=False):
    """puts the old text of the edits in bad back; returns the remaining edits. With retry, an edit
    that has a portable form left (and its siblings of that name in the file) switches to it instead"""
    bad = [e for e in bad if e in edits]
    if retry:
        names = {(e['file'], e['name']) for e in bad if e.get('alt')}
        bad += [e for e in edits if (e['file'], e['name']) in names and e not in bad]
    gone = []
    for f in {e['file'] for e in bad}:
        text = (ROOT / f).read_bytes()
        lines = text.split(b'\n')
        for e in [e for e in bad if e['file'] == f]:
            i = e['line'] - 1
            span = b'\n'.join(lines[i:i + 1 + e['new'].count('\n')])
            to = e.pop('alt', None) if retry and (f, e['name']) in names else None
            new, old = e['new'].encode('latin-1'), (to or e['old']).encode('latin-1')
            assert new in span, (f, e['line'], e['name'])
            lines[i:i + 1 + e['new'].count('\n')] = span.replace(new, old, 1).split(b'\n')
            if to:
                e['new'] = to
            else:
                e.pop('alt', None)
                gone.append(e)
        (ROOT / f).write_bytes(b'\n'.join(lines))
    print('  %d declarations: %d back to the original, %d to the portable form (%s)'
          % (len(bad), len(gone), len(bad) - len(gone), why))
    return [e for e in edits if e not in gone]


def settle(edits):
    """reverts edits until clang reports no error the tree did not have before them"""
    base = json.loads(BASE.read_text())
    for round_ in range(1, 16):
        now = diag_all()
        bad, loose = [], []
        for key in sorted(now):
            j = key.split(' ')
            extra = collections.Counter(map(tuple, now[key])) - collections.Counter(map(tuple, base.get(key, [])))
            for ef, line, msg in extra:
                ef = os.path.relpath(os.path.join(ROOT, ef), ROOT)
                try:
                    src = (ROOT / ef).read_text('latin-1').split('\n')[line - 1]
                except (OSError, IndexError):
                    src = ''
                hit = [e for e in edits if (e['file'] in (ef, j[0]) or e['file'].endswith('.h')) and uses(e, msg + ' ' + src)]
                if hit:
                    bad += hit
                else:
                    loose.append((j, ef, line, msg))
                    bad += [e for e in edits if e['file'] == j[0]]
        if loose:
            print('  %d errors without a name, e.g. %s' % (len(loose), loose[:3]))
        if not bad:
            if loose:
                sys.exit('settle: errors left that no edit explains')
            return edits
        uniq = []
        for e in bad:
            if e not in uniq:
                uniq.append(e)
        edits = revert(edits, uniq, 'clang, round %d' % round_, retry=True)
        save(edits)
    sys.exit('settle: still new errors after %d rounds' % round_)


def fix():
    items = plan()
    print('fix: %d declarations to rewrite in %d files' % (len(items), len({i[0] for i in items})))
    BASE.write_text(json.dumps(diag_all()))
    by = collections.defaultdict(list)
    for it in items:
        by[it[0]].append(it)
    edits = load()  # earlier, verified rounds stay in the log
    for f, its in by.items():
        src, last = (ROOT / f).read_bytes(), None
        for _, start, end, line, name, old, new, alt in sorted(its, key=lambda x: -x[1]):
            if last is not None and end > last:
                continue  # overlapping extents
            src, last = src[:start] + new.encode('latin-1') + src[end:], start
            edits.append({'file': f, 'line': line, 'name': name, 'old': old, 'new': new, **({'alt': alt} if alt else {})})
        (ROOT / f).write_bytes(src)
    save(edits)
    edits = settle(edits)
    print('fix: %d declarations rewritten in %d files; now `protos.py n64`' % (len(edits), len({e['file'] for e in edits})))


def n64(tree):
    tree = tree.resolve()
    if not (tree / 'build.pre').exists():
        sys.exit('n64: %s/build.pre missing (objects of the tree before `fix`)' % tree)
    edits, rejected = load(), []
    files = subprocess.run(['git', 'ls-files', 'src/*.c'], cwd=ROOT, capture_output=True, text=True).stdout.split()
    try:
        for round_ in range(1, 16):
            L.offsets.sync(tree)
            ok, log = L.offsets.docker_make(tree, '-k')  # -k: every compile error in one round
            if ok:
                print('n64 round %d: make check OK' % round_)
                break
            errs = re.findall(r'^cfe: Error: (\S+), line (\d+):', log.read_text(errors='replace'), re.M)
            if errs:  # IDO rejects what clang took: the declarations named on those lines, else the file's
                hit = []
                for f, line in errs:
                    src = (ROOT / f).read_text('latin-1').split('\n')[int(line) - 1]
                    named = [e for e in edits if (e['file'] == f or e['file'].endswith('.h')) and uses(e, src)]
                    hit += [e for e in named or [e for e in edits if e['file'] == f] if e not in hit]
                print('n64 round %d: %d IDO compile errors' % (round_, len(errs)))
                if not hit:
                    sys.exit('n64: IDO errors that no rewritten declaration explains; see %s' % log)
                rejected += hit
                edits = revert(edits, hit, 'IDO error')
                save(edits)
                continue
            bad = subprocess.run([sys.executable, str(Path(__file__).with_name('n64_objdiff.py')), str(tree),
                                  'build.pre', 'build'] + files, capture_output=True, text=True, check=True).stdout.split()
            hit = []
            for b in bad:
                f, func = b.rsplit(':', 1)
                text = (ROOT / f).read_text('latin-1')
                body = ' '.join(text[a:z] for a, z in L.offsets.bodies(text, func))
                hit += [e for e in edits if (e['file'] == f or e['file'].endswith('.h')) and e not in hit
                        and uses(e, body)]
            print('n64 round %d: make check FAIL, %d functions differ' % (round_, len(bad)))
            if not hit:  # a compile error outside every function body: give up on these files
                failed = {b.rsplit(':', 1)[0] for b in bad}
                hit = [e for e in edits if e['file'] in failed]
            if not hit:
                sys.exit('n64: make check fails and no rewritten declaration explains it; see %s' % log)
            rejected += hit
            edits = revert(edits, hit, 'IDO code changed')
            save(edits)
        else:
            sys.exit('n64: make check still fails; see %s' % log)
    finally:
        old = set(KEEP.read_text().splitlines()) if KEEP.exists() else set()
        KEEP.write_text(''.join(x + '\n' for x in sorted(old | {'%s %s' % (e['file'], e['name']) for e in rejected})))
    print('n64: %d declarations kept as IDO needs them, %d rewritten' % (len(rejected), len(edits)))


def main():
    if sys.argv[1:2] == ['fix']:
        return fix()
    if sys.argv[1:2] == ['settle']:  # after an interrupted fix; `settle TREE` takes the errors before from TREE
        if len(sys.argv) > 2:
            BASE.write_text(json.dumps(diag_all(Path(sys.argv[2]).resolve())))
        return print('settle: %d declarations rewritten' % len(settle(load())))
    if sys.argv[1:2] == ['n64']:
        return n64(Path(sys.argv[2]) if len(sys.argv) > 2 else ROOT / 'build' / 'n64verify')
    decls = parse_all()
    by = collections.defaultdict(dict)
    for name, is_def, ret, params, where, spelling, *_ in decls:
        by[name][(where, is_def)] = (ret, params, spelling)
    rows, counts = [], collections.Counter()
    for name, ds in sorted(by.items()):
        defs = [v for (w, d), v in ds.items() if d]
        if not defs:
            continue
        dret, dparams, dspell = defs[0]
        for (where, is_def), (ret, params, spelling) in sorted(ds.items()):
            if is_def:
                continue
            for k in sorted(kinds(dret, dparams, ret, params)):
                counts[k] += 1
                rows.append((name, k, dspell, spelling, where))
    OUT.write_text('function\tkind\tdefinition\tdeclaration\twhere\n' +
                   ''.join('\t'.join(r) + '\n' for r in sorted(set(rows))))
    funcs = collections.Counter(k for _, k in {(r[0], r[1]) for r in rows})
    print('protos: %d declarations disagree with their definition -> %s' % (len(set(rows)), OUT))
    for k in ('float', 'ret', 'arity', 'size'):
        print('  %-6s %5d declarations, %4d functions' % (k, counts[k], funcs[k]))


if __name__ == '__main__':
    main()
