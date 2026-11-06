// Native equivalents of handwritten assembly functions in src/*.s.
#include <ultra64.h>

// src/core1/1E35D40.s: reads one big-endian ROM word through the PI.
s32 rom_read_word(u32 address, u32 *value) {
    osPiReadIo(address, value);
    return 0;
}

// src/core1/inflate_asm.s: Rare's raw DEFLATE decoder, here through zlib.
#include <stdio.h>
#include <stdlib.h>
#include <zlib.h>

static u8 *inflate_input_end;     // D_8007D158
static u32 inflate_crc1, inflate_crc2; // D_8003F760, D_8003F764

void func_8001D1E0(void) {} // builds the fixed Huffman tables; zlib has its own

// Inflates one raw DEFLATE stream; returns the output size. Like the N64 routine
// it has no output bound, so the caller's buffer must be large enough.
s32 func_8001C324(u8 *src, u8 *dst, void *scratch) {
    z_stream z = {0};
    int r;
    (void)scratch;
    if (inflateInit2(&z, -15) != Z_OK) abort();
    z.next_in = src;
    z.avail_in = 0x7FFFFFFF;
    z.next_out = dst;
    z.avail_out = 0x7FFFFFFF;
    r = inflate(&z, Z_FINISH);
    if (r != Z_STREAM_END) {
        fprintf(stderr, "bt_native: inflate failed (%d) at %p\n", r, (void *)src);
        abort();
    }
    inflate_input_end = src + z.total_in;
    // shortcut: assumes the asm checksum equals crc.c's byte sum/xor-shift; only the
    // N64 overlay loader compares it, which the native build does not run.
    inflate_crc1 = inflate_crc2 = 0;
    for (uLong i = 0; i < z.total_out; i++) {
        inflate_crc1 += dst[i];
        inflate_crc2 ^= (u32)dst[i] << (inflate_crc1 & 0x17);
    }
    inflateEnd(&z);
    return (s32)z.total_out;
}

s32 func_8001C2F0(u8 *src, u8 *dst, void *scratch) {
    return func_8001C324(src, dst, scratch);
}

u8 *func_8001D30C(void) { return inflate_input_end; }
u32 func_8001D31C(void) { return inflate_crc1; }
u32 func_8001D32C(void) { return inflate_crc2; }
