#include "ch/boggy/fatboy.h"

u32 D_80801154_chboggyfatboy[];
void func_80101870(Actor *, void *);
void *func_80107C2C(s32 *, s32, void *, s32, void *);
OSThread *func_80108ED0(void);
void func_808000AC_chboggyfatboy(Actor *arg0);
void func_8080052C_chboggyfatboy(Actor *arg0);
s32 func_808005AC_chboggyfatboy(Actor *arg0, s32 arg1, s32 arg2);
void func_80800978_chboggyfatboy(Actor* arg0);
void func_80800B38_chboggyfatboy(s32 arg0, void *arg1, s32 arg2, s32 arg3);
s32 func_80800BA0_chboggyfatboy(s32 arg0, s32 arg1, f32 *arg2);

BtFnWord D_80801120_chboggyfatboy[] = {
    (BtFnWord)func_80800BA0_chboggyfatboy, (BtFnWord)func_80800B38_chboggyfatboy,
};

s32 D_80801128_chboggyfatboy[] = {
    0x00000201, 0xFFFF0100,
    0x00000601, 0xFFFE0200,
    0x00000400, 0x11100100,
    0xFFFEDFFF, 0x12220300,
};

s32 D_80801148_chboggyfatboy[] = {
    0x00130524, 0x000A00CC,
    0x00000000,
};

u32 D_80801154_chboggyfatboy[] = {
    0x00000000, 0x00000000,
    0x409CCCCD, 0x02460001,
    0x3F400000, 0x02470001,
    0x3F400000, 0x02470001,
    0x409CCCCD, 0x02460001,
    0x3F400000, 0x02470001,
    0x3F400000, 0x02470001,
    0x3F400000, 0x02470001,
    0x409CCCCD, 0x02460001,
    0x409CCCCD, 0x02460001,
    0x409CCCCD, 0x02460001,
    0x409CCCCD, 0x02460001,
    0x409CCCCD, 0x02460001,
    0x409CCCCD, 0x02460001,
    0x40A00000, 0x02480002,
    0x409CCCCD, 0x02460001,
    0x00000000, 0x00000000,
};

BtFnWord D_808011DC_chboggyfatboy[] = {
    0x01940142, 0x075B0001,
    (BtFnWord)D_80801154_chboggyfatboy, (BtFnWord)func_808000AC_chboggyfatboy,
    (BtFnWord)func_8080052C_chboggyfatboy, (BtFnWord)func_80101870,
    0x09C40000, 0x40000000,
    0x00000000, 0x40040164,
    (BtFnWord)func_80800978_chboggyfatboy, (BtFnWord)func_80108ED0,
    0x00240000, 0x00000000,
    (BtFnWord)func_80107C2C, 0x80105014,
    (BtFnWord)func_808005AC_chboggyfatboy, 0x00000000,
};

s32 D_80801224_chboggyfatboy[] = {
    0x00000000, 0x0190003D,
    0x0000000E, 0x463C0400,
};

s32 D_80801234_chboggyfatboy[] = {
    0x43340000, 0x430C0000,
    0x430C0000, 0x42A00000,
};

s32 D_80801244_chboggyfatboy[] = {
    0x001304A4, 0x000A0140,
    0x00000000,
};

u32 D_80801250_chboggyfatboy[] = {
    0x00130417, 0x000D00E6,
    0x01190000,
};

u32 D_8080125C_chboggyfatboy[] = {
    0x0013040E, 0x00000000,
};

s32 D_80801264_chboggyfatboy[] = {
    0x001D09E3, 0x00150019,
    0x00990022, 0x00380042,
    0x0023002E, 0x002B0066,
    0x0080002D, 0x012C0190,
    0x000B0014, 0x001E000A,
    0x00000000,
};

u32 D_80801290_chboggyfatboy[] = {
    0x3DF5C28F, 0x3E8A3D71,
    0x3ECCCCCD, 0xBF800000,
};

s16 D_808012A0_chboggyfatboy[] = {
    0x0540, 0x042B, 0x0558, 0x0559,
    0x0557, 0x0000,
};

f32 D_808012AC_chboggyfatboy[] = {
    0.6000000238418579f, 0.7200000286102295f,
    0.8600000143051147f, -1.0f,
};

s32 D_808012BC_chboggyfatboy[] = {
    0x0021000D, 0x00D900F3,
    0x00194E20, 0x5DC00000,
};

s32 D_808012CC_chboggyfatboy[] = {
    0x00130486, 0x000D00C0,
    0x00D90015, 0x000C00CC,
    0x00330019, 0x6D607D00,
    0x00000000,
};

s32 D_808012E8_chboggyfatboy[] = {
    0x001305CA, 0x000D00D9,
    0x00F30018, 0x00000000,
    0x00000000, 0x00000000,
};

void *func_80100094(Actor *, u32);     

OSThread *chboggyfatboy_entrypoint_0(void)
{


    return (OSThread *) D_80801120_chboggyfatboy;
}

OSThread *chboggyfatboy_entrypoint_1(void)
{


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
    _subaddieitem_entrypoint_0((BtIntPtr)data + 0xC, 0x3CA, 0x190, 1);
}

void func_808000AC_chboggyfatboy(Actor *arg0) {
    void _subaddieDll_entrypoint_4(void *arg0, s32 arg1);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32 *, void *);
    u32 _subaddiedialog_entrypoint_11(Unk80132ED0* arg0, u32 DialogId, u32 arg2, f32* CameraTarget, s16 arg4);
    s32 _subaddiedialog_entrypoint_8(BtIntPtr, void *, s32 *, s32 *, s32);
    s32 _subaddieitem_entrypoint_3(Actor *, f32 *, void *);
    s32 _subaddietaxi_entrypoint_1(Actor *, s32);
    s32 _subaddietaxi_entrypoint_11(Actor *, s32);
    s32 _subaddietaxi_entrypoint_12(Actor *, s32);
    void _subaddietaxi_entrypoint_14(Actor *, s32);
    s32 _subaddietaxi_entrypoint_15(Actor *, s32);
    s32 _subaddietaxi_entrypoint_5(Actor *, s32);
    void _subaddietaxi_entrypoint_9(Actor *, s32);
    s32 _sudeflect_entrypoint_1(f32 *arg0, f32 arg1, f32 arg2, f32 arg3, s32 arg4);
    void _suexpression_entrypoint_10(u32 *, Unk80132ED0 *, BtUIntPtr);
    int func_800D9154(f32 *, f32);
    s32 func_800DA298(s32);
    void func_800DA544(s32 index);
    void func_800EE88C(f32 *, s16 *);
    int func_800F0064(f32 *, f32, f32 *);
    BtIntPtr func_800F54E4(void);
    s32 func_800F64A4(BtIntPtr, s32);
    s32 func_8010108C(Actor *, s32, BtIntPtr);
    s32 func_80101DDC(Actor *);
    void func_80102424(Actor *actor,s32 state);
    f32 func_801028C4(Actor *, f32 *, f32, f32, f32);
    void func_80102BF8(Actor *, f32, f32, f32);
    f32 func_80102D78(Actor *, f32 *);
    void func_801058C4(Actor *, s32, f32, u32);
    void func_80105BAC(Actor *);
    Actor *func_80106790(Unk80132ED0 *);
    void func_8010A590(Actor *);
    s32 func_8010B990(Actor *, s32);
    s32 func_8010CAC0(f32 *, s32);
    void func_80800998_chboggyfatboy(Actor *);
    void func_80800D84_chboggyfatboy(Actor *);
    void func_80800E80_chboggyfatboy(Actor *);
    s32 func_80800FE0_chboggyfatboy(s32);



    struct {
        s16 position[3];
        s16 yaw;
        BT_BITFIELD_ORDER(u32 flag : 1, u32 pad8 : 31);
        BT_BITFIELD_ORDER(u32 pad8 : 31, u32 flag : 1);
        u8 item[0x14];
        f32 timer;
    } *data;
    s32 deflect;
    f32 sp4C[3];
    f32 sp40[3];
    s32 pad[4];

    data = func_80100094(arg0, 0);
    deflect = 1;
    if (func_80100094(arg0, 1) != NULL) {
        _suexpression_entrypoint_10(func_80100094(arg0, 1), arg0->unk0, 0);
    }
    switch (arg0->unk70_10) {
    case 1:
        if (func_800DA298(0xBA)) {
            if (func_800DA298(0xBB)) {
                arg0->unk74_30 = 1;
            } else if (func_80800FE0_chboggyfatboy(0x3CA) && !func_8010CAC0(arg0->position, 0x320)) {
                arg0->unk74_30 = 0;
            }
        }
        _subaddiedialog_entrypoint_8(arg0, arg0->position, &D_80801224_chboggyfatboy[0], &D_80801128_chboggyfatboy[0], 4);
        break;
    case 5:
        func_800EE88C(sp4C, data->position);
        if (func_801028C4(arg0, sp4C, 0.2f, 30.0f, 180.0f) < 40.0f) {
            func_80102424(arg0, 6);
        }
        break;
    case 6:
        func_800EE88C(sp40, data->position);
        arg0->unk54 = func_80102D78(arg0, sp40);
        func_80102BF8(arg0, 0.2f, 30.0f, 180.0f);
        func_8010B990(arg0, 0x1005);
        if (func_800F0064(arg0->position, 100.0f, sp40)) {
            func_801058C4(arg0, data->yaw, *(f32 *)&arg0->actorData[3], 1);
            func_80105BAC(arg0);
            func_80102424(arg0, 7);
        }
        break;
    case 9:
        deflect = 0;
        break;
    case 10:
        arg0->unk54 = func_80102D78(arg0, func_80106790(arg0->unk3C)->position);
        func_80102BF8(arg0, 0.2f, 30.0f, 180.0f);
        deflect = 0;
        if (_subaddietaxi_entrypoint_1(arg0, 1)) {
            func_800DA544(0x8E);
            func_80102424(arg0, 0xC);
        }
        break;
    case 11:
        if (_subaddietaxi_entrypoint_11(arg0, 1) && _subaddietaxi_entrypoint_5(arg0, 1)) {
            _subaddietaxi_entrypoint_14(arg0, 1);
            func_80102424(arg0, 0xD);
        }
        deflect = _subaddietaxi_entrypoint_12(arg0, 1);
        break;
    case 12:
        arg0->unk54 = func_80102D78(arg0, func_80106790(arg0->unk3C)->position);
        func_80102BF8(arg0, 0.2f, 30.0f, 180.0f);
        if (!arg0->unk64_20 && func_8010108C(func_80106790(arg0->unk3C), 0x31, arg0->unk6C_9) > 0) {
            arg0->unk64_20 = 1;
        }
        break;
    case 13:
        if (_subaddietaxi_entrypoint_15(arg0, 1)) {
            func_80102424(arg0, 1);
            func_8010A590(arg0);
        }
        break;
    case 14:
        func_80800D84_chboggyfatboy(arg0);
        if (func_80101DDC(arg0)) {
            func_80800998_chboggyfatboy(arg0);
            func_80102424(arg0, 5);
            _subaddieDll_entrypoint_4(arg0, 1);
        }
        break;
    case 15: {
        s32 text;
        if (_subaddieitem_entrypoint_3(arg0, NULL, data->item)) {
            if (func_800F64A4(func_800F54E4(), 0x200)) {
                text = 0x1111;
            } else {
                text = 0x1095;
            }
            func_800DA544(0xBB);
            _subaddiedialog_entrypoint_11(arg0->unk0, text, 0xE, arg0->position, 0x3B);
            func_80102424(arg0, 4);
        }
        break;
    }
    }
    if (data->flag && func_800D9154(&data->timer, 1.4f)) {
        _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_80801148_chboggyfatboy[0]);
    }
    func_80800E80_chboggyfatboy(arg0);
    _subaddietaxi_entrypoint_9(arg0, 1);
    if (deflect) {
        _sudeflect_entrypoint_1(arg0->position, 100.0f, 0.0f, 70.0f, 0xA);
    }
}

/* extern */

void func_8080052C_chboggyfatboy(Actor *arg0) {
    s32 _sudeflect_entrypoint_0(f32 *arg0, f32 arg1, f32 arg2, s32 arg3);
    s32 func_800DA980(s32, s32);
    void func_800FFAB0(Actor *);
    s32 func_80101180(s32, s32, BtIntPtr);
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
    void _gcdialogcamera_entrypoint_3(f32 *arg0, f32 arg1);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32 *, void *);
    void func_800C9C70(f32, u32, f32, u32, f32 *, f32, f32);
    s32 func_800DA298(s32);
    s32 func_800DA980(s32, s32);
    BtIntPtr func_800F54E4();
    s32 func_800F64A4(BtIntPtr, s32);
    void func_80800808_chboggyfatboy(Actor *, s32, s32);
    void func_808009E0_chboggyfatboy(Actor *);
    void func_80800AF0_chboggyfatboy(BtIntPtr, s32);
    void func_80800C5C_chboggyfatboy(Actor *, s32);
    void func_80800F40_chboggyfatboy(Actor *);
    s32 func_80800FE0_chboggyfatboy(s32);


    f32 *position[5];
    s16 *parts;
    s32 masked;

    switch (arg1) {
    case 0x3E:
        func_80800AF0_chboggyfatboy((BtIntPtr)arg0, arg2);
        break;
    case 0x44:
        func_80800C5C_chboggyfatboy(arg0, arg2);
        break;
    case 0x52:
        _gcdialogcamera_entrypoint_3(&D_80801234_chboggyfatboy[0], arg0->scale);
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
        _subaddieaudioquick_entrypoint_2(arg0, position[0] = arg0->position, &D_80801244_chboggyfatboy[0]);
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
    u32 _subaddiedialog_entrypoint_11(Unk80132ED0* arg0, u32 DialogId, u32 arg2, f32* CameraTarget, s16 arg4);
    u8 _subaddiedialog_entrypoint_9(void *arg0, s32 arg1, void *arg2, s32 arg3);
    void _subaddieitem_entrypoint_2(BtIntPtr);
    void func_800C01A8(s16, s32);
    void func_800C0850(void);
    void func_800DA544(s32 index);
    void func_80102424(Actor *actor,s32 state);
    s32 func_80800FE0_chboggyfatboy(s32);

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
            _subaddieitem_entrypoint_2((BtIntPtr)data + 0xC);
        } else {
            _subaddiedialog_entrypoint_11(arg0->unk0, 0x1094, 0xE, arg0->position, 0x3D);
        }
        break;
    default:
        if (_subaddiedialog_entrypoint_9((BtIntPtr)arg0, arg1, &D_80801128_chboggyfatboy[0], 4) == 1) {
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
    void func_800EE940(s16 dst[3], f32 src[3]);
    Actor *func_80106790(Unk80132ED0 *);
    BtIntPtr sp1C;
    Actor *temp_v0;

    sp1C = func_80100094(arg0, 0U);
    temp_v0 = func_80106790(arg0->unk3C);
    ((s16 *)sp1C)[3] = *(s32 *)((u8 *)temp_v0 + 0x2C);
    func_800EE940((void *)sp1C, (u8 *)temp_v0 + 0x18);
}

void func_808009E0_chboggyfatboy(Actor *arg0) {
    Actor *_subaddiefind_entrypoint_2(s32, BtIntPtr);
    s32 _subaddietaxi_entrypoint_13(Actor *arg0, s32 arg1, BtIntPtr arg2, s32 arg3);
    s32 func_800DA298(s32);
    void func_800DA524(s32 index);
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

void func_80800AF0_chboggyfatboy(BtIntPtr arg0, s32 arg1) {
    s32 _subaddietaxi_entrypoint_2(BtIntPtr, s32);
    s32 func_800DA298(s32);
    void func_80102424(Actor *actor,s32 state);
    if ((func_800DA298(0xBB) != 0) && (_subaddietaxi_entrypoint_2(arg0, 1) != 0)) {
        func_80102424(arg0, 9);
    }
}                typedef struct { s32 unk0; s32 unk4; s32 unk8; } Objfatboy_arg1; /* offsets.py genstruct: fields from raw offsets on arg1; rename once understood */

void func_80800B38_chboggyfatboy(s32 arg0, void *arg1, s32 arg2, s32 arg3) {
    s32 _chbaddiesetup_entrypoint_6(s32 *, BtIntPtr, BtIntPtr, s32, s32, s32, BtIntPtr);
    s32 func_800DA298(s32);
    extern s32 _subaddietaxi_entrypoint_16;
    if (func_800DA298(0x8E) == 0) {
        _chbaddiesetup_entrypoint_6(&_subaddietaxi_entrypoint_16, arg0, (((Objfatboy_arg1 *)arg1)->unk0), (((Objfatboy_arg1 *)arg1)->unk4), (((Objfatboy_arg1 *)arg1)->unk8), arg2, arg3);
    }
}

/* extern */

s32 func_80800BA0_chboggyfatboy(s32 arg0, s32 arg1, f32 *arg2) {
    Actor *_subaddiefind_entrypoint_2(s32, BtIntPtr);
    s32 func_800C05B8(s32, s32, f32 *, Unk80132ED0 *, BtIntPtr, s32, s16);
    s32 func_800CBC3C(BtIntPtr);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF1B8(f32 *, f32, f32);
    Actor *temp_v0;
    Actor *sp2C;
    s32 index;

    temp_v0 = _subaddiefind_entrypoint_2(0x13F, 0);
    if (temp_v0 != NULL) {
        sp2C = temp_v0;
        index = func_800CBC3C(arg1) + 1;
        if (index == (s32)sp2C->unk70_25) {
            func_800EE7F8(arg2, sp2C->position);
            func_800EF1B8(arg2, sp2C->rotation[1] - 45.0f, 180.0f);
            return 2;
        }
    }
    func_800C05B8(0x1097, 1, 0, 0, 0, 0, 0);
    return 1;
}

void func_80800C5C_chboggyfatboy(Actor *arg0, s32 arg1) {
    Actor *_subaddiefind_entrypoint_2(s32, BtIntPtr);
    void _subaddietaxi_entrypoint_0(Actor *, s32, f32 *, s32);
    void _subaddietaxi_entrypoint_10(Actor *, s32, s32);
    s32 func_800CB3E0(s32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF1B8(f32 *, f32, f32);
    void func_80102424(Actor *actor,s32 state);
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
    BtIntPtr func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    s32 _subaddieaudioquick_entrypoint_3(Actor *, f32 *, u32 *, f32);
    s32 _subaddieaudioquick_entrypoint_4(Actor *, f32 *, u32 *, u32 *);




    struct { u8 pad[8]; BT_BITFIELD_ORDER(u8 flag : 1, u8 : 7; u8 flag : 1); } *sp44;
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





    if (func_801022E4(arg0) == 0x246) {
        if (func_80101E14(arg0, 0.0f) != 0) {
            func_800C4B7C(D_808012A0_chboggyfatboy[func_800DC128(0, 5)]);
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_808012BC_chboggyfatboy[0]);
        }
        if (func_80101E14(arg0, 0.5f) != 0) {
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_808012CC_chboggyfatboy[0]);
        }
        if (func_80101E4C(arg0, D_808012AC_chboggyfatboy) != 0) {
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_808012E8_chboggyfatboy[0]);
        }
    }
}

/* extern */

void func_80800F40_chboggyfatboy(Actor *arg0) {
    s32 _suexpression_entrypoint_12(void *, s32, s32);
    s32 _suexpression_entrypoint_17(void *, s32);
    BtIntPtr _suexpression_entrypoint_7(Actor *, s32, s32);
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
    BtIntPtr func_800F54E4();
    s32 func_800F640C(BtIntPtr, s32);
    s32 func_800F64A4(BtIntPtr, s32);
    BtIntPtr sp1C;
    BtIntPtr temp_v0;

    temp_v0 = func_800F54E4();
    sp1C = temp_v0;
    if (func_800F64A4(temp_v0, 0x201) == 0) {
        return 0;
    }
    return func_800F640C(sp1C, arg0) > 0;
}
