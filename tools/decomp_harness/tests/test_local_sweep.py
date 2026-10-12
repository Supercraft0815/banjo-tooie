import hashlib
import io
import json
from pathlib import Path
import shutil
import tempfile
import unittest
from contextlib import redirect_stdout
from types import SimpleNamespace
from unittest.mock import patch

from test_harness import Fixture, ASM, SOURCE
from test_optimizations import assembly
from decomp_harness import cache
from decomp_harness.cli import dry_run, parser
from decomp_harness.common import Control, HarnessError
from decomp_harness.patterns import (candidate_source, local_plan, pattern_key,
                                    replacements, trial_key)
from decomp_harness.scanner import scan
from decomp_harness.workflow import Loop

JUMP = (0x03E00008, 'jr $ra')
ADDRESS = assembly((0x3C028012, 'lui $v0,%hi(D_global)'), JUMP,
                   (0x24427110, 'addiu $v0,$v0,%lo(D_global)'))


class RecipeTests(Fixture):
    def test_symbolic_address_and_padding_outside_function(self):
        padded = ADDRESS+'/* 100C 8000040C 00000000 */ nop\n'
        code, = replacements(padded, 'target')
        self.assertIn('extern u8 D_global;', code)
        self.assertIn('return &D_global;', code)
        self.assertEqual(pattern_key(ADDRESS, 'target'), pattern_key(padded, 'target'))
        self.assertEqual(replacements(ADDRESS.replace('%lo(D_global)', '%lo(other)'), 'target'), [])
        self.assertEqual(replacements(ADDRESS.replace('24427110', '24627110'), 'target'), [])

    def test_reuse_typed_declaration_but_not_function_local_declaration(self):
        code, = replacements(ADDRESS, 'target', 'extern s32 D_global;\n'+SOURCE)
        self.assertNotIn('extern u8', code)
        for text in ('void sibling(void) { extern s32 D_global; }',
                     '/* extern s32 D_global; */', 'const char *s="D_global";'):
            code, = replacements(ADDRESS, 'target', text+'\n'+SOURCE)
            self.assertIn('extern u8 D_global;', code)

    def test_global_access_and_indexed_table(self):
        code, = replacements(assembly((0x3C018012, 'lui $at,%hi(D_global)'), JUMP,
                                      (0xA0247000, 'sb $a0,%lo(D_global)($at)')), 'target')
        self.assertIn('*(s8 *)((u8 *)&D_global + 0) = arg0;', code)
        table = assembly((0x00047080, 'sll $t6,$a0,2'),
                         (0x3C028008, 'lui $v0,%hi(D_global)'),
                         (0x004E1021, 'addu $v0,$v0,$t6'), JUMP,
                         (0x8C42E95C, 'lw $v0,%lo(D_global)($v0)'))
        code, = replacements(table, 'target')
        self.assertIn('return ((s32 *)&D_global)[arg0];', code)
        self.assertEqual(replacements(table.replace('00047080', '00047040'), 'target'), [])
        self.assertEqual(replacements(table.replace('8C42E95C', '8C62E95C'), 'target'), [])

    def test_nested_pointer_and_float_argument(self):
        pointer = (0x8C8E0050, 'lw $t6,0x50($a0)')
        code, = replacements(assembly(pointer, JUMP, (0x91C20017, 'lbu $v0,0x17($t6)')), 'target')
        self.assertIn('*(void **)((u8 *)arg0 + 80)', code)
        self.assertIn(' + 23)', code)
        code, = replacements(assembly((0x44856000, 'mtc1 $a1,$f12'), pointer, JUMP,
                                      (0xE5CC00C8, 'swc1 $f12,0xc8($t6)')), 'target')
        self.assertIn('void *arg0, f32 arg1', code)
        self.assertIn(' + 200) = arg1;', code)
        self.assertEqual(replacements(assembly(pointer, JUMP,
                                    (0xA1C40014, 'sb $a0,0x14($t6)')), 'target'), [])


class LocalSweepTests(Fixture):
    def args(self, *extra):
        return parser().parse_args(['run', '--local-only', *extra])

    def test_unbounded_dry_scan_skips_unsupported_and_attempted_without_models(self):
        source = self.root/self.function['source']
        source.write_text(SOURCE+'\n#pragma GLOBAL_ASM("asm/nonmatchings/core1/a/second.s")\n')
        second = self.root/'asm/nonmatchings/core1/a/second.s'
        second.write_text(ASM.replace('target', 'second'))
        self.state.sync(scan(self.root))
        with patch('decomp_harness.workflow.runner_for', side_effect=AssertionError('No model')):
            result = dry_run(self.root, self.state, self.cfg, self.args('--dry-run'))
        self.assertEqual(result['eligible_functions'], 2)
        self.assertEqual(len(result['plan']), 2)
        code, = replacements(ASM, 'target')
        candidate = candidate_source(source.read_text(), 'target', code)
        self.state.db.execute('INSERT INTO local_trials VALUES (?,?,?)',
                              (self.function['id'], trial_key(candidate, self.function), 'improve'))
        self.state.db.commit()
        second.write_text(assembly((0x10000001, 'b .Lx'), (0, 'nop')).replace('target', 'second'))
        self.state.sync(scan(self.root))
        plan = local_plan(self.root, self.state)
        self.assertEqual(plan['scanned_functions'], 2)
        self.assertEqual(plan['eligible_functions'], 0)

    def test_empty_plan_exits_before_snapshot_build_or_auth(self):
        (self.root/self.function['asm']).write_text(assembly((0x10000001, 'b .Lx'), (0, 'nop')))
        loop = Loop(self.root, self.state, self.cfg, Control(), self.args())
        with patch('decomp_harness.workflow.cache.prepare', side_effect=AssertionError('No build')), \
             patch('decomp_harness.workflow.runner_for', side_effect=AssertionError('No model')), redirect_stdout(io.StringIO()):
            result = loop.run()
        self.assertEqual((result['functions'], result['model_worker_runs']), (0, 0))
        self.assertEqual(self.state.get('target')['status'], 'pending')

    def test_crash_candidate_stays_in_plan_even_without_recipe(self):
        (self.root/self.function['asm']).write_text(assembly((0x10000001, 'b .Lx'), (0, 'nop')))
        self.state.sync(scan(self.root))
        self.state.update(self.function['id'], base_sha=hashlib.sha256(SOURCE.encode()).hexdigest())
        directory = self.root/'.decomp-agent/runs/recovered'
        directory.mkdir(parents=True)
        (directory/'source-after.c').write_text('candidate to be guarded by resume_candidate')
        run = self.state.start_run(self.function['id'], 'local', 'template', 'none', directory)
        self.state.finish_run(run, outcome='interrupted')
        self.assertTrue(local_plan(self.root, self.state)['plan'][0]['resume'])

    def test_selection_counts_candidates_and_respects_file_locks_and_external_stop(self):
        loop = Loop(self.root, self.state, self.cfg, Control(), self.args('--max-functions', '1'))
        loop.local_queue = local_plan(self.root, self.state)['plan']
        self.assertIsNone(loop.select_function(set(), {self.function['source']}))
        self.assertEqual(loop.select_function(set())['id'], self.function['id'])
        marker = self.root/'.decomp-agent/stop-after-current'
        marker.write_text('stop')
        self.assertIsNone(loop.select_function(set()))  # Also before the first function.
        marker.unlink()
        loop.examined = 1
        self.assertIsNone(loop.select_function(set()))

    def test_warm_run_still_checks_full_rom_and_interruption_does_not_retain(self):
        for interrupted in (False, True):
            loop = Loop(self.root, self.state, self.cfg, Control(), self.args())
            work = Path(tempfile.mkdtemp())
            def finish():
                loop.control.cancelled = interrupted
            with patch('decomp_harness.workflow.cache.prepare', return_value=(work, True)), \
                 patch('decomp_harness.workflow.cache.retain') as retain, \
                 patch('decomp_harness.workflow.verify_rom'), \
                 patch('decomp_harness.workflow.git', return_value='decomp'), \
                 patch('decomp_harness.workflow.repository_stamp', return_value={'head': 'stable'}), \
                 patch('decomp_harness.workflow.Builder') as builder, \
                 patch.object(loop, 'process_queue', side_effect=finish), redirect_stdout(io.StringIO()):
                builder.return_value.regression.return_value = True
                loop.run()
                builder.return_value.regression.assert_called_once()
                self.assertEqual(retain.call_count, 0 if interrupted else 1)
            self.assertFalse(work.exists())


class BuildCacheTests(Fixture):
    def setUp(self):
        super().setUp()
        for name in ('baserom.us.z64', 'decompressed.us.z64'):
            (self.root/name).write_bytes(b'fixture ROM; no compiler in this test')
        self.command = patch('decomp_harness.cache.command', return_value=SimpleNamespace(stdout=b'sha256:test-image'))
        self.command.start()
        self.addCleanup(self.command.stop)
        self.addCleanup(self.clean_work)
        self.work = None

    def clean_work(self):
        if self.work and self.work.exists():
            shutil.rmtree(self.work)

    def seed(self):
        self.work, warm = cache.prepare(self.root, self.cfg)
        self.assertFalse(warm)
        (self.work/'build/us/test.o').write_bytes(b'compiled object')
        cache.retain(self.root, self.work, self.cfg)
        self.assertFalse(self.work.exists())

    def test_reuse_content_checked_artifacts_and_ignore_submodule_git_files(self):
        (self.root/'src/.git').write_text('gitdir: private')
        self.seed()
        self.work, warm = cache.prepare(self.root, self.cfg)
        self.assertTrue(warm)
        self.assertEqual((self.work/'build/us/test.o').read_bytes(), b'compiled object')

    def test_reject_changed_source_even_with_same_timestamp(self):
        self.seed()
        import os
        source = self.root/self.function['source']
        stamp = source.stat()
        source.write_text(SOURCE+'/* changed */')
        os.utime(source, ns=(stamp.st_atime_ns, stamp.st_mtime_ns))
        self.work, warm = cache.prepare(self.root, self.cfg)
        self.assertFalse(warm)
        self.assertFalse((self.work/'build/us/test.o').exists())

    def test_reject_tampered_artifact_and_invalid_metadata(self):
        self.seed()
        record = self.root/'.decomp-agent/build-cache/current.json'
        cached = cache.cache_path(self.root, json.loads(record.read_text()))
        (cached/'build/us/test.o').write_bytes(b'tampered')
        self.work, warm = cache.prepare(self.root, self.cfg)
        self.assertFalse(warm)
        self.clean_work()
        record.write_text('null')
        self.work, warm = cache.prepare(self.root, self.cfg)
        self.assertFalse(warm)
        self.assertTrue(cached.exists())

    def test_different_toolchain_and_disabled_cache_force_fresh_build(self):
        self.seed()
        with patch('decomp_harness.cache.command', return_value=SimpleNamespace(stdout=b'sha256:other')):
            self.work, warm = cache.prepare(self.root, self.cfg)
        self.assertFalse(warm)
        self.clean_work()
        self.cfg['build_cache'] = False
        with patch('decomp_harness.cache.input_key', side_effect=AssertionError('Disabled')):
            self.work, warm = cache.prepare(self.root, self.cfg)
            cache.retain(self.root, self.work, self.cfg)
        self.assertFalse(warm)
        self.assertTrue(self.work.exists())

    def test_never_retain_changed_snapshot_inputs(self):
        self.work, _ = cache.prepare(self.root, self.cfg)
        (self.work/self.function['source']).write_text('modified copied input')
        cache.retain(self.root, self.work, self.cfg)
        self.assertFalse((self.root/'.decomp-agent/build-cache/current.json').exists())
        self.assertTrue(self.work.exists())

    def test_cache_path_cannot_escape_repository_or_follow_link(self):
        for name in ('../outside', '/build-outside', 'build-../outside'):
            with self.assertRaises(HarnessError):
                cache.cache_path(self.root, {'directory': name})
        self.seed()
        record = self.root/'.decomp-agent/build-cache/current.json'
        path = cache.cache_path(self.root, json.loads(record.read_text()))
        (path/'.harness-snapshot').write_text('/other/repository')
        self.work, warm = cache.prepare(self.root, self.cfg)
        self.assertFalse(warm)

    def test_linked_artifacts_and_native_toolchain_are_not_reused(self):
        self.seed()
        record = self.root/'.decomp-agent/build-cache/current.json'
        path = cache.cache_path(self.root, json.loads(record.read_text()))
        (path/'build/us/link.o').symlink_to(self.root/self.function['source'])
        self.work, warm = cache.prepare(self.root, self.cfg)
        self.assertFalse(warm)
        self.clean_work()
        self.cfg['build']['backend'] = 'native'
        with patch('decomp_harness.cache.input_key', side_effect=AssertionError('Native toolchain not pinned')):
            self.work, warm = cache.prepare(self.root, self.cfg)
            cache.retain(self.root, self.work, self.cfg)
        self.assertFalse(warm)
        self.assertTrue(self.work.exists())

    def test_all_cached_files_are_verified_including_hidden_and_generated_code(self):
        self.seed()
        record = self.root/'.decomp-agent/build-cache/current.json'
        path = cache.cache_path(self.root, json.loads(record.read_text()))
        for name in ('tools/__pycache__/injected.pyc', '.codex/config.toml', 'lib/.git'):
            injected = path/name
            injected.parent.mkdir(parents=True, exist_ok=True)
            injected.write_bytes(b'previously absent content')
            self.work, warm = cache.prepare(self.root, self.cfg)
            self.assertFalse(warm, name)
            self.clean_work()
            injected.unlink()


class QuirkVariantTests(unittest.TestCase):
    """Variants follow from the saved diff; each is only a candidate for the compiler."""
    CODE = 's32 target(s32 *arg0) {\n    s32 value;\n\n    value = arg0[1];\n    return other(value);\n}'

    @staticmethod
    def diff(expected, actual):
        return {'diffs': [{'expected': [{'asm': a} for a in expected], 'actual': [{'asm': a} for a in actual]}]}

    def variants(self, expected, actual, code=None):
        from decomp_harness.local_tools import quirk_variants
        return dict(quirk_variants(code or self.CODE, 'target', self.diff(expected, actual)))

    def test_reordered_instructions_try_the_one_line_layout(self):
        got = self.variants(['move a0,a1', 'sw ra,20(sp)'], ['sw ra,20(sp)', 'move a0,a1'])
        self.assertEqual(got, {'quirk:one-line': 's32 target(s32 *arg0) { s32 value; value = arg0[1]; return other(value); }'})

    def test_extra_result_move_tries_int_and_small_frame_tries_padding(self):
        got = self.variants(['addiu sp,sp,-40'], ['addiu sp,sp,-32', 'move v0,v1'])
        self.assertTrue(got['quirk:int-return'].startswith('int target('))
        self.assertIn('{\n    s32 pad[2];\n    s32 value;', got['quirk:pad2-first'])
        self.assertIn('s32 value;\n    s32 pad[2];\n\n', got['quirk:pad2-last'])
        self.assertIn('s32 pad;', got['quirk:pad1-first'])

    def test_m2c_scalar_buffer_and_hex_float_arguments_are_retyped(self):
        code = ('void target(u8 *arg0) {\n    s32 set(s32 *, s32, s32);\n    s32 unknown();\n    s32 sp2C;\n\n'
                '    set(&sp2C, 0, 0x42200000);\n    unknown(0x3F800000);\n}')
        got = self.variants(['addiu sp,sp,-48'], ['addiu sp,sp,-40'], code)
        self.assertIn('s32 sp2C[3];\n\n    set(sp2C, 0, 0x42200000);', got['quirk:array3-sp2C'])
        self.assertIn('s32 set(s32 *, s32, f32);', got['quirk:float-args'])
        self.assertIn('set(&sp2C, 0, 40.0f);', got['quirk:float-args'])
        self.assertIn('s32 set(s32 *, f32, f32);', got['quirk:float-args-zero'])
        self.assertIn('set(&sp2C, 0.0f, 40.0f);', got['quirk:float-args-zero'])
        # An unprototyped callee would promote the float to double: left alone.
        self.assertIn('unknown(0x3F800000);', got['quirk:float-args-zero'])

    def test_unrelated_differences_produce_nothing(self):
        self.assertEqual(self.variants(['lw v0,0(a0)'], ['lh v0,0(a0)']), {})
        self.assertEqual(self.variants(['addiu sp,sp,-32'], ['addiu sp,sp,-40']), {})

