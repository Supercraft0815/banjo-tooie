#ifndef BT_NATIVE_RENDER_H
#define BT_NATIVE_RENDER_H
#include "native_skinning.h"
#include "core2/geometry_callbacks.h"
#include "core2/model_materials.h"
typedef struct {u32 header[2];Gfx commands[];} NativeDisplayList;
typedef struct {s16 light[3];u8 color[4];} NativeVertexLight;
typedef struct GeometryRenderData {
    f32 scale,*position,*rotation,*origin,*extra_rotation;
    u8 *textures;NativeDisplayList *display_list;NativeVertexList *vertices;
    NativeBoneMatrices *animation;u8 texture_animation;void *zones;
    NativeVertexLight *colors;s8 *normals;u8 *animated_vertices;Mtx *matrices;
} NativeRenderData;
typedef void (*NativeRenderCallback)(uintptr_t);
typedef struct {
    BoneTransformList *pose;s32 cull;f32 distance,range_scale;s32 fade,callback_mode,color_mode;
    NativeBoneMatrices *scratch;void *attachments,*zone_override;s32 visible;
    s32 switches[60],prim[4],env[4];
    NativeRenderCallback before,after;uintptr_t before_arg,after_arg;
    s32 transform_mode;f32 transform[3];MtxF extra_matrix;
    uintptr_t callback_args[2];u8 callback_type;
    s32 asset_id;f32 center_radius,radius;s32 depth_mode;Gfx *custom_modes[2];
    s16 unknown_short[2];u32 geometry_mode;
    LookAtBuffer look_at;
    NativeRenderData data;
} NativeRenderState;
extern NativeRenderState native_render;
void func_800DE318(void);
BoneTransformList *func_800DF324(void);
NativeBoneMatrices **func_800DF330(void);
s32 func_800DF33C(s32);
s32 func_800DF350(void);
void func_800DF35C(void);
void func_800DF38C(void);
void func_800DF3E0(void);
void func_800DF410(s32);
void func_800DF41C(BoneTransformList *);
f32 func_800DF428(f32);
void func_800DF440(s32);
void func_800DF464(f32);
void func_800DF470(s32);
void func_800DF47C(NativeRenderCallback,uintptr_t);
void func_800DF490(NativeRenderCallback,uintptr_t);
void func_800DF4A4(NativeDisplayList *);
void func_800DF4B0(u32);
void func_800DF4CC(f32 *);
void func_800DF500(f32,f32,f32);
void func_800DF540(MtxF *);
void func_800DF574(s32);
void func_800DF580(s32 *,s32 *);
void func_800DF5D8(u32,u32,u32,s32);
void func_800DF660(s32,uintptr_t,uintptr_t,s32);
void func_800DF6BC(s32,s32);
void func_800DF714(Mtx *);
void func_800DF720(NativeVertexLight *);
void func_800DF72C(NativeBoneMatrices *);
void func_800DF738(void *);
void func_800DF744(s32,s32);
void func_800DF758(s32 *);
void func_800DF7C4(s32,s32);
void func_800DF7DC(u8 *);
void func_800DF7E8(u8);
void func_800DF7F8(s32,f32,f32);
void func_800DF818(NativeVertexList *);
void func_800DF824(s8 *);
void func_800DF830(s32);
void func_800DF83C(void *);
void func_800DF848(Gfx *,Gfx *);
void func_800DF874(void);
NativeVertexList *func_800DF8B4(NativeRenderData *);
NativeVertexLight *func_800DF8BC(NativeRenderData *);
f32 func_800DF8C4(NativeRenderData *);
s8 *func_800DF8CC(NativeRenderData *);
int func_800DF8D4(NativeRenderData *);
f32 *func_800DF8F8(NativeRenderData *);
void func_800DF900(NativeRenderData *);
void func_8010EF70(NativeRenderData *,s32,void *,const f32 *);
void func_8010F070(f32 *,s32 *,s32);
void func_8010F270(void);
int native_texture_projection_apply(NativeRenderData *,f32 *,s32 *,s32);
Gfx *native_model_modes(s16);
enum {NATIVE_MODEL_RENDER_PACKETS=58};
extern Gfx native_model_render_banks[8][NATIVE_MODEL_RENDER_PACKETS];
#define native_model_render_restore D_80122DB0
Gfx *native_model_render_modes(s32 depth,s32 alpha);
void func_80013C80(Mtx *,LookAt *,f32,f32,f32,f32,f32,f32,f32,f32,f32);
#endif
