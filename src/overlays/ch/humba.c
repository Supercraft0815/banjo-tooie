#include "common.h"
#include "humba_tables.h"

s32 func_800EA05C(void);     

/* extern */

void func_80800000_chhumba(s32 *arg0, s32 arg1) {
    s32 _capod_entrypoint_2(BtIntPtr, s32, s32);
    _capod_entrypoint_2(*arg0, 9, arg1);
}

void func_80800028_chhumba(Actor *arg0, s32 arg1, s32 arg2) {
    void _capod_entrypoint_7(s32, s32);
    void _capod_entrypoint_8(s32);
    void _capod_entrypoint_12(s32);
    void _gcdialogcamera_entrypoint_6(Unk80132ED0 *);
    void _gcdialogcamera_entrypoint_8(void);

    switch (arg0->unk74_7) {
        case 0:
            func_80800000_chhumba(arg0, 0);
        case 1:
        case 3:
            _capod_entrypoint_8(1);
            arg0->unk74_7 = 2;
            _gcdialogcamera_entrypoint_6(arg0->unk0);
            _gcdialogcamera_entrypoint_8();
            _capod_entrypoint_12(0);
        case 2:
            _capod_entrypoint_7(arg1, arg2);
            break;
    }
}

void func_808000D4_chhumba(Actor *arg0, s32 arg1, s32 arg2, Unk80132ED0 *arg3) {
    s32 _capod_entrypoint_20(BtIntPtr arg0, s32 arg1, s32 arg2);

    switch (arg0->unk74_7) {
        case 0:
            func_80800000_chhumba(arg0, arg2);
        case 1:
        case 2:
            arg0->unk74_7 = 3;
        case 3:
            _capod_entrypoint_20(arg3, arg1, arg2);
            break;
    }
}

void func_8080015C_chhumba(Actor *arg0, s32 arg1, s32 arg2, Unk80132ED0 *arg3) {
    s32 _capod_entrypoint_6(BtIntPtr arg0, s32 arg1, s32 arg2);

    switch (arg0->unk74_7) {
        case 0:
            func_80800000_chhumba(arg0, arg2);
        case 2:
        case 3:
            arg0->unk74_7 = 1;
        case 1:
            _capod_entrypoint_6(arg3, arg1, arg2);
            break;
    }
}

/* extern */

void func_808001E4_chhumba(Actor *arg0) {
    s32 _capod_entrypoint_3(s32);
    s32 func_800DA298(s32);
    if ((func_800DA298(0x9C7) != 0) && (arg0->unk74_7 != 0)) {
        _capod_entrypoint_3(0);
        arg0->unk74_7 = 0;
    }
}

void func_80800238_chhumba(u8 *arg0, f32 *arg1) {
    void func_800EFA4C(f32[3], f32, f32, f32);
    func_800EFA4C(arg1, 0.0f, (((Actor *)arg0)->scale) * 5.0f * -50.0f, 0.0f);
}

void func_80800294_chhumba(u8 *arg0, s32 arg1) {
    void func_800904C8(s32);
    void func_80090658(s32);
    void func_80090708(s32);
    void func_80090734(s32, f32 *);
    s32 func_800DA298(s32);
    s32 func_800EA05C();

    if ((arg1 != 0) && (func_800DA298(0x9C8) != 0)) {
        func_800904C8(0x8D);
    }
    if (func_800EA05C() != 0x122) {
        if (arg1 != 0) {
            func_80090734(1, (f32 *)(arg0 + 4));
            return;
        }
        if (func_800DA298(0x9C8) != 0) {
            func_80090708(0);
        }
    } else if (func_800DA298(0x9C8) != 0) {
        func_80090658(arg1);
    }
}

void func_80800338_chhumba(u8 *arg0, s32 arg1, s32 arg2) {
    struct Flags { u8 pad[0x74]; BT_BITFIELD_ORDER(u8 high : 1, u8 low : 6); u8 flag : 1; BT_BITFIELD_ORDER(u8 low : 6, u8 high : 1); };
    u32 _subaddiedialog_entrypoint_11(Unk80132ED0* arg0, u32 DialogId, u32 arg2, f32* CameraTarget, s16 arg4);
    arg2 |= 4;
    _subaddiedialog_entrypoint_11(*(Unk80132ED0 **)arg0, arg1, arg2, (f32 *)(arg0 + 4), 0x40U);
    ((struct Flags *)arg0)->flag = 1;
}                typedef struct { u8 pad0[0x38]; f32 unk38; u8 pad3C[0x30]; s32 unk6C; } Objhumba_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

s32 func_80800384_chhumba(u8 *arg0) {
    s32 func_800EA05C();
    if (func_800EA05C() == 0x122) {
        return 0x13;
    }
    return HUMBA_FORM(D_808025A4_chhumba, ((((Objhumba_arg0 *)arg0)->unk6C) & 0x1FF));
}

s32 func_808003CC_chhumba(u8 *arg0) {
    s32 func_800EA05C();
    if (func_800EA05C() == 0x122) {
        return 0x11AA;
    }
    return HUMBA_DIALOG(D_808025A4_chhumba, ((((Objhumba_arg0 *)arg0)->unk6C) & 0x1FF));
}

/* extern */

s32 func_80800414_chhumba(void *arg0) {
    s32 func_800EA05C();
    if (func_800EA05C() == 0x122) {
        return 0x346;
    }
    return ((((Objhumba_arg0 *)arg0)->unk6C) & 0x1FF) + 0x346;
}

s32 func_80800450_chhumba(Actor *arg0, s32 arg1, s32 arg2) {
    typedef struct {
        u8 pad[0x14];
        BT_BITFIELD_ORDER(u32 pad14 : 31, u32 unk14_0 : 1);
        BT_BITFIELD_ORDER(u32 unk14_0 : 1, u32 pad14 : 31);
    } HumbaModel;
    void func_80800E44_chhumba(u8 *, s32);
    void func_80801DB0_chhumba(Actor *, s32, s32);
    void func_80801F74_chhumba(Actor *);
    
    s32 _gcdialogcamera_entrypoint_0(s32, s32);
    void _gcdialogcamera_entrypoint_3(f32 *arg0, f32 arg1);
    void func_800904C8(s32);
    void func_80090708(s32);
    void func_800DF744(s32, s32);
    void func_800EE7F8(f32 *, f32 *);
    s32 func_801015D0(Actor *);
    u8 *func_801039E4(Unk80132ED0 *);
    BtIntPtr func_80103CB8(Actor *, BtUIntPtr);
    Actor *func_801084B0(BtIntPtr, Actor **);
    void func_8010D254(f32 *);
    extern f32 D_80802684_chhumba[4];
    Actor *sp2C;
    f32 sp20[3];

    switch (arg1) {
        case 0x49:
            func_80801F74_chhumba(arg0);
            break;
        case 0xA1:
            switch (arg0->unk70_10) {
                case 10:
                    func_80800E44_chhumba((u8 *)arg0, 11);
                    break;
                case 15:
                    func_80800E44_chhumba((u8 *)arg0, 16);
                    break;
            }
            break;
        case 0x3D:
            func_80800238_chhumba((u8 *)arg0, sp20);
            sp2C = func_801084B0(0x29F, &arg0);
            func_800EE7F8((f32 *)sp2C->actorData, sp20);
            func_8010D254(sp2C->position);
            sp2C->unk74_30 = 1;
            arg0->unk3C = sp2C->unk0;
            func_80800E44_chhumba((u8 *)arg0, 6);
            break;
        case 0x2E:
            func_80801DB0_chhumba(arg0, ((s16 *)&arg2)[0], ((s16 *)&arg2)[1]);
            break;
        case 0x2F:
            if (((s16 *)&arg2)[1] == 1) {
                func_80090708(0);
                func_80090708(1);
            }
            break;
        case 0x52:
            _gcdialogcamera_entrypoint_3(D_80802684_chhumba, arg0->scale);
            break;
        case 0x57:
            if (_gcdialogcamera_entrypoint_0(arg2 & 0xFFFF, (u32)(arg2 & 0xFFFF0000) >> 16)) {
                if (arg0->unk74_7 != 2) {
                    func_80800028_chhumba(arg0, 2, 1);
                }
                return 2;
            }
            return 1;
        case 0x32:
            switch (arg0->unk70_10) {
                case 17:
                    func_80800338_chhumba((u8 *)arg0, 0x11AF, 0xF);
                    break;
                case 18:
                    func_80800E44_chhumba((u8 *)arg0, 0x12);
                    break;
                default:
                    func_800904C8(0x8D);
                    if (arg0->unk74_29) {
                        func_80800338_chhumba((u8 *)arg0, 0x11BD, 0xF);
                    } else {
                        func_80800338_chhumba((u8 *)arg0, 0x11A4, 0xF);
                    }
                    break;
            }
            break;
        case 0x1F:
            func_801015D0(arg0);
            sp2C = (Actor *)func_80103CB8(arg0, (BtUIntPtr)func_801039E4(arg0->unk0));
            ((HumbaModel *)sp2C)->unk14_0 = 1;
            func_800DF744(3, 0);
            func_800DF744(5, 0);
            break;
        default:
            return 0;
    }
    return 1;
}

s32 func_8080071C_chhumba(BtIntPtr arg0) {
    s32 func_800EA05C();
    s32 map;

    map = func_800EA05C();
    switch (map) {
        case 0xB6:
            return 1;
        case 0xD5:
            return 3;
        case 0xE9:
            return 2;
        case 0x11E:
        case 0x122:
            return 5;
        case 0x120:
            return 4;
        case 0x11F:
            return 6;
        case 0x135:
            return 7;
        case 0x140:
            return 8;
        case 0x157:
            return 9;
        default:
            return 0;
    }
}

s32 func_808007EC_chhumba(BtIntPtr arg0) {
    return 1;
}

/* extern */

void func_808007F8_chhumba(Actor *arg0) {
    BT_IDO_ONLY(void func_800D175C(s32, s32);) BT_NATIVE_ONLY(s32 func_800D175C(s32, s32);)
    void func_800DA544(GameFlag);
    func_800DA544(arg0->unk6C_0 + 0xD5);
    if (arg0->unk74_29) {
        func_800D175C(0x54, -func_808007EC_chhumba((BtIntPtr) arg0));
    } else {
        func_800D175C(0x48, -func_808007EC_chhumba((BtIntPtr) arg0));
    }
    arg0->unk64_20 = 1;
}

/* extern */

s32 func_80800878_chhumba(void *arg0) {
    s32 func_800DA298(s32);
    BT_NATIVE_ONLY(return) func_800DA298(((*(s32 *)((s8 *)(arg0) + (0x6C))) & 0x1FF) + 0xD5);
}

s32 func_808008A0_chhumba(Actor *arg0) {
    int func_800F0064(f32 *, f32, f32 *);
    Actor *func_80106790(Unk80132ED0 *);
    f32 sp24[3];
    Actor *sp20;
    f32 temp_f0;

    sp20 = func_80106790(arg0->unk3C);
    func_80800238_chhumba(arg0, sp24);
    temp_f0 = arg0->scale;
    if ((sp20->position[1] < -202.5f * temp_f0) &&
        (func_800F0064(sp20->position, temp_f0 * 1550.0f, sp24) != 0)) {
        return 1;
    }
    return 0;
}

s32 func_80800934_chhumba(Actor *arg0, s32 arg1) {
    s32 func_80016B30(s32, s32);
    s32 func_8008FA60(s32, s32);
    s32 func_80090080();
    BtUIntPtr func_800F54E4(void);
    s32 func_800F5FE0(BtIntPtr);
    void func_8010D254(f32 *);
    f32 sp3C;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp24[3];

    sp3C = arg0->scale * 500.0f;
    sp38 = arg0->scale * -500.0f;
    sp34 = arg0->scale * 1900.0f;
    sp30 = arg0->scale * 2950.0f;
    func_8010D254(sp24);
    if ((sp24[0] < sp38) || (sp3C < sp24[0])) {
        return 0;
    }
    if ((sp24[2] < sp34) || (sp30 < sp24[2])) {
        return 0;
    }
    if (func_8008FA60(arg1, 6) == 0) {
        return 0;
    }
    if (func_80090080() != 0) {
        if (func_80016B30(0, 1) != 0) {
            return 1;
        }
        func_800F5FE0(func_800F54E4());
    }
    return 0;
}

s32 func_80800A50_chhumba(Actor *arg0) {
    s32 func_800EA05C();
    BtUIntPtr func_800F54E4(void);
    s32 func_800F71D4(BtIntPtr);
    s32 func_8010C9FC(f32 *, s32, s32, s32);
    void func_8010D254(f32 *);
    f32 sp2C[3];
    f32 sp20[3];
    f32 scale;

    func_80800238_chhumba(arg0, sp2C);
    sp2C[1] = 0.0f;
    func_8010D254(sp20);
    scale = arg0->scale;
    if (func_8010C9FC(sp2C, (s32)(scale * 1550.0f),
                     (s32)(scale * -202.5f), (s32)(scale * -1237.5f)) == 0) {
        return 0;
    }
    if (func_800F71D4(func_800F54E4()) == 0) {
        return 0;
    }
    if ((func_800EA05C() == 0x120) && (sp20[1] > -100.0f)) {
        return 0;
    }
    return 1;
}

/* extern */

s32 func_80800B40_chhumba(u8 *arg0) {
    void func_8008F8B0();
    void func_8008F8D8(s32);
    void func_8008F904(void*, BtIntPtr);
    void func_8008F938(s32);
    extern s32 func_8010D5DC;
    void func_8008F9F8(f32 *, f32);
    void func_8080015C_chhumba(Actor *, s32, s32, Unk80132ED0 *);
    func_8080015C_chhumba(arg0, 0, 0x60, 0);
    func_8008F8B0();
    func_8008F8D8(1);
    func_8008F938(1);
    func_8008F904(&func_8010D5DC, *(s32 *)arg0);
    func_8008F9F8((f32 *)(arg0 + 0x28), 200.0f); BT_NATIVE_ONLY(return 0;)
}

void func_80800BA8_chhumba(Actor *arg0, f32 *arg1) {
    void func_800EFCD8(f32 *, f32, f32);
    int func_800F1EA4(f32 *, f32 *);
    f32 func_800F1F38(f32, f32, f32);
    void func_8010D254(f32 *);
    f32 yaw;
    f32 position[3];

    func_8010D254(position);
    func_800F1EA4(position, &yaw);
    func_800EFCD8(arg1, func_800F1F38(yaw, 0.0f, 10.0f), arg0->scale * 2000.0f);
    arg1[1] = position[1];
}

s32 func_80800C20_chhumba(u8 *arg0) {
    int func_800F1EA4(f32[3], f32 *);
    s32 func_800F20BC(f32, f32, s32);
    void func_8010D254(f32*);
    f32 sp24;
    f32 sp18[3];

    (void)&arg0;
    func_8010D254(&sp18);
    func_800F1EA4(&sp18, &sp24);
    if (func_800F20BC(0.0f, sp24, 0x40A00000) == 0) {
        return 1;
    }
    return 0;
}

/* extern */

void func_80800C6C_chhumba(s32 *arg0) {
    void func_8008F8B0();
    void func_8008F8D8(s32);
    void func_8008F904(void*, BtIntPtr);
    void func_8008F938(s32);
    void func_8008F990(BtIntPtr, f32);
    extern s32 func_8010D5DC;
    void func_80800BA8_chhumba(Actor *, f32 *);
    s32 pad[2];
    s32 sp1C;

    func_80800BA8_chhumba(arg0, &sp1C);
    func_8008F8B0();
    func_8008F8D8(1);
    func_8008F938(1);
    func_8008F904(&func_8010D5DC, *arg0);
    func_8008F990((BtIntPtr) &sp1C, 300.0f);
}

void func_80800CC8_chhumba(Actor *volatile arg0) {
    void func_8008FB10(BtIntPtr, f32, f32, f32);
    extern f32 D_80802694_chhumba[3];
    f32 temp_f0;

    temp_f0 = arg0->scale;
    func_8008FB10((BtIntPtr) D_80802694_chhumba, temp_f0 * 1600.0f, temp_f0 * 72.0f, temp_f0 * 350.0f);
}

/* extern */

s32 func_80800D2C_chhumba(BtIntPtr arg0) {
    s32 func_800DA9E4(s32, s32);
    void func_80800338_chhumba(u8 *, s32, s32);
    if (func_800DA9E4(0xE2, 1) == 0) {
        func_80800338_chhumba(arg0, 0x11B5, 0xF);
        return 1;
    }
    return 0;
}

void func_80800D74_chhumba(Actor *arg0) {
    BtIntPtr func_800B53A4(s32);
    void func_800BA22C(BtIntPtr, s32);
    BtIntPtr func_800BABB8(BtIntPtr, f32[3], f32[3], f32, s16[]);
    f32 func_800DC0C0(void);
    s32 func_800DC128(s32, s32);
    f32 func_800DC178(f32, f32);
    void func_800EEB9C(f32[3], f32, f32);
    extern s16 D_808026A0_chhumba[40];
    s32 sp3C;
    BtIntPtr sp38;
    f32 sp2C[3];
    f32 sp28;
    f32 sp24;

    if (func_800DC0C0() < 0.1f) {
        sp3C = func_800DC128(1, 3);
        sp38 = func_800B53A4(sp3C);
        sp24 = func_800DC178(0.0f, 360.0f);
        func_800EEB9C(sp2C, sp24, arg0->scale * func_800DC178(0.0f, 1000.0f));
        sp2C[1] = -50.0f;
        func_800BABB8(sp38, sp2C, NULL, 1.0f, D_808026A0_chhumba);
        func_800BA22C(sp38, sp3C);
    }
}

void func_80800E44_chhumba(u8 *arg0, s32 arg1) {
    s32 _fxsplash25d_entrypoint_0(f32 *);
    void _fxsplash_entrypoint_1(f32 arg0[3]);
    void _subaddieaudioquick_entrypoint_2(Actor *arg0, f32 arg1[3], void *arg2);
    s32 func_8008FD48(void);
    Unk80132ED0 *func_8008FDEC(void);
    void func_80090658(s32);
    void func_80090708(s32);
    BT_IDO_ONLY(s32) BT_NATIVE_ONLY(void) func_80090768(f32 *);
    s32 func_800907EC(s32);
    s32 func_8009EA2C(void);
    void func_8009EAAC(s32);
    s32 func_800DA9E4(s32, s32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800FC660(u32);
    void func_800FC6B0(u32);
    void func_80101FDC(Actor *, u32);
    Actor *func_80106790(Unk80132ED0 *);
    void func_80800028_chhumba(Actor *, s32, s32);
    void func_808000D4_chhumba(Actor *, s32, s32, Unk80132ED0 *);
    void func_8080015C_chhumba(Actor *, s32, s32, Unk80132ED0 *);
    void func_808001E4_chhumba(Actor *);
    void func_80800294_chhumba(u8 *, s32);
    void func_80800338_chhumba(u8 *, s32, s32);
    s32 func_80800384_chhumba(u8 *);
    s32 func_808003CC_chhumba(u8 *);
    void func_808007F8_chhumba(Actor *);
    s32 func_80800B40_chhumba(u8 *);
    s32 func_80800C20_chhumba(u8 *);
    void func_80800C6C_chhumba(s32 *);
    extern s16 D_80802590_chhumba[10];
    f32 sp34[3];
    Actor *sp30;
    f32 sp24[3];

    switch (((Actor *)arg0)->unk70_10) {
        case 2:
            break;
        case 3:
            func_80800294_chhumba(arg0, 0);
            break;
        case 5:
        case 6:
            func_80800238_chhumba(arg0, sp34);
            func_80090658(0);
            _fxsplash_entrypoint_1(sp34);
            _fxsplash25d_entrypoint_0(sp34);
            _subaddieaudioquick_entrypoint_2(arg0, arg0 + 4, (s32 *)D_80802590_chhumba);
            func_808007F8_chhumba(arg0);
            func_800FC660(0xE);
            func_80800338_chhumba((BtIntPtr)arg0, 0x11B4, 0xF);
            break;
    }
    func_80101FDC((Actor *)arg0, arg1);
    switch (((Actor *)arg0)->unk70_10) {
        case 2:
            func_80800B40_chhumba(arg0);
            return;
        case 3:
            func_80800028_chhumba(arg0, 3, 1);
            func_80800294_chhumba(arg0, 1);
            return;
        case 18:
            if (func_80800C20_chhumba(arg0) != 0) {
                func_80800C6C_chhumba(arg0);
                return;
            }
            func_80800E44_chhumba(arg0, 4);
            return;
        case 4:
            func_80090658(1);
            return;
        case 5:
            func_80800238_chhumba(arg0, sp24);
            func_80090768(sp24);
            ((Actor *)arg0)->unk3C = func_8008FDEC();
            sp30 = func_80106790(((Actor *)arg0)->unk3C);
            func_800EE7F8((f32 *)sp30->actorData, sp24);
            sp30->unk74_30 = 1;
            func_808000D4_chhumba(arg0, 0xE, 9, ((Actor *)arg0)->unk3C);
            return;
        case 6:
            func_808000D4_chhumba(arg0, 0xE, 9, ((Actor *)arg0)->unk3C);
            return;
        case 8:
            func_80090658(1);
            func_8080015C_chhumba(arg0, 2, 0x60, 0);
            return;
        case 9:
            ((Actor *)arg0)->unk58 = 4.0f;
            func_800FC6B0(0xC);
            if (((Actor *)arg0)->unk74_29 && func_8009EA2C() == 0) {
                func_8009EAAC(1);
                func_800907EC(func_8008FD48());
                return;
            }
            func_800907EC(func_80800384_chhumba(arg0));
            return;
        case 11:
            func_80090658(0);
            if (func_800DA9E4(func_80800414_chhumba(arg0), 1) == 0) {
                if (((Actor *)arg0)->unk74_29) {
                    func_80090708(2);
                    func_80800338_chhumba((BtIntPtr)arg0, func_808003CC_chhumba(arg0), 3);
                    return;
                }
                func_80800338_chhumba((BtIntPtr)arg0, func_808003CC_chhumba(arg0), 0xB);
                return;
            }
            if (func_80800D2C_chhumba((BtIntPtr)arg0) == 0) {
                func_808001E4_chhumba(arg0);
                func_80800E44_chhumba(arg0, 0xC);
                return;
            }
            return;
        case 13:
            func_80090658(1);
            func_8080015C_chhumba(arg0, 5, 0x60, 0);
            return;
        case 14:
            ((Actor *)arg0)->unk58 = 4.0f;
            func_800FC6B0(0xC);
            if (((Actor *)arg0)->unk74_29 && func_8009EA2C() != 0) {
                func_8009EAAC(0);
                func_800907EC(func_8008FD48());
                return;
            }
            func_800907EC(1);
            return;
        case 16:
            func_80090658(0);
            if (func_800DA9E4(0x1D1, 1) == 0) {
                func_80800338_chhumba((BtIntPtr)arg0, 0x11B6, 0xF);
                return;
            }
            func_808001E4_chhumba(arg0);
            func_80800E44_chhumba(arg0, 7);
            return;
        case 17:
            if (func_800DA9E4(0x505, 1) == 0) {
                func_80800B40_chhumba(arg0);
            }
            return;
    }
}
struct HumbaVector { f32 v[3]; };
void func_80801260_chhumba(Actor *arg0) {
    void func_8008FE68(f32 *);
    void func_8008FF40(f32 *);
    void func_800906DC(f32 *);
    void func_800907C0(f32 *);
    void func_800EF334(f32 *, f32);
    f32 func_800F1DCC(f32, f32);

    extern struct HumbaVector D_808026F0_chhumba;
    struct HumbaVector target;
    s32 i;
    f32 position[3];

    target = D_808026F0_chhumba;
    func_800EF334(target.v, arg0->scale);
    func_8008FE68(position);
    for (i = 0; i < 3; i++) {
        position[i] += (target.v[i] - position[i]) * 0.05f;
    }
    func_800907C0(position);
    func_8008FF40(position);
    position[1] += func_800F1DCC(180.0f, position[1]) * 0.05f;
    position[0] += func_800F1DCC(0.0f, position[0]) * 0.05f;
    position[2] += func_800F1DCC(0.0f, position[2]) * 0.05f;
    func_800906DC(position);
}

/* extern */

void func_8080138C_chhumba(u8 *arg0) {
    s32 func_8008FD48();
    s32 func_80090270();
    s32 func_8009EA2C(void);
    s32 func_80800A50_chhumba();
    s32 sp1C;
    s32 temp_v0;

#ifdef BT_NATIVE
    if ((((s32 (*)())func_80800A50_chhumba)() != 0) && (func_80090270() == 0)) {
#else
    if ((func_80800A50_chhumba() != 0) && (func_80090270() == 0)) {
#endif
        temp_v0 = func_8008FD48();
        sp1C = temp_v0;
        if ((temp_v0 == 1) && ((func_8009EA2C() == 0) || !((Actor *)arg0)->unk74_29)) {
            func_80800E44_chhumba(arg0, 8);
            return;
        }
        if ((func_80800384_chhumba(arg0) == sp1C) || ((func_8009EA2C() != 0) && ((Actor *)arg0)->unk74_29)) {
            func_80800E44_chhumba(arg0, 0xD);
        }
    }
}

void func_8080144C_chhumba(f32 arg0) {
    void func_800EE7F8(f32 *, f32 *);
    void func_800EFA20(void *, void *, f32);
    void func_800EFB24(void *, void *, void *);
    BtUIntPtr func_800F54E4(void);
    void func_800F7F50(BtIntPtr, void *, void *, f32, s32, s32);
    void func_8010D254(f32 *);
    extern f32 D_808026FC_chhumba[4][3];
    extern f32 D_8080272C_chhumba[3];
    s32 pad;
    f32 sp98[3];
    f32 sp8C[3];
    f32 sp80[3];
    f32 temp_f0;
    f32 sp70[3];
    f32 *var_s0;
    f32 var_f20;

    func_8010D254(sp8C);
    if (arg0 <= 1.0f) {
        var_f20 = 60.0f;
    } else {
        var_f20 = 100.0f;
    }
    var_s0 = D_808026FC_chhumba[0];
    do {
        func_800EFA20(sp98, var_s0, arg0);
        func_800EE7F8(sp80, sp98);
        sp80[1] = 610.0f * arg0;
        func_800EFB24(sp70, sp98, sp8C);
        temp_f0 = var_f20 + 25.0f;
        if ((sp70[0] * sp70[0] + sp70[2] * sp70[2] < temp_f0 * temp_f0)
            && (sp98[1] < sp8C[1]) && (sp8C[1] <= sp80[1])) {
            func_800F7F50(func_800F54E4(), sp98, sp80, var_f20, 2, 1);
        }
        var_s0 += 3;
    } while (var_s0 != BT_DATA_FIELD((f32 *)(D_808026FC_chhumba + 4), D_8080272C_chhumba));
}

void *func_80100094(Actor *, u32);

void func_808015DC_chhumba(Actor *arg0) {
    u32 _chbaddiesetup_entrypoint_0(u32 *);
    s32 _subaddiedialog_entrypoint_6(f32 *, s32, s32, s32, s32);
    void _suexpression_entrypoint_10(u32 *, Unk80132ED0 *, BtUIntPtr);
    void func_8008F964(f32 *);
    void func_8008FB10(BtIntPtr, f32, f32, f32);
    s32 func_8008FE14(void);
    s32 func_80090178(s32);
    s32 func_800902E4(f32 *, f32, s32, Actor **);
    s32 func_800903D0(f32 *);
    void func_800904F4(s32, Unk80132ED0 *);
    s32 func_80090818(void);
    s32 func_800C0638(void);
    void func_800D1824(s32);
    s32 func_800D1A04(s32);
    f32 func_800D8FF8(void);
    s32 func_800EA05C(void);
    void *func_80100094(Actor *, u32);
    void func_80108B04(Actor *, u32);
    void func_8010D254(f32 *);
    extern u32 _chglowbo_entrypoint_4;
    f32 sp44[3];
    f32 sp38[3];
    s32 sp34;
    f32 temp_f0;
    s32 sp2C;

    _suexpression_entrypoint_10(func_80100094(arg0, 1), arg0->unk0, 0);
    func_8080144C_chhumba(arg0->scale * 5.0f);
    if (func_800C0638() != 0) {
        ((f32 *)arg0->actorData)[3] = 1.5f;
    } else if (((f32 *)arg0->actorData)[3] > 0.0f) {
        ((f32 *)arg0->actorData)[3] -= func_800D8FF8();
    }
    if (func_80800878_chhumba(arg0) != 0) {
        func_80800D74_chhumba(arg0);
    } else if (((f32 *)arg0->actorData)[3] <= 0.0f) {
        if (arg0->unk74_29) {
            func_800D1824(0x54);
        } else {
            func_800D1824(0x48);
        }
    }
    temp_f0 = arg0->scale;
    func_8008FB10((BtIntPtr)arg0->position, temp_f0 * 1350.0f,
                  temp_f0 * 72.0f, temp_f0 * 350.0f);
    if (func_80090178(0x10000) == 0) {
        switch (arg0->unk70_10) {
        case 1:
            if (func_800EA05C() == 0x120) {
                func_8010D254(sp44);
                if ((sp44[1] > -30.0f) && (func_80090178(0x6C8E3) != 0) &&
                    (_subaddiedialog_entrypoint_6(arg0->position, (s32)arg0->rotation[1], 0x15E, 0x32, 6) != 0)) {
                    func_80800E44_chhumba((u8 *)arg0, 3);
                }
                if (func_80800934_chhumba(arg0, 0x6C8E3) != 0) {
                    func_80800E44_chhumba((u8 *)arg0, 3);
                }
            } else {
                if ((func_80090178(0x6C8E3) != 0) &&
                    (_subaddiedialog_entrypoint_6(arg0->position, (s32)arg0->rotation[1], 0x15E, 0x32, 0) != 0)) {
                    func_80800E44_chhumba((u8 *)arg0, 3);
                }
                if (func_80800934_chhumba(arg0, 0x6C8E3) != 0) {
                    func_80800E44_chhumba((u8 *)arg0, 3);
                }
            }
            break;
        case 3:
            if (!arg0->unk74_30) {
                if (arg0->unk74_29) {
                    sp2C = func_800D1A04(0x54);
                    if (sp2C >= func_808007EC_chhumba((BtIntPtr)arg0)) {
                        func_80800338_chhumba((u8 *)arg0, 0x11BE, 0x4E);
                    } else {
                        func_80800338_chhumba((u8 *)arg0, 0x11BF, 0xF);
                    }
                } else {
                    sp2C = func_800D1A04(0x48);
                    if (sp2C >= func_808007EC_chhumba((BtIntPtr)arg0)) {
                        func_80800338_chhumba((u8 *)arg0, 0x11B0, 0x4E);
                    } else {
                        func_80800338_chhumba((u8 *)arg0, 0x11B3, 0xF);
                    }
                }
            }
            break;
        case 18:
            func_80800BA8_chhumba(arg0, sp38);
            func_8008F964(sp38);
            func_80800CC8_chhumba(arg0);
            break;
        case 4:
            if (func_800EA05C() == 0x120) {
                func_80108B04(arg0, 0);
            } else {
                sp34 = arg0->unk74_29 ? 0x523 : 0x29F;
                if ((func_800902E4(arg0->position, 2500.0f, sp34, &arg0) != 0) &&
                    (func_8008FE14() == sp34) && (func_80090818() != 0)) {
                    func_80800E44_chhumba((u8 *)arg0, 5);
                }
            }
            break;
        case 5:
        case 6:
            if (func_808008A0_chhumba(arg0) != 0) {
                func_80800E44_chhumba((u8 *)arg0, 7);
            }
            break;
        case 7:
            if (((func_80090178(0x6C8E3) != 0) &&
                 (_subaddiedialog_entrypoint_6(arg0->position, (s32)arg0->rotation[1], 0x15E, 0x32, 6) != 0)) ||
                (func_80800934_chhumba(arg0, 0x6C8E3) != 0)) {
                func_80800338_chhumba((u8 *)arg0, 0x11B8, 0xF);
            } else {
                func_8080138C_chhumba((u8 *)arg0);
            }
            break;
        case 8:
            func_80800E44_chhumba((u8 *)arg0, 9);
            break;
        case 9:
            if (arg0->unk58 > 0.0f) {
                arg0->unk58 -= func_800D8FF8();
                if (arg0->unk64_20 && (arg0->unk58 < 1.5f)) {
                    _chbaddiesetup_entrypoint_0(&_chglowbo_entrypoint_4);
                    arg0->unk64_20 = 0;
                }
            } else if (func_800903D0((f32 *)&arg0->actorData[4]) != 0) {
                func_800904F4(0x89, arg0->unk0);
                func_80800E44_chhumba((u8 *)arg0, 10);
            }
            func_80801260_chhumba(arg0);
            break;
        case 12:
            if (((func_80090178(0x6C8E3) != 0) &&
                 (_subaddiedialog_entrypoint_6(arg0->position, (s32)arg0->rotation[1], 0x15E, 0x32, 0) != 0)) ||
                (func_80800934_chhumba(arg0, 0x6C8E3) != 0)) {
                func_80800338_chhumba((u8 *)arg0, 0x11B9, 0xF);
            } else {
                func_8080138C_chhumba((u8 *)arg0);
            }
            break;
        case 13:
            func_80800E44_chhumba((u8 *)arg0, 14);
            break;
        case 14:
            if (arg0->unk58 > 0.0f) {
                arg0->unk58 -= func_800D8FF8();
            } else if (func_800903D0((f32 *)&arg0->actorData[4]) != 0) {
                func_800904F4(0x89, arg0->unk0);
                func_80800E44_chhumba((u8 *)arg0, 15);
            }
            func_80801260_chhumba(arg0);
            break;
        case 17:
            if ((_subaddiedialog_entrypoint_6(arg0->position, (s32)arg0->rotation[1], 0x15E, 0x32, 0) != 0) ||
                (func_80800934_chhumba(arg0, 0x600) != 0)) {
                func_80800338_chhumba((u8 *)arg0, 0x11BC, 0xF);
            } else if (!arg0->unk64_19 && (func_80800A50_chhumba(arg0) != 0)) {
                arg0->unk64_19 = 1;
                func_80800338_chhumba((u8 *)arg0, 0x11BA, 0xF);
            }
            break;
        case 19:
            if ((_subaddiedialog_entrypoint_6(arg0->position, (s32)arg0->rotation[1], 0x15E, 0x32, 0) != 0) ||
                (func_80800934_chhumba(arg0, 0x600) != 0)) {
                func_80800338_chhumba((u8 *)arg0, func_80090178(0x200) ? 0x121C : 0x121D, 0xF);
            } else if (!arg0->unk64_19 && (func_80800A50_chhumba(arg0) != 0)) {
                arg0->unk64_19 = 1;
                func_80800338_chhumba((u8 *)arg0, 0x11BB, 0xF);
            }
            break;
        }
    }
}

void func_80801DB0_chhumba(Actor *arg0, s32 arg1, s32 arg2) {
    void func_80090708(s32);
    void func_800C0850(void);
    void func_800EE7F8(f32 *, f32 *);

    arg0->unk74_30 = 0;
    arg1 = arg1;
    switch (arg1) {
    case 0x11AF:
        func_808001E4_chhumba(arg0);
        return;
    case 0x11A4:
    case 0x11BD:
        func_80800E44_chhumba((u8 *)arg0, 3);
        return;
    case 0x11A5:
    case 0x11A6:
    case 0x11A7:
    case 0x11A8:
    case 0x11A9:
    case 0x11AA:
    case 0x11AB:
    case 0x11AC:
    case 0x11AD:
    case 0x11AE:
    case 0x11B7:
        if (func_80800D2C_chhumba((BtIntPtr)arg0) == 0) {
            func_800C0850();
            func_808001E4_chhumba(arg0);
            func_80800E44_chhumba((u8 *)arg0, 0xC);
        }
        if (arg1 == 0x11B7) {
            func_80090708(0);
            return;
        }
    default:
        return;
    case 0x11B0:
    case 0x11BE:
        if (arg2 != 0) {
            func_80800338_chhumba((u8 *)arg0, 0x11B1, 0xF);
            return;
        }
        func_80800338_chhumba((u8 *)arg0, 0x11B2, 0xF);
        return;
    case 0x11B2:
        func_808001E4_chhumba(arg0);
        func_800EE7F8((f32 *)arg0->actorData, arg0->position);
        func_80800E44_chhumba((u8 *)arg0, 1);
        return;
    case 0x11B1:
        if (func_80800C20_chhumba((u8 *)arg0) != 0) {
            func_808001E4_chhumba(arg0);
        }
        func_808000D4_chhumba(arg0, 0xE, 0x40, NULL);
        func_80800E44_chhumba((u8 *)arg0, 0x12);
        return;
    case 0x11B3:
    case 0x11BF:
        func_808001E4_chhumba(arg0);
        func_80800E44_chhumba((u8 *)arg0, 1);
        return;
    case 0x11B5:
        func_808001E4_chhumba(arg0);
        func_80800E44_chhumba((u8 *)arg0, 0xC);
        return;
    case 0x11B4:
        func_808001E4_chhumba(arg0);
        return;
    case 0x11B6:
        func_808001E4_chhumba(arg0);
        func_80800E44_chhumba((u8 *)arg0, 7);
        break;
    }
}

void func_80801F74_chhumba(Actor *arg0) {
    Prop *_gccubesearch_entrypoint_1(u32, f32[3]);
    s32 _glcutDll_entrypoint_20();
    void _gspropctrl_entrypoint_11(Prop *, f32[3]);
    void _suexpression_entrypoint_12(void *, f32, f32);
    void *_suexpression_entrypoint_7(Actor *arg0, s32 arg1, s16 arg2);
    s32 func_8008FD48();
    s32 func_8008FD70(void);
    s32 func_8009EA2C(void);
    void func_800BF744(s32, s32);
    s32 func_800DA9E4(s32, s32);
    s32 func_800EA05C();
    void func_800FFAB0(Actor *);
    Actor *func_80108474(u32, f32 *, s32);
    extern f32 D_8080272C_chhumba[3];
    Prop *sp24;
    s32 sp20;
    s32 temp_v0;

    sp24 = _gccubesearch_entrypoint_1(0x226, arg0->position);
    sp20 = func_800EA05C();
    arg0->unk74_7 = 0;
    if (sp24 == NULL) {
        func_800FFAB0(arg0);
        return;
    }
    _gspropctrl_entrypoint_11(sp24, (f32 *)&arg0->actorData[4]);
    arg0->unk6C_0 = func_8080071C_chhumba((BtIntPtr)arg0);
    _suexpression_entrypoint_7(arg0, 1, 0x40);
    _suexpression_entrypoint_12(func_80100094(arg0, 1), 0.0f, 0.0f);
    switch (sp20) {
    case 0x135:
        func_800BF744(1, 1);
        break;
    case 0x120:
        func_800BF744(2, 1);
        break;
    case 0x157:
        arg0->unk74_29 = 1;
        break;
    }
    if (sp20 != 0x135) {
        func_80108474(0x381, D_8080272C_chhumba, 0);
    }
    if (_glcutDll_entrypoint_20() != 0) {
        func_80800E44_chhumba((u8 *)arg0, 0x14);
        return;
    }
    temp_v0 = func_8008FD70();
    switch (temp_v0) {
    case 0x1000:
        func_80800E44_chhumba((u8 *)arg0, 0x11);
        return;
    case 0x200:
    case 0x400:
        func_80800E44_chhumba((u8 *)arg0, 0x13);
        return;
    default:
        if (arg0->unk74_29 && func_800DA9E4(0x55, 1) == 0) {
            func_80800E44_chhumba((u8 *)arg0, 2);
            return;
        }
        if (!arg0->unk74_29 && func_800DA9E4(0x8F, 1) == 0) {
            func_80800E44_chhumba((u8 *)arg0, 2);
            return;
        }
        if (func_80800878_chhumba(arg0) != 0) {
            if (func_8008FD48() == 1 && (func_8009EA2C() == 0 || !arg0->unk74_29)) {
                func_80800E44_chhumba((u8 *)arg0, 7);
                return;
            }
            func_80800E44_chhumba((u8 *)arg0, 0xC);
            return;
        }
        func_80800E44_chhumba((u8 *)arg0, 1);
    case 0x10000:
        return;
    }
}

void func_808021F4_chhumba(Actor* arg0) 
{
    if (func_80100094(arg0,1) != 0)
    {
        _suexpression_entrypoint_8(arg0, 1);
    }
}
OSThread *chhumba_entrypoint_0(void)
{
    extern ActorData D_80802738_chhumba;

    return (OSThread *)&D_80802738_chhumba;
}

/* extern */

void func_80802234_chhumba(void *arg0) {
    s32 func_800EA05C();
    if (func_800EA05C() == 0x122) {
        (((Objhumba_arg0 *)arg0)->unk38) = 2.0f;
        return;
    }
    (((Objhumba_arg0 *)arg0)->unk38) = 1.0f;
}

OSThread *chhumba_entrypoint_1(void)
{
    extern ActorData D_80802780_chhumba;

    return (OSThread *)&D_80802780_chhumba;
}
#include "humba_data.inc"
