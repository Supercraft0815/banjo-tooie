#include "common.h"

OSThread *chtntdetonator_entrypoint_0(void)
{
    extern u8 D_808006A8_chtntdetonator[];

    return (OSThread *) D_808006A8_chtntdetonator;
}

void func_8080000C_chtntdetonator(Actor *arg0) {
    s32 _subaddiefade_entrypoint_14(s32);
    void func_80102FDC(Actor*, f32);
    s32 func_8010A63C(s32);
    func_80102FDC(arg0, arg0->scale * 0.5f);
    _subaddiefade_entrypoint_14((s32) arg0);
    func_8010A63C((s32) arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/tnt/detonator/func_80800054_chtntdetonator.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/tnt/detonator/func_80800148_chtntdetonator.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/tnt/detonator/func_8080021C_chtntdetonator.s")

void func_808002D8_chtntdetonator(u8 *arg0) {
    s32 *_fxgenlist_entrypoint_2(void);
    void func_80018820(s32, f32, f32);
    s32 func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    void func_800C4AF0(f32 *, void *);
    s32 func_800E1610(s32, f32, f32, f32 *);
    void func_800EE7F8(f32 *, f32 *);
    void func_80800380_chtntdetonator(u8 *);
    void func_808003C0_chtntdetonator(u8 *);
    extern s32 D_808006F0_chtntdetonator;
    f32 position[3];

    func_800EE7F8(position, (f32 *)(arg0 + 4));
    position[1] += 270.0f;
    func_800BBCB8(position, NULL, 1.5f, 1, _fxgenlist_entrypoint_2());
    func_808003C0_chtntdetonator(arg0);
    func_80800380_chtntdetonator(arg0);
    func_800C4AF0((f32 *)(arg0 + 4), &D_808006F0_chtntdetonator);
    func_800E1610(0, 30.0f, 0.9f, (f32 *)(arg0 + 4));
    func_80018820(0, 3.0f, 0.25f);
}

void func_80800380_chtntdetonator(u8 *arg0) {
    s32 func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    extern s32 D_80800704_chtntdetonator;
    func_800BBCB8((f32 *)(arg0 + 4), NULL, (*(f32 *)((s8 *)(arg0) + (0x38))), 12, &D_80800704_chtntdetonator);
}

void func_808003C0_chtntdetonator(u8 *arg0) {
    s32 func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    extern s32 D_80800754_chtntdetonator;
    func_800BBCB8((f32 *)(arg0 + 4), NULL, (*(f32 *)((s8 *)(arg0) + (0x38))), 15, &D_80800754_chtntdetonator);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/tnt/detonator/func_80800400_chtntdetonator.s")

void func_80800588_chtntdetonator(Actor *arg0) {
    s32 _subaddieaudioloop_entrypoint_4(Actor*, f32*, u32, u32*);
    extern u32 D_80800798_chtntdetonator;
    u32 temp_t7;

    temp_t7 = (u32)arg0->unk70_10 == 2;
    if ((temp_t7 != 0) || ((temp_t7 == 0) && (arg0->unk5F != 0))) {
        _subaddieaudioloop_entrypoint_4(arg0, (f32 *)((u8 *)arg0 + 0x18), temp_t7, &D_80800798_chtntdetonator);
    }
}

/* extern */

s32 chtntdetonator_entrypoint_1(Actor *arg0, s32 arg1) {
    s32 _subaddiefind_entrypoint_7(Actor *, s32, s32);
    s32 func_800DA298(GameFlag);
    void func_800FFA88(Unk80132ED0 *);
    void func_800FFAB0(Actor *);
    Actor *func_80106790(Unk80132ED0 *);
    Actor *var_v1;

    if (func_800DA298(arg1) != 0) {
        if (_subaddiefind_entrypoint_7(arg0, 0x149, 0x320) != -1) {
            func_800FFA88(arg0->unk3C);
        }
        func_800FFAB0(arg0);
        return 0;
    }
    if (_subaddiefind_entrypoint_7(arg0, 0x149, 0x320) != 0) {
        var_v1 = func_80106790(arg0->unk3C);
    } else {
        var_v1 = NULL;
    }
    if (var_v1 != NULL) {
        var_v1->unk3C = arg0->unk0;
    }
    return 1;
}
