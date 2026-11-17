#!/usr/bin/env python3
"""Repeat the Phase-0 scenarios in isolated save directories and verify their traces."""
import argparse
from concurrent.futures import ThreadPoolExecutor
import json
import os
from pathlib import Path
import re
import shutil
import subprocess
import sys

import save_editor
import trace_tools

HERE = Path(__file__).resolve().parent


def script():
    events = ['0:0']
    for t in range(10, 99, 4):
        events.extend((f'{t}:1000', f'{t}.2:0'))
    for t in range(100, 941, 2):
        events.extend((f'{t}:8000', f'{t}.2:0'))
    return ','.join(events)


# Hub maps of every world (and Isle o' Hags) in turn, 20 s each: stick circles, A and B.
WORLDS = [0xB8, 0xC7, 0xD6, 0x1A7, 0x112, 0x100, 0x127, 0x128, 0x136, 0x15D, 0x142, 0x14F]


def worlds_script():
    events, sticks = ['0:0'], ['50000000', '00500000', 'B0000000', '00B00000']
    events += [f'{t}:1000,{t}.2:0' for t in range(10, 23, 4)]  # Start through the logos to the file select
    events += [f'{t}:8000,{t}.2:0' for t in range(26, 34, 2)]  # A: pick the file, skip dialogs
    for i in range(2 * (20 * len(WORLDS) + 4)):
        button = 0x8000 if i % 4 == 0 else 0x4000 if i % 10 == 5 else 0
        events.append(f'{37 + i / 2}:{int(sticks[i // 4 % 4], 16) | button:x}')
    return ','.join(events)


def run_env(case):
    """Scripted input of a case: BT_PRESS, and BT_WARP for map changes on a timetable."""
    return {'BT_PRESS': case['press'], **({'BT_WARP': case['warp']} if case.get('warp') else {})}


CASES = {
    'intro': {'seconds': 45, 'press': '', 'expected_map': 395, 'flags': None},
    'new-game': {'seconds': 950, 'press': script(), 'expected_map': 175, 'flags': None},
    'edited-save': {'seconds': 180, 'press': script(), 'expected_map': 175, 'flags': list(range(0x392, 0x39B)) + save_editor.START_ABILITIES},
    'worlds': {'seconds': 36 + 20 * len(WORLDS), 'press': worlds_script(), 'expected_map': WORLDS[-1],
               'flags': list(range(0x392, 0x39B)) + save_editor.START_ABILITIES,
               'warp': ','.join(f'{36 + 20 * i}:{m:X}:1' for i, m in enumerate(WORLDS))},
}


def replay(exe, rom, directory, case):
    directory.mkdir()
    if case['flags'] is not None:
        image = save_editor.edit(bytes(2048), 0, [(flag, True) for flag in case['flags']], create=True)
        (directory / 'bt_eeprom.bin').write_bytes(image)
    env = {key: value for key, value in os.environ.items() if not key.startswith('BT_')}
    env.update(BT_VCLOCK='1', BT_HEADLESS='1', BT_EXIT_AFTER=str(case['seconds']),
               **run_env(case), BT_TRACE=str(directory / 'trace.jsonl'),
               BT_DUMP=str(directory / 'frame'), BT_DUMP_EVERY='1800')
    with (directory / 'run.log').open('w') as log:
        subprocess.run([str(exe), str(rom)], cwd=directory, env=env, stdout=log, stderr=log,
                       check=True, timeout=1800)
    maps, last = {}, None
    with (directory / 'trace.jsonl').open() as stream:
        header = trace_tools.read_trace(stream)
        for count, line in enumerate(stream, 1):
            last = trace_tools.read_retrace(line, count)
            key = str(last['map'])
            maps[key] = maps.get(key, 0) + 1
    if last is None or last['map'] != case['expected_map']:
        raise ValueError(f'{directory.name}: expected final map {case["expected_map"]}, got {last and last["map"]}')
    if abs(last['ticks'] / 46875000 - case['seconds']) > 0.1:
        raise ValueError(f'{directory.name}: run stopped before the requested game time')
    return {'build': header['build'], 'retraces': last['retrace'], 'maps': maps, 'last_map': last['map']}


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--exe', type=Path, default=HERE.parents[2] / 'build/ilp32/bt_game')
    parser.add_argument('--rom', type=Path, default=HERE.parents[2] / 'baserom.us.z64')
    parser.add_argument('--case', choices=CASES, action='append', help='defaults to all implemented cases')
    parser.add_argument('output', type=Path, help='new artifact directory; never overwrites previous evidence')
    args = parser.parse_args()
    output = args.output.resolve()
    try:
        output.mkdir()
        # A rebuild during a long corpus run must not change the binary between replays.
        exe = output / 'bt_game'
        shutil.copy2(args.exe.resolve(), exe)
        results = {}
        for name in args.case or CASES:
            case = CASES[name]
            a, b = output / (name + '-a'), output / (name + '-b')
            print(f'{name}: replaying twice ({case["seconds"]} seconds each)', flush=True)
            with ThreadPoolExecutor(2) as pool:
                runs = [pool.submit(replay, exe, args.rom.resolve(), directory, case) for directory in (a, b)]
                result, again = [run.result() for run in runs]
            if result != again:
                raise ValueError(f'{name}: replay summaries differ')
            with (a / 'trace.jsonl').open() as left, (b / 'trace.jsonl').open() as right:
                if trace_tools.compare(left, right):
                    raise ValueError(f'{name}: replay traces differ')
            images = sorted(a.glob('*.bmp'))
            if not images or [p.name for p in images] != [p.name for p in sorted(b.glob('*.bmp'))]:
                raise ValueError(f'{name}: missing frame dumps')
            if any(p.read_bytes() != (b / p.name).read_bytes() for p in images):
                raise ValueError(f'{name}: replay images differ')
            result['identical_frame_dumps'] = len(images)
            results[name] = result
        # A map appearing in a trace is not a completed boss, transformation or minigame test.
        known = dict((int(value, 16), name) for name, value in re.findall(
            r'\b(MAP_\w+)\s*=\s*(0x[0-9A-Fa-f]+)', (save_editor.ROOT / 'include/maps.h').read_text()))
        seen = {int(key) for row in results.values() for key in row['maps']}
        summary = {'format': 'bt-corpus-1', 'cases': results,
                   'unvisited_named_maps': [name for key, name in known.items() if key not in seen],
                   'acceptance': {'emulator_comparison': False, 'human_playthrough': False,
                                  'all_bosses': False, 'all_minigames': False,
                                  'all_transformations': False, 'multiplayer': False}}
        (output / 'summary.json').write_text(json.dumps(summary, indent=2) + '\n')
        print(f'PASS: {len(results)} scenarios; {len(summary["unvisited_named_maps"])} named maps still unvisited')
    except (OSError, ValueError, StopIteration, subprocess.SubprocessError) as error:
        parser.exit(2, f'Corpus failed: {error}\n')
    return 0


if __name__ == '__main__':
    sys.exit(main())
