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

/* extern */

void func_80800050_chbanjocurrent(u16 *arg0, f32 *arg1, f32 arg2[][2], s32 *arg3) {
    s32 func_800B2840(s32);
    s32 func_800BEB28(s32);
    void func_800EE88C(f32 *, s16 *);
    f32 var_f0;
    f32 var_f2;
    s32 *var_s5;
    s32 temp_s6;
    s32 temp_v0;
    s32 var_a0;
    s32 var_s0;
    f32 *var_s4;
    u16 *var_s3;
    s16 *temp_s2;
    f32 (*var_s1)[2];

    temp_v0 = func_800BEB28(1);
    var_a0 = temp_v0;
    if (temp_v0 == 0) {
        var_a0 = func_800BEB28(0);
    }
    temp_s6 = func_800B2840(var_a0) + 0x18;
    for (var_s0 = 0, var_s3 = arg0, var_s4 = arg1, var_s1 = arg2, var_s5 = arg3; var_s0 != 3; var_s0++) {
        temp_s2 = (s16 *)(*var_s3 * 0x10 + temp_s6);
        func_800EE88C(var_s4, temp_s2);
        var_s1[0][0] = temp_s2[4];
        var_s1[0][1] = temp_s2[5];
        *var_s5 = var_s0;
        var_s3++;
        var_s4 += 3;
        var_s1++;
        var_s5++;
    }
    if (arg2[arg3[2]][0] <= arg2[arg3[1]][0]) {
        func_80800034_chbanjocurrent(arg3);
    }
    if (arg2[arg3[2]][0] <= arg2[arg3[1]][0]) {
        func_80800034_chbanjocurrent(arg3);
    }
}

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
