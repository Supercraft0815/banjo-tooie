#include "common.h"

/* extern */

u8 *vpscroll_entrypoint_0(u8 *arg0, u8 *arg1) {
    u8 *temp_a0;
    u8 *temp_a1;
    u8 *temp_v0;
    u8 *var_v1;
    temp_v0 = heap_alloc(((*(s32 *)((s8 *)(arg0) + (0x14))) * 2) + 0x10);
    temp_a1 = ((*(s32 *)((s8 *)(arg0) + (0x14))) * 4) + arg1 + 0x14;
    (*(s32 *)((s8 *)(temp_v0) + (0xC))) = 0;
    (*(s16 *)((s8 *)(temp_v0) + (4))) = 0;
    (*(f32 *)((s8 *)(temp_v0) + (0))) = 0.0f;
    temp_a0 = arg1 + 0x14;
    var_v1 = temp_a0;
    (*(f32 *)((s8 *)(temp_v0) + (8))) = (f32) (*(s32 *)arg1 % 100);
    if ((u32) temp_a0 < (u32) temp_a1) {
        do {
            if ((*(u16 *)((s8 *)(var_v1) + (2))) != 0) {
                (*(s16 *)((s8 *)((temp_v0 + ((*(s32 *)((s8 *)(temp_v0) + (0xC))) * 2))) + (0x10))) = (s16) ((s32) (var_v1 - temp_a0) >> 2);
                (*(s32 *)((s8 *)(temp_v0) + (0xC))) = (s32) ((*(s32 *)((s8 *)(temp_v0) + (0xC))) + 1);
            }
            var_v1 += 4;
        } while ((u32) var_v1 < (u32) temp_a1);
    }
    return temp_v0;
}
void vpscroll_entrypoint_1(void* arg0) 
{
    heap_free(arg0);
}
void vpscroll_entrypoint_2(f32 *arg0, u8 *arg1) {
    f32 func_800D8FF8(void);
    struct {
        u8 pad[3];
        u8 flag;
        u8 rest[16];
    } *meshes;
    f32 delta;
    s32 i;
    s16 *indices;
    struct { u8 pad[28]; s32 offset; } *model;


    delta = func_800D8FF8();
    arg0[0] += arg0[2] * 64.0f * delta;
    if ((s32)arg0[0] >= 0x2001) {
        arg0[0] -= 8192.0f;
    }
    ((s16 *)arg0)[2] = (s16)arg0[0];
    model = (void *)arg1;
    meshes = (void *)((u8 *)model + model->offset);
    indices = (s16 *)(arg0 + 4);
    for (i = 0; i < ((s32 *)arg0)[3]; i++) {
        meshes[indices[i]].flag = 1;
    }
}
void vpscroll_entrypoint_3(s16 *arg0, s32 arg1, u8 *arg2, s32 arg3) {
    s16 offset = arg0[2];
    u8 *end = arg2 + (arg3 << 4);
    if (arg2 < end) {
        do {
        *(s16 *)(arg2 + 10) += offset;
        arg2 += 16;
        } while (arg2 < end);
    }
}
