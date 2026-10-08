#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/btwmdoor/func_80800000_chfactorybtwmdoor.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/btwmdoor/func_80800068_chfactorybtwmdoor.s")

OSThread *chfactorybtwmdoor_entrypoint_0(void)
{
    extern u8 D_80800344_chfactorybtwmdoor[];

    return (OSThread *) D_80800344_chfactorybtwmdoor;
}
