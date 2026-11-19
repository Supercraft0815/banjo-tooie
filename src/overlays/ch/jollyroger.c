#include "common.h"

void func_80800024_chjollyroger(Actor *arg0);
void func_80105834(Actor *);
void func_80101870(Actor *, void *);
void func_80800DB8_chjollyroger(Actor* arg0);
void func_808002E8_chjollyroger(BtIntPtr arg0);
void *func_80107C2C(s32 *, s32, void *, s32, void *);
s32 func_80800370_chjollyroger(Actor *arg0, s32 arg1, s32 arg2);

s32 D_80801200_chjollyroger[] = {
    0x00000001, 0x0FFE0100, 0x00000001, 0x0FFF0200,
    0x00000200, 0x10500100, 0x00000200, 0x0FFF0200,
    0x00000400, 0x10510100, 0x00000400, 0x0FFF0200,
    0xFFFEDFFF, 0x12100300
};

s32 D_80801238_chjollyroger[] = {
    0x00000001, 0x10000100, 0x00000001, 0x10010200,
    0x00000200, 0x10520100, 0x00000200, 0x10010200,
    0x00000400, 0x10530100, 0x00000400, 0x10010200,
    0xFFFEDFFF, 0x12100300
};

s32 D_80801270_chjollyroger[] = {
    0x00000001, 0x0FFC0100, 0x00000001, 0x0FFD0200,
    0x00000200, 0x0FFC0100, 0x00000200, 0x10560200,
    0x00000400, 0x10550100, 0x00000400, 0x0FFD0200,
    0xFFFEDFFF, 0x12100300
};

u32 D_808012A8_chjollyroger[] = {
    0x439D8000, 0x42F00000, 0x42A00000, 0x43200000
};

u32 D_808012B8_chjollyroger[] = {
    0x43340000, 0x43480000, 0x42F00000, 0x43160000
};

u32 D_808012C8_chjollyroger[] = {
    0x00000000, 0x00000000, 0x41180000, 0x01540001,
    0x411E6666, 0x01540001, 0x40733333, 0x03E40001,
    0x40E33333, 0x01550002, 0x40733333, 0x03E40001,
    0x40E33333, 0x01550001, 0x411E6666, 0x01540001,
    0x40733333, 0x03E40001, 0x40E33333, 0x01550001
};

u32 D_80801318_chjollyroger[] = {
    0x00000000, 0x00000000, 0x41100000, 0x01560001,
    0x41100000, 0x01560001, 0x41100000, 0x01560001,
    0x3F4CCCCD, 0x01570001, 0x41100000, 0x01560001,
    0x41100000, 0x01560001, 0x41100000, 0x01560001
};

BtFnWord D_80801358_chjollyroger[] = {
    0x02F30360, 0x06D60001, (BtFnWord)D_808012C8_chjollyroger, (BtFnWord)func_80800024_chjollyroger,
    (BtFnWord)func_80105834, (BtFnWord)func_80101870, 0x00000000, 0x00000000,
    0x00000000, 0x00000520, (BtFnWord)func_80800DB8_chjollyroger, 0x00000000,
    0x00140000, (BtFnWord)func_808002E8_chjollyroger, (BtFnWord)func_80107C2C, 0x82002502,
    (BtFnWord)func_80800370_chjollyroger, 0x00000000
};

OSThread *chjollyroger_entrypoint_0(void)
{
    return (OSThread *) D_80801358_chjollyroger;
}

OSThread *chjollyroger_entrypoint_1(void)
{
    extern u8 D_808013A0_chjollyroger[];

    return (OSThread *) D_808013A0_chjollyroger;
}

OSThread *chjollyroger_entrypoint_2(void)
{
    extern u8 D_808013E8_chjollyroger[];

    return (OSThread *) D_808013E8_chjollyroger;
}

void func_80800024_chjollyroger(Actor *arg0) {
    s32 _chbadshad_entrypoint_2(Actor *arg0, s32 arg1, f32 arg2, f32 *arg3);
    s32 _glcutDll_entrypoint_20(void);
    u32 _subaddiedialog_entrypoint_11(Unk80132ED0* arg0, u32 DialogId, u32 arg2, f32* CameraTarget, s16 arg4);
    s32 _subaddieitem_entrypoint_3(Actor *arg0, void *arg1, u8 *arg2);
    s32 _sudeflect_entrypoint_1(f32 *arg0, f32 arg1, f32 arg2, f32 arg3, s32 arg4);
    void _suexpression_entrypoint_10(void *arg0, Unk80132ED0 *arg1, f32 *arg2);
    void _suexpression_entrypoint_18(s8 *arg0, s32 arg1);
    void * _suexpression_entrypoint_20(Actor *arg0);
    void func_800D1824(s32 arg0);
    s32 func_800DA298(s32 index);
    int func_800DC298(f32 arg0);
    void func_800EE7F8(f32 dst[3], f32 src[3]);
    void * func_80100094(Actor *arg0, u32 arg1);
    s32 func_80101DDC(Actor *arg0);
    s32 func_80101E14(Actor *arg0, f32 arg1);
    s32 func_801022E4(Actor *arg0);
    void func_80102424(Actor *arg0, s32 arg1);
    void func_80103DFC(Actor *arg0, f32 *arg1);
    void func_8080056C_chjollyroger(void *arg0);
    s32 func_8080059C_chjollyroger(Actor *arg0, s32 *arg1, s32 arg2, s32 arg3);
    struct Flags94 {
        BT_BITFIELD_ORDER(unsigned int pad : 1, unsigned int rest : 30);
        unsigned int enabled : 1;
        BT_BITFIELD_ORDER(unsigned int rest : 30, unsigned int pad : 1);
    };
    void *sp44;
    f32 sp38[3];
    sp44 = _suexpression_entrypoint_20(arg0);
    if (func_800DA298(0) == 0 && _glcutDll_entrypoint_20() == 0) {
        func_800D1824(0x4E);
    }
    _suexpression_entrypoint_10(sp44, arg0->unk0, 0);
    if (func_801022E4(arg0) == 0x155) {
        _suexpression_entrypoint_18(sp44, 1);
    }
    func_800EE7F8((f32 *)arg0->actorData, arg0->position);
    if (arg0->unk7C_12 && _chbadshad_entrypoint_2(arg0, 3, 1.5f, (f32 *)arg0->actorData)) {
        _sudeflect_entrypoint_1((f32 *)arg0->actorData, 250.0f, 0.0f, 80.0f, 10);
    }
    switch (arg0->unk70_10) {
    case 1:
        func_8080059C_chjollyroger(arg0, D_80801200_chjollyroger, 7, 2);
        break;
    case 3:
        if (!func_8080059C_chjollyroger(arg0, D_80801238_chjollyroger, 7, 5) && func_80101E14(arg0, 0.999f)) {
            if (arg0->unk64_19) {
                arg0->unk64_19 = 0;
            }
            else if (func_800DA298(0xC3) && func_800DC298(0.35f)) {
                func_80102424(arg0, 4);
                arg0->unk64_19 = 1;
            }
        }
        break;
    case 4:
        if (func_80101DDC(arg0)) {
            func_80102424(arg0, 3);
        }
        else {
            func_8080059C_chjollyroger(arg0, D_80801238_chjollyroger, 7, 6);
        }
        func_8080056C_chjollyroger(arg0);
        break;
    case 6:
        if (func_80101E14(arg0, 0.999)) {
            func_80102424(arg0, 5);
        }
        break;
    case 7:
    case 8:
        func_80103DFC(arg0, sp38);
        if (_subaddieitem_entrypoint_3(arg0, sp38, func_80100094(arg0, 0))) {
            _subaddiedialog_entrypoint_11(arg0->unk0, 0x1004, 0xE, arg0->position, 0x55);
            func_80102424(arg0, func_800DA298(0xC0) ? 5 : 2);
        }
        break;
    case 9:
        func_8080056C_chjollyroger(arg0);
        break;
    }
    if (func_801022E4(arg0) == 0x155) {
        ((struct Flags94 *)&arg0->pad94)->enabled = 0;
    }
    else {
        ((struct Flags94 *)&arg0->pad94)->enabled = 1;
    }
}

/* extern */

void func_808002E8_chjollyroger(BtIntPtr arg0) {
    s32 _glcutDll_entrypoint_20();
    void _subaddieitem_entrypoint_0(u8 *arg0, BtIntPtr arg1, s32 arg2, s32 arg3);
    void _subaddieitem_entrypoint_1(s8 *arg0, s32 arg1);
    s32 func_800DA298(s32);
    void *func_80100094(Actor *, u32);
    void func_80102424(Actor *, s32);
    if (_glcutDll_entrypoint_20() != 0) {
        func_80102424(arg0, 9);
    } else if (func_800DA298(0xC0) != 0) {
        func_80102424(arg0, 4);
    }
    _subaddieitem_entrypoint_0(func_80100094(arg0, 0), 0x4E4, -1, 3);
    _subaddieitem_entrypoint_1(func_80100094(arg0, 0), 2);
}

s32 func_80800370_chjollyroger(Actor *arg0, s32 arg1, s32 arg2) {
    void _gcdialogcamera_entrypoint_3(u32 *, f32);
    u32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, u32, u32, f32 *, s16);
    BtIntPtr _suexpression_entrypoint_7(Actor *, s32, s32);
    s32 _suexpression_entrypoint_12(void *, s32, s32);
    s32 _suexpression_entrypoint_17(void *, s32);
    s32 func_800DA298(s32);
    BtIntPtr func_800F54E4();
    s32 func_800F7F98(BtIntPtr, u32);
    void func_80102424(Actor *, s32);
    void func_80800624_chjollyroger(Actor *, s32, s32);
    s32 func_80800DD8_chjollyroger(void *, s32, s32);
    void func_80800E30_chjollyroger(void *);
    void func_80800E6C_chjollyroger(Actor *, s32, s32);

    s32 dialog;
    BtIntPtr expression;
    s32 value;

    switch (arg1) {
    case 0xB:
        switch (arg2) {
        case 1:
            func_800F7F98(func_800F54E4(), 0);
            if (func_800DA298(0xC2) == 0 && func_800DA298(0x41) == 0) {
                func_80800E6C_chjollyroger(arg0, 3, 1);
                _subaddiedialog_entrypoint_11(arg0->unk0, 0x1002, 0x4E, arg0->position, 0x55);
                return 4;
            }
            func_80800E30_chjollyroger(arg0);
            func_80102424(arg0, 3);
            return 4;
        case 3:
            dialog = func_800DA298(0xC0) ? 0x1043 : 0x1042;
            _subaddiedialog_entrypoint_11(arg0->unk0, dialog, 0xE, arg0->position, 0x55);
            break;
        }
        return 3;
    case 0x2E:
        func_80800624_chjollyroger(arg0, ((s16 *)&arg2)[0], ((s16 *)&arg2)[1]);
        break;
    case 0x52:
        _gcdialogcamera_entrypoint_3(D_808012A8_chjollyroger, arg0->scale);
        break;
    case 0x57:
        return func_80800DD8_chjollyroger(arg0, arg2 & 0xFFFF, (u32)(arg2 & 0xFFFF0000) >> 16);
    case 0x95:
        expression = _suexpression_entrypoint_7(arg0, 1, 0x55);
        _suexpression_entrypoint_12(expression, 0x42700000, 0x41A00000);
        _suexpression_entrypoint_17(expression, 1000);
        break;
    case 0x6E:
        value = arg2;
        arg0->unk64_16 = value == 0;
        break;
    default:
        return 0;
    }
    return 1;
}

void func_8080056C_chjollyroger(void *arg0) {
    extern u32 D_80801430_chjollyroger;
    extern u32 D_8080143C_chjollyroger;
    _subaddieaudioquick_entrypoint_4(arg0, (u8 *)arg0 + 24, &D_80801430_chjollyroger, &D_8080143C_chjollyroger);
}

s32 func_8080059C_chjollyroger(Actor *arg0, s32 *arg1, s32 arg2, s32 arg3) {
    s32 _subaddiedialog_entrypoint_8(BtIntPtr, void *, s32 *, s32 *, s32);
    s32 _subaddiedialog_entrypoint_9(BtIntPtr, s32, s32 *, s32);
    void func_80800E6C_chjollyroger(Actor *, s32, s32);
    extern s32 D_80801448_chjollyroger;
    extern s8 D_80801456_chjollyroger;
    s32 temp_v0;

    D_80801456_chjollyroger = arg3;
    temp_v0 = _subaddiedialog_entrypoint_8((BtIntPtr)arg0, (u8 *)arg0 + 4, &D_80801448_chjollyroger, arg1, arg2);
    if (temp_v0 == 0) {
        return 0;
    }
    if (_subaddiedialog_entrypoint_9((BtIntPtr)arg0, temp_v0, arg1, arg2) != 3) {
        func_80800E6C_chjollyroger(arg0, 3, 0);
    }
    return 1;
}

void func_80800624_chjollyroger(Actor *arg0, s32 arg1, s32 arg2) {
    u32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, u32, u32, f32 *, s16);
    s32 _subaddiedialog_entrypoint_9(BtIntPtr, s32, s32 *, s32);
    void _subaddieitem_entrypoint_2(BtIntPtr);
    void func_800C01A8(s16, s32);
    void func_800C0850(void);
    s32 func_800D0A9C(u32, u32);
    s32 func_800D1000(s32, s32, s32 *, s32, BtIntPtr);
    s32 func_800D1A04(s32);
    s32 func_800DA298(s32);
    BtIntPtr func_800F54E4(void);
    s32 func_800F64A4(BtIntPtr, s32);
    s32 func_800F7F98(BtIntPtr, u32);
    void *func_80100094(Actor *, u32);
    s32 func_80101180(s32, s32, BtIntPtr);
    void func_80102424(Actor *, s32);
    void func_80800E30_chjollyroger(void *);
    void func_80800F3C_chjollyroger(Actor *, s32, s32);
    void func_80800FBC_chjollyroger(Actor *, s32, s32);

    s32 temp;

    switch (arg1) {
    case 0x1002:
        if (arg2 > 0) {
            if (func_800D1A04(0x4E) < 2) {
                _subaddiedialog_entrypoint_11(arg0->unk0, 0x1005, 0xE, arg0->position, 0x55);
                return;
            }
            if (func_800F64A4(func_800F54E4(), 0x201)) {
                func_80800FBC_chjollyroger(arg0, 0xD, 0);
                _subaddiedialog_entrypoint_11(arg0->unk0, 0x1041, 0xE, arg0->position, 0x55);
                return;
            }
            _subaddiedialog_entrypoint_11(arg0->unk0, 0x1225, 0xE, arg0->position, 0x55);
            return;
        }
        _subaddiedialog_entrypoint_11(arg0->unk0, 0x1003, 0xE, arg0->position, 0x55);
        return;
    case 0x1041:
        _subaddieitem_entrypoint_2(func_80100094((BtIntPtr)arg0, 0));
        func_80102424(arg0, func_800DA298(0xC0) ? 8 : 7);
        return;
    case 0x1004:
        func_80101180(0x36A, 7, 0);
        func_80800F3C_chjollyroger(arg0, 3, 0x10);
        return;
    default:
        if (func_800DA298(0xC0)) {
            switch (_subaddiedialog_entrypoint_9((BtIntPtr)arg0, arg1, D_80801238_chjollyroger, 7)) {
            case 1:
                if (!func_800D0A9C(0x24, 1)) {
                    func_800F7F98(func_800F54E4(), 1);
                    func_80800F3C_chjollyroger(arg0, 1, 0x20);
                    func_800D1000(0x24, 1, 0, 1, 0);
                    return;
                }
            case 2:
                if (!func_800DA298(0xC2) && !func_800DA298(0x41)) {
                    _subaddiedialog_entrypoint_11(arg0->unk0, 0x1002, 0x4E, arg0->position, 0x55);
                    return;
                }
                func_800C01A8(0x64, 0);
                func_800C0850();
            default:
                func_80800E30_chjollyroger(arg0);
                func_80102424(arg0, 3);
                return;
            }
        } else {
            temp = _subaddiedialog_entrypoint_9((BtIntPtr)arg0, arg1, D_80801200_chjollyroger, 7);
            if (temp == 1 || temp == 2) {
                if (!func_800DA298(0xC2) && !func_800DA298(0x41)) {
                    _subaddiedialog_entrypoint_11(arg0->unk0, 0x1002, 0x4E, arg0->position, 0x55);
                    return;
                }
                func_800C01A8(0x64, 0);
                func_800C0850();
            }
            func_80800E30_chjollyroger(arg0);
            func_80102424(arg0, 1);
        }
    }
}

void func_80800930_chjollyroger(Actor *arg0) {
    s32 _sudeflect_entrypoint_1(f32 *, f32, f32, f32, s32);
    void _suexpression_entrypoint_10(void *, Unk80132ED0 *, f32 *);
    void *_suexpression_entrypoint_20(Actor *);
    void func_8008F8B0();
    void func_8008F8D8(s32);
    void func_8008F904(void *, Unk80132ED0 *);
    void func_8008F990(f32 *, f32);
    void func_800DA524(GameFlag);
    s32 func_800DA544(s32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF1B8(f32 *, f32, f32);
    BtIntPtr func_800F54E4();
    s32 func_800F64A4(BtIntPtr, s32);
    void func_80102424(Actor *, s32);
    s32 func_80105230(Actor *, f32 *);
    void func_80105854(Actor *);
    s32 func_80105A5C(Actor *);
    s32 func_8010CA74(f32 *, s32);
    void func_80800CC4_chjollyroger(Actor *);
    void func_80800E30_chjollyroger(void *);
    void func_80800F3C_chjollyroger(Actor *, s32, s32);
    s32 _subaddiedialog_entrypoint_8(BtIntPtr, void *, s32 *, s32 *, s32);
    extern s32 func_8010D5DC;
    extern s32 D_80801458_chjollyroger;

    _sudeflect_entrypoint_1(arg0->position, 230.0f, 0.0f, 100.0f, 10);
    _suexpression_entrypoint_10(_suexpression_entrypoint_20(arg0), arg0->unk0, 0);
    switch (arg0->unk70_10) {
        case 1: {
            f32 sp34[3];
            if (func_800F64A4(func_800F54E4(), 0x201) && func_8010CA74(arg0->position, 0x4B0)) {
                func_80102424(arg0, 2);
                func_80800F3C_chjollyroger(arg0, 1, 0x220);
                func_800EE7F8(sp34, arg0->position);
                func_800EF1B8(sp34, arg0->rotation[1] + 20.0f, 250.0f);
                func_8008F8B0();
                func_8008F8D8(1);
                func_8008F904(&func_8010D5DC, arg0->unk0);
                func_8008F990(sp34, 250.0f);
            }
            break;
        }
        case 2:
            if (arg0->unk64_20) {
                func_80800CC4_chjollyroger(arg0);
            }
            break;
        case 4:
            func_80105230(arg0, 0);
            func_80105854(arg0);
            if (func_80105A5C(arg0)) {
                func_800DA544(0xC0);
                func_800DA524(0xC3);
                func_80800E30_chjollyroger(arg0);
            }
            break;
        case 5:
            _subaddiedialog_entrypoint_8((BtIntPtr)arg0, arg0->position, &D_80801458_chjollyroger, D_80801270_chjollyroger, 7);
            break;
    }
}

void func_80800AEC_chjollyroger(Actor *arg0) {
    s32 func_800DA298(s32);
    s32 _glcutDll_entrypoint_20();
    s32 func_800EA05C();
    void func_800FFAB0(Actor *);
    void func_80102424(Actor *, s32);
    s32 active;

    active = func_800DA298(0xC0) || _glcutDll_entrypoint_20();
    switch (func_800EA05C()) {
        case 0xED:
            if (!active) {
                func_800FFAB0(arg0);
            } else {
                func_80102424(arg0, _glcutDll_entrypoint_20() ? 7 : 5);
            }
            break;
        case 0xF8:
            if (active) {
                func_800FFAB0(arg0);
            }
            break;
    }
}

s32 func_80800BA0_chjollyroger(Actor *arg0, s32 arg1, s32 arg2) {

    void _gcdialogcamera_entrypoint_3(u32 *, f32);
    BtIntPtr _suexpression_entrypoint_7(Actor *, s32, s32);
    s32 _suexpression_entrypoint_12(void *, s32, s32);
    s32 _suexpression_entrypoint_17(void *, s32);
    BtIntPtr func_800F54E4();
    void func_800F8300();
    void func_80800D28_chjollyroger(BtIntPtr, s32, s32);
    s32 func_80800DD8_chjollyroger(void *, s32, s32);
    BtIntPtr expression;

    switch (arg1) {
        case 0x2E:
            func_80800D28_chjollyroger(arg0, ((s16 *)&arg2)[0], ((s16 *)&arg2)[1]);
            break;
        case 0x32:
            arg0->unk64_20 = 1;
            func_800F8300(func_800F54E4(), 1, arg0->position, arg0);
            break;
        case 0x57:
            return func_80800DD8_chjollyroger(arg0, arg2 & 0xFFFF, (u32)(arg2 & 0xFFFF0000) >> 16);
        case 0x52:
            _gcdialogcamera_entrypoint_3(D_808012B8_chjollyroger, arg0->scale);
            break;
        case 0x95:
            expression = _suexpression_entrypoint_7(arg0, 1, 0x56);
            _suexpression_entrypoint_12(expression, 0x42700000, 0x41A00000);
            _suexpression_entrypoint_17(expression, 1000);
            break;
        default:
            return 0;
    }
    return 1;
}

/* extern */

void func_80800CC4_chjollyroger(Actor *arg0) {
    u32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, u32, u32, f32 *, s16);
    BtIntPtr func_800F54E4();
    s32 func_800F64A4(BtIntPtr, s32);
    void func_80102424(Actor *, s32);
    s32 var_a1;

    var_a1 = func_800F64A4(func_800F54E4(), 0x200) ? 0x1054 : 0xFFB;
    _subaddiedialog_entrypoint_11(arg0->unk0, var_a1, 6, arg0->position, 0x56);
    func_80102424(arg0, 3);
}

/* extern */

void func_80800D28_chjollyroger(BtIntPtr arg0, s32 arg1, s32 arg2) {
    BtIntPtr func_800F54E4();
    s32 func_800F82D4(BtIntPtr, s32);
    void func_80102424(Actor *, s32);
    s32 func_80105A9C(BtIntPtr, s32);
    s32 func_80105BAC(BtIntPtr);
    void func_80800F3C_chjollyroger(Actor *, s32, s32);
    if ((arg1 == 0xFFB) || (arg1 == 0x1054)) {
        func_80102424(arg0, 4);
        func_80105A9C(arg0, 0x43AF0000);
        func_80105BAC(arg0);
        func_800F82D4(func_800F54E4(), 0);
        func_80800F3C_chjollyroger(arg0, 4, 0x30);
        return;
    }
    func_80102424(arg0, 5);
}

void func_80800DB8_chjollyroger(Actor* arg0) 
{
    _suexpression_entrypoint_8(arg0, 1);
}
/* extern */

s32 func_80800DD8_chjollyroger(void *arg0, s32 arg1, s32 arg2) {
    s32 _gcdialogcamera_entrypoint_0(s32, s32);
    void func_80800E6C_chjollyroger(Actor *, s32, s32);
    if (_gcdialogcamera_entrypoint_0(arg1, arg2) != 0) {
        if ((*(s32 *)((s8 *)(arg0) + (0x28))) != 2) {
            func_80800E6C_chjollyroger(arg0, 2, 1);
        }
        return 2;
    }
    return 1;
}

/* extern */

void func_80800E30_chjollyroger(void *arg0) {
    s32 _capod_entrypoint_3(s32, void *);
    if ((*(s32 *)((s8 *)(arg0) + (0x28))) != 0) {
        _capod_entrypoint_3(0, arg0);
        (*(s32 *)((s8 *)(arg0) + (0x28))) = 0;
    }
}

void func_80800E6C_chjollyroger(Actor *arg0, s32 arg1, s32 arg2) {
    void _capod_entrypoint_2(Unk80132ED0 *, u32, s32);
    void _capod_entrypoint_7(s32, s32);
    s32 _capod_entrypoint_8(s32);
    void _gcdialogcamera_entrypoint_3(u32 *, f32);
    void _gcdialogcamera_entrypoint_4(f32 *);
    void _gcdialogcamera_entrypoint_5(f32 *);
    void _gcdialogcamera_entrypoint_8(void);

    switch (arg0->actorData[4]) {
        case 0:
            _capod_entrypoint_2(arg0->unk0, 0x10, 0);
        case 1:
        case 3:
            _capod_entrypoint_8(1);
            arg0->actorData[4] = 2;
            _gcdialogcamera_entrypoint_3(arg0->unk6C_9 == 0x360 ? D_808012A8_chjollyroger : D_808012B8_chjollyroger, arg0->scale);
            _gcdialogcamera_entrypoint_4(arg0->position);
            _gcdialogcamera_entrypoint_5(arg0->rotation);
            _gcdialogcamera_entrypoint_8();
        case 2:
            _capod_entrypoint_7(arg1, arg2);
            break;
    }
}

void func_80800F3C_chjollyroger(Actor *arg0, s32 arg1, s32 arg2) {
    void _capod_entrypoint_2(Unk80132ED0 *, u32, s32);
    void _capod_entrypoint_6(Unk80132ED0 *, s32, s32);

    switch (arg0->actorData[4]) {
        case 0:
            _capod_entrypoint_2(arg0->unk0, 0x10, arg2);
        case 2:
        case 3:
            arg0->actorData[4] = 1;
        case 1:
            _capod_entrypoint_6(arg0->unk0, arg1, arg2);
            break;
    }
}

void func_80800FBC_chjollyroger(Actor *arg0, s32 arg1, s32 arg2) {
    void _capod_entrypoint_2(Unk80132ED0 *, u32, s32);
    void _capod_entrypoint_20(Unk80132ED0 *, s32, s32);

    switch (arg0->actorData[4]) {
        case 0:
            _capod_entrypoint_2(arg0->unk0, 0x10, arg2);
        case 1:
        case 2:
            arg0->actorData[4] = 1;
        case 3:
            _capod_entrypoint_20(arg0->unk0, arg1, arg2);
            break;
    }
}

/* extern */

void func_8080103C_chjollyroger(Actor *arg0) {
    s32 _chdoormake_entrypoint_0(void *, f32, u32, s32);
    void _chdoormake_entrypoint_5(Actor *, f32);
    void _chdoormake_entrypoint_8(void *, u32);
    void func_8010A63C(void ***);
    s32 func_8010A800(Actor *, s32);
    if (_chdoormake_entrypoint_0(arg0, -120.0f, 0x8000, 0xC2) != 0) {
        _chdoormake_entrypoint_8(arg0, 1);
        _chdoormake_entrypoint_5(arg0, 3.5f);
    }
    func_8010A800(arg0, 0);
    func_8010A63C(arg0);
}

s32 func_808010A0_chjollyroger(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _chdoor_entrypoint_1(Actor *, s32, BtIntPtr);
    void _chexploder_entrypoint_3(void *, void *, u32);
    u32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, u32, u32, f32 *, s16);
    Actor *_subaddiefind_entrypoint_2(s32, BtIntPtr);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF1B8(f32 *, f32, f32);
    void func_80102424(Actor *, s32);
    void func_80801194_chjollyroger(BtIntPtr);
    f32 sp34[3];
    Actor *sp30;

    switch (arg1) {
        case 0x90:
            func_80801194_chjollyroger(arg0);
            break;
        case 0x40:
            sp30 = _subaddiefind_entrypoint_2(0x360, 0);
            func_800EE7F8(sp34, arg0->position);
            func_800EF1B8(sp34, arg0->rotation[1] - 90.0f, 100.0f);
            sp34[1] += 25.0f;
            _chexploder_entrypoint_3(arg0, sp34, 0x28);
            _subaddiedialog_entrypoint_11(sp30->unk0, 0x1044, 0x4C, sp30->position, 0x55);
            func_80102424(sp30, 2);
            break;
        default:
            return _chdoor_entrypoint_1(arg0, arg1, arg2);
    }
    return 1;
}

/* extern */

void func_80801194_chjollyroger(BtIntPtr arg0) {
    void _chexploder_entrypoint_12(Actor *arg0, s32 arg1);
    s32 func_800DA544(s32);
    BtIntPtr func_80101080();
    BtIntPtr func_80106790(BtIntPtr);
    _chexploder_entrypoint_12(func_80106790(func_80101080()), 0x3C);
    func_800DA544(0x41);
}
