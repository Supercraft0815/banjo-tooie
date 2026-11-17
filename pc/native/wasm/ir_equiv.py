#!/usr/bin/env python3
"""Which game functions behave differently from a reference build, as FixCalls leaves them.

A native source fix must do exactly what FixCalls did with the old source. The gate only sees
the paths the recorded runs take; this compares every function. Both builds' game.linked.bc go
through FixCalls and a fixed set of local cleanups (no inlining, so a function's IR is its own).
Each function is then reduced to a canonical text: pointer/int/float reinterpretations dropped
(the same register bits in ILP32; a numeric conversion such as sitofp stays), attributes and
metadata dropped, values and labels renumbered in order of appearance. Different text means
different behaviour, or a harmless form change to look at; equal text means the same code.
A function that returns a value where the reference returned nothing counts as unchanged when
it is otherwise the same: its callers, compared too, show any effect.

    ir_equiv.py REF_DIR NEW_ROOT      REF_DIR holds game.linked.bc and linker_syms.txt
"""
import argparse
import difflib
from pathlib import Path
import re
import subprocess
import sys
import tempfile

LLVM_BIN = '/opt/homebrew/opt/llvm/bin'
PASSES = ('function(mem2reg),bt-fixcalls,bt-bigendian,'
          'function(sroa,early-cse,instcombine<no-verify-fixpoint>,simplifycfg,instcombine<no-verify-fixpoint>,dce)')
CAST = re.compile(r'^\s*(%[\w.]+) = (?:inttoptr|ptrtoint|bitcast) \S+ (%[\w.]+|@[\w.$"]+) to \S+\s*$')
CONST_CAST = re.compile(r'\b(?:inttoptr|ptrtoint|bitcast) \((?:i32|ptr|float) ([^()]*?) to (?:i32|ptr|float)\)')


def normalized(bc: Path, syms: Path, plugin: Path, out: Path):
    with tempfile.TemporaryDirectory() as tmp:
        r = subprocess.run([LLVM_BIN + '/opt', '--load-pass-plugin=%s' % plugin, '-passes=' + PASSES,
                            '-bt-abs-syms=%s' % syms, '-bt-widened=%s' % (Path(tmp) / 'w.txt'),
                            '-bt-xsym-sites=%s' % (Path(tmp) / 'x.txt'), '-S', str(bc), '-o', str(out)],
                           capture_output=True, text=True)
    if r.returncode:
        raise RuntimeError('opt failed for %s:\n%s' % (bc, r.stderr[:4000]))


def functions(text):
    """{name: (define line, [body lines])}"""
    out = {}
    for m in re.finditer(r'^define [^\n]*?@("?[^"(\s]+"?)\(([^\n]*)\{\n(.*?)^\}', text, re.M | re.S):
        out[m.group(1).strip('"')] = (m.group(0).split('\n', 1)[0], m.group(3).splitlines())
    return out


def canonical(define, body, void=False):
    """Canonical lines of one function (see the module doc). void: the reference returns nothing."""
    if void:
        body = [re.sub(r'^(\s*)ret \S+ \S+\s*$', r'\1ret void', l) for l in body]
    used = {}
    for line in body:
        for v in re.findall(r'%[\w.]+', line.split(' = ', 1)[1] if ' = ' in line else line):
            used[v] = used.get(v, 0) + 1
    # an unused call result is the same call (a void callee that got a return value)
    body = [re.sub(r'^(\s*)(%[\w.]+) = ((?:tail )?call )\S+ ', r'\1\3void ', l) if re.match(r'^\s*(%[\w.]+) = (?:tail )?call ', l)
            and not used.get(re.match(r'^\s*(%[\w.]+)', l).group(1)) else l for l in body]
    alias = {}
    for line in body:
        m = CAST.match(line)
        if m:
            alias[m.group(1)] = m.group(2)

    def resolve(v):
        seen = set()
        while v in alias and v not in seen:
            seen.add(v)
            v = alias[v]
        return v
    names = {}

    def rename(m):
        v = resolve(m.group(0))
        if v.startswith('@'):
            return v
        return names.setdefault(v, '%%%d' % len(names))
    head = re.sub(r'^define .*?@', '@', define)
    params = re.findall(r'(%[\w.]+)\s*[,)]', head)
    while params and not used.get(params[-1]):  # an unused trailing parameter (ARGS widening) changes nothing
        params.pop()
    ret = re.match(r'define (?:[a-z_]+ )*?(void|i\d+|ptr|float|double)\b', define.replace('dso_local ', '').replace('internal ', ''))
    rt = 'void' if void else {'ptr': 'i32', 'float': 'i32'}.get(ret.group(1), ret.group(1)) if ret else '?'
    lines = ['ret-type ' + rt, 'params %d' % len(params)]
    for p in params:
        rename(re.match(r'.*', p))
    for line in body:
        if CAST.match(line) or not line.strip() or line.lstrip().startswith(';'):
            continue
        line = re.sub(r';.*$', '', line)
        if re.match(r'^[\w.]+:', line):  # a label
            line = '%' + line.split(':')[0] + ':'
        line = CONST_CAST.sub(r'\1', line)
        line = re.sub(r'%[\w.]+', rename, line)
        line = re.sub(r'\b(noundef|nonnull|nuw|nsw|nneg|zeroext|signext|inbounds|exact|disjoint|samesign|tail|musttail|'
                      r'dereferenceable(?:_or_null)?\(\d+\)|align \d+|nocapture|readonly|writeonly)\b|#\d+|,? ![\w.]+ !\d+', '', line)
        line = re.sub(r'@\.[\w.]+', '@.private', line)  # numbered per module (.str.123)
        line = re.sub(r'(@[A-Za-z_]\w*)\.\d+\b', r'\1', line)  # function-local statics (D_x.6513)
        line = re.sub(r'\b(ptr|float)\b', 'i32', line)  # same register bits in ILP32
        line = re.sub(r'getelementptr i8, i32 (%\d+), i32 (-?\d+)', r'add i32 \1, \2', line)
        lines.append(re.sub(r'\s+', ' ', line).strip(' ,'))
    return lines


def differing(ref_dir: Path, new_root: Path, plugin: Path = None):
    """{function: [changed canonical lines]} between the reference and NEW_ROOT's current build."""
    plugin = plugin or new_root / 'build/ilp32/FixCalls.dylib'
    with tempfile.TemporaryDirectory() as tmp:
        a, b = Path(tmp) / 'a.ll', Path(tmp) / 'b.ll'
        normalized(ref_dir / 'game.linked.bc', ref_dir / 'linker_syms.txt', plugin, a)
        normalized(new_root / 'build/ilp32/game.linked.bc', new_root / 'build/ilp32/gen/linker_syms.txt', plugin, b)
        old, new = functions(a.read_text()), functions(b.read_text())
    out = {}
    for name in sorted(set(old) | set(new)):
        if name not in old or name not in new:
            out[name] = ['defined in %s only' % ('the reference' if name in old else 'the new build')]
            continue
        void = re.match(r'define (?:\w+ )*void\b', old[name][0]) is not None
        x, y = canonical(*old[name]), canonical(*new[name], void=void)
        if void and x != y:
            x = canonical(*old[name], void=True)
        if x != y:
            out[name] = [l for l in difflib.unified_diff(x, y, lineterm='', n=0) if l[:1] in '-+' and l[:3] not in ('---', '+++')]
    return out


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('ref', type=Path)
    ap.add_argument('new', type=Path)
    ap.add_argument('--only', help='comma-separated function names')
    args = ap.parse_args()
    found = differing(args.ref, args.new)
    only = set(args.only.split(',')) if args.only else None
    for name, r in found.items():
        if only is None or name in only:
            print(name + ':\n' + ''.join('    %s\n' % l for l in r[:16]), end='')
    return 1 if found else 0


if __name__ == '__main__':
    sys.exit(main())
