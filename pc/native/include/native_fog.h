#ifndef BT_NATIVE_FOG_H
#define BT_NATIVE_FOG_H
#include "common.h"
typedef struct {s16 map;u8 flags,padding;f32 start,end;u8 color[4];} NativeFogConfig;
_Static_assert(sizeof(NativeFogConfig)==16,"fog configuration scalar layout");
void func_800D2910(s32,const NativeFogConfig *);
void func_800D2970(void);
void func_800D298C(void);
void func_800D2A44(Gfx **);
void func_800D2C54(Gfx **);
void func_800D2CC4(void);
void func_800D2CD0(void);
void func_800D2E4C(void);
s32 func_800D2E90(s32);
void func_800D2EE4(void);
/* Shared by the original world/view wrappers; output needs room for one packet. */
void native_fog_load_map(s32);
void native_fog_apply(Gfx **,s32);
#endif
