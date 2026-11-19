#include "native_skinning.h"
#include <math.h>

static s16 vertex_round(f32 value) {
    /* MIPS round.w.s uses nearest-even, then sh keeps the low sixteen bits. */
    if(!isfinite(value) || value < -2147483648.0f || value >= 2147483648.0f)return 0;
    f32 lower=floorf(value),fraction=value-lower;
    s32 result=(s32)lower;
    if(fraction>0.5f || (fraction==0.5f && (result&1)))++result;
    return (s16)(u16)result;
}
void func_80116568(const MtxF *matrix,const s16 *input,s16 *output,s32 count) {
    for(s32 i=0;i<count;++i,input+=3,output+=3) {
        f32 x=input[0],y=input[1],z=input[2];
        for(int axis=0;axis<3;++axis) {
            f32 value=x*matrix->m[0][axis];value+=matrix->m[3][axis];
            value+=y*matrix->m[1][axis];value+=z*matrix->m[2][axis];
            output[axis]=vertex_round(value);
        }
    }
}
void func_801163B0(const s8 *input,const MtxF *matrix,f32 *output,s32 count) {
    for(s32 i=0;i<count;++i,input+=4,output+=3) {
        f32 x=input[0]*(1.0f/127.0f),y=input[1]*(1.0f/127.0f),z=input[2]*(1.0f/127.0f);
        for(int axis=0;axis<3;++axis) {
            f32 value=y*matrix->m[1][axis];value+=x*matrix->m[0][axis];
            output[axis]=z*matrix->m[2][axis]+value;
        }
    }
}
/* 1EEFCA0.s func_8011649C: replaces the first component of each 3-vector by its dot product with v
   (runs at least once, like the asm's do-while). */
void func_8011649C(const f32 *v,f32 *vectors,s32 count) {
    do{vectors[0]=(vectors[0]*v[0]+vectors[1]*v[1])+vectors[2]*v[2];vectors+=3;}while(--count>0);
}
/* 1EEFCA0.s func_801164E0: s8 normals (stride 4) times D_80126634 into vectors, and their dot
   products with v into dots. */
extern const f32 D_80126634[];
void func_801164E0(const f32 *v,const s8 *normals,f32 *vectors,f32 *dots,s32 count) {
    do{
        f32 x=normals[0]*D_80126634[0],y=normals[1]*D_80126634[0],z=normals[2]*D_80126634[0];
        vectors[0]=x;vectors[1]=y;vectors[2]=z;*dots++=(x*v[0]+y*v[1])+z*v[2];
        normals+=4;vectors+=3;
    }while(--count>0);
}
