import subprocess
from unittest.mock import patch

import test_harness as fixtures
from decomp_harness.build import Builder
from decomp_harness.common import Control, HarnessError


class BuildSessionTests(fixtures.Fixture):
    def test_reuses_one_offline_container_and_cleans_up(self):
        builder = Builder(self.root, self.cfg, Control())
        with patch('decomp_harness.build.command') as command, \
                patch('decomp_harness.build.run_logged', return_value=0) as run:
            builder.start()
            name = builder.container
            startup = command.call_args.args[0]
            self.assertIn('--init', startup)
            self.assertIn('type=bind,source=' + str(self.root) + ',target=/work', startup)
            self.assertEqual(startup[startup.index('--network') + 1], 'none')
            self.assertIn('--cap-drop', startup)
            self.assertIn('no-new-privileges', startup)
            builder.start()
            self.assertEqual(command.call_count, 1)
            for _ in range(2):
                builder.invoke(['make', 'check'], self.root/'log')
                self.assertEqual(run.call_args.args[0], ['docker', 'exec', name, 'make', 'check'])
            self.assertEqual(builder.argv(['make', 'setup'], network=True)[:2], ['docker', 'run'])
            builder.close()
            self.assertEqual(command.call_args.args[0], ['docker', 'rm', '-f', name])
            builder.close()
            self.assertEqual(command.call_count, 2)
            self.assertIsNone(builder.container)

    def test_timeout_removes_container_and_its_running_compiler(self):
        builder = Builder(self.root, self.cfg, Control())
        with patch('decomp_harness.build.command') as command, \
                patch('decomp_harness.build.run_logged', side_effect=HarnessError('timed out')):
            builder.start()
            name = builder.container
            with self.assertRaisesRegex(HarnessError, 'timed out'):
                builder.object_build('src/core1/a.c', self.root/'log')
            self.assertEqual(command.call_args.args[0], ['docker', 'rm', '-f', name])
            self.assertIsNone(builder.container)

    def test_failed_start_cleans_up_only_its_own_name(self):
        builder = Builder(self.root, self.cfg, Control())
        calls = []

        def command(args, *a, **kw):
            calls.append(args)
            if args[1] == 'run':
                raise HarnessError('start failed')
            return subprocess.CompletedProcess(args, 0)

        with patch('decomp_harness.build.command', side_effect=command):
            with self.assertRaisesRegex(HarnessError, 'start failed'):
                builder.start()
        name = calls[0][calls[0].index('--name') + 1]
        self.assertTrue(name.startswith('decomp-build-'))
        self.assertEqual(calls[1], ['docker', 'rm', '-f', name])
        self.assertIsNone(builder.container)

    def test_native_backend_does_not_start_docker(self):
        self.cfg['build']['backend'] = 'native'
        builder = Builder(self.root, self.cfg, Control())
        with patch('decomp_harness.build.command') as command:
            builder.start()
            self.assertEqual(builder.argv(['make', 'check']), ['make', 'check'])
            builder.close()
            command.assert_not_called()
