#!/usr/bin/env python3
"""ROM-free validation for isolated play.py sessions."""
from pathlib import Path
import contextlib
import io
import subprocess
import sys
import tempfile
import unittest
from unittest import mock

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE.parent))
import play


class PlayOptionsTest(unittest.TestCase):
    def test_rejects_existing_session_directory(self):
        with tempfile.TemporaryDirectory(prefix='bt-play-test-') as tmp:
            old_dir, old_ctl = play.DIR, play.CTL
            try:
                with contextlib.redirect_stderr(io.StringIO()):
                    with self.assertRaises(SystemExit): play.start(['--dir', tmp])
                self.assertEqual(play.DIR, old_dir)
                self.assertEqual(play.CTL, old_ctl)
            finally:
                play.DIR, play.CTL = old_dir, old_ctl

    def test_expands_and_resolves_start_directory_before_exists_check(self):
        with tempfile.TemporaryDirectory(prefix='bt-play-test-') as tmp:
            existing = Path(tmp) / 'existing'; existing.mkdir()
            original = Path.expanduser
            def expand(path):
                return existing if str(path) == '~/already-created' else original(path)
            with mock.patch.object(Path, 'expanduser', expand), contextlib.redirect_stderr(io.StringIO()):
                with self.assertRaises(SystemExit): play.start(['--dir', '~/already-created'])

    def test_rejects_missing_executable(self):
        with tempfile.TemporaryDirectory(prefix='bt-play-test-') as tmp:
            missing = Path(tmp) / 'missing'
            with contextlib.redirect_stderr(io.StringIO()):
                with self.assertRaises(SystemExit): play.start(['--exe', str(missing)])

    def test_requires_option_values(self):
        for option in ('--dir', '--exe', '--save', '--scale'):
            with self.subTest(option=option), contextlib.redirect_stderr(io.StringIO()):
                with self.assertRaises(SystemExit): play.start([option])

    def test_rejects_malformed_environment_without_creating_session(self):
        with tempfile.TemporaryDirectory(prefix='bt-play-test-') as tmp:
            root = Path(tmp)
            exe = root / 'game'; exe.write_text('#!/bin/sh\n'); exe.chmod(0o755)
            session = root / 'new-session'
            error = io.StringIO()
            with contextlib.redirect_stderr(error), self.assertRaises(SystemExit):
                play.start(['--dir', str(session), '--exe', str(exe), '--', 'BROKEN'])
            self.assertIn('invalid environment argument', error.getvalue())
            self.assertFalse(session.exists())

    def test_rejects_unknown_start_arguments_clearly(self):
        error = io.StringIO()
        with contextlib.redirect_stderr(error), self.assertRaises(SystemExit):
            play.start(['--unknown'])
        self.assertIn('unexpected start arguments', error.getvalue())

    def test_followup_cli_uses_selected_directory(self):
        with tempfile.TemporaryDirectory(prefix='bt-play-test-') as tmp:
            directory = Path(tmp)
            marker = 'selected-session-log'
            (directory / 'log.txt').write_text(marker + '\n')
            result = subprocess.run([sys.executable, str(HERE.parent / 'play.py'), '--dir', tmp,
                                     'run 1 0'], capture_output=True, text=True)
            self.assertNotEqual(result.returncode, 0)
            self.assertIn(marker, result.stderr)
            self.assertIn(str(directory.resolve() / 'log.txt'), result.stderr)

    def test_followup_cli_rejects_missing_directory(self):
        with tempfile.TemporaryDirectory(prefix='bt-play-test-') as tmp:
            missing = Path(tmp) / 'not-created'
            result = subprocess.run([sys.executable, str(HERE.parent / 'play.py'), '--dir', str(missing),
                                     'stop'], capture_output=True, text=True)
            self.assertNotEqual(result.returncode, 0)
            self.assertIn('play directory is not a directory', result.stderr)

    def test_frozen_binary_and_environment_arguments(self):
        with tempfile.TemporaryDirectory(prefix='bt-play-test-') as tmp:
            root = Path(tmp)
            exe = root / 'frozen-game'
            exe.write_text('#!/bin/sh\n')
            exe.chmod(0o755)
            save = root / 'save.eep'; save.write_bytes(b'synthetic save')
            session = root / 'new-session'
            old_dir, old_ctl = play.DIR, play.CTL
            try:
                with mock.patch.dict('os.environ', {}, clear=True), \
                     mock.patch.object(play.subprocess, 'Popen') as popen, \
                     mock.patch.object(play, 'send', return_value='ready 1 map AF\n'):
                    popen.return_value.pid = 123
                    play.start(['--dir', str(session), '--exe', str(exe), '--save', str(save),
                                '--scale', '4', '--', 'BT_PRESS=0:0'])
                    cmd, = popen.call_args.args
                    env = popen.call_args.kwargs['env']
                    self.assertEqual(cmd[0], str(exe.resolve()))
                    self.assertEqual(env['BT_CONTROL'], str(session.resolve() / 'ctl'))
                    self.assertEqual(env['BT_SAVE'], str(session.resolve() / 'eeprom.bin'))
                    self.assertEqual(env['BT_SCALE'], '4')
                    self.assertEqual(env['BT_PRESS'], '0:0')
                    self.assertEqual((session / 'eeprom.bin').read_bytes(), save.read_bytes())
            finally:
                play.DIR, play.CTL = old_dir, old_ctl


if __name__ == '__main__':
    unittest.main()
