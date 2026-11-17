#!/usr/bin/env python3
import pathlib
import sys
import tempfile
import unittest

sys.path.insert(0, str(pathlib.Path(__file__).resolve().parents[1]))
import data_inventory
import data


class InventoryTest(unittest.TestCase):
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


if __name__ == '__main__':
    unittest.main()
