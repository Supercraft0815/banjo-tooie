#ifndef BT_NATIVE_MODEL_LIGHTING_H
#define BT_NATIVE_MODEL_LIGHTING_H
#include "native_render.h"
typedef struct {f32 direction[3];s32 color[3];f32 distance;} NativeModelLight;
typedef struct {s32 ambient[3],capacity;NativeModelLight *used,*end;NativeModelLight entries[];} NativeModelLightList;
NativeModelLightList *func_800B3310(s32);
void func_800B3370(void *);
NativeModelLight *func_800B3390(NativeModelLightList *,f32);
s32 func_800B3494(NativeModelLightList *,f32 *,f32);
int func_800B36C0(NativeModelLightList *,f32 *,s32 *,f32);
void func_800B3748(NativeModelLightList *);
s32 func_800B3784(NativeModelLightList *);
void func_800B37A4(NativeModelLightList *,NativeModelLight **,NativeModelLight **);
void func_800B37B8(NativeModelLightList *,s32 *);
void func_800B37E4(NativeModelLightList *,NativeModelLightList *);
void func_800B388C(NativeModelLightList *,s32);
void func_800B38A8(NativeModelLightList *,s32 *);
void func_800B38C8(NativeModelLightList *);
NativeModelLightList *func_800B38E8(NativeModelLightList *);
void func_8010E070(void);
void func_8010E204(NativeRenderData *,s32,f32);
void func_8010E2C4(NativeRenderData *,s32,NativeModelLightList *,f32);
void func_8010E334(void);
void func_8010E358(void);
void func_8010E390(void);
NativeModelLightList *func_8010E3B8(void);
void func_8010E3C4(f32 *,s32 *,f32 *);
void func_8010E4C4(f32 *,s32 *,s32);
void func_8010E7F4(void);
#endif
