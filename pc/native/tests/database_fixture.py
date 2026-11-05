#!/usr/bin/env python3
"""Exercise encrypted database loading with a fixed key and synthetic data."""
from pathlib import Path
import struct
import subprocess
import sys
import tempfile
import zlib


def main():
    asset_id = 0x9F5
    key = bytes.fromhex("d3711f9f91717bf9f9f9f9f9f9f9")
    encoder = zlib.compressobj(wbits=-15)
    packed = b"\x00\x02" + encoder.compress(b"Native database fixture") + encoder.flush()
    encrypted = bytes(value ^ key[index % 14] for index, value in enumerate(packed))
    entries = [0] * asset_id + [0x1A, len(encrypted) << 6]
    header = struct.pack(">II", len(entries), 0xFFFFFFFF)
    with tempfile.TemporaryDirectory(prefix="tooie-database-") as directory:
        archive = Path(directory) / "database.bin"
        for flags in (0x1A, 0x0A):
            entries[asset_id] = flags
            archive.write_bytes(header + struct.pack(f">{len(entries)}I", *entries) + encrypted)
            result = subprocess.call([str(Path(sys.argv[1]).resolve()), str(archive), "fixture"])
            if result:
                return result
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
