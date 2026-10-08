#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mumbo/healspell/func_80800000_chmumbohealspell.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mumbo/healspell/func_80800074_chmumbohealspell.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mumbo/healspell/func_808003A8_chmumbohealspell.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mumbo/healspell/func_80800450_chmumbohealspell.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mumbo/healspell/func_80800740_chmumbohealspell.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mumbo/healspell/func_80800800_chmumbohealspell.s")

OSThread *chmumbohealspell_entrypoint_0(void)
{
    extern u8 D_80800900_chmumbohealspell[];

    return (OSThread *) D_80800900_chmumbohealspell;
}
