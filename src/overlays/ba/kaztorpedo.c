#include "common.h"

s32 bakaztorpedo_entrypoint_0() 
{
    return 0x20;
}

f32 bakaztorpedo_entrypoint_1(void *arg0) {
    return *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 176) + 16);
}

/* extern */

void bakaztorpedo_entrypoint_2(void *arg0) {
    s32 func_8009EA08(f32);
    s32 func_800C2FDC(u8);
    func_8009EA08((*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0xB0)))) + (0x10))));
    func_800C2FDC((*(u8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0xB0)))) + (0x1C))));
}

void bakaztorpedo_entrypoint_3(void *arg0) {
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0xB0)))) + (0x10))) = 20.0f;
}

void bakaztorpedo_entrypoint_4(void *arg0) {
    s8 func_8009D454(void *, s32, s32 *);
    f32 func_8009EA88();
    extern s32 D_80800420_bakaztorpedo;
    f32 temp_f0;
    void *temp_v0;
    void *temp_v0_2;

    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0xB0)))) + (8))) = 0.0f;
    temp_v0 = (*(void **)((s8 *)(arg0) + (0xB0)));
    temp_f0 = (*(f32 *)((s8 *)(temp_v0) + (8)));
    (*(f32 *)((s8 *)(temp_v0) + (4))) = temp_f0;
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0xB0)))) + (0))) = temp_f0;
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0xB0)))) + (0x10))) = func_8009EA88();
    (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0xB0)))) + (0xC))) = 1;
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0xB0)))) + (0x18))) = 0.0f;
    temp_v0_2 = (*(void **)((s8 *)(arg0) + (0xB0)));
    (*(f32 *)((s8 *)(temp_v0_2) + (0x14))) = (f32) (*(f32 *)((s8 *)(temp_v0_2) + (0x18)));
    (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0xB0)))) + (0x1C))) = func_8009D454(arg0, 0, &D_80800420_bakaztorpedo);
}

void bakaztorpedo_entrypoint_5(void *arg0, f32 arg1, f32 arg2) {
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0xB0)))) + (4))) = arg1;
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0xB0)))) + (8))) = arg2;
}

void bakaztorpedo_entrypoint_6(void *arg0, s32 arg1) {
    *(s8 *)((u8 *)*(void **)((u8 *)arg0 + 176) + 12) = arg1;
}

void bakaztorpedo_entrypoint_7(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 176) + 24) = arg1;
}

void bakaztorpedo_entrypoint_8(void *arg0) {
    f32 func_800136E4(f32);
    f32 func_800D8FF8(void);
    s32 func_800C954C(void);
    void *func_80092AD8(void *);
    void func_800E0AF0(void *, f32);
    void func_800E0AFC(void *, u8, f32, f32, f32, f32);
    s32 func_8008E124(void *);
    void func_8009C128(void *, f32[3]);
    void func_800C31DC(u8, f32);
    void func_800C35E8(u8, f32[3]);
    void func_800C3BDC(u8);
    s32 func_800D2498(u32, s32, u32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    s32 func_800F1574(f32 *, f32);
    f32 func_800F15F8(f32, f32, f32);
    int func_800F8004(s32);
    void func_800FC660(u32);
    s32 player_inWater(void *);
    f32 sp64;
    f32 sp60;
    f32 sp5C;
    void *sp58;
    s32 active;
    s32 sp50;
    s32 sp4C;
    s32 value;
    f32 zero;
    f32 sp40;
    f32 sp34[3];
    void *data;

    sp60 = func_800D8FF8();
    data = *(void **)((u8 *)arg0 + 0xB0);
    switch (*(u8 *)((u8 *)data + 0xC)) {
        default: sp64 = 0.0f; break;
        case 2: sp64 = 1.0f; break;
        case 3: sp64 = 1.0f; break;
        case 4: sp64 = 3.0f; break;
    }
    sp5C = *(f32 *)((u8 *)data + 0x10);
    sp50 = func_8008E124(arg0);
    sp4C = func_800C954C();
    active = func_800F8004(*(s32 *)((u8 *)arg0 + 0x184));
    active = !sp50 && !sp4C && !active;
    if (active) {
        func_800F1574((f32 *)((u8 *)*(void **)((u8 *)arg0 + 0xB0) + 0x10), sp60 * sp64);
    }
    if (sp5C > 0.1f && *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 0xB0) + 0x10) <= 0.1f) {
        func_800FC660(0x19);
    }
    if (*(f32 *)((u8 *)*(void **)((u8 *)arg0 + 0xB0) + 0x10) > 0.0f) {
        value = func_800F10B4(*(f32 *)((u8 *)*(void **)((u8 *)arg0 + 0xB0) + 0x10), 0.0f, 20.0f, 1.0f, 20.99f);
    } else {
        value = 0;
    }
    func_800D2498(0xCB, value, 0);
    data = *(void **)((u8 *)arg0 + 0xB0);
    *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 0xB0) + 0x14) = func_800136E4(*(f32 *)((u8 *)data + 0x18) * sp60 + *(f32 *)((u8 *)data + 0x14));
    sp58 = func_80092AD8(arg0);
    func_800E0AF0(sp58, 1.0f);
    func_800E0AFC(sp58, 0x5D, 1.0f, 0.0f, 0.0f, *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 0xB0) + 0x14));
    if (player_inWater(arg0)) {
        func_8009C128(arg0, sp34);
        sp40 = func_800F10B4(*(f32 *)((u8 *)*(void **)((u8 *)arg0 + 0xB0) + 0x18), 300.0f, 1200.0f, 0.7f, 1.5f);
        func_800C35E8(*(u8 *)((u8 *)*(void **)((u8 *)arg0 + 0xB0) + 0x1C), sp34);
        func_800C31DC(*(u8 *)((u8 *)*(void **)((u8 *)arg0 + 0xB0) + 0x1C), sp40);
        func_800C3BDC(*(u8 *)((u8 *)*(void **)((u8 *)arg0 + 0xB0) + 0x1C));
    }
    data = *(void **)((u8 *)arg0 + 0xB0);
    *(f32 *)*(void **)((u8 *)arg0 + 0xB0) = func_800F15F8(*(f32 *)data, *(f32 *)((u8 *)data + 4), sp60 * 100.0f);
    zero = 0.0;
    func_800E0AFC(sp58, 0x6C, 1.0f, *(f32 *)*(void **)((u8 *)arg0 + 0xB0), 0.0, 0.0);
    func_800E0AFC(sp58, 0x6C, 1.0f, 0.0f, *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 0xB0) + 8), 0.0f);
}
