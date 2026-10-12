#include "common.h"

/* extern */

void func_80800000_chwaspstatue(s32 arg0) {
    s32 func_800DA298(s32);
    s32 func_80800134_chwaspstatue(s32, s32);

    func_80800134_chwaspstatue(arg0, func_800DA298(0x35A) ? 0x6 : 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/waspstatue/func_8080003C_chwaspstatue.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/waspstatue/func_80800134_chwaspstatue.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/waspstatue/func_80800350_chwaspstatue.s")

/* extern */

void chwaspstatue_entrypoint_0(s32 arg0, s32 arg1) {
    s32 func_80106790(s32);
    s32 func_80800134_chwaspstatue(s32, s32);
    func_80800134_chwaspstatue(func_80106790(arg1), 4);
}

OSThread *chwaspstatue_entrypoint_1(void)
{
    extern u8 D_80800740_chwaspstatue[];

    return (OSThread *) D_80800740_chwaspstatue;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/waspstatue/func_80800544_chwaspstatue.s")

OSThread *chwaspstatue_entrypoint_2(void)
{
    extern u8 D_80800788_chwaspstatue[];

    return (OSThread *) D_80800788_chwaspstatue;
}
