#!/usr/bin/env python3
"""Exercise the native sampler with animation assets from a local extracted archive."""
import argparse
from pathlib import Path
import struct
import subprocess
import tempfile
import zlib


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("archive", type=Path, help="assets/assets.bin from the user's ROM")
    parser.add_argument("sampler", type=Path, help="bt_native_animation_resource_test executable")
    args = parser.parse_args()
    data = args.archive.read_bytes()
    if len(data) < 8:
        parser.error("truncated asset header")
    count = struct.unpack_from(">I", data)[0]
    table_end = 8 + count * 4
    if count < 2 or table_end > len(data):
        parser.error("invalid asset table length")
    with tempfile.TemporaryDirectory(prefix="tooie-animation-") as directory:
        files = []
        for index in range(count - 1):
            word, next_word = struct.unpack_from(">II", data, 8 + index * 4)
            start, end = table_end + (word >> 6), table_end + (next_word >> 6)
            if not table_end <= start <= end <= len(data):
                parser.error(f"asset {index:#x} lies outside the archive")
            if word & 15 != 6:
                continue
            raw = data[start:end]
            if word & 16:
                if len(raw) < 2:
                    parser.error(f"asset {index:#x} has no compressed header")
                limit = int.from_bytes(raw[:2], "big") * 16
                stream = zlib.decompressobj(-15)
                raw = stream.decompress(raw[2:], limit + 1)
                if not stream.eof or len(raw) > limit:
                    parser.error(f"asset {index:#x} exceeds its decoded size")
            path = Path(directory) / f"{index:04x}.bin"
            path.write_bytes(raw)
            files.append(str(path))
        if not files:
            parser.error("archive contains no animation resources")
        print(f"Sampling {len(files)} original animation resources", flush=True)
        return subprocess.call([str(args.sampler.resolve()), *files])


if __name__ == "__main__":
    raise SystemExit(main())
