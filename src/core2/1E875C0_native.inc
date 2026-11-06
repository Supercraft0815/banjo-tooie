#include "native_skinning.h"
#include "memory.h"
#include "1E875C0_matrix.inc"
void func_800D9CE8(f32 *,f32 *);
void func_800F23D0(MtxF *,f32 *,f32 *);

void func_800F274C(MtxF *);
static NativeBoneMatrices *bones_resize(NativeBoneMatrices *list,s16 handle,s32 count) {
    if(list->capacity<count) {
        s32 size=sizeof(*list)+count*sizeof(MtxF);
        list=handle ? func_8001B710(handle,size) : heap_realloc(list,size);
        list->capacity=count;
    }
    list->count=count;return list;
}
void func_800ADCD0(NativeBoneMatrices **list,NativeSkeleton *skeleton) {
    *list=bones_resize(*list,0,skeleton->count);
    mlMtxIdent();for(int i=0;i<(*list)->count;++i)mlMtxGet(&(*list)->matrices[i]);
}
void func_800ADD80(s16 handle,NativeSkeleton *skeleton) {
    NativeBoneMatrices *list=bones_resize(func_800AE080(handle),handle,skeleton->count);
    mlMtxIdent();for(int i=0;i<list->count;++i)mlMtxGet(&list->matrices[i]);
}
MtxF *func_800ADE50(NativeBoneMatrices *list,NativeSkeleton *skeleton,s32 index) {
    if(list && list->count==skeleton->count)
        for(int i=0;i<list->count;++i)if(skeleton->bones[i].pose_index==index)return &list->matrices[i];
    return NULL;
}
void func_800ADEC4(NativeBoneMatrices *list,NativeSkeleton *skeleton,s32 index,MtxF *matrix) {
    if(list->count==skeleton->count)
        for(int i=0;i<list->count;++i)if(skeleton->bones[i].pose_index==index)list->matrices[i]=*matrix;
}
void func_800ADF5C(NativeBoneMatrices *list) {
    if(!list)return;
    if(list->expression)func_800E0A50(list->expression);
    heap_free(list);
}
NativeBoneMatrices *func_800ADF98(void) {
    NativeBoneMatrices *list=heap_alloc(sizeof(*list));
    list->count=list->capacity=0;list->expression=NULL;list->expression_handle=0;
    mlMtxIdent();mlMtxGet(&list->base);return list;
}
void func_800ADFE0(s16 handle) {
    if(!handle)return;
    NativeBoneMatrices *list=func_800AE080(handle);
    if(list->expression_handle)func_800E0A70(list->expression_handle);
    func_8001B754(handle);
}
s16 func_800AE020(void) {
    s16 handle=func_8001B668(0,sizeof(NativeBoneMatrices));if(!handle)return 0;
    NativeBoneMatrices *list=func_800AE080(handle);
    list->count=list->capacity=0;list->expression=NULL;list->expression_handle=0;
    mlMtxIdent();mlMtxGet(&list->base);return handle;
}
NativeBoneMatrices *func_800AE080(s16 handle) {return handle ? func_8001B798(handle) : NULL;}
s32 func_800AE0B8(NativeBoneMatrices *list) {return list ? list->count : 1;}
s32 func_800AE0D0(NativeBoneMatrices *list) {return list ? list->count : 0;}
s32 func_800AE0E8(s16 handle) {return func_800AE0B8(func_800AE080(handle));}
s32 func_800AE124(s16 handle) {return func_800AE0D0(func_800AE080(handle));}
void func_800AE160(NativeBoneMatrices **list,NativeSkeleton *skeleton,BoneTransformList *pose) {
    *list=bones_resize(*list,0,skeleton->count);
    func_800AE820(pose,skeleton,(*list)->matrices,(*list)->expression);
}
void func_800AE1E8(s16 handle,NativeSkeleton *skeleton,BoneTransformList *pose) {
    NativeBoneMatrices *list=bones_resize(func_800AE080(handle),handle,skeleton->count);
    func_800AE820(pose,skeleton,list->matrices,list->expression_handle ? func_800E0A28(list->expression_handle) : NULL);
}
static void bones_rotation(s16 handle,NativeSkeleton *skeleton,BoneTransformList *pose,int scale) {
    NativeBoneMatrices *list=bones_resize(func_800AE080(handle),handle,skeleton->count);
    MtxF identity;func_800F274C(&identity);
    for(int i=0;i<list->count;++i) {
        NativeBone *bone=&skeleton->bones[i];BoneTransform *transform=&pose->ptr[bone->pose_index];
        MtxF *parent=bone->parent<0 ? &identity : &list->matrices[bone->parent],*out=&list->matrices[i];
        if(bone->parent<0)mlMtxIdent();
        *out=*parent;
        f32 *q=transform->unk0;
        if(q[0]!=0 || q[1]!=0 || q[2]!=0 || q[3]!=1) {
            f32 rotation[9];func_800D9CE8(q,rotation);
            for(int row=0;row<3;++row)for(int col=0;col<3;++col)
                out->m[row][col]=(rotation[row*3]*parent->m[0][col]+rotation[row*3+1]*parent->m[1][col])+rotation[row*3+2]*parent->m[2][col];
        }
        if(scale)for(int row=0;row<3;++row)for(int col=0;col<3;++col)out->m[row][col]*=transform->scale[row];
        mlMtxSet(out);
    }
}
void func_800AE290(s16 handle,NativeSkeleton *skeleton,BoneTransformList *pose) {bones_rotation(handle,skeleton,pose,0);}
void func_800AE40C(s16 handle,NativeSkeleton *skeleton,BoneTransformList *pose) {bones_rotation(handle,skeleton,pose,1);}
void func_800AE598(NativeBoneMatrices *list,Mtx **output) {
    func_80116684(&list->base,*output,1);
    func_80116684(list->matrices,*output+1,list->count);*output+=list->count+1;
}
// defrag can move both blocks (the N64 heap in the ILP32 build); the caller stores the moved list.
NativeBoneMatrices *func_800AE5F0(NativeBoneMatrices *list) {
    if(list->expression) {
        Unkfunc_800E0960_1 *e=defrag(list->expression);  // func_800E0A98, keeping the moved address
        e->unk0=(Unkfunc_800E0960_2 *)&e[1];list->expression=e;
    }
    return defrag(list);
}
s32 func_800AE630(NativeBoneMatrices *list,NativeSkeleton *skeleton,s32 index,f32 *output) {
    if(list->count==skeleton->count)for(int i=0;i<list->count;++i)if(skeleton->bones[i].pose_index==index) {
        func_800F23D0(&list->matrices[i],output,skeleton->bones[i].pivot);return 1;
    }
    return 0;
}
Unkfunc_800E0960_1 *func_800AE6BC(NativeBoneMatrices *list) {
    return list->expression_handle ? func_800E0A28(list->expression_handle) : list->expression;
}
void func_800AE6FC(NativeBoneMatrices *list,s16 handle) {list->expression_handle=handle;}
s32 func_800AE708(NativeBoneMatrices *source,NativeSkeleton *from,NativeBoneMatrices **target,NativeSkeleton *to) {
    if(!source || !source->count || from->count<to->count || from->translation_scale!=to->translation_scale)return 0;
    func_800ADCD0(target,to);
    for(int i=0;i<to->count;++i) {
        MtxF *matrix=func_800ADE50(source,from,to->bones[i].pose_index);if(!matrix)return 0;
        (*target)->matrices[i]=*matrix;
    }
    return 1;
}
