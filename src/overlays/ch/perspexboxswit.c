#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/perspexboxswit/func_80800000_chperspexboxswitch.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/perspexboxswit/func_80800080_chperspexboxswitch.s")

OSThread *chperspexboxswitch_entrypoint_0(void)
{
    extern u8 D_808000D0_chperspexboxswitch[];

    return (OSThread *) D_808000D0_chperspexboxswitch;
}
