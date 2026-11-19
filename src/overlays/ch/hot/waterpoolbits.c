#include "common.h"

OSThread *chhotwaterpoolbits_entrypoint_0(void)
{
    extern ActorData D_80800930_chhotwaterpoolbits[];

    return (OSThread *) D_80800930_chhotwaterpoolbits;
}

OSThread *chhotwaterpoolbits_entrypoint_1(void)
{
    extern ActorData D_80800978_chhotwaterpoolbits[];

    return (OSThread *) D_80800978_chhotwaterpoolbits;
}

OSThread *chhotwaterpoolbits_entrypoint_2(void)
{
    extern ActorData D_808009C0_chhotwaterpoolbits[];

    return (OSThread *) D_808009C0_chhotwaterpoolbits;
}

OSThread *chhotwaterpoolbits_entrypoint_3(void)
{
    extern ActorData D_80800A08_chhotwaterpoolbits[];

    return (OSThread *) D_80800A08_chhotwaterpoolbits;
}

/* extern */

void func_80800030_chhotwaterpoolbits(BtIntPtr arg0) {
    s32 _chswitch_entrypoint_7(BtIntPtr, s32);
    void _chswitch_entrypoint_8(s32 *arg0, s32 arg1);
    void _chswitch_entrypoint_9(void *arg0);
    s32 sp1C;

    sp1C = _chswitch_entrypoint_7(arg0, 0x167);
    _chswitch_entrypoint_8(arg0, 0x200);
    if (sp1C != 0) {
        _chswitch_entrypoint_9(arg0);
    }
}

s32 func_80800078_chhotwaterpoolbits(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _chswitch_entrypoint_10(BtIntPtr, s32, s32);
    void _chswitch_entrypoint_9(void *arg0);
    u32 _subaddiedialog_entrypoint_11(Unk80132ED0* arg0, u32 DialogId, u32 arg2, f32* CameraTarget, s16 arg4);
    s32 func_800DA298(s32);
    s32 func_80101180(s32, s32, BtIntPtr);
    void func_80103110(Actor *, u32);

    if (arg1 == 7) {
        if (func_800DA298(0x31B) == 0) {
            _subaddiedialog_entrypoint_11(arg0->unk0, 0x12B0, 0xF, arg0->position, 0);
        } else {
            func_80101180(0x428, arg1, 0);
            func_80101180(0x439, 0xA, 0x427);
            func_80103110(arg0, 0);
            _chswitch_entrypoint_9(arg0);
        }
    } else {
        return _chswitch_entrypoint_10(arg0, arg1, arg2);
    }
    return 1;
}

/* extern */

void func_80800124_chhotwaterpoolbits(Actor *arg0) {
    s32 _chdoormake_entrypoint_3(Actor *, f32, f32, f32, s32, s32);
    void _chdoormake_entrypoint_5(Actor *, f32);
    void _chdoormake_entrypoint_6(Actor *, s32);
    void _chdoormake_entrypoint_8(void *, u32);
    BT_IDO_ONLY(s32 _chdoormake_entrypoint_9(Actor *, s32, s32, s32);) BT_NATIVE_ONLY(void _chdoormake_entrypoint_9(Actor *, s32, u16, s32);)
    if (_chdoormake_entrypoint_3(arg0, 0.0f, 90.0f, 300.0f, 0x60, 0x167) != 0) {
        _chdoormake_entrypoint_5(arg0, 2.0f);
        _chdoormake_entrypoint_6(arg0, 0x3E19999A);
        _chdoormake_entrypoint_9(arg0, 0, 0xD, 0x10);
        _chdoormake_entrypoint_8(arg0, 0xD);
    }
}

/* extern */

s32 func_808001A8_chhotwaterpoolbits(BtIntPtr arg0, s32 arg1, s32 arg2) {
    s32 _capod_entrypoint_14();
    s32 _chdoor_entrypoint_1(BtIntPtr);
    void _glcutDll_entrypoint_6(u32 arg0, u32 arg1);
    void func_800FFAB0(Actor *);
    if ((arg1 == 0xB) && (arg2 == 0xD)) {
        _capod_entrypoint_14();
        _glcutDll_entrypoint_6(0x1A7, 0x29);
        func_800FFAB0(arg0);
        return 4;
    }
    return _chdoor_entrypoint_1(arg0);
}                typedef struct { u8 pad0[0x18]; f32 unk18; f32 unk1C; } Objwaterpoolbits_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

void func_80800204_chhotwaterpoolbits(u8 *arg0) {
    void func_800F2E60(s32 *, s32 *);
    extern s32 D_80800A50_chhotwaterpoolbits[3];
    func_800F2E60((s32 *)(arg0 + 0x28), D_80800A50_chhotwaterpoolbits);
    (((Objwaterpoolbits_arg0 *)arg0)->unk1C) = 0.0f;
    (((Objwaterpoolbits_arg0 *)arg0)->unk18) = 127.0f;
}

void func_8080024C_chhotwaterpoolbits(Actor *arg0) {
    s32 func_800D9078(f32 *arg0);
    f32 func_800F10B4(f32 value, f32 in_min, f32 in_max, f32 out_min, f32 out_max);
    f32 func_800F12D4(f32 a, f32 b, f32 c, f32 d, f32 e);
    void func_800F2E60(s32 arg0[3], s32 arg1[3]);
    int func_800F3214(void *arg0, void *arg1, void *arg2, f32 arg3);
    void func_800FFAB0(Actor *arg0);
    void func_80101FDC(Actor *arg0, u32 arg1);
    void func_80103110(Actor *arg0, u32 arg1);
    void func_80800528_chhotwaterpoolbits(s32 *arg0);
    extern s32 D_80800A50_chhotwaterpoolbits[3];
    extern s32 D_80800A5C_chhotwaterpoolbits[3];
    struct WaterData {
        f32 alpha;
        f32 height;
        int unused[2];
        int color[3];
    };
    f32 height;
    f32 alpha;

    switch (arg0->unk70_10) {
    case 2:
        if (func_800D9078(&arg0->unk58)) {
            func_80101FDC(arg0, 3);
            func_80103110(arg0, 0);
        }
        func_800F3214(((struct WaterData *)arg0->actorData)->color, D_80800A50_chhotwaterpoolbits, D_80800A5C_chhotwaterpoolbits, func_800F10B4(arg0->unk58, 0.0f, 4.0f, 1.0f, 0.0f));
        ((struct WaterData *)arg0->actorData)->height = 0.0;
        break;
    case 3:
        func_800F2E60(((struct WaterData *)arg0->actorData)->color, D_80800A5C_chhotwaterpoolbits);
        ((struct WaterData *)arg0->actorData)->height = 0.0;
        ((struct WaterData *)arg0->actorData)->alpha = 100.0f;
        break;
    case 4:
        if (func_800D9078(&arg0->unk58)) {
            func_80101FDC(arg0, 3);
            func_80103110(arg0, 0);
        }
        height = func_800F12D4(arg0->unk58, 0.0f, 10.0f, -800.0f, 0.0f);
        ((struct WaterData *)arg0->actorData)->height = height;
        alpha = func_800F12D4(arg0->unk58, 0.0f, 10.0f, 100.0f, 127.0f);
        ((struct WaterData *)arg0->actorData)->alpha = alpha;
        func_800F2E60(((struct WaterData *)arg0->actorData)->color, D_80800A5C_chhotwaterpoolbits);
        break;
    case 5:
        func_800F2E60(((struct WaterData *)arg0->actorData)->color, D_80800A5C_chhotwaterpoolbits);
        ((struct WaterData *)arg0->actorData)->alpha = 100.0f;
        ((struct WaterData *)arg0->actorData)->height = -800.0f;
        func_800FFAB0(arg0);
        break;
    }
    func_80800528_chhotwaterpoolbits((s32 *)arg0);
}

s32 func_808003E0_chhotwaterpoolbits(Actor *arg0, s32 arg1, s32 arg2) {
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    s32 func_800DA298(s32);
    void func_800F2E60(s32 *, s32 *);
    void func_800FFAB0(Actor *);
    void func_80101FDC(Actor *, u32);
    void func_80103110(Actor *, u32);
    void func_80800528_chhotwaterpoolbits(s32 *);
    extern s32 D_80800A5C_chhotwaterpoolbits[3];
    extern s32 D_80800A68_chhotwaterpoolbits[8];
    struct WaterData {
        f32 alpha;
        f32 height;
        s32 unused[2];
        s32 color[3];
    };

    switch (arg1) {
        case 0xA:
            if (arg2 == 0x3E7) {
                func_80101FDC(arg0, 2);
                func_80103110(arg0, 1);
                arg0->unk58 = 4.0f;
            } else {
                _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_80800A68_chhotwaterpoolbits);
                func_80101FDC(arg0, 4);
                func_80103110(arg0, 1);
                arg0->unk58 = 10.0f;
            }
            break;
        case 0x95:
            if (func_800DA298(0x167)) {
                func_800F2E60(((struct WaterData *)arg0->actorData)->color, D_80800A5C_chhotwaterpoolbits);
                ((struct WaterData *)arg0->actorData)->alpha = 100.0f;
                ((struct WaterData *)arg0->actorData)->height = -800.0f;
                func_800FFAB0(arg0);
            } else if (func_800DA298(0x31B)) {
                func_800F2E60(((struct WaterData *)arg0->actorData)->color, D_80800A5C_chhotwaterpoolbits);
                ((struct WaterData *)arg0->actorData)->height = 0.0f;
                ((struct WaterData *)arg0->actorData)->alpha = 100.0f;
                func_80101FDC(arg0, 3);
            }
            func_80800528_chhotwaterpoolbits((s32 *)arg0);
            return 1;
        default:
            return 0;
    }
    return 1;
}

void func_80800528_chhotwaterpoolbits(s32 *arg0) {
    void _glid_entrypoint_0(u8 *arg0, s32 arg1, s32 (*arg2)(s16, u8 *, u8 *, s16, s32), BtIntPtr arg3);
    void *func_800BEA88(s32 i);
#ifdef BT_NATIVE
    void chhotwaterpoolbits_entrypoint_4(s32 arg0, Vtx *arg1, Vtx *arg2, s32 arg3, Unk80132ED0 *arg4);
#else
    extern s32 _chhotwaterpoolbits_entrypoint_4;
#endif
    BtIntPtr temp_v0;

    temp_v0 = func_800BEA88(1);
    if (temp_v0 != 0) {
        _glid_entrypoint_0(temp_v0, 0xA, &_chhotwaterpoolbits_entrypoint_4, *arg0);
    }
}

/* extern */

void chhotwaterpoolbits_entrypoint_4(s32 arg0, Vtx *arg1, Vtx *arg2, s32 arg3, Unk80132ED0 *arg4) {
    Actor *func_80106790(Unk80132ED0 *);
    struct WaterData {
        f32 alpha;
        f32 height;
        s32 unused[2];
        s32 color[3];
    };
    Actor *actor;
    Vtx *end;
    u32 alpha;
    s16 height;
    s32 i;

    actor = func_80106790(arg4);
    alpha = (u32)((struct WaterData *)actor->actorData)->alpha & 0xFF;
    height = (s16)(s32)((struct WaterData *)actor->actorData)->height;
    end = arg2 + arg3;
    while (arg2 < end) {
        for (i = 0; i != 3; i++) {
            arg2->v.cn[i] = (arg1->v.cn[i] * ((struct WaterData *)actor->actorData)->color[i]) >> 8;
        }
        arg2->v.cn[3] = alpha;
        arg2++;
        arg1++;
        arg2[-1].v.ob[1] = arg1[-1].v.ob[1] + height;
    }
}

void func_808006BC_chhotwaterpoolbits(Actor *arg0) {
    s32 func_800DA298(s32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800FFAB0(Actor *);
    if ((arg0->unk74_7 == 0x33) && (func_800DA298(0x31B) != 0)) {
        func_800FFAB0(arg0);
        return;
    }
    func_800EE7F8((f32 *)arg0->actorData, arg0->position);
}

void func_80800718_chhotwaterpoolbits(Actor *arg0) {
    void chhotwaterpoolbits_entrypoint_5(Actor *, f32);
    s32 func_800D9078(f32 *);
    void func_800EE7F8(f32 *, f32 *);
    BtUIntPtr func_800F54E4(void);
    s32 func_800F5578(BtIntPtr);
    s32 func_800F55FC(BtIntPtr);
    BT_IDO_ONLY(f32) BT_NATIVE_ONLY(s32) func_800F5628(BtIntPtr);
    void func_800F5A00(BtIntPtr, f32 *);
    s32 func_800F5C94(BtIntPtr);
    s32 func_800F5D18(BtIntPtr);
    s32 func_800F64A4(BtIntPtr, s32);
    s32 func_800F6A38(BtIntPtr);
    void func_800F7D90(BtIntPtr, s32, void *, s32);
    void func_80101FDC(Actor *, u32);
    BtIntPtr sp3C;
    s32 sp38;
    s32 sp34;
    s32 temp;
    f32 sp24[3];

    switch (arg0->unk70_10) {
    case 1:
        sp3C = func_800F54E4();
        if (func_800F6A38(sp3C)) {
            sp38 = func_800F5C94(sp3C);
            sp34 = func_800F5D18(sp3C);
            temp = func_800F64A4(sp3C, 2);
            if (sp38 != 0xC && sp38 != 0xE &&
                (sp34 != 0 || temp != 0) && func_800D9078(&arg0->unk58)) {
                func_800F7D90(sp3C, 0x52, arg0->actorData, 1);
                func_80101FDC(arg0, 2);
                chhotwaterpoolbits_entrypoint_5(arg0, 1.0f);
                arg0->unk58 = 1.0f;
            }
        } else {
            func_800F5A00(sp3C, sp24);
            BT_IDO_ONLY(sp24[1] = func_800F5628(sp3C);) BT_NATIVE_ONLY(((s32 *)sp24)[1] = func_800F5628(sp3C);)
            if (func_800F55FC(sp3C) & 0x08000000) {
                func_800EE7F8((f32 *)arg0->actorData, sp24);
            }
            arg0->unk58 = 0.04f;
        }
        break;
    case 2:
        if (func_800D9078(&arg0->unk58) &&
            func_800F5578(func_800F54E4()) > 0) {
            func_80101FDC(arg0, 1);
            arg0->unk58 = 0.04f;
        }
        break;
    }
}

void chhotwaterpoolbits_entrypoint_5(Actor *arg0, f32 arg1) {
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    BtIntPtr func_800BABB8(BtIntPtr, f32[3], f32[3], f32, s32[]);
    void func_800EE780(f32 *, f32 *, f32 *);
    BtUIntPtr func_800F54E4(void);
    void func_800F5A00(BtIntPtr, f32 *);
    void func_800F7620(BtIntPtr, f32, f32, f32);
    extern s32 D_80800A88_chhotwaterpoolbits[];
    extern s32 D_80800AC0_chhotwaterpoolbits[6];
    extern f32 D_80800AD8_chhotwaterpoolbits[3];
    f32 sp34[3];
    f32 sp28[3];
    BtIntPtr sp24;
    BtIntPtr temp_v0;

    temp_v0 = func_800F54E4();
    sp24 = temp_v0;
    func_800F7620(temp_v0, 1.0f, 0.5f, 0.4f);
    func_800F5A00(sp24, sp28);
    func_800EE780(sp34, sp28, D_80800AD8_chhotwaterpoolbits);
    func_800BABB8(0, sp28, sp34, arg1, D_80800A88_chhotwaterpoolbits);
    _subaddieaudioquick_entrypoint_2(arg0, sp28, D_80800AC0_chhotwaterpoolbits);
}
/* data_to_c.py: from asm/data/overlays/ch/hot/waterpoolbits.data.s */
extern u8 D_8011A270[];
void _chswitch_entrypoint_6();
void func_80105834(Actor*);
void func_80101870(Actor* arg0, void* arg1);
OSThread *func_80108ED0(void);
void func_80107C2C();
void _chdoor_entrypoint_0();
void func_80102EC0();
void func_8010A730();
ActorData D_80800930_chhotwaterpoolbits [1] BT_DATA(4, overlays_ch_hot_waterpoolbits, 0x0) = { { 825, 1063, 1976, 1, (void *)D_8011A270, (void (*)(struct Actor *))_chswitch_entrypoint_6, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 16384, 2060, 0, (BtIntPtr)func_80108ED0, 0, 0, (void (*)(struct Actor *))func_80800030_chhotwaterpoolbits, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32760, 11266, (void (*)(struct Actor *, long, long))func_80800078_chhotwaterpoolbits, 0 } };
ActorData D_80800978_chhotwaterpoolbits [1] BT_DATA(4, overlays_ch_hot_waterpoolbits, 0x48) = { { 172, 1064, 2375, 1, 0, (void (*)(struct Actor *))_chdoor_entrypoint_0, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 359, 0, 0, 2052, 0, 0, 0, 0, (void (*)(struct Actor *))func_80800124_chhotwaterpoolbits, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 11266, (void (*)(struct Actor *, long, long))func_808001A8_chhotwaterpoolbits, 0 } };
ActorData D_808009C0_chhotwaterpoolbits [1] BT_DATA(4, overlays_ch_hot_waterpoolbits, 0x90) = { { 344, 1081, 0, 1, 0, (void (*)(struct Actor *))func_8080024C_chhotwaterpoolbits, (void (*)(struct Actor *))func_80102EC0, (void (*)(long, long))func_8010A730, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, (void (*)(struct Actor *))func_80800204_chhotwaterpoolbits, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 3586, (void (*)(struct Actor *, long, long))func_808003E0_chhotwaterpoolbits, 0 } };
ActorData D_80800A08_chhotwaterpoolbits [1] BT_DATA(4, overlays_ch_hot_waterpoolbits, 0xD8) = { { 344, 1082, 0, 1, 0, (void (*)(struct Actor *))func_80800718_chhotwaterpoolbits, (void (*)(struct Actor *))func_80102EC0, (void (*)(long, long))func_8010A730, 196608000, 0, 0, 0, 0, 4, 0, 0, 0, 0, (void (*)(struct Actor *))func_808006BC_chhotwaterpoolbits, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 1538, 0, 0 } };
s32 D_80800A50_chhotwaterpoolbits[3] BT_DATA(4, overlays_ch_hot_waterpoolbits, 0x120) = { 255, 120, 120 };
s32 D_80800A5C_chhotwaterpoolbits [ 3 ] BT_DATA(4, overlays_ch_hot_waterpoolbits, 0x12C) = { 255, 255, 255 };
s32 D_80800A68_chhotwaterpoolbits[8] BT_DATA(4, overlays_ch_hot_waterpoolbits, 0x138) = { 1246570, 1572874, 12582924, 2304, 12583180, 1376307, 155975808, 0 };
s32 D_80800A88_chhotwaterpoolbits [14] BT_DATA(4, overlays_ch_hot_waterpoolbits, 0x158) = { 202375197, 165478445, 65537200, 720896, 1310720, 24578, 2228377, 16777984, 58720277, 153, 2752512, 655500, 10878991, 0 };
s32 D_80800AC0_chhotwaterpoolbits[6] BT_DATA(4, overlays_ch_hot_waterpoolbits, 0x190) = { 1246428, 852224, 21757973, 128, 6684674, 0 };
f32 D_80800AD8_chhotwaterpoolbits [ 3 ] BT_DATA(4, overlays_ch_hot_waterpoolbits, 0x1A8) = { 0.0f, -130.0f, 0.0f };
