#!/usr/bin/env python3
"""Reproduce the lagoon section constants from their owning N64 data files."""
from pathlib import Path
import re
import struct
import sys

source, output = map(Path, sys.argv[1:])
for name, start, count, links, disabled in [
    ("top", 0x80800630, 5, 4, 2), ("mid", 0x80800230, 4, 3, 4), ("bot", 0x80800230, 4, 3, 4)
]:
    text = (source / f"_lagoon{name}.data.s").read_text()
    memory = {}
    for address, kind, value in re.findall(r"/\* \w+ ([0-9A-Fa-f]+).*?\*/\s+\.(short|word)\s+(0x[0-9A-Fa-f]+)", text):
        for i, byte in enumerate(int(value, 16).to_bytes(2 if kind == "short" else 4, "big")):
            memory[int(address, 16) + i] = byte
    def read(address, fmt):
        data = bytes(memory[address + i] for i in range(struct.calcsize(fmt)))
        return struct.unpack(fmt, data)
    rows = []
    for i in range(count):
        values = read(start + i * 44, ">9fhHHH")
        vectors = ["{" + ",".join(v.hex() + "f" for v in values[j:j+3]) + "}" for j in (0, 3, 6)]
        rows.append("    {" + ",".join(vectors) + f",{values[9]},{{{values[10]},{values[11]}}}" + "},")
    cursor = start + count * 44
    pairs = [read(cursor + i * 4, ">hh") for i in range(links)]
    cursor += links * 4
    off = read(cursor, ">" + "h" * disabled)
    cursor += disabled * 2
    points = [read(cursor + i * 12, ">3f") for i in range(4 if name == "top" else 1)]
    body = "/* Generated scalar data from the original lagoon overlay. */\n"
    body += "static const NativeMapSectionConfig lagoon_sections[] = {\n" + "\n".join(rows) + "\n};\n"
    body += "static const s16 lagoon_links[][2] = {" + ",".join("{%d,%d}" % pair for pair in pairs) + "};\n"
    body += "static const s16 lagoon_disabled[] = {" + ",".join(map(str, off)) + "};\n"
    body += "static f32 lagoon_points[][3] = {" + ",".join("{" + ",".join(v.hex() + "f" for v in p) + "}" for p in points) + "};\n"
    output.mkdir(parents=True, exist_ok=True)
    (output / f"native_lagoon{name}_data.inc").write_text(body)
