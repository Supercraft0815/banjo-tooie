#!/usr/bin/env python3
"""List code that reaches one data symbol through another's address (Phase 1/5 work list).

Builds a diagnostic copy with the bt-xsym pass (BT_XSYM=1, separate BT_OUT tree), replays
corpus cases with it and names each access that left its label: function, label used,
symbol actually hit. Output: <out>/xsym_report.tsv plus a short summary on stdout.

  python3 pc/native/wasm/xsym_report.py                 # build + all registered cases
  python3 pc/native/wasm/xsym_report.py --no-build --case intro
"""
import argparse
import bisect
import collections
import os
import re
from pathlib import Path
import subprocess
import sys

import corpus

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]


ALIAS = re.compile(r'@"([^"]+)" = alias i8, ptr (?:getelementptr \(i8, ptr )?@"(__bt_data_\d+)"(?:, i32 (\d+)\))?')


def symbols(out):
    """(address, size, name, block) of every data symbol, sorted: wasm-ld map entries plus every asm
    label of data.ll (unused ones are missing from the map but still split the asm data)."""
    table, blocks = {}, {}
    for line in (out / 'game.map').read_text().splitlines():
        parts = line.split()
        if len(parts) == 4 and '(' not in parts[3] and re.fullmatch(r'[0-9a-f]{8}', parts[0]):
            table[parts[3]] = (int(parts[0], 16), int(parts[2], 16), parts[3], None)
            if parts[3].startswith('__bt_data_'):
                blocks[parts[3]] = table[parts[3]]
    for m in ALIAS.finditer((out / 'gen' / 'data.ll').read_text()):
        block = blocks.get(m.group(2))
        if block:
            offset = int(m.group(3) or 0)
            table[m.group(1)] = (block[0] + offset, block[1] - offset, m.group(1), m.group(2))
    return sorted(table.values())


def resolve(table, starts, address):
    """(label, offset) containing address: the last asm label at or below it inside its block,
    else a C variable that spans it."""
    i = bisect.bisect_right(starts, address) - 1
    for j in range(i, -1, -1):
        start, size, name, block = table[j]
        if name.startswith('__bt_data_'):
            continue
        if address < start + size:
            return name, address - start
    return '?%08x' % address, 0


def run_case(exe, rom, work, name):
    case = corpus.CASES[name]
    work.mkdir(parents=True, exist_ok=True)
    hits = work / 'xsym_hits.txt'
    hits.unlink(missing_ok=True)
    if case['flags'] is not None:
        image = corpus.save_editor.edit(bytes(2048), 0, [(f, True) for f in case['flags']], create=True)
        (work / 'bt_eeprom.bin').write_bytes(image)
    else:
        (work / 'bt_eeprom.bin').unlink(missing_ok=True)
    env = {k: v for k, v in os.environ.items() if not k.startswith('BT_')}
    env.update(BT_VCLOCK='1', BT_HEADLESS='1', BT_EXIT_AFTER=str(case['seconds']),
               **corpus.run_env(case), BT_SAVE=str(work / 'bt_eeprom.bin'), BT_XSYM=str(hits))
    with (work / 'run.log').open('w') as log:
        r = subprocess.run([str(exe), str(rom)], cwd=work, env=env, stdout=log, stderr=log, timeout=7200)
    if r.returncode:
        sys.exit('%s: exit %d, see %s' % (name, r.returncode, work / 'run.log'))
    return [l.split() for l in hits.read_text().splitlines()] if hits.exists() else []


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('--out', type=Path, default=ROOT / 'build' / 'ilp32-xsym')
    ap.add_argument('--rom', type=Path, default=ROOT / 'baserom.us.z64')
    ap.add_argument('--case', action='append', choices=corpus.CASES, help='default: all registered cases')
    ap.add_argument('--no-build', action='store_true')
    args = ap.parse_args()
    out = args.out.resolve()
    if not args.no_build:
        env = dict(os.environ, BT_XSYM='1', BT_OUT=str(out))
        r = subprocess.run([sys.executable, str(HERE / 'build.py')], env=env, capture_output=True, text=True)
        if r.returncode:
            sys.exit('build failed:\n' + (r.stdout + r.stderr)[-4000:])
    sites = {}
    for line in (out / 'xsym_sites.txt').read_text().splitlines():
        sid, func, via, width, kind = line.split()
        sites[sid] = (func, via, width, kind)
    table = symbols(out)
    starts = [t[0] for t in table]
    by_name = {t[2]: t for t in table}
    rows = {}
    for name in args.case or corpus.CASES:
        for sid, addr in run_case(out / 'bt_game', args.rom.resolve(), out / 'runs' / name, name):
            a = int(addr, 16)
            hit, off = resolve(table, starts, a)
            if (sid, hit) not in rows:
                func, via, width, kind = sites[sid]
                delta = '%+d' % (a - by_name[via][0]) if via in by_name else '?'
                rows[sid, hit] = (func, via, delta, hit if not off else '%s+0x%x' % (hit, off), width, kind, name)
    report = out / 'xsym_report.tsv'
    with report.open('w') as f:
        f.write('site\tfunction\tvia\toffset\thit\twidth\tkind\tfirst_case\n')
        for (sid, _), row in sorted(rows.items(), key=lambda r: (r[1][0], int(r[0][0]), r[0][1])):
            f.write(sid + '\t' + '\t'.join(row) + '\n')
    # Labels joined by an access must become one C object (struct or array): union-find groups.
    parent = {}

    def find(x):
        while parent.setdefault(x, x) != x:
            parent[x] = parent[parent[x]]
            x = parent[x]
        return x
    for r in rows.values():
        parent[find(r[1])] = find(r[3].split('+')[0])
    groups = collections.defaultdict(lambda: (set(), set()))
    for r in rows.values():
        root = find(r[1])
        groups[root][0].update((r[1], r[3].split('+')[0]))
        groups[root][1].add(r[0])
    order = {t[2]: t[0] for t in table}
    with (out / 'xsym_groups.tsv').open('w') as f:
        f.write('labels\tfunctions\n')
        for labels, funcs in sorted(groups.values(), key=lambda g: min(order.get(l, 0) for l in g[0])):
            f.write(' '.join(sorted(labels, key=lambda l: order.get(l, 0))) + '\t' + ' '.join(sorted(funcs)) + '\n')
    funcs = {r[0] for r in rows.values()}
    print('xsym: %d checked sites, %d hit in %d functions, %d site/target pairs; %d label groups -> %s, %s'
          % (len(sites), len({sid for sid, _ in rows}), len(funcs), len(rows), len(groups), report, out / 'xsym_groups.tsv'))


if __name__ == '__main__':
    main()
