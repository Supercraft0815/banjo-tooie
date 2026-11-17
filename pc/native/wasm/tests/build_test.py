#!/usr/bin/env python3
"""Build discovery, staged builds and dependency-cache regressions, without a ROM."""
import contextlib
import io
import os
from pathlib import Path
import shutil
import subprocess
import sys
import tempfile
import unittest
from unittest.mock import patch

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
import build
import trace_tools


class BuildTest(unittest.TestCase):
    def test_disabled_passes_preserve_pipeline_order_and_remove_both_fixcalls(self):
        baseline = 'function(mem2reg),bt-fixcalls,bt-bigendian,bt-datagroup,bt-stackslots,internalize,bt-safepoints,default<O2>,bt-fixcalls'
        self.assertEqual(build.guest_pipeline('', False), baseline)
        self.assertEqual(build.guest_pipeline('bt-fixcalls, stackslots', True),
                         'function(mem2reg),bt-linker-symbols,bt-xsym,bt-bigendian,bt-datagroup,internalize,bt-safepoints,default<O2>')
        with self.assertRaisesRegex(ValueError, 'BT_PASS_OFF'):
            build.guest_pipeline('stackslot', False)

    def test_explicit_prefix_wins_over_path(self):
        with patch.dict(os.environ, {'BT_LLVM_BIN': '/custom llvm/bin', 'BT_WABT': '/custom wabt'}, clear=True), \
             patch.object(build.sys, 'platform', 'linux'), patch.object(build.shutil, 'which', return_value='/path/tool'):
            self.assertEqual(build.tool('clang'), '/custom llvm/bin/clang')
            self.assertEqual(build.tool('wasm2c'), '/custom wabt/bin/wasm2c')
        with patch.dict(os.environ, {}, clear=True), patch.object(build.shutil, 'which', return_value='/path/tool'):
            self.assertEqual(build.tool('opt'), '/path/tool')

    def test_sdl_prefix_and_pkg_config_quoting(self):
        with patch.dict(os.environ, {'BT_SDL3': '/SDL install'}, clear=True):
            cflags, libs = build.sdl_flags()
            self.assertIn('/SDL install/include', cflags)
            self.assertIn('-L/SDL install/lib', libs)
        with patch.dict(os.environ, {}, clear=True), patch.object(build.shutil, 'which', return_value='pkg-config'), \
             patch.object(build.subprocess, 'run', side_effect=[
                 subprocess.CompletedProcess([], 0, '-I"/SDL install/include"'),
                 subprocess.CompletedProcess([], 0, '-L"/SDL install/lib" -lSDL3')]):
            self.assertEqual(build.sdl_flags(), (['-I/SDL install/include'], ['-L/SDL install/lib', '-lSDL3']))

    def test_dependencies_with_spaces_and_drive_letter(self):
        with tempfile.TemporaryDirectory(prefix='bt build test ') as tmp:
            directory = Path(tmp)
            header, obj, dep = [directory / name for name in ('header file.h', 'unit.o', 'unit.d')]
            header.write_text('header')
            obj.write_text('object')
            dep.write_text('C:/output/unit.o: ' + str(header).replace(' ', '\\ ') + '\n')
            os.utime(header, (10, 10))
            os.utime(obj, (20, 20))
            self.assertTrue(build.up_to_date(obj, dep))
            os.utime(header, (30, 30))
            self.assertFalse(build.up_to_date(obj, dep))
            header.unlink()
            self.assertFalse(build.up_to_date(obj, dep))

    def test_host_needs_no_guest_tools_or_map(self):
        with tempfile.TemporaryDirectory() as tmp:
            out = Path(tmp)
            for name in ('gen/game.h', 'gen/game-impl.h', 'gen/o32.c', 'gen/trace_symbols.h',
                         'include/wasm-rt.h', 'runtime/wasm-rt-impl.c', 'runtime/wasm-rt-mem-impl.c'):
                path = out / name
                path.parent.mkdir(exist_ok=True)
                path.touch()
            with patch.object(build, 'OUT', out), patch.object(build, 'WASM2C_INC', out / 'include'), \
                 patch.object(build, 'WASM2C_RT', out / 'runtime'), \
                 patch.object(build.sys, 'argv', ['build.py', 'host']), \
                 patch.object(build.shutil, 'which', side_effect=lambda name: name if name in (build.CLANG, build.CXX) else None), \
                 patch.object(build, 'run', return_value=subprocess.CompletedProcess([], 0, 'clang version 19.1.0', '')), \
                 patch.object(build, 'build_guest') as guest, patch.object(build, 'build_host') as host:
                build.main()
                guest.assert_not_called()
                host.assert_called_once()

    def test_host_bundle_imports_without_guest_modules_or_symbol_tables(self):
        with tempfile.TemporaryDirectory() as tmp:
            here = Path(tmp) / 'pc/native/wasm'
            here.mkdir(parents=True)
            for name in ('build.py', 'trace_tools.py'):
                shutil.copy2(build.HERE / name, here / name)
            subprocess.run([sys.executable, '-I', str(here / 'build.py'), '--help'],
                           cwd=tmp, check=True, capture_output=True)

    def test_old_clang_fails_before_building(self):
        with patch.object(build.sys, 'argv', ['build.py', 'host']), \
             patch.object(build.shutil, 'which', return_value='/clang'), \
             patch.object(build, 'run', return_value=subprocess.CompletedProcess([], 0, 'clang version 18.1', '')), \
             patch.object(build, 'build_host') as host, contextlib.redirect_stderr(io.StringIO()) as error:
            with self.assertRaises(SystemExit):
                build.main()
            self.assertIn('clang >= 19', error.getvalue())
            host.assert_not_called()

    def test_host_trace_identity_works_with_only_gen(self):
        with tempfile.TemporaryDirectory() as tmp:
            out = Path(tmp)
            gen = out / 'gen'
            gen.mkdir()
            header = gen / 'trace_symbols.h'
            header.write_text('#define TRACE_MAP 0x1234\n#define BT_TRACE_BUILD "old"\n')
            source = gen / 'game_0.c'
            source.write_text('int guest;')
            first = trace_tools.trace_header(out, build.HERE, ['-O2'], from_gen=True)
            header.write_text(first)
            (gen / 'n_aspMain.textbin.bin').write_bytes(b'legacy unused audio input')
            self.assertEqual(first, trace_tools.trace_header(out, build.HERE, ['-O2'], from_gen=True))
            self.assertNotEqual(first, trace_tools.trace_header(out, build.HERE, ['-O0'], from_gen=True))
            source.write_text('int changed_guest;')
            self.assertNotEqual(first, trace_tools.trace_header(out, build.HERE, ['-O2'], from_gen=True))

    def test_only_debug_hosts_fingerprint_the_interpreter(self):
        with tempfile.TemporaryDirectory() as tmp:
            here = Path(tmp)
            (here / 'gen').mkdir()
            (here / 'gen/trace_symbols.h').write_text('#define TRACE_MAP 0x1234\n')
            (here / 'host').mkdir()
            (here / 'build.py').touch()
            rsp = here / 'host/rsp.c'
            rsp.write_text('int rsp;')
            debug = ['-DBT_AUDIO_DEBUG=1']
            release_id = trace_tools.trace_header(here, here, [], from_gen=True)
            debug_id = trace_tools.trace_header(here, here, debug, from_gen=True)
            rsp.write_text('int changed_rsp;')
            self.assertEqual(release_id, trace_tools.trace_header(here, here, [], from_gen=True))
            self.assertNotEqual(debug_id, trace_tools.trace_header(here, here, debug, from_gen=True))


if __name__ == '__main__':
    unittest.main()
