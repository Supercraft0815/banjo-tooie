#include "common.h"

OSThread *chsquits_entrypoint_0(void)
{
    extern u8 D_808006D8_chsquits[];

    return (OSThread *) D_808006D8_chsquits;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/squits/func_8080000C_chsquits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/squits/func_80800054_chsquits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/squits/func_80800108_chsquits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/squits/func_808001A4_chsquits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/squits/func_80800358_chsquits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/squits/func_808003C4_chsquits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/squits/func_80800528_chsquits.s")

/* extern */

void func_80800564_chsquits(void *arg0) {
    s32 func_800DC128(s32, s32);
    (*(s32 *)((s8 *)(arg0) + (0x28))) = func_800DC128(0, 4);
    (*(f32 *)((s8 *)(arg0) + (0x2C))) = 0.0f;
}
