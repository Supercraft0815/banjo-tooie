#include "native_model_lighting.h"
#include <math.h>
#include <limits.h>
void func_80019224(f32 *,f32 *);
void func_800192FC(f32 *,f32 *);
static struct {
    NativeRenderData *render;s32 ambient[3];u8 bones,count;
    NativeModelLightList *lights;NativeModelLight *start,*end;
} model_lighting;
void func_8010E070(void) {
    model_lighting.count=func_800B3784(model_lighting.lights);
    func_800B37A4(model_lighting.lights,&model_lighting.start,&model_lighting.end);
    if(!model_lighting.bones)for(NativeModelLight *p=model_lighting.start;p<model_lighting.end;++p) {
        func_800192FC(p->direction,p->direction);for(int i=0;i<3;++i)p->direction[i]*=256;
    }
    if(model_lighting.count>=2) {
        f32 total=0;for(NativeModelLight *p=model_lighting.start;p<model_lighting.end;++p)total+=p->distance;
        f32 inverse=total>0 ? 1.0f/total : 0;
        for(NativeModelLight *p=model_lighting.start;p<model_lighting.end;++p) {
            f32 weight=1-p->distance*inverse;
            for(int i=0;i<3;++i)p->color[i]*=weight;
        }
    }
    func_800B37B8(model_lighting.lights,model_lighting.ambient);
}
void func_8010E204(NativeRenderData *data,s32 count,f32 unused) {
    (void)unused;f32 center[3],radius;
    func_800B388C(model_lighting.lights,count==INT_MIN ? INT_MAX : count<0 ? -count : count);
    func_800B237C(data->vertices,center,&radius);func_80019224(center,center);
    func_800B3494(model_lighting.lights,center,radius*data->scale);
    if(count<0)func_800B3748(model_lighting.lights);
    func_800B38C8(model_lighting.lights);
}
void func_8010E2C4(NativeRenderData *data,s32 count,void *lights,const f32 *camera) {
    model_lighting.render=data;model_lighting.bones=func_800DF8D4(data);
    if(lights)func_800B37E4(model_lighting.lights,lights);else func_8010E204(data,count,0.0f);
    func_8010E070();
}
void func_8010E334(void) {model_lighting.lights=func_800B3310(4);}
void func_8010E358(void) {if(model_lighting.lights)model_lighting.lights=func_800B38E8(model_lighting.lights);}
void func_8010E390(void) {func_800B3370(model_lighting.lights);model_lighting.lights=NULL;func_8010E7F4();}
NativeModelLightList *func_8010E3B8(void) {return model_lighting.lights;}
void func_8010E3C4(f32 *matrix,s32 *out,f32 *input) {
    f32 v[3];for(int i=0;i<3;++i)v[i]=(input[0]*matrix[i*4]+input[1]*matrix[i*4+1])+input[2]*matrix[i*4+2];
    f32 length=sqrtf(v[0]*v[0]+v[1]*v[1]+v[2]*v[2]);
    for(int i=0;i<3;++i)out[i]=length>0 ? v[i]*(256.0f/length) : 0;
}
void func_8010E4C4(f32 *matrix,s32 *first,s32 count) {
    NativeRenderData *data=model_lighting.render;
    if(!data || !data->vertices || !data->colors || *first<0 || count<0 || (u32)*first>func_800B2344(data->vertices) || (u32)count>func_800B2344(data->vertices)-(u32)*first)return;
    if(model_lighting.count && !data->normals)return;
    s32 begin=*first,end=begin+count;*first=end;
    if(model_lighting.count) {
        for(int i=begin;i<end;++i)for(int c=0;c<3;++c)data->colors[i].light[c]=model_lighting.ambient[c];
        for(NativeModelLight *p=model_lighting.start;p<model_lighting.end;++p) {
            s32 direction[3];
            if(model_lighting.bones)func_8010E3C4(matrix,direction,p->direction);
            else for(int c=0;c<3;++c)direction[c]=p->direction[c];
            for(int i=begin;i<end;++i) {
                s8 *normal=data->normals+i*4;
                s32 dot=direction[0]*normal[0]+direction[1]*normal[1]+direction[2]*normal[2];
                if(dot>0)for(int c=0;c<3;++c)data->colors[i].light[c]+=(dot*p->color[c])>>15;
            }
        }
        for(int i=begin;i<end;++i)for(int c=0;c<3;++c) {
            s32 value=(data->colors[i].light[c]*data->colors[i].color[c])>>8;
            data->vertices->vertices[i].v.cn[c]=value>=256 ? 255 : value;
        }
    } else for(int i=begin;i<end;++i)for(int c=0;c<3;++c)
        data->vertices->vertices[i].v.cn[c]=(data->colors[i].color[c]*model_lighting.ambient[c])>>8;
}
void func_8010E7F4(void) {model_lighting.render=NULL;model_lighting.start=model_lighting.end=NULL;}
