// Host services for the guest: ROM image, controller, files, console, zlib and libm.
#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <zlib.h>
#include "guest.h"

static unsigned char *rom;
static u32 rom_size;

_Noreturn void bt_fatal(const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    fputs("bt_native: ", stderr);
    vfprintf(stderr, fmt, ap);
    fputc('\n', stderr);
    va_end(ap);
    abort();
}

void bt_rom_open(const char *path) {
    FILE *f = fopen(path, "rb");
    long n;
    if (!f) bt_fatal("cannot open ROM %s (pass the .z64 path as first argument)", path);
    fseek(f, 0, SEEK_END);
    n = ftell(f);
    fseek(f, 0, SEEK_SET);
    rom = malloc((size_t)n);
    if (!rom || fread(rom, 1, (size_t)n, f) != (size_t)n) bt_fatal("cannot read ROM %s", path);
    fclose(f);
    rom_size = (u32)n;
    if (rom[0] != 0x80 || rom[1] != 0x37) bt_fatal("%s is not a big-endian .z64 ROM", path);
}

// Cartridge domain addresses (0x10000000 + offset) or plain offsets.
u32 w2c_env_rom_read(struct w2c_env *env, u32 dev, u32 dst, u32 n) {
    (void)env;
    dev &= 0x0FFFFFFF;
    if (dev > rom_size || n > rom_size - dev) bt_fatal("ROM read 0x%x+0x%x beyond the image", dev, n);
    memcpy(G(dst), rom + dev, n);
    return 0;
}

void w2c_env_write(struct w2c_env *env, u32 fd, u32 buf, u32 n) {
    (void)env;
    if (write(fd == 1 ? 1 : 2, G(buf), n) < 0) {}
}

_Noreturn void w2c_env_exit(struct w2c_env *env, u32 code) { (void)env; exit((int)code); }
_Noreturn void w2c_env_unported(struct w2c_env *env, u32 name) {
    (void)env;
    bt_fatal("unported %s called", (const char *)G(name));
}

// Guest files: host FILE pointers in a small table, numbered from 3.
static FILE *files[32];

u32 w2c_env_fopen(struct w2c_env *env, u32 path, u32 mode) {
    (void)env;
    for (int i = 3; i < 32; i++) {
        if (!files[i]) {
            unsigned start, end;
            // "rom:START-END" opens that range of the cartridge image read-only.
            if (sscanf(G(path), "rom:%x-%x", &start, &end) == 2) {
                if (start > end || end > rom_size) bt_fatal("ROM file %s beyond the image", (char *)G(path));
                files[i] = fmemopen(rom + start, end - start, "rb");
            } else {
                files[i] = fopen(G(path), G(mode));
            }
            return files[i] ? (u32)i : (u32)-1;
        }
    }
    return (u32)-1;
}

static FILE *file(u32 fd) {
    if (fd >= 32 || !files[fd]) bt_fatal("guest file %u is not open", fd);
    return files[fd];
}

u32 w2c_env_fread(struct w2c_env *env, u32 fd, u32 buf, u32 n) { (void)env; return (u32)fread(G(buf), 1, n, file(fd)); }
u32 w2c_env_fwrite(struct w2c_env *env, u32 fd, u32 buf, u32 n) { (void)env; return (u32)fwrite(G(buf), 1, n, file(fd)); }
u32 w2c_env_fseek(struct w2c_env *env, u32 fd, u32 off, u32 whence) { (void)env; return (u32)fseek(file(fd), (s32)off, (int)whence); }
u32 w2c_env_ftell(struct w2c_env *env, u32 fd) { (void)env; return (u32)ftell(file(fd)); }
u32 w2c_env_fclose(struct w2c_env *env, u32 fd) {
    int r = fclose(file(fd));
    (void)env;
    files[fd] = NULL;
    return (u32)r;
}

// One raw DEFLATE stream; the guest zlib.h shim allows only this call.
u32 w2c_env_inflate_raw(struct w2c_env *env, u32 src, u32 src_len, u32 dst, u32 dst_len, u32 in_used, u32 out_used) {
    z_stream z = {0};
    int r;
    (void)env;
    if (inflateInit2(&z, -15) != Z_OK) bt_fatal("inflateInit2 failed");
    z.next_in = G(src);
    z.avail_in = src_len;
    z.next_out = G(dst);
    z.avail_out = dst_len;
    r = inflate(&z, Z_FINISH);
    gw32(in_used, (u32)z.total_in);
    gw32(out_used, (u32)z.total_out);
    inflateEnd(&z);
    return (u32)r;
}

#define LIBM1(name, T) T w2c_env_##name(struct w2c_env *env, T x) { (void)env; return name(x); }
#define LIBM2(name, T) T w2c_env_##name(struct w2c_env *env, T x, T y) { (void)env; return name(x, y); }
LIBM1(sinf, f32) LIBM1(cosf, f32) LIBM1(tanf, f32) LIBM1(asinf, f32) LIBM1(acosf, f32) LIBM1(atanf, f32)
LIBM2(atan2f, f32) LIBM2(powf, f32) LIBM1(expf, f32) LIBM1(logf, f32) LIBM2(fmodf, f32)
LIBM1(sin, f64) LIBM1(cos, f64) LIBM1(tan, f64) LIBM1(asin, f64) LIBM1(acos, f64)
LIBM1(atan, f64) LIBM2(atan2, f64) LIBM2(pow, f64) LIBM1(exp, f64) LIBM1(log, f64)
LIBM2(fmod, f64)
