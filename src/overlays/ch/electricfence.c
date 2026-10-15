#include "common.h"

OSThread *chelectricfence_entrypoint_0(void)
{
    extern u8 D_808004C0_chelectricfence[];

    return (OSThread *) D_808004C0_chelectricfence;
}

/* extern */

void func_8080000C_chelectricfence(s32 arg0) {
    s32 func_800EA05C();
    s32 func_80104004(s32, s32, s32);
    s32 func_8010A570(s32);
    s32 func_8010A624(s32);
    if (func_800EA05C() == 0x124) {
        func_8010A624(arg0);
        func_8010A570(arg0);
    }
    func_80104004(arg0, arg0 + 0x18, arg0 + 0x28);
}

void func_80800060_chelectricfence(Actor *arg0) {
    s32 _subaddieaudioloop_entrypoint_5(s32, s32, s32, s32, s32 *);
    s32 chelectricfence_entrypoint_2(Actor *, u32 *, u32 *);
    u8 func_800D9078(f32 *);
    int func_800DC298(f32);
    void func_8010A590(Actor *);
    extern s32 D_80800508_chelectricfence;
    if (func_800D9078(&arg0->unk58) != 0) {
        func_8010A590(arg0);
    }
    _subaddieaudioloop_entrypoint_5((s32)arg0, (s32)arg0->position, arg0->unk70_10 == 1, -1, &D_80800508_chelectricfence);
    if ((arg0->unk70_10 == 1) && arg0->unk7C_12 && (func_800DC298(0.2f) != 0)) {
        chelectricfence_entrypoint_2(arg0, arg0->actorData, &arg0->actorData[4]);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/electricfence/func_8080010C_chelectricfence.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/electricfence/chelectricfence_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/electricfence/chelectricfence_entrypoint_2.s")
