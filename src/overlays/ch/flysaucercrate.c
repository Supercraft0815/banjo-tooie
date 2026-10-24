#include "common.h"

void func_80800348_chflysaucercrate(Actor *);
void func_80105834(Actor *);
void func_80101870(Actor *, void *);
void *func_80107C2C(s32 *, s32, void *, s32, void *);
void func_80800A88_chflysaucercrate(Actor *);
s32 func_808000E4_chflysaucercrate(Actor *, s32, u32);

u32 D_80800CF0_chflysaucercrate[] = {
    0x00130448, 0x00180001, 0x13882710, 0x00000000,
};

u32 D_80800D00_chflysaucercrate[] = {
    0x00130448, 0x00191770, 0x1F400000,
};

u32 D_80800D0C_chflysaucercrate[] = {
    0x00130447, 0x000D00E6, 0x01190018, 0x00011388,
    0x27100000,
};

u32 D_80800D20_chflysaucercrate[] = {
    0x00000000, 0x00000000, 0x3FC00000, 0x00960009,
    0x3FC00000, 0x00960004, 0x3FC00000, 0x00960004,
    0x3FC00000, 0x00960004, 0x3FC00000, 0x00960004,
    0x3FC00000, 0x00960004, 0x3FC00000, 0x00960004,
    0x3FC00000, 0x0094004A, 0x3FC00000, 0x00940084,
    0x3FC00000, 0x00940084,
};

u32 D_80800D78_chflysaucercrate[] = {
    0x020302A3, 0x06910001, (u32)D_80800D20_chflysaucercrate, (u32)func_80800348_chflysaucercrate,
    (u32)func_80105834, (u32)func_80101870, 0x07D00000, 0x40400000,
    0x00000000, 0x00080004, 0x00000000, 0x00000000,
    0x00000000, (u32)func_80800A88_chflysaucercrate, (u32)func_80107C2C, 0x80000002,
    (u32)func_808000E4_chflysaucercrate, 0x00000000,
};

u32 D_80800DC0_chflysaucercrate[] = {
    0x43200000, 0x43340000, 0x43340000, 0x00000000,
};

u32 D_80800DD0_chflysaucercrate[] = {
    0x02060013, 0x04E00016, 0x32000001, 0x00C807D0,
    0x00000000,
};

u32 D_80800DE4_chflysaucercrate[] = {
    0x00000000, 0x3DCCCCCD, 0x3E800000, 0x3EC28F5C,
    0x3EEB851F, 0x3F2147AE, 0x3F400000, 0xBF800000,
};

u32 D_80800E04_chflysaucercrate[] = {
    0x3E800000, 0x3E99999A, 0x3EB33333, 0x3ECCCCCD,
    0x3EE147AE, 0x3EF33333, 0x3F028F5C, 0x3F0F5C29,
    0x3F147AE1, 0x3F1EB852, 0x3F28F5C3, 0x3F35C28F,
    0x3F428F5C, 0x3F51EB85, 0x3F6147AE, 0x3F7AE148,
    0xBF800000, 0x00000000, 0x00000000,
};

OSThread *chflysaucercrate_entrypoint_0(void)
{


    return (OSThread *) D_80800D78_chflysaucercrate;
}

void func_8080000C_chflysaucercrate(Actor *arg0, s32 arg1) {
    void _capod_entrypoint_13(Unk80132ED0 *, Unk80132ED0 *, u32, u32);
    s32 _subaddieDll_entrypoint_4(void *, s32);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    s32 func_800DA544(s32);
    void func_80102424(Actor *, s32);
    void func_80108B04(Actor *, u32);

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


    if (arg0->unk5F == 0) {
        arg0->unk5F = func_800C4350(0, arg0->position, &D_80800DD0_chflysaucercrate);
    } else {
        func_800C31DC(arg0->unk5F, arg1);
        func_800C4350(arg0->unk5F, arg0->position, NULL);
    }
}

void func_80800348_chflysaucercrate(Actor *arg0) {
    s32 _subaddieaudioquick_entrypoint_4(Actor *, f32 *, u32 *, u32 *);
    s32 _subaddiefade_entrypoint_5(Actor *);
    s32 _sudeflect_entrypoint_1(f32 *, f32, f32, f32, s32);
    s32 func_80016B30(s32, s32);
    s32 func_8008FA60(s32, s32);
    void func_8008FAC8(f32 *, f32, f32, f32);
    f32 func_800D8FF8(void);
    s32 func_800DA298(s32);
    s32 func_800DA9E4(s32, s32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    void func_800FFAB0(Actor *);
    s32 func_80101E14(Actor *, f32);
    s32 func_8010C9B0(f32 *, s32);
    void func_8080000C_chflysaucercrate(Actor *, s32);
    void func_808002D8_chflysaucercrate(Actor *, f32);
    void func_80800904_chflysaucercrate(void *);
    void func_80800A2C_chflysaucercrate(void *);

    if ((s32)arg0->unk70_10 < 8) {
        func_8008FAC8(arg0->position, 115.0f, 175.0f, 115.0f);
        _sudeflect_entrypoint_1(arg0->position, 170.0f, 0.0f, 160.0f, 4);
    }
    switch (arg0->unk70_10) {
    case 1:
        if (!arg0->unk74_30 && func_8010C9B0(arg0->position, 0x15E) && func_8008FA60(0x4001, 0) && !func_800DA298(0x80)) {
            if (!func_800DA9E4(0x90, 1)) {
                func_8080028C_chflysaucercrate((u8 *)arg0, 0xF92, 8);
            } else if (func_80016B30(0, 1)) {
                func_8080028C_chflysaucercrate((u8 *)arg0, 0xFA5, 0);
            }
        }
        _subaddieaudioquick_entrypoint_4(arg0, arg0->position, &D_80800D00_chflysaucercrate, &D_80800DE4_chflysaucercrate);
        break;
    case 2:
        func_80800904_chflysaucercrate(arg0);
        if (arg0->position[1] < 525.0f) {
            arg0->position[1] += 250.0f * func_800D8FF8();
        } else {
            func_8080000C_chflysaucercrate(arg0, 3);
        }
        func_808002D8_chflysaucercrate(arg0, func_800F10B4(arg0->position[1], 478.0f, 525.0f, 0.1f, 0.3f));
        break;
    case 3:
        func_80800904_chflysaucercrate(arg0);
        if (arg0->position[0] < 4750.0f) {
            arg0->position[0] += 375.0f * func_800D8FF8();
        } else if (func_800DA298(0xB3)) {
            func_8080000C_chflysaucercrate(arg0, 5);
        } else {
            func_8080000C_chflysaucercrate(arg0, 4);
        }
        func_808002D8_chflysaucercrate(arg0, func_800F10B4(arg0->position[1], 478.0f, 525.0f, 0.1f, 0.3f));
        break;
    case 4:
        func_80800904_chflysaucercrate(arg0);
        if (!arg0->unk74_30 && func_8010C9B0(arg0->position, 0x15E) && func_8008FA60(0x4001, 0)) {
            if (!func_800DA9E4(0x92, 1)) {
                func_8080028C_chflysaucercrate((u8 *)arg0, 0xF94, 8);
            } else if (func_80016B30(0, 1)) {
                func_8080028C_chflysaucercrate((u8 *)arg0, 0xFA6, 0);
            }
        }
        func_808002D8_chflysaucercrate(arg0, func_800F10B4(arg0->position[1], 478.0f, 525.0f, 0.1f, 0.3f));
        break;
    case 5:
        func_80800904_chflysaucercrate(arg0);
        if (arg0->position[0] < 6300.0f) {
            arg0->position[0] += 375.0f * func_800D8FF8();
        }
        func_808002D8_chflysaucercrate(arg0, func_800F10B4(arg0->position[1], 478.0f, 525.0f, 0.1f, 0.3f));
        break;
    case 6:
        arg0->position[1] = func_800F10B4(arg0->position[2], -4000.0f, -3500.0f, 1600.0f, 1800.0f);
        func_808002D8_chflysaucercrate(arg0, 0.3f);
        func_80800904_chflysaucercrate(arg0);
        if (arg0->position[2] < -2900.0f) {
            arg0->position[2] += 375.0f * func_800D8FF8();
        } else {
            func_8080000C_chflysaucercrate(arg0, 7);
        }
        break;
    case 7:
        func_80800A2C_chflysaucercrate(arg0);
        if (arg0->position[1] > 1700.0f) {
            arg0->position[1] -= 250.0f * func_800D8FF8();
        } else {
            arg0->position[1] = 1700.0f;
            func_8080000C_chflysaucercrate(arg0, 8);
        }
        func_808002D8_chflysaucercrate(arg0, func_800F10B4(arg0->position[1], 1700.0f, 1800.0f, 0.1f, 0.3f));
        break;
    case 8:
        func_80800A2C_chflysaucercrate(arg0);
        _subaddieaudioquick_entrypoint_4(arg0, arg0->position, &D_80800D0C_chflysaucercrate, &D_80800E04_chflysaucercrate);
        func_80800A2C_chflysaucercrate(arg0);
        if (func_80101E14(arg0, 0.999f)) {
            func_8080000C_chflysaucercrate(arg0, 9);
        }
        break;
    case 9:
        func_80800A2C_chflysaucercrate(arg0);
        arg0->unk58 += func_800D8FF8();
        if (arg0->unk58 > 1.5f) {
            _subaddiefade_entrypoint_5(arg0);
        }
        break;
    case 10:
        func_800FFAB0(arg0);
        break;
    }
}

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
