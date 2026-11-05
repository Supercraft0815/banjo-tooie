#!/usr/bin/env python3
"""Two map layers plus a missing secondary model, using the original map IDs."""
from pathlib import Path
import struct
import subprocess
import sys
import tempfile
import zlib

def model(second=False):
    data = bytearray(268)
    struct.pack_into(">I", data, 0, 11)
    struct.pack_into(">H", data, 8, 80)
    for field, offset in [(16, 88), (28, 240), (32, 200), (36, 192), (48, 160), (52, 184), (56, 176)]:
        struct.pack_into(">I", data, field, offset)
    bounds = (-4000, -1000, -2000, 3000, 9000, 10000) if second else (-1000, -2000, -3000, 4000, 5000, 6000)
    struct.pack_into(">9h3H", data, 88, *bounds, 1, 2, 3, 17, 700, 4)
    for offset in (112, 128):
        struct.pack_into(">3hH2h4B", data, offset, 1, 2, 3, 0, 4, 5, 200, 100, 60, 255)
    data[200] = 2
    struct.pack_into(">6h2B", data, 202, -10, -10, -10, 10, 10, 10, 0, 0)
    struct.pack_into(">6h2B", data, 216, 0, 0, 0, 20, 20, 20, 0, 0)
    struct.pack_into(">H", data, 256, 1)  # one empty collision cell
    expanded = data[:88] + bytearray(8) + data[88:]
    for field in range(4, 68, 4):
        if field == 8:
            continue
        offset = struct.unpack_from(">I", expanded, field)[0]
        if offset >= 88:
            struct.pack_into(">I", expanded, field, offset + 8)
    struct.pack_into(">IHHIHBB", expanded, 80, 32, 1, 0x100, int(second), 8, 4, 8)
    return expanded

payload, entries = bytearray(), []
for index in range(0x1EF8):
    data = model(index == 0x1CFA) if index in (0x1CF9, 0x1CFA, 0x1CFB) else b""
    flags = 0 if data else 1
    if index in (0x1EF6, 0x1EF7):
        raw = bytes([0x51 if index == 0x1EF6 else 0xA2]) * 32
        compressor = zlib.compressobj(wbits=-15)
        data = struct.pack(">H", 2) + compressor.compress(raw) + compressor.flush()
        flags = 19
    entries.append(len(payload) << 6 | flags)
    payload.extend(data)
entries.append(len(payload) << 6)
archive = struct.pack(">II", len(entries), 0xFFFFFFFF) + struct.pack(">" + "I" * len(entries), *entries) + payload
with tempfile.TemporaryDirectory(prefix="tooie-map-") as directory:
    path = Path(directory) / "assets.bin"
    path.write_bytes(archive)
    raise SystemExit(subprocess.call([str(Path(sys.argv[1]).resolve()), str(path)]))
