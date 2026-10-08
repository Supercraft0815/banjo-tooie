#include "common.h"

OSThread *chicestationbits_entrypoint_0(void)
{
    extern u8 D_80800280_chicestationbits[];

    return (OSThread *) D_80800280_chicestationbits;
}

OSThread *chicestationbits_entrypoint_1(void)
{
    extern u8 D_808002C8_chicestationbits[];

    return (OSThread *) D_808002C8_chicestationbits;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/icestationbits/func_80800018_chicestationbits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/icestationbits/func_80800050_chicestationbits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/icestationbits/func_808000D4_chicestationbits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/icestationbits/func_808001E0_chicestationbits.s")
