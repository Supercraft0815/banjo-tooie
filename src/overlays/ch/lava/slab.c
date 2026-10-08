#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lava/slab/func_80800000_chlavaslab.s")

OSThread *chlavaslab_entrypoint_0(void)
{
    extern u8 D_808000A0_chlavaslab[];

    return (OSThread *) D_808000A0_chlavaslab;
}
