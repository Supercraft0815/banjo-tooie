#ifndef __CORE2_1EA1270_H__
#define __CORE2_1EA1270_H__

#include "common.h"

typedef struct Unk800C7A68 {
    s16 unk0;
    u8 unk2;
    u8 pad3[0x14 - 0x3];
    s32 unk14;
} Unk800C7A68;

#ifdef BT_NATIVE
#include "ml/spline.h"
SplineDerivativeFunc func_800C79EC(Unk800C7A68 *);
SplineDerivativeFunc func_800C7980(u8 *);
f32 func_800C7AE4(u8 *, f32, f32);
f32 func_800C7B28(u8 *, f32, f32, s32);
f32 func_800C7BCC(u8 *, u8 *);
f32 func_800C7E28(void *);
f32 func_800C7FD4(u8 *, f32, f32);
f32 func_800C8070(u8 *, f32, f32, s32 *);
void func_800C810C(u8 *, f32, f32 *, f32 *);
f32 func_800C82CC(void *, f32 *);
void func_800C84A4(s8 *, s32);
#else
void (*func_800C79EC(Unk800C7A68 *))(f32, u8, s32*, f32 *);
#endif
void func_800C7A68(Unk800C7A68*, f32, f32 *);
f32 func_800C7B7C(Unk800C7A68 *, f32, f32, f32);

#endif
