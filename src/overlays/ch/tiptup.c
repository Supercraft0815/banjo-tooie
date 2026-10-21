#include "common.h"

OSThread *chtiptup_entrypoint_0(void)
{
    extern u8 D_80801448_chtiptup[];

    return (OSThread *) D_80801448_chtiptup;
}

OSThread *chtiptup_entrypoint_1(void)
{
    extern u8 D_80801490_chtiptup[];

    return (OSThread *) D_80801490_chtiptup;
}

OSThread *chtiptup_entrypoint_2(void)
{
    extern u8 D_808014D8_chtiptup[];

    return (OSThread *) D_808014D8_chtiptup;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/tiptup/func_80800024_chtiptup.s")

/* extern */

void func_80800200_chtiptup(Actor *arg0) {
    s32 _glcutDll_entrypoint_20();
    Actor *_subaddiefind_entrypoint_2(s32, s32);
    s32 _subaddiesect_entrypoint_1(Actor *);
    s32 _subaddiesect_entrypoint_2(void *, s32, s32);
    s32 func_800D0A9C(u32, u32);
    void func_800FFAB0(Actor *);
    void func_80102424(Actor *, s32);
    void func_80105A9C(Actor *, f32);
    Actor *temp_v0;

    if ((func_800D0A9C(0x20, 1) != 0) && (_glcutDll_entrypoint_20() == 0)) {
        func_800FFAB0(arg0);
        return;
    }
    arg0->unk6C_0 = _subaddiesect_entrypoint_1(arg0);
    _subaddiesect_entrypoint_2(arg0, arg0->unk6C_0, 0);
    temp_v0 = _subaddiefind_entrypoint_2(0x359, 0);
    if (temp_v0 != NULL) {
        arg0->unk3C = temp_v0->unk0;
    }
    func_80105A9C(arg0, 400.0f);
    if (_glcutDll_entrypoint_20() != 0) {
        func_80102424(arg0, 6);
    }
}

/* extern */

void func_808002C8_chtiptup(void *arg0) {
    u8 _subaddieaudioloop_entrypoint_3(u8);
    (*(u8 *)((s8 *)(arg0) + (0x28))) = _subaddieaudioloop_entrypoint_3((*(u8 *)((s8 *)(arg0) + (0x28))));
}

s32 func_808002F4_chtiptup(Actor *arg0, s32 arg1, s32 arg2) {
    void _gcdialogcamera_entrypoint_3(u32 *, f32);
    s32 func_800DA298(s32);
    void func_800FFA88(Unk80132ED0 *);
    void func_800FFAB0(Actor *);
    void func_80800534_chtiptup(Actor *, s32, s32);
    void func_80800578_chtiptup(Actor *, s32, s32);
    s32 func_80800774_chtiptup(void *, s32, s32);
    void func_808007CC_chtiptup(void *);
    extern u32 D_80801398_chtiptup;
    s32 sp1C;
    s32 temp_v0;

    switch (arg1) {
        case 46:
            func_80800578_chtiptup(arg0, ((s16 *)&arg2)[0], ((s16 *)&arg2)[1]);
            break;
        case 47:
            func_80800534_chtiptup(arg0, ((s16 *)&arg2)[0], ((s16 *)&arg2)[1]);
            break;
        case 0x52:
            _gcdialogcamera_entrypoint_3(&D_80801398_chtiptup, arg0->scale);
            break;
        case 0x57:
            return func_80800774_chtiptup(arg0, arg2 & 0xFFFF, (u32)(arg2 & 0xFFFF0000) >> 16);
        case 11:
            if (arg2 == 4) {
                func_808007CC_chtiptup(arg0);
                func_800FFA88(arg0->unk3C);
                func_800FFAB0(arg0);
                return 4;
            }
            return 3;
        case 0x95:
            ((u8 *)arg0->actorData)[16] = 0;
            break;
        case 0xB8:
            sp1C = arg2 & 0xFFFF;
            temp_v0 = func_800DA298(0xBD);
            switch (sp1C) {
                case 1: return temp_v0 ? 0xFF8 : 0xFF7;
                case 2: return temp_v0 ? 0xFF8 : 0x104F;
                case 3: return temp_v0 ? 0xFF8 : 0xFF7;
            }
        default:
            return 0;
        case 41:
        case 42:
            ;
    }
    return 1;
}

void func_808004C4_chtiptup(Actor *arg0) {
    s32 _subaddiedialog_entrypoint_8(s32, void *, s32 *, s32 *, s32);
    s32 _subaddiedialog_entrypoint_9(s32, s32, s32 *, s32);
    void func_80800808_chtiptup(Actor *, s32, s32);
    extern s32 D_80801360_chtiptup;
    extern s32 D_80801570_chtiptup;
    s32 temp_v0;

    temp_v0 = _subaddiedialog_entrypoint_8((s32)arg0, (s8 *)arg0 + 4, &D_80801570_chtiptup, &D_80801360_chtiptup, 7);
    if ((temp_v0 != 0) && (_subaddiedialog_entrypoint_9((s32)arg0, temp_v0, &D_80801360_chtiptup, 7) != 3)) {
        func_80800808_chtiptup(arg0, 2, 0);
    }
}

/* extern */

void func_80800534_chtiptup(Actor *arg0, s32 arg1, s32 arg2) {
    void func_800D1000(u32, u32, f32*, u32, Unk80132ED0*);
    void func_80800934_chtiptup(Actor *, s32, s32);
    func_80800934_chtiptup(arg0, 0x40, 0);
    func_800D1000(0x20U, 1U, NULL, 0U, NULL);
}

void func_80800578_chtiptup(Actor *arg0, s32 arg1, s32 arg2) {
    s32 func_800DA298(s32);
    u32 func_800F54E4(void);
    void func_800F82D4(s32, s32);
    void func_80102424(Actor *, s32);
    void func_808007CC_chtiptup(void *);
    void func_808008B4_chtiptup(Actor *, s32, s32);
    s32 state;

    if (arg1 == 0xFFA) {
        func_800F82D4(func_800F54E4(), 0);
        func_80102424(arg0, 4);
        func_808008B4_chtiptup(arg0, 4, 0x30);
        return;
    }
    if (arg0->actorData[5] != 0) {
        func_808007CC_chtiptup(arg0);
    }
    state = func_800DA298(0xBE) != 0 ? 3 : 1;
    func_80102424(arg0, state);
}

void func_80800614_chtiptup(f32 *arg0, f32 *arg1, s32 arg2, f32 arg3, s32 *arg4) {
    s32 func_800B53A4(s32);
    s32 func_800BA22C(s32, s32);
    s32 func_800BABB8(s32, f32 *, f32 *, f32, s32 *);
    extern s32 D_80801580_chtiptup;
    s32 sp24;
    s32 temp_v0;

    temp_v0 = func_800B53A4(arg2);
    sp24 = temp_v0;
    func_800BABB8(temp_v0, arg0, arg1, arg3, &D_80801580_chtiptup);
    if (arg4 != NULL) {
        func_800BABB8(sp24, arg0, arg1, arg3, arg4);
    }
    func_800BA22C(sp24, arg2);
}

void func_80800694_chtiptup(Actor *arg0) {
    u8 _subaddieaudioquick_entrypoint_1(Actor *, f32 *);
    s32 _subaddieaudioquick_entrypoint_3(Actor *, f32 *, u32 *, f32);
    void _subaddieaudioquick_entrypoint_4(Actor *, f32 *, u32 *, u32 *);
    u8 func_800C4350(s32, f32[3], s32 *);
    s32 func_80101E4C(Actor *, f32 *);
    s32 func_801022E4(Actor *);
    extern u32 D_808015B0_chtiptup;
    extern u32 D_808015C0_chtiptup;
    extern u32 D_808015CC_chtiptup;
    extern u32 D_808015DC_chtiptup;
    extern s32 D_808015EC_chtiptup;
    extern f32 D_80801600_chtiptup;
    f32 *sp20[2];
    s32 temp_v0;
    u8 temp_v0_2;
    u8 var_a0;

    switch (func_801022E4(arg0)) {
        case 0x18A:
            _subaddieaudioquick_entrypoint_3(arg0, sp20[0] = arg0->position, &D_808015B0_chtiptup, 0.7f);
            _subaddieaudioquick_entrypoint_3(arg0, sp20[0], &D_808015C0_chtiptup, 0.35f);
            _subaddieaudioquick_entrypoint_4(arg0, sp20[0], &D_808015CC_chtiptup, &D_808015DC_chtiptup);
            break;
        case 0x189:
        if (func_80101E4C(arg0, &D_80801600_chtiptup) != 0) {
        var_a0 = *((u8 *)arg0 + 0x28);
        if (var_a0 == 0) {
            temp_v0_2 = _subaddieaudioquick_entrypoint_1(arg0, arg0->position);
            *((u8 *)arg0 + 0x28) = temp_v0_2;
            var_a0 = temp_v0_2 & 0xFF;
        }
        func_800C4350(var_a0, arg0->position, &D_808015EC_chtiptup);
        }
        break;
    }
}

/* extern */

s32 func_80800774_chtiptup(void *arg0, s32 arg1, s32 arg2) {
    s32 _gcdialogcamera_entrypoint_0(s32, s32);
    void func_80800808_chtiptup(Actor *, s32, s32);
    if (_gcdialogcamera_entrypoint_0(arg1, arg2) != 0) {
        if ((*(s32 *)((s8 *)(arg0) + (0x2C))) != 2) {
            func_80800808_chtiptup(arg0, 2, 1);
        }
        return 2;
    }
    return 1;
}

/* extern */

void func_808007CC_chtiptup(void *arg0) {
    s32 _capod_entrypoint_3(s32, void *);
    if ((*(s32 *)((s8 *)(arg0) + (0x2C))) != 0) {
        _capod_entrypoint_3(0, arg0);
        (*(s32 *)((s8 *)(arg0) + (0x2C))) = 0;
    }
}

void func_80800808_chtiptup(Actor *arg0, s32 arg1, s32 arg2) {
    void _capod_entrypoint_2(Unk80132ED0 *, u32, s32);
    void _capod_entrypoint_7(s32, s32);
    s32 _capod_entrypoint_8(s32);
    void _gcdialogcamera_entrypoint_3(u32 *, f32);
    void _gcdialogcamera_entrypoint_4(f32 *);
    void _gcdialogcamera_entrypoint_5(f32 *);
    void _gcdialogcamera_entrypoint_8(void);
    extern u32 D_80801398_chtiptup;

    switch (arg0->actorData[5]) {
        case 0:
            _capod_entrypoint_2(arg0->unk0, 0x16, 0);
        case 1:
        case 3:
            _capod_entrypoint_8(1);
            arg0->actorData[5] = 2;
            _gcdialogcamera_entrypoint_3(&D_80801398_chtiptup, arg0->scale);
            _gcdialogcamera_entrypoint_4(arg0->position);
            _gcdialogcamera_entrypoint_5(arg0->rotation);
            _gcdialogcamera_entrypoint_8();
        case 2:
            _capod_entrypoint_7(arg1, arg2);
            break;
    }
}

void func_808008B4_chtiptup(Actor *arg0, s32 arg1, s32 arg2) {
    void _capod_entrypoint_2(Unk80132ED0 *, u32, s32);
    void _capod_entrypoint_6(Unk80132ED0 *, s32, s32);

    switch (arg0->actorData[5]) {
        case 0:
            _capod_entrypoint_2(arg0->unk0, 0x16, arg2);
        case 2:
        case 3:
            arg0->actorData[5] = 1;
        case 1:
            _capod_entrypoint_6(arg0->unk0, arg1, arg2);
            break;
    }
}

void func_80800934_chtiptup(Actor *arg0, s32 arg1, s32 arg2) {
    void _capod_entrypoint_2(Unk80132ED0 *, u32, s32);
    void _capod_entrypoint_20(Unk80132ED0 *, s32, s32);

    switch (arg0->actorData[5]) {
        case 0:
            _capod_entrypoint_2(arg0->unk0, 0x16, arg2);
        case 1:
        case 2:
            arg0->actorData[5] = 3;
        case 3:
            _capod_entrypoint_20(arg0->unk0, arg1, arg2);
            break;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/tiptup/func_808009B4_chtiptup.s")

/* extern */

void func_80800C70_chtiptup(Actor *arg0) {
    s32 _glcutDll_entrypoint_20();
    s32 _subaddiesect_entrypoint_1(Actor *);
    s32 _subaddiesect_entrypoint_2(void *, s32, s32);
    s32 func_800DA298(s32);
    void func_800FFAB0(Actor *);
    void func_80102424(Actor *, s32);
    void func_80103110(Actor *, u32);
    void func_80105BAC(Actor *);
    void func_8010A590(Actor *);
    if ((func_800DA298(0xBE) != 0) && (_glcutDll_entrypoint_20() == 0)) {
        func_800FFAB0(arg0);
        return;
    }
    arg0->unk6C_0 = _subaddiesect_entrypoint_1(arg0);
    _subaddiesect_entrypoint_2(arg0, arg0->unk6C_0, 0);
    if (_glcutDll_entrypoint_20() != 0) {
        func_80102424(arg0, 6);
    } else if (func_800DA298(0xBD) != 0) {
        func_80102424(arg0, 3);
        func_8010A590(arg0);
    } else {
        func_80102424(arg0, 1);
        func_80103110(arg0, 0);
        arg0->unk64_16 = 0;
    }
    func_80105BAC(arg0);
    ((u8 *)&arg0->pad94)[1] = (((u8 *)&arg0->pad94)[1] & ~1) | 1;
}

s32 func_80800D78_chtiptup(Actor *arg0, s32 arg1, s32 arg2) {
    Actor *other;
    s32 _subaddieDll_entrypoint_4(void *, s32);
    Actor *_subaddiefind_entrypoint_2(s32, s32);
    u32 func_800F54E4(void);
    void func_800F8300();
    void func_800FC660(u32);
    void func_80102424(Actor *, s32);
    void func_8010A570(Actor *);

    switch (arg1) {
        case 0x40:
            func_800F8300(func_800F54E4(), 2, arg0->position);
            func_8010A570(arg0);
            func_80102424(arg0, 4);
            _subaddieDll_entrypoint_4(arg0, 1);
            func_800FC660(0xE);
            break;
        case 0x95:
            other = _subaddiefind_entrypoint_2(0x358, 0);
            if (other != NULL) {
                arg0->unk3C = other->unk0;
            }
            break;
        default:
            return 0;
    }
    return 1;
}

void func_80800E2C_chtiptup(Actor *arg0) {
    f32 *sp1C[1];
    s32 _subaddieaudioquick_entrypoint_3(Actor *, f32 *, u32 *, f32);
    void _subaddieaudioquick_entrypoint_4(Actor *, f32 *, u32 *, u32 *);
    extern u32 D_8080165C_chtiptup;
    extern u32 D_80801668_chtiptup;
    extern u32 D_80801674_chtiptup;
    extern u32 D_8080167C_chtiptup;

    sp1C[0] = (f32 *)((u8 *)arg0 + 0x18);
    _subaddieaudioquick_entrypoint_3(arg0, sp1C[0], &D_8080165C_chtiptup, 0.02f);
    _subaddieaudioquick_entrypoint_3(arg0, sp1C[0], &D_80801668_chtiptup, 0.14f);
    _subaddieaudioquick_entrypoint_4(arg0, sp1C[0], &D_80801674_chtiptup, &D_8080167C_chtiptup);
}

void func_80800E9C_chtiptup(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    s32 _subaddieaudioquick_entrypoint_3(Actor *, f32 *, u32 *, f32);
    int func_800D9154(f32 *, f32);
    void func_800EF1B8(f32 *, f32, f32);
    void func_800EFA4C(f32 *, f32, f32, f32);
    extern u32 D_80801690_chtiptup;
    extern u32 D_808016A0_chtiptup;
    extern s32 D_808016AC_chtiptup[];
    f32 sp44[3];
    f32 sp38[3];
    f32 sp2C[3];

    if (func_800D9154(&arg0->unk58, 2.2f) != 0) {
        _subaddieaudioquick_entrypoint_2(arg0, (f32 *)arg0->actorData, &D_808016A0_chtiptup);
    }
    if (_subaddieaudioquick_entrypoint_3(arg0, (f32 *)arg0->actorData, &D_80801690_chtiptup, 0.1f) != 0) {
        func_800EFA4C(sp44, ((f32 *)arg0->actorData)[0], arg0->position[1], ((f32 *)arg0->actorData)[2]);
        func_800EFA4C(sp38, ((f32 *)arg0->actorData)[0], arg0->position[1], ((f32 *)arg0->actorData)[2]);
        func_800EFA4C(sp2C, ((f32 *)arg0->actorData)[0], arg0->position[1], ((f32 *)arg0->actorData)[2]);
        func_800EF1B8(sp44, arg0->rotation[1], 20.0f);
        func_800EF1B8(sp38, arg0->rotation[1] + 70.0f, 10.0f);
        func_800EF1B8(sp2C, arg0->rotation[1] - 70.0f, 10.0f);
        sp44[1] -= 10.0f;
        func_80800614_chtiptup(sp38, sp44, 1, 0.5f, D_808016AC_chtiptup);
        func_80800614_chtiptup(sp2C, sp44, 1, 0.5f, D_808016AC_chtiptup);
    }
}

void func_80800FE8_chtiptup(Actor *arg0) {
    s32 _subaddieskeleton_entrypoint_2(Unk80132ED0 *, s32, f32 *);
    s32 _chbadshad_entrypoint_1(Actor *, f32 *, f32);
    s32 _plsu_entrypoint_3(Unk80132ED0 *);
    void func_800F7BC8(s32, s32, Unk80132ED0 *);
    s32 func_80101DDC(Actor *);
    void func_80102424(Actor *, s32);
    void func_800DA544(GameFlag);
    u32 func_800F54E4(void);
    s32 func_800F4F34(u32, f32 *, f32, f32);
    u8 pad[4];
    s32 temp_v0;
    f32 *sp24[1];
    f32 *temp_a2;

    if (_subaddieskeleton_entrypoint_2(arg0->unk0, 4,
            sp24[0] = temp_a2 = (f32 *)arg0->actorData) != 0) {
        _chbadshad_entrypoint_1(arg0, sp24[0], 1.0f);
    }
    switch (arg0->unk70_10) {
        case 1:
            temp_v0 = _plsu_entrypoint_3(arg0->unk0);
            if (temp_v0 != -1) {
                func_800F7BC8(temp_v0, 0x53, arg0->unk0);
            }
            break;
        case 2:
            if (func_80101DDC(arg0) != 0) {
                func_80102424(arg0, 3);
                func_800DA544(0xBD);
            }
            break;
        case 3:
            temp_v0 = func_800F54E4();
            func_800F4F34(temp_v0, sp24[0], 30.0f, 80.0f);
            break;
    }
}

/* extern */

void func_808010CC_chtiptup(Actor *arg0) {
    s32 _glcutDll_entrypoint_20();
    s32 _subaddiesect_entrypoint_1(Actor *);
    s32 _subaddiesect_entrypoint_2(void *, s32, s32);
    s32 func_800DA298(GameFlag);
    void func_80102424(Actor *, s32);
    void func_8010A570(Actor *);
    void func_8010A63C(void ***);
    arg0->unk6C_0 = _subaddiesect_entrypoint_1(arg0);
    _subaddiesect_entrypoint_2(arg0, arg0->unk6C_0, 0);
    if (_glcutDll_entrypoint_20() != 0) {
        func_80102424(arg0, 4);
        return;
    }
    if (func_800DA298(0xBD) != 0) {
        func_8010A570(arg0);
        func_80102424(arg0, 3);
        return;
    }
    func_8010A63C(arg0);
    func_80102424(arg0, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/tiptup/func_80801180_chtiptup.s")
