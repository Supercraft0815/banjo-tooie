#ifndef __CORE2_1EB93C0_H__
#define __CORE2_1EB93C0_H__

#include "common.h"

typedef struct { f32 unk0[4]; f32 scale[3]; f32 unk1C[3]; } BoneTransform;
typedef struct { BoneTransform *ptr; s32 count; } BoneTransformList;

#ifdef BT_NATIVE
_Static_assert(sizeof(BoneTransform) == 0x28, "bone transform stride");
void func_800DFAD0(BoneTransformList *);
void func_800DFB40(BoneTransformList *, s32, f32 *);
void func_800DFB7C(BoneTransformList *, s32, f32 *, f32 *, f32 *);
void func_800DFBE0(BoneTransformList *, s32, f32 *);
void func_800DFC20(BoneTransformList *, s32, f32 *);
void func_800DFC60(void *);
BoneTransformList *func_800DFC80(void);
void func_800DFCC0(s16);
BoneTransformList *func_800DFCE8(s16);
s16 func_800DFD10(void);
void func_800DFD64(BoneTransformList *, BoneTransformList *, BoneTransformList *, f32);
void func_800DFEA8(BoneTransformList *, BoneTransformList *);
void func_800DFF2C(BoneTransformList *, s32, f32[4]);
void func_800DFF64(BoneTransformList *, s32, f32 *);
void func_800DFFA0(BoneTransformList *, s32, f32 *);
void func_800DFFDC(BoneTransformList *, s32, f32 *);
BoneTransformList *func_800E0018(BoneTransformList *);
void func_800E0040(BoneTransformList *);
#else
void func_800DFF2C(u8 **, s32, f32[4]);
#endif

#endif // __CORE2_1EB93C0_H__
