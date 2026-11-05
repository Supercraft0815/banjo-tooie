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
