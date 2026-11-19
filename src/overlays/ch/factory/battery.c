#include "common.h"

OSThread *chfactorybattery_entrypoint_0(void)
{
    extern BtFnWord D_80801B34_chfactorybattery[2];

    return (OSThread *) D_80801B34_chfactorybattery;
}

/* extern */

s32 func_8080000C_chfactorybattery(Actor *arg0) {
    void func_800EE7F8(f32 dst[3], f32 src[3]);
    s32 _gccubesearch_entrypoint_12(s32 *, s32, u8 *);
    f32 sp24[3];
    s32 sp20;
    sp20 = _gccubesearch_entrypoint_12((s32 *)sp24, 0x28C, (u8 *)arg0->position);
    func_800EE7F8(arg0->position, sp24);
    return sp20;
}

void func_80800050_chfactorybattery(Actor *arg0, s32 arg1) {
    s32 func_800CB3E0(s32);
    void func_80102FDC(Actor *, f32);
    void func_8080130C_chfactorybattery(Actor *, s32);
    f32 func_80800580_chfactorybattery(f32 *);
    void _subaddietaxi_entrypoint_0(Actor *, s32, f32 *, s32);
    void _subaddietaxi_entrypoint_10(Actor *, s32, s32);
    f32 sp24[3];

    switch (func_800CB3E0(arg1)) {
        case 6:
            break;
        case 1:
            arg0->unk6C_0 = arg1;
            func_80102FDC(arg0, 0.45f);
            func_8080130C_chfactorybattery(arg0, 6);
            arg0->unk64_24 = 1;
            break;
        case 3:
            arg0->unk6C_0 = arg1;
            func_80102FDC(arg0, 0.45f);
            _subaddietaxi_entrypoint_10(arg0, arg1, 4);
            break;
        case 4:
            arg0->rotation[1] = func_80800580_chfactorybattery(sp24);
            arg0->unk6C_0 = arg1;
            func_80102FDC(arg0, 0.45f);
            _subaddietaxi_entrypoint_0(arg0, arg1, sp24, 3);
            break;
    }
    if (arg0 != NULL && arg0->pad6C_21 == 0) {
        arg0->unk6C_0 = arg1;
    }
}                typedef struct { s32 unk0; s32 unk4; s32 unk8; } Objbattery_arg1; /* offsets.py genstruct: fields from raw offsets on arg1; rename once understood */

void func_8080019C_chfactorybattery(volatile unsigned int arg0, void *arg1, s32 arg2, s32 arg3)
{
  s32 _chbaddiesetup_entrypoint_6(s32 *, BtIntPtr, BtIntPtr, s32, s32, s32, BtIntPtr);
  extern s32 _subaddietaxi_entrypoint_16;
  _chbaddiesetup_entrypoint_6(&_subaddietaxi_entrypoint_16, arg0, ((Objbattery_arg1 *)arg1)->unk0, ((Objbattery_arg1 *)arg1)->unk4, ((Objbattery_arg1 *)arg1)->unk8, arg2, arg3);
}

s32 func_808001F8_chfactorybattery(Actor *arg0) {
    void func_80102FDC(Actor *, f32);
    void func_8010A3E8(void *, f32);
    void func_800FFAB0(Actor *);
    s32 func_80800678_chfactorybattery(Actor *);
    s32 func_80800558_chfactorybattery(Actor *);
    s32 func_80800444_chfactorybattery(void);
    void func_808006E4_chfactorybattery(Actor *);
    void func_8080130C_chfactorybattery(Actor *, s32);
    s32 _subaddietaxi_entrypoint_13(Actor *arg0, s32 arg1, BtIntPtr arg2, s32 arg3);
    void _subaddieDll_entrypoint_1(Actor *arg0);
    void _subaddierouteDll_entrypoint_1(Actor *);
#ifndef BT_NATIVE
    extern s32 _chfactorybattery_entrypoint_0;
#endif

    struct BatteryCollisionFlags {
        u8 prefix[0x64];
        BT_BITFIELD_ORDER(u32 upper : 3, u32 lower : 27);
        u32 flags : 2;
        BT_BITFIELD_ORDER(u32 lower : 27, u32 upper : 3);
    };
    struct BatteryRouteFlags {
        u8 prefix[0x70];
        BT_BITFIELD_ORDER(u32 upper : 22, u32 lower : 4);
        u32 route : 6;
        BT_BITFIELD_ORDER(u32 lower : 4, u32 upper : 22);
    };

    func_80102FDC(arg0, 0.45f);
    func_8010A3E8(arg0, 0.6f);
    if (arg0->unk7A_5) {
        if (func_80800678_chfactorybattery(arg0)) {
            if (!func_80800558_chfactorybattery(arg0)) {
                if (_subaddietaxi_entrypoint_13(arg0, func_80800678_chfactorybattery(arg0), &_chfactorybattery_entrypoint_0, 3)) {
                    arg0->unk64_24 = 1;
                } else {
                    func_800FFAB0(arg0);
                    return 0;
                }
            } else {
                func_800FFAB0(arg0);
                return 0;
            }
        } else {
            arg0->unk64_24 = 0;
            ((struct BatteryCollisionFlags *)arg0)->flags = 0;
            if (func_80800444_chfactorybattery()) {
                func_8080130C_chfactorybattery(arg0, 13);
            } else {
                func_800FFAB0(arg0);
                return 0;
            }
        }
    } else {
        if (func_80800678_chfactorybattery(arg0)) {
            if (func_80800558_chfactorybattery(arg0)) {
                func_800FFAB0(arg0);
                return 0;
            }
        } else {
            func_800FFAB0(arg0);
            return 0;
        }
    }
    func_808006E4_chfactorybattery(arg0);
    func_8080130C_chfactorybattery(arg0, arg0->unk70_10);
    if (arg0->unk70_10 != 3 && arg0->unk70_10 != 4 && arg0->unk70_10 != 5 && arg0->unk70_10 != 13) {
        if (!arg0->unk70_25 || !((struct BatteryRouteFlags *)arg0)->route) {
            func_8080000C_chfactorybattery(arg0);
            _subaddieDll_entrypoint_1(arg0);
        }
        _subaddierouteDll_entrypoint_1(arg0);
    }
    return 1;
}

s32 func_808003C0_chfactorybattery(s32 arg0, f32 *arg1, f32 *arg2) {
    f32 func_800EEAD4(f32 *, f32 *);
    s32 func_80800444_chfactorybattery(void);
    int func_808004E8_chfactorybattery(void);
    f32 func_80800580_chfactorybattery(f32 *);

    if ((func_80800444_chfactorybattery() == 0) && (func_808004E8_chfactorybattery() != 0)) {
        func_80800580_chfactorybattery(arg2);
        if (func_800EEAD4(arg2, arg1) < 1000.0f) {
            return 2;
        }
        return 1;
    }
    return 1;
}

/* extern */

s32 func_80800444_chfactorybattery(void) {
    s32 func_800DA298(s32);
    s32 func_80800480_chfactorybattery();
    s32 temp_v0;

    temp_v0 = func_80800480_chfactorybattery();
    if (temp_v0 != 0) {
        return func_800DA298(temp_v0);
    }
    return 0;
}

s32 func_80800480_chfactorybattery(void) {
    s32 func_800EA05C();
    s32 temp_v0;

    temp_v0 = func_800EA05C();
    switch (temp_v0) {
    case 0x101:
        return 0x1B0;
    case 0x106:
        return 0x1B1;
    case 0x109:
        return 0x1B2;
    case 0x10B:
        return 0x1B3;
    default:
        return 0;
    }
}

/* extern */

int func_808004E8_chfactorybattery(void) {
    s32 func_800EA05C();
    return func_800EA05C() == 0x101 ||
           func_800EA05C() == 0x106 ||
           func_800EA05C() == 0x109 ||
           func_800EA05C() == 0x10B;
}

s32 func_80800558_chfactorybattery(Actor *arg0) {
    s32 func_800DA298(s32);
    s32 func_80800678_chfactorybattery(Actor *);
    return func_800DA298(func_80800678_chfactorybattery(arg0) + 0x1B1);
}

f32 func_80800580_chfactorybattery(f32 *arg0) {
    s32 func_800EA05C();
    void func_800EFA4C(f32 *, f32, f32, f32);
    switch (func_800EA05C()) {
    case 0x101:
        func_800EFA4C(arg0, 2521.0f, 750.0f, -2529.0f);
        return 310.0f;
    case 0x106:
        func_800EFA4C(arg0, 6303.0f, 1550.0f, -986.0f);
        return 180.0f;
    case 0x109:
        func_800EFA4C(arg0, -293.0f, 50.0f, 2634.0f);
        return 180.0f;
    case 0x10B:
        func_800EFA4C(arg0, 3678.0f, 350.0f, -1994.0f);
        return 90.0f;
    default:
        return 0.0f;
    }
}

s32 func_80800678_chfactorybattery(Actor *arg0) { switch (arg0->pad6C_21) { case 0x51: return 3; case 0x5C: return 4; case 0x63: return 5; case 0x65: return 6; case 0: return arg0->unk6C_0; default: return 0; } }

void func_808006E4_chfactorybattery(Actor *arg0) {
    s32 func_800C8A98(void);
    void func_800C8D4C(s32, f32 *);
    void func_800C8F64(s32, s32);
    void func_800C8FE0(s32, s32);
    f32 func_80103EAC(Actor *);
    f32 size[2];

    size[0] = 2.0f * func_80103EAC(arg0);
    size[1] = func_80103EAC(arg0) * 4.0f;
    if ((*(s32 *)&arg0->unk50 = func_800C8A98()) != 0) {
        func_800C8F64(*(s32 *)&arg0->unk50, 3);
        func_800C8D4C(*(s32 *)&arg0->unk50, size);
        func_800C8FE0(*(s32 *)&arg0->unk50, 0);
    }
}
typedef struct { u32 v[3]; } Color;
void func_80800760_chfactorybattery(Actor *arg0) {
    s32 _subaddieskeleton_entrypoint_2(Unk80132ED0 *, s32, f32 *);
    void func_800C8CB8(s32, f32[3]);
    void func_800C8E84(s32, u32[3]);
    void func_800C8FE0(s32, s32);
    f32 func_800DC178(f32, f32);
    int func_800F3214(void *, void *, void *, f32);

    extern Color D_80801B3C_chfactorybattery;
    extern Color D_80801B48_chfactorybattery;
    extern Color D_80801B54_chfactorybattery;
    f32 sp5C[3];
    Color sp50;
    u32 sp44[3];
    Color sp38;
    Color sp2C;
    s32 temp_a0;

    if (_subaddieskeleton_entrypoint_2(arg0->unk0, 4, sp5C) &&
        (temp_a0 = *(s32 *)&arg0->unk50) != 0) {
        if (arg0->unk70_10 == 1 || arg0->unk70_10 == 9) {
            sp50 = D_80801B3C_chfactorybattery;
            func_800C8CB8(*(s32 *)&arg0->unk50, sp5C);
            func_800C8E84(*(s32 *)&arg0->unk50, sp50.v);
            func_800C8FE0(*(s32 *)&arg0->unk50, 1);
            return;
        }
        if (arg0->unk79_4) {
            sp38 = D_80801B48_chfactorybattery;
            sp2C = D_80801B54_chfactorybattery;
            func_800F3214(sp44, &sp38, &sp2C, func_800DC178(0.7f, 1.0f));
            func_800C8CB8(*(s32 *)&arg0->unk50, sp5C);
            func_800C8E84(*(s32 *)&arg0->unk50, sp44);
            func_800C8FE0(*(s32 *)&arg0->unk50, 1);
            return;
        }
        func_800C8FE0(temp_a0, 0);
    }
}

/* extern */

void func_808008C8_chfactorybattery(Actor *arg0) {
    s32 func_800DC128(s32, s32);

    switch (arg0->unk70_10) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 6:
    case 9:
        arg0->unk79_4 = 0;
        return;
    case 5:
    case 7:
    case 10:
    case 13:
        arg0->unk79_4 = func_800DC128(1, 4);
        /* fallthrough */
    default:
        return;
    }
}

void func_80800948_chfactorybattery(Actor *arg0) {
    s32 _subaddieaudioloop_entrypoint_4(Actor *, f32 *, u32, u32 *);
    s32 _subaddieaudioquick_entrypoint_3(Actor *arg0, f32 arg1[3], void *arg2, f32 arg3);
    extern s16 D_80801B60_chfactorybattery[12];
    extern s16 D_80801B78_chfactorybattery[8];

    switch (arg0->unk70_10) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 7:
    case 9:
        break;
    case 6:
    case 8:
    case 10:
        _subaddieaudioquick_entrypoint_3(arg0, arg0->position, D_80801B60_chfactorybattery, 0.5f);
        break;
    }
    if (arg0->unk79_4 != 0) {
        _subaddieaudioloop_entrypoint_4(arg0, arg0->position, 1, (u32 *)D_80801B78_chfactorybattery);
    }
}

void func_808009C8_chfactorybattery(Actor *arg0) {
    s32 func_800F4EC8(BtUIntPtr, BtIntPtr, f32, f32, f32);
    BtIntPtr func_800F54E4();
    f32 func_80103EAC(Actor *);
    f32 func_80103EF4(Actor *);
    s32 pad[1];
    f32 sp30;
    BtUIntPtr sp2C;

    switch (arg0->unk70_10) {
    case 1:
    case 4:
    case 5:
    case 9:
    case 13:
        sp2C = func_800F54E4();
        sp30 = func_80103EF4(arg0);
        func_800F4EC8(sp2C, (BtIntPtr)arg0->position, sp30, 0.0f, func_80103EAC(arg0) * 0.25f);
        return;
    case 8:
    case 10:
        if (arg0->unk79_4 == 0) {
            sp2C = func_800F54E4();
            sp30 = func_80103EF4(arg0);
            func_800F4EC8(sp2C, (BtIntPtr)arg0->position, sp30, 0.0f, func_80103EAC(arg0) * 0.25f);
        }
        break;
    }
}

void func_80800AB8_chfactorybattery(Actor *arg0) {
    void _subaddiefx_entrypoint_0(Actor *, s32, void *);
    f32 _subaddiejoy_entrypoint_3();
    s32 _subaddiejoy_entrypoint_6(Actor *, s32);
    s32 _subaddierouteDll_entrypoint_4(Actor *);
    void _subaddierouteDll_entrypoint_5(Actor *, void *, u32, f32, f32, f32);
    s32 _subaddierouteDll_entrypoint_6(Actor *arg0, void *arg1, s32 arg2, s32 arg3, f32 arg4, s32 arg5, s32 arg6);
    s32 _subaddierouteDll_entrypoint_7(Actor *, void *, f32, f32, f32, s32);
    s32 _subaddietaxi_entrypoint_1(Actor *, s32);
    s32 _subaddietaxi_entrypoint_11(Actor *, s32);
    s32 _subaddietaxi_entrypoint_5(Actor *, s32);
    void _subaddietaxi_entrypoint_9(Actor *, s32);
    f32 func_80013970(f32);
    void *func_800CC63C(s32, s32);
    s32 func_800D90A4(f32 *);
    s32 func_800DC128(s32, s32);
    f32 func_800F1DF4(f32 *, f32 *);
    f32 func_800F3780(f32, u8 *, s16);
    BtIntPtr func_800F54E4();
    void *func_80100094(Actor *, u32);
    s32 func_8010108C(Actor *, s32, BtIntPtr);
    f32 func_80101F24(Actor *);
    void func_80102BAC(Actor *, f32, f32, f32);
    s32 func_80102CCC(Actor *);
    f32 func_80103EAC(Actor *);
    f32 func_80103EF4(Actor *);
    s32 func_8010BA80(Actor *volatile arg0, volatile s32 arg1, s32 arg2);
    s32 func_8010C3A8(Actor *arg0, u32 arg1, f32 arg2);
    s32 func_8010C500(Actor *);
    s32 func_8010C9FC(f32 *, s32, s32, s32);
    f32 func_8010CD50(Actor *, BtIntPtr);
    void func_8080130C_chfactorybattery(Actor *, s32);
    extern f32 D_80801B88_chfactorybattery[4][2];
    struct Route { u16 pad[3]; u16 node; };
    struct BatteryActorFlags {
        u8 pad[0x70];
        BT_BITFIELD_ORDER(u32 unk70_25 : 7, u32 pad70_0 : 4);
        BT_BITFIELD_ORDER(u32 pad70_10 : 15, u32 unk70_4 : 6);
        BT_BITFIELD_ORDER(u32 unk70_4 : 6, u32 pad70_10 : 15);
        BT_BITFIELD_ORDER(u32 pad70_0 : 4, u32 unk70_25 : 7);
    };

    f32 sp4C;
    struct Route *sp48;
    s32 pad44;
    f32 sp40;
    f32 sp3C;
    s32 pad38;
    f32 sp34;
    f32 sp30;

    switch (arg0->unk70_10) {
    case 1:
        _subaddiefx_entrypoint_0(arg0, 4, func_80100094(arg0, 0));
        if (func_800D90A4(&arg0->unk58)) {
            func_8080130C_chfactorybattery(arg0, 6);
        }
        break;
    case 3:
        if (_subaddietaxi_entrypoint_1(arg0, func_80800678_chfactorybattery(arg0))) {
            func_8080130C_chfactorybattery(arg0, 5);
        }
        break;
    case 4:
        if (_subaddietaxi_entrypoint_11(arg0, func_80800678_chfactorybattery(arg0)) &&
            _subaddietaxi_entrypoint_5(arg0, func_80800678_chfactorybattery(arg0))) {
            func_8080130C_chfactorybattery(arg0, 6);
        }
        break;
    case 6:
        sp4C = func_800F3780(func_80101F24(arg0), (u8 *)D_80801B88_chfactorybattery, 4);
        sp48 = func_80100094(arg0, 1);
        if (_subaddierouteDll_entrypoint_4(arg0)) {
            if (func_8010C500(arg0)) {
                sp40 = func_800F1DF4(func_800CC63C(((struct BatteryActorFlags *)arg0)->unk70_25 - 1, ((struct BatteryActorFlags *)arg0)->unk70_4 - 1), arg0->position);
                arg0->unk54 = func_8010CD50(arg0, func_800F54E4()) - 180.0f;
                if (sp40 + 90.0f < arg0->unk54) {
                    arg0->unk54 = sp40 + 90.0f;
                } else if (arg0->unk54 < sp40 - 90.0f) {
                    arg0->unk54 = sp40 - 90.0f;
                }
            } else {
                _subaddierouteDll_entrypoint_6(arg0, sp48, arg0->unk74_7, 0x3F, 0.4f, 20, 40);
            }
            _subaddierouteDll_entrypoint_7(arg0, sp48, arg0->rotation[1], arg0->unk54, 200.0f, 0x4803);
            arg0->unk74_7 = sp48->node;
        }
        _subaddierouteDll_entrypoint_5(arg0, sp48, arg0->unk74_7, 0.3f, 1.0f, 300.0f * sp4C);
        func_8010C3A8(arg0, 0x305425, sp4C);
        break;
    case 7:
        if (func_800D90A4(&arg0->unk58)) {
            func_8080130C_chfactorybattery(arg0, 6);
        }
        break;
    case 10:
        if (func_800D90A4(&arg0->unk58)) {
            func_8080130C_chfactorybattery(arg0, 8);
        }
        /* fallthrough */
    case 8:
        if (arg0->unk64_20) {
            if (_subaddiejoy_entrypoint_6(arg0, 1)) {
                if (func_800D90A4(&arg0->unk58)) {
                    arg0->unk64_20 = 0;
                    arg0->unk79_4 = 0;
                    arg0->unk58 = 1.0f;
                } else {
                    arg0->unk79_4 = func_800DC128(1, 4);
                }
            } else {
                arg0->unk79_4 = 0;
            }
        } else if (func_800D90A4(&arg0->unk58) && _subaddiejoy_entrypoint_6(arg0, 1)) {
            arg0->unk64_20 = 1;
            arg0->unk58 = 2.0f;
            arg0->unk79_4 = func_800DC128(1, 4);
        }
        sp3C = _subaddiejoy_entrypoint_3(arg0);
        sp3C = 600.0f * sp3C;
        if (func_80101F24(arg0) > 0.5f) {
            if (func_80102CCC(arg0) == 0) {
                func_80102BAC(arg0, 1.5f, 1.0f, 20.0f);
            } else {
                ((f32 *)arg0->actorData)[3] = func_80013970((func_80101F24(arg0) > 0.5f ? (func_80101F24(arg0) - 0.5f) * 2.0f : 0.0f) * 180.0f) * sp3C;
                func_8010BA80(arg0, 0x201005, 0x20);
            }
        }
        break;
    case 9:
        _subaddiefx_entrypoint_0(arg0, 4, func_80100094(arg0, 0));
        if (func_800D90A4(&arg0->unk58)) {
            func_8080130C_chfactorybattery(arg0, 8);
        }
        break;
    case 5:
    case 13:
        sp30 = func_80103EAC(arg0);
        sp34 = func_80103EF4(arg0);
        if (func_8010C9FC(arg0->position, (s32)sp30, (s32)sp34, 0)) {
            func_8010108C(arg0, 0x3E, 0);
        }
        break;
    }
    func_808009C8_chfactorybattery(arg0);
    func_80800948_chfactorybattery(arg0);
    func_808008C8_chfactorybattery(arg0);
    func_80800760_chfactorybattery(arg0);
    _subaddietaxi_entrypoint_9(arg0, func_80800678_chfactorybattery(arg0));
}

s32 func_80801040_chfactorybattery(Actor *arg0, s32 arg1, s32 arg2) {
    void _subaddieDll_entrypoint_1(Actor *arg0);
    void _subaddierouteDll_entrypoint_1(Actor *);
    s32 _subaddietaxi_entrypoint_2(Actor *, s32);
    void func_800DF744(s32, s32);
    BtIntPtr func_800F54E4();
    int func_800F7A2C(BtIntPtr arg0, s32 arg1, f32 *arg2);
    s32 func_801015D0(Actor *);
    s32 func_80107070(Actor *, s32);
    f32 func_8010A40C(void *);
    s32 func_8080000C_chfactorybattery(Actor *);
    void func_80800050_chfactorybattery(Actor *, s32);
    s32 func_808001F8_chfactorybattery(Actor *);
    s32 func_80800678_chfactorybattery();
    void func_8080130C_chfactorybattery(Actor *, s32);

    switch (arg1) {
        case 0x3E:
            switch (arg0->unk70_10) {
                case 1:
                case 4:
                case 9:
                    if (_subaddietaxi_entrypoint_2(arg0, func_80800678_chfactorybattery(arg0))) {
                        func_8080130C_chfactorybattery(arg0, 2);
                    }
                    return 1;
                case 6:
                case 7:
                    func_8080130C_chfactorybattery(arg0, 7);
                    return 1;
                case 8:
                case 10:
                    if (arg0->unk79_4) {
                        func_8080130C_chfactorybattery(arg0, 10);
                    }
                    return 1;
                case 5:
                case 13:
                    func_800F7A2C(func_800F54E4(), 5, arg0->position);
                    return 1;
                default:
                    return 1;
            }
        case 0x40:
            switch (arg0->unk70_10) {
                case 1:
                case 6:
                    func_8080130C_chfactorybattery(arg0, 1);
                    return 1;
                case 8:
                case 9:
                case 10:
                    func_8080130C_chfactorybattery(arg0, 9);
                    return 1;
                default:
                    return 1;
            }
        case 1:
            switch ((s32)arg0->unk70_10) {
                case 1:
                case 6:
                case 7:
                    func_8080130C_chfactorybattery(arg0, 8);
                    return 1;
            }
            return 1;
        case 2:
            func_80107070(arg0, 1);
            return 1;
        case 0x1F:
            func_801015D0(arg0);
            func_800DF744(3, arg0->unk79_4);
            return 1;
        case 0x44:
            func_80800050_chfactorybattery(arg0, arg2);
            return 1;
        case 0x29:
            ((s16 *)arg0->unk0)[0x10] = (s32)(func_8010A40C(arg0) * 120.0f);
            return 1;
        case 0x95:
            func_808001F8_chfactorybattery(arg0);
            return 1;
        case 0x4D:
            func_8080000C_chfactorybattery(arg0);
            if (arg0->unk70_10 != 3 && arg0->unk70_10 != 4 && arg0->unk70_10 != 5 && arg0->unk70_10 != 13) {
                _subaddieDll_entrypoint_1(arg0);
                _subaddierouteDll_entrypoint_1(arg0);
            }
            return 1;
        default:
            return 0;
    }
}

void func_8080130C_chfactorybattery(Actor *arg0, s32 arg1) {
    void _subaddiefx_entrypoint_1(BtIntPtr arg0, void *arg1);
    void _subaddierouteDll_entrypoint_3(BtIntPtr arg0, void *arg1, f32 *arg2);
    void func_800DA544(s32 index);
    BtIntPtr func_800F54E4();
    int func_800F7A2C(BtIntPtr arg0, s32 arg1, f32 *arg2);
    u32 *func_80100074(Actor *, u32, u32);
    void *func_80100094(Actor *, u32);
    void func_80102424(Actor *, s32);
    void func_8010A570(Actor *);
    s32 temp_v0;

    switch (arg1) {
    case 1:
    case 9:
        arg0->unk79_4 = 0;
        arg0->unk58 = 6.0f;
        break;
    case 6:
        ((f32 *)arg0->actorData)[3] = 800.0f;
        if (func_80100094(arg0, 0) == NULL) {
            func_80100074(arg0, 0, 8);
        }
        if (func_80100094(arg0, 1) == NULL) {
            func_80100074(arg0, 1, 12);
            _subaddierouteDll_entrypoint_3(arg0, func_80100094(arg0, 1), arg0->position);
        }
        if (func_80100094(arg0, 0) != NULL) {
            _subaddiefx_entrypoint_1(arg0, func_80100094(arg0, 0));
        }
        break;
    case 7:
    case 10:
        func_800F7A2C(func_800F54E4(), 5, arg0->position);
        arg0->unk58 = 1.0f;
        break;
    case 8:
        arg0->unk64_20 = 0;
        arg0->unk79_4 = 0;
        arg0->unk58 = 0.0f;
        if (func_80100094(arg0, 0) != NULL) {
            _subaddiefx_entrypoint_1(arg0, func_80100094(arg0, 0));
        }
        break;
    case 5:
        temp_v0 = func_80800480_chfactorybattery();
        if (temp_v0 != 0) {
            func_800DA544(temp_v0);
            func_800DA544(func_80800678_chfactorybattery(arg0) + 0x1B1);
        }
    case 13:
        func_8010A570(arg0);
        break;
    }
    func_80102424(arg0, arg1);
}

/* extern */

void func_808014C0_chfactorybattery(Actor *arg0) {
    void* func_80100094(Actor*, u32);
    void _subaddiefx_entrypoint_1(BtIntPtr arg0, void *arg1);
    if (func_80100094(arg0, 0U) != NULL) {
        _subaddiefx_entrypoint_1(arg0, func_80100094(arg0, 0U));
    }
}

OSThread *chfactorybattery_entrypoint_1(void)
{
    extern ActorData D_80801BA8_chfactorybattery[];

    return (OSThread *) D_80801BA8_chfactorybattery;
}

void func_8080150C_chfactorybattery(Actor *arg0) {
    void _chdoormake_entrypoint_1(Actor *, f32, s32, s32);
    s32 _chdoormake_entrypoint_3(Actor *, f32, f32, f32, s32, s32);
    void _chdoormake_entrypoint_5(Actor *, f32);
    void _chdoormake_entrypoint_6(Actor *, s32);
    void _chdoormake_entrypoint_8(void *, u32);
    s32 _chdoormake_entrypoint_9(Actor *, s32, s32, s32);
    s32 func_800DA298(s32);
    s32 func_800EA05C(void);
    s32 func_80103140(Actor *, u32, u16);
    f32 func_80103EF4(Actor *);
    f32 sp28[2];
    s32 map;

    map = func_800EA05C();
    switch (map) {
    case 0x101:
        func_80103140(arg0, 0x87F, 0);
        _chdoormake_entrypoint_1(arg0, -90.0f, 0x4C, func_80800480_chfactorybattery());
        _chdoormake_entrypoint_9(arg0, 0, 6, 0x10);
        break;
    case 0x106:
        sp28[0] = func_80103EF4(arg0);
        _chdoormake_entrypoint_3(arg0, 0.0f, 90.0f, sp28[0] * 0.75f, 0x44, func_80800480_chfactorybattery());
        _chdoormake_entrypoint_9(arg0, 0, 3, 0x10);
        break;
    case 0x109:
        sp28[0] = func_80103EF4(arg0);
        _chdoormake_entrypoint_3(arg0, 0.0f, 90.0f, sp28[0] * 0.75f, 0x44, func_80800480_chfactorybattery());
        _chdoormake_entrypoint_9(arg0, 0, 1, 0x10);
        break;
    case 0x10B:
        sp28[0] = func_80103EF4(arg0);
        _chdoormake_entrypoint_3(arg0, 0.0f, 90.0f, sp28[0] * 0.75f, 0x44, func_80800480_chfactorybattery());
        _chdoormake_entrypoint_9(arg0, 0, 1, 0x10);
        break;
    }
    _chdoormake_entrypoint_8(arg0, 4);
    _chdoormake_entrypoint_5(arg0, 3.0f);
    _chdoormake_entrypoint_6(arg0, 0x3F800000);
    if (func_800DA298(func_80800480_chfactorybattery()) != 0) {
        arg0->unk74_30 = 1;
        arg0->unk74_29 = arg0->unk74_30;
    }
}

/* extern */

void func_80801728_chfactorybattery(Actor *arg0) {
    void _chdoor_entrypoint_0(BtIntPtr arg0);
    u32 _subaddiedialog_entrypoint_11(Unk80132ED0* arg0, u32 DialogId, u32 arg2, f32* CameraTarget, s16 arg4);
    s32 func_800DA298(s32);
    void func_800DA544(s32 index);
    s32 func_8010CA74(f32 *, s32);
    s32 func_80800480_chfactorybattery();
    if (func_800DA298(0x343) == 0) {
        if ((func_8010CA74(arg0->position, 0x2EE) != 0) && (func_800DA298(func_80800480_chfactorybattery()) == 0)) {
            func_800DA544(0x343);
            _subaddiedialog_entrypoint_11(arg0->unk0, 0x1352, 6, arg0->position, 0);
            arg0->unk74_30 = 1;
        }
    }
    if (!arg0->unk74_29 && (func_800DA298(func_80800480_chfactorybattery()) != 0)) {
        _subaddiedialog_entrypoint_11(arg0->unk0, 0x1353, 6, arg0->position, 0);
        arg0->unk74_29 = 1;
    }
    _chdoor_entrypoint_0(arg0);
}

/* extern */

void func_80801804_chfactorybattery(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _chdoor_entrypoint_1(Actor *, s32, BtIntPtr);
    s32 func_800EA05C(void);
    s32 func_80103140(Actor *, u32, u16);
    if (arg1 == 0x95) {
        if (func_800EA05C() == 0x101) {
            func_80103140(arg0, 0x87F, 0);
        }
        _chdoor_entrypoint_1(arg0, arg1, arg2);
        return;
    }
    _chdoor_entrypoint_1(arg0, arg1, arg2);
}

OSThread *chfactorybattery_entrypoint_2(void)
{
    extern ActorData D_80801BF0_chfactorybattery[];
    return (OSThread *) D_80801BF0_chfactorybattery;
}
#include "battery_data.inc"
