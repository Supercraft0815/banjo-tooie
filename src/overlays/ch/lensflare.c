#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lensflare/chlensflare_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lensflare/func_80800084_chlensflare.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lensflare/func_808000FC_chlensflare.s")

/* extern */

s32 func_80800634_chlensflare(void *arg0, s32 arg1, s32 arg2) {
    s8 func_800E8714(s32);
    if (arg1 == 0x95) {
        (*(s8 *)((s8 *)(arg0) + (0x50))) = func_800E8714(0);
        return 1;
    }
    return 0;
}

OSThread *chlensflare_entrypoint_1(void)
{
    extern u8 D_80800928_chlensflare[];

    return (OSThread *) D_80800928_chlensflare;
}
