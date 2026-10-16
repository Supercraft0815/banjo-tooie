#include "common.h"

s32 chmumbopad_entrypoint_0(s32 arg0) {
    extern s32 D_80801086_chmumbopad[];
    return *(s16 *)((u8 *)D_80801086_chmumbopad + (arg0 << 2));
}

/* extern */

void func_80800014_chmumbopad(s32 arg0, s32 arg1, s32 arg2) {
    s32 _gccubesearch_entrypoint_1(s32);
    s32 _gspropctrl_entrypoint_11(s32, s32);
    _gspropctrl_entrypoint_11(_gccubesearch_entrypoint_1(arg2), arg1);
}

s32 func_80800048_chmumbopad(void *arg0) { s32 func_800DA298(s32); extern s16 D_808010C8_chmumbopad[]; s16 temp_a1; temp_a1 = D_808010C8_chmumbopad[(*(s32 *)((s8 *)arg0 + 0x6C)) & 0x1FF]; if (temp_a1 != -1) { return func_800DA298(temp_a1); } else { return 0; } }

int func_80800098_chmumbopad(Actor *arg0) {
    s32 func_800DA298(s32);
    s32 func_800DA564(s32, s32);
    extern s16 D_808010EC_chmumbopad[];
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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mumbo/pad/func_80800140_chmumbopad.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mumbo/pad/func_8080044C_chmumbopad.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mumbo/pad/func_80800514_chmumbopad.s")

/* extern */

void func_8080063C_chmumbopad(s32 *arg0, s32 arg1) {
    s32 func_800F5FA8(s32);
    s32 func_800F7874(s32, s32, void *, s32 *);
    func_800F7874(arg1, *arg0, (u8 *)arg0 + 4, arg0);
    func_800F5FA8(arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mumbo/pad/func_80800674_chmumbopad.s")

void func_808008CC_chmumbopad(void *arg0, s32 arg1) {
    typedef struct {
        Unk80132ED0 *marker;
        f32 position[3];
        u8 pad10[0x54];
        u32 : 11;
        u32 blocked : 1;
        u32 : 20;
        u32 unk68;
        u32 : 23;
        u32 spell : 9;
        u32 unk70;
        u32 : 1;
        u32 warned : 1;
        u32 touched : 1;
        u32 : 29;
    } MumboPad;
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
    void func_80015E80(s32, void *);
    s32 func_800C0638(void);
    s32 func_800DA298(s32);
    s32 func_800DA544(s32);
    s32 func_800DA564(s32, s32);
    s32 func_800F5410(s32);
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
    extern u8 D_80801110_chmumbopad[];

    return (OSThread *) D_80801110_chmumbopad;
}
