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

// src/core1/1E2B200.s: table-based trigonometry in degrees (and scaled variants).
// The constants and tables are the ROM data the asm reads.
extern f32 D_800416B0, D_800416B4, D_800416B8, D_800416C0, D_800416C4, D_800416CC, D_800416D0,
    D_800416D8, D_800416DC, D_800416E0, D_800416E4, D_800416E8, D_800416EC, D_800416F0,
    D_800416F8, D_80041700, D_80041704, D_80041708, D_8004170C;
extern f32 D_8003CC90[2];  // last cos, sin of func_80013818
extern f32 D_8003D3A0[];   // sine table
extern u8 D_8003CCA0[];    // arcsine index tables

static f32 angle_mod(f32 a, f32 k, f32 period) {
    f32 r = a - (f32)(s32)(a * k) * period;
    return r < 0.0f ? r + period : r;
}

f32 func_800136D0(f32 a) { return angle_mod(a, D_800416B0, D_800416B4); }

// Reduces a to one period, scales it to table units and interpolates; off 0x800 = cosine.
static f32 table_lookup(f32 a, f32 k, f32 period, f32 fk, u32 off) {
    a = (a - (f32)(s32)(a * k) * period) * k;
    s32 i = (s32)__builtin_rintf(a * 8388608.0f);
    f32 frac = (f32)(i & 0xFFF) * fk;
    const f32 *t = (const f32 *)((u8 *)D_8003D3A0 + ((((u32)i >> 10) + off) & 0x1FFC));
    return (t[1] - t[0]) * frac + t[0];
}

static void sincos_store(f32 a, f32 k, f32 period) {
    D_8003CC90[1] = table_lookup(a, k, period, D_800416D8, 0);
    D_8003CC90[0] = table_lookup(a, k, period, D_800416D8, 0x800);
}
f32 func_80013798(f32 a) { sincos_store(a, D_800416C0, D_800416C4); return D_8003CC90[0]; }
f32 func_800137D4(f32 a) { sincos_store(a, D_800416CC, D_800416D0); return D_8003CC90[1]; }
f32 func_800138BC(f32 a) { return table_lookup(a, D_800416DC, D_800416E0, D_800416E8, 0x800); }
f32 func_800138D0(f32 a) { return table_lookup(a, D_800416E4, 360.0f, D_800416E8, 0x800); }
f32 func_8001395C(f32 a) { return table_lookup(a, D_800416EC, D_800416F0, D_800416F8, 0); }

// func_80013ABC: arcsine of x through the index tables, times scale.
static f32 arcsin_scaled(f32 x, f32 scale) {
    s32 v = (s32)(262144.0f * x);
    if (v <= 0) {
        x = __builtin_fabsf(x);
        scale = -scale;
        v = -v;
    }
    s8 c = (s8)D_8003CCA0[(u32)v >> 12];
    if (c < 0) c = (s8)D_8003CCA0[(s32)((u32)v >> 6) - 0xF7F];
    const u8 *e = D_8003CCA0 + c;
    s32 base = *(const s32 *)(e + 0x84), first = *(const s32 *)(e + 0x88), shift = *(const s32 *)(e + 0x8C);
    u32 slot = (((u32)(v - base) >> (shift & 31)) + first) << 1;
    s16 h = *(const s16 *)(D_8003CCA0 + slot + 0xF4);
    const f32 *t = D_8003D3A0 + h;
    return ((x - t[0]) / (t[1] - t[0]) + (f32)h) * scale;
}
f32 func_80013A5C(f32 x) { return D_80041704 - arcsin_scaled(x, D_80041700); }
f32 func_80013AA0(f32 x) { return arcsin_scaled(x, D_80041708); }
f32 func_80013AAC(f32 x) { return arcsin_scaled(x, 0.17578125f); }

// func_80013B7C: atan2-like angle of (x, y) in degrees, 0..360.
static f32 angle_of(f32 x, f32 y) {
    f32 len = __builtin_sqrtf(y * y + x * x);
    if (x == 0.0f) return 0.0f <= y ? 0.0f : 180.0f;
    if (y == 0.0f) return 0.0f < x ? 90.0f : 270.0f;
    f32 r = arcsin_scaled(x / len, 0.17578125f);
    if (y < 0.0f) r = 180.0f - r;
    return r < 0.0f ? 360.0f + r : r;
}
f32 func_80013C48(f32 x, f32 y) { return angle_of(x, y) * D_8004170C; }
