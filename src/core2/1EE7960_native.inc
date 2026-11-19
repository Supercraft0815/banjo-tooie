#include "native_model_lighting.h"
#include <math.h>
#include <limits.h>
void func_80019224(f32 *,f32 *);
void func_800192FC(f32 *,f32 *);
NativeModelLighting D_80137060;
void func_8010E070(void) {
    D_80137060.count=func_800B3784(D_80137060.lights);
    func_800B37A4(D_80137060.lights,&D_80137060.start,&D_80137060.end);
    if(!D_80137060.bones)for(NativeModelLight *p=D_80137060.start;p<D_80137060.end;++p) {
        func_800192FC(p->direction,p->direction);for(int i=0;i<3;++i)p->direction[i]*=256;
    }
    if(D_80137060.count>=2) {
        f32 total=0;for(NativeModelLight *p=D_80137060.start;p<D_80137060.end;++p)total+=p->distance;
        f32 inverse=total>0 ? 1.0f/total : 0;
        for(NativeModelLight *p=D_80137060.start;p<D_80137060.end;++p) {
            f32 weight=1-p->distance*inverse;
            for(int i=0;i<3;++i)p->color[i]*=weight;
        }
    }
    func_800B37B8(D_80137060.lights,D_80137060.ambient);
}
void func_8010E204(NativeRenderData *data,s32 count,f32 unused) {
    (void)unused;f32 center[3],radius;
    func_800B388C(D_80137060.lights,count==INT_MIN ? INT_MAX : count<0 ? -count : count);
    func_800B237C(data->vertices,center,&radius);func_80019224(center,center);
    func_800B3494(D_80137060.lights,center,radius*data->scale);
    if(count<0)func_800B3748(D_80137060.lights);
    func_800B38C8(D_80137060.lights);
}
void func_8010E2C4(NativeRenderData *data,s32 count,void *lights,const f32 *camera) {
    D_80137060.render=data;D_80137060.bones=func_800DF8D4(data);
    if(lights)func_800B37E4(D_80137060.lights,lights);else func_8010E204(data,count,0.0f);
    func_8010E070();
}
void func_8010E334(void) {D_80137060.lights=func_800B3310(4);}
void func_8010E358(void) {if(D_80137060.lights){D_80137060.lights=func_800B38E8(D_80137060.lights);if(D_80137060.lights)func_800B37A4(D_80137060.lights,&D_80137060.start,&D_80137060.end);else D_80137060.start=D_80137060.end=NULL;}}
void func_8010E390(void) {func_800B3370(D_80137060.lights);D_80137060.lights=NULL;func_8010E7F4();}
NativeModelLightList *func_8010E3B8(void) {return D_80137060.lights;}
void func_8010E3C4(f32 *matrix,s32 *out,f32 *input) {
    f32 v[3];for(int i=0;i<3;++i)v[i]=(input[0]*matrix[i*4]+input[1]*matrix[i*4+1])+input[2]*matrix[i*4+2];
    f32 length=sqrtf(v[0]*v[0]+v[1]*v[1]+v[2]*v[2]);
    for(int i=0;i<3;++i)out[i]=length>0 ? v[i]*(256.0f/length) : 0;
}
void func_8010E4C4(f32 *matrix,s32 *first,s32 count) {
    NativeRenderData *data=D_80137060.render;
    if(!data || !data->vertices || !data->colors || *first<0 || count<0 || (u32)*first>func_800B2344(data->vertices) || (u32)count>func_800B2344(data->vertices)-(u32)*first)return;
    if(D_80137060.count && !data->normals)return;
    s32 begin=*first,end=begin+count;*first=end;
    if(D_80137060.count) {
        for(int i=begin;i<end;++i)for(int c=0;c<3;++c)data->colors[i].light[c]=D_80137060.ambient[c];
        for(NativeModelLight *p=D_80137060.start;p<D_80137060.end;++p) {
            s32 direction[3];
            if(D_80137060.bones)func_8010E3C4(matrix,direction,p->direction);
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
        data->vertices->vertices[i].v.cn[c]=(data->colors[i].color[c]*D_80137060.ambient[c])>>8;
}
void func_8010E7F4(void) {D_80137060.render=NULL;D_80137060.start=D_80137060.end=NULL;}
