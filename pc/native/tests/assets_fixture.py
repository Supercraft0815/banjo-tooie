#!/usr/bin/env python3
"""Build synthetic assets for the native manager without copyrighted game data."""
from pathlib import Path
import struct
import subprocess
import sys
import tempfile
import zlib


def main():
    payload = bytearray()
    entries = []
    for index in range(140):
        raw = struct.pack(">10H", 0, 10, 1, 0, 0x16, 2, 0, index * 128, 10, (index + 1) * 128)
        flags = 6
        if index & 1:
            encoder = zlib.compressobj(wbits=-15)
            raw = struct.pack(">H", (len(raw) + 15) // 16) + encoder.compress(raw) + encoder.flush()
            flags |= 16
        if index == 136:
            encoder = zlib.compressobj(wbits=-15)
            raw = b"\x00\x01" + encoder.compress(raw) + encoder.flush()
            flags = 22
        elif index == 137:
            raw = b"\x00\x02\x07"
        elif index == 138:
            raw, flags = b"abc", 3
        elif index == 139:
            raw, flags = b"database", 10
        entries.append(len(payload) << 6 | flags)
        payload.extend(raw)
    entries.append(len(payload) << 6)
    archive = struct.pack(">II", len(entries), 0xFFFFFFFF)
    archive += struct.pack(f">{len(entries)}I", *entries) + payload
    with tempfile.TemporaryDirectory(prefix="tooie-assets-") as directory:
        valid, invalid = Path(directory) / "valid.bin", Path(directory) / "invalid.bin"
        valid.write_bytes(archive)
        invalid.write_bytes(struct.pack(">II", 0x7FFFFFFF, 0))
        return subprocess.call([str(Path(sys.argv[1]).resolve()), str(valid), str(invalid)])


if __name__ == "__main__":
    raise SystemExit(main())
