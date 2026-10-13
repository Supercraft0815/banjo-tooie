#include "common.h"

void sufreezy_entrypoint_0(Actor *arg0) {
    f32 func_800DC178(f32, f32);
    arg0->unk58 = func_800DC178(6.0f, 10.0f);
}

void sufreezy_entrypoint_1(Actor *arg0)
{
    sufreezy_entrypoint_0(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/freezy/sufreezy_entrypoint_2.s")

void sufreezy_entrypoint_3(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_2(Actor*, f32[3], void*);
    extern s32 D_80800300_sufreezy;
    _subaddieaudioquick_entrypoint_2(arg0, NULL, &D_80800300_sufreezy);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/freezy/sufreezy_entrypoint_4.s")

/* extern */

void sufreezy_entrypoint_5(Unk80132ED0 *arg0, s32 arg1) {
    s32 func_8010114C(s32, s32, s32);
    Actor* func_80106790(Unk80132ED0 *);
    void func_8010A570(Actor*);
    s32 _sueggmisc_entrypoint_0(s32);
    func_8010A570(func_80106790(arg0));
    if (_sueggmisc_entrypoint_0(arg1) != 0) {
        func_8010114C(arg1, 5, 0);
    }
}

void sufreezy_entrypoint_6(Unk80132ED0 *arg0, s32 arg1) {
    f32 func_800DC178(f32, f32);
    Actor* func_80106790(Unk80132ED0 *);
    Actor *sp1C;

    sp1C = func_80106790(arg0);
    sp1C->unk58 = func_800DC178(6.0f, 10.0f);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/freezy/sufreezy_entrypoint_7.s")
