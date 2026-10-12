import json
import subprocess
import sys
from unittest.mock import patch

import test_harness as fixtures
from test_harness import ASM, DUMP, SOURCE
from decomp_harness.build import LINK_OUTPUTS, Builder, object_path
from decomp_harness.cli import summary
from decomp_harness.codex import Result
from decomp_harness.common import Control, HarnessError, load_config
from decomp_harness.context import context_pack, worker_prompt
from decomp_harness.guard import extract_function, mark_targets, manifest, split_targets, verify_worker_changes
from decomp_harness.local_tools import m2c_candidate, m2c_candidates
from decomp_harness.matching import instructions, score, worth_rom_check
from decomp_harness.patterns import candidates, declarations, known_declarations, remember, transfer
from decomp_harness.scanner import scan
from decomp_harness.scheduler import next_function, resources

SYMBOLS = ('SYMBOL TABLE:\n'
           '00000000 l    d  .rodata\t00000140 .rodata\n'
           '00000068 g       .rodata\t00000000 R_80802948\n'
           '00000000         *UND*\t00000000 D_global\n\n')
NAMED = ('00000000 <target>:\n   0: 3c010000  lui at,0x0\n\t0: R_MIPS_HI16 R_80802948\n'
         '   4: c4280000  lwc1 $f8,0(at)\n\t4: R_MIPS_LO16 R_80802948\n'
         '   8: 03e00008  jr ra\n   c: 00000000  nop\n')
SECTION = NAMED.replace('R_80802948', '.rodata').replace('lwc1 $f8,0(at)', 'lwc1 $f8,104(at)')


def body(name, *rows):
    return f'glabel {name}\n' + ''.join(f'/* {0x1000+i*4:X} {0x80000400+i*4:08X} {word} */ {op}\n'
                                        for i, (word, op) in enumerate(rows)) + f'endlabel {name}\n'


class ScoreTests(fixtures.Fixture):
    def test_named_rodata_and_section_relocations_compare_by_offset(self):
        reference = instructions(SYMBOLS + NAMED, 'target')
        self.assertEqual(score(reference, instructions(SYMBOLS + SECTION, 'target'))['different_instructions'], 0)
        wrong = SECTION.replace('104(at)', '108(at)')
        self.assertEqual(score(reference, instructions(SYMBOLS + wrong, 'target'))['different_instructions'], 1)
        # Undefined (external) symbols keep their names.
        external = NAMED.replace('R_80802948', 'D_global')
        self.assertLess(score(instructions(SYMBOLS + external, 'target'), reference)['score'], 100)

    def test_alignment_padding_after_endlabel_is_ignored_only_beyond_length(self):
        padded = DUMP + '   8: 00000000  nop\n   c: 00000000  nop\n'
        self.assertEqual(len(instructions(padded, 'target', 2)), 2)
        self.assertEqual(len(instructions(padded, 'target')), 4)
        real = DUMP + '   8: 24020001  li v0,1\n'
        self.assertEqual(len(instructions(real, 'target', 2)), 3)

    def test_rom_check_gate(self):
        self.assertTrue(worth_rom_check({'different_instructions': 0, 'score': 100}))
        self.assertTrue(worth_rom_check({'different_instructions': 4, 'score': 99.4}))
        self.assertFalse(worth_rom_check({'different_instructions': 1, 'score': 66.7}))

    def test_baseline_object_is_saved_and_restored_inside_the_build_environment(self):
        """Host-side writes under build/ broke ld through Docker file sharing."""
        work = self.root/'work'
        (work/object_path('src/core1/a.c')).parent.mkdir(parents=True)
        (work/object_path('src/core1/a.c')).write_bytes(b'object')
        (work/'src/core1').mkdir(parents=True)
        builder = Builder(work, self.cfg, Control())
        calls = []
        builder.invoke = lambda args, log, network=False: calls.append(args) or 0
        self.assertTrue(builder.save_baseline('src/core1/a.c', self.root/'log'))
        builder.restore('src/core1/a.c', b'original', True, self.root/'log')
        obj = object_path('src/core1/a.c')
        self.assertEqual(calls[0], ['cp', '-p', obj, obj + '.baseline'])
        self.assertEqual(calls[1][-len(LINK_OUTPUTS)-2:], [obj + '.baseline', obj, *LINK_OUTPUTS])
        self.assertEqual((work/'src/core1/a.c').read_bytes(), b'original')
        self.assertEqual((work/obj).read_bytes(), b'object')  # Host never touched build/.
        builder.restore('src/core1/a.c', b'original', False, self.root/'log')
        self.assertEqual(calls[2], ['rm', '-f', obj, *LINK_OUTPUTS])
        builder.invoke = lambda *a, **k: 1
        with self.assertRaises(HarnessError):
            builder.restore('src/core1/a.c', b'original', True, self.root/'log')


class GuardTests(fixtures.Fixture):
    def test_batch_markers_split_and_reject_outside_changes(self):
        source = SOURCE + '#pragma GLOBAL_ASM("asm/nonmatchings/core1/a/second.s")\n'
        marked = mark_targets(source, ['target', 'second'])
        edited = marked.replace('#pragma GLOBAL_ASM("asm/nonmatchings/core1/a/second.s")', 'void second(void) {\n}')
        self.assertEqual(split_targets(source, edited, {'target', 'second'}), {'target': None, 'second': 'void second(void) {\n}'})
        for bad in (edited.replace('void other', 'void evil'), edited.replace('/* decomp-target-end second */', ''),
                    edited.replace('void second(void) {\n}', 'void second(void) {}\nint extra;')):
            with self.assertRaises(HarnessError):
                split_targets(source, bad, {'target', 'second'})

    def test_extract_function_skips_strings_comments_and_preprocessor(self):
        text = '#include "x.h"\n/* f(void) { */\nstatic char *s = "}";\ns32 *\nf(s32 a) {\n    if (a) { return 0; }\n    return s;\n}\nvoid g(void) {}\n'
        self.assertEqual(extract_function(text, 'f'), 's32 *\nf(s32 a) {\n    if (a) { return 0; }\n    return s;\n}')
        self.assertIsNone(extract_function(text, 'missing'))

    def test_ipc_directory_is_outside_the_worker_manifest(self):
        worker = self.root/'worker'
        (worker/'.decomp-ipc').mkdir(parents=True)
        (worker/'a.c').write_text('a')
        before = manifest(worker)
        (worker/'.decomp-ipc/request-1.c').write_text('x')
        verify_worker_changes(worker, before, 'a.c')


class TransferTests(fixtures.Fixture):
    SETTER_A = body('set_a', ('3C018012', 'lui $at, %hi(D_A)'), ('24020039', 'addiu $v0, $zero, 0x39'),
                    ('03E00008', 'jr $ra'), ('AC22E95C', 'sw $v0, %lo(D_A)($at)'))
    SETTER_B = body('set_b', ('3C018012', 'lui $at, %hi(D_B)'), ('24020012', 'addiu $v0, $zero, 0x12'),
                    ('03E00008', 'jr $ra'), ('AC22E960', 'sw $v0, %lo(D_B)($at)'))

    def test_transfer_renames_symbols_and_rewrites_integer_literals(self):
        code = 'void set_a(void) {\n    extern s32 D_A;\n    D_A = 0x39;\n}'
        self.assertEqual(transfer(code, self.SETTER_A, 'set_a', self.SETTER_B, 'set_b'),
                         'void set_b(void) {\n    extern s32 D_B;\n    D_B = 0x12;\n}')
        other = self.SETTER_B.replace('addiu $v0, $zero', 'addiu $v1, $zero')
        self.assertIsNone(transfer(code, self.SETTER_A, 'set_a', other.replace('addiu', 'ori'), 'set_b'))

    def test_solved_shape_group_yields_transfer_candidate_and_priority(self):
        folder = self.root/'asm/nonmatchings/core1/a'
        (folder/'set_a.s').write_text(self.SETTER_A)
        (folder/'set_b.s').write_text(self.SETTER_B)
        source = '#pragma GLOBAL_ASM("asm/nonmatchings/core1/a/set_a.s")\n#pragma GLOBAL_ASM("asm/nonmatchings/core1/a/set_b.s")\n'
        (self.root/'src/core1/set.c').write_text(source)
        self.state.sync(scan(self.root))
        a, b = self.state.get('set_a'), self.state.get('set_b')
        self.assertEqual(a['shape'], b['shape'])
        self.assertIn('shape:'+a['shape'], resources(a))
        self.state.update(a['id'], status='matched')
        remember(self.root, self.state, a, 'void set_a(void) {\n    extern s32 D_A;\n    D_A = 0x39;\n}', 'c0ffee')
        self.assertEqual(next_function(self.state)['id'], b['id'])  # Harvest first, before smaller target.
        found = list(candidates(self.root, b, self.state))
        self.assertIn(('transfer:set_a', 'void set_b(void) {\n    extern s32 D_B;\n    D_B = 0x12;\n}'), found)

    def test_old_matches_without_shape_still_seed_their_group(self):
        legacy = {**self.function, 'shape': None}
        remember(self.root, self.state, legacy, 'void target(void) { }', 'old')
        row = self.state.db.execute('SELECT shape FROM solutions WHERE function_id=?', (self.function['id'],)).fetchone()
        self.assertEqual(row['shape'], self.function['shape'])

    def test_unsolved_large_group_and_known_callees_go_first(self):
        folder = self.root/'asm/nonmatchings/core1/a'
        source = ''
        for name in ('g1', 'g2', 'g3'):
            (folder/f'{name}.s').write_text(self.SETTER_A.replace('set_a', name).replace('D_A', 'D_'+name))
            source += f'#pragma GLOBAL_ASM("asm/nonmatchings/core1/a/{name}.s")\n'
        (self.root/'src/core1/g.c').write_text(source)
        self.state.sync(scan(self.root))
        self.state.update(self.function['id'], size=4)
        self.assertIn(next_function(self.state)['symbol'], ('g1', 'g2', 'g3'))
        self.state.update(self.state.get('g1')['id'], status='blocked')
        self.assertEqual(next_function(self.state)['symbol'], 'target')


class ConcurrencyTests(fixtures.Fixture):
    def test_candidate_generation_holds_no_read_snapshot_across_writes(self):
        """Regression: a lazily iterated cursor made a later write fail after another
        connection committed (WAL SQLITE_BUSY_SNAPSHOT, "database is locked")."""
        from decomp_harness.state import State
        source = ''
        for value in (1, 2, 3):
            (self.root/f'asm/nonmatchings/core1/a/s{value}.s').write_text(
                body(f's{value}', ('03E00008', 'jr $ra'), (f'2402000{value}', f'addiu $v0, $zero, 0x{value}')))
            source += f'#pragma GLOBAL_ASM("asm/nonmatchings/core1/a/s{value}.s")\n'
        (self.root/'src/core1/s.c').write_text(source)
        self.state.sync(scan(self.root))
        # Two distinct stored solutions: Python's cursor reads one row ahead, so the statement stays open.
        remember(self.root, self.state, self.state.get('s1'), 's32 s1(void) { return 1; }', 'one')
        remember(self.root, self.state, self.state.get('s2'), 's32 s2(void) { return (2); }', 'two')
        other = State(self.root/'.decomp-agent/state.db')
        try:
            found = 0
            for origin, _ in candidates(self.root, self.state.get('s3'), self.state):
                other.note('tag', f'concurrent commit {origin} {found}', 'test')
                self.state.note('tag', f'own write {origin} {found}', 'test')
                found += 1
            self.assertGreaterEqual(found, 1)
        finally:
            other.close()


class DeclarationTests(fixtures.Fixture):
    CODE = ('void target(Actor* arg0) {\n    typedef struct { u8 pad[4]; } Local;\n    s32 func_800DA298(s32);\n'
            '    extern Local D_local;\n    extern f32 D_table[3];\n    return func_800DA298(1);\n}')

    def test_declarations_skip_local_types_and_statements(self):
        found = {name: (decl, definition) for name, decl, definition in declarations(self.CODE, 'target')}
        self.assertEqual(found['target'], ('void target(Actor* arg0);', 1))
        self.assertEqual(found['func_800DA298'][0], 's32 func_800DA298(s32);')
        self.assertEqual(found['D_table'][0], 'extern f32 D_table[3];')
        self.assertNotIn('D_local', found)

    def test_registry_reaches_the_context_pack(self):
        remember(self.root, self.state, self.function, self.CODE, 'abc')
        self.assertIn('s32 func_800DA298(s32);', known_declarations(self.state, ['func_800DA298']))
        self.state.update(self.function['id'], features=json.dumps({**json.loads(self.function['features']),
                                                                     'calls': ['func_800DA298']}))
        pack = context_pack(self.root, self.state.get('target'), self.state, self.cfg, draft='int m2c_draft;')
        self.assertIn('s32 func_800DA298(s32);  /* used by 1 matched */', pack)
        self.assertIn('Unverified m2c draft', pack)


class M2cTests(fixtures.Fixture):
    def test_clean_draft_moves_externs_inside_and_unknowns_are_rejected(self):
        draft = ('s32 func_A(?);  /* extern */\nextern ? D_X;\n\ns32 target(s32 arg0) {\n'
                 '    return func_A(arg0) + D_X;\n}\n')
        self.assertEqual(m2c_candidate(draft, 'target'),
                         's32 target(s32 arg0) {\n    s32 func_A();\n    extern s32 D_X;\n    return func_A(arg0) + D_X;\n}')
        self.assertIsNone(m2c_candidate(draft.replace('return', '? x;\n    return'), 'target'))
        self.assertIsNone(m2c_candidate('static ? sp;\n' + draft, 'target'))

    def test_valid_syntax_macros_expand_to_plain_c(self):
        draft = ('extern M2C_UNK D_X;\n\nvoid target(void *arg0) {\n'
                 '    M2C_FIELD(M2C_FIELD(arg0, void **, 0xBC), s8 *, 0x19) = M2C_BITWISE(s32, D_X);\n}\n')
        self.assertEqual(m2c_candidate(draft, 'target'),
                         'void target(void *arg0) {\n    extern s32 D_X;\n'
                         '    (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0xBC)))) + (0x19))) = ((s32)(D_X));\n}')
        self.assertIsNone(m2c_candidate(draft.replace('M2C_BITWISE(s32, D_X)', 'M2C_ERROR(/* unknown */)'), 'target'))
        plain, bytes_ = m2c_candidates(draft, 'target')
        self.assertIn('void *arg0', plain)
        self.assertIn('u8 *arg0', bytes_)
        self.assertEqual(len(m2c_candidates('s32 target(s32 a) {\n    return a;\n}\n', 'target')), 1)


class LoopFixture(fixtures.LoopTests):
    """LoopTests setup without re-running its test methods."""
    def setUp(self):
        super().setUp()
        self.cfg['m2c'] = False
        self.cfg['permuter_seconds'] = 0


for _name in [n for n in dir(fixtures.LoopTests) if n.startswith('test_')]:
    setattr(LoopFixture, _name, None)


class AcceleratedLoopTests(LoopFixture):
    def test_nonmatching_candidate_skips_full_rom_check(self):
        calls = []
        self.loop.builder.disassemble = lambda source, symbol: (
            DUMP.replace('nop', 'li v0,1') if 'void target' in (self.work/source).read_text() else DUMP)
        self.loop.builder.regression = lambda *_: calls.append(1) or False
        self.loop.args.max_attempts = 1
        self.process()
        self.assertEqual(calls, [])
        self.assertEqual(self.state.get('target')['best_score'], 50)

    def test_compile_service_answers_worker_requests(self):
        replies = []
        owner = self

        class CompilingRunner:
            redact = staticmethod(lambda text: text)

            def run(self, **kw):
                cwd = kw['cwd']
                (cwd/'src/core1/a.c').write_text(fixtures.CANDIDATE.replace('{ }', '{ return; }'))
                replies.append(subprocess.run([sys.executable, str(cwd/'decomp-compile')], capture_output=True, text=True, timeout=30).stdout)
                (cwd/'src/core1/a.c').write_text(fixtures.CANDIDATE.replace('void other', 'void evil'))
                replies.append(subprocess.run([sys.executable, str(cwd/'decomp-compile')], capture_output=True, text=True, timeout=30).stdout)
                secret = owner.root/'secret.txt'
                secret.write_text('TOP-SECRET')
                (cwd/'.decomp-ipc/request-9.c').symlink_to(secret)
                answer = cwd/'.decomp-ipc/response-9.txt'
                for _ in range(100):
                    if answer.exists():
                        break
                    __import__('time').sleep(0.05)
                replies.append(answer.read_text())
                (cwd/'src/core1/a.c').write_text(fixtures.CANDIDATE)
                return Result(0, 'ok', usage={'input_tokens': 5}, message={'status': 'candidate', 'knowledge': []})

        with patch('decomp_harness.workflow.CodexRunner', CompilingRunner):
            self.loop.runners = {}
            self.process()
        self.assertIn('OBJECT MATCH', replies[0])
        self.assertIn('Rejected before compiling', replies[1])
        self.assertIn('Internal harness error', replies[2])
        self.assertNotIn('TOP-SECRET', ''.join(replies))
        self.assertEqual(self.state.get('target')['status'], 'matched')
        self.assertEqual((self.work/'src/core1/a.c').read_text(), fixtures.CANDIDATE.replace('{ }', '{ return; }'))

    def test_prompt_names_compile_loop_and_batch_markers(self):
        prompt = worker_prompt(self.function, 'pack', 12, [{'symbol': 'second'}])
        self.assertIn('./decomp-compile', prompt)
        self.assertIn('decomp-target-begin', prompt)
        self.assertIn('Do not resubmit a tested failed source patch', prompt)
        self.assertNotIn('./decomp-compile', worker_prompt(self.function, 'pack', 0))

    def test_permuter_near_miss_matches_without_another_model_run(self):
        self.cfg['permuter_seconds'] = 5
        self.cfg['permuter_min_score'] = 50
        self.loop.builder.disassemble = lambda source, symbol: (
            DUMP if 'permuted' in (self.work/source).read_text() or 'void target' not in (self.work/source).read_text()
            else DUMP.replace('nop', 'li v0,1'))
        found = (0, 'void target(void) { /* permuted */ }')
        with patch('decomp_harness.workflow.run_permuter', return_value=found) as permuter:
            self.process()
        permuter.assert_called_once()
        self.assertEqual(self.state.get('target')['status'], 'matched')
        self.assertEqual(len(self.invocations), 1)
        self.assertEqual(summary(self.state)['local_matches'], 1)

    def test_local_only_sweep_uses_m2c_without_models(self):
        self.cfg['m2c'] = True
        self.cfg['local_patterns'] = True
        self.loop.args.local_only = True
        (self.work/'tools/m2c').mkdir(parents=True)
        (self.work/'tools/m2c/m2c.py').write_text('')
        with patch('decomp_harness.workflow.m2c_draft', return_value='void target(void) {\n    return;\n}\n') as draft, \
             patch('decomp_harness.workflow.untried_candidates', return_value=iter(())), \
             patch('decomp_harness.workflow.runner_for', side_effect=AssertionError('No model')):
            self.process()
        draft.assert_called_once()
        self.assertEqual(self.state.get('target')['status'], 'matched')

    def test_m2c_candidate_matches_before_any_model(self):
        self.cfg['m2c'] = True
        self.cfg['local_patterns'] = True
        draft = 'void target(void) {\n}\n'
        with patch('decomp_harness.workflow.m2c_draft', return_value=draft), \
             patch('decomp_harness.workflow.untried_candidates', return_value=iter(())):
            self.process()
        self.assertEqual(self.state.get('target')['status'], 'matched')
        self.assertEqual(self.invocations, [])


class LocalSweepM2cTests(fixtures.Fixture):
    def test_local_plan_includes_untranslated_functions_once_per_context(self):
        from decomp_harness.patterns import local_plan, m2c_key
        self.assertEqual(local_plan(self.root, self.state)['eligible_functions'], 1)  # jr/nop template
        with patch('decomp_harness.patterns.untried_candidates', return_value=iter(())):
            self.assertEqual(local_plan(self.root, self.state)['eligible_functions'], 0)
        with patch('decomp_harness.patterns.untried_candidates', return_value=iter(())):
            plan = local_plan(self.root, self.state, m2c=True)['plan']
        self.assertEqual(plan[0]['origins'], ['m2c'])
        with self.state.db:
            self.state.db.execute('INSERT INTO local_trials VALUES (?,?,?)',
                                  (self.function['id'], m2c_key(self.function, SOURCE), 'm2c-done'))
        with patch('decomp_harness.patterns.untried_candidates', return_value=iter(())):
            self.assertEqual(local_plan(self.root, self.state, m2c=True)['eligible_functions'], 0)
            changed = SOURCE + 'void more(void) {}\n'
            (self.root/'src/core1/a.c').write_text(changed)
            self.assertEqual(local_plan(self.root, self.state, m2c=True)['eligible_functions'], 1)


class BatchLoopTests(LoopFixture):
    def setUp(self):
        super().setUp()
        self.cfg['easy_model']['enabled'] = True
        source = SOURCE + '#pragma GLOBAL_ASM("asm/nonmatchings/core1/a/second.s")\n'
        for root in (self.root, self.work):
            (root/'src/core1/a.c').write_text(source)
            (root/'asm/nonmatchings/core1/a/second.s').write_text(ASM.replace('target', 'second'))
        self.git('add', 'src')
        self.git('commit', '-qm', 'second target')
        self.state.sync(scan(self.root))
        self.loop.builder.disassemble = lambda source, symbol: DUMP.replace('target', symbol)
        self.seen_prompts = []
        owner = self

        class BatchRunner:
            redact = staticmethod(lambda text: text)

            def run(self, **kw):
                owner.seen_prompts.append(kw['prompt'])
                path = kw['cwd']/'src/core1/a.c'
                text = path.read_text()
                symbols = ('target', 'second') if len(owner.seen_prompts) == 1 else ('target',)
                for symbol in symbols:
                    text = text.replace(f'#pragma GLOBAL_ASM("asm/nonmatchings/core1/a/{symbol}.s")', f'void {symbol}(void) {{ }}')
                path.write_text(text)
                return Result(0, 'ok', usage={'input_tokens': 5}, message={'status': 'candidate', 'knowledge': []})

        self.patches.append(patch('decomp_harness.workflow.CodexRunner', BatchRunner))
        self.patches[-1].start()
        self.loop.runners = {}

    def test_one_session_publishes_each_target_separately(self):
        self.process()
        self.assertEqual(len(self.seen_prompts), 1)
        self.assertIn('second', self.seen_prompts[0])
        self.assertEqual({self.state.get('target')['status'], self.state.get('second')['status']}, {'matched'})
        self.assertEqual(self.git('rev-list', '--count', 'HEAD'), '4')
        final = (self.root/'src/core1/a.c').read_text()
        self.assertNotIn('decomp-target', final)
        self.assertIn('void second(void) { }', final)
        self.assertEqual(self.loop.matched, 2)

    def test_failed_companion_is_escalated_and_released(self):
        self.allow_match = False
        self.loop.args.max_attempts = 1
        self.process()
        second = self.state.get('second')
        self.assertEqual((second['status'], second['cycle_attempts'], second['initial_done']), ('pending', 1, 1))

    def test_failed_batch_target_retries_on_published_companion(self):
        def object_build(source, log):
            if len(self.seen_prompts) == 1 and 'void target' in (self.work/source).read_text():
                log.write_text('Batch target did not compile')
                return 1
            return 0

        self.loop.builder.object_build = object_build
        with patch.object(self.loop, 'try_permuter', wraps=self.loop.try_permuter) as permuter:
            self.process()
        self.assertEqual(len(self.seen_prompts), 2)
        self.assertEqual({self.state.get('target')['status'], self.state.get('second')['status']}, {'matched'})
        self.assertEqual(self.git('rev-list', '--count', 'HEAD'), '4')
        self.assertEqual(self.loop.matched, 2)
        final = (self.root/'src/core1/a.c').read_text()
        self.assertIn('void target(void) { }', final)
        self.assertIn('void second(void) { }', final)
        self.assertEqual((self.work/'src/core1/a.c').read_text(), final)
        self.assertIn(b'void second(void) { }', permuter.call_args.args[0].original)
        history = self.state.history(self.function['id'])
        self.assertEqual({r['outcome'] for r in history}, {'compile_error', 'matched'})

    def test_batch_retry_discards_candidate_based_on_old_source(self):
        def disassemble(source, symbol):
            dump = DUMP.replace('target', symbol)
            if len(self.seen_prompts) == 1 and symbol == 'target' and 'void target' in (self.work/source).read_text():
                return dump.replace('nop', 'li v0,1')
            return dump

        self.loop.builder.disassemble = disassemble
        self.process()
        self.assertEqual(len(self.seen_prompts), 2)
        self.assertEqual({self.state.get('target')['status'], self.state.get('second')['status']}, {'matched'})
        self.assertIn(b'void second(void) { }', self.state.get('target')['best_source'])
        self.assertEqual({r['outcome'] for r in self.state.history(self.function['id'])}, {'nonmatching', 'matched'})

    def test_batch_retry_preserves_user_edits(self):
        self.allow_match = False
        finish_batch = self.loop.finish_batch
        edited = (self.root/'src/core1/a.c').read_text() + '\n/* user edit */\n'

        def edit_after_batch(*args, **kwargs):
            finish_batch(*args, **kwargs)
            (self.root/'src/core1/a.c').write_text(edited)

        with patch.object(self.loop, 'finish_batch', side_effect=edit_after_batch):
            self.process()
        self.assertEqual(len(self.seen_prompts), 1)
        self.assertEqual(self.state.get('target')['status'], 'blocked')
        self.assertIn('Uncommitted target changes', self.state.get('target')['last_error'])
        self.assertEqual((self.root/'src/core1/a.c').read_text(), edited)
        self.assertEqual(self.git('rev-list', '--count', 'HEAD'), '2')


class ConfigTests(fixtures.Fixture):
    def test_new_keys_are_validated(self):
        path = self.root/'.decomp-agent/config.toml'
        for line in ('batch_size = 0', 'permuter_min_score = 101', 'm2c = "yes"', 'worker_compiles = -1'):
            path.write_text(line + '\n')
            with self.assertRaises(HarnessError):
                load_config(self.root)
        path.write_text('worker_compiles = 0\npermuter_seconds = 0\n')
        self.assertEqual(load_config(self.root)['worker_compiles'], 0)


if __name__ == '__main__':
    import unittest
    unittest.main()
