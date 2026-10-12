import json
import os
import subprocess
import sys
import time
from unittest.mock import patch

import test_harness as fixtures
from test_acceleration import LoopFixture, NAMED
from decomp_harness.common import HarnessError, atomic_write
from decomp_harness.codex import Result
from decomp_harness.guard import publish, recover_publications
from decomp_harness.matching import instructions, score, worth_rom_check
from decomp_harness.repairs import guard_candidate, guard_repair, refresh_repairs
from decomp_harness.scanner import scan


class RelocationTests(fixtures.Fixture):
    def test_only_address_relocations_pass_and_score_stays_honest(self):
        expected = instructions(NAMED, 'target')
        alias = NAMED.replace('R_80802948', 'base').replace('c4280000', 'c428000c').replace('0(at)', '12(at)')
        result = score(expected, instructions(alias, 'target'))
        self.assertLess(result['score'], 99)
        self.assertTrue(result['relocation_only'])
        self.assertTrue(worth_rom_check(result))
        self.assertFalse(result['exact'])
        for wrong in (alias.replace('c428000c', 'c448000c').replace('12(at)', '12(v0)'),
                      alias.replace('lwc1', 'swc1').replace('c428000c', 'e428000c'),
                      alias.replace('R_MIPS_LO16', 'R_MIPS_26'),
                      alias.replace('\t4: R_MIPS_LO16 base\n', ''),
                      alias + '  10: 00000000 nop\n',
                      alias.replace('00000000  nop', '24020001  li v0,1')):
            self.assertFalse(score(expected, instructions(wrong, 'target'))['relocation_only'], wrong)

    def test_c_surface_repairs_preserve_imports_directives_and_function_names(self):
        source = fixtures.SOURCE.replace('void other', 'int other')
        candidate = fixtures.CANDIDATE.replace('void other', 'float other')
        self.assertIn('target', guard_candidate(source, candidate, 'target'))
        guard_repair('extern int x;\n', 'extern float x;\n')
        for wrong in (candidate.replace('x.h', 'payload.h'),
                      candidate.replace('other', 'renamed'),
                      candidate + '\nvoid helper(void) {}',
                      candidate.replace('{ }', '{ __asm__("nop"); }'),
                      candidate + '\n#pragma GLOBAL_ASM("extra.s")'):
            with self.assertRaises(HarnessError):
                guard_candidate(source, wrong, 'target')

    def test_refresh_only_evidenced_failures_once(self):
        self.state.update(self.function['id'], status='blocked', last_error='Escalation/stagnation budget exhausted')
        with patch('decomp_harness.common.git', return_value=''):
            self.assertEqual(refresh_repairs(self.root, self.state), [])
            self.state.update(self.function['id'], last_error='Uncommitted target changes; untouched.')
            self.assertEqual(len(refresh_repairs(self.root, self.state)), 1)
            self.state.update(self.function['id'], status='blocked')
            self.assertEqual(refresh_repairs(self.root, self.state), [])


class JournalTests(fixtures.GuardTests):
    def test_partial_multifile_write_recovers_every_file(self):
        git = self.setup_git()
        other = self.root/'src/core1/b.c'
        other.write_bytes(b'int dependency;\n')
        git('add', 'src'); git('commit', '-qm', 'dependency')
        support = {'src/core1/b.c': (other.read_bytes(), b'float dependency;\n')}
        writes = []

        def fail_second(path, value):
            writes.append(path)
            if len(writes) == 2:
                raise OSError('simulated interrupted write')
            atomic_write(path, value)

        with patch('decomp_harness.guard.atomic_write', side_effect=fail_second), self.assertRaises(OSError):
            publish(self.root, self.state, self.function, fixtures.SOURCE.encode(), fixtures.CANDIDATE.encode(), support)
        self.assertEqual((self.root/self.function['source']).read_text(), fixtures.SOURCE)
        self.assertEqual(other.read_bytes(), support['src/core1/b.c'][0])
        self.assertEqual(self.state.db.execute('SELECT count(*) FROM publication_files').fetchone()[0], 0)
        self.assertEqual(git('status', '--porcelain', '--', 'src'), '')

    def test_conflicting_support_file_preserves_entire_journal(self):
        git = self.setup_git()
        other = self.root/'src/core1/b.c'
        other.write_bytes(b'user edit')
        with self.state.db:
            self.state.db.execute('INSERT INTO publication VALUES (?,?,?,?,?,?)',
                (self.function['id'], self.function['source'], fixtures.SOURCE.encode(), fixtures.CANDIDATE.encode(), git('rev-parse', 'HEAD'), time.time()))
            self.state.db.execute('INSERT INTO publication_files VALUES (?,?,?,?)',
                (self.function['id'], 'src/core1/b.c', b'before', b'after'))
        (self.root/self.function['source']).write_text(fixtures.CANDIDATE)
        with self.assertRaises(HarnessError):
            recover_publications(self.root, self.state)
        self.assertEqual(other.read_bytes(), b'user edit')
        self.assertEqual((self.root/self.function['source']).read_text(), fixtures.CANDIDATE)
        self.assertEqual(self.state.db.execute('SELECT count(*) FROM publication_files').fetchone()[0], 1)


for _name in [n for n in dir(fixtures.GuardTests) if n.startswith('test_')]:
    setattr(JournalTests, _name, None)


class RepairLoopTests(LoopFixture):
    def dependency(self):
        header = 'include/dependency.h'
        before, after = b'extern int D_dep;\n', b'extern float D_dep;\n'
        for root in (self.root, self.work):
            (root/header).write_bytes(before)
        self.git('add', header); self.git('commit', '-qm', 'dependency header')
        features = json.loads(self.function['features'])
        features['globals'] = ['D_dep']
        self.state.update(self.function['id'], features=json.dumps(features))
        self.function = self.state.get('target')
        self.invalidations = []
        self.loop.builder.invalidate = lambda paths, log: self.invalidations.append(set(paths))
        return header, before, after

    def repair_runner(self, header, after):
        class Runner:
            redact = staticmethod(lambda text: text)

            def run(self, **kwargs):
                (kwargs['cwd']/header).write_bytes(after)
                (kwargs['cwd']/self_source).write_text(fixtures.CANDIDATE)
                return Result(0, 'ok', message={'status': 'candidate', 'summary': 'correct float declaration', 'blocker': '', 'knowledge': []})

        self_source = self.function['source']
        return patch('decomp_harness.workflow.CodexRunner', Runner)

    def test_header_repair_is_validated_and_committed_with_target(self):
        header, before, after = self.dependency()
        with self.repair_runner(header, after):
            self.process()
        self.assertEqual((self.root/header).read_bytes(), after)
        self.assertEqual(self.state.get('target')['status'], 'matched')
        self.assertEqual(set(self.git('show', '--format=', '--name-only', 'HEAD').splitlines()), {header, self.function['source']})
        self.assertIn({header}, self.invalidations)

    def test_wrong_linked_rom_restores_header_and_never_commits(self):
        header, before, after = self.dependency()
        initial = self.git('rev-parse', 'HEAD')
        self.allow_match = False
        self.loop.args.max_attempts = 1
        with self.repair_runner(header, after):
            self.process()
        self.assertEqual((self.root/header).read_bytes(), before)
        self.assertEqual((self.work/header).read_bytes(), before)
        self.assertEqual((self.work/self.function['source']).read_text(), fixtures.SOURCE)
        self.assertEqual(self.git('rev-parse', 'HEAD'), initial)
        self.assertEqual(len(self.invalidations), 2)

    def test_duplicate_probes_use_cache_and_retain_best_tested_source(self):
        replies, builds = [], []
        self.loop.builder.object_build = lambda source, log: builds.append(log.name) or 0

        class Runner:
            redact = staticmethod(lambda text: text)

            def run(self, **kwargs):
                worker = kwargs['cwd']
                (worker/'src/core1/a.c').write_text(fixtures.CANDIDATE)
                for _ in range(2):
                    replies.append(subprocess.run([sys.executable, str(worker/'decomp-compile')], capture_output=True, text=True, timeout=30).stdout)
                (worker/'src/core1/a.c').write_text(fixtures.CANDIDATE.replace('target', 'wrong'))
                return Result(0, 'agent_error', message='malformed final JSON')

        with patch('decomp_harness.workflow.CodexRunner', Runner):
            self.process()
        self.assertIn('cached result', replies[1])
        self.assertEqual(builds.count('compile-1.log'), 1)
        self.assertNotIn('compile-2.log', builds)
        self.assertEqual(self.state.get('target')['status'], 'matched')
        self.assertTrue(list((self.root/'.decomp-agent/runs').glob('*/compile-1.c')))

    def test_wrong_alias_reaches_rom_check_but_cannot_publish(self):
        initial = self.git('rev-parse', 'HEAD')
        wrong = NAMED.replace('R_80802948', 'wrong_global').replace('0(at)', '12(at)').replace('c4280000', 'c428000c')
        self.loop.builder.disassemble = lambda source, symbol: (NAMED if (self.work/source).read_text() == fixtures.SOURCE else wrong)
        self.allow_match = False
        self.loop.args.max_attempts = 1
        self.process()
        comparison = json.loads(next((self.root/'.decomp-agent/runs').glob('*/comparison.json')).read_text())
        self.assertTrue(comparison['relocation_only'])
        self.assertTrue(comparison['rom_checked'])
        self.assertFalse(comparison['exact'])
        self.assertEqual(self.git('rev-parse', 'HEAD'), initial)

    def test_isa_prerequisite_stops_before_inference(self):
        features = json.loads(self.function['features'])
        features['isa64_ops'] = ['daddiu', 'sd']
        self.state.update(self.function['id'], features=json.dumps(features))
        self.process()
        self.assertEqual(self.invocations, [])
        self.assertIn('Toolchain/ABI', self.state.get('target')['last_error'])

    def test_stored_nonmatching_candidate_rechecked_without_model(self):
        self.state.update(self.function['id'], best_source=fixtures.CANDIDATE.encode(), base_sha=__import__('hashlib').sha256(fixtures.SOURCE.encode()).hexdigest())
        with patch('decomp_harness.workflow.runner_for', side_effect=AssertionError('No inference for replay')):
            self.process()
        self.assertEqual(self.state.get('target')['status'], 'matched')
        self.assertEqual(self.loop.calls, 0)
