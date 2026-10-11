#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4440/func_800FAB50.s")

void *func_800FABF4(f32 start[3], f32 end[3], f32 normal[3], u32 flags, f32 radius, f32 height) {
    void func_800EE7F8(f32 *, f32 *);
    void *func_800FAB50(f32 *, f32 *, f32 *, u32, f32);
    f32 shifted_start[3];
    f32 shifted_end[3];
    void *triangle;
    func_800EE7F8(shifted_start, start);
    func_800EE7F8(shifted_end, end);
    shifted_start[1] += height;
    shifted_end[1] += height;
    triangle = func_800FAB50(shifted_start, shifted_end, normal, flags, radius);
    if (triangle == NULL) return NULL;
    shifted_end[1] -= height;
    func_800EE7F8(end, shifted_end);
    return triangle;
}

void func_800FACA0(f32 arg0[3], s32 unused, u32 arg1) {
    void func_800EE7F8(f32 *, f32 *);
    s32 func_800C6A7C(s32, f32 *, f32 *, s32);
    f32 sp34[3];
    f32 sp28[3];
    f32 sp1C[3];
    u8 *temp_v0;

    func_800EE7F8(sp28, arg0);
    func_800EE7F8(sp1C, arg0);
    sp28[1] += 100.0f;
    sp1C[1] -= 500.0f;
    temp_v0 = (u8 *)func_800C6A7C((s32)sp28, sp1C, sp34, arg1);
    if ((temp_v0 != NULL) && (!(sp34[1] < 0.0f) || (*(u32 *)(temp_v0 + 8) & 0x10000)) && (arg0[1] < sp1C[1])) {
        arg0[1] = sp1C[1];
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4440/func_800FAD68.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4440/func_800FAE44.s")

void func_800FAF78(f32 arg0[3], f32 arg1[3], f32 arg2[3], f32 arg3[3], f32 arg4[3]) {
    void func_800EFB24(f32 *, f32 *, f32 *);
    f32 func_800EEAA4(f32 *, f32 *);
    f32 sp3C[3];
    f32 sp30[3];
    f32 sp24[3];
    f32 phi_f12;

    func_800EFB24(sp3C, arg1, arg0);
    func_800EFB24(sp30, arg3, arg2);
    func_800EFB24(sp24, sp3C, sp30);
    phi_f12 = -func_800EEAA4(arg4, sp24);
    if (phi_f12 < 5.0f) phi_f12 = 5.0f;
    arg1[0] += phi_f12 * arg4[0];
    arg1[1] += phi_f12 * arg4[1];
    arg1[2] += phi_f12 * arg4[2];
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4440/func_800FB040.s")

/* extern */

void func_800FB1B0(s32 arg0, f32 *arg1, s32 arg2) {
    s32 func_800C6A7C(s32, f32 *, f32 *, s32);
    void func_800EE7F8(f32 *, f32 *);
    f32 sp24[3];
    f32 sp18[3];

    func_800EE7F8(sp18, arg1);
    func_800C6A7C(arg0, sp18, sp24, arg2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4440/func_800FB1EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4440/func_800FB2AC.s")

s32 func_800FB338(void *arg0, s32 arg1, s32 arg2, f32 *arg3) {
    *arg3 = (*(f32 *)((s8 *)(arg0) + (4)));
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4440/func_800FB350.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4440/func_800FB3C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4440/func_800FB434.s")

void func_800FB508(void *arg0, void *arg1) {
    (*(u16 *)((s8 *)(arg0) + (0))) = (u16) (*(u16 *)((s8 *)(arg1) + (0)));
    (*(u16 *)((s8 *)(arg0) + (2))) = (u16) (*(u16 *)((s8 *)(arg1) + (2)));
    (*(u16 *)((s8 *)(arg0) + (4))) = (u16) (*(u16 *)((s8 *)(arg1) + (4)));
    (*(s32 *)((s8 *)(arg0) + (8))) = (s32) (*(s32 *)((s8 *)(arg1) + (8)));
    (*(s16 *)((s8 *)(arg0) + (6))) = (s16) (*(s16 *)((s8 *)(arg1) + (6)));
}
