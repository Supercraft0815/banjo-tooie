#include "ch/introtext.h"

OSThread *chintrotext_entrypoint_0(void)
{
    extern u8 D_808007D0_chintrotext[];

    return (OSThread *) D_808007D0_chintrotext;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/intro/text/func_8080000C_chintrotext.s")

void func_80800130_chintrotext(s32 arg0)
{
    func_800DA524(FLAG2_6AD_CURRENTLY_SHOWING_INTROTEXT);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/intro/text/func_80800154_chintrotext.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/intro/text/func_808003EC_chintrotext.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/intro/text/func_8080051C_chintrotext.s")

void chintrotext_entrypoint_1(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 _chbaddiesetup_entrypoint_4(s32 *, s32, s32, s32, s32);
    s32 func_800A9C98();
    extern s32 _chintrotext_entrypoint_3;
    if (func_800A9C98() == 0) {
        _chbaddiesetup_entrypoint_4(&_chintrotext_entrypoint_3, arg0, arg1, arg3, arg2);
    }
}

/* extern */

s32 chintrotext_entrypoint_2(s32 arg0) {
    s32 _gcintrotext_entrypoint_2(s32, s32 *, s32 *);
    s32 sp24;
    s32 sp20;
    s32 temp_v0;

    temp_v0 = _gcintrotext_entrypoint_2(-1, &sp24, &sp20);
    if ((temp_v0 != -1) && ((arg0 != 0) || (temp_v0 > 0))) {
        chintrotext_entrypoint_1(sp24, sp20, 0, 0);
        return 1;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/intro/text/chintrotext_entrypoint_3.s")
