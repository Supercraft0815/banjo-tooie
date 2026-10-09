#include "common.h"

/* extern */

void func_80800000_chlighthalo(u8 *arg0) {
    s32 func_800E8830(s32, u8 *, u8, u8 *);
    u8 temp_a2;

    temp_a2 = (*(u8 *)((s8 *)(arg0) + (0x34)));
    if (temp_a2 != 0) {
        func_800E8830(temp_a2 & 0xFF, arg0 + 4, temp_a2, arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/light/halo/func_80800030_chlighthalo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/light/halo/func_80800068_chlighthalo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/light/halo/func_80800448_chlighthalo.s")

void func_80800630_chlighthalo(s32 arg0) 
{
}
OSThread *chlighthalo_entrypoint_0(void)
{
    extern u8 D_808006A8_chlighthalo[];

    return (OSThread *) D_808006A8_chlighthalo;
}
