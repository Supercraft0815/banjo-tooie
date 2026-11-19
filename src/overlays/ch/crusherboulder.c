#include "common.h"

void func_80800000_chcrusherboulder(Actor *arg0, void *arg1) {
    void *func_80100094(Actor *, u32);
    s32 _sumumbofx_entrypoint_10(u8 *);
    void _sumumbofx_entrypoint_8(u8 *arg0, BtIntPtr arg1);
    void _sumumbofx_entrypoint_9(u8 *arg0, Gfx **arg1);
    void func_800DF5D8(u32, u32, u32, s32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF04C(f32 *, f32 *);
    void func_800EF5A0(f32 *, f32 *, f32, f32, f32);
    void func_80101870(Actor *, void *);
    f32 savedPosition[3];
    f32 rotation[3];
    f32 *position;
    u8 *data;
    s32 color;

    data = func_80100094(arg0, 1);
    rotation[0] = -arg0->rotation[0];
    rotation[1] = arg0->rotation[1];
    rotation[2] = arg0->rotation[2];
    if (data != NULL) {
        color = _sumumbofx_entrypoint_10(data);
        func_800DF5D8(color, 255, color, 255);
    }
    position = arg0->position;
    func_800EE7F8(savedPosition, position);
    func_800EF5A0(position, rotation, 0.0f, 150.0f, 0.0f);
    func_800EF04C(position, savedPosition);
    arg0->position[1] -= 150.0f;
    if (data != NULL) {
        _sumumbofx_entrypoint_9(data, arg1);
    }
    func_80101870(arg0, arg1);
    func_800EE7F8(position, savedPosition);
    if (data != NULL) {
        _sumumbofx_entrypoint_8(data, arg1);
    }
}
struct Vector { s32 v[3]; };
s32 func_80800100_chcrusherboulder(u8 *arg0, f32 *arg1) {

    extern struct Vector D_80801388_chcrusherboulder;
    extern struct Vector D_80801394_chcrusherboulder;
    void _sumumbofx_entrypoint_7(u8 *arg0, f32 arg1, s32 arg2, s32 arg3, f32 *arg4, f32 *arg5, f32 *arg6);
    void _sumumbofx_entrypoint_14(u8 *arg0);
    void _sumumbofx_entrypoint_11(void *arg0, BtIntPtr bt_a1);
    struct Vector sp3C = D_80801388_chcrusherboulder;
    struct Vector sp30 = D_80801394_chcrusherboulder;

    _sumumbofx_entrypoint_7(arg0, 225.0f, 0, 0x19, arg1, &sp30, &sp3C);
    _sumumbofx_entrypoint_14(arg0);
    arg1[1] += 300.0f;
    _sumumbofx_entrypoint_11(arg0, arg1);
    arg1[1] -= 300.0f; BT_NATIVE_ONLY(return 0;)
}

/* extern */

void func_808001CC_chcrusherboulder(Actor *arg0) {
    void* func_80100094(Actor*, u32);
    s32 _sumumbofx_entrypoint_5(u8 *, s32);
    s32 func_80800100_chcrusherboulder(u8 *, f32 *);
    u8 *sp1C;
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 1U);
    sp1C = temp_v0;
    _sumumbofx_entrypoint_5(temp_v0, 0x40400000);
    func_80800100_chcrusherboulder(sp1C, arg0->position);
}

void func_80800210_chcrusherboulder(Actor *arg0) {
    f32 func_800DC178(f32, f32);
    void func_800EE7F8(f32 *, f32 *);
    void func_80105834(Actor *);
    void func_80105A9C(Actor *, f32);
    f32 savedRotation[3];
    s32 i;

    if (arg0->unk58 < 20.0f) {
        func_800EE7F8(savedRotation, arg0->rotation);
        func_80105A9C(arg0, 80.0f);
        func_80105834(arg0);
        func_800EE7F8(arg0->rotation, savedRotation);
    }
    for (i = 0; i < 3; i++) {
        arg0->rotation[i] += func_800DC178(-0.25f, 0.25f);
        arg0->rotation[i] = arg0->rotation[i] < -10.0f ? -10.0f :
            (arg0->rotation[i] > 10.0f ? 10.0f : arg0->rotation[i]);
    }
}

void func_80800338_chcrusherboulder(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    s32 func_80800100_chcrusherboulder(u8 *, f32 *);
    void func_80800A1C_chcrusherboulder(Actor *, s32);
    void func_80800F38_chcrusherboulder(Actor *);
    f32 func_800D8FF8(void);
    f32 func_800DC0C0(void);
    f32 func_800DC178(f32, f32);
    s32 func_800DA298(s32);
    s32 func_800DA544(s32);
    f32 _sumumbofx_entrypoint_22(u8 *);
    s32 _sumumbofx_entrypoint_1(void *, s32);
    s32 func_8010A800(BtIntPtr, s32);
    s32 _capod_entrypoint_13(BtIntPtr, BtIntPtr, s32, s32);
    BT_IDO_ONLY(s8 _subaddieaudioloop_entrypoint_7(u8, f32 *, u8, s32 *, s32);) BT_NATIVE_ONLY(s8 _subaddieaudioloop_entrypoint_7(u8, f32 *, u32, s32 *, s32);)
    void func_800187B4(s32, f32, f32, f32);
    extern s32 D_808013A0_chcrusherboulder[5];
    u8 *sp3C;
    s8 sp3B;

    sp3C = func_80100094(arg0, 1U);
    switch (arg0->unk70_10) {
        case 1:
            break;
        case 2:
            func_80800100_chcrusherboulder(sp3C, arg0->position);
            if (arg0->position[1] > 5.0f) {
                arg0->position[1] -= 210.0f * func_800D8FF8();
            } else {
                arg0->unk64_20 = 0;
                arg0->unk58 = 0.0f;
                func_80800A1C_chcrusherboulder(arg0, 3);
            }
            break;
        case 3:
            func_80800100_chcrusherboulder(sp3C, arg0->position);
            arg0->position[1] = 15.0f;
            ((f32 *)arg0->actorData)[7] = 0.0f;
            if (func_800DA298(0x4FB)) {
                func_80800A1C_chcrusherboulder(arg0, 5);
            } else {
                func_80800A1C_chcrusherboulder(arg0, 4);
            }
            func_800DA544(0x4FD);
            func_800DA544(0x9DF);
            break;
        case 4:
            func_80800100_chcrusherboulder(sp3C, arg0->position);
            if (_sumumbofx_entrypoint_22(sp3C) <= 0.02f) {
                _sumumbofx_entrypoint_1(arg0, 1);
                func_8010A800((BtIntPtr)arg0, 0);
                func_80800A1C_chcrusherboulder(arg0, 6);
            }
            break;
        case 6:
            if (func_800DA298(0x4FB)) {
                _capod_entrypoint_13((BtIntPtr)arg0->unk0, 0, 4, 0x4030);
                func_80800A1C_chcrusherboulder(arg0, 7);
            }
            break;
        case 5:
            func_80800100_chcrusherboulder(sp3C, arg0->position);
            if (_sumumbofx_entrypoint_22(sp3C) <= 0.02f) {
                _sumumbofx_entrypoint_1(arg0, 1);
                func_8010A800((BtIntPtr)arg0, 0);
                func_80800A1C_chcrusherboulder(arg0, 7);
            }
        case 7:
            if (arg0->position[0] < -2850.0f) {
                func_80800A1C_chcrusherboulder(arg0, 12);
            }
            if (arg0->position[0] < -1900.0f) {
                if (arg0->position[0] > -2350.0f) {
                    if (((f32 *)arg0->actorData)[7] < 500.0f) {
                        ((f32 *)arg0->actorData)[7] += 2.0f;
                    }
                } else if (((f32 *)arg0->actorData)[7] > 0.0f) {
                    ((f32 *)arg0->actorData)[7] -= 2.0f;
                }
                if (arg0->position[2] > -325.0f && func_800DC0C0() < 0.4f) {
                    arg0->position[2] -= func_800DC178(4.0f, 8.0f);
                    arg0->rotation[2] = -func_800DC178(2.0f, 8.0f);
                }
                if (arg0->position[2] < -375.0f && func_800DC0C0() < 0.4f) {
                    arg0->position[2] += func_800DC178(4.0f, 8.0f);
                    arg0->rotation[2] = func_800DC178(2.0f, 8.0f);
                }
                if (arg0->unk74_30) {
                    arg0->position[0] -= 144.0f * func_800D8FF8() * func_800DC178(0.2f, 0.3f);
                    sp3B = _subaddieaudioloop_entrypoint_7(((u8 *)arg0->actorData)[12], arg0->position, 1, D_808013A0_chcrusherboulder, *(u32 *)((u8 *)arg0 + 0x70) & 1);
                    ((f32 *)arg0->actorData)[3] = *(f32 *)&sp3B;
                    if (func_800DC0C0() < 0.2f) {
                        arg0->unk74_30 = 0;
                    }
                } else {
                    arg0->position[0] -= 144.0f * func_800D8FF8() * func_800DC178(0.9f, 1.0f);
                    if (func_800DC0C0() < 0.2f) {
                        arg0->unk74_30 = 1;
                    }
                }
                func_80800F38_chcrusherboulder(arg0);
                if (!arg0->unk64_20) {
                    func_800187B4(0, 1.0f, 1.0f, 6.5f);
                    arg0->unk64_20 = 1;
                }
            } else {
                arg0->position[0] -= 144.0f * func_800D8FF8();
            }
            break;
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
            break;
    }
}

void func_8080087C_chcrusherboulder(u8 *arg0) {
    void _chglowbo_entrypoint_6(void);
    s32 func_8001211C(void);
    f32 func_800D8FF8(void);
    s32 func_800DA9E4(s32, s32);
    f32 func_800DC0C0(void);
    void func_80800A1C_chcrusherboulder(Actor *, s32);
    void func_808010EC_chcrusherboulder(void);
    Actor *actor = (Actor *)arg0;

    switch (actor->unk70_10) {
        case 1:
            if (func_800DA9E4(0x9DE, 0)) {
                func_80800A1C_chcrusherboulder(actor, 8);
            }
            break;
        case 8:
            func_80800210_chcrusherboulder(actor);
            func_808001CC_chcrusherboulder(actor);
            if (actor->unk58 > 0.0f) {
                actor->unk58 -= func_800D8FF8();
            } else if (!actor->unk64_19) {
                _chglowbo_entrypoint_6();
                actor->unk64_19 = 1;
            }
            break;
        case 11:
            actor->unk58 -= func_800D8FF8();
            if (actor->unk58 > 0.0f && !(func_8001211C() & 2) && func_800DC0C0() < 0.3f) {
                func_808010EC_chcrusherboulder();
            }
            break;
    }
}

/* extern */

void func_808009C0_chcrusherboulder(u8 *arg0) {
    s32 _sudeflect_entrypoint_0(BtIntPtr, s32, s32, s32);
    _sudeflect_entrypoint_0((BtIntPtr) (arg0 + 4), 0x43160000, 0x43700000, 0xA);
    if (((Actor *) arg0)->unk74_29) {
        func_80800338_chcrusherboulder((Actor *) arg0);
        return;
    }
    func_8080087C_chcrusherboulder(arg0);
}
void func_80800A1C_chcrusherboulder(Actor *arg0, s32 arg1) {
    void *func_80100094(Actor *, u32);
    void func_80101FDC(Actor *, u32);
    s16 _chmumbopad_entrypoint_0(s32);
    s32 _sumumbofx_entrypoint_0(Actor *, s32, s32, s16);
    s32 _sumumbofx_entrypoint_2(void *);
    void _sumumbofx_entrypoint_4(void *);
    void _sumumbofx_entrypoint_15(void *, f32);
    void _sumumbofx_entrypoint_16(void *, f32);
    void _sumumbofx_entrypoint_25(void *, s32, s32 *);
    void _sumumbofx_entrypoint_3(void *, f32);
    s32 _sumumbofx_entrypoint_12(void *, f32 *, f32 *, f32 *);
    s32 _sumumbofx_entrypoint_24(void *, f32);
    s32 func_8010A800(BtIntPtr, s32);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32 *, void *);
    s32 func_800E1610(s32, f32, f32, f32 *);
    s32 func_800DA544(s32);
    void _subaddieaudioloop_entrypoint_2(Actor *);
    u8 _subaddieaudioloop_entrypoint_3(u8);
    s32 _capod_entrypoint_13(BtIntPtr, BtIntPtr, s32, s32);
    void func_808010EC_chcrusherboulder(void);
    s32 func_80101180(s32, s32, BtIntPtr);
    extern s32 D_808013B4_chcrusherboulder[];
    extern f32 D_808013C0_chcrusherboulder[];
    extern f32 D_808013C8_chcrusherboulder[];
    extern f32 D_808013D4_chcrusherboulder[];
    extern u8 D_80801360_chcrusherboulder[];
    extern u8 D_80801374_chcrusherboulder[];
    void *sp4C;
    f32 sp40[3];
    u8 sp3F;
    void *sp38;
    f32 sp2C[3];

    sp4C = func_80100094(arg0, 1);
    func_80101FDC(arg0, arg1);
    switch (arg1) {
        case 2:
            arg0->position[1] = 750.0f;
            _sumumbofx_entrypoint_0(arg0, 1, 0x19, _chmumbopad_entrypoint_0(1));
            sp4C = func_80100094(arg0, 1);
            _sumumbofx_entrypoint_2(sp4C);
            _sumumbofx_entrypoint_4(sp4C);
            _sumumbofx_entrypoint_15(sp4C, 0.1f);
            _sumumbofx_entrypoint_25(sp4C, 0x80, D_808013B4_chcrusherboulder);
            func_8010A800(arg0, 2);
            _sumumbofx_entrypoint_3(sp4C, 250.0f);
            sp40[0] = arg0->position[0];
            sp40[1] = arg0->position[1] + 300.0f;
            sp40[2] = arg0->position[2];
            _sumumbofx_entrypoint_12(sp4C, sp40, D_808013C0_chcrusherboulder, D_808013C8_chcrusherboulder);
            break;
        case 4:
        case 5:
            _sumumbofx_entrypoint_16(sp4C, 0.5f);
            break;
        case 3:
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_80801360_chcrusherboulder);
            func_800E1610(0, 10.0f, 0.8f, arg0->position);
            break;
        case 6:
            arg0->position[1] = 15.0f;
            break;
        case 7:
            func_800DA544(0x4FF);
            func_800DA544(0);
            arg0->unk74_30 = 0;
            break;
        case 12:
            _subaddieaudioloop_entrypoint_2(arg0);
            sp3F = _subaddieaudioloop_entrypoint_3(*(u8 *)&arg0->actorData[3]);
            *(f32 *)&arg0->actorData[3] = *(f32 *)&sp3F;
            break;
        case 8:
            _sumumbofx_entrypoint_0(arg0, 1, 0x2D, _chmumbopad_entrypoint_0(1));
            sp38 = func_80100094(arg0, 1);
            _sumumbofx_entrypoint_2(sp38);
            _sumumbofx_entrypoint_24(sp38, 0.65f);
            _sumumbofx_entrypoint_15(sp38, 3.0f);
            _sumumbofx_entrypoint_25(sp38, 0x80, D_808013B4_chcrusherboulder);
            func_8010A800(arg0, 2);
            sp2C[0] = arg0->position[0];
            sp2C[1] = arg0->position[1] + 300.0f;
            sp2C[2] = arg0->position[2];
            _sumumbofx_entrypoint_12(sp38, sp2C, D_808013C0_chcrusherboulder, D_808013C8_chcrusherboulder);
            func_80800210_chcrusherboulder(arg0);
            _capod_entrypoint_13(arg0->unk0, NULL, 6, 0x4810);
            arg0->unk58 = 22.5f;
            break;
        case 11:
            _capod_entrypoint_13(arg0->unk0, NULL, 8, 0x2830);
            arg0->unk64_16 = 0;
            arg0->unk58 = 3.0f;
            func_808010EC_chcrusherboulder();
            func_80101180(0x180, 0xA, 0);
            _subaddieaudioquick_entrypoint_2(arg0, D_808013D4_chcrusherboulder, D_80801374_chcrusherboulder);
            break;
    }
}

void func_80800D3C_chcrusherboulder(Actor *arg0) {
    s32 _capod_entrypoint_13();
    s32 func_800FFAB0();
    s32 func_800DA298(s32);
    s32 func_800DA9E4(s32, s32);
    s32 func_800EA05C();

    arg0->scale = 0.7f;
    if (func_800EA05C() == 0xCB) {
        arg0->unk74_29 = 1;
    } else {
        arg0->unk74_29 = 0;
    }
    if (arg0->unk74_29) {
        if (func_800DA298(0x4FF) || !func_800DA298(0x4FC)) {
            func_800FFAB0(arg0);
            return;
        }
        if (func_800DA298(0x4FC)) {
            if (func_800DA298(0x4FD)) {
                func_80800A1C_chcrusherboulder(arg0, 6);
                return;
            }
            if (func_800DA298(0x4FB)) {
                _capod_entrypoint_13(arg0->unk0, NULL, 2, 0x2820);
            } else {
                _capod_entrypoint_13(arg0->unk0, NULL, 0, 0x2820);
            }
            func_80800A1C_chcrusherboulder(arg0, 2);
        }
    } else {
        if (func_800DA298(0x4FF)) {
            if (!func_800DA9E4(0x500, 1)) {
                func_80800A1C_chcrusherboulder(arg0, 11);
                return;
            }
            func_800FFAB0(arg0);
            return;
        }
        if (func_800DA298(0x4FC)) {
            func_800FFAB0(arg0);
            return;
        }
        if (func_800DA298(0x4FD)) {
            func_800FFAB0(arg0);
        }
    }
}

void func_80800ED0_chcrusherboulder(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    s32 _sumumbofx_entrypoint_1(void *, s32);
    void _subaddieaudioloop_entrypoint_2(Actor *);
    u8 _subaddieaudioloop_entrypoint_3(u8);
    void func_800DA524(GameFlag);
    u8 sp27;

    if (func_80100094(arg0, 1) != 0) {
        _sumumbofx_entrypoint_1(arg0, 1);
    }
    _subaddieaudioloop_entrypoint_2(arg0);
    sp27 = _subaddieaudioloop_entrypoint_3(((u8 *)arg0)[0x24]);
    *(f32 *)&arg0->actorData[3] = *(f32 *)&sp27;
    func_800DA524(0);
}
struct BoulderPosition { f32 v[3]; };
void func_80800F38_chcrusherboulder(Actor *arg0) {
    s32 _subaddieaudioloop_entrypoint_4(Actor *, f32 *, u32, u32 *);
    s32 func_8001211C(void);
    f32 func_800DC0C0(void);
    void func_80801064_chcrusherboulder(f32[3], f32);
    void func_80801128_chcrusherboulder(f32[3], s32);

    extern struct BoulderPosition D_808013E0_chcrusherboulder;
    extern u32 D_808013EC_chcrusherboulder[4];
    struct BoulderPosition sp24 = D_808013E0_chcrusherboulder;

    if (!(func_8001211C() & 3)) {
        sp24.v[2] = *(f32 *)&arg0->actorData[7] + -325.0f;
        if (func_800DC0C0() < 0.6f) {
            func_80801064_chcrusherboulder(sp24.v, arg0->scale);
        }
        sp24.v[2] += 25.0f;
        func_800DC0C0();
        func_80801128_chcrusherboulder(sp24.v, *(s32 *)&arg0->scale);
        sp24.v[2] = -325.0f - *(f32 *)&arg0->actorData[7];
        if (func_800DC0C0() < 0.6f) {
            func_80801064_chcrusherboulder(sp24.v, arg0->scale);
        }
        sp24.v[2] -= 25.0f;
        func_800DC0C0();
        func_80801128_chcrusherboulder(sp24.v, *(s32 *)&arg0->scale);
    }
    _subaddieaudioloop_entrypoint_4(arg0, arg0->position, 1, D_808013EC_chcrusherboulder);
}

void func_80801064_chcrusherboulder(f32 arg0[3], f32 arg1) {
    BtIntPtr func_800BABB8(BtIntPtr, f32[3], f32[3], f32, s32[]);
    extern s32 D_808013FC_chcrusherboulder[16];
    extern s32 D_8080143C_chcrusherboulder[5];
    extern s32 D_80801450_chcrusherboulder[5];
    BtIntPtr temp_a0;

    temp_a0 = func_800BABB8(0, arg0, NULL, 1.0f, D_808013FC_chcrusherboulder);
    func_800BABB8(temp_a0, arg0, NULL, 1.0f,
        arg0[2] < -325.0f ? D_8080143C_chcrusherboulder : D_80801450_chcrusherboulder);
}

void func_808010EC_chcrusherboulder(void) {
    BtIntPtr func_800BBCB8(s32 *, BtIntPtr, s32, s32, s32 *);
    extern s32 D_80801464_chcrusherboulder[3];
    extern s32 D_80801470_chcrusherboulder[19];
    func_800BBCB8(D_80801464_chcrusherboulder, 0, 0x3F800000, 3, D_80801470_chcrusherboulder);
}

void func_80801128_chcrusherboulder(f32 arg0[3], s32 arg1) {
    void func_800BA22C(BtIntPtr arg0, s32 n);
    void func_800BA3FC(BtIntPtr arg0, s32 asset_id);
    BtIntPtr func_800BABB8(BtIntPtr, f32[3], f32[3], f32, s32[]);
    extern s32 D_808014BC_chcrusherboulder[12];
    BtIntPtr sp24;
    BtIntPtr temp_v0;

    temp_v0 = func_800BABB8(0, arg0, NULL, 1.0f, D_808014BC_chcrusherboulder);
    sp24 = temp_v0;
    func_800BA3FC(temp_v0, 0x9DD);
    func_800BA22C(sp24, 1);
}

/* extern */

s32 func_80801184_chcrusherboulder(s32 arg0, s32 arg1, u32 arg2) {
    s32 _capod_entrypoint_14();
    s32 _capod_entrypoint_15();
    s32 _glcutDll_entrypoint_17();
    s32 _glcutDll_entrypoint_23();
    s32 _glcutDll_entrypoint_6(s32, s32);
    s32 func_800DA544(s32);
    s32 func_800DB9B0();
    s32 func_800FFAB0(BtIntPtr);
    if (arg1 == 0xB) {
        switch (arg2) {
        case 6:
            func_800DA544(0x4FC);
            _glcutDll_entrypoint_6(0xCB, 0x19);
            /* fallthrough */
        default:
            return 3;
        case 0:
            _glcutDll_entrypoint_17();
            return 3;
        case 4:
            _capod_entrypoint_15();
            _glcutDll_entrypoint_6(0xC7, 0x19);
            return 4;
        case 2:
            _glcutDll_entrypoint_17();
            return 3;
        case 8:
            if (_glcutDll_entrypoint_23() != 0) {
                _glcutDll_entrypoint_17();
                return 3;
            }
            if (func_800DB9B0() != 0) {
                _glcutDll_entrypoint_17();
            }
            _capod_entrypoint_14();
            func_800FFAB0(arg0);
            return 4;
        }
    } else {
        return 0;
    }
}

OSThread *chcrusherboulder_entrypoint_0(void)
{
    extern ActorData D_808014EC_chcrusherboulder[];

    return (OSThread *) D_808014EC_chcrusherboulder;
}
/* data_to_c.py: from asm/data/overlays/ch/crusherboulder.data.s */
void func_80107C2C();
u8 D_80801360_chcrusherboulder [20] BT_DATA(4, overlays_ch_crusherboulder, 0x0) = { 0, 0x13, 4, 0xCC, 0, 0xA, 1, 0, 0, 0x16, 0x7D, 0, 0, 1, 0, 0, 0x13, 0x88, 0, 0 };
u8 D_80801374_chcrusherboulder [20] BT_DATA(4, overlays_ch_crusherboulder, 0x14) = { 0, 0x13, 4, 0xD1, 0, 0xA, 0, 0xE6, 0, 0x16, 0x7D, 0, 0, 1, 0x27, 0x10, 0x3A, 0x98, 0, 0 };
struct Vector D_80801388_chcrusherboulder BT_DATA(4, overlays_ch_crusherboulder, 0x28) = { { 0, 0, 0 } };
struct Vector D_80801394_chcrusherboulder BT_DATA(4, overlays_ch_crusherboulder, 0x34) = { { 0, 1125515264, 0 } };
s32 D_808013A0_chcrusherboulder[5] BT_DATA(4, overlays_ch_crusherboulder, 0x40) = { 1246381, 655590, 1465792, 66036, 327680000 };
s32 D_808013B4_chcrusherboulder [3] BT_DATA(4, overlays_ch_crusherboulder, 0x54) = { 0, 0, 0 };
f32 D_808013C0_chcrusherboulder [2] BT_DATA(4, overlays_ch_crusherboulder, 0x60) = { 500.0f, 1000.0f };
f32 D_808013C8_chcrusherboulder [3] BT_DATA(4, overlays_ch_crusherboulder, 0x68) = { 0.0f, 3.57331e-43f, 0.0f };
f32 D_808013D4_chcrusherboulder [3] BT_DATA(4, overlays_ch_crusherboulder, 0x74) = { -5000.0f, 950.0f, -6000.0f };
struct BoulderPosition D_808013E0_chcrusherboulder BT_DATA(4, overlays_ch_crusherboulder, 0x80) = { { -2350.0f, 325.0f, -325.0f } };
u32 D_808013EC_chcrusherboulder[4] BT_DATA(4, overlays_ch_crusherboulder, 0x8C) = { 0x1304D2, 0x167D00, 0x101F4, 0x13880000 };
s32 D_808013FC_chcrusherboulder[16] BT_DATA(4, overlays_ch_crusherboulder, 0x9C) = { 51380253, 109576202, 65436, -3276800, 6553650, 1834008, -131071961, -23527784, 23593320, 2228864, 100664576, 58720277, 384, 1441796, 458753, 0 };
s32 D_8080143C_chcrusherboulder[5] BT_DATA(4, overlays_ch_crusherboulder, 0xDC) = { 3080167, 5898640, 1638520, 52429594, 0 };
s32 D_80801450_chcrusherboulder[5] BT_DATA(4, overlays_ch_crusherboulder, 0xF0) = { 3080167, 3932560, 1638490, 52429594, 0 };
s32 D_80801464_chcrusherboulder[3] BT_DATA(4, overlays_ch_crusherboulder, 0x104) = { -979615744, 1148026880, -977567744 };
s32 D_80801470_chcrusherboulder[19] BT_DATA(4, overlays_ch_crusherboulder, 0x110) = { 1902216, 720846, -3211314, 3276850, 3276846, -1572899, 98304025, 2295760, 1833008, -262143961, -23527784, 23593320, 2228864, 100664576, 58720277, 384, 1441796, 458753, 0 };
s32 D_808014BC_chcrusherboulder[12] BT_DATA(4, overlays_ch_crusherboulder, 0x15C) = { 17825817, 65542, 655510, -19595364, 16384100, 6553627, 3276900, 2228608, 41943168, 25165845, 384, -603848704 };
ActorData D_808014EC_chcrusherboulder [1] BT_DATA(4, overlays_ch_crusherboulder, 0x18C) = { { 610, 382, 1671, 1, 0, (void (*)(struct Actor *))func_808009C0_chcrusherboulder, (void (*)(struct Actor *))func_808009C0_chcrusherboulder, (void (*)(long, long))func_80800000_chcrusherboulder, 262144000, 0, 0, 0, 8200, 4, (void (*)(struct Actor *))func_80800ED0_chcrusherboulder, 0, 0, 0, (void (*)(struct Actor *))func_80800D3C_chcrusherboulder, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32760, 2, (void (*)(struct Actor *, long, long))func_80801184_chcrusherboulder, 0 } };
