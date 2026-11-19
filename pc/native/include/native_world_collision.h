#ifndef BT_NATIVE_WORLD_COLLISION_H
#define BT_NATIVE_WORLD_COLLISION_H
#include "native_world_grid.h"
typedef struct NativeMarkerCollision {
    void *(*line)(Unk80132ED0 *,f32 *,f32 *,f32 *,u32);
    void *(*sweep)(Unk80132ED0 *,f32 *,f32 *,f32,f32 *,s32,u32);
    void *(*sphere)(Unk80132ED0 *,f32 *,f32,f32 *,u32);
    s32 (*test)(Unk80132ED0 *,f32 *,f32,f32 *,u32);
} NativeMarkerCollision;
void func_800CB840(s32,BtIntPtr);
s16 func_800CB854(s32 *);
void func_800CB870(void);
void func_800CD230(f32);
void *func_800CD23C(f32 *,f32 *,f32 *,u32);
void *func_800CD3A8(f32 *,f32 *,f32,f32 *,s32,u32);
void *func_800CD544(f32 *,f32,f32 *,u32);
s32 func_800CD6B4(Unk80132ED0 *,f32 *,f32,f32 *,s32);
Unk80132ED0 *func_800CD820(Unk80132ED0 *,f32 *,f32 *,f32);
s32 func_800CDBA8(Unk80132ED0 *,f32 *,f32 *,s32);
Unk80132ED0 *func_800CDFA8(s32,s32 *);
int func_800EA3A0(void);
void func_800EA400(s32,Unk80132ED0 *,f32 *,void *);
void func_800EA600(void (*)(uintptr_t,uintptr_t),uintptr_t);
void func_800EA614(void);
void *func_800EA628(NativeWorldCell *,f32 *,f32 *,f32 *,u32);
void *func_800EAA2C(NativeWorldCell *,f32 *,f32 *,f32,f32 *,s32,u32);
void *func_800EADFC(NativeWorldCell *,f32 *,f32,f32 *,u32);
#endif
