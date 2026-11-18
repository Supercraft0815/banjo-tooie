#!/usr/bin/env python3
"""Repeat the Phase-0 scenarios in isolated save directories and verify their traces."""
import argparse
from concurrent.futures import ThreadPoolExecutor
import json
import os
from pathlib import Path
import subprocess
import sys

import save_editor
import sweep
import trace_tools
import corpus_worlds
import corpus_bosses
import corpus_multiplayer

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
    """Return the exact scripted ports and optional map warp used by corpus.record."""
    env = {'BT_PRESS': case['press']}
    for port in range(2, 5):
        script = case.get(f'press{port}')
        if script is not None:
            env[f'BT_PRESS{port}'] = script
    if case.get('warp'):
        env['BT_WARP'] = case['warp']
    return env


CASES = {
    'intro': {'seconds': 45, 'press': '', 'expected_map': 395, 'flags': None},
    'new-game': {'seconds': 950, 'press': script(), 'expected_map': 175, 'flags': None},
    'edited-save': {'seconds': 180, 'press': script(), 'expected_map': 175, 'flags': list(range(0x392, 0x39B)) + save_editor.START_ABILITIES},
    'worlds': {'seconds': 36 + 20 * len(WORLDS), 'press': worlds_script(), 'expected_map': WORLDS[-1],
               'flags': list(range(0x392, 0x39B)) + save_editor.START_ABILITIES,
               'warp': ','.join(f'{36 + 20 * i}:{m:X}:1' for i, m in enumerate(WORLDS))},
    **corpus_worlds.CASES,
    **corpus_bosses.CASES,
    **corpus_multiplayer.CASES,
}


def record(exe, rom, directory, case, *, dump, timeout):
    directory.mkdir(parents=True)
    if case['flags'] is not None:
        image = save_editor.edit(bytes(2048), 0, [(flag, True) for flag in case['flags']], create=True)
        (directory / 'bt_eeprom.bin').write_bytes(image)
    env = {key: value for key, value in os.environ.items()
           if not key.startswith('BT_') or key in ('BT_AUDIO', 'BT_AUDIO_CHECK')}
    env.update(BT_VCLOCK='1', BT_HEADLESS='1', BT_EXIT_AFTER=str(case['seconds']),
               **run_env(case), BT_TRACE=str(directory / 'trace.jsonl'), BT_SAVE=str(directory / 'bt_eeprom.bin'))
    if dump:
        env.update(BT_DUMP=str(directory / 'frame'), BT_DUMP_EVERY=str(case.get('dump_every', 1800)))
    with (directory / 'run.log').open('w') as log:
        return subprocess.run([str(exe), str(rom)], cwd=directory, env=env, stdout=log, stderr=log,
                              timeout=timeout).returncode


def replay(exe, rom, directory, case):
    code = record(exe, rom, directory, case, dump=True, timeout=1800)
    if code:
        raise ValueError(f'{directory.name}: exit {code}, see {directory / "run.log"}')
    return trace_summary(directory, case)


def trace_summary(directory, case):
    maps, last = {}, None
    with (directory / 'trace.jsonl').open() as stream:
        header = trace_tools.read_trace(stream)
        for count, line in enumerate(stream, 1):
            last = trace_tools.read_retrace(line, count)
            key = str(last['map'])
            maps[key] = maps.get(key, 0) + 1
    if last is None or last['map'] != case['expected_map']:
        raise ValueError(f'{directory.name}: expected final map {case["expected_map"]}, got {last and last["map"]}')
    players = case.get('expected_players', 0)
    if players and (len(last['players']) < players or not all(p['present'] for p in last['players'][:players])):
        raise ValueError(f'{directory.name}: expected {players} active players in the final scene')
    if abs(last['ticks'] / 46875000 - case['seconds']) > 0.1:
        raise ValueError(f'{directory.name}: run stopped before the requested game time')
    return {'build': header['build'], 'retraces': last['retrace'], 'maps': maps, 'last_map': last['map']}


def missing_maps(results, sweep_results=()):
    known = sweep.maps()
    seen = {int(key) for row in results.values() for key in row['maps']}
    probes = {int(row['map'], 16): row for row in sweep_results}
    unvisited = {}
    for key, name in known.items():
        if key in seen:
            continue
        probe = probes.get(key, {})
        targets = [case for case, route in CASES.items() if route['expected_map'] == key]
        if targets:
            reason = 'Available replay outside this selection: ' + ', '.join(targets)
        elif key in sweep.EXPECTED:
            reason = sweep.EXPECTED[key]
        elif probe.get('status') == 'other-map':
            reason = f"Warp probe finished on map 0x{probe['last_map']}. No reviewed replay stops on this map."
        elif probe.get('status') == 'static':
            reason = 'Warp probe reached the map, but its final picture stayed still for at least five seconds.'
        elif probe.get('status') == 'ok':
            reason = 'A warp probe reached the destination. No gameplay replay there has passed repeat and image checks.'
        elif probe:
            reason = 'Warp probe status: ' + probe['status']
        elif '_CS_' in name or name.endswith('_STILL'):
            reason = 'No reviewed replay triggers this scripted scene.'
        elif 'WUMBA' in name or 'MUMBO' in name:
            reason = 'No reviewed replay enters this hut with the interaction and game state required for its scene.'
        else:
            reason = 'No reviewed replay visits this location in the selected cases.'
        unvisited[name] = reason
    return unvisited


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--exe', type=Path, default=HERE.parents[2] / 'build/ilp32' / trace_tools.GAME_NAME)
    parser.add_argument('--rom', type=Path, default=HERE.parents[2] / 'baserom.us.z64')
    parser.add_argument('--sweep-summary', type=Path, help='add per-map warp observations from sweep.py summary.json')
    parser.add_argument('--case', choices=CASES, action='append', help='defaults to all implemented cases')
    parser.add_argument('output', type=Path, help='new artifact directory; never overwrites previous evidence')
    args = parser.parse_args()
    output = args.output.resolve()
    try:
        output.mkdir()
        # A rebuild during a long corpus run must not change the binary between replays.
        exe = trace_tools.freeze_game(args.exe, output)
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
        probes = json.loads(args.sweep_summary.read_text())['results'] if args.sweep_summary else ()
        missing = missing_maps(results, probes)
        summary = {'format': 'bt-corpus-1', 'cases': results,
                   'unvisited_named_maps': list(missing), 'unvisited_map_reasons': missing,
                   'acceptance': {'emulator_comparison': False, 'human_playthrough': False,
                                  'all_bosses': False, 'all_minigames': False,
                                  'all_transformations': False, 'multiplayer': corpus_multiplayer.CASES.keys() <= results.keys()}}
        (output / 'summary.json').write_text(json.dumps(summary, indent=2) + '\n')
        for name, reason in missing.items():
            print(f'{name}: {reason}')
        print(f'PASS: {len(results)} scenarios; {len(summary["unvisited_named_maps"])} named maps still unvisited')
    except (OSError, ValueError, StopIteration, subprocess.SubprocessError) as error:
        parser.exit(2, f'Corpus failed: {error}\n')
    return 0


if __name__ == '__main__':
    sys.exit(main())
