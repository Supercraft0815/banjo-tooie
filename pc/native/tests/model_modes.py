"""Compare native graphics packets with the US decompressed game's render banks."""
from pathlib import Path
import struct
import subprocess
import sys

# Eight banks occupy 0xE80 bytes each. Segment-3 display lists use the first 58 packets.
expected = bytearray()
with Path(sys.argv[2]).open("rb") as rom:
    rom.seek(0x1EF52A0)
    for bank in range(8):
        packets = rom.read(0xE80)
        if len(packets) != 0xE80 or any(packets[58 * 8:]):
            raise SystemExit(f"Unexpected render bank {bank} length or padding")
        expected.extend(packets[:58 * 8])
    # Render-state restore and the three texture-mode lists.
    for offset, count in [(0x1EFC6A0, 3), (0x1EFC6E0, 24), (0x1EFC7A0, 24), (0x1EFC860, 24)]:
        rom.seek(offset)
        expected.extend(rom.read(count * 8))

result = subprocess.run([sys.argv[1]], check=True, capture_output=True, text=True)
actual = b"".join(struct.pack(">I", int(word, 16)) for word in result.stdout.split())
if actual != expected or len(actual) != 539 * 8:
    raise SystemExit("Native model render/texture mode packets differ from the original data")
print("All 539 native model mode packets match the original data.")
