#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/bounce/subaddiebounce_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/bounce/subaddiebounce_entrypoint_1.s")

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
