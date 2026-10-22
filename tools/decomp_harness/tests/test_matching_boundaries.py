import unittest

from decomp_harness.matching import instructions, score


DUMP = '''SYMBOL TABLE:
00000020 g     F .text	00000018 target
00000028 l       .text	00000000 .Lcase
0000002c g     F .text	00000000 exported_alias
00000038 g     F .text	00000008 next_function

Disassembly of section .text:
00000020 <target>:
 20: 10800003 beqz a0,30 <exported_alias+0x4>
 24: 00000000 nop
00000028 <.Lcase>:
 28: 3c020000 lui v0,0x0
 28: R_MIPS_HI16 global
0000002c <exported_alias>:
 2c: 24420000 addiu v0,v0,0
 2c: R_MIPS_LO16 global
 30: 03e00008 jr ra
 34: 00000000 nop
00000038 <next_function>:
 38: 03e00008 jr ra
 3c: 00000000 nop
'''


class FunctionBoundaryTests(unittest.TestCase):
    def test_internal_local_and_global_labels_do_not_truncate_function(self):
        rows = instructions(DUMP, 'target', 6)
        self.assertEqual([row['offset'] for row in rows], list(range(0, 24, 4)))
        self.assertEqual(rows[0]['asm'], 'beqz a0,@+10')
        self.assertEqual(rows[2]['relocs'], ['R_MIPS_HI16 global'])
        self.assertEqual(rows[3]['relocs'], ['R_MIPS_LO16 global'])
        no_labels = DUMP.replace('00000028 <.Lcase>:\n', '').replace('0000002c <exported_alias>:\n', '')
        self.assertTrue(score(rows, instructions(no_labels, 'target', 6))['object_identical'])

    def test_expected_length_does_not_hide_longer_compiled_function(self):
        for extra in ('li v0,1', 'move v0,a0'):
            with self.subTest(extra=extra):
                larger = DUMP.replace('00000018 target', '0000001c target').replace('00000038 g     F', '0000003c g     F').replace(
                    '0000002c g     F .text\t00000000 exported_alias',
                    '0000002c g     F .text\t00000000 exported_alias\n00000038 g     F .text\t00000000 extra_label').replace(
                    '00000038 <next_function>:\n', '00000038 <extra_label>:\n')
                larger = larger.replace(' 38: 03e00008 jr ra', ' 38: 00000000 '+extra)
                reference = instructions(DUMP, 'target', 6)
                candidate = instructions(larger, 'target', 6)
                self.assertEqual(len(candidate), 7)
                self.assertLess(score(reference, candidate)['score'], 100)

    def test_missing_symbol_size_preserves_conservative_label_boundary(self):
        no_size = DUMP.replace('00000018 target', '00000000 target')
        self.assertEqual(len(instructions(no_size, 'target', 6)), 3)


if __name__ == '__main__':
    unittest.main()
