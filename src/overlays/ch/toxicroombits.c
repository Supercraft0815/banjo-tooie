#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/toxicroombits/func_80800000_chtoxicroombits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/toxicroombits/func_808001D4_chtoxicroombits.s")

OSThread *chtoxicroombits_entrypoint_0(void)
{
    extern u8 D_80800FB0_chtoxicroombits[];

    return (OSThread *) D_80800FB0_chtoxicroombits;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/toxicroombits/func_80800410_chtoxicroombits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/toxicroombits/func_80800458_chtoxicroombits.s")

/* extern */

void func_808004C8_chtoxicroombits(s32 arg0) {
    s32 func_800DA7A8(s32, s32, s32);
    func_800DA7A8(0x6DF, arg0, 3);
}

/* extern */

s32 func_808004F0_chtoxicroombits(void) {
    s32 _glcutDll_entrypoint_19(s32);
    s32 func_800D0A9C(s32, s32);
    s32 func_800DA564(s32, s32);
    if ((func_800D0A9C(0x38, 1) == 0) && (_glcutDll_entrypoint_19(0x41) == 0)) {
        return func_800DA564(0x6DF, 3);
    }
    return 6;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/toxicroombits/func_80800540_chtoxicroombits.s")

void func_80800630_chtoxicroombits(u8 *arg0) {
    struct State {
        u8 pad[0x64];
        u32 flagsHigh : 12;
        u32 flag : 1;
        u32 flagsLow : 19;
        u8 pad68[0x11];
        u8 count : 4;
        u8 other : 4;
    };
    s32 _capod_entrypoint_13(s32, s32, s32, s32);
    void _subaddieaudioloop_entrypoint_0(Actor *, f32);
    void _subaddieaudioloop_entrypoint_1(u8 *, s32);
    s32 _subaddieaudioloop_entrypoint_4(Actor *, f32 *, u32, u32 *);
    s32 _subaddiefind_entrypoint_4(s32, u8 **, s32);
    s32 _sudeflect_entrypoint_1(u8 *, f32, f32, f32, s32);
    s32 func_800D0634(u32, u32);
    f32 func_800D8FF8(void);
    s32 func_800D90A4(f32 *);
    f32 func_800D91B8(f32 *);
    s32 func_800DA298(s32);
    s32 func_800DA544(s32);
    void func_800E3980(f32 *);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    void func_800FFAB0(Actor *);
    f32 func_80103EAC(Actor *);
    f32 func_80103EF4(Actor *);
    u8 *func_80106790(s32);
    f32 func_80800458_chtoxicroombits(void);
    void func_80800960_chtoxicroombits(u8 *, s32);
    s32 func_80800BE4_chtoxicroombits(u8 *);
    extern u32 D_80801004_chtoxicroombits;
    u8 *found[20];
    f32 movement;
    f32 camera[3];
    s32 active;
    f32 radius;
    s32 count;
    s32 i;
    u8 **actor;

    count = _subaddiefind_entrypoint_4(0x3EA, found, 20);
    if (*(f32 *)(arg0 + 0x34) + 0.05f < func_80800458_chtoxicroombits()) {
        *(f32 *)(arg0 + 0x34) += 0.05f;
    } else if (func_80800458_chtoxicroombits() < *(f32 *)(arg0 + 0x34) - 0.05f) {
        *(f32 *)(arg0 + 0x34) -= 0.05f;
    } else {
        *(f32 *)(arg0 + 0x34) = func_80800458_chtoxicroombits();
    }
    _subaddieaudioloop_entrypoint_0((Actor *)arg0,
        func_800F10B4((f32)func_808004F0_chtoxicroombits(), 6.0f, 1.0f, 0.45f, 0.7f));
    func_800E3980(camera);
    if (camera[0] > -200.0f && !func_800DA298(0xA04) && func_800DA298(0x1BD)) {
        _subaddieaudioloop_entrypoint_1(arg0, 0x1F40);
    } else {
        _subaddieaudioloop_entrypoint_1(arg0, 0x55F0);
    }
    _subaddieaudioloop_entrypoint_4((Actor *)arg0, (f32 *)(arg0 + 4), 1, &D_80801004_chtoxicroombits);
    radius = 16.0f;
    if (*(f32 *)(arg0 + 0x34) / radius <= func_800D91B8((f32 *)(arg0 + 0x58))) {
        *(f32 *)(arg0 + 0x58) -= *(f32 *)(arg0 + 0x34) / radius;
        if (--((struct State *)arg0)->count == 0) {
            func_80800960_chtoxicroombits(arg0, 0);
        }
    }
    active = func_80800BE4_chtoxicroombits(arg0);
    movement = func_800D8FF8() / (*(f32 *)(arg0 + 0x34) / radius) * 250.0f;
    for (i = 0, actor = found; i < count; i++, actor++) {
        *(f32 *)(*actor + 0xC) -= movement;
        if (*(f32 *)(*actor + 0xC) < -2000.0f) {
            func_800FFAB0((Actor *)*actor);
        } else if (active) {
            radius = func_80103EF4((Actor *)*actor);
            _sudeflect_entrypoint_1(*actor + 4, radius, 0.0f, func_80103EAC((Actor *)*actor), 30);
        }
    }
    if (*(f32 *)(arg0 + 0x18) != 0.0f && func_800D90A4((f32 *)(arg0 + 0x18))) {
        if (((struct State *)arg0)->flag) {
            _capod_entrypoint_13(*(s32 *)arg0, 0, 5, 0x90);
            *(f32 *)(arg0 + 0x1C) = *(f32 *)(func_80106790(func_800D0634(0x38, 1)) + 8);
        } else if (!func_800DA298(0x1BE)) {
            func_800DA544(0x1BE);
            _capod_entrypoint_13(*(s32 *)arg0, 0, 3, 0x10);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/toxicroombits/func_80800960_chtoxicroombits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/toxicroombits/func_80800A2C_chtoxicroombits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/toxicroombits/func_80800BE4_chtoxicroombits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/toxicroombits/func_80800CB0_chtoxicroombits.s")

OSThread *chtoxicroombits_entrypoint_1(void)
{
    extern u8 D_80801034_chtoxicroombits[];

    return (OSThread *) D_80801034_chtoxicroombits;
}
