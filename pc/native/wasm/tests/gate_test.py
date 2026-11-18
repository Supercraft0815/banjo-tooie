"""Reference acceptance must keep the existing oracle on incomplete runs."""
import contextlib
import io
import json
from pathlib import Path
import subprocess
import sys
import tempfile
import unittest
from unittest.mock import patch

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
import port


class GateTest(unittest.TestCase):
    def test_unvisited_map_reasons_use_sweep_evidence_without_counting_warps_as_replays(self):
        known = {1: 'seen', 2: 'other', 3: 'static', 4: 'reached', 5: 'invalid', 6: 'excluded'}
        probes = [{'map': '02', 'status': 'other-map', 'last_map': 'AF'}, {'map': '03', 'status': 'static'},
                  {'map': '04', 'status': 'ok'}, {'map': '05', 'status': 'ok'}]
        with patch.object(port.corpus.sweep, 'maps', return_value=known), \
             patch.object(port.corpus.sweep, 'EXPECTED', {5: 'dummy map'}), \
             patch.object(port.corpus, 'CASES', {'another-case': {'expected_map': 6}}):
            missing = port.corpus.missing_maps({'case': {'maps': {'1': 2}}}, probes)
        self.assertEqual(set(missing), set(known.values()) - {'seen'})
        self.assertIn('0xAF', missing['other'])
        self.assertIn('five seconds', missing['static'])
        self.assertIn('repeat and image checks', missing['reached'])
        self.assertEqual(missing['invalid'], 'dummy map')
        self.assertIn('another-case', missing['excluded'])

    def test_long_emulated_run_has_its_own_deadline(self):
        with patch.object(port.corpus, 'record', side_effect=subprocess.TimeoutExpired('game', 1)) as record:
            self.assertEqual(port.run_case(Path('game'), 'new-game', Path('run')), 124)
            self.assertEqual(record.call_args.kwargs['timeout'], port.corpus.CASES['new-game']['seconds'] * 16)

    def test_reference_requires_explicit_accept_and_expected_end_state(self):
        header = dict.fromkeys(('build', 'rom', 'eeprom', 'BT_PRESS', 'BT_SCALE', 'BT_MUTE'), 'fixture')
        header.update(format='bt-trace-1', clock='vclock-build-local')
        row = dict(retrace=1, ticks=45 * 46875000, framebuffer={}, map=395,
                   players=[], actors=[], flags=[], state='fixture')

        def run(exe, name, work):
            work.mkdir()
            (work / 'trace.jsonl').write_text(json.dumps(header) + '\n' + json.dumps(row) + '\n')
            return 0

        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp)
            (root / 'build').mkdir()
            reference = root / 'refs/intro.jsonl'
            with patch.object(port, 'ROOT', root), patch.object(port, 'REF', reference.parent), \
                 patch.object(port, 'run_case', run), contextlib.redirect_stdout(io.StringIO()):
                def gate(accept):
                    return port.replay(['intro'], accept, Path(__file__))

                self.assertEqual(gate(False), 1)
                self.assertFalse(reference.exists())
                self.assertEqual(gate(True), 0)
                original = reference.read_bytes()
                row['map'] = 175
                self.assertEqual(gate(True), 1)
                row.update(map=395, ticks=0)
                self.assertEqual(gate(True), 1)
                self.assertEqual(reference.read_bytes(), original)


if __name__ == '__main__':
    unittest.main()
