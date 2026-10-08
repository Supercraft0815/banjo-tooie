#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fantasy/safeswitch/func_80800000_chfantasysafeswitch.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fantasy/safeswitch/func_8080002C_chfantasysafeswitch.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fantasy/safeswitch/func_80800070_chfantasysafeswitch.s")

OSThread *chfantasysafeswitch_entrypoint_0(void)
{
    extern u8 D_80800288_chfantasysafeswitch[];

    return (OSThread *) D_80800288_chfantasysafeswitch;
}
