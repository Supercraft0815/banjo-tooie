#include "common.h"

OSThread *chdiggerfly_entrypoint_0(void)
{
    extern u8 D_808000F8_chdiggerfly[];

    return (OSThread *) D_808000F8_chdiggerfly;
}

OSThread *chdiggerfly_entrypoint_1(void)
{
    extern u8 D_80800140_chdiggerfly[];

    return (OSThread *) D_80800140_chdiggerfly;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/fly/func_80800018_chdiggerfly.s")
