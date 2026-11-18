#!/usr/bin/env python3
import pathlib
import sys
import tempfile
import unittest

sys.path.insert(0, str(pathlib.Path(__file__).resolve().parents[1]))
import data_inventory
import data
import xsym_report


class InventoryTest(unittest.TestCase):
    def test_xsym_respects_block_ends_and_overlapping_data(self):
        with tempfile.TemporaryDirectory() as tmp:
            out = pathlib.Path(tmp)
            (out / 'gen').mkdir()
            (out / 'game.map').write_text('80000010 100 10 __bt_data_0\n80000018 108 8 tail\n80000030 200 100 outer\n')
            (out / 'gen/data.ll').write_text('@"__bt_place_tail" = alias i8, ptr getelementptr (i8, ptr @"__bt_data_0", i32 8)\n')
            table = xsym_report.symbols(out)
            table.extend((0x80000030+i, 1, f'inner{i}', None) for i in range(1, 71))
            table.sort()
            starts = [row[0] for row in table]
            self.assertEqual(xsym_report.resolve(table, starts, 0x8000001f), ('tail', 7))
            self.assertEqual(xsym_report.resolve(table, starts, 0x80000020), ('?80000020', 0))
            self.assertEqual(xsym_report.resolve(table, starts, 0x80000080), ('outer', 0x50))

    def test_ownership_and_raw_function_pointer(self):
        stub = next(iter(data.STUBS))
        with tempfile.TemporaryDirectory() as tmp:
            file = pathlib.Path(tmp) / 'module.s'
            file.write_text(f'''.section .data
dlabel table
/* 000000 80800000 {stub:08X} */ .word 0x{stub:08X}
dlabel R_constant
/* 000004 80800004 3F800000 */ .float 1.0
''')
            rows = data_inventory.scan([file], {'table'}, {'R_constant': 'float'})
            self.assertEqual(rows[0]['bytes'], 8)
            self.assertTrue(rows[0]['labels'][0]['defined_in_c'])
            self.assertFalse(rows[0]['labels'][1]['defined_in_c'])
            self.assertTrue(rows[0]['labels'][1]['declaration_known'])
            self.assertEqual(rows[0]['raw_syscall_pointers'], [data.STUBS[stub]])

    def test_strict_mode_keeps_only_hasms_and_reports_unowned_data(self):
        with tempfile.TemporaryDirectory() as tmp:
            root = pathlib.Path(tmp)
            hasm, module = root / 'src/core.s', root / 'src/generated.s'
            hasm.parent.mkdir()
            hasm.write_text('.section .data\ndlabel permitted\n/* 000000 80000000 01 */ .byte 1\n')
            module.write_text('.section .data\ndlabel in_c\n/* 000000 80000000 01 */ .byte 1\n'
                              'dlabel required\n/* 000001 80000001 02 */ .byte 2\n')
            layout = '      - [0x1000, hasm, ../../src/core]\n'
            report = root / 'remaining.tsv'
            with self.assertRaisesRegex(SystemExit, '1 assembler data entr'):
                data.strict_inputs([hasm, module], {'in_c'}, root, layout, report)
            self.assertEqual(report.read_text(), 'src/generated.s\tdata\trequired\n')
            self.assertEqual(data.strict_inputs([hasm, module], {'in_c', 'required'}, root, layout, report), [hasm])
            self.assertEqual(report.read_text(), '')


if __name__ == '__main__':
    unittest.main()
