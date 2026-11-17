// Exercise the real scheduler's publication of __osRunningThread without starting guest threads.
#define BT_HOST_GUEST_H
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <assert.h>
typedef uint8_t u8; typedef uint16_t u16; typedef uint32_t u32; typedef uint64_t u64;
typedef int32_t s32;
struct w2c_env;
static u8 memory[65536];
static u32 guest_sp;
#define BT_SP guest_sp
static void *G(u32 a) { assert((u64)a + 8 < sizeof memory); return memory + a; }
static u32 gr32(u32 a) { u32 v; __builtin_memcpy(&v, G(a), 4); return __builtin_bswap32(v); }
static u16 gr16(u32 a) { u8 *p = G(a); return p[0] << 8 | p[1]; }
static u64 gr64(u32 a) { return (u64)gr32(a) << 32 | gr32(a + 4); }
static void gw32(u32 a, u32 v) { v = __builtin_bswap32(v); __builtin_memcpy(G(a), &v, 4); }
static void gw16(u32 a, u32 v) { u8 *p = G(a); p[0] = v >> 8; p[1] = v; }
static void gw64(u32 a, u64 v) { gw32(a, v >> 32); gw32(a + 4, v); }
static _Noreturn void bt_fatal(const char *fmt, ...) { (void)fmt; abort(); }
static void wasm_rt_init_thread(void) {}
static void bt_call_guest(u32 fn, u32 arg) { (void)fn; (void)arg; abort(); }
static _Noreturn void bt_video_main(void) { abort(); }
static void bt_vi_init(void) { abort(); }
static void bt_vi_retrace(u32 *mq, u32 *msg) { *mq = *msg = 0; }
void w2c_env_osDestroyThread(struct w2c_env *, u32);
double bt_speed(void);
#include "../host/os.c"

int main(void) {
    setenv("BT_VCLOCK", "1", 1); setenv("BT_HEADLESS", "1", 1);
    w2c_env_osInitialize(NULL, 0x100);
    assert(gr32(0x100) == 0);
    bt_vclock_on = 0;
    threads[0].t = 0x1000; threads[1].t = 0x1100;
    pthread_cond_init(&threads[0].cv, NULL); pthread_cond_init(&threads[1].cv, NULL);
    gw32(0x1004, 20); gw32(0x1104, 40);
    enqueue(READY, 0x1000); enqueue(READY, 0x1100);
    dispatch(); assert(running == 0x1100 && gr32(0x100) == running && state(running) == OS_STATE_RUNNING);
    dispatch(); assert(running == 0x1000 && gr32(0x100) == running);
    dispatch(); assert(running == 0 && gr32(0x100) == 0);
    puts("Scheduler publishes current thread and idle state: PASS");
}
