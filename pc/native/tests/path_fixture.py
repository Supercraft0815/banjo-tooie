#!/usr/bin/env python3
"""Synthetic path command archive, including truncated streams."""
from pathlib import Path
import struct
import subprocess
import sys
import tempfile
import zlib


def main():
    words = [0x10005, 0, 2, 0x10006, 17, 0, 2, 3, 7 << 16 | 9, 4]
    cases = [(words, "fixture"), (words[:-1], "invalid"), (words[:6], "invalid"), ([0, 2, 3, 4], "invalid")]
    with tempfile.TemporaryDirectory(prefix="tooie-path-") as directory:
        path = Path(directory) / "assets.bin"
        for data, mode in cases:
            raw = struct.pack(f">{len(data)}I", *data)
            encoder = zlib.compressobj(wbits=-15)
            packed = struct.pack(">H", (len(raw) + 15) // 16) + encoder.compress(raw) + encoder.flush()
            entries = [0] * 0xAFF + [0x13, len(packed) << 6]
            archive = struct.pack(">II", len(entries), 0xFFFFFFFF)
            archive += struct.pack(f">{len(entries)}I", *entries) + packed
            path.write_bytes(archive)
            result = subprocess.call([str(Path(sys.argv[1]).resolve()), str(path), mode])
            if result:
                return result
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
