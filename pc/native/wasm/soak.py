#!/usr/bin/env python3
"""Soak run: one process warps through every loadable map in turn (BT_WARP timetable), to find heap
corruption, leaks and crashes that only build up over many map changes.

    soak.py OUTDIR [--seconds-per-map 15] [--rounds 1] [--exe PATH]

Cutscene (_CS_) and still maps are left out: without their script they stop swapping buffers, and
BT_WARP is polled per swap. Headless under the virtual clock, with the sweep's save (all worlds open) and its stick/A/B script.
Records the process's resident memory every 10 s of wall time into OUTDIR/summary.json. For arena
checks on every alloc/free use a diagnostic build: BT_HEAPCHECK=1 BT_OUT=build/ilp32-heap build.py.
"""
import argparse
import json
import os
import shutil
import subprocess
import sys
import time
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import save_editor  # noqa: E402
import sweep  # noqa: E402


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('out', type=Path)
    ap.add_argument('--seconds-per-map', type=int, default=15)
    ap.add_argument('--rounds', type=int, default=1)
    ap.add_argument('--exe', type=Path, default=sweep.ROOT / 'build/ilp32/bt_game')
    ap.add_argument('--rom', type=Path, default=sweep.ROOT / 'baserom.us.z64')
    args = ap.parse_args()
    # Cutscene and still maps stop swapping buffers without their script, and the warp is polled per swap.
    names = sweep.maps()
    ids = [m for m in sorted(names) if m not in sweep.EXPECTED and '_CS_' not in names[m] and not names[m].endswith('_STILL')]
    ids *= args.rounds
    per, start = args.seconds_per_map, sweep.WARP_AT
    seconds = start + len(ids) * per + 5
    out = args.out.resolve()
    out.mkdir(parents=True)
    exe = out / 'bt_game'  # frozen copy
    shutil.copy2(args.exe, exe)
    flags = [(flag, True) for flag in [*range(0x392, 0x39B), *save_editor.START_ABILITIES]]
    (out / 'bt_eeprom.bin').write_bytes(save_editor.edit(bytes(2048), 0, flags, create=True))
    env = {k: v for k, v in os.environ.items() if not k.startswith('BT_')}
    env.update(BT_VCLOCK='1', BT_HEADLESS='1', BT_MUTE='1', BT_EXIT_AFTER=str(seconds),
               BT_WARP=','.join(f'{start + i * per}:{m:X}:1' for i, m in enumerate(ids)),
               BT_PRESS=sweep.press(start, seconds - start))
    began, rss = time.time(), []
    with (out / 'run.log').open('w') as log:
        p = subprocess.Popen([str(exe), str(args.rom.resolve())], cwd=out, env=env, stdout=log, stderr=log)
        while p.poll() is None:
            r = subprocess.run(['ps', '-o', 'rss=', '-p', str(p.pid)], capture_output=True, text=True).stdout.strip()
            if r:
                rss.append((round(time.time() - began), int(r) // 1024))
            try:
                p.wait(timeout=10)
            except subprocess.TimeoutExpired:
                pass
    lines = (out / 'run.log').read_text(errors='replace').splitlines()
    warps = [l for l in lines if 'warp to' in l]
    summary = {'exit': p.returncode, 'maps': len(ids), 'warps_done': len(warps), 'last_warp': warps[-1] if warps else None,
               'game_seconds': seconds, 'wall_seconds': round(time.time() - began),
               'rss_mb': {'first': rss[0][1] if rss else None, 'max': max(r for _, r in rss) if rss else None,
                          'last': rss[-1][1] if rss else None}, 'rss_samples': rss,
               'log_tail': [l for l in lines if 'warp to' not in l][-8:]}
    (out / 'summary.json').write_text(json.dumps(summary, indent=1) + '\n')
    print(json.dumps({k: v for k, v in summary.items() if k != 'rss_samples'}, indent=1))
    return 0 if p.returncode == 0 and len(warps) == len(ids) else 1


if __name__ == '__main__':
    sys.exit(main())
