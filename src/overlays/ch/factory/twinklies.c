#include "common.h"

OSThread *chfactorytwinklies_entrypoint_0(void)
{
    extern u8 D_80802218_chfactorytwinklies[];

    return (OSThread *) D_80802218_chfactorytwinklies;
}

OSThread *chfactorytwinklies_entrypoint_1(void)
{
    extern u8 D_80802260_chfactorytwinklies[];

    return (OSThread *) D_80802260_chfactorytwinklies;
}

OSThread *chfactorytwinklies_entrypoint_2(void)
{
    extern u8 D_808022A8_chfactorytwinklies[];

    return (OSThread *) D_808022A8_chfactorytwinklies;
}

OSThread *chfactorytwinklies_entrypoint_3(void)
{
    extern u8 D_808022F0_chfactorytwinklies[];

    return (OSThread *) D_808022F0_chfactorytwinklies;
}

OSThread *chfactorytwinklies_entrypoint_4(void)
{
    extern u8 D_80802338_chfactorytwinklies[];

    return (OSThread *) D_80802338_chfactorytwinklies;
}

OSThread *chfactorytwinklies_entrypoint_5(void)
{
    extern u8 D_80802380_chfactorytwinklies[];

    return (OSThread *) D_80802380_chfactorytwinklies;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/twinklies/func_80800048_chfactorytwinklies.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/twinklies/func_808001A0_chfactorytwinklies.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/twinklies/func_8080040C_chfactorytwinklies.s")

void func_8080064C_chfactorytwinklies(Actor *arg0) {
    s32 _susubgame_entrypoint_2(void *, s32);
    s32 _susubgame_entrypoint_4(void *, s32);
    void func_800A16BC(s32);
    void func_800CE88C(s32, s32);
    s32 func_800CEAA8(s32);
    u32 func_800FDC28(u32);
    void *func_80100094(Actor *, u32);
    s32 data[2];

    data[1] = func_80100094(arg0, 0);
    func_800A16BC(0);
    if (func_800CEAA8(0) != 0) {
        func_800CE88C(0, 0);
    }
    data[0] = data[1] + 0xAC;
    if (_susubgame_entrypoint_2(arg0, data[0]) != 0) {
        _susubgame_entrypoint_4(arg0, data[0]);
    }
    func_800FDC28(0);
}

/* extern */

void func_808006C0_chfactorytwinklies(Actor *arg0) {
    s32 _subaddiemulti_entrypoint_2();
    s32 _subaddiemulti_entrypoint_4(s32);
    void func_800CE88C(s32, s32);
    void func_800CE8D8(s32, f32, s32);
    s32 func_800DA298(s32);
    u32 func_800FDC28(u32);
    void func_80101FDC(Actor *, u32);
    f32 duration;
    _subaddiemulti_entrypoint_2();
    func_80101FDC(arg0, 3);
    duration = 60.0f;
    func_800CE8D8(0, duration, (s32) duration);
    func_800CE88C(0, 1);
    arg0->unk58 = 0.01f;
    if (func_800DA298(0x6A7) != 0) {
        _subaddiemulti_entrypoint_4(0x17);
    }
    func_800FDC28(0xC);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/twinklies/func_80800748_chfactorytwinklies.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/twinklies/func_808009EC_chfactorytwinklies.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/twinklies/func_80800A84_chfactorytwinklies.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/twinklies/func_80800B80_chfactorytwinklies.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/twinklies/func_80800D00_chfactorytwinklies.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/twinklies/func_80800DE0_chfactorytwinklies.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/twinklies/func_80800E9C_chfactorytwinklies.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/twinklies/func_8080105C_chfactorytwinklies.s")

void func_80801108_chfactorytwinklies(Actor *arg0, s32 arg1, s32 arg2) {
    void _gcfrontend_entrypoint_10(void);
    s32 _subaddiemulti_entrypoint_2();
    void func_80101FDC(Actor *, u32);
    switch (arg1) {
    case 0xCEC:
        func_808006C0_chfactorytwinklies(arg0);
        return;
    case 0x1348:
    case 0x1349:
        _subaddiemulti_entrypoint_2();
        func_80101FDC(arg0, 6);
        _gcfrontend_entrypoint_10();
        return;
    }
}

s32 func_80801174_chfactorytwinklies(Actor *arg0, s32 arg1, s32 arg2) {
    void* func_80100094(Actor*, u32);
    if (arg1 == 0x1348) {
        return (*(s32 *)((s8 *)(func_80100094(arg0, 0U)) + (0xA0))) + 1;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/twinklies/func_808011B0_chfactorytwinklies.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/twinklies/func_808013BC_chfactorytwinklies.s")

void func_8080145C_chfactorytwinklies(Actor *arg0) {
    s32 temp_v0;

    temp_v0 = arg0->unk74_7 - 0x32;
    arg0->actorData[5] = temp_v0;
    switch (temp_v0) {
    case 0:
        arg0->actorData[4] = 0x20000000;
        break;
    case 1:
        arg0->actorData[4] = 0x10000000;
        break;
    case 2:
        arg0->actorData[4] = 0x08000000;
        break;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/twinklies/func_808014B0_chfactorytwinklies.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/twinklies/func_80801608_chfactorytwinklies.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/twinklies/func_8080171C_chfactorytwinklies.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/twinklies/func_808018A0_chfactorytwinklies.s")

void func_80801D58_chfactorytwinklies(u8 *arg0) {
    s32 _chlightfader_entrypoint_1(s32, f32, s32);
    s32 temp_a3;

    temp_a3 = (*(s32 *)((s8 *)(arg0) + (0x50)));
    if (temp_a3 != 0) {
        (*(s32 *)((s8 *)(arg0) + (0x50))) = _chlightfader_entrypoint_1(temp_a3, 1.0f, 2);
    }
}

/* extern */

s32 func_80801D94_chfactorytwinklies(s32 arg0, s32 arg1, u8 *arg2) {
    s32 func_80801DD8_chfactorytwinklies(s32, u32);
    u8 **ptr = &arg2;
    switch (arg1) {
    case 0x3E:
        func_80801DD8_chfactorytwinklies(arg0, (u32)*(u16 *)(*ptr + 0x1A) >> 5);
        break;
    default:
        return 0;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/twinklies/func_80801DD8_chfactorytwinklies.s")

f32 func_80801ED0_chfactorytwinklies(void *arg0) {
    f32 func_800DC178(f32, f32);
    switch (*(s32 *)((u8 *)arg0 + 0x2C)) {
    case 0:
        return func_800DC178(800.0f, 900.0f);
    case 1:
        return func_800DC178(600.0f, 700.0f);
    default:
        return func_800DC178(400.0f, 500.0f);
    }
}

f32 func_80801F5C_chfactorytwinklies(void *arg0) { switch (*(s32 *)((u8 *)arg0 + 0x2C)) { case 0: return 900.0f; case 1: return 700.0f; default: return 500.0f; } }

f32 func_80801FAC_chfactorytwinklies(void *arg0) {
    f32 func_800DC178(f32, f32);
    switch (*(s32 *)((u8 *)arg0 + 0x2C)) {
    case 0:
        return func_800DC178(4.0f, 4.0f);
    case 1:
        return func_800DC178(4.0f, 4.0f);
    default:
        return func_800DC178(4.0f, 4.0f);
    }
}

/* extern */
s32 func_80802020_chfactorytwinklies(u8 *arg0) {
    u8 func_800D9078(f32 *);
    f32 func_800F12D4(f32, f32, f32, f32, f32);
    s32 sp24;
    s32 temp_v0;

    temp_v0 = func_800D9078((f32 *) (arg0 + 0x28));
    sp24 = temp_v0;
    (*(f32 *)((s8 *)(arg0) + (8))) = func_800F12D4((*(f32 *)((s8 *)(arg0) + (0x28))), 0.0f, 0.6f, 0.0f, -250.0f);
    return sp24;
}

/* extern */

s32 func_8080207C_chfactorytwinklies(u8 *arg0) {
    u8 func_800D9078(f32 *);
    f32 func_800F12D4(f32, f32, f32, f32, f32);
    s32 sp28;

    sp28 = func_800D9078((f32 *) (arg0 + 0x28));
    (*(f32 *)((s8 *)(arg0) + (8))) = func_800F12D4((*(f32 *)((s8 *)(arg0) + (0x28))), 0.0f, 0.6f, -250.0f, 0.0f);
    return sp28;
}
