"""Why an OBJECT MATCH is rejected must reach the worker; regressions outside the target
are caught before the full ROM check; shared callees no longer serialize the queue."""
from dataclasses import replace
import json
from pathlib import Path
import subprocess
import sys
import tempfile
import unittest
from unittest.mock import patch

import test_harness as fixtures
from test_acceleration import LoopFixture
from decomp_harness.build import differing_offsets, explain_rom_failure, locate
from decomp_harness.codex import Result
from decomp_harness.matching import CHANGED, changed_functions
from decomp_harness.repairs import save_support
from decomp_harness.scheduler import rom_rejected

UNIT = ('00000000 <target>:\n   0: 03e00008  jr ra\n   4: 00000000  nop\n'
        '00000008 <other>:\n   8: 03e00008  jr ra\n   c: 00000000  nop\n')
REGRESSED = UNIT.replace('   c: 00000000  nop', '   c: 24020001  li v0,1')
MAP = '''
.core2          0x0000000080001000       0x20 load address 0x0000000000002000
 .text          0x0000000080001000       0x10 build/us/src/core2/a.c.o
                0x0000000080001000                func_A
                0x0000000080001008                func_B
 .text          0x0000000080001010       0x10 build/us/src/core2/b.c.o
                0x0000000080001010                func_C
.overlay_with_a_long_name
                0x0000000080800000       0x10 load address 0x0000000000003000
 .text          0x0000000080800000       0x10 build/us/src/overlays/x.c.o
                0x0000000080800000                func_X
'''


class HelperTests(unittest.TestCase):
    def test_changed_functions_reports_neighbours_never_targets(self):
        self.assertEqual(changed_functions(UNIT, REGRESSED), ['other'])
        self.assertEqual(changed_functions(UNIT, REGRESSED, skip=('other',)), [])
        target_only = UNIT.replace('   4: 00000000  nop', '   4: 24020001  li v0,1')
        self.assertEqual(changed_functions(UNIT, target_only, skip=('target',)), [])

    def test_locate_picks_section_by_load_address(self):
        self.assertEqual(locate(MAP, 0x2009), ('.core2', '.text of build/us/src/core2/a.c.o', ('func_B', 1)))
        self.assertEqual(locate(MAP, 0x2010), ('.core2', '.text of build/us/src/core2/b.c.o', ('func_C', 0)))
        # Same VMA range as other overlays: only the load address disambiguates; long names wrap.
        self.assertEqual(locate(MAP, 0x3004), ('.overlay_with_a_long_name', '.text of build/us/src/overlays/x.c.o', ('func_X', 4)))
        self.assertEqual(locate(MAP, 0x9999), (None, None, None))

    def test_differing_offsets_crosses_blocks_and_caps(self):
        a = bytes(200000)
        b = bytearray(a); b[5] = 1; b[150001] = 2
        self.assertEqual(differing_offsets(a, bytes(b)), [5, 150001])
        self.assertEqual(differing_offsets(a, bytes(b), limit=1), [5])

    def test_explanation_names_build_error_or_rom_location(self):
        with tempfile.TemporaryDirectory() as folder:
            root = Path(folder)
            log = root/'regression.log'
            log.write_text("tools/ido/cc -c x.c\ncfe: Error: src/core2/b.c, line 58: redeclaration of 'f'\n    s32 f(s32);\n"
                           "make: *** [Makefile:94: x] Error 1\n")
            self.assertIn("src/core2/b.c, line 58: redeclaration of 'f'", explain_rom_failure(root, log, 'func_A'))
            log.write_text('Binary files decompressed.us.z64 and build/us/banjotooie_decompressed.z64 differ\n')
            (root/'build/us').mkdir(parents=True)
            expected = bytes(0x4000)
            actual = bytearray(expected); actual[0x2009] = 0xff
            (root/'decompressed.us.z64').write_bytes(expected)
            (root/'build/us/banjotooie_decompressed.z64').write_bytes(bytes(actual))
            (root/'build/us/banjotooie_decompressed.map').write_text(MAP)
            text = explain_rom_failure(root, log, 'func_A')
            self.assertIn('ROM 0x2009: .core2 func_B+0x1', text)
            self.assertIn('outside the target', text)
            self.assertNotIn('outside the target', explain_rom_failure(root, log, 'func_B'))
            self.assertIn('outside the target', explain_rom_failure(root, log, 'func_'))  # no prefix match

    def test_rom_rejected_counts_only_consecutive_worker_object_matches(self):
        hit = {'id': 'attempt-1', 'outcome': 'nonmatching', 'score': 100.0}
        recheck = {'id': 'recheck-1', 'outcome': 'nonmatching', 'score': 100.0}
        miss = {'id': 'attempt-2', 'outcome': 'nonmatching', 'score': 97.0}
        self.assertTrue(rom_rejected([miss, hit, recheck, hit], 2))
        self.assertFalse(rom_rejected([hit, miss], 2))
        self.assertFalse(rom_rejected([hit], 2))
        self.assertFalse(rom_rejected([hit, hit], 0))


class RegressionLoopTests(LoopFixture):
    def neighbours_regress(self):
        """Target object matches, but the candidate file also changes `other`."""
        self.loop.builder.disassemble_all = lambda source: (
            UNIT if (self.work/source).read_text() == fixtures.SOURCE else REGRESSED)

    def test_neighbour_regression_reaches_next_worker_and_stops_early(self):
        self.allow_match = False
        self.neighbours_regress()
        self.process()
        f = self.state.get('target')
        self.assertEqual(f['status'], 'needs_human')
        self.assertEqual(len(self.invocations), 2)
        self.assertIn('already matching functions (src/core1/a.c: other)', f['last_error'])
        comparison = json.loads((self.root/'.decomp-agent/runs'/f['best_run']/'comparison.json').read_text())
        self.assertEqual(comparison['regressions'], {'src/core1/a.c': ['other']})
        self.assertIn('other', comparison['rejection'])

    def test_compile_loop_marks_a_regression_as_unfinished(self):
        self.neighbours_regress()
        replies = []

        class CompilingRunner:
            redact = staticmethod(lambda text: text)

            def run(self, **kw):
                (kw['cwd']/'src/core1/a.c').write_text(fixtures.CANDIDATE)
                replies.append(subprocess.run([sys.executable, str(kw['cwd']/'decomp-compile')],
                                              capture_output=True, text=True, timeout=30).stdout)
                return Result(0, 'ok', usage={}, message={'status': 'candidate', 'knowledge': []})

        with patch('decomp_harness.workflow.CodexRunner', CompilingRunner):
            self.loop.runners = {}
            self.process()
        self.assertIn('OBJECT MATCH', replies[0])
        self.assertIn('REGRESSION, not finished', replies[0])
        self.assertIn('src/core1/a.c: other', replies[0])

    def support_target(self):
        (self.work/'src/core1/b.c').write_bytes(b'void helper(void) {}\n')
        target = self.loop.prepare(self.state.get('target'))
        return replace(target, support={'src/core1/b.c': b'void helper(void) {}\n'})

    def test_changed_dependency_unit_is_compiled_and_its_error_reported(self):
        target = self.support_target()
        built = []

        def object_build(source, log):
            built.append(source)
            if source == 'src/core1/b.c' and (self.work/source).read_bytes() == b'broken':
                log.write_text("cfe: Error: src/core1/b.c, line 1: redeclaration of 'helper'\n")
                return 1
            return 0

        self.loop.builder.object_build = object_build
        log = self.root/'probe.log'
        dumps = self.loop.object_dumps(target, fixtures.CANDIDATE.encode(), ['target'], log, self.root/'restore.log',
                                       {'src/core1/b.c': b'broken'})
        self.assertIsNone(dumps)
        self.assertIn('Dependency src/core1/b.c no longer compiles', log.read_text())
        self.assertIn("redeclaration of 'helper'", log.read_text())
        self.assertEqual(built.count('src/core1/b.c'), 2)  # unchanged baseline, then the edit
        self.assertEqual((self.work/'src/core1/b.c').read_bytes(), b'void helper(void) {}\n')

    def test_unchanged_baseline_is_compiled_once_per_snapshot(self):
        target = self.loop.prepare(self.state.get('target'))
        built = []
        self.loop.builder.object_build = lambda source, log: built.append(source) or 0
        for _ in range(3):
            dumps = self.loop.object_dumps(target, fixtures.CANDIDATE.encode(), ['target'], self.root/'p.log', self.root/'r.log')
            self.assertEqual(dumps[CHANGED], {})
        self.assertEqual(len(built), 4)

    def test_dependency_changed_by_another_publication_is_retried_not_fatal(self):
        target = self.support_target()
        (self.root/'src/core1/b.c').write_bytes(b'void helper(int published);\n')
        directory = self.root/'.decomp-agent/runs/attempt-stale'
        directory.mkdir(parents=True)
        save_support(directory, target.support, {'src/core1/b.c': b'void helper(float x) {}\n'})
        self.state.start_run(target.function['id'], 'worker', 'm', 'high', directory)
        outcome = self.loop.accept_candidate(target, fixtures.CANDIDATE.encode(), directory)
        self.assertEqual(outcome, 'improve')
        self.assertEqual(self.state.db.execute("SELECT outcome FROM runs WHERE id='attempt-stale'").fetchone()[0], 'stale_dependency')
        self.assertIn('redo the dependency edit', self.state.get('target')['last_error'])


if __name__ == '__main__':
    unittest.main()
