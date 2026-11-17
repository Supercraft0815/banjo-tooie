#!/usr/bin/env python3
"""Exercise the n_audio filters against the cartridge microcode with synthetic inputs."""
from pathlib import Path
import os
import subprocess
import sys
import tempfile
import zlib

here = Path(__file__).resolve().parent
sys.path.insert(0, str(here.parent))
import build

with tempfile.TemporaryDirectory() as out:
    exe = Path(out) / 'audio_mixer'
    # Independent of the host ROM loader: compare both sections to the existing split if present.
    rom = (build.ROOT/'baserom.us.z64').read_bytes()
    paths = []
    for kind, start, end, offset, size in [
        ('rodatabin', 0x1e3f718, 0x1e42550, 0x5640, 0x740),
        ('textbin', 0x1e29b60, 0x1e3f718, 0x25850, 0xf80),
    ]:
        section = zlib.decompress(rom[start+2:end], -15)[offset:offset+size]
        split = build.ROOT/'assets/core1'/('n_aspMain.'+kind+'.bin')
        assert len(section) == size and (not split.exists() or section == split.read_bytes()[:size])
        path = Path(out)/kind
        path.write_bytes(section)
        paths.append(path)
    subprocess.run([build.CLANG, *build.HOST_FLAGS, '-DBT_AUDIO_DEBUG=1', str(here/'audio_mixer.c'),
                    str(here.parent/'host/mixer.c'), str(here.parent/'host/rsp.c'),
                    '-o', str(exe)], check=True)
    subprocess.run([exe, *paths], check=True, env=dict(os.environ, BT_AUDIO_CHECK='1'))
