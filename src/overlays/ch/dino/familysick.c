#include "common.h"
void func_80102424(Actor *, s32);

OSThread *chdinofamilysick_entrypoint_0(void)
{
    extern u8 D_80800E60_chdinofamilysick[];

    return (OSThread *) D_80800E60_chdinofamilysick;
}

void func_8080000C_chdinofamilysick(Actor *arg0) {
    s32 _subaddiedialog_entrypoint_4(f32 *, s32, s32);
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
    s32 _subaddietaxi_entrypoint_1(Actor *, s32);
    s32 _subaddietaxi_entrypoint_11(Actor *, s32);
    s32 _subaddietaxi_entrypoint_5(Actor *, s32);
    void _subaddietaxi_entrypoint_9(Actor *, s32);
    s32 _chdinofamilyfx_entrypoint_0(u8 *);
    void _sudeflect_entrypoint_1(f32 *, f32, f32, f32, s32);
    void func_800DA544(GameFlag);

    switch (arg0->unk70_10) {
        case 1:
            if (_subaddiedialog_entrypoint_4(arg0->position, 0x258, 0)) {
                _subaddiedialog_entrypoint_11(arg0->unk0, 0x17C7, 0xF, arg0->position, 0x39);
            }
            _sudeflect_entrypoint_1(arg0->position, arg0->scale * 235.0f, 0.0f, arg0->scale * 179.0f, 0x1E);
            break;
        case 3:
            if (_subaddietaxi_entrypoint_1(arg0, 2)) {
                func_800DA544(0x189);
                func_80102424(arg0, 5);
            }
            break;
        case 4:
            if (_subaddietaxi_entrypoint_11(arg0, 2) && _subaddietaxi_entrypoint_5(arg0, 2)) {
                func_80102424(arg0, 1);
            }
            _sudeflect_entrypoint_1(arg0->position, arg0->scale * 235.0f, 0.0f, arg0->scale * 179.0f, 0x1E);
            break;
        case 5:
            if (_subaddiedialog_entrypoint_4(arg0->position, 0x258, 0)) {
                _subaddiedialog_entrypoint_11(arg0->unk0, 0x17C8, 0xF, arg0->position, 0x39);
            }
            _sudeflect_entrypoint_1(arg0->position, arg0->scale * 235.0f, 0.0f, arg0->scale * 179.0f, 0x1E);
            break;
    }
    _subaddietaxi_entrypoint_9(arg0, 2);
    _chdinofamilyfx_entrypoint_0((u8 *)arg0);
}

/* extern */

f32 func_808001FC_chdinofamilysick(s32 arg0, f32 arg1[3]) {
    s32 _gccubesearch_entrypoint_9(s32, Prop **, s32);
    void _gspropctrl_entrypoint_11(Prop *, f32[3]);
    s32 _gspropctrl_entrypoint_12(Prop *);
    Prop *sp1C;

    _gccubesearch_entrypoint_9(0x52D, &sp1C, 1);
    _gspropctrl_entrypoint_11(sp1C, arg1);
    return (f32) _gspropctrl_entrypoint_12(sp1C);
}

void func_80800244_chdinofamilysick(Actor *arg0, s32 arg1) {
    s32 func_800CB3E0(s32);
    void _subaddietaxi_entrypoint_10(Actor *, s32, s32);
    void _subaddietaxi_entrypoint_0(Actor *, s32, f32 *, s32);
    f32 sp24[3];

    switch (func_800CB3E0(arg1)) {
        case 1:
            func_80102424(arg0, 1);
            break;
        case 3:
            _subaddietaxi_entrypoint_10(arg0, arg1, 4);
            break;
        case 4:
            arg0->rotation[1] = func_808001FC_chdinofamilysick(arg1, sp24);
            func_80102424(arg0, 3);
            _subaddietaxi_entrypoint_0(arg0, arg1, sp24, -1);
            break;
        case 6:
            func_80102424(arg0, 5);
            break;
    }
}

void func_8080030C_chdinofamilysick(volatile unsigned int arg0, void *arg1, s32 arg2, s32 arg3)
{
  s32 _chbaddiesetup_entrypoint_6(s32 *, s32, s32, s32, s32, s32, s32);
  extern s32 _subaddietaxi_entrypoint_16;
  _chbaddiesetup_entrypoint_6(&_subaddietaxi_entrypoint_16, arg0, *((s32 *) (((s8 *) arg1) + 0)), *((s32 *) (((s8 *) arg1) + 4)), *((s32 *) (((s8 *) arg1) + 8)), arg2, arg3);
}

/* extern */

s32 func_80800368_chdinofamilysick(s32 arg0, s32 arg1, f32 arg2[3]) {
    s32 func_800EA05C();
    if (func_800EA05C() == 0x121) {
        func_808001FC_chdinofamilysick(arg0, arg2);
        return 2;
    }
    return 1;
}

s32 func_808003B0_chdinofamilysick(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _gcdialogcamera_entrypoint_3(s32 *, f32);
    void _gcdialogcamera_entrypoint_4(f32 *);
    s32 _glcutDll_entrypoint_20();
    s32 _subaddietaxi_entrypoint_13(Actor *, s32, void *, s32);
    s32 _subaddietaxi_entrypoint_2(Actor *, s32);
    s32 func_800CB3E0(s32);
    s32 func_800DA298(s32);
    void func_800DF744(s32, s32);
    void func_800FFAB0(Actor *);
    s32 func_801015D0(Actor *);
    void func_80101EE4(Actor *, f32);
    s32 func_801022E4(Actor *);
    void func_80102424(Actor *, s32);
    extern s32 D_80800E98_chdinofamilysick;
#ifndef BT_NATIVE
    extern s32 _chdinofamilysick_entrypoint_0;
#endif

    switch (arg1) {
        case 0x3E:
            if (arg0->unk70_10 == 1 || arg0->unk70_10 == 2 || arg0->unk70_10 == 4) {
                if (func_800DA298(0x15D) && _subaddietaxi_entrypoint_2(arg0, 2)) {
                    func_80102424(arg0, 2);
                }
                return 1;
            }
            return 0;
        case 0x44:
            func_80800244_chdinofamilysick(arg0, arg2);
            return 1;
        case 0x1F:
            func_801015D0(arg0);
            if (func_801022E4(arg0) == 0x3F7) {
                func_800DF744(3, 1);
                return 1;
            }
            func_800DF744(1, 0);
            func_800DF744(2, 1);
            func_800DF744(3, 2);
            return 1;
        case 0x37:
            func_80101EE4(arg0, 0.0f);
            return 1;
        case 0x95:
            if (_glcutDll_entrypoint_20()) {
                func_800FFAB0(arg0);
                return 1;
            }
            if (arg0->unk7A_5) {
                if (func_800DA298(0x189) || func_800DA298(0x15E)) {
                    func_800FFAB0(arg0);
                    return 1;
                }
                if (!_subaddietaxi_entrypoint_13(arg0, 2, &_chdinofamilysick_entrypoint_0, 7)) {
                    func_800FFAB0(arg0);
                    return 1;
                }
            } else if (func_800CB3E0(2) == 6 || func_800DA298(0x189) || func_800DA298(0x15E)) {
                func_800FFAB0(arg0);
            }
            return 1;
        case 0x52:
            _gcdialogcamera_entrypoint_4(arg0->position);
            _gcdialogcamera_entrypoint_3(&D_80800E98_chdinofamilysick, arg0->scale);
            return 3;
    }
    return 0;
}

OSThread *chdinofamilysick_entrypoint_1(void)
{
    extern u8 D_80800EA8_chdinofamilysick[];

    return (OSThread *) D_80800EA8_chdinofamilysick;
}

void func_808005F8_chdinofamilysick(Actor *arg0) {
    s32 _glcutDll_entrypoint_19(u32);
    s32 _glcutDll_entrypoint_20();
    s32 func_800DA298(s32);
    s32 func_800EA05C();
    void func_800FFA88(Unk80132ED0 *);
    void func_800FFAB0(Actor *);
    void *func_80105494(Actor *);

    switch (func_800EA05C()) {
    case 0x114:
        if (_glcutDll_entrypoint_19(0x38) == 0) {
            func_800FFA88(arg0->unk0);
        }
        break;
    case 0x118:
        if (_glcutDll_entrypoint_20() != 0) {
            if (func_80105494(arg0) != 0) {
                func_800FFAB0(arg0);
            } else {
                func_80102424(arg0, 7);
            }
        } else if (_glcutDll_entrypoint_19(0x38) == 0) {
            if (func_80105494(arg0) == 0) {
                if (func_800DA298(0x189) == 0 && func_800DA298(0x15E) != 0) {
                    func_80102424(arg0, 6);
                } else {
                    func_800FFAB0(arg0);
                }
            } else {
                func_800FFAB0(arg0);
            }
        }
        break;
    case 0x121:
        if (func_800DA298(0x189) != 0) {
            if (func_800DA298(0x15E) != 0) {
                func_80102424(arg0, 3);
            } else {
                func_80102424(arg0, 1);
            }
        } else {
            func_800FFA88(arg0->unk0);
        }
        break;
    default:
        func_800FFA88(arg0->unk0);
        break;
    }
}

void func_80800768_chdinofamilysick(Actor *arg0) {
    s32 _chdinofamilyfx_entrypoint_0(u8 *);
    void _glcutDll_entrypoint_24(u32, u32, u32);
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
    s32 _subaddiedialog_entrypoint_4(f32 *, s32, s32);
    void _sudeflect_entrypoint_1(f32 *, f32, f32, f32, s32);
    void func_800C8E84(s32, u32 *);
    void func_800DA524(s32);
    int func_800F3214(void *, void *, void *, f32);
    void func_800FFA88(Unk80132ED0 *);
    s32 func_80101180(s32, s32, s32);
    f32 func_80101F24(Actor *);
    s32 func_80105998(Actor *, f32);
    s32 func_80105A5C(Actor *);
    void func_80800A1C_chdinofamilysick(Actor *);
    struct StateFlags {
        u8 pad0[0x74];
        u32 pad74_4 : 28;
        u32 unk74_0 : 4;
    };
    u32 rgb[3];

    switch (arg0->unk70_10) {
    case 1:
        if (_subaddiedialog_entrypoint_4(arg0->position, 0x258, 0)) {
            _subaddiedialog_entrypoint_11(arg0->unk0, 0x17C8, 0xF, arg0->position, 0x39);
        }
        break;
    case 2: {
        typedef struct { u32 rgb[3]; } Color;
        extern Color D_80800F30_chdinofamilysick;
        extern Color D_80800F3C_chdinofamilysick;
        Color start = D_80800F30_chdinofamilysick;
        Color end = D_80800F3C_chdinofamilysick;
        func_800F3214(rgb, &start, &end, func_80101F24(arg0));
        func_800C8E84(*(s32 *)&arg0->unk54, rgb);
        break;
    }
    case 3:
        if (_subaddiedialog_entrypoint_4(arg0->position, 0x258, 0)) {
            _subaddiedialog_entrypoint_11(arg0->unk0, 0x17C9, 0xF, arg0->position, 0x39);
        }
        _sudeflect_entrypoint_1(arg0->position, arg0->scale * 235.0f, 0.0f, arg0->scale * 179.0f, 0x1E);
        break;
    case 4:
        if (func_80105A5C(arg0)) {
            _glcutDll_entrypoint_24(0x118, -1, 0x38);
            func_800FFA88(arg0->unk0);
        } else {
            if (func_80105998(arg0, 0.15f)) {
                _subaddiedialog_entrypoint_11(arg0->unk0, 0x180D, 0xF, arg0->position, 0x39);
            }
            func_80800A1C_chdinofamilysick(arg0);
        }
        break;
    case 5:
        if (func_80105A5C(arg0)) {
            func_800DA524(0x189);
            func_80101180(0x290, 0x33, 0);
            func_80102424(arg0, 6);
            ((struct StateFlags *)arg0)->unk74_0 = 0;
        } else {
            func_80800A1C_chdinofamilysick(arg0);
        }
        break;
    case 6:
        if (_subaddiedialog_entrypoint_4(arg0->position, 0x258, 0)) {
            _subaddiedialog_entrypoint_11(arg0->unk0, 0x17CA, 0xF, arg0->position, 0x39);
        }
        break;
    }
    _sudeflect_entrypoint_1(arg0->position, arg0->scale * 235.0f, 0.0f, arg0->scale * 179.0f, 0x1E);
    _chdinofamilyfx_entrypoint_0((u8 *)arg0);
}

void func_80800A1C_chdinofamilysick(Actor *arg0) {
    f32 func_800F3780(f32, u8 *, s16);
    f32 func_80101F24(Actor *);
    void func_80105834(Actor *);
    void func_80105A9C(Actor *, f32);
    extern u8 D_80800F48_chdinofamilysick;
    f32 temp_f2;
    f32 var_f0;
    f32 temp_f6;

    temp_f2 = func_800F3780(func_80101F24(arg0), &D_80800F48_chdinofamilysick, 4);
    if (arg0->unk70_10 == 4) {
        var_f0 = 0.75f;
    } else {
        var_f0 = 1.0f;
    }
    temp_f6 = temp_f2 * 1200.0f;
    func_80105A9C(arg0, var_f0 * temp_f6);
    func_80105834(arg0);
}

s32 func_80800AB0_chdinofamilysick(Actor *arg0, s32 arg1, s32 arg2) {
    void _capod_entrypoint_13(Unk80132ED0 *, Unk80132ED0 *, u32, u32);
    s32 _gcdialogcamera_entrypoint_3(s32 *, f32);
    void _gcdialogcamera_entrypoint_4(f32 *);
    s32 _glcutDll_entrypoint_19(u32);
    s32 func_800C8A98(void);
    void func_800C8CB8(s32, f32 *);
    void func_800C8E54(s32, f32, f32);
    void func_800C8F64(s32, s32);
    void func_800C8FB0(s32, u32, u32, u32);
    s32 func_800DA298(s32);
    void func_800DF744(s32, s32);
    s32 func_800EA05C(void);
    void func_800EEC30(f32 *, f32, f32, f32);
    void func_800EF04C(f32 *, f32 *);
    void func_800FFAB0(Actor *);
    s32 func_801015D0(Actor *);
    s32 func_801022E4(Actor *);
    f32 func_80103EAC(Actor *);
    void *func_80105494(Actor *);
    extern s32 D_80800F68_chdinofamilysick[];
    struct DinoFamilySickFlags {
        u8 pad0[0x74];
        u32 pad74_4 : 28;
        u32 unk74_0 : 4;
    };
    f32 sp2C[3];

    switch (arg1) {
    case 0x49:
        switch (func_800EA05C()) {
        case 0x114:
            if (_glcutDll_entrypoint_19(0x38)) {
                func_80102424(arg0, 4);
                _capod_entrypoint_13(arg0->unk0, NULL, 5, 0x2831);
                ((struct DinoFamilySickFlags *)arg0)->unk74_0 = 0;
                return 1;
            }
            break;
        case 0x118:
            if (_glcutDll_entrypoint_19(0x38)) {
                if (func_80105494(arg0)) {
                    func_80102424(arg0, 5);
                    arg2 = (func_800DA298(0x8A) && func_800DA298(0x15F)) ? 0 : 0x100;
                    _capod_entrypoint_13(arg0->unk0, NULL, 0xC, arg2 | 0x2831);
                    ((struct DinoFamilySickFlags *)arg0)->unk74_0 = 0;
                    return 1;
                }
                func_800FFAB0(arg0);
                return 0;
            }
            break;
        case 0x121:
            if (_glcutDll_entrypoint_19(0x71)) {
                *(s32 *)&arg0->unk54 = func_800C8A98();
                func_800C8E54(*(s32 *)&arg0->unk54, func_80103EAC(arg0) * 1.5f, 2.0f * func_80103EAC(arg0));
                func_800C8FB0(*(s32 *)&arg0->unk54, 0, 0xFF, 0);
                func_800C8F64(*(s32 *)&arg0->unk54, 3);
                func_800EEC30(sp2C, 45.0f, arg0->rotation[1], 2.0f * func_80103EAC(arg0));
                func_800EF04C(sp2C, arg0->position);
                func_800C8CB8(*(s32 *)&arg0->unk54, sp2C);
                func_80102424(arg0, 2);
                return 1;
            }
            break;
        default:
            break;
        }
        return 0;
    case 0x1F:
        func_801015D0(arg0);
        if (func_801022E4(arg0) == 0x3F7) {
            func_800DF744(3, 1);
        } else {
            func_800DF744(1, 0);
            func_800DF744(2, 1);
            func_800DF744(3, 2);
        }
        return 1;
    case 0x33:
        func_80102424(arg0, 3);
        return 1;
    case 0x52:
        _gcdialogcamera_entrypoint_4(arg0->position);
        _gcdialogcamera_entrypoint_3(D_80800F68_chdinofamilysick, arg0->scale);
        return 3;
    default:
        return 0;
    }
}

OSThread *chdinofamilysick_entrypoint_2(void)
{
    extern u8 D_80800F78_chdinofamilysick[];

    return (OSThread *) D_80800F78_chdinofamilysick;
}
