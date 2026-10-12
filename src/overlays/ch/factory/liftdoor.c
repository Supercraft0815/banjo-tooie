#include "common.h"

OSThread *chfactoryliftdoor_entrypoint_0(void)
{
    extern u8 D_80800140_chfactoryliftdoor[];

    return (OSThread *) D_80800140_chfactoryliftdoor;
}

OSThread *chfactoryliftdoor_entrypoint_1(void)
{
    extern u8 D_80800188_chfactoryliftdoor[];

    return (OSThread *) D_80800188_chfactoryliftdoor;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/liftdoor/func_80800018_chfactoryliftdoor.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/liftdoor/func_8080008C_chfactoryliftdoor.s")

s32 func_808000F0_chfactoryliftdoor(Actor *arg0, s32 arg1, s32 arg2) {
    if (arg1 == 7) {
        func_80101180(0x3B8, arg1, 0);
        func_8010A570(arg0);
    } else {
        return 0;
    }
    return 1;
}
