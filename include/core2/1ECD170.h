#ifndef __CORE2_1ECD170_H__
#define __CORE2_1ECD170_H__

#include "common.h"

#include <ultra64.h>

f32 func_800F3780(f32, u8 *, s16);
s32 func_800F424C(void *player);
#ifdef BT_NATIVE
struct player_state_s;
void func_800F3E84(struct player_state_s *, f32[3]);
void func_800F452C(struct player_state_s *, f32[3]);
void func_800F4648(void *player, f32 position[3]);
#endif

#endif // __CORE2_1ECD170_H__
