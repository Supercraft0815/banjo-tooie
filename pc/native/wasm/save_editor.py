#!/usr/bin/env python3
"""Create/edit a separate US 16-Kbit EEPROM fixture using the game's tagged save format."""
import argparse
from pathlib import Path
import re
import struct
import sys

ROOT = Path(__file__).resolve().parents[3]
SIZES = {1: 2, 2: 1, 3: 28, 4: 42, 5: 46, 6: 176, 0: 0}
SLOT_SIZE = 0x1C0


def checksum(payload):
    # gl/crc.c and the 64-bit shift register in core2/1EF0140.s.
    seed, shift, result = 0x8F809F473108B3C1, 0, []
    for data, step in ((payload, 7), (reversed(payload), 3)):
        crc = 0
        for byte in data:
            seed = (seed + (byte << (shift & 15))) & 0xFFFFFFFFFFFFFFFF
            word = ((seed & 1) << 32) | ((seed >> 1) & 0xFFFFFFFF)
            word ^= (seed & 0xFFFFF) << 12
            seed = word ^ ((word >> 20) & 0xFFF)
            crc ^= seed & 0xFFFFFFFF
            shift += step
        result.append(crc)
    return struct.pack('>II', *result)


def records(block):
    if len(block) != SLOT_SIZE or block[:4] != b'KHJC':
        raise ValueError('not a KHJC game record')
    if checksum(block[:-8]) != block[-8:]:
        raise ValueError('game-record checksum mismatch')
    found, offset = {}, 4
    while offset + 2 <= SLOT_SIZE - 8:
        tag, size = block[offset:offset + 2]
        offset += 2
        if tag in found or tag not in SIZES or size != SIZES[tag] or offset + size > SLOT_SIZE - 8:
            raise ValueError('invalid or duplicate save section')
        found[tag] = (offset, size)
        offset += size
        if tag == 0:
            if found.keys() != SIZES.keys() or block[found[1][0]] != 0x1E:
                raise ValueError('incomplete or unsupported game record')
            return found
    raise ValueError('unterminated game record')


def new_record(slot):
    if slot not in range(3):
        raise ValueError('logical slot must be 0, 1 or 2')
    block = bytearray(b'KHJC')
    for tag, size in SIZES.items():
        block.extend((tag, size))
        block.extend(bytes(size))
    block.extend(bytes(SLOT_SIZE - len(block)))
    # The version and one-based logical slot are fields 1 and 2 (gl/gamedata.c).
    block[6] = 0x1E
    block[10] = slot + 1
    block[-8:] = checksum(block[:-8])
    records(block)
    return block


# What a new game sets (func_800C6E60): the Banjo-Kazooie moves and blue eggs. A save without
# them is no state the game can reach: egg nests then loop forever looking for an egg type.
START_ABILITIES = [0xED + a for a in [*range(0x14), 0x31]] + [0xEE + a for a in range(0x3C, 0x49)]


def edit(image, slot, changes, create=False):
    if len(image) != 2048 or slot not in range(3):
        raise ValueError('expected exactly 2048 EEPROM bytes and logical slot 0..2')
    image = bytearray(image)
    matches = []
    for physical in range(4):
        start = 0x100 + physical * SLOT_SIZE
        block = image[start:start + SLOT_SIZE]
        if block[:4] == b'KHJC':
            fields = records(block)
            if block[fields[2][0]] == slot + 1:
                matches.append(start)
    if create:
        if matches:
            raise ValueError('logical slot already exists')
        empty = [0x100 + i * SLOT_SIZE for i in range(4)
                 if not any(image[0x100 + i * SLOT_SIZE:0x100 + (i + 1) * SLOT_SIZE])]
        if not empty:
            raise ValueError('no empty physical record')
        start = empty[0]
        image[start:start + SLOT_SIZE] = new_record(slot)
        matches = [start]
    if len(matches) != 1:
        raise ValueError('expected one valid physical record for the logical slot')
    start = matches[0]
    block = image[start:start + SLOT_SIZE]
    flags, _ = records(block)[6]
    for flag, enabled in changes:
        if not 0x28 < flag < 0x5A5:
            raise ValueError(f'flag {flag:#x} is not in the permanent save bank')
        bit = flag - 0x28
        if enabled:
            block[flags + bit // 8] |= 1 << (bit & 7)
        else:
            block[flags + bit // 8] &= ~(1 << (bit & 7))
    block[-8:] = checksum(block[:-8])
    records(block)
    image[start:start + SLOT_SIZE] = block
    return bytes(image)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('output', type=Path, help='new output file; never overwrites a save')
    parser.add_argument('--input', type=Path, help='existing 2048-byte EEPROM; otherwise starts empty')
    parser.add_argument('--slot', type=int, choices=range(3), default=0)
    parser.add_argument('--create', action='store_true', help='create a new logical game record')
    parser.add_argument('--set-flag', action='append', default=[], metavar='NAME_OR_ID')
    parser.add_argument('--clear-flag', action='append', default=[], metavar='NAME_OR_ID')
    args = parser.parse_args()
    names = dict((name, int(number, 16)) for name, number in re.findall(
        r'\b(FLAG_\w+)\s*=\s*(0x[0-9A-Fa-f]+)', (ROOT / 'include/gameflags.h').read_text()))
    try:
        changes = [(names[name] if name in names else int(name, 0), enabled)
                   for items, enabled in ((args.set_flag, True), (args.clear_flag, False)) for name in items]
        result = edit(args.input.read_bytes() if args.input else bytes(2048), args.slot, changes, args.create)
        with args.output.open('xb') as output:
            output.write(result)
    except (OSError, ValueError) as error:
        parser.exit(2, f'{error}\n')
    return 0


if __name__ == '__main__':
    sys.exit(main())
