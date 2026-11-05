#include "native_camera.h"
#include "memory.h"
#include <math.h>
#include <limits.h>
f32 func_800137F4(f32),func_80013788(void),func_800139F8(f32),func_800136E4(f32);
void func_800EF8BC(f32 *,f32 *,f32),func_800EF934(f32 *,f32 *,f32),func_800EF2A0(f32 *);
void func_800EE7F8(f32 *,f32 *),func_800EE84C(f32 *,s32 *),func_800EF368(f32 *,f32),func_800EFA4C(f32 *,f32,f32,f32);
void func_800EF4E4(f32 *,f32,f32,f32,f32,f32),func_800EF04C(f32 *,f32 *),func_800EFB24(void *,void *,void *);
f32 func_800EEAA4(f32 *,f32 *),func_800EEAD4(f32 *,f32 *);
void func_800D93A0(f32 *,f32 *),func_800D9624(f32 *,f32 *),func_800D965C(f32 *,f32 *);
void func_80019224(f32 *,f32 *),func_80019480(f32 *,f32,f32,f32),func_800F274C(MtxF *);

void func_800CA1B0(NativeCamera *camera) {
    func_800EFA4C(camera->side,-1,0,0);func_800EF934(camera->side,camera->side,camera->aspect*(camera->fov*0.5f));
}
void func_800CA218(NativeCamera *camera,f32 angle) {
    func_800EFA4C(camera->top,0,1,0);func_800EF8BC(camera->top,camera->top,angle);
    func_800EFA4C(camera->side,-1,0,0);func_800EF934(camera->side,camera->side,camera->aspect*angle);
}
void func_800CA2A8(NativeCamera *camera,f32 angle) {
    camera->local_rays[0][0]=0;
    f32 sine=func_800137F4(angle);camera->local_rays[1][1]=sine;camera->local_rays[0][1]=-sine;
    f32 cosine=-func_80013788();camera->local_rays[1][2]=camera->local_rays[0][2]=cosine;
    camera->local_rays[1][0]=camera->aspect*camera->local_rays[1][1];func_800EF2A0(camera->local_rays[1]);
}
void func_800CA314(NativeCamera *destination,NativeCamera *source) {*destination=*source;}
NativeCamera *func_800CA334(void) {NativeCamera *camera=heap_alloc(sizeof(*camera));func_800CA440(camera);return camera;}
void func_800CA364(void *camera) {heap_free(camera);}
void *func_800CA384(void *camera) {return defrag(camera);}
void func_800CA3A4(NativeCamera *camera,f32 distance) {
    f32 delta[3];func_800EF4E4(delta,camera->rotation[0],camera->rotation[1],0,0,distance);func_800EF04C(camera->position,delta);
}
void func_800CA3F4(f32 *position,f32 *point,f32 distance) {
    f32 delta[3];func_800EFB24(delta,position,point);func_800EF368(delta,distance);func_800EF04C(point,delta);
}
void func_800CA440(NativeCamera *camera) {
    func_800CA5F8(camera,0,0,0);func_800CA688(camera,0,0,0);func_800CA6C0(camera,1,10000);func_800CA6F0(camera,1);
    camera->fov=40;camera->cotangent=1.0f/func_800139F8(20);camera->aspect=1.333333373f;
    func_800CA218(camera,20);func_800CA2A8(camera,20);func_800CAF34(camera);
}
void func_800CA510(NativeCamera *camera,f32 aspect) {camera->aspect=aspect;func_800CA1B0(camera);func_800CA2A8(camera,camera->fov*0.5f);}
void func_800CA558(NativeCamera *camera,f32 fov) {
    f32 half=fov*0.5f;camera->fov=fov;camera->cotangent=1.0f/func_800139F8(half);func_800CA218(camera,half);func_800CA2A8(camera,half);
}
void func_800CA5B8(NativeCamera *camera,f32 *position) {func_800EE7F8(camera->position,position);}
void func_800CA5D8(NativeCamera *camera,s32 *position) {func_800EE84C(camera->position,position);}
void func_800CA5F8(NativeCamera *camera,f32 x,f32 y,f32 z) {func_800EFA4C(camera->position,x,y,z);}
void func_800CA628(NativeCamera *camera,f32 *position,f32 *rotation) {for(int i=0;i<3;++i){camera->position[i]=position[i];camera->rotation[i]=rotation[i];}}
void func_800CA668(NativeCamera *camera,f32 *rotation) {func_800EE7F8(camera->rotation,rotation);}
void func_800CA688(NativeCamera *camera,f32 pitch,f32 yaw,f32 roll) {func_800EFA4C(camera->rotation,pitch,yaw,roll);}
void func_800CA6C0(NativeCamera *camera,f32 near,f32 far) {camera->near_clip=near;camera->far_clip=far;}
void func_800CA6D4(NativeCamera *camera,f32 *near,f32 *far) {*near=camera->near_clip;*far=camera->far_clip;}
f32 func_800CA6E8(NativeCamera *camera) {return camera->range_scale;}
void func_800CA6F0(NativeCamera *camera,f32 scale) {camera->range_scale=scale;}
f32 func_800CA6FC(NativeCamera *camera) {return camera->aspect;}
f32 func_800CA704(NativeCamera *camera,f32 *point,f32 *delta) {func_800EFB24(delta,point,camera->position);return func_800EEAA4(camera->forward,delta);}
void func_800CA740(NativeCamera *camera,f32 *forward) {func_800EE7F8(forward,camera->forward);}
f32 func_800CA768(NativeCamera *camera,f32 *point) {return func_800EEAD4(point,camera->position);}
f32 func_800CA794(NativeCamera *camera) {return camera->fov;}
f32 func_800CA79C(NativeCamera *camera) {return camera->cotangent;}
MtxF *func_800CA7A4(NativeCamera *camera) {return &camera->world_rotation;}
MtxF *func_800CA7AC(NativeCamera *camera) {return &camera->view_rotation;}
f32 func_800CA7B4(NativeCamera *camera) {return camera->near_clip;}
void func_800CA7BC(NativeCamera *camera,f32 *fov,f32 *aspect,f32 *near,f32 *far) {*fov=camera->fov;*aspect=camera->aspect;*near=camera->near_clip;*far=camera->far_clip;}
void func_800CA7E4(NativeCamera *camera,f32 *position) {func_800EE7F8(position,camera->position);}
static s32 camera_integer(f32 value) {return isfinite(value) && value>=-2147483648.0f && value<2147483648.0f ? (s32)value : INT_MIN;}
void func_800CA810(NativeCamera *camera,s32 *position) {for(int i=0;i<3;++i)position[i]=camera_integer((f32)camera_integer(camera->position[i]*500.0f)/500.0f);}
void func_800CA8B4(NativeCamera *camera,f32 *position,f32 *rotation) {for(int i=0;i<3;++i){position[i]=camera->position[i];rotation[i]=camera->rotation[i];}}
void func_800CA8F4(NativeCamera *camera,f32 *position,f32 *forward) {for(int i=0;i<3;++i){position[i]=camera->position[i];forward[i]=camera->forward[i];}}
void func_800CA934(NativeCamera *camera,s16 *position) {s32 integers[3];func_800CA810(camera,integers);for(int i=0;i<3;++i)position[i]=(s16)(u16)integers[i];}
void func_800CA9D8(NativeCamera *camera,f32 *rotation) {func_800EE7F8(rotation,camera->rotation);}
void func_800CAA00(NativeCamera *camera,f32 *pitch,f32 *yaw,f32 *roll) {*pitch=camera->rotation[0];*yaw=camera->rotation[1];*roll=camera->rotation[2];}
f32 func_800CAA1C(NativeCamera *camera) {return camera->rotation[1];}
#include "1EA3AA0_culling.inc"
s32 func_800CAD9C(NativeCamera *camera,f32 x,f32 y,f32 z) {
    for(int i=0;i<4;++i) {
        f32 *p=camera->planes[i];if(!(p[0]*x+p[1]*y+p[2]*z+p[3]<=0))return 0;
    }
    return 1;
}
int func_800CAEA4(NativeCamera *camera,f32 x,f32 y,f32 z) {
    f32 *p=camera->planes[2];return p[0]*x+p[1]*y+p[2]*z+p[3]<=0;
}
f32 func_800CAF00(NativeCamera *camera,f32 angle) {return func_800136E4(camera->rotation[1]+angle+90);}
void func_800CAF34(NativeCamera *camera) {
    f32 quaternion[4],inverse[4];func_800D93A0(quaternion,camera->rotation);
    func_800D965C(quaternion,&camera->world_rotation.m[0][0]);func_800D9624(inverse,quaternion);func_800D965C(inverse,&camera->view_rotation.m[0][0]);
    mlMtxSet(&camera->world_rotation);func_800EFA4C(camera->forward,0,0,-1);func_80019224(camera->forward,camera->forward);
    func_80019224(camera->planes[0],camera->side);func_80019480(camera->planes[1],-camera->side[0],camera->side[1],camera->side[2]);
    func_80019224(camera->planes[2],camera->top);func_80019480(camera->planes[3],camera->top[0],-camera->top[1],camera->top[2]);
    for(int i=0;i<4;++i)camera->planes[i][3]=-func_800EEAA4(camera->position,camera->planes[i]);
    f32 *corner=camera->local_rays[1];
    func_80019480(camera->world_rays[0],-corner[0],-corner[1],corner[2]);func_80019224(camera->world_rays[1],corner);
    func_80019224(camera->world_rays[2],camera->local_rays[0]);func_80019480(camera->world_rays[3],-corner[0],corner[1],corner[2]);
    func_80019480(camera->world_rays[4],corner[0],-corner[1],corner[2]);
}
void func_800CB0E8(NativeCamera *camera,f32 *ray,s32 index) {if(index>=0 && index<5)func_800EE7F8(ray,camera->world_rays[index]);}
u16 func_800CB124(NativeCamera *camera,MtxF *output) {
    f32 near=camera->near_clip,far=camera->far_clip;
    if(!isfinite(near) || !isfinite(far) || !isfinite(camera->cotangent) || !isfinite(camera->aspect) || camera->aspect<=0 || camera->cotangent<=0)return 0;
    if(near<1)near=1;if(far<near+100)far=near+100;if(!(far>near))return 0;
    f32 depth=(2*near*far/(near-far))*0.5f;
    if(depth>32767 || depth<-32767){depth=depth>32767 ? 32767 : -32767;near=(-(depth/0.5f)*far)/(2*far-depth/0.5f);}
    MtxF matrix;func_800F274C(&matrix);matrix.m[0][0]=camera->cotangent/camera->aspect;matrix.m[1][1]=camera->cotangent;
    matrix.m[2][2]=(near+far)/(near-far);matrix.m[2][3]=-1;matrix.m[3][2]=2*near*far/(near-far);matrix.m[3][3]=0;
    for(int i=0;i<4;++i)for(int j=0;j<4;++j){matrix.m[i][j]*=0.5f;if(!isfinite(matrix.m[i][j]))return 0;}
    u16 norm=near+far<=2 ? 0xFFFF : (u32)(131072.0f/(near+far));if(!norm)norm=1;
    *output=matrix;return norm;
}
