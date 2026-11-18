#!/usr/bin/env python3
"""Map sweep: warp into every map of include/maps.h (BT_WARP) and report traps, crashes, hangs.

    sweep.py OUTDIR [--map B8 ...] [--exit N] [--seconds S] [--jobs J] [--exe PATH]

Each map runs headless under the virtual clock in its own directory: load a save with all worlds
open (Spiral Mountain at 29 s), warp at 34 s, then S seconds with the stick pushed around and A/B
taps. Warping from the title screen instead leaves the attract mode running, which then changes
maps by itself. Result: OUTDIR/summary.json and one line per
failing map. A map that loads and runs is "ok"; that is no statement about how it looks.
"""
import argparse
import json
import os
import re
import shutil
import subprocess
import sys
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
WARP_AT = 34
# Crashes that are no port bugs: the map change itself reads a NULL section entry on the N64 too.
EXPECTED = {
    0xA0: 'not in the section table (gcsectionDll)', 0xF5: 'not in the section table',
    0x149: 'not in the section table', 0x184: 'not in the section table',
    0xD0: "Chuffy's cab needs a train position in the save; none set, the station lookup runs off its table",
}
sys.path.insert(0, str(Path(__file__).resolve().parent))
import save_editor  # noqa: E402
import trace_tools


def maps():
    text = (ROOT / 'include/maps.h').read_text()
    return {int(v, 16): name for name, v in re.findall(r'(MAP_\w+)\s*=\s*(0x[0-9A-Fa-f]+)', text)}


def press(start, seconds):
    # stick up/right/down/left for 2 s each, A at every even second, B at every fifth
    events, sticks = ['0:0'], ['50000000', '00500000', 'B0000000', '00B00000']
    for t in range(10, 23, 4):  # Start through the logos to the file select
        events.extend((f'{t}:1000', f'{t}.2:0'))
    for t in range(26, start, 2):  # A: pick the file, skip dialogs
        events.extend((f'{t}:8000', f'{t}.2:0'))
    for i in range(int(seconds * 2)):
        t, stick = start + 3 + i / 2, int(sticks[i // 4 % 4], 16)
        button = 0x8000 if i % 4 == 0 else 0x4000 if i % 10 == 5 else 0
        events.append(f'{t}:{stick | button:x}')
    return ','.join(events)


def where(exe, lines):
    """Guest functions of the fault, innermost first (atos resolves inlined frames; macOS only)."""
    slide = next((l.split()[-1] for l in lines if 'image slide' in l), None)
    frames = [l.split()[-1] for l in lines if 'guest fault' in l and ' pc ' in l]
    frames += [l.split()[2] for l in lines if re.match(r'\d+\s+bt_game\s+0x', l)]
    message = next((l for l in lines if 'unported' in l or 'memory:' in l), '')
    if not slide or not frames or not shutil.which('atos'):
        return message
    text = subprocess.run(['atos', '-i', '-o', str(exe), '-s', slide] + frames, capture_output=True, text=True).stdout
    names = [n for n in re.findall(r'^w2c_bt_(\w+)', text, re.M) if n != 'abort']
    return ' < '.join(dict.fromkeys(names[:4])) + (' | ' + message if message else '')


def run(exe, rom, out, map_id, exit_id, seconds):
    directory = out / f'{map_id:03X}'
    shutil.rmtree(directory, ignore_errors=True)
    directory.mkdir(parents=True)
    end = WARP_AT + seconds
    flags = [(flag, True) for flag in [*range(0x392, 0x39B), *save_editor.START_ABILITIES]]  # as corpus.py
    (directory / 'bt_eeprom.bin').write_bytes(save_editor.edit(bytes(2048), 0, flags, create=True))
    env = {k: v for k, v in os.environ.items() if not k.startswith('BT_')}
    env.update(BT_VCLOCK='1', BT_HEADLESS='1', BT_SAVE=str(directory / 'bt_eeprom.bin'), BT_WARP=f'{WARP_AT}:{map_id:X}:{exit_id}',
               BT_PRESS=press(WARP_AT, seconds), BT_EXIT_AFTER=str(end),
               BT_TRACE=str(directory / 'trace.jsonl'),
               BT_DUMP=str(directory / 'frame'), BT_DUMP_EVERY='60', BT_DUMP_FROM=str(end - 2.5))
    result = {'map': f'{map_id:X}', 'status': 'ok'}
    try:
        with (directory / 'run.log').open('w') as log:
            code = subprocess.run([str(exe), str(rom)], cwd=directory, env=env, stdout=log,
                                  stderr=log, timeout=600).returncode
    except subprocess.TimeoutExpired:
        code, result['status'] = None, 'hang'
    lines = (directory / 'run.log').read_text(errors='replace').splitlines()
    if code:
        result['status'] = 'trap' if any('unported' in l for l in lines) else 'crash'
        result['code'] = code
    trace = directory / 'trace.jsonl'
    last, image, changed, count = None, None, 0, 0
    if trace.exists():
        with trace.open() as stream:
            for count, line in enumerate(stream):
                found = re.search(r'"framebuffer":\{[^}]*\}', line)
                if found and found.group(0) != image:
                    image, changed = found.group(0), count
            try:
                last = json.loads(line)
            except ValueError:
                pass
        trace.unlink()
    if last:
        result['last_map'] = f'{last.get("map", 0):X}'
        result['seconds'] = round(last.get('ticks', 0) / 46875000, 1)
        if result['status'] == 'ok' and last.get('map') != map_id:
            result['status'] = 'other-map'
        elif result['status'] == 'ok' and count - changed > 300:
            result['status'] = 'static'  # the picture has not changed for 5 s: look at it
    if result['status'] != 'ok':
        result['log'] = [l for l in lines if 'warp to' not in l][-6:]
        result['where'] = where(exe, lines)
    if result['status'] == 'crash' and map_id in EXPECTED:
        result['status'], result['where'] = 'expected', EXPECTED[map_id]
    return result


def main():
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument('out', type=Path)
    parser.add_argument('--map', action='append', help='hex map id; default: all of maps.h')
    parser.add_argument('--exit', type=int, default=1)
    parser.add_argument('--seconds', type=int, default=25)
    parser.add_argument('--jobs', type=int, default=max(1, (os.cpu_count() or 2) - 2))
    parser.add_argument('--exe', type=Path, default=ROOT / 'build/ilp32' / trace_tools.GAME_NAME)
    parser.add_argument('--rom', type=Path, default=ROOT / 'baserom.us.z64')
    args = parser.parse_args()
    names = maps()
    ids = [int(m, 16) for m in args.map] if args.map else sorted(names)
    out = args.out.resolve()
    out.mkdir(parents=True, exist_ok=True)
    exe = trace_tools.freeze_game(args.exe, out)
    with ThreadPoolExecutor(args.jobs) as pool:
        results = list(pool.map(lambda m: run(exe, args.rom.resolve(), out, m, args.exit, args.seconds), ids))
    counts = {}
    for r in results:
        r['name'] = names.get(int(r['map'], 16), '?')
        counts[r['status']] = counts.get(r['status'], 0) + 1
        if r['status'] not in ('ok', 'other-map', 'expected', 'static'):
            print(f"{r['map']:>3} {r['name']:<40} {r['status']:<9} last map {r.get('last_map', '-')} "
                  f"at {r.get('seconds', '-')} s | {r.get('where', '')[:160]}")
    groups = {}
    for r in results:
        if r['status'] in ('crash', 'trap'):
            groups.setdefault(r.get('where', ''), []).append(r['map'])
    for key, members in sorted(groups.items(), key=lambda kv: -len(kv[1])):
        print(f'{len(members):3} {key[:150]}: {" ".join(members)}')
    (out / 'summary.json').write_text(json.dumps({'counts': counts, 'results': results}, indent=1))
    print('static:', ' '.join(r['map'] for r in results if r['status'] == 'static'))
    print(' '.join(f'{k}={v}' for k, v in sorted(counts.items())), f'-> {out / "summary.json"}')
    return 0 if set(counts) <= {'ok', 'other-map', 'expected', 'static'} else 1  # other-map: walked through a door


if __name__ == '__main__':
    sys.exit(main())
