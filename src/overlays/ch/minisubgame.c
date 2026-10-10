#include "common.h"

OSThread *chminisubgame_entrypoint_0(void)
{
    extern u8 D_80801424_chminisubgame[];

    return (OSThread *) D_80801424_chminisubgame;
}

OSThread *chminisubgame_entrypoint_1(void)
{
    extern u8 D_8080146C_chminisubgame[];

    return (OSThread *) D_8080146C_chminisubgame;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/minisubgame/func_80800018_chminisubgame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/minisubgame/func_808000C8_chminisubgame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/minisubgame/func_80800430_chminisubgame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/minisubgame/func_80800484_chminisubgame.s")

void func_80800A64_chminisubgame(Actor *arg0, s32 arg1) {
    void* func_80100094(Actor*, u32);
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    arg0->actorData[5] -= 1;
    (*(s8 *)((s8 *)((temp_v0 + arg1)) + (0x2D0))) = 2;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/minisubgame/func_80800AAC_chminisubgame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/minisubgame/func_80800BA8_chminisubgame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/minisubgame/func_80800EC8_chminisubgame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/minisubgame/func_80801058_chminisubgame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/minisubgame/func_808011DC_chminisubgame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/minisubgame/func_80801248_chminisubgame.s")
