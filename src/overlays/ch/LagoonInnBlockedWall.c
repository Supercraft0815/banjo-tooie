#include "common.h"

/* extern */

void func_80800000_chLagoonInnBlockedWall(Actor *arg0) {
    void _chexploder_entrypoint_3(void *, void *, u32);
    void _glcutDll_entrypoint_6(u32, u32);
    u8 func_800D9078(f32 *);
    s32 func_800DA544(s32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF1B8(f32 *, f32, f32);
    u32 func_800F54E4(void);
    void func_800F82D4(s32, s32);
    void func_800FFAB0(Actor *);

    switch (arg0->unk70_10) {
    case 3:
        if (func_800D9078(&arg0->unk58) != 0) {
            f32 sp24[3];
            func_800EE7F8(sp24, arg0->position);
            func_800EF1B8(sp24, arg0->rotation[1], -100);
            _chexploder_entrypoint_3(arg0, sp24, 3);
            func_800DA544(0x3A9);
        }
        break;
    case 2:
        if (func_800D9078(&arg0->unk58) != 0) {
            func_800F82D4(func_800F54E4(), 0);
            _glcutDll_entrypoint_6(0x1A7, 0x32);
            func_800FFAB0(arg0);
        }
        break;
    }
}

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
