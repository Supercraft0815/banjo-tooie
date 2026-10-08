#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lava/archgrill/func_80800000_chlavaarchgrill.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lava/archgrill/func_80800044_chlavaarchgrill.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lava/archgrill/func_80800288_chlavaarchgrill.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lava/archgrill/func_808002D0_chlavaarchgrill.s")

OSThread *chlavaarchgrill_entrypoint_0(void)
{
    extern u8 D_808006A4_chlavaarchgrill[];

    return (OSThread *) D_808006A4_chlavaarchgrill;
}
