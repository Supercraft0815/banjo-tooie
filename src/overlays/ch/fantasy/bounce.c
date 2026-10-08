#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fantasy/bounce/func_80800000_chfantasybounce.s")

OSThread *chfantasybounce_entrypoint_0(void)
{
    extern u8 D_80800060_chfantasybounce[];

    return (OSThread *) D_80800060_chfantasybounce;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fantasy/bounce/chfantasybounce_entrypoint_1.s")
