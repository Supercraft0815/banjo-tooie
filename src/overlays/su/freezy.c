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

void sufreezy_entrypoint_4(Unk80132ED0 *arg0, s32 arg1) {
    Actor *func_80106790(Unk80132ED0 *);
    s32 func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    void func_801094E0(f32 *, f32);
    extern s32 D_80800314_sufreezy;
    extern s32 D_80800328_sufreezy;
    Actor *actor;

    actor = func_80106790(arg0);
    func_800BBCB8(actor->position, actor->position, actor->scale, arg1, &D_80800328_sufreezy);
    _subaddieaudioquick_entrypoint_2(actor, NULL, &D_80800314_sufreezy);
    func_801094E0(actor->position, actor->scale * 1.4f);
}

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

void sufreezy_entrypoint_7(Unk80132ED0 *arg0, s32 arg1) {
    s32 _glhittableDll_entrypoint_2(s32);
    s32 _glhittableDll_entrypoint_4(void *, Unk80132ED0 *);
    s32 _subaddielink_entrypoint_0(u8 *);
    Actor *_subaddielink_entrypoint_4(u8 *);
    void func_800EB210(void *, void *, s32);
    void func_800EB2DC(void *, s32, s32);
    void *func_80100094(Actor *, u32);
    s32 func_8010108C(Actor *, s32, s32);
    void func_80102190(void *, s32);
    Actor *func_80106790(Unk80132ED0 *);
    void func_8010A570(Actor *);
    void func_8010A590(Actor *);
    Actor *sp2C;
    s32 pad;
    s32 sp24;
    s32 pad2;
    volatile Actor *actor;

    sp2C = func_80106790(arg0);
    actor = _subaddielink_entrypoint_4(func_80100094(sp2C, 1));
    func_8010A570(sp2C);
    func_8010A590(actor);
    func_80102190(actor, 0);
    *((volatile u8 *)actor + 0x7B) &= ~4;
    func_8010108C(actor, 4, 0);
    sp24 = _glhittableDll_entrypoint_4(arg0, actor->unk0);
    if (_glhittableDll_entrypoint_2(sp24)) {
        func_800EB2DC(actor->unk0, arg0, sp24);
    } else {
        func_800EB210(actor->unk0, arg0, 2);
    }
    _subaddielink_entrypoint_0(func_80100094(sp2C, 1));
}
