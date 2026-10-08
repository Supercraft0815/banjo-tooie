#include "common.h"

OSThread *chbigfoot_entrypoint_0(void)
{
    extern u8 D_808000C8_chbigfoot[];

    return (OSThread *) D_808000C8_chbigfoot;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bigfoot/func_8080000C_chbigfoot.s")
