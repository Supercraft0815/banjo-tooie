#!/usr/bin/env python3
"""Opt-in hardware check. Run outside the sandbox for SDL/OpenGL access on macOS."""
import os
from pathlib import Path
import subprocess
import sys
import tempfile

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE.parent))
import build


def main():
    with tempfile.TemporaryDirectory(prefix='bt-gpu-test-') as tmp:
        exe = str(Path(tmp) / 'gpu-renderer')
        subprocess.run([build.CLANG, '-O2', '-Wno-shift-op-parentheses', '-DBT_GPU_OPENGL=1',
                        '-I', str(HERE.parent / 'host'), *build.SDL_CFLAGS,
                        str(HERE / 'gpu_renderer.c'), str(HERE.parent / 'host/glad/gl.c'), '-o', exe,
                        '-lpthread', '-lm', *build.SDL_LIBS, *build.PLATFORM_LIBS[sys.platform]], check=True, capture_output=True)
        output = []
        env = {k: v for k, v in os.environ.items() if not k.startswith('BT_')}
        for backend in ('soft', 'gpu'):
            run = subprocess.run([exe], env={**env, 'BT_RENDERER': backend, 'BT_SCALE': '1'},
                                 capture_output=True, timeout=60)
            if run.returncode:
                raise RuntimeError(f'{backend}: exit {run.returncode}: {run.stderr.decode()[-1600:]}')
            output.append(run.stdout)
        assert len(output[0]) == 4*4*4096 and output[0] == output[1], 'GPU/software fixture mismatch'
        print('PASS GPU: triangles, fill, copy texrect, framebuffer read as texture, CPU writes/copies, borrowed Z (65536 identical bytes)')
        fallback = subprocess.run([exe], env={**env, 'BT_RENDERER': 'gpu', 'BT_SCALE': '1', 'BT_TEST_NO_BARRIER': '1'},
                                  capture_output=True, timeout=60, check=True)
        assert fallback.stdout == output[0] and b'needs a texture barrier' in fallback.stderr
        print('PASS: missing texture barrier falls back to exact software rendering at 1x')
        for name in ('gl', 'invalid'):
            run = subprocess.run([exe], env={**env, 'BT_RENDERER': name}, capture_output=True)
            assert run.returncode and b'BT_RENDERER must be' in run.stderr
        print('PASS: unsupported backend rejected; no silent software fallback')


if __name__ == '__main__':
    main()
