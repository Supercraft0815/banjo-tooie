// Software RDP (see rdp.h): TMEM loads, texture sampling, color combiner, blender,
// 16-bit N64 depth buffer, fill/copy/1-cycle/2-cycle rectangles and triangles.
// shortcut: no coverage/anti-aliasing, dithering or chroma key; the blender treats
// memory coverage as full. Upgrade when an effect visibly depends on them.
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rdp.h"

typedef struct {
    int fmt, siz, line, tmem, pal, cms, cmt, masks, maskt, shifts, shiftt;
    int uls, ult, lrs, lrt;  // 10.2
} Tile;

// Combiner sources; the *_A entries hold an alpha in all four channels.
enum { C_COMB, C_T0, C_T1, C_PRIM, C_SHADE, C_ENV, C_ONE, C_ZERO, C_NOISE, C_KEYC, C_KEYS, C_K4, C_K5,
       C_COMB_A, C_T0_A, C_T1_A, C_PRIM_A, C_SHADE_A, C_ENV_A, C_LOD, C_PLOD, C_N };
static const u8 SEL_A[16] = {C_COMB, C_T0, C_T1, C_PRIM, C_SHADE, C_ENV, C_ONE, C_NOISE,
                             C_ZERO, C_ZERO, C_ZERO, C_ZERO, C_ZERO, C_ZERO, C_ZERO, C_ZERO};
static const u8 SEL_B[16] = {C_COMB, C_T0, C_T1, C_PRIM, C_SHADE, C_ENV, C_KEYC, C_K4,
                             C_ZERO, C_ZERO, C_ZERO, C_ZERO, C_ZERO, C_ZERO, C_ZERO, C_ZERO};
static const u8 SEL_C[32] = {C_COMB, C_T0, C_T1, C_PRIM, C_SHADE, C_ENV, C_KEYS, C_COMB_A,
                             C_T0_A, C_T1_A, C_PRIM_A, C_SHADE_A, C_ENV_A, C_LOD, C_PLOD, C_K5,
                             C_ZERO, C_ZERO, C_ZERO, C_ZERO, C_ZERO, C_ZERO, C_ZERO, C_ZERO,
                             C_ZERO, C_ZERO, C_ZERO, C_ZERO, C_ZERO, C_ZERO, C_ZERO, C_ZERO};
static const u8 SEL_D[8] = {C_COMB, C_T0, C_T1, C_PRIM, C_SHADE, C_ENV, C_ONE, C_ZERO};
static const u8 SEL_AA[8] = {C_COMB, C_T0, C_T1, C_PRIM, C_SHADE, C_ENV, C_ONE, C_ZERO};  // alpha a, b, d
static const u8 SEL_AC[8] = {C_LOD, C_T0, C_T1, C_PRIM, C_SHADE, C_ENV, C_PLOD, C_ZERO};

static struct {
    u32 cimg, zimg, timg;
    int cimg_siz, cimg_width, timg_fmt, timg_siz, timg_width;
    u32 om_h, om_l, fill, prim_z;
    int prim[4], env[4], fog[4], blend[4], prim_lod, k4, k5;
    int sc_x0, sc_y0, sc_x1, sc_y1;  // 10.2
    Tile tile[8];
    u8 tmem[4096];
    int tex_tile, tex_levels;
    u8 rgb[2][4], alpha[2][4];  // combiner source indices per cycle: a, b, c, d
} R = {.sc_x1 = 320 << 2, .sc_y1 = 240 << 2, .cimg_width = 320, .cimg_siz = 2};

static u8 *gptr(u32 addr, u32 n) {
    return addr >= 0x80000000u && (u64)addr + n <= bt_inst.w2c_memory.size ? bt_mem + addr : NULL;
}
static inline u16 rd16(const u8 *p) { return (u16)(p[0] << 8 | p[1]); }
static inline void wr16(u8 *p, u32 v) { p[0] = (u8)(v >> 8); p[1] = (u8)v; }
static inline int clamp8(int v) { return v < 0 ? 0 : v > 255 ? 255 : v; }

void rdp_set_texture(int tile, int levels) { R.tex_tile = tile & 7; R.tex_levels = levels & 7; }

void rdp_othermode(int high, u32 mask, u32 value) {
    u32 *m = high ? &R.om_h : &R.om_l;
    *m = (*m & ~mask) | (value & mask);
}

// ---- Depth: 18-bit values stored as 3-bit exponent + 11-bit mantissa (+ 2 bits dz).
static const int Z_SHIFT[8] = {6, 5, 4, 3, 2, 1, 0, 0};
static const u32 Z_BASE[8] = {0, 0x20000, 0x30000, 0x38000, 0x3C000, 0x3E000, 0x3F000, 0x3F800};
static u32 z_compress(u32 z) {
    int e = z < 0x20000 ? 0 : z < 0x30000 ? 1 : z < 0x38000 ? 2 : z < 0x3C000 ? 3
          : z < 0x3E000 ? 4 : z < 0x3F000 ? 5 : z < 0x3F800 ? 6 : 7;
    return (u32)e << 11 | ((z - Z_BASE[e]) >> Z_SHIFT[e] & 0x7FF);
}
static u32 z_decompress(u32 c) { u32 e = c >> 11 & 7; return Z_BASE[e] + ((c & 0x7FF) << Z_SHIFT[e]); }

// ---- Texels
static void rgba16(u32 v, int *o) {
    int r = v >> 11 & 31, g = v >> 6 & 31, b = v >> 1 & 31;
    o[0] = r << 3 | r >> 2; o[1] = g << 3 | g >> 2; o[2] = b << 3 | b >> 2; o[3] = v & 1 ? 255 : 0;
}
static void palette(int index, int *o) {
    const u8 *p = R.tmem + 0x800 + (index & 255) * 8;
    u32 v = rd16(p);
    if ((R.om_h >> 14 & 3) == 3) { o[0] = o[1] = o[2] = v >> 8; o[3] = v & 255; }  // IA16 lookup table
    else rgba16(v, o);
}
static void texel(const Tile *tl, int s, int t, int *o) {
    const u8 *m = R.tmem;
    int base = tl->tmem * 8 + t * tl->line * 8, x = t & 1 ? 4 : 0, tlut = R.om_h >> 15 & 1;
    switch (tl->siz) {
    case 0: {
        int n = m[((base + (s >> 1)) ^ x) & 0xFFF] >> (s & 1 ? 0 : 4) & 15;
        if (tlut) { palette(tl->pal << 4 | n, o); return; }
        if (tl->fmt == 3) { int i = n >> 1; o[0] = o[1] = o[2] = i << 5 | i << 2 | i >> 1; o[3] = n & 1 ? 255 : 0; }
        else o[0] = o[1] = o[2] = o[3] = n * 17;
        return;
    }
    case 1: {
        int v = m[((base + s) ^ x) & 0xFFF];
        if (tlut) { palette(v, o); return; }
        if (tl->fmt == 3) { o[0] = o[1] = o[2] = (v >> 4) * 17; o[3] = (v & 15) * 17; }
        else o[0] = o[1] = o[2] = o[3] = v;
        return;
    }
    case 2: {
        int a = (base + s * 2) ^ x;
        u32 v = (u32)m[a & 0xFFF] << 8 | m[(a + 1) & 0xFFF];
        if (tl->fmt == 3) { o[0] = o[1] = o[2] = v >> 8; o[3] = v & 255; }
        else if (tl->fmt == 4) { o[0] = o[1] = o[2] = o[3] = v >> 8; }
        else rgba16(v, o);
        return;
    }
    default: {  // 32-bit: red/green in the low half of TMEM, blue/alpha in the high half
        int a = ((base + s * 2) ^ x) & 0x7FF;
        o[0] = m[a]; o[1] = m[a + 1]; o[2] = m[a | 0x800]; o[3] = m[(a + 1) | 0x800];
        return;
    }
    }
}
static int wrap(int c, int cm, int mask, int max) {
    if ((cm & 2) || !mask) c = c < 0 ? 0 : c > max ? max : c;
    if (mask) {
        if ((cm & 1) && (c >> mask & 1)) c = ~c;
        c &= (1 << mask) - 1;
    }
    return c;
}
static float shifted(float v, int sh) { return sh == 0 ? v : sh < 11 ? v / (float)(1 << sh) : v * (float)(1 << (16 - sh)); }

// s, t in texels before the tile's shift.
static void sample(int index, float s, float t, int filter, int *o) {
    const Tile *tl = &R.tile[index & 7];
    int ms = (tl->lrs - tl->uls) >> 2, mt = (tl->lrt - tl->ult) >> 2;
    s = shifted(s, tl->shifts) - tl->uls * 0.25f;
    t = shifted(t, tl->shiftt) - tl->ult * 0.25f;
    if (!filter) {
        texel(tl, wrap((int)floorf(s), tl->cms, tl->masks, ms), wrap((int)floorf(t), tl->cmt, tl->maskt, mt), o);
        return;
    }
    float fs = floorf(s), ft = floorf(t);
    int s0 = (int)fs, t0 = (int)ft, c[4][4];
    int sa = wrap(s0, tl->cms, tl->masks, ms), sb = wrap(s0 + 1, tl->cms, tl->masks, ms);
    int ta = wrap(t0, tl->cmt, tl->maskt, mt), tb = wrap(t0 + 1, tl->cmt, tl->maskt, mt);
    texel(tl, sa, ta, c[0]); texel(tl, sb, ta, c[1]); texel(tl, sa, tb, c[2]); texel(tl, sb, tb, c[3]);
    int wx = (int)((s - fs) * 256), wy = (int)((t - ft) * 256);
    for (int i = 0; i < 4; i++) {
        int top = c[0][i] * 256 + (c[1][i] - c[0][i]) * wx, bot = c[2][i] * 256 + (c[3][i] - c[2][i]) * wx;
        o[i] = (top * 256 + (bot - top) * wy) >> 16;
    }
}

// ---- Color image access
static void read_pixel(const u8 *p, int *o) {
    if (R.cimg_siz == 3) { o[0] = p[0]; o[1] = p[1]; o[2] = p[2]; o[3] = p[3]; }
    else if (R.cimg_siz == 2) { rgba16(rd16(p), o); o[3] = 255; }
    else { o[0] = o[1] = o[2] = p[0]; o[3] = 255; }
}
static void write_pixel(u8 *p, const int *c) {
    if (R.cimg_siz == 3) { p[0] = (u8)c[0]; p[1] = (u8)c[1]; p[2] = (u8)c[2]; p[3] = (u8)c[3]; }
    else if (R.cimg_siz == 2) wr16(p, (u32)(c[0] >> 3) << 11 | (u32)(c[1] >> 3) << 6 | (u32)(c[2] >> 3) << 1 | 1);
    else p[0] = (u8)c[0];
}
static int pixel_bytes(void) { return R.cimg_siz == 3 ? 4 : R.cimg_siz == 2 ? 2 : 1; }

// ---- Pixel pipeline
typedef struct {
    int src[C_N][4];
    int cycles;  // 1 or 2
} Pipe;

static void pipe_begin(Pipe *p) {
    memset(p->src, 0, sizeof p->src);
    for (int i = 0; i < 4; i++) {
        p->src[C_PRIM][i] = R.prim[i]; p->src[C_ENV][i] = R.env[i]; p->src[C_ONE][i] = 256;
        p->src[C_PRIM_A][i] = R.prim[3]; p->src[C_ENV_A][i] = R.env[3]; p->src[C_PLOD][i] = R.prim_lod;
        p->src[C_K4][i] = R.k4; p->src[C_K5][i] = R.k5;
    }
    p->cycles = (R.om_h >> 20 & 3) == 1 ? 2 : 1;
}

static void combine(Pipe *p, int cycle, int *out) {
    const u8 *c = R.rgb[cycle], *a = R.alpha[cycle];
    for (int i = 0; i < 3; i++)
        out[i] = clamp8((((p->src[c[0]][i] - p->src[c[1]][i]) * p->src[c[2]][i] + 0x80) >> 8) + p->src[c[3]][i]);
    out[3] = clamp8((((p->src[a[0]][3] - p->src[a[1]][3]) * p->src[a[2]][3] + 0x80) >> 8) + p->src[a[3]][3]);
}

// Blends color in (alpha in[3]) with memory for one blender cycle (0 or 1).
static void blend(int cycle, const int *in, int shade_a, const int *mem, int *out) {
    u32 bl = R.om_l >> 16;
    int ps = bl >> (cycle ? 12 : 14) & 3, as = bl >> (cycle ? 8 : 10) & 3;
    int ms = bl >> (cycle ? 4 : 6) & 3, bs = bl >> (cycle ? 0 : 2) & 3;
    const int *P = ps == 0 ? in : ps == 1 ? mem : ps == 2 ? R.blend : R.fog;
    const int *M = ms == 0 ? in : ms == 1 ? mem : ms == 2 ? R.blend : R.fog;
    int A = as == 0 ? in[3] : as == 1 ? R.fog[3] : as == 2 ? shade_a : 0;
    int B = bs == 0 ? 255 - A : bs == 1 ? 255 : bs == 2 ? 255 : 0;
    for (int i = 0; i < 3; i++) out[i] = clamp8((P[i] * A + M[i] * B) / 255);
    out[3] = in[3];
}

// Shades and writes one pixel. z is in 18-bit units, zdz its tolerance; zon = depth test allowed.
static void pixel(Pipe *p, u8 *cp, u8 *zp, u32 z, u32 zdz, int zon) {
    u32 oml = R.om_l;
    u32 cz = 0;
    if (zon && zp && (oml & 0x10)) {  // Z_CMP
        cz = z_compress(z);
        u32 oz = z_decompress(rd16(zp) >> 2), zq = z_decompress(cz);
        if ((oml >> 10 & 3) == 3) {  // decal: equal within the slope
            u32 tol = zdz + (1u << Z_SHIFT[cz >> 11]) * 2;
            if (zq > oz + tol || zq + tol < oz) return;
        } else if (zq > oz) return;
    }
    int *comb = p->src[C_COMB], out[4];
    static u32 noise = 1;
    noise = noise * 1664525u + 1013904223u;
    for (int i = 0; i < 4; i++) p->src[C_NOISE][i] = noise >> 24;
    combine(p, p->cycles == 2 ? 0 : 1, out);
    if (p->cycles == 2) {
        memcpy(comb, out, sizeof out);
        for (int i = 0; i < 4; i++) p->src[C_COMB_A][i] = out[3];
        combine(p, 1, out);
    }
    if ((oml & 3) == 1 && out[3] < R.blend[3]) return;  // alpha compare against the blend alpha
    if ((oml & 0x2000) && !(oml & 0x4000) && out[3] < ((oml & 0x1000) ? 128 : 8)) return;  // alpha as coverage
    int mem[4] = {0, 0, 0, 255}, res[4];
    read_pixel(cp, mem);
    if (p->cycles == 2) {
        blend(0, out, p->src[C_SHADE][3], mem, res);
        res[3] = out[3];
        memcpy(out, res, sizeof res);
    }
    if (oml & 0x4000) blend(p->cycles == 2, out, p->src[C_SHADE][3], mem, res);  // FORCE_BL
    else {
        u32 bl = oml >> 16;
        int ps = bl >> (p->cycles == 2 ? 12 : 14) & 3;
        const int *P = ps == 0 ? out : ps == 1 ? mem : ps == 2 ? R.blend : R.fog;
        memcpy(res, P, sizeof res);
        res[3] = out[3];
    }
    write_pixel(cp, res);
    if (zon && zp && (oml & 0x20)) wr16(zp, (cz ? cz : z_compress(z)) << 2);  // Z_UPD
}

static void set_inputs(Pipe *p, const int *shade, const int *t0, const int *t1, int lod) {
    memcpy(p->src[C_SHADE], shade, 4 * sizeof(int));
    memcpy(p->src[C_T0], t0, 4 * sizeof(int));
    memcpy(p->src[C_T1], t1, 4 * sizeof(int));
    for (int i = 0; i < 4; i++) {
        p->src[C_SHADE_A][i] = shade[3]; p->src[C_T0_A][i] = t0[3]; p->src[C_T1_A][i] = t1[3]; p->src[C_LOD][i] = lod;
    }
}

static int row_ptrs(int y, u8 **cp, u8 **zp) {
    int bpp = pixel_bytes();
    *cp = gptr(R.cimg + (u32)(y * R.cimg_width) * bpp, (u32)R.cimg_width * bpp);
    *zp = R.zimg ? gptr(R.zimg + (u32)(y * R.cimg_width) * 2, (u32)R.cimg_width * 2) : NULL;
    return *cp != NULL;
}

static void clip_rect(int *x0, int *y0, int *x1, int *y1) {
    int sx0 = R.sc_x0 >> 2, sy0 = R.sc_y0 >> 2, sx1 = R.sc_x1 >> 2, sy1 = R.sc_y1 >> 2;
    if (sx1 > R.cimg_width) sx1 = R.cimg_width;
    if (*x0 < sx0) *x0 = sx0;
    if (*y0 < sy0) *y0 = sy0;
    if (*x1 > sx1) *x1 = sx1;
    if (*y1 > sy1) *y1 = sy1;
}

// ---- Rectangles
static void fill_rect(int ulx, int uly, int lrx, int lry) {
    int cyc = R.om_h >> 20 & 3, bpp = pixel_bytes();
    int x0 = ulx >> 2, y0 = uly >> 2, x1, y1;
    if (cyc >= 2) { x1 = (lrx >> 2) + 1; y1 = (lry >> 2) + 1; }  // fill/copy: inclusive
    else { x1 = (lrx + 3) >> 2; y1 = (lry + 3) >> 2; }
    clip_rect(&x0, &y0, &x1, &y1);
    for (int y = y0; y < y1; y++) {
        u8 *cp, *zp;
        if (!row_ptrs(y, &cp, &zp)) continue;
        if (cyc == 3) {
            for (int x = x0; x < x1; x++) {
                u8 *d = cp + x * bpp;
                if (bpp == 4) { d[0] = (u8)(R.fill >> 24); d[1] = (u8)(R.fill >> 16); d[2] = (u8)(R.fill >> 8); d[3] = (u8)R.fill; }
                else if (bpp == 2) wr16(d, x & 1 ? R.fill & 0xFFFF : R.fill >> 16);
                else d[0] = (u8)(R.fill >> (24 - 8 * (x & 3)));
            }
        } else {
            Pipe p;
            int zero[4] = {0};
            pipe_begin(&p);
            set_inputs(&p, zero, zero, zero, 0);
            for (int x = x0; x < x1; x++)
                pixel(&p, cp + x * bpp, zp ? zp + x * 2 : NULL, R.prim_z, 0, (R.om_l >> 2 & 1));
        }
    }
}

void rdp_texrect(u32 w0, u32 w1, u32 st, u32 dsdt, int flip) {
    int xh = w0 >> 12 & 0xFFF, yh = w0 & 0xFFF, tile = w1 >> 24 & 7, xl = w1 >> 12 & 0xFFF, yl = w1 & 0xFFF;
    int cyc = R.om_h >> 20 & 3, bpp = pixel_bytes();
    float s0 = (s16)(st >> 16) / 32.0f, t0 = (s16)st / 32.0f;
    float dsdx = (s16)(dsdt >> 16) / 1024.0f, dtdy = (s16)dsdt / 1024.0f;
    int x0 = xl >> 2, y0 = yl >> 2, x1, y1;
    if (cyc >= 2) { x1 = (xh >> 2) + 1; y1 = (yh >> 2) + 1; dsdx /= 4; }
    else { x1 = (xh + 3) >> 2; y1 = (yh + 3) >> 2; }
    int cx0 = x0, cy0 = y0;
    clip_rect(&x0, &y0, &x1, &y1);
    int filter = cyc < 2 && (R.om_h >> 12 & 3) != 0;
    Pipe p;
    pipe_begin(&p);
    for (int y = y0; y < y1; y++) {
        u8 *cp, *zp;
        if (!row_ptrs(y, &cp, &zp)) continue;
        for (int x = x0; x < x1; x++) {
            float a = (x - cx0) * dsdx, b = (y - cy0) * dtdy;
            float s = s0 + (flip ? b : a), t = t0 + (flip ? a : b);
            int t0c[4], t1c[4];
            if (cyc == 2) {  // copy
                sample(tile, s, t, 0, t0c);
                if ((R.om_l & 1) && t0c[3] == 0) continue;
                write_pixel(cp + x * bpp, t0c);
                continue;
            }
            sample(tile, s, t, filter, t0c);
            if (p.cycles == 2) sample(tile + 1, s, t, filter, t1c); else memcpy(t1c, t0c, sizeof t0c);
            int zero[4] = {0};
            set_inputs(&p, zero, t0c, t1c, 0);
            pixel(&p, cp + x * bpp, zp ? zp + x * 2 : NULL, R.prim_z, 0, (R.om_l >> 2 & 1));
        }
    }
}

// ---- Triangles
enum { A_Z, A_W, A_S, A_T, A_R, A_G, A_B, A_A, NA };

void rdp_triangle(const RdpVtx *va, const RdpVtx *vb, const RdpVtx *vc, int flags) {
    const RdpVtx *v[3] = {va, vb, vc};
    int cyc = R.om_h >> 20 & 3;
    if (cyc >= 2) return;
    float x0 = va->x, y0 = va->y, x1 = vb->x, y1 = vb->y, x2 = vc->x, y2 = vc->y;
    float area = (x1 - x0) * (y2 - y0) - (x2 - x0) * (y1 - y0);
    if (!(fabsf(area) > 1e-6f)) return;
    int persp = R.om_h >> 19 & 1, tex = flags & RDP_TEX, bpp = pixel_bytes();
    float f[3][NA], dx[NA], dy[NA];
    for (int i = 0; i < 3; i++) {
        float iw = v[i]->w > 1e-6f ? 1.0f / v[i]->w : 1e6f;
        f[i][A_Z] = v[i]->z;
        f[i][A_W] = iw;
        f[i][A_S] = persp ? v[i]->s * iw : v[i]->s;
        f[i][A_T] = persp ? v[i]->t * iw : v[i]->t;
        for (int k = 0; k < 4; k++) f[i][A_R + k] = (flags & RDP_SHADE) ? v[i]->c[k] : 0;
    }
    float inv = 1.0f / area;
    for (int k = 0; k < NA; k++) {
        float d1 = f[1][k] - f[0][k], d2 = f[2][k] - f[0][k];
        dx[k] = (d1 * (y2 - y0) - d2 * (y1 - y0)) * inv;
        dy[k] = (d2 * (x1 - x0) - d1 * (x2 - x0)) * inv;
    }
    int bx0 = (int)floorf(fminf(x0, fminf(x1, x2))), by0 = (int)floorf(fminf(y0, fminf(y1, y2)));
    int bx1 = (int)ceilf(fmaxf(x0, fmaxf(x1, x2))) + 1, by1 = (int)ceilf(fmaxf(y0, fmaxf(y1, y2))) + 1;
    clip_rect(&bx0, &by0, &bx1, &by1);
    if (bx0 >= bx1 || by0 >= by1) return;
    // Edge functions, positive inside.
    float sg = area > 0 ? 1.0f : -1.0f;
    float ex[3] = {x1, x2, x0}, ey[3] = {y1, y2, y0}, fx[3] = {x2, x0, x1}, fy[3] = {y2, y0, y1};
    float ea[3], eb[3], ec[3];
    for (int i = 0; i < 3; i++) {  // E = ea*px + eb*py + ec
        ea[i] = -(fy[i] - ey[i]) * sg;
        eb[i] = (fx[i] - ex[i]) * sg;
        ec[i] = -(ea[i] * ex[i] + eb[i] * ey[i]);
    }
    int lod_on = tex && (R.om_h >> 16 & 1), filter = (R.om_h >> 12 & 3) != 0, zon = (flags & RDP_Z) != 0;
    u32 zdz = (u32)(fabsf(dx[A_Z]) + fabsf(dy[A_Z]));
    Pipe p;
    pipe_begin(&p);
    for (int y = by0; y < by1; y++) {
        u8 *cp, *zp;
        if (!row_ptrs(y, &cp, &zp)) continue;
        float py = y + 0.5f;
        for (int x = bx0; x < bx1; x++) {
            float px = x + 0.5f;
            int in = 1;
            for (int i = 0; i < 3 && in; i++) {
                float e = ea[i] * px + eb[i] * py + ec[i];
                in = e > 0 || (e == 0 && (ea[i] > 0 || (ea[i] == 0 && eb[i] > 0)));
            }
            if (!in) continue;
            float ox = px - x0, oy = py - y0, a[NA];
            for (int k = 0; k < NA; k++) a[k] = f[0][k] + dx[k] * ox + dy[k] * oy;
            int shade[4], t0[4] = {0}, t1[4] = {0}, lod = 0;
            for (int k = 0; k < 4; k++) shade[k] = clamp8((int)a[A_R + k]);
            if (tex) {
                float w = a[A_W] > 1e-9f ? 1.0f / a[A_W] : 1e9f;
                float s = (persp ? a[A_S] * w : a[A_S]) / 32.0f, t = (persp ? a[A_T] * w : a[A_T]) / 32.0f;
                int t0i = R.tex_tile, t1i = R.tex_tile + 1;
                if (lod_on) {
                    float dsx = persp ? (dx[A_S] - s * 32 * dx[A_W]) * w : dx[A_S];
                    float dtx = persp ? (dx[A_T] - t * 32 * dx[A_W]) * w : dx[A_T];
                    float dsy = persp ? (dy[A_S] - s * 32 * dy[A_W]) * w : dy[A_S];
                    float dty = persp ? (dy[A_T] - t * 32 * dy[A_W]) * w : dy[A_T];
                    float l = fmaxf(fmaxf(fabsf(dsx), fabsf(dtx)), fmaxf(fabsf(dsy), fabsf(dty))) / 32.0f;
                    if (l >= 1.0f) {
                        int lv = (int)log2f(l);
                        if (lv >= R.tex_levels) { lv = R.tex_levels; lod = 255; }
                        else lod = clamp8((int)((l / (float)(1 << lv) - 1.0f) * 256));
                        t0i = R.tex_tile + lv;
                        t1i = R.tex_tile + (lv < R.tex_levels ? lv + 1 : lv);
                    }
                }
                sample(t0i, s, t, filter, t0);
                if (p.cycles == 2) sample(t1i, s, t, filter, t1); else memcpy(t1, t0, sizeof t0);
            }
            { static int dbg = -1; if (dbg < 0) dbg = getenv("BT_RDP_DEBUG") ? atoi(getenv("BT_RDP_DEBUG")) : 0;
              if (dbg == 1) { for (int k = 0; k < 4; k++) t0[k] = t1[k] = 255; }
              if (dbg == 2) { memcpy(shade, t0, sizeof t0); shade[3] = 255; for (int k = 0; k < 4; k++) t1[k] = 255; R.rgb[0][0]=R.rgb[1][0]=C_SHADE; R.rgb[0][1]=R.rgb[1][1]=C_ZERO; R.rgb[0][2]=R.rgb[1][2]=C_ONE; R.rgb[0][3]=R.rgb[1][3]=C_ZERO; }
            }
            set_inputs(&p, shade, t0, t1, lod);
            u32 z = (R.om_l >> 2 & 1) ? R.prim_z : a[A_Z] <= 0 ? 0 : a[A_Z] >= 0x3FFFF ? 0x3FFFF : (u32)a[A_Z];
            pixel(&p, cp + x * bpp, zp ? zp + x * 2 : NULL, z, zdz, zon);
        }
    }
}

// ---- Commands
static void set_combine(u32 w0, u32 w1) {
    R.rgb[0][0] = SEL_A[w0 >> 20 & 15]; R.rgb[0][2] = SEL_C[w0 >> 15 & 31];
    R.alpha[0][0] = SEL_AA[w0 >> 12 & 7]; R.alpha[0][2] = SEL_AC[w0 >> 9 & 7];
    R.rgb[1][0] = SEL_A[w0 >> 5 & 15]; R.rgb[1][2] = SEL_C[w0 & 31];
    R.rgb[0][1] = SEL_B[w1 >> 28 & 15]; R.rgb[1][1] = SEL_B[w1 >> 24 & 15];
    R.alpha[1][0] = SEL_AA[w1 >> 21 & 7]; R.alpha[1][2] = SEL_AC[w1 >> 18 & 7];
    R.rgb[0][3] = SEL_D[w1 >> 15 & 7]; R.alpha[0][1] = SEL_AA[w1 >> 12 & 7]; R.alpha[0][3] = SEL_AA[w1 >> 9 & 7];
    R.rgb[1][3] = SEL_D[w1 >> 6 & 7]; R.alpha[1][1] = SEL_AA[w1 >> 3 & 7]; R.alpha[1][3] = SEL_AA[w1 & 7];
}

static void color(int *c, u32 w) { c[0] = w >> 24; c[1] = w >> 16 & 255; c[2] = w >> 8 & 255; c[3] = w & 255; }

static void load_block(u32 w0, u32 w1) {
    Tile *tl = &R.tile[w1 >> 24 & 7];
    int uls = w0 >> 12 & 0xFFF, ult = w0 & 0xFFF, lrs = w1 >> 12 & 0xFFF, dxt = w1 & 0xFFF, siz = R.timg_siz;
    tl->uls = uls << 2; tl->ult = ult << 2; tl->lrs = lrs << 2; tl->lrt = dxt << 2;
    u32 texels = (u32)(lrs - uls + 1), bytes = siz == 0 ? (texels + 1) / 2 : texels << (siz - 1);
    u32 src = R.timg + (((u32)(ult * R.timg_width + uls) << siz) >> 1), tm = (u32)tl->tmem * 8, acc = 0;
    for (u32 w = 0; w < (bytes + 7) / 8 && w < 512; w++, acc += (u32)dxt) {
        const u8 *s = gptr(src + w * 8, 8);
        u32 x = acc >> 11 & 1 ? 4 : 0;
        if (!s) break;
        if (siz == 3) {
            u32 a = ((tm + w * 4) ^ x) & 0x7FF;
            R.tmem[a] = s[0]; R.tmem[a + 1] = s[1]; R.tmem[a + 2] = s[4]; R.tmem[a + 3] = s[5];
            R.tmem[a | 0x800] = s[2]; R.tmem[(a + 1) | 0x800] = s[3]; R.tmem[(a + 2) | 0x800] = s[6]; R.tmem[(a + 3) | 0x800] = s[7];
        } else {
            for (int i = 0; i < 8; i++) R.tmem[((tm + w * 8 + i) ^ x) & 0xFFF] = s[i];
        }
    }
}

static void load_tile(u32 w0, u32 w1) {
    Tile *tl = &R.tile[w1 >> 24 & 7];
    tl->uls = w0 >> 12 & 0xFFF; tl->ult = w0 & 0xFFF; tl->lrs = w1 >> 12 & 0xFFF; tl->lrt = w1 & 0xFFF;
    int sl = tl->uls >> 2, tt = tl->ult >> 2, sh = tl->lrs >> 2, th = tl->lrt >> 2, siz = R.timg_siz;
    int bpp = siz == 3 ? 4 : siz == 2 ? 2 : 1;
    for (int t = tt; t <= th; t++) {
        int row = t - tt;
        u32 x = row & 1 ? 4 : 0, rb = (u32)tl->tmem * 8 + (u32)(row * tl->line * 8);
        const u8 *s = gptr(R.timg + (u32)(t * R.timg_width + sl) * bpp >> (siz == 0), (u32)(sh - sl + 1) * bpp);
        if (!s) continue;
        for (int i = 0; i <= sh - sl; i++) {
            if (siz == 3) {
                u32 a = ((rb + i * 2) ^ x) & 0x7FF;
                R.tmem[a] = s[i * 4]; R.tmem[a + 1] = s[i * 4 + 1];
                R.tmem[a | 0x800] = s[i * 4 + 2]; R.tmem[(a + 1) | 0x800] = s[i * 4 + 3];
            } else if (siz == 0) {
                if (!(i & 1)) R.tmem[((rb + i / 2) ^ x) & 0xFFF] = s[i / 2];
            } else {
                for (int b = 0; b < bpp; b++) R.tmem[((rb + i * bpp + b) ^ x) & 0xFFF] = s[i * bpp + b];
            }
        }
    }
}

static void load_tlut(u32 w0, u32 w1) {
    Tile *tl = &R.tile[w1 >> 24 & 7];
    int uls = w0 >> 12 & 0xFFF, lrs = w1 >> 12 & 0xFFF, n = (lrs >> 2) - (uls >> 2) + 1;
    u32 tm = (u32)tl->tmem * 8;
    const u8 *s = gptr(R.timg + (u32)(uls >> 2) * 2, (u32)(n > 0 ? n : 0) * 2);
    if (!s || n <= 0 || n > 256) return;
    for (int i = 0; i < n; i++)
        for (int c = 0; c < 4; c++) { R.tmem[(tm + i * 8 + c * 2) & 0xFFF] = s[i * 2]; R.tmem[(tm + i * 8 + c * 2 + 1) & 0xFFF] = s[i * 2 + 1]; }
}

void rdp_command(u32 w0, u32 w1) {
    switch (w0 >> 24) {
    case 0xE6: case 0xE7: case 0xE8: case 0xE9: case 0x00: break;  // syncs, no-op
    case 0xEA: case 0xEB: break;  // chroma key
    case 0xEC: R.k4 = w1 >> 9 & 0x1FF; R.k5 = w1 & 0x1FF; break;
    case 0xED: R.sc_x0 = w0 >> 12 & 0xFFF; R.sc_y0 = w0 & 0xFFF; R.sc_x1 = w1 >> 12 & 0xFFF; R.sc_y1 = w1 & 0xFFF; break;
    case 0xEE: R.prim_z = (w1 >> 16 & 0x7FFF) << 3; break;
    case 0xEF: R.om_h = w0 & 0x00FFFFFF; R.om_l = w1; break;
    case 0xF0: load_tlut(w0, w1); break;
    case 0xF2: {
        Tile *tl = &R.tile[w1 >> 24 & 7];
        tl->uls = w0 >> 12 & 0xFFF; tl->ult = w0 & 0xFFF; tl->lrs = w1 >> 12 & 0xFFF; tl->lrt = w1 & 0xFFF;
        break;
    }
    case 0xF3: load_block(w0, w1); break;
    case 0xF4: load_tile(w0, w1); break;
    case 0xF5: {
        Tile *tl = &R.tile[w1 >> 24 & 7];
        tl->fmt = w0 >> 21 & 7; tl->siz = w0 >> 19 & 3; tl->line = w0 >> 9 & 0x1FF; tl->tmem = w0 & 0x1FF;
        tl->pal = w1 >> 20 & 15; tl->cmt = w1 >> 18 & 3; tl->maskt = w1 >> 14 & 15; tl->shiftt = w1 >> 10 & 15;
        tl->cms = w1 >> 8 & 3; tl->masks = w1 >> 4 & 15; tl->shifts = w1 & 15;
        break;
    }
    case 0xF6: fill_rect(w1 >> 12 & 0xFFF, w1 & 0xFFF, w0 >> 12 & 0xFFF, w0 & 0xFFF); break;
    case 0xF7: R.fill = w1; break;
    case 0xF8: color(R.fog, w1); break;
    case 0xF9: color(R.blend, w1); break;
    case 0xFA: color(R.prim, w1); R.prim_lod = w0 & 255; break;
    case 0xFB: color(R.env, w1); break;
    case 0xFC: set_combine(w0, w1); break;
    case 0xFD: R.timg_fmt = w0 >> 21 & 7; R.timg_siz = w0 >> 19 & 3; R.timg_width = (w0 & 0xFFF) + 1; R.timg = w1; break;
    case 0xFE: R.zimg = w1; break;
    case 0xFF: R.cimg_siz = w0 >> 19 & 3; R.cimg_width = (w0 & 0xFFF) + 1; R.cimg = w1; break;
    default: {
        static u8 seen[256];
        if (!seen[w0 >> 24]++) fprintf(stderr, "bt_native rdp: command %02x not handled\n", w0 >> 24);
    }
    }
}
