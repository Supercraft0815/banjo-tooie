"""Compare native graphics constants with the original checked-in N64 data."""
from pathlib import Path
import re
import subprocess
import sys

source = Path(sys.argv[2]).read_text()
words = {
    int(address, 16): int(value, 16)
    for address, value in re.findall(
        r"/\* [0-9A-F]+ ([0-9A-F]+) [0-9A-F]+ \*/ \.word 0x([0-9A-F]+)", source
    )
}
ranges = [(address, 58) for address in (
    0x8011B9B0, 0x8011C830, 0x8011D6B0, 0x8011E530,
    0x8011F3B0, 0x80120230, 0x801210B0, 0x80121F30,
)]
for address, count in ranges:
    if any(words[offset] for offset in range(address + count * 8, address + 0xE80, 4)):
        raise SystemExit(f"Unexpected nonzero render-bank padding at {address:#x}")
ranges += [(0x80122DB0, 3), (0x80122DF0, 24), (0x80122EB0, 24), (0x80122F70, 24)]
expected = [words[offset] for address, count in ranges for offset in range(address, address + count * 8, 4)]
result = subprocess.run([sys.argv[1]], check=True, capture_output=True, text=True)
actual = [int(word, 16) for word in result.stdout.split()]
if actual != expected:
    raise SystemExit("Native model render/texture mode packets differ from the original data")
print(f"All {len(actual) // 2} native model mode packets match the original data.")
