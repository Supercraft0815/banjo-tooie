#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ml/wave/mlwave_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ml/wave/mlwave_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ml/wave/mlwave_entrypoint_2.s")

void mlwave_entrypoint_3(void *arg0, f32 arg1, f32 arg2) {
    (*(f32 *)((s8 *)(arg0) + (0x10))) = arg1;
    (*(f32 *)((s8 *)(arg0) + (0x14))) = arg2;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ml/wave/mlwave_entrypoint_4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ml/wave/mlwave_entrypoint_5.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ml/wave/mlwave_entrypoint_6.s")

void mlwave_entrypoint_7(void *arg0, f32 arg1) {
    (*(f32 *)((s8 *)(arg0) + (0x18))) = arg1;
    (*(f32 *)((s8 *)(arg0) + (0))) = (f32) ((*(f32 *)((s8 *)(arg0) + (8))) * arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ml/wave/mlwave_entrypoint_8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ml/wave/mlwave_entrypoint_9.s")
