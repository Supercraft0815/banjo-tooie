import pathlib
import sys
import tempfile
import unittest

sys.path.insert(0, str(pathlib.Path(__file__).resolve().parents[1]))
import stack_arrays


class StackArraysTest(unittest.TestCase):
    def test_only_one_array_supplies_an_address(self):
        with tempfile.TemporaryDirectory() as tmp:
            path = pathlib.Path(tmp) / 'stack.c'
            path.write_text('void take(int *); void number(int);\n'
                            'void one(void) { int a[3], b[3]; take(&a[b[0]]); number(b[1]); }\n'
                            'void both(void) { int a[3], b[3]; take(a); number((int)b); }\n'
                            'void separate(void) { int a[3]; int pad; int b[3]; take(a); }\n'
                            'void mixed(void) { static int a[3]; int b[3]; take(b); }\n')
            self.assertEqual(stack_arrays.scan(str(path)),
                             [(str(path), 'one', '2', 'a,b', 'a', 'take')])


if __name__ == '__main__':
    unittest.main()
