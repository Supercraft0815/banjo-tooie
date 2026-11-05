#include "native_skinning.h"
#include <math.h>
void func_800D9470(f32 *,f32 *,f32 *);

void func_800AE820(BoneTransformList *pose,NativeSkeleton *skeleton,MtxF *matrices,Unkfunc_800E0960_1 *expression) {
    /* The original reuses each output matrix for its world quaternion and scale. */
    for(int i=0;i<skeleton->count;++i) {
        NativeBone *bone=&skeleton->bones[i];BoneTransform local=pose->ptr[bone->pose_index];
        f32 identity[4]={0,0,0,1},unit[3]={1,1,1};
        f32 *parent_q=bone->parent<0 ? identity : matrices[bone->parent].m[0];
        f32 *parent_scale=bone->parent<0 ? unit : matrices[bone->parent].m[1];
        int masked=expression && ((u32)expression->unk10[bone->pose_index>>5]&(1u<<(bone->pose_index&31)));
        if(masked && expression->unk8)func_800E0CB4(expression,bone->pose_index,local.unk0);
        if(masked && expression->unk9)func_800E0E94(expression,bone->pose_index,local.scale);
        if(local.unk0[0]==0 && local.unk0[1]==0 && local.unk0[2]==0 && local.unk0[3]==1)
            for(int j=0;j<4;++j)matrices[i].m[0][j]=parent_q[j];
        else func_800D9470(matrices[i].m[0],parent_q,local.unk0);
        for(int j=0;j<3;++j)matrices[i].m[1][j]=parent_scale[j]*local.scale[j];
    }
    for(int i=0;i<skeleton->count;++i) {
        MtxF *m=&matrices[i];f32 x=m->m[0][0],y=m->m[0][1],z=m->m[0][2],w=m->m[0][3];
        f32 sx=m->m[1][0],sy=m->m[1][1],sz=m->m[1][2];
        f32 xx=x*(x+x),xy=x*(y+y),xz=x*(z+z),yy=y*(y+y),yz=y*(z+z),zz=z*(z+z);
        f32 wx=w*(x+x),wy=w*(y+y),wz=w*(z+z);
        m->m[0][0]=((1-yy)-zz)*sx;m->m[0][1]=(xy+wz)*sx;m->m[0][2]=(xz-wy)*sx;m->m[0][3]=0;
        m->m[1][0]=(xy-wz)*sy;m->m[1][1]=((1-xx)-zz)*sy;m->m[1][2]=(yz+wx)*sy;m->m[1][3]=0;
        m->m[2][0]=(xz+wy)*sz;m->m[2][1]=(yz-wx)*sz;m->m[2][2]=((1-xx)-yy)*sz;m->m[2][3]=0;m->m[3][3]=1;
    }
    MtxF identity={.m={{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}}};
    for(int i=0;i<skeleton->count;++i) {
        NativeBone *bone=&skeleton->bones[i];MtxF *m=&matrices[i],*parent=bone->parent<0 ? &identity : &matrices[bone->parent];
        f32 translation[3];for(int j=0;j<3;++j)translation[j]=pose->ptr[bone->pose_index].unk1C[j];
        if(expression && expression->unkA && ((u32)expression->unk10[bone->pose_index>>5]&(1u<<(bone->pose_index&31))))
            func_800E0FE8(expression,bone->pose_index,translation);
        for(int j=0;j<3;++j)translation[j]=translation[j]*skeleton->translation_scale+bone->pivot[j];
        for(int axis=0;axis<3;++axis) {
            f32 value=parent->m[3][axis];
            for(int j=0;j<3;++j)value+=parent->m[j][axis]*translation[j];
            for(int j=0;j<3;++j)value-=m->m[j][axis]*bone->pivot[j];
            m->m[3][axis]=value;
        }
    }
}
void func_80116684(const MtxF *input,Mtx *output,s32 count) {
    for(int i=0;i<count;++i) {
        u32 fixed[16],words[16];
        for(int row=0;row<4;++row)for(int col=0;col<4;++col) {
            f32 value=input[i].m[row][col]*65536.0f;
            fixed[row*4+col]=col==3 ? (row==3 ? 65536 : 0) :
                (!isfinite(value) || value < -2147483648.0f || value>=2147483648.0f) ? 0x80000000u : (u32)(s32)nearbyintf(value);
        }
        for(int j=0;j<8;++j) {
            words[j]=(fixed[j*2]&0xFFFF0000u)|(fixed[j*2+1]>>16);
            words[j+8]=(fixed[j*2]<<16)|(fixed[j*2+1]&0xFFFFu);
        }
        /* Mtx is a packet of N64 words; halfword order must survive little-endian hosts. */
        for(int j=0;j<16;++j)((u32 *)&output[i])[j]=words[j];
    }
}
