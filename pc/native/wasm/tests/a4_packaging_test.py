#!/usr/bin/env python3
import json
import os
from pathlib import Path
import subprocess
import sys
import tempfile
import unittest
import zipfile
from unittest.mock import patch

HERE = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(HERE))
import data_inventory
import corpus
import reference_manifest
import package


class A4MediaInventoryTest(unittest.TestCase):
    def test_compiled_display_lists_remain_visible_after_migration_from_assembly(self):
        ir = ['%union.Gfx = type { i64 }',
              '@list = global [130 x %union.Gfx] [%union.Gfx { i64 1 }, ...], align 8',
              '@pool = global [4096 x i8] zeroinitializer, align 4',
              '@small = constant [1024 x i8] c"...", align 1',
              '@other = global [2048 x i8] c"...", align 1']
        rows = data_inventory.compiled_large_labels(ir, {'list', 'pool', 'small'})
        self.assertEqual([(r['name'], r['bytes'], r['media_candidate']['kind']) for r in rows],
                         [('list', 1040, 'display-list-type')])

    def test_large_labels_are_sized_and_named_as_candidates(self):
        labels = {'gDisplayList': 0x1000, 'R_TextureCI8': 0x1500, 'opaque_blob': 0x2000}
        items = [(0x1000, 0x500, 'space', 0x500), (0x1500, 0xB00, 'space', 0xB00),
                 (0x2000, 0xB00, 'space', 0xB00)]
        with patch.object(data_inventory.data, 'parse_file', return_value=[('rodata', labels, items)]):
            result = data_inventory.scan([Path('sample.s')], set(), set())[0]
        by_name = {label['name']: label for label in result['labels']}
        self.assertEqual(by_name['gDisplayList']['bytes'], 0x500)
        self.assertEqual(by_name['gDisplayList']['media_candidate']['kind'], 'display-list-candidate')
        self.assertEqual(by_name['R_TextureCI8']['media_candidate']['kind'], 'texture-candidate')
        self.assertEqual(by_name['opaque_blob']['media_candidate']['kind'], 'unclassified-large')
        self.assertEqual(data_inventory.classify_label('D_80100000', 0x500, 'union.Gfx')['kind'],
                         'display-list-type')


class A4ReferenceDigestTest(unittest.TestCase):
    def test_digest_ignores_only_build_identity(self):
        header = {'format': 'bt-trace-1', 'clock': 'vclock-build-local', 'build': 'one',
                  'rom': 'romhash', 'eeprom': 'savehash', 'BT_PRESS': 'p', 'BT_SCALE': 's', 'BT_MUTE': 'm'}
        row = {'retrace': 1, 'ticks': 10, 'framebuffer': 'f', 'map': 2, 'players': [],
               'actors': [], 'flags': [], 'state': 'x'}
        with tempfile.TemporaryDirectory() as temp:
            first, second = Path(temp) / 'a.jsonl', Path(temp) / 'b.jsonl'
            first.write_text(json.dumps(header) + '\n' + json.dumps(row) + '\n')
            second.write_text(json.dumps(dict(header, build='two')) + '\n' + json.dumps(row) + '\n')
            self.assertEqual(reference_manifest.digest_trace(first), reference_manifest.digest_trace(second))
            altered = dict(row, map=3)
            second.write_text(json.dumps(dict(header, build='two')) + '\n' + json.dumps(altered) + '\n')
            self.assertNotEqual(reference_manifest.digest_trace(first), reference_manifest.digest_trace(second))

    def test_checked_manifest_is_complete_for_existing_local_set(self):
        manifest = HERE / 'reference_hashes.json'
        saved = json.loads(manifest.read_text())['cases']
        self.assertEqual(set(corpus.CASES), set(saved))
        refs = Path(os.environ.get('BT_REFERENCE_DIR', data_inventory.build.ROOT / 'build' / 'reference'))
        if not refs.is_dir():
            self.skipTest('local private references are not installed')
        actual = sorted(p.stem for p in refs.glob('*.jsonl'))
        self.assertEqual(actual, sorted(saved))


class A4PackageTest(unittest.TestCase):
    def test_linux_resolves_sdl_with_spaces_and_reports_missing_libraries(self):
        with tempfile.TemporaryDirectory(prefix='SDL build ') as tmp:
            root = Path(tmp)
            output = root / 'package'
            output.mkdir()
            sdl = root / 'libSDL3.so.0'
            sdl.write_bytes(b'SDL fixture')
            dependencies = f'{sdl.name} => {sdl} (0x1234)\nlibc.so.6 => /lib/libc.so.6 (0x2345)\n'
            with patch.object(subprocess, 'run', return_value=subprocess.CompletedProcess([], 0, dependencies)):
                package.copy_linux_dependencies(root / 'game', [root], output)
            self.assertEqual(list(output.iterdir()), [output / sdl.name])
            self.assertEqual((output / sdl.name).read_bytes(), sdl.read_bytes())
            with patch.object(subprocess, 'run', return_value=subprocess.CompletedProcess([], 0, 'libSDL3.so.0 => not found\n')):
                with self.assertRaisesRegex(ValueError, 'unresolved Linux runtime dependency'):
                    package.copy_linux_dependencies(root / 'game', [], output)

    def test_windows_package_contains_only_host_and_runtime(self):
        with tempfile.TemporaryDirectory() as temp:
            root = Path(temp)
            exe, runtime = root / 'bt_game.exe', root / 'runtime'
            game_map, native_map = root / 'game.map', root / 'bt_game.native.map'
            runtime.mkdir()
            exe.write_bytes(b'PE host fixture')
            game_map.write_text('guest map fixture\n')
            native_map.write_text('native map fixture\n')
            (runtime / 'SDL3.dll').write_bytes(b'SDL runtime')
            (runtime / 'libwinpthread-1.dll').write_bytes(b'pthread runtime')
            (runtime / 'baserom.us.z64').write_bytes(b'must not be packaged')
            def imports(binary, objdump):
                return ['SDL3.dll', 'libwinpthread-1.dll', 'dbghelp.dll'] if Path(binary).name == exe.name else []
            with patch.object(package, 'pe_imports', side_effect=imports):
                archive = package.package('windows', exe, root / 'game.zip', [runtime], objdump='fake-objdump',
                                          game_map=game_map, native_map=native_map)
            with zipfile.ZipFile(archive) as zf:
                names = set(zf.namelist())
                self.assertEqual(names, {'BanjoTooie/BanjoTooie.exe', 'BanjoTooie/SDL3.dll',
                                         'BanjoTooie/libwinpthread-1.dll', 'BanjoTooie/game.map',
                                         'BanjoTooie/bt_game.native.map', 'BanjoTooie/PACKAGE-MANIFEST.json'})
                self.assertEqual(zf.read('BanjoTooie/game.map'), game_map.read_bytes())
                self.assertEqual(zf.read('BanjoTooie/bt_game.native.map'), native_map.read_bytes())
                self.assertFalse(any('baserom' in name.lower() for name in names))


if __name__ == '__main__':
    unittest.main()
