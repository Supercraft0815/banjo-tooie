"""Exercise the retail streaming decoder with synthetic DEFLATE blocks."""
from pathlib import Path
import random
import subprocess
import sys
import tempfile
import zlib


def main():
    samples = [
        (random.Random(807).randbytes(12288), 0, zlib.Z_DEFAULT_STRATEGY, 0),
        (b"BTxyz123" * 576, 6, zlib.Z_FIXED, 1),
        (bytes((i * i + 3 * i) % 53 for i in range(16384)), 6, zlib.Z_DEFAULT_STRATEGY, 2),
        (b"Banjo Tooie 1234" * 32, 6, zlib.Z_FIXED, 1),
    ]
    with tempfile.TemporaryDirectory() as directory:
        command = [sys.argv[1]]
        for index, (raw, level, strategy, block_type) in enumerate(samples):
            encoder = zlib.compressobj(level, wbits=-15, strategy=strategy)
            stream = encoder.compress(raw) + encoder.flush()
            assert (stream[0] >> 1) & 3 == block_type
            assert len(raw) % 16 == 0
            encoded = Path(directory) / f"{index}.deflate"
            expected = Path(directory) / f"{index}.bin"
            encoded.write_bytes((len(raw) // 16).to_bytes(2, "big") + stream)
            expected.write_bytes(raw)
            command.extend((encoded, expected))
        subprocess.run(command, check=True)


if __name__ == "__main__":
    main()
