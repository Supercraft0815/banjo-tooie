#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ml/wave/mlwave_entrypoint_0.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ml/wave/mlwave_entrypoint_2.s")

void mlwave_entrypoint_3(void *arg0, f32 arg1, f32 arg2) {
    (*(f32 *)((s8 *)(arg0) + (0x10))) = arg1;
    (*(f32 *)((s8 *)(arg0) + (0x14))) = arg2;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ml/wave/mlwave_entrypoint_4.s")

/* extern */

void mlwave_entrypoint_5(s32 arg0, f32 arg1, f32 arg2) { void mlwave_entrypoint_4(s32, f32, f32, f32); mlwave_entrypoint_4(arg0, 0.0f, arg1, arg2); }

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ml/wave/mlwave_entrypoint_6.s")

void mlwave_entrypoint_7(void *arg0, f32 arg1) {
    (*(f32 *)((s8 *)(arg0) + (0x18))) = arg1;
    (*(f32 *)((s8 *)(arg0) + (0))) = (f32) ((*(f32 *)((s8 *)(arg0) + (8))) * arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ml/wave/mlwave_entrypoint_8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ml/wave/mlwave_entrypoint_9.s")
