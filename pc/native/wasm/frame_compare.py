#!/usr/bin/env python3
"""Compare BT_DUMP directories, or replay the corpus with soft and gl/metal.

Examples:
  frame_compare.py compare SOFT_DIR GPU_DIR
  frame_compare.py replay NEW_OUTPUT --renderer gl [--case intro]
Every retrace is dumped. Tolerance is per RGB channel, in 8-bit units; a pixel
fails if any channel exceeds it. No registration, cropping or reference updates.
"""
import argparse
import json
import math
import os
from pathlib import Path
import re
import shutil
import struct
import subprocess
import sys

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]


def read_bmp(path):
    """SDL's uncompressed 24/32-bit BGR BMP, normalized to top-down RGB bytes."""
    data = path.read_bytes()
    if len(data) < 54 or data[:2] != b'BM':
        raise ValueError(f'{path.name}: invalid BMP')
    offset, dib = struct.unpack_from('<II', data, 10)
    w, h, planes, bits, compression = struct.unpack_from('<iiHHI', data, 18)
    if not (dib >= 40 and 0 < w <= 8192 and 0 < abs(h) <= 8192 and planes == 1
            and bits in (24, 32) and compression in (0, 3)):
        raise ValueError(f'{path.name}: unsupported BMP layout')
    if compression == 3:
        if bits != 32 or offset < 66 or len(data) < 66 or struct.unpack_from('<III', data, 54) != (
                0xff0000, 0xff00, 0xff):
            raise ValueError(f'{path.name}: unsupported BMP channel masks')
    stride = ((w * bits + 31) // 32) * 4
    if offset < 14 + dib or offset + stride * abs(h) > len(data):
        raise ValueError(f'{path.name}: truncated BMP')
    rgb = bytearray(w * abs(h) * 3)
    for y in range(abs(h)):
        row = y if h < 0 else h - y - 1
        source = data[offset + row * stride:offset + row * stride + w * (bits // 8)]
        start = y * w * 3
        rgb[start:start + w * 3:3] = source[2::bits // 8]
        rgb[start + 1:start + w * 3:3] = source[1::bits // 8]
        rgb[start + 2:start + w * 3:3] = source[0::bits // 8]
    return w, abs(h), bytes(rgb)


def compare(soft, gpu, tolerance=8, max_bad_fraction=0.005):
    a, b = {p.name: p for p in soft.glob('frame_*.bmp')}, {p.name: p for p in gpu.glob('frame_*.bmp')}
    if not a or a.keys() != b.keys():
        raise ValueError(f'missing frames: soft={len(a)}, gpu={len(b)}, unmatched={len(a.keys() ^ b.keys())}')
    names = [re.fullmatch(r'frame_(\d+)\.bmp', name) for name in a]
    if any(m is None for m in names):
        raise ValueError('invalid frame filename')
    ids = sorted(int(m[1]) for m in names)
    if ids[-1] - ids[0] + 1 != len(ids):
        raise ValueError('missing retraces inside frame sequence')
    failed, worst, peak, first = 0, 0.0, 0, None
    for name in sorted(a):
        w, h, left = read_bmp(a[name])
        gw, gh, right = read_bmp(b[name])
        if (w, h) != (gw, gh):
            raise ValueError(f'{name}: dimensions differ ({w}x{h}, {gw}x{gh})')
        bad, delta = 0, 0
        if left != right:
            for i in range(0, len(left), 3):
                d = max(abs(left[i + k] - right[i + k]) for k in range(3))
                bad += d > tolerance
                delta = max(delta, d)
        fraction = bad / (w * h)
        if fraction > max_bad_fraction:
            failed += 1
            if first is None:
                first = name
        worst, peak = max(worst, fraction), max(peak, delta)
    result = dict(frames=len(a), failed_frames=failed, first_failure=first,
                  worst_bad_fraction=worst, peak_channel_delta=peak,
                  channel_tolerance=tolerance, max_bad_fraction=max_bad_fraction)
    print(f'{"FAIL" if failed else "PASS"}: {len(a)} frames, {failed} failed, '
          f'worst={worst:.6%}, delta={peak}, tolerance={tolerance}, allowed={max_bad_fraction:.6%}'
          + (f', first={first}' if first else ''))
    return result


def replay(args):
    import corpus
    output = args.output.resolve()
    output.mkdir()  # Never overwrite prior evidence or saves.
    exe = output / 'bt_game'
    shutil.copy2(args.exe.resolve(), exe)
    results = {}
    for name in args.case or corpus.CASES:
        case = corpus.CASES[name]
        seconds = args.seconds if args.seconds is not None else case['seconds']
        for renderer in ('soft', args.renderer):
            work = output / name / renderer
            work.mkdir(parents=True)
            if case['flags'] is not None:
                (work / 'bt_eeprom.bin').write_bytes(corpus.save_editor.edit(
                    bytes(2048), 0, [(f, True) for f in case['flags']], create=True))
            env = {k: v for k, v in os.environ.items() if not k.startswith('BT_')}
            env.update(BT_VCLOCK='1', BT_HEADLESS='1', BT_RENDERER=renderer,
                       BT_EXIT_AFTER=str(seconds), BT_PRESS=case['press'],
                       BT_DUMP=str(work / 'frame'), BT_DUMP_EVERY='1')
            if args.probe and renderer != 'soft':
                env['BT_GPU_PROBE'] = str(work / 'probe.json')
                env['BT_GPU_PROBE_TOLERANCE'] = str(args.tolerance)
                env['BT_GPU_PROBE_FRACTION'] = str(args.max_bad_fraction)
            with (work / 'run.log').open('w') as log:
                run = subprocess.run([str(exe), str(args.rom.resolve())], cwd=work, env=env,
                                     stdout=log, stderr=log, timeout=3600)
            if run.returncode:
                if (work / 'probe.json').exists():
                    print('draw oracle: ' + (work / 'probe.json').read_text().strip())
                raise ValueError(f'{name}/{renderer}: exit {run.returncode} (log retained)')
            marker = 'renderer: soft' if renderer == 'soft' else f'renderer: {renderer} ('
            if not any(line.startswith(marker) for line in (work / 'run.log').read_text().splitlines()):
                raise ValueError(f'{name}/{renderer}: renderer identity missing (old or wrong executable)')
            expected = math.ceil(seconds * 59.94) - 1
            if not (work / f'frame_{expected:05d}.bmp').exists():
                raise ValueError(f'{name}/{renderer}: missing final retrace {expected}')
        print(name + ': ', end='', flush=True)
        results[name] = compare(output / name / 'soft', output / name / args.renderer,
                                args.tolerance, args.max_bad_fraction)
    summary = dict(format='bt-frame-compare-1', renderer=args.renderer, cases=results,
                   partial_seconds=args.seconds, every_retrace=True)
    (output / 'summary.json').write_text(json.dumps(summary, indent=2) + '\n')
    return int(any(r['failed_frames'] for r in results.values()))


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest='cmd', required=True)
    for command in ('compare', 'replay'):
        p = sub.add_parser(command)
        p.add_argument('--tolerance', type=int, default=8)
        p.add_argument('--max-bad-fraction', type=float, default=0.005)
        if command == 'compare':
            p.add_argument('soft', type=Path)
            p.add_argument('gpu', type=Path)
        else:
            p.add_argument('output', type=Path)
            p.add_argument('--renderer', choices=('gl', 'metal'), default='gl')
            p.add_argument('--exe', type=Path, default=ROOT / 'build/ilp32/bt_game')
            p.add_argument('--rom', type=Path, default=ROOT / 'baserom.us.z64')
            p.add_argument('--case', choices=('intro', 'new-game', 'edited-save'), action='append')
            p.add_argument('--seconds', type=float, help='partial diagnostic replay only')
            p.add_argument('--probe', action='store_true', help='stop at first GPU draw outside the image tolerance; write probe.json')
    args = ap.parse_args()
    if not 0 <= args.tolerance <= 255 or not 0 <= args.max_bad_fraction <= 1:
        ap.error('tolerance must be 0..255; max-bad-fraction must be 0..1')
    if args.cmd == 'replay' and args.seconds is not None and (not math.isfinite(args.seconds) or args.seconds <= 0):
        ap.error('seconds must be positive and finite')
    try:
        if args.cmd == 'replay':
            return replay(args)
        return int(compare(args.soft, args.gpu, args.tolerance, args.max_bad_fraction)['failed_frames'] > 0)
    except (OSError, ValueError, subprocess.SubprocessError) as error:
        print(f'FAIL: {error}', file=sys.stderr)
        return 2


if __name__ == '__main__':
    sys.exit(main())
