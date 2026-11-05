#include "native_point_lighting.h"
#include "native_lights.h"
void func_80019224(f32 *,f32 *);
void func_80800000_trangler(NativeRenderData *data,s32 amount,s32 forced,const f32 *camera) {
    (void)camera;NativePointLighting *list=func_8010E810();
    list->end=list->used+native_point_capacity(amount,list->entries+9-list->used);
    if(!data || !data->vertices || !isfinite(data->scale) || data->scale<=0){list->count=0;return;}
    f32 center[3],radius;func_800B237C(data->vertices,center,&radius);func_80019224(center,center);radius*=data->scale;
    func_800DF900(data);
    if(forced) {
        NativePointLight *entry=func_8010E924(forced,center,radius,data->scale);
        if(entry)entry->distance=-1;
    }
    for(s32 id=func_800C8760(0,1);id;id=func_800C878C(id,0,1))func_8010E924(id,center,radius,data->scale);
    list->count=list->used-list->entries;mlMtxPop();
}
void trangler_entrypoint_0(NativeRenderData *data,s32 packed,uintptr_t unused,const f32 *camera) {
    (void)unused;NativePointLighting *list=func_8010E810();list->render=data;list->bones=data ? func_800DF8D4(data) : 0;list->used=list->entries;
    func_80800000_trangler(data,((u32)packed>>16)&0xFFFF,packed&0xFFFF,camera);
    func_800C87B8(list->ambient);if(data)func_8010EBE4(data->vertices,data->normals,data->colors);
}
