#include "native_render.h"
#include "native_model_lighting.h"
#include "memory.h"
void func_8001980C(f32 *,f32 *,f32,f32 *);
NativeRenderState native_render={.custom_modes={native_model_render_banks[0],native_model_render_banks[3]}};
BoneTransformList *func_800DF324(void) {return native_render.pose;}
NativeBoneMatrices **func_800DF330(void) {return &native_render.scratch;}
s32 func_800DF33C(s32 index) {return index>=0 && index<60 ? native_render.switches[index] : 0;}
s32 func_800DF350(void) {return native_render.visible;}
void func_800DF35C(void) {func_800ADF5C(native_render.scratch);native_render.scratch=NULL;func_8010E390();}
void func_800DF38C(void) {
    func_800DE318();native_render.look_current=native_render.look_at;native_render.look_end=native_render.look_at+32;
    for(int i=0;i<3;++i)native_render.look_position[i]=0;
    native_render.scratch=func_800ADF98();func_8010E334();
}
void func_800DF3E0(void) {for(int i=0;i<60;++i)native_render.switches[i]=0;}
void func_800DF410(s32 alpha) {native_render.env[3]=alpha;}
void func_800DF41C(BoneTransformList *pose) {native_render.pose=pose;}
f32 func_800DF428(f32 distance) {f32 previous=native_render.distance;native_render.distance=distance;return previous;}
void func_800DF440(s32 enabled) {native_render.cull=enabled!=0;}
void func_800DF464(f32 scale) {native_render.range_scale=scale;}
void func_800DF470(s32 fade) {native_render.fade=fade;}
void func_800DF47C(NativeRenderCallback callback,uintptr_t data) {native_render.before=callback;native_render.before_arg=data;}
void func_800DF490(NativeRenderCallback callback,uintptr_t data) {native_render.after=callback;native_render.after_arg=data;}
void func_800DF4A4(NativeDisplayList *list) {native_render.data.display_list=list;}
void func_800DF4B0(u32 mode) {native_render.geometry_mode=mode;}
void func_800DF4CC(f32 *rotation) {native_render.transform_mode=1;for(int i=0;i<3;++i)native_render.transform[i]=rotation[i];}
void func_800DF500(f32 x,f32 y,f32 z) {native_render.transform_mode=2;native_render.transform[0]=x;native_render.transform[1]=y;native_render.transform[2]=z;}
void func_800DF540(MtxF *matrix) {native_render.transform_mode=3;native_render.extra_matrix=*matrix;}
void func_800DF574(s32 value) {native_render.unknown_short[0]=value;}
void func_800DF580(s32 *env,s32 *prim) {native_render.color_mode=1;for(int i=0;i<4;++i){native_render.env[i]=env[i];native_render.prim[i]=prim[i];}}
void func_800DF5D8(u32 r,u32 g,u32 b,s32 alpha) {
    u32 color[3]={r,g,b};native_render.color_mode=2;
    for(int i=0;i<3;++i)native_render.env[i]=(s32)color[i]>=256 ? 255 : (s32)color[i];func_800DF410(alpha);
}
void func_800DF660(s32 type,uintptr_t a,uintptr_t b,s32 alpha) {
    if(!a && !b){native_render.callback_mode=0;return;}
    native_render.callback_mode=1;native_render.callback_args[0]=a;native_render.callback_args[1]=b;native_render.callback_type=type;func_800DF410(alpha);
}
void func_800DF6BC(s32 value,s32 alpha) {native_render.color_mode=3;for(int i=0;i<4;++i)native_render.prim[i]=value>=256 ? 255 : value;func_800DF410(alpha);}
void func_800DF714(Mtx *matrices) {native_render.data.matrices=matrices;}
void func_800DF720(NativeVertexLight *colors) {native_render.data.colors=colors;}
void func_800DF72C(NativeBoneMatrices *matrices) {native_render.data.animation=matrices;}
void func_800DF738(void *attachments) {native_render.attachments=attachments;}
void func_800DF744(s32 index,s32 value) {if(index>=0 && index<60)native_render.switches[index]=value;}
void func_800DF758(s32 *values) {for(int i=1;i<60;++i)native_render.switches[i]=values[i];}
void func_800DF7C4(s32 index,s32 value) {func_800DF744(index,(s32)(0u-(u32)value));}
void func_800DF7DC(u8 *textures) {native_render.data.textures=textures;}
void func_800DF7E8(u8 index) {native_render.data.texture_animation=index;}
void func_800DF7F8(s32 id,f32 center,f32 radius) {native_render.asset_id=id;native_render.center_radius=center;native_render.radius=radius;}
void func_800DF818(NativeVertexList *vertices) {native_render.data.vertices=vertices;}
void func_800DF824(s8 *normals) {native_render.data.normals=normals;}
void func_800DF830(s32 mode) {native_render.depth_mode=mode;}
void func_800DF83C(void *zone) {native_render.zone_override=zone;}
void func_800DF848(Gfx *opaque,Gfx *translucent) {native_render.depth_mode=4;native_render.custom_modes[0]=opaque;native_render.custom_modes[1]=translucent;}
void func_800DF874(void) {if(native_render.scratch)func_800AE5F0(native_render.scratch);func_8010E358();}
NativeVertexList *func_800DF8B4(NativeRenderData *data) {return data->vertices;}
NativeVertexLight *func_800DF8BC(NativeRenderData *data) {return data->colors;}
f32 func_800DF8C4(NativeRenderData *data) {return data->scale;}
s8 *func_800DF8CC(NativeRenderData *data) {return data->normals;}
int func_800DF8D4(NativeRenderData *data) {return data->animation && !data->animated_vertices;}
f32 *func_800DF8F8(NativeRenderData *data) {return data->position;}
void func_800DF900(NativeRenderData *data) {mlMtx_push_translation(0,0,0);func_8001980C(data->position,data->rotation,data->scale,data->origin);}
