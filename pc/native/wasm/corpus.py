#!/usr/bin/env python3
"""Repeat the Phase-0 scenarios in isolated save directories and verify their traces."""
import argparse
from concurrent.futures import ThreadPoolExecutor
import json
import os
from pathlib import Path
import struct
import subprocess
import sys

import save_editor
import sweep
import trace_tools
import corpus_worlds
import corpus_bosses
import corpus_mumbo
import corpus_rides
import corpus_solo
import corpus_multiplayer
import corpus_transformations

HERE = Path(__file__).resolve().parent


def script():
    events = ['0:0']
    for t in range(10, 99, 4):
        events.extend((f'{t}:1000', f'{t}.2:0'))
    for t in range(100, 941, 2):
        events.extend((f'{t}:8000', f'{t}.2:0'))
    return ','.join(events)


# Exercise each hub, then release the controls so its next warp can start.
WORLDS = [0xB8, 0xC7, 0xD6, 0x1A7, 0x112, 0x100, 0x127, 0x128, 0x136, 0x15D, 0x142, 0x14F]


WORLD_WARPS = [(36 + 36 * i, target) for i, target in enumerate(WORLDS)]


def worlds_script():
    events = [corpus_worlds.START_PRESS]
    sticks = (0x50000000, 0x00500000, 0xB0000000, 0x00B00000)
    for start, _ in WORLD_WARPS:
        for i in range(30):
            button = 0x8000 if i % 4 == 0 else 0x4000 if i % 10 == 5 else 0
            events.append(f'{start + 1 + i / 2:g}:{sticks[i // 4 % 4] | button:x}')
        events.append(f'{start + 16}:0')
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
    'worlds': {'seconds': WORLD_WARPS[-1][0] + 20, 'press': worlds_script(), 'expected_map': WORLDS[-1], 'expected_route': WORLDS,
               'flags': list(range(0x392, 0x39B)) + save_editor.START_ABILITIES,
               'warp': ','.join(f'{start}:{m:X}:1' for start, m in WORLD_WARPS)},
    **corpus_worlds.CASES,
    **corpus_bosses.CASES,
    **corpus_multiplayer.CASES,
    **corpus_transformations.CASES,
    **corpus_mumbo.CASES,
    **corpus_rides.CASES,
    **corpus_solo.CASES,
}


def prepare_save(directory, case):
    """Reset the isolated replay's EEPROM to the case's initial inventory and flags."""
    path = directory / 'bt_eeprom.bin'
    if case['flags'] is not None:
        image = save_editor.edit(bytes(2048), 0, [(flag, True) for flag in case['flags']],
                                 create=True, items=case.get('items', ()))
        path.write_bytes(image)
    else:
        path.unlink(missing_ok=True)
    return path


def record(exe, rom, directory, case, *, dump, timeout):
    directory.mkdir(parents=True)
    save = prepare_save(directory, case)
    env = {key: value for key, value in os.environ.items()
           if not key.startswith('BT_') or key in ('BT_AUDIO', 'BT_AUDIO_CHECK')}
    env.update(BT_VCLOCK='1', BT_HEADLESS='1', BT_EXIT_AFTER=str(case['seconds']),
               **run_env(case), BT_TRACE=str(directory / 'trace.jsonl'), BT_SAVE=str(save))
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
    encounter = case.get('expected_actor_state')
    saw_encounter = encounter is None
    route = iter(case.get('expected_route', ()))
    next_map = next(route, None)
    split = corpus_solo.SplitMovement(case['solo_slot']) if 'solo_slot' in case else None
    pending_spawns = dict(case.get('expected_spawns', {}))
    with (directory / 'trace.jsonl').open() as stream:
        header = trace_tools.read_trace(stream)
        for count, line in enumerate(stream, 1):
            last = trace_tools.read_retrace(line, count)
            key = str(last['map'])
            maps[key] = maps.get(key, 0) + 1
            if last['map'] == next_map:
                next_map = next(route, None)
            if split and last['map'] == case['expected_map']:
                split.observe(last)
            if pending_spawns and last['map'] == case['expected_map']:
                for actor in last['actors']:
                    expected = pending_spawns.pop(actor['id'], None)
                    if expected is not None:
                        position = struct.unpack('>3f', struct.pack('>3I', *actor['position']))
                        if position != expected:
                            raise ValueError(f'{directory.name}: actor {actor["id"]:#x} spawned at {position}, expected {expected}')
            if not saw_encounter and last['map'] == case['expected_map']:
                actor_id, state = encounter
                # Actor.unk70_10 occupies bits 10..15 of the word at +0x70.
                saw_encounter = any(actor['id'] == actor_id and (actor['health_flags'][5] >> 10 & 63) == state
                                    for actor in last['actors'])
    if last is None or last['map'] != case['expected_map']:
        raise ValueError(f'{directory.name}: expected final map {case["expected_map"]}, got {last and last["map"]}')
    if next_map is not None:
        raise ValueError(f'{directory.name}: missed route map {next_map:#x}')
    if split and not split.moved:
        raise ValueError(f'{directory.name}: player {split.active} never moved away from the parked partner')
    if not saw_encounter:
        raise ValueError(f'{directory.name}: actor {encounter[0]:#x} never reached state {encounter[1]}')
    if pending_spawns:
        raise ValueError(f'{directory.name}: missing actor spawns {list(map(hex, pending_spawns))}')
    players = case.get('expected_players', 0)
    if players and (len(last['players']) < players or not all(p['present'] for p in last['players'][:players])):
        raise ValueError(f'{directory.name}: expected {players} active players in the final scene')
    if 'expected_player_state' in case:
        slot = case.get('expected_player_slot', 0)
        player = last['players'][slot] if 0 <= slot < len(last['players']) else {}
        actual = player['status'][0] if player.get('present') else None
        if actual != case['expected_player_state']:
            raise ValueError(f'{directory.name}: expected player state {case["expected_player_state"]}, got {actual}')
    expected_flags = case.get('expected_permanent_flags_hash')
    if expected_flags and (len(last['flags']) < 2 or last['flags'][1] != expected_flags):
        raise ValueError(f'{directory.name}: unexpected permanent flags after the transformation')
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
