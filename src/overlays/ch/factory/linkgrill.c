#include "ch/factory/linkgrill.h"

/* extern */

void func_80800000_chfactorylinkgrill(Actor *arg0) {
    s32 _gccubesearch_entrypoint_10(s32, u32, Actor *);

    arg0->unk79_4 = _gccubesearch_entrypoint_10(0x3E8, arg0->pad6C_21, arg0);
    if (func_800DA298(arg0->unk79_4 + 0x1C0) != 0) {
        func_800FFAB0(arg0);
    }
}

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

void func_80800150_chfactorylinkgrill(s32 arg0, s32 arg1, s32 arg2) {
    s32 _chswitch_entrypoint_10(s32, s32, s32);
    s32 func_80101180(s32, s32, s32);
    if (arg1 == 7) {
        func_80101180(0x3FA, 7, 0);
    }
    _chswitch_entrypoint_10(arg0, arg1, arg2);
}

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
