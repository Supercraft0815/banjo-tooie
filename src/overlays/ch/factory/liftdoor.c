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

/* extern */

void func_8080008C_chfactoryliftdoor(Actor *arg0) {
    s32 _chswitch_entrypoint_14(s32, s32);
    s32 func_800DA298(s32);
    s32 func_80105010();
    void func_80109EEC(s16 *, s32);
    s32 sp24[2];
    s32 temp_a1;

    temp_a1 = arg0->unk74_7 + 0xC;
    sp24[1] = temp_a1;
    _chswitch_entrypoint_14((s32)arg0, temp_a1);
    func_80109EEC((s16 *)arg0, 0x40);
    func_80105010(arg0);
    if (func_800DA298(sp24[1]) != 0) {
        func_8010A570(arg0);
    }
}

s32 func_808000F0_chfactoryliftdoor(Actor *arg0, s32 arg1, s32 arg2) {
    if (arg1 == 7) {
        func_80101180(0x3B8, arg1, 0);
        func_8010A570(arg0);
    } else {
        return 0;
    }
    return 1;
}
