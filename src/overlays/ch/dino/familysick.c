#include "common.h"

OSThread *chdinofamilysick_entrypoint_0(void)
{
    extern u8 D_80800E60_chdinofamilysick[];

    return (OSThread *) D_80800E60_chdinofamilysick;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/familysick/func_8080000C_chdinofamilysick.s")

/* extern */

f32 func_808001FC_chdinofamilysick(s32 arg0, s32 arg1) {
    s32 _gccubesearch_entrypoint_9(s32, s32 *, s32);
    s32 _gspropctrl_entrypoint_11(s32, s32);
    s32 _gspropctrl_entrypoint_12(s32);
    s32 sp1C;

    _gccubesearch_entrypoint_9(0x52D, &sp1C, 1);
    _gspropctrl_entrypoint_11(sp1C, arg1);
    return (f32) _gspropctrl_entrypoint_12(sp1C);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/familysick/func_80800244_chdinofamilysick.s")

void func_8080030C_chdinofamilysick(volatile unsigned int arg0, void *arg1, s32 arg2, s32 arg3)
{
  s32 _chbaddiesetup_entrypoint_6(s32 *, s32, s32, s32, s32, s32, s32);
  extern s32 _subaddietaxi_entrypoint_16;
  _chbaddiesetup_entrypoint_6(&_subaddietaxi_entrypoint_16, arg0, *((s32 *) (((s8 *) arg1) + 0)), *((s32 *) (((s8 *) arg1) + 4)), *((s32 *) (((s8 *) arg1) + 8)), arg2, arg3);
}

/* extern */

s32 func_80800368_chdinofamilysick(s32 arg0, s32 arg1, s32 arg2) {
    s32 func_800EA05C();
    if (func_800EA05C() == 0x121) {
        func_808001FC_chdinofamilysick(arg0, arg2);
        return 2;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/familysick/func_808003B0_chdinofamilysick.s")

OSThread *chdinofamilysick_entrypoint_1(void)
{
    extern u8 D_80800EA8_chdinofamilysick[];

    return (OSThread *) D_80800EA8_chdinofamilysick;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/familysick/func_808005F8_chdinofamilysick.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/familysick/func_80800768_chdinofamilysick.s")

void func_80800A1C_chdinofamilysick(Actor *arg0) {
    f32 func_800F3780(f32, u8 *, s16);
    f32 func_80101F24(Actor *);
    void func_80105834(Actor *);
    void func_80105A9C(Actor *, f32);
    extern u8 D_80800F48_chdinofamilysick;
    f32 temp_f2;
    f32 var_f0;
    f32 temp_f6;

    temp_f2 = func_800F3780(func_80101F24(arg0), &D_80800F48_chdinofamilysick, 4);
    if (arg0->unk70_10 == 4) {
        var_f0 = 0.75f;
    } else {
        var_f0 = 1.0f;
    }
    temp_f6 = temp_f2 * 1200.0f;
    func_80105A9C(arg0, var_f0 * temp_f6);
    func_80105834(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/familysick/func_80800AB0_chdinofamilysick.s")

OSThread *chdinofamilysick_entrypoint_2(void)
{
    extern u8 D_80800F78_chdinofamilysick[];

    return (OSThread *) D_80800F78_chdinofamilysick;
}
