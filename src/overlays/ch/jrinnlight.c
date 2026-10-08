#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jrinnlight/func_80800000_chjrinnlight.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jrinnlight/func_80800038_chjrinnlight.s")

OSThread *chjrinnlight_entrypoint_0(void)
{
    extern u8 D_808000F0_chjrinnlight[];

    return (OSThread *) D_808000F0_chjrinnlight;
}
