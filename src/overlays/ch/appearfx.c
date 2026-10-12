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

void func_8080031C_chappearfx(Actor *arg0) {
    void func_800FCA90(u32);
    void func_800FCAE0(u32, u32, u32);
    void* func_80100094(Actor*, u32);
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    if ((*(u8 *)((s8 *)(temp_v0) + (0xD))) != 0) {
        (*(u8 *)((s8 *)(temp_v0) + (0xD))) = 0U;
        func_800FCAE0(0x1CU, 0U, 0x1F4U);
        func_800FCA90(0x1CU);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/appearfx/func_80800360_chappearfx.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/appearfx/func_808003A0_chappearfx.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/appearfx/func_80800554_chappearfx.s")

void chappearfx_entrypoint_1(s32 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 _chbaddiesetup_entrypoint_4(s32 *, s32, s32, s32, s32);
    extern s32 _chappearfx_entrypoint_3;
    _chbaddiesetup_entrypoint_4(&_chappearfx_entrypoint_3, *arg0, arg1, arg2, arg3);
}

/* extern */

void chappearfx_entrypoint_2(s32 *arg0, s32 arg1, s32 arg2, f32 arg3) {
    s32 chappearfx_entrypoint_3(s32, s32, s32);
    chappearfx_entrypoint_3(*arg0, arg1, arg2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/appearfx/chappearfx_entrypoint_3.s")
