#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/deflect/sudeflect_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/deflect/sudeflect_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/deflect/sudeflect_entrypoint_2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/deflect/sudeflect_entrypoint_3.s")

void sudeflect_entrypoint_4(s32 arg0, f32 *arg1) {
    int func_800F7700(s32, s32, f32 *);
    s32 func_80800630_sudeflect(s32);
    extern struct {
        s32 entries[9];
        s32 count;
    } B_80801020_sudeflect;
    s32 temp_s0;
    s32 var_s1;

    for (var_s1 = 0; var_s1 < B_80801020_sudeflect.count; var_s1++) {
        temp_s0 = B_80801020_sudeflect.entries[var_s1 + 1];
        if (func_80800630_sudeflect(temp_s0) != 0) {
            func_800F7700(temp_s0, arg0, arg1);
        }
    }
}

/* extern */

s32 func_80800630_sudeflect(s32 arg0) {
    s32 func_800F52B8(s32, s32);
    s32 func_800F5410(s32);
    s32 func_800F6720();
    s32 temp_v0;

    if (func_800F6720() != 0) {
        return 1;
    }
    if (func_800F5410(arg0) == 0x11) {
        return 1;
    }
    temp_v0 = func_800F52B8(arg0, 0);
    if ((temp_v0 == 1) || (temp_v0 == 0xB)) {
        return 1;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/deflect/func_808006A4_sudeflect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/deflect/func_808007F4_sudeflect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/deflect/func_80800940_sudeflect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/deflect/func_80800A98_sudeflect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/deflect/func_80800BEC_sudeflect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/deflect/func_80800D14_sudeflect.s")

/* extern */

s32 func_80800E44_sudeflect(f32 *arg0, f32 arg1, f32 arg2, f32 arg3, f32 *arg4, f32 arg5) {
    int func_800F0064(f32 *, f32, f32 *);
    f32 temp_f0;

    temp_f0 = arg4[1] - arg0[1];
    if (arg1 < (temp_f0 - arg5)) {
        return 0;
    }
    if ((temp_f0 + arg5) < arg2) {
        return 0;
    }
    return func_800F0064(arg0, arg3 + arg5, arg4);
}

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
