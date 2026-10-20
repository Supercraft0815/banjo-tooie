#include "common.h"

/* extern */

void func_800E0050(s16 *arg0, f32 arg1, s32 arg2, f32 *arg3) {
    struct Entry { u16 group : 12; u16 channel : 4; s16 count; };
    f32 func_800E0414(s16 *, f32);
    f32 func_800E04C0(u8 *, f32, s32);
    f32 temp_f0;
    s32 var_s0;
    s32 var_s2;
    s32 var_s3;
    struct Entry *var_s1;

    temp_f0 = func_800E0414(arg0, arg1);
    (*(f32 *)((s8 *)(arg3) + (8))) = 0.0f;
    (*(f32 *)((s8 *)(arg3) + (4))) = 0.0f;
    (*(f32 *)((s8 *)(arg3) + (0))) = 0.0f;
    (*(f32 *)((s8 *)(arg3) + (0x20))) = 0.0f;
    (*(f32 *)((s8 *)(arg3) + (0x1C))) = 0.0f;
    (*(f32 *)((s8 *)(arg3) + (0x18))) = 0.0f;
    (*(f32 *)((s8 *)(arg3) + (0x14))) = 1.0f;
    (*(f32 *)((s8 *)(arg3) + (0x10))) = 1.0f;
    (*(f32 *)((s8 *)(arg3) + (0xC))) = 1.0f;
    var_s3 = 0;
    var_s1 = (struct Entry *)((u8 *)arg0 + 8);
    var_s2 = 0;
    if ((*(s16 *)((s8 *)(arg0) + (4))) > 0) {
loop_1:
        var_s0 = var_s1->channel;
        if (arg2 != var_s1->group) {
            if (var_s3 != 0) {
                return;
            }
            goto block_7;
        }
        var_s3 = 1;
        if (var_s0 >= 9) {
            var_s0 -= 9;
        }
        arg3[var_s0] = func_800E04C0((u8 *)var_s1, temp_f0, 0);
block_7:
        var_s2 += 1;
        var_s1 = (struct Entry *)((u8 *)var_s1 + var_s1->count * 4 + 4);
        if (var_s2 >= (*(s16 *)((s8 *)(arg0) + (4)))) {

        } else {
            goto loop_1;
        }
    }
}

void func_800E0170(s16 *arg0, f32 arg1, s32 arg2, s32 arg3) {
    f32 func_800E0414(s16 *, f32);
    f32 func_800E04C0(u8 *, f32, s32);
    void func_800E084C(s32, f32 *, u32);
    s32 channel;
    u8 *element;
    u32 group;
    s32 i;
    s32 duration;
    f32 progress;
    s32 pad_before[1];
    f32 transform[3][3];
    s32 pad[2];

    progress = func_800E0414(arg0, arg1);
    if (arg2 != 0) {
        duration = arg0[1] - arg0[0];
    } else {
        duration = 0;
    }
    element = (u8 *)(arg0 + 4);
    group = 0;
    for (i = 0; i < arg0[2]; i++) {
        if (group != (u32)*(u16 *)element >> 4) {
            if (group != 0) {
                func_800E084C(arg3, transform[0], group);
            }
            group = (u32)*(u16 *)element >> 4;
            transform[0][0] = transform[0][1] = transform[0][2] = 0.0f;
            transform[1][0] = transform[1][1] = transform[1][2] = 1.0f;
            transform[2][0] = transform[2][1] = transform[2][2] = 0.0f;
        }
        channel = *(u16 *)element & 0xF;
        if (channel >= 9) {
            channel -= 9;
        }
        transform[0][channel] = func_800E04C0(element, progress, duration);
        element += *(s16 *)(element + 2) * 4 + 4;
    }
    func_800E084C(arg3, transform[0], group);
}

void func_800E02F8(s16 *arg0, f32 arg1, s32 arg2, s32 arg3, s32 arg4, f32 *arg5) {
    f32 func_800E0414(s16 *, f32);
    f32 func_800E04C0(u8 *, f32, s32);
    f32 temp_f20;
    u8 *var_s1;
    s32 var_fp;
    s32 var_s2;
    s32 var_s3;
    u16 temp_v0;
    u32 temp_v1;

    temp_f20 = func_800E0414(arg0, arg1);
    var_s3 = 0;
    if (arg2 != 0) {
        var_fp = arg0[1] - arg0[0];
    } else {
        var_fp = 0;
    }
    var_s1 = (u8 *)(arg0 + 4);
    var_s2 = 0;
    if (arg0[2] > 0) {
        do {
            temp_v0 = *(u16 *)var_s1;
            temp_v1 = (u32)temp_v0 >> 4;
            if (((s32)temp_v1 >= arg3) && (arg4 >= (s32)temp_v1) && ((temp_v0 & 0xF) == 7)) {
                arg5[var_s3] = func_800E04C0((u8 *)var_s1, temp_f20, var_fp);
                var_s3 += 1;
            }
            var_s2 += 1;
            var_s1 += *(s16 *)(var_s1 + 2) * 4 + 4;
        } while (var_s2 < arg0[2]);
    }
}

f32 func_800E0414(s16 *arg0, f32 arg1) {
    return (arg1 * (arg0[1] - arg0[0])) + arg0[0];
}

s32 func_800E0440(s16 *arg0) {
    return arg0[1];
}

s32 func_800E0448(s16 *arg0) {
    return arg0[0];
}

s32 func_800E0450(void *arg0) {
    return ((*(s16 *)((s8 *)(arg0) + (2))) - (*(s16 *)((s8 *)(arg0) + (0)))) + 1;
}

s32 func_800E0464(s16 *arg0) {
    return arg0[2];
}

f32 func_800E046C(void *arg0, s32 arg1) {
    extern f32 D_80125D70;
    s32 temp_v0;
    s16 temp_v1;

    temp_v0 = (*(s16 *)((s8 *)(arg0) + (2)));
    if (!(arg1 != temp_v0)) {
        return D_80125D70;
    }
    temp_v1 = (*(s16 *)((s8 *)(arg0) + (0)));
    return (f32) (arg1 - temp_v1) / (f32) (temp_v0 - temp_v1);
}

void func_800E04AC(void *arg0)
{
}
