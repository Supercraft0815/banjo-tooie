#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/deflect/sudeflect_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/deflect/sudeflect_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/deflect/sudeflect_entrypoint_2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/deflect/sudeflect_entrypoint_3.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/deflect/sudeflect_entrypoint_4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/deflect/func_80800630_sudeflect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/deflect/func_808006A4_sudeflect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/deflect/func_808007F4_sudeflect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/deflect/func_80800940_sudeflect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/deflect/func_80800A98_sudeflect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/deflect/func_80800BEC_sudeflect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/deflect/func_80800D14_sudeflect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/deflect/func_80800E44_sudeflect.s")

s32 func_80800ECC_sudeflect(f32 *arg0, f32 *arg1, f32 *arg2, f32 arg3) {
    void func_800EE7F8(f32 *, f32 *);
    f32 b;
    f32 a;
    f32 min[3];
    f32 max[3];
    s32 i;

    func_800EE7F8(min, arg2);
    func_800EE7F8(max, arg2);
    for (i = 0; i < 3; i++) {
        min[i] -= arg3;
        max[i] += arg3;
    }
    if (arg1[1] <= min[1] || max[1] <= arg0[1]) {
        return 0;
    }
    b = max[0] - arg0[0];
    a = min[0] - arg1[0];
    if (a >= 0.0f || b <= 0.0f) {
        return 0;
    }
    b = max[2] - arg0[2];
    a = min[2] - arg1[2];
    if (a >= 0.0f || b <= 0.0f) {
        return 0;
    }
    return 1;
}
