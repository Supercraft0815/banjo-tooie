#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/trashbelt/func_80800000_chfactorytrashbelt.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/trashbelt/func_808001EC_chfactorytrashbelt.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/trashbelt/func_8080041C_chfactorytrashbelt.s")

OSThread *chfactorytrashbelt_entrypoint_0(void)
{
    extern u8 D_808005EC_chfactorytrashbelt[];

    return (OSThread *) D_808005EC_chfactorytrashbelt;
}
