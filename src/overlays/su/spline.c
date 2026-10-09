#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/spline/suspline_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/spline/func_80800074_suspline.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/spline/func_808000B4_suspline.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/spline/suspline_entrypoint_1.s")

s32 suspline_entrypoint_2(void *arg0, f32 arg1) {
    if (((*(f32 *)((s8 *)(arg0) + (0x5C))) <= arg1) && (arg1 < (*(f32 *)((s8 *)(arg0) + (0x58))))) {
        return 1;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/spline/suspline_entrypoint_3.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/spline/suspline_entrypoint_4.s")

/* extern */

void suspline_entrypoint_5(s32 arg0) {
    s32 func_800EE7F8(s32);
    func_800EE7F8(arg0 + 0x3C);
}

f32 suspline_entrypoint_6(f32 *arg0) {
    return arg0[22];
}

u32 suspline_entrypoint_7(u8 *arg0) {
    return arg0[139];
}

void suspline_entrypoint_8(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)arg0 + 88) = arg1;
}

void suspline_entrypoint_9(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)arg0 + 92) = arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/spline/suspline_entrypoint_10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/spline/suspline_entrypoint_11.s")

void suspline_entrypoint_12(void *arg0, s8 arg1) {
    (*(s8 *)((s8 *)(arg0) + (0x8A))) = arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/spline/func_80800224_suspline.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/spline/suspline_entrypoint_13.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/spline/suspline_entrypoint_14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/spline/suspline_entrypoint_15.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/spline/suspline_entrypoint_16.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/spline/suspline_entrypoint_17.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/spline/func_80800C8C_suspline.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/spline/suspline_entrypoint_18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/spline/suspline_entrypoint_19.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/spline/suspline_entrypoint_20.s")
