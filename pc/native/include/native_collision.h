#ifndef BT_NATIVE_COLLISION_H
#define BT_NATIVE_COLLISION_H
#include "common.h"
typedef void *(*NativeCollisionLineQuery)(f32 *,f32 *,f32 *,u32);
typedef void *(*NativeCollisionSweepQuery)(f32 *,f32 *,f32,f32 *,s32,u32);
typedef void *(*NativeCollisionSphereQuery)(f32 *,f32,f32 *,u32);
typedef void *(*NativeCollisionModelQuery)(void);
f32 func_800C6920(f32 *,f32,f32,s32);
s32 func_800C696C(f32 *,f32,f32,s32,f32 *);
void *func_800C69FC(void);
s32 func_800C6A08(NativeCollisionLineQuery,NativeCollisionSweepQuery,NativeCollisionSphereQuery);
s32 func_800C6A28(NativeCollisionLineQuery,NativeCollisionSweepQuery,NativeCollisionSphereQuery,NativeCollisionModelQuery);
void func_800C6A60(void);
void func_800C6A68(void);
void *func_800C6A7C(f32 *,f32 *,f32 *,u32);
void *func_800C6B78(f32 *,f32 *,f32,f32 *,s32,u32);
void *func_800C6C94(f32 *,f32,f32 *,u32);
#endif
