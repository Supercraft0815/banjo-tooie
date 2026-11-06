#include "common.h"

void func_80800D30_chsabreman(Actor *, s32);

void func_808017D8_chsabreman(Actor *, s32, s32);
void func_80801010_chsabreman(Actor *, s32);

OSThread *chsabreman_entrypoint_0(void)
{
    extern u8 D_80801BE0_chsabreman[];

    return (OSThread *) D_80801BE0_chsabreman;
}

OSThread *chsabreman_entrypoint_1(void)
{
    extern u8 D_80801D30_chsabreman[];

    return (OSThread *) D_80801D30_chsabreman;
}

OSThread *chsabreman_entrypoint_2(void)
{
    extern u8 D_80801D78_chsabreman[];

    return (OSThread *) D_80801D78_chsabreman;
}

OSThread *chsabreman_entrypoint_3(void)
{
    extern u8 D_80801DC0_chsabreman[];

    return (OSThread *) D_80801DC0_chsabreman;
}

int func_80800030_chsabreman(Actor *arg0) {
    struct SabremanFlags {
        u8 pad0[0x74];
        u32 pad74_21 : 11;
        u32 unk74_20 : 1;
        u32 pad74_0 : 20;
    };
    s32 _glcutDll_entrypoint_20();
    s32 _subaddielink_entrypoint_0(u8 *);
    s32 _subaddiepalette_entrypoint_0(void *, void *, s32);
    s32 func_800CB3E0(s32);
    s32 func_800DA564(s32, s32);
    void func_800FFAB0(Actor *);
    void *func_80100094(Actor *, u32);
    void func_80102424(Actor *, s32);
    void func_80102FDC(Actor *, f32);
    void func_801088A8(void *, s32, s32, void *);
    void func_80108B04(Actor *, u32);
    void func_8010A570(Actor *);
    void func_8010A590(Actor *);
    void func_8010A85C(u8 *, s32);
    f32 func_8080112C_chsabreman(Actor *);
    void func_808011F8_chsabreman();
    u8 *data;

    data = func_80100094(arg0, 0);
    func_80102FDC(arg0, 0.45f);
    func_801088A8(arg0, 0x10002000, 0, NULL);
    _subaddielink_entrypoint_0(data + 0x810);
    if (_glcutDll_entrypoint_20()) {
        _subaddiepalette_entrypoint_0(arg0, func_80100094(arg0, 0), 0x7F1);
        func_80102424(arg0, 0x19);
        arg0->position[1] = func_8080112C_chsabreman(arg0);
        return 1;
    } else {
        switch (func_800DA564(0x1CA, 2)) {
            case 0:
                func_8010A85C((u8 *)arg0, 2);
                _subaddiepalette_entrypoint_0(arg0, func_80100094(arg0, 0), 0x7F0);
                func_80108B04(arg0, 0);
                func_808011F8_chsabreman(arg0, 1);
                func_8010A570(arg0);
                ((struct SabremanFlags *)arg0)->unk74_20 = 0;
                break;
            case 1:
                _subaddiepalette_entrypoint_0(arg0, func_80100094(arg0, 0), 0x7F0);
                if (func_800CB3E0(0xB) == 1) {
                    func_80108B04(arg0, 0);
                }
                func_808011F8_chsabreman(arg0, 5);
                func_8010A590(arg0);
                arg0->position[1] = func_8080112C_chsabreman(arg0);
                break;
            case 2:
                _subaddiepalette_entrypoint_0(arg0, func_80100094(arg0, 0), 0x7F1);
                func_808011F8_chsabreman(arg0, 0xA);
                func_8010A590(arg0);
                arg0->position[1] = func_8080112C_chsabreman(arg0);
                break;
            case 3:
                func_800FFAB0(arg0);
                return 0;
        }
    }
    return 1;
}

void func_80800218_chsabreman(Actor *arg0) {
    struct SabremanData {
        u8 pad0[4];
        s16 unk4;
        u8 pad6[0x812];
        s16 unk818;
        s16 unk81A[3];
    };
    struct SabremanFlags {
        u8 pad0[0x74];
        u32 pad74_21 : 11;
        u32 unk74_20 : 1;
        u32 pad74_0 : 20;
    };
    s32 _subaddieDll_entrypoint_4(void *, s32);
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
    s32 _subaddiedialog_entrypoint_8(s32, void *, s32 *, s32 *, s32);
    s32 _subaddiepalette_entrypoint_1(Actor *, void *);
    s32 _subaddiepalette_entrypoint_2(Actor *, void *, s32, f32);
    s32 _subaddieskeleton_entrypoint_0(Actor *, s32, f32 *);
    s32 _subaddietaxi_entrypoint_1(Actor *, s32);
    s32 _subaddietaxi_entrypoint_11(Actor *, s32);
    s32 _subaddietaxi_entrypoint_12(Actor *, s32);
    void _subaddietaxi_entrypoint_14(Actor *, s32);
    s32 _subaddietaxi_entrypoint_15(Actor *, s32);
    s32 _subaddietaxi_entrypoint_5(Actor *, s32);
    void _subaddietaxi_entrypoint_9(Actor *, s32);
    void _sudeflect_entrypoint_0(f32 *, f32, f32, s32);
    s32 func_800C0638(void);
    s32 func_800D9078(f32 *);
    s32 func_800D90A4(f32 *);
    s32 func_800DA7A8(s32, s32, s32);
    s32 func_800DC128(s32, s32);
    f32 func_800DC178(f32, f32);
    void func_800EE88C(f32 *, s16 *);
    f32 func_800EEB40(f32 *, f32 *);
    s32 func_800F54E4();
    s32 func_800F64A4(s32, s32);
    s32 func_800F6CC8(s32);
    void func_800F82D4(s32, s32);
    void *func_80100094(Actor *, u32);
    s32 func_80101180(s32, s32, s32);
    s32 func_80101DDC(Actor *);
    s32 func_80101E14(Actor *, f32);
    void func_80102424(Actor *, s32);
    s32 func_80102BF8(void *, s32, s32, s32);
    s32 func_80102CF4(Actor *, f32);
    f32 func_80102D78(void *, s32 *);
    void func_8010A590(Actor *);
    void func_8010A85C(u8 *, s32);
    s32 func_8010B990(Actor *, s32);
    s32 func_8010CAC0(f32 *, s32);
    void func_808011AC_chsabreman(void *);
    void func_808011F8_chsabreman();
    void func_80801218_chsabreman(Actor *);
    void func_80801724_chsabreman(Actor *, s32, s32);
    extern s32 D_80801BF8_chsabreman;
    extern s32 D_80801C20_chsabreman;
    extern s32 D_80801E08_chsabreman;
    extern s8 D_80801E16_chsabreman;
    struct SabremanData *data;
    s32 sp60;
    s32 sp5C;
    s32 sp58;
    f32 sp4C[3];
    f32 sp40[3];
    f32 sp34[3];

    data = func_80100094(arg0, 0);
    sp60 = 2;
    sp5C = 8;
    switch (arg0->unk70_10) {
        case 1:
        case 6:
        case 12:
        case 24:
            break;
        case 2:
            if (func_800D9078(&arg0->unk58)) {
                func_808011F8_chsabreman(arg0, 3);
                func_80101180(0x1FE, 10, 0);
                func_8010A85C(arg0, 1);
                ((struct SabremanFlags *)arg0)->unk74_20 = 1;
            }
            break;
        case 3:
            if (func_80101DDC(arg0)) {
                func_808011F8_chsabreman(arg0, 4);
            }
            break;
        case 4:
            if (func_80101DDC(arg0)) {
                func_80801724_chsabreman(arg0, 3, 1);
                func_8010A590(arg0);
                _subaddiedialog_entrypoint_11(arg0->unk0, 0x1271, 14, arg0->position, 0xAA);
                func_808011F8_chsabreman(arg0, 6);
                func_800DA7A8(0x1CA, 1, 2);
            }
            break;
        case 5:
            sp5C = 0;
            D_80801E16_chsabreman = 6;
            _subaddiedialog_entrypoint_8(arg0, arg0->position, &D_80801E08_chsabreman, &D_80801BF8_chsabreman, 5);
            break;
        case 7:
            if (func_80101DDC(arg0)) {
                _subaddieDll_entrypoint_4(arg0, 0);
                if (*(s32 *)&arg0->unk50 >= 3) {
                    func_800F82D4(func_800F54E4(), 0);
                    if (!func_800F6CC8(func_800F54E4())) {
                        _subaddiepalette_entrypoint_2(arg0, func_80100094(arg0, 0), 0x7F1, 3.0f);
                        func_808011F8_chsabreman(arg0, 8);
                        func_808017D8_chsabreman(arg0, 1, 0x30);
                    } else {
                        func_808011F8_chsabreman(arg0, 5);
                    }
                } else {
                    func_808011F8_chsabreman(arg0, 5);
                }
            }
            break;
        case 8:
            if (((struct SabremanData *)func_80100094(arg0, 0))->unk4 == 0) {
                func_808011F8_chsabreman(arg0, 9);
                arg0->unk64_20 = 0;
            }
            break;
        case 9:
            if (func_80101E14(arg0, 0.23f)) {
                func_80101180(0x1FE, 0x48, 3);
                arg0->unk64_20 = 1;
            }
            if (func_80101DDC(arg0)) {
                if (func_800F64A4(func_800F54E4(), 0x400)) {
                    sp58 = 0x12D9;
                } else {
                    sp58 = 0x1273;
                }
                func_808011F8_chsabreman(arg0, 11);
                func_800DA7A8(0x1CA, 2, 2);
                func_80801724_chsabreman(arg0, 2, 1);
                _subaddiedialog_entrypoint_11(arg0->unk0, sp58, 14, arg0->position, 0xAA);
            }
            break;
        case 10:
            func_808011AC_chsabreman(arg0);
            D_80801E16_chsabreman = 11;
            _subaddiedialog_entrypoint_8(arg0, arg0->position, &D_80801E08_chsabreman, &D_80801C20_chsabreman, 4);
            break;
        case 11:
            func_808011AC_chsabreman(arg0);
            break;
        case 13:
            sp60 = 0;
            break;
        case 14:
            sp60 = 0;
            func_808011AC_chsabreman(arg0);
            if (_subaddietaxi_entrypoint_1(arg0, 11)) {
                func_808011F8_chsabreman(arg0, 17);
                _subaddiedialog_entrypoint_11(arg0->unk0, 0x1275, 14, arg0->position, 0xAA);
                func_800DA7A8(0x1CA, 3, 2);
            }
            break;
        case 15:
            if (_subaddietaxi_entrypoint_11(arg0, 11) && _subaddietaxi_entrypoint_5(arg0, 11)) {
                _subaddietaxi_entrypoint_14(arg0, 11);
                func_808011F8_chsabreman(arg0, 18);
                func_8010A590(arg0);
            }
            sp60 = _subaddietaxi_entrypoint_12(arg0, 11);
            break;
        case 16:
            func_808011AC_chsabreman(arg0);
            break;
        case 17:
            func_808011AC_chsabreman(arg0);
            break;
        case 18:
            if (_subaddietaxi_entrypoint_15(arg0, 11)) {
                func_808011F8_chsabreman(arg0, 12);
            }
            break;
        case 19:
            func_800EE88C(sp4C, data->unk81A);
            arg0->unk54 = func_80102D78(arg0, sp4C);
            func_80102BF8(arg0, 0x3DCCCCCD, 0x40800000, 0x43160000);
            if (func_80102CF4(arg0, 8.0f)) {
                func_808011F8_chsabreman(arg0, 20);
                ((f32 *)arg0->actorData)[3] = 50.0f;
            }
            break;
        case 20:
            func_800EE88C(sp40, data->unk81A);
            arg0->unk54 = func_80102D78(arg0, sp40);
            func_80102BF8(arg0, 0x3DCCCCCD, 0x40800000, 0x43160000);
            func_8010B990(arg0, 0x1005);
            if (func_800EEB40(arg0->position, sp40) < 2500.0f) {
                func_808011F8_chsabreman(arg0, 21);
            }
            break;
        case 21:
            arg0->unk54 = data->unk818;
            func_80102BF8(arg0, 0x3DCCCCCD, 0x40800000, 0x43160000);
            if (func_80102CF4(arg0, 8.0f)) {
                func_808011F8_chsabreman(arg0, 22);
            }
            break;
        case 22:
            if (func_80101DDC(arg0)) {
                func_808011F8_chsabreman(arg0, 23);
            }
            break;
        case 23:
            if (!func_800C0638() && func_800D90A4(&arg0->unk58) && func_8010CAC0(arg0->position, 400) && arg0->unk58 <= 0.0f) {
                _subaddiedialog_entrypoint_11(arg0->unk0, 0x1293 + func_800DC128(0, 3), 0, arg0->position, 0xAA);
                func_80102424(arg0, 24);
                arg0->unk58 = func_800DC178(8.0f, 12.0f);
            }
            break;
    }
    _subaddietaxi_entrypoint_9(arg0, 11);
    _subaddiepalette_entrypoint_1(arg0, func_80100094(arg0, 0));
    func_80801218_chsabreman(arg0);
    if ((sp60 | sp5C) && _subaddieskeleton_entrypoint_0(arg0, 1, sp34)) {
        _sudeflect_entrypoint_0(sp34, 0.0f, 90.0f, sp60 | sp5C);
    }
}

s32 func_808008C8_chsabreman(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _chlifeforcespell_entrypoint_1(Actor **, void *, s32, f32, s32);
    s32 _gcdialogcamera_entrypoint_3(s32 *, f32);
    s32 _glcutDll_entrypoint_20();
    s32 _subaddieDll_entrypoint_4(void *, s32);
    s32 _subaddielink_entrypoint_1(void *, Unk80132ED0 *);
    s32 _subaddiepalette_entrypoint_4(void *, void *);
    s32 _subaddietaxi_entrypoint_13(Actor *, s32, void *, s32);
    s32 _subaddietaxi_entrypoint_2(Actor *, s32);
    void func_800C01A8(s16, s32);
    s32 func_800D1000(s32, s32, s32 *, s32, s32);
    s32 func_800DA564(s32, s32);
    s32 func_800F54E4();
    s32 func_800F8300(s32, s32, s32);
    void func_800FC660(u32);
    void func_800FFAB0(Actor *);
    void *func_80100094(Actor *, u32);
    void func_808016E4_chsabreman(Actor *);
    void func_80102FDC(Actor *, f32);
    Actor *func_801084B0(s32, Actor **);
    void func_80108B04(Actor *, u32);
    void func_808011F8_chsabreman();
    s32 func_8080167C_chsabreman(s32, s32, s32);
    extern s32 D_80801BE8_chsabreman;
#ifndef BT_NATIVE
    extern s32 _chsabreman_entrypoint_0;
#endif
    struct SabremanFlags {
        u32 pad : 26;
        u32 active : 1;
        u32 rest : 5;
    };
    u8 *data;
    Actor *child;

    switch (arg1) {
        case 0x3E:
            if (func_800DA564(0x1CA, 2) == 2 && _subaddietaxi_entrypoint_2(arg0, 0xB)) {
                func_808011F8_chsabreman(arg0, 0xD);
            }
            break;
        case 0x40:
            if (func_800DA564(0x1CA, 2) == 1 && arg0->unk70_10 == 5) {
                func_800FC660(0xE);
                func_808011F8_chsabreman(arg0, 7);
                _subaddieDll_entrypoint_4(arg0, 1);
                (*(s32 *)((u8 *)arg0 + 0x50))++;
                if (*(s32 *)((u8 *)arg0 + 0x50) == 3) {
                    func_800F8300(func_800F54E4(), 2, (s32)((u8 *)arg0 + 4));
                }
            }
            break;
        case 0x3D:
            data = func_80100094((s32)arg0, 0);
            switch (arg2) {
                case 0:
                    child = func_801084B0(0x1FE, &arg0);
                    _subaddielink_entrypoint_1(data + 0x810, *(Unk80132ED0 **)child);
                    func_80102FDC(child, *(f32 *)((u8 *)arg0 + 0x38));
                    *(s32 *)((u8 *)child + 0x3C) = *(s32 *)arg0;
                    break;
                case 1:
                    *(s32 *)((u8 *)arg0 + 0x3C) = _chlifeforcespell_entrypoint_1(&arg0, (u8 *)arg0 + 4, 0x64, 4.0f, 0x12);
                    func_808017D8_chsabreman(arg0, 0x1B, 0x30);
                    break;
            }
            break;
        case 0x2E:
            switch (arg0->unk70_10) {
                case 6:
                    func_808016E4_chsabreman(arg0);
                    func_808011F8_chsabreman(arg0, 5);
                    _subaddieDll_entrypoint_4(arg0, 0);
                    break;
                case 11:
                    func_808016E4_chsabreman(arg0);
                    func_808011F8_chsabreman(arg0, 0xA);
                    break;
                case 24:
                    func_808011F8_chsabreman(arg0, 0x17);
                    break;
            }
            if (*(s16 *)&arg2 == 0x1275) {
                func_800C01A8(0x64, 0);
                func_808017D8_chsabreman(arg0, 8, 0x2030);
                func_800D1000(0x3F, 1, 0, 1, 0);
            }
            break;
        case 0xB:
            if (arg2 == 8) {
                func_808016E4_chsabreman(arg0);
                func_808011F8_chsabreman(arg0, 0x13);
                return 4;
            }
            return 3;
        case 0x44:
            func_80801010_chsabreman(arg0, arg2);
            break;
        case 0x4B:
            func_80108B04(arg0, 1);
            _subaddieDll_entrypoint_4(arg0, 1);
            func_808011F8_chsabreman(arg0, 2);
            *(f32 *)((u8 *)arg0 + 0x58) = 14.0f;
            break;
        case 0x4C:
            *(s32 *)((u8 *)arg0 + 0x3C) = 0;
            break;
        case 0x52:
            _gcdialogcamera_entrypoint_3(&D_80801BE8_chsabreman, *(f32 *)((u8 *)arg0 + 0x38));
            break;
        case 0x1F:
            func_80800D30_chsabreman(arg0, arg2);
            break;
        case 0x57:
            return func_8080167C_chsabreman((s32)arg0, arg2 & 0xFFFF, ((u32)arg2 & 0xFFFF0000) >> 16);
        case 0x95:
            *(s32 *)((u8 *)arg0 + 0x50) = 0;
            if (_glcutDll_entrypoint_20() || _subaddietaxi_entrypoint_13(arg0, 0xB, &_chsabreman_entrypoint_0, 3)) {
                func_80800030_chsabreman(arg0);
            } else if (((struct SabremanFlags *)((u8 *)arg0 + 0x78))->active) {
                func_800FFAB0(arg0);
            }
            break;
        case 0x29:
            data = func_80100094((s32)arg0, 0);
            _subaddiepalette_entrypoint_4(arg0, data);
            break;
        default:
            return 0;
    }
    return 1;
}

void func_80800CDC_chsabreman(Actor *arg0, s32 arg1) {
    void *func_80100094(Actor *, u32);
    Actor *_subaddielink_entrypoint_4(u8 *);
    s32 func_80101808(void *, s32 *);
    void func_8010A764(s32, s32);
    extern s32 func_801017D0;
    Actor *temp_v0;

    if (func_80101808(arg0, &func_801017D0) != 0) {
        temp_v0 = _subaddielink_entrypoint_4((u8 *)func_80100094(arg0, 0U) + 0x810);
        if (temp_v0 != NULL) {
            func_8010A764((s32)temp_v0, arg1);
        }
    }
}

void func_80800D30_chsabreman(Actor *arg0, s32 arg1) {
    void _chlifeforcespell_entrypoint_2(Actor *, s32, s32 *);
    void _subaddiefade_entrypoint_11(Actor *, s32 *);
    void _subaddiefade_entrypoint_9(Actor *, s32 *);
    void _subaddiepalette_entrypoint_3(Actor *, void *, s32);
    void func_800DF744(s32, s32);
    void *func_80100094(Actor *, u32);
    s32 func_801015D0(Actor *);
    f32 func_80101F24(Actor *);
    s32 func_801022E4(Actor *);
    s32 func_80102320(Actor *, f32, f32);
    s32 sp4C;
    s32 sp40[3];
    s32 sp34[3];
    s32 sp30;
    s32 sp2C;
    s32 sp28;

    sp4C = func_801022E4(arg0);
    if (arg0->unk3C != NULL) {
        _subaddiefade_entrypoint_9(arg0, sp34);
        _chlifeforcespell_entrypoint_2(arg0, arg0->unk3C, sp40);
        _subaddiefade_entrypoint_11(arg0, sp40);
        func_801015D0(arg0);
        _subaddiefade_entrypoint_11(arg0, sp34);
    } else {
        func_801015D0(arg0);
    }
    switch (sp4C) {
        case 0x2FB:
            if (func_80101F24(arg0) < 0.602f) {
                sp30 = 1;
            } else {
                sp30 = 0;
            }
            sp2C = func_80102320(arg0, 0.602f, 0.819f);
            func_800DF744(5, 1);
            func_800DF744(3, 0);
            func_800DF744(6, sp30 && arg0->unk64_20);
            func_800DF744(4, sp2C);
            break;
        case 0x2FA:
            sp28 = func_80102320(arg0, 0.33f, 0.93f);
            func_800DF744(5, sp28 == 0);
            func_800DF744(3, sp28);
            func_800DF744(6, 0);
            func_800DF744(4, 0);
            break;
        default:
            func_800DF744(5, 1);
            func_800DF744(3, 0);
            func_800DF744(6, 0);
            func_800DF744(4, 0);
            break;
    }
    _subaddiepalette_entrypoint_3(arg0, func_80100094(arg0, 0), arg1);
}

void func_80800F04_chsabreman(s32 arg0, void *arg1, s32 arg2, s32 arg3) {
    s32 _chbaddiesetup_entrypoint_6(s32 *, s32, s32, s32, s32, s32, s32);
    s32 func_800DA564(s32, s32);
    extern s32 _subaddietaxi_entrypoint_16;
    if (func_800DA564(0x1CA, 2) != 3) {
        _chbaddiesetup_entrypoint_6(&_subaddietaxi_entrypoint_16, arg0, (*(s32 *)((s8 *)(arg1) + (0))), (*(s32 *)((s8 *)(arg1) + (4))), (*(s32 *)((s8 *)(arg1) + (8))), arg2, arg3);
    }
}

/* extern */

s32 func_80800F74_chsabreman(s32 arg0, s32 arg1, s32 arg2) {
    Prop *_gccubesearch_entrypoint_15(u32, u32, f32 *);
    s32 func_800C05B8(s32, s32, s32, s32, s32, s32, s32);
    s32 func_800CBC3C(s32);
    s32 func_800EA05C();
    void func_800EE88C(f32 *, s16 *);
    Prop *temp_v0;
    s32 sp28;

    if (func_800EA05C() == 0x127) {
        temp_v0 = _gccubesearch_entrypoint_15(0x154, 0, arg1);
        if (temp_v0 != 0) {
            func_800EE88C(arg2, temp_v0->position);
            sp28 = func_800CBC3C(arg2);
            if (func_800CBC3C(arg1) == sp28) {
                return 2;
            }
        }
    }
    func_800C05B8(0x1276, 1, 0, 0, 0, 0, 0);
    return 1;
}

void func_80801010_chsabreman(Actor *arg0, s32 arg1) {
    Prop *_gccubesearch_entrypoint_15(u32, u32, f32 *);
    void _subaddietaxi_entrypoint_0(Actor *, s32, f32 *, s32);
    void _subaddietaxi_entrypoint_10(Actor *, s32, s32);
    s32 func_800CB3E0(s32);
    void func_800EE814(s16 *, s16 *);
    void func_800EE88C(f32 *, s16 *);
    void *func_80100094(Actor *, u32);
    void func_8010A570(Actor *);
    void func_808011F8_chsabreman();
    s16 *sp3C;
    f32 sp30[3];
    Prop *sp2C;

    sp3C = func_80100094(arg0, 0);
    if (func_80800030_chsabreman(arg0) != 0) {
            switch (func_800CB3E0(arg1)) {
                case 1:
                    break;
                case 3:
                    _subaddietaxi_entrypoint_10(arg0, arg1, 0xF);
                    break;
                case 4:
                    func_800EE88C(sp30, _gccubesearch_entrypoint_15(0x154, 0, arg0->position)->position);
                    sp2C = _gccubesearch_entrypoint_15(0x347, 0, arg0->position);
                    func_800EE814(sp3C + 0x40D, sp2C->position);
                    sp3C[0x40C] = sp2C->FlagOrRotation;
                    func_8010A570(arg0);
                    _subaddietaxi_entrypoint_0(arg0, arg1, sp30, 0xE);
                    break;
                case 6:
                    func_808011F8_chsabreman(arg0, 0x10);
                    func_8010A570(arg0);
                    break;
            }
    }
}

/* extern */

f32 func_8080112C_chsabreman(Actor *arg0) {
    s32 func_800BEF00(f32[3], f32[3], f32[3], s32);
    void func_800EE7F8(f32 *, f32 *);
    f32 sp34[3];
    f32 sp28[3];
    f32 sp1C[3];

    func_800EE7F8(sp34, arg0->position);
    func_800EE7F8(sp28, arg0->position);
    sp34[1] += 100.0f;
    sp28[1] -= 400.0f;
    func_800BEF00(sp34, sp28, sp1C, arg0->unk14);
    return sp28[1];
}

/* extern */

void func_808011AC_chsabreman(void *arg0) {
    s32 func_80102BF8(void *, s32, s32, s32);
    f32 func_80102D78(void *, s32 *);
    s32 func_8010D600(s32 *);
    s32 sp1C[3];

    func_8010D600(sp1C);
    (*(f32 *)((s8 *)(arg0) + (0x54))) = func_80102D78(arg0, sp1C);
    func_80102BF8(arg0, 0x3DCCCCCD, 0x40800000, 0x43160000);
}

void func_808011F8_chsabreman()
{
    void func_80102424();
    func_80102424();
}

void func_80801218_chsabreman(Actor *arg0) {
    typedef struct { u32 words[3]; } AudioTimes;
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    s32 _subaddieaudioquick_entrypoint_3(Actor *, f32 *, u32 *, f32);
    void _subaddieaudioquick_entrypoint_4(Actor *, f32 *, u32 *, u32 *);
    s32 _subaddieskeleton_entrypoint_2(Unk80132ED0 *, s32, f32 *);
    s32 func_8001210C(s32);
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    s32 func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    u8 func_800C4350(u8, f32 *, s32 *);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF1B8(f32 *, f32, f32);
    s32 func_80101E14(Actor *, f32);
    f32 func_80101F24(Actor *);
    s32 func_801022E4(Actor *);
    extern AudioTimes D_80801E18_chsabreman, D_80801E24_chsabreman;
    extern u32 D_80801E30_chsabreman[], D_80801E40_chsabreman[];
    extern u32 D_80801E50_chsabreman[], D_80801E8C_chsabreman[];
    extern u32 D_80801E9C_chsabreman[], D_80801EC4_chsabreman[];
    extern u32 D_80801EFC_chsabreman[], D_80801F08_chsabreman[];
    extern u32 D_80801F14_chsabreman[], D_80801F2C_chsabreman[];
    extern u32 D_80801F44_chsabreman[], D_80801F5C_chsabreman[];
    extern u32 D_80801F6C_chsabreman[];
    extern s32 D_80801E60_chsabreman[], D_80801ED4_chsabreman[];
    extern s32 D_80801F78_chsabreman[], D_80801F88_chsabreman[], D_80801F98_chsabreman[];
    AudioTimes sp5C;
    f32 sp50[3];
    f32 sp44[3];
    f32 sp38[3];
    AudioTimes sp2C;

    switch (func_801022E4(arg0)) {
        case 0x2F7:
            sp5C = D_80801E18_chsabreman;
            _subaddieaudioquick_entrypoint_4(arg0, arg0->position, D_80801E30_chsabreman, sp5C.words);
            _subaddieaudioquick_entrypoint_3(arg0, arg0->position, D_80801E40_chsabreman, 0.2f);
            break;
        case 0x2F9:
            if (func_80101E14(arg0, 0.02f)) {
                if (_subaddieskeleton_entrypoint_2(arg0->unk0, 5, sp50)) {
                    func_800EE7F8(sp44, sp50);
                    func_800EF1B8(sp44, arg0->rotation[1], -50.0f);
                    sp44[1] += 30.0f;
                    func_800BABB8(0, sp50, sp44, 1.0f, D_80801E60_chsabreman);
                }
                _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_80801E50_chsabreman);
            }
            _subaddieaudioquick_entrypoint_4(arg0, arg0->position, D_80801E8C_chsabreman, D_80801E9C_chsabreman);
            break;
        case 0x2FA:
            _subaddieaudioquick_entrypoint_3(arg0, arg0->position, D_80801EC4_chsabreman, 0.0f);
            _subaddieaudioquick_entrypoint_3(arg0, arg0->position, D_80801E30_chsabreman, 0.75f);
            if (func_80101F24(arg0) < 0.7f && func_8001210C(1) &&
                _subaddieskeleton_entrypoint_2(arg0->unk0, 4, sp38)) {
                func_800BBCB8(sp38, NULL, 1.0f, 1, D_80801ED4_chsabreman);
            }
            break;
        case 0x2FB:
            _subaddieaudioquick_entrypoint_3(arg0, arg0->position, D_80801EFC_chsabreman, 0.6f);
            _subaddieaudioquick_entrypoint_3(arg0, arg0->position, D_80801F08_chsabreman, 0.8f);
            break;
        case 0x2FC:
            _subaddieaudioquick_entrypoint_3(arg0, arg0->position, D_80801F14_chsabreman, 0.025f);
            _subaddieaudioquick_entrypoint_3(arg0, arg0->position, D_80801F2C_chsabreman, 0.12f);
            _subaddieaudioquick_entrypoint_4(arg0, arg0->position, D_80801F44_chsabreman, D_80801F5C_chsabreman);
            break;
        case 0x2FD:
            sp2C = D_80801E24_chsabreman;
            _subaddieaudioquick_entrypoint_4(arg0, arg0->position, D_80801E30_chsabreman, sp2C.words);
            break;
        case 0x2FE:
            _subaddieaudioquick_entrypoint_3(arg0, arg0->position, D_80801F6C_chsabreman, 0.8f);
            break;
        case 0x2FF:
            if (arg0->unk5F == 0) {
                arg0->unk5F = func_800C4350(0, arg0->position, D_80801F78_chsabreman);
            }
            if (arg0->unk5F != 0) {
                if (func_80101E14(arg0, 0.0f)) {
                    func_800C4350(arg0->unk5F, arg0->position, D_80801F88_chsabreman);
                }
                if (func_80101E14(arg0, 0.65f)) {
                    func_800C4350(arg0->unk5F, arg0->position, D_80801F98_chsabreman);
                }
            }
            break;
    }
}

void func_8080158C_chsabreman(Actor *arg0) {
    s32 func_800DA564(s32, s32);
    void func_800FFAB0(Actor*);
    void func_80102FDC(Actor*, f32);
    func_80102FDC(arg0, 0.45f);
    if (func_800DA564(0x1CA, 2) != 3) {
        func_800FFAB0(arg0);
    }
}

/* extern */

void func_808015D4_chsabreman(Actor *arg0) {
    s32 _subaddieskeleton_entrypoint_0(Actor *, s32, f32 *);
    void _sudeflect_entrypoint_0(f32 *, f32, f32, s32);
    void func_80801218_chsabreman(Actor *);
    f32 sp1C[3];

    if (_subaddieskeleton_entrypoint_0(arg0, 1, sp1C) != 0) {
        _sudeflect_entrypoint_0(arg0->position, 0.0f, 100.0f, 0xA);
    }
    func_80801218_chsabreman(arg0);
}

/* extern */

void func_80801620_chsabreman(Actor *arg0, void *arg1) {
    void func_800DF744(s32, s32);
    void func_80101870(Actor *, void *);
    func_800DF744(5, 1);
    func_800DF744(3, 0);
    func_800DF744(6, 0);
    func_800DF744(4, 0);
    func_80101870(arg0, arg1);
}

/* extern */

s32 func_8080167C_chsabreman(s32 arg0, s32 arg1, s32 arg2) {
    s32 _gcdialogcamera_entrypoint_0(s32, s32);
    void *func_80100094(Actor *, u32);
    void func_80801724_chsabreman(Actor *, s32, s32);
    void *temp_v0;

    if (_gcdialogcamera_entrypoint_0(arg1, arg2) != 0) {
        temp_v0 = func_80100094(arg0, 0);
        if ((temp_v0 != NULL) && ((*(s16 *)((s8 *)(temp_v0) + (0x820))) != 2)) {
            func_80801724_chsabreman(arg0, 2, 1);
        }
        return 2;
    }
    return 1;
}

void func_808016E4_chsabreman(Actor *arg0) {
    void _capod_entrypoint_3(u32);
    void *func_80100094(Actor *, u32);
    u8 *sp1C[1];
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0);
    if ((*(s16 *)((s8 *)(temp_v0) + (0x820))) != 0) {
        sp1C[0] = temp_v0;
        _capod_entrypoint_3(0U);
        temp_v0 = sp1C[0];
        (*(s16 *)((s8 *)(temp_v0) + (0x820))) = 0;
    }
}

void func_80801724_chsabreman(Actor *arg0, s32 arg1, s32 arg2) {
    void *func_80100094(Actor *, u32);
    void _capod_entrypoint_2(Unk80132ED0 *, u32, s32);
    void _capod_entrypoint_7(s32, s32);
    s32 _capod_entrypoint_8(s32);
    s32 _gcdialogcamera_entrypoint_3(s32 *, f32);
    void _gcdialogcamera_entrypoint_4(f32 *);
    void _gcdialogcamera_entrypoint_5(f32 *);
    void _gcdialogcamera_entrypoint_8(void);
    extern s32 D_80801BE8_chsabreman;
    s16 *data;

    data = func_80100094(arg0, 0U);
    switch (data[0x410]) {
        case 0:
            _capod_entrypoint_2(arg0->unk0, 0xE, 0);
        case 1:
            _capod_entrypoint_8(1);
            data[0x410] = 2;
            _gcdialogcamera_entrypoint_3(&D_80801BE8_chsabreman, arg0->scale);
            _gcdialogcamera_entrypoint_4(arg0->position);
            _gcdialogcamera_entrypoint_5(arg0->rotation);
            _gcdialogcamera_entrypoint_8();
        case 2:
            _capod_entrypoint_7(arg1, arg2);
            break;
    }
}

void func_808017D8_chsabreman(Actor *arg0, s32 arg1, s32 arg2) {
    void *func_80100094(Actor *, u32);
    void _capod_entrypoint_2(Unk80132ED0 *, u32, s32);
    void _capod_entrypoint_6(Unk80132ED0 *, s32, s32);
    s16 *data;

    data = func_80100094(arg0, 0U);
    switch (data[0x410]) {
        case 0:
            _capod_entrypoint_2(arg0->unk0, 0xE, arg2);
        case 2:
            data[0x410] = 1;
        case 1:
            _capod_entrypoint_6(arg0->unk0, arg1, arg2);
            break;
    }
}

void func_80801864_chsabreman(Actor *arg0) {
    s32 func_800DA564(s32, s32);
    void func_80102424(Actor *, s32);
    void func_80103110(Actor *, u32);
    void func_8010A800(Actor *, s32);
    if (func_800DA564(0x1CA, 2) > 0) {
        func_80102424(arg0, 3);
        func_80103110(arg0, 0);
    }
    if (func_800DA564(0x1CA, 2) >= 2) {
        arg0->unk64_20 = 1;
    }
    func_8010A800(arg0, 2);
}

void func_808018DC_chsabreman(Actor *arg0) {
    s32 func_80101DDC(Actor *);
    void func_80102424(Actor *, s32);
    void func_80103110(Actor *, u32);

    switch (arg0->unk70_10) {
        case 2:
            if (func_80101DDC(arg0) != 0) {
                func_80102424(arg0, 3);
                func_80103110(arg0, 0);
            }
        case 3:
            return;
    }
}

void func_8080193C_chsabreman(Actor *arg0, void *arg1) {
    void func_800DF744(s32, s32);
    void func_80101870(Actor *, void *);
    s32 var_a1;

    if (arg0->unk64_20) {
        var_a1 = 0;
    } else {
        var_a1 = 1;
    }
    func_800DF744(3, var_a1);
    func_800DF744(4, 1);
    func_800DF744(5, 1);
    func_80101870(arg0, arg1);
}

s32 func_808019A4_chsabreman(Actor *arg0, s32 arg1, s32 arg2) {
    void func_80102424(Actor *, s32);
    s32 *data = &arg2;
    switch (arg1) {
        case 0xA:
            func_80102424(arg0, 2);
            break;
        case 0x48:
            arg0->unk64_20 = 1;
            break;
        default:
            return 0;
    }
    return 1;
}
