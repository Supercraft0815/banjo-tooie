#include "common.h"

OSThread *chfloater_entrypoint_0(void)
{
    extern u8 D_808002A0_chfloater[];

    return (OSThread *) D_808002A0_chfloater;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/floater/func_8080000C_chfloater.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/floater/func_808000C0_chfloater.s")
