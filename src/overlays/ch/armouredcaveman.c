#include "common.h"

OSThread *charmouredcaveman_entrypoint_0(void)
{
    extern ActorData D_80800B20_charmouredcaveman[];

    return (OSThread *) D_80800B20_charmouredcaveman;
}

/* extern */

void func_8080000C_charmouredcaveman(Actor *arg0) {
    s32 _glcutDll_entrypoint_20();
    s32 func_800D0B68(u32, u32);
    void func_800D1000(u32, u32, f32 *, u32, Unk80132ED0 *);
    s32 func_800DA298(s32);
    s32 func_800DA564(s32, s32);
    void func_800FFAB0(Actor *);
    void func_80102424(Actor *, s32);
    s32 func_8010B990(Actor *, s32);
    s32 temp_v0;

    temp_v0 = arg0->unk74_7 - 0x32;
    arg0->actorData[5] = temp_v0;
    arg0->actorData[4] = temp_v0 + 0x17A;
    if (_glcutDll_entrypoint_20() != 0) {
        func_80102424(arg0, 7);
        goto block_9;
    }
    if (func_800DA298(0x5D) != 0) {
        if ((func_800DA564(0x17A, 5) == arg0->actorData[5]) && (func_800D0B68(0x31, 1) == 0)) {
            func_800D1000(0x31, 1, arg0->position, 3, NULL);
        }
        func_800FFAB0(arg0);
        return;
    }
    if (func_800DA298(arg0->actorData[4]) != 0) {
        func_800FFAB0(arg0);
        return;
    }
block_9:
    func_8010B990(arg0, 0x1000);
}

void func_808000EC_charmouredcaveman(Actor *arg0) {
    typedef struct {
        u8 prefix[0x74];
        BT_BITFIELD_ORDER(u32 pad74_21 : 11, u32 pad74_0 : 20);
        u32 unk74_20 : 1;
        BT_BITFIELD_ORDER(u32 pad74_0 : 20, u32 pad74_21 : 11);
    } ArmouredCavemanFlags;
    s32 _subaddiefade_entrypoint_0(Actor *);
    void _subaddiefade_entrypoint_5(void *arg0);
    s32 _sudeflect_entrypoint_1(f32 *, f32, f32, f32, s32);
    s32 func_80101DDC(Actor *);
    void func_80102424(Actor *, s32);
    void func_80102BF8(void *, f32, f32, f32);
    s32 func_8010C9B0(f32 *, s32);
    f32 func_8010CD28(Actor *);
    s32 func_8010D23C(void);
    s32 func_8010D278();
    void func_80800640_charmouredcaveman(Actor *);
    void func_8080072C_charmouredcaveman(Actor *);
    void func_808008B0_charmouredcaveman(Actor *);
    void func_8080092C_charmouredcaveman(Actor *);
    void func_8080095C_charmouredcaveman(Actor *);
    void func_808009D4_charmouredcaveman(Actor *);
    s32 sp34;
    s32 sp30;
    s32 deflected;
    s32 state;

    sp34 = 1;
    sp30 = func_8010D23C();
    deflected = 0;
    if (arg0->unk70_10 != 6) {
        deflected = _sudeflect_entrypoint_1(arg0->position, 250.0f, -10.0f, 140.0f, 10) & 8;
    }
    switch (arg0->unk70_10) {
    case 1:
        func_80800640_charmouredcaveman(arg0);
        if (deflected) {
            func_808009D4_charmouredcaveman(arg0);
        }
        if (sp30 && func_8010D278() != 0x11 && func_8010C9B0(arg0->position, 400)) {
            arg0->unk64_19 = 0;
            func_80102424(arg0, 4);
        }
        break;
    case 2:
        func_80800640_charmouredcaveman(arg0);
        sp34 = 0;
        break;
    case 3:
        func_8080072C_charmouredcaveman(arg0);
        if (func_80101DDC(arg0)) {
            state = arg0->unk64_20 ? 2 : 1;
            func_80102424(arg0, state);
        }
        break;
    case 4:
        func_808008B0_charmouredcaveman(arg0);
        if (func_80101DDC(arg0)) {
            if (arg0->unk64_19) {
                func_8080095C_charmouredcaveman(arg0);
            } else {
                func_80102424(arg0, 1);
            }
        }
        break;
    case 5:
        sp34 = 0;
        func_8080092C_charmouredcaveman(arg0);
        if (func_80101DDC(arg0)) {
            func_80102424(arg0, 6);
            _subaddiefade_entrypoint_5(arg0);
        }
        break;
    case 6:
        sp34 = 0;
        state = _subaddiefade_entrypoint_0(arg0) == 0 ? 0 : 1;
        arg0->unk64_16 = state; ((ArmouredCavemanFlags *)arg0)->unk74_20 = state;
        break;
    case 7:
        func_8080072C_charmouredcaveman(arg0);
        break;
    }
    if (sp34 && sp30) {
        if (func_8010D278() != 0x11) {
            arg0->unk54 = func_8010CD28(arg0);
        }
        func_80102BF8(arg0, 0.3f, 3.0f, 300.0f);
    }
}

typedef struct {
    u8 pad0[0x18];
    BT_BITFIELD_ORDER(u32 pad18_21 : 11, u32 pad18_0 : 5);
    BT_BITFIELD_ORDER(u32 state : 4, u32 index : 11);
    u32 pad18_16 : 1;
    BT_BITFIELD_ORDER(u32 index : 11, u32 state : 4);
    BT_BITFIELD_ORDER(u32 pad18_0 : 5, u32 pad18_21 : 11);
    u32 unk1C;
    u32 unk20;
    BT_BITFIELD_ORDER(u32 id : 10, u32 pad24_0 : 22);
    BT_BITFIELD_ORDER(u32 pad24_0 : 22, u32 id : 10);
} ArmouredCavemanMarker;

typedef union {
    Unk80132ED0 *marker;
    s16 dialog;
} ArmouredCavemanEvent;

s32 func_80800370_charmouredcaveman(Actor *arg0, s32 arg1, ArmouredCavemanEvent arg2) {
    void _chbaddiesetup_entrypoint_5(void *, BtIntPtr, s32, s32, s32, s32);
    extern Actor *_chbaddiesetup_entrypoint_10(s32 id, s32 x, s32 y, s32 z, s32 yaw);
    void _gcdialogcamera_entrypoint_3(f32 *arg0, f32 arg1);
    void _subaddieDll_entrypoint_4(void *arg0, s32 arg1);
    u32 _subaddiedialog_entrypoint_11(Unk80132ED0* arg0, u32 DialogId, u32 arg2, f32* CameraTarget, s16 arg4);
    s32 _sueggmisc_entrypoint_0();
    void func_800D1000(u32, u32, f32 *, u32, Unk80132ED0 *);
    void func_800DA544(s32 index);
    s32 func_800DA564(s32, s32);
    void func_800DA7A8(s32 startIndex, s32 set, s32 length);
    s32 func_800DA980(s32, s32);
    void func_800EC398(Unk80132ED0 *, f32 *);
    f32 func_800F1DF4(f32 *, f32 *);
    f32 func_800F2094(f32, f32);
    s32 func_800F64A4(BtIntPtr, s32);
    void func_800FFAB0(Actor *);
    void func_80102424(Actor *, s32);
    void func_80103DFC(Actor *, f32 *);
    void func_80109600(void *, void *);
    void func_8010A570(Actor *);
    void func_8010A590(Actor *);
    void func_808009D4_charmouredcaveman(Actor *);
    extern s32 D_80800B68_charmouredcaveman[4];
    Unk80132ED0 *sp5C;
    f32 sp50[3];
    s32 sp4C;
    f32 sp40[3];
    s32 sp3C;
    s32 sp38;
    BtIntPtr event;

    switch (arg1) {
    case 0x40:
        sp5C = arg2.marker;
        if (((ArmouredCavemanMarker *)sp5C)->id == 0x270) {
            if (_sueggmisc_entrypoint_0(sp5C) == 0 && ((ArmouredCavemanMarker *)arg0->unk0)->state == 1) {
                func_800EC398(sp5C, sp50);
                if (func_800F2094(func_800F1DF4(arg0->position, sp50), arg0->rotation[1]) > 100.0f) {
                    func_80109600(arg0, sp5C);
                    func_8010A570(arg0);
                    func_80102424(arg0, 5);
                    _subaddieDll_entrypoint_4(arg0, 1);
                    func_80103DFC(arg0, sp40);
                    _chbaddiesetup_entrypoint_5(_chbaddiesetup_entrypoint_10, 4, ((s32 *)sp40)[0], ((s32 *)sp40)[1], ((s32 *)sp40)[2], *(s32 *)&arg0->rotation[1]);
                    sp3C = func_800DA564(0x17A, 5) == 0;
                    func_800DA544(arg0->actorData[4]);
                    if (sp3C) {
                        sp38 = 0x17E3;
                    } else if (func_800DA564(0x17A, 5) == 0x1F) {
                        sp38 = 0x1806;
                        func_800DA544(0x5D);
                        func_800DA7A8(0x17A, arg0->actorData[5], 5);
                        func_800D1000(0x31, 1, arg0->position, 1, NULL);
                    } else {
                        sp38 = 0x17E4;
                    }
                    _subaddiedialog_entrypoint_11(arg0->unk0, sp38, 0x44, arg0->position, 0xA6);
                    arg0->unk74_17 = 0;
                    return 1;
                }
            }
        }
    case 0x3E:
    case 0x3F: {
        event = (BtIntPtr)arg2.marker;
        if (((ArmouredCavemanMarker *)event)->id == 0 && func_800F64A4(((ArmouredCavemanMarker *)event)->index, 0x10000)) {
            return 0;
        }
        func_808009D4_charmouredcaveman(arg0);
        func_80109600(arg0, arg2.marker);
        return 1;
    }
    case 0x30:
        return 5 - func_800DA980(0x17A, 5);
    case 0x2E: {
        event = arg2.dialog;
        if (event == 0x17E2) {
            func_800DA544(0x66C);
            arg0->unk64_20 = 0;
            func_8010A590(arg0);
            func_80102424(arg0, 1);
        } else {
            func_800FFAB0(arg0);
        }
        break;
    }
    case 0x52:
        _gcdialogcamera_entrypoint_3(D_80800B68_charmouredcaveman, arg0->scale);
        break;
    default:
        return 0;
    }
    return 1;
}

void func_80800640_charmouredcaveman(Actor *arg0) {
    s32 _subaddieaudioquick_entrypoint_3(Actor *, f32 *, u32 *, f32);
    s32 _subaddieaudioquick_entrypoint_4(Actor *, f32 *, u32 *, u32 *);
    BtIntPtr func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    void func_800EE7F8(f32 *, f32 *);
    extern s32 D_80800B78_charmouredcaveman[11];
    extern u32 D_80800BA4_charmouredcaveman[3]; extern u32 D_80800BB0_charmouredcaveman[3]; extern u32 D_80800BBC_charmouredcaveman[4];
    s32 sp44;
    f32 sp38[3];
    f32 sp2C[3];
    sp44 = _subaddieaudioquick_entrypoint_4(arg0, arg0->position, D_80800BA4_charmouredcaveman, D_80800BBC_charmouredcaveman);
    _subaddieaudioquick_entrypoint_3(arg0, arg0->position, D_80800BB0_charmouredcaveman, 0.83f);
    if (sp44 && arg0->unk7C_12) {
    func_800EE7F8(sp38, arg0->position);
    sp38[1] += arg0->scale * 180.0f;
    func_800EE7F8(sp2C, sp38);
    sp2C[1] -= arg0->scale * 10.0f;
    func_800BBCB8(sp38, sp2C, 1.0f, 8, D_80800B78_charmouredcaveman);
    }
}
typedef struct { f32 values[4]; } FloatTable; typedef struct { s16 values[4]; } ShortTable;
void func_8080072C_charmouredcaveman(Actor *arg0) {
    void func_800C301C(u8, s32);
    void func_800C3058(u8, s32);
    void func_800C31DC(u8, f32);
    void func_800C3BDC(u8);
    u8 func_800C4350(u8 index, f32 *position, s32 *command_list);
    f32 func_800DC178(f32, f32);
    s32 func_80101E14(Actor *, f32);


    extern FloatTable D_80800BCC_charmouredcaveman;
    extern FloatTable D_80800BDC_charmouredcaveman;
    extern ShortTable D_80800BEC_charmouredcaveman;
    extern ShortTable D_80800BF4_charmouredcaveman;
    extern s32 D_80800BFC_charmouredcaveman[3];
    FloatTable times = D_80800BCC_charmouredcaveman;
    FloatTable volumes = D_80800BDC_charmouredcaveman;
    ShortTable sounds = D_80800BEC_charmouredcaveman;
    ShortTable rates = D_80800BF4_charmouredcaveman;
    s32 i;

    if (arg0->unk5F == 0) {
        arg0->unk5F = func_800C4350(0, arg0->position, D_80800BFC_charmouredcaveman);
    }
    for (i = 0; i < 4; i++) {
        if (func_80101E14(arg0, times.values[i])) {
            func_800C301C(arg0->unk5F, sounds.values[i]);
            func_800C31DC(arg0->unk5F, volumes.values[i] + func_800DC178(-0.02f, 0.02f));
            func_800C3058(arg0->unk5F, rates.values[i]);
            func_800C3BDC(arg0->unk5F);
            return;
        }
    }
}

void func_808008B0_charmouredcaveman(Actor *arg0) {
    s32 _subaddieaudioquick_entrypoint_3(Actor *, f32 *, u32 *, f32);
    void func_80018820(s32, f32, f32);
    s32 func_800E15CC(s32, f32, f32);
    extern u32 D_80800C08_charmouredcaveman[3]; extern u32 D_80800C14_charmouredcaveman[3];
    f32 *position[1];

    position[0] = arg0->position;
    _subaddieaudioquick_entrypoint_3(arg0, position[0], D_80800C08_charmouredcaveman, 0.3f);
    if (_subaddieaudioquick_entrypoint_3(arg0, position[0], D_80800C14_charmouredcaveman, 0.5f)) {
        func_80018820(0, 1.0f, 0.4f);
        func_800E15CC(0, 20.0f, 0.85f);
    }
}

void func_8080092C_charmouredcaveman(Actor *arg0) {
    s32 _subaddieaudioquick_entrypoint_3(Actor *, f32 *, u32 *, f32);
    extern u32 D_80800C20_charmouredcaveman[4];
    _subaddieaudioquick_entrypoint_3(arg0, arg0->position, D_80800C20_charmouredcaveman, 0.1f);
}

/* extern */

void func_8080095C_charmouredcaveman(Actor *arg0) {
    u32 _subaddiedialog_entrypoint_11(Unk80132ED0* arg0, u32 DialogId, u32 arg2, f32* CameraTarget, s16 arg4);
    s32 func_800DA298(s32);
    void func_80102424(Actor *, s32);
    void func_8010A570(Actor *);
    arg0->unk64_19 = 0;
    if (func_800DA298(0x66C) == 0) {
        _subaddiedialog_entrypoint_11(arg0->unk0, 0x17E2, 0xE, arg0->position, 0xA6);
        arg0->unk64_20 = 1;
        func_8010A570(arg0);
    }
    func_80102424(arg0, 3);
}

/* extern */

void func_808009D4_charmouredcaveman(Actor *arg0) {
    void func_8080095C_charmouredcaveman(Actor *);
    if (arg0->unk70_10 != 3) {
        if (arg0->unk70_10 == 4) {
            arg0->unk64_19 = 1;
            return;
        }
        func_8080095C_charmouredcaveman(arg0);
    }
}
/* data_to_c.py: from asm/data/overlays/ch/armouredcaveman.data.s */
extern u8 D_80800AE0_charmouredcaveman[];
void func_80105834(Actor*);
void func_80101870(Actor* arg0, void* arg1);
void func_80108ED0();
void func_80107C2C();
u8 D_80800AE0_charmouredcaveman[64] BT_DATA(4, overlays_ch_armouredcaveman, 0x0) = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0xA3, 0x33, 0x33, 0x04, 0x30, 0x00, 0x01, 0x40, 0xA3, 0x33, 0x33, 0x04, 0x30, 0x00, 0x01, 0x40, 0x4C, 0xCC, 0xCD, 0x04, 0x31, 0x00, 0x02, 0x3F, 0x8C, 0xCC, 0xCD, 0x04, 0x32, 0x00, 0x02, 0x3F, 0xC0, 0x00, 0x00, 0x04, 0x33, 0x00, 0x02, 0x3F, 0xC0, 0x00, 0x00, 0x04, 0x33, 0x00, 0x84, 0x40, 0x4C, 0xCC, 0xCD, 0x04, 0x31, 0x00, 0x01 };
ActorData D_80800B20_charmouredcaveman [1] BT_DATA(4, overlays_ch_armouredcaveman, 0x40) = { { 787, 939, 2303, 1, (void *)D_80800AE0_charmouredcaveman, (void (*)(struct Actor *))func_808000EC_charmouredcaveman, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 98304000, 1075419546, 0, 0, 16512, 292, 0, (BtIntPtr)func_80108ED0, 0, 0, (void (*)(struct Actor *))func_8080000C_charmouredcaveman, (void (*)(void *, long, void *, long, void *))func_80107C2C, -31728, 17424, (void (*)(struct Actor *, long, long))func_80800370_charmouredcaveman, 0 } };
s32 D_80800B68_charmouredcaveman[4] BT_DATA(4, overlays_ch_armouredcaveman, 0x88) = { 1128792064, 1128792064, 1128792064, 1123024896 };
s32 D_80800B78_charmouredcaveman[11] BT_DATA(4, overlays_ch_armouredcaveman, 0x98) = { 1903075, 1376256, 10027042, 3670082, 2293806, 2818150, 8388653, 19661200, 720916, 1966085, 0 };
u32 D_80800BA4_charmouredcaveman[3] BT_DATA(4, overlays_ch_armouredcaveman, 0xC4) = { 0x130415, 0xD00F3, 0x10C0000 };
u32 D_80800BB0_charmouredcaveman[3] BT_DATA(4, overlays_ch_armouredcaveman, 0xD0) = { 0x13041D, 0xD010C, 0x1260000 };
u32 D_80800BBC_charmouredcaveman[4] BT_DATA(4, overlays_ch_armouredcaveman, 0xDC) = { 0x3EE147AE, 0x3F0A3D71, 0x3F1EB852, 0xBF800000 };
FloatTable D_80800BCC_charmouredcaveman BT_DATA(4, overlays_ch_armouredcaveman, 0xEC) = { { 0.15f, 0.25f, 0.35f, 0.45f } };
FloatTable D_80800BDC_charmouredcaveman BT_DATA(4, overlays_ch_armouredcaveman, 0xFC) = { { 0.9f, 1.1f, 1.05f, 1.0f } };
ShortTable D_80800BEC_charmouredcaveman BT_DATA(4, overlays_ch_armouredcaveman, 0x10C) = { { 1468, 1469, 1469, 1468 } };
ShortTable D_80800BF4_charmouredcaveman BT_DATA(4, overlays_ch_armouredcaveman, 0x114) = { { 28000, 22000, 22000, 22000 } };
s32 D_80800BFC_charmouredcaveman[3] BT_DATA(4, overlays_ch_armouredcaveman, 0x11C) = { 50724865, 13110200, 458752 };
u32 D_80800C08_charmouredcaveman[3] BT_DATA(4, overlays_ch_armouredcaveman, 0x128) = { 0x1305BC, 0xD0099, 0xB30000 };
u32 D_80800C14_charmouredcaveman[3] BT_DATA(4, overlays_ch_armouredcaveman, 0x134) = { 0x130417, 0xD00F3, 0x10C0000 };
u32 D_80800C20_charmouredcaveman[4] BT_DATA(4, overlays_ch_armouredcaveman, 0x140) = { 0x1305B6, 0xD00F3, 0x10C0018, 0 };
