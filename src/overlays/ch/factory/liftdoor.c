#include "common.h"

OSThread *chfactoryliftdoor_entrypoint_0(void)
{
    extern u8 D_80800140_chfactoryliftdoor[];

    return (OSThread *) D_80800140_chfactoryliftdoor;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/liftdoor/chfactoryliftdoor_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/liftdoor/func_80800018_chfactoryliftdoor.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/liftdoor/func_8080008C_chfactoryliftdoor.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/liftdoor/func_808000F0_chfactoryliftdoor.s")
