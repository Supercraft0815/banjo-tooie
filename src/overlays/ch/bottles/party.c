#include "common.h"

OSThread *chbottlesparty_entrypoint_0(void)
{
    extern u8 D_80800410_chbottlesparty[];

    return (OSThread *) D_80800410_chbottlesparty;
}

OSThread *chbottlesparty_entrypoint_1(void)
{
    extern u8 D_80800458_chbottlesparty[];

    return (OSThread *) D_80800458_chbottlesparty;
}

/* extern */

void func_80800018_chbottlesparty(s32 arg0) {
    s32 func_800DA298(s32);
    s32 func_800FFAB0(s32);
    s32 func_8010A800(s32, s32);
    if (func_800DA298(0x3B) == 0) {
        func_800FFAB0(arg0);
        return;
    }
    func_8010A800(arg0, 0);
}

void func_8080022C_chbottlesparty(s32);
void func_8080005C_chbottlesparty(s32 arg0) { void func_80800170_chbottlesparty(s32); func_8080022C_chbottlesparty(arg0); if (((Actor *)arg0)->unk70_10 == 1) { func_80800170_chbottlesparty(arg0); } }

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bottles/party/func_8080009C_chbottlesparty.s")

void func_80800138_chbottlesparty(Actor *arg0) {
    if ((u32) arg0->unk74_7 == 0x32) {
        func_80103140(arg0, 0x653U, 0U);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bottles/party/func_80800170_chbottlesparty.s")

void func_8080022C_chbottlesparty(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bottles/party/func_80800234_chbottlesparty.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bottles/party/func_80800330_chbottlesparty.s")

s32 func_808003E4_chbottlesparty(s32 arg0, s32 arg1, s32 arg2) {
    return 0;
}
