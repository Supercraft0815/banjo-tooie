// Software RDP (see rdp.h): TMEM loads, texture sampling, color combiner, blender,
// 16-bit N64 depth buffer, fill/copy/1-cycle/2-cycle rectangles and triangles.
// shortcut: no coverage/anti-aliasing, dithering or chroma key; the blender treats
// memory coverage as full. Upgrade when an effect visibly depends on them.
#include <math.h>
#include <pthread.h>
#include <stdatomic.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "plat.h"
#include "rdp.h"

static int gpu_enabled(void);
static void gpu_begin(void), gpu_end(void), gpu_resolve_address(u32 address);
static void gpu_release(void);
static void gpu_register(u32 address, int width, int widescreen);
static void pool_task(int on);
static int gpu_mask_load(void);
static void gpu_mask_touch(u32 address);
static void gpu_finish(void);  // the last task's GPU output is in RDRAM and scanout
static int gpu_done_later(u32 event);
static int load_tile_tile;  // the tile of the load_tile in progress, for gpu_mask_load
static int rice_load_owner; // tile+1 while a known RDRAM load writes TMEM; zero for unknown sources
static u32 rice_probe_block_src, rice_probe_block_bytes, rice_probe_block_tmem;
static u32 rice_probe_block_generation, rice_block_generation, rice_load_generation;
static u32 rice_tmem_generation[4096];
static int rice_probe_block_fmt, rice_probe_block_siz, rice_probe_block_valid;

typedef struct {
    int fmt, siz, line, tmem, pal, cms, cmt, masks, maskt, shifts, shiftt;
    int uls, ult, lrs, lrt;  // 10.2
    u32 rice_addr;
    u32 rice_generation;
    int rice_width, rice_height, rice_stride, rice_size, rice_format, rice_valid;
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
    // GPU renderer: TMEM bytes a load took from the GPU's CI8 image (gpu_mask_load) hold record + 1
    // here and stale bytes in tmem until the record is replayed from RDRAM (gpu_mask_materialize).
    u8 tsrc[4096];
    u8 rice_palette_valid[256];
    u8 rice_tmem_owner[4096];
    struct { u32 timg; int width, x0, y0, w, h, tmem, line, bytes; u32 uid; } trec[8];
    int tsrc_live;  // owned bytes of all records
} R = {.sc_x1 = 320 << 2, .sc_y1 = 240 << 2, .cimg_width = 320, .cimg_siz = 2};

// The in-between worker reads a snapshot of game memory taken after the real pass (rdp_interp_post),
// so the game can run on meanwhile; game memory is the first 16 MB (statics, heap arena, stacks).
#define SNAP_LIMIT (16u << 20)
static _Thread_local const u8 *snap_mem;
static u8 *gptr(u32 addr, u32 n) {
    if (snap_mem) return addr >= 0x80000000u && (u64)addr - 0x80000000u + n <= SNAP_LIMIT ? (u8 *)snap_mem + (addr - 0x80000000u) : NULL;
    return addr >= 0x80000000u && (u64)addr + n <= bt_inst.w2c_memory.size ? bt_mem + addr : NULL;
}
const u8 *rdp_mem(u32 addr, u32 n) {
#ifdef BT_IMAGE_ACCESS_HOST
    if (!snap_mem) bt_image_range(addr,n);
#endif
    return gptr(addr,n);
}
static inline u16 rd16(const u8 *p) { return (u16)(p[0] << 8 | p[1]); }
static inline void wr16(u8 *p, u32 v) { p[0] = (u8)(v >> 8); p[1] = (u8)v; }
static inline int clamp8(int v) { return v < 0 ? 0 : v > 255 ? 255 : v; }
// Every TMEM write of a load: the byte is valid in R.tmem from now on.
static inline void tmem_put(u32 a, u8 v) {
    a &= 0xFFF;
    R.tmem[a] = v;
    if (R.rice_tmem_owner[a]) R.tile[R.rice_tmem_owner[a] - 1].rice_valid = 0;
    R.rice_tmem_owner[a] = (u8)rice_load_owner;
    rice_tmem_generation[a] = rice_load_generation;
    if (a >= 0x800 && a < 0x1000 && ((a - 0x800) & 7) < 2)
        R.rice_palette_valid[(a - 0x800) >> 3] = 0;
    if (R.tsrc[a]) { R.trec[R.tsrc[a] - 1].bytes--; R.tsrc_live--; R.tsrc[a] = 0; }
}
static u64 texture_epoch = 1;
static u64 tmem_gen = 1, state_gen = 1;  // GPU renderer: TMEM loads; any RDP state change

void rdp_set_texture(int tile, int levels) { R.tex_tile = tile & 7; R.tex_levels = levels & 7; state_gen++; }

void rdp_othermode(int high, u32 mask, u32 value) {
    u32 *m = high ? &R.om_h : &R.om_l;
    state_gen++;
    *m = (*m & ~mask) | (value & mask);
    if (high && (mask & 0xC000)) texture_epoch++;
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

// Only VI-registered color images are enlarged. Offscreen images stay in RDRAM.
// Depth is keyed by its own RDRAM address: BT shares one Z image between color images.
typedef struct {
    u32 address;
    int width, height, sx, sy, dirty, changed;  // sx, sy: the scale the data was allocated for
    u8 *data, *resolved;
} Frame;
static Frame frames[3], depth;
static int scaled_depth_row;
static pthread_mutex_t frame_lock = PTHREAD_MUTEX_INITIALIZER;
static _Thread_local int in_render_task;
static pthread_mutex_t scanout_lock = PTHREAD_MUTEX_INITIALIZER;
typedef struct { u32 address, *pixels; int width, height, pixel_w, pixel_h; unsigned tex; float phase; } Picture;
static Picture scanout[3], ip_out[3 * BT_POSES_PER_PICTURE];
static u32 ip_addresses[3];  // each VI buffer keeps its own pictures until it is drawn again
static int ip_bank;
// Frame interpolation: in-between pictures of a task's scanout image, rasterized from its display
// list into host buffers (ip.color, ip.z). Guest memory, the RDP state and the noise sequence stay
// as the real pass left them, so the game never sees these passes.
static u32 vi_fbs[3];  // the color images the VI showed last, at every scale
static struct {
    int armed, on;      // in-between images wanted this task; a pass is rasterizing
    u32 address;        // the task's scanout image (0: none drawn)
    u8 *pre;            // its content before the task drew into it
    size_t bytes;
    u32 noise;          // the real pass's noise state, restored after an in-between pass
    Frame color, z;     // targets at the render scale; color.address = address
} ip;
static void interp_target(void);
void rdp_interp_wait(void);
static pthread_once_t scale_once = PTHREAD_ONCE_INIT;
// render_scale is the vertical factor; render_sx the horizontal one. They differ in the game's
// anamorphic widescreen mode, where 304 guest columns stand for a 16:9 picture.
static int render_scale = 1, render_sx = 1;
static _Atomic u32 window_pixels;
void rdp_window_size(int width, int height) {
    if (width > 0 && height > 0 && width <= 65535 && height <= 65535)
        atomic_store(&window_pixels, (u32)width << 16 | (u32)height);
}
static _Atomic int requested_scale;  // from the settings menu; applied between tasks

static void scale_init(void) {
    const char *s = getenv("BT_SCALE");
    if (s && (strlen(s) != 1 || s[0] < '1' || s[0] > '0' + RDP_MAX_SCALE))
        bt_fatal("BT_SCALE must be 1 to %d", RDP_MAX_SCALE);
    if (s) render_scale = render_sx = atoi(s);
}

int rdp_scale(void) { pthread_once(&scale_once, scale_init); return render_scale; }
void rdp_request_scale(int scale) { if (scale >= 1 && scale <= RDP_MAX_SCALE) atomic_store(&requested_scale, scale); }

static void frame_init(Frame *f, u32 address, int width) {
    int height = width * 3 / 4, sx = render_sx, sy = rdp_scale();
    if (f->address == address && f->width == width && f->sx == sx && f->sy == sy) return;
    free(f->data); free(f->resolved);
    *f = (Frame){.address = address, .width = width, .height = height, .sx = sx, .sy = sy, .changed = 1};
    f->data = calloc((size_t)width * height * sx * sy, 2);
    f->resolved = calloc((size_t)width * height, 2);
    if (!f->data || !f->resolved) bt_fatal("allocating scaled framebuffer");
}

// Import CPU writes (clears, pause/transition copies), retaining untouched subpixels.
static void frame_import(Frame *f) {
    int sx = render_sx, sy = render_scale;
    u8 *src = gptr(f->address, f->width * f->height * 2);
    if (!src) return;
    if (!memcmp(src, f->resolved, (size_t)f->width * f->height * 2)) return;
    for (int y = 0; y < f->height; y++) for (int x = 0; x < f->width; x++) {
        int i = (y * f->width + x) * 2;
        if (rd16(src + i) == rd16(f->resolved + i)) continue;
        f->changed = 1;
        for (int ry = 0; ry < sy; ry++) for (int rx = 0; rx < sx; rx++)
            wr16(f->data + ((y * sy + ry) * f->width * sx + x * sx + rx) * 2, rd16(src + i));
    }
    memcpy(f->resolved, src, (size_t)f->width * f->height * 2);
}

static void frame_publish(Frame *f) {
    int slot = (int)(f - frames), n = f->width * f->height * render_sx * render_scale;
    pthread_mutex_lock(&scanout_lock);
    if (!scanout[slot].pixels || scanout[slot].pixel_w != f->width * render_sx || scanout[slot].pixel_h != f->height * render_scale) {
        free(scanout[slot].pixels);
        scanout[slot].pixels = malloc((size_t)n * sizeof(u32));
        if (!scanout[slot].pixels) bt_fatal("allocating scanout image");
    }
    scanout[slot].address = f->address;
    scanout[slot].width = f->width; scanout[slot].height = f->height;
    scanout[slot].pixel_w = f->width * render_sx; scanout[slot].pixel_h = f->height * render_scale;
    for (int p = 0; p < n; p++) {
        int c[4]; rgba16(rd16(f->data + p * 2), c);
        scanout[slot].pixels[p] = 0xFF000000u | c[0] << 16 | c[1] << 8 | c[2];
    }
    pthread_mutex_unlock(&scanout_lock);
    f->changed = 0;
}

static void frame_resolve(Frame *f);

// A new scale from the menu: hi-res content goes down to RDRAM, then frames start over from it.
static void rescale(int scale) {
    for (int i = 0; i < 4; i++) frame_resolve(i == 3 ? &depth : &frames[i]);
    for (int i = 0; i < 4; i++) {
        Frame *f = i == 3 ? &depth : &frames[i];
        free(f->data); free(f->resolved);
        *f = (Frame){0};
    }
    pthread_mutex_lock(&scanout_lock);
    for (int i = 0; i < 3; i++) scanout[i].address = 0;  // scale 1 shows RDRAM directly
    pthread_mutex_unlock(&scanout_lock);
    render_scale = render_sx = scale;
}

void rdp_register_framebuffer(u32 address, int width, int widescreen) {
    static unsigned replace_slot;
    int want = atomic_exchange(&requested_scale, 0);
    if (want && want != rdp_scale()) {
        rdp_interp_wait();
        pthread_mutex_lock(&frame_lock);  // no task runs while it is held
        rescale(want);
        pthread_mutex_unlock(&frame_lock);
    }
    pthread_mutex_lock(&frame_lock);
    if (vi_fbs[0] != address && vi_fbs[1] != address && vi_fbs[2] != address) {
        vi_fbs[2] = vi_fbs[1]; vi_fbs[1] = vi_fbs[0]; vi_fbs[0] = address;
    }
    if (gpu_enabled()) gpu_register(address, width, widescreen);
    pthread_mutex_unlock(&frame_lock);
    if (gpu_enabled() || rdp_scale() == 1 || width < 16 || width > 640 || !gptr(address, width * (width * 3 / 4) * 2)) return;
    int sx = widescreen == 2 ? (render_scale * 7 + 2) / 4 : widescreen ? (render_scale * 4 + 1) / 3 : render_scale;  // nearest to 4:3 more columns
    if (sx != render_sx) rdp_interp_wait();
    pthread_mutex_lock(&frame_lock);  // no task runs while it is held
    if (sx != render_sx) {
        for (int i = 0; i < 3; i++) frame_resolve(&frames[i]);
        frame_resolve(&depth);
        render_sx = sx;
        for (int i = 0; i < 3; i++) if (frames[i].address) frame_init(&frames[i], frames[i].address, frames[i].width);
        if (depth.address) frame_init(&depth, depth.address, depth.width);
        for (int i = 0; i < 3; i++) if (frames[i].address) frame_import(&frames[i]);
        if (depth.address) frame_import(&depth);
    }
    int slot = -1;
    for (int i = 0; i < 3; i++) {
        if (frames[i].address == address) { slot = i; break; }
        if (!frames[i].address) slot = i;
    }
    if (slot < 0) slot = (int)(replace_slot++ % 3);
    frame_init(&frames[slot], address, width);
    frame_import(&frames[slot]);
    if (frames[slot].changed) frame_publish(&frames[slot]);
    pthread_mutex_unlock(&frame_lock);
}

static Frame *color_frame(void) {
    if (ip.on) {  // only the scanout image and the depth clear; other images are not drawn
        if (R.cimg_siz == 2 && R.cimg == ip.address && R.cimg_width == ip.color.width) return &ip.color;
        if (R.cimg == R.zimg && R.cimg_width == ip.z.width && (R.om_h >> 20 & 3) == 3 && R.fill == 0xFFFCFFFC) return &ip.z;
        return NULL;
    }
    if (render_scale == 1 || R.cimg_siz != 2) return NULL;
    for (int i = 0; i < 3; i++) {
        Frame *f = &frames[i];
        if (f->address == R.cimg && f->width == R.cimg_width) return f;
    }
    // BT also borrows Z memory as a color-copy target. Only its depth clear is enlarged;
    // color copies into that address must retain their RGBA16 bytes in RDRAM.
    if (R.cimg == R.zimg && depth.address == R.cimg && depth.width == R.cimg_width &&
        (R.om_h >> 20 & 3) == 3 && R.fill == 0xFFFCFFFC) return &depth;
    return NULL;
}

static int target_sx(void) { Frame *f = color_frame(); return f ? f->sx : 1; }
static int target_sy(void) { Frame *f = color_frame(); return f ? f->sy : 1; }

typedef struct { Frame *f; u8 *dst; int rows; } ResolveJob;
static void resolve_band(const void *job, int band, u32 *noise);
static void pool_for(void (*fn)(const void *, int, u32 *), const void *job, int bands);

static void frame_resolve(Frame *f) {
    if (!f->dirty) return;
    u8 *dst = gptr(f->address, f->width * f->height * 2);
    if (!dst) return;
    ResolveJob job = {f, dst, 8};
    pool_for(resolve_band, &job, (f->height + job.rows - 1) / job.rows);
    memcpy(f->resolved, dst, (size_t)f->width * f->height * 2);
    f->dirty = 0;
}

static void resolve_band(const void *job, int band, u32 *noise) {
    const ResolveJob *j = job;
    Frame *f = j->f;
    u8 *dst = j->dst;
    int sx = render_sx, sy = render_scale, n = sx * sy, y1 = (band + 1) * j->rows < f->height ? (band + 1) * j->rows : f->height;
    (void)noise;
    for (int y = band * j->rows; y < y1; y++) for (int x = 0; x < f->width; x++) {
        u32 sum[4] = {0}, z = 0;
        for (int ry = 0; ry < sy; ry++) for (int rx = 0; rx < sx; rx++) {
            u32 v = rd16(f->data + ((y * sy + ry) * f->width * sx + x * sx + rx) * 2);
            if (f == &depth) z += z_decompress(v >> 2);
            else { sum[0] += v >> 11; sum[1] += v >> 6 & 31; sum[2] += v >> 1 & 31; sum[3] += v & 1; }
        }
        u32 v = f == &depth ? z_compress(z / n) << 2 :
            (sum[0] / n) << 11 | (sum[1] / n) << 6 | (sum[2] / n) << 1 | (sum[3] * 2 >= (u32)n);
        wr16(dst + (y * f->width + x) * 2, v);
    }
}

static void resolve_all(void) {
    for (int i = 0; i < 3; i++) frame_resolve(&frames[i]);
    frame_resolve(&depth);
}

static void resolve_texture(u32 address) {
    if (ip.on) return;  // RDRAM holds the real pass, resolved before the in-between passes
    if (gpu_enabled()) { gpu_resolve_address(address); return; }
    for (int i = 0; i < 4; i++) {
        Frame *f = i == 3 ? &depth : &frames[i];
        if (f->address && address >= f->address && (u64)address < (u64)f->address + f->width * f->height * 2)
            frame_resolve(f);
    }
}

static typeof(R) task_state, real_state;
void rdp_begin(void) {
    rdp_scale();
    rdp_interp_wait();  // the previous picture's in-between passes use the same RDP state
    pthread_mutex_lock(&frame_lock);
    in_render_task = 1;
    ip.armed = 0;
    ip.address = 0;
    gpu_begin();
    pool_task(1);
    for (int i = 0; i < 3; i++) if (frames[i].address) frame_import(&frames[i]);
    if (depth.address) frame_import(&depth);
}

void rdp_end(void) {
    gpu_end();
    if (ip.armed) gpu_finish();  // in-between passes start from the state the task leaves
    // Publish only complete tasks; the window never waits for a full raster pass.
    for (int i = 0; i < 3; i++) if (frames[i].changed) { gpu_finish(); frame_publish(&frames[i]); }
    resolve_all();  // still on the pool
    pool_task(0);
    if (gpu_enabled()) gpu_release();
    in_render_task = 0;
    pthread_mutex_unlock(&frame_lock);
}

int rdp_done_later(u32 event) { return gpu_done_later(event); }

// Caller holds scanout_lock. Fractional targets publish their physical dimensions.
static Picture *picture_slot(Picture *slots, int count, u32 address, int width, int height, int texture) {
    for (int i = 0; address && i < count; i++) {
        Picture *p = &slots[i];
        if (p->address == address && p->width == width && p->height == height &&
            (texture ? p->tex != 0 : p->pixels != NULL)) return p;
    }
    return NULL;
}
static Picture *in_between(u32 address, int width, int height, int index, int texture) {
    if (index < 0 || index >= BT_POSES_PER_PICTURE) return NULL;
    for (int i = 0; i < 3; i++) {
        if (ip_addresses[i] == address)
            return picture_slot(&ip_out[i * BT_POSES_PER_PICTURE + index], 1, address, width, height, texture);
    }
    return NULL;
}
int rdp_picture_phase(u32 address, float phase) {
    float distance = 1 - phase;
    int index = -1;
    pthread_mutex_lock(&scanout_lock);
    for (int i = 0; i < 3; i++) if (address && ip_addresses[i] == address) {
        for (int j = 0; j < BT_POSES_PER_PICTURE; j++) {
            Picture *p = &ip_out[i * BT_POSES_PER_PICTURE + j];
            float d = fabsf(phase - p->phase);
            if (p->address == address && d < distance) { distance = d; index = j; }
        }
        break;
    }
    pthread_mutex_unlock(&scanout_lock);
    return index;
}
static Picture *picture_for(u32 address, int width, int height, int index, int texture) {
    Picture *p = in_between(address, width, height, index, texture);
    return p ? p : picture_slot(scanout, 3, address, width, height, texture);
}
void rdp_reserve_pixels(u32 **pixels, size_t *capacity, int w, int h) {
    if (w <= 0 || h <= 0 || (size_t)w > SIZE_MAX / sizeof(u32) / (size_t)h) bt_fatal("invalid picture dimensions");
    size_t n = (size_t)w * h;
    if (*capacity >= n) return;
    u32 *new_pixels = realloc(*pixels, n * sizeof(u32));
    if (!new_pixels) bt_fatal("allocating a %d x %d picture", w, h);
    *pixels = new_pixels;
    *capacity = n;
}
int rdp_picture(u32 address, int width, int height, int index, u32 **pixels, size_t *capacity, int *w, int *h) {
    pthread_mutex_lock(&scanout_lock);
    Picture *p = picture_for(address, width, height, index, 0);
    if (p) {
        *w = p->pixel_w; *h = p->pixel_h;
        rdp_reserve_pixels(pixels, capacity, *w, *h);
        memcpy(*pixels, p->pixels, (size_t)*w * *h * sizeof(u32));
    }
    pthread_mutex_unlock(&scanout_lock);
    return p != NULL;
}
// Existing integer-scale consumers reserve space for RDP_MAX_SX by RDP_MAX_SCALE.
static int integer_picture(int index, u32 address, int width, int height, u32 *pixels, int *sx) {
    int sy = 0;
    pthread_mutex_lock(&scanout_lock);
    Picture *p = index < 0 ? picture_slot(scanout, 3, address, width, height, 0)
                           : in_between(address, width, height, index, 0);
    if (p && p->pixel_w % width == 0 && p->pixel_h % height == 0 &&
        p->pixel_w / width <= RDP_MAX_SX && p->pixel_h / height <= RDP_MAX_SCALE) {
        *sx = p->pixel_w / width; sy = p->pixel_h / height;
        memcpy(pixels, p->pixels, (size_t)p->pixel_w * p->pixel_h * sizeof(u32));
    }
    pthread_mutex_unlock(&scanout_lock);
    return sy;
}
int rdp_frame(u32 address, int width, int height, u32 *pixels, int *sx) {
    return integer_picture(-1, address, width, height, pixels, sx);
}
int rdp_interp_frame(u32 address, int width, int height, int index, u32 *pixels, int *sx) {
    return index >= 0 ? integer_picture(index, address, width, height, pixels, sx) : 0;
}
static void gpu_window_picture(unsigned tex);  // scanout_lock is held
unsigned rdp_frame_texture(u32 address, int width, int height, int index, int *w, int *h) {
    unsigned tex = 0;
    pthread_mutex_lock(&scanout_lock);
    Picture *p = picture_for(address, width, height, index, 1);
    if (p) { tex = p->tex; *w = p->pixel_w; *h = p->pixel_h; }
    gpu_window_picture(tex);
    pthread_mutex_unlock(&scanout_lock);
    return tex;
}
static void palette(int index, int *o) {
    const u8 *p = R.tmem + 0x800 + (index & 255) * 8;
    u32 v = rd16(p);
    if ((R.om_h >> 14 & 3) == 3) { o[0] = o[1] = o[2] = v >> 8; o[3] = v & 255; }  // IA16 lookup table
    else rgba16(v, o);
}
// Keep the decode slow path out of the inlined per-pixel cache lookup.
static __attribute__((noinline)) void decode_texel(const Tile *tl, int s, int t, int *o) {
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
static inline __attribute__((always_inline)) void texel(const Tile *tl, int s, int t, int *o) {
    // Adjacent high-resolution fragments repeatedly filter the same four N64 texels.
    static _Thread_local struct { u64 epoch; int s, t, color[4]; } cache[8][1024];  // per raster thread
    unsigned slot = ((unsigned)s + (unsigned)t * 32) & 1023;
    __typeof__(cache[0][0]) *c = &cache[tl - R.tile][slot];
    if (c->epoch != texture_epoch || c->s != s || c->t != t) {
        decode_texel(tl, s, t, c->color);
        c->s = s; c->t = t; c->epoch = texture_epoch;
    }
    memcpy(o, c->color, sizeof c->color);
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
static void sample(int index, float s, float t, int filter, int *restrict o) {
    const Tile *tl = &R.tile[index & 7];
    int ms = (tl->lrs - tl->uls) >> 2, mt = (tl->lrt - tl->ult) >> 2;
    s = fmaf(-tl->uls, 0.25f, shifted(s, tl->shifts));
    t = fmaf(-tl->ult, 0.25f, shifted(t, tl->shiftt));
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
static u32 noise_state = 1;

// GPU renderer, 8-bit images (the player shadow's mask, rdp_gl.h gpu_mask_defer): while `on`, pixels
// whose depth test needs Z memory are not tested here but kept as fragments in draw order (with any
// pixel drawn after them); the GPU tests them against its depth (gpu_mask_compose) or the CPU does after
// a readback (gpu_mask_finalize). Raster, depth values and shading stay exactly these of rdp.c.
typedef struct { u32 off, z, zdz; u16 value; u8 ztest, decal; } MaskFrag;  // ztest: 0 no, 1 yes, 2 yes but no write
static struct {
    int on;  // the current draw
    u32 base; int width, height; u8 *bp;
    MaskFrag *f; int n, cap;
    u32 noise;  // noise steps of fragments that pass, owed to noise_state
} mdefer;
static void mask_frag(u8 *cp, u32 z, u32 zdz, int ztest, int value) {
    if (mdefer.n == mdefer.cap && !(mdefer.f = realloc(mdefer.f, (size_t)(mdefer.cap = mdefer.cap * 2 + 1024) * sizeof *mdefer.f)))
        bt_fatal("allocating mask fragments");
    mdefer.f[mdefer.n++] = (MaskFrag){(u32)(cp - mdefer.bp), z, zdz, (u16)value, (u8)ztest, (u8)((R.om_l >> 10 & 3) == 3)};
}
typedef struct {
    int src[C_N][4];
    int cycles;  // 1 or 2
    int texture0, texture1;
    u32 *noise;  // the combiner's noise generator: the global one, or a band's own (worker threads)
} Pipe;

static void pipe_begin(Pipe *p) {
    memset(p->src, 0, sizeof p->src);
    p->noise = &noise_state;
    for (int i = 0; i < 4; i++) {
        p->src[C_PRIM][i] = R.prim[i]; p->src[C_ENV][i] = R.env[i]; p->src[C_ONE][i] = 256;
        p->src[C_PRIM_A][i] = R.prim[3]; p->src[C_ENV_A][i] = R.env[3]; p->src[C_PLOD][i] = R.prim_lod;
        p->src[C_K4][i] = R.k4; p->src[C_K5][i] = R.k5;
    }
    p->cycles = (R.om_h >> 20 & 3) == 1 ? 2 : 1;
    p->texture0 = p->texture1 = 0;
    for (int cycle = p->cycles == 2 ? 0 : 1; cycle < 2; cycle++) for (int i = 0; i < 4; i++) {
        int rgb = R.rgb[cycle][i], alpha = R.alpha[cycle][i];
        p->texture0 |= rgb == C_T0 || rgb == C_T0_A || alpha == C_T0 || alpha == C_T0_A;
        p->texture1 |= rgb == C_T1 || rgb == C_T1_A || alpha == C_T1 || alpha == C_T1_A;
    }
}

static int depth_pass(const u8 *zp, u32 z, u32 zdz) {
    u32 cz = z_compress(z), oz = z_decompress(rd16(zp) >> 2), zq = z_decompress(cz);
    if ((R.om_l >> 10 & 3) == 3) {
        u32 tol = zdz + (1u << Z_SHIFT[cz >> 11]) * 2;
        return zq <= oz + tol && zq + tol >= oz;
    }
    return zq <= oz;
}

static void combine(Pipe *restrict p, int cycle, int *restrict out) {
    const u8 *c = R.rgb[cycle], *a = R.alpha[cycle];
    for (int i = 0; i < 3; i++)
        out[i] = clamp8((((p->src[c[0]][i] - p->src[c[1]][i]) * p->src[c[2]][i] + 0x80) >> 8) + p->src[c[3]][i]);
    out[3] = clamp8((((p->src[a[0]][3] - p->src[a[1]][3]) * p->src[a[2]][3] + 0x80) >> 8) + p->src[a[3]][3]);
}

// Blends color in (alpha in[3]) with memory for one blender cycle (0 or 1).
static inline __attribute__((always_inline)) void blend(int cycle, const int *in, int shade_a, const int *mem, int *out) {
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
static inline __attribute__((always_inline)) void pixel(Pipe *restrict p, u8 *cp, u8 *zp, u32 z, u32 zdz, int zon) {
    u32 oml = R.om_l;
    u32 cz = 0;
    int defer = 0;
    if (zon && zp && (oml & 0x10) && mdefer.on) defer = 1;  // tested later (mask_frag)
    else if (zon && zp && (oml & 0x10)) {  // Z_CMP
        cz = z_compress(z);
        u32 oz = z_decompress(rd16(zp) >> 2), zq = z_decompress(cz);
        if ((oml >> 10 & 3) == 3) {  // decal: equal within the slope
            u32 tol = zdz + (1u << Z_SHIFT[cz >> 11]) * 2;
            if (zq > oz + tol || zq + tol < oz) return;
        } else if (zq > oz) return;
    }
    int *comb = p->src[C_COMB], out[4];
    u32 noise = defer ? *p->noise : (*p->noise = *p->noise * 1664525u + 1013904223u);  // defer: no noise in the combiner
    for (int i = 0; i < 4; i++) p->src[C_NOISE][i] = noise >> 24;
    combine(p, p->cycles == 2 ? 0 : 1, out);
    if (p->cycles == 2) {
        memcpy(comb, out, sizeof out);
        for (int i = 0; i < 4; i++) p->src[C_COMB_A][i] = out[3];
        combine(p, 1, out);
    }
    if (((oml & 3) == 1 && out[3] < R.blend[3]) ||  // alpha compare against the blend alpha
        ((oml & 0x2000) && !(oml & 0x4000) && out[3] < ((oml & 0x1000) ? 128 : 8))) {  // alpha as coverage
        if (defer) mask_frag(cp, z, zdz, 2, 0);  // no write, but its noise step if it passes
        return;
    }
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
    if (mdefer.on && (defer || mdefer.n)) { mask_frag(cp, z, zdz, defer, res[0]); return; }  // 8-bit image, no Z update
    write_pixel(cp, res);
    if (zon && zp && (oml & 0x20)) {  // Z_UPD
        wr16(zp, (cz ? cz : z_compress(z)) << 2);
        if (scaled_depth_row) depth.dirty = 1;
    }
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
    scaled_depth_row = 0;
    Frame *f = color_frame();
    if (ip.on) {
        if (!f) return 0;
        *cp = f->data + (size_t)y * f->width * f->sx * 2;
        *zp = f == &ip.z ? NULL : ip.z.data + (size_t)y * f->width * f->sx * 2;
        return 1;
    }
    if (f) {
        f->dirty = f->changed = 1;
        *cp = f->data + (size_t)y * f->width * render_sx * 2;
        *zp = NULL;
        if (f != &depth && depth.address == R.zimg && depth.width == f->width && depth.sx == render_sx) {
            *zp = depth.data + (size_t)y * f->width * render_sx * 2;
            scaled_depth_row = 1;
        }
        return 1;
    }
    if (R.cimg == depth.address) frame_resolve(&depth);
    int bpp = pixel_bytes();
    *cp = gptr(R.cimg + (u32)(y * R.cimg_width) * bpp, (u32)R.cimg_width * bpp);
    *zp = R.zimg ? gptr(R.zimg + (u32)(y * R.cimg_width) * 2, (u32)R.cimg_width * 2) : NULL;
    return *cp != NULL;
}

static void clip_rect(int *x0, int *y0, int *x1, int *y1) {
    int kx = target_sx(), ky = target_sy();
    int sx0 = R.sc_x0 * kx >> 2, sy0 = R.sc_y0 * ky >> 2;
    int sx1 = R.sc_x1 * kx >> 2, sy1 = R.sc_y1 * ky >> 2;
    if (sx1 > R.cimg_width * kx) sx1 = R.cimg_width * kx;
    Frame *f = color_frame();
    if (f && sy1 > f->height * ky) sy1 = f->height * ky;
    if (*x0 < sx0) *x0 = sx0;
    if (*y0 < sy0) *y0 = sy0;
    if (*x1 > sx1) *x1 = sx1;
    if (*y1 > sy1) *y1 = sy1;
}

// ---- Rectangles
#include "rdp_gl.h"

typedef struct { int x0, x1, y0, y1, kx, bpp, rows; } FillJob;
static void fill_band(const void *job, int band, u32 *noise) {
    const FillJob *j = job;
    int ya = j->y0 + band * j->rows, yb = ya + j->rows < j->y1 ? ya + j->rows : j->y1, bpp = j->bpp;
    (void)noise;
    for (int y = ya; y < yb; y++) {
        u8 *cp, *zp;
        if (!row_ptrs(y, &cp, &zp)) continue;
        for (int x = j->x0; x < j->x1; x++) {
            u8 *d = cp + x * bpp;
            if (bpp == 4) { d[0] = (u8)(R.fill >> 24); d[1] = (u8)(R.fill >> 16); d[2] = (u8)(R.fill >> 8); d[3] = (u8)R.fill; }
            else if (bpp == 2) wr16(d, (x / j->kx) & 1 ? R.fill & 0xFFFF : R.fill >> 16);
            else d[0] = (u8)(R.fill >> (24 - 8 * (x & 3)));
        }
    }
}

static void fill_rect(int ulx, int uly, int lrx, int lry) {
    if (gpu_fill(ulx, uly, lrx, lry)) return;
    int kx = target_sx(), ky = target_sy();
    int cyc = R.om_h >> 20 & 3, bpp = pixel_bytes();
    int x0 = ulx * kx >> 2, y0 = uly * ky >> 2, x1, y1;
    if (cyc >= 2) { x1 = ((lrx >> 2) + 1) * kx; y1 = ((lry >> 2) + 1) * ky; }  // fill/copy: inclusive
    else { x1 = (lrx * kx + 3) >> 2; y1 = (lry * ky + 3) >> 2; }
    clip_rect(&x0, &y0, &x1, &y1);
    if (cyc == 3) {  // fill mode: plain stores, in bands on the pool
        FillJob job = {x0, x1, y0, y1, kx, bpp, 8};
        if (y1 > y0) pool_for(fill_band, &job, (y1 - y0 + job.rows - 1) / job.rows);
        return;
    }
    for (int y = y0; y < y1; y++) {
        u8 *cp, *zp;
        if (!row_ptrs(y, &cp, &zp)) continue;
        {
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
    if (gpu_texrect(w0, w1, st, dsdt, flip)) return;
    int kx = target_sx(), ky = target_sy();
    int xh = w0 >> 12 & 0xFFF, yh = w0 & 0xFFF, tile = w1 >> 24 & 7, xl = w1 >> 12 & 0xFFF, yl = w1 & 0xFFF;
    int cyc = R.om_h >> 20 & 3, bpp = pixel_bytes();
    float s0 = (s16)(st >> 16) / 32.0f, t0 = (s16)st / 32.0f;
    float dsdx = (s16)(dsdt >> 16) / 1024.0f, dtdy = (s16)dsdt / 1024.0f;
    int x0 = xl * kx >> 2, y0 = yl * ky >> 2, x1, y1;
    if (cyc >= 2) { x1 = ((xh >> 2) + 1) * kx; y1 = ((yh >> 2) + 1) * ky; dsdx /= 4; }
    else { x1 = (xh * kx + 3) >> 2; y1 = (yh * ky + 3) >> 2; }
    dsdx /= kx; dtdy /= ky;
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

// One triangle after setup: everything its row loop reads, so bands of rows can run on several
// threads.
typedef struct {
    int bx0, bx1, by0, by1, bpp, persp, tex, lod_on, filter, zon, dbg;
    float x0, y0, ea[3], eb[3], ec[3], f0[NA], dx[NA], dy[NA];
    u32 zdz;
    u8 *cp0, *zp0;  // row by0 of a scaled frame, rows are stride bytes apart; NULL: row_ptrs per row
    size_t stride;
} Tri;

static void tri_rows(const Tri *tr, int ya, int yb, u32 *noise) {
    const float *ea = tr->ea, *eb = tr->eb, *ec = tr->ec, *dx = tr->dx, *dy = tr->dy;
    const float (*f)[NA] = (const float (*)[NA])tr->f0;
    float x0 = tr->x0, y0 = tr->y0;
    int bx0 = tr->bx0, bx1 = tr->bx1, bpp = tr->bpp, persp = tr->persp, tex = tr->tex, lod_on = tr->lod_on;
    int filter = tr->filter, zon = tr->zon, dbg = tr->dbg;
    u32 zdz = tr->zdz;
    Pipe p;
    pipe_begin(&p);
    if (noise) p.noise = noise;
    for (int y = ya; y < yb; y++) {
        u8 *cp, *zp;
        if (tr->cp0) {
            cp = tr->cp0 + (size_t)(y - tr->by0) * tr->stride;
            zp = tr->zp0 ? tr->zp0 + (size_t)(y - tr->by0) * tr->stride : NULL;
        } else if (!row_ptrs(y, &cp, &zp)) continue;
        float py = y + 0.5f;
        for (int x = bx0; x < bx1; x++) {
            float px = x + 0.5f;
            int in = 1;
            for (int i = 0; i < 3 && in; i++) {
                float e = fmaf(ea[i], px, eb[i] * py) + ec[i];
                in = e > 0 || (e == 0 && (ea[i] > 0 || (ea[i] == 0 && eb[i] > 0)));
            }
            if (!in) continue;
            float ox = px - x0, oy = py - y0, a[NA];
            for (int k = 0; k < NA; k++) a[k] = fmaf(dy[k], oy, fmaf(dx[k], ox, f[0][k]));
            u32 z = (R.om_l >> 2 & 1) ? R.prim_z : a[A_Z] <= 0 ? 0 : a[A_Z] >= 0x3FFFF ? 0x3FFFF : (u32)a[A_Z];
            // Reject hidden fragments before perspective division, filtering and shading.
            if (dbg != 2 && zon && zp && (R.om_l & 0x10) && !mdefer.on && !depth_pass(zp + x * 2, z, zdz)) continue;
            int shade[4], t0[4] = {0}, t1[4] = {0}, lod = 0;
            for (int k = 0; k < 4; k++) shade[k] = clamp8((int)a[A_R + k]);
            if (tex && (p.texture0 || p.texture1 || lod_on || dbg)) {
                float w = a[A_W] > 1e-9f ? 1.0f / a[A_W] : 1e9f;
                float s = (persp ? a[A_S] * w : a[A_S]) / 32.0f, t = (persp ? a[A_T] * w : a[A_T]) / 32.0f;
                int t0i = R.tex_tile, t1i = R.tex_tile + 1;
                if (lod_on) {
                    float dsx = persp ? fmaf(-s * 32, dx[A_W], dx[A_S]) * w : dx[A_S];
                    float dtx = persp ? fmaf(-t * 32, dx[A_W], dx[A_T]) * w : dx[A_T];
                    float dsy = persp ? fmaf(-s * 32, dy[A_W], dy[A_S]) * w : dy[A_S];
                    float dty = persp ? fmaf(-t * 32, dy[A_W], dy[A_T]) * w : dy[A_T];
                    float l = fmaxf(fmaxf(fabsf(dsx), fabsf(dtx)), fmaxf(fabsf(dsy), fabsf(dty))) / 32.0f;
                    if (l >= 1.0f) {
                        int lv = (int)log2f(l);
                        if (lv >= R.tex_levels) { lv = R.tex_levels; lod = 255; }
                        else lod = clamp8((int)((l / (float)(1 << lv) - 1.0f) * 256));
                        t0i = R.tex_tile + lv;
                        t1i = R.tex_tile + (lv < R.tex_levels ? lv + 1 : lv);
                    }
                }
                if (p.texture0 || (p.texture1 && p.cycles == 1) || dbg) sample(t0i, s, t, filter, t0);
                if (p.texture1 || dbg) {
                    if (p.cycles == 2) sample(t1i, s, t, filter, t1); else memcpy(t1, t0, sizeof t0);
                }
            }
            {
              if (dbg == 1) { for (int k = 0; k < 4; k++) t0[k] = t1[k] = 255; }
              if (dbg == 2) { memcpy(shade, t0, sizeof t0); shade[3] = 255; for (int k = 0; k < 4; k++) t1[k] = 255; R.rgb[0][0]=R.rgb[1][0]=C_SHADE; R.rgb[0][1]=R.rgb[1][1]=C_ZERO; R.rgb[0][2]=R.rgb[1][2]=C_ONE; R.rgb[0][3]=R.rgb[1][3]=C_ZERO; }
            }
            set_inputs(&p, shade, t0, t1, lod);
            pixel(&p, cp + x * bpp, zp ? zp + x * 2 : NULL, z, zdz, zon);
        }
    }
}

// ---- Raster threads (BT_SCALE > 1): the rows of a large triangle are shaded on several cores.
// The workers spin between triangles while a task runs (waking a sleeping thread costs more than
// most triangles) and sleep between tasks. BT_THREADS=n sets their number including the caller;
// 1 turns them off. BT_SCALE=1 always rasterizes on the caller: it is the bit-exact reference.
#if defined(__aarch64__)
#define cpu_relax() __asm__ volatile("yield")
#elif defined(__x86_64__) || defined(__i386__)
#define cpu_relax() __builtin_ia32_pause()
#else
#define cpu_relax() ((void)0)
#endif
static struct {
    pthread_mutex_t lock;
    pthread_cond_t wake;
    int nthreads, started;
    _Atomic int active, left;  // a task is running; bands of the current triangle not finished
    _Atomic int sleepers;      // workers waiting on wake for a job
    _Atomic u64 state;         // job number << 32 | next band << 16 | bands: claimed with one CAS
    void (*fn)(const void *job, int band, u32 *noise);
    const void *job;
    u32 seed;
} pool = {.lock = PTHREAD_MUTEX_INITIALIZER, .wake = PTHREAD_COND_INITIALIZER};

static void pool_bands(void) {
    for (;;) {
        u64 st = atomic_load(&pool.state);
        int band = (int)(st >> 16 & 0xFFFF), bands = (int)(st & 0xFFFF);
        if (band >= bands) return;
        if (!atomic_compare_exchange_weak(&pool.state, &st, st + 0x10000)) continue;
        u32 noise = pool.seed + (u32)band * 0x9E3779B9u;
        pool.fn(pool.job, band, &noise);  // published before the state that let this band be claimed
        atomic_fetch_sub(&pool.left, 1);
    }
}

static int pool_pending(void) {
    u64 st = atomic_load(&pool.state);
    return (int)(st >> 16 & 0xFFFF) < (int)(st & 0xFFFF);
}

// Workers spin up to 200 us for the next job (triangles of one task come in quick succession), then
// sleep, so idle raster threads leave the cores to the game, audio and in-between threads.
static void *pool_worker(void *unused) {
    (void)unused;
    for (;;) {
        struct timespec t0, t;
        clock_gettime(CLOCK_MONOTONIC, &t0);
        for (int spin = 1; !pool_pending(); spin++) {
            cpu_relax();
            if (spin % 256) continue;
            clock_gettime(CLOCK_MONOTONIC, &t);
            if ((t.tv_sec - t0.tv_sec) * 1000000000L + (t.tv_nsec - t0.tv_nsec) > 200000) break;
        }
        if (!pool_pending()) {
            pthread_mutex_lock(&pool.lock);
            atomic_fetch_add(&pool.sleepers, 1);
            while (!pool_pending()) pthread_cond_wait(&pool.wake, &pool.lock);
            atomic_fetch_sub(&pool.sleepers, 1);
            pthread_mutex_unlock(&pool.lock);
        }
        pool_bands();
    }
}

static void pool_task(int on) {
    if (on && !pool.started && render_scale > 1 && !gpu_enabled()) {  // scale 1 rasterizes on the caller
        const char *e = getenv("BT_THREADS");
        long n = e ? atol(e) : bt_cpu_count() - 2;
        pool.nthreads = render_scale == 1 || n < 2 ? 1 : n > 8 ? 8 : (int)n;
        pool.started = 1;
        for (int i = 1; i < pool.nthreads; i++) {
            pthread_t t;
            if (pthread_create(&t, NULL, pool_worker, NULL) != 0) { pool.nthreads = i; break; }
            pthread_detach(t);
        }
    }
    if (pool.nthreads < 2) return;
    atomic_store(&pool.active, on);
}

// Runs fn for bands 0..bands-1 on the pool, the caller included; serially outside a task.
static void pool_for(void (*fn)(const void *, int, u32 *), const void *job, int bands) {
    if (pool.nthreads < 2 || !atomic_load(&pool.active) || bands < 2) {
        for (int b = 0; b < bands; b++) fn(job, b, NULL);
        return;
    }
    pool.fn = fn;
    pool.job = job;
    pool.seed = noise_state;
    atomic_store(&pool.left, bands);
    atomic_store(&pool.state, ((atomic_load(&pool.state) >> 32) + 1) << 32 | (u64)bands);
    if (atomic_load(&pool.sleepers)) {  // seq_cst: a worker counted after this load sees the new state
        pthread_mutex_lock(&pool.lock);
        pthread_cond_broadcast(&pool.wake);
        pthread_mutex_unlock(&pool.lock);
    }
    pool_bands();  // the caller takes bands too
    while (atomic_load(&pool.left)) cpu_relax();
}

typedef struct { const Tri *tr; int rows; } TriJob;
static void tri_band(const void *job, int band, u32 *noise) {
    const TriJob *j = job;
    int ya = j->tr->by0 + band * j->rows, yb = ya + j->rows < j->tr->by1 ? ya + j->rows : j->tr->by1;
    tri_rows(j->tr, ya, yb, noise);
}

static void pool_run(const Tri *tr) {
    int rows = tr->by1 - tr->by0, bands = pool.nthreads * 4;
    if (bands > rows / 4) bands = rows / 4;
    TriJob job = {tr, (rows + bands - 1) / bands};
    pool_for(tri_band, &job, (rows + job.rows - 1) / job.rows);
    noise_state = noise_state * 1664525u + 1013904223u;
}

void rdp_triangle(const RdpVtx *va, const RdpVtx *vb, const RdpVtx *vc, int flags) {
    if (gpu_triangle(va, vb, vc, flags)) return;
    static int dbg = -1;
    if (dbg < 0) dbg = getenv("BT_RDP_DEBUG") ? atoi(getenv("BT_RDP_DEBUG")) : 0;
    const RdpVtx *v[3] = {va, vb, vc};
    int cyc = R.om_h >> 20 & 3;
    if (cyc >= 2) return;
    float kx = (float)target_sx(), ky = (float)target_sy();
    float x0 = va->x * kx, y0 = va->y * ky, x1 = vb->x * kx, y1 = vb->y * ky;
    float x2 = vc->x * kx, y2 = vc->y * ky;
    float area = fmaf(x1 - x0, y2 - y0, -((x2 - x0) * (y1 - y0)));
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
        dx[k] = fmaf(d1, y2 - y0, -d2 * (y1 - y0)) * inv;
        dy[k] = fmaf(d2, x1 - x0, -d1 * (x2 - x0)) * inv;
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
        ec[i] = -fmaf(ea[i], ex[i], eb[i] * ey[i]);
    }
    int lod_on = tex && (R.om_h >> 16 & 1), filter = (R.om_h >> 12 & 3) != 0, zon = (flags & RDP_Z) != 0;
    u32 zdz = (u32)(fabsf(dx[A_Z]) + fabsf(dy[A_Z]));
#ifdef BT_GPU_OPENGL
    if (mdefer.on) gpu_shadow_triangle(v,flags,zdz);
#endif
    Tri tr = {.bx0 = bx0, .bx1 = bx1, .by0 = by0, .by1 = by1, .bpp = bpp, .persp = persp, .tex = tex,
              .lod_on = lod_on, .filter = filter, .zon = zon, .dbg = dbg, .x0 = x0, .y0 = y0, .zdz = zdz};
    memcpy(tr.ea, ea, sizeof ea); memcpy(tr.eb, eb, sizeof eb); memcpy(tr.ec, ec, sizeof ec);
    memcpy(tr.f0, f[0], sizeof tr.f0); memcpy(tr.dx, dx, sizeof dx); memcpy(tr.dy, dy, sizeof dy);
    Frame *fr = color_frame();
    if (pool.nthreads > 1 && fr && !dbg && by1 - by0 >= 8 && (long)(bx1 - bx0) * (by1 - by0) >= 2048 &&
        row_ptrs(by0, &tr.cp0, &tr.zp0)) {
        tr.stride = (size_t)fr->width * fr->sx * 2;
        pool_run(&tr);
        return;
    }
    tr.cp0 = tr.zp0 = NULL;
    tri_rows(&tr, by0, by1, NULL);
}

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
    rice_load_owner = 0;
    texture_epoch++;
    tmem_gen++;
    resolve_texture(R.timg);
    gpu_mask_touch(R.timg);
    Tile *tl = &R.tile[w1 >> 24 & 7];
    int uls = w0 >> 12 & 0xFFF, ult = w0 & 0xFFF, lrs = w1 >> 12 & 0xFFF, dxt = w1 & 0xFFF, siz = R.timg_siz;
    tl->uls = uls << 2; tl->ult = ult << 2; tl->lrs = lrs << 2; tl->lrt = dxt << 2;
    u32 texels = (u32)(lrs - uls + 1), bytes = siz == 0 ? (texels + 1) / 2 : texels << (siz - 1);
    u32 src = R.timg + (((u32)(ult * R.timg_width + uls) << siz) >> 1), tm = (u32)tl->tmem * 8, acc = 0;
    tl->rice_valid = 0;
    rice_probe_block_src = src; rice_probe_block_bytes = bytes; rice_probe_block_tmem = tm;
    rice_probe_block_generation = ++rice_block_generation;
    if (!rice_probe_block_generation) rice_probe_block_generation = ++rice_block_generation;
    rice_probe_block_fmt = tl->fmt; rice_probe_block_siz = siz;
    rice_probe_block_valid = rdp_mem(src, bytes) != NULL;
    rice_load_owner = (int)(tl - R.tile) + 1;
    rice_load_generation = rice_probe_block_generation;
    tl->rice_addr = src; tl->rice_generation = rice_probe_block_generation;
    tl->rice_width = tl->rice_height = tl->rice_stride = 0;
    tl->rice_size = siz; tl->rice_format = tl->fmt;
    if (getenv("BT_RICE_TRACE")) fprintf(stderr, "bt_rice: load-block tile=%ld src=%08x texels=%u size=%d\n", (long)(tl - R.tile), src, texels, siz);
    for (u32 w = 0; w < (bytes + 7) / 8 && w < 512; w++, acc += (u32)dxt) {
        const u8 *s = rdp_mem(src + w * 8, 8);
        u32 x = acc >> 11 & 1 ? 4 : 0;
        if (!s) break;
        if (siz == 3) {
            u32 a = ((tm + w * 4) ^ x) & 0x7FF;
            tmem_put(a, s[0]); tmem_put(a + 1, s[1]); tmem_put(a + 2, s[4]); tmem_put(a + 3, s[5]);
            tmem_put(a | 0x800, s[2]); tmem_put((a + 1) | 0x800, s[3]); tmem_put((a + 2) | 0x800, s[6]); tmem_put((a + 3) | 0x800, s[7]);
        } else {
            for (int i = 0; i < 8; i++) tmem_put((tm + w * 8 + i) ^ x, s[i]);
        }
    }
    tl->rice_valid = rice_probe_block_valid && tl->fmt == 2 && siz == 2;
    rice_load_owner = 0;
    rice_load_generation = 0;
}

static void load_tile(u32 w0, u32 w1) {
    texture_epoch++;
    tmem_gen++;
    Tile *tl = &R.tile[w1 >> 24 & 7];
    tl->uls = w0 >> 12 & 0xFFF; tl->ult = w0 & 0xFFF; tl->lrs = w1 >> 12 & 0xFFF; tl->lrt = w1 & 0xFFF;
    load_tile_tile = w1 >> 24 & 7;
    tl->rice_valid = 0;
    tl->rice_generation = 0;
    if (gpu_mask_load()) {
        for (int k = 0; k < 8; k++) R.tile[k].rice_valid = 0;
        memset(R.rice_tmem_owner, 0, sizeof R.rice_tmem_owner);
        if (getenv("BT_RICE_TRACE")) fprintf(stderr, "bt_rice: load-tile tile=%d gpu-owned; origin rejected\n", load_tile_tile);
        return;  // from the GPU's CI8 image: no RDRAM read, no sync
    }
    rice_load_owner = load_tile_tile + 1;
    resolve_texture(R.timg);
    gpu_mask_touch(R.timg);
    int sl = tl->uls >> 2, tt = tl->ult >> 2, sh = tl->lrs >> 2, th = tl->lrt >> 2, siz = R.timg_siz;
    int bpp = siz == 3 ? 4 : siz == 2 ? 2 : 1;
    int width = sh - sl + 1, height = th - tt + 1;
    int stride = (R.timg_width << siz) >> 1;
    u32 rice_addr = R.timg + ((((u32)tt * (u32)R.timg_width + (u32)sl) << siz) + 1u) / 2u;
    int rice_ok = width > 0 && height > 0 && stride >= ((width << siz) >> 1) &&
                  ((width << siz) >> 1) >= 4 && rdp_mem(rice_addr, (u32)((height - 1) * stride + ((width << siz) >> 1))) != NULL;
    for (int t = tt; t <= th; t++) {
        int row = t - tt;
        u32 x = row & 1 ? 4 : 0, rb = (u32)tl->tmem * 8 + (u32)(row * tl->line * 8);
        const u8 *s = rdp_mem(R.timg + (u32)(t * R.timg_width + sl) * bpp >> (siz == 0), (u32)(sh - sl + 1) * bpp);
        if (!s) { rice_ok = 0; continue; }
        for (int i = 0; i <= sh - sl; i++) {
            if (siz == 3) {
                u32 a = ((rb + i * 2) ^ x) & 0x7FF;
                tmem_put(a, s[i * 4]); tmem_put(a + 1, s[i * 4 + 1]);
                tmem_put(a | 0x800, s[i * 4 + 2]); tmem_put((a + 1) | 0x800, s[i * 4 + 3]);
            } else if (siz == 0) {
                if (!(i & 1)) tmem_put((rb + i / 2) ^ x, s[i / 2]);
            } else {
                for (int b = 0; b < bpp; b++) tmem_put((rb + i * bpp + b) ^ x, s[i * bpp + b]);
            }
        }
    }
    rice_load_owner = 0;
    if (rice_ok) {
        tl->rice_addr = rice_addr; tl->rice_width = width; tl->rice_height = height;
        tl->rice_stride = stride; tl->rice_size = siz; tl->rice_format = tl->fmt;
        tl->rice_valid = 1;
    }
    if (getenv("BT_RICE_TRACE"))
        fprintf(stderr, "bt_rice: load-tile tile=%d src=%08x size=%d fmt=%d dims=%dx%d stride=%d valid=%d\n",
                load_tile_tile, rice_addr, siz, tl->fmt, width, height, stride, rice_ok);
}

static void load_tlut(u32 w0, u32 w1) {
    rice_load_owner = 0;
    texture_epoch++;
    tmem_gen++;
    resolve_texture(R.timg);
    gpu_mask_touch(R.timg);
    Tile *tl = &R.tile[w1 >> 24 & 7];
    int uls = w0 >> 12 & 0xFFF, lrs = w1 >> 12 & 0xFFF, n = (lrs >> 2) - (uls >> 2) + 1;
    u32 tm = (u32)tl->tmem * 8;
    const u8 *s = rdp_mem(R.timg + (u32)(uls >> 2) * 2, (u32)(n > 0 ? n : 0) * 2);
    if (!s || n <= 0 || n > 256) return;
    u32 palette_src = R.timg + (u32)(uls >> 2) * 2;
    for (int i = 0; i < n; i++) {
        for (int c = 0; c < 4; c++) { tmem_put(tm + i * 8 + c * 2, s[i * 2]); tmem_put(tm + i * 8 + c * 2 + 1, s[i * 2 + 1]); }
        if (tm >= 0x800 && tm < 0x1000 && ((tm - 0x800) & 7) == 0) {
            u32 index = (tm - 0x800) / 8 + (u32)i;
            if (index < 256) R.rice_palette_valid[index] = 1;
        }
    }
}

void rdp_command(u32 w0, u32 w1) {
    state_gen++;
    switch (w0 >> 24) {
    case 0xE6: case 0xE7: case 0xE8: case 0xE9: case 0x00: break;  // syncs, no-op
    case 0xEA: case 0xEB: break;  // chroma key
    case 0xEC: R.k4 = w1 >> 9 & 0x1FF; R.k5 = w1 & 0x1FF; break;
    case 0xED: R.sc_x0 = w0 >> 12 & 0xFFF; R.sc_y0 = w0 & 0xFFF; R.sc_x1 = w1 >> 12 & 0xFFF; R.sc_y1 = w1 & 0xFFF; break;
    case 0xEE: R.prim_z = (w1 >> 16 & 0x7FFF) << 3; break;
    case 0xEF: R.om_h = w0 & 0x00FFFFFF; R.om_l = w1; texture_epoch++; break;
    case 0xF0: load_tlut(w0, w1); break;
    case 0xF2: {
        Tile *tl = &R.tile[w1 >> 24 & 7];
        tl->uls = w0 >> 12 & 0xFFF; tl->ult = w0 & 0xFFF; tl->lrs = w1 >> 12 & 0xFFF; tl->lrt = w1 & 0xFFF;
        break;
    }
    case 0xF3: load_block(w0, w1); break;
    case 0xF4: load_tile(w0, w1); break;
    case 0xF5: {
        texture_epoch++;
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
    case 0xFD: resolve_texture(w1); R.timg_fmt = w0 >> 21 & 7; R.timg_siz = w0 >> 19 & 3; R.timg_width = (w0 & 0xFFF) + 1; R.timg = w1; break;
    case 0xFE:
        R.zimg = w1;
        if (ip.on) break;
        if (render_scale > 1) for (int i = 0; i < 3; i++) if (frames[i].address) {
            frame_resolve(&depth);
            frame_init(&depth, w1, frames[i].width);
            frame_import(&depth);
            break;
        }
        break;
    case 0xFF:
        if (!ip.on) {
            resolve_all();
            for (int i = 0; i < 3; i++) if (frames[i].address) frame_import(&frames[i]);
            if (depth.address) frame_import(&depth);
        }
        R.cimg_siz = w0 >> 19 & 3; R.cimg_width = (w0 & 0xFFF) + 1; R.cimg = w1;
        if (ip.armed && !ip.on && !ip.address) interp_target();
        break;
    default: {
        static u8 seen[256];
        if (!seen[w0 >> 24]++) fprintf(stderr, "bt_native rdp: command %02x not handled\n", w0 >> 24);
    }
    }
}

// ---- Frame interpolation (see ip above). gsp.c arms a task, re-runs its display list once per
// in-between image between rdp_interp_begin and rdp_interp_end, and video.c shows the results.
void rdp_interp_arm(int images) {
    ip.armed = images > 0;
    if (ip.armed) { task_state = R; return; }
    // No in-betweens this task (60 Hz, interval 1): older ones must not be shown for this framebuffer.
    pthread_mutex_lock(&scanout_lock);
    for (int i = 0; i < 3 * BT_POSES_PER_PICTURE; i++) ip_out[i].address = 0;
    pthread_mutex_unlock(&scanout_lock);
}

static void interp_invalidate(void) {
    pthread_mutex_lock(&scanout_lock);
    static unsigned replace;
    int bank = 0;
    while (bank < 3 && ip_addresses[bank] != ip.address) bank++;
    if (bank == 3) {
        bank = 0;
        while (bank < 3 && ip_addresses[bank]) bank++;
        if (bank == 3) bank = (int)(replace++ % 3);
    }
    ip_bank = bank;
    ip_addresses[bank] = ip.address;
    for (int i = 0; i < BT_POSES_PER_PICTURE; i++) ip_out[bank * BT_POSES_PER_PICTURE + i].address = 0;
    pthread_mutex_unlock(&scanout_lock);
}

// The first VI image the task draws into: keep its content from before the task.
static void interp_target(void) {
    int w = R.cimg_width, h = w * 3 / 4;
    if (R.cimg_siz != 2 || (R.cimg != vi_fbs[0] && R.cimg != vi_fbs[1] && R.cimg != vi_fbs[2])) return;
    if (gpu_enabled()) {
        gpu_interp_target();  // sets ip.address when the image is on the GPU
        if (ip.address) interp_invalidate();
        return;
    }
    Frame *f = color_frame();
    u8 *src = f ? f->data : render_scale == 1 ? gptr(R.cimg, (u32)(w * h * 2)) : NULL;
    if (!src) return;  // scaled but not yet registered: no picture to pair with
    size_t bytes = (size_t)w * h * render_sx * render_scale * 2;
    if (bytes != ip.bytes || ip.color.sx != render_sx || ip.color.sy != render_scale) {
        free(ip.pre); free(ip.color.data); free(ip.z.data);
        ip.pre = malloc(bytes); ip.color.data = malloc(bytes); ip.z.data = malloc(bytes);
        if (!ip.pre || !ip.color.data || !ip.z.data) bt_fatal("allocating in-between images");
        ip.bytes = bytes;
    }
    ip.color = (Frame){.address = R.cimg, .width = w, .height = h, .sx = render_sx, .sy = render_scale, .data = ip.color.data};
    ip.z = (Frame){.width = w, .height = h, .sx = render_sx, .sy = render_scale, .data = ip.z.data};
    memcpy(ip.pre, src, bytes);
    ip.address = R.cimg;
    interp_invalidate();
}

int rdp_interp_begin(void) {
    if (!ip.armed || !ip.address) return 0;
    real_state = R;
    R = task_state;
    state_gen++;
    ip.noise = noise_state;
    texture_epoch++;
    if (gpu_enabled()) {
        pthread_mutex_lock(&frame_lock);
        in_render_task = 1;
        gpu_interp_begin();
    }
    else {
        memcpy(ip.color.data, ip.pre, ip.bytes);
        for (size_t i = 0; i < ip.bytes; i += 2) wr16(ip.z.data + i, 0xFFFC);
    }
    ip.on = 1;
    return 1;
}

void rdp_interp_end(int index, float phase) {
    if (index < 0 || index >= BT_POSES_PER_PICTURE) bt_fatal("rdp_interp_end: index %d", index);
    int w = ip.color.width, h = ip.color.height, sx = ip.color.sx, sy = ip.color.sy;
    unsigned tex = 0;  // GPU with a window: the image is a texture, and picture stays NULL unless dumps need it
    const u32 *picture = gpu_enabled() ? gpu_interp_end(index, &tex, &w, &h, &sx, &sy) : NULL;
    ip.on = 0;
    R = real_state;
    state_gen++;
    noise_state = ip.noise;
    texture_epoch++;
    int pw = w * sx, ph = h * sy;
#ifdef BT_GPU_OPENGL
    if (picture || tex) { pw = gpu.ipt.pw; ph = gpu.ipt.ph; }
#endif
    size_t n = (size_t)pw * ph;
    pthread_mutex_lock(&scanout_lock);
    index += ip_bank * BT_POSES_PER_PICTURE;
    ip_out[index].phase = phase;
    if (tex && !picture) { free(ip_out[index].pixels); ip_out[index].pixels = NULL; }
    else if (!ip_out[index].pixels || (size_t)ip_out[index].pixel_w * ip_out[index].pixel_h != n) {
        free(ip_out[index].pixels);
        if (!(ip_out[index].pixels = malloc(n * sizeof(u32)))) bt_fatal("allocating in-between image");
    }
    ip_out[index].address = ip.address;
    ip_out[index].width = w; ip_out[index].height = h;
    ip_out[index].pixel_w = pw; ip_out[index].pixel_h = ph;
    ip_out[index].tex = tex;
    if (picture) memcpy(ip_out[index].pixels, picture, (size_t)n * sizeof(u32));
    else if (!tex) for (size_t i = 0; i < n; i++) {
        int c[4]; rgba16(rd16(ip.color.data + i * 2), c);
        ip_out[index].pixels[i] = 0xFF000000u | c[0] << 16 | c[1] << 8 | c[2];
    }
    pthread_mutex_unlock(&scanout_lock);
    if (in_render_task) {
        in_render_task = 0;
        pthread_mutex_unlock(&frame_lock);
    }
}



// The in-between passes run on gsp.c's worker thread, one job per picture: posted by the game's
// task after rdp_end, waited for by the next task (and by rescaling) before the RDP state is touched.
static pthread_mutex_t job_lock = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t job_cond = PTHREAD_COND_INITIALIZER;
static int job;  // in-between images posted and not finished
static u8 *snap;

void rdp_interp_wait(void) {
    pthread_mutex_lock(&job_lock);
    while (job) pthread_cond_wait(&job_cond, &job_lock);
    pthread_mutex_unlock(&job_lock);
}

int rdp_interp_post(int images) {
    if (!ip.armed || !ip.address || images <= 0) return 0;
    if (gpu_enabled()) return 1;  // the task runs the passes itself (gsp.c)
    u64 have = bt_inst.w2c_memory.size - 0x80000000u;
    if (!snap && !(snap = calloc(1, SNAP_LIMIT))) bt_fatal("allocating the in-between snapshot");
    memcpy(snap, bt_mem + 0x80000000u, have < SNAP_LIMIT ? (size_t)have : SNAP_LIMIT);
    pthread_mutex_lock(&job_lock);
    job = images;
    pthread_cond_broadcast(&job_cond);
    pthread_mutex_unlock(&job_lock);
    return 1;
}

int rdp_interp_next(void) {
    pthread_mutex_lock(&job_lock);
    while (!job) pthread_cond_wait(&job_cond, &job_lock);
    int images = job;
    pthread_mutex_unlock(&job_lock);
    snap_mem = snap;
    pool_task(1);
    return images;
}

void rdp_interp_done(void) {
    pool_task(0);
    snap_mem = NULL;
    pthread_mutex_lock(&job_lock);
    job = 0;
    pthread_cond_broadcast(&job_cond);
    pthread_mutex_unlock(&job_lock);
}
