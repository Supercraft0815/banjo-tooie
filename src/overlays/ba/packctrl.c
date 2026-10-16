#include "common.h"

s32 bapackctrl_entrypoint_0() 
{
    return 0x20;
}

void func_80800008_bapackctrl(u8 *arg0) {
    s32 bapackctrl_entrypoint_1(u8 *);
    void func_800984F0(u8 *, f32 *);
    void func_800EFA4C(f32 *, f32, f32, f32);
    f32 sp1C[3];

    if (bapackctrl_entrypoint_1(arg0)) {
        func_800EFA4C(sp1C, 1.7f, 1.7f, 2.6f);
    } else {
        func_800EFA4C(sp1C, 1.0f, 1.0f, 1.0f);
    }
    func_800984F0(arg0, sp1C);
}

/* extern */

s32 bapackctrl_entrypoint_1(u8 *arg0) {
    s32 func_8009EA58();
    return func_8009EA58();
}

void bapackctrl_entrypoint_2(s32 arg0)
{
    bapackctrl_entrypoint_5(arg0,0);
}

void bapackctrl_entrypoint_3(s32 arg0) {
    void func_80800008_bapackctrl(u8 *);
    f32 temp_f0;
    s32 temp_v0;

    temp_v0 = *(s32 *) (arg0 + 0xD8);
    temp_f0 = *(f32 *) (temp_v0 + 0xC);
    *(f32 *) (temp_v0 + 8) = temp_f0;
    *(f32 *) (*(s32 *) (arg0 + 0xD8) + 4) = temp_f0;
    *(f32 *) (*(s32 *) (arg0 + 0xD8) + 0) = temp_f0;
    func_800EFD24(*(s32 *) (arg0 + 0xD8) + 0x10);
    func_80800008_bapackctrl(arg0);
    *(s8 *) (*(s32 *) (arg0 + 0xD8) + 0x1C) = 0;
    bapackctrl_entrypoint_5(arg0, 1);
}

/* extern */

void bapackctrl_entrypoint_4(s32 arg0, s32 arg1) {
    s32 func_8009EADC(s32);
    void func_80800008_bapackctrl(u8 *);
    func_8009EADC(arg1);
    func_80800008_bapackctrl(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/packctrl/bapackctrl_entrypoint_5.s")
