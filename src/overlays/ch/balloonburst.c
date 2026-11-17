#include "common.h"

typedef union {
    Actor actor;
    struct {
        u8 pad0[0x70];
        u32 pad70_1 : 31;
        u32 flag : 1;
    } balloon;
} BalloonBurstActor;

void func_80800098_chballoonburst(Actor *arg0);
void func_80105834(Actor *);
void func_8010A730(s32, s32);
void func_808008F0_chballoonburst(Actor *arg0);
void func_80800024_chballoonburst(Actor *arg0);
void *func_80107C2C(s32 *, s32, void *, s32, void *);
s32 func_808001FC_chballoonburst(Actor *arg0, int arg1, s32 arg2);
void func_80800F4C_chballoonburst(Actor *arg0);
void func_808010D8_chballoonburst(Actor *arg0, s32 arg1);
void func_80800EDC_chballoonburst(Actor *arg0);
s32 func_8080110C_chballoonburst(void *arg0, s32 arg1, s32 arg2);
void func_808015D4_chballoonburst(Actor *arg0);
void func_801018A4(Actor *, BtIntPtr);
OSThread *func_80108ED0(void);
void func_8080154C_chballoonburst(BalloonBurstActor *arg0);
s32 func_808017A4_chballoonburst(BalloonBurstActor *arg0, s32 arg1, Unk80132ED0 *arg2);

BtFnWord D_80801C40_chballoonburst[] = {
    0x02B1034F, 0x00000001, 0x00000000, (BtFnWord)func_80800098_chballoonburst,
    (BtFnWord)func_80105834, (BtFnWord)func_8010A730, 0x00000000, 0x00000000,
    0x00000000, 0x00400000, (BtFnWord)func_808008F0_chballoonburst, 0x00000000,
    0x054C0000, (BtFnWord)func_80800024_chballoonburst, (BtFnWord)func_80107C2C, 0x80000602,
    (BtFnWord)func_808001FC_chballoonburst, 0x00000000
};

BtFnWord D_80801C88_chballoonburst[] = {
    0x02B1044C, 0xFFFF0001, 0x00000000, (BtFnWord)func_80800F4C_chballoonburst,
    (BtFnWord)func_80105834, (BtFnWord)func_808010D8_chballoonburst, 0x00000000, 0x00000000,
    0x00000000, 0x00400400, (BtFnWord)func_808008F0_chballoonburst, 0x00000000,
    0x054C0000, (BtFnWord)func_80800EDC_chballoonburst, (BtFnWord)func_80107C2C, 0x80000402,
    (BtFnWord)func_8080110C_chballoonburst, 0x00000000
};

BtFnWord D_80801CD0_chballoonburst[] = {
    0x02B20350, 0xFFFF0001, 0x00000000, (BtFnWord)func_808015D4_chballoonburst,
    (BtFnWord)func_80105834, (BtFnWord)func_801018A4, 0x00000000, 0x00000000,
    0x00000000, 0x00000004, 0x00000000, (BtFnWord)func_80108ED0,
    0x00000000, (BtFnWord)func_8080154C_chballoonburst, (BtFnWord)func_80107C2C, 0x80200080,
    (BtFnWord)func_808017A4_chballoonburst, 0x00000000
};

s32 D_80801D18_chballoonburst[] = {
    0x001304FB, 0x00180001, 0x07D01388, 0x00000000
};

s32 D_80801D28_chballoonburst[] = {
    0x0113001D, 0x09E20016, 0x10000015, 0x000000B3,
    0x002B0133, 0x01990022, 0x004C0059, 0x00260033,
    0x000E000A, 0x0014002D, 0x04B005DC, 0x001BFF9C,
    0xFF380000
};

s32 D_80801D5C_chballoonburst[] = {
    0x01130016, 0x10000015, 0x000000CC, 0x002B0133,
    0x01990022, 0x01000100, 0x00660099, 0x000E000A,
    0x0014002D, 0x04B005DC, 0x001BFF9C, 0xFF380027,
    0x00C800C8, 0x01900190, 0x00000000
};

s32 D_80801D98_chballoonburst[] = {
    0x001D09DD, 0x002B0200, 0x02800022, 0x03000380,
    0x08000A00, 0x00150000, 0x00260019, 0x00000007,
    0x00000000
};

s32 D_80801DBC_chballoonburst[] = {
    0x0113001D, 0x09E5001B, 0x00C80320, 0x000B0078,
    0x008C0064, 0x00000023, 0x0099002B, 0x01330166,
    0x00150000, 0x008C0016, 0x1200001E, 0xFFB0FFB0,
    0x00000000
};

s32 D_80801DF0_chballoonburst[] = {
    0x001303ED, 0x000103E8, 0x09C40000
};

s32 D_80801DFC_chballoonburst[] = {
    0x001304FD, 0x000D00F3, 0x010C0015, 0x00000133,
    0x00330001, 0x03E809C4, 0x00000000, 0x00000000,
    0x00000000
};

OSThread *chballoonburst_entrypoint_0(void)
{

    return (OSThread *) D_80801C40_chballoonburst;
}

OSThread *chballoonburst_entrypoint_1(void)
{

    return (OSThread *) D_80801C88_chballoonburst;
}

OSThread *chballoonburst_entrypoint_2(void)
{

    return (OSThread *) D_80801CD0_chballoonburst;
}

/* extern */

void func_80800024_chballoonburst(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    void func_800DA524(s32);
    u32 *sp1C;
    sp1C = func_80100094(arg0, 0U);
    func_800DA524(0);
    func_800DA524(3);
    func_800DA524(2);
    func_800DA524(1);
    arg0->unk6C_0 = 0;
    sp1C[3] = 0;
    _susubgame_entrypoint_0(arg0, sp1C + 6, 0);
    _susubgame_entrypoint_11(0);
}

void func_80800098_chballoonburst(Actor *arg0) {
    u32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, u32, u32, f32 *, s16);
    void _susubgame_entrypoint_5(Actor *, void *, s32, s32, s32);
    s32 _susubgame_entrypoint_9(void);
    s32 func_800CEAD0(s32);
    s32 func_800D24E8(s32, s32, u32);
    int func_800D9154(f32 *, f32);
    f32 func_800DC178(f32, f32);
    BtUIntPtr func_800F54E4(void);
    s32 func_800F7C0C(BtIntPtr arg0, s32 arg1, f32 arg2);
    void func_800F8300();
    void *func_80100094(Actor *, u32);
    void func_80101FDC(Actor *, u32);
    void func_80108B04(Actor *, u32);
    s32 func_80800A7C_chballoonburst(void *, s32 *);
    u8 *volatile sp2C;
    u8 *dialog;
    u8 *resultData;
    s32 dialogId;
    s32 dialogType;
    s32 active;

    sp2C = func_80100094(arg0, 0);
    switch (arg0->unk70_10) {
        case 3:
            func_800D24E8(0xC1, *(s32 *)(sp2C + 4), 0);
            if (func_800D9154(&arg0->unk58, func_800DC178(0.5f, 1.0f))) {
                func_80108B04(arg0, -1);
            }
            active = func_800CEAD0(arg0->unk6C_0);
            resultData = sp2C;
            if (active) {
                *(s32 *)(sp2C + 0x10) = func_80800A7C_chballoonburst(arg0, (s32 *)(resultData += 0x14));
                func_800F8300(func_800F54E4(), 2, 0);
                func_800F7C0C(func_800F54E4(), 0x5F, 0.0f);
                func_80101FDC(arg0, 4);
            }
            return;
        default:
        case 1:
        case 2:
        case 5:
        case 6:
            return;
        case 4:
            if (_susubgame_entrypoint_9()) {
                _susubgame_entrypoint_5(arg0, sp2C + 0x18, 5, 1, 0);
                func_80101FDC(arg0, 5);
                dialog = sp2C;
                dialogId = *(s32 *)(dialog + 0x10);
                dialogType = *(s32 *)(dialog + 0x14);
                _subaddiedialog_entrypoint_11(arg0->unk0, dialogId, dialogType, NULL, 0x22);
            }
            break;
    }
}

s32 func_808001FC_chballoonburst(Actor *arg0, int arg1, s32 arg2) {
    void _capod_entrypoint_19(BtIntPtr arg0);
    u32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, u32, u32, f32 *, s16);
    s32 _susubgame_entrypoint_3(BtIntPtr arg0, u8 *arg1, s32 arg2, s32 arg3);
    s32 func_800D395C(void);
    BtUIntPtr func_800F54E4(void);
    void func_800F82D4(BtIntPtr arg0,s32 arg1);
    void * func_80100094(Actor *arg0, u32 arg1);
    Actor * func_80106790(Unk80132ED0 *arg0);
    void func_808003C4_chballoonburst(Actor *arg0, s32 arg1, s32 arg2);
    s32 func_8080066C_chballoonburst(Actor *arg0, s32 arg1, s32 arg2);
    void func_80800704_chballoonburst(Actor *arg0, s32 arg1, s32 arg2);
    void func_80800790_chballoonburst(Actor *arg0);
    void func_80800BE8_chballoonburst(Actor *arg0, s32 arg1);
    u8 *data;
    s32 dialog;
    Unk80132ED0 *marker;

    data = func_80100094(arg0, 0);
    switch (arg1) {
        default:
            return 0;
        case 0x2E:
            func_808003C4_chballoonburst(arg0, ((s16 *)&arg2)[0], ((s16 *)&arg2)[1]);
            break;
        case 0x2F:
            func_80800704_chballoonburst(arg0, ((s16 *)&arg2)[0], ((s16 *)&arg2)[1]);
            break;
        case 0x30:
            return func_8080066C_chballoonburst(arg0, ((s16 *)&arg2)[0], ((s16 *)&arg2)[1]);
        case 0x3D:
            func_80800BE8_chballoonburst(arg0, arg2);
            break;
        case 0xE:
            if (arg2 == 4) {
                marker = arg0->unk3C;
                if (marker != NULL) {
                    _capod_entrypoint_19((BtIntPtr)func_80106790(marker)->position);
                }
            }
            return 3;
        case 0x32:
            dialog = func_800D395C() ? 0x1118 : 0x10BE;
            _subaddiedialog_entrypoint_11(arg0->unk0, dialog, 0x46, NULL, 0x22);
            func_800F82D4(func_800F54E4(), 2);
            break;
        case 0x57:
            return _susubgame_entrypoint_3((BtIntPtr)arg0, data + 0x18, arg2 & 0xFFFF, (u32)(arg2 & 0xFFFF0000) >> 16);
        case 0x95:
            func_80800790_chballoonburst(arg0);
            break;
    }
    return 1;
}

void func_80800970_chballoonburst(Actor *, s32);
typedef enum flag_e GameFlag;
s32 _gcstatusDll_entrypoint_11(void);

void func_808003C4_chballoonburst(Actor *arg0, s32 arg1, s32 arg2) {
    void _gcfrontend_entrypoint_10(void);
    void _gcfrontend_entrypoint_11(void);
    void _gcfrontend_entrypoint_9(s32 arg0);
    void _gcgoto_entrypoint_1(u32 a0, u32 a1);
    void _glcutDll_entrypoint_6(u32, u32);
    void _plcamera_entrypoint_8(s32 *arg0);
    u32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, u32, u32, f32 *, s16);
    s32 _susubgame_entrypoint_4(void *, BtIntPtr);
    void _susubgame_entrypoint_5(Actor *, void *, s32, s32, s32);
    s32 func_800D395C(void);
    void func_800DA544(GameFlag);
    void func_800F4CC0(BtIntPtr);
    BtUIntPtr func_800F54E4(void);
    int func_800F7C58(BtIntPtr, s32, s32);
    void func_800F82D4(BtIntPtr, s32);
    void *func_80100094(Actor *, u32);
    void func_80101FDC(Actor *, u32);
    void func_80108B04(Actor *, u32);
    u8 *data;
    BtIntPtr player;

    data = func_80100094(arg0, 0);
    switch (arg1) {
        case 0x10BE:
        case 0x1118:
            if (arg2 > 0) {
                func_800DA544(0);
                _subaddiedialog_entrypoint_11(arg0->unk0, 0x10BF, 0x44, NULL, 0x22);
                func_80108B04(arg0, 0);
            } else {
                _plcamera_entrypoint_8(func_800F54E4());
                _susubgame_entrypoint_5(arg0, data + 0x18, 5, 1, 0);
                _subaddiedialog_entrypoint_11(arg0->unk0, 0xCEC, 7, NULL, 0x22);
            }
            _gcfrontend_entrypoint_9(0x68);
            break;
        case 0x10BF:
            _susubgame_entrypoint_5(arg0, data + 0x18, 5, 1, 0);
            _subaddiedialog_entrypoint_11(arg0->unk0, 0xCEC, 7, NULL, 0x22);
            break;
        case 0x10C0:
        case 0x10F8:
        case 0x10F9:
        case 0x10FA:
            _subaddiedialog_entrypoint_11(arg0->unk0, 0xCEB, 0x46, NULL, 0x22);
            break;
        case 0xCEB:
            player = func_800F54E4();
            func_800F82D4(player, 0);
            func_80101FDC(arg0, 6);
            if (func_800D395C() != 0) {
                if (arg2 > 0) {
                    _gcfrontend_entrypoint_11();
                } else {
                    _gcfrontend_entrypoint_10();
                }
            } else {
                if (arg2 > 0) {
                    _gcgoto_entrypoint_1(0xE4, 1);
                } else {
                    func_800F4CC0(player);
                    _susubgame_entrypoint_4(arg0, (BtIntPtr)(data + 0x18));
                }
                func_800F7C58(player, 0x5D, 0);
            }
            break;
        case 0xCEC:
            _susubgame_entrypoint_4(arg0, (BtIntPtr)(data + 0x18));
            func_80800970_chballoonburst(arg0, 0);
            break;
        case 0x10D2:
            _susubgame_entrypoint_4(arg0, (BtIntPtr)(data + 0x18));
            func_800F82D4(func_800F54E4(), 0);
            _glcutDll_entrypoint_6(0xE1, 0x22);
            break;
    }
}

s32 func_8080066C_chballoonburst(Actor *arg0, s32 arg1, s32 arg2) {
    s16 func_800D211C(s32);

    switch (arg1) {
        case 0x10BE:
            return arg2 == 0 ? arg0->unk74_7 : 50;
        case 0x10C0:
        case 0x10F9:
            return func_800D211C(0x80);
        case 0x1118:
            return arg2 == 0 ? arg0->unk74_7 : func_800D211C(0x80);
        default:
            return 0;
    }
}

void func_80800704_chballoonburst(Actor *arg0, s32 arg1, s32 arg2) {
    void func_80108B04(Actor *, u32);
    void func_800DA544(GameFlag);

    switch (arg2) {
        case 1:
            func_80108B04(arg0, 1);
            func_800DA544(3);
            break;
        case 2:
            func_80108B04(arg0, 2);
            func_800DA544(2);
            break;
        case 3:
            func_800DA544(1);
            arg0->unk3C = NULL;
            break;
    }
}

void func_80800790_chballoonburst(Actor *arg0) {
    s32 _chintrotext_entrypoint_2(s32);
    u32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, u32, u32, f32 *, s16);
    s32 _susubgame_entrypoint_10(Actor *, s32, s32, s32);
    void _susubgame_entrypoint_5(Actor *, void *, s32, s32, s32);
    void _susubgame_entrypoint_6(Actor *, void *, s32, s32, BtIntPtr);
    void func_800BF744(s32, s32);
    void func_800F4CEC(BtIntPtr, u32);
    BtUIntPtr func_800F54E4(void);
    int func_800F7C58(BtIntPtr, s32, s32);
    void func_800F82D4(BtIntPtr, s32);
    void func_800F8300();
    void *func_80100094(Actor *, u32);
    void func_80101FDC(Actor *, u32);
    u8 *sp2C;
    BtIntPtr sp28;

    sp2C = func_80100094(arg0, 0);
    sp28 = func_800F54E4();
    func_800BF744(1, 1);
    func_800BF744(2, 0);
    func_800F4CEC(sp28, 0x77);
    if (arg0->unk70_10 == 1) {
        if (_susubgame_entrypoint_10(arg0, 2, 0x320, 0x1AE) != 0) {
            _chintrotext_entrypoint_2(1);
            _susubgame_entrypoint_6(arg0, sp2C + 0x18, 0, 0x20, 0);
        } else {
            _susubgame_entrypoint_5(arg0, sp2C + 0x18, 5, 1, 0);
            _subaddiedialog_entrypoint_11(arg0->unk0, 0xCEC, 5, NULL, 0x22);
            func_800F82D4(sp28, 2);
        }
        func_800F7C58(sp28, 0x5D, 1);
        func_80101FDC(arg0, 2);
        return;
    }
    func_800F8300(sp28, 2, 0);
    _susubgame_entrypoint_5(arg0, sp2C + 0x18, 5, 1, 0);
    _subaddiedialog_entrypoint_11(arg0->unk0, 0xCEB, 0x46, NULL, 0x22);
}

void func_808008F0_chballoonburst(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    s32 func_800CEAA8(s32);
    void func_800CE88C(s32, s32);
    s32 _susubgame_entrypoint_2(void *, BtIntPtr);
    s32 _susubgame_entrypoint_4(void *, BtIntPtr);
    s32 data[2];

    data[1] = func_80100094(arg0, 0);
    if (func_800CEAA8(arg0->unk6C_0) != 0) {
        func_800CE88C(arg0->unk6C_0, 0);
    }
    data[0] = data[1] + 0x18;
    if (_susubgame_entrypoint_2(arg0, data[0]) != 0) {
        _susubgame_entrypoint_4(arg0, data[0]);
    }
}

void func_80800970_chballoonburst(Actor *arg0, s32 arg1) {
    s32 _gcstatusDll_entrypoint_11();
    s32 _subaddiemulti_entrypoint_2();
    void func_800CE88C(s32, s32);
    void func_800CE8D8(s32, f32, s32);
    void func_800D2770(s32, s32);
    void func_800DA524(s32);
    void func_800F7B9C(BtIntPtr, u32);
    s32 func_800F7C0C(BtIntPtr arg0, s32 arg1, f32 arg2);
    u32 func_800FDC28(u32);
    void func_80101FDC(Actor *, u32);
    s32 i;

    _subaddiemulti_entrypoint_2();
    func_80101FDC(arg0, 3);
    func_800D2770(0xC1, 0);
    func_800CE8D8(arg0->unk6C_0, arg0->unk74_7, arg0->unk74_7);
    func_800CE88C(arg0->unk6C_0, 1);
    func_800DA524(0);
    func_800DA524(3);
    func_800DA524(2);
    func_800DA524(1);
    func_800FDC28(0xC);
    for (i = 0; i < _gcstatusDll_entrypoint_11(); i++) {
        func_800F7B9C(i, 0x69);
        func_800F7C0C(i, 0x5F, -1.0f);
    }
}

s32 func_80800A7C_chballoonburst(void *arg0, s32 *arg1) {
    s32 func_800D0A9C(s32, s32);
    s32 func_800D2054(s32, s32, s32);
    s32 func_800D395C(void);
    void func_800FC6B0(u32);
    u32 func_800FDC28(u32);
    void *func_80100094(Actor *, u32);
    void *data;
    s32 count;
    s32 result;
    s32 available;
    s32 choice;
    s32 completed;
    s32 flag;
    s32 mode;
    s32 state;

    data = func_80100094(arg0, 0);
    count = ((s32 *)data)[1];
    flag = func_800D0A9C(0x19, 1);
    mode = func_800D395C();
    state = func_800D2054(0, 0x80, count);
    available = (state == 1) && (flag || mode);
    choice = ((count >= 0x32) != 0) && !flag && !mode;
    completed = choice;
    func_800FDC28(0);
    func_800FC6B0((choice || available) ? 0x16 : 0x17);
    *arg1 = 6;
    if (completed) {
        result = 0x10D2;
    } else if (available) {
        result = 0x10C0;
    } else if (func_800D395C() == 0) {
        if (flag != 0) {
            if (state == 0) {
                result = 0x10FA;
            } else {
                result = 0x10F9;
            }
        } else {
            result = 0x10F8;
        }
    } else {
        result = 0xCEB;
        *arg1 = 0x46;
    }
    return result;
}

void func_80102424(Actor *, s32);

void func_80800BE8_chballoonburst(Actor *arg0, s32 arg1) {
    void _susubgame_entrypoint_6(Actor *, void *, s32, s32, BtIntPtr);
    s32 func_800DA298(s32);
    f32 func_800DC0C0(void);
    f32 func_800DC178(f32, f32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EFA4C(f32 *, f32, f32, f32);
    void *func_80100094(Actor *, u32);
    s32 func_801032B0(Actor *, u16, u16);
    Actor *func_80106790(Unk80132ED0 *);
    Actor *func_80108528(s32, f32 *, s32, Actor **);
    void func_80801B6C_chballoonburst(Actor *);
    f32 position[3];
    s32 choice;
    u32 *data;
    Actor *balloon;
    f32 random;
    s32 mode;
    s32 flag;

    data = func_80100094(arg0, 0U);
    mode = func_800DA298(0);
    if (mode) {
        if (arg0->unk3C) {
            func_800EE7F8(position, func_80106790(arg0->unk3C)->position);
        } else {
            func_800EFA4C(position, 1400.0f, 350.0f, -1400.0f);
        }
    } else {
        position[0] = func_800DC178(-1800.0f, 1800.0f);
        position[1] = func_800DC178(100.0f, 200.0f);
        position[2] = func_800DC178(-1800.0f, 1800.0f);
    }
    balloon = func_80108528(0x350, position, (s32)func_800DC178(0.0f, 360.0f), &arg0);
    random = func_800DC0C0();
    if (random < 0.1666f) {
        choice = 0;
    } else if (random < 0.5f) {
        choice = 1;
    } else {
        choice = 2;
    }
    if (arg1 != -1) {
        choice = arg1;
    }
    balloon->actorData[4] = 2 - choice;
    flag = data[3];
    balloon->unk64_20 = flag == 0;
    switch (choice) {
        case 0:
            func_80102424(balloon, 4);
            func_801032B0(balloon, 0x78C, 0);
            balloon->unk54 = 350.0f;
            break;
        case 1:
            func_80102424(balloon, 3);
            func_801032B0(balloon, 0x78D, 0);
            balloon->unk54 = 300.0f;
            break;
        case 2:
            func_80102424(balloon, 2);
            func_801032B0(balloon, 0x796, 0);
            balloon->unk54 = 250.0f;
            break;
    }
    balloon->unk3C = arg0->unk0;
    balloon->unk6C_0 = arg0->unk6C_0;
    balloon->unk64_19 = data[3];
    if (mode) {
        balloon->unk54 = 50.0f;
        _susubgame_entrypoint_6(arg0, data + 6, 4, 0xA0, 0);
        if (arg1 != -1) {
            if (arg0->unk3C) {
                func_80801B6C_chballoonburst(func_80106790(arg0->unk3C));
            }
        }
        arg0->unk3C = balloon->unk0;
    }
}

/* extern */

void func_80800EDC_chballoonburst(Actor *arg0) {
    void _subaddiemulti_entrypoint_3(s32 arg0);
    void *func_80100094(Actor *, u32);
    void _sumultiscore_entrypoint_3(u8 *arg0);
    s32 _sumultiscore_entrypoint_4(u8 *, s32, s32, s32);
    u8 *data;

    data = func_80100094(arg0, 0U);
    arg0->unk6C_0 = 5;
    ((s32 *)data)[3] = 1;
    _subaddiemulti_entrypoint_3(0xA);
    _sumultiscore_entrypoint_3(data + 0x30);
    _sumultiscore_entrypoint_4(data + 0x30, 6, 0, 1);
}

void func_80800F4C_chballoonburst(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    void _sumultiscore_entrypoint_6(u8 *);
    s32 func_800C954C(void);
    s32 func_800DA298(s32);
    u32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, u32, u32, f32 *, s16);
    void func_80101FDC(Actor *, u32);
    s32 _subaddiefind_entrypoint_9(s32);
    f32 func_800DC178(f32, f32);
    s32 _gcstatusDll_entrypoint_11(void);
    int func_800D9154(f32 *, f32);
    void func_80108B04(Actor *, u32);
    s32 func_800CEAD0(s32);
    void func_80801338_chballoonburst(Actor *);
    s32 _susubgame_entrypoint_9(void);
    void _susubgame_entrypoint_5(Actor *, void *, s32, s32, s32);
    u8 *data;
    s32 state;
    f32 interval;
    u8 *temp;

    temp = func_80100094(arg0, 0U);
    data = temp;
    _sumultiscore_entrypoint_6(data + 0x30);
    state = arg0->unk70_10;
    switch (state) {
    case 1:
        if (func_800C954C() == 0 && func_800DA298(0x6AD) == 0) {
            _subaddiedialog_entrypoint_11(arg0->unk0, 0xCEC, 7, NULL, 0x22);
            func_80101FDC(arg0, 2);
        }
        break;
    case 3:
        if (_subaddiefind_entrypoint_9(0x350) < 8) {
            interval = func_800DC178(0.5f, 1.0f);
            if (func_800D9154(&arg0->unk58, interval / (f32)_gcstatusDll_entrypoint_11())) {
                func_80108B04(arg0, -1);
            }
        }
        if (func_800CEAD0(arg0->unk6C_0)) {
            func_80801338_chballoonburst(arg0);
        }
        break;
    case 4:
        if (_susubgame_entrypoint_9()) {
            _susubgame_entrypoint_5(arg0, data + 0x18, 5, 1, 0);
            _subaddiedialog_entrypoint_11(arg0->unk0, ((s32 *)data)[4], ((s32 *)data)[5], NULL, 0x22);
            func_80101FDC(arg0, 5);
        }
        break;
    }
}

void func_808010D8_chballoonburst(Actor *arg0, s32 arg1) {
    void* func_80100094(Actor*, u32);
    void _sumultiscore_entrypoint_12(BtIntPtr arg0, BtIntPtr arg1, s32 arg2);
    _sumultiscore_entrypoint_12((BtIntPtr)func_80100094(arg0, 0U) + 0x30, arg1, 1);
}

s32 func_8080110C_chballoonburst(void *arg0, s32 arg1, s32 arg2) {
    void func_808011A8_chballoonburst(Actor *, s32, s32);
    s32 func_80801254_chballoonburst(u8 *, s32, s32);
    void func_80801290_chballoonburst(void *);

    switch (arg1) {
    case 0x2E:
        func_808011A8_chballoonburst(arg0, ((s16 *)&arg2)[0], ((s16 *)&arg2)[1]);
        break;
    case 0x30:
        return func_80801254_chballoonburst(arg0, ((s16 *)&arg2)[0], ((s16 *)&arg2)[1]);
    case 0x3D:
        func_80800BE8_chballoonburst(arg0, -1);
        break;
    case 0x95:
        func_80801290_chballoonburst(arg0);
        break;
    default:
        return 0;
    }
    return 1;
}

void func_808011A8_chballoonburst(Actor *arg0, s32 arg1, s32 arg2) {
    void _gcfrontend_entrypoint_10(void);
    s32 _gcstatusDll_entrypoint_11();
    s32 _subaddiemulti_entrypoint_2();
    int func_800F7C58(BtIntPtr, s32, s32);
    void func_80101FDC(Actor *, u32);
    s32 i;

    switch (arg1) {
    case 0xCEC:
        func_80800970_chballoonburst(arg0, 1);
        break;
    case 0x10CF:
    case 0x10D0:
        for (i = 0; i < _gcstatusDll_entrypoint_11(); i++) {
            func_800F7C58(i, 0x5D, 1);
        }
        _subaddiemulti_entrypoint_2();
        func_80101FDC(arg0, 6);
        _gcfrontend_entrypoint_10();
        break;
    }
}

s32 func_80801254_chballoonburst(u8 *arg0, s32 arg1, s32 arg2) {
    void *func_80100094(Actor *, u32);
    if (arg1 == 0x10CF) {
        return (*(s32 *)((s8 *)(func_80100094(arg0, 0U)) + (8))) + 1;
    }
    return 0;
}    typedef struct { u8 pad0[0x72]; u16 unk72; } Objballoonburst_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

void func_80801290_chballoonburst(void *arg0)
{
  s32 _gcstatusDll_entrypoint_11();
  s32 _subaddiemulti_entrypoint_1(s32, s32);
  s32 func_800BF544(s32, s32, s32);
  void func_800BF744(s32, s32);
  void func_800F4CEC(BtIntPtr, u32);
  int func_800F7C58(BtIntPtr, s32, s32);
  s32 var_s0;
  func_800BF744(1, 1);
  func_800BF744(2, 0);
  func_800BF544(0, 0, 0);
  if (((((u16) (((Objballoonburst_arg0 *)arg0)->unk72)) & 0xFFFFFFFFu) >> 0xA) == 1)
  {
    _subaddiemulti_entrypoint_1(2, 0);
  }
  var_s0 = 0;
  if (_gcstatusDll_entrypoint_11() > 0)
  {
    do
    {
      func_800F7C58(var_s0, 0x5D, 1);
      func_800F4CEC(var_s0, 0x77);
      var_s0 += 1;
    }
    while (var_s0 < _gcstatusDll_entrypoint_11());
  }
}

void func_80801338_chballoonburst(Actor *arg0) {
    s32 _gcstatusDll_entrypoint_11();
    s32 _subaddiemulti_entrypoint_1(s32, s32);
    void _sumultiscore_entrypoint_11(u8 *, s32, s32, f32);
    s32 _sumultiscore_entrypoint_8(void *, s32, s32);
    void func_800AA20C(s32, s32);
    void func_800FC6B0(u32);
    void *func_80100094(Actor *, u32);
    void func_80101FDC(Actor *, u32);
    s32 temp;
    s32 scores[8];
    s32 *data;
    s32 max;
    s32 i;
    s32 j;
    s32 k;
    s32 dialog;

    data = func_80100094(arg0, 0);
    max = -1;
    for (j = 0; j < _gcstatusDll_entrypoint_11(); j++) {
        scores[j] = _sumultiscore_entrypoint_8(data + 12, j, 6);
        if (max < scores[j]) {
            max = scores[j];
        }
        func_800AA20C(j, scores[j]);
    }
    for (j = 0; j < _gcstatusDll_entrypoint_11(); j++) {
        if (max == scores[j]) {
            _sumultiscore_entrypoint_11((u8 *)(data + 12), j, 6, 3.0f);
        }
    }
    for (i = 1; i < _gcstatusDll_entrypoint_11(); i++) {
        for (k = i; k > 0 && scores[k - 1] < scores[k]; k--) {
            temp = scores[k];
            scores[k] = scores[k - 1];
            scores[k - 1] = temp;
        }
    }
    func_800FC6B0(0x16);
    k = 0;
    if (scores[0] != scores[1]) {
        while (_sumultiscore_entrypoint_8(data + 12, k, 6) != scores[0]) {
            k++;
        }
        data[2] = k;
        dialog = 0x10CF;
    } else {
        dialog = 0x10D0;
    }
    _subaddiemulti_entrypoint_1(0, 0);
    data[4] = dialog;
    data[5] = 6;
    func_80101FDC(arg0, 4);
}

/* extern */



void func_8080154C_chballoonburst(BalloonBurstActor *arg0) {
    s32 _subaddiefade_entrypoint_2();
    f32 func_800DC178(f32, f32);
    int func_800DC298(f32);
    void func_8010A800(Actor *, s32);
    void func_80801AFC_chballoonburst(BalloonBurstActor *);
    f32 var_f2;

    if (func_800DC298(0.5f) != 0) {
        var_f2 = 1.0f;
    } else {
        var_f2 = -1.0f;
    }
    arg0->actor.unk50 = func_800DC178(100.0f, 200.0f) * var_f2;
    _subaddiefade_entrypoint_2(arg0);
    func_8010A800(&arg0->actor, 2);
    func_80801AFC_chballoonburst(arg0);
}

void func_808015D4_chballoonburst(Actor *arg0) {
    s32 _subaddiefade_entrypoint_0(Actor *);
    f32 func_800136E4(f32);
    s32 func_800CEAD0(s32);
    f32 func_800D8FF8(void);
    s32 func_800D90A4(f32 *);
    s32 func_800DA298(s32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    void func_800FFAB0(Actor *);
    void func_80102FDC(Actor *, f32);
    void func_8010A570(Actor *);
    void func_8010A800(Actor *, s32);
    void func_80801B6C_chballoonburst(Actor *);
    f32 sp3C;
    s32 sp38;
    s32 sp34;
    s32 sp30;
    s32 sp2C;
    f32 scale;

    sp3C = func_800D8FF8();
    sp38 = 0;
    sp34 = func_800DA298(0);
    sp30 = 0;
    sp2C = 1;
    if (func_800CEAD0(arg0->unk6C_0)) {
        func_8010A570(arg0);
    }
    arg0->rotation[1] = func_800136E4(arg0->rotation[1] + arg0->unk50 * sp3C);
    if (arg0->position[1] < 2800.0f) {
        arg0->position[1] += sp3C * arg0->unk54;
    } else {
        sp38 = 1;
    }
    if (_subaddiefade_entrypoint_0(arg0) == 0xFF) {
        func_8010A800(arg0, 0);
    }
    switch (arg0->unk70_10) {
        case 4:
            sp30 = func_800DA298(3);
            break;
        case 3:
            sp30 = func_800DA298(2);
            break;
        case 2:
            sp30 = func_800DA298(1);
            break;
        case 5:
            scale = func_800F10B4(arg0->unk58, 0.0f, 1.4f, 0.2f, 1.0f);
            sp2C = 0;
            func_80102FDC(arg0, scale);
            if (func_800D90A4(&arg0->unk58)) {
                func_8010A570(arg0);
                func_800FFAB0(arg0);
                return;
            }
            break;
    }
    if (sp2C && ((!sp34 && sp38) || (sp34 && sp30))) {
        func_80801B6C_chballoonburst(arg0);
    }
}

s32 func_808017A4_chballoonburst(BalloonBurstActor *arg0, s32 arg1, Unk80132ED0 *arg2) {
    void _chscorepoints_entrypoint_2(s32, BtIntPtr, f32 *, s32);
    BtIntPtr _subaddiemulti_entrypoint_5(Unk80132ED0 *);
    void _sumultiscore_entrypoint_7(u8 *, BtIntPtr, s32, s32);
    void func_800FFAB0(Actor *);
    void *func_80100094(Actor *, u32);
    s32 func_8010114C(BtIntPtr, s32, BtIntPtr);
    s32 func_801015D0(Actor *);
    Actor *func_80106790(Unk80132ED0 *);
    void func_8010A570(Actor *);
    void func_8010DC50(s32);
    void func_8010DCB4(s32);
    int func_8010DD20(u8 *, s32, u8 *);
    void func_80801948_chballoonburst(BalloonBurstActor *);
    Unk80132ED0 **argp;
    Unk80132ED0 *sp28;
    BtIntPtr sp24;
    s32 sp20;
    s32 state;
    s32 *data;

    switch (arg1) {
        case 0x40:
            state = arg0->actor.unk70_10;
            if (state >= 2) {
                sp28 = arg2;
                if (state < 6) {
                sp24 = _subaddiemulti_entrypoint_5(sp28);
                sp20 = arg0->actor.actorData[4] + 1;
                data = func_80100094(func_80106790(arg0->actor.unk3C), 0);
                if (data[3]) {
                    _sumultiscore_entrypoint_7((u8 *)(data + 12), sp24, 6, sp20);
                } else {
                    data[1] += sp20;
                }
                _chscorepoints_entrypoint_2(sp20, sp24, arg0->actor.position, 1);
                func_80801948_chballoonburst(arg0);
                func_8010A570(&arg0->actor);
                func_800FFAB0(&arg0->actor);
                if (*(u16 *)&sp28->unk18 & 1) {
                    func_8010114C((BtIntPtr)sp28, 0x98, 0);
                }
                }
            }
            break;
        case 0x29:
            if (arg0->actor.unk64_20) {
                func_8010DC50(4);
            }
            break;
        case 0x2A:
            if (arg0->actor.unk64_20) {
                func_8010DCB4(4);
            }
            break;
        case 0x1F:
            argp = &arg2;
            sp28 = arg2;
            if (arg0->actor.unk64_20) {
                func_8010DD20((u8 *)arg0, 4, (u8 *)sp28);
            } else {
                func_801015D0(&arg0->actor);
            }
            break;
        default:
            return 0;
    }
    return 1;
}

void func_80801948_chballoonburst(BalloonBurstActor *arg0) {
    s32 func_8010D930(s32, s32, f32 *, s32 *);
    void func_80801A10_chballoonburst(Actor *);
    void func_80801A50_chballoonburst(u8 *, s32, s32);
    void func_80801ABC_chballoonburst(Actor *);

    func_8010D930(1, arg0->balloon.flag, arg0->actor.position, D_80801D18_chballoonburst);
    if (arg0->actor.unk64_20) {
        func_80801A50_chballoonburst((u8 *)arg0, 0x771, 2);
        func_80801A50_chballoonburst((u8 *)arg0, 0x772, 3);
        func_80801A50_chballoonburst((u8 *)arg0, 0x773, 4);
        func_80801ABC_chballoonburst(&arg0->actor);
        func_80801A10_chballoonburst(&arg0->actor);
        return;
    }
    func_80801A50_chballoonburst((u8 *)arg0, 0x771, 2);
    func_80801A50_chballoonburst((u8 *)arg0, 0x772, 2);
    func_80801A50_chballoonburst((u8 *)arg0, 0x773, 2);
}

void func_80801A10_chballoonburst(Actor *arg0) {
    BtIntPtr func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    f32 *temp_a0;

    temp_a0 = arg0->position;
    func_800BBCB8(temp_a0, temp_a0, arg0->scale, 8, D_80801D28_chballoonburst);
}

void func_80801A50_chballoonburst(u8 *arg0, s32 arg1, s32 arg2) {
    BtIntPtr func_800B53A4(s32);
    void func_800BA22C(BtIntPtr, s32);
    void func_800BA670(BtIntPtr, s32);
    BtIntPtr func_800BABB8(BtIntPtr, f32[3], f32[3], f32, s32[]);
    BtIntPtr sp24;
    f32 *temp_a1;
    BtIntPtr temp_v0;

    temp_v0 = func_800B53A4(arg2);
    sp24 = temp_v0;
    func_800BA670(temp_v0, arg1);
    temp_a1 = arg0 + 4;
    func_800BABB8(sp24, temp_a1, temp_a1, (((BalloonBurstActor *)arg0)->actor.scale), D_80801D5C_chballoonburst);
    func_800BA22C(sp24, arg2);
}

void func_80801ABC_chballoonburst(Actor *arg0) {
    BtIntPtr func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    func_800BBCB8(arg0->position, 0, arg0->scale, 1, D_80801D98_chballoonburst);
}

void func_80801AFC_chballoonburst(BalloonBurstActor *arg0) {
    BtIntPtr func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    s32 func_8010D930(s32, s32, f32 *, s32 *);
    if (arg0->actor.unk64_20) {
        func_800BBCB8(arg0->actor.position, NULL, arg0->actor.scale, 0xE, D_80801DBC_chballoonburst);
    }
    func_8010D930(4, arg0->balloon.flag, arg0->actor.position, D_80801DF0_chballoonburst);
}

void func_80801B6C_chballoonburst(Actor *arg0) {
    s32 func_8010D930(s32, s32, f32 *, s32 *);
    if (arg0->unk70_10 != 5) {
        arg0->unk58 = 1.4f;
        func_80102424(arg0, 5);
        func_8010D930(5, (*(s32 *)((s8 *)arg0 + 0x70)) & 1, arg0->position, D_80801DFC_chballoonburst);
    }
}
