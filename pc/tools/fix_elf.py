#!/usr/bin/env python3
"""Copies the decomp ELF and gives sizes to handwritten inner entry points, which N64Recomp skips at size 0."""
import pathlib
import struct

root = pathlib.Path(__file__).resolve().parents[1]
data = bytearray((root.parent / "build/us/banjotooie_decompressed.elf").read_bytes())

SIZES = {b"func_800136E4": 0x44, b"func_800138D0": 0x8C, b"func_80013970": 0x88}

shoff, = struct.unpack_from(">I", data, 0x20)
shentsize, shnum = struct.unpack_from(">HH", data, 0x2E)
sections = [struct.unpack_from(">10I", data, shoff + i * shentsize) for i in range(shnum)]
symtab = next(s for s in sections if s[1] == 2)  # SHT_SYMTAB
strtab = sections[symtab[6]]

patched = 0
for off in range(symtab[4], symtab[4] + symtab[5], 16):
    name_off, = struct.unpack_from(">I", data, off)
    start = strtab[4] + name_off
    name = bytes(data[start:data.index(0, start)])
    if name in SIZES:
        struct.pack_into(">I", data, off + 8, SIZES[name])
        patched += 1

assert patched == len(SIZES), f"expected {len(SIZES)} symbols, patched {patched}"
(root / "tooie.elf").write_bytes(data)
print(f"patched {patched} symbols")
