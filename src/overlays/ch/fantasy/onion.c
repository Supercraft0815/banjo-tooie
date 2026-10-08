#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fantasy/onion/func_80800000_chfantasyonion.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fantasy/onion/func_808000BC_chfantasyonion.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fantasy/onion/func_80800254_chfantasyonion.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fantasy/onion/func_80800624_chfantasyonion.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fantasy/onion/func_808006E0_chfantasyonion.s")

OSThread *chfantasyonion_entrypoint_0(void)
{
    extern u8 D_80800754_chfantasyonion[];

    return (OSThread *) D_80800754_chfantasyonion;
}
