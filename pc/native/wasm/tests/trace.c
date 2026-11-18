#define BT_HOST_GUEST_H
#include <assert.h>
#include <stdint.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef uint8_t u8;
typedef uint32_t u32;
typedef uint64_t u64;
static struct { struct { u64 size; } w2c_memory; } bt_inst = {{0x81000000u}};
static u8 memory[0x1000000];
static void *G(u32 address) { return memory + (address - 0x80000000u); }
static void *G_range(u32 address, u64 bytes) {
    assert(address >= 0x80000000u && (u64)address + bytes <= bt_inst.w2c_memory.size);
    return G(address);
}
static u32 gr32(u32 a) { const u8 *p = G(a); return (u32)p[0] << 24 | p[1] << 16 | p[2] << 8 | p[3]; }
static uint16_t gr16(u32 a) { const u8 *p = G(a); return p[0] << 8 | p[1]; }
static void gw32(u32 a, u32 w) { u8 *p = G(a); p[0] = w >> 24; p[1] = w >> 16; p[2] = w >> 8; p[3] = w; }
static u64 bt_vclock_ticks(void) { return 781250; }
static const char *bt_host_path(const char *path) { return getenv("BT_SAVE") ? getenv("BT_SAVE") : path; }
static _Noreturn void bt_fatal(const char *fmt, ...) {
    va_list ap; va_start(ap, fmt); vfprintf(stderr, fmt, ap); va_end(ap); exit(3);
}
#include "../host/trace.c"

int main(int argc, char **argv) {
    assert(argc >= 2);
    assert(hash_bytes(FNV_OFFSET, "hello", 5) == UINT64_C(0xa430d84680aabd0b));
    bt_trace_init(argv[1]);
    if (argc > 2) { region_hash(0x80FFFFFF, 2); return 4; }
    bt_trace_retrace(1, 0, 320);
    const u32 player = 0x80010000, pos = 0x80011000, status = 0x80012000;
    const u32 vector = 0x80013000, actor = 0x80014000, marker = 0x80015000;
    gw32(TRACE_D_80132DC2, 0x018B0000); // Map 395, big-endian u16.
    gw32(TRACE_D_80135490, player);
    gw32(player + 0xE4, pos); gw32(player + 0x120, status);
    gw32(pos, 0x3F800000); gw32(status + 4, 7);
    gw32(TRACE_D_80136EE0, vector);
    gw32(vector, 0x9C); gw32(vector + 4, actor); gw32(vector + 8, actor + 0x9C);
    gw32(actor, marker); gw32(marker + 0x14, 0x00420000);
    gw32(actor + 4, 0x40000000); gw32(actor + 0x14, 3);
    gw32(TRACE_FLAGS_0, 0x80016000); gw32(0x80016000, 1);
    memset(G(0x80020000), 0x55, 320 * 240 * 2);
    u64 before = hash_bytes(FNV_OFFSET, memory, sizeof memory);
    bt_trace_retrace(2, 0x80020000, 320);
    assert(before == hash_bytes(FNV_OFFSET, memory, sizeof memory));
    // Relocating the registry and player must leave the semantic state unchanged.
    memcpy(G(player + 0x100000), G(player), 0x200);
    gw32(TRACE_D_80135490, player + 0x100000);
    memcpy(G(actor + 0x100000), G(actor), 0x9C);
    gw32(vector + 4, actor + 0x100000); gw32(vector + 8, actor + 0x100000 + 0x9C);
    bt_trace_retrace(3, 0x80020000, 320);
    assert(!fclose(trace));
    return 0;
}
