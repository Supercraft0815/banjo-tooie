#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ml/spline/mlspline_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ml/spline/mlspline_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ml/spline/mlspline_entrypoint_2.s")

void mlspline_entrypoint_3(f32 arg0, s32 arg1, void *arg2, f32 *arg3) {
    f32 temp_f0;
    f32 temp_f14;
    f32 temp_f2;

    temp_f0 = (*(f32 *)((s8 *)(arg2) + (0)));
    temp_f2 = (*(f32 *)((s8 *)(arg2) + (4)));
    temp_f14 = (*(f32 *)((s8 *)(arg2) + (8)));
    *arg3 = (((((temp_f14 + temp_f0) - (2.0f * temp_f2)) * (2.0f * arg0)) + (((4.0f * temp_f2) - (3.0f * temp_f0)) - temp_f14)) * arg0) + temp_f0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ml/spline/mlspline_entrypoint_4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ml/spline/mlspline_entrypoint_5.s")

/* extern */

void mlspline_entrypoint_6(f32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 func_800EFB24(s32, s32);
    func_800EFB24(arg3, arg2 + 0xC);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ml/spline/mlspline_entrypoint_7.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ml/spline/mlspline_entrypoint_8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ml/spline/mlspline_entrypoint_9.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ml/spline/mlspline_entrypoint_10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ml/spline/func_8080145C_mlspline.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ml/spline/func_80801488_mlspline.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ml/spline/mlspline_entrypoint_11.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ml/spline/mlspline_entrypoint_12.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ml/spline/mlspline_entrypoint_13.s")
