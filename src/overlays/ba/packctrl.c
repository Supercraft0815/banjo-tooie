#include "common.h"

s32 bapackctrl_entrypoint_0() 
{
    return 0x20;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/packctrl/func_80800008_bapackctrl.s")

/* extern */

void bapackctrl_entrypoint_1(s32 arg0) {
    s32 func_8009EA58();
    func_8009EA58();
}

void bapackctrl_entrypoint_2(s32 arg0)
{
    bapackctrl_entrypoint_5(arg0,0);
}

void bapackctrl_entrypoint_3(s32 arg0) {
    s32 func_80800008_bapackctrl(s32);
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
    s32 func_80800008_bapackctrl(s32);
    func_8009EADC(arg1);
    func_80800008_bapackctrl(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/packctrl/bapackctrl_entrypoint_5.s")
