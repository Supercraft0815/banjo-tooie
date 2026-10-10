#include "ch/factory/linkgrill.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/linkgrill/func_80800000_chfactorylinkgrill.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/linkgrill/func_8080006C_chfactorylinkgrill.s")

OSThread *chfactorylinkgrill_entrypoint_0(void)
{
    extern u8 D_80800250_chfactorylinkgrill[];

    return (OSThread *) D_80800250_chfactorylinkgrill;
}

void func_80800124_chfactorylinkgrill(s32 arg0)
{
    _chswitch_entrypoint_7(arg0,FLAG_1D9_UNK);
    _chswitch_entrypoint_9(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/linkgrill/func_80800150_chfactorylinkgrill.s")

OSThread *chfactorylinkgrill_entrypoint_1(void)
{
    extern u8 D_80800298_chfactorylinkgrill[];

    return (OSThread *) D_80800298_chfactorylinkgrill;
}

void func_808001B0_chfactorylinkgrill(Actor *arg0) {
    void _chdoormake_entrypoint_0(void*, f32, u32, s32);
    void _chdoormake_entrypoint_5(Actor*, f32);
    void _chdoormake_entrypoint_8(void*, u32);
    _chdoormake_entrypoint_0(arg0, -90.0f, 0U, 0x1D9);
    _chdoormake_entrypoint_5(arg0, 1.5f);
    _chdoormake_entrypoint_8(arg0, 2U);
}

OSThread *chfactorylinkgrill_entrypoint_2(void)
{
    extern u8 D_808002E0_chfactorylinkgrill[];

    return (OSThread *) D_808002E0_chfactorylinkgrill;
}
