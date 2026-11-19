#include "native_render.h"
#include <math.h>
void func_800192FC(f32 *,f32 *);
void func_800EE97C(f32 *,f32 *,f32 *);
void func_800EF2A0(f32 *);
void func_800EF368(f32 *,f32);
void func_800F24D0(MtxF *,f32 *,f32 *);
static struct {NativeRenderData *data;f32 right[3],up[3];int bones;} texture_projection;
void func_8010EF70(NativeRenderData *data,s32 unused1,void *unused2,const f32 *camera) {
    (void)unused1;(void)unused2;texture_projection.data=data;texture_projection.bones=func_800DF8D4(data);
    f32 direction[3],up[3]={0,1,0};
    for(int i=0;i<3;++i)direction[i]=data->position[i]-camera[i];
    func_800EF368(direction,-1);func_800EE97C(texture_projection.right,up,direction);func_800EF2A0(texture_projection.right);
    func_800EE97C(texture_projection.up,direction,texture_projection.right);func_800EF2A0(texture_projection.up);
    if(!texture_projection.bones) {
        func_800192FC(texture_projection.up,texture_projection.up);
        func_800192FC(texture_projection.right,texture_projection.right);
    }
}
int native_texture_projection_apply(NativeRenderData *data,f32 *matrix,s32 *first,s32 count) {
    if(!data || data!=texture_projection.data || !data->vertices || !data->normals || *first<0 || count<0 ||
       (u32)*first>func_800B2344(data->vertices) || (u32)count>func_800B2344(data->vertices)-(u32)*first)return 0;
    f32 right[3],up[3];
    if(texture_projection.bones) {
        func_800F24D0((MtxF *)matrix,right,texture_projection.right);func_800EF2A0(right);
        func_800F24D0((MtxF *)matrix,up,texture_projection.up);func_800EF2A0(up);
    } else for(int i=0;i<3;++i){right[i]=texture_projection.right[i];up[i]=texture_projection.up[i];}
    for(int i=*first;i<*first+count;++i) {
        f32 normal[3];for(int c=0;c<3;++c)normal[c]=data->normals[i*4+c]*0.007874015719f;
        f32 s=(normal[0]*right[0]+normal[1]*right[1])+normal[2]*right[2];
        f32 t=(normal[0]*up[0]+normal[1]*up[1])+normal[2]*up[2];
        /* The original stores the low 16 bits after truncating the scaled dot. */
        f32 coordinates[2]={s*992.0f+992.0f,t*992.0f+992.0f};
        for(int c=0;c<2;++c) {
            f32 value=coordinates[c];s32 integer=isfinite(value) && value>=-2147483648.0f && value<2147483648.0f ? (s32)value : 0;
            data->vertices->vertices[i].v.tc[c]=(s16)(u16)integer;
        }
    }
    *first+=count;return 1;
}
void func_8010F070(f32 *matrix,s32 *first,s32 count) {native_texture_projection_apply(texture_projection.data,matrix,first,count);}
void func_8010F270(void) {texture_projection.data=NULL;}
