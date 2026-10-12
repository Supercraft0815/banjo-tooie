#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EB9940/func_800E0050.s")

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
