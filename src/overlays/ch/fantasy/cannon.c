#include "common.h"

/* extern */

s32 func_80800000_chfantasycannon(Actor *arg0) {
    s32 func_800DA298(s32);
    return func_800DA298(((u32) (*(u16 *)((s8 *)(arg0) + (0x76))) >> 7) + 0x55D);
}

/* extern */

void func_80800028_chfantasycannon(u8 *arg0) {
    s32 func_800DA544(s32);
    func_800DA544(((u32) (*(u16 *)((s8 *)(arg0) + (0x76))) >> 7) + 0x55D);
}

/* extern */

s32 func_80800050_chfantasycannon(void) {
    u32 func_800F54E4(void);
    s32 func_800F64DC(s32);
    s32 func_8010C500();
    if (func_8010C500() == 0) {
        return 0;
    }
    if (func_800F64DC(func_800F54E4()) == 0) {
        return 0;
    }
    return 1;
}

void func_808000A4_chfantasycannon(void) {
    s32 func_800B5BE4(s32);
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    u32 func_800F54E4(void);
    void func_800F5A00(s32, f32[3]);
    extern s32 D_80800CF8_chfantasycannon;
    f32 sp2C[3];
    s32 sp28;

    sp28 = func_800B5BE4(0x1A);
    func_800F5A00(func_800F54E4(), sp2C);
    sp2C[1] += 60.0f;
    func_800BABB8(sp28, sp2C, NULL, 1.0f, &D_80800CF8_chfantasycannon);
}

/* extern */

void func_8080010C_chfantasycannon(Actor *arg0) {
    s32 _gccubesearch_entrypoint_9(s32, Prop **, s32);
    void _gspropctrl_entrypoint_11(Prop *, f32[3]);
    s32 _gspropctrl_entrypoint_8(Prop *);
    s32 _subaddieDll_entrypoint_1(Actor *);
    void func_800EF1B8(f32 *, f32, f32);
    f32 func_800F1DF4(f32 *, f32 *);
    void func_800FFA88(Unk80132ED0 *);
    s32 func_808009B8_chfantasycannon(Actor *);
    Prop *sp40[20];
    s32 sp3C;
    Prop **var_s0;
    s32 temp_s2;
    s32 var_s1;

    sp3C = 0;
    temp_s2 = _gccubesearch_entrypoint_9(0x47E, sp40, 0x14);
    if (_subaddieDll_entrypoint_1(arg0) == 0) {
        func_800FFA88(arg0->unk0);
        return;
    }
    var_s1 = 0;
    if (temp_s2 > 0) {
        var_s0 = sp40;
loop_4:
        if (_gspropctrl_entrypoint_8(*var_s0) == arg0->unk74_7) {
            _gspropctrl_entrypoint_11(*var_s0, (f32 *)arg0->actorData);
            func_800EF1B8((f32 *)arg0->actorData, func_800F1DF4((f32 *)arg0->actorData, arg0->position), -70.0f);
            ((f32 *)arg0->actorData)[1] += 60.0f;
            sp3C = 1;
        } else {
            var_s1 += 1;
            var_s0++;
            if (var_s1 != temp_s2) {
                goto loop_4;
            }
        }
    }
    if (sp3C == 0) {
        func_800FFA88(arg0->unk0);
        return;
    }
    func_808009B8_chfantasycannon(arg0);
    arg0->unk64_19 = 0;
}

/* extern */

void func_80800228_chfantasycannon(Actor *arg0) {
    s32 _sudeflect_entrypoint_0(f32 *, f32, f32, s32);
    f32 func_80013970(f32);
    void func_800C3F48(u32);
    s32 func_800D90A4(f32 *);
    void func_800EFE50(f32 *, f32 *, f32 *, f32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    void func_800F4CC0(s32);
    void func_800F4CEC(s32, u32);
    u32 func_800F54E4(void);
    s32 func_800F6C5C(s32);
    s32 func_800F7B9C(s32, s32);
    s32 func_800F8294(s32, f32 *);
    s32 func_80101DDC(Actor *);
    s32 func_80101E14(Actor *, f32);
    f32 func_80101F24(Actor *);
    s32 func_80800050_chfantasycannon();
    void func_808000A4_chfantasycannon(void);
    s32 func_80800544_chfantasycannon(Actor *, s32);
    void func_808008B0_chfantasycannon(Actor *);
    f32 temp_f0;
    f32 sp38[3];
    f32 sp34;
    f32 temp_f0_2;
    switch (arg0->unk70_10) {
    case 1:
        if (func_80800050_chfantasycannon(arg0) != 0) {
            func_80800544_chfantasycannon(arg0, 3);
            return;
        }
        temp_f0 = arg0->scale * 226.0f * 0.75f;
        _sudeflect_entrypoint_0(arg0->position, temp_f0, temp_f0, 0xE);
        return;
    case 2:
        if (func_800D90A4(&arg0->unk54) != 0) {
            func_80800544_chfantasycannon(arg0, 3);
            return;
        }
    default:
        return;
    case 3:
        if (func_80101E14(arg0, 0.47f) != 0) {
            func_800C3F48(0x7FFB5E0D);
            func_80800544_chfantasycannon(arg0, 4);
        }
        if (func_80101E14(arg0, 0.16f) != 0) {
            func_800F4CEC(func_800F54E4(), 0x2E);
            arg0->unk64_20 = 0;
        }
        if (func_80101E14(arg0, 0.01f) != 0) {
            func_800C3F48(0x665B5E0C);
        }
        if (func_80101F24(arg0) <= 0.3f) {
            temp_f0_2 = func_800F10B4(func_80101F24(arg0), 0.0f, 0.16f, 0.0f, 1.0f);
            sp34 = temp_f0_2;
            func_800EFE50(sp38, (f32 *)&arg0->actorData[4], arg0->position, temp_f0_2);
            sp38[1] += func_80013970(sp34 * 180.0f) * 300.0f;
            func_800F8294(func_800F54E4(), sp38);
            return;
        }
        break;
    case 4:
        if (func_80101DDC(arg0) != 0) {
            func_80800544_chfantasycannon(arg0, 5);
        } else if (func_80101F24(arg0) >= 0.5f) {
            func_808000A4_chfantasycannon();
            if (!arg0->unk64_20 && (func_80101E14(arg0, 0.5f) != 0)) {
                arg0->unk64_20 = 1;
                func_800F4CC0(func_800F54E4());
            }
        }
        func_800F7B9C(func_800F54E4(), 0x8C);
        func_808008B0_chfantasycannon(arg0);
        return;
    case 5:
        func_808000A4_chfantasycannon();
        if (func_800F6C5C(func_800F54E4()) != 0) {
            func_80800544_chfantasycannon(arg0, 6);
        }
        func_800F7B9C(func_800F54E4(), 0x8C);
        func_808008B0_chfantasycannon(arg0);
        return;
    case 6:
        if (func_800D90A4(&arg0->unk54) != 0) {
            func_80800544_chfantasycannon(arg0, 1);
            return;
        }
        func_808008B0_chfantasycannon(arg0);
        break;
    }
}

s32 func_80800544_chfantasycannon(Actor *arg0, s32 arg1) {
    void _capod_entrypoint_1(f32 *, f32 *);
    void func_800F5A00(s32, f32[3]);
    Actor *_subaddiefind_entrypoint_2(s32, s32);
    s32 func_800DA298(s32);
    s32 func_80015184(void);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EEC30(f32 *, f32, f32, f32);
    void func_800EFA4C(f32 *, f32, f32, f32);
    f32 func_800F1DF4(f32 *, f32 *);
    u32 func_800F54E4(void);
    s32 func_800F5EF8(s32);
    int func_800F78EC(s32, f32 *, f32, f32);
    s32 func_800F8294(s32, f32 *);
    void *func_80100094(Actor *, u32);
    void func_8010FFB0(s32, f32 *, f32 *);
    f32 *sp84;
    f32 sp78[3];
    f32 sp6C[3];
    f32 launchSpeed;
    f32 verticalSpeed;
    f32 gravity;
    f32 discriminant;
    f32 sp50[3];
    f32 sp44[3];
    f32 sp38[3];
    Actor *other;

    sp84 = func_80100094(arg0, 0);
    switch (arg1) {
    case 1:
        _subaddieDll_entrypoint_4(arg0, 0);
        func_800F7F98(func_800F54E4(), 0);
        if (arg0->unk64_19) {
            arg0->unk64_19 = 0;
            _capod_entrypoint_3(0);
        }
        break;
    case 2:
        arg0->unk54 = 1.0f;
        break;
    case 3:
        if (func_800DA298(0x1E1)) {
            other = _subaddiefind_entrypoint_2(0x40E, 0);
            if (other != NULL) {
                func_8010A624(other);
            }
        }
        _subaddieDll_entrypoint_4(arg0, 1);
        func_8010FFB0(func_800F5EF8(func_800F54E4()), sp6C, sp78);
        _capod_entrypoint_2(arg0->unk0, 0x2D, 0x10804);
        _capod_entrypoint_8(0);
        _capod_entrypoint_1(sp6C, sp78);
        if (func_80800000_chfantasycannon(arg0)) {
            func_800EE7F8(sp84, sp6C);
            func_800EE7F8(sp84 + 3, sp78);
        }
        func_800F7F98(func_800F54E4(), 1);
        arg0->unk64_19 = 1;
        func_800F5A00(func_800F54E4(), (f32 *)&arg0->actorData[4]);
        *(s32 *)&arg0->unk50 = func_80015184();
        func_80015178(4);
        break;
    case 4:
        if (func_80800000_chfantasycannon(arg0)) {
            func_800EEC30(sp44, 45.0f,
                func_800F1DF4((f32 *)arg0->actorData, arg0->position), 1250.0f);
            func_800EFA4C(sp50,
                ((f32 *)arg0->actorData)[0] + sp44[0],
                ((f32 *)arg0->actorData)[1] + sp44[1],
                ((f32 *)arg0->actorData)[2] + sp44[2]);
            func_800F8294(func_800F54E4(), sp50);
            gravity = -1250.0f;
            verticalSpeed = 50.0f;
        } else {
            gravity = -800.0f;
            func_800EFA4C(sp38, arg0->position[0],
                arg0->position[1] + 350.0f, arg0->position[2]);
            func_800F8294(func_800F54E4(), sp38);
            launchSpeed = 1700.0f;
            verticalSpeed = launchSpeed * launchSpeed -
                (((f32 *)arg0->actorData)[1] - sp38[1]) * (gravity + gravity);
            if (verticalSpeed > 0.0f) {
                verticalSpeed = sqrtf(verticalSpeed);
            } else {
                verticalSpeed = launchSpeed;
            }
        }
        func_800F78EC(func_800F54E4(), (f32 *)arg0->actorData, verticalSpeed, gravity);
        break;
    case 6:
        arg0->unk54 = 0.25f;
        func_80015178(*(s32 *)&arg0->unk50);
        func_80800028_chfantasycannon((u8 *)arg0);
        if (func_800DA298(0x1E1)) {
            other = _subaddiefind_entrypoint_2(0x40E, 0);
            if (other != NULL) {
                func_8010A63C(other);
            }
        }
        break;
    }
    func_80102424(arg0, arg1);
}

void func_808008B0_chfantasycannon(Actor *arg0) {
    void _capod_entrypoint_1(f32 *, f32 *);
    void func_800A516C(f32 *, f32 *, f32 *);
    f32 func_800EEB40(f32 *, f32 *);
    void func_800EFE50(f32 *, f32 *, f32 *, f32);
    u32 func_800F54E4(void);
    void func_800F5A00(s32, f32 *);
    void *func_80100094(Actor *, u32);
    f32 sp4C[3];
    f32 sp40[3];
    f32 sp34[3];
    f32 (*data)[3];

    data = func_80100094(arg0, 0);
    if (func_80800000_chfantasycannon(arg0) != 0) {
        if ((s32)arg0->unk70_10 < 4) {
            _capod_entrypoint_1(data[0], data[1]);
            return;
        }
        func_800A516C(sp4C, (f32 *)arg0->actorData, data[2]);
        _capod_entrypoint_1(data[2], sp4C);
        return;
    }
    func_800F5A00(func_800F54E4(), sp34);
    func_800EFE50(sp40, data[2], data[0], func_800EEB40(sp34, (f32 *)arg0->actorData) / func_800EEB40(arg0->position, (f32 *)arg0->actorData));
    func_800A516C(sp4C, sp34, sp40);
    _capod_entrypoint_1(sp40, sp4C);
}

s32 func_808009B8_chfantasycannon(Actor *arg0) {
    s32 *func_800BEF00(f32 *, f32 *, f32 *, s32);
    f32 func_800DC0C0(void);
    void func_800EE780(f32 *, f32 *, f32 *);
    void func_800EEC30(f32 *, f32, f32, f32);
    void func_800EF334(f32 *, f32);
    f32 func_800F1DF4(f32 *, f32 *);
    void *func_80100094(Actor *, u32);
    f32 angle;
    f32 sp88[3];
    f32 sp7C[3];
    s32 i;
    f32 (*data)[3];

    data = func_80100094(arg0, 0);
    angle = func_800F1DF4(arg0->position, (f32 *)arg0->actorData) - 180.0f;
    for (i = 5; i >= 0; i++) {
        func_800EEC30(sp88, func_800DC0C0() * 10.0f + 25.0f, i * 12 + angle, 2000.0f);
        func_800EE780(data[2], (f32 *)arg0->actorData, sp88);
        if (func_800BEF00(arg0->position, data[2], sp7C, 0) == 0) {
            break;
        }
        func_800EEC30(sp88, func_800DC0C0() * 10.0f + 25.0f, i * -12 + angle, 2000.0f);
        func_800EE780(data[2], (f32 *)arg0->actorData, sp88);
        if (func_800BEF00(arg0->position, data[2], sp7C, 0) == 0) {
            break;
        }
    }
    func_800EE780(data[0], data[2], arg0->position);
    func_800EF334(data[0], 0.5f);
}

OSThread *chfantasycannon_entrypoint_0(void)
{
    extern u8 D_80800D30_chfantasycannon[];

    return (OSThread *) D_80800D30_chfantasycannon;
}

void func_80800B84_chfantasycannon()
{
    func_80101870();
}

void func_80800BA4_chfantasycannon(Actor *arg0) { arg0->rotation[1] = 0.0f; if (arg0->unk74_7 == 0x38) { func_800FFAB0(arg0); } }

/* extern */

void func_80800BDC_chfantasycannon(Actor *arg0) {
    s32 _plsu_entrypoint_3(Unk80132ED0 *);
    void func_800C3F48(u32);
    s32 func_800D90A4(f32 *);
    s32 sp24;
    s32 temp_v0;

    temp_v0 = _plsu_entrypoint_3(arg0->unk0);
    sp24 = temp_v0;
    if ((temp_v0 == 0) && (func_800D90A4(&arg0->unk58) != 0) && !arg0->unk64_20) {
        func_800C3F48(0x731C5699);
        arg0->unk58 = 0.5f;
    }
    arg0->unk64_20 = sp24 == 0;
}

OSThread *chfantasycannon_entrypoint_1(void)
{
    extern u8 D_80800D78_chfantasycannon[];

    return (OSThread *) D_80800D78_chfantasycannon;
}
