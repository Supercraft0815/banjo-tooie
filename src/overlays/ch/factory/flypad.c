#include "ch/factory/flypad.h"

OSThread *chfactoryflypad_entrypoint_0(void)
{
    extern u8 D_80800250_chfactoryflypad[];

    return (OSThread *) D_80800250_chfactoryflypad;
}

OSThread *chfactoryflypad_entrypoint_1(void)
{
    extern u8 D_80800298_chfactoryflypad[];

    return (OSThread *) D_80800298_chfactoryflypad;
}

void func_80800018_chfactoryflypad(s32 arg0)
{
    _chswitch_entrypoint_7(arg0,FLAG_16B_UNK);
    _chswitch_entrypoint_9(arg0);
}

s32 func_80800044_chfactoryflypad(s32 arg0, s32 arg1, s32 arg2) {
    s32 _chswitch_entrypoint_10(s32, s32, s32);
    void _glcutDll_entrypoint_6(u32, u32);
    if (arg1 == 7) {
        _glcutDll_entrypoint_6(0x100U, 0x42U);
        return 1;
    }
    return _chswitch_entrypoint_10(arg0, arg1, arg2);
}

void func_80800080_chfactoryflypad(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/flypad/func_80800088_chfactoryflypad.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/flypad/func_80800130_chfactoryflypad.s")
