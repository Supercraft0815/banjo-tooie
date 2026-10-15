#include "common.h"

void func_80800000_chbanjocurrent()
{
    func_800F4C24(func_800F54E4());
}

OSThread *chbanjocurrent_entrypoint_0(void)
{
    extern u8 D_808007D0_chbanjocurrent[];

    return (OSThread *) D_808007D0_chbanjocurrent;
}

void func_80800034_chbanjocurrent(s32 *arg0) {
    s32 temp = arg0[1];
    arg0[1] = arg0[2];
    arg0[2] = arg0[0];
    arg0[0] = temp;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/banjocurrent/func_80800050_chbanjocurrent.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/banjocurrent/func_808001D0_chbanjocurrent.s")

OSThread *chbanjocurrent_entrypoint_1(void)
{
    extern u8 D_80800818_chbanjocurrent[];

    return (OSThread *) D_80800818_chbanjocurrent;
}

/* extern */

f32 func_80800514_chbanjocurrent(f32 *arg0, f32 *arg1, f32 arg2) {
    f32 func_800136D0(f32);
    f32 func_80013788();
    f32 func_800137D4(f32);
    f32 func_800EEF94(f32 *);
    f32 sp24;
    f32 sp20;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f12;

    temp_f0 = func_800EEF94(arg0);
    sp24 = temp_f0;
    sp20 = func_800137D4(func_800136D0((temp_f0 - arg2) * 0.015707964f)) * 20.0f;
    temp_f12 = func_80013788() * 20.0f * 0.015707964f;
    if (sp24 != 0.0f) {
        temp_f0_2 = temp_f12 / sp24;
        arg1[0] = arg0[0] * temp_f0_2;
        arg1[1] = arg0[2] * temp_f0_2;
    } else {
        arg1[0] = arg0[0] * temp_f12;
        arg1[1] = arg0[2] * temp_f12;
    }
    return sp20;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/banjocurrent/func_808005F4_chbanjocurrent.s")
