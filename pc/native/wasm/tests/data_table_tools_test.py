#!/usr/bin/env python3
"""Exercise the conservative audio command and callback table proposal filters."""
from pathlib import Path
import struct
import subprocess
import sys
import tempfile
import unittest

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from audio_command_tables import decode
from build import tool
from callback_tables import callback_entries, original_functions


class AudioCommands(unittest.TestCase):
    def test_decoder(self):
        cases = [
            ([], None), ([0], 1), ([19, 0, 0], 3), ([1, 4, 0, 0], 4),
            ([0x9002, 0], 2), ([35, 0, 0, 0, 0, 0, 0, 0], 8),
            ([19, 1, 0, 0], 3), ([0, 1], None), ([19], None), ([19, 1], None),
            ([99, 0], None), ([3, 0], None), ([4, 0], None), ([0x0100, 0], None),
        ]
        for words, consumed in cases:
            with self.subTest(words=words):
                self.assertEqual(decode(struct.pack(f">{len(words)}H", *words)), consumed)
        self.assertIsNone(decode(b"\x00"))


class CallbackTables(unittest.TestCase):
    def test_relocations(self):
        functions = {"first", "second"}
        entries = {4: ("first", 0), 8: ("second", 0)}
        self.assertEqual(callback_entries(4, 12, entries, functions), ["first", "second"])
        for start, end, relocs in [
            (4, 4, entries), (3, 12, entries), (4, 11, entries), (4, 16, entries),
            (4, 12, {4: ("first", 0)}), (4, 12, {**entries, 5: ("first", 0)}),
            (4, 12, {**entries, 8: ("second", 4)}), (4, 12, {**entries, 8: ("data", 0)}),
        ]:
            with self.subTest(start=start, end=end, relocs=relocs):
                self.assertIsNone(callback_entries(start, end, relocs, functions))

    def test_linked_symbol_kinds(self):
        source = """.text
.globl handler
.type handler,@function
handler:
    nop
.size handler, .-handler
.weak weak_handler
.type weak_handler,@function
weak_handler:
    nop
.local private_handler
.type private_handler,@function
private_handler:
    nop
.globl plain_label
plain_label:
    nop
.data
.globl object
.type object,@object
object:
    .4byte external
.type external,@function
.globl absolute
.type absolute,@function
.set absolute, 42
"""
        with tempfile.TemporaryDirectory() as temp:
            root = Path(temp)
            asm = root / "callbacks.s"
            asm.write_text(source)
            reader = tool("llvm-readelf")
            for triple, emulation in [("mips", "elf32btsmip"), ("mipsel", "elf32ltsmip"),
                                      ("mips64", "elf64btsmip"), ("powerpc", "elf32ppc")]:
                obj, elf = root / (triple + ".o"), root / (triple + ".elf")
                subprocess.run([tool("llvm-mc"), "-triple=" + triple, "-filetype=obj",
                                str(asm), "-o", str(obj)], check=True)
                subprocess.run([tool("ld.lld"), "-m", emulation, "-e", "handler",
                                "--unresolved-symbols=ignore-all", str(obj), "-o", str(elf)],
                               check=True)
                if triple == "mips":
                    self.assertEqual(original_functions(elf, reader), {"handler", "weak_handler"})
                    with self.assertRaises(ValueError):
                        original_functions(obj, reader)
                else:
                    with self.assertRaises(ValueError):
                        original_functions(elf, reader)
            with self.assertRaises(ValueError):
                original_functions(asm, reader)


if __name__ == "__main__":
    unittest.main()
