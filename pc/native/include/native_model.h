#ifndef BT_NATIVE_MODEL_H
#define BT_NATIVE_MODEL_H
#include "common.h"

/* Header, vertex, collision, skeleton, geometry, texture metadata, display-list and skinning-binding scalars are host-endian. */
typedef struct {
    s16 minimum[3], maximum[3], center[3];
    u16 center_radius, radius, count_flags;
    Vtx vertices[];
} NativeVertexList;
_Static_assert(sizeof(Vtx)==16 && offsetof(NativeVertexList,vertices)==24,
               "model vertex layout");

/* Validate the raw model before changing any bytes. Decode exactly once at load. */
int native_model_decode(void *model, s32 size);
u8 *func_800B26F0(u8 *);
s32 func_800B270C(s16 *);
void *func_800B2714(void *);
u8 *func_800B2720(u8 *);
u8 *func_800B274C(u8 *);
u8 *func_800B2768(u8 *);
u8 *func_800B2784(u8 *);
u8 *func_800B27A0(u8 *);
u8 *func_800B27BC(u8 *);
f32 func_800B27D8(f32 *);
u8 *func_800B27E0(u8 *);
void *func_800B27FC(void *);
u8 *func_800B2808(u8 *);
u8 *func_800B2824(u8 *);
void *func_800B2840(void *);
u8 *func_800B284C(u8 *);
u8 *func_800B2868(u8 *);

void *func_800B2190(void *);
void func_800B2198(void *,void *,void *);
void func_800B21CC(void *,void *,void *);
s32 func_800B2248(void *);
u8 *func_800B2324(u8 *,u8 **,u8 **);
u32 func_800B2344(void *);
f32 func_800B2354(void *);
void func_800B237C(void *,f32[3],f32 *);
void func_800B23E0(void *);
void *func_800B2400(NativeVertexList *,s32);
void func_800B2464(NativeVertexList *,s32[3],NativeVertexList *);
void func_800B2540(NativeVertexList *,s32[3]);
void func_800B25D8(NativeVertexList *,NativeVertexList *,const void *);
void func_800B26C8(void);
#endif
