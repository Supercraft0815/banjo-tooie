#ifndef __TYPES_H__
#define __TYPES_H__

#include <ultra64.h>

#define SQ(x) ((x) * (x))

#define ARRLEN(x) ((s32)(sizeof(x) / sizeof(x[0])))

#ifdef BT_NATIVE
#include <stdint.h>
#include <stddef.h>
#else
typedef u32 uintptr_t;

#define offsetof(type, member) \
    ((size_t)&((type*)0)->member)
#endif

#define UNUSED

// Minimum retraces between two game frames (func_80015184). Natively the player's frame-rate
// setting may lower it to 1; the game's delta time follows the retraces that really passed.
#ifdef BT_NATIVE
s32 bt_frame_interval(s32 game);
#define BT_FRAME_INTERVAL(n) bt_frame_interval(n)
// Other dialog languages from the European ROM (host io.c rom_add_language).
s32 bt_language(void);
s32 bt_asset_shift(void);
#else
#define BT_FRAME_INTERVAL(n) (n)
#endif

#endif
