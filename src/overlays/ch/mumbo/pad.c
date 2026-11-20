#include "common.h"

void func_80101870(Actor *, void *);
void func_80105834(Actor *);
void *func_80107C2C(s32 *, s32, void *, s32, void *);
OSThread *func_80108ED0(void);
void func_80800140_chmumbopad(void *arg0);
void func_8080044C_chmumbopad(Actor *arg0);
s32 func_80800514_chmumbopad(Actor *arg0, s32 arg1, s32 arg2);

s16 D_80801060_chmumbopad[] = {
    0x02A5, 0x017E, 0x0163, 0x0154,
    0x0154, 0x0154, 0x0297, 0x0292,
    0x028E, 0x028D, 0x03F5, 0x03EE,
    0x040E, 0x0346, 0x045A, 0x0457,
    0x04D8, 0x0000,
};

u16 D_80801084_chmumbopad[][2] = {
    0x07D8, 0x09D5, 0x07D8, 0x09D5,
    0x07E0, 0x09DF, 0x07D9, 0x09E0,
    0x07D9, 0x09E0, 0x07D9, 0x09E0,
    0x07DB, 0x09E2, 0x07DC, 0x09E5,
    0x07DC, 0x09E5, 0x07DC, 0x09E5,
    0x07DE, 0x09E3, 0x07DE, 0x09E3,
    0x07DD, 0x09E4, 0x07DA, 0x09E9,
    0x07DA, 0x09E9, 0x07DA, 0x09E9,
    0x07DF, 0x09DE,
};

s16 D_808010C8_chmumbopad[] = {
    0xFFFF, 0xFFFF, 0x057C, 0xFFFF,
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
    0xFFFF, 0x057D, 0x057E, 0x057F,
    0x0580, 0xFFFF, 0xFFFF, 0xFFFF,
    0xFFFF, 0x0000,
};

s16 D_808010EC_chmumbopad[] = {
    0x0095, 0x04FC, 0xFFFF, 0x00EA,
    0x00EC, 0x00EB, 0x00E9, 0x015F,
    0x0160, 0xFFFF, 0x01B8, 0x0329,
    0xFFFF, 0xFFFF, 0xFFFF, 0x0373,
    0x015E, 0x0000,
};

BtFnWord D_80801110_chmumbopad[] = {
    0x021002B0, 0xFFFF0001,
    0x00000000, (BtFnWord)func_8080044C_chmumbopad,
    (BtFnWord)func_80105834, (BtFnWord)func_80101870,
    0x00000000, 0x00000000,
    0x00000000, 0x0000181C,
    0x00000000, (BtFnWord)func_80108ED0,
    0x00000000, (BtFnWord)func_80800140_chmumbopad,
    (BtFnWord)func_80107C2C, 0x80002C02,
    (BtFnWord)func_80800514_chmumbopad, 0x00000000,
    0x00000000, 0x00000000,
};

s32 chmumbopad_entrypoint_0(s32 arg0) {
    return *(s16 *)((u8 *)(&D_80801084_chmumbopad[0][1]) + (arg0 << 2));
}

/* extern */

void func_80800014_chmumbopad(BtIntPtr arg0, BtIntPtr arg1, s32 arg2) {
    BT_NATIVE_ONLY(void *_gccubesearch_entrypoint_1(s32, f32 *);) BT_IDO_ONLY(s32 _gccubesearch_entrypoint_1(s32);)
    BT_NATIVE_ONLY(void _gspropctrl_entrypoint_11(void *, void *);) BT_IDO_ONLY(s32 _gspropctrl_entrypoint_11(BtIntPtr, BtIntPtr);)
    _gspropctrl_entrypoint_11(BT_NATIVE_ONLY(_gccubesearch_entrypoint_1(arg2, (f32 *)arg1)) BT_IDO_ONLY(_gccubesearch_entrypoint_1(arg2)), BT_NATIVE_ONLY((void *))arg1);
}

s32 func_80800048_chmumbopad(void *arg0) { s32 func_800DA298(s32); extern s16 D_808010C8_chmumbopad[]; s16 temp_a1; temp_a1 = D_808010C8_chmumbopad[(*(s32 *)((s8 *)arg0 + 0x6C)) & 0x1FF]; if (temp_a1 != -1) { return func_800DA298(temp_a1); } else { return 0; } }

int func_80800098_chmumbopad(Actor *arg0) {
    s32 func_800DA298(s32);
    s32 func_800DA564(s32, s32);
    s16 flag;

    switch (arg0->unk6C_0) {
        case 12:
            return (func_800DA298(0x358) != 0) && (func_800DA298(0x359) != 0);
        case 13:
            return func_800DA564(0x1CA, 2) != 0;
        default:
            flag = D_808010EC_chmumbopad[arg0->unk6C_0];
            if (flag != -1) {
                return func_800DA298(flag);
            } else {
                return 0;
            }
    }
}

void func_80800140_chmumbopad(void *arg0) {
    typedef struct {
        Unk80132ED0 *marker;
        f32 position[3];
        u8 pad10[0x5C];
        BT_BITFIELD_ORDER(u32 id : 11, u32 spell : 9);
        u32 : 12;
        BT_BITFIELD_ORDER(u32 spell : 9, u32 id : 11);
    } MumboPad;
    void _subaddiefade_entrypoint_1(void *arg0, s32 arg1);
    s32 func_800DA298(s32);
    int func_800EA05C(void);
    s32 func_800F5410(BtIntPtr);
    u32 func_800F54E4(void);
    void func_800FFAB0(BtIntPtr);
    void func_80101FDC(Actor *, u32);
    s32 func_80103140(void **, s32, u16);
    f32 func_80103EAC(Actor *);
    s32 func_8010A654(void *, s32);
    s32 func_8010CB84(f32 *, u32);
    int func_80800098_chmumbopad(Actor *);
    MumboPad *pad = arg0;
    int map;

    map = func_800EA05C();
    switch (map) {
        default:
            break;
        case 0xD7:
            pad->spell = 0;
            break;
        case 0xC7:
            pad->spell = 1;
            break;
        case 0xB8:
            pad->spell = 2;
            break;
        case 0xE6:
            pad->spell = 3;
            break;
        case 0xD6:
            if (pad->id == 0xB4) {
                pad->spell = 5;
                break;
            }
            pad->spell = 4;
            break;
        case 0x1A7:
            pad->spell = 6;
            break;
        case 0x118:
            pad->spell = 7;
            break;
        case 0x112:
            if (pad->id == 0x5D) {
                pad->spell = 8;
                break;
            }
            pad->spell = 9;
            break;
        case 0x107:
            pad->spell = 0xA;
            break;
        case 0x10B:
            pad->spell = 0xB;
            break;
        case 0x136:
            pad->spell = 0xC;
            break;
        case 0x128:
            if (pad->id == 0x144) {
                pad->spell = 0xD;
                break;
            }
            if (func_800DA298(0x376)) {
                pad->spell = 0xF;
                break;
            }
            pad->spell = 0xE;
            break;
        case 0x155:
            pad->spell = 0x10;
            break;
    }
    func_80103140((void **)pad, D_80801084_chmumbopad[pad->spell][0], ((u16 *)pad->marker)[0xB]);
    func_8010A654(pad, func_800DA298(0x64D));
    if (func_80800098_chmumbopad((Actor *)pad)) {
        if (func_8010CB84(pad->position, (s32)func_80103EAC((Actor *)pad))) {
            func_80101FDC((Actor *)pad, 2);
            goto active;
        }
        func_800FFAB0((BtIntPtr)pad);
        return;
    }
active:
    func_80800014_chmumbopad((BtIntPtr)pad, (BtIntPtr)((u8 *)pad + 0x18), D_80801060_chmumbopad[pad->spell]);
    if (func_800F5410(func_800F54E4()) != 0xD) {
        _subaddiefade_entrypoint_1((BtIntPtr)pad, 0x87);
    }
}

void func_8080044C_chmumbopad(Actor *arg0) {
    void func_80103110(void *, s32);
    void func_80101FDC(Actor *, u32);
    void _subaddiefade_entrypoint_3(Actor *);

    switch (arg0->unk70_10) {
        case 1:
            if (!arg0->unk74_29) {
                func_80103110(arg0, 0);
                if (func_80800098_chmumbopad(arg0)) {
                    _subaddiefade_entrypoint_3(arg0);
                    func_80101FDC(arg0, 3);
                }
            }
            arg0->unk74_29 = 0;
            break;
        case 2:
            if (!arg0->unk74_29) {
                _subaddiefade_entrypoint_3(arg0);
                func_80101FDC(arg0, 3);
            }
            arg0->unk74_29 = 0;
            break;
    }
}

s32 func_80800514_chmumbopad(Actor *arg0, s32 arg1, s32 arg2) {
    typedef struct {
        u8 pad[0x28];
        BT_BITFIELD_ORDER(u32 : 18, u32  : 13);
        u32 enabled : 1;
        BT_BITFIELD_ORDER(u32 : 13, u32  : 18);
    } PadMarker;
    void _chintrotext_entrypoint_1(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
    void func_80103110(void *, s32);
    void func_80800674_chmumbopad(Actor *, s32);
    void func_808008CC_chmumbopad(void *, s32);

    switch (arg1) {
        case 0x91:
            if (!arg0->unk64_19 && !arg0->unk74_29 && !((PadMarker *)arg0->unk0)->enabled) {
                func_808008CC_chmumbopad(arg0, arg2);
            }
            func_80103110(arg0, 1);
            break;
        case 0x32:
            func_80800674_chmumbopad(arg0, arg2);
            break;
        case 0xBB:
            if (arg2 == arg0->unk6C_0) {
                ((PadMarker *)arg0->unk0)->enabled = 0;
            }
            break;
        case 0x2E:
            if (*(s16 *)&arg2 == 0x11DE) {
                _chintrotext_entrypoint_1(0x18BD, arg0->unk6C_0, 0, 1);
                arg0->unk64_19 = 0;
            }
        default:
            return 0;
    }
    return 1;
}

/* extern */

void func_8080063C_chmumbopad(s32 *arg0, s32 arg1) {
    s32 func_800F5FA8(s32);
    s32 func_800F7874(s32, BtIntPtr, void *, s32 *);
    func_800F7874(arg1, *arg0, (u8 *)arg0 + 4, arg0);
    func_800F5FA8(arg1);
}

void func_80800674_chmumbopad(Actor *arg0, s32 arg1) {
    typedef struct {
        u8 pad[0x28];
        BT_BITFIELD_ORDER(u32 : 18, u32  : 13);
        u32 enabled : 1;
        BT_BITFIELD_ORDER(u32 : 13, u32  : 18);
    } PadMarker;
    u32 _subaddiedialog_entrypoint_11(Unk80132ED0* arg0, u32 DialogId, u32 arg2, f32* CameraTarget, s16 arg4);
    s32 func_800C067C(s32);
    s32 func_800F7CF4(BtIntPtr, s32, void *);
    s32 func_80101180(s32, s32, BtIntPtr);

    func_800F7CF4(arg1, 0x43, arg0->actorData);
    func_800C067C(0x11DD);
    if (func_80800048_chmumbopad(arg0) == 0) {
        _subaddiedialog_entrypoint_11(arg0->unk0, 0x11DE, 6, arg0->position, 0);
        arg0->unk64_19 = 1;
    }
    arg0->unk64_20 = 1;
    arg0->unk74_30 = 0;
    func_800C067C(0x11DD);
    switch (arg0->unk6C_0) {
        case 0:
        case 1:
            break;
        case 2:
            arg0->unk64_20 = 0;
            break;
        case 3:
            func_80101180(0x337, 0xA, 0);
            break;
        case 4:
            func_80101180(0x39D, 0xA, 0);
            break;
        case 5:
            func_80101180(0x39C, 0xA, 0);
            break;
        case 6:
            func_80101180(0x297, 0x4B, 0);
            break;
        case 7:
            func_80101180(0x292, 0x4B, 0);
            break;
        case 8:
            func_80101180(0x28E, 0x4B, 8);
            break;
        case 9:
            func_80101180(0x28D, 0x4B, 9);
            arg0->unk64_20 = 0;
            break;
        case 11:
            func_80101180(0x3EE, 0x4B, 0);
            arg0->unk64_20 = 0;
            break;
        case 10:
            func_80101180(0x3F5, 0x4B, 0);
            arg0->unk64_20 = 0;
            break;
        case 12:
            func_80101180(0x40E, 0x4B, 12);
            arg0->unk64_20 = 0;
            break;
        case 13:
            func_80101180(0x346, 0x4B, 0);
            break;
        case 14:
            func_80101180(0x45A, 0x4B, 0);
            break;
        case 15:
            func_80101180(0x457, 0x4B, 0);
            break;
        case 16:
            func_80101180(0x4D8, 0x4B, 0);
            break;
    }
    ((PadMarker *)arg0->unk0)->enabled = !arg0->unk64_20;
}

void func_808008CC_chmumbopad(void *arg0, s32 arg1) {
    typedef struct {
        Unk80132ED0 *marker;
        f32 position[3];
        u8 pad10[0x54];
        BT_BITFIELD_ORDER(u32 : 11, u32  : 20);
        u32 blocked : 1;
        BT_BITFIELD_ORDER(u32 : 20, u32  : 11);
        u32 unk68;
        BT_BITFIELD_ORDER(u32 : 23, u32 spell : 9);
        BT_BITFIELD_ORDER(u32 spell : 9, u32  : 23);
        u32 unk70;
        BT_BITFIELD_ORDER(u32 : 1, u32  : 29);
        BT_BITFIELD_ORDER(u32 warned : 1, u32 touched : 1);
        BT_BITFIELD_ORDER(u32 touched : 1, u32 warned : 1);
        BT_BITFIELD_ORDER(u32 : 29, u32  : 1);
    } MumboPad;
    u32 _subaddiedialog_entrypoint_11(Unk80132ED0* arg0, u32 DialogId, u32 arg2, f32* CameraTarget, s16 arg4);
    void func_80015E80(s32, void *);
    s32 func_800C0638(void);
    s32 func_800DA298(s32);
    void func_800DA544(s32 index);
    s32 func_800DA564(s32, s32);
    s32 func_800F5410(BtIntPtr);
    u32 func_800F54E4(void);
    s32 buttons[6];

    if (func_800F54E4() == arg1) {
        if (func_800F5410(arg1) == 0xD) {
            func_80015E80(0, buttons);
            ((MumboPad *)arg0)->touched = 1;
            if (!func_800DA298(0x9B)) {
                func_800DA544(0x9B);
                _subaddiedialog_entrypoint_11(((MumboPad *)arg0)->marker, 0x11DD, 6, ((MumboPad *)arg0)->position, 0);
            }
            if (buttons[1] == 1 && !((MumboPad *)arg0)->blocked && !func_800DA298(0x9DE)) {
                switch (((MumboPad *)arg0)->spell) {
                    case 0:
                        if (!func_800DA298(0x95)) {
                            func_8080063C_chmumbopad(arg0, arg1);
                        }
                        break;
                    case 1:
                        if (!func_800DA564(0x4FC, 4)) {
                            func_8080063C_chmumbopad(arg0, arg1);
                        }
                        break;
                    case 2:
                        func_8080063C_chmumbopad(arg0, arg1);
                        break;
                    case 3:
                        func_8080063C_chmumbopad(arg0, arg1);
                        break;
                    case 4:
                        func_8080063C_chmumbopad(arg0, arg1);
                        break;
                    case 5:
                        func_8080063C_chmumbopad(arg0, arg1);
                        break;
                    case 6:
                        if (!func_800DA298(0xE9)) {
                            func_8080063C_chmumbopad(arg0, arg1);
                        }
                        break;
                    case 7:
                        if (!func_800DA298(0x15F)) {
                            func_8080063C_chmumbopad(arg0, arg1);
                        }
                        break;
                    case 8:
                        if (!func_800DA298(0x160)) {
                            func_8080063C_chmumbopad(arg0, arg1);
                        }
                        break;
                    case 9:
                        func_8080063C_chmumbopad(arg0, arg1);
                        break;
                    case 11:
                        if (!func_800DA298(0xA05) && !func_800DA298(0x329)) {
                            if (!func_800DA298(0xA06)) {
                                func_8080063C_chmumbopad(arg0, arg1);
                            } else if (!((MumboPad *)arg0)->warned) {
                                ((MumboPad *)arg0)->warned = 1;
                                _subaddiedialog_entrypoint_11(((MumboPad *)arg0)->marker, 0x11E9, 0xE, ((MumboPad *)arg0)->position, 0x10);
                            }
                        }
                        break;
                    case 10:
                        if (!func_800DA298(0xA06)) {
                            if (!func_800DA298(0xA05)) {
                                func_8080063C_chmumbopad(arg0, arg1);
                            } else if (!((MumboPad *)arg0)->warned) {
                                ((MumboPad *)arg0)->warned = 1;
                                _subaddiedialog_entrypoint_11(((MumboPad *)arg0)->marker, 0x11E9, 0xE, ((MumboPad *)arg0)->position, 0x10);
                            }
                        }
                        break;
                    case 12:
                        if (!func_800DA298(0x1E1) || !func_800DA298(0x358) || !func_800DA298(0x359) || !func_800DA298(0x35A)) {
                            func_8080063C_chmumbopad(arg0, arg1);
                        }
                        break;
                    case 13:
                        if (!func_800DA564(0x1CA, 2)) {
                            func_8080063C_chmumbopad(arg0, arg1);
                        }
                        break;
                    case 14:
                        if (func_800DA298(0x375) && !func_800DA298(0x376)) {
                            func_8080063C_chmumbopad(arg0, arg1);
                        } else if (!((MumboPad *)arg0)->warned) {
                            ((MumboPad *)arg0)->warned = 1;
                            _subaddiedialog_entrypoint_11(((MumboPad *)arg0)->marker, 0x11EC, 0xE, ((MumboPad *)arg0)->position, 0x10);
                        }
                        break;
                    case 15:
                        if (!func_800DA298(0x373) && func_800DA298(0x6B4)) {
                            func_8080063C_chmumbopad(arg0, arg1);
                        } else if (!((MumboPad *)arg0)->warned) {
                            ((MumboPad *)arg0)->warned = 1;
                            _subaddiedialog_entrypoint_11(((MumboPad *)arg0)->marker, 0x11EC, 0xE, ((MumboPad *)arg0)->position, 0x10);
                        }
                        break;
                    case 16:
                        if (func_800DA298(0x4F3) && !func_800DA298(0x15E)) {
                            if (!func_800C0638()) {
                                if (func_800DA298(0x189)) {
                                    func_8080063C_chmumbopad(arg0, arg1);
                                } else if (func_800DA298(0x6DB)) {
                                    _subaddiedialog_entrypoint_11(((MumboPad *)arg0)->marker, 0x150E, 0xE, ((MumboPad *)arg0)->position, 0x10);
                                } else {
                                    _subaddiedialog_entrypoint_11(((MumboPad *)arg0)->marker, 0x150F, 0xE, ((MumboPad *)arg0)->position, 0x10);
                                    func_800DA544(0x6DB);
                                }
                            }
                        } else if (!func_800C0638()) {
                            if (func_800DA298(0x6DC)) {
                                _subaddiedialog_entrypoint_11(((MumboPad *)arg0)->marker, 0x150D, 0xE, ((MumboPad *)arg0)->position, 0x10);
                            } else {
                                _subaddiedialog_entrypoint_11(((MumboPad *)arg0)->marker, 0x150C, 0xE, ((MumboPad *)arg0)->position, 0x10);
                                func_800DA544(0x6DC);
                            }
                        }
                        break;
                }
            }
        } else if (!func_800DA298(0x9A)) {
            func_800DA544(0x9A);
            _subaddiedialog_entrypoint_11(((MumboPad *)arg0)->marker, 0x11DC, 6, ((MumboPad *)arg0)->position, 0);
        }
    }
}

OSThread *chmumbopad_entrypoint_1(void)
{

    return (OSThread *) D_80801110_chmumbopad;
}
