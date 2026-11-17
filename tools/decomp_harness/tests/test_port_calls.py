from pathlib import Path
import shutil
import tempfile
import unittest

from types import SimpleNamespace

from decomp_harness.codex import Result
from decomp_harness.common import Control
from decomp_harness.port_calls import Lane, Port, allowed, bisect, changed_files, first_difference, item_functions, load_module, n64_tokens, parse_items

REPO = Path(__file__).resolve().parents[3]


class PortCallsTest(unittest.TestCase):
    def test_items_go_to_the_file_that_needs_the_fix(self):
        files = {'f': 'src/a.c', 'g': 'src/b.c', 'h': 'src/n_native.inc'}
        work, rest = parse_items(['UNDEFRET f', 'f 0 1', 'RETCLASS h in g', 'VOIDSTORE f in g', 'RET h', 'RET x', ''], files)
        self.assertEqual(work, {'src/a.c': ['UNDEFRET f', 'f 0 1'], 'src/b.c': ['RETCLASS h in g']})
        self.assertEqual(sorted(rest), ['RET h', 'RET x', 'VOIDSTORE f in g'])

    def test_bisect_isolates_the_bad_candidate(self):
        calls = []

        def validate(batch):
            calls.append(list(batch))
            return 'bad' if 'x' in batch else None
        ok, bad = bisect(validate, ['a', 'x', 'b', 'c'])
        self.assertEqual(ok, ['a', 'b', 'c'])
        self.assertEqual(bad, [('x', 'bad')])
        self.assertEqual(calls[0], ['a', 'x', 'b', 'c'])

    def test_blamed_candidates_drop_without_halving(self):
        calls = []

        def validate(batch):
            calls.append(list(batch))
            return 'bad' if 'x' in batch or 'y' in batch else None
        ok, bad = bisect(validate, ['a', 'x', 'b', 'y'], lambda: ['x', 'y'])
        self.assertEqual((ok, bad), (['a', 'b'], [('x', 'bad'), ('y', 'bad')]))
        self.assertEqual(calls, [['a', 'x', 'b', 'y'], ['a', 'b']])  # one revalidation, no halves

    def test_ir_canonical_ignores_casts_but_not_conversions(self):
        eq = load_module(REPO / 'pc/native/wasm/ir_equiv.py')
        ref = ('define internal i32 @f(ptr noundef %0) #3 {', ['  %2 = call i32 @g(ptr %0) #78', '  ret i32 %2'])
        cast = ('define i32 @f(i32 %a, i32 %unused) {', ['  %p = inttoptr i32 %a to ptr', '  %r = call float @g(ptr %p)',
                                                       '  %b = bitcast float %r to i32', '  ret i32 %b'])
        numeric = ('define i32 @f(ptr %0) {', ['  %2 = call float @g(ptr %0)', '  %3 = fptosi float %2 to i32', '  ret i32 %3'])
        self.assertEqual(eq.canonical(*ref), eq.canonical(*cast))
        self.assertNotEqual(eq.canonical(*ref), eq.canonical(*numeric))
        void = ('define void @h() {', ['  call void @g()', '  ret void'])
        now = ('define i32 @h() {', ['  %1 = call i32 @g()', '  ret i32 %1'])
        self.assertEqual(eq.canonical(*void, void=True), eq.canonical(*now, void=True))
        self.assertTrue(eq.functions('define i32 @k(i32 %0) {\n  ret i32 %0\n}\n')['k'])

    def test_definitions_see_macro_and_split_heads(self):
        port = load_module(REPO / 'pc/native/wasm/port.py')
        text = ('void f(BtIntPtr a)\n#else\nvoid f()\n#endif\n{ if (x) { g(); } }\nint t[] = {1};\n'
                'BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) k(void *a) // c\n{ "}"; }\n'
                'void m(void) {\n#ifdef A\n    if (a) {\n#else\n    if (b) {\n#endif\n    }\n}\ntypedef struct { int a; } X; void h(void *p) {}\n')
        self.assertEqual(port.definitions(text), ['f', 'k', 'm', 'h'])

    def test_ir_items_skip_accepted_and_new_functions(self):
        lane = SimpleNamespace(irdiff={'f': ['-x'], 'g': ['-y'], 'bt_new': ['defined in the new build only']},
                               accepted=lambda: {'g'})
        self.assertEqual(Lane.ir_items(lane), {'IRDIFF f'})

    def test_item_functions(self):
        self.assertEqual(item_functions('func_800D1804 0 1'), ['func_800D1804'])
        self.assertEqual(item_functions('RET func_800D1804'), ['func_800D1804'])
        self.assertEqual(item_functions('RETCLASS func_a in func_b'), ['func_a', 'func_b'])
        self.assertEqual(item_functions('IRDIFF func_a'), ['func_a'])
        self.assertTrue(allowed('src/overlays/ba/backpack.h', 'src/overlays/ba/ckpack.c'))
        self.assertFalse(allowed('src/overlays/ba/data.c', 'src/overlays/ba/ckpack.c'))

    @unittest.skipUnless(shutil.which('clang'), 'needs clang')
    def test_native_only_edits_keep_the_ido_token_view(self):
        root = Path(tempfile.mkdtemp())
        try:
            shutil.copytree(REPO / 'include', root / 'include')
            shutil.copytree(REPO / 'lib/ultralib/include', root / 'lib/ultralib/include')
            (root / 'src').mkdir()
            original = '#include "common.h"\nu32 f() {\n    g();\n}\nvoid h(s32 a) {}\n'
            fixed = '#include "common.h"\nu32 f() {\n    BT_NATIVE_ONLY(return) g();\n}\nvoid h(BT_IDO_ONLY(s32 a) BT_PASS2(s32 a, s32 bt_a1)) {}\n'
            broken = '#include "common.h"\nu32 f() {\n    return g();\n}\nvoid h(s32 a) {}\n'
            views = {}
            for name, text in (('a', original), ('b', fixed), ('c', broken)):
                (root / 'src/x.c').write_text(text)
                views[name] = n64_tokens(root, 'src/x.c')
            self.assertNotIn('preprocessor error:', views['a'][0])
            self.assertEqual(first_difference(views['a'], views['b']), '')
            self.assertIn('return', first_difference(views['a'], views['c']))
        finally:
            shutil.rmtree(root)

    def test_changed_files_sees_edits_and_new_files(self):
        a, b = Path(tempfile.mkdtemp()), Path(tempfile.mkdtemp())
        try:
            for root in (a, b):
                (root / 'src').mkdir()
                (root / 'src/x.c').write_text('int x;\n')
            (b / 'src/x.c').write_text('int y;\n')
            (b / 'include').mkdir()
            (b / 'include/new.h').write_text('\n')
            self.assertEqual(changed_files(b, a), ['include/new.h', 'src/x.c'])
            self.assertEqual(changed_files(a, a), [])
        finally:
            shutil.rmtree(a)
            shutil.rmtree(b)

    def test_worker_guard_keeps_the_file_and_rejects_strays(self):
        root = Path(tempfile.mkdtemp())
        try:
            lane = root / '.decomp-agent/port-calls/lane'
            for tree in (root, lane):
                (tree / 'src').mkdir(parents=True)
                (tree / 'build/us').mkdir(parents=True)
                (tree / 'build/us/banjotooie_decompressed.map').write_text('')
                (tree / 'src/a.c').write_text('u32 f() {\n    g();\n}\n')
                (tree / 'src/b.c').write_text('int b;\n')

            class Runner:  # a fake worker: edits its clone like codex would
                def __init__(self, stray):
                    self.stray = stray

                def run(self, cwd, **_):
                    (cwd / 'src/a.c').write_text('u32 f() {\n    BT_NATIVE_ONLY(return) g();\n}\n')
                    if self.stray:
                        (cwd / 'src/b.c').write_text('int c;\n')
                    return Result(0, 'ok', message={'status': 'candidate', 'summary': 's', 'knowledge': [], 'blocker': ''})
            config = {'easy_model': {'enabled': True, 'model': 'm', 'effort': 'low'}, 'routing': [{'model': 'n', 'effort': 'medium'}],
                      'worker_timeout': 60, 'concurrency': 1}
            args = SimpleNamespace(model=None, file=None, retry=False, attempts=2, dry_run=False)
            port = Port(root, config, Control(), args)
            port.flags = []
            (root / '.decomp-agent/port-calls/reference-ir').mkdir()
            fake_lane = SimpleNamespace(path=lane, widened={'UNDEFRET f'}, irdiff={}, units=lambda: ['src/a.c', 'src/b.c'],
                                        reference=root / '.decomp-agent/port-calls/reference-ir')
            good = port.work(Runner(False), fake_lane, 'src/a.c', ['UNDEFRET f'], root / 'runs')
            self.assertEqual(good.files, {'src/a.c': 'u32 f() {\n    BT_NATIVE_ONLY(return) g();\n}\n'})
            self.assertIsNone(port.work(Runner(True), fake_lane, 'src/a.c', ['UNDEFRET f'], root / 'runs'))
            entry = port.state['files']['src/a.c']
            self.assertEqual((entry['status'], entry['attempts']), ('rejected', 2))
            self.assertIn('src/b.c', entry['feedback'])
            self.assertEqual(list((root / '.decomp-agent/port-calls/work').iterdir()), [])  # clones removed
        finally:
            shutil.rmtree(root)


if __name__ == '__main__':
    unittest.main()
