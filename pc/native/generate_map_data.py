#!/usr/bin/env python3
"""Emit native scalar map tables from the owning N64 assembly data."""
from pathlib import Path
import re
import struct
import sys

source = Path(sys.argv[1]).read_text()

def shorts(label, end=None):
    body = source.split(f"dlabel {label}\n", 1)[1]
    if end:
        body = body.split(f"dlabel {end}\n", 1)[0]
    values = re.findall(r"\.short (0x[0-9A-Fa-f]+)", body)
    return b"".join(struct.pack(">H", int(value, 16)) for value in values)

data = shorts("D_80800F10_gcmapDll", "D_80801B98_gcmapDll")
rows = []
for offset in range(0, len(data) - 13, 14):
    row = struct.unpack_from(">hHH6b2B", data, offset)
    rows.append("    {%d,{%d,%d},{%s},{%d,%d}}," %
                (*row[:3], ",".join(map(str, row[3:9])), *row[9:]))
    if row[0] == 0:
        break
else:
    raise ValueError("map table has no terminator")
cells = []
for map_id, size in struct.iter_unpack(">hh", shorts("D_80801BE8_gcmapDll")):
    if size <= 0:
        raise ValueError("invalid map cell size")
    cells.append(f"    {{{map_id},{size}}},")
    if map_id == -1:
        break
else:
    raise ValueError("cell-size table has no terminator")
output = Path(sys.argv[2])
output.parent.mkdir(parents=True, exist_ok=True)
output.write_text("/* Generated from gc/mapDll.data.s; scalar data only. */\n"
                  "const NativeMapConfig native_map_configs[] = {\n" + "\n".join(rows) +
                  "\n};\nconst s16 native_map_cell_sizes[][2] = {\n" + "\n".join(cells) + "\n};\n")
