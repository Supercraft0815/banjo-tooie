#include "native_skinning.h"
#include "native_vertex_cache.h"
#include <math.h>
static u8 normal_byte(f32 value) {
    value*=127.0f;
    if(!isfinite(value) || value < -2147483648.0f || value >= 2147483648.0f)return 0;
    return (u8)(s32)value;
}
/* The model loader validates and converts the binding records before use. */
void dbanim_entrypoint_0(u8 *binding,void *vertices,NativeBoneMatrices *matrices) {
    if(!binding || !vertices)return;
    Vtx *out=func_800B2190(vertices);s16 *entry=(s16 *)(binding+4);
    for(s32 group=0;group<((s16 *)binding)[1];++group) {
        MtxF *matrix=func_800ADE2C(matrices,entry[0]);if(!matrix)return;
        s16 *positions=func_80100480(4,entry[1]);
        func_80116568(matrix,entry+3,positions,entry[1]);
        s16 *index=entry+3+entry[1]*3;
        if(*(s16 *)binding)index+=entry[2]*2;
        while(*index>=-1) {
            if(*index==-1)positions+=3;
            else for(int axis=0;axis<3;++axis)out[*index].v.ob[axis]=positions[axis];
            ++index;
        }
        entry=index+1;
    }
}
void dbanim_entrypoint_1(u8 *binding,void *vertices,NativeBoneMatrices *matrices,u8 *normals) {
    if(!binding || !vertices || !normals || !*(s16 *)binding)return;
    Vtx *out=func_800B2190(vertices);s16 *entry=(s16 *)(binding+4);
    for(s32 group=0;group<((s16 *)binding)[1];++group) {
        MtxF *matrix=func_800ADE2C(matrices,entry[0]);if(!matrix)return;
        s16 *positions=func_80100480(4,entry[1]),*index=entry+3+entry[1]*3;
        f32 *transformed_normals=func_80100480(2,entry[2]);
        func_80116568(matrix,entry+3,positions,entry[1]);
        func_801163B0((s8 *)index,matrix,transformed_normals,entry[2]);index+=entry[2]*2;
        while(*index>=-1) {
            if(*index==-1)positions+=3;
            else {
                for(int axis=0;axis<3;++axis) {
                    out[*index].v.ob[axis]=positions[axis];
                    normals[*index*4+axis]=normal_byte(transformed_normals[axis]);
                }
                transformed_normals+=3;
            }
            ++index;
        }
        entry=index+1;
    }
}
