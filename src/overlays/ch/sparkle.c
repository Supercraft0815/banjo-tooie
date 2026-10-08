#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/sparkle/func_80800000_chsparkle.s")

OSThread *chsparkle_entrypoint_0(void)
{
    extern u8 D_80800164_chsparkle[];

    return (OSThread *) D_80800164_chsparkle;
}
