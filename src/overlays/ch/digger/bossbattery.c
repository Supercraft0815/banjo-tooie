#include "common.h"

OSThread *chdiggerbossbattery_entrypoint_0(void)
{
    extern u8 D_808002F0_chdiggerbossbattery[];

    return (OSThread *) D_808002F0_chdiggerbossbattery;
}

/* extern */

void func_8080000C_chdiggerbossbattery(Actor *arg0) {
    s32 func_800DA298(s32);
    f32 func_800DC178(f32, f32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EFD24(f32 *);
    void func_800FFAB0(Actor *);
    void func_80102FDC(Actor *, f32);
    func_800EE7F8((f32 *)arg0->actorData, arg0->position);
    func_800EFD24(arg0->position);
    func_80102FDC(arg0, 0.25f);
    arg0->unk58 = func_800DC178(1.5f, 3.0f);
    if (func_800DA298(arg0->unk74_7 + 0xA1D) != 0) {
        func_800FFAB0(arg0);
    }
}

void func_80800090_chdiggerbossbattery(Actor *arg0) {
    void _chelectricfence_entrypoint_1(Actor *, f32 *);
    s32 _subaddieaudioloop_entrypoint_4(Actor *, f32 *, u32, u32 *);
    u8 func_800D9078(f32 *);
    f32 func_800DC178(f32, f32);
    int func_800DC298(f32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF1B8(f32 *, f32, f32);
    extern u32 D_80800338_chdiggerbossbattery;
    f32 sp2C[3];


    _subaddieaudioloop_entrypoint_4(arg0, (f32 *)arg0->actorData, 1, &D_80800338_chdiggerbossbattery);
    if (func_800D9078(&arg0->unk58) != 0) {
        func_800EE7F8(sp2C, (f32 *)arg0->actorData);
        func_800EF1B8(sp2C, (func_800DC298(0.5f) ? 1.0f : -1.0f) * 90.0f, 80.0f);
        sp2C[1] += 300.0f;
        _chelectricfence_entrypoint_1(arg0, sp2C);
        arg0->unk58 = func_800DC178(1.5f, 3.0f);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/bossbattery/func_80800170_chdiggerbossbattery.s")
