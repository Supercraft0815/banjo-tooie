#include "common.h"

OSThread *chgobihailfire_entrypoint_0(void)
{
    extern u8 D_80800788_chgobihailfire[];

    return (OSThread *) D_80800788_chgobihailfire;
}

OSThread *chgobihailfire_entrypoint_1(void)
{
    extern u8 D_808007D0_chgobihailfire[];

    return (OSThread *) D_808007D0_chgobihailfire;
}

/* extern */

void func_80800018_chgobihailfire(Actor *arg0) {
    s32 _glcutDll_entrypoint_20();
    s32 func_800DA298(s32);
    s32 func_800EA05C();
    void func_800FFAB0(Actor *);
    void func_80102424(Actor *, s32);
    void func_80102FDC(Actor *, f32);
    void func_8010573C(Actor *, f32);
    void func_80105A9C(Actor *, f32);
    struct {
        u32 unused : 15;
        u32 enabled : 1;
        u32 unused2 : 16;
    } *flags;
    if (_glcutDll_entrypoint_20() != 0) {
        if (func_800EA05C() != 0x129) {
            func_800FFAB0(arg0);
        }
        func_80102424(arg0, 4);
        func_8010573C(arg0, 1.0f);
        goto block_6;
    }
    if (func_800DA298(0x97) == 0) {
        func_800FFAB0(arg0);
        return;
    }
block_6:
    func_80105A9C(arg0, 500.0f);
    func_80102FDC(arg0, 0.25f);
    flags = (void *)&arg0->pad94;
    flags->enabled = 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gobi/hailfire/func_808000C8_chgobihailfire.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gobi/hailfire/func_8080032C_chgobihailfire.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gobi/hailfire/func_80800538_chgobihailfire.s")
