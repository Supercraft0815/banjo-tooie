#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/ping/func_80800000_chping.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/ping/func_808001B8_chping.s")

/* extern */

s32 chping_entrypoint_0(s32 arg0) {
    void func_800F5A00(s32, f32 *);
    void *func_80100094(s32 *, s32);
    s32 *func_80108474(s32, s32 *, s32);
    s32 func_8010A570(s32 *);
    s32 *sp2C;
    s32 sp20[3];
    s32 *temp_v0;
    void *temp_v0_2;

    func_800F5A00(arg0, sp20);
    temp_v0 = func_80108474(0x169, sp20, 0);
    sp2C = temp_v0;
    temp_v0_2 = func_80100094(temp_v0, 0);
    (*(f32 *)((s8 *)(temp_v0_2) + (4))) = 0.0f;
    (*(s32 *)((s8 *)(temp_v0_2) + (0))) = arg0;
    func_8010A570(sp2C);
    return *sp2C;
}

OSThread *chping_entrypoint_1(void)
{
    extern u8 D_80800410_chping[];

    return (OSThread *) D_80800410_chping;
}
