#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lagoon/lockerdoorhits/func_80800000_chlagoonlockerdoorhits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lagoon/lockerdoorhits/func_8080010C_chlagoonlockerdoorhits.s")

/* extern */

void func_808001B0_chlagoonlockerdoorhits(void) {
    void func_800BF744(s32, s32);
    s32 func_800DA298(s32);
    s32 func_800DA564(s32, s32);
    s32 sp24[2];
    s32 sp1C;
    sp24[1] = func_800DA564(0x3A4, 4);
    func_800BF744((sp1C = sp24[1] * 2) + 9, func_800DA298(0x3A8) ? 0 : 1);
    func_800BF744(sp1C + 0xA, func_800DA298(0x3A8) ? 0 : 0xF);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lagoon/lockerdoorhits/func_8080022C_chlagoonlockerdoorhits.s")

OSThread *chlagoonlockerdoorhits_entrypoint_0(void)
{
    extern u8 D_8080045C_chlagoonlockerdoorhits[];

    return (OSThread *) D_8080045C_chlagoonlockerdoorhits;
}
