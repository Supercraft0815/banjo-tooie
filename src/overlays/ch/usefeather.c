#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/usefeather/func_80800000_chusefeather.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/usefeather/chusefeather_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/usefeather/chusefeather_entrypoint_1.s")

OSThread *chusefeather_entrypoint_2(void)
{
    extern u8 D_80800364_chusefeather[];

    return (OSThread *) D_80800364_chusefeather;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/usefeather/chusefeather_entrypoint_3.s")
