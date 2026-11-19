#include "common.h"

void func_8080016C_chhoopswoop(Actor *arg0);
void func_80105834(Actor *);
void func_80101870(Actor *, void *);
void func_80800620_chhoopswoop(Actor *arg0);
void func_80800024_chhoopswoop(void *arg0);
void *func_80107C2C(s32 *, s32, void *, s32, void *);
s32 func_80800320_chhoopswoop(Actor *arg0, int arg1, s32 arg2);
void func_808011DC_chhoopswoop(Actor *arg0);
void func_808013C4_chhoopswoop(Actor *arg0, s32 arg1);
void func_80801130_chhoopswoop(Actor *arg0);
s32 func_808013F8_chhoopswoop(void *arg0, s32 arg1, s32 arg2);
void func_80801838_chhoopswoop(Actor *arg0);
void func_80801A94_chhoopswoop();
void func_808017C4_chhoopswoop(Actor *arg0);
s32 func_80801A10_chhoopswoop(u8 *arg0, s32 arg1, s32 arg2);

BtFnWord D_80801EC0_chhoopswoop[] = {
    0x02B70355, 0x00000001, 0x00000000, (BtFnWord)func_8080016C_chhoopswoop,
    (BtFnWord)func_80105834, (BtFnWord)func_80101870, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, (BtFnWord)func_80800620_chhoopswoop, 0x00000000,
    0x09FC0000, (BtFnWord)func_80800024_chhoopswoop, (BtFnWord)func_80107C2C, 0x80000602,
    (BtFnWord)func_80800320_chhoopswoop, 0x00000000
};

BtFnWord D_80801F08_chhoopswoop[] = {
    0x02B7044A, 0xFFFF0001, 0x00000000, (BtFnWord)func_808011DC_chhoopswoop,
    (BtFnWord)func_80105834, (BtFnWord)func_808013C4_chhoopswoop, 0x00000000, 0x00000000,
    0x00000000, 0x00400400, (BtFnWord)func_80800620_chhoopswoop, 0x00000000,
    0x09FC0000, (BtFnWord)func_80801130_chhoopswoop, (BtFnWord)func_80107C2C, 0x80000402,
    (BtFnWord)func_808013F8_chhoopswoop, 0x00000000
};

BtFnWord D_80801F50_chhoopswoop[] = {
    0x02B80356, 0x00000001, 0x00000000, (BtFnWord)func_80801838_chhoopswoop,
    (BtFnWord)func_80105834, (BtFnWord)func_80801A94_chhoopswoop, 0x00000000, 0x00000000,
    0x00000000, 0x00000804, 0x00000000, 0x00000000,
    0x00440000, (BtFnWord)func_808017C4_chhoopswoop, (BtFnWord)func_80107C2C, 0x80000082,
    (BtFnWord)func_80801A10_chhoopswoop, 0x00000000
};

s32 D_80801F98_chhoopswoop[] = {
    0x001304EE, 0x000D0119, 0x01330016, 0x46500001,
    0x03200640, 0x00000000
};

s32 D_80801FB0_chhoopswoop[] = {
    0x00161000, 0x00150000, 0x00CC002B, 0x00C00100,
    0x0022004C, 0x00590026, 0x0033002D, 0x01900258,
    0x000D0014, 0x001BFCE0, 0xFDA80000
};

s32 D_80801FDC_chhoopswoop[] = {
    0x001304ED, 0x000D0119, 0x01330016, 0x46500001,
    0x03200640, 0x00000000, 0x00000000, 0x00000000,
    0x00000000
};

typedef struct player_state_s PlayerState;     

OSThread *chhoopswoop_entrypoint_0(void)
{

    return (OSThread *) D_80801EC0_chhoopswoop;
}

OSThread *chhoopswoop_entrypoint_1(void)
{

    return (OSThread *) D_80801F08_chhoopswoop;
}

OSThread *chhoopswoop_entrypoint_2(void)
{

    return (OSThread *) D_80801F50_chhoopswoop;
}                typedef struct { u8 pad0[0x6E]; u16 unk6E; u8 pad70[0x2]; u16 unk72; } Objhoopswoop_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

/* extern */

void func_80800024_chhoopswoop(void *arg0) {
    void _susubgame_entrypoint_11(s32 arg0);
    void func_800946C4(PlayerState *, s32);
    void func_800DA524(s32 index);
    PlayerState *func_800F53D0(BtIntPtr);
    BtUIntPtr func_800F54E4(void);
    s32 func_80800094_chhoopswoop(void *);
    func_800946C4(func_800F53D0(func_800F54E4()), 1);
    func_800DA524(0);
    func_800DA524(3);
    func_800DA524(2);
    func_800DA524(1);
    (((Objhoopswoop_arg0 *)arg0)->unk6E) = (u16) ((((Objhoopswoop_arg0 *)arg0)->unk6E) & 0xFE00);
    func_80800094_chhoopswoop(arg0);
    _susubgame_entrypoint_11(0);
}

s32 func_80800094_chhoopswoop(void *arg0) {
    typedef struct {
        BT_BITFIELD_ORDER(s16 rotation : 15, u16 active : 1);
        BT_BITFIELD_ORDER(u16 active : 1, s16 rotation : 15);
        s16 position[3];
        f32 time;
    } Hoop;
    typedef struct {
        s32 count;
        u8 unk4[0x10];
        Hoop hoops[100];
    } HoopData;
    void *func_80100094(Actor *, u32);
    s32 _gccubesearch_entrypoint_9(s32, Prop **, s32);
    void func_800EE814(s16[3], s16[3]);
    BT_NATIVE_ONLY(s32 result = 0;) Prop *props[100];
    HoopData *data;
    HoopData *cursor;
    Prop **prop;
    s16 *position;
    s32 i;

    data = func_80100094(arg0, 0);
    data->count = _gccubesearch_entrypoint_9(0x154, props, 100);
    i = 0;
    if (data->count > 0) {
        cursor = data;
        position = data->hoops[0].position;
        prop = props;
        do {
            func_800EE814(position, (*prop)->position);
            i++;
            cursor->hoops[0].rotation = (*prop)->FlagOrRotation;
            cursor->hoops[0].time = 0.0f;
            cursor->hoops[0].active = 0;
            cursor = (HoopData *)((u8 *)cursor + sizeof(Hoop));
            position += 6;
            prop++;
        } while (i < data->count);
    } BT_NATIVE_ONLY(return result;)
}

void func_8080016C_chhoopswoop(Actor *arg0) {
    typedef struct {
        BT_BITFIELD_ORDER(s16 rotation : 15, u16 active : 1);
        BT_BITFIELD_ORDER(u16 active : 1, s16 rotation : 15);
        s16 position[3];
        f32 time;
    } UpdateHoop;
    typedef struct {
        s32 count;
        s32 score;
        s32 unk8;
        s32 dialog;
        s32 dialogArg;
        UpdateHoop hoops[100];
        u8 game[0x534];
        f32 timer;
    } UpdateHoopData;
    u32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, u32, u32, f32 *, s16);
    void _susubgame_entrypoint_5(Actor *, void *, s32, s32, s32);
    s32 _susubgame_entrypoint_9(void);
    s32 func_800CEAD0(s32);
    s32 func_800D24E8(s32, s32, u32);
    s32 func_800D9078(f32 *);
    s32 func_800D90A4(f32 *);
    int func_800D9154(f32 *, f32);
    f32 func_800DC178(f32, f32);
    BtUIntPtr func_800F54E4(void);
    void func_800F7ECC(BtIntPtr, s32, f32);
    void func_800F8300();
    void *func_80100094(Actor *, u32);
    void func_80101FDC(Actor *, u32);
    void func_80108B04(Actor *, u32);
    s32 func_808007A4_chhoopswoop(void *, s32 *);
    s32 i;
    s32 score;
    UpdateHoopData *data;

    data = func_80100094(arg0, 0);
    switch (arg0->unk70_10) {
        case 1:
        case 2:
        case 6:
            break;
        case 3:
            score = data->score;
            func_800D24E8(0xC2, score, 0);
            for (i = 0; i < data->count; i++) {
                func_800D90A4(&data->hoops[i].time);
            }
            if (func_800D9154(&arg0->unk58, func_800DC178(0.5f, 1.0f))) {
                func_80108B04(arg0, -1);
            }
            if (func_800CEAD0(arg0->unk6C_0)) {
                data->dialog = func_808007A4_chhoopswoop(arg0, &data->dialogArg);
                func_800F7ECC(func_800F54E4(), 3, 0.0f);
                func_800F8300(func_800F54E4(), 2, 0);
                data->timer = 3.0f;
                func_80101FDC(arg0, 4);
            }
            break;
        case 4:
            if (_susubgame_entrypoint_9() || func_800D9078(&data->timer)) {
                _susubgame_entrypoint_5(arg0, data->game, 5, 1, 0);
                func_80101FDC(arg0, 5);
                _subaddiedialog_entrypoint_11(arg0->unk0, data->dialog, data->dialogArg, NULL, 0x22);
            }
            break;
    }
}

s32 func_80800320_chhoopswoop(Actor *arg0, int arg1, s32 arg2) {
    u32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, u32, u32, f32 *, s16);
    s32 _susubgame_entrypoint_3(BtIntPtr arg0, u8 *arg1, s32 arg2, s32 arg3);
    s32 func_800D395C(void);
    BtUIntPtr func_800F54E4(void);
    void func_800F82D4(BtIntPtr arg0,s32 arg1);
    void * func_80100094(Actor *arg0, u32 arg1);
    void func_808004BC_chhoopswoop(Actor *arg0);
    void func_80800910_chhoopswoop(Actor *arg0, s32 arg1, s32 arg2);
    s32 func_80800C04_chhoopswoop(Actor *arg0, s32 arg1, s32 arg2);
    void func_80800C9C_chhoopswoop(Actor *arg0, s32 arg1, s32 arg2);
    void func_80800D28_chhoopswoop(void *arg0, s32 arg1);
    u8 *data;
    s32 dialog;

    data = func_80100094(arg0, 0);
    switch (arg1) {
        case 0x2E:
            func_80800910_chhoopswoop(arg0, ((s16 *)&arg2)[0], ((s16 *)&arg2)[1]);
            break;
        case 0x2F:
            func_80800C9C_chhoopswoop(arg0, ((s16 *)&arg2)[0], ((s16 *)&arg2)[1]);
            break;
        case 0x30:
            return func_80800C04_chhoopswoop(arg0, ((s16 *)&arg2)[0], ((s16 *)&arg2)[1]);
        case 0x3D:
            func_80800D28_chhoopswoop(arg0, arg2);
            break;
        case 0x32:
            dialog = func_800D395C() ? 0x1119 : 0x10C1;
            _subaddiedialog_entrypoint_11(arg0->unk0, dialog, 0x46, arg0->position, 0x22);
            func_800F82D4(func_800F54E4(), 2);
            break;
        case 0x57:
            return _susubgame_entrypoint_3((BtIntPtr)arg0, data + 0x4C4, arg2 & 0xFFFF, (u32)(arg2 & 0xFFFF0000) >> 16);
        case 0x95:
            func_808004BC_chhoopswoop(arg0);
            break;
        default:
            return 0;
    }
    return 1;
}

void func_808004BC_chhoopswoop(Actor *arg0) {
    s32 _chintrotext_entrypoint_2(s32);
    u32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, u32, u32, f32 *, s16);
    s32 _susubgame_entrypoint_10(Actor *, s32, s32, s32);
    void _susubgame_entrypoint_5(Actor *, void *, s32, s32, s32);
    void _susubgame_entrypoint_6(Actor *, void *, s32, s32, BtIntPtr);
    void func_800A16BC(s32);
    s32 func_800BF744(s32, s32);
    s32 func_800D395C(void);
    BtUIntPtr func_800F54E4(void);
    void func_800F82D4(BtIntPtr, s32);
    void func_800F8300();
    void *func_80100094(Actor *, u32);
    void func_80101FDC(Actor *, u32);
    u8 *sp2C;

    sp2C = func_80100094(arg0, 0);
    func_800BF744(1, 0);
    func_800BF744(2, 1);
    if (func_800D395C() != 0) {
        func_800A16BC(1);
    }
    if (arg0->unk70_10 == 1) {
        if (_susubgame_entrypoint_10(arg0, 1, 0x320, 0x1AD) != 0) {
            _chintrotext_entrypoint_2(1);
            _susubgame_entrypoint_6(arg0, sp2C + 0x4C4, 0, 0x20, 0);
        } else {
            _susubgame_entrypoint_5(arg0, sp2C + 0x4C4, 5, 1, 0);
            _subaddiedialog_entrypoint_11(arg0->unk0, 0xCEC, 7, arg0->position, 0x22);
            func_800F82D4(func_800F54E4(), 2);
        }
        func_80101FDC(arg0, 2);
        return;
    }
    func_800F8300(func_800F54E4(), 2, 0);
    _susubgame_entrypoint_5(arg0, sp2C + 0x4C4, 5, 1, 0);
    _subaddiedialog_entrypoint_11(arg0->unk0, 0xCEB, 0x46, NULL, 0x22);
}

void func_80800620_chhoopswoop(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    s32 func_800CEAA8(s32);
    void func_800CE88C(s32, s32);
    BT_IDO_ONLY(s32) BT_NATIVE_ONLY(u8) _susubgame_entrypoint_2(void *, BtIntPtr);
    s32 _susubgame_entrypoint_4(void *, BtIntPtr);
    s32 data[2];

    data[1] = func_80100094(arg0, 0);
    if (func_800CEAA8(arg0->unk6C_0) != 0) {
        func_800CE88C(arg0->unk6C_0, 0);
    }
    data[0] = data[1] + 0x4C4;
    if (_susubgame_entrypoint_2(arg0, data[0]) != 0) {
        _susubgame_entrypoint_4(arg0, data[0]);
    }
}

void func_808006A0_chhoopswoop(Actor *arg0) {
    typedef struct {
        BT_BITFIELD_ORDER(s16 rotation : 15, u16 active : 1);
        BT_BITFIELD_ORDER(u16 active : 1, s16 rotation : 15);
        s16 position[3];
        f32 time;
    } Hoop;
    typedef struct {
        s32 count;
        u8 unk4[0x10];
        Hoop hoops[100];
    } HoopData;
    void *func_80100094(Actor *, u32);
    void _subaddiemulti_entrypoint_2(void);
    void func_80101FDC(Actor *, u32);
    void func_800D2770(s32, s32);
    void func_800CE8D8(s32, f32, s32);
    void func_800CE88C(s32, s32);
    void func_800DA524(s32 index);
    u32 func_800FDC28(u32);
    HoopData *data;
    f32 duration;
    f32 value;
    HoopData *temp;
    HoopData *cursor;
    s32 i;

    data = func_80100094(arg0, 0); value = arg0->unk74_7; duration = value; _subaddiemulti_entrypoint_2();
    i = 0;
    if (data->count > 0) {
        cursor = data;
        do {
            cursor->hoops[0].time = 0.0f;
            i++;
            cursor->hoops[0].active = 0;
            cursor = (HoopData *)((u8 *)cursor + sizeof(Hoop));
        } while (i < data->count);
    }
    func_80101FDC(arg0, 3);
    func_800D2770(0xC2, 0);
    func_800CE8D8(arg0->unk6C_0, duration, (s32)duration);
    func_800CE88C(arg0->unk6C_0, 1);
    func_800DA524(0);
    func_800FDC28(0xC);
}

s32 func_808007A4_chhoopswoop(void *arg0, s32 *arg1) {
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
    flag = func_800D0A9C(0x15, 1);
    mode = func_800D395C();
    state = func_800D2054(0, 0x81, count);
    available = (state == 1) && (flag || mode);
    choice = ((count >= 0x1E) != 0) && !flag && !mode;
    completed = choice;
    func_800FDC28(0);
    func_800FC6B0((choice || available) ? 0x16 : 0x17);
    *arg1 = 6;
    if (completed) {
        result = 0x10D1;
    } else if (available) {
        result = 0x10C3;
    } else if (func_800D395C() == 0) {
        if (flag != 0) {
            if (state == 0) {
                result = 0x10F7;
            } else {
                result = 0x10F6;
            }
        } else {
            result = 0x10F5;
        }
    } else {
        result = 0xCEB;
        *arg1 = 0x46;
    }
    return result;
}

void func_80800910_chhoopswoop(Actor *arg0, s32 arg1, s32 arg2) {
    void _gcfrontend_entrypoint_10(void);
    void _gcfrontend_entrypoint_11(void);
    void _gcfrontend_entrypoint_9(s32 arg0);
    void _gcgoto_entrypoint_1(u32 a0, u32 a1);
    void _glcutDll_entrypoint_6(u32, u32);
    void _plcamera_entrypoint_8(s32 *arg0);
    u32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, u32, u32, f32 *, s16);
    void _subaddiefade_entrypoint_3(Actor *);
    Actor *_subaddiefind_entrypoint_2(s32, BtIntPtr);
    s32 _susubgame_entrypoint_4(void *, BtIntPtr);
    void _susubgame_entrypoint_5(Actor *, void *, s32, s32, s32);
    void _susubgame_entrypoint_6(Actor *, void *, s32, s32, BtIntPtr);
    void func_800A16BC(s32);
    s32 func_800D395C(void);
    void func_800DA544(s32);
    BtUIntPtr func_800F54E4(void);
    void func_800F82D4(BtIntPtr, s32);
    void *func_80100094(Actor *, u32);
    void func_80101FDC(Actor *, u32);
    void func_80108B04(Actor *, u32);
    void func_8010A570(Actor *);
    u8 *data;
    Actor *other;

    data = func_80100094(arg0, 0);
    switch (arg1) {
        case 0x10C1:
        case 0x1119:
            if (arg2 > 0) {
                func_800DA544(0);
                _susubgame_entrypoint_6(arg0, data + 0x4C4, 7, 0x20, 0);
                _subaddiedialog_entrypoint_11(arg0->unk0, 0x10C2, 0x44, 0, 0x22);
                func_80108B04(arg0, 0);
            } else {
                _plcamera_entrypoint_8(func_800F54E4());
                _susubgame_entrypoint_5(arg0, data + 0x4C4, 5, 1, 0);
                _subaddiedialog_entrypoint_11(arg0->unk0, 0xCEC, 7, 0, 0x22);
            }
            func_800DA544(0x1AD);
            _gcfrontend_entrypoint_9(0x67);
            break;
        case 0x10C2:
            _plcamera_entrypoint_8(func_800F54E4());
            _susubgame_entrypoint_5(arg0, data + 0x4C4, 5, 1, 0);
            _subaddiedialog_entrypoint_11(arg0->unk0, 0xCEC, 7, 0, 0x22);
            break;
        case 0x10C3:
        case 0x10F5:
        case 0x10F6:
        case 0x10F7:
            _subaddiedialog_entrypoint_11(arg0->unk0, 0xCEB, 0x46, 0, 0x22);
            break;
        case 0xCEB:
            func_800F82D4(func_800F54E4(), 0);
            func_80101FDC(arg0, 6);
            if (func_800D395C() != 0) {
                func_800A16BC(0);
                if (arg2 > 0) {
                    _gcfrontend_entrypoint_11();
                } else {
                    _gcfrontend_entrypoint_10();
                }
            } else if (arg2 > 0) {
                _gcgoto_entrypoint_1(0xE5, 1);
            } else {
                other = _subaddiefind_entrypoint_2(0x21A, 0);
                if (other != NULL) {
                    _subaddiefade_entrypoint_3(other);
                    func_8010A570(other);
                }
                _susubgame_entrypoint_4(arg0, (BtIntPtr)(data + 0x4C4));
            }
            break;
        case 0xCEC:
            _susubgame_entrypoint_4(arg0, (BtIntPtr)(data + 0x4C4));
            func_808006A0_chhoopswoop(arg0);
            break;
        case 0x10D1:
            _susubgame_entrypoint_4(arg0, (BtIntPtr)(data + 0x4C4));
            func_800F82D4(func_800F54E4(), 0);
            _glcutDll_entrypoint_6(0xE1, 0x21);
            break;
    }
}

s32 func_80800C04_chhoopswoop(Actor *arg0, s32 arg1, s32 arg2) {
    s16 func_800D211C(s32);

    switch (arg1) {
        case 0x10C1:
            return arg2 == 0 ? arg0->unk74_7 : 30;
        case 0x10C3:
        case 0x10F6:
            return func_800D211C(0x81);
        case 0x1119:
            return arg2 == 0 ? arg0->unk74_7 : func_800D211C(0x81);
        default:
            return 0;
    }
}

void func_80800C9C_chhoopswoop(Actor *arg0, s32 arg1, s32 arg2) {
    void func_80108B04(Actor *, u32);
#ifndef BT_NATIVE
    void func_800DA544(GameFlag);
#endif

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

void func_80800D28_chhoopswoop(void *arg0, s32 arg1) {
    typedef struct {
        BT_BITFIELD_ORDER(s32 kind : 15, u32 used : 1);
        BT_BITFIELD_ORDER(u32 used : 1, s32 kind : 15);
        s16 position[3];
        f32 timer;
    } Hoop;
    typedef struct {
        s32 count;
        u8 pad[16];
        Hoop hoops[1];
    } HoopData;
    typedef struct {
        void *marker;
        u8 pad04[4];
        f32 y;
        u8 pad0C[32];
        s32 index;
        u8 pad30[12];
        s32 parent;
        u8 pad40[24];
        f32 scale;
        u8 pad5C[16];
        BT_BITFIELD_ORDER(u32 flags : 23, u32 id : 9);
        BT_BITFIELD_ORDER(u32 id : 9, u32 flags : 23);
    } HoopActor;
    s32 func_800DA298(s32);
    void *func_80100094(Actor *, u32);
    s32 func_800DC128(s32, s32);
    void func_800EFA4C(f32 *, f32, f32, f32);
    void func_800EE88C(f32 *, s16 *);
    void *func_80108474(s32, f32 *, s32);
    void _subaddiefade_entrypoint_2(void *arg0);
    f32 func_800DC0C0(void);
    s32 func_800D3948(void);
    s32 func_80103140(Actor *actor,u32 id,u16 palette);
    void func_80102424(void *, s32);
    s32 func_8010114C(BtIntPtr, s32, BtIntPtr);
    f32 position[3];
    f32 random;
    HoopData *data;
    s32 index;
    s32 i;
    s32 found;
    HoopActor *actor;
    s32 height;
    s32 special;
    s32 *actorData;
    s32 model;
    s32 variant;

    special = func_800DA298(0);
    data = func_80100094(arg0, 0);
    index = func_800DC128(0, data->count);
    if (special) {
        func_800EFA4C(position, 1400.0f, 260.0f, -1400.0f);
        index = -1;
    } else {
        found = 0;
        for (i = 0; i < data->count; i++) {
            if (data->hoops[index].timer == 0.0f && !data->hoops[index].used) {
                found = 1;
                break;
            }
            index++;
            if (index >= data->count) {
                index = 0;
            }
        }
        if (!found) {
            return;
        }
        func_800EE88C(position, data->hoops[index].position);
    }
    actor = func_80108474(0x356, position, data->hoops[index].kind);
    actorData = func_80100094(actor, 0);
    _subaddiefade_entrypoint_2(actor);
    random = func_800DC0C0();
    if (random < 0.1666f) {
        variant = 0;
    } else if (random < 0.5f) {
        variant = 1;
    } else {
        variant = 2;
    }
    if (arg1 != -1) {
        variant = arg1;
    }
    actorData[16] = 2 - variant;
    switch (variant) {
        case 0:
            model = func_800D3948() ? 0x958 : 0x878;
            func_80103140(actor, (u16)model, *(u16 *)((u8 *)((HoopActor *)arg0)->marker + 0x16));
            func_80102424(actor, 4);
            height = 100;
            actor->scale = 10.0f;
            break;
        case 1:
            model = func_800D3948() ? 0x957 : 0x877;
            func_80103140(actor, (u16)model, *(u16 *)((u8 *)((HoopActor *)arg0)->marker + 0x16));
            func_80102424(actor, 3);
            height = 150;
            actor->scale = 10.0f;
            break;
        case 2:
            model = func_800D3948() ? 0x956 : 0x7A1;
            func_80103140(actor, (u16)model, *(u16 *)((u8 *)((HoopActor *)arg0)->marker + 0x16));
            func_80102424(actor, 2);
            height = 200;
            actor->scale = 10.0f;
            break;
    }
    if (!special) {
        actor->y = height + 80.0f;
    }
    actor->parent = (BtIntPtr)((HoopActor *)arg0)->marker;
    actor->index = index;
    actor->id = ((HoopActor *)arg0)->id;
    if (index != -1) {
        data->hoops[index].used = 1;
    }
    if (special) {
        actor->scale = 60.0f;
        if (((HoopActor *)arg0)->parent) {
            func_8010114C(((HoopActor *)arg0)->parent, 0x4F, 1);
        }
        ((HoopActor *)arg0)->parent = (BtIntPtr)actor->marker;
    }
}

void func_80801130_chhoopswoop(Actor *arg0) {
    BT_IDO_ONLY(s32) BT_NATIVE_ONLY(u8) _gcstatusDll_entrypoint_11();
    void _subaddiemulti_entrypoint_3(s32 arg0);
    void _sumultiscore_entrypoint_3(u8 *arg0);
    s32 _sumultiscore_entrypoint_4(u8 *, s32, s32, s32);
    void func_800946C4(PlayerState *, s32);
    PlayerState *func_800F53D0(BtIntPtr);
    void *func_80100094(Actor *, u32);
    u8 *data;
    u8 *score;
    s32 i;

    data = func_80100094(arg0, 0);
    arg0->unk6C_0 = 5;
    func_80800094_chhoopswoop(arg0);
    _subaddiemulti_entrypoint_3(0xA);
    score = data + 0x4DC;
    _sumultiscore_entrypoint_3(score);
    _sumultiscore_entrypoint_4(score, 7, 0, 1);
    for (i = 0; i < _gcstatusDll_entrypoint_11(); i++) {
        func_800946C4(func_800F53D0(i), 1);
    }
}

void func_808011DC_chhoopswoop(Actor *arg0) {
    typedef struct {
        BT_BITFIELD_ORDER(s16 rotation : 15, u16 active : 1);
        BT_BITFIELD_ORDER(u16 active : 1, s16 rotation : 15);
        s16 position[3];
        f32 time;
    } Hoop;
    typedef struct {
        s32 count;
        u8 unk4[8];
        s32 dialog;
        s32 dialogFlags;
        Hoop hoops[100];
        u8 subgame[0x18];
        u8 score[0x51C];
        f32 timer;
    } HoopData;
    BT_IDO_ONLY(s32) BT_NATIVE_ONLY(u8) _gcstatusDll_entrypoint_11();
    u32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, u32, u32, f32 *, s16);
    s32 _subaddiefind_entrypoint_9(s32);
    void _sumultiscore_entrypoint_6(u8 *);
    void _susubgame_entrypoint_5(Actor *, void *, s32, s32, s32);
    s32 _susubgame_entrypoint_9(void);
    s32 func_800C954C(void);
    s32 func_800CEAD0(s32);
    s32 func_800D9078(f32 *);
    s32 func_800D90A4(f32 *);
    int func_800D9154(f32 *, f32);
    s32 func_800DA298(s32);
    f32 func_800DC178(f32, f32);
    void *func_80100094(Actor *, u32);
    void func_80101FDC(Actor *, u32);
    void func_80108B04(Actor *, u32);
    void func_808015A4_chhoopswoop(Actor *);
    HoopData *data;
    int i;
    f32 *time;
    f32 interval;

    data = func_80100094(arg0, 0);
    _sumultiscore_entrypoint_6(data->score);
    switch (arg0->unk70_10) {
    case 1:
        if (!func_800C954C() && !func_800DA298(0x6AD)) {
            _subaddiedialog_entrypoint_11(arg0->unk0, 0xCEC, 7, NULL, 0x22);
            func_80101FDC(arg0, 2);
        }
        return;
    case 3:
        i = 0;
        time = &data->hoops[0].time;
        if (data->count > 0) {
            do {
                func_800D90A4(time);
                time += 3;
                i++;
            } while (i < data->count);
        }
        if (_subaddiefind_entrypoint_9(0x356) < 5) {
            interval = func_800DC178(0.5f, 1.0f);
            if (func_800D9154(&arg0->unk58, interval / (f32)_gcstatusDll_entrypoint_11())) {
                func_80108B04(arg0, -1);
            }
        }
        if (func_800CEAD0(arg0->unk6C_0)) {
            func_808015A4_chhoopswoop(arg0);
        }
        return;
    case 4:
        if (_susubgame_entrypoint_9() || func_800D9078(&data->timer)) {
            _susubgame_entrypoint_5(arg0, data->subgame, 5, 1, 0);
            _subaddiedialog_entrypoint_11(arg0->unk0, data->dialog, data->dialogFlags, NULL, 0x22);
            func_80101FDC(arg0, 5);
        }
    }
}

void func_808013C4_chhoopswoop(Actor *arg0, s32 arg1) {
    void *func_80100094(Actor *, u32);
    void _sumultiscore_entrypoint_12(BtIntPtr arg0, BtIntPtr arg1, s32 arg2);
    _sumultiscore_entrypoint_12((BtIntPtr)func_80100094(arg0, 0U) + 0x4DC, arg1, 1);
}

s32 func_808013F8_chhoopswoop(void *arg0, s32 arg1, s32 arg2) {
    void func_80801494_chhoopswoop(Actor *, s32, s32);
    s32 func_80801500_chhoopswoop(u8 *, s32, s32);
    void func_8080153C_chhoopswoop(void *);

    switch (arg1) {
    case 0x2E:
        func_80801494_chhoopswoop(arg0, ((s16 *)&arg2)[0], ((s16 *)&arg2)[1]);
        break;
    case 0x30:
        return func_80801500_chhoopswoop(arg0, ((s16 *)&arg2)[0], ((s16 *)&arg2)[1]);
    case 0x3D:
        func_80800D28_chhoopswoop(arg0, -1);
        break;
    case 0x95:
        func_8080153C_chhoopswoop(arg0);
        break;
    default:
        return 0;
    }
    return 1;
}

void func_80801494_chhoopswoop(Actor *arg0, s32 arg1, s32 arg2) {
    void _gcfrontend_entrypoint_10(void);
    void _subaddiemulti_entrypoint_2(void);
    void func_80101FDC(Actor *, u32);
    switch (arg1) {
    case 0xCEC:
        func_808006A0_chhoopswoop(arg0);
        return;
    case 0x10CD:
    case 0x10CE:
        _subaddiemulti_entrypoint_2();
        func_80101FDC(arg0, 6);
        _gcfrontend_entrypoint_10();
        return;
    }
}

s32 func_80801500_chhoopswoop(u8 *arg0, s32 arg1, s32 arg2) {
    void *func_80100094(Actor *, u32);
    if (arg1 == 0x10CD) {
        return (*(s32 *)((s8 *)(func_80100094(arg0, 0U)) + (8))) + 1;
    }
    return 0;
}

void func_8080153C_chhoopswoop(void *arg0)
{
  s32 _subaddiemulti_entrypoint_1(s32, s32);
  s32 func_800BF544(s32, s32, s32);
  s32 func_800BF744(s32, s32);
  func_800BF744(1, 0);
  func_800BF744(2, 1);
  func_800BF544(0, 0, 0);
  if ((((((((((u16) (((Objhoopswoop_arg0 *)arg0)->unk72)) & 0xFFFFFFFFu) & 0xFFFFFFFFu) & 0xFFFFFFFFu) & 0xFFFFFFFFu) & 0xFFFFFFFFu) & 0xFFFFFFFFu) >> 0xA) == 1)
  {
    _subaddiemulti_entrypoint_1(0, 0);
  }
}

void func_808015A4_chhoopswoop(Actor *arg0) {
    BT_IDO_ONLY(s32) BT_NATIVE_ONLY(u8) _gcstatusDll_entrypoint_11();
    s32 _subaddiemulti_entrypoint_1(s32, s32);
    void _sumultiscore_entrypoint_11(u8 *, s32, s32, f32);
    BT_IDO_ONLY(s32) BT_NATIVE_ONLY(s16) _sumultiscore_entrypoint_8(void *, s32, s32);
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
        scores[j] = _sumultiscore_entrypoint_8(data + 311, j, 7);
        if (max < scores[j]) {
            max = scores[j];
        }
        func_800AA20C(j, scores[j]);
    }
    for (j = 0; j < _gcstatusDll_entrypoint_11(); j++) {
        if (max == scores[j]) {
            _sumultiscore_entrypoint_11((u8 *)(data + 311), j, 7, 3.0f);
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
    if (scores[0] != scores[1]) {
        for (k = 0; _sumultiscore_entrypoint_8(data + 311, k, 7) != scores[0]; k++) {
        }
        data[2] = k;
        dialog = 0x10CD;
    } else {
        dialog = 0x10CE;
    }
    _subaddiemulti_entrypoint_1(0, 0);
    data[3] = dialog;
    data[4] = 6;
    ((f32 *)data)[638] = 3.0f;
    func_80101FDC(arg0, 4);
}

void func_808017C4_chhoopswoop(Actor *arg0) {
    f32 func_800DC178(f32, f32);
    int func_800DC298(f32);
    void func_80801D8C_chhoopswoop(u8 *);
    f32 var_f2;

    if (func_800DC298(0.5f) != 0) {
        var_f2 = 1.0f;
    } else {
        var_f2 = -1.0f;
    }
    arg0->unk50 = func_800DC178(50.0f, 100.0f) * var_f2;
    func_80801D8C_chhoopswoop(arg0);
}

void func_80801838_chhoopswoop(Actor *arg0) {
    f32 func_800D8FF8(void);
    s32 func_800DA298(s32);
    s32 _subaddiefade_entrypoint_0(Actor *);
    void func_8010A800(Actor *, s32);
    s32 func_800D90A4(f32 *);
    s32 func_800CEAD0(s32);
    f32 func_800136E4(f32);
    void func_800FFAB0(Actor *);
    s32 func_80801AB4_chhoopswoop(Actor *);
    void func_80801DCC_chhoopswoop(Actor *);
    s32 func_80801A10_chhoopswoop(u8 *, s32, s32);
    f32 sp34;
    s32 sp30;
    s32 sp2C;
    s32 sp28;
    s32 sp24;

    sp34 = func_800D8FF8();
    sp2C = func_800DA298(0);
    sp28 = 0;
    sp24 = 1;
    func_8010A800(arg0, _subaddiefade_entrypoint_0(arg0) == 0xFF ? 1 : 0);
    sp30 = func_800D90A4(&arg0->unk58);
    if (!sp2C && func_800CEAD0(arg0->unk6C_0)) {
        arg0->unk64_20 = 1;
    }
    switch (arg0->unk70_10) {
        case 4:
            sp28 = func_800DA298(3);
            break;
        case 3:
            sp28 = func_800DA298(2);
            break;
        case 2:
            sp28 = func_800DA298(1);
            break;
        case 5:
            sp24 = 0;
            if (_subaddiefade_entrypoint_0(arg0) == 0) {
                func_80801DCC_chhoopswoop(arg0);
                func_800FFAB0(arg0);
                return;
            }
            break;
    }
    if (!sp2C) {
        func_80801AB4_chhoopswoop(arg0);
    }
    arg0->rotation[2] = func_800136E4(arg0->rotation[2] + arg0->unk50 * sp34);
    if (sp24) {
        if ((!sp2C && (sp30 != 0 || arg0->unk64_20)) || (sp2C && sp28)) {
            func_80801A10_chhoopswoop((u8 *)arg0, 0x4F, sp30 != 0 && !sp2C);
        }
    }
}

s32 func_80801A10_chhoopswoop(u8 *arg0, s32 arg1, s32 arg2)
{
  s32 _subaddiefade_entrypoint_5(u8 *);
  u8 *new_var;
  void func_80101FDC(Actor *, u32);
  s32 func_8010D930(s32, s32, u8 *, s32 *);

  if (arg1 == 0x4F)
  {
    if (((((((((((u16) (*((u16 *) (((s8 *) arg0) + 0x72)))) & 0xFFFFFFFFu) & 0xFFFFFFFFu) & 0xFFFFFFFFu) & 0xFFFFFFFFu) & 0xFFFFFFFFu) & 0xFFFFFFFFu) & 0xFFFFFFFFu) >> 0xA) != 5)
    {
      if (arg2 != 0)
      {
        func_8010D930(5, (*((s32 *) (((s8 *) arg0) + 0x70))) & 1, arg0 + 4, D_80801F98_chhoopswoop);
      }
      _subaddiefade_entrypoint_5(arg0);
      func_80101FDC(new_var = arg0, 5);
    }
    return 1;
  }
  return 0;
}

void func_80801A94_chhoopswoop(Actor *arg0, void *arg1)
{
    func_80101870(arg0, arg1);
}

s32 func_80801AB4_chhoopswoop(Actor *arg0) {
    typedef struct {
        s32 side[8];
        s32 initialized[8];
        s32 points;
    } HoopData;
    typedef struct {
        s32 count;
        s32 score;
        u8 pad8[0x4D4];
        u8 multiplayer[1];
    } ParentData;
    void _chscorepoints_entrypoint_2(s32, BtIntPtr, f32 *, s32);
    BT_IDO_ONLY(s32) BT_NATIVE_ONLY(u8) _gcstatusDll_entrypoint_11();
    void _sumultiscore_entrypoint_7(u8 *, BtIntPtr, s32, s32);
    s32 func_800D3948(void);
    f32 func_800EEAA4(f32 *, f32 *);
    f32 func_800EEFD4(f32 *);
    void func_800EF3DC(f32 *, f32 *);
    void func_800EF934(f32 *, f32 *, f32);
    void func_800EFA4C(f32 *, f32, f32, f32);
    void func_800F5A00(BtIntPtr, f32 *);
    s32 func_800F6438(BtUIntPtr);
    void *func_80100094(Actor *, u32);
    f32 func_80103F38(Actor *, f32 *);
    Actor *func_80106790(Unk80132ED0 *);
    void func_80801D20_chhoopswoop(BtIntPtr, s32, s32);
    f32 position[3];
    s32 side;
    s32 i;
    f32 radius;
    ParentData *parent;
    HoopData *data;
    f32 forward[3];
    s32 points;

    parent = func_80100094(func_80106790(arg0->unk3C), 0);
    radius = func_80103F38(arg0, NULL);
    if (arg0->unk64_20) {
        return 0;
    }
    data = func_80100094(arg0, 0);
    i = 0;
    if (i < _gcstatusDll_entrypoint_11()) {
      do {
        points = i;
        if (func_800F6438(points)) {
            func_800F5A00(points, position);
            position[1] += 50.0f;
            func_800EF3DC(position, arg0->position);
            if (data->initialized[points] && func_800EEFD4(position) < radius * radius) {
                func_800EFA4C(forward, 0, 0, 1);
                func_800EF934(forward, forward, arg0->rotation[1]);
                if (func_800EEAA4(position, forward) >= 0.0f) {
                    side = 1;
                } else {
                    side = -1;
                }
                if (side == -data->side[points]) {
                    points = data->points + 1;
                    if (func_800D3948()) {
                        _sumultiscore_entrypoint_7(parent->multiplayer, i, 7, points);
                    } else {
                        parent->score += points;
                        func_80801D20_chhoopswoop((BtIntPtr)arg0, 0x9E2, 10);
                    }
                    arg0->unk64_20 = 1;
                    _chscorepoints_entrypoint_2(points, i, arg0->position, 1);
                    return 1;
                }
            }
            data->initialized[points] = 1;
            data->side[points] = side;
        }
        i++;
      } while (i < _gcstatusDll_entrypoint_11());
    }
    return 0;
}

void func_80801D20_chhoopswoop(BtIntPtr arg0, s32 arg1, s32 arg2) {
    BtIntPtr func_800B53A4(s32);
    s32 func_800BA22C(BtIntPtr, s32);
    BT_IDO_ONLY(s32 func_800BA3FC(BtIntPtr, s32);) BT_NATIVE_ONLY(void func_800BA3FC(BtIntPtr, s32);)
    BtIntPtr func_800BABB8(BtIntPtr, BtIntPtr, BtIntPtr, s32, s32 *);
    BtIntPtr sp24;
    BtIntPtr temp_a1;
    BtIntPtr temp_v0;

    temp_v0 = func_800B53A4(arg2);
    temp_a1 = arg0 + 4;
    sp24 = temp_v0;
    func_800BABB8(temp_v0, temp_a1, temp_a1, 0x3F800000, D_80801FB0_chhoopswoop);
    func_800BA3FC(sp24, arg1);
    func_800BA22C(sp24, arg2);
}

void func_80801D8C_chhoopswoop(u8 *arg0) {
    s32 func_8010D930(s32, s32, u8 *, s32 *);
    func_8010D930(4, (*(s32 *)((s8 *)(arg0) + (0x70))) & 1, arg0 + 4, D_80801FDC_chhoopswoop);
}

void func_80801DCC_chhoopswoop(Actor *arg0) {
    typedef struct {
        BT_BITFIELD_ORDER(s32 kind : 15, u32 used : 1);
        BT_BITFIELD_ORDER(u32 used : 1, s32 kind : 15);
        s16 position[3];
        f32 timer;
    } Hoop;
    typedef struct {
        s32 count;
        u8 pad[16];
        Hoop hoops[1];
    } HoopData;
    Actor *func_80106790(Unk80132ED0 *);
    void *func_80100094(Actor *, u32);
    Actor *actor;
    HoopData *data;

    actor = func_80106790(arg0->unk3C);
    if (arg0->actorData[5] != -1) {
        data = func_80100094(actor, 0);
        data->hoops[arg0->actorData[5]].used = 0;
        data->hoops[arg0->actorData[5]].timer = 5.0f;
    }
}
