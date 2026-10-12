#include "core2/1ECB0F0.h"

/* extern */

void func_800F1800(void) {
    f32 func_80013AAC();
    s32 mlAbsF(f32);
    mlAbsF(func_80013AAC());
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECB0F0/func_800F1828.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECB0F0/func_800F1884.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECB0F0/func_800F18FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECB0F0/func_800F1988.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECB0F0/func_800F1A88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECB0F0/func_800F1AFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECB0F0/func_800F1B78.s")

f32 func_800F1C98(f32 *arg0, f32 *arg1) {
    void func_800EE97C(f32 dst[3], f32 a[3], f32 b[3]);
    f32 func_800EEF94(f32*);
    f32 sp2C;
    f32 sp28;
    f32 sp1C[3];

    sp2C = func_800EEF94(arg0);
    sp28 = func_800EEF94(arg1);
    func_800EE97C(sp1C, arg0, arg1);
    return func_800EEF94(sp1C) / (sp2C * sp28);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECB0F0/func_800F1CF0.s")

f32 func_800F1DCC(f32 arg0, f32 arg1) {
    f32 func_80013728(f32);
    return func_80013728(arg0 - arg1);
}

/* extern */

f32 func_800F1DF4(f32 *arg0, f32 *arg1) {
    f32 func_80013B7C(f32, f32);
    return ((f32)(func_80013B7C((*(f32 *)((s8 *)(arg1) + (0))) - (*(f32 *)((s8 *)(arg0) + (0))), arg1[2] - arg0[2])));
}

/* extern */

void func_800F1E28(void *arg0, void *arg1) {
    f32 func_80013B7C(f32, f32);
    func_80013B7C((f32) ((*(s16 *)((s8 *)(arg1) + (0))) - (*(s16 *)((s8 *)(arg0) + (0)))), (f32) ((*(s16 *)((s8 *)(arg1) + (4))) - (*(s16 *)((s8 *)(arg0) + (4)))));
}

s32 func_800F1E6C(f32 *arg0, f32 *arg1, f32 *target_yaw) {
    void func_800EFB24(void *arg0, void *arg1, void *arg2);
    f32 sp1C[3];

    func_800EFB24(sp1C, arg1, arg0);
    return func_800F1EA4(sp1C, target_yaw);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECB0F0/func_800F1EA4.s")

void func_800F1F0C(f32 *arg0, f32 *arg1, f32 arg2) {
    func_800F1DCC(func_800F1DF4(arg0, arg1), arg2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECB0F0/func_800F1F38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECB0F0/func_800F1FF0.s")

/* extern */

void func_800F2094(f32 arg0, f32 arg1) {
    s32 mlAbsF(f32);
    mlAbsF(func_800F1DCC(arg0, arg1));
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECB0F0/func_800F20BC.s")
