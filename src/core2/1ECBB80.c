#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECBB80/func_800F2290.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECBB80/func_800F22B4.s")

void func_800F22EC(void *arg0) {
    f32 temp_f0;
    f32 temp_f2;

    temp_f0 = (*(f32 *)((s8 *)(arg0) + (4)));
    temp_f2 = (*(f32 *)((s8 *)(arg0) + (0)));
    sqrtf((temp_f0 * temp_f0) + (temp_f2 * temp_f2));
}

f32 func_800F2320(void *arg0) {
    f32 mlAbsF(f32);
    extern f32 D_80125EE0;
    f32 sp1C;
    f32 temp_f0;
    f32 var_f12;

    sp1C = mlAbsF((*(f32 *)((s8 *)(arg0) + (0))));
    temp_f0 = mlAbsF((*(f32 *)((s8 *)(arg0) + (4))));
    if (sp1C < temp_f0) {
        var_f12 = sp1C;
    } else {
        var_f12 = temp_f0;
    }
    return (sp1C + temp_f0) - (var_f12 * D_80125EE0);
}

void func_800F2388(void *arg0, void *arg1, void *arg2) {
    (*(f32 *)((s8 *)(arg0) + (0))) = (f32) ((*(f32 *)((s8 *)(arg1) + (0))) - (*(f32 *)((s8 *)(arg2) + (0))));
    (*(f32 *)((s8 *)(arg0) + (4))) = (f32) ((*(f32 *)((s8 *)(arg1) + (4))) - (*(f32 *)((s8 *)(arg2) + (4))));
}

void func_800F23AC(void *arg0, void *arg1) {
    (*(f32 *)((s8 *)(arg0) + (0))) = (f32) (*(f32 *)((s8 *)(arg1) + (4)));
    (*(f32 *)((s8 *)(arg0) + (4))) = (f32) -(*(f32 *)((s8 *)(arg1) + (0)));
}
