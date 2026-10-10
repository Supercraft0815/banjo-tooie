#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/screenadjust/func_80800000_chscreenadjust.s")

/* extern */

s32 func_8080016C_chscreenadjust(void *arg0, s32 arg1, s32 arg2) {
    s32 _glglobalsettings_entrypoint_5(s32 *, s32 *, void *);
    s32 sp1C;
    s32 sp18;

    if (arg1 == 0x95) {
        _glglobalsettings_entrypoint_5(&sp1C, &sp18, arg0);
        (*(f32 *)((s8 *)(arg0) + (0x18))) = (f32) sp1C;
        (*(f32 *)((s8 *)(arg0) + (0x1C))) = (f32) sp18;
        return 1;
    }
    return 0;
}

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
