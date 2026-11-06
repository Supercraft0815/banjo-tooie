// Host view of the guest (wasm2c instance of the game).
#ifndef BT_HOST_GUEST_H
#define BT_HOST_GUEST_H
#include <stdint.h>
#include "game.h"

extern w2c_bt bt_inst;
extern u8 *bt_mem;

// Guest address -> host pointer. Guest pointers are 32-bit offsets into linear memory.
static inline void *G(u32 addr) { return bt_mem + addr; }
static inline u32 GW(u32 addr) { return *(u32 *)G(addr); }

// Calls the guest function at table index fn with one argument.
void bt_call_guest(u32 fn, u32 arg);
// The guest stack pointer of the instance; the running game thread owns it.
#define BT_SP (*w2c_bt_0x5F_stack_pointer(&bt_inst))

// ILP32 libultra structs as the guest lays them out.
typedef struct { u32 next; s32 priority; u32 queue; u32 tlnext; u16 state; u16 flags; s32 id; } GThread;
typedef struct { u32 mtqueue, fullqueue; s32 validCount, first, msgCount; u32 msg; } GMesgQueue;
typedef struct { u32 next, prev; u64 interval, value; u32 mq, msg; } GTimer;
_Static_assert(sizeof(GTimer) == 32, "OSTimer layout");

_Noreturn void bt_fatal(const char *fmt, ...);
void bt_os_post(u32 mq, u32 msg);  // from host threads: NOBLOCK send, dropped when full
void bt_os_event(u32 event);
u64 bt_os_time(void);        // CPU counter ticks since boot; a preemption safe point
void bt_vi_init(void);
void bt_rom_open(const char *path);

#endif
