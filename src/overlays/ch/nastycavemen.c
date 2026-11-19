#include "common.h"
BT_NATIVE_ONLY(s16 D_801275CA;)

void func_80102EC0(s32);
void func_8080067C_chnastycavemen(Actor *arg0);
void func_80800B10_chnastycavemen(Actor *arg0, void *arg1);
void *func_80107C2C(s32 *, s32, void *, s32, void *);
s32 func_808009BC_chnastycavemen(Actor *arg0, s32 arg1, s32 arg2);
void func_80800BE0_chnastycavemen(Actor *arg0);
void func_80800E68_chnastycavemen(u8 *arg0, s32 arg1);
void func_8080103C_chnastycavemen(s32 arg0);
s32 func_80800E90_chnastycavemen(Actor *arg0, s32 arg1, s32 arg2);

u32 D_808010B0_chnastycavemen[] = {
    0x00000000, 0x00000000, 0x40466666, 0x02F10001,
    0x4019999A, 0x02F20002, 0x40533333, 0x02F30001,
    0x40600000, 0x02F40002, 0x3F28F5C3, 0x02F00001,
    0x40600000, 0x02F40001
};

BtFnWord D_808010E8_chnastycavemen[] = {
    0x01DE01DA, 0x07EE0001, (BtFnWord)D_808010B0_chnastycavemen, (BtFnWord)func_80102EC0,
    (BtFnWord)func_8080067C_chnastycavemen, (BtFnWord)func_80800B10_chnastycavemen, 0x00000000, 0x00000000,
    0x00000000, 0x00040420, 0x00000000, 0x00000000,
    0x00580000, 0x00000000, (BtFnWord)func_80107C2C, 0x84005412,
    (BtFnWord)func_808009BC_chnastycavemen, 0x00000000
};

s32 D_80801130_chnastycavemen[] = {
    0x001305B6, 0x00000000
};

u32 D_80801138_chnastycavemen[] = {
    0x001305C6, 0x000D00CC, 0x00D90000
};

u32 D_80801144_chnastycavemen[] = {
    0x001305C7, 0x000D00CC, 0x00D90000
};

u32 D_80801150_chnastycavemen[] = {
    0x001304AA, 0x00000000
};

u32 D_80801158_chnastycavemen[] = {
    0x001305CE, 0x000A00E6, 0x00000000
};

u32 D_80801164_chnastycavemen[] = {
    0x3F19999A, 0x3F3D70A4, 0x3F6147AE, 0xBF800000
};

u32 D_80801174_chnastycavemen[] = {
    0x00130417, 0x00000000
};

u32 D_8080117C_chnastycavemen[] = {
    0x3E743958, 0x3EB74BC7, 0x3ECA0903, 0xBF800000
};

u32 D_8080118C_chnastycavemen[] = {
    0x00130417, 0x00000000
};

u32 D_80801194_chnastycavemen[] = {
    0x00000000, 0x00000000, 0x406CCCCD, 0x02F50000,
    0x406CCCCD, 0x02F50000, 0x3F222222, 0x02F60000,
    0x406CCCCD, 0x02F50000
};

BtFnWord D_808011BC_chnastycavemen[] = {
    0x015801DB, 0x07EE0001, (BtFnWord)D_80801194_chnastycavemen, (BtFnWord)func_80102EC0,
    (BtFnWord)func_80800BE0_chnastycavemen, (BtFnWord)func_80800E68_chnastycavemen, 0x0BB80000, 0x3F800000,
    0x00000000, 0x00040020, (BtFnWord)func_8080103C_chnastycavemen, 0x00000000,
    0x00000000, 0x00000000, (BtFnWord)func_80107C2C, 0x80004412,
    (BtFnWord)func_80800E90_chnastycavemen, 0x00000000
};

u32 D_80801204_chnastycavemen[] = {
    0x00000000, 0x00000000, 0x3E800000, 0x3F800000,
    0x3F000000, 0x00000000, 0x3F400000, 0x3F800000,
    0x3F800000, 0x00000000, 0x00000000
};

OSThread *chnastycavemen_entrypoint_0(void)
{

    return (OSThread *) D_808010E8_chnastycavemen;
}

/* extern */

int func_8080000C_chnastycavemen(void) {
    s32 _plsu_entrypoint_1(s32);
    return (func_80090178(0x10000) != 0) &&
        (_plsu_entrypoint_1(1) == -1) &&
        (_plsu_entrypoint_1(0xB) == -1);
}

/* extern */

int func_80800060_chnastycavemen(void) {
    u32 func_800F54E4(void);
    s32 func_800F640C(BtIntPtr, s32);
    s32 func_8008FE14();
    return (func_8008FE14() == 0x1D9) ||
        (func_800F640C(func_800F54E4(), 0x1D9) != 0);
}

int func_808000AC_chnastycavemen(int arg0, s32 *arg1, s32 *arg2) {
    switch (arg0) {
        default:
        case 1:
            *arg1 = 0xC5;
            *arg2 = 3;
            break;
        case 2:
            *arg1 = 0x112;
            *arg2 = 5;
            break;
        case 5:
            *arg1 = 0x112;
            *arg2 = 0xD;
            break;
    }
    return 1;
}    typedef struct { u8 pad0[0x436]; s16 unk436; } Objnastycavemen_D_80127194; /* offsets.py genstruct: fields from raw offsets on &D_80127194; rename once understood */

int func_8080010C_chnastycavemen(BtIntPtr arg0) {
    extern f32 D_80127194;
    void _gcgoto_entrypoint_1(u32 a0, u32 a1);
    s32 func_8008FD48();
    void func_800900D0(s32);
    void func_800904C8(s32);
    s32 sp24;
    s32 sp20;

    if (func_80800060_chnastycavemen() != 0) {
        func_800900D0(0x1D9);
    }
    switch (func_8008FD48()) {
        case 17:
            break;
        case 10:
        case 11:
            func_800904C8(0x97);
            break;
        default:
            func_808000AC_chnastycavemen(BT_DATA_FIELD(D_801275CA, ((Objnastycavemen_D_80127194 *)&D_80127194)->unk436), &sp24, &sp20);
            _gcgoto_entrypoint_1(sp24, sp20);
            break;
    }
    return 1;
}

/* extern */

int func_80800194_chnastycavemen(BtIntPtr arg0, BtIntPtr arg1) {
    s32 func_800F56AC(BtIntPtr);
    s32 func_800F6478(BtIntPtr);
    s32 func_800F64A4(BtIntPtr, s32);
    s32 func_800F651C(BtIntPtr);
    s32 func_800F6C5C(BtIntPtr);
    int func_800F72DC(BtIntPtr);
    s32 sp34;
    s32 sp30;
    s32 sp2C;
    s32 sp28;
    s32 sp24;
    s32 temp_t0;
    s32 temp_t1;
    s32 temp_t2;
    s32 temp_t8;
    s32 temp_t9;
    s32 var_v0;

    sp34 = func_800F64A4(arg1, 0x10000) == 0;
    sp30 = func_800F651C(arg1);
    sp2C = func_800F6C5C(arg1);
    sp28 = func_800F72DC(arg1);
    sp24 = func_800F56AC(arg1) == 0x10;
    return func_800F6478(arg1) && sp34 && sp24 && (sp28 || (sp2C && !sp30));
}

void func_80800268_chnastycavemen(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _capod_entrypoint_13(BtIntPtr arg0, BtIntPtr arg1, s32 arg2, s32 arg3);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    u32 _subaddiedialog_entrypoint_11(Unk80132ED0* arg0, u32 DialogId, u32 arg2, f32* CameraTarget, s16 arg4);
    s32 func_8008FD48();
    void func_800EE7F8(f32 *, f32 *);
    void *func_80100094(Actor *, u32);
    void func_80102424(Actor *, s32);
    s32 dialog;
    f32 *sp30;

    if (arg1 != arg0->unk70_10) {
        switch (arg1) {
        case 2:
            if (arg2 != 0) {
                _capod_entrypoint_13(arg0->unk0, NULL, 5, 0x2830);
            } else {
                _capod_entrypoint_13(arg0->unk0, NULL, 1, 0x30);
            }
            break;
        case 4:
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_80801130_chnastycavemen);
            _subaddiedialog_entrypoint_11(arg0->unk0, 0x17EE, 8, arg0->position, 0x96);
            break;
        case 3:
            if (func_8008FD48() == 0xB) {
                dialog = 0x1805;
            } else {
                dialog = func_80800060_chnastycavemen() ? 0x17DB : 0x17DA;
            }
            _subaddiedialog_entrypoint_11(arg0->unk0, dialog, 0x6C, arg0->position, 0x96);
            break;
        case 5:
            sp30 = func_80100094(arg0, 0);
            func_800EE7F8(sp30, arg0->position);
            func_800EE7F8(sp30 + 3, arg0->rotation);
            func_800EE7F8(sp30 + 6, sp30);
            func_800EE7F8(sp30 + 9, sp30 + 3);
            break;
        case 6:
            arg0->unk64_20 = 1;
            break;
        }
        func_80102424(arg0, arg1);
    }
}

/* extern */

void func_808003FC_chnastycavemen(Actor *arg0) {
    void _glcutDll_entrypoint_17(void);
    void func_800EE7F8(f32 *, f32 *);
    void *func_80100094(Actor *, u32);
    s32 func_80105230();
    void func_80105834(Actor *);
    s32 func_80105A5C(Actor *);
    void func_80105BAC(Actor *);
    void func_80800268_chnastycavemen(Actor *, s32, s32);
    f32 *data;

    data = func_80100094(arg0, 0);
    func_800EE7F8(arg0->position, data + 6);
    func_800EE7F8(arg0->rotation, data + 9);
    func_80105BAC(arg0);
    func_80105230(arg0, 0);
    func_80105834(arg0);
    func_800EE7F8(data + 6, arg0->position);
    func_800EE7F8(data + 9, arg0->rotation);
    func_800EE7F8(arg0->position, data);
    func_800EE7F8(arg0->rotation, data + 3);
    if (func_80105A5C(arg0) != 0) {
        func_80800268_chnastycavemen(arg0, 6, 1);
        _glcutDll_entrypoint_17();
    }
}

void func_808004C4_chnastycavemen(Actor *arg0) {
    void func_800E0AFC(void *, u8, f32, f32, f32, f32);
    void func_800E0C20(void *, u8, f32, f32, f32, f32);
    void func_800EF334(f32 *, f32);
    void func_800EFB24(void *, void *, void *);
    f32 func_800F1DCC(f32, f32);
    void *func_80100094(Actor *, u32);
    BtIntPtr func_8010262C(Unk80132ED0 *, u32);
    s32 pad;
    f32 vec[3];
    void *anim;
    f32 *data;

    if ((s32)arg0->unk70_10 >= 5 && *(s16 *)&arg0->unk0->unk10 != 0) {
        data = func_80100094(arg0, 0);
        anim = (void *)func_8010262C(arg0->unk0, 6);
        func_800EFB24(vec, data + 6, arg0->position);
        func_800EF334(vec, 0.1f);
        func_800E0C20(anim, 3, 1.0f, vec[0], vec[1], vec[2]);
        vec[0] = func_800F1DCC(data[9], arg0->rotation[0]);
        vec[1] = func_800F1DCC(data[10], arg0->rotation[1]);
        vec[2] = func_800F1DCC(data[11], arg0->rotation[2]);
        func_800E0AFC(anim, 3, 1.0f, vec[0], vec[1], vec[2]);
        func_800E0C20(anim, 0x56, -1.0f, -1.65625f, 20.34375f, -7.125f);
        func_800E0AFC(anim, 0x56, -1.0f, 10.59375f, 91.59375f, 0.0f);
        func_800E0C20(anim, 0x5A, -1.0f, -3.90625f, -13.9375f, 27.56325f);
        func_800E0AFC(anim, 0x5A, -1.0f, -91.203125f, -15.09375f, 13.09375f);
    }
}

void func_8080067C_chnastycavemen(Actor *arg0) {
    s32 _capod_entrypoint_14(void);
    void _chbadshad_entrypoint_1(void *arg0, void *arg1, f32 arg2);
    u32 _glcutDll_entrypoint_19(s32 arg0);
    void _subaddieaudioquick_entrypoint_2(Actor *arg0, f32 arg1[3], void *arg2);
    s32 _subaddieaudioquick_entrypoint_3(Actor *arg0, f32 arg1[3], void *arg2, f32 arg3);
    s32 _subaddieaudioquick_entrypoint_4(Actor *arg0, f32 *arg1, void *arg2, f32 *arg3);
    s32 func_8008FB10(f32 *arg0, f32 arg1, f32 arg2, f32 arg3);
    s32 func_800902E4(f32 *, f32, s32, Actor **);
    u32 func_800F54E4(void);
    s32 func_800F55FC(BtIntPtr arg0);
    void * func_80100094(Actor *arg0, u32 arg1);
    s32 func_80101DDC(Actor *arg0);
    s32 func_80101E14(Actor *arg0, f32 arg1);
    extern u32 D_80801138_chnastycavemen[], D_80801144_chnastycavemen[];
    extern u32 D_80801150_chnastycavemen[], D_80801158_chnastycavemen[];
    extern u32 D_80801164_chnastycavemen[], D_80801174_chnastycavemen[];
    extern u32 D_8080117C_chnastycavemen[], D_8080118C_chnastycavemen[];
    f32 *sp1C;
    int sp18;

    sp1C = func_80100094(arg0, 0);
    sp18 = _glcutDll_entrypoint_19(0x34);
    if (arg0->unk70_10 != 6) {
        func_8008FB10(arg0->position, 150.0f, 0.0f, 100.0f);
        if (func_800F55FC(func_800F54E4()) & 0x08000000) {
            func_800902E4(arg0->position, -1.0f, 0x1D9, &arg0);
        }
    }
    switch (arg0->unk70_10) {
    case 1:
        _subaddieaudioquick_entrypoint_3(arg0, arg0->position, D_80801138_chnastycavemen, 0.6f);
        _subaddieaudioquick_entrypoint_3(arg0, arg0->position, D_80801144_chnastycavemen, 0.05f);
        if (func_80800194_chnastycavemen((BtIntPtr)arg0, func_800F54E4())) {
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_80801150_chnastycavemen);
            func_80800268_chnastycavemen(arg0, 2, 0);
        }
        break;
    case 2:
        _subaddieaudioquick_entrypoint_3(arg0, arg0->position, D_80801158_chnastycavemen, 0.01f);
        if (func_80101DDC(arg0)) {
            func_80800268_chnastycavemen(arg0, sp18 ? 4 : 3, sp18);
        }
        break;
    case 3:
        _subaddieaudioquick_entrypoint_4(arg0, arg0->position, D_80801174_chnastycavemen, D_80801164_chnastycavemen);
        if (arg0->unk74_30 && arg0->unk74_29) {
            if (!func_8080010C_chnastycavemen((BtIntPtr)arg0)) {
                _capod_entrypoint_14();
            }
            arg0->unk74_29 = 0;
            arg0->unk74_30 = arg0->unk74_29;
        }
        break;
    case 4:
        _subaddieaudioquick_entrypoint_4(arg0, arg0->position, D_8080118C_chnastycavemen, D_8080117C_chnastycavemen);
        if (func_80101E14(arg0, 0.0367f)) {
            arg0->unk64_20 = 1;
        }
        if (func_80101DDC(arg0)) {
            func_80800268_chnastycavemen(arg0, 5, sp18);
        }
        break;
    case 5:
        func_808003FC_chnastycavemen(arg0);
        break;
    case 6:
        arg0->position[1] = -5000.0f;
        break;
    }
    func_808004C4_chnastycavemen(arg0);
    if (arg0->unk70_10 == 5) {
        _chbadshad_entrypoint_1(arg0, sp1C + 6, 1.0f);
    } else if (arg0->unk70_10 != 6) {
        _chbadshad_entrypoint_1(arg0, arg0->position, 1.0);
    }
}

/* extern */

void func_80800968_chnastycavemen(void) {
    extern f32 D_80127194;
    s32 func_800EA090(void);
    s32 sp1C;
    sp1C = func_800EA090();
    if (((BT_DATA_FIELD(D_801275CA, ((Objnastycavemen_D_80127194 *)&D_80127194)->unk436)) == 0) || ((sp1C != 0) && (func_80090178(0x10000) == 0))) {
        (BT_DATA_FIELD(D_801275CA, ((Objnastycavemen_D_80127194 *)&D_80127194)->unk436)) = (s16) sp1C;
    }
}

s32 func_808009BC_chnastycavemen(Actor *arg0, s32 arg1, s32 arg2) {
    Prop *_gccubesearch_entrypoint_1(u32, f32[3]);
    u32 _glcutDll_entrypoint_19(s32);
    void _gspropctrl_entrypoint_11(Prop *, f32[3]);
    s32 func_800DA298(s32);
    u32 func_800F54E4(void);
    s32 func_800F640C(BtIntPtr, s32);
    void func_800FFA88(Unk80132ED0 *);
    void func_80105A9C(Actor *, f32);
    void func_80108A30(s32, void *, f32, s32);
    struct NastyFlags { BT_BITFIELD_ORDER(u32 pad : 15, u32 rest : 16); u32 active : 1; BT_BITFIELD_ORDER(u32 rest : 16, u32 pad : 15); };
    s32 sp2C;
    Prop *sp28;

    switch (arg1) {
    case 0x95:
        sp2C = _glcutDll_entrypoint_19(0x34);
        func_80800968_chnastycavemen();
        func_80105A9C(arg0, 440.0f);
        ((struct NastyFlags *)&arg0->pad94)->active = 1;
        if (sp2C == 0) {
            if (func_800DA298(0x5A)) {
                func_800FFA88(arg0->unk0);
            } else if (func_800F640C(func_800F54E4(), 0x1D9) == 0) {
                sp28 = _gccubesearch_entrypoint_1(0x1C0, arg0->position);
                _gspropctrl_entrypoint_11(sp28, (f32 *)arg0->actorData);
                func_80108A30(0x1D9, arg0->actorData, sp28->FlagOrRotation, 0);
            }
        } else {
            func_80800268_chnastycavemen(arg0, 2, sp2C);
        }
        break;
    case 0xB:
        arg0->unk74_29 = 1;
        return 3;
    case 0x2E:
        arg0->unk74_30 = 1;
        break;
    default:
        return 0;
    }
    return 1;
}

/* extern */

void func_80800B10_chnastycavemen(Actor *arg0, void *arg1) {
    void func_800DF3E0(void);
    void func_800DF440(s32);
    void func_800DF744(s32, s32);
    void func_80101870(Actor *, void *);

    func_800DF3E0();
    func_800DF744(5, 2);
    func_800DF744(6, 2);
    func_800DF744(8, 1);
    func_800DF744(4, arg0->unk64_20 ? 0 : 2);
    func_800DF744(7, arg0->unk64_20 ? 2 : 0);
    if (arg0->unk70_10 == 5) {
        func_800DF440(0);
    }
    func_80101870(arg0, arg1);
}

OSThread *chnastycavemen_entrypoint_1(void)
{

    return (OSThread *) D_808011BC_chnastycavemen;
}

void func_80800BE0_chnastycavemen(Actor *arg0) {
    u32 _subaddiedialog_entrypoint_11(Unk80132ED0* arg0, u32 DialogId, u32 arg2, f32* CameraTarget, s16 arg4);
    s32 _subaddiedialog_entrypoint_5(f32 *, u32, u32, u32);
    s32 _sudeflect_entrypoint_1(f32 *arg0, f32 arg1, f32 arg2, f32 arg3, s32 arg4);
    void _suexpression_entrypoint_10(u32 *, Unk80132ED0 *, BtUIntPtr);
    s32 func_8008FF6C(void);
    void func_80090708(s32);
    f32 func_800F1DCC(f32, f32);
    f32 func_800F3780(f32, u8 *, s16);
    void *func_80100094(Actor *, u32);
    f32 func_80101F24(Actor *);
    void func_80102424(Actor *, s32);
    s32 func_80105230(Actor *, f32 *);
    void func_80105834(Actor *);
    s32 func_80105A5C(Actor *);
    void func_80105A9C(Actor *, f32);
    void func_80105BAC(Actor *);
    s32 func_8010C9FC(f32 *, s32, s32, s32);
    void *sp44;
    s32 dialog;
    s32 sp3C;

    sp44 = func_80100094(arg0, 1);
    _sudeflect_entrypoint_1(arg0->position, arg0->scale * 300.0f, 0.0f, arg0->scale * 150.0f, 14);
    _suexpression_entrypoint_10(sp44, arg0->unk0, 0);
    switch (arg0->unk70_10) {
        case 1:
            if (func_8010C9FC(arg0->position, 400, 400, -200) && !func_80090178(0x10000)) {
                if (func_80800060_chnastycavemen()) {
                    dialog = 0x17EF;
                } else if (func_8008FF6C() == 15) {
                    dialog = 0x17F0;
                } else {
                    dialog = 0x17F1;
                }
                _subaddiedialog_entrypoint_11(arg0->unk0, dialog, 10, arg0->position, 150);
                func_80102424(arg0, 2);
            }
            break;
        case 2:
            break;
        case 3:
            func_80105A9C(arg0, func_800F3780(func_80101F24(arg0), D_80801204_chnastycavemen, 5) * (150.0f * arg0->scale));
            func_80105BAC(arg0);
            func_80105834(arg0);
            func_80105230(arg0, NULL);
            arg0->rotation[1] = func_800F1DCC(arg0->rotation[1], 180.0f);
            if (func_80105A5C(arg0)) {
                func_80090708(0);
                func_80102424(arg0, 4);
            }
            break;
        case 4:
            if (func_8010C9FC(arg0->position, 600, 400, -200) && !func_80090178(0x10000)) {
                sp3C = 0;
                if (func_80800060_chnastycavemen()) {
                    sp3C = 0x17EF;
                } else if (func_8008FF6C() == 15) {
                    sp3C = 0x17F0;
                } else if (_subaddiedialog_entrypoint_5(arg0->position, 400, 45, 0)) {
                    sp3C = 0x1804;
                }
                if (sp3C) {
                    _subaddiedialog_entrypoint_11(arg0->unk0, sp3C, 10, arg0->position, 150);
                    func_80102424(arg0, 2);
                }
            }
            break;
    }
}

void func_80800E68_chnastycavemen(u8 *arg0, s32 arg1) {
    extern s32 func_801017D0;
    s32 func_80101808(void *, s32 *);
    func_80101808(arg0, &func_801017D0);
}

s32 func_80800E90_chnastycavemen(Actor *arg0, s32 arg1, s32 arg2) { s32 _suexpression_entrypoint_12(void *, s32, s32); s32 _suexpression_entrypoint_17(void *, s32); BT_IDO_ONLY(BtIntPtr _suexpression_entrypoint_7(Actor *, s32, s32);) BT_NATIVE_ONLY(void *_suexpression_entrypoint_7(Actor *, s32, s16);) void func_80090708(s32); s32 func_800DA298(s32); void func_800DF3E0(void); void func_800DF744(s32, s32); s32 func_800EA090(void); f32 func_800F1DCC(f32, f32); void *func_80100094(Actor *, u32); s32 func_801015D0(Actor *); void func_80102424(Actor *, s32); void func_8010573C(Actor *, f32); void *sp1C; f32 yaw; Actor *rotationActor; switch (arg1) { case 0x95: func_80100094(arg0, 1); func_80800968_chnastycavemen(); if (func_8080000C_chnastycavemen()) { func_80102424(arg0, 1); } else if (func_800DA298(0x184)) { func_8010573C(arg0, 1.0f); yaw = func_800F1DCC(arg0->rotation[1], 180.0f); rotationActor = arg0; rotationActor->rotation[1] = yaw; func_80102424(rotationActor, 4); } else if (func_800EA090() == 5) { func_80102424(arg0, 1); } _suexpression_entrypoint_7(arg0, 1, 0x96); sp1C = func_80100094(arg0, 1);
    _suexpression_entrypoint_12(sp1C, 0x42700000, 0x41700000); _suexpression_entrypoint_17(sp1C, 0x320); break; case 0x2E: switch (*(s16 *)&arg2) { case 0x17EF: case 0x17F0: func_8080010C_chnastycavemen((BtIntPtr)arg0); break; default: func_80090708(2); func_80102424(arg0, 3); break; } break; case 0x1F: func_801015D0(arg0); func_800DF3E0(); func_800DF744(5, 2); func_800DF744(6, 2); func_800DF744(8, 2); func_800DF744(4, 3); break; default: return 0; } return 1; }

void func_8080103C_chnastycavemen(s32 arg0) {
    _suexpression_entrypoint_8(arg0, 1);
}
