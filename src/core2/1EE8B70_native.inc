#include "native_point_lighting.h"
#include "native_lights.h"
void func_80019224(f32 *,f32 *),func_800193C4(f32 *,f32 *);
NativeAdditiveLighting D_80137240;
NativePointLight *func_8010F280(s32 score) {
    if(!D_80137240.used || !D_80137240.end)return NULL;
    NativePointLight *entry=D_80137240.entries;
    for(;entry<D_80137240.used;++entry)if(entry->score<score)break;
    if(entry==D_80137240.used){if(entry==D_80137240.end)return NULL;++D_80137240.used;return entry;}
    if(D_80137240.used==D_80137240.end)--D_80137240.used;
    for(NativePointLight *p=D_80137240.used;p>entry;--p)*p=*(p-1);
    ++D_80137240.used;return entry;
}
void func_8010F384(NativeRenderData *data,s32 amount,uintptr_t unused) {
    (void)unused;
    D_80137240.end=D_80137240.used+native_point_capacity(amount,D_80137240.entries+5-D_80137240.used);
    if(!data || !data->vertices || !isfinite(data->scale) || data->scale<=0){D_80137240.count=0;return;}
    f32 center[3],radius,scale=data->scale;func_800B237C(data->vertices,center,&radius);func_80019224(center,center);radius*=scale;
    func_800DF900(data);
    for(s32 id=func_800C8760(0,2);id;id=func_800C878C(id,0,2)) {
        f32 position[3],range[2],delta[3];s32 color[3];func_800C8800(id,position);func_800C883C(id,range);
        for(int i=0;i<3;++i)delta[i]=position[i]-center[i];
        f32 distance=sqrtf((delta[0]*delta[0]+delta[1]*delta[1])+delta[2]*delta[2]);
        if(!isfinite(distance) || range[1]+radius<=distance)continue;
        func_800C8900(id,color);
        s32 score=native_point_word((color[0]+color[1]+color[2])*(1.0f-distance/(range[1]+radius)));
        NativePointLight *entry=func_8010F280(score);if(!entry)continue;
        entry->score=score;func_800193C4(delta,position);
        for(int i=0;i<3;++i){entry->position[i]=native_point_word(delta[i]);entry->color[i]=color[i];}
        range[0]/=scale;range[1]/=scale;entry->inner=native_point_word(range[0]*256);
        entry->outer_squared=native_point_word(range[1]*range[1]);entry->falloff=native_point_word(16384.0f/(range[1]-range[0]));
    }
    D_80137240.count=D_80137240.used-D_80137240.entries;mlMtxPop();
}
void func_8010F68C(NativeVertexList *vertices,NativeVertexLight *colors) {
    if(!vertices || !colors)return;
    if(!D_80137240.count && !(vertices->count_flags&1))return;
    for(u32 i=0;i<func_800B2344(vertices);++i) {
        Vtx *vertex=vertices->vertices+i;if(vertex->v.flag&0x1000)continue;
        s32 rgb[3]={colors[i].color[0],colors[i].color[1],colors[i].color[2]};
        if(D_80137240.count)for(NativePointLight *light=D_80137240.entries;light<D_80137240.used;++light) {
            s32 scale=native_point_attenuation(light,vertex)*4;
            for(int c=0;c<3;++c)rgb[c]+=(light->color[c]*scale)>>16;
        }
        for(int c=0;c<3;++c)vertex->v.cn[c]=rgb[c]>=256 ? 255 : rgb[c];
    }
    vertices->count_flags=(vertices->count_flags&~1u)|(D_80137240.count!=0);
}
void func_8010F950(NativeRenderData *data,s32 amount,void *unused,const f32 *camera) {
    (void)unused;(void)camera;D_80137240.render=data;D_80137240.used=D_80137240.entries;
    func_8010F384(data,amount,0);if(data)func_8010F68C(data->vertices,data->colors);
}
