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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gobi/hailfire/func_80800018_chgobihailfire.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gobi/hailfire/func_808000C8_chgobihailfire.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gobi/hailfire/func_8080032C_chgobihailfire.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gobi/hailfire/func_80800538_chgobihailfire.s")
