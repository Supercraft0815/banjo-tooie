#ifndef BT_NATIVE_POINT_LIGHTING_H
#define BT_NATIVE_POINT_LIGHTING_H
#include "native_render.h"
#include <math.h>
#include <limits.h>
typedef struct {
    s32 position[3],inner,outer_squared,falloff,color[3];
    union {f32 distance;s32 score;};
} NativePointLight;
_Static_assert(sizeof(NativePointLight)==40,"point-light scalar layout");
typedef struct {
    NativeRenderData *render;
    s32 ambient[3];
    u8 bones, count, pad[2];
    NativePointLight *used,*end,entries[9];
} NativePointLighting;
extern NativePointLighting D_80137080;
typedef struct {
    NativeRenderData *render;
    s32 count;
    NativePointLight *used, *end;
    NativePointLight entries[5];
} NativeAdditiveLighting;
extern NativeAdditiveLighting D_80137240;
#if UINTPTR_MAX == UINT32_MAX
_Static_assert(offsetof(NativePointLighting, entries) == 0x1C, "ILP32 point-light entries offset");
_Static_assert(sizeof(NativePointLighting) == 0x184, "ILP32 point-light state size");
_Static_assert(offsetof(NativeAdditiveLighting, entries) == 0x10, "ILP32 additive entries offset");
_Static_assert(sizeof(NativeAdditiveLighting) == 0xD8, "ILP32 additive state size");
#elif UINTPTR_MAX == UINT64_MAX
_Static_assert(offsetof(NativePointLighting, entries) == 0x28, "LP64 point-light entries offset");
_Static_assert(sizeof(NativePointLighting) == 0x190, "LP64 point-light state size");
_Static_assert(offsetof(NativeAdditiveLighting, entries) == 0x20, "LP64 additive entries offset");
_Static_assert(sizeof(NativeAdditiveLighting) == 0xE8, "LP64 additive state size");
#endif
NativePointLighting *func_8010E810(void);
NativePointLight *func_8010E81C(f32);
NativePointLight *func_8010E924(s32,f32 *,f32,f32);
void func_8010EACC(NativeRenderData *,s32,f32);
void func_8010EBE4(NativeVertexList *,s8 *,NativeVertexLight *);
void func_8010EECC(NativeRenderData *,s32,void *,const f32 *);
NativePointLight *func_8010F280(s32);
void func_8010F384(NativeRenderData *,s32,uintptr_t);
void func_8010F68C(NativeVertexList *,NativeVertexLight *);
void func_8010F950(NativeRenderData *,s32,void *,const f32 *);
void func_80800000_trangler(NativeRenderData *,s32,s32,const f32 *);
void trangler_entrypoint_0(NativeRenderData *,s32,void *,const f32 *);
/* MIPS trunc.w.s yields its indefinite word for invalid conversion. */
static inline s32 native_point_word(f32 value) {
    return isfinite(value) && value>=-2147483648.0f && value<2147483648.0f ? (s32)value : INT_MIN;
}
static inline s32 native_point_capacity(s32 amount,s32 available) {
    s64 count = amount < 0 ? -(s64)amount : amount;
    return count < available ? (s32)count : available;
}
static inline s32 native_point_attenuation(const NativePointLight *light,const Vtx *vertex) {
    s32 x=light->position[0]-vertex->v.ob[0],y=light->position[1]-vertex->v.ob[1],z=light->position[2]-vertex->v.ob[2];
    s32 squared=x*x+y*y+z*z;
    if(squared>=light->outer_squared)return 0;
    s32 distance=native_point_word(sqrtf((f32)squared)*256.0f);
    return light->inner<distance ? 0x4000-((light->falloff*(distance-light->inner))>>8) : 0x4000;
}
#endif
