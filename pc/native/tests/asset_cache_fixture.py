#!/usr/bin/env python3
"""Synthetic animation/model resources for the game cache integration test."""
from pathlib import Path
import struct
import subprocess
import sys
import tempfile
import zlib


def main():
    payload, entries = bytearray(), []
    for index in range(160):
        raw = struct.pack(">10H", 0, 10, 1, 0, 0x16, 2, 0, index * 128, 10, (index + 1) * 128)
        flags = 6
        if index & 1:
            encoder = zlib.compressobj(wbits=-15)
            raw = b"\x00\x02" + encoder.compress(raw) + encoder.flush()
            flags |= 16
        if 145 <= index <= 148:
            flags = 0
            raw = bytearray(104)
            struct.pack_into(">I", raw, 0, 11)
            struct.pack_into(">I", raw, 16, 80)
            struct.pack_into(">I", raw, 44, 104 if index != 148 else 0)
            struct.pack_into(">9h3H", raw, 80, -10, -20, -30, 40, 50, 60, -3, 4, 5, 17, 70, 0)
            if index == 145:
                raw += b"".join(struct.pack(">hhf", i + 1, 100 + i, 4.0) for i in range(7))
            elif index == 146:
                raw = raw[:16]
            elif index == 147:
                struct.pack_into(">I", raw, 44, 0xFFFFFFF0)
        elif 149 <= index <= 151:
            flags, raw = index - 142, bytes(range(64))
        elif index == 152:
            flags, raw = 1, b"native raw asset"
        entries.append(len(payload) << 6 | flags)
        payload.extend(raw)
    entries.append(len(payload) << 6)
    archive = struct.pack(">II", len(entries), 0xFFFFFFFF)
    archive += struct.pack(f">{len(entries)}I", *entries) + payload
    with tempfile.TemporaryDirectory(prefix="tooie-cache-") as directory:
        path = Path(directory) / "assets.bin"
        path.write_bytes(archive)
        return subprocess.call([str(Path(sys.argv[1]).resolve()), str(path), "fixture"])


if __name__ == "__main__":
    raise SystemExit(main())
