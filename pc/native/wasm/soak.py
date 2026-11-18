#!/usr/bin/env python3
"""Soak run: one process warps through every loadable map in turn (BT_WARP timetable), to find heap
corruption, leaks and crashes that only build up over many map changes.

    soak.py OUTDIR [--seconds-per-map 15] [--rounds 1] [--exe PATH]

Cutscene (_CS_) and still maps are left out: without their script they stop swapping buffers, and
BT_WARP is polled per swap. By default it runs headless with the virtual clock. --wall-seconds uses
BT_SPEED=1 and real wall time, distributing all eligible map warps and compact input events over the
requested duration. RSS samples are flushed every 10 seconds to OUTDIR/rss_samples.jsonl and
summarized in OUTDIR/summary.json. For arena checks, use a diagnostic build with BT_HEAPCHECK=1 and
an isolated BT_OUT directory.
"""
import argparse
import json
import os
import subprocess
import sys
import time
from datetime import datetime, timezone
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import save_editor  # noqa: E402
import sweep  # noqa: E402
import trace_tools  # noqa: E402


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('out', type=Path)
    ap.add_argument('--seconds-per-map', type=int, default=15)
    ap.add_argument('--rounds', type=int, default=1)
    ap.add_argument('--wall-seconds', type=int, help='run at BT_SPEED=1 for this many real seconds (no virtual clock)')
    ap.add_argument('--exe', type=Path, default=sweep.ROOT / 'build/ilp32' / trace_tools.GAME_NAME)
    ap.add_argument('--rom', type=Path, default=sweep.ROOT / 'baserom.us.z64')
    args = ap.parse_args()
    if args.rounds < 1 or args.seconds_per_map < 1 or (args.wall_seconds is not None and args.wall_seconds < 1):
        ap.error('rounds and durations must be positive')
    # Cutscene and still maps stop swapping buffers without their script, and the warp is polled per swap.
    names = sweep.maps()
    ids = [m for m in sorted(names) if m not in sweep.EXPECTED and '_CS_' not in names[m] and not names[m].endswith('_STILL')]
    ids *= args.rounds
    per, start = args.seconds_per_map, sweep.WARP_AT
    if not ids:
        ap.error('no eligible maps')
    if args.wall_seconds:
        available = args.wall_seconds - start - 5
        if available < per * (len(ids) - 1):
            ap.error('wall duration is too short for the requested map count and spacing')
        if len(ids) > 1:
            per = available // (len(ids) - 1)
    seconds = args.wall_seconds if args.wall_seconds else start + len(ids) * per + 5
    out = args.out.resolve()
    out.mkdir(parents=True)
    exe = trace_tools.freeze_game(args.exe, out)
    flags = [(flag, True) for flag in [*range(0x392, 0x39B), *save_editor.START_ABILITIES]]
    (out / 'bt_eeprom.bin').write_bytes(save_editor.edit(bytes(2048), 0, flags, create=True))
    env = {k: v for k, v in os.environ.items() if not k.startswith('BT_')}
    if args.wall_seconds:
        # Keep both event streams bounded by ARG_MAX while continuing to exercise controls
        # and every eligible map throughout an eight-hour wall-clock run.
        sticks = (0x50000000, 0x00500000, 0xB0000000, 0x00B00000)
        events = ['0:0']
        for t in range(10, 23, 4):
            events.extend((f'{t}:1000', f'{t}.2:0'))
        for t in range(26, start, 2):
            events.extend((f'{t}:8000', f'{t}.2:0'))
        for i, t in enumerate(range(start, seconds, 10)):
            button = 0x8000 if i % 4 == 0 else 0x4000 if i % 10 == 5 else 0
            events.append(f'{t}:{sticks[i // 4 % len(sticks)] | button:x}')
        press = ','.join(events)
        if len(events) > 1 << 16:
            ap.error(f'BT_PRESS has {len(events)} entries; host parser holds at most {1 << 16}')
    else:
        press = sweep.press(start, seconds - start)
    warp = ','.join(f'{start + i * per}:{m:X}:1' for i, m in enumerate(ids))
    env.update(BT_HEADLESS='1', BT_MUTE='1', BT_SPEED='1', BT_EXIT_AFTER=str(seconds),
               BT_SAVE=str((out / 'bt_eeprom.bin').resolve()), BT_WARP=warp, BT_PRESS=press)
    sample_path = out / 'rss_samples.jsonl'
    try:
        arg_max = int(os.sysconf('SC_ARG_MAX'))
    except (ValueError, OSError):
        ap.error('cannot determine the platform argument/environment limit')
    argv = [str(exe), str(args.rom.resolve())]
    argv_bytes = sum(len(value.encode()) + 1 for value in argv)
    launch_env_bytes = sum(len(k.encode()) + len(v.encode()) + 2 for k, v in env.items())
    safety_margin = 8192
    if argv_bytes + launch_env_bytes > arg_max - safety_margin:
        ap.error(f'argv+environment is {argv_bytes + launch_env_bytes} bytes; ARG_MAX={arg_max} with {safety_margin} bytes reserved')
    input_config = {'BT_PRESS_bytes': len(press.encode()), 'BT_PRESS_events': len(events) - 1 if args.wall_seconds else None,
                    'BT_WARP_bytes': len(warp.encode()), 'argv_bytes': argv_bytes, 'launch_env_bytes': launch_env_bytes,
                    'arg_max_bytes': arg_max, 'parser_event_limit': 1 << 16}
    print(json.dumps({'mode': 'wall-clock' if args.wall_seconds else 'virtual', **input_config,
                      'maps': len(ids), 'seconds_per_map': per, 'duration_seconds': seconds}, indent=1), flush=True)
    if not args.wall_seconds:
        env['BT_VCLOCK'] = '1'
    monotonic_start, rss = time.monotonic(), []
    start_utc = datetime.now(timezone.utc).isoformat()
    with sample_path.open('w') as samples, (out / 'run.log').open('w') as log:
        p = subprocess.Popen([str(exe), str(args.rom.resolve())], cwd=out, env=env, stdout=log, stderr=log)
        print(json.dumps({'started_utc': start_utc, 'pid': p.pid, 'exe': str(exe), **input_config}), flush=True)
        try:
            p.wait(timeout=5)  # first RSS sample after SDL/game startup, not during exec handoff
        except subprocess.TimeoutExpired:
            pass
        while p.poll() is None:
            r = subprocess.run(['ps', '-o', 'rss=', '-p', str(p.pid)], capture_output=True, text=True).stdout.strip()
            if r:
                sample = {'elapsed_seconds': round(time.monotonic() - monotonic_start),
                          'utc': datetime.now(timezone.utc).isoformat(), 'pid': p.pid, 'rss_mb': int(r) // 1024}
                rss.append(sample)
                samples.write(json.dumps(sample) + '\n')
                samples.flush()
            try:
                p.wait(timeout=10)
            except subprocess.TimeoutExpired:
                pass
    ended_utc = datetime.now(timezone.utc).isoformat()
    wall_duration = time.monotonic() - monotonic_start
    elapsed = round(wall_duration)
    lines = (out / 'run.log').read_text(errors='replace').splitlines()
    warps = [l for l in lines if 'warp to' in l]
    diagnostics = [l for l in lines if any(marker in l.lower() for marker in
                   ('addresssanitizer', 'undefinedbehaviorsanitizer', 'runtime error:', 'heap check failed',
                    'leaksanitizer', 'heap corruption', 'heap broken at', 'free list broken at'))]
    after_start = min(rss, key=lambda r: abs(r['elapsed_seconds'] - 300)) if rss else None
    summary = {'exit': p.returncode, 'maps': len(ids), 'seconds_per_map': per, 'warps_done': len(warps), 'last_warp': warps[-1] if warps else None,
               'game_seconds': seconds, 'wall_seconds': round(wall_duration, 3), 'started_utc': start_utc, 'ended_utc': ended_utc,
               **input_config,
               'rss_samples_file': str(sample_path),
               'rss_mb': {'start_sample': rss[0]['rss_mb'] if rss else None,
                          'after_start_phase_approx_300s': after_start['rss_mb'] if after_start else None,
                          'peak_sampled': max((r['rss_mb'] for r in rss), default=None),
                          'end_sample': rss[-1]['rss_mb'] if rss else None,
                          'last_sample_age_seconds': elapsed - rss[-1]['elapsed_seconds'] if rss else None},
               'diagnostics': diagnostics,
               'log_tail': [l for l in lines if 'warp to' not in l][-8:]}
    (out / 'summary.json').write_text(json.dumps(summary, indent=1) + '\n')
    print(json.dumps({k: v for k, v in summary.items() if k != 'rss_samples'}, indent=1))
    wall_ok = not args.wall_seconds or (wall_duration >= args.wall_seconds and bool(rss))
    return 0 if p.returncode == 0 and len(warps) == len(ids) and not diagnostics and wall_ok else 1


if __name__ == '__main__':
    sys.exit(main())
