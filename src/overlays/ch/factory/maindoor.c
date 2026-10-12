#include "ch/factory/maindoor.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/maindoor/func_80800000_chfactorymaindoor.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/maindoor/func_80800078_chfactorymaindoor.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/maindoor/func_808001F0_chfactorymaindoor.s")

OSThread *chfactorymaindoor_entrypoint_0(void)
{
    extern u8 D_808004D4_chfactorymaindoor[];

    return (OSThread *) D_808004D4_chfactorymaindoor;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/maindoor/func_80800344_chfactorymaindoor.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/maindoor/func_808003A8_chfactorymaindoor.s")

OSThread *chfactorymaindoor_entrypoint_1(void)
{
    extern u8 D_8080051C_chfactorymaindoor[];

    return (OSThread *) D_8080051C_chfactorymaindoor;
}

void func_8080041C_chfactorymaindoor(s32 arg0)
{
    _chswitch_entrypoint_3(arg0,FLAG_188_UNK);
}

void func_8080043C_chfactorymaindoor(s32 arg0, s32 arg1, s32 arg2) {
    s32 _chswitch_entrypoint_5(s32, s32, s32);
    void _glcutDll_entrypoint_6(u32, u32);
    if (arg1 == 7) {
        _glcutDll_entrypoint_6(0x100U, 0x86U);
    }
    _chswitch_entrypoint_5(arg0, arg1, arg2);
}

OSThread *chfactorymaindoor_entrypoint_2(void)
{
    extern u8 D_80800564_chfactorymaindoor[];

    return (OSThread *) D_80800564_chfactorymaindoor;
}
