#include "common.h"

void func_80800000_chfantasysafe(Actor *arg0) {
    s32 _glcutDll_entrypoint_20();
    s32 func_800DA298(s32);
    void func_800EFA4C(f32 *, f32, f32, f32);
    void func_80101FDC(Actor *, u32);
    extern f32 D_80800998_chfantasysafe[];
    f32 angle;
    s32 fourth;
    s32 pad;
    s32 third;
    s32 second;
    s32 first;

    func_800EFA4C(arg0->position, 4539.4f, -748.6f, 2277.6f);
    if (_glcutDll_entrypoint_20()) {
        arg0->actorData[4] = 0;
        arg0->unk79_4 = 0;
        ((f32 *)arg0->actorData)[7] = 0.0f;
        ((f32 *)arg0->actorData)[3] = 0.0f;
        arg0->unk50 = 0.0f;
        arg0->unk54 = 0.0f;
        arg0->unk58 = 0.0f;
        arg0->rotation[1] = 228.0f;
        func_80101FDC(arg0, 6);
        return;
    }
    if (func_800DA298(0x38D)) {
        arg0->rotation[1] = 360.0f;
        arg0->unk50 = 0.0f;
        arg0->unk54 = 110.0f;
        func_80101FDC(arg0, 5);
        return;
    }
    first = func_800DA298(0x38B) ? 1 : 0;
    second = func_800DA298(0x38A) ? 1 : 0;
    third = func_800DA298(0x389) ? 1 : 0;
    fourth = func_800DA298(0x38C) ? 1 : 0;
    angle = D_80800998_chfantasysafe[fourth + third + second + first];
    ((f32 *)arg0->actorData)[7] = angle;
    ((f32 *)arg0->actorData)[3] = angle;
    arg0->unk50 = angle;
    arg0->unk54 = 0.0f;
    arg0->rotation[1] = 228.0f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fantasy/safe/func_808001A0_chfantasysafe.s")

s32 func_80800630_chfantasysafe(Actor *arg0, s32 arg1, s32 arg2) {
    void _capod_entrypoint_13(Unk80132ED0 *, Unk80132ED0 *, u32, u32);
    s32 _glcutDll_entrypoint_20();
    s32 func_800DA298(s32);
    int func_800DB9B0(void);
    void func_800DF744(s32, s32);
    s32 func_801015D0(Actor *);
    void func_80101FDC(Actor *, u32);
    extern f32 D_80800998_chfantasysafe[];
    s32 index;
    s32 flags;

    switch (arg1) {
    case 0x49:
        index = arg2 - 0x51;
        flags = 0x810 | (func_800DB9B0() ? 0x100 : 0);
        if (index < 4 && index >= 0) {
            arg0->unk58 = 2.0f;
            func_80101FDC(arg0, 2);
            arg0->unk6C_0 = index;
            ((f32 *)arg0->actorData)[7] = arg0->unk50 = D_80800998_chfantasysafe[index];
            ((f32 *)arg0->actorData)[3] = D_80800998_chfantasysafe[index + 1];
            if ((func_800DA298(0x389) ? 1 : 0) +
                (func_800DA298(0x38A) ? 1 : 0) +
                (func_800DA298(0x38B) ? 1 : 0) +
                (func_800DA298(0x38C) ? 1 : 0) >= 3) {
                _capod_entrypoint_13(arg0->unk0, NULL, 0, flags);
            } else {
                _capod_entrypoint_13(arg0->unk0, NULL, 2, flags);
            }
            return 1;
        }
        return 0;
    case 0x1F:
        func_801015D0(arg0);
        if (_glcutDll_entrypoint_20()) {
            func_800DF744(1, (arg0->unk79_4 & 1) ? 1 : 0);
            func_800DF744(2, (arg0->unk79_4 & 2) ? 1 : 0);
            func_800DF744(3, (arg0->unk79_4 & 4) ? 1 : 0);
            func_800DF744(4, (arg0->unk79_4 & 8) ? 1 : 0);
        } else {
            func_800DF744(1, func_800DA298(0x389) ? 1 : 0);
            func_800DF744(2, func_800DA298(0x38A) ? 1 : 0);
            func_800DF744(3, func_800DA298(0x38B) ? 1 : 0);
            func_800DF744(4, func_800DA298(0x38C) ? 1 : 0);
        }
        return 1;
    }
    return 0;
}

OSThread *chfantasysafe_entrypoint_0(void)
{
    extern u8 D_80800AA0_chfantasysafe[];

    return (OSThread *) D_80800AA0_chfantasysafe;
}

OSThread *chfantasysafe_entrypoint_1(void)
{
    extern u8 D_80800AE8_chfantasysafe[];

    return (OSThread *) D_80800AE8_chfantasysafe;
}
