#!/usr/bin/env python3
"""One triangle model at both an actor ID and an original static-prop lookup ID."""
from pathlib import Path
import struct
import subprocess
import sys
import tempfile

model = bytearray(192)
struct.pack_into(">I", model, 0, 11)
struct.pack_into(">I", model, 16, 80)
struct.pack_into(">I", model, 28, 152)
struct.pack_into(">9h3H", model, 80, -100, 0, -100, 100, 0, 100, 0, 0, 0, 200, 200, 6)
for i, point in enumerate([(-100, 0, -100), (-100, 0, 100), (100, 0, -100)]):
    struct.pack_into(">3h", model, 104 + i * 16, *point)
    model[116+i*16:120+i*16] = bytes((200,100,60,255))
struct.pack_into(">H", model, 168, 1)
struct.pack_into(">H", model, 172, 1)
struct.pack_into(">2H", model, 176, 0, 1)
struct.pack_into(">3H", model, 180, 0, 1, 2)
model.extend(bytes(84))
struct.pack_into(">I", model, 24, 192)
struct.pack_into(">I", model, 40, 216)
struct.pack_into(">fhh3fhh", model, 192, 1.0, 1, 0, 0.0, 0.0, 0.0, 1, -1)
struct.pack_into(">5h9h", model, 216, 1, 1, 0, 3, 3, -100, 0, -100, -100, 0, 100, 100, 0, -100)
model[244:256] = bytes((127,0,0,0,0,127,0,0,0,0,127,0))
struct.pack_into(">6h", model, 256, 0, -1, 1, -1, 2, -2)
payload, entries = bytearray(), []
animation = bytes((0,0,0,10,0,1,0,0,0,0x16,0,2,0,0,0,64,0,10,0,128))
for i in range(1501):
    data = model if i in (148, 1500) else (bytes((255,64,255,128)) if i == 149 else animation if i in (151,152) else b"")
    entries.append(len(payload) << 6 | (0 if i in (148,1500) else 6 if i in (151,152) else 1))
    payload.extend(data)
entries.append(len(payload) << 6)
archive = struct.pack(">II", len(entries), 0xFFFFFFFF) + struct.pack(f">{len(entries)}I", *entries) + payload
with tempfile.TemporaryDirectory(prefix="tooie-world-collision-") as directory:
    path = Path(directory) / "assets.bin"
    path.write_bytes(archive)
    raise SystemExit(subprocess.call([str(Path(sys.argv[1]).resolve()), str(path)]))
