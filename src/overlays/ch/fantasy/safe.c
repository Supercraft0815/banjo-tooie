#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fantasy/safe/func_80800000_chfantasysafe.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fantasy/safe/func_808001A0_chfantasysafe.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fantasy/safe/func_80800630_chfantasysafe.s")

OSThread *chfantasysafe_entrypoint_0(void)
{
    extern u8 D_80800AA0_chfantasysafe[];

    return (OSThread *) D_80800AA0_chfantasysafe;
}

OSThread *chfantasysafe_entrypoint_1(void)
{
    extern u8 D_80800AE8_chfantasysafe[];

    return (OSThread *) D_80800AE8_chfantasysafe;
}
