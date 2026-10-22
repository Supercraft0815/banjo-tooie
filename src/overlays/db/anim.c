#include "common.h"

void dbanim_entrypoint_0(u8 *arg0, void *arg1, s32 arg2) {
    s32 func_800ADE2C(s32, s32);
    void *func_800B2190(void *);
    u32 func_800B2344(void *);
    void *func_80100480(s32, s32);
    s32 func_80116568(s32, void *, void *, s32);
    s16 *var_a0;
    s16 var_v1;
    s32 var_s5;
    u8 *temp_s3;
    s16 *temp_s4;
    u8 *temp_v0;
    u8 *var_s0;
    u8 *var_s2;

    temp_s3 = func_800B2190(arg1);
    var_s2 = arg0 + 4;
    var_s5 = 0;
    if (*(s16 *)(arg0 + 2) > 0) {
        do {
            var_s0 = func_80100480(4, *(s16 *)(var_s2 + 2));
            temp_s4 = (s16 *)(var_s2 + 6);
            func_80116568(func_800ADE2C(arg2, *(s16 *)var_s2), temp_s4, var_s0, *(s16 *)(var_s2 + 2));
            var_a0 = temp_s4;
            var_a0 += *(s16 *)(var_s2 + 2) * 3;
            if (*(s16 *)arg0 != 0) {
                var_a0 += *(s16 *)(var_s2 + 4) * 2;
            }
            var_v1 = *var_a0;
            if (var_v1 >= -1) {
                do {
                    if (0xFFFFFFFFU == (u32)var_v1) {
                        var_s0 += 6;
                    } else {
                        temp_v0 = var_v1 * 0x10 + temp_s3;
                        *(s16 *)(temp_v0 + 0) = *(s16 *)(var_s0 + 0);
                        *(s16 *)(temp_v0 + 2) = *(s16 *)(var_s0 + 2);
                        *(s16 *)(temp_v0 + 4) = *(s16 *)(var_s0 + 4);
                    }
                    var_v1 = var_a0[1];
                    var_a0++;
                } while (var_v1 >= -1);
            }
            var_s5 += 1;
            var_s2 = (u8 *)(var_a0 + 1);
        } while (var_s5 < *(s16 *)(arg0 + 2));
    }
    osWritebackDCache(temp_s3, func_800B2344(arg1) * 0x10);
}

void dbanim_entrypoint_1(u8 *arg0, void *arg1, s32 arg2, u8 *arg3) {
    s32 func_800ADE2C(s32, s32);
    void *func_800B2190(void *);
    u32 func_800B2344(void *);
    void *func_80100480(s32, s32);
    s32 func_80116568(s32, void *, void *, s32);
    s32 func_801163B0(void *, s32, void *, s32);
    s16 *indices;
    s16 index;
    u32 count;
    s32 i;
    s16 *positions;
    u8 *vertices;
    u8 *vertex;
    u8 *normal;
    u8 *outNormals;
    u8 *outPositions;
    u8 *entry;

    vertices = func_800B2190(arg1);
    i = 0;
    entry = arg0 + 4;
    if (*(s16 *)(arg0 + 2) > 0) {
        do {
            outPositions = func_80100480(4, *(s16 *)(entry + 2));
            positions = (s16 *)(entry + 6);
            func_80116568(func_800ADE2C(arg2, *(s16 *)entry), positions, outPositions, *(s16 *)(entry + 2));
            indices = positions;
            indices += *(s16 *)(entry + 2) * 3;
            outNormals = func_80100480(2, *(s16 *)(entry + 4));
            func_801163B0(indices, func_800ADE2C(arg2, *(s16 *)entry), outNormals, *(s16 *)(entry + 4));
            indices += *(s16 *)(entry + 4) * 2;
            index = *indices;
            if (index >= -1) {
                do {
                    if (0xFFFFFFFFU == (u32)index) {
                        outPositions += 6;
                    } else {
                        vertex = index * 0x10 + vertices;
                        *(s16 *)(vertex + 0) = *(s16 *)(outPositions + 0);
                        outNormals += 12;
                        *(s16 *)(vertex + 2) = *(s16 *)(outPositions + 2);
                        *(s16 *)(vertex + 4) = *(s16 *)(outPositions + 4);
                        normal = *indices * 4 + arg3;
                        normal[0] = (s32)(*(f32 *)(outNormals - 12) * 127.0f);
                        normal[1] = (s32)(*(f32 *)(outNormals - 8) * 127.0f);
                        normal[2] = (s32)(*(f32 *)(outNormals - 4) * 127.0f);
                    }
                    index = indices[1];
                    indices++;
                } while (index >= -1);
            }
            i++;
            entry = (u8 *)(indices + 1);
        } while (i < *(s16 *)(arg0 + 2));
    }
    count = func_800B2344(arg1);
    osWritebackDCache(vertices, count * 0x10);
    osWritebackDCache(arg3, count * 4);
}
