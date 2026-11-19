#include "native_point_lighting.h"
#include "native_lights.h"
void func_80019224(f32 *,f32 *),func_800193C4(f32 *,f32 *);
static NativePointLighting point_lighting;
NativePointLighting *func_8010E810(void) {return &point_lighting;}
NativePointLight *func_8010E81C(f32 distance) {
    NativePointLighting *list=&point_lighting;
    if(!list->used || !list->end)return NULL;
    NativePointLight *entry=list->entries;
    for(;entry<list->used;++entry)if(distance<entry->distance)break;
    if(entry==list->used){if(list->used==list->end)return NULL;++list->used;return entry;}
    if(list->used==list->end)--list->used;
    for(NativePointLight *p=list->used;p>entry;--p)*p=*(p-1);
    ++list->used;return entry;
}
NativePointLight *func_8010E924(s32 id,f32 *center,f32 radius,f32 scale) {
    if(!func_800C89A8(id) || !isfinite(scale) || scale<=0)return NULL;
    f32 position[3],range[2],delta[3];func_800C8800(id,position);func_800C883C(id,range);
    for(int i=0;i<3;++i)delta[i]=position[i]-center[i];
    f32 distance=sqrtf((delta[0]*delta[0]+delta[1]*delta[1])+delta[2]*delta[2]);
    if(!isfinite(distance) || range[1]+radius<=distance)return NULL;
    NativePointLight *entry=func_8010E81C(distance);if(!entry)return NULL;
    entry->distance=distance;func_800193C4(delta,position);
    for(int i=0;i<3;++i)entry->position[i]=native_point_word(delta[i]);
    range[0]/=scale;range[1]/=scale;
    entry->inner=native_point_word(range[0]*256);entry->outer_squared=native_point_word(range[1]*range[1]);
    entry->falloff=native_point_word(16384.0f/(range[1]-range[0]));func_800C8900(id,entry->color);return entry;
}
void func_8010EACC(NativeRenderData *data,s32 amount,f32 unused) {
    (void)unused;NativePointLighting *list=&point_lighting;
    list->end=list->used+native_point_capacity(amount,list->entries+9-list->used);
    if(!data || !data->vertices || !isfinite(data->scale) || data->scale<=0){list->count=0;return;}
    f32 center[3],radius;func_800B237C(data->vertices,center,&radius);func_80019224(center,center);radius*=data->scale;
    func_800DF900(data);
    for(s32 id=func_800C8760(0,1);id;id=func_800C878C(id,0,1))func_8010E924(id,center,radius,data->scale);
    list->count=list->used-list->entries;mlMtxPop();
}
void func_8010EBE4(NativeVertexList *vertices,s8 *normals,NativeVertexLight *colors) {
    (void)normals;if(!vertices || !colors)return;
    NativePointLighting *list=&point_lighting;
    for(u32 i=0;i<func_800B2344(vertices);++i) {
        Vtx *vertex=vertices->vertices+i;if(vertex->v.flag&0x1000)continue;
        s32 rgb[3]={list->ambient[0],list->ambient[1],list->ambient[2]};
        if(list->count)for(NativePointLight *light=list->entries;light<list->used;++light) {
            s32 attenuation=native_point_attenuation(light,vertex),scale=(s32)((u32)attenuation<<16)>>14;
            for(int c=0;c<3;++c)rgb[c]+=(light->color[c]*scale)>>16;
        }
        for(int c=0;c<3;++c) {
            s32 value=(colors[i].color[c]*rgb[c])>>8;
            vertex->v.cn[c]=list->count && value>=256 ? 255 : value;
        }
    }
}
void func_8010EECC(NativeRenderData *data,s32 count,void *unused,const f32 *camera) {
    (void)unused;(void)camera;
    point_lighting.render=data;point_lighting.bones=data ? func_800DF8D4(data) : 0;
    point_lighting.used=point_lighting.entries;
    func_8010EACC(data,count,0);func_800C87B8(point_lighting.ambient);
    if(data)func_8010EBE4(data->vertices,data->normals,data->colors);
}
