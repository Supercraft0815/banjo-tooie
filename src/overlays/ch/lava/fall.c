#include "common.h"

OSThread *chlavafall_entrypoint_0(void)
{
    extern u8 D_808000B0_chlavafall[];

    return (OSThread *) D_808000B0_chlavafall;
}

void func_8080000C_chlavafall(void *arg0) {
    (*(u8 *)((s8 *)(arg0) + (0x7A))) = (u8) (((*(u8 *)((s8 *)(arg0) + (0x7A))) & 0xFF3F) | 0x80);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lava/fall/func_80800020_chlavafall.s")
