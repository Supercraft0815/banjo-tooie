#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/familysmall/func_80800000_chdinofamilysmall.s")

void func_80800090_chdinofamilysmall(u8 *arg0) {
    s32 _chdinofamilyfx_entrypoint_0(u8 *);
    s32 _subaddieaudioquick_entrypoint_2(u8 *, u8 *, s32 *);
    s32 _subaddiedialog_entrypoint_11(s32, s32, s32, u8 *, s32);
    s32 _subaddiedialog_entrypoint_4(u8 *, s32, s32);
    s32 _sudeflect_entrypoint_1(u8 *, f32, f32, f32, s32);
    s32 _sumumbofx_entrypoint_14(s32);
    f32 _sumumbofx_entrypoint_21(s32);
    f32 _sumumbofx_entrypoint_26(s32);
    s32 _sumumbofx_entrypoint_27(s32);
    s32 _sumumbofx_entrypoint_5(s32, s32);
    s32 _sumumbofx_entrypoint_7(s32, f32, s32, s32, f32 *, s32, s32);
    f32 func_800138D0(f32);
    f32 func_80013970(f32);
    s32 func_800C4244(s32, s32, s32, u8 *, f32, f32);
    s32 func_800DA298(s32);
    s32 func_800E1610(s32, s32, s32, u8 *);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    f32 func_800F12D4(f32, f32, f32, f32, f32);
    s32 func_80100094(u8 *, s32);
    s32 func_80103DFC(u8 *, f32 *);
    f32 func_80103EAC(u8 *);
    s32 func_808008B4_chdinofamilysmall(u8 *, s32);
    extern s32 D_80800EE8_chdinofamilysmall;
    extern s32 D_80800EFC_chdinofamilysmall;
    f32 sp84[3];
    f32 sp78[3];
    f32 sp6C[3];
    f32 sp60[3];
    f32 sp5C;
    f32 sp50[3];
    f32 sp4C;
    struct StateBits { u32 unused:16; u32 state:6; u32 rest:10; };
    struct SoundBits { u32 unused:11; u32 first:1; u32 second:1; u32 rest:19; };
    struct LandingBits { u32 unused:1; u32 landed:1; u32 rest:30; };

    switch (((struct StateBits *)(arg0 + 0x70))->state) {
    case 1:
        if (_subaddiedialog_entrypoint_4(arg0 + 4, 0x258, 0) != 0) {
            _subaddiedialog_entrypoint_11((*(s32 *)((s8 *)(arg0) + (0))), 0x17CB, 0xF, arg0 + 4, 0x39);
        }
        _sudeflect_entrypoint_1(arg0 + 4, (*(f32 *)(arg0 + 0x38)) * 235.0f, 0, (*(f32 *)(arg0 + 0x38)) * 179.0f, 0x1E);
        _chdinofamilyfx_entrypoint_0(arg0);
        return;
    case 2:
        if (func_800DA298(0x9DE) != 0) {
            func_808008B4_chdinofamilysmall(arg0, 3);
        }
        _chdinofamilyfx_entrypoint_0(arg0);
        return;
    case 3:
        func_80103DFC(arg0, sp84);
        _sumumbofx_entrypoint_7(func_80100094(arg0, 1), func_80103EAC(arg0), 0, 0x28, sp84, 0, 0);
        _sumumbofx_entrypoint_14(func_80100094(arg0, 1));
        if (_sumumbofx_entrypoint_27(func_80100094(arg0, 1)) != 0) {
            func_808008B4_chdinofamilysmall(arg0, 4);
        }
        _chdinofamilyfx_entrypoint_0(arg0);
        return;
    case 4:
        func_80103DFC(arg0, sp78);
        _sumumbofx_entrypoint_7(func_80100094(arg0, 1), func_80103EAC(arg0), 0, 0x28, sp78, 0, 0);
        _sumumbofx_entrypoint_14(func_80100094(arg0, 1));
        _sumumbofx_entrypoint_5(func_80100094(arg0, 1), 0x40000000);
        if (_sumumbofx_entrypoint_27(func_80100094(arg0, 1)) != 0) {
            func_808008B4_chdinofamilysmall(arg0, 5);
            return;
        }
    default:
        return;
    case 5:
        func_80103DFC(arg0, sp6C);
        _sumumbofx_entrypoint_7(func_80100094(arg0, 1), func_80103EAC(arg0), 0, 0x28, sp6C, 0, 0);
        _sumumbofx_entrypoint_14(func_80100094(arg0, 1));
        (*(f32 *)((s8 *)(arg0) + (8))) = (f32) ((*(f32 *)((s8 *)(arg0) + (0x34))) + func_800F12D4(_sumumbofx_entrypoint_26(func_80100094(arg0, 1)), 0.0f, 1.0f, 0.0f, 800.0f));
        if (_sumumbofx_entrypoint_27(func_80100094(arg0, 1)) != 0) {
            func_808008B4_chdinofamilysmall(arg0, 6);
            return;
        }
        break;
    case 6:
        func_80103DFC(arg0, sp60);
        if (_sumumbofx_entrypoint_21(func_80100094(arg0, 1)) > 2.0f) {
            if (!((struct SoundBits *)(arg0 + 0x64))->first) {
                _subaddieaudioquick_entrypoint_2(arg0, arg0 + 4, &D_80800EE8_chdinofamilysmall);
                ((struct SoundBits *)(arg0 + 0x64))->first = 1;
            }
            (*(f32 *)((s8 *)(arg0) + (0x38))) = func_800F12D4(_sumumbofx_entrypoint_21(func_80100094(arg0, 1)), 4.0f, 2.0f, 0.5f, 0.5);
            (*(f32 *)(arg0 + 0x30)) = (*(f32 *)(arg0 + 0x2C)) = (*(f32 *)(arg0 + 0x28)) = func_800F12D4(_sumumbofx_entrypoint_21(func_80100094(arg0, 1)), 4.0f, 2.0f, 1.0f, 2.0);
        } else {
            sp5C = func_800F10B4(_sumumbofx_entrypoint_21(func_80100094(arg0, 1)), 2.0f, 0.0f, 1.0f, 0.0f);
            if (!((struct SoundBits *)(arg0 + 0x64))->second) {
                _subaddieaudioquick_entrypoint_2(arg0, arg0 + 4, &D_80800EFC_chdinofamilysmall);
                ((struct SoundBits *)(arg0 + 0x64))->second = 1;
            }
            (*(f32 *)((s8 *)(arg0) + (0x38))) = func_800F12D4(_sumumbofx_entrypoint_21(func_80100094(arg0, 1)), 2.0f, 0.0f, 0.5f, 1.0f);
            (*(f32 *)((s8 *)(arg0) + (0x28))) = (f32) ((func_800138D0(sp5C * 3.0f * 360.0f) * sp5C) + 1.0f);
            (*(f32 *)((s8 *)(arg0) + (0x2C))) = (f32) ((func_800138D0(sp5C * 5.0f * 360.0f) * sp5C) + 1.0f);
            (*(f32 *)((s8 *)(arg0) + (0x30))) = (f32) ((func_800138D0(sp5C * 4.0f * 360.0f) * sp5C) + 1.0f);
        }
        _sumumbofx_entrypoint_7(func_80100094(arg0, 1), func_80103EAC(arg0) * ((2.0f * func_80013970(_sumumbofx_entrypoint_26(func_80100094(arg0, 1)) * 180.0f)) + 1.0f), 0, 0x28, sp60, 0, 0);
        _sumumbofx_entrypoint_14(func_80100094(arg0, 1));
        if (_sumumbofx_entrypoint_27(func_80100094(arg0, 1)) != 0) {
            func_808008B4_chdinofamilysmall(arg0, 7);
            return;
        }
        break;
    case 7:
        func_80103DFC(arg0, sp50);
        _sumumbofx_entrypoint_7(func_80100094(arg0, 1), func_80103EAC(arg0), 0, 0x28, sp50, 0, 0);
        _sumumbofx_entrypoint_14(func_80100094(arg0, 1));
        sp4C = _sumumbofx_entrypoint_21(func_80100094(arg0, 1));
        if ((sp4C <= 1.6500001f) && (sp4C >= 1.05f)) {
            (*(f32 *)((s8 *)(arg0) + (8))) = (f32) ((*(f32 *)((s8 *)(arg0) + (0x34))) + (func_800138D0(func_800F10B4(sp4C, 1.6500001f, 1.05f, 0, 90.0f)) * 800.0f));
        } else if ((sp4C < 1.05f) && !((struct LandingBits *)(arg0 + 0x74))->landed) {
                    func_800C4244(0x416, 0x3F666666, 0x55F0, arg0 + 4, 100.0f, 2500.0f);
            ((struct LandingBits *)(arg0 + 0x74))->landed = 1;
            func_800E1610(3, 0x42C80000, 0x3F19999A, arg0 + 4);
            (*(f32 *)((s8 *)(arg0) + (8))) = (f32) (*(f32 *)((s8 *)(arg0) + (0x34)));
        }
        if (sp4C <= 0.0f) {
            func_808008B4_chdinofamilysmall(arg0, 8);
            return;
        }
        break;
    case 8:
        func_808008B4_chdinofamilysmall(arg0, 9);
        return;
    case 9:
        if (_subaddiedialog_entrypoint_4(arg0 + 4, 0x258, 0) != 0) {
            _subaddiedialog_entrypoint_11((*(s32 *)((s8 *)(arg0) + (0))), 0x17CC, 0xF, arg0 + 4, 0x39);
        }
        _sudeflect_entrypoint_1(arg0 + 4, (*(f32 *)(arg0 + 0x38)) * 235.0f, 0, (*(f32 *)(arg0 + 0x38)) * 179.0f, 0x1E);
        _chdinofamilyfx_entrypoint_0(arg0);
        return;
    case 10:
        _chdinofamilyfx_entrypoint_0(arg0);
        break;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/familysmall/func_808008B4_chdinofamilysmall.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/familysmall/func_80800AF4_chdinofamilysmall.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/familysmall/func_80800C10_chdinofamilysmall.s")

OSThread *chdinofamilysmall_entrypoint_0(void)
{
    extern u8 D_80800F20_chdinofamilysmall[];

    return (OSThread *) D_80800F20_chdinofamilysmall;
}
