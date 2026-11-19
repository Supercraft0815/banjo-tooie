// Native equivalents of handwritten assembly functions in src/*.s.
#include <ultra64.h>

// src/core1/1E35D40.s: reads one big-endian ROM word through the PI.
s32 rom_read_word(u32 address, u32 *value) {
    osPiReadIo(address, value);
    return 0;
}

// src/core1/memory_asm.s: 8-byte blocks, n rounded down (callers pass n >= 8).
void aligned8_memcpy(void *dst, const void *src, u32 n) {
    __builtin_memcpy(dst, src, n & ~7u);
}

void aligned8_memset(void *dst, u32 value, u32 n) {
    u32 *d = dst;
    for (u32 i = 0; i < (n >> 3) * 2; i++) d[i] = value;
}

// src/core1/inflate_asm.s: Rare's raw DEFLATE decoder, here through zlib.
#include <stdio.h>
#include <stdlib.h>
#include <zlib.h>

static u8 *inflate_input_end;     // D_8007D158
static u32 inflate_crc1, inflate_crc2; // D_8003F760, D_8003F764

void func_8001D1E0(void) {} // builds the fixed Huffman tables; zlib has its own

// Inflates one raw DEFLATE stream that follows a 2-byte header; returns the output size, 0 on a
// bad stream. Like the asm, output may not reach src (when src lies behind dst) or scratch.
s32 func_8001C324(u8 *src, u8 *dst, void *scratch) {
    z_stream z = {0};
    s32 limit = 0x70000000;
    int r;
    if ((s32)(src - dst) > 0) limit = src - dst;
    if ((s32)((u8 *)scratch - dst) >= 0 && (s32)((u8 *)scratch - dst) < limit) limit = (u8 *)scratch - dst;
    if (inflateInit2(&z, -15) != Z_OK) abort();
    z.next_in = src + 2;
    z.avail_in = 0x7FFFFFFF;
    z.next_out = dst;
    z.avail_out = limit;
    r = inflate(&z, Z_FINISH);
    inflate_input_end = src + 2 + z.total_in;
    inflate_crc1 = inflate_crc2 = 0; // asm: per output byte, crc1 += b; crc2 ^= b << (crc1 & 0x17)
    for (uLong i = 0; i < z.total_out; i++) {
        inflate_crc1 += dst[i];
        inflate_crc2 ^= (u32)dst[i] << (inflate_crc1 & 0x17);
    }
    inflateEnd(&z);
    if (r != Z_STREAM_END) {
        fprintf(stderr, "bt_native: inflate failed (%d) at %p\n", r, (void *)src);
        return 0;
    }
    return (s32)z.total_out;
}

s32 func_8001C2F0(u8 *src, u8 *dst, void *scratch) {
    return func_8001C324(src, dst, scratch);
}

u8 *func_8001D30C(void) { return inflate_input_end; }
u32 func_8001D31C(void) { return inflate_crc1; }
u32 func_8001D32C(void) { return inflate_crc2; }

// src/core2/1EF0820.s (bit reader and codes; the tables are 1EF01E0.c): streams a raw DEFLATE
// asset from ROM through 0x800-byte PI DMA chunks into dst and returns dst. The host inflates
// from the ROM image instead; the chunk buffer D_80124A8C is not touched.
u32 __attribute__((import_module("env"), import_name("rom_inflate"))) host_rom_inflate(u32 rom, u32 size, void *dst);
void *func_80117248(u32 rom, s32 size, u8 *dst) {
    host_rom_inflate(rom, size, dst);
    return dst;
}

// src/core2/1EF0140.s: 64-bit shift-register random numbers.
static s32 rng_step(u64 *state) {
    u64 x = *state;
    u64 t = ((x & 1) << 32) | ((x >> 1) & 0xFFFFFFFF);
    t ^= (x & 0xFFFFF) << 12;
    t ^= (t >> 20) & 0xFFF;
    *state = t;
    return (s32)t;
}

extern u64 D_80124A70;
s32 func_80116850(void) { return rng_step(&D_80124A70); }
s32 func_80116898(s64 seed) { D_80124A70 = seed + 1; return 0; }
s32 func_801168AC(u64 *state) { return rng_step(state); }

// asm/nonmatchings/core2/1ED8C80/func_80100368.s: returns what the actor's own getter at +0x10 returns.
void *func_80100368(void *actor) { return (*(void *(**)(void *))((u8 *)actor + 0x10))(actor); }

// src/core2/1ECB9F0.s: float helpers.
static u32 f32_bits(f32 x) { u32 b; __builtin_memcpy(&b, &x, 4); return b; }
static f32 bits_f32(u32 b) { f32 x; __builtin_memcpy(&x, &b, 4); return x; }
// Sign as +-1.0f; both zeros give +0.
f32 func_800F2108(f32 x) { u32 b = f32_bits(x), s = b & 0x80000000u; return bits_f32(b == s ? 0 : 0x3F800000u | s); }
// The argument with the smaller magnitude (b on ties).
f32 func_800F212C(f32 a, f32 b) { return __builtin_fabsf(a) < __builtin_fabsf(b) ? a : b; }
// 0 when |a| < limit, else a.
f32 func_800F214C(f32 a, f32 limit) { return __builtin_fabsf(a) < limit ? 0.0f : a; }
// Zeroes the components of a 3-vector below the limit in magnitude.
void func_800F2168(f32 *v, f32 limit) {
    for (int i = 0; i < 3; i++)
        if (__builtin_fabsf(v[i]) < limit) v[i] = 0.0f;
}
// 1 for NaN.
s32 func_800F219C(f32 x) { u32 b = f32_bits(x) << 1; return (b >> 24) == 0xFF ? (b << 8) != 0 : 0; }
// fpclassify: 0 quiet NaN, 1 signaling NaN, 2/3 +-inf, 4/5 +-normal, 6/7 +-denormal, 8/9 +-0.
u32 func_800F21C4(f32 x) {
    u32 b = f32_bits(x), exp = (b >> 23) & 0xFF, mant = b & 0x7FFFFF, neg = b >> 31;
    if (exp == 0xFF) return mant ? !(mant & 0x400000) : 2 + neg;
    if (exp == 0) return (mant ? 6 : 8) + neg;
    return 4 + neg;
}
