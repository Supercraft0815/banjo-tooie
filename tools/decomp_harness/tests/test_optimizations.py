import hashlib
import io
import json
from pathlib import Path
import sqlite3
import tempfile
import sys
import threading
import time
import unittest
from contextlib import redirect_stdout
from unittest.mock import patch

import test_harness as fixtures
from test_harness import ASM, SOURCE, CANDIDATE, DUMP
from decomp_harness.claude import ClaudeRunner, check_subscription, clean_claude_environment, parse_claude_events
from decomp_harness.cli import FORK_DECOMPED_BYTES, TOTAL_CODE_BYTES, parser, progress, summary
from decomp_harness.codex import Result
from decomp_harness.codex import Redactor
from decomp_harness.common import Control, HarnessError, git, validate_stage
from decomp_harness.context import context_pack, worker_prompt
from decomp_harness.guard import candidate_guard, dispose_worker, worker_copy
from decomp_harness.patterns import candidates, candidate_source, pattern_key, remember, replacements
from decomp_harness.scanner import scan
from decomp_harness.scheduler import advance, next_function, resources, route
from decomp_harness.state import State
from decomp_harness.workflow import Loop


def assembly(*words):
    return 'glabel target\n' + ''.join(f'/* {0x1000+i*4:X} {0x80000400+i*4:08X} {word:08X} */ {op}\n'
                                     for i, (word, op) in enumerate(words)) + 'endlabel target\n'


class PatternTests(fixtures.Fixture):
    def test_load_store_constants_and_signed_offsets(self):
        jump = (0x03E00008, 'jr $ra')
        for word, opcode, expected in (
            (0x8C82000C, 'lw $v0,0xc($a0)', 'return arg0[3];'),
            (0x8482FFFE, 'lh $v0,-2($a0)', 'return arg0[-1];'),
            (0x90820007, 'lbu $v0,7($a0)', 'u8 *arg0'),
            (0xC4800014, 'lwc1 $f0,0x14($a0)', 'f32 target(f32 *arg0)'),
            (0xA4850018, 'sh $a1,0x18($a0)', 'arg0[12] = arg1;'),
            (0x2402FFFF, 'addiu $v0,$zero,-1', 'return -1;'),
            (0x3C028040, 'lui $v0,0x8040', 'return 0x80400000U;'),
            (0, 'nop', 'void target(void)'),
        ):
            with self.subTest(opcode=opcode):
                code, = replacements(assembly(jump, (word, opcode)), 'target')
                self.assertIn(expected, code)
                candidate_guard(SOURCE, candidate_source(SOURCE, 'target', code).decode(), 'target')
        code, = replacements(assembly((0x3C028040, 'lui $v0,0x8040'), jump,
                                      (0x2442FFF0, 'addiu $v0,$v0,-16')), 'target')
        self.assertIn('0x803FFFF0U', code)

    def test_reject_relocations_misalignment_wrong_registers_and_branches(self):
        for asm in (assembly((0x03E00008, 'jr $ra'), (0x8C820001, 'lw $v0,1($a0)')),
                    assembly((0x03E00008, 'jr $ra'), (0x8C830004, 'lw $v1,4($a0)')),
                    assembly((0x03E00008, 'jr $ra'), (0x3C028000, 'lui $v0,%hi(global)')),
                    assembly((0x10000001, 'b .Lx'), (0, 'nop'))):
            self.assertEqual(replacements(asm, 'target'), [])

    def test_reuse_keeps_exact_operands_and_replaces_only_symbol(self):
        remember(self.root, self.state, self.function, 'void target(void) {}', 'verified-commit')
        got = list(candidates(self.root, self.function, self.state))
        self.assertTrue(got[0][0].startswith('reuse:'))
        self.assertEqual(got[0][1], 'void target(void) {}')
        self.assertEqual(pattern_key(ASM, 'target'), pattern_key(ASM.replace('800004', '800008'), 'target'))
        self.assertNotEqual(pattern_key(ASM, 'target'), pattern_key(ASM.replace('nop', 'li $v0,1'), 'target'))

    def test_context_contains_actual_types_and_no_mandatory_reread(self):
        p = self.root/'lib/ultralib/include/PR/ultratypes.h'
        p.parent.mkdir(parents=True)
        p.write_text('typedef long s32;\ntypedef float f32;\n')
        pack = context_pack(self.root, self.function, self.state, self.cfg)
        self.assertIn('typedef long s32;', pack)
        self.assertIn('#pragma GLOBAL_ASM', pack)
        self.assertIn('Target line: 3', pack)
        self.assertIn('do not reread', worker_prompt(self.function, pack, False))
        self.assertLessEqual(len(pack), self.cfg['context_chars'])

    def test_context_carries_quirks_and_closest_matched_function(self):
        solved = self.root/'asm/nonmatchings/core1/a/solved.s'
        solved.write_text(ASM.replace('target', 'solved'))
        self.state.db.execute('PRAGMA foreign_keys=OFF')
        self.state.db.execute('INSERT INTO solutions VALUES (?,?,?,?,?)', (
            'solved', '', 'solved', solved.relative_to(self.root).as_posix(), 'void solved(void) { one_line(); }'))
        self.state.note('core1 IDO solved', 'line layout moved sw ra', 'commit')
        self.state.note('core1 IDO solved', 'validation deferred to parent', 'commit')
        pack = context_pack(self.root, self.function, self.state, self.cfg)
        self.assertIn('Source line layout changes scheduling', pack)
        self.assertIn('void solved(void) { one_line(); }', pack)
        self.assertIn('note: line layout moved sw ra', pack)
        self.assertNotIn('deferred to parent', pack)

    def test_retry_context_pairs_failed_patches_with_results_and_flags_repeats(self):
        for index in range(5):
            directory = self.root / '.decomp-agent/runs' / f'attempt-{index}'
            directory.mkdir(parents=True)
            (directory / 'source.diff').write_text('+return first_variant;' if index == 0 else '+return repeated_variant;')
            (directory / 'comparison.json').write_text(json.dumps({
                'exact': False, 'different_instructions': 1,
                'first_diff': {'expected': 'addu v0,a0,t6', 'actual': f'actual_{index}'},
            }))
            run_id = self.state.start_run(self.function['id'], 'worker', 'test', 'low', directory)
            self.state.finish_run(run_id, outcome='nonmatching', score=66.6667)
        pack = context_pack(self.root, self.state.get('target'), self.state, self.cfg)
        feedback = pack.split('Failed attempts (newest first):\n', 1)[1]
        self.assertIn('+return first_variant;', feedback)  # Survives beyond the old four-run window.
        self.assertEqual(feedback.count('+return repeated_variant;'), 1)
        self.assertIn('Identical source patch to attempt-4; already tried.', feedback)
        oldest = feedback.split('Run attempt-0:', 1)[1]
        self.assertIn('actual_0', oldest)
        self.assertNotIn('actual_4', oldest)
        self.assertLessEqual(len(pack), self.cfg['context_chars'])
        self.assertIn('Do not resubmit a tested failed source patch', worker_prompt(self.function, pack, False))
        # A missing patch or incomplete comparison must not prevent resuming the run.
        (directory / 'source.diff').unlink()
        (directory / 'comparison.json').write_text('{incomplete')
        pack = context_pack(self.root, self.state.get('target'), self.state, self.cfg)
        self.assertIn('Compiler comparison unavailable', pack)
        self.assertIn('+return first_variant;', pack)

    def test_busy_file_and_dependencies_are_excluded(self):
        self.assertIsNone(next_function(self.state, busy=resources(self.function)))
        self.state.update(self.function['id'], dependencies='["shared_helper"]')
        self.assertIsNone(next_function(self.state, busy={'shared_helper'}))

    def test_luna_one_attempt_then_existing_escalation(self):
        f = dict(self.function)
        stage, model = route(f, self.cfg)
        self.assertEqual((stage, model['model']), (-2, 'gpt-6-luna'))
        stage, used, total, done = advance(f, [{'score': 20}], self.cfg, stage)
        f.update(stage=stage, stage_attempts=used, cycle_attempts=total, initial_done=1)
        self.assertEqual(route(f, self.cfg)[1]['model'], 'gpt-6.1-sol')
        self.assertFalse(done)

    def test_schema_migration_preserves_history(self):
        self.state.start_run(self.function['id'], 'worker', 'sol', 'medium', self.root/'old')
        self.state.db.execute('ALTER TABLE functions DROP COLUMN initial_done')
        self.state.db.execute('ALTER TABLE runs DROP COLUMN provider')
        self.state.db.execute('DROP TABLE patterns')
        self.state.db.execute('DROP TABLE local_trials')
        self.state.db.execute('PRAGMA user_version=1')
        self.state.db.commit()
        other = State(self.root/'.decomp-agent/state.db')
        try:
            self.assertEqual(other.get('target')['attempts'], 1)
            self.assertEqual(other.db.execute('PRAGMA user_version').fetchone()[0], 4)
            self.assertEqual(other.db.execute('SELECT provider FROM runs').fetchone()[0], 'codex')
        finally:
            other.close()

    def test_usage_report_keeps_probes_models_and_providers_separate(self):
        for index, (provider, model, kind, tokens) in enumerate((('codex', 'luna', 'worker', 50),
                ('codex', 'luna', 'probe', 10), ('claude', 'haiku', 'worker', 30))):
            run_id = self.state.start_run(None, kind, model, 'low', self.root/str(index))
            self.state.finish_run(run_id, provider=provider, usage=json.dumps({'input_tokens': tokens}))
        report = summary(self.state)
        self.assertEqual(report['reported_usage']['input_tokens'], 90)
        groups = {(r['provider'], r['model'], r['kind']): r['reported_usage']['input_tokens'] for r in report['runs']}
        self.assertEqual(groups, {('codex', 'luna', 'worker'): 50, ('codex', 'luna', 'probe'): 10,
                                  ('claude', 'haiku', 'worker'): 30})

    def test_progress_adds_matched_bytes_to_fork_baseline(self):
        with self.state.db:
            self.state.db.execute("UPDATE functions SET status='matched' WHERE id=?", (self.function['id'],))
        report = progress(self.state)
        size = self.function['size']
        self.assertEqual(report['matched_functions'], 1)
        self.assertEqual(report['decomped_code_bytes'], FORK_DECOMPED_BYTES+size)
        self.assertEqual(report['gained_percent_points'], round(100*size/TOTAL_CODE_BYTES, 3))
        self.assertEqual(report['segments']['boot'], {'fork_percent': 100.0, 'percent': 100.0})
        self.assertEqual(sum(d['matched'] for d in report['difficulties'].values()), 1)

    def test_private_worktree_cannot_reference_user_git(self):
        fixtures.GuardTests.setup_git(self)
        (self.root/'include').mkdir()
        (self.root/'lib/ultralib/include').mkdir(parents=True)
        worker = worker_copy(self.root, self.function, worktree=True)
        owner = worker.parent
        try:
            self.assertEqual(git(worker, 'rev-parse', '--show-toplevel'), str(worker))
            private_git = Path(git(worker, 'rev-parse', '--git-common-dir')).resolve()
            self.assertTrue(private_git.is_relative_to(owner))
            self.assertNotEqual(private_git, self.root/'.git')
        finally:
            dispose_worker(worker)
        self.assertFalse(owner.exists())


class ClaudeTests(unittest.TestCase):
    def test_configuration_requires_explicit_provider_and_supported_effort(self):
        stage = {'provider': 'claude', 'model': 'haiku', 'effort': 'low', 'attempts': 1}
        validate_stage(stage, True)
        for value, enabled in ((stage, False), ({**stage, 'effort': 'xhigh'}, True),
                               ({**stage, 'provider': 'api'}, True), ({**stage, 'attempts': True}, True)):
            with self.assertRaises(HarnessError):
                validate_stage(value, enabled)

    def test_real_fake_cli_process_with_structured_output(self):
        with tempfile.TemporaryDirectory() as folder:
            root = Path(folder)
            exe = root/'fake-claude'
            event = {'type': 'result', 'subtype': 'success', 'is_error': False,
                     'structured_output': {'status': 'candidate', 'knowledge': []},
                     'usage': {'input_tokens': 4, 'output_tokens': 2}}
            exe.write_text(f'#!{sys.executable}\nimport sys\nsys.stdin.read()\nprint({json.dumps(json.dumps(event))})\n')
            exe.chmod(0o755)
            runner = object.__new__(ClaudeRunner)
            runner.executable, runner.env, runner.redact = str(exe), clean_claude_environment(), Redactor()
            runner.version, runner.authenticate = 'fake', lambda: {}
            schema = root/'schema.json'; schema.write_text('{"type":"object"}')
            result = runner.run(cwd=root, prompt='test', model='claude-haiku-5-5', effort='low',
                                directory=root/'logs', timeout=3, control=Control(), schema=schema)
            self.assertEqual(result.outcome, 'ok')
            self.assertEqual(result.message['status'], 'candidate')
            self.assertEqual(result.usage['input_tokens'], 4)

    def test_subscription_guard_rejects_console_keys_missing_plan_and_other_provider(self):
        good = {'loggedIn': True, 'authMethod': 'claude.ai', 'apiProvider': 'firstParty', 'subscriptionType': 'max'}
        check_subscription(good)
        for change in ({'loggedIn': False}, {'authMethod': 'api_key'}, {'authMethod': 'console'},
                       {'subscriptionType': None}, {'subscriptionType': 'free'}, {'apiProvider': 'bedrock'},
                       {'forcedLoginMethod': 'console'}):
            with self.assertRaises(HarnessError):
                check_subscription({**good, **change})

    def test_environment_and_flags_cannot_enable_api_or_bare_mode(self):
        env = clean_claude_environment({'HOME': '/tmp', 'PATH': '/bin', 'ANTHROPIC_API_KEY': 'key',
            'ANTHROPIC_AUTH_TOKEN': 'token', 'CLAUDE_CODE_OAUTH_TOKEN': 'override',
            'CLAUDE_CODE_USE_BEDROCK': '1', 'ANTHROPIC_BASE_URL': 'https://bad.invalid', 'NODE_OPTIONS': 'bad'})
        self.assertEqual(set(env), {'HOME', 'PATH', 'CLAUDE_CONFIG_DIR'})
        runner = object.__new__(ClaudeRunner)
        runner.executable = 'claude'
        argv = runner.argv(Path('/tmp/worker'), 'claude-haiku-5-5', 'low', Path('/tmp/logs/result'))
        self.assertIn('--restricted', argv)
        self.assertIn('--safe-mode', argv)
        self.assertNotIn('--bare', argv)
        self.assertNotIn('--fallback-model', argv)
        self.assertIn('{"forceLoginMethod":"claudeai"}', argv)

    def test_jsonl_parsing_normalizes_cache_usage_and_errors(self):
        text = json.dumps({'type': 'result', 'subtype': 'success', 'is_error': False,
                           'structured_output': {'status': 'candidate'},
                           'usage': {'input_tokens': 3, 'cache_read_input_tokens': 7, 'cache_creation_input_tokens': 2, 'output_tokens': 4}})
        result = parse_claude_events(text, 0)
        self.assertEqual(result.outcome, 'ok')
        self.assertEqual(result.usage['input_tokens'], 12)
        self.assertEqual(result.usage['cached_input_tokens'], 7)
        for error, kind in [('usage limit reached', 'quota_error'), ('authentication failed', 'auth_error'),
                            ('model not supported', 'model_error')]:
            event = json.dumps({'type': 'result', 'subtype': 'error_during_execution', 'is_error': True, 'errors': [error]})
            self.assertEqual(parse_claude_events(event, 1).outcome, kind)
        self.assertEqual(parse_claude_events('', -15, interrupted=True).outcome, 'interrupted')


class ParallelTests(fixtures.Fixture):
    def setUp(self):
        super().setUp()
        self.cfg['concurrency'] = 2
        self.cfg['local_patterns'] = False
        self.cfg['easy_model']['enabled'] = False
        # Distinct instruction shapes: members of one shape group never run concurrently.
        for name, delay in (('other_target', '24020001 */ addiu $v0, $zero, 0x1'), ('third_target', '24030001 */ addiu $v1, $zero, 0x1')):
            (self.root/f'src/core1/{name}.c').write_text(f'#pragma GLOBAL_ASM("asm/nonmatchings/core1/a/{name}.s")\n')
            (self.root/f'asm/nonmatchings/core1/a/{name}.s').write_text(ASM.replace('target', name).replace('00000000 */ nop', delay))
        self.state.sync(scan(self.root))
        self.git = fixtures.GuardTests.setup_git(self)
        (self.root/'include').mkdir()
        (self.root/'lib/ultralib/include').mkdir(parents=True)
        self.work = self.root/'trusted'
        self.work.mkdir()
        import shutil
        for folder in ('src', 'include', 'lib', 'asm'):
            shutil.copytree(self.root/folder, self.work/folder)
        self.barrier = threading.Barrier(2)
        self.starts = []
        self.stop_after_pair = False
        self.fail = False
        self.active_builds = self.peak_builds = self.active_checks = self.peak_checks = 0
        self.build_roots = set()
        owner = self

        class FakeRunner:
            redact = staticmethod(lambda value: value)

            def run(self, **kw):
                identity = (kw['cwd']/'.harness-worker').read_text()
                path, symbol = identity.split('::')
                owner.starts.append(symbol)
                if owner.barrier:
                    owner.barrier.wait(timeout=5)
                if owner.stop_after_pair:
                    (owner.root/'.decomp-agent/stop-after-current').write_text('stop')
                if owner.fail:
                    return Result(1, 'quota_error')
                source = (kw['cwd']/path).read_text()
                (kw['cwd']/path).write_bytes(candidate_source(source, symbol, f'void {symbol}(void) {{}}'))
                return Result(0, 'ok', message={'status': 'candidate', 'knowledge': []})

        class FakeBuilder:
            def __init__(self, root=None, *_):
                self.root = root

            def start(self):
                pass

            def close(self):
                pass

            def disassemble(self, source, symbol):
                return DUMP.replace('target', symbol)

            def object_build(self, source, log):
                owner.build_roots.add(self.root)
                owner.active_builds += 1
                owner.peak_builds = max(owner.peak_builds, owner.active_builds)
                time.sleep(0.02)
                owner.active_builds -= 1
                return 0

            def build(self, *_):
                return 0

            def regression(self, *_):
                owner.active_checks += 1
                owner.peak_checks = max(owner.peak_checks, owner.active_checks)
                time.sleep(0.02)
                owner.active_checks -= 1
                return True

            def save_baseline(self, *_):
                return False

            def restore(self, source, original, saved, log):
                (owner.work/source).write_bytes(original)

        def stamp(root):
            return {'head': git(root, 'rev-parse', 'HEAD'),
                    'src': hashlib.sha256(b''.join(p.read_bytes() for p in sorted((root/'src').rglob('*.c')))).hexdigest()}

        self.patches = [patch('decomp_harness.workflow.CodexRunner', FakeRunner),
                        patch('decomp_harness.workflow.Builder', FakeBuilder),
                        patch('decomp_harness.workflow.repository_stamp', side_effect=stamp),
                        patch('decomp_harness.workflow.probe_models', return_value=({}, {}))]
        for p in self.patches:
            p.start()
        self.loop = Loop(self.root, self.state, self.cfg, Control(), parser().parse_args(['run', '--max-functions', '2']))
        self.loop.workspace, self.loop.builder = self.work, FakeBuilder(self.work)
        self.loop.expected_stamp = stamp(self.root)

    def tearDown(self):
        for p in self.patches:
            p.stop()
        super().tearDown()

    def process(self):
        with redirect_stdout(io.StringIO()):
            self.loop.process_parallel()

    def test_two_real_worktrees_overlap_but_rom_checks_and_commits_are_serial(self):
        self.process()
        self.assertEqual(len(self.starts), 2)
        self.assertEqual((self.loop.calls, self.loop.matched), (2, 2))
        self.assertEqual(self.peak_checks, 1)
        # Object probes ran in private lanes; only the ROM check rebuilt in the trusted tree.
        lanes = self.build_roots - {self.work}
        self.assertTrue(lanes and all(l.name.startswith('decomp-lane-') and not l.exists() for l in lanes))
        self.assertIsNone(self.loop.lanes)
        self.assertEqual(self.git('rev-list', '--count', 'HEAD'), '3')
        self.assertEqual(self.state.db.execute("SELECT count(*) FROM functions WHERE status='matched'").fetchone()[0], 2)

    def test_shared_attempt_budget_and_stop_after_current(self):
        self.barrier = None
        self.loop.args.max_attempts = 1
        self.loop.args.stop_after_current = True
        self.process()
        self.assertEqual(len(self.starts), 1)
        self.assertEqual(self.loop.calls, 1)

    def test_external_stop_drains_current_pair_without_third_function(self):
        self.stop_after_pair = True
        self.loop.args.max_functions = 3
        self.process()
        self.assertEqual(len(self.starts), 2)
        self.assertEqual(self.loop.matched, 2)

    def test_quota_failure_keeps_both_functions_resumable(self):
        self.fail = True
        with self.assertRaises(HarnessError):
            self.process()
        self.assertEqual(self.state.db.execute("SELECT count(*) FROM functions WHERE status='pending'").fetchone()[0], 3)
        self.assertEqual(self.loop.matched, 0)

    def test_new_probe_finishes_while_an_earlier_rom_check_is_waiting(self):
        self.loop.args.max_functions = 3
        self.loop.local_queue = [{'function': self.state.get(name)['id'], **self.state.get(name)}
                                 for name in ('target', 'other_target', 'third_target')]
        rom_started, third_probe = threading.Event(), threading.Event()
        builder_type = type(self.loop.builder)
        build, regression = builder_type.object_build, builder_type.regression

        def object_build(builder, source, log):
            if builder.root != self.work:
                if 'other_target' in source:
                    self.assertTrue(rom_started.wait(5))
                elif 'third_target' in source:
                    third_probe.set()
            return build(builder, source, log)

        def check(builder, log):
            rom_started.set()
            self.assertTrue(third_probe.wait(5), 'ROM publication blocked admission of a new probe')
            return regression(builder, log)

        def disassemble(builder, source, symbol):
            dump = DUMP.replace('target', symbol)
            if symbol == 'other_target' and 'void other_target' in (builder.root/source).read_text():
                return dump.replace('nop', 'li v0,1')
            return dump

        def process(loop, function):
            target = loop.prepare(function)
            try:
                candidate = candidate_source(target.original.decode(), function['symbol'],
                                             f"void {function['symbol']}(void) {{}}")
                loop.local_trial(function, target, 'test', candidate, function['id'])
            finally:
                loop.release(function['id'], 'test complete')

        with patch.object(builder_type, 'object_build', object_build), \
                patch.object(builder_type, 'regression', check), \
                patch.object(builder_type, 'disassemble', disassemble), \
                patch.object(Loop, 'process_function', process):
            self.process()
        self.assertTrue(third_probe.is_set())
        self.assertEqual(self.peak_checks, 1)
        self.assertEqual(self.state.get('target')['status'], 'matched')
        self.assertEqual(self.state.get('third_target')['status'], 'matched')
        self.assertEqual(self.state.get('other_target')['status'], 'pending')
        self.assertIsNone(self.loop.baseline_builder)

    def test_parallel_rom_mismatch_never_publishes_and_restores_source(self):
        self.barrier = None
        self.loop.args.max_attempts = 1
        self.loop.args.max_functions = 1
        with patch.object(type(self.loop.builder), 'regression', return_value=False):
            self.process()
        self.assertEqual(self.git('rev-list', '--count', 'HEAD'), '1')
        self.assertEqual(self.state.db.execute("SELECT count(*) FROM functions WHERE status='matched'").fetchone()[0], 0)
        for source in (self.root/'src').rglob('*.c'):
            self.assertEqual(source.read_bytes(), (self.work/source.relative_to(self.root)).read_bytes())

    def test_repository_change_during_rom_check_withholds_publication(self):
        self.barrier = None
        self.loop.args.max_attempts = self.loop.args.max_functions = 1
        source = self.root/'src/core1/a.c'
        original = source.read_text()

        def change(*_):
            source.write_text(original + '\n/* external edit */\n')
            return True

        with patch.object(type(self.loop.builder), 'regression', change):
            with self.assertRaisesRegex(HarnessError, 'Repository changed'):
                self.process()
        self.assertTrue(source.read_text().endswith('/* external edit */\n'))
        self.assertEqual(self.git('rev-list', '--count', 'HEAD'), '1')
        self.assertEqual((self.work/'src/core1/a.c').read_text(), original)


if __name__ == '__main__':
    unittest.main()
