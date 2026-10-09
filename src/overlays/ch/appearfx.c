#include "common.h"

OSThread *chappearfx_entrypoint_0(void)
{
    extern u8 D_80800990_chappearfx[];

    return (OSThread *) D_80800990_chappearfx;
}

void func_8080000C_chappearfx(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/appearfx/func_80800014_chappearfx.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/appearfx/func_8080031C_chappearfx.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/appearfx/func_80800360_chappearfx.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/appearfx/func_808003A0_chappearfx.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/appearfx/func_80800554_chappearfx.s")

void chappearfx_entrypoint_1(s32 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 _chbaddiesetup_entrypoint_4(s32 *, s32, s32, s32, s32);
    extern s32 _chappearfx_entrypoint_3;
    _chbaddiesetup_entrypoint_4(&_chappearfx_entrypoint_3, *arg0, arg1, arg2, arg3);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/appearfx/chappearfx_entrypoint_2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/appearfx/chappearfx_entrypoint_3.s")
