#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/taxi/subaddietaxi_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/taxi/subaddietaxi_entrypoint_1.s")

/* extern */

s32 func_80800220_subaddietaxi(f32 *arg0, f32 arg1) {
    f32 func_80090010();
    f32 func_800F1DCC(f32, f32);
    f32 func_800F1DF4(f32 *, f32 *);
    void func_8010D254(f32 *);
    f32 mlAbsF(f32);
    f32 sp24[3];
    f32 currentYaw;
    f32 sp1C;

    func_8010D254(sp24);
    sp1C = func_800F1DF4(sp24, arg0 + 1);
    currentYaw = func_80090010();
    return mlAbsF(func_800F1DCC(currentYaw, sp1C)) < arg1;
}

/* extern */

int subaddietaxi_entrypoint_2(Actor *arg0, s32 arg1) {
    s32 func_8008FCC8(Unk80132ED0 *);
    s32 func_800905C4(Unk80132ED0 *, s32);
    u8 func_800CB3E0(s32);
    s32 temp_v0;

    temp_v0 = func_800CB3E0(arg1);
    if ((temp_v0 != 1) && (temp_v0 != 5)) {
        return 0;
    }
    if (func_80800220_subaddietaxi(arg0, 90.0f) == 0) {
        return 0;
    }
    if (_subaddiefade_entrypoint_0(arg0) < 0x78) {
        return 0;
    }
    return func_8008FCC8(arg0->unk0) == 0x13 &&
        func_800905C4(arg0->unk0, arg1) != 0;
}

void subaddietaxi_entrypoint_3(void) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/taxi/subaddietaxi_entrypoint_4.s")

s32 subaddietaxi_entrypoint_5(Actor *arg0, s32 arg1) {
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    s32 _subaddiefade_entrypoint_2();
    f32 func_800CB45C(volatile s32, f32 *, s32 *, s32 *);
    s32 func_800CB698(s32, s32);
    void func_800CB70C(s32);
    s32 func_800EA05C();
    void func_800EE7F8(f32 *, f32 *);
    void func_800FFAB0(Actor *);
    extern s32 D_80800D5C_subaddietaxi;
    s32 sp3C;
    s32 sp38;
    f32 sp2C[3];
    f32 sp28;
    s32 sp24;

    sp24 = 0;
    sp28 = func_800CB45C(arg1, sp2C, &sp3C, &sp38);
    if (func_800EA05C() == sp3C) {
        arg0->rotation[1] = sp28;
        func_800EE7F8(arg0->position, sp2C);
        arg0->unk74_7 = sp38;
        sp24 = 1;
        _subaddiefade_entrypoint_2(arg0);
        _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_80800D5C_subaddietaxi);
    } else {
        func_800FFAB0(arg0);
    }
    func_800CB698(arg1, 1);
    func_800CB70C(arg1);
    return sp24;
}

/* extern */

void subaddietaxi_entrypoint_6(s32 *arg0, volatile f32 arg1) {
    void func_800DFF64(s32 *, s32, s32);
    void func_800EFA4C(f32 *, f32, f32, f32);
    f32 sp1C[3];
    f32 scale = arg1;

    func_800EFA4C(sp1C, scale, scale, scale);
    func_800DFF64(arg0, 0x12, (s32)sp1C);
}

void *func_8010410C(void);

void subaddietaxi_entrypoint_7(Unk80132ED0 *arg0) {
    typedef struct { f32 position[3]; f32 rotation[3]; f32 scale; } TaxiState;
    Actor *func_80106790(Unk80132ED0 *);
    struct anctrl_s *func_80104248(void *);
    void func_800EE7F8(f32 *, f32 *);
    void func_8008AEE4(struct anctrl_s *, void (*)(s32 *, f32));
    void func_8008AF04(struct anctrl_s *, s32);
    s32 _subaddiefade_entrypoint_1(s32, s32);
    extern void _subaddietaxi_entrypoint_6(s32 *, f32);
    s32 pad;
    TaxiState *sp28;
    struct anctrl_s *sp24;
    union { f32 value; s32 bits; } sp20;
    Actor *actor;

    actor = func_80106790(arg0);
    sp28 = func_8010410C();
    sp24 = func_80104248(actor);
    func_800EE7F8(sp28->position, actor->position);
    sp28->scale = actor->scale;
    func_8008AEE4(sp24, _subaddietaxi_entrypoint_6);
    sp20.value = 1.0f;
    func_8008AF04(sp24, sp20.bits);
    _subaddiefade_entrypoint_1((s32)actor, 0xFF);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/taxi/subaddietaxi_entrypoint_8.s")

/* extern */

void subaddietaxi_entrypoint_9(Actor *arg0, s32 arg1) {
    void func_800CB6B4(s32, f32 *, f32, s32);
    s32 func_800EA05C();
    if (!arg0->unk64_17) {
        func_800CB6B4(arg1, (f32 *)((u8 *)arg0 + 4), *(f32 *)((u8 *)arg0 + 0x48), func_800EA05C());
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/taxi/subaddietaxi_entrypoint_10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/taxi/subaddietaxi_entrypoint_11.s")

s32 subaddietaxi_entrypoint_12(u8 *arg0, s32 arg1) {
    return (*(f32 *)(arg0 + 0x34)) == 0.0f;
}

/* extern */

s32 subaddietaxi_entrypoint_13(Actor *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 func_800CB4D0(s32, s32, s32);
    void func_800CB70C(s32);
    void func_800CB764(s32, f32 *, f32, s32, s32);
    s32 func_800EA05C();
    s32 sp24;
    s32 temp_v0;

    temp_v0 = func_800CB4D0(arg1, arg2, arg3);
    sp24 = temp_v0;
    if (temp_v0 != 0) {
        func_800CB764(arg1, arg0->position, arg0->rotation[1], func_800EA05C(), arg0->unk74_7);
        func_800CB70C(arg1);
    }
    arg0->unk14 = 0x420021;
    return sp24;
}

/* extern */

void subaddietaxi_entrypoint_14(s32 arg0, s32 arg1) {
    (*(s16 *)((s8 *)(func_8010410C()) + (0x20))) = 0;
    _subaddieDll_entrypoint_4(arg0, 1);
}

/* extern */
s32 subaddietaxi_entrypoint_15(s32 arg0, s32 arg1) {
    func_801078DC((Actor *)arg0, (u8 *)func_8010410C() + 0x20);
    if (_subaddiefade_entrypoint_0(arg0) == 0xFF) {
        _subaddieDll_entrypoint_4((Actor *)arg0, 0);
        return 1;
    }
    return 0;
}

void func_80800C00_subaddietaxi(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    void func_800BBCB8(f32[3], s32, f32, s32, s32 *);
    extern s32 D_80800D50_subaddietaxi;
    extern s32 D_80800D74_subaddietaxi;
    f32 *sp24[2];

    sp24[1] = arg0->position; func_800BBCB8(sp24[1], (s32)sp24[1], 1.0f, 6, &D_80800D74_subaddietaxi);
    _subaddieaudioquick_entrypoint_2(arg0, sp24[1], &D_80800D50_subaddietaxi);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/taxi/subaddietaxi_entrypoint_16.s")

s32 func_80800CF0_subaddietaxi(s32 arg0) {
    extern s16 D_80800DB4_subaddietaxi[];
    return ((s16 *)&D_80800DB4_subaddietaxi)[arg0];
}
