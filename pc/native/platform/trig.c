#include <ultra64.h>

// src/core1/1E2B200.s: table-based trigonometry in degrees (and scaled variants).
// The constants and tables are the ROM data the asm reads.
extern volatile f32 D_800416B0[], D_800416B4[], D_800416B8[], D_800416BC[];
extern volatile f32 D_800416C0[], D_800416C4[], D_800416C8[], D_800416CC[];
extern volatile f32 D_800416D0[], D_800416D4[], D_800416D8[], D_800416DC[];
extern volatile f32 D_800416E0[], D_800416E4[], D_800416E8[], D_800416EC[];
extern volatile f32 D_800416F0[], D_800416F4[], D_800416F8[], D_800416FC[];
extern volatile f32 D_80041700[], D_80041704[], D_80041708[], D_8004170C[];
extern f32 D_8003CC90[2];  // last cos, sin of func_80013818
extern f32 D_8003D3A0[];   // sine table
extern u8 D_8003CCA0[];    // arcsine index tables

static f32 angle_mod(f32 a, f32 k, f32 period) {
    f32 r = a - (f32)(s32)(a * k) * period;
    return r < 0.0f ? r + period : r;
}

f32 func_800136D0(f32 a) { return angle_mod(a, D_800416B0[0], D_800416B4[0]); }
f32 func_800136E4(f32 a) { return angle_mod(a, D_800416B8[0], 360.0f); }
// Wraps to [-180, 180).
f32 func_80013728(f32 a) {
    f32 r = a - (f32)(s32)(a * D_800416BC[0]) * 360.0f;
    if (!(r < 180.0f)) return r - 360.0f;
    return r < -180.0f ? r + 360.0f : r;
}

// Reduces a to one period, scales it to table units and interpolates; off 0x800 = cosine.
static f32 table_lookup(f32 a, f32 k, f32 period, f32 fk, u32 off) {
    a = (a - (f32)(s32)(a * k) * period) * k;
    s32 i = (s32)__builtin_rintf(a * 8388608.0f);
    f32 frac = (f32)(i & 0xFFF) * fk;
    const f32 *t = (const f32 *)((u8 *)D_8003D3A0 + ((((u32)i >> 10) + off) & 0x1FFC));
    return (t[1] - t[0]) * frac + t[0];
}

static void sincos_store(f32 a, f32 k, f32 period) {
    D_8003CC90[1] = table_lookup(a, k, period, D_800416D8[0], 0);
    D_8003CC90[0] = table_lookup(a, k, period, D_800416D8[0], 0x800);
}
f32 func_800137AC(f32 a) { sincos_store(a, D_800416C8[0], 360.0f); return D_8003CC90[0]; }
f32 func_800137F4(f32 a) { sincos_store(a, D_800416D4[0], 360.0f); return D_8003CC90[1]; }
f32 func_80013788(void) { return D_8003CC90[0]; }
f32 func_800137C4(void) { return D_8003CC90[1]; }
f32 func_80013798(f32 a) { sincos_store(a, D_800416C0[0], D_800416C4[0]); return D_8003CC90[0]; }
f32 func_800137D4(f32 a) { sincos_store(a, D_800416CC[0], D_800416D0[0]); return D_8003CC90[1]; }
f32 func_800138BC(f32 a) { return table_lookup(a, D_800416DC[0], D_800416E0[0], D_800416E8[0], 0x800); }
f32 func_800138D0(f32 a) { return table_lookup(a, D_800416E4[0], 360.0f, D_800416E8[0], 0x800); }
f32 func_8001395C(f32 a) { return table_lookup(a, D_800416EC[0], D_800416F0[0], D_800416F8[0], 0); }
f32 func_80013970(f32 a) { return table_lookup(a, D_800416F4[0], 360.0f, D_800416F8[0], 0); }
// Tangent through func_80013818 (so it also sets the last sine/cosine); +-0x7F000000 where cos is 0.
f32 func_800139F8(f32 a) {
    sincos_store(a, D_800416FC[0], 360.0f);
    if (D_8003CC90[0] != 0.0f) return D_8003CC90[1] / D_8003CC90[0];
    return D_8003CC90[1] < 0.0f ? -0x1p127f : 0x1p127f;
}

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
f32 func_80013A5C(f32 x) { return D_80041704[0] - arcsin_scaled(x, D_80041700[0]); }
f32 func_80013AA0(f32 x) { return arcsin_scaled(x, D_80041708[0]); }
f32 func_80013AAC(f32 x) { return arcsin_scaled(x, 0.17578125f); }
f32 func_80013A7C(f32 x) { return 90.0f - arcsin_scaled(x, 0.17578125f); }

// func_80013B70/7C: atan2-like angle of (x, y) in degrees, 0..360; 80013B70 takes the length.
f32 func_80013B70(f32 x, f32 y, f32 len) {
    if (x == 0.0f) return 0.0f <= y ? 0.0f : 180.0f;
    if (y == 0.0f) return 0.0f < x ? 90.0f : 270.0f;
    f32 r = arcsin_scaled(x / len, 0.17578125f);
    if (y < 0.0f) r = 180.0f - r;
    return r < 0.0f ? 360.0f + r : r;
}
f32 func_80013B7C(f32 x, f32 y) { return func_80013B70(x, y, __builtin_sqrtf(y * y + x * x)); }
f32 func_80013C48(f32 x, f32 y) { return func_80013B7C(x, y) * D_8004170C[0]; }
