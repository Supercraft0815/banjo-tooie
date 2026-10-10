#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/screenadjust/func_80800000_chscreenadjust.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/screenadjust/func_8080016C_chscreenadjust.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/screenadjust/func_808001E0_chscreenadjust.s")

/* extern */

void func_8080037C_chscreenadjust(s32 arg0, s32 arg1) {
    s32 func_808001E0_chscreenadjust(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
    func_808001E0_chscreenadjust(arg1, 0, 0, 0x130, 0xE4, 0x40, 0xA, 0xFF, 0, 0);
    func_808001E0_chscreenadjust(arg1, 0x20, 0x20, 0x110, 0xC4, 0x20, 5, 0xFF, 0, 0);
}

OSThread *chscreenadjust_entrypoint_0(void)
{
    extern u8 D_80800430_chscreenadjust[];

    return (OSThread *) D_80800430_chscreenadjust;
}
