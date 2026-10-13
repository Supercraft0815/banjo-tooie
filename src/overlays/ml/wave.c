#include "common.h"

void mlwave_entrypoint_0(void *arg0, f32 arg1, f32 arg2) {
    (*(f32 *)((s8 *)(arg0) + (0xC))) = arg2;
    (*(f32 *)((s8 *)(arg0) + (0x10))) = arg2;
    (*(f32 *)((s8 *)(arg0) + (8))) = arg1;
    (*(f32 *)((s8 *)(arg0) + (0))) = 0;
    (*(f32 *)((s8 *)(arg0) + (0x14))) = 100.0f;
    if (arg1 != 0.0f) {
        (*(f32 *)((s8 *)(arg0) + (4))) = (f32) (6.2831855f / arg1);
    } else {
        (*(f32 *)((s8 *)(arg0) + (4))) = 0;
    }
    (*(f32 *)((s8 *)(arg0) + (0x18))) = 0;
}

/* extern */

void mlwave_entrypoint_1(void *arg0) {
    f32 func_800D8FF8();
    f32 func_800F15F8(f32, f32, f32);
    f32 mlwave_entrypoint_6(void *);
    f32 sp24;
    f32 temp_f0;

    sp24 = func_800D8FF8();
    (*(f32 *)((s8 *)(arg0) + (0x18))) = mlwave_entrypoint_6(arg0);
    temp_f0 = func_800F15F8((*(f32 *)((s8 *)(arg0) + (0xC))), (*(f32 *)((s8 *)(arg0) + (0x10))), (*(f32 *)((s8 *)(arg0) + (0x14))) * sp24);
    (*(f32 *)((s8 *)(arg0) + (0xC))) = temp_f0;
    (*(f32 *)((s8 *)(arg0) + (0))) = (f32) ((*(f32 *)((s8 *)(arg0) + (0))) + (temp_f0 * sp24));
}

/* extern */

void mlwave_entrypoint_2(void *arg0, f32 arg1, f32 arg2) {
    f32 func_800DC178(f32, f32);
    f32 mlwave_entrypoint_6(void *);
    f32 temp_f0;
    temp_f0 = func_800DC178(arg1, arg2);
    (*(f32 *)((s8 *)(arg0) + (0))) = (f32) ((*(f32 *)((s8 *)(arg0) + (8))) * temp_f0);
    (*(f32 *)((s8 *)(arg0) + (0x18))) = mlwave_entrypoint_6(arg0);
}

void mlwave_entrypoint_3(void *arg0, f32 arg1, f32 arg2) {
    (*(f32 *)((s8 *)(arg0) + (0x10))) = arg1;
    (*(f32 *)((s8 *)(arg0) + (0x14))) = arg2;
}

/* extern */

void mlwave_entrypoint_4(void *arg0, f32 arg1, f32 arg2, f32 arg3) {
    f32 func_8001395C(f32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    func_800F10B4(func_8001395C((arg1 - *(f32 *)arg0) * *(f32 *)((s8 *)arg0 + 4)), -1.0f, 1.0f, arg2, arg3);
}

/* extern */

void mlwave_entrypoint_5(void *arg0, f32 arg1, f32 arg2) { void mlwave_entrypoint_4(void *, f32, f32, f32); mlwave_entrypoint_4(arg0, 0.0f, arg1, arg2); }

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ml/wave/mlwave_entrypoint_6.s")

void mlwave_entrypoint_7(void *arg0, f32 arg1) {
    (*(f32 *)((s8 *)(arg0) + (0x18))) = arg1;
    (*(f32 *)((s8 *)(arg0) + (0))) = (f32) ((*(f32 *)((s8 *)(arg0) + (8))) * arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ml/wave/mlwave_entrypoint_8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ml/wave/mlwave_entrypoint_9.s")
