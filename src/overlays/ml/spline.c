#include "common.h"

void mlspline_entrypoint_0(f32 t, s32 arg1, f32 points[2][3], f32 dst[3]) {
    int i;
    for (i = 0; i < 3; i++) {
        f32 start = points[0][i];
        f32 end = points[1][i];
        dst[i] = start + (end - start) * t;
    }
}

void mlspline_entrypoint_1(f32 arg0, s32 arg1, u8 *arg2, f32 *arg3) {
    f32 temp_f0;
    register f32 temp_f2;
    register f32 temp_f4;
    register f32 temp_f6;
    register f32 temp_f8;
    temp_f0 = *(f32 *)(arg2 + 0);
    temp_f2 = *(f32 *)(arg2 + 4);
    temp_f4 = temp_f2 - temp_f0;
    temp_f6 = temp_f4 * arg0;
    temp_f0 = (*(f32 *)((s8 *)(arg2) + (0)));
    *arg3 = (((*(f32 *)((s8 *)(arg2) + (4))) - temp_f0) * arg0) + temp_f0;
}

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
