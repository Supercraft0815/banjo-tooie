#!/usr/bin/env python3
"""ROM-free image oracle checks, including BMP orientation and missing frames."""
import contextlib
import io
from pathlib import Path
import struct
import sys
import tempfile
import unittest

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
import frame_compare as fc


def bmp(rgb, top_down=False, bits=32):
    # Two rows of one pixel; 24-bit rows have a padding byte.
    rows = [bytes((b, g, r, 0)) for r, g, b in rgb]
    data = b''.join(rows if top_down else reversed(rows))
    return (b'BM' + struct.pack('<IHHI', 54 + len(data), 0, 0, 54)
            + struct.pack('<IiiHHIIiiII', 40, 1, -2 if top_down else 2, 1, bits, 0,
                          len(data), 0, 0, 0, 0) + data)


class FrameCompareTest(unittest.TestCase):
    def test_oracle(self):
        with tempfile.TemporaryDirectory() as tmp, contextlib.redirect_stdout(io.StringIO()):
            a, b = Path(tmp) / 'a', Path(tmp) / 'b'
            a.mkdir(); b.mkdir()
            left, right = a / 'frame_00001.bmp', b / 'frame_00001.bmp'
            left.write_bytes(bmp([(20, 40, 60), (80, 100, 120)], bits=24))
            right.write_bytes(bmp([(20, 40, 60), (80, 100, 120)], top_down=True))
            self.assertEqual(fc.compare(a, b, 0, 0)['failed_frames'], 0)
            right.write_bytes(bmp([(28, 40, 60), (80, 100, 120)]))
            self.assertEqual(fc.compare(a, b, 8, 0)['failed_frames'], 0)
            result = fc.compare(a, b, 7, 0)
            self.assertEqual(result['failed_frames'], 1)
            self.assertEqual(result['worst_bad_fraction'], 0.5)
            self.assertEqual(fc.compare(a, b, 7, 0.5)['failed_frames'], 0)
            right.unlink()
            with self.assertRaises(ValueError):
                fc.compare(a, b)
            left.write_bytes(left.read_bytes()[:-1])
            with self.assertRaises(ValueError):
                fc.read_bmp(left)


if __name__ == '__main__':
    unittest.main()
