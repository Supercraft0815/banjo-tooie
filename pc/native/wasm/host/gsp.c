// RSP half of a graphics task: an F3DEX2 display-list interpreter (plus the L3DEX2 line
// command), feeding screen-space triangles and RDP commands to rdp.c.
// Guest structs written by game C code (Gfx words, Vtx, Mtx, Vp) are read natively;
// the RDP side reads image data as big-endian bytes.
#include <math.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "rdp.h"

#define MAX_VTX 64
#define MTX_DEPTH 32
#define DL_DEPTH 32

enum {
    G_ZBUFFER = 0x1, G_SHADE = 0x4, G_CULL_FRONT = 0x200, G_CULL_BACK = 0x400, G_FOG = 0x10000,
    G_LIGHTING = 0x20000, G_TEXTURE_GEN = 0x40000, G_TEXTURE_GEN_LINEAR = 0x80000, G_SHADING_SMOOTH = 0x200000,
};
enum { CLIP_NX = 1, CLIP_PX = 2, CLIP_NY = 4, CLIP_PY = 8, CLIP_W = 16 };

typedef struct { float x, y, z, w, c[4], s, t; int clip; } Vert;
typedef float Mat[4][4];

static struct {
    u32 seg[16];
    Mat mv[MTX_DEPTH], proj, mvp;
    int mvi, mvp_ok, lights_ok, forced;
    Vert v[MAX_VTX];
    u32 geom;
    u8 lcol[8][3];
    s8 ldir[8][3], lookat[2][3];
    float lobj[8][3], lookobj[2][3];
    int nlights;
    float vscale[3], vtrans[3];
    float tex_s, tex_t;
    int tex_on;
    float fog_m, fog_o;
    u32 half1;
} S;

// BT_GFX_TRACE=n prints a command histogram for the first n graphics tasks.
static int trace_left = -1;
static u32 trace_ops[256];

static int ip_mode_now(void);
static int tracing(void) { return trace_left > 0 && ip_mode_now() != 2; }  // never in the in-between worker

static void trace_end(u32 dl) {
    if (trace_left <= 0) return;
    trace_left--;
    fprintf(stderr, "gsp task dl=%08x:", dl);
    for (int i = 0; i < 256; i++)
        if (trace_ops[i]) fprintf(stderr, " %02x:%u", i, trace_ops[i]);
    fprintf(stderr, "\n");
    memset(trace_ops, 0, sizeof trace_ops);
}

static const u8 *gmem(u32 addr, u32 n) { return rdp_mem(addr, n); }
// RDRAM is big-endian (guest.h).
static u32 be32(const u8 *p) { return (u32)p[0] << 24 | p[1] << 16 | p[2] << 8 | p[3]; }
static s16 be16(const u8 *p) { return (s16)(p[0] << 8 | p[1]); }
static u32 seg_addr(u32 a) { return 0x80000000u | ((S.seg[a >> 24 & 15] + (a & 0x00FFFFFF)) & 0x00FFFFFF); }

static void mat_mul(Mat out, Mat a, Mat b) {  // out = a * b (row vectors: a applies first)
    Mat r;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            r[i][j] = a[i][0] * b[0][j] + a[i][1] * b[1][j] + a[i][2] * b[2][j] + a[i][3] * b[3][j];
    memcpy(out, r, sizeof r);
}
static void mat_ident(Mat m) {
    memset(m, 0, sizeof(Mat));
    m[0][0] = m[1][1] = m[2][2] = m[3][3] = 1;
}
// Mtx: 16 s16 integer parts, then 16 u16 fractions, packed two per native word.
static int read_mtx(u32 addr, Mat m) {
    const u8 *w = gmem(addr, 64);
    if (!w) return 0;
    for (int k = 0; k < 16; k++) {
        s16 i = be16(w + 2 * k);
        u16 f = (u16)be16(w + 32 + 2 * k);
        m[k / 4][k % 4] = i + f / 65536.0f;
    }
    return 1;
}

static void normalize(float *v) {
    float l = sqrtf(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
    if (l > 1e-9f) { v[0] /= l; v[1] /= l; v[2] /= l; }
}
// Light directions into object space with the modelview matrix (as F3DEX2 does).
static void update_lights(void) {
    float(*m)[4] = S.mv[S.mvi];
    for (int i = 0; i < 10; i++) {
        const s8 *d = i < 8 ? S.ldir[i] : S.lookat[i - 8];
        float *o = i < 8 ? S.lobj[i] : S.lookobj[i - 8];
        for (int r = 0; r < 3; r++) o[r] = m[r][0] * d[0] + m[r][1] * d[1] + m[r][2] * d[2];
        normalize(o);
    }
    S.lights_ok = 1;
}

static void load_vertices(u32 addr, int n, int v0) {
    if (!S.mvp_ok) { mat_mul(S.mvp, S.mv[S.mvi], S.proj); S.mvp_ok = 1; }
    if (!S.lights_ok && (S.geom & (G_LIGHTING | G_TEXTURE_GEN))) update_lights();
    if (v0 < 0) return;  // a malformed G_VTX (the RSP would wrap inside its vertex buffer)
    for (int i = 0; i < n && v0 + i < MAX_VTX; i++) {
        const u8 *p = gmem(addr + i * 16, 16);
        Vert *v = &S.v[v0 + i];
        if (!p) return;
        float x = be16(p), y = be16(p + 2), z = be16(p + 4);
        float(*m)[4] = S.mvp;
        v->x = x * m[0][0] + y * m[1][0] + z * m[2][0] + m[3][0];
        v->y = x * m[0][1] + y * m[1][1] + z * m[2][1] + m[3][1];
        v->z = x * m[0][2] + y * m[1][2] + z * m[2][2] + m[3][2];
        v->w = x * m[0][3] + y * m[1][3] + z * m[2][3] + m[3][3];
        const u8 *cn = p + 12;
        float nrm[3] = {(s8)cn[0], (s8)cn[1], (s8)cn[2]};
        if (S.geom & (G_LIGHTING | G_TEXTURE_GEN)) normalize(nrm);
        if (S.geom & G_LIGHTING) {
            float c[3];
            for (int k = 0; k < 3; k++) c[k] = S.lcol[S.nlights][k];
            for (int l = 0; l < S.nlights; l++) {
                float d = nrm[0] * S.lobj[l][0] + nrm[1] * S.lobj[l][1] + nrm[2] * S.lobj[l][2];
                if (d > 0)
                    for (int k = 0; k < 3; k++) c[k] += d * S.lcol[l][k];
            }
            for (int k = 0; k < 3; k++) v->c[k] = c[k] > 255 ? 255 : c[k];
        } else {
            for (int k = 0; k < 3; k++) v->c[k] = cn[k];
        }
        v->c[3] = cn[3];
        float s = be16(p + 8), t = be16(p + 10);
        if (S.geom & G_TEXTURE_GEN) {
            float gx = nrm[0] * S.lookobj[0][0] + nrm[1] * S.lookobj[0][1] + nrm[2] * S.lookobj[0][2];
            float gy = nrm[0] * S.lookobj[1][0] + nrm[1] * S.lookobj[1][1] + nrm[2] * S.lookobj[1][2];
            if (S.geom & G_TEXTURE_GEN_LINEAR) {
                gx = 1.0f - acosf(gx < -1 ? -1 : gx > 1 ? 1 : gx) * (2.0f / (float)M_PI);
                gy = 1.0f - acosf(gy < -1 ? -1 : gy > 1 ? 1 : gy) * (2.0f / (float)M_PI);
            }
            s = (gx + 1.0f) * 16384.0f;
            t = (gy + 1.0f) * 16384.0f;
        }
        v->s = s * S.tex_s;
        v->t = t * S.tex_t;
        if (S.geom & G_FOG) {
            float f = (v->w > 1e-6f ? v->z / v->w : -1.0f) * S.fog_m + S.fog_o;
            v->c[3] = f < 0 ? 0 : f > 255 ? 255 : f;
        }
        v->clip = (v->x < -v->w ? CLIP_NX : 0) | (v->x > v->w ? CLIP_PX : 0) | (v->y < -v->w ? CLIP_NY : 0) |
                  (v->y > v->w ? CLIP_PY : 0) | (v->w < 1e-3f ? CLIP_W : 0);
    }
}

// Polygon clipping against w > 0 and a guard band, then perspective divide and viewport.
#define GUARD 4.0f
static float plane(const Vert *v, int p) {
    switch (p) {
    case 0: return v->w - 1e-3f;
    case 1: return GUARD * v->w - v->x;
    case 2: return GUARD * v->w + v->x;
    case 3: return GUARD * v->w - v->y;
    default: return GUARD * v->w + v->y;
    }
}
static void lerp(Vert *o, const Vert *a, const Vert *b, float t) {
    const float *pa = &a->x, *pb = &b->x;
    float *po = &o->x;
    for (int i = 0; i < 10; i++) po[i] = pa[i] + (pb[i] - pa[i]) * t;
}

static void draw_poly(Vert *in, int n, int flat_from) {
    Vert buf[2][16];
    Vert *cur = in;
    for (int p = 0; p < 5 && n >= 3; p++) {
        Vert *out = buf[p & 1];
        int m = 0;
        for (int i = 0; i < n; i++) {
            const Vert *a = &cur[i], *b = &cur[(i + 1) % n];
            float da = plane(a, p), db = plane(b, p);
            if (da >= 0) out[m++] = *a;
            if ((da >= 0) != (db >= 0) && m < 16) lerp(&out[m++], a, b, da / (da - db));
        }
        cur = out;
        n = m;
    }
    if (n < 3) return;
    RdpVtx r[16];
    float area = 0;
    for (int i = 0; i < n; i++) {
        const Vert *v = &cur[i];
        float iw = 1.0f / v->w;
        r[i].x = v->x * iw * S.vscale[0] + S.vtrans[0];
        r[i].y = -v->y * iw * S.vscale[1] + S.vtrans[1];
        r[i].z = (v->z * iw * S.vscale[2] + S.vtrans[2]) * 256.0f;
        r[i].w = v->w;
        memcpy(r[i].c, flat_from >= 0 ? S.v[flat_from].c : v->c, sizeof r[i].c);
        r[i].s = v->s;
        r[i].t = v->t;
    }
    for (int i = 1; i + 1 < n; i++)
        area += (r[i].x - r[0].x) * (r[i + 1].y - r[0].y) - (r[i + 1].x - r[0].x) * (r[i].y - r[0].y);
    if ((S.geom & G_CULL_BACK) && area > 0) return;
    if ((S.geom & G_CULL_FRONT) && area < 0) return;
    int flags = (S.geom & G_SHADE ? RDP_SHADE : 0) | (S.tex_on ? RDP_TEX : 0) | (S.geom & G_ZBUFFER ? RDP_Z : 0);
    if (tracing() && getenv("BT_GFX_DUMP")) {
        fprintf(stderr, "      poly");
        for (int i = 0; i < n; i++) fprintf(stderr, " (%.2f,%.2f z%.0f c%02x%02x%02x%02x st%.2f,%.2f)", r[i].x, r[i].y, r[i].z / 256, (int)r[i].c[0], (int)r[i].c[1], (int)r[i].c[2], (int)r[i].c[3], r[i].s / 32, r[i].t / 32);
        fprintf(stderr, "\n");
    }
    for (int i = 1; i + 1 < n; i++) rdp_triangle(&r[0], &r[i], &r[i + 1], flags);
}

static void triangle(int a, int b, int c) {
    if (a >= MAX_VTX || b >= MAX_VTX || c >= MAX_VTX) return;
    if (S.v[a].clip & S.v[b].clip & S.v[c].clip) return;  // all outside one plane
    Vert poly[3] = {S.v[a], S.v[b], S.v[c]};
    draw_poly(poly, 3, S.geom & G_SHADING_SMOOTH ? -1 : a);
}

static void line3d(int a, int b, int wd) {
    if (a >= MAX_VTX || b >= MAX_VTX) return;
    const Vert *p = &S.v[a], *q = &S.v[b];
    if (p->w < 1e-3f || q->w < 1e-3f) return;
    float ax = p->x / p->w * S.vscale[0] + S.vtrans[0], ay = -p->y / p->w * S.vscale[1] + S.vtrans[1];
    float bx = q->x / q->w * S.vscale[0] + S.vtrans[0], by = -q->y / q->w * S.vscale[1] + S.vtrans[1];
    // rdp_triangle scales the expanded quad, including this line width, exactly once.
    float dx = bx - ax, dy = by - ay, l = sqrtf(dx * dx + dy * dy), h = (1.0f + wd * 0.5f) * 0.5f;
    if (l < 1e-6f) return;
    float nx = -dy / l * h, ny = dx / l * h;
    RdpVtx r[4];
    const Vert *src[4] = {p, p, q, q};
    float ox[4] = {nx, -nx, -nx, nx}, oy[4] = {ny, -ny, -ny, ny};
    for (int i = 0; i < 4; i++) {
        const Vert *v = src[i];
        r[i].x = (i < 2 ? ax : bx) + ox[i];
        r[i].y = (i < 2 ? ay : by) + oy[i];
        r[i].z = (v->z / v->w * S.vscale[2] + S.vtrans[2]) * 256.0f;
        r[i].w = v->w;
        memcpy(r[i].c, v->c, sizeof r[i].c);
        r[i].s = v->s;
        r[i].t = v->t;
    }
    int flags = RDP_SHADE | (S.tex_on ? RDP_TEX : 0) | (S.geom & G_ZBUFFER ? RDP_Z : 0);
    rdp_triangle(&r[0], &r[1], &r[2], flags);
    rdp_triangle(&r[0], &r[2], &r[3], flags);
}

static void movemem(u32 w0, u32 w1) {
    int idx = w0 & 0xFF, ofs = (w0 >> 8 & 0xFF) * 8;
    u32 a = seg_addr(w1);
    if (idx == 8) {  // viewport: s16 scale[4], trans[4]; x and y have two fraction bits
        const u8 *vb = gmem(a, 16);
        if (!vb) return;
        s16 vp[8];
        for (int i = 0; i < 8; i++) vp[i] = be16(vb + 2 * i);
        S.vscale[0] = vp[0] / 4.0f; S.vscale[1] = vp[1] / 4.0f; S.vscale[2] = vp[2];
        S.vtrans[0] = vp[4] / 4.0f; S.vtrans[1] = vp[5] / 4.0f; S.vtrans[2] = vp[6];
        if (tracing()) fprintf(stderr, "      viewport %d %d %d / %d %d %d\n", vp[0], vp[1], vp[2], vp[4], vp[5], vp[6]);
    } else if (idx == 10) {  // lights: slot 0/1 look-at, then lights from slot 2
        const u8 *l = gmem(a, 16);
        int slot = ofs / 24;
        if (!l) return;
        if (slot < 2) memcpy(S.lookat[slot], l + 8, 3);
        else if (slot - 2 < 8) { memcpy(S.lcol[slot - 2], l, 3); memcpy(S.ldir[slot - 2], l + 8, 3); }
        S.lights_ok = 0;
    } else if (idx == 14) {  // forced MVP matrix
        if (read_mtx(a, S.mvp)) { S.mvp_ok = 1; S.forced = 1; }
    }
}

static void moveword(u32 w0, u32 w1) {
    int index = w0 >> 16 & 0xFF, ofs = w0 & 0xFFFF;
    switch (index) {
    case 2: S.nlights = (int)(w1 / 24); if (S.nlights > 7) S.nlights = 7; S.lights_ok = 0; break;
    case 6: S.seg[(ofs >> 2) & 15] = w1 & 0x00FFFFFF; break;
    case 8: S.fog_m = (s16)(w1 >> 16); S.fog_o = (s16)w1; break;
    case 10: if (ofs / 24 < 8 && ofs % 24 == 0) { S.lcol[ofs / 24][0] = w1 >> 24; S.lcol[ofs / 24][1] = w1 >> 16; S.lcol[ofs / 24][2] = w1 >> 8; } break;
    default: break;  // matrix element, clip ratio, forced-matrix flag, perspective normalization
    }
}

// ---- Frame interpolation (presentation only; rdp_interp_* keeps it out of guest memory).
// A task that draws a picture records every G_MTX with a key from the geometry drawn after it:
// the first G_DL/G_VTX address as written (segment-relative where the game uses segments, so it
// is the same in every frame). Direct-address matrices are object roots, matched to the nearest
// previous one with the same key; segment-relative ones (bones in static model lists) are matched
// inside their root. In-between passes re-run the display list with each matched matrix mixed
// between the previous frame and this one. Culling/branch decisions are replayed from the real
// pass, so every pass walks the same commands.
#define IP_EVENTS 8192
#define IP_DECISIONS 8192
#define IP_JUMP 500.0f  // translation per frame beyond which a pair is a cut or a teleport
typedef struct { Mat m; u64 sig; int root, proj_load, parent, match; } IpEvent;
static struct {
    IpEvent ev[2][IP_EVENTS];  // ev[cur]: this frame; ev[cur ^ 1]: the previous picture
    int n[2], cur, pending, last_root;
    int mode, at, desync;  // mode 0 off, 1 recording (real pass), 2 replaying (in-between pass)
    float t;
    u8 decision[IP_DECISIONS];
    int ndecision, dat;
    u32 dl;  // the display list of the posted picture
    unsigned frames, events, matched, desyncs;  // BT_RENDER_STATS
} IP;

static int ip_mode_now(void) { return IP.mode; }
static u64 ip_hash(u64 h, u64 v) { h = (h ^ v) * 0x9E3779B97F4A7C15ull; return h ^ h >> 31; }

static void ip_record(Mat m, u32 p, u32 w1, u32 pc) {
    int n = IP.n[IP.cur];
    if (n >= IP_EVENTS) return;
    IpEvent *e = &IP.ev[IP.cur][n];
    u32 seg = w1 >> 24;
    memcpy(e->m, m, sizeof(Mat));
    e->root = seg == 0 || seg == 0x80;
    e->proj_load = (p & 6) == 6;
    e->sig = e->root ? ip_hash(1, p) : ip_hash(ip_hash(2, p), (u64)w1 << 32 | pc);
    e->parent = e->root ? -1 : IP.last_root;
    if (e->root) IP.last_root = n;
    e->match = -1;
    IP.n[IP.cur] = n + 1;
}

// The geometry a G_DL or G_VTX draws keys the matrices recorded since the previous one.
static void ip_anchor(u32 w1) {
    if (IP.mode != 1) return;
    for (int i = IP.pending; i < IP.n[IP.cur]; i++) IP.ev[IP.cur][i].sig = ip_hash(IP.ev[IP.cur][i].sig, w1);
    IP.pending = IP.n[IP.cur];
}

static int ip_decide(int taken) {
    if (IP.mode == 1 && IP.ndecision < IP_DECISIONS) IP.decision[IP.ndecision++] = (u8)taken;
    if (IP.mode == 2 && IP.dat < IP.ndecision) return IP.decision[IP.dat++];
    return taken;
}

static float ip_dist(Mat a, Mat b) {
    float d = 0;
    for (int c = 0; c < 3; c++) d += (a[3][c] - b[3][c]) * (a[3][c] - b[3][c]);
    return d;
}

static void ip_match(void) {
    static int head[1024], link[IP_EVENTS], projs[IP_EVENTS];
    static u8 used[IP_EVENTS];
    IpEvent *cur = IP.ev[IP.cur], *prev = IP.ev[IP.cur ^ 1];
    int nc = IP.n[IP.cur], np = IP.n[IP.cur ^ 1], nproj = 0, kproj = 0;
    memset(head, -1, sizeof head);
    for (int j = np - 1; j >= 0; j--) {
        used[j] = 0;
        if (prev[j].root) { link[j] = head[prev[j].sig & 1023]; head[prev[j].sig & 1023] = j; }
    }
    for (int j = 0; j < np; j++) if (prev[j].proj_load) projs[nproj++] = j;
    for (int i = 0; i < nc; i++) {
        IpEvent *e = &cur[i];
        e->match = -1;
        if (e->root) {
            float best = INFINITY;
            for (int j = head[e->sig & 1023]; j >= 0; j = link[j]) {
                float d = used[j] || prev[j].sig != e->sig ? INFINITY : ip_dist(e->m, prev[j].m);
                if (d < best) { best = d; e->match = j; }
            }
            // A camera matrix keyed by a per-frame list: the same projection load of the previous frame.
            if (e->match < 0 && e->proj_load && kproj < nproj && !used[projs[kproj]]) e->match = projs[kproj];
            kproj += e->proj_load;
            if (e->match >= 0) used[e->match] = 1;
        } else if (e->parent >= 0 && cur[e->parent].match >= 0) {
            int ord = 0;
            for (int k = e->parent + 1; k < i; k++) ord += cur[k].sig == e->sig;
            for (int j = cur[e->parent].match + 1; j < np && !prev[j].root; j++)
                if (prev[j].sig == e->sig && !ord--) { e->match = j; break; }
        }
    }
}

// m becomes the mix of the previous frame's matrix and m, unless the pair looks like a cut.
static void ip_replay(Mat m) {
    IpEvent *e = !IP.desync && IP.at < IP.n[IP.cur] ? &IP.ev[IP.cur][IP.at] : NULL;
    IP.at++;
    if (!e || memcmp(e->m, m, sizeof(Mat))) { IP.desync = 1; return; }
    if (e->match < 0) return;
    float(*a)[4] = IP.ev[IP.cur ^ 1][e->match].m, d = 0, mag = 0;
    for (int r = 0; r < 3; r++)
        for (int c = 0; c < 3; c++) { d = fmaxf(d, fabsf(a[r][c] - m[r][c])); mag = fmaxf(mag, fabsf(m[r][c])); }
    if (d > 0.5f * mag || ip_dist(a, m) > IP_JUMP * IP_JUMP) return;
    for (int r = 0; r < 4; r++)
        for (int c = 0; c < 4; c++) m[r][c] = a[r][c] + (m[r][c] - a[r][c]) * IP.t;
}

// In-between pictures per game frame: the VI interval minus one, when the option is on.
static int ip_images(void) {
    if (!bt_setting(BT_SET_INTERP) || bt_setting(BT_SET_FPS)) return 0;
    int k = bt_vi_interval();
    return k < 2 ? 0 : k > 4 ? 3 : k - 1;
}

static void matrix(u32 w0, u32 w1, u32 pc) {
    u32 p = (w0 & 0xFF) ^ 1;  // G_MTX_PUSH is inverted in the command
    Mat m;
    if (!read_mtx(seg_addr(w1), m)) return;
    if (IP.mode == 1) ip_record(m, p, w1, pc);
    if (IP.mode == 2) ip_replay(m);
    if (tracing() && getenv("BT_GFX_DUMP"))
        for (int i = 0; i < 4; i++) fprintf(stderr, "      mtx p%x %10.3f %10.3f %10.3f %10.3f\n", p, m[i][0], m[i][1], m[i][2], m[i][3]);
    if (p & 4) {
        if (p & 2) memcpy(S.proj, m, sizeof m); else mat_mul(S.proj, m, S.proj);
    } else {
        if ((p & 1) && S.mvi + 1 < MTX_DEPTH) { memcpy(S.mv[S.mvi + 1], S.mv[S.mvi], sizeof(Mat)); S.mvi++; }
        if (p & 2) memcpy(S.mv[S.mvi], m, sizeof m); else mat_mul(S.mv[S.mvi], m, S.mv[S.mvi]);
        S.lights_ok = 0;
    }
    S.mvp_ok = 0;
    S.forced = 0;
}

static int culled(int a, int b) {
    int all = ~0;
    for (int i = a; i <= b && i < MAX_VTX; i++) all &= S.v[i].clip;
    return (all & 0x1F) != 0;
}

static void run(u32 dl);
static void ip_passes(int images) {
    for (int i = 0; i < images && rdp_interp_begin(); i++) {
        IP.mode = 2; IP.at = IP.dat = IP.desync = 0;
        IP.t = (i + 1.0f) / (images + 1);
        run(IP.dl);
        rdp_interp_end(i);
    }
    IP.frames++; IP.events += (unsigned)IP.n[IP.cur]; IP.desyncs += (unsigned)IP.desync;
    for (int i = 0; i < IP.n[IP.cur]; i++) IP.matched += IP.ev[IP.cur][i].match >= 0;
    IP.mode = 0;
    IP.cur ^= 1;  // this picture is the previous one for the next
}
static void *ip_worker(void *unused) {
    (void)unused;
    for (;;) {
        ip_passes(rdp_interp_next());
        rdp_interp_done();
    }
    return NULL;
}
static void ip_start(void) {
    pthread_t t;
    if (pthread_create(&t, NULL, ip_worker, NULL)) bt_fatal("starting the in-between worker");
    pthread_detach(t);
}

void gsp_run(u32 dl) {
    static int stats = -1;
    static pthread_once_t worker_once = PTHREAD_ONCE_INIT;
    int images = ip_images();
    rdp_begin();  // waits for the previous picture's in-between passes
    static double window, total, peak;
    static unsigned tasks;
    struct timespec start, end;
    if (stats < 0) stats = getenv("BT_RENDER_STATS") != NULL;
    if (stats) clock_gettime(CLOCK_MONOTONIC, &start);
    static int trace_skip = -2, trace_n;  // BT_GFX_TRACE=N or N@K: trace N tasks after skipping K
    if (trace_skip == -2) {
        const char *t = getenv("BT_GFX_TRACE"), *at = t ? strchr(t, '@') : NULL;
        trace_n = t ? atoi(t) : 0;
        trace_skip = at ? atoi(at + 1) : 0;
        trace_left = 0;
    }
    if (trace_skip == 0) trace_left = trace_n;
    if (trace_skip >= 0) trace_skip--;  // -1: armed or done
    rdp_interp_arm(images);
    IP.mode = images ? 1 : 0;
    IP.n[IP.cur] = IP.pending = IP.ndecision = 0;
    IP.last_root = -1;
    if (!images) IP.n[IP.cur ^ 1] = 0;  // no stale previous frame once the option comes back
    run(dl);
    IP.mode = 0;
    if (images) { ip_match(); IP.dl = dl; }
    rdp_end();
    trace_end(dl);
    if (stats) {
        clock_gettime(CLOCK_MONOTONIC, &end);
        double now = end.tv_sec + end.tv_nsec * 1e-9;
        double ms = (end.tv_sec - start.tv_sec) * 1000.0 + (end.tv_nsec - start.tv_nsec) * 1e-6;
        if (!window) window = start.tv_sec + start.tv_nsec * 1e-9;
        total += ms; tasks++;
        if (ms > peak) peak = ms;
        if (now - window >= 5) {
            fprintf(stderr, "render: scale=%d tasks/s=%.1f mean=%.2fms max=%.2fms\n",
                    rdp_scale(), tasks / (now - window), total / tasks, peak);
            if (IP.frames)
                fprintf(stderr, "interp: frames=%u matrices/frame=%.0f matched=%.1f%% desyncs=%u\n", IP.frames,
                        (double)IP.events / IP.frames, IP.events ? 100.0 * IP.matched / IP.events : 0.0, IP.desyncs);
            IP.frames = IP.events = IP.matched = IP.desyncs = 0;
            window = now; tasks = 0; total = peak = 0;
        }
    }
    if (images && rdp_gpu()) {  // GPU passes are quick: in the task, on the thread that owns the context
        if (rdp_interp_post(images)) ip_passes(images);
    } else if (images) {
        pthread_once(&worker_once, ip_start);
        rdp_interp_post(images);  // nothing when the task drew no VI image: its record is dropped
    }
}

static void run(u32 dl) {
    u32 stack[DL_DEPTH], pc = seg_addr(dl);
    int sp = 0;
    memset(S.seg, 0, sizeof S.seg);
    S.mvi = 0;
    mat_ident(S.mv[0]);
    mat_ident(S.proj);
    S.mvp_ok = S.lights_ok = S.forced = 0;
    S.geom = 0;
    S.tex_on = 0;
    for (long guard = 0; guard < 4000000; guard++) {
        const u8 *g = gmem(pc, 8);
        if (!g) { fprintf(stderr, "bt_native gsp: display list at 0x%08x outside memory\n", pc); return; }
        u32 w0 = be32(g), w1 = be32(g + 4), op = w0 >> 24;
        pc += 8;
        if (tracing()) trace_ops[op]++;
        if (tracing() && getenv("BT_GFX_DUMP")) fprintf(stderr, "    %08x [%d]: %08x %08x\n", pc - 8, sp, w0, w1);
        switch (op) {
        case 0x00: case 0xE0: case 0xD3: case 0xD4: case 0xD5: case 0xD6: case 0xDD: break;
        case 0x01: { int n = w0 >> 12 & 0xFF; ip_anchor(w1); load_vertices(seg_addr(w1), n, (int)(w0 >> 1 & 0x7F) - n); break; }
        case 0x02: {  // modify vertex
            int i = (w0 & 0xFFFF) / 2, where = w0 >> 16 & 0xFF;
            if (i >= MAX_VTX) break;
            if (where == 0x10) { S.v[i].c[0] = w1 >> 24; S.v[i].c[1] = w1 >> 16 & 255; S.v[i].c[2] = w1 >> 8 & 255; S.v[i].c[3] = w1 & 255; }
            else if (where == 0x14) { S.v[i].s = (s16)(w1 >> 16); S.v[i].t = (s16)w1; }
            break;
        }
        case 0x03: if (ip_decide(culled((w0 & 0xFFFF) / 2, (w1 & 0xFFFF) / 2))) goto end_dl; break;
        case 0x04: {  // branch if the vertex is nearer than w1
            int i = (w0 & 0xFFF) / 2;
            int near = 0;
            if (i < MAX_VTX && S.v[i].w > 1e-6f) {
                float z = (S.v[i].z / S.v[i].w * S.vscale[2] + S.vtrans[2]) * 32.0f;
                near = z <= (float)(s32)w1 || S.v[i].clip & CLIP_W;
            }
            if (ip_decide(near)) pc = seg_addr(S.half1);
            break;
        }
        case 0x05: triangle((w0 >> 16 & 0xFF) / 2, (w0 >> 8 & 0xFF) / 2, (w0 & 0xFF) / 2); break;
        case 0x06: case 0x07:
            triangle((w0 >> 16 & 0xFF) / 2, (w0 >> 8 & 0xFF) / 2, (w0 & 0xFF) / 2);
            triangle((w1 >> 16 & 0xFF) / 2, (w1 >> 8 & 0xFF) / 2, (w1 & 0xFF) / 2);
            break;
        case 0x08: line3d((w0 >> 16 & 0xFF) / 2, (w0 >> 8 & 0xFF) / 2, w0 & 0xFF); break;
        case 0xD7:
            S.tex_s = (w1 >> 16) / 65536.0f;
            S.tex_t = (w1 & 0xFFFF) / 65536.0f;
            S.tex_on = (w0 >> 1 & 0x7F) != 0;
            rdp_set_texture(w0 >> 8 & 7, w0 >> 11 & 7);
            break;
        case 0xD8: {
            int n = (int)(w1 / 64);
            S.mvi = S.mvi > n ? S.mvi - n : 0;
            S.mvp_ok = S.lights_ok = S.forced = 0;
            break;
        }
        case 0xD9: S.geom = (S.geom & (w0 | 0xFF000000)) | w1; break;
        case 0xDA: matrix(w0, w1, pc - 8); break;
        case 0xDB: moveword(w0, w1); break;
        case 0xDC: movemem(w0, w1); break;
        case 0xDE:
            ip_anchor(w1);
            if (!(w0 >> 16 & 0xFF)) {
                if (sp >= DL_DEPTH) { fprintf(stderr, "bt_native gsp: display list stack overflow\n"); return; }
                stack[sp++] = pc;
            }
            pc = seg_addr(w1);
            break;
        case 0xDF:
        end_dl:
            if (!sp) return;
            pc = stack[--sp];
            break;
        case 0xE1: S.half1 = w1; break;
        case 0xF1: break;
        case 0xE2: case 0xE3: {
            int len = (w0 & 0xFF) + 1, sft = 32 - (int)(w0 >> 8 & 0xFF) - len;
            u32 mask = (len >= 32 ? ~0u : (1u << len) - 1) << (sft < 0 ? 0 : sft);
            rdp_othermode(op == 0xE3, mask, w1);
            break;
        }
        case 0xE4: case 0xE5: {
            const u8 *h = gmem(pc, 16);
            if (!h) return;
            rdp_texrect(w0, w1, be32(h + 4), be32(h + 12), op == 0xE5);
            pc += 16;
            break;
        }
        case 0xFD: case 0xFE: case 0xFF:
            if (tracing() && op != 0xFD) fprintf(stderr, "  %s %08x width %u\n", op == 0xFF ? "cimg" : "zimg", seg_addr(w1), (w0 & 0xFFF) + 1);
            rdp_command(w0, seg_addr(w1));
            break;
        default:
            if (op >= 0xE6) { rdp_command(w0, w1); break; }
            {
                static u8 seen[256];
                if (!seen[op]++) fprintf(stderr, "bt_native gsp: command %02x not handled\n", op);
            }
        }
    }
    fprintf(stderr, "bt_native gsp: display list did not end\n");
}
