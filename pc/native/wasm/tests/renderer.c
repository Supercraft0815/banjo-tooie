// Standalone renderer fixture: no ROM, wasm runtime, SDL or wall clock.
#define BT_HOST_GUEST_H
#include <stdint.h>
#include <stdarg.h>
#include <assert.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stdatomic.h>
typedef uint8_t u8;
typedef int8_t s8;
typedef uint16_t u16;
typedef int16_t s16;
typedef uint32_t u32;
typedef int32_t s32;
typedef uint64_t u64;
static struct { struct { u64 size; } w2c_memory; } bt_inst;
static u8 *bt_mem;
_Noreturn void bt_fatal(const char *fmt, ...);
#ifdef BT_GPU_OPENGL  // what rdp_gl.h takes from the host: the virtual clock finishes each task before it returns
static int bt_vclock_on = 1;
enum { BT_SET_SMOOTH, BT_SET_RENDER_STATS };
static int bt_setting(int id) { (void)id; return 0; }
static void bt_os_event(u32 event) { (void)event; }
#endif
#ifndef RDP_SOURCE
#define RDP_SOURCE "../host/rdp.c"
#endif
#include RDP_SOURCE
_Noreturn void bt_fatal(const char *fmt, ...) {
    va_list args; va_start(args, fmt); vfprintf(stderr, fmt, args); va_end(args); abort();
}

#define FB 0x80001000u
#define FB2 0x80002000u
#define ZB 0x80003000u
#define RTT 0x80004000u
#define TEX 0x80005000u
#define W 32
#define H 24
static void target(u32 address) { rdp_command(0xFF100000 | (W - 1), address); }
static void fill(u32 value, int x0, int y0, int x1, int y1) {
    rdp_command(0xEF300000, 0);
    rdp_command(0xF7000000, value);
    rdp_command(0xF6000000 | ((x1 - 1) * 4 << 12) | ((y1 - 1) * 4), x0 * 4 << 12 | y0 * 4);
}
static void scene(void) {
    rdp_command(0xED000000, W * 4 << 12 | H * 4);
    rdp_command(0xFE000000, ZB);
    target(ZB); fill(0xFFFCFFFC, 0, 0, W, H);
    target(FB); fill(0xF80107C1, 0, 0, W, H);
    rdp_command(0xEF000000, 0x30);
    // D = shade for both RGB/alpha, all products zero.
    rdp_command(0xFCFFFFFF, 0xFFFE793C);
    RdpVtx a = {.x=3, .y=2, .z=10000, .w=1, .c={0,0,255,255}};
    RdpVtx b = a, c = a; b.x=26; b.y=5; c.x=9; c.y=21;
    rdp_triangle(&a, &b, &c, RDP_SHADE | RDP_Z);
    // Fill a second buffer and a render-to-texture image.
    target(FB2); fill(0xFFFF0001, 1, 1, 5, 3);
    target(RTT); fill(0x003F003F, 2, 2, 8, 6);
    target(FB);
    for (int i=0; i<16; i++) wr16(bt_mem + TEX + i*2, i&1 ? 0xFFFF : 0xF801);
    rdp_command(0xFD100003, TEX);
    rdp_command(0xF5100200, 0);
    rdp_command(0xF4000000, 12 << 12 | 12);
    rdp_command(0xF2000000, 12 << 12 | 12);
    rdp_command(0xEF200000, 0);
    rdp_texrect(0xE4000000 | 60 << 12 | 60, 48 << 12 | 48, 0, 4096u << 16 | 1024, 0);
}
#ifndef BASELINE
static atomic_int stop_reader;
static void *read_scanout(void *unused) {
    (void)unused;
    static u32 pixels[W*H*RDP_MAX_SX*RDP_MAX_SCALE];
    while (!atomic_load(&stop_reader)) {
        int sx, s = rdp_frame(FB, W, H, pixels, &sx);
        assert(s > 1);
        u32 color = pixels[0];
        assert(color == 0xFFFF0000 || color == 0xFF00FF00);
        for (int i = 1; i < W*H*s*sx; i++) assert(pixels[i] == color);
    }
    return NULL;
}
#endif
int main(void) {
    bt_inst.w2c_memory.size = 0x80010000ull;
    bt_mem = mmap(NULL, bt_inst.w2c_memory.size, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANON, -1, 0);
    assert(bt_mem != MAP_FAILED);
#ifndef BASELINE
    rdp_register_framebuffer(FB, W, 0);
    rdp_register_framebuffer(FB2, W, 0);
    rdp_begin();
#endif
    scene();
#ifndef BASELINE
    rdp_end();
    int s = rdp_scale();
    if (s > 1) {
        static u32 pixels[W*H*RDP_MAX_SX*RDP_MAX_SCALE];
        int sx;
        assert(rdp_frame(FB, W, H, pixels, &sx) == s && sx == s);
        // Fill's alternating 16-bit words repeat per original pixel, not per subpixel.
        assert(pixels[0] == 0xFFFF0000 && pixels[s-1] == 0xFFFF0000);
        assert(pixels[s] == 0xFF00FF00 && pixels[2*s-1] == 0xFF00FF00);
        assert(pixels[(12*s)*W*s+12*s] == 0xFFFF0000);
        assert(pixels[(12*s)*W*s+13*s] == 0xFFFFFFFF);
        assert(pixels[(12*s)*W*s+14*s-1] == 0xFFFFFFFF);
        assert(rd16(bt_mem+RTT+(2*W+2)*2) == 0x003F);
        assert(rd16(bt_mem+RTT+(6*W+2)*2) == 0);
        assert(rd16(bt_mem+FB2+(W+1)*2) == 0x0001);
        assert(rdp_frame(RTT, W, H, pixels, &sx) == 0);
        // A CPU write must refresh all subpixels, without erasing adjacent detail.
        wr16(bt_mem+FB, 0x003F);
        rdp_begin(); rdp_end();
        assert(rdp_frame(FB,W,H,pixels,&sx) == s && pixels[0] == 0xFF0000FF);
        // Texture loads must see a resolved framebuffer within the same task.
        rdp_begin(); target(FB); fill(0xFFFFffff,0,0,2,2);
        rdp_command(0xFD100000 | (W-1), FB);
        assert(rd16(bt_mem+FB) == 0xFFFF);
        rdp_end();
        assert(rd16(bt_mem+ZB+(10*W+10)*2) != 0xFFFC);
        // The game borrows Z memory for RGBA16 pause/transition copies.
        rdp_begin(); target(ZB); fill(0xF80107C1, 0, 0, W, H); target(FB); rdp_end();
        assert(rd16(bt_mem+ZB) == 0xF801 && rd16(bt_mem+ZB+2) == 0x07C1);
        // Oversized scissors cannot overrun a scaled allocation.
        rdp_begin();
        rdp_command(0xED000000, 0x00FFFFFF);
        fill(0x00010001, 0, 0, 100, 100);
        rdp_end();
        // Drawing HUD/color without Z_UPD must not recompress borrowed RGBA16 Z memory
        // (that would destroy its alpha bit and break the following pause texture load).
        assert(rd16(bt_mem+ZB) == 0xF801 && rd16(bt_mem+ZB+2) == 0x07C1);
        // Preserve subpixel scissor coordinates at higher resolutions.
        rdp_begin();
        rdp_command(0xED000000 | 6 << 12, W * 4 << 12 | H * 4);
        fill(0xFFFFFFFF, 0, 0, W, H);
        rdp_end();
        assert(rdp_frame(FB,W,H,pixels,&sx) == s);
        assert(pixels[6*s/4-1] == 0xFF000000 && pixels[6*s/4] == 0xFFFFFFFF);
        // Widescreen: columns get round(s * 4 / 3) subpixels and still resolve to W guest pixels.
        rdp_register_framebuffer(FB, W, 1);
        rdp_begin(); rdp_command(0xED000000,W*4<<12|H*4); fill(0x07C107C1,0,0,W,H); fill(0xF801F801,0,0,W/2,H); rdp_end();
        assert(rdp_frame(FB,W,H,pixels,&sx) == s && sx == (s*4+1)/3);
        assert(pixels[0] == 0xFFFF0000 && pixels[W/2*sx-1] == 0xFFFF0000 && pixels[W/2*sx] == 0xFF00FF00);
        assert(pixels[W*sx*H*s-1] == 0xFF00FF00 && pixels[W*sx*(H*s-1)+W/2*sx-1] == 0xFFFF0000);
        assert(rd16(bt_mem+FB+(W/2-1)*2) == 0xF801 && rd16(bt_mem+FB+(W/2)*2) == 0x07C1);
        rdp_register_framebuffer(FB, W, 0);
        assert(rdp_frame(FB,W,H,pixels,&sx) == s && sx == s && pixels[W/2*s] == 0xFF00FF00);
        // Concurrent presentation only sees complete frames.
        rdp_begin(); rdp_command(0xED000000,W*4<<12|H*4); fill(0xF801F801,0,0,W,H); rdp_end();
        pthread_t reader;
        assert(pthread_create(&reader, NULL, read_scanout, NULL) == 0);
        for (int i=0; i<20; i++) {
            rdp_begin(); fill(i&1 ? 0xF801F801 : 0x07C107C1,0,0,W,H); rdp_end();
        }
        atomic_store(&stop_reader,1);
        assert(pthread_join(reader,NULL) == 0);
        return 0;
    }
#endif
    // Raw color, Z, second framebuffer and offscreen image for a byte-exact S=1 oracle.
    assert(fwrite(bt_mem+FB, 1, 4*4096, stdout) == 4*4096);
    return 0;
}
