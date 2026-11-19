"""PNG indexing, valid ratios, package priority, and decodable texture dumps."""
import os
import pathlib
import struct
import subprocess
import tempfile
import zlib

ROOT = pathlib.Path(__file__).resolve().parents[1]
HOST = ROOT / 'host'
THIRD_PARTY = ROOT.parent / 'third_party'


def png(path, width, height, rgba):
    row = rgba * width if len(rgba) == 4 else rgba
    assert len(row) == width * 4
    raw = (b'\0' + row) * height

    def chunk(name, payload):
        return (struct.pack('>I', len(payload)) + name + payload +
                struct.pack('>I', zlib.crc32(name + payload) & 0xffffffff))

    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_bytes(b'\x89PNG\r\n\x1a\n' +
                     chunk(b'IHDR', struct.pack('>IIBBBBB', width, height, 8, 6, 0, 0, 0)) +
                     chunk(b'IDAT', zlib.compress(raw)) + chunk(b'IEND', b''))


def hash_texture(fmt, siz, width, height, rgba):
    payload = b''.join(struct.pack('<I', value) for value in (fmt, siz, width, height)) + rgba * (width * height)
    value = 14695981039346656037
    for byte in payload:
        value = ((value ^ byte) * 1099511628211) & 0xffffffffffffffff
    return f'{value:016x}'


def decode_dump(path):
    data = path.read_bytes()
    assert data[:8] == b'\x89PNG\r\n\x1a\n', 'bad PNG signature'
    chunks, compressed = [], bytearray()
    offset = 8
    while offset < len(data):
        size = struct.unpack_from('>I', data, offset)[0]
        kind = data[offset + 4:offset + 8]
        payload = data[offset + 8:offset + 8 + size]
        crc = struct.unpack_from('>I', data, offset + 8 + size)[0]
        assert zlib.crc32(kind + payload) & 0xffffffff == crc, f'bad {kind!r} CRC'
        chunks.append(kind)
        if kind == b'IHDR':
            width, height, depth, color, compression, filtering, interlace = struct.unpack('>IIBBBBB', payload)
            assert depth == 8 and color == 6 and not compression and not filtering and not interlace
        elif kind == b'IDAT':
            compressed.extend(payload)
        offset += 12 + size
        if kind == b'IEND':
            break
    assert offset == len(data) and chunks == [b'IHDR', b'IDAT', b'IEND']
    raw = zlib.decompress(compressed)
    stride = width * 4
    rows = [raw[y * (stride + 1) + 1:(y + 1) * (stride + 1)]
            for y in range(height) if raw[y * (stride + 1)] == 0]
    assert len(rows) == height and all(len(row) == stride for row in rows)
    return width, height, b''.join(rows)


def main():
    with tempfile.TemporaryDirectory(prefix='a9-modtex-') as temporary:
        temp = pathlib.Path(temporary)
        base = bytes((17, 34, 51, 255))
        key = hash_texture(0, 0, 2, 2, base)
        fixtures = {
            'first': (16, 16, bytes((10, 220, 30, 255))),  # 8x
            'second': (8, 8, bytes((220, 10, 30, 255))),  # 4x
            'third': (6, 6, bytes((30, 90, 210, 255))),   # 3x
            'bad': (6, 4, bytes((50, 60, 70, 255))),      # 3x by 2x
            'one': (2, 2, bytes((80, 90, 100, 255))),    # 1x
            'misnamed': (6, 6, bytes((110, 120, 130, 255))),
        }
        for package, (width, height, color) in fixtures.items():
            leaf_width, leaf_height = (3, 3) if package == 'misnamed' else (2, 2)
            png(temp / 'mods' / package / 'textures' / f'{key}_{leaf_width}x{leaf_height}.png',
                width, height, color)

        test_c = temp / 'test.c'
        test_c.write_text(r'''#include "mod_texture.h"
#include "stb_image.h"
#include <stdint.h>
#include <stdio.h>
#include <string.h>
int main(int argc, char **argv) {
    const uint64_t hash = HASH_VALUE;
    int w=0,h=0;
    uint32_t *p;
    bt_mod_texture_init("first,second");
    p=bt_mod_texture_load(hash,2,2,&w,&h);
    if(!p||w!=16||h!=16||((unsigned char*)p)[0]!=10)return 1;
    bt_mod_texture_init("second,first");
    p=bt_mod_texture_load(hash,2,2,&w,&h);
    if(!p||w!=8||h!=8||((unsigned char*)p)[0]!=220)return 2;
    bt_mod_texture_init("third");
    p=bt_mod_texture_load(hash,2,2,&w,&h);
    if(!p||w!=6||h!=6||((unsigned char*)p)[0]!=30)return 3;
    bt_mod_texture_init("bad");
    if(bt_mod_texture_load(hash,2,2,&w,&h))return 4;
    bt_mod_texture_init("one");
    if(bt_mod_texture_load(hash,2,2,&w,&h))return 5;
    bt_mod_texture_init("misnamed");
    if(bt_mod_texture_load(hash,2,2,&w,&h))return 6;
    bt_mod_texture_init("");
    if(bt_mod_texture_load(hash,2,2,&w,&h))return 7;
    bt_mod_texture_init("../first");
    if(bt_mod_texture_load(hash,2,2,&w,&h))return 8;
    uint32_t pixels[4]={0xff332211,0xff332211,0xff332211,0xff332211};
    bt_mod_texture_dump(hash,2,2,pixels);
    int dw=0,dh=0,channels=0;
    unsigned char *decoded=stbi_load(argv[1],&dw,&dh,&channels,4);
    if(!decoded||dw!=2||dh!=2||channels!=4)return 9;
    for(int i=0;i<16;i++)if(decoded[i]!=((unsigned char*)pixels)[i])return 10;
    stbi_image_free(decoded);
    bt_mod_texture_shutdown();
    return 0;
}
'''.replace('HASH_VALUE', f'0x{key}ULL'))
        exe = temp / 'test'
        subprocess.run(['cc', '-std=c11', '-I', str(HOST), '-I', str(THIRD_PARTY),
                        str(test_c), str(HOST / 'mod_texture.c'), '-lz', '-o', str(exe)], check=True)
        dump_dir = temp / 'dump'
        dump = dump_dir / f'{key}_2x2.png'
        env = dict(os.environ, BT_TEX_DUMP=str(dump_dir))
        subprocess.run([str(exe), str(dump)], cwd=temp, env=env, check=True)
        width, height, pixels = decode_dump(dump)
        assert (width, height, pixels) == (2, 2, bytes((17, 34, 51, 255)) * 4)
        print('A9 textures: package priority, 8x/4x/3x, bad aspect, 1x, base dimensions, and PNG dump decode: PASS')


if __name__ == '__main__':
    main()
