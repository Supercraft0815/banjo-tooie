#include "common.h"

/* extern */

void func_80800000_chsunlightspell(Actor *arg0) {
    s32 func_800DA298(s32);
    void func_800FFA88(Unk80132ED0*);
    void func_80800404_chsunlightspell(Actor *, s32);
    if (func_800DA298(0xE9) != 0) {
        func_800FFA88(arg0->unk0);
        return;
    }
    func_80800404_chsunlightspell(arg0, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/sunlightspell/func_80800048_chsunlightspell.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/sunlightspell/func_80800404_chsunlightspell.s")

void func_80800668_chsunlightspell(Actor *arg0) {
    s32 func_800BFFB4(s32, s32, f32 *);
    void func_800E3980(f32 *);
    void func_800EE780(f32 *, f32 *, f32 *);
    void func_800EEBF0(f32 *, f32 *, f32);
    void func_800F18FC(f32 *, f32 *, f32 *);
    extern f32 D_808008B0_chsunlightspell[3];
    f32 sp34[3];
    f32 sp28[3];
    f32 sp20[2];

    if (func_800BFFB4(0, 4, sp34) != 0) {
        func_800E3980(sp28);
        func_800F18FC(sp28, sp34, sp20);
        func_800EEBF0(sp34, sp20, 1000.0f);
        func_800EE780(arg0->position, sp28, sp34);
        func_800F18FC(arg0->position, D_808008B0_chsunlightspell, sp20);
        arg0->rotation[1] = sp20[1];
        arg0->rotation[0] = sp20[0];
    }
}

/* extern */

void func_80800704_chsunlightspell(Actor *arg0, s32 arg1) {
    void* func_80100094(Actor*, u32);
    s32 _sumumbofx_entrypoint_14(u8 *);
    s32 _sumumbofx_entrypoint_7(u8 *, s32, s32, s32, f32 *, s32, s32);
    _sumumbofx_entrypoint_7(func_80100094(arg0, 1U), arg1, 0, 0x2E, arg0->position, 0, 0);
    _sumumbofx_entrypoint_14(func_80100094(arg0, 1U));
}

/* extern */

void func_80800768_chsunlightspell(Actor *arg0, u8 *arg1) {
    void* func_80100094(Actor*, u32);
    void func_80101870(Actor* arg0, void* arg1);
    s32 _sumumbofx_entrypoint_8(u8 *, u8 *);
    if (func_80100094(arg0, 1U) != NULL) {
        _sumumbofx_entrypoint_8(func_80100094(arg0, 1U), arg1);
    }
    if (arg0->unk64_19) {
        func_80101870(arg0, arg1);
    }
}

/* extern */

s32 func_808007CC_chsunlightspell(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _subaddieDll_entrypoint_0(Actor *);
    void func_800FFA88(Unk80132ED0 *);
    void func_80800404_chsunlightspell(Actor *, s32);

    switch (arg1) {
    case 0x4B:
        _subaddieDll_entrypoint_0(arg0);
        func_80800404_chsunlightspell(arg0, 2);
        return 1;
    case 0x2E:
        func_800FFA88(arg0->unk0);
        return 1;
    default:
        return 0;
    }
}

OSThread *chsunlightspell_entrypoint_0(void)
{
    extern u8 D_808008BC_chsunlightspell[];

    return (OSThread *) D_808008BC_chsunlightspell;
}
