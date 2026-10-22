#include "ch/boggy/fatboy.h"

void *func_80100094(Actor *, u32);

OSThread *chboggyfatboy_entrypoint_0(void)
{
    extern u8 D_80801120_chboggyfatboy[];

    return (OSThread *) D_80801120_chboggyfatboy;
}

OSThread *chboggyfatboy_entrypoint_1(void)
{
    extern u8 D_808011DC_chboggyfatboy[];

    return (OSThread *) D_808011DC_chboggyfatboy;
}

s32 func_80800018_chboggyfatboy(Actor *arg0) {
    s32 _chboggykids_entrypoint_0(void);
    s32 func_800DA298(s32);
    void func_800FFAB0(Actor *);

    if (_chboggykids_entrypoint_0() == 0) {
        func_800FFAB0(arg0);
        return 0;
    }
    *(f32 *)&arg0->actorData[3] = 270.0f;
    if (func_800DA298(0x8E) != 0) {
        return 0;
    }
    return 1;
}

void func_80800078_chboggyfatboy(Actor *arg0) {
    void *data = func_80100094(arg0, 0);
    _subaddieitem_entrypoint_0((s32)data + 0xC, 0x3CA, 0x190, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/boggy/fatboy/func_808000AC_chboggyfatboy.s")

/* extern */

void func_8080052C_chboggyfatboy(Actor *arg0) {
    void _sudeflect_entrypoint_0(f32 *, f32, f32, s32);
    s32 func_800DA980(s32, s32);
    void func_800FFAB0(Actor *);
    s32 func_80101180(s32, s32, s32);
    s32 func_80105230();
    void func_80105834(Actor *);
    s32 func_80105A5C(Actor *);
    func_80105834(arg0);
    func_80105230(arg0, 0);
    _sudeflect_entrypoint_0(arg0->position, 100.0f, 50.0f, 0xA);
    if (func_80105A5C(arg0) != 0) {
        if (func_800DA980(0x8C, 3) != 3) {
            func_80101180(0x13F, 0x4F, 0);
        }
        func_800FFAB0(arg0);
    }
}

s32 func_808005AC_chboggyfatboy(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _gcdialogcamera_entrypoint_3(s32 *, f32);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32 *, void *);
    void func_800C9C70(f32, u32, f32, u32, f32 *, f32, f32);
    s32 func_800DA298(s32);
    s32 func_800DA980(s32, s32);
    s32 func_800F54E4();
    s32 func_800F64A4(s32, s32);
    void func_80800808_chboggyfatboy(Actor *, s32, s32);
    void func_808009E0_chboggyfatboy(Actor *);
    void func_80800AF0_chboggyfatboy(s32, s32);
    void func_80800C5C_chboggyfatboy(Actor *, s32);
    void func_80800F40_chboggyfatboy(Actor *);
    s32 func_80800FE0_chboggyfatboy(s32);
    extern s32 D_80801234_chboggyfatboy;
    extern s32 D_80801244_chboggyfatboy;
    f32 *position[5];
    s16 *parts;
    s32 masked;

    switch (arg1) {
    case 0x3E:
        func_80800AF0_chboggyfatboy((s32)arg0, arg2);
        break;
    case 0x44:
        func_80800C5C_chboggyfatboy(arg0, arg2);
        break;
    case 0x52:
        _gcdialogcamera_entrypoint_3(&D_80801234_chboggyfatboy, arg0->scale);
        break;
    case 0x29:
        func_80800F40_chboggyfatboy(arg0);
        break;
    case 0x95:
        func_808009E0_chboggyfatboy(arg0);
        arg0->unk74_30 = func_800DA298(0xBA);
        break;
    case 0x2E:
        parts = (s16 *)&arg2;
        func_80800808_chboggyfatboy(arg0, parts[0], parts[1]);
        break;
    case 0xB8:
        masked = arg2 & 0xFFFF;
        switch (masked) {
        case 1:
            if (func_800DA298(0xBA)) {
                return func_80800FE0_chboggyfatboy(0x3CA) ? 0x1093 : 0x1092;
            }
            return func_800F64A4(func_800F54E4(), 0x200) ? 0x110F : 0x1091;
        case 2:
            if (func_800DA298(0xBB)) {
                return 0x1096;
            }
            return func_80800FE0_chboggyfatboy(0x3CA) ? 0x1093 : 0x1092;
        }
        break;
    case 0x2D:
        _subaddieaudioquick_entrypoint_2(arg0, position[0] = arg0->position, &D_80801244_chboggyfatboy);
        func_800C9C70(1.0f, 0x525, 1.05f, 0x55F0, position[0], 200.0f, 3000.0f);
        break;
    case 0x30:
        return 3 - func_800DA980(0x8C, 3);
    case 0x2A:
        func_80800FAC_chboggyfatboy(arg0);
        break;
    default:
        return 0;
    }
    return 1;
}

void func_80800808_chboggyfatboy(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
    s32 _subaddiedialog_entrypoint_9(s32, s32, s32 *, s32);
    void _subaddieitem_entrypoint_2(s32);
    void func_800C01A8(s16, s32);
    void func_800C0850(void);
    s32 func_800DA544(s32);
    s32 func_80102424(s32, s32);
    s32 func_80800FE0_chboggyfatboy(s32);
    extern s32 D_80801128_chboggyfatboy;
    void *data;

    data = func_80100094(arg0, 0);
    switch (arg1) {
    case 0x1093:
        _subaddiedialog_entrypoint_11(arg0->unk0, 0x108B, 0x4E, arg0->position, 0x3D);
        break;
    case 0x1095:
    case 0x1111:
        func_80102424(arg0, 1);
        break;
    case 0x108B:
        if (arg2 > 0) {
            func_80102424(arg0, 0xF);
            _subaddieitem_entrypoint_2((s32)data + 0xC);
        } else {
            _subaddiedialog_entrypoint_11(arg0->unk0, 0x1094, 0xE, arg0->position, 0x3D);
        }
        break;
    default:
        if (_subaddiedialog_entrypoint_9((s32)arg0, arg1, &D_80801128_chboggyfatboy, 4) == 1) {
            func_800DA544(0xBA);
            if (func_80800FE0_chboggyfatboy(0x3CA)) {
                _subaddiedialog_entrypoint_11(arg0->unk0, 0x1093, 0xE, arg0->position, 0x3D);
            } else {
                func_800C01A8(0x64, 0);
                func_800C0850();
                func_80102424(arg0, 1);
            }
        } else {
            func_80102424(arg0, 1);
        }
        break;
    }
}

void func_80800978_chboggyfatboy(Actor* arg0)
{
    func_80800FAC_chboggyfatboy(arg0);
}

void func_80800998_chboggyfatboy(Actor *arg0) {
    s32 func_800EE940();
    Actor *func_80106790(Unk80132ED0 *);
    s32 sp1C;
    Actor *temp_v0;

    sp1C = func_80100094(arg0, 0U);
    temp_v0 = func_80106790(arg0->unk3C);
    ((s16 *)sp1C)[3] = *(s32 *)((u8 *)temp_v0 + 0x2C);
    func_800EE940((void *)sp1C, (u8 *)temp_v0 + 0x18);
}

void func_808009E0_chboggyfatboy(Actor *arg0) {
    Actor *_subaddiefind_entrypoint_2(s32, s32);
    s32 _subaddietaxi_entrypoint_13(Actor *, s32, void *, s32);
    s32 func_800DA298(s32);
    s32 func_800DA524(s32);
    void func_800FFAB0(Actor *);
    void func_80102FDC(void *, f32);
    void func_801088A8(void *, s32, s32, void *);
    s32 func_80800FE0_chboggyfatboy(s32);
    extern OSThread *_chboggyfatboy_entrypoint_0(void);
    Actor *temp_v0;

    if (func_80800018_chboggyfatboy(arg0) == 0) {
        func_800FFAB0(arg0);
        return;
    }
    if (_subaddietaxi_entrypoint_13(arg0, 1, &_chboggyfatboy_entrypoint_0, 7) != 0) {
        func_80800078_chboggyfatboy(arg0);
        func_80102FDC(arg0, 1.0f);
    } else {
        if (arg0->unk7A_5) {
            func_800FFAB0(arg0);
            return;
        }
        func_80800078_chboggyfatboy(arg0);
        func_80102FDC(arg0, 1.0f);
    }
    temp_v0 = _subaddiefind_entrypoint_2(0x13F, 0);
    if (temp_v0 != NULL) {
        arg0->unk3C = temp_v0->unk0;
    } else {
        arg0->unk3C = NULL;
    }
    if ((func_80800FE0_chboggyfatboy(0x3CA) != 0) && (func_800DA298(0xBB) == 0)) {
        func_800DA524(0xBA);
    }
    func_801088A8(arg0, 0x10002000, 0, NULL);
}

/* extern */

void func_80800AF0_chboggyfatboy(s32 arg0, s32 arg1) {
    s32 _subaddietaxi_entrypoint_2(s32, s32);
    s32 func_800DA298(s32);
    s32 func_80102424(s32, s32);
    if ((func_800DA298(0xBB) != 0) && (_subaddietaxi_entrypoint_2(arg0, 1) != 0)) {
        func_80102424(arg0, 9);
    }
}

void func_80800B38_chboggyfatboy(s32 arg0, void *arg1, s32 arg2, s32 arg3) {
    s32 _chbaddiesetup_entrypoint_6(s32 *, s32, s32, s32, s32, s32, s32);
    s32 func_800DA298(s32);
    extern s32 _subaddietaxi_entrypoint_16;
    if (func_800DA298(0x8E) == 0) {
        _chbaddiesetup_entrypoint_6(&_subaddietaxi_entrypoint_16, arg0, (*(s32 *)((s8 *)(arg1) + (0))), (*(s32 *)((s8 *)(arg1) + (4))), (*(s32 *)((s8 *)(arg1) + (8))), arg2, arg3);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/boggy/fatboy/func_80800BA0_chboggyfatboy.s")

void func_80800C5C_chboggyfatboy(Actor *arg0, s32 arg1) {
    Actor *_subaddiefind_entrypoint_2(s32, s32);
    void _subaddietaxi_entrypoint_0(Actor *, s32, f32 *, s32);
    void _subaddietaxi_entrypoint_10(Actor *, s32, s32);
    s32 func_800CB3E0(s32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF1B8(f32 *, f32, f32);
    s32 func_80102424();
    void func_80102FDC(void *, f32);
    void func_8010A570(Actor *);
    void func_8010A590(Actor *);
    f32 sp2C[3];
    Actor *sp28;

    func_80102FDC(arg0, 1.0f);
    switch (func_800CB3E0(arg1)) {
        case 1:
            func_80102424(arg0, 1);
            func_8010A590(arg0);
            break;
        case 3:
            _subaddietaxi_entrypoint_10(arg0, arg1, 0xB);
            break;
        case 4:
            sp28 = _subaddiefind_entrypoint_2(0x13F, 0);
            func_800EE7F8(sp2C, sp28->position);
            func_800EF1B8(sp2C, sp28->rotation[1] - 45.0f, 180.0f);
            func_8010A570(arg0);
            _subaddietaxi_entrypoint_0(arg0, arg1, sp2C, 0xA);
            break;
        case 6:
            _subaddiefind_entrypoint_2(0x13F, 0);
            func_80102424(arg0, 0xC);
            func_8010A570(arg0);
            arg0->unk64_20 = 1;
            break;
    }
}

void func_80800D84_chboggyfatboy(Actor *arg0) {
    s32 func_80101E14(Actor *, f32);
    void func_800EE7F8(f32 *, f32 *);
    s32 func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    s32 _subaddieaudioquick_entrypoint_3(Actor *, f32 *, u32 *, f32);
    s32 _subaddieaudioquick_entrypoint_4(Actor *, f32 *, u32 *, u32 *);
    extern u32 D_80801250_chboggyfatboy[];
    extern u32 D_8080125C_chboggyfatboy[];
    extern s32 D_80801264_chboggyfatboy[];
    extern u32 D_80801290_chboggyfatboy[];
    struct { u8 pad[8]; u8 flag : 1; } *sp44;
    f32 sp38[3];
    f32 sp2C[3];

    sp44 = func_80100094(arg0, 0);
    if (func_80101E14(arg0, 0.8f)) {
        sp44->flag = 1;
    }
    if (_subaddieaudioquick_entrypoint_4(arg0, arg0->position, D_80801250_chboggyfatboy, D_80801290_chboggyfatboy) ||
        _subaddieaudioquick_entrypoint_3(arg0, arg0->position, D_8080125C_chboggyfatboy, 0.64f)) {
        func_800EE7F8(sp38, arg0->position);
        sp38[1] += 120.0f;
        func_800EE7F8(sp2C, sp38);
        sp2C[1] -= 30.0f;
        func_800BBCB8(sp38, sp2C, 1.0f, 8, D_80801264_chboggyfatboy);
    }
}

void func_80800E80_chboggyfatboy(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_2(Actor *, f32 *, void *);
    void func_800C4B7C(s32);
    s32 func_800DC128(s32, s32);
    s32 func_80101E14(Actor *, f32);
    s32 func_80101E4C(Actor *, f32 *);
    s32 func_801022E4(Actor *);
    extern s16 D_808012A0_chboggyfatboy[];
    extern f32 D_808012AC_chboggyfatboy[];
    extern s32 D_808012BC_chboggyfatboy;
    extern s32 D_808012CC_chboggyfatboy;
    extern s32 D_808012E8_chboggyfatboy;
    if (func_801022E4(arg0) == 0x246) {
        if (func_80101E14(arg0, 0.0f) != 0) {
            func_800C4B7C(D_808012A0_chboggyfatboy[func_800DC128(0, 5)]);
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_808012BC_chboggyfatboy);
        }
        if (func_80101E14(arg0, 0.5f) != 0) {
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_808012CC_chboggyfatboy);
        }
        if (func_80101E4C(arg0, D_808012AC_chboggyfatboy) != 0) {
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_808012E8_chboggyfatboy);
        }
    }
}

/* extern */

void func_80800F40_chboggyfatboy(Actor *arg0) {
    s32 _suexpression_entrypoint_12(void *, s32, s32);
    s32 _suexpression_entrypoint_17(void *, s32);
    s32 _suexpression_entrypoint_7(Actor *, s32, s32);
    if (func_80100094(arg0, 1U) == NULL) {
        _suexpression_entrypoint_7(arg0, 1, 0x3D);
        _suexpression_entrypoint_12(func_80100094(arg0, 1U), 0x42700000, 0x41A00000);
        _suexpression_entrypoint_17(func_80100094(arg0, 1U), 0x3E8);
    }
}

void func_80800FAC_chboggyfatboy(Actor* arg0) 
{
    if (func_80100094(arg0,1) != 0)
    {
        _suexpression_entrypoint_8(arg0, 1);
    }
}
/* extern */

s32 func_80800FE0_chboggyfatboy(s32 arg0) {
    s32 func_800F54E4();
    s32 func_800F640C(s32, s32);
    s32 func_800F64A4(s32, s32);
    s32 sp1C;
    s32 temp_v0;

    temp_v0 = func_800F54E4();
    sp1C = temp_v0;
    if (func_800F64A4(temp_v0, 0x201) == 0) {
        return 0;
    }
    return func_800F640C(sp1C, arg0) > 0;
}
