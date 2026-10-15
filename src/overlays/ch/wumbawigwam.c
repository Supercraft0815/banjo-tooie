#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/wumbawigwam/func_80800000_chwumbawigwam.s")

void func_80800158_chwumbawigwam(u8 *arg0) {
    typedef struct { f32 v[3]; } WigwamVec;
    typedef struct {
        u8 pad0[0x64];
        u32 : 11;
        u32 sound1 : 1;
        u32 sound2 : 1;
        u32 : 19;
        u8 pad68[0xC];
        u32 : 2;
        u32 effect : 1;
        u32 : 29;
    } WigwamFlags;
    s32 _gcgoto_entrypoint_5(s32, s32, f32);
    s32 _subaddieaudioquick_entrypoint_2(u8 *, u8 *, s32 *);
    s32 _sumumbofx_entrypoint_14(s32);
    f32 _sumumbofx_entrypoint_21(s32);
    s32 _sumumbofx_entrypoint_27(s32);
    s32 _sumumbofx_entrypoint_5(s32, s32);
    s32 _sumumbofx_entrypoint_6(s32, f32, f32, s32, s32, u8 *, s32, s32);
    f32 func_800138D0(f32);
    f32 func_80013970(f32);
    s32 func_800BBCB8(WigwamVec *, WigwamVec *, f32, s32, s32 *);
    s32 func_800C4140(s32, WigwamVec *, s32);
    s32 func_800DA298(s32);
    s32 func_800EA05C(void);
    s32 func_800F00A4(f32 *, f32, f32, f32, f32 *);
    f32 func_800F0E00(f32, f32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    f32 func_800F12D4(f32, f32, f32, f32, f32);
    s32 func_800F54E4(void);
    void func_800F5A00(s32, f32 *);
    s32 func_800F64A4(s32, s32);
    s32 func_80100094(u8 *, s32);
    void func_80103110(u8 *, s32);
    f32 func_80103EAC(u8 *);
    f32 func_80103EF4(u8 *);
    void func_8010A624(u8 *);
    f32 func_8010CD28(u8 *);
    void func_80800B9C_chwumbawigwam(u8 *, s32);
    extern WigwamVec D_808010E0_chwumbawigwam;
    extern s32 D_808010EC_chwumbawigwam;
    extern s32 D_80801100_chwumbawigwam;
    extern s32 D_80801114_chwumbawigwam;
    extern s32 D_80801158_chwumbawigwam;
    f32 sp6C[3];
    f32 sp60[3];
    f32 sp5C;
    WigwamVec sp50;
    f32 sp4C;

    switch ((u32)*(u16 *)(arg0 + 0x72) >> 10) {
    case 1:
        func_80103110(arg0, 0);
        break;
    case 2:
        func_800F5A00(func_800F54E4(), sp6C);
        if (!func_800F00A4((f32 *)(arg0 + 4),
            func_80103EAC(arg0) * (func_800F64A4(func_800F54E4(), 0x40000) ? 1.0f : 0.6f),
            func_800F64A4(func_800F54E4(), 0x40000) ? 40.0f : *(f32 *)(arg0 + 0x38) * 280.0f, 0.0f, sp6C)) {
            func_80800B9C_chwumbawigwam(arg0, 3);
        }
        break;
    case 3:
        func_800F5A00(func_800F54E4(), sp60);
        if (func_800F00A4((f32 *)(arg0 + 4),
            func_80103EAC(arg0) * (func_800F64A4(func_800F54E4(), 0x40000) ? 1.0f : 0.6f),
            func_800F64A4(func_800F54E4(), 0x40000) ? 40.0f : *(f32 *)(arg0 + 0x38) * 280.0f, 0.0f, sp60)) {
            func_8010A624(arg0);
            if (func_800DA298(0x18A) && func_800EA05C() == 0x112) {
                _gcgoto_entrypoint_5(0x122, 1, func_8010CD28(arg0) + 180.0f);
            } else {
                _gcgoto_entrypoint_5(0x11E, 1, func_8010CD28(arg0) + 180.0f);
            }
        }
        break;
    case 4:
        if (func_800DA298(0x9DE)) {
            func_80800B9C_chwumbawigwam(arg0, 5);
        }
        break;
    case 5:
        _sumumbofx_entrypoint_6(func_80100094(arg0, 1), func_80103EF4(arg0),
            *(f32 *)(arg0 + 0x38) * (f32)(u32)*(u16 *)(arg0 + 0x62), 0, 0x28, arg0 + 4, 0, 0);
        _sumumbofx_entrypoint_14(func_80100094(arg0, 1));
        if (_sumumbofx_entrypoint_27(func_80100094(arg0, 1))) {
            func_80800B9C_chwumbawigwam(arg0, 6);
        }
        break;
    case 6:
        _sumumbofx_entrypoint_6(func_80100094(arg0, 1), func_80103EF4(arg0),
            *(f32 *)(arg0 + 0x38) * (f32)(u32)*(u16 *)(arg0 + 0x62), 0, 0x28, arg0 + 4, 0, 0);
        _sumumbofx_entrypoint_14(func_80100094(arg0, 1));
        _sumumbofx_entrypoint_5(func_80100094(arg0, 1), 0x40400000);
        if (_sumumbofx_entrypoint_27(func_80100094(arg0, 1))) {
            if (func_800DA298(0x18A)) {
                func_80800B9C_chwumbawigwam(arg0, 8);
            } else {
                func_80800B9C_chwumbawigwam(arg0, 7);
            }
        }
        break;
    case 7:
        if (_sumumbofx_entrypoint_21(func_80100094(arg0, 1)) > 2.5f) {
            if (!((WigwamFlags *)arg0)->sound2) {
                _subaddieaudioquick_entrypoint_2(arg0, arg0 + 4, &D_808010EC_chwumbawigwam);
                ((WigwamFlags *)arg0)->sound2 = 1;
            }
            *(f32 *)(arg0 + 0x28) = func_800F12D4(_sumumbofx_entrypoint_21(func_80100094(arg0, 1)), 4.0f, 2.5f, 1.0f, 2.0f);
            *(f32 *)(arg0 + 0x2C) = *(f32 *)(arg0 + 0x28);
            *(f32 *)(arg0 + 0x30) = *(f32 *)(arg0 + 0x28);
        } else {
            sp5C = func_800F10B4(_sumumbofx_entrypoint_21(func_80100094(arg0, 1)), 2.5f, 0.0f, 1.0f, 0.0f);
            if (!((WigwamFlags *)arg0)->sound1) {
                _subaddieaudioquick_entrypoint_2(arg0, arg0 + 4, &D_80801100_chwumbawigwam);
                ((WigwamFlags *)arg0)->sound1 = 1;
            }
            *(f32 *)(arg0 + 0x28) = func_800138D0(sp5C * 3.0f * 360.0f) * sp5C + 1.0f;
            *(f32 *)(arg0 + 0x2C) = func_800138D0(sp5C * 5.0f * 360.0f) * sp5C + 1.0f;
            *(f32 *)(arg0 + 0x30) = *(f32 *)(arg0 + 0x28);
            *(f32 *)(arg0 + 0x38) = func_800F12D4(_sumumbofx_entrypoint_21(func_80100094(arg0, 1)), 2.5f, 0.0f, 1.0f, 2.8f);
        }
        _sumumbofx_entrypoint_6(func_80100094(arg0, 1), func_80103EF4(arg0) * *(f32 *)(arg0 + 0x2C),
            ((f32)(u32)*(u16 *)(arg0 + 0x62) * *(f32 *)(arg0 + 0x38)) * func_800F0E00(*(f32 *)(arg0 + 0x28), *(f32 *)(arg0 + 0x30)), 0, 0x28, arg0 + 4, 0, 0);
        _sumumbofx_entrypoint_14(func_80100094(arg0, 1));
        if (_sumumbofx_entrypoint_27(func_80100094(arg0, 1))) {
            func_80800B9C_chwumbawigwam(arg0, 9);
        }
        if (_sumumbofx_entrypoint_21(func_80100094(arg0, 1)) <= 2.0f) {
            if (!((WigwamFlags *)arg0)->effect) {
                sp50 = D_808010E0_chwumbawigwam;
                func_800BBCB8(&sp50, &sp50, 1.0f, 0xF, &D_80801114_chwumbawigwam);
                func_800C4140(0x7FFB5BF2, &sp50, 0x1F4003E8);
                ((WigwamFlags *)arg0)->effect = 1;
            }
        }
        break;
    case 8:
        sp4C = func_800F10B4(_sumumbofx_entrypoint_21(func_80100094(arg0, 1)), 4.0f, 0.0f, 1.0f, 0.0f);
        if (!((WigwamFlags *)arg0)->sound1) {
            _subaddieaudioquick_entrypoint_2(arg0, arg0 + 4, &D_80801158_chwumbawigwam);
            ((WigwamFlags *)arg0)->sound1 = 1;
        }
        *(f32 *)(arg0 + 0x28) = func_80013970(sp4C * 6.0f * 360.0f) * (sp4C * 0.5f) + 1.0f;
        *(f32 *)(arg0 + 0x2C) = func_80013970(sp4C * 7.0f * 360.0f) * (sp4C * 0.5f) + 1.0f;
        *(f32 *)(arg0 + 0x30) = *(f32 *)(arg0 + 0x28);
        *(f32 *)(arg0 + 0x38) = func_800F12D4(_sumumbofx_entrypoint_21(func_80100094(arg0, 1)), 4.0f, 2.5f, 2.8f, 1.0f);
        _sumumbofx_entrypoint_6(func_80100094(arg0, 1), func_80103EF4(arg0) * *(f32 *)(arg0 + 0x2C),
            ((f32)(u32)*(u16 *)(arg0 + 0x62) * *(f32 *)(arg0 + 0x38)) * func_800F0E00(*(f32 *)(arg0 + 0x28), *(f32 *)(arg0 + 0x30)), 0, 0x28, arg0 + 4, 0, 0);
        _sumumbofx_entrypoint_14(func_80100094(arg0, 1));
        if (_sumumbofx_entrypoint_27(func_80100094(arg0, 1))) {
            func_80800B9C_chwumbawigwam(arg0, 9);
        }
        break;
    case 9:
        _sumumbofx_entrypoint_6(func_80100094(arg0, 1), func_80103EF4(arg0),
            *(f32 *)(arg0 + 0x38) * (f32)(u32)*(u16 *)(arg0 + 0x62), 0, 0x28, arg0 + 4, 0, 0);
        _sumumbofx_entrypoint_14(func_80100094(arg0, 1));
        if (_sumumbofx_entrypoint_27(func_80100094(arg0, 1))) {
            func_80800B9C_chwumbawigwam(arg0, 10);
        }
        break;
    case 10:
        func_80800B9C_chwumbawigwam(arg0, 3);
        break;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/wumbawigwam/func_80800B9C_chwumbawigwam.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/wumbawigwam/func_80800E04_chwumbawigwam.s")

/* extern */

s32 func_80800FEC_chwumbawigwam(u8 *arg0, s32 arg1, s32 arg2) {
    s32 func_800DA524(s32);
    void func_80800B9C_chwumbawigwam(u8 *, s32);
    switch (arg1) {
    case 0x4B:
        if ((arg2 == 9) && ((s32)((Actor *)arg0)->unk70_10 < 5)) {
            func_80800B9C_chwumbawigwam(arg0, 4);
            return 1;
        }
        return 0;
    case 0x2E:
        return 1;
    case 0xB:
        func_800DA524(0x9DE);
        return 3;
    }
    return 0;
}

OSThread *chwumbawigwam_entrypoint_0(void)
{
    extern u8 D_8080116C_chwumbawigwam[];

    return (OSThread *) D_8080116C_chwumbawigwam;
}
