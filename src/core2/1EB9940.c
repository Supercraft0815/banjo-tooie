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

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EB9940/func_800E0170.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EB9940/func_800E02F8.s")

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
