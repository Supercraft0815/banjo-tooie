#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/bounce/subaddiebounce_entrypoint_0.s")

/* extern */

s32 subaddiebounce_entrypoint_1(u8 *arg0) {
    f32 func_800D8FF8(void);
    void func_800EF04C(f32 *, f32 *);
    void func_800EFA20(void *, void *, f32);
    f32 temp_f2;
    f32 sp28[3];
    f32 temp_f0;
    s32 var_v0;

    temp_f2 = func_800D8FF8();
    if (((*(f32 *)((s8 *)(arg0) + (0x1C))) < (*(f32 *)((s8 *)(arg0) + (8)))) || (var_v0 = 1, ((*(f32 *)((s8 *)(arg0) + (0x2C))) > 0.0f))) {
        func_800EFA20(sp28, arg0 + 0x28, temp_f2);
        func_800EF04C((f32 *)(arg0 + 4), sp28);
        temp_f0 = (*(f32 *)((s8 *)(arg0) + (0x1C)));
        if ((*(f32 *)((s8 *)(arg0) + (8))) < temp_f0) {
            (*(f32 *)((s8 *)(arg0) + (8))) = temp_f0;
            (*(f32 *)((s8 *)(arg0) + (0x28))) = 0.0f;
            (*(f32 *)((s8 *)(arg0) + (0x30))) = 0.0f;
            (*(f32 *)((s8 *)(arg0) + (0x2C))) = (f32) ((*(f32 *)((s8 *)(arg0) + (0x2C))) * -0.5f);
            return 1;
        }
        var_v0 = 0;
        (*(f32 *)((s8 *)(arg0) + (0x2C))) = (f32) (((*(f32 *)((s8 *)(arg0) + (0x34))) * temp_f2) + (*(f32 *)((s8 *)(arg0) + (0x2C))));
        /* Duplicate return node #5. Try simplifying control flow for better match */
        return var_v0;
    }
    return var_v0;
}

s32 subaddiebounce_entrypoint_2(f32 *arg0) {
    f32 func_800D8FF8(void);
    f32 dt;

    dt = func_800D8FF8();
    if (arg0[7] < arg0[2] || arg0[11] > 0.0f) {
        arg0[2] += arg0[11] * dt;
        if (arg0[2] < arg0[7]) {
            arg0[2] = arg0[7];
            arg0[11] *= -0.5f;
            return 1;
        } else {
            arg0[11] += arg0[13] * dt;
            return 0;
        }
    }
    return 1;
}
