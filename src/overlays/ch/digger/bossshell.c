#include "common.h"

OSThread *chdiggerbossshell_entrypoint_0(void)
{
    extern u8 D_80800560_chdiggerbossshell[];

    return (OSThread *) D_80800560_chdiggerbossshell;
}

OSThread *chdiggerbossshell_entrypoint_1(void)
{
    extern u8 D_808005A8_chdiggerbossshell[];

    return (OSThread *) D_808005A8_chdiggerbossshell;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/bossshell/func_80800018_chdiggerbossshell.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/bossshell/func_808000B4_chdiggerbossshell.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/bossshell/func_80800188_chdiggerbossshell.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/bossshell/func_808001EC_chdiggerbossshell.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/bossshell/func_808002CC_chdiggerbossshell.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/bossshell/func_80800330_chdiggerbossshell.s")

void func_8080044C_chdiggerbossshell(void *arg0) {
    (*(f32 *)((s8 *)(arg0) + (0x58))) = 1.75f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/bossshell/func_8080045C_chdiggerbossshell.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/bossshell/func_808004C8_chdiggerbossshell.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/bossshell/func_80800504_chdiggerbossshell.s")
