#include "common.h"

OSThread *chloggo_entrypoint_0(void)
{
    extern u8 D_80800648_chloggo[];

    return (OSThread *) D_80800648_chloggo;
}

OSThread *chloggo_entrypoint_1(void)
{
    extern u8 D_80800690_chloggo[];

    return (OSThread *) D_80800690_chloggo;
}

/* extern */

void func_80800018_chloggo(s32 arg0) {
    s32 _gccubesearch_entrypoint_0(s32, s32);
    s32 _glcutDll_entrypoint_20();
    s32 func_800D0A9C(s32, s32);
    s32 func_800DA298(s32);
    s32 func_800EE88C(s32, s32);
    s32 func_80102424(s32, s32);
    s32 func_8010A570(s32);
    s32 func_8010A5B0(s32, s32);
    func_800EE88C(arg0 + 0x18, _gccubesearch_entrypoint_0(0x201, arg0));
    if (_glcutDll_entrypoint_20() != 0) {
        func_80102424(arg0, 4);
        return;
    }
    if (func_800D0A9C(0x10, 4) != 0) {
        func_8010A570(arg0);
        return;
    }
    func_8010A5B0(arg0, func_800DA298(0x169));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/loggo/func_808000AC_chloggo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/loggo/func_808001B8_chloggo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/loggo/func_80800398_chloggo.s")

void func_80800460_chloggo(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_3(Actor *, f32 *, u32 *, f32);
    extern u32 D_808006F8_chloggo;
    extern u32 D_80800710_chloggo;
    extern u32 D_80800728_chloggo;
    extern u32 D_80800740_chloggo;
    f32 *temp_s1;

    temp_s1 = (f32 *)((s8 *)arg0 + 4);
    _subaddieaudioquick_entrypoint_3(arg0, temp_s1, &D_808006F8_chloggo, 0.09f);
    _subaddieaudioquick_entrypoint_3(arg0, temp_s1, &D_80800740_chloggo, 0.16f);
    _subaddieaudioquick_entrypoint_3(arg0, temp_s1, &D_80800710_chloggo, 0.22f);
    _subaddieaudioquick_entrypoint_3(arg0, temp_s1, &D_80800728_chloggo, 0.6f);
}

/* extern */

void func_808004F8_chloggo(s32 arg0) {
    s32 _glcutDll_entrypoint_20();
    s32 func_800FFAB0(s32);
    if (_glcutDll_entrypoint_20() != 0) {
        func_800FFAB0(arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/loggo/func_80800528_chloggo.s")
