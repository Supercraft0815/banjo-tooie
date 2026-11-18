"""Generated declarations can grow only when their callers use them as member views."""
import contextlib
import io
from pathlib import Path
import sys
import tempfile
import unittest
from unittest.mock import patch

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
import offsets
import place_decls


class OffsetsTest(unittest.TestCase):
    def test_repeated_declaration_placement_keeps_spacing(self):
        with tempfile.TemporaryDirectory() as tmp:
            path = Path(tmp) / 'view.c'
            path.write_text('int first(void) { return 0; }\n'
                            'typedef struct { s32 unk0; } ObjView; /* offsets.py genstruct */ '
                            'int read(void *p) { return ((ObjView *)p)->unk0; }\n')
            place_decls.place(path)
            once = path.read_text()
            place_decls.place(path)
            self.assertEqual(path.read_text(), once)

    def test_extend_preserves_stride_and_reports_matching_views(self):
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp)
            source = ('typedef struct { BtUIntPtr unk0; } ObjView; '
                      '/* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */\n')
            files = [root / name for name in ('left.c', 'right.c', 'array.c')]
            for f in files:
                f.write_text(source + 'int read(void *p) { return ((ObjView *)p)->unk0; }\n')
            files[-1].write_text(source + 'int read(void *p) { return ((ObjView *)p)[1].unk0; }\n')
            original = files[-1].read_text()
            records = [('VIEW', 'ObjView', 0, 'u8 *'), ('VIEW', 'ObjView', 8, 'f32'),
                       ('VIEW', 'ObjView', 12, 'u32'), ('VIEW', 'ObjView', 12, 'void (*)(s32)'),
                       ('VIEW', 'ObjView', 12, 'void (*)(u32)')]
            results = [(f.name, ([], {}, records)) for f in files]
            with patch.object(offsets, 'ROOT', root), contextlib.redirect_stdout(io.StringIO()):
                offsets.unions(results)
                after = files[0].read_text()
                offsets.unions(results)
            self.assertEqual(files[0].read_text(), after)
            self.assertIn('union { BtUIntPtr unk0; u8 * unk0_u8p; }; u8 pad4[0x4]; f32 unk8;', after)
            self.assertIn('void (*unkC_fn)(s32); void (*unkC_fn2)(u32);', after)
            self.assertEqual(files[-1].read_text(), original)
            groups = list(offsets.layouts(files))
            self.assertEqual(len(groups), 1)
            self.assertEqual([f for f, _, _ in groups[0][1]], files[:2])


if __name__ == '__main__':
    unittest.main()
