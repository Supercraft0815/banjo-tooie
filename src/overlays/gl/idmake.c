#include "common.h"

s32 func_80800000_glidmake(s32 arg0) {
    int func_800EEEA8(f32 vec[3]);
    s32 var_v1;
    f32 *vec;

    vec = (f32 *) (arg0 + 8);
    arg0 = (s32) vec;
    if (func_800EEEA8(vec) != 0) {
        var_v1 = 0;
    } else {
        var_v1 = (s32) vec;
    }
    return var_v1;
}

void glidmake_entrypoint_0(void *model, s32 mesh_id, s16 dst[3]) {
    void glidmake_entrypoint_2(void *, s32, s16 *, s16 *);
    s16 min[3];
    s16 max[3];
    glidmake_entrypoint_2(model, mesh_id, min, max);
    dst[0] = (min[0] + max[0]) / 2;
    dst[1] = (min[1] + max[1]) / 2;
    dst[2] = (min[2] + max[2]) / 2;
}

/* extern */

void glidmake_entrypoint_1(s32 *arg0) {
    s32 func_800B274C(s32);
    s32 func_800D674C(s32);
    func_800B274C(func_800D674C(*arg0));
}

void glidmake_entrypoint_2(void *arg0, s32 arg1, s16 *arg2, s16 *arg3) {
    void *_dbid_entrypoint_2(s32, s32);
    void *func_800B2190(void *);
    s32 func_800B274C(s32);
    s32 func_800D674C(s32);
    void func_800EFD4C(s16 *);
    void func_800EF0B4(s16 *, f32 *);
    u32 index;
    u32 end;
    s16 *mesh;
    u8 *vertices;
    s16 *vertex;
    s32 i;
    f32 *scale;
    s32 asset;

    func_800EFD4C(arg2);
    func_800EFD4C(arg3);
    asset = func_800D674C(*(s32 *)arg0);
    mesh = _dbid_entrypoint_2(func_800B274C(asset), arg1);
    if (mesh != NULL) {
        vertices = func_800B2190(*(void **)((u8 *)arg0 + 0x14));
        index = (u32)mesh + 4;
        end = (u32)mesh + mesh[1] * 2 + 4;
        for (; index < end; index += 2) {
            vertex = (s16 *)(vertices + *(s16 *)index * 0x10);
            for (i = 0; i < 3; i++) {
                if (mesh == (s16 *)(index - 4)) {
                    arg2[i] = arg3[i] = vertex[i];
                } else {
                    arg2[i] = vertex[i] < arg2[i] ? vertex[i] : arg2[i];
                    arg3[i] = arg3[i] < vertex[i] ? vertex[i] : arg3[i];
                }
            }
        }
        scale = (f32 *)func_80800000_glidmake((s32)arg0);
        if (scale != NULL) {
            func_800EF0B4(arg2, scale);
            func_800EF0B4(arg3, scale);
        }
    }
}

/* extern */

s16 glidmake_entrypoint_3(s32 *arg0, s32 arg1) {
    void *_dbid_entrypoint_2(s32, s32);
    s32 func_800B274C(s32);
    s32 func_800D674C(s32);
    s16 var_v1;
    void *temp_v0;

    temp_v0 = _dbid_entrypoint_2(func_800B274C(func_800D674C(*arg0)), arg1);
    if (temp_v0 != NULL) {
        var_v1 = (*(s16 *)((s8 *)(temp_v0) + (2)));
    } else {
        var_v1 = 0;
    }
    return var_v1;
}

void glidmake_entrypoint_4(void* arg0) 
{
    heap_free(arg0);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/idmake/glidmake_entrypoint_5.s")
