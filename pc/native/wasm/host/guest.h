// Host view of the guest (wasm2c instance of the game).
#ifndef BT_HOST_GUEST_H
#define BT_HOST_GUEST_H
#include <stdint.h>
#include "game.h"

extern w2c_bt bt_inst;
extern u8 *bt_mem;

// Guest address -> host pointer. Guest pointers are 32-bit offsets into linear memory.
static inline void *G(u32 addr) { return bt_mem + addr; }
// Guest memory is big-endian like N64 RDRAM (the bt-bigendian pass): values wider than a byte
// go through these.
static inline u16 gr16(u32 a) { const u8 *p = G(a); return (u16)(p[0] << 8 | p[1]); }
static inline u32 gr32(u32 a) { u32 v; __builtin_memcpy(&v, G(a), 4); return __builtin_bswap32(v); }
static inline u64 gr64(u32 a) { return (u64)gr32(a) << 32 | gr32(a + 4); }
static inline void gw16(u32 a, u32 v) { u8 *p = G(a); p[0] = (u8)(v >> 8); p[1] = (u8)v; }
static inline void gw32(u32 a, u32 v) { v = __builtin_bswap32(v); __builtin_memcpy(G(a), &v, 4); }
static inline void gw64(u32 a, u64 v) { gw32(a, (u32)(v >> 32)); gw32(a + 4, (u32)v); }

// Calls the guest function at table index fn with one argument.
void bt_call_guest(u32 fn, u32 arg);
// The guest stack pointer of the instance; the running game thread owns it.
#define BT_SP (*w2c_bt_0x5F_stack_pointer(&bt_inst))


_Noreturn void bt_fatal(const char *fmt, ...);
void bt_os_post(u32 mq, u32 msg);  // from host threads: NOBLOCK send, dropped when full
void bt_os_event(u32 event);
u64 bt_os_time(void);        // CPU counter ticks since boot; a preemption safe point
void bt_vi_init(void);
u32 bt_vi_frame(u32 *fb, u32 *width);  // retrace count; framebuffer being shown (0 = black) and its width
_Noreturn void bt_video_main(void);    // main-thread window loop (video.c)
void gsp_run(u32 dl);                  // runs a graphics task's display list (gsp.c)
union SDL_Event;
void bt_input_event(const union SDL_Event *e);  // input.c: gamepad hotplug
void bt_input_update(double secs, int keyboard);  // input.c: samples controller 1
void bt_rom_open(const char *path);

#endif
