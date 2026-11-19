// Host services for the guest: ROM image, controller, files, console, zlib and libm.
#include "plat.h"
#ifndef _WIN32
#include <execinfo.h>
#endif
#ifdef __APPLE__
#include <mach-o/dyld.h>
#endif
#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <zlib.h>
#include <SDL3/SDL.h>
#include "guest.h"
#include "mixer.h"
#include "crash.h"

static unsigned char *rom;
static u32 rom_size, us_size;  // the US dump; rom_size also counts the language assets after it

_Noreturn void bt_fatal(const char *fmt, ...) {
    char detail[2048];
    va_list ap;
    va_start(ap, fmt);
    vsnprintf(detail, sizeof detail, fmt, ap);
    va_end(ap);
    fprintf(stderr, "bt_native: %s\n", detail);
    bt_backtrace();
    void *frames[48];
    int count = bt_crash_capture(frames, 48);
    bt_crash_report("bt_fatal", detail, (const void *const *)frames, (size_t)count);
    abort();
}

// Guest functions keep their names (w2c_bt_<name>), so this names the failing game code.
void bt_backtrace(void) {
    void *frames[48];
    // BT_PEEK=80d27bc2:2,... dumps guest bytes (big-endian, as stored) when the run dies
    for (const char *p = getenv("BT_PEEK"); p && *p;) {
        char *end;
        unsigned long addr = strtoul(p, &end, 16), size = *end == ':' ? strtoul(end + 1, &end, 0) : 4;
        fprintf(stderr, "bt_native: peek %08lx:", addr);
        for (unsigned long i = 0; i < size && i < 256; i++) fprintf(stderr, " %02x", bt_mem[addr + i]);
        fputc('\n', stderr);
        p = *end == ',' ? end + 1 : end + strlen(end);
    }
#ifdef __APPLE__  // sweep.py feeds slide and addresses to atos, which also names inlined functions
    fprintf(stderr, "bt_native: image slide 0x%lx\n", (long)_dyld_get_image_vmaddr_slide(0));
#endif
#ifdef _WIN32
    USHORT count = CaptureStackBackTrace(0, 48, frames, NULL);
    for (USHORT i = 0; i < count; ++i) fprintf(stderr, "bt_native: frame %p\n", frames[i]);
#else
    backtrace_symbols_fd(frames, backtrace(frames, 48), 2);
#endif
}

// wasm2c runtime trap (WASM_RT_TRAP_HANDLER): out-of-bounds access, NULL call, division by zero...
void bt_trap(wasm_rt_trap_t code) {
    fprintf(stderr, "bt_native: guest trap: %s\n", wasm_rt_strerror(code));
    bt_backtrace();
    void *frames[48];
    int count = bt_crash_capture(frames, 48);
    bt_crash_report("bt_trap", wasm_rt_strerror(code), (const void *const *)frames, (size_t)count);
    abort();
}

// Windowed runs report ROM problems in a message box too; the player may have no terminal.
static _Noreturn void rom_error(const char *path, const char *what) {
    char text[1200];
    snprintf(text, sizeof text, "%s:\n%s", path, what);
    if (SDL_WasInit(SDL_INIT_VIDEO)) SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Banjo-Tooie", text, NULL);
    bt_fatal("%s: %s", path, what);
}

// Reads a .z64 (big-endian), .v64 (byte-swapped) or .n64 (little-endian) image into big-endian
// order. Returns NULL if the file cannot be opened.
static unsigned char *image_read(const char *path, u32 *size) {
    FILE *f = bt_disk_open(path, "rb");
    long n;
    if (!f) return NULL;
    fseek(f, 0, SEEK_END);
    n = ftell(f);
    fseek(f, 0, SEEK_SET);
    unsigned char *image = n >= 0x1000 ? malloc((size_t)n) : NULL;
    if (!image || fread(image, 1, (size_t)n, f) != (size_t)n) rom_error(path, "Die Datei ist zu kurz oder nicht lesbar.");
    fclose(f);
    *size = (u32)n;
    int v64 = image[0] == 0x37 && image[1] == 0x80, n64 = image[0] == 0x40 && image[1] == 0x12;
    for (long i = 0; (v64 || n64) && i + 3 < n; i += 4) {
        unsigned char a = image[i], b = image[i + 1], c = image[i + 2], d = image[i + 3];
        if (v64) { image[i] = b; image[i + 1] = a; image[i + 2] = d; image[i + 3] = c; }
        else { image[i] = d; image[i + 1] = c; image[i + 2] = b; image[i + 3] = a; }
    }
    if (image[0] != 0x80 || image[1] != 0x37) rom_error(path, "Das ist keine N64-ROM (.z64, .v64 oder .n64).");
    return image;
}

static void rom_add_language(void);

// The US version; returns 0 if the file cannot be opened.
static int rom_load(const char *path) {
    rom = image_read(path, &rom_size);
    if (!rom) return 0;
    us_size = rom_size;
    if (memcmp(rom + 0x3B, "NB7E", 4)) rom_error(path, "Das ist nicht Banjo-Tooie in der US-Version (Spielcode NB7E).");
    u64 hash = UINT64_C(14695981039346656037);  // FNV-1a over the .z64 bytes, as in the trace header
    for (u32 i = 0; i < rom_size; i++) hash = (hash ^ rom[i]) * UINT64_C(1099511628211);
    if (hash != UINT64_C(0xe04fb9f40c35687f))
        rom_error(path, "Diese Banjo-Tooie-ROM (US) ist veraendert oder beschaedigt; erwartet wird der unveraenderte Dump.");
    rom_add_language();
    return 1;
}

void bt_rom_open(const char *path) {
    if (!rom_load(path)) rom_error(path, "Die ROM wurde nicht gefunden (Pfad als erstes Argument angeben).");
}

const char *bt_rom_title(void) {
    static char title[21];
    if (!rom) return "";
    size_t n = 20;
    while (n && (rom[0x20 + n - 1] == ' ' || rom[0x20 + n - 1] == 0)) n--;
    if (n > sizeof title - 1) n = sizeof title - 1;
    for (size_t i = 0; i < n; i++) {
        unsigned char c = rom[0x20 + i];
        title[i] = (c >= 0x20 && c <= 0x7e) ? (char)c : '_';
    }
    title[n] = 0;
    return title;
}

static char picked[1024];
static _Atomic int picking;
static void SDLCALL on_pick(void *data, const char *const *files, int filter) {
    (void)data; (void)filter;
    if (files && files[0]) snprintf(picked, sizeof picked, "%s", files[0]);
    picking = 0;
}

// Windowed runs ask once with a file dialog; returns NULL if the player cancels.
static const char *pick_rom(const char *message) {
    static const SDL_DialogFileFilter filter[] = {{"N64-ROM", "z64;v64;n64"}};
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Banjo-Tooie", message, NULL);
    picked[0] = 0;
    picking = 1;
    SDL_ShowOpenFileDialog(on_pick, NULL, NULL, filter, 1, NULL, false);
    while (picking) SDL_WaitEventTimeout(NULL, 50);
    return picked[0] ? picked : NULL;
}

static u32 be32(const unsigned char *p) { return (u32)p[0] << 24 | p[1] << 16 | p[2] << 8 | p[3]; }

// First bytes of a compressed asset (2-byte length, then raw DEFLATE).
static int asset_peek(const unsigned char *packed, u32 n, unsigned char out[3]) {
    z_stream z = {0};
    if (n < 3 || inflateInit2(&z, -15) != Z_OK) return 0;
    z.next_in = (Bytef *)packed + 2;
    z.avail_in = n - 2;
    z.next_out = out;
    z.avail_out = 3;
    inflate(&z, Z_SYNC_FLUSH);
    inflateEnd(&z);
    return z.avail_out == 0;
}

// Dialog texts in French, German and Spanish come from the European ROM (NB7P, En/Fr/De/Es). Its
// asset table has the same ids; a dialog asset there starts with 4 (languages) instead of 1, then
// one offset per language, which gldialog_entrypoint_0 picks. A copy of the US asset region with
// those dialogs swapped in goes after the US image; the guest moves its asset base there
// (bt_asset_shift). Other EU assets (textures, level setups) stay US. Language 0 changes nothing.
static u32 asset_shift, language;
static void rom_add_language(void) {
    enum { US = 0x5180, EU = 0x5140, COUNT = 0x3667, BASE = 8 + COUNT * 4 };
    if (!bt_setting(BT_SET_LANGUAGE)) return;
    char saved[1024];
    char *dir = SDL_GetPrefPath("", "BanjoTooie");
    snprintf(saved, sizeof saved, "%sbaserom.eu.z64", dir ? dir : "");
    SDL_free(dir);
    const char *path = getenv("BT_PAL_ROM");
    u32 n = 0;
    unsigned char *eu = path ? image_read(path, &n) : NULL;
    if (!path && !(eu = image_read(path = "baserom.eu.z64", &n)) && !(eu = image_read(path = saved, &n)) &&
        SDL_WasInit(SDL_INIT_VIDEO) &&
        (path = pick_rom("Fuer die gewaehlte Sprache brauche ich die europaeische Banjo-Tooie-ROM (En,Fr,De,Es).\n"
                         "Eine Kopie wird fuer die naechsten Starts im Benutzerordner abgelegt."))) {
        eu = image_read(path, &n);
        FILE *f = eu ? bt_disk_open(saved, "wb") : NULL;
        if (!f || fwrite(eu, 1, n, f) != n) fprintf(stderr, "bt_native: cannot keep a ROM copy in %s\n", saved);
        if (f) fclose(f);
    }
    if (!eu || n < EU + BASE || memcmp(eu + 0x3B, "NB7P", 4) || be32(eu + EU) != COUNT || be32(rom + US) != COUNT) {
        fprintf(stderr, "bt_native: no European ROM (BT_PAL_ROM, baserom.eu.z64): dialog stays English\n");
        free(eu);
        return;
    }
    u32 at = (us_size + 15) & ~15u, out = BASE, swapped = 0;
    u32 eu_end = be32(eu + EU + 8 + (COUNT - 1) * 4) >> 6, us_end = be32(rom + US + 8 + (COUNT - 1) * 4) >> 6;
    if (EU + BASE + eu_end > n) bt_fatal("%s: asset table beyond the image", path);
    unsigned char *image = realloc(rom, at + BASE + us_end + eu_end);  // bound: all of both regions
    if (!image) bt_fatal("out of memory for the language assets");
    rom = image;
    unsigned char *table = rom + at;
    memcpy(table, rom + US, 8);
    for (u32 i = 0; i + 1 < COUNT; i++) {
        const unsigned char *u = rom + US + 8 + i * 4, *e = eu + EU + 8 + i * 4;
        const unsigned char *src = rom + US + BASE + (be32(u) >> 6);
        u32 size = (be32(u + 4) >> 6) - (be32(u) >> 6), flags = be32(u) & 63;
        unsigned char head[3], eu_head[3];
        u32 eu_size = (be32(e + 4) >> 6) - (be32(e) >> 6);
        if ((flags & 31) == 19 && (be32(e) & 63) == flags && asset_peek(src, size, head) &&
            !memcmp(head, "\1\3\0", 3) && asset_peek(eu + EU + BASE + (be32(e) >> 6), eu_size, eu_head) &&
            eu_head[0] == 4) {
            src = eu + EU + BASE + (be32(e) >> 6);
            size = eu_size;
            swapped++;
        }
        memmove(table + out, src, size);
        u32 word = (out - BASE) << 6 | flags;
        table[8 + i * 4] = word >> 24; table[9 + i * 4] = word >> 16; table[10 + i * 4] = word >> 8; table[11 + i * 4] = word;
        out += size;
    }
    u32 last = (out - BASE) << 6 | (be32(rom + US + 8 + (COUNT - 1) * 4) & 63);
    table[8 + (COUNT - 1) * 4] = last >> 24; table[9 + (COUNT - 1) * 4] = last >> 16;
    table[10 + (COUNT - 1) * 4] = last >> 8; table[11 + (COUNT - 1) * 4] = last;
    free(eu);
    rom_size = at + out;
    asset_shift = at - US;
    language = (u32)bt_setting(BT_SET_LANGUAGE);
    fprintf(stderr, "bt_native: language %u, %u dialog assets from %s\n", language, swapped, path);
}

u32 w2c_env_language(struct w2c_env *env) { (void)env; return language; }
u32 w2c_env_asset_shift(struct w2c_env *env) { (void)env; return asset_shift; }

// No ROM argument: baserom.us.z64 here, else the copy in the user data directory, else ask once
// with a file dialog and keep a .z64 copy there for the next start. Returns the path for traces.
const char *bt_rom_find(void) {
    static char saved[1024];
    char *dir = SDL_GetPrefPath("", "BanjoTooie");
    if (rom_load("baserom.us.z64")) return "baserom.us.z64";
    snprintf(saved, sizeof saved, "%sbaserom.us.z64", dir ? dir : "");
    SDL_free(dir);
    if (rom_load(saved)) return saved;
    if (!SDL_WasInit(SDL_INIT_VIDEO)) bt_fatal("no ROM: pass the path of Banjo-Tooie (US) as first argument");
    if (!pick_rom("Bitte waehle deine Banjo-Tooie-ROM (US-Version) aus.\n"
                  "Eine Kopie wird fuer die naechsten Starts im Benutzerordner abgelegt.")) exit(0);
    bt_rom_open(picked);
    FILE *f = bt_disk_open(saved, "wb");
    if (!f || fwrite(rom, 1, us_size, f) != us_size) fprintf(stderr, "bt_native: cannot keep a ROM copy in %s\n", saved);
    if (f) fclose(f);
    return saved;
}

// Cartridge domain addresses (0x10000000 + offset) or plain offsets.
u32 w2c_env_rom_read(struct w2c_env *env, u32 dev, u32 dst, u32 n) {
    (void)env;
    dev &= 0x0FFFFFFF;
    if (dev > rom_size || n > rom_size - dev) bt_fatal("ROM read 0x%x+0x%x beyond the image", dev, n);
    memcpy(G_range(dst,n), rom + dev, n);
    return 0;
}

void w2c_env_write(struct w2c_env *env, u32 fd, u32 buf, u32 n) {
    (void)env;
    if (write(fd == 1 ? 1 : 2, G_range(buf,n), n) < 0) {}
}

_Noreturn void w2c_env_exit(struct w2c_env *env, u32 code) { (void)env; exit((int)code); }
_Noreturn void w2c_env_unported(struct w2c_env *env, u32 name) {
    (void)env;
    bt_fatal("unported %s called", (const char *)G_range(name, bt_inst.w2c_memory.size - name));
}

// Disk errors are returned to the guest. Keep them out of the SDL error state of its scheduler thread.
typedef struct { FILE *disk; SDL_IOStream *slice; } GuestFile;
static GuestFile files[32];

const char *bt_path_env(const char *name) {
#ifdef _WIN32
    return SDL_getenv(name);  // SDL converts the wide Windows environment to UTF-8.
#else
    return getenv(name);
#endif
}

FILE *bt_disk_open(const char *path, const char *mode) {
#ifdef _WIN32
    wchar_t *wide_path = (wchar_t *)SDL_iconv_string("UTF-16LE", "UTF-8", path, strlen(path) + 1);
    wchar_t *wide_mode = (wchar_t *)SDL_iconv_string("UTF-16LE", "UTF-8", mode, strlen(mode) + 1);
    FILE *file = wide_path && wide_mode ? _wfopen(wide_path, wide_mode) : NULL;
    SDL_free(wide_mode);
    SDL_free(wide_path);
    return file;
#else
    return fopen(path, mode);
#endif
}

// The game's save file (guest/os.c opens "bt_eeprom.bin"): BT_SAVE=path if set; the working
// directory for scripted runs (BT_HEADLESS, BT_VCLOCK) or when a save is already there; otherwise
// the user's data directory (macOS: ~/Library/Application Support/BanjoTooie).
const char *bt_host_path(const char *path) {
    static char save[1024];
    if (strcmp(path, "bt_eeprom.bin")) return path;
    if (!save[0]) {
        char *dir;
        const char *override = bt_path_env("BT_SAVE");
        if (override) snprintf(save, sizeof save, "%s", override);
        else if (getenv("BT_HEADLESS") || getenv("BT_VCLOCK") || !access(path, F_OK) ||
                 !(dir = SDL_GetPrefPath("", "BanjoTooie"))) snprintf(save, sizeof save, "%s", path);
        else { snprintf(save, sizeof save, "%s%s", dir, path); SDL_free(dir); }
        fprintf(stderr, "bt_native: save file %s\n", save);
    }
    return save;
}

u32 w2c_env_fopen(struct w2c_env *env, u32 path, u32 mode) {
    (void)env;
    for (int i = 3; i < 32; i++) {
        if (!files[i].disk && !files[i].slice) {
            unsigned start, end;
            // "rom:START-END" opens that range of the cartridge image read-only.
            bt_image_range(path, bt_inst.w2c_memory.size - path);
            bt_image_range(mode, bt_inst.w2c_memory.size - mode);
            if (sscanf(G(path), "rom:%x-%x", &start, &end) == 2) {
                if (start > end || end > rom_size) bt_fatal("ROM file %s beyond the image", (char *)G(path));
                files[i].slice = SDL_IOFromConstMem(rom + start, end - start);
            } else {
                files[i].disk = bt_disk_open(bt_host_path(G(path)), G(mode));
            }
            return files[i].disk || files[i].slice ? (u32)i : (u32)-1;
        }
    }
    return (u32)-1;
}

static GuestFile *file(u32 fd) {
    if (fd >= 32 || (!files[fd].disk && !files[fd].slice)) bt_fatal("guest file %u is not open", fd);
    return &files[fd];
}

u32 w2c_env_fread(struct w2c_env *env, u32 fd, u32 buf, u32 n) {
    (void)env;
    GuestFile *f = file(fd);
    void *dst = G_range(buf, n);
    return (u32)(f->disk ? fread(dst, 1, n, f->disk) : SDL_ReadIO(f->slice, dst, n));
}

u32 w2c_env_fwrite(struct w2c_env *env, u32 fd, u32 buf, u32 n) {
    (void)env;
    GuestFile *f = file(fd);
    return f->disk ? (u32)fwrite(G_range(buf, n), 1, n, f->disk) : 0;
}

u32 w2c_env_fseek(struct w2c_env *env, u32 fd, u32 off, u32 whence) {
    (void)env;
    GuestFile *f = file(fd);
    int failed = f->disk ? fseek(f->disk, (s32)off, whence) != 0
                         : SDL_SeekIO(f->slice, (s32)off, (SDL_IOWhence)whence) < 0;
    return failed ? (u32)-1 : 0;
}

u32 w2c_env_ftell(struct w2c_env *env, u32 fd) {
    (void)env;
    GuestFile *f = file(fd);
    return (u32)(f->disk ? ftell(f->disk) : SDL_TellIO(f->slice));
}

u32 w2c_env_fclose(struct w2c_env *env, u32 fd) {
    (void)env;
    GuestFile *f = file(fd);
    int result = f->disk ? fclose(f->disk) : SDL_CloseIO(f->slice) ? 0 : -1;
    *f = (GuestFile){0};
    return (u32)result;
}

// One raw DEFLATE stream; the guest zlib.h shim allows only this call.
u32 w2c_env_inflate_raw(struct w2c_env *env, u32 src, u32 src_len, u32 dst, u32 dst_len, u32 in_used, u32 out_used) {
    z_stream z = {0};
    int r;
    (void)env;
    if (inflateInit2(&z, -15) != Z_OK) bt_fatal("inflateInit2 failed");
    z.next_in = G_range(src,src_len);
    z.avail_in = src_len;
    z.next_out = G_range(dst,dst_len);
    z.avail_out = dst_len;
    r = inflate(&z, Z_FINISH);
    gw32(in_used, (u32)z.total_in);
    gw32(out_used, (u32)z.total_out);
    inflateEnd(&z);
    return (u32)r;
}

// US assets have a big-endian size in 16-byte units followed by raw DEFLATE.
static u32 inflate_rom_block(u32 dev, u32 n, u8 *dst, u64 capacity) {
    z_stream z = {0};
    if (n < 2 || dev > rom_size || n > rom_size - dev) bt_fatal("ROM inflate 0x%x+0x%x beyond the image", dev, n);
    u32 size = ((u32)rom[dev] << 8 | rom[dev + 1]) * 16;
    if (size > capacity) bt_fatal("ROM inflate at 0x%x exceeds destination", dev);
    if (inflateInit2(&z, -15) != Z_OK) bt_fatal("inflateInit2 failed");
    z.next_in = rom + dev + 2;
    z.avail_in = n - 2;
    z.next_out = dst;
    z.avail_out = size;
    int result = inflate(&z, Z_FINISH);
    inflateEnd(&z);
    if (result != Z_STREAM_END) bt_fatal("ROM inflate at 0x%x failed (%d)", dev, result);
    return (u32)z.total_out;
}

// src/core2/1EF0820.s: decompress one asset to guest memory.
u32 w2c_env_rom_inflate(struct w2c_env *env, u32 dev, u32 n, u32 dst) {
    (void)env;
    if (dst > bt_inst.w2c_memory.size) bt_fatal("ROM inflate destination outside guest memory");
    u32 off = dev & 0x0fffffff;
    if (n >= 2 && off < rom_size && n <= rom_size-off)
        bt_image_range(dst, ((u32)rom[off] << 8 | rom[off+1])*16);
    return inflate_rom_block(off, n, G(dst), bt_inst.w2c_memory.size - dst);
}

// US core1 blocks (tools/tooie_utils.h); split positions from baserom.us.yaml relative to each block.
void bt_rom_audio(int text, u8 *out) {
    u32 at = text ? 0x1e29b60 : 0x1e3f718, end = text ? 0x1e3f718 : 0x1e42550;
    u32 offset = text ? 0x25850 : 0x5640, size = text ? BT_AUDIO_TEXT_BYTES : BT_AUDIO_DATA_BYTES;
    u32 capacity = text ? 0x2a9a0 : 0x69b0;
    u8 *block = malloc(capacity);
    if (!block) bt_fatal("out of memory loading n_audio");
    if (inflate_rom_block(at, end - at, block, capacity) < offset + size) bt_fatal("truncated n_audio in core1");
    memcpy(out, block + offset, size);
    free(block);
}

#define LIBM1(name, T) T w2c_env_##name(struct w2c_env *env, T x) { (void)env; return name(x); }
#define LIBM2(name, T) T w2c_env_##name(struct w2c_env *env, T x, T y) { (void)env; return name(x, y); }
LIBM1(sinf, f32) LIBM1(cosf, f32) LIBM1(tanf, f32) LIBM1(asinf, f32) LIBM1(acosf, f32) LIBM1(atanf, f32)
LIBM2(atan2f, f32) LIBM2(powf, f32) LIBM1(expf, f32) LIBM1(logf, f32) LIBM2(fmodf, f32)
LIBM1(sin, f64) LIBM1(cos, f64) LIBM1(tan, f64) LIBM1(asin, f64) LIBM1(acos, f64)
LIBM1(atan, f64) LIBM2(atan2, f64) LIBM2(pow, f64) LIBM1(exp, f64) LIBM1(log, f64)
LIBM2(fmod, f64)
