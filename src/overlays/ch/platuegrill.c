#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/platuegrill/func_80800000_chplatuegrill.s")

OSThread *chplatuegrill_entrypoint_0(void)
{
    extern u8 D_808001D0_chplatuegrill[];

    return (OSThread *) D_808001D0_chplatuegrill;
}

/* extern */

void func_808000A0_chplatuegrill(void *arg0) {
    s32 func_800DA298(s32);
    s32 func_80102424(void *, s32);
    if (func_800DA298(0x3EA) != 0) {
        (*(f32 *)((s8 *)(arg0) + (0x58))) = 0.0f;
        func_80102424(arg0, 2);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/platuegrill/func_808000DC_chplatuegrill.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/platuegrill/func_80800148_chplatuegrill.s")

OSThread *chplatuegrill_entrypoint_1(void)
{
    extern u8 D_80800238_chplatuegrill[];

    return (OSThread *) D_80800238_chplatuegrill;
}
