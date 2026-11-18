// Phase-0 oracle: read-only snapshots on the guest thread, before delivery of each VI event.
#include <errno.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "guest.h"
#include "trace_symbols.h"

#define FNV_OFFSET UINT64_C(14695981039346656037)
static FILE *trace;
static u64 state_hash;

static u64 hash_bytes(u64 hash, const void *data, size_t size) {
    const u8 *p = data;
    for (size_t i = 0; i < size; i++) hash = (hash ^ p[i]) * UINT64_C(1099511628211);
    return hash;
}

static void check_range(u32 address, u32 size) {
    if (address < 0x80000000u || (u64)address + size > bt_inst.w2c_memory.size)
        bt_fatal("BT_TRACE: invalid guest range %08x+%x", address, size);
}

static u32 read_word(u32 address) {
    check_range(address, 4);
    return gr32(address);
}

static u64 region_hash(u32 address, u32 size) {
    if (!address) return 0; // Absent state is distinct from a zero-filled region.
    check_range(address, size);
    return hash_bytes(FNV_OFFSET, G_range(address,size), size);
}

static void value(FILE *out, u32 word) {
    u8 bytes[] = {word >> 24, word >> 16, word >> 8, word};
    state_hash = hash_bytes(state_hash, bytes, sizeof bytes);
    fprintf(out, "%u", word);
}

static void words(FILE *out, u32 address, u32 count) {
    fputc('[', out);
    for (u32 i = 0; i < count; i++) {
        if (i) fputc(',', out);
        value(out, read_word(address + i * 4));
    }
    fputc(']', out);
}

static void players(FILE *out) {
    fputs(",\"players\":[", out);
    for (u32 i = 0; i < 8; i++) {
        if (i) fputc(',', out);
        u32 player = read_word(TRACE_D_80135490 + i * 4);
        fputs("{\"present\":", out);
        value(out, player != 0);
        if (player) {
            u32 position = read_word(player + 0xE4), state = read_word(player + 0x120);
            fputs(",\"position\":", out);
            if (position) words(out, position, 3); else fputs("null", out);
            fputs(",\"status\":", out);
            if (state) words(out, state, 3); else fputs("null", out);
        }
        fputc('}', out);
    }
    fputc(']', out);
}

static void actors(FILE *out) {
    u32 vector = read_word(TRACE_D_80136EE0), begin = 0, end = 0, stride = 0;
    if (vector) {
        stride = read_word(vector);
        begin = read_word(vector + 4);
        end = read_word(vector + 8);
        if (stride != 0x9C || end < begin || (end - begin) % stride || (end - begin) / stride > 2048)
            bt_fatal("BT_TRACE: invalid actor vector");
        check_range(begin, end - begin);
    }
    fputs(",\"actors\":[", out);
    for (u32 a = begin; a < end; a += stride) {
        if (a != begin) fputc(',', out);
        u32 marker = read_word(a);
        fputs("{\"id\":", out);
        if (marker) check_range(marker + 0x14, 2);
        value(out, marker ? gr16(marker + 0x14) : 0);
        fputs(",\"position\":", out); words(out, a + 4, 3);
        fputs(",\"state\":", out); value(out, read_word(a + 0x14));
        fputs(",\"scale\":", out); value(out, read_word(a + 0x38));
        fputs(",\"rotation\":", out); words(out, a + 0x44, 3);
        fputs(",\"health_flags\":", out); words(out, a + 0x5C, 9);
        fputc('}', out);
    }
    fputc(']', out);
}

static void flags(FILE *out) {
    const u32 addresses[] = {TRACE_D_8011B990, read_word(TRACE_FLAGS_0), read_word(TRACE_FLAGS_1),
                            read_word(TRACE_FLAGS_2), TRACE_D_8012C780, TRACE_D_8012C78C};
    const u32 sizes[] = {4, 176, 22, 32, 12, 6};
    fputs(",\"flags\":[", out);
    for (u32 i = 0; i < 6; i++) {
        if (i) fputc(',', out);
        u64 hash = region_hash(addresses[i], sizes[i]);
        u8 bytes[8];
        for (u32 j = 0; j < 8; j++) bytes[j] = (u8)(hash >> (56 - j * 8));
        state_hash = hash_bytes(state_hash, bytes, sizeof bytes);
        fprintf(out, "\"%016" PRIx64 "\"", hash);
    }
    fputc(']', out);
}

static u64 file_hash(const char *path, int optional) {
    FILE *file = fopen(path, "rb");
    if (!file) {
        if (optional && errno == ENOENT) return 0;
        bt_fatal("BT_TRACE: cannot read %s: %s", path, strerror(errno));
    }
    u8 buffer[4096];
    size_t size;
    u64 hash = FNV_OFFSET;
    while ((size = fread(buffer, 1, sizeof buffer, file))) hash = hash_bytes(hash, buffer, size);
    if (ferror(file)) bt_fatal("BT_TRACE: read failed: %s", path);
    fclose(file);
    return hash;
}

void bt_trace_init(const char *rom) {
    const char *path = getenv("BT_TRACE");
    if (!path) return;
    if (!getenv("BT_VCLOCK") || !getenv("BT_HEADLESS"))
        bt_fatal("BT_TRACE requires BT_VCLOCK=1 and BT_HEADLESS=1 (scripted, build-local comparisons)");
    // Read inputs before opening the output, including when a path accidentally names an input file.
    u64 rom_hash = file_hash(rom, 0), eeprom_hash = file_hash(bt_host_path("bt_eeprom.bin"), 1);
    trace = fopen(path, "wx");
    if (!trace) bt_fatal("BT_TRACE: cannot create %s: %s", path, strerror(errno));
    setvbuf(trace, NULL, _IOLBF, 0);
    fprintf(trace, "{\"format\":\"bt-trace-1\",\"clock\":\"vclock-build-local\",\"build\":\"%s\","
            "\"rom\":\"%016" PRIx64 "\",\"eeprom\":\"%016" PRIx64 "\"", BT_TRACE_BUILD, rom_hash, eeprom_hash);
    const char *names[] = {"BT_PRESS", "BT_SCALE", "BT_MUTE"};
    for (u32 i = 0; i < 3; i++) {
        const char *setting = getenv(names[i]);
        if (!setting) setting = "";
        u64 h = hash_bytes(FNV_OFFSET, setting, strlen(setting));
        // Settings that change the run like scripted input does count into the BT_PRESS identity
        // (only when set, so older traces keep theirs).
        if (i == 0 && getenv("BT_WARP")) h = hash_bytes(h, getenv("BT_WARP"), strlen(getenv("BT_WARP")));
        const char *more[] = {"BT_FPS60", "BT_WIDESCREEN", "BT_LANG"};
        for (u32 j = 0; i == 0 && j < 3; j++)
            if (getenv(more[j])) h = hash_bytes(hash_bytes(h, more[j], strlen(more[j])), getenv(more[j]), strlen(getenv(more[j])));
        fprintf(trace, ",\"%s\":\"%016" PRIx64 "\"", names[i], h);
    }
    for (unsigned port = 2; port <= 4; port++) {
        char name[] = "BT_PRESS2";
        name[8] = '0' + port;
        const char *value = getenv(name);
        if (value && *value)
            fprintf(trace, ",\"%s\":\"%016" PRIx64 "\"", name, hash_bytes(FNV_OFFSET, value, strlen(value)));
    }
    fputs("}\n", trace);
    if (ferror(trace)) bt_fatal("BT_TRACE: header write failed");
}

void bt_trace_retrace(u32 retrace, u32 fb, u32 width) {
    if (!trace) return;
    u32 w = width >= 16 && width <= 640 ? width : 320, h = w * 3 / 4;
    fprintf(trace, "{\"retrace\":%u,\"ticks\":%" PRIu64 ",\"framebuffer\":{\"width\":%u,\"height\":%u,"
            "\"hash\":\"%016" PRIx64 "\"},\"map\":", retrace, bt_vclock_ticks(), w, h, region_hash(fb, w * h * 2));
    state_hash = FNV_OFFSET;
    // func_800EA05C returns this current map; D_80127630 holds a pending transition.
    check_range(TRACE_D_80132DC2, 2);
    value(trace, gr16(TRACE_D_80132DC2));
    players(trace);
    actors(trace);
    flags(trace);
    fprintf(trace, ",\"state\":\"%016" PRIx64 "\"}\n", state_hash);
    if (ferror(trace)) bt_fatal("BT_TRACE: retrace write failed");
}

// BT_XSYM builds (bt-xsym pass): an access left its label's extent. Each site reports its first
// hit as "SITE ADDRESS" to $BT_XSYM (default xsym_hits.txt); xsym_report.py names the symbols.
struct w2c_env;
void w2c_env_xsym(struct w2c_env *env, u32 site, u32 address) {
    (void)env;
    static u8 seen[1 << 20];
    static FILE *out;
    if (site >= sizeof seen || seen[site])
        return;
    seen[site] = 1;  // guest code runs on one host thread at a time
    if (!out) {
        const char *path = getenv("BT_XSYM");
        if (!(out = fopen(path && *path ? path : "xsym_hits.txt", "w")))
            bt_fatal("BT_XSYM: cannot write hits file");
        setvbuf(out, NULL, _IOLBF, 0);
    }
    fprintf(out, "%u %08x\n", site, address);
}
