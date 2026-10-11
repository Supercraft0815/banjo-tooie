import argparse
from contextlib import redirect_stdout
from copy import deepcopy
import hashlib
import io
import json
import os
from pathlib import Path
import subprocess
import sys
import tempfile
import time
import tomllib
import unittest
from unittest.mock import patch

from decomp_harness.build import import_rom
from decomp_harness.cli import dry_run, parser, summary
from decomp_harness.codex import CodexRunner, Redactor, Result, check_auth_document, clean_environment, parse_events
from decomp_harness.context import asm_analogues
from decomp_harness.common import Control, HarnessError, atomic_write, load_config, locked
from decomp_harness.guard import candidate_guard, manifest, publish, recover_publications, verify_worker_changes
from decomp_harness.matching import instructions, score
from decomp_harness.scanner import asm_features, global_asms, scan
from decomp_harness.scheduler import advance, next_function, route
from decomp_harness.state import State
from decomp_harness.workflow import Loop

ASM = 'glabel target\n/* 1000 80000400 03E00008 */ jr $ra\n/* 1004 80000404 00000000 */ nop\nendlabel target\n'
SOURCE = '#include "x.h"\n\n#pragma GLOBAL_ASM("asm/nonmatchings/core1/a/target.s")\n\nvoid other(void) {}\n'
CANDIDATE = SOURCE.replace('#pragma GLOBAL_ASM("asm/nonmatchings/core1/a/target.s")', 'void target(void) { }')
DUMP = '00000000 <target>:\n   0: 03e00008  jr ra\n   4: 00000000  nop\n'


class Fixture(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory()
        self.root = Path(self.temp.name)
        (self.root/'src/core1').mkdir(parents=True)
        (self.root/'src/core1/a.c').write_text(SOURCE)
        (self.root/'asm/nonmatchings/core1/a').mkdir(parents=True)
        (self.root/'asm/nonmatchings/core1/a/target.s').write_text(ASM)
        self.state = State(self.root/'.decomp-agent/state.db')
        self.state.sync(scan(self.root))
        self.function = self.state.get('target')
        self.cfg = load_config(self.root)

    def tearDown(self):
        self.state.close()
        self.temp.cleanup()


class ScannerTests(Fixture):
    def test_elif_constant_chain(self):
        text = '#if 0\nGLOBAL_ASM("a.s")\n#elif 1\nGLOBAL_ASM("b.s")\n#else\nGLOBAL_ASM("c.s")\n#endif\n'
        self.assertEqual([m['symbol'] for m in global_asms(text)], ['b'])

    def test_comments_strings_and_disabled_conditionals(self):
        source = '/* '+SOURCE+' */\n// GLOBAL_ASM("fake.s")\nconst char*s="GLOBAL_ASM(\\"fake.s\\")";\n#if 0\nGLOBAL_ASM("no.s")\n#else\n'+SOURCE+'#endif\n'
        self.assertEqual([m['symbol'] for m in global_asms(source)], ['target'])

    def test_multiline_macro_and_offsets(self):
        source = '  #pragma GLOBAL_ASM(\n "asm/a.s"\n)\n'
        macro, = global_asms(source)
        self.assertEqual(source[macro['start']:macro['end']].strip(), source.strip())

    def test_unsafe_path_rejected(self):
        with self.assertRaises(HarnessError):
            list(global_asms('GLOBAL_ASM("../secret.s")'))

    def test_real_feature_extraction(self):
        f = asm_features(ASM, 'target')
        self.assertEqual((f['instructions'], f['rom_start'], f['difficulty']), (2, 0x1000, 'easy'))
        data = asm_features('.section .rodata\ndlabel x\n/* 1000 80000400 00000000 */ .word 0', 'x')
        self.assertEqual(data['kind'], 'data')
        self.assertEqual(data['instructions'], 0)

    def test_missing_asm_still_discovered(self):
        (self.root/'asm/nonmatchings/core1/a/target.s').unlink()
        found = list(scan(self.root))
        self.assertEqual(len(found), 1)
        self.assertEqual(found[0]['features']['kind'], 'missing')


class StateTests(Fixture):
    def test_persistence_and_state_machine(self):
        self.state.transition(self.function['id'], 'analyzing')
        self.state.transition(self.function['id'], 'attempting', best_source=b'candidate', best_score=50)
        other = State(self.root/'.decomp-agent/state.db')
        self.assertEqual(other.get('target')['best_source'], b'candidate')
        other.close()
        with self.assertRaises(HarnessError):
            self.state.transition(self.function['id'], 'skipped')

    def test_crash_resume_preserves_best_and_history(self):
        self.state.transition(self.function['id'], 'analyzing')
        self.state.transition(self.function['id'], 'attempting', best_source=b'x', best_score=75)
        self.state.start_run(self.function['id'], 'worker', 'sol', 'medium', self.root/'run1')
        self.state.recover()
        self.assertEqual(self.state.get('target')['status'], 'pending')
        self.assertEqual(self.state.get('target')['best_source'], b'x')
        self.assertEqual(self.state.history(self.function['id'])[0]['outcome'], 'interrupted')

    def test_scan_does_not_claim_external_removal_is_matched(self):
        self.state.sync([])
        self.assertEqual(self.state.get('target')['status'], 'needs_human')

    def test_data_is_skipped(self):
        (self.root/'asm/nonmatchings/core1/a/target.s').write_text('dlabel target\n.word 0\n')
        self.state.sync(scan(self.root))
        self.assertEqual(self.state.get('target')['status'], 'skipped')

    def test_lock_excludes_second_runner(self):
        with locked(self.root/'.decomp-agent'):
            with self.assertRaises(HarnessError):
                with locked(self.root/'.decomp-agent'):
                    pass


class ScoringTests(unittest.TestCase):
    def test_exact_object_does_not_claim_rom_match(self):
        rows = instructions(DUMP, 'target')
        result = score(rows, rows)
        self.assertEqual(result['score'], 100)
        self.assertTrue(result['object_identical'])
        self.assertFalse(result['exact'])

    def test_changed_instruction_and_length(self):
        a = instructions(DUMP, 'target')
        b = instructions(DUMP.replace('nop', 'li v0,1'), 'target')
        result = score(a, b)
        self.assertEqual(result['score'], 50)
        self.assertEqual(result['different_instructions'], 1)
        self.assertIsNotNone(result['first_diff'])
        self.assertLess(score(a, b[:1])['score'], 100)

    def test_relocations_cannot_disappear(self):
        a = instructions(DUMP+'\t4: R_MIPS_LO16 global_a\n', 'target')
        b = instructions(DUMP+'\t4: R_MIPS_LO16 global_b\n', 'target')
        self.assertLess(score(a, b)['score'], 100)

    def test_missing_symbol_fails_closed(self):
        with self.assertRaises(HarnessError):
            instructions(DUMP, 'not_found')

    def test_address_normalization_preserves_branch_offset(self):
        a = instructions('00000000 <target>:\n 0: 10000002 b c\n', 'target')
        b = instructions('00000020 <target>:\n 20: 10000002 b 2c\n', 'target')
        self.assertEqual(score(a, b)['score'], 100)


class SchedulerTests(Fixture):
    def test_bk_asm_index_is_read_only_and_refreshes(self):
        bk = self.root/'bk'; (bk/'asm').mkdir(parents=True)
        path = bk/'asm/target.s'; path.write_text(ASM)
        before = manifest(bk)
        self.assertIn('target', asm_analogues(bk, ASM, self.state))
        self.assertEqual(before, manifest(bk))
        path.unlink()
        self.assertEqual(asm_analogues(bk, ASM, self.state), '')

    def test_bk_map_supplies_analogue_and_callee_signatures(self):
        from decomp_harness import bkmap
        from decomp_harness.context import context_pack
        bk = self.root/'bk'; (bk/'src/core2').mkdir(parents=True)
        (bk/'src/core2/x.c').write_text('static int helper(int a){ return a; }\n/* { */\nf32 bk_get(Actor *this, f32 scale)\n{\n    if (scale) { return 1.0f; }\n    return this->unk0;\n}\n')
        self.cfg['banjo_kazooie_repo'] = str(bk)
        self.assertNotIn('Banjo-Kazooie analogue', context_pack(self.root, self.function, self.state, self.cfg))
        table = self.root/bkmap.TABLE; table.parent.mkdir(parents=True)
        table.write_text(json.dumps({self.function['id']: ['core2/x', 'bk_get', 0.93, 'similar'],
                                     'src/core2/b.c::callee': ['core2/x', 'helper', 1.0, 'call']}))
        bkmap.load.cache_clear()
        pack = context_pack(self.root, self.function, self.state, self.cfg)
        self.assertIn('Banjo-Kazooie analogue bk_get', pack)
        self.assertIn('return this->unk0;\n}', pack)
        self.assertEqual(bkmap.bk_context(self.root, bk, 'none', ['callee', 'unknown']).splitlines()[1],
                         'callee = BK helper (1.00): static int helper(int a)')
        chunks = bkmap.split_functions([0x10000004, 0, 0x03E00008, 0, 0x03E00008, 0, 0, 0, 0x03E00008, 0])
        self.assertEqual([(start, len(words)) for start, words in chunks], [(0, 6), (8, 2)])

    def test_selection_and_difficulty_route(self):
        self.assertEqual(next_function(self.state)['id'], self.function['id'])
        self.assertIsNone(next_function(self.state, 'hard'))
        self.assertEqual(route(self.function, self.cfg)[1]['model'], 'gpt-6-luna')
        hard = {**self.function, 'difficulty': 'hard'}
        self.assertEqual(route(hard, self.cfg)[1]['model'], 'gpt-6-astra')

    def test_escalation_and_stop(self):
        f = deepcopy(self.function)
        history = []
        for i in range(8):
            stage, _ = route(f, self.cfg)
            history.append({'score': 50})
            stage, used, total, done = advance(f, history, self.cfg, stage)
            f.update(stage=stage, stage_attempts=used, cycle_attempts=total)
        self.assertTrue(done)
        self.assertEqual(total, 8)

    def test_dry_run_never_constructs_codex_runner(self):
        args = parser().parse_args(['run', '--dry-run'])
        with patch('decomp_harness.workflow.CodexRunner', side_effect=AssertionError('No inference')):
            result = dry_run(self.root, self.state, self.cfg, args)
        self.assertEqual(result['codex_runs'], 0)
        self.assertEqual(len(result['plan']), 1)

    def test_budget_cli(self):
        args = parser().parse_args(['run', '--max-functions', '1', '--max-attempts', '2', '--max-runtime', '90'])
        self.assertEqual((args.max_functions, args.max_attempts, args.max_runtime), (1, 2, 90))


class CredentialTests(unittest.TestCase):
    def test_all_unlisted_overrides_removed(self):
        env = clean_environment({'PATH': '/bin', 'HOME': '/home/a', 'OPENAI_API_KEY': 'secret',
                                 'CODEX_API_KEY': 'secret', 'CODEX_ACCESS_TOKEN': 'secret',
                                 'OPENAI_BASE_URL': 'https://evil.invalid', 'NEW_CREDENTIAL_OVERRIDE': 'secret',
                                 'BASH_ENV': '/evil', 'NODE_OPTIONS': '--require=/evil'})
        self.assertEqual(set(env), {'PATH', 'HOME', 'CODEX_HOME'})

    def test_only_complete_chatgpt_document_accepted(self):
        auth = {'auth_mode': 'chatgpt', 'tokens': {k: 'value' for k in ('access_token', 'refresh_token', 'id_token', 'account_id')}}
        check_auth_document(auth)
        for bad in ({}, {**auth, 'auth_mode': 'apikey'}, {**auth, 'OPENAI_API_KEY': 'value'}, {**auth, 'tokens': {}}):
            with self.assertRaises(HarnessError):
                check_auth_document(bad)

    def test_redaction(self):
        redact = Redactor({'tokens': {'access_token': 'private-bearer-value'}})
        self.assertNotIn('private-bearer-value', redact('token private-bearer-value'))
        self.assertNotIn('sk-', redact('sk-abcdefghijklmnopqrstuvwx'))

    def test_required_cli_flags_and_model_are_explicit(self):
        runner = object.__new__(CodexRunner)
        runner.executable = 'codex'
        runner.env = clean_environment()
        args = runner.argv(Path('/tmp/worker'), 'gpt-6-astra', 'high', Path('/tmp/result'))
        self.assertIn('forced_login_method="chatgpt"', args)
        self.assertIn('--ignore-user-config', args)
        self.assertIn('--no-daemon', args)
        self.assertIn('gpt-6-astra', args)
        self.assertNotIn('--dangerously-bypass-approvals-and-sandbox', args)
        setting = next(a for a in args if a.startswith('shell_environment_policy.set='))
        self.assertEqual(tomllib.loads(setting)['shell_environment_policy']['set']['PYTHONDONTWRITEBYTECODE'], '1')
        probe = runner.argv(Path('/tmp/worker'), 'gpt-6-astra', 'medium', Path('/tmp/result'), read_only=True)
        self.assertFalse(any('model_instructions_file' in arg for arg in probe))


class RunnerTests(unittest.TestCase):
    def test_jsonl_usage_and_failure_categories(self):
        out = json.dumps({'type': 'turn.completed', 'usage': {'input_tokens': 3}})
        self.assertEqual(parse_events(out, 0, 'OK').usage['input_tokens'], 3)
        for message, expected in [('Usage limit reached', 'quota_error'), ('Model not supported', 'model_error'),
                                  ('Authentication failed', 'auth_error'), ('connection dropped', 'technical_error')]:
            out = json.dumps({'type': 'turn.failed', 'error': {'message': message}})
            self.assertEqual(parse_events(out, 1).outcome, expected)
        self.assertEqual(parse_events('', 0).outcome, 'agent_error')
        self.assertEqual(parse_events('broken', 0).outcome, 'technical_error')

    def test_real_subprocess_json_stream_and_timeout(self):
        with tempfile.TemporaryDirectory() as folder:
            root = Path(folder)
            exe = root/'fake-codex'
            exe.write_text(f'#!{sys.executable}\nimport json,sys,time\nsys.stdin.read()\n'
                           'print(json.dumps({"type":"turn.completed","usage":{"input_tokens":7}}),flush=True)\n'
                           'p=sys.argv[sys.argv.index("--output-last-message")+1]\n'
                           'open(p,"w").write("OK")\n')
            exe.chmod(0o755)
            runner = object.__new__(CodexRunner)
            runner.executable, runner.env, runner.redact = str(exe), clean_environment(), Redactor()
            runner.version = 'fake-codex'
            runner.authenticate = lambda: {}
            kwargs = dict(cwd=root, prompt='test', model='fake', effort='medium', timeout=5, control=Control())
            result = runner.run(directory=root/'logs1', **kwargs)
            self.assertEqual((result.outcome, result.usage['input_tokens']), ('ok', 7))
            exe.write_text(f'#!{sys.executable}\nimport time\ntime.sleep(30)\n')
            kwargs['timeout'] = 0.15
            result = runner.run(directory=root/'logs2', **kwargs)
            self.assertEqual(result.outcome, 'timeout')
            control = Control(); control.cancelled = True
            kwargs['control'] = control
            self.assertEqual(runner.run(directory=root/'logs3', **kwargs).outcome, 'interrupted')


class GuardTests(Fixture):
    def test_only_target_replacement(self):
        self.assertEqual(candidate_guard(SOURCE, CANDIDATE, 'target'), 'void target(void) { }')
        for candidate in (CANDIDATE.replace('other', 'damaged'), CANDIDATE.replace('{ }', '{ asm("nop"); }'),
                          CANDIDATE.replace('void target(void) { }', '#include "payload"\nvoid target(void) {}'),
                          CANDIDATE.replace('void target(void) { }', 'void target(void) {}\nvoid extra(void) {}')):
            with self.assertRaises(HarnessError):
                candidate_guard(SOURCE, candidate, 'target')

    def test_worker_files_and_symlinks_guarded(self):
        worker = self.root/'worker'; worker.mkdir()
        (worker/'a.c').write_text('a')
        before = manifest(worker)
        (worker/'a.c').write_text('b')
        verify_worker_changes(worker, before, 'a.c')
        (worker/'evil').symlink_to(self.root)
        with self.assertRaises(HarnessError):
            verify_worker_changes(worker, before, 'a.c')

    def setup_git(self):
        def git(*args):
            p = subprocess.run(['git', *args], cwd=self.root, capture_output=True, text=True, check=True)
            return p.stdout.strip()
        git('init', '-q', '-b', 'codex/test')
        git('config', 'user.email', 'test@example.invalid')
        git('config', 'user.name', 'Test')
        git('add', 'src')
        git('commit', '-qm', 'initial')
        return git

    def test_atomic_commit_preserves_foreign_staged_change(self):
        git = self.setup_git()
        (self.root/'user.txt').write_text('user content')
        git('add', 'user.txt')
        sha = publish(self.root, self.state, self.function, SOURCE.encode(), CANDIDATE.encode())
        self.assertEqual(git('rev-parse', 'HEAD'), sha)
        self.assertEqual(git('diff', '--cached', '--name-only'), 'user.txt')
        self.assertEqual(git('show', '--format=', '--name-only', 'HEAD'), 'src/core1/a.c')
        self.assertEqual(self.state.get('target')['status'], 'matched')

    def test_recover_before_commit_and_after_commit(self):
        git = self.setup_git()
        for committed in (False, True):
            head = git('rev-parse', 'HEAD')
            with self.state.db:
                self.state.db.execute('INSERT INTO publication VALUES (?,?,?,?,?,?)',
                    (self.function['id'], self.function['source'], SOURCE.encode(), CANDIDATE.encode(), head, time.time()))
            atomic_write(self.root/self.function['source'], CANDIDATE)
            if committed:
                git('add', self.function['source'])
                git('commit', '-qm', 'match\n\nDecomp-Function: '+self.function['id'])
            recover_publications(self.root, self.state)
            self.assertEqual(self.state.get('target')['status'], 'matched' if committed else 'pending')
            if not committed:
                self.assertEqual((self.root/self.function['source']).read_text(), SOURCE)

    def test_concurrent_target_edit_is_preserved(self):
        self.setup_git()
        (self.root/self.function['source']).write_text('user edit')
        with self.assertRaises(HarnessError):
            publish(self.root, self.state, self.function, SOURCE.encode(), CANDIDATE.encode())
        self.assertEqual((self.root/self.function['source']).read_text(), 'user edit')

    def test_wrong_rom_never_written(self):
        path = self.root/'wrong.n64'; path.write_bytes(b'bad')
        with self.assertRaises(HarnessError):
            import_rom(path, self.root)
        self.assertFalse((self.root/'baserom.us.z64').exists())


class LoopTests(Fixture):
    def setUp(self):
        super().setUp()
        self.cfg['local_patterns'] = False
        self.cfg['easy_model']['enabled'] = False
        self.git = GuardTests.setup_git(self)
        for name in ('include', 'lib/ultralib/include'):
            (self.root/name).mkdir(parents=True)
        self.work = self.root/'trusted'
        self.work.mkdir()
        import shutil
        for name in ('src', 'asm', 'include', 'lib'):
            shutil.copytree(self.root/name, self.work/name)
        self.outcomes = []
        self.invocations = []
        self.allow_match = True
        owner = self

        class FakeRunner:
            redact = staticmethod(lambda text: text)

            def run(self, **kwargs):
                owner.invocations.append((kwargs['model'], kwargs['effort']))
                (kwargs['cwd']/'src/core1/a.c').write_text(CANDIDATE)
                outcome = owner.outcomes.pop(0) if owner.outcomes else 'ok'
                return Result(0, outcome, usage={'input_tokens': 5}, message={'status': 'candidate', 'knowledge': []})

        class FakeBuilder:
            def disassemble(self, *_):
                return DUMP

            def object_build(self, *_):
                return 0

            def build(self, *_):
                return 0

            def regression(self, *_):
                return owner.allow_match or (owner.work/'src/core1/a.c').read_text() == SOURCE

            def save_baseline(self, *_):
                return False

            def restore(self, source, original, saved, log):
                (owner.work/source).write_bytes(original)

        self.patches = [patch('decomp_harness.workflow.CodexRunner', FakeRunner),
                        patch('decomp_harness.workflow.repository_stamp', return_value={'head': 'stable'}),
                        patch('decomp_harness.workflow.probe_models', return_value=({}, {}))]
        for p in self.patches:
            p.start()
        self.loop = Loop(self.root, self.state, self.cfg, Control(), parser().parse_args(['run']))
        self.loop.workspace, self.loop.builder = self.work, FakeBuilder()

    def tearDown(self):
        for p in self.patches:
            p.stop()
        super().tearDown()

    def process(self):
        with redirect_stdout(io.StringIO()):
            self.loop.process_function(self.state.get('target'))

    def test_complete_matching_loop_publishes_one_function(self):
        self.process()
        self.assertEqual(self.state.get('target')['status'], 'matched')
        self.assertEqual(len(self.invocations), 1)
        self.assertEqual(self.git('show', '--format=', '--name-only', 'HEAD'), 'src/core1/a.c')

    def test_score_100_without_rom_match_escalates_and_blocks(self):
        self.allow_match = False
        self.process()
        self.assertEqual(self.state.get('target')['status'], 'blocked')
        self.assertEqual(self.state.get('target')['best_score'], 100)
        self.assertEqual(len(self.invocations), 8)
        self.assertEqual(self.invocations[-1], ('gpt-6-astra', 'xhigh'))
        self.assertEqual((self.root/'src/core1/a.c').read_text(), SOURCE)
        self.assertEqual((self.work/'src/core1/a.c').read_text(), SOURCE)

    def test_technical_retry_is_counted(self):
        self.outcomes = ['technical_error', 'ok']
        self.process()
        self.assertEqual(self.state.get('target')['status'], 'matched')
        self.assertEqual(self.loop.calls, 2)

    def test_global_attempt_budget_preserves_candidate_for_resume(self):
        self.allow_match = False
        self.loop.args.max_attempts = 1
        self.process()
        f = self.state.get('target')
        self.assertEqual((f['status'], f['cycle_attempts']), ('pending', 1))
        self.assertEqual(f['best_source'], CANDIDATE.encode())
        self.assertEqual((self.root/'src/core1/a.c').read_text(), SOURCE)

    def test_interruption_leaves_partial_source_and_resumable_state(self):
        self.outcomes = ['interrupted']
        with self.assertRaises(HarnessError):
            self.process()
        self.assertEqual(self.state.get('target')['status'], 'pending')
        self.assertEqual((self.root/'src/core1/a.c').read_text(), SOURCE)
        run = self.state.history(self.function['id'])[0]
        self.assertTrue((self.root/'.decomp-agent/runs'/run['id']/'source-after.c').exists())

    def test_guarded_interrupted_edit_resumes_without_second_model_call(self):
        self.outcomes = ['interrupted']
        with self.assertRaises(HarnessError):
            self.process()
        self.process()
        self.assertEqual(self.state.get('target')['status'], 'matched')
        self.assertEqual(len(self.invocations), 1)

    def test_hard_crash_candidate_recovered_from_private_worker(self):
        from decomp_harness.workflow import recover_candidates
        from decomp_harness.guard import worker_copy, dispose_worker
        from decomp_harness.common import save_json
        worker = worker_copy(self.work, self.function, worktree=True)
        try:
            directory = self.root/'.decomp-agent/runs/crash-test'
            directory.mkdir(parents=True)
            save_json(directory/'worker-before.json', manifest(worker))
            (worker/self.function['source']).write_text(CANDIDATE)
            self.state.update(self.function['id'], base_sha=hashlib.sha256(SOURCE.encode()).hexdigest())
            self.state.start_run(self.function['id'], 'worker', 'sol', 'medium', directory, worker)
            recover_candidates(self.root, self.state)
            self.state.recover()
            self.process()
            self.assertEqual(self.state.get('target')['status'], 'matched')
            self.assertEqual(self.invocations, [])
        finally:
            dispose_worker(worker)

    def test_crash_after_worker_resumes_without_new_inference(self):
        directory = self.root/'.decomp-agent/runs/recovery-test'; directory.mkdir(parents=True)
        (directory/'source-after.c').write_text(CANDIDATE)
        run = self.state.start_run(self.function['id'], 'worker', 'sol', 'medium', directory)
        self.state.finish_run(run, ended=time.time(), outcome='ok')
        self.state.update(self.function['id'], base_sha=hashlib.sha256(SOURCE.encode()).hexdigest())
        self.process()
        self.assertEqual(self.state.get('target')['status'], 'matched')
        self.assertEqual(self.invocations, [])

    def test_local_match_uses_no_runner_and_learns_pattern(self):
        self.cfg['local_patterns'] = True
        with patch('decomp_harness.workflow.runner_for', side_effect=AssertionError('No model')):
            self.process()
        self.assertEqual(self.state.get('target')['status'], 'matched')
        self.assertEqual(self.loop.calls, 0)
        self.assertEqual(summary(self.state)['open_functions'], 0)
        self.assertEqual(summary(self.state)['local_matches'], 1)
        self.assertEqual(summary(self.state)['learned_patterns'], 1)

    def test_local_only_failure_is_resumable_and_not_retried_forever(self):
        self.cfg['local_patterns'] = True
        self.allow_match = False
        self.loop.args.local_only = True
        with patch('decomp_harness.workflow.runner_for', side_effect=AssertionError('No model')):
            self.process()
            self.process()
        self.assertEqual(self.state.get('target')['status'], 'pending')
        self.assertEqual(self.state.db.execute("SELECT count(*) FROM runs WHERE kind='local'").fetchone()[0], 1)
        self.assertEqual(self.state.get('target')['attempts'], 0)


if __name__ == '__main__':
    unittest.main()
