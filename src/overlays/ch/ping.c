#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/ping/func_80800000_chping.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/ping/func_808001B8_chping.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/ping/chping_entrypoint_0.s")

OSThread *chping_entrypoint_1(void)
{
    extern u8 D_80800410_chping[];

    return (OSThread *) D_80800410_chping;
}
