"""Exercise the real helper against tiny CLI fixtures, without compilers or models."""
from pathlib import Path
import subprocess
import sys
import tempfile
import threading
import unittest
from types import SimpleNamespace
from unittest.mock import patch

import test_acceleration as acceleration
from test_harness import CANDIDATE, SOURCE
from decomp_harness.patterns import trial_key
from decomp_harness.common import HarnessError

from decomp_harness.local_tools import run_permuter


class PermuterTests(unittest.TestCase):
    def test_stack_only_mismatch_is_searched_and_partial_timeout_result_is_kept(self):
        for search_exit in (0, 124):
            with self.subTest(search_exit=search_exit):
                self.run_cli_case(search_exit=search_exit)

    def test_import_error_restores_source_and_removes_temporary_files(self):
        self.run_cli_case(import_exit=1)

    def test_import_syntax_error_with_zero_exit_is_not_a_search(self):
        self.run_cli_case(import_message='Syntax error in base.c at end of input')

    def test_search_failure_does_not_return_partial_candidates(self):
        self.run_cli_case(search_exit=1)
        self.run_cli_case(search_message='Traceback (most recent call last):')

    def test_timeout_before_base_compile_is_not_a_completed_search(self):
        self.run_cli_case(search_exit=124, base_compiled=False)

    def test_timeout_after_base_compile_but_before_iteration_is_retryable(self):
        self.run_cli_case(search_exit=124, searched=False)

    def run_cli_case(self, import_exit=0, search_exit=0, import_message='',
                     search_message='', base_compiled=True, searched=True):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            tool = root/'tools/decomp-permuter'
            tool.mkdir(parents=True)
            source = root/'source.c'
            source.write_bytes(b'original source')
            tool.joinpath('import.py').write_text(
                'from pathlib import Path\nimport sys\n'
                'assert Path(sys.argv[1]).read_bytes() == b"candidate source"\n'
                f'print({import_message!r})\n'
                f'sys.exit({import_exit}) if {import_exit} else None\n'
                'Path("nonmatchings/target").mkdir(parents=True)\n')
            tool.joinpath('permuter.py').write_text(
                'from pathlib import Path\nimport sys\n'
                '# Stack offsets alone differ: default scoring stops without output.\n'
                'if "--stack-diffs" not in sys.argv:\n'
                '    print("[target] base score = 0")\n'
                '    sys.exit(0)\n'
                f'print("[target] base score = 8") if {base_compiled!r} else None\n'
                f'print({search_message!r})\n'
                f'print("iteration 1, 0 errors, score = 0") if {searched!r} else None\n'
                'result = Path(sys.argv[1])/"output-0-1"\n'
                'result.mkdir()\n'
                'result.joinpath("source.c").write_text("void target(void) { return; }")\n'
                f'sys.exit({search_exit})\n')
            calls = []

            class CliBuilder:
                config = {'build': {'jobs': 2}}

                def invoke(self, args, log):
                    calls.append(args)
                    cwd, timeout = root, 5
                    if args[0] == 'env':
                        cwd, args = root/args[2], args[3:]
                    elif args[0] == 'timeout':
                        timeout, args = float(args[1]), args[2:]
                    with log.open('w') as output:
                        return subprocess.run([sys.executable, *args[1:]], cwd=cwd,
                                              timeout=timeout, stdout=output,
                                              stderr=subprocess.STDOUT).returncode

            failed_import = import_exit or import_message
            failed_search = search_exit not in (0, 124) or search_message or not base_compiled or not searched
            args = (CliBuilder(), root,
                    {'symbol': 'target', 'source': 'source.c', 'asm': 'target.s'},
                    b'candidate source', b'original source', threading.Lock(), 5, root)
            if failed_import or failed_search:
                with self.assertRaises(HarnessError):
                    run_permuter(*args)
            else:
                result = run_permuter(*args)
            self.assertEqual(source.read_bytes(), b'original source')
            self.assertFalse((root/'.permuter').exists())
            if failed_import:
                self.assertEqual(len(calls), 1)
            else:
                if not failed_search:
                    self.assertEqual(result, (0, 'void target(void) { return; }'))
                self.assertEqual(calls[1][:3], ['timeout', '5', 'python3'])
                self.assertIn('--stop-on-zero', calls[1])
                self.assertNotIn('--quiet', calls[1])
                self.assertEqual(calls[1][-2:], ['-j', '2'])


class PermuterCacheTests(acceleration.LoopFixture):
    def test_old_trial_does_not_skip_stack_search_and_new_trial_is_reused(self):
        self.cfg['permuter_seconds'] = 5
        self.cfg['permuter_min_score'] = 50
        self.state.transition(self.function['id'], 'analyzing')
        self.state.transition(self.function['id'], 'attempting',
                              best_source=CANDIDATE.encode(), best_score=50)
        function = self.state.get('target')
        suffix = trial_key(function['best_source'], function)
        old_key, new_key = 'permuter:stack-diffs:' + suffix, 'permuter:checked:stack-diffs:' + suffix
        with self.state.db:
            self.state.db.execute('INSERT INTO local_trials VALUES (?,?,?)',
                                  (function['id'], old_key, 'no_improvement'))
        target = SimpleNamespace(function=function, original=SOURCE.encode())
        with patch('decomp_harness.workflow.run_permuter', return_value=None) as permuter:
            self.assertFalse(self.loop.try_permuter(target))
            self.assertFalse(self.loop.try_permuter(target))
        permuter.assert_called_once()
        rows = self.state.db.execute('SELECT candidate_sha, outcome FROM local_trials WHERE function_id=?',
                                     (function['id'],)).fetchall()
        self.assertEqual({row['candidate_sha']: row['outcome'] for row in rows},
                         {old_key: 'no_improvement', new_key: 'no_improvement'})

    def test_technical_failure_is_reported_and_remains_retryable(self):
        self.cfg['permuter_seconds'] = 5
        self.cfg['permuter_min_score'] = 50
        self.state.transition(self.function['id'], 'analyzing')
        self.state.transition(self.function['id'], 'attempting',
                              best_source=CANDIDATE.encode(), best_score=50)
        target = SimpleNamespace(function=self.state.get('target'), original=SOURCE.encode())
        with patch('decomp_harness.workflow.run_permuter', side_effect=HarnessError('Import syntax error')) as permuter:
            self.assertFalse(self.loop.try_permuter(target))
            self.assertFalse(self.loop.try_permuter(target))
        self.assertEqual(permuter.call_count, 2)
        self.assertEqual(self.state.db.execute('SELECT count(*) FROM local_trials').fetchone()[0], 0)
        runs = self.state.db.execute('SELECT outcome, error, ended FROM runs WHERE model=?', ('permuter',)).fetchall()
        self.assertEqual(len(runs), 2)
        self.assertTrue(all(row['outcome'] == 'technical' and row['ended']
                            and row['error'] == 'Import syntax error' for row in runs))
