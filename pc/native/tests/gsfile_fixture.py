#!/usr/bin/env python3
"""Raw, compressed, broken and map-indexed streams for the original gs/maker C."""
from pathlib import Path
import struct
import subprocess
import sys
import tempfile
import zlib

wire = bytes.fromhex(
    "11 ab 12 00 01 fe ff 13 bfc00000 14 80000000 7fc12345 "
    "15 89abcdef 16 00000001 80000000 17 55aa 18 fedc 19 0001 8000 00"
)
payload, entries = bytearray(), []
for index in range(0xA03):
    raw, flags = b"", 1
    if index in (1, 0xA02):
        raw = wire
    elif index == 2:
        compressor = zlib.compressobj(wbits=-15)
        raw = struct.pack(">H", (len(wire) + 15) // 16) + compressor.compress(wire) + compressor.flush()
        flags |= 16
    elif index == 3:
        raw, flags = b"\x00\x02\xff", 17
    entries.append(len(payload) << 6 | flags)
    payload.extend(raw)
entries.append(len(payload) << 6)
archive = struct.pack(">II", len(entries), 0xFFFFFFFF)
archive += struct.pack(f">{len(entries)}I", *entries) + payload
with tempfile.TemporaryDirectory(prefix="tooie-gsfile-") as directory:
    path = Path(directory) / "assets.bin"
    path.write_bytes(archive)
    raise SystemExit(subprocess.call([str(Path(sys.argv[1]).resolve()), str(path), "fixture"]))
