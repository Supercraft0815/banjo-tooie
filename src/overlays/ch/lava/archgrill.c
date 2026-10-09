#include "common.h"

/* extern */

void func_80800000_chlavaarchgrill(void *arg0) {
    s32 func_800DA7A8(s32, s32, s32, void *);
    s32 func_8010A800(void *, s32);
    (*(f32 *)((s8 *)(arg0) + (0x2C))) = (f32) (*(f32 *)((s8 *)(arg0) + (8)));
    func_800DA7A8(0xA1A, 0, 3, arg0);
    func_8010A800(arg0, 2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lava/archgrill/func_80800044_chlavaarchgrill.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lava/archgrill/func_80800288_chlavaarchgrill.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lava/archgrill/func_808002D0_chlavaarchgrill.s")

OSThread *chlavaarchgrill_entrypoint_0(void)
{
    extern u8 D_808006A4_chlavaarchgrill[];

    return (OSThread *) D_808006A4_chlavaarchgrill;
}
