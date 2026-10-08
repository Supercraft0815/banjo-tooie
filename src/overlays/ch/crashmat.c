#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/crashmat/func_80800000_chcrashmat.s")

OSThread *chcrashmat_entrypoint_0(void)
{
    extern u8 D_808000A0_chcrashmat[];

    return (OSThread *) D_808000A0_chcrashmat;
}
