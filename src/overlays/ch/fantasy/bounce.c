#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fantasy/bounce/func_80800000_chfantasybounce.s")

OSThread *chfantasybounce_entrypoint_0(void)
{
    extern u8 D_80800060_chfantasybounce[];

    return (OSThread *) D_80800060_chfantasybounce;
}

OSThread *chfantasybounce_entrypoint_1(void)
{
    extern u8 D_808000A8_chfantasybounce[];

    return (OSThread *) D_808000A8_chfantasybounce;
}
