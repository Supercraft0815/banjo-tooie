#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lava/traindoor/func_80800000_chlavatraindoor.s")

OSThread *chlavatraindoor_entrypoint_0(void)
{
    extern u8 D_808000F0_chlavatraindoor[];

    return (OSThread *) D_808000F0_chlavatraindoor;
}
