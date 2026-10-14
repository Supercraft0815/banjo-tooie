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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/taxi/subaddietaxi_entrypoint_2.s")

void subaddietaxi_entrypoint_3(void) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/taxi/subaddietaxi_entrypoint_4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/taxi/subaddietaxi_entrypoint_5.s")

/* extern */

void subaddietaxi_entrypoint_6(s32 *arg0, volatile f32 arg1) {
    void func_800DFF64(s32 *, s32, s32);
    void func_800EFA4C(f32 *, f32, f32, f32);
    f32 sp1C[3];
    f32 scale = arg1;

    func_800EFA4C(sp1C, scale, scale, scale);
    func_800DFF64(arg0, 0x12, (s32)sp1C);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/taxi/subaddietaxi_entrypoint_7.s")

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
