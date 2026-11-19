#!/usr/bin/env python3
"""Check C callback decoding and original literal/relocation comparison."""
from pathlib import Path
import sys
import unittest
import tempfile

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
import data_to_c as d


class StubPointers(unittest.TestCase):
    def test_only_a_declared_function_pointer_uses_a_recovered_stub(self):
        unit = d.ci.Index.create().parse(
            'callback.c', args=['--target=mips-unknown-none-elf'],
            unsaved_files=[('callback.c', 'int (*fn)(void); void *obj; unsigned int bits;')])
        self.assertEqual(list(unit.diagnostics), [])
        types = {var.spelling: var.type for var in unit.cursor.get_children()}
        address, stub = next(iter(d.data.STUBS.items()))
        contents = address.to_bytes(4, 'big')
        names = {d.RAW_STUBS: {0: stub}}
        self.assertIn(stub, d.init(types['fn'], contents, 0, {}, names, None))
        self.assertEqual(int(d.init(types['bits'], contents, 0, {}, names, None), 0), address)
        with self.assertRaisesRegex(d.Refuse, 'raw address'):
            d.init(types['obj'], contents, 0, {}, names, None)
        with self.assertRaisesRegex(d.Refuse, 'raw address'):
            d.init(types['fn'], contents, 0, {}, {}, None)

    def test_assembly_directive_and_alignment(self):
        address, stub = next(iter(d.data.STUBS.items()))
        b = address.to_bytes(4, 'big')
        source = ['.section .data', 'dlabel test',
                  f'    /* 0 80000000 {address:08X} */ .word 0x{address:08X}',
                  f'    /* 4 80000004 {address:08X} */ .float -0.0',
                  f'    /* 8 80000008 {address:08X} */ .word {stub}']
        for i, byte in enumerate(b):
            source.append(f'    /* {12+i:X} {0x8000000C+i:08X} */ .byte 0x{byte:02X}')
        source += ['    /* 10 80000010 */ .byte 0x00',
                   f'    /* 11 80000011 {address:08X} */ .word 0x{address:08X}']
        with tempfile.TemporaryDirectory() as temp:
            path = Path(temp) / 'callbacks.data.s'
            path.write_text('\n'.join(source) + '\n')
            recovered = {}
            _, _, relocations = d.image(path, recovered)
        self.assertEqual(recovered, {0: stub, 4: stub})
        self.assertEqual(relocations, {8: (stub, 0)})

    def test_new_relocation_must_resolve_to_exact_old_word(self):
        (address, symbol), (_, other) = list(d.data.STUBS.items())[:2]
        old = [f' 0000 {address:08x}']
        relocation = f'00000000 R_MIPS_32 {symbol}'
        self.assertEqual(d.matching_literal_stubs([' 0000 00000000', relocation], old), {0})
        for new, before in [
            ([' 0000 00000004', relocation], old),
            ([' 0000 00000000', f'00000000 R_MIPS_32 {other}'], old),
            ([' 0000 00000000', relocation.replace('R_MIPS_32', 'R_MIPS_26')], old),
            ([' 0000 00000000', relocation], old + [f'00000000 R_MIPS_32 {other}']),
            ([' 0000 00000000', relocation], [' 0000 12345678']),
        ]:
            with self.subTest(new=new, before=before):
                self.assertEqual(d.matching_literal_stubs(new, before), set())


if __name__ == '__main__':
    unittest.main()
