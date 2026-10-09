#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/usefeather/func_80800000_chusefeather.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/usefeather/chusefeather_entrypoint_0.s")

void chusefeather_entrypoint_1(s32 arg0, s32 arg1) {
    s32 _chbaddiesetup_entrypoint_2(s32 *, s32, s32);
    s32 func_800D3948();
    extern s32 _chusefeather_entrypoint_0;
    s32 var_a2;

    if (func_800D3948() == 0) {
        if (arg1 == 0) {
            var_a2 = 0x26A;
        } else {
            var_a2 = 0x26B;
        }
        _chbaddiesetup_entrypoint_2(&_chusefeather_entrypoint_0, arg0, var_a2);
    }
}

OSThread *chusefeather_entrypoint_2(void)
{
    extern u8 D_80800364_chusefeather[];

    return (OSThread *) D_80800364_chusefeather;
}

OSThread *chusefeather_entrypoint_3(void)
{
    extern u8 D_808003AC_chusefeather[];

    return (OSThread *) D_808003AC_chusefeather;
}
