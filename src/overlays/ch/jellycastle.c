#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jellycastle/func_80800000_chjellycastle.s")

OSThread *chjellycastle_entrypoint_0(void)
{
    extern u8 D_808000A0_chjellycastle[];

    return (OSThread *) D_808000A0_chjellycastle;
}
