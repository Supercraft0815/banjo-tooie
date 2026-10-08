#include "common.h"

OSThread *chklungodoors_entrypoint_0(void)
{
    extern u8 D_808004C0_chklungodoors[];

    return (OSThread *) D_808004C0_chklungodoors;
}

OSThread *chklungodoors_entrypoint_1(void)
{
    extern u8 D_80800508_chklungodoors[];

    return (OSThread *) D_80800508_chklungodoors;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/klungo/doors/func_80800018_chklungodoors.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/klungo/doors/func_80800234_chklungodoors.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/klungo/doors/func_80800300_chklungodoors.s")
