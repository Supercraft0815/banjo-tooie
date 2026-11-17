#ifndef __CORE2_1EA3AA0_H__
#define __CORE2_1EA3AA0_H__

#if defined(BT_NATIVE) && !defined(BT_ILP32)
#include "native_camera.h"
#else
#include <ultra64.h>
#include "core1/mlmtx.h"
void* func_800CA384(void*);
void func_800CA9D8(f32 *, f32 *);
f32 func_800CAF00(f32 [3], f32);

u16 func_800CB124(s32, MtxF *);

#endif
#endif // __CORE2_1EA3AA0_H__
