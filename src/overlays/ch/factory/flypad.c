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
void func_80800088_chfactoryflypad(Actor *arg0) {
    s32 _glcutDll_entrypoint_19(u32);
    void func_800FFAB0(Actor *);
    void func_80108B04(Actor *, u32);
    s32 sp1C;
    sp1C = 0;
    if ((arg0->unk74_7 == 0x32) && (_glcutDll_entrypoint_19(0x42) != 0)) {
    func_80108B04(arg0, 0);
    sp1C = 1;
    }
    if ((_glcutDll_entrypoint_19(0x42) == 0) && (func_800DA298(FLAG_16B_UNK) != 0)) {
    func_80108B04(arg0, 0);
    sp1C = 1;
    }
    if ((sp1C == 0) && (_glcutDll_entrypoint_19(0x42) == 0)) {
    func_800FFAB0(arg0);
    }
    }

s32 func_80800130_chfactoryflypad(Actor *arg0, s32 arg1, s32 arg2) {
    void _capod_entrypoint_13(Unk80132ED0 *, Unk80132ED0 *, u32, u32);
    void _chappearfx_entrypoint_1(Actor *, u32, u32, f32);
    s32 _glcutDll_entrypoint_19(u32);
    Unk80132ED0 **_subaddiefind_entrypoint_1(Actor *, s32, s32, s32);
    void func_800FFAB0(Actor *);
    Actor *func_801084B0(s32, Actor **);
    void func_80108B04(Actor *, u32);
    Actor *sp1C;

    switch (arg1) {
    case 0x3D:
        sp1C = func_801084B0(0x234, &arg0);
        if (_glcutDll_entrypoint_19(0x42) != 0) {
            _chappearfx_entrypoint_1(sp1C, 0x22, 2, 1.0f);
        }
        func_800FFAB0(arg0);
        break;
    case 0x49:
        if ((arg0->unk74_7 == 0x32) && (_glcutDll_entrypoint_19(0x42) != 0)) {
            _capod_entrypoint_13(arg0->unk0, *_subaddiefind_entrypoint_1(arg0, 0x42F, -1, 0), 5, 0x900);
            break;
        }
        return 0;
    case 0xC:
        func_80108B04(arg0, 0);
        return 3;
    case 0x95:
        func_80800088_chfactoryflypad(arg0);
        break;
    default:
        return 0;
    }
    return 1;
}
