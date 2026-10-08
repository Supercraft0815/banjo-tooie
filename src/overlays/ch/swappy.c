#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/swappy/func_80800000_chswappy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/swappy/func_808000B0_chswappy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/swappy/func_80800108_chswappy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/swappy/func_80800234_chswappy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/swappy/func_80800300_chswappy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/swappy/func_808003DC_chswappy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/swappy/chswappy_entrypoint_0.s")

OSThread *chswappy_entrypoint_1(void)
{
    extern u8 D_808006D4_chswappy[];

    return (OSThread *) D_808006D4_chswappy;
}
