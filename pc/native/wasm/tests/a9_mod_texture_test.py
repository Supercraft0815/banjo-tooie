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

        # The combined loader must honor package order across Rice and native keys.
        cross_rgba = bytes((1, 2, 3, 4)) * 16
        cross_hash = hash_texture(2, 0, 4, 4, cross_rgba)
        rice_crc, palette_crc = 0x06040200, 0x44003240
        png(temp / 'mods' / 'ricefirst' / 'textures' /
            f'BANJO TOOIE#{rice_crc:08X}#2#0#{palette_crc:08X}_ciByRGBA.png',
            12, 12, bytes((200, 10, 20, 255)))
        png(temp / 'mods' / 'nativesecond' / 'textures' / f'{cross_hash}_4x4.png',
            8, 8, bytes((0, 0, 255, 255)))
        png(temp / 'mods' / 'nativefirst' / 'textures' / f'{cross_hash}_4x4.png',
            8, 8, bytes((0, 0, 255, 255)))
        png(temp / 'mods' / 'ricesecond' / 'textures' /
            f'BANJO TOOIE#{rice_crc:08X}#2#0#{palette_crc:08X}_ciByRGBA.png',
            12, 12, bytes((200, 10, 20, 255)))

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
    bt_mod_texture_init_rom("ricefirst,nativesecond", "BANJO TOOIE");
    int selected=0;
    p=bt_mod_texture_load_best(CROSS_HASH,4,4,1,0x06040200u,0x44003240u,2,0,&w,&h,&selected);
    if(!p||w!=12||h!=12||!selected||((unsigned char*)p)[0]!=200)return 11;
    bt_mod_texture_init_rom("nativefirst,ricesecond", "BANJO TOOIE");
    p=bt_mod_texture_load_best(CROSS_HASH,4,4,1,0x06040200u,0x44003240u,2,0,&w,&h,&selected);
    if(!p||w!=8||h!=8||selected||((unsigned char*)p)[2]!=255)return 12;

    // Model the real 16-bit LoadBlock transfer with DXT=512. TMEM owns the bytes
    // after the guest reuses the original RDRAM source area.
    unsigned char source[2048], saved[2048], tmem[4096]={0}, unpacked[2048];
    for(int i=0;i<2048;i++)source[i]=saved[i]=(unsigned char)(i*37+11);
    unsigned acc=0;
    for(unsigned word=0;word<256;word++) {
        unsigned swizzle=((acc>>11)&1)?4:0;
        for(unsigned i=0;i<8;i++)tmem[((word*8+i)^swizzle)&4095]=source[word*8+i];
        acc+=512;
    }
    uint32_t expected_crc=bt_mod_texture_rice_crc32(saved,64,64,0,32);
    memset(source,0xff,sizeof source);
    int stride=0;
    if(!bt_mod_texture_rice_tmem_unpack(tmem,sizeof tmem,0,32,64,64,0,unpacked,sizeof unpacked,&stride))return 13;
    if(stride!=32||memcmp(unpacked,saved,sizeof saved)||
       bt_mod_texture_rice_crc32(unpacked,64,64,0,stride)!=expected_crc||
       bt_mod_texture_rice_crc32(source,64,64,0,32)==expected_crc)return 14;

    // 8-bit odd width and 16-bit rows both exercise the odd-row XOR-4 path.
    memset(tmem,0,sizeof tmem);
    unsigned char ci8[15], out8[15];
    for(int i=0;i<15;i++)ci8[i]=(unsigned char)(i*13+3);
    for(int y=0;y<3;y++)for(int x=0;x<5;x++)tmem[((y*8+x)^(y&1?4:0))&4095]=ci8[y*5+x];
    if(!bt_mod_texture_rice_tmem_unpack(tmem,sizeof tmem,0,8,5,3,1,out8,sizeof out8,&stride)||
       stride!=5||memcmp(ci8,out8,sizeof ci8)||
       bt_mod_texture_rice_crc32(ci8,5,3,1,5)!=bt_mod_texture_rice_crc32(out8,5,3,1,stride))return 15;

    memset(tmem,0,sizeof tmem);
    unsigned char rgba16[30], out16[30];
    for(int i=0;i<30;i++)rgba16[i]=(unsigned char)(i*17+9);
    for(int y=0;y<3;y++)for(int x=0;x<5;x++)for(int b=0;b<2;b++)
        tmem[((y*16+x*2+b)^(y&1?4:0))&4095]=rgba16[y*10+x*2+b];
    if(!bt_mod_texture_rice_tmem_unpack(tmem,sizeof tmem,0,16,5,3,2,out16,sizeof out16,&stride)||
       stride!=10||memcmp(rgba16,out16,sizeof rgba16)||
       bt_mod_texture_rice_crc32(rgba16,5,3,2,10)!=bt_mod_texture_rice_crc32(out16,5,3,2,stride))return 16;

    // 32-bit N64 texels split RG and BA across the lower/upper TMEM planes.
    memset(tmem,0,sizeof tmem);
    unsigned char rgba32[60], out32[60];
    for(int i=0;i<60;i++)rgba32[i]=(unsigned char)(i*29+7);
    for(int y=0;y<3;y++)for(int x=0;x<5;x++) {
        unsigned a=((y*16+x*2)^(y&1?4:0))&0x7ff; int d=y*20+x*4;
        tmem[a]=rgba32[d]; tmem[a+1]=rgba32[d+1];
        tmem[a|0x800]=rgba32[d+2]; tmem[(a+1)|0x800]=rgba32[d+3];
    }
    if(!bt_mod_texture_rice_tmem_unpack(tmem,sizeof tmem,0,16,5,3,3,out32,sizeof out32,&stride)||
       stride!=20||memcmp(rgba32,out32,sizeof rgba32)||
       bt_mod_texture_rice_crc32(rgba32,5,3,3,20)!=bt_mod_texture_rice_crc32(out32,5,3,3,stride))return 17;
    bt_mod_texture_shutdown();
    return 0;
}
'''.replace('HASH_VALUE', f'0x{key}ULL').replace('CROSS_HASH', f'0x{cross_hash}ULL'))
        exe = temp / 'test'
        subprocess.run(['cc', '-std=c11', '-I', str(HOST), '-I', str(THIRD_PARTY),
                        str(test_c), str(HOST / 'mod_texture.c'), '-lz', '-o', str(exe)], check=True)
        dump_dir = temp / 'dump'
        dump = dump_dir / f'{key}_2x2.png'
        env = dict(os.environ, BT_TEX_DUMP=str(dump_dir))
        subprocess.run([str(exe), str(dump)], cwd=temp, env=env, check=True)
        width, height, pixels = decode_dump(dump)
        assert (width, height, pixels) == (2, 2, bytes((17, 34, 51, 255)) * 4)
        print('A9 textures: native package order; cross-format Rice/native precedence both ways; LoadBlock TMEM overwrite, odd-width CI8, RGBA16 and split-plane RGBA32 swizzle: PASS')


if __name__ == '__main__':
    main()
