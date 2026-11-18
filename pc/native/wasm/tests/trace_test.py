#!/usr/bin/env python3
"""ROM-free trace snapshots, map resolution, comparator and failure tests."""
import contextlib
import copy
import io
import json
import os
from pathlib import Path
import subprocess
import sys
import tempfile
import unittest
from unittest.mock import patch

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE.parent))
import trace_tools
import build


class TraceTest(unittest.TestCase):
    def test_freeze_windows_runtime(self):
        with tempfile.TemporaryDirectory() as tmp:
            tree = Path(tmp)
            exe = tree / 'bt_game.exe'
            exe.write_bytes(b'program')
            (tree / 'SDL3.DLL').write_bytes(b'library')
            (tree / 'other.txt').write_text('unrelated')
            work = tree / 'run'
            work.mkdir()
            with patch.object(trace_tools, 'GAME_NAME', 'bt_game.exe'):
                copy = trace_tools.freeze_game(exe, work)
            self.assertEqual(copy.name, 'bt_game.exe')
            self.assertEqual(copy.read_bytes(), b'program')
            self.assertEqual((work / 'SDL3.DLL').read_bytes(), b'library')
            self.assertFalse((work / 'other.txt').exists())

    def test_guest_layout(self):
        # No generated overlay aliases or ROM assets are needed for these type checks.
        flags = list(build.GUEST_FLAGS)
        index = flags.index('-include')
        del flags[index:index + 2]
        subprocess.run([build.CLANG, *flags, '-std=c11', '-fsyntax-only', str(HERE / 'trace_layout.c')], check=True)

    def test_snapshots(self):
        with tempfile.TemporaryDirectory(prefix='bt-trace-test-') as tmp:
            out = Path(tmp)
            names = ['D_80135490', 'D_80136EE0', 'D_80132DC2', 'D_8011B990',
                     'D_8012C780', 'D_8012C78C', 'D_8012C770', 'widescreen_enabled']
            (out / 'game.map').write_text('\n'.join(f'{0x80001000 + i * 0x100:08x} 0 100 {name}'
                                                    for i, name in enumerate(names)))
            (out / 'game.wasm').write_bytes(b'fixture')
            header = trace_tools.trace_header(out, HERE.parent, ['fixture'])
            self.assertIn('#define TRACE_FLAGS_2 0x80001608u', header)
            with (out / 'game.map').open('a') as file:
                file.write('\n80001700 0 4 D_8012C770.1\n')
            split = trace_tools.trace_header(out, HERE.parent, ['fixture'])
            self.assertIn('#define TRACE_FLAGS_1 0x80001700u', split)
            (out / 'game.wasm').write_bytes(b'different build')
            self.assertNotEqual(split, trace_tools.trace_header(out, HERE.parent, ['fixture']))
            (out / 'trace_symbols.h').write_text(split)
            exe = out / 'trace'
            subprocess.run(['clang', '-std=c11', '-O2', '-Wall', '-Wextra', '-Werror',
                            '-I', tmp, str(HERE / 'trace.c'), '-o', str(exe)], check=True)
            rom = out / 'rom'; rom.write_bytes(b'fixture ROM')
            path = out / 'trace.jsonl'
            env = {**os.environ, 'BT_TRACE': str(path), 'BT_HEADLESS': '1', 'BT_VCLOCK': '1'}
            (out / 'bt_eeprom.bin').write_bytes(b'different default')
            (out / 'selected.eep').write_bytes(b'hello')
            env['BT_SAVE'] = str(out / 'selected.eep')
            subprocess.run([str(exe), str(rom)], cwd=tmp, env=env, check=True)
            rows = [json.loads(line) for line in path.read_text().splitlines()]
            self.assertEqual(len(rows), 4)
            self.assertEqual(rows[0]['eeprom'], 'a430d84680aabd0b')
            self.assertNotIn('BT_PRESS2', rows[0])
            secondary = out / 'two-pads.jsonl'
            subprocess.run([str(exe), str(rom)], cwd=tmp, check=True,
                           env={**env, 'BT_PRESS2': '0:0', 'BT_TRACE': str(secondary)})
            pads = [json.loads(line) for line in secondary.read_text().splitlines()]
            self.assertEqual(self.compare(pads, pads)[0], 0)
            with self.assertRaisesRegex(ValueError, 'BT_PRESS2'):
                self.compare(rows, pads)
            self.assertEqual(rows[1]['actors'], [])
            self.assertEqual(rows[1]['players'][0], {'present': 0})
            self.assertEqual(rows[2]['map'], 395)
            self.assertEqual(rows[2]['players'][0]['position'], [0x3F800000, 0, 0])
            self.assertEqual(rows[2]['players'][0]['status'], [0, 7, 0])
            self.assertEqual(rows[2]['actors'][0]['id'], 0x42)
            self.assertNotEqual(rows[1]['flags'][1], rows[2]['flags'][1])
            for key in ('state', 'actors', 'players', 'framebuffer'):
                self.assertEqual(rows[2][key], rows[3][key], key)
            self.assertNotEqual(rows[1]['framebuffer'], rows[2]['framebuffer'])
            self.assertEqual(self.compare(rows, rows)[0], 0)
            changed = copy.deepcopy(rows)
            changed[2]['players'][0]['position'][0] += 1
            code, message = self.compare(rows, changed)
            self.assertEqual(code, 1)
            self.assertIn('Retrace 2, players[0].position[0]', message)
            self.assertEqual(self.compare(rows, rows[:-1])[0], 1)
            for key in ('build', 'eeprom', 'BT_PRESS'):
                changed = copy.deepcopy(rows); changed[0][key] = 'different'
                with self.assertRaisesRegex(ValueError, key): self.compare(rows, changed)
            changed = copy.deepcopy(rows); changed[2]['retrace'] = 4
            with self.assertRaisesRegex(ValueError, 'out-of-order'): self.compare(rows, changed)
            with self.assertRaisesRegex(ValueError, 'no retraces'): self.compare(rows[:1], rows[:1])
            existing = subprocess.run([str(exe), str(rom)], cwd=tmp, env=env, capture_output=True)
            self.assertEqual(existing.returncode, 3)
            self.assertEqual(len(path.read_text().splitlines()), 4)  # Never overwrite a baseline.
            env['BT_TRACE'] = str(out / 'bad.jsonl')
            bad = subprocess.run([str(exe), str(rom), 'range'], cwd=tmp, env=env, capture_output=True)
            self.assertEqual(bad.returncode, 3)
            self.assertIn(b'invalid guest range', bad.stderr)
            env.pop('BT_VCLOCK')
            bad = subprocess.run([str(exe), str(rom)], cwd=tmp, env=env, capture_output=True)
            self.assertEqual(bad.returncode, 3)
            self.assertIn(b'requires BT_VCLOCK', bad.stderr)

    def test_invalid_files(self):
        with tempfile.TemporaryDirectory(prefix='bt-trace-invalid-') as tmp:
            file = Path(tmp) / 'bad.jsonl'
            for content in ('', '{}\n', '[]\n', '{truncated'):
                file.write_text(content)
                result = subprocess.run([sys.executable, str(HERE.parent / 'trace_tools.py'), str(file), str(file)],
                                        capture_output=True, text=True)
                self.assertEqual(result.returncode, 2)
                self.assertIn('Invalid trace:', result.stderr)
        with self.assertRaisesRegex(ValueError, 'incomplete retrace'):
            trace_tools.read_retrace('{"retrace":1}', 1)

    @staticmethod
    def compare(left, right):
        output = io.StringIO()
        with contextlib.redirect_stdout(output):
            code = trace_tools.compare(io.StringIO(''.join(json.dumps(row) + '\n' for row in left)),
                                       io.StringIO(''.join(json.dumps(row) + '\n' for row in right)))
        return code, output.getvalue()


if __name__ == '__main__':
    unittest.main()
