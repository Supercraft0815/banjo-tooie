#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lensflare/chlensflare_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lensflare/func_80800084_chlensflare.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lensflare/func_808000FC_chlensflare.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lensflare/func_80800634_chlensflare.s")

OSThread *chlensflare_entrypoint_1(void)
{
    extern u8 D_80800928_chlensflare[];

    return (OSThread *) D_80800928_chlensflare;
}
