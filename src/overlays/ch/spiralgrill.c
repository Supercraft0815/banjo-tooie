#include "common.h"

OSThread *chspiralgrill_entrypoint_0(void)
{
    extern u8 D_80800180_chspiralgrill[];

    return (OSThread *) D_80800180_chspiralgrill;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/spiralgrill/func_8080000C_chspiralgrill.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/spiralgrill/func_8080003C_chspiralgrill.s")
