#ifndef BT_NATIVE_SKINNING_H
#define BT_NATIVE_SKINNING_H
#include "native_model.h"
#include "core1/mlmtx.h"
#include "core2/1EB93C0.h"
#include "core2/1EBA250.h"
typedef struct {f32 pivot[3];s16 pose_index,parent;} NativeBone;
typedef struct {f32 translation_scale;s16 count,reserved;NativeBone bones[];} NativeSkeleton;
_Static_assert(sizeof(NativeBone)==16 && offsetof(NativeSkeleton,bones)==8,"skeleton layout");
typedef struct {
    s32 count,capacity;
    void *expression;
    s16 expression_handle;
    MtxF base;
    MtxF matrices[];
} NativeBoneMatrices;
MtxF *func_800ADE2C(NativeBoneMatrices *,s32);
void func_800ADCD0(NativeBoneMatrices **,NativeSkeleton *);
void func_800ADD80(s16,NativeSkeleton *);
MtxF *func_800ADE50(NativeBoneMatrices *,NativeSkeleton *,s32);
void func_800ADEC4(NativeBoneMatrices *,NativeSkeleton *,s32,MtxF *);
void func_800ADF5C(NativeBoneMatrices *);
NativeBoneMatrices *func_800ADF98(void);
void func_800ADFE0(s16);
s16 func_800AE020(void);
NativeBoneMatrices *func_800AE080(s16);
s32 func_800AE0B8(NativeBoneMatrices *);
s32 func_800AE0D0(NativeBoneMatrices *);
s32 func_800AE0E8(s16);
s32 func_800AE124(s16);
void func_800AE160(NativeBoneMatrices **,NativeSkeleton *,BoneTransformList *);
void func_800AE1E8(s16,NativeSkeleton *,BoneTransformList *);
void func_800AE290(s16,NativeSkeleton *,BoneTransformList *);
void func_800AE40C(s16,NativeSkeleton *,BoneTransformList *);
void func_800AE598(NativeBoneMatrices *,Mtx **);
void func_800AE5F0(NativeBoneMatrices *);
s32 func_800AE630(NativeBoneMatrices *,NativeSkeleton *,s32,f32 *);
Unkfunc_800E0960_1 *func_800AE6BC(NativeBoneMatrices *);
void func_800AE6FC(NativeBoneMatrices *,s16);
s32 func_800AE708(NativeBoneMatrices *,NativeSkeleton *,NativeBoneMatrices **,NativeSkeleton *);
void func_800AE820(BoneTransformList *,NativeSkeleton *,MtxF *,Unkfunc_800E0960_1 *);
void func_80116684(const MtxF *,Mtx *,s32);
void func_80116568(const MtxF *,const s16 *,s16 *,s32);
void func_801163B0(const s8 *,const MtxF *,f32 *,s32);
void _dbanim_entrypoint_0(u8 *,void *,NativeBoneMatrices *);
void _dbanim_entrypoint_1(u8 *,void *,NativeBoneMatrices *,u8 *);
#endif
