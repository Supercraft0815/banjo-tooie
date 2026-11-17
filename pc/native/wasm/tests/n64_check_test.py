#!/usr/bin/env python3
"""The N64 gate must reject code/ROM changes and failed comparison tools."""
import contextlib
import io
from pathlib import Path
import subprocess
import sys
import tempfile
import unittest
from unittest.mock import patch

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
import offsets
import n64_objdiff


class N64CheckTest(unittest.TestCase):
    def check_result(self, rom_ok, differences):
        with tempfile.TemporaryDirectory() as tmp:
            tree = Path(tmp) / 'tree'
            (tree / 'build.base').mkdir(parents=True)
            log = Path(tmp) / 'tree.log'
            results = [subprocess.CompletedProcess([], 0, 'src/example.c\n'),
                       subprocess.CompletedProcess([], 0, differences)]
            with patch.object(sys, 'argv', ['offsets.py', 'check', str(tree)]), \
                 patch.object(offsets, 'sync'), \
                 patch.object(offsets, 'docker_make', return_value=(rom_ok, log)), \
                 patch.object(offsets.subprocess, 'run', side_effect=results) as run, \
                 contextlib.redirect_stdout(io.StringIO()):
                result = offsets.main()
            self.assertTrue(run.call_args.kwargs['check'])
            self.assertIn('--linked', run.call_args.args[0])
            self.assertEqual(log.with_suffix('.objdiff').read_text(), differences)
            return result

    def test_data_ownership_changes_require_identical_rom(self):
        self.assertEqual(self.check_result(True, 'src/example.c:<data>\n'), 0)
        self.assertEqual(self.check_result(False, 'src/example.c:<data>\n'), 1)

    def test_changed_or_missing_function_fails_even_with_matching_rom(self):
        self.assertEqual(self.check_result(True, 'src/example.c:<data>\nsrc/example.c:func\n'), 1)

    def test_unchanged_objects_still_require_matching_rom(self):
        self.assertEqual(self.check_result(True, ''), 0)
        self.assertEqual(self.check_result(False, ''), 1)

    def test_failed_comparison_is_not_an_empty_diff(self):
        with tempfile.TemporaryDirectory() as tmp:
            tree = Path(tmp)
            (tree / 'build.base').mkdir()
            with patch.object(sys, 'argv', ['offsets.py', 'check', str(tree)]), \
                 patch.object(offsets, 'sync'), \
                 patch.object(offsets, 'docker_make', return_value=(True, tree / 'check.log')), \
                 patch.object(offsets.subprocess, 'run', side_effect=[
                     subprocess.CompletedProcess([], 0, 'src/example.c\n'),
                     subprocess.CalledProcessError(1, ['n64_objdiff.py'])]):
                with self.assertRaises(subprocess.CalledProcessError):
                    offsets.main()

    def test_linked_bytes_ignore_only_annotations(self):
        text = '@@@ func\n80800624 <func>:\n80800624: 27bdffe8 \taddiu sp,sp,-24\n'
        with patch.object(n64_objdiff.subprocess, 'run', return_value=subprocess.CompletedProcess([], 0, text)):
            self.assertEqual(n64_objdiff.linked_dump('/tree', 'build', {'func'}),
                             {'func': [('80800624', '27bdffe8')]})

    def test_linked_mode_preserves_missing_functions_and_changed_bytes(self):
        old = {('f.c', name): ['old'] for name in ('same', 'changed', 'removed', 'absent')}
        new = {('f.c', name): ['new'] for name in ('same', 'changed', 'added', 'absent')}
        for argv in (['diff', '/tree', 'old', 'new', 'f.c'],
                     ['diff', '/tree', 'old', 'new', '--linked', 'f.c']):
            with patch.object(sys, 'argv', argv), \
                 patch.object(n64_objdiff, 'dump', side_effect=[old, new]), \
                 patch.object(n64_objdiff, 'linked_dump', side_effect=[
                     {'same': [('1000', '00000000')], 'changed': [('1004', '00000001')]},
                     {'same': [('1000', '00000000')], 'changed': [('1004', '00000002')]}]), \
                 contextlib.redirect_stdout(io.StringIO()) as output:
                n64_objdiff.main()
            names = set(output.getvalue().splitlines())
            self.assertEqual(names, {'f.c:changed', 'f.c:removed', 'f.c:added', 'f.c:absent'} |
                             ({'f.c:same'} if '--linked' not in argv else set()))


if __name__ == '__main__':
    unittest.main()
