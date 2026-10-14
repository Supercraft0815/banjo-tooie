#include "common.h"

s32 ncba1p_entrypoint_0() 
{
    return 0x54;
}

int func_80800008_ncba1p(s32 arg0, f32 *arg1, f32 *arg2) {
    f32 func_800EEAD4(f32 *, f32 *);
    return func_800EEAD4(arg1, arg2) < 40.0f;
}

/* extern */

void func_8080004C_ncba1p(void **arg0, s32 arg1) {
    s32 func_800F7B9C(s32, s32);
    s32 func_80110840();
    s32 temp_a0;

    temp_a0 = func_80110840();
    if ((*(u8 *)((s8 *)(*arg0) + (0x51))) == 0) {
        func_800F7B9C(temp_a0, arg1);
        (*(s8 *)((s8 *)(*arg0) + (0x51))) = 1;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/ba/1p/func_808000A0_ncba1p.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/ba/1p/func_80800230_ncba1p.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/ba/1p/func_808003DC_ncba1p.s")

/* extern */

void ncba1p_entrypoint_1(u8 **arg0) {
    s32 _plcamera_entrypoint_1(s32);
    s32 func_800EFD24(u8 *);
    s32 func_80110840();
    s32 func_80111590(u8 **, s32, s32, s32, f32);
    if (_plcamera_entrypoint_1(func_80110840()) == 0) {
        func_800EFD24(*arg0);
        func_800EFD24(*arg0 + 0xC);
        func_800EFD24(*arg0 + 0x18);
        func_800EFD24(*arg0 + 0x24);
        func_800EFD24(*arg0 + 0x30);
        func_800EFD24(*arg0 + 0x3C);
        (*(s32 *)((s8 *)(*arg0) + (0x4C))) = 0;
        (*(s8 *)((s8 *)(*arg0) + (0x50))) = 1;
        (*(s8 *)((s8 *)(*arg0) + (0x51))) = 0;
        func_80111590(arg0, 0x41200000, 0x41A00000, 0x42F00000, 300.0f);
    }
}

/* extern */

void ncba1p_entrypoint_2(u8 **arg0) {
    s32 ncba1p_entrypoint_3(u8 **, s32 *, s32 *);
    s32 sp24[3];
    s32 sp18[3];

    (*(s32 *)((s8 *)(*arg0) + (0x4C))) = 2;
    (*(s8 *)((s8 *)(*arg0) + (0x50))) = 0;
    ncba1p_entrypoint_3(arg0, sp24, sp18);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/ba/1p/ncba1p_entrypoint_3.s")

void ncba1p_entrypoint_4(void *arg0, s32 arg1) {
    *(s8 *)((u8 *)*(void **)((u8 *)arg0 + 0) + 80) = arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/ba/1p/ncba1p_entrypoint_5.s")

/* extern */

void ncba1p_entrypoint_6(f32 **arg0, f32 *arg1) {
    void func_800EE7F8(f32 *, f32 *);
    func_800EE7F8(*arg0 + 6, arg1);
}

/* extern */

void ncba1p_entrypoint_7(void **arg0, void *arg1) {
    f32 func_800136E4(f32);
    (*(f32 *)((s8 *)(*arg0) + (0x24))) = func_800136E4((*(f32 *)((s8 *)(arg1) + (0))));
    (*(f32 *)((s8 *)(*arg0) + (0x28))) = func_800136E4((*(f32 *)((s8 *)(arg1) + (4))));
    (*(f32 *)((s8 *)(*arg0) + (0x2C))) = func_800136E4((*(f32 *)((s8 *)(arg1) + (8))));
}

void ncba1p_entrypoint_8(f32 **arg0, f32 *arg1) {
    void func_800EE7F8(f32 *, f32 *);
    func_800EE7F8(arg1, *arg0 + 9);
}

f32 ncba1p_entrypoint_9(void *arg0) {
    return *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 0) + 16);
}

s32 ncba1p_entrypoint_10(void *arg0) {
    return *(s32 *)((u8 *)*(void **)((u8 *)arg0 + 0) + 76);
}

f32 ncba1p_entrypoint_11(void *arg0) {
    return *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 0) + 72);
}

void ncba1p_entrypoint_12(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 0) + 72) = arg1;
}

void ncba1p_entrypoint_13(f32 **volatile arg0, f32 *arg1, f32 *arg2) { void func_800EE7F8(f32 *, f32 *);
    func_800EE7F8(arg1, *arg0);
    func_800EE7F8(arg2, *arg0 + 3);
}
