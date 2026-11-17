#ifndef __CORE2_1EDA900_H__
#define __CORE2_1EDA900_H__

#include "common.h"

void func_80101010(f32 *);
void func_80101074(void *);
void *func_80101080(void);
#ifdef BT_NATIVE
void *func_80100368(void *);
void func_80101038(f32 *),func_8010105C(f32);
f32 func_80101068(void);
#ifndef BT_ILP32 // ILP32 compiles the original 1EDA900.c, which defines these with s32
intptr_t func_8010108C(Actor *,s32,uintptr_t);
intptr_t func_8010114C(Unk80132ED0 *,s32,uintptr_t);
intptr_t func_80101180(s32,s32,uintptr_t);
intptr_t func_80101238(s32,uintptr_t);
intptr_t func_801012D0(f32 *,f32,s32,uintptr_t);
intptr_t func_801013A8(f32 *,s32,uintptr_t);
#else
s32 func_8010108C(Actor *,s32,s32),func_8010114C(Unk80132ED0 *,s32,s32),func_80101180(s32,s32,s32);
s32 func_80101238(s32,s32),func_801012D0(f32 *,f32,s32,s32),func_801013A8(f32 *,s32,s32);
#endif
#else
s32 func_8010114C(s32, s32, s32);
s32 func_8010108C();
s32 func_80101180(s32, s32, s32);
#endif

#endif // __CORE2_1EDA900_H__
