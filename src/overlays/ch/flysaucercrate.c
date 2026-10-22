#include "common.h"

OSThread *chflysaucercrate_entrypoint_0(void)
{
    extern u8 D_80800D78_chflysaucercrate[];

    return (OSThread *) D_80800D78_chflysaucercrate;
}

void func_8080000C_chflysaucercrate(Actor *arg0, s32 arg1) {
    void _capod_entrypoint_13(Unk80132ED0 *, Unk80132ED0 *, u32, u32);
    s32 _subaddieDll_entrypoint_4(void *, s32);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    s32 func_800DA544(s32);
    void func_80102424(Actor *, s32);
    void func_80108B04(Actor *, u32);
    extern s32 D_80800CF0_chflysaucercrate;
    func_80102424(arg0, arg1);
    switch (arg0->unk70_10) {
    case 4:
        _subaddieDll_entrypoint_4(arg0, 0);
        return;
    case 3:
        func_800DA544(0x91);
        return;
    case 5:
        func_800DA544(0x93);
        _capod_entrypoint_13(arg0->unk0, NULL, 4, 0x2810);
        return;
    case 7:
        arg0->unk54 = 0.0f;
        arg0->unk50 = 0.0f;
        return;
    case 8:
        _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_80800CF0_chflysaucercrate);
        func_800DA544(0x94);
        func_80108B04(arg0, 0);
        /* fallthrough */
    default:
        return;
    }
}

s32 func_808000E4_chflysaucercrate(Actor *arg0, s32 arg1, u32 arg2) {
    void _capod_entrypoint_13(Unk80132ED0 *, Unk80132ED0 *, u32, u32);
    void _capod_entrypoint_14(void);
    s32 _gcdialogcamera_entrypoint_3(s32 *, f32);
    void _glcutDll_entrypoint_17(void);
    s32 _glcutDll_entrypoint_19(s32);
    void _glcutDll_entrypoint_6(u32, u32);
    s32 _subaddieDll_entrypoint_4(void *, s32);
    s32 func_800DA298(s32);
    void func_800FFAB0(Actor *);
    Actor *func_801084B0(s32, Actor **);
    extern s32 D_80800DC0_chflysaucercrate;

    switch (arg1) {
    case 0xB:
        switch (arg2) {
        case 6:
            if (func_800DA298(0x80) != 0) {
                _capod_entrypoint_14();
                func_8080000C_chflysaucercrate(arg0, 2);
                _subaddieDll_entrypoint_4(arg0, 1);
                if (func_800DA298(0xB3) != 0) {
                    _glcutDll_entrypoint_6(0xCA, 0x17);
                    _capod_entrypoint_13(arg0->unk0, NULL, 2, 0x2810);
                    return 4;
                }
                _capod_entrypoint_13(arg0->unk0, NULL, 0, 0x2010);
                return 4;
            }
            return 3;
        case 12:
            if (_glcutDll_entrypoint_19(0x23) != 0) {
                _glcutDll_entrypoint_17();
            }
            func_8080000C_chflysaucercrate(arg0, 9);
            return 3;
        case 4:
            _glcutDll_entrypoint_17();
            return 3;
        case 2:
            _glcutDll_entrypoint_6(0xD6, 0x23);
        case 0:
        default:
            return 3;
        }
        break;
    case 0x2E:
        arg0->unk74_30 = 0;
        goto handled;
    case 0x3D:
        if (arg2 == 1) {
            func_800FFAB0(arg0);
        }
        func_801084B0(0x2A2, &arg0);
        goto handled;
    case 0x52:
        _gcdialogcamera_entrypoint_3(&D_80800DC0_chflysaucercrate, arg0->scale);
        goto handled;
    default:
        return 0;
    }
    return 0;
handled:
    return 1;
}

void func_8080028C_chflysaucercrate(u8 *arg0, u32 arg1, s32 arg2) {
    struct Flags { u8 pad[0x74]; u8 high : 1; u8 flag : 1; u8 low : 6; };
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0*, u32, u32, f32*, u32);
    arg2 |= 4;
    _subaddiedialog_entrypoint_11((*(Unk80132ED0 **)((s8 *)(arg0) + (0))), arg1, arg2, arg0 + 4, 0x41U);
    ((struct Flags *)arg0)->flag = 1;
}

void func_808002D8_chflysaucercrate(Actor *arg0, f32 arg1) {
    void func_800C31DC(u8, f32);
    u8 func_800C4350(s32, f32[3], s32 *);
    extern s32 D_80800DD0_chflysaucercrate;

    if (arg0->unk5F == 0) {
        arg0->unk5F = func_800C4350(0, arg0->position, &D_80800DD0_chflysaucercrate);
    } else {
        func_800C31DC(arg0->unk5F, arg1);
        func_800C4350(arg0->unk5F, arg0->position, NULL);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flysaucercrate/func_80800348_chflysaucercrate.s")

void func_80800904_chflysaucercrate(void *arg0) {
    f32 func_800DC0C0(void);
    f32 func_800DC178(f32, f32);
    void func_80102B2C(Actor *, f32);
    void func_80102B6C(u8 *, f32);
    Actor *actor = arg0;

    if (func_800DC0C0() < 0.2f) {
        actor->unk50 = func_800DC178(-10.0f, 10.0f);
    }
    func_80102B6C(arg0, 1.0f);
    if (func_800DC0C0() < 0.2f) {
        actor->unk54 = func_800DC178(-10.0f, 10.0f);
    }
    func_80102B2C(arg0, 1.0f);
    if (actor->rotation[2] < 10.0f) {
        actor->rotation[2] += func_800DC178(0.0f, 2.0f);
    }
    if (actor->rotation[2] > -10.0f) {
        actor->rotation[2] += func_800DC178(-2.0f, 0.0f);
    }
}

/* extern */

void func_80800A2C_chflysaucercrate(void *arg0) {
    void func_80102B2C(Actor *, f32);
    void func_80102B6C(u8 *, f32);

    func_80102B2C(arg0, 4.0f);
    func_80102B6C(arg0, 4.0f);
    if (*(f32 *)((s8 *)arg0 + 0x4C)) {
        *(f32 *)((s8 *)arg0 + 0x4C) *= 0.8f;
    }
}

void func_80800A88_chflysaucercrate(Actor *arg0) {
    void _capod_entrypoint_13(Unk80132ED0 *, Unk80132ED0 *, u32, u32);
    s32 _glcutDll_entrypoint_19(s32);
    s32 _subaddieDll_entrypoint_4(void *, s32);
    s32 func_800DA298(s32);
    s32 func_800EA05C();
    void func_800FFAB0(Actor *);

    arg0->scale = 1.25f;
    switch (func_800EA05C()) {
    case 0xCA:
        if (func_800DA298(0x93)) {
            func_800FFAB0(arg0);
            return;
        }
        if (func_800DA298(0x91)) {
            arg0->position[0] = 4750.0f;
            arg0->position[1] = 525.0f;
            if (func_800DA298(0xB3)) {
                func_8080000C_chflysaucercrate(arg0, 5);
                return;
            }
            func_8080000C_chflysaucercrate(arg0, 4);
            return;
        }
        return;
    case 0xD6:
        if (func_800DA298(0x94)) {
            func_800FFAB0(arg0);
            arg0->unk64_16 = 0;
            return;
        }
        if (_glcutDll_entrypoint_19(0x23) || func_800DA298(0x93)) {
            arg0->position[0] = -7800.0f;
            arg0->position[1] = 1600.0f;
            arg0->position[2] = -4500.0f;
            _subaddieDll_entrypoint_4(arg0, 1);
            func_8080000C_chflysaucercrate(arg0, 6);
            if (_glcutDll_entrypoint_19(0x23)) {
                _capod_entrypoint_13(arg0->unk0, 0, 0xC, 0x2810);
                return;
            }
            _capod_entrypoint_13(arg0->unk0, 0, 0xC, 0x2010);
            return;
        }
        func_800FFAB0(arg0);
        break;
    }
}
