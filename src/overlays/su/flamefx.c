#include "common.h"

void suflamefx_entrypoint_0(Actor *arg0, u32 arg1, s32 arg2, s16 arg3) {
    u32* func_80100074(Actor*, u32, u32);
    void* func_80100094(Actor*, u32);
    u8 *temp_v0;

    func_80100074(arg0, arg1, (arg2 * 0x30) + 0x20);
    temp_v0 = func_80100094(arg0, arg1);
    (*(s16 *)((s8 *)(temp_v0) + (0x18))) = arg3;
    (*(s8 *)((s8 *)(temp_v0) + (0x1B))) = (s8) arg2;
}

void suflamefx_entrypoint_1(Actor *arg0, u32 arg1) {
    u32* func_80100074(Actor*, u32, u32);
    func_80100074(arg0, arg1, 0U);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/flamefx/suflamefx_entrypoint_2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/flamefx/suflamefx_entrypoint_3.s")

void suflamefx_entrypoint_4(void *arg0) {
    (*(s8 *)((s8 *)(arg0) + (0x1C))) = 1;
}

void suflamefx_entrypoint_5(void *arg0, f32 arg1, f32 arg2) {
    (*(s16 *)((s8 *)(arg0) + (0xC))) = (s16) (s32) arg1;
    (*(s16 *)((s8 *)(arg0) + (0xE))) = (s16) (s32) arg2;
}

void suflamefx_entrypoint_6(f32 *arg0, f32 arg1) {
    arg0[5] = arg1;
}

/* extern */

void suflamefx_entrypoint_7(u8 *arg0, f32 *arg1, f32 arg2, f32 arg3, f32 arg4, u8 arg5, f32 arg6) {
    s32 func_800AF5A0(s16 *);
    void *func_800D674C(s32);
    f32 func_800DC178(f32, f32);
    void func_80800428_suflamefx(u8 *, u8 *, f32 *);
    s32 var_s1;
    u8 *var_s0;

    (*(f32 *)((s8 *)(arg0) + (8))) = arg2;
    (*(f32 *)((s8 *)(arg0) + (4))) = arg3;
    (*(f32 *)((s8 *)(arg0) + (0))) = arg4;
    (*(u8 *)((s8 *)(arg0) + (0x1A))) = arg5;
    (*(f32 *)((s8 *)(arg0) + (0x10))) = arg6;
    (*(s16 *)((s8 *)(arg0) + (0xC))) = 0x64;
    (*(s16 *)((s8 *)(arg0) + (0xE))) = 0xC8;
    (*(f32 *)((s8 *)(arg0) + (0x14))) = -0.03f;
    (*(s8 *)((s8 *)(arg0) + (0x1C))) = 0;
    if (arg0[0x1A] == 0xFF) {
        (*(u8 *)((s8 *)(arg0) + (0x1D))) = (func_800AF5A0(func_800D674C((*(s16 *)((s8 *)(arg0) + (0x18))))) - 1);
    } else {
        (*(u8 *)((s8 *)(arg0) + (0x1D))) = 0xFF;
    }
    var_s0 = arg0 + 0x20;
    var_s1 = 0;
    if ((s32) (*(u8 *)((s8 *)(arg0) + (0x1B))) > 0) {
        do {
            func_80800428_suflamefx(arg0, var_s0, arg1);
            (*(f32 *)((s8 *)(var_s0) + (0x28))) = func_800DC178(0.0f, (*(f32 *)((s8 *)(arg0) + (4))));
            var_s1 += 1;
            var_s0 += 0x30;
        } while (var_s1 < (s32) (*(u8 *)((s8 *)(arg0) + (0x1B))));
    }
}

/* extern */

void func_80800428_suflamefx(u8 *arg0, u8 *arg1, f32 *arg2) {
    s32 func_800DC128(s32, s32);
    f32 func_800DC178(f32, f32);
    void func_800E3980(f32 *);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EFCD8(f32 *, f32, f32);
    f32 func_800F1DF4(f32 *, f32 *);
    f32 sp2C[3];
    f32 sp28;
    s32 var_v0;

    (*(f32 *)((s8 *)(arg1) + (0x10))) = func_800DC178(0.0f, 20.0f);
    (*(f32 *)((s8 *)(arg1) + (0x24))) = func_800DC178((f32) (*(s16 *)((s8 *)(arg0) + (0xC))), (f32) (*(s16 *)((s8 *)(arg0) + (0xE))));
    (*(f32 *)((s8 *)(arg1) + (0x28))) = func_800DC178((*(f32 *)((s8 *)(arg0) + (8))), (*(f32 *)((s8 *)(arg0) + (4))));
    var_v0 = (*(u8 *)((s8 *)(arg0) + (0x1A)));
    if (var_v0 == 0xFF) {
        (*(u8 *)((s8 *)(arg1) + (0x2C))) = func_800DC128(0, (*(u8 *)((s8 *)(arg0) + (0x1D))));
    } else {
        (*(u8 *)((s8 *)(arg1) + (0x2C))) = var_v0;
    }
    func_800EE7F8((f32 *)arg1, arg2);
    func_800E3980(sp2C);
    sp28 = func_800F1DF4((f32 *)arg1, sp2C);
    func_800EFCD8((f32 *)(arg1 + 0xC), func_800DC178(-90.0f, 90.0f) + sp28, (*(f32 *)arg0));
}
