#include "common.h"

void func_80800000_chbanjocurrent()
{
    func_800F4C24(func_800F54E4());
}

OSThread *chbanjocurrent_entrypoint_0(void)
{
    extern u8 D_808007D0_chbanjocurrent[];

    return (OSThread *) D_808007D0_chbanjocurrent;
}

void func_80800034_chbanjocurrent(s32 *arg0) {
    s32 temp = arg0[1];
    arg0[1] = arg0[2];
    arg0[2] = arg0[0];
    arg0[0] = temp;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/banjocurrent/func_80800050_chbanjocurrent.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/banjocurrent/func_808001D0_chbanjocurrent.s")

OSThread *chbanjocurrent_entrypoint_1(void)
{
    extern u8 D_80800818_chbanjocurrent[];

    return (OSThread *) D_80800818_chbanjocurrent;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/banjocurrent/func_80800514_chbanjocurrent.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/banjocurrent/func_808005F4_chbanjocurrent.s")
