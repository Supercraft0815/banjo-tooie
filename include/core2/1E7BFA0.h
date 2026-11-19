#ifndef __CORE2_1E7BFA0_H__
#define __CORE2_1E7BFA0_H__

#include "common.h"
#include "core2/player_form_data.h"
#include "transformations.h"

#include "overlays/ba/playerstate.h"

void func_800A2CE8(PlayerState *, f32, s32);
void func_800A2D2C(PlayerState *, f32, s32);
TransformationId func_800A3274(PlayerState *);
f32 func_800A3298(PlayerState *);
void func_800A32C4(PlayerState *, f32[3]);
f32 func_800A3394(PlayerState *);
void func_800A3410(PlayerState *, s32);
void func_800A34AC(PlayerState *, f32[3]);
void func_800A38F0(PlayerState *, s32, s32);
void func_800A3904(PlayerState *, s32);

#ifdef BT_NATIVE
void func_800A3328(PlayerState *, f32 *);
void func_800A33A0(PlayerState *, f32 *);
void func_800A33CC(PlayerState *, f32 *);
void func_800A34F0(PlayerState *, f32 *);
void func_800A3514(PlayerState *, f32 *);
#endif

#endif // __CORE2_1E7BFA0_H__
