#!/usr/bin/env python3
"""Check which C objects can occupy the original IDO data section."""
from pathlib import Path
import sys
import unittest

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from data_to_c import K, ci, readonly_object


class DataQualifiers(unittest.TestCase):
    def test_initialized_objects(self):
        source = """
            typedef const char Constant;
            const char text[] = "abc";
            const Constant matrix[2][4] = {"one", "two"};
            const int scalar = 3;
            char mutable[] = "abc";
            const char *pointers[] = {text, text};
            const char *const fixed_pointers[] = {text, text};
            const char *pointer = text;
            const volatile char hardware[] = "abc";
            #define IN_DATA __attribute__((section(".data")))
            const char explicit_data[] IN_DATA = "abc";
            const int placed_scalar IN_DATA = 7;
            const volatile int hardware_register = 1;
        """
        unit = ci.Index.create().parse(
            "objects.c", args=["--target=mips-unknown-none-elf", "-std=c11"],
            unsaved_files=[("objects.c", source)])
        self.assertEqual(list(unit.diagnostics), [])
        objects = {var.spelling: readonly_object(var) for var in unit.cursor.get_children()
                   if var.kind == K.VAR_DECL}
        self.assertEqual(objects, {
            "text": True, "matrix": True, "scalar": True, "mutable": False,
            "pointers": False, "fixed_pointers": True, "pointer": False,
            "explicit_data": False, "hardware": False, "placed_scalar": False,
            "hardware_register": False,
        })


if __name__ == "__main__":
    unittest.main()
