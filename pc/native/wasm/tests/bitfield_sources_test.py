#!/usr/bin/env python3
"""Check line-preserving conversion, original-branch preprocessing and repeat runs."""
from pathlib import Path
import subprocess
import sys
import tempfile
import unittest
from unittest.mock import patch

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
import bitfield_sources as converter
import build


class BitfieldSources(unittest.TestCase):
    def test_two_orders_and_repeat(self):
        with tempfile.TemporaryDirectory() as d:
            root = Path(d)
            (root / 'src').mkdir()
            source = root / 'src/test.c'
            inp = ('typedef unsigned char u8;\nstruct Foo {\n'
                   '    u8 a : 1; /* apple */\n    u8 b : 7;\n'
                   '    u8 c : 7; u8 d : 1;\n};\n')
            source.write_text(inp)
            header = (build.ROOT / 'include/bt_native.h').resolve()
            flags = ['--target=wasm32-unknown-unknown', '-DBT_ILP32', '-include', str(header)]
            with patch.object(build, 'ROOT', root), patch.object(build, 'GUEST_FLAGS', flags):
                runs, notes = converter.scan(source)
                self.assertEqual(notes, [])
                self.assertEqual(len(runs), 1)
                self.assertEqual(runs[0][0], str(source))
                _, first, last, old, new = runs[0]
                updated = converter.replacements(inp, {(first, last, old): new})
                self.assertEqual(inp.count('\n'), updated.count('\n'))
                self.assertIn('/* apple */', updated)
                source.write_text(updated)
                guest = subprocess.check_output([build.CLANG, *flags, '-E', '-P', str(source)], text=True)
                self.assertIn('char : 0;', guest)
                self.assertLess(guest.index('u8 b : 7'), guest.index('u8 a : 1'))
                self.assertEqual(converter.scan(source)[0], [])
            processed = subprocess.check_output([build.CLANG, '-include', str(header), '-E', '-P',
                                                 str(source)], text=True)
            self.assertEqual([m[0] for m in converter.tokens(processed)], [m[0] for m in converter.tokens(inp)])

    def test_refuses_ambiguous_source_span(self):
        with self.assertRaisesRegex(ValueError, 'found 2'):
            converter.replacements('struct A {int x:1;}; struct B {int x:1;};',
                                   {(1, 1, 'int x:1;'): 'int :31; int x:1;'})


if __name__ == '__main__':
    unittest.main()
