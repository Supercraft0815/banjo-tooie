#!/usr/bin/env python3
"""./port-check [--build]: the worker's own check of a port-calls edit (copied into its workspace).

Fast part: allowed files only, line counts unchanged, N64 token view unchanged, native compile.
--build adds the ILP32 build, reports which assigned items remain and every function whose
behaviour (canonical IR after FixCalls) now differs from the reference build.
The trusted parent repeats every check in its own lane; this script is only feedback.
"""
import json
from pathlib import Path
import subprocess
import sys

HERE = Path(__file__).resolve().parent
META = json.loads((HERE / '.port-base' / 'meta.json').read_text())
sys.path.insert(0, META['harness'])
from decomp_harness.port_calls import allowed, changed_files, n64_tokens, first_difference, load_module  # noqa: E402


def main():
    lane = Path(META['lane'])
    changed = changed_files(HERE, lane)
    bad = [p for p in changed if not allowed(p, META['source'])]
    if bad:
        return print('FAIL: only %s and headers (.h under include/ or src/) may change; also changed: %s' % (META['source'], ', '.join(bad))) or 1
    if not changed:
        return print('No change yet.') or 1
    for p in changed:
        old, new = (lane / p).read_text(errors='replace'), (HERE / p).read_text(errors='replace')
        if old.count('\n') != new.count('\n'):
            return print('FAIL: %s has %d lines, the original %d. Never add or remove lines.' % (p, new.count('\n'), old.count('\n'))) or 1
    units = META['units'] if any(p.endswith('.h') for p in changed) else [META['source']]
    for unit in units:
        diff = first_difference(n64_tokens(lane, unit), n64_tokens(HERE, unit))
        if diff:
            return print('FAIL: IDO would see different tokens in %s: %s' % (unit, diff)) or 1
    r = subprocess.run(['clang', *META['native_flags'], '-fsyntax-only', META['source']], cwd=HERE,
                       capture_output=True, text=True)
    if r.returncode:
        return print('FAIL: native compile:\n' + '\n'.join(r.stderr.splitlines()[:40])) or 1
    print('OK: lines, N64 tokens and native compile.')
    if '--build' not in sys.argv:
        return 0
    r = subprocess.run([sys.executable, 'pc/native/wasm/build.py'], cwd=HERE, capture_output=True, text=True)
    if r.returncode:
        return print('FAIL: ILP32 build:\n' + (r.stdout + r.stderr)[-3000:]) or 1
    now = set(l.strip() for l in (HERE / 'build/ilp32/widened.txt').read_text().splitlines() if l.strip())
    irdiff = load_module(HERE / 'pc/native/wasm/ir_equiv.py').differing(HERE / '.port-base/reference-ir', HERE)
    moved = {f: r for f, r in irdiff.items() if META['irdiff'].get(f) != r}
    now |= {'IRDIFF ' + f for f in irdiff}
    left = [i for i in META['items'] if i in now]
    new = sorted(now - set(META['baseline']) - {'IRDIFF ' + f for f in META['irdiff']})
    if moved:
        print('FAIL: behaviour differs from FixCalls on the old code (canonical IR, - reference, + now):')
        for f, r in sorted(moved.items())[:12]:
            print(f + ':\n' + ''.join('    %s\n' % l for l in r[:16]), end='')
    for f in sorted(irdiff):
        if 'IRDIFF ' + f in META['items'] and f not in moved:
            print(f + ' (unchanged so far):\n' + ''.join('    %s\n' % l for l in irdiff[f][:16]), end='')
    if new:
        print('FAIL: new FixCalls items: ' + '; '.join(new[:20]))
    print('Items left: ' + ('; '.join(left) if left else 'none. ALL ITEMS FIXED'))
    return 1 if new or left or moved else 0


if __name__ == '__main__':
    sys.exit(main())
