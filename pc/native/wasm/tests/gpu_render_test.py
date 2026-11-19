#!/usr/bin/env python3
"""Opt-in hardware check. Run outside the sandbox for SDL/OpenGL access on macOS."""
import math
import os
import re
from pathlib import Path
import subprocess
import sys
import tempfile

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE.parent))
import build
from a9_mod_texture_test import hash_texture, png


def check_samples(exe, env):
    env = {**env, 'BT_RENDERER': 'gpu', 'BT_SCALE': '2'}
    def picture(level, w, h):
        run = subprocess.run([exe, str(level), '0', str(w), str(h)], env=env, check=True, capture_output=True, timeout=60)
        width, height, samples, maximum = map(int, re.search(rb'target=(\d+)x(\d+) samples=(\d+) max=(\d+)', run.stderr).groups())
        assert (width,height)==(w,h) and len(run.stdout)==w*h*4
        return run.stdout[::4], samples, maximum
    w,h = 132,99 # 4.125 times the guest resolution
    ref,off,_ = picture(0,w,h)
    assert off==0 and set(ref)=={0,255}
    vertices = [(x*w/32, y*h/24) for x,y in ((3,2),(26,5),(9,21))]
    def edge_distance(x,y):
        distances = []
        for (ax,ay),(bx,by) in zip(vertices,vertices[1:]+vertices[:1]):
            dx,dy = bx-ax,by-ay
            t = min(1,max(0,((x-ax)*dx+(y-ay)*dy)/(dx*dx+dy*dy)))
            distances.append(math.hypot(x-ax-t*dx,y-ay-t*dy))
        return min(distances)
    for level in (1,2,3):
        pixels,samples,maximum = picture(level,w,h)
        interior = edges = changed = 0
        for y in range(h):
            for x in range(w):
                i=y*w+x
                if edge_distance(x+.5,y+.5) > .72:  # half the pixel diagonal plus raster rounding
                    interior += 1
                    assert pixels[i]==ref[i], (x,y,'flat interior changed')
                else:
                    edges += 1
                    changed += 0 < pixels[i] < 255
        assert samples >= min(1 << level,maximum) and changed > 0
        print(f'PASS {w}x{h} fractional raster, MSAA requested {1<<level}, actual {samples}, {interior} identical flat pixels, {changed}/{edges} edge pixels with partial coverage')
    native,off,_ = picture(0,32,24)
    requested,effective,_ = picture(3,32,24)
    assert effective == 0 and native == requested
    print('PASS 1x: 8x request leaves MSAA off and every pixel identical')



def check_point_boundaries(exe, env):
    for case, expected in ((0, (0,255,0)), (1, (0,255,0)), (2, (0,255,0))):
        run = subprocess.run([exe, 'point-boundary', str(case)], env={**env, 'BT_RENDERER':'gpu', 'BT_SCALE':'1'},
                             capture_output=True, timeout=60)
        assert run.returncode == 0, (case, run.stderr.decode()[-1600:])
        assert len(run.stdout)==4, (case, run.stdout)
        red,green,blue,alpha=run.stdout
        assert (red,green,blue)==expected and alpha==255, (case, tuple(run.stdout))
    # At 255/256 the filtered texel is within one 8-bit level of column 1.
    run = subprocess.run([exe, 'point-boundary', '3'], env={**env, 'BT_RENDERER':'gpu', 'BT_SCALE':'1'},
                         capture_output=True, timeout=60)
    assert run.returncode == 0, ('filtered', run.stderr.decode()[-1600:])
    assert len(run.stdout)==4 and 253 <= run.stdout[1] <= 255 and run.stdout[0] <= 1, tuple(run.stdout)
    print('PASS point sample ULP snap and +/-8192 1/32 boundaries; filtered 255/256 remains within one level')


def main():
    with tempfile.TemporaryDirectory(prefix='bt-gpu-test-') as tmp:
        exe = str(Path(tmp) / 'gpu-renderer')
        subprocess.run([build.CLANG, '-O2', '-Wno-shift-op-parentheses', '-DBT_GPU_OPENGL=1', '-DBT_IMAGE_ACCESS_HOST=1',
                        '-I', str(HERE.parent / 'host'), *build.SDL_CFLAGS,
                        str(HERE / 'gpu_renderer.c'), str(HERE.parent / 'host/glad/gl.c'),
                        str(HERE.parent / 'host/mod_texture.c'), '-o', exe,
                        '-lpthread', '-lm', '-lz', *build.SDL_LIBS, *build.PLATFORM_LIBS[sys.platform]], check=True)
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
        for scale in (1, 4):
            outputs = []
            for backend in ('soft','gpu'):
                result = subprocess.run([exe, 'depth'], capture_output=True, timeout=60,
                                        env={**env, 'BT_RENDERER': backend, 'BT_SCALE': str(scale)})
                assert result.returncode == 0, (backend,scale,result.stderr.decode()[-1024:])
                outputs.append(result.stdout)
            assert outputs[0] == outputs[1] and len(outputs[0]) == 32*24*2
            print(f'PASS {scale}x CPU depth write, borrowed Z as color and changed Z address')
        outputs = [subprocess.run([exe, mode], env={**env, 'BT_RENDERER':'gpu', 'BT_SCALE':'4'},
                                  check=True,capture_output=True,timeout=60).stdout for mode in ('whole','strips')]
        assert len(outputs[0]) == 128*96*4 and outputs[0] == outputs[1], 'filtered texrect strip seam at 4x'
        assert len(set(outputs[0][::4]))>8, 'empty strip fixture'
        print('PASS 4x: split and whole filtered texrect images have 12,288 identical pixels')
        key = hash_texture(0, 2, 2, 1, bytes([255]*4))
        shades = [17, 52, 87, 122, 157, 192]
        png(Path(tmp) / 'mods/stripes/textures' / f'{key}_2x1.png', 6, 3,
            b''.join(bytes((v,v,v,255)) for v in shades))
        run = subprocess.run([exe, 'mod-wrap'], cwd=tmp, env={**env,'BT_RENDERER':'gpu','BT_SCALE':'4'},
                             check=True, capture_output=True, timeout=60)
        coords = [math.floor(3*(-60/32+x/4)) for x in range(32)]
        for mode in range(3):
            indices = [(s % 6 if mode == 0 else min(s % 12, 11 - s % 12) if mode == 1 else
                        min(5, max(0, s))) for s in coords]
            assert run.stdout[32*mode:32*(mode+1)] == bytes(shades[i] for i in indices), (mode,run.stdout)
        print('PASS 3x replacement: all six texels through repeat, mirror and clamp, including negative S')
        base = {**env,'BT_RENDERER':'gpu','BT_SCALE':'1'}
        results = [subprocess.run([exe,'programs'],env={**base,'BT_GPU_SPECIALIZE':value},
                                  check=True,capture_output=True,timeout=60).stdout for value in ('0','1')]
        assert len(results[0])==16384 and results[0]==results[1]
        print('PASS asynchronous and generic draw programs: 16,384 identical bytes')
        subprocess.run([exe,'shared'],env=base,check=True,capture_output=True,timeout=60)
        print('PASS held scanout remained red through 80 publications, newest frame is blue')
        subprocess.run([exe, 'image-access'], env={**base, 'BT_GPU_DEMAND': '1'},
                       check=True, capture_output=True, timeout=60)
        print('PASS on-demand overlap for scalar and bulk accesses, CPU color write preserved')
        check_samples(exe, env)
        check_point_boundaries(exe, env)
        for name in ('gl', 'invalid'):
            run = subprocess.run([exe], env={**env, 'BT_RENDERER': name}, capture_output=True)
            assert run.returncode and b'BT_RENDERER must be' in run.stderr
        print('PASS: unsupported backend rejected; no silent software fallback')


if __name__ == '__main__':
    main()
