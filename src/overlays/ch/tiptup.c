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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/tiptup/func_808002F4_chtiptup.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/tiptup/func_80800578_chtiptup.s")

void func_80800614_chtiptup(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 *arg4) {
    s32 func_800B53A4(s32);
    s32 func_800BA22C(s32, s32);
    s32 func_800BABB8(s32, s32, s32, s32, s32 *);
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
    void _subaddieaudioquick_entrypoint_3(Actor *, f32 *, u32 *, f32);
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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/tiptup/func_80800D78_chtiptup.s")

void func_80800E2C_chtiptup(Actor *arg0) {
    f32 *sp1C[1];
    void _subaddieaudioquick_entrypoint_3(Actor *, f32 *, u32 *, f32);
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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/tiptup/func_80800E9C_chtiptup.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/tiptup/func_80800FE8_chtiptup.s")

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
