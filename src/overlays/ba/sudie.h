#ifndef __BA_SUDIE_H__
#define __BA_SUDIE_H__

#include <ultra64.h>
#include "overlays/ba/playerstate.h"

extern void _basudie_entrypoint_0(PlayerState *self);
extern void _basudie_entrypoint_1(PlayerState *self);

void _basudie_entrypoint_2(BtIntPtr arg0, f32 arg1, f32 arg2, f32 arg3);
void _basudie_entrypoint_5(PlayerState *self);
void _basudie_entrypoint_6(PlayerState *self, s32);

extern void _basudie_entrypoint_12(BtIntPtr arg0);

#endif // __BA_SUDIE_H__
