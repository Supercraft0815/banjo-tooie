#!/usr/bin/env python3
"""ROM-free renderer regression. Run: python3 pc/native/wasm/tests/render_test.py."""
import hashlib
import os
from pathlib import Path
import subprocess
import tempfile

HERE = Path(__file__).resolve().parent
# Captured from the pre-scaling renderer, commit 02629d9d1 (16 KiB of fixture RDRAM).
ORIGINAL = '4480c69fe4809c6012196bcdb667b7b5381c83c22cc8f6c35a9a5e8aeb22ff42'


def main():
    with tempfile.TemporaryDirectory(prefix='bt-render-test-') as tmp:
        exe = str(Path(tmp) / 'renderer')
        subprocess.run(['clang', '-O2', '-Wall', '-Wextra', '-Wno-shift-op-parentheses',
                        '-I', str(HERE.parent / 'host'), str(HERE / 'renderer.c'),
                        '-o', exe, '-lpthread', '-lm'], check=True)
        for scale in (1, 2, 3, 4):
            result = subprocess.run([exe], env={**os.environ, 'BT_SCALE': str(scale)},
                                    check=True, capture_output=True)
            if scale == 1:
                assert hashlib.sha256(result.stdout).hexdigest() == ORIGINAL, 'S=1 differs from original renderer'
            else:
                assert not result.stdout
            print(f'BT_SCALE={scale}: PASS')
        bad = subprocess.run([exe], env={**os.environ, 'BT_SCALE': '5'}, capture_output=True)
        assert bad.returncode != 0 and b'BT_SCALE must be' in bad.stderr
        print('Invalid scale rejected: PASS')
        sampling = str(Path(tmp) / 'sampling')
        subprocess.run(['clang', '-O2', '-Wno-shift-op-parentheses', str(HERE / 'sampling.c'),
                        '-o', sampling, '-lpthread', '-lm'], check=True)
        assert subprocess.check_output([sampling]).strip() == b'298bd68a'
        print('Texture formats, palette/othermode changes and cache invalidation: PASS')
        bench = str(Path(tmp) / 'benchmark')
        subprocess.run(['clang', '-O2', '-Wno-shift-op-parentheses', str(HERE / 'benchmark.c'),
                        '-o', bench, '-lpthread', '-lm'], check=True)
        # Captured with the renderer before the performance changes, including high-resolution scanout.
        for scale, expected in [(1, '1e3f2225'), (2, '3b53b8b5'), (4, 'c6d1ca85')]:
            result = subprocess.check_output([bench], env={**os.environ, 'BT_SCALE': str(scale)}, text=True)
            assert result.strip().endswith('hash=' + expected), result
            print(result.strip())
        keyboard = str(Path(tmp) / 'keyboard')
        sdl = ['-I/opt/homebrew/include', '-L/opt/homebrew/lib', '-lSDL3']  # same SDL as build.py
        subprocess.run(['clang', '-O2', str(HERE / 'keyboard.c'), '-o', keyboard] + sdl, check=True)
        subprocess.run([keyboard], check=True)
        retrace = str(Path(tmp) / 'retrace')
        subprocess.run(['clang', '-O2', '-Wall', str(HERE / 'retrace.c'), '-o', retrace, '-lm'], check=True)
        subprocess.run([retrace], check=True)


if __name__ == '__main__':
    main()
