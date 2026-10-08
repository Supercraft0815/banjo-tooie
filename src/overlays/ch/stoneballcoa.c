#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stoneballcoa/func_80800000_chstoneballcoach.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stoneballcoa/func_80800090_chstoneballcoach.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stoneballcoa/func_80800100_chstoneballcoach.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stoneballcoa/func_80800140_chstoneballcoach.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stoneballcoa/func_8080035C_chstoneballcoach.s")

OSThread *chstoneballcoach_entrypoint_0(void)
{
    extern u8 D_808003D4_chstoneballcoach[];

    return (OSThread *) D_808003D4_chstoneballcoach;
}
