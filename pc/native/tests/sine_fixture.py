"""Emit the original trigonometric tables in the layout used by native tests."""
import struct
import sys
from pathlib import Path


def generate(rom, output):
    # Offsets in the US decompressed ROM, from core1data1 and 1E591D0.
    def floats(offset, count):
        rom.seek(offset)
        return struct.unpack(f'>{count}f', rom.read(count * 4))

    # Arcsine first indexes bytes, then loads words at +0x84 and halfwords at +0xf4.
    rom.seek(0x1E547D0)
    lookup = rom.read(0x700)
    layout = '132s28I774H'
    parts = struct.unpack('>' + layout, lookup)
    output.write('_Alignas(4) unsigned char D_8003CCA0[] = {\n')
    output.write('#if defined(__BYTE_ORDER__) && __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__\n')
    for order in ('>', '<'):
        if order == '<':
            output.write('#else\n')
        data = struct.pack(order + layout, *parts)
        for start in range(0, len(data), 24):
            output.write('    ' + ','.join(map(str, data[start:start + 24])) + ',\n')
    output.write('#endif\n};\n')

    samples = floats(0x1E54ED0, 2052)
    if samples[0] != 0 or samples[512] != 1 or samples[1536] != -1:
        raise ValueError('unexpected US sine table')
    output.write('float D_8003D3A0[] = {\n')
    for index in range(0, len(samples), 8):
        output.write('    ' + ', '.join(x.hex() + 'f' for x in samples[index:index + 8]) + ',\n')
    output.write('};\n')
    last = floats(0x1E547C0, 4)
    output.write('float D_8003CC90[] = {' + ', '.join(x.hex() + 'f' for x in last) + '};\n')


if __name__ == '__main__':
    with Path(sys.argv[1]).open('rb') as rom, Path(sys.argv[2]).open('w') as output:
        generate(rom, output)
