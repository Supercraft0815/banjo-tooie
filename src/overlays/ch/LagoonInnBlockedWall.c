#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/LagoonInnBlockedWall/func_80800000_chLagoonInnBlockedWall.s")

void func_808000C0_chLagoonInnBlockedWall()
{
    func_8010A63C();
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/LagoonInnBlockedWall/func_808000E0_chLagoonInnBlockedWall.s")

OSThread *chLagoonInnBlockedWall_entrypoint_0(void)
{
    extern u8 D_80800480_chLagoonInnBlockedWall[];

    return (OSThread *) D_80800480_chLagoonInnBlockedWall;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/LagoonInnBlockedWall/func_8080025C_chLagoonInnBlockedWall.s")

s32 func_80800398_chLagoonInnBlockedWall(s32 arg0, s32 arg1, volatile s32 arg2) {
    if (arg1 == 0x40) {
        func_8080025C_chLagoonInnBlockedWall(arg0, *(s32 *)&arg2);
        return 1;
    }
    return 0;
}

OSThread *chLagoonInnBlockedWall_entrypoint_1(void)
{
    extern u8 D_80800570_chLagoonInnBlockedWall[];

    return (OSThread *) D_80800570_chLagoonInnBlockedWall;
}
