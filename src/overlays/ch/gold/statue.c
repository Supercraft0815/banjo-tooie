#include "common.h"

/* extern */

void func_80800000_chgoldstatue(s32 arg0) {
    s16 _chmumbopad_entrypoint_0(s32);
    s32 _sumumbofx_entrypoint_0(s32, s32, s32, s16);
    s32 _sumumbofx_entrypoint_15(s32, s32);
    s32 _sumumbofx_entrypoint_2(s32);
    s32 _sumumbofx_entrypoint_24(s32, s32);
    s32 func_800DA298(s32);
    s32 func_80100094(s32, s32);
    s32 sp1C;
    s32 temp_v0;

    _sumumbofx_entrypoint_0(arg0, 1, 0x2D, _chmumbopad_entrypoint_0(2));
    temp_v0 = func_80100094(arg0, 1);
    sp1C = temp_v0;
    _sumumbofx_entrypoint_2(temp_v0);
    _sumumbofx_entrypoint_24(sp1C, 0x3F266666);
    if (func_800DA298(0x57C) == 0) {
        _sumumbofx_entrypoint_15(sp1C, 0x40400000);
        return;
    }
    _sumumbofx_entrypoint_15(sp1C, 0x3E800000);
}

void func_80800094_chgoldstatue(s32 arg0)
{
    _sumumbofx_entrypoint_1(arg0,1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gold/statue/func_808000B4_chgoldstatue.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gold/statue/func_80800150_chgoldstatue.s")

/* extern */

void func_808002C8_chgoldstatue(s32 arg0) {
    s32 _glcutDll_entrypoint_20();
    s32 _subaddieDll_entrypoint_1();
    s32 func_800DA524(s32);
    s32 func_8010D278();
    s32 func_80800150_chgoldstatue(s32, s32);
    _subaddieDll_entrypoint_1();
    if (func_8010D278() == 0xE) {
        func_80800150_chgoldstatue(arg0, 6);
        return;
    }
    func_800DA524(0x9DE);
    if (_glcutDll_entrypoint_20() != 0) {
        func_80800150_chgoldstatue(arg0, 7);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gold/statue/func_8080032C_chgoldstatue.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gold/statue/func_80800528_chgoldstatue.s")

OSThread *chgoldstatue_entrypoint_0(void)
{
    extern u8 D_80800990_chgoldstatue[];

    return (OSThread *) D_80800990_chgoldstatue;
}
