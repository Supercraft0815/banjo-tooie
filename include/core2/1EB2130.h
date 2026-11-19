#ifndef CORE2_1EB2130_H
#define CORE2_1EB2130_H

#ifdef BT_NATIVE
#include "freelist.h"

s32 func_800D89C8(s16 handle, s32 slot, f32 *position, f32 *rotation, f32 scale,
                  f32 *origin, u8 *vertices, f32 *previous, f32 *out);
void func_800D8B80(s16 handle, s32 slot, f32 *position, f32 *rotation, f32 scale,
                   f32 *origin, u16 *indices, u8 *vertices, f32 *contact);
#endif
#endif
