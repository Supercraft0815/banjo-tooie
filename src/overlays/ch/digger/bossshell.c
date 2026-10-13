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

void func_808002CC_chdiggerbossshell(s32 arg0) {
    s32 _chlightfader_entrypoint_1(s32, s32, s32);
    s32 func_800C8A98();
    s32 func_800C8CB8(s32, s32);
    s32 func_800C8E54(s32, s32, s32);
    s32 func_800C8E84(s32, s32 *);
    extern s32 D_80800600_chdiggerbossshell;
    s32 sp1C;
    s32 temp_v0;

    temp_v0 = func_800C8A98();
    sp1C = temp_v0;
    func_800C8CB8(temp_v0, arg0);
    func_800C8E84(sp1C, &D_80800600_chdiggerbossshell);
    func_800C8E54(sp1C, 0x44160000, 0x447A0000);
    _chlightfader_entrypoint_1(sp1C, 0x3FB33333, 5);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/bossshell/func_80800330_chdiggerbossshell.s")

void func_8080044C_chdiggerbossshell(void *arg0) {
    (*(f32 *)((s8 *)(arg0) + (0x58))) = 1.75f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/bossshell/func_8080045C_chdiggerbossshell.s")

/* extern */

s32 func_808004C8_chdiggerbossshell(s32 arg0, s32 arg1, s32 arg2) {
    void func_80800504_chdiggerbossshell(s32 arg0);
    switch (arg1) {
    case 0x40:
        func_80800504_chdiggerbossshell(arg0);
        break;
    default:
        return 0;
    }
    return 1;
}

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
