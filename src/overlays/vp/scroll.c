#include "common.h"
#include "core1/heap.h"
/* extern */

typedef struct { f32 unk0; s16 unk4; u8 pad6[0x2]; f32 unk8; s32 unkC; } Objscroll_vpscroll_entrypoint_0_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */ typedef struct { u8 pad0[0x14]; s32 unk14; } Objscroll_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */ typedef struct { u8 pad0[0x2]; u16 unk2; } Objscroll_vpscroll_entrypoint_0_var_v1; /* offsets.py genstruct: fields from raw offsets on var_v1; rename once understood */ u8 *vpscroll_entrypoint_0(u8 *arg0, u8 *arg1) {
    u8 *temp_a0;
    u8 *temp_a1;
    u8 *temp_v0;
    u8 *var_v1;
    temp_v0 = heap_alloc(((((Objscroll_arg0 *)arg0)->unk14) * 2) + 0x10);
    temp_a1 = ((((Objscroll_arg0 *)arg0)->unk14) * 4) + arg1 + 0x14;
    (((Objscroll_vpscroll_entrypoint_0_temp_v0 *)temp_v0)->unkC) = 0;
    (((Objscroll_vpscroll_entrypoint_0_temp_v0 *)temp_v0)->unk4) = 0;
    (((Objscroll_vpscroll_entrypoint_0_temp_v0 *)temp_v0)->unk0) = 0.0f;
    temp_a0 = arg1 + 0x14;
    var_v1 = temp_a0;
    (((Objscroll_vpscroll_entrypoint_0_temp_v0 *)temp_v0)->unk8) = (f32) (*(s32 *)arg1 % 100);
    if ((BtUIntPtr) temp_a0 < (BtUIntPtr) temp_a1) {
        do {
            if ((((Objscroll_vpscroll_entrypoint_0_var_v1 *)var_v1)->unk2) != 0) {
                (*(s16 *)((s8 *)((temp_v0 + ((((Objscroll_vpscroll_entrypoint_0_temp_v0 *)temp_v0)->unkC) * 2))) + (0x10))) = (s16) ((s32) (var_v1 - temp_a0) >> 2);
                (((Objscroll_vpscroll_entrypoint_0_temp_v0 *)temp_v0)->unkC) = (s32) ((((Objscroll_vpscroll_entrypoint_0_temp_v0 *)temp_v0)->unkC) + 1);
            }
            var_v1 += 4;
        } while ((BtUIntPtr) var_v1 < (BtUIntPtr) temp_a1);
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
