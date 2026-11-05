#ifndef __CORE2_ANIMATION_RESOURCE_H__
#define __CORE2_ANIMATION_RESOURCE_H__

#include "core2/1EB93C0.h"

#ifdef BT_NATIVE
/* Decode bounded big-endian resource bytes; free the returned host words with heap_free. */
s16 *native_animation_decode(const void *data, size_t size);
void func_800E0050(s16 *, f32, s32, f32 *);
void func_800E0170(s16 *, f32, s32, BoneTransformList *);
void func_800E02F8(s16 *, f32, s32, s32, s32, f32 *);
f32 func_800E0414(s16 *, f32);
s32 func_800E0440(s16 *);
s32 func_800E0448(s16 *);
s32 func_800E0450(void *);
s32 func_800E0464(s16 *);
f32 func_800E046C(void *, s32);
void func_800E04AC(void *);
f32 func_800E04C0(u8 *, f32, s32);
void func_800E084C(BoneTransformList *, f32 *, u32);
#endif
#endif
