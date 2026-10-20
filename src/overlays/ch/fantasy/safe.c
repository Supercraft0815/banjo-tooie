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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fantasy/safe/func_80800630_chfantasysafe.s")

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
