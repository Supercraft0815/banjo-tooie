import unittest

from decomp_harness.matching import changed_functions, function_rows, instructions, score


SYMBOLS = ('SYMBOL TABLE:\n'
           '00000020 g     F .text\t00000010 target\n'
           '00000030 g     F .text\t00000008 next\n')
BODY = ('00000020 <target>:\n'
        ' 20: 24020001 li v0,1\n'
        ' 24: 10000001 b 2c <.L8000002C>\n'
        '00000028 <.L80000028>:\n'
        ' 28: 00000000 nop\n'
        '0000002c <.L8000002C>:\n'
        ' 2c: 03e00008 jr ra\n')
NEXT = ('00000030 <next>:\n'
        ' 30: 24020002 li v0,2\n'
        ' 34: 00000000 nop\n')


class ReferenceLabelTests(unittest.TestCase):
    def test_internal_labels_keep_the_whole_function_and_original_start(self):
        for symbols in ('', SYMBOLS):
            with self.subTest(symbol_table=bool(symbols)):
                rows = instructions(symbols + BODY + NEXT, 'target')
                self.assertEqual([r['offset'] for r in rows], [0, 4, 8, 12])
                self.assertEqual(rows[1]['asm'], 'b @+c')
                self.assertEqual(rows[-1]['asm'], 'jr ra')

    def test_own_symbol_size_stops_before_unlabelled_padding(self):
        padding = ' 30: 00000000 nop\n 34: 00000000 nop\n'
        self.assertEqual(len(instructions(SYMBOLS + BODY + padding, 'target')), 4)

    def test_larger_candidate_keeps_real_extra_instructions_and_their_delay_slots(self):
        candidate_symbols = SYMBOLS.replace('00000010 target', '00000018 target')
        extra = ' 30: 24030003 li v1,3\n 34: 00000000 nop\n'
        candidate = instructions(candidate_symbols + BODY + extra, 'target', 4)
        self.assertEqual(len(candidate), 6)
        self.assertLess(score(instructions(SYMBOLS + BODY, 'target', 4), candidate)['score'], 100)

    def test_asm_processor_alignment_in_symbol_size_still_uses_original_length(self):
        symbols = SYMBOLS.replace('00000010 target', '00000018 target')
        padding = ' 30: 00000000 nop\n 34: 00000000 nop\n'
        self.assertEqual(len(instructions(symbols + BODY + padding, 'target', 4)), 4)

    def test_next_function_still_stops_even_if_the_previous_size_overlaps(self):
        symbols = SYMBOLS.replace('00000010 target', '00000030 target')
        self.assertEqual(len(instructions(symbols + BODY + NEXT, 'target')), 4)

    def test_symbol_offset_labels_are_internal(self):
        body = BODY.replace('.L80000028', 'target+0x8').replace('.L8000002C', 'target+0xc')
        self.assertEqual(len(instructions(body + NEXT, 'target')), 4)
        self.assertEqual(set(function_rows(body + NEXT)), {'target', 'next'})

    def test_zero_size_uses_next_function_and_keeps_real_extra_code(self):
        symbols = SYMBOLS.replace('00000010 target', '00000000 target')
        self.assertEqual(len(instructions(symbols + BODY + NEXT, 'target', 2)), 4)

    def test_fallback_padding_with_a_relocation_cannot_disappear(self):
        padded = BODY + ' 30: 00000000 nop\n\t30: R_MIPS_LO16 external\n'
        self.assertEqual(len(instructions(padded, 'target', 4)), 5)

    def test_relocation_after_internal_label_is_retained(self):
        body = BODY + '\t2c: R_MIPS_26 external\n'
        self.assertEqual(instructions(body, 'target')[-1]['relocs'], ['R_MIPS_26 external'])

    def test_next_section_does_not_become_part_of_an_unsized_function(self):
        other = 'Disassembly of section .other:\n00000000 <.Lother>:\n 0: 00000000 nop\n'
        self.assertEqual(len(instructions(BODY + other, 'target')), 4)

    def test_local_pc16_normalizes_signed_addends_but_keeps_word_evidence(self):
        cases = [('ffff', '24', '.L8000002C', '2c', '0001'),
                 ('0000', '28', '.L80000028', '2c', '0001'),
                 ('fffe', '20', '.L8000002C', '28', '0000')]
        for immediate, placeholder, label, destination, resolved in cases:
            with self.subTest(immediate=immediate):
                reference = BODY.replace('10000001 b 2c <.L8000002C>',
                                         f'1000{immediate} b {placeholder}\n\t24: R_MIPS_PC16 {label}')
                candidate = BODY.replace('10000001 b 2c <.L8000002C>', f'1000{resolved} b {destination}')
                expected = instructions(SYMBOLS + reference, 'target')
                actual = instructions(SYMBOLS + candidate, 'target')
                comparison = score(expected, actual)
                self.assertEqual(comparison['score'], 100)
                self.assertFalse(comparison['object_identical'])
                self.assertFalse(comparison['exact'])
                self.assertEqual(expected[1]['word'], '1000' + immediate)
                self.assertEqual(expected[1]['relocs'], [])

    def test_local_pc16_with_a_different_branch_destination_is_a_difference(self):
        reference = BODY.replace('10000001 b 2c <.L8000002C>',
                                 '1000ffff b 24\n\t24: R_MIPS_PC16 .L8000002C')
        wrong = BODY.replace('10000001 b 2c', '10000000 b 28')
        self.assertEqual(score(instructions(reference, 'target'), instructions(wrong, 'target'))['different_instructions'], 1)

    def test_unknown_external_duplicate_and_outside_pc16_relocations_stay_visible(self):
        cases = [('external', ''), ('.Lunknown', ''),
                 ('.L8000002C', '0000002c <.L8000002C>:\n'),
                 ('.Loutside', '00000030 <.Loutside>:\n')]
        for label, suffix in cases:
            with self.subTest(label=label, suffix=suffix):
                body = BODY.replace('10000001 b 2c <.L8000002C>',
                                    f'1000ffff b 24\n\t24: R_MIPS_PC16 {label}') + suffix
                row = instructions(SYMBOLS + body, 'target')[1]
                self.assertEqual(row['relocs'], [f'R_MIPS_PC16 {label}'])
                self.assertEqual(row['asm'], 'b @+4')

    def test_pc16_addend_cannot_resolve_past_the_own_function(self):
        body = BODY.replace('10000001 b 2c <.L8000002C>',
                            '10000000 b 28\n\t24: R_MIPS_PC16 .L8000002C')
        self.assertEqual(instructions(SYMBOLS + body, 'target')[1]['relocs'], ['R_MIPS_PC16 .L8000002C'])

    def test_whole_object_regressions_include_changes_beyond_internal_labels(self):
        before = SYMBOLS + BODY + NEXT
        after = before.replace(' 2c: 03e00008 jr ra', ' 2c: 03e00008 jr t0')
        self.assertEqual(set(function_rows(before)), {'target', 'next'})
        self.assertEqual(changed_functions(before, after), ['target'])
        self.assertEqual(changed_functions(before, after, skip=['target']), [])


if __name__ == '__main__':
    unittest.main()
