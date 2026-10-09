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

void func_80800504_chdiggerbossshell(s32 arg0) {
    s32 func_800BBCB8(s32, s32, s32, s32, s32 *);
    s32 func_800FFAB0(s32);
    s32 func_8010A570(s32);
    extern s32 D_8080060C_chdiggerbossshell;
    s32 temp_a0;

    temp_a0 = arg0 + 4;
    func_800BBCB8(temp_a0, temp_a0, 0x3F800000, 3, &D_8080060C_chdiggerbossshell);
    func_8010A570(arg0);
    func_800FFAB0(arg0);
}
