#!/usr/bin/env python3
"""A complete world stream with camera, cube and lighting sections, plus invalid assets."""
from pathlib import Path
import struct
import subprocess
import sys
import tempfile

def integers(tag,*values):
    return bytes([tag])+struct.pack('>'+len(values)*'i',*values)
def floats(tag,*values):
    return bytes([tag])+struct.pack('>'+len(values)*'f',*values)
world=bytes([6])+integers(20,0)+integers(1,0)+integers(2,2)+floats(3,1,2,3)+bytes([0,0])
world+=bytes([7])+integers(10,1)+struct.pack('>hhhHHHIHH',100,100,100,(50<<7)|(6<<1),42,0,(77<<23)|250,0,0)
world+=integers(8,1)+struct.pack('>IhhhH',0x12345678,100,100,100,0)+bytes([1])
world+=bytes([4,1])+floats(2,10,20,30)+floats(3,100,1000)+integers(4,10,20,30)+bytes([0,2,5,0])
payload,entries=bytearray(),[]
for index in range(0x959):
    data=world if index==0x956 else bytes([99,0]) if index==0x957 else bytes([6,20,0]) if index==0x958 else b''
    entries.append(len(payload)<<6|1);payload.extend(data)
entries.append(len(payload)<<6)
archive=struct.pack('>II',len(entries),0xFFFFFFFF)+struct.pack('>'+len(entries)*'I',*entries)+payload
with tempfile.TemporaryDirectory(prefix='tooie-world-') as directory:
    path=Path(directory)/'assets.bin';path.write_bytes(archive)
    raise SystemExit(subprocess.call([str(Path(sys.argv[1]).resolve()),str(path),'world']))
