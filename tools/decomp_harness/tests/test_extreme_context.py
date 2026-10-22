import stat

from test_harness import Fixture
from decomp_harness.common import HarnessError
from decomp_harness.context import context_pack
from decomp_harness.guard import dispose_worker, manifest, referenced_data, verify_worker_changes, worker_copy


class ExtremeContextTests(Fixture):
    def setUp(self):
        super().setUp()
        (self.root/'include').mkdir()
        (self.root/'lib/ultralib/include').mkdir(parents=True)
        self.asm = self.root/self.function['asm']
        self.asm.write_text(self.asm.read_text() + '\n'
                            'lui $t0, %hi(jtbl_target)\n'
                            'lw $t0, %lo(jtbl_target)($t0)\n'
                            'lwc1 $f0, %lo(D_constant+4)($t1)\n')
        self.relative = 'asm/data/core1/referenced.rodata.s'
        self.data = self.root/self.relative
        self.data.parent.mkdir(parents=True)
        self.data.write_text('.section .rodata\n'
                             'dlabel jtbl_target\n.word .L80000400\n.word .L80000404\n'
                             'dlabel D_constant\n.float 0.4\n.float 0.8\n')
        (self.data.parent/'unrelated.rodata.s').write_text('dlabel jtbl_target_longer\n.word 0\n')
        (self.root/'decompressed.us.z64').write_bytes(b'private ROM')

    def test_referenced_data_only_selects_exact_defined_symbols(self):
        self.assertEqual(referenced_data(self.root, self.asm.read_text()),
                         {self.relative: ['D_constant', 'jtbl_target']})
        self.assertEqual(referenced_data(self.root, 'jr $ra\n'), {})
        self.assertEqual(referenced_data(self.root, 'lui $t0,%hi(missing)\n'), {})
        (self.data.parent/'alias.rodata.s').symlink_to(self.data)
        self.assertEqual(list(referenced_data(self.root, self.asm.read_text())), [self.relative])

    def test_missing_data_file_or_directory_does_not_prevent_context(self):
        self.data.unlink()
        (self.data.parent/'unrelated.rodata.s').unlink()
        self.data.parent.rmdir()
        self.data.parent.parent.rmdir()
        self.assertEqual(referenced_data(self.root, self.asm.read_text()), {})
        pack = context_pack(self.root, self.function, self.state, self.cfg)
        self.assertNotIn('Referenced read-only ASM data', pack)

    def test_worker_data_is_read_only_and_manifest_guarded_in_both_modes(self):
        for worktree in (False, True):
            with self.subTest(worktree=worktree):
                worker = worker_copy(self.root, self.function, worktree=worktree)
                try:
                    copied = worker/self.relative
                    self.assertEqual(copied.read_bytes(), self.data.read_bytes())
                    self.assertEqual(stat.S_IMODE(copied.stat().st_mode), 0o444)
                    self.assertFalse((worker/'decompressed.us.z64').exists())
                    self.assertEqual([p.relative_to(worker).as_posix() for p in (worker/'asm/data').rglob('*.s')],
                                     [self.relative])
                    before = manifest(worker)
                    self.assertEqual(verify_worker_changes(worker, before, self.function['source']), set())
                    copied.chmod(0o644)
                    copied.write_text('dlabel jtbl_target\n.word 0\n')
                    copied.chmod(0o444)
                    with self.assertRaisesRegex(HarnessError, 'Worker changed forbidden files'):
                        verify_worker_changes(worker, before, self.function['source'])
                finally:
                    dispose_worker(worker)

    def test_context_indexes_data_and_does_not_claim_one_compiler_profile(self):
        pack = context_pack(self.root, self.function, self.state, self.cfg)
        self.assertIn(f'{self.relative}: D_constant, jtbl_target', pack)
        self.assertNotIn('unrelated.rodata.s', pack)
        self.assertIn('Makefile-selected IDO version and flags for this source', pack)
        self.assertNotIn('Compiler: IDO 5.3, -O2', pack)
        self.assertLessEqual(len(pack), self.cfg['context_chars'])
