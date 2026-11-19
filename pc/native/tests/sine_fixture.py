"""Compare the compiled trigonometric tables with their US ROM image."""
from pathlib import Path
import struct
import subprocess
import sys

layout = "4f132b28i774h2052f"
with Path(sys.argv[2]).open("rb") as rom:
    rom.seek(0x1E547C0)
    values = struct.unpack(">" + layout, rom.read(struct.calcsize(">" + layout)))

actual = subprocess.run([sys.argv[1]], check=True, capture_output=True, text=True)
if bytes.fromhex(actual.stdout) != struct.pack("=" + layout, *values):
    raise SystemExit("Native trigonometric tables differ from the US ROM")
