#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fair/coin/func_80800000_chfaircoin.s")

u8 *chfaircoin_entrypoint_0(s32 arg0, s32 arg1, f32 arg2) {
    s32 func_800C4AF0(s32, s32 *);
    s32 func_800EE7F8(u8 *, s32);
    u8 *func_80108474(s32, s32, s32);
    extern s32 D_80800150_chfaircoin;
    u8 *temp_v0;

    temp_v0 = func_80108474(0x166, arg0, 0);
    func_800EE7F8(temp_v0 + 0x18, arg1);
    func_800EE7F8(temp_v0 + 0x28, arg0);
    (*(f32 *)((s8 *)(temp_v0) + (0x24))) = arg2;
    (*(f32 *)((s8 *)(temp_v0) + (0x58))) = arg2;
    func_800C4AF0(0, &D_80800150_chfaircoin);
    return temp_v0;
}

OSThread *chfaircoin_entrypoint_1(void)
{
    extern u8 D_8080015C_chfaircoin[];

    return (OSThread *) D_8080015C_chfaircoin;
}
