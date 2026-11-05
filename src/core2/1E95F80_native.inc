#include "native_reflection.h"
#include "native_render.h"
#include "core2/1EAF950.h"
#include "memory.h"
void func_800EF410(f32 *,f32 *),func_800EFA20(void *,void *,f32),func_800F23D0(MtxF *,f32 *,f32 *);
f32 func_800EEAA4(f32 *,f32 *);
extern Mtx *D_8012D558;
NativeReflection native_reflection;
int native_reflection_load_map(s32 map) {
    static const struct {s16 map,model,alpha,water;f32 point[3],normal[3];} entries[]={
        {0x151,0x861,255,1,{0,0,0},{0,1,0}},
        {0x103,0x860,255,0,{1050,0,0},{-1,0,0}},
        {0x15E,0x857,255,1,{0,0,0},{0,1,0}},
    };
    NativeReflection *state=&native_reflection;func_800BC8A0();
    unsigned index;for(index=0;index<sizeof(entries)/sizeof(*entries);++index)if(entries[index].map==map)break;
    if(index==sizeof(entries)/sizeof(*entries))return 0;
    if(entries[index].water)func_800B5680(entries[index].point[1]);
    state->cull_enabled=state->active=1;state->bounds_valid=state->bounds_cached=0;
    state->model=entries[index].model;state->alpha=entries[index].alpha;
    for(int i=0;i<2;++i)state->buffers[i]=heap_alloc(NATIVE_REFLECTION_PACKETS*sizeof(Gfx));
    f32 normal[3],input[3];for(int i=0;i<3;++i)input[i]=entries[index].normal[i];func_800EF410(normal,input);
    for(int row=0;row<3;++row)for(int column=0;column<3;++column)
        state->matrix.m[row][column]=row==column ? 1.0f-(2.0f*normal[row])*normal[column] : (2.0f*-normal[row])*normal[column];
    for(int i=0;i<3;++i){state->matrix.m[i][3]=0;state->point[i]=entries[index].point[i];state->normal[i]=normal[i];}
    func_800EFA20(state->matrix.m[3],normal,2.0f*func_800EEAA4(state->point,normal));state->matrix.m[3][3]=1;
    guMtxF2L(state->matrix.m,&state->fixed);return 1;
}
void func_800BC690(void) {s32 func_800EA05C(void);native_reflection_load_map(func_800EA05C());}
void func_800BC8A0(void) {
    NativeReflection *state=&native_reflection;
    if(state->frame){state->frame->gfx=state->saved_gfx;state->frame->gfx_end=state->saved_end;state->frame->mtx=state->saved_mtx;state->frame=NULL;func_800E42E4(0);}
    for(int i=0;i<2;++i){heap_free(state->buffers[i]);state->buffers[i]=NULL;}state->active=0;
}
int func_800BC8F8(NativeGraphicsContext *frame) {
    NativeReflection *state=&native_reflection;if(!state->active)return 1;
    if(!frame || !frame->memory || !frame->gfx || !frame->gfx_end || frame->gfx>frame->gfx_end || state->frame || !func_800E42A8())return 0;
    NativeGraphicsMemory *memory=frame->memory;
    if(!native_graphics_address(memory,D_8012D558,sizeof(Mtx)) ||
       !native_graphics_register(memory,&state->fixed,sizeof(state->fixed)) ||
       !native_graphics_register(memory,state->restore,sizeof(state->restore)) ||
       !native_graphics_register(memory,D_80123418,sizeof(D_80123418)) ||
       !native_graphics_register(memory,D_80123428,sizeof(D_80123428)))return 0;
    for(int i=0;i<2;++i)if(!native_graphics_register(memory,state->buffers[i],NATIVE_REFLECTION_PACKETS*sizeof(Gfx)))return 0;
    state->saved_gfx=frame->gfx;state->saved_end=frame->gfx_end;state->saved_mtx=frame->mtx;state->frame=frame;
    frame->gfx=state->buffers[state->index];frame->gfx_end=frame->gfx+NATIVE_REFLECTION_PACKETS-1;
    func_800E42E4(1);return 1;
}
int func_800BC948(NativeGraphicsContext *frame) {
    void *func_800DE498(NativeGraphicsContext *,f32 *,f32 *,f32,f32 *,void *);
    NativeReflection *state=&native_reflection;if(!state->active)return 1;
    if(!frame || state->frame!=frame)return 0;
    Gfx *buffer=state->buffers[state->index];int success=0,previous_cull=state->cull_enabled;
    NativeGraphicsMemory *previous=native_graphics_bind(frame->memory);
    if(frame->gfx<buffer || frame->gfx>buffer+NATIVE_REFLECTION_PACKETS-1 || !func_800E42A8() || !native_graphics_address(frame->memory,D_8012D558,sizeof(Mtx)))goto done;
    int visible=!state->bounds_valid || func_800CAA24(func_800E42A8()->values,state->minimum,state->maximum);
    if(state->saved_end-state->saved_gfx<(visible ? 12 : 2))goto done;
    void *model=NULL;
    if(visible && state->model){model=func_800D674C(state->model);if(!model || !func_800B2840(model))goto done;}
    state->cull_enabled=0;gSPEndDisplayList(frame->gfx++);
    frame->gfx=state->saved_gfx;frame->gfx_end=state->saved_end;func_800E42E4(0);
    Gfx *script=state->restore[state->index],*cursor=script;
    func_800E4640(&cursor);func_800BCC90(&cursor);gSPEndDisplayList(cursor++);
    Gfx *normal=cursor;func_800E4640(&cursor);gSPEndDisplayList(cursor++);
    if(visible) {
        func_800E46E0(&frame->gfx,script);func_800BCC90(&frame->gfx);
        gSPClearGeometryMode(frame->gfx++,G_CULL_BOTH);func_800E7FF8(&frame->gfx,G_CULL_FRONT);
        gSPDisplayList(frame->gfx++,buffer);func_800E4640(&frame->gfx);
        gSPClearGeometryMode(frame->gfx++,G_CULL_BOTH);func_800E7FF8(&frame->gfx,G_CULL_BACK);
        if(model) {
            if(!state->bounds_cached){func_800B21CC(func_800B2840(model),state->minimum,state->maximum);state->bounds_cached=state->bounds_valid=1;}
            func_800DF440(0);func_800DF830(1);func_800DF410(state->alpha);
            frame->gfx_end-=2;func_800DE498(frame,NULL,NULL,1,NULL,model);frame->gfx_end=state->saved_end;
            if(frame->gfx>frame->gfx_end-2)goto done;
        }
        state->cull_enabled=1;
    }
    func_800E46E0(&frame->gfx,normal);gSPDisplayList(frame->gfx++,buffer);
    state->index^=1;success=1;
done:
    if(!success){frame->gfx=state->saved_gfx;frame->gfx_end=state->saved_end;frame->mtx=state->saved_mtx;state->cull_enabled=previous_cull;}
    state->frame=NULL;func_800E42E4(0);native_graphics_bind(previous);return success;
}
void func_800BCC28(f32 *out,f32 *in) {func_800F23D0(&native_reflection.matrix,out,in);}
int func_800BCC58(void) {return native_reflection.active && native_reflection.cull_enabled;}
u32 func_800BCC84(void) {return native_reflection.active;}
void func_800BCC90(Gfx **output) {gSPMatrix((*output)++,&native_reflection.fixed,G_MTX_PROJECTION|G_MTX_MUL|G_MTX_NOPUSH);}
