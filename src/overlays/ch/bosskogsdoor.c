#include "common.h"

/* extern */

void func_80800000_chbosskogsdoor(Actor *arg0) {
    s32 func_800DA298(s32);
    void func_80101FDC(Actor *, u32);

    if (func_800DA298(0x1B8) != 0) {
        arg0->unk58 = arg0->unk74_7 / 10.0f;
        func_80101FDC(arg0, 9);
    } else {
        arg0->unk58 = 0.0f;
    }
    *(f32 *)&arg0->actorData[7] = arg0->position[1];
}                 typedef struct { u8 pad0[0x8]; f32 unk8; u8 padC[0x10]; f32 unk1C; f32 unk20; u8 pad24[0x10]; f32 unk34; u8 pad38[0x20]; f32 unk58; } Objbosskogsdoor_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

void func_80800090_chbosskogsdoor(u8 *arg0) {
    void _subaddieaudioloop_entrypoint_2(void *arg0);
    s32 _subaddieaudioloop_entrypoint_4(u8 *, u8 *, s32, s32 *);
    void _subaddieaudioquick_entrypoint_2(Actor *arg0, f32 arg1[3], void *arg2);
    BtIntPtr func_800BBCB8(u8 *, u8 *, s32, s32, s32 *);
    f32 func_800D8FF8();
    s32 func_800D90A4(u8 *);
    s32 func_800D91EC(u8 *, f32);
    void func_800DA544(s32 index);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    void func_80101FDC(Actor *, u32);
    s32 func_80103110(u8 *, s32);
    f32 func_80103EF4(u8 *);
    extern s32 D_808008B0_chbosskogsdoor[14];
    extern s32 D_808008E8_chbosskogsdoor[4];
    extern s32 D_808008F8_chbosskogsdoor[3];
    extern s32 D_80800904_chbosskogsdoor;
    extern s32 D_8080090C_chbosskogsdoor[3];
    f32 temp_f0;
    switch ((u32)*(u16 *)(arg0 + 0x72) >> 10) {
    case 1:
        break;
    case 2:
        if (func_800D90A4(arg0 + 0x2C) != 0) {
            func_80101FDC(arg0, 3);
            func_800DA544(0x1B8);
        }
        break;
    case 3:
        _subaddieaudioloop_entrypoint_4(arg0, arg0 + 4, 1, D_8080090C_chbosskogsdoor);
        temp_f0 = func_800D8FF8();
        (((Objbosskogsdoor_arg0 *)arg0)->unk20) += 1200.0f * temp_f0;
        if ((((Objbosskogsdoor_arg0 *)arg0)->unk20) > -220.0f) {
            (((Objbosskogsdoor_arg0 *)arg0)->unk20) = -220.0f;
            func_80101FDC(arg0, 4);
        }
        func_800BBCB8(arg0 + 0x18, arg0 + 0x18, 0x3F800000, 1, D_808008B0_chbosskogsdoor);
        break;
    case 4:
        _subaddieaudioloop_entrypoint_4(arg0, arg0 + 4, 1, D_8080090C_chbosskogsdoor);
        temp_f0 = func_800D8FF8();
        (((Objbosskogsdoor_arg0 *)arg0)->unk1C) += 1200.0f * temp_f0;
        if ((((Objbosskogsdoor_arg0 *)arg0)->unk1C) > 2480.0f) {
            (((Objbosskogsdoor_arg0 *)arg0)->unk1C) = 2480.0f;
            func_80101FDC(arg0, 5);
        }
        func_800BBCB8(arg0 + 0x18, arg0 + 0x18, 0x3F800000, 1, D_808008B0_chbosskogsdoor);
        break;
    case 5:
        _subaddieaudioloop_entrypoint_4(arg0, arg0 + 4, 1, D_8080090C_chbosskogsdoor);
        temp_f0 = func_800D8FF8();
        (((Objbosskogsdoor_arg0 *)arg0)->unk20) += 1200.0f * temp_f0;
        if ((((Objbosskogsdoor_arg0 *)arg0)->unk20) > 0.0f) {
            (((Objbosskogsdoor_arg0 *)arg0)->unk20) = 0.0f;
            func_80101FDC(arg0, 6);
        }
        func_800BBCB8(arg0 + 0x18, arg0 + 0x18, 0x3F800000, 1, D_808008B0_chbosskogsdoor);
        break;
    case 6:
        _subaddieaudioloop_entrypoint_4(arg0, arg0 + 4, 1, D_8080090C_chbosskogsdoor);
        temp_f0 = func_800D8FF8();
        (((Objbosskogsdoor_arg0 *)arg0)->unk1C) -= 1200.0f * temp_f0;
        if ((((Objbosskogsdoor_arg0 *)arg0)->unk1C) < 2204.0f) {
            func_80101FDC(arg0, 7);
            _subaddieaudioquick_entrypoint_2(arg0, arg0 + 4, &D_80800904_chbosskogsdoor);
            _subaddieaudioloop_entrypoint_2(arg0);
        }
        func_800BBCB8(arg0 + 0x18, arg0 + 0x18, 0x3F800000, 4, D_808008B0_chbosskogsdoor);
        break;
    case 7:
        if (func_800D91EC(arg0 + 0x58, (f32)((u32)*(u16 *)(arg0 + 0x76) >> 7) / 10.0f) != 0) {
            func_80101FDC(arg0, 8);
            _subaddieaudioloop_entrypoint_2(arg0);
            _subaddieaudioquick_entrypoint_2(arg0, arg0 + 4, D_808008F8_chbosskogsdoor);
        } else {
            _subaddieaudioloop_entrypoint_4(arg0, arg0 + 4, 1, D_808008E8_chbosskogsdoor);
        }
        break;
    case 9:
        func_80103110(arg0, 0);
        break;
    }
    temp_f0 = func_80103EF4(arg0);
    (((Objbosskogsdoor_arg0 *)arg0)->unk8) = (((Objbosskogsdoor_arg0 *)arg0)->unk34) + func_800F10B4((((Objbosskogsdoor_arg0 *)arg0)->unk58), 0.0f, (f32)((u32)*(u16 *)(arg0 + 0x76) >> 7) / 10.0f, 0.0f, temp_f0);
}

/* extern */

s32 func_80800458_chbosskogsdoor(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _capod_entrypoint_13(BtIntPtr arg0, BtIntPtr arg1, s32 arg2, s32 arg3);
    void func_800EFA4C(f32 *, f32, f32, f32);
    void func_80101FDC(Actor *, u32);
    switch (arg1) {
    case 0x49:
        if (arg2 == 0x40) {
            _capod_entrypoint_13(arg0->unk0, NULL, 1, 0x930);
            func_80101FDC(arg0, 2);
            func_800EFA4C((f32 *)arg0->actorData, -7472.0f, 2405.0f, -1240.0f);
            ((f32 *)arg0->actorData)[5] = 5.0f;
            return 1;
        }
        return 0;
    }
    return 0;
}

OSThread *chbosskogsdoor_entrypoint_0(void)
{
    extern ActorData D_80800918_chbosskogsdoor[];

    return (OSThread *) D_80800918_chbosskogsdoor;
}

/* extern */

void func_808004F4_chbosskogsdoor(Actor *arg0) {
    s32 func_800DA298(s32);
    s32 func_80102424(void *, s32);
    if (func_800DA298(0x1B8) != 0) {
        func_80102424(arg0, 4);
        arg0->unk74_30 = 1;
        return;
    }
    func_80102424(arg0, 1);
}

void func_80800544_chbosskogsdoor(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_2(Actor *arg0, f32 arg1[3], void *arg2);
    BtIntPtr func_800BBCB8(u8 *, u8 *, s32, s32, s32 *);
    f32 func_800D8FF8(void);
    void func_800EFA4C(f32 *, f32, f32, f32);
    s32 func_80101DDC(Actor *);
    s32 func_80101E14(Actor *, f32);
    f32 func_80101F24(Actor *);
    s32 func_80102424(void *, s32);
    s32 func_80103110(u8 *, s32);
    extern s32 D_808008B0_chbosskogsdoor[14];
    extern s32 D_80800988_chbosskogsdoor[3];
    extern s32 D_80800994_chbosskogsdoor[3];
    extern s32 D_808009A0_chbosskogsdoor[4];
    extern s32 D_808009B0_chbosskogsdoor[15];
    f32 sp34[3];

    switch (arg0->unk70_10) {
        case 1:
            if (arg0->unk64_20) {
                func_80102424(arg0, 2);
                _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_80800994_chbosskogsdoor);
                ((f32 *)arg0->actorData)[4] = 0.0f;
            } else {
                func_80103110(arg0, 0);
            }
            break;
        case 2:
            if (func_80101E14(arg0, 0.35f)) {
                _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_80800988_chbosskogsdoor);
            } else if (func_80101E14(arg0, 0.4f)) {
                _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_808009A0_chbosskogsdoor);
                func_800BBCB8(arg0->position, NULL, *(s32 *)&arg0->scale, 4, D_808009B0_chbosskogsdoor);
            }
            if (func_80101F24(arg0) > 0.4f) {
                func_800EFA4C(sp34, -247.0f, ((f32 *)arg0->actorData)[4] + 150.0f, 1720.0f);
                ((f32 *)arg0->actorData)[4] += 1200.0f * func_800D8FF8();
                func_800BBCB8(sp34, sp34, 0x3F800000, 2, D_808008B0_chbosskogsdoor);
            }
            if (func_80101DDC(arg0)) {
                arg0->unk58 = 2.0f;
                func_80102424(arg0, 3);
            }
            break;
        case 3:
        case 4:
            break;
    }
}

s32 func_80800714_chbosskogsdoor(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _capod_entrypoint_13(BtIntPtr arg0, BtIntPtr arg1, s32 arg2, s32 arg3);
    s32 _capod_entrypoint_14(void);
    void _glcutDll_entrypoint_6(u32, u32);
    u32 _subaddiedialog_entrypoint_11(Unk80132ED0* arg0, u32 DialogId, u32 arg2, f32* CameraTarget, s16 arg4);
    s32 func_800DA298(s32);
    u32 func_800F54E4(void);
    s32 func_800F64A4(BtIntPtr, s32);
    void func_80102204(Actor *);
    s32 func_80102424(void *, s32);
    s32 func_80103110(u8 *, s32);

    switch (arg1) {
        case 0x91:
            if (func_800F64A4(func_800F54E4(), 0x40)) {
                if (func_800DA298(0xA06) && arg0->unk70_10 == 1) {
                    arg0->unk64_20 = 1;
                    func_80103110(arg0, 1);
                    _capod_entrypoint_13(arg0->unk0, 0, 0x18, 0x810);
                    return 1;
                }
            } else if (!arg0->unk74_30) {
                _subaddiedialog_entrypoint_11(arg0->unk0, 0x1354, 6, arg0->position, 0);
                arg0->unk74_30 = 1;
            }
            return 1;
        case 0x95:
            func_80102424(arg0, arg0->unk70_10);
            func_80102204(arg0);
            return 1;
        case 0xB:
            if (arg2 == 0x18) {
                _capod_entrypoint_14();
                func_80102424(arg0, 4);
                _glcutDll_entrypoint_6(0x10F, 0x40);
                return 4;
            }
            return 3;
        default:
            return 0;
    }
}

OSThread *chbosskogsdoor_entrypoint_1(void)
{
    extern ActorData D_808009EC_chbosskogsdoor[];

    return (OSThread *) D_808009EC_chbosskogsdoor;
}
/* data_to_c.py: from asm/data/overlays/ch/bosskogsdoor.data.s */
void func_80105834(Actor*);
void func_80101870(Actor* arg0, void* arg1);
void func_80107C2C();
extern u8 D_80800960_chbosskogsdoor[];
void func_80108ED0();
s32 D_808008B0_chbosskogsdoor[14] BT_DATA(4, overlays_ch_bosskogsdoor, 0x0) = { 1903053, 1834008, -52428755, 19661200, 1446144, 1572864, 269824, 587202594, 4194393, 1638451, 1376256, 13369387, 8388736, 0 };
s32 D_808008E8_chbosskogsdoor[4] BT_DATA(4, overlays_ch_bosskogsdoor, 0x38) = { 1246504, 655552, 65736, 393216000 };
s32 D_808008F8_chbosskogsdoor[3] BT_DATA(4, overlays_ch_bosskogsdoor, 0x48) = { 1246368, 655513, 0 };
s32 D_80800904_chbosskogsdoor BT_DATA(4, overlays_ch_bosskogsdoor, 0x54) = 1246414;
u8 D_80800904_chbosskogsdoor__gap[4] BT_DATA(4, overlays_ch_bosskogsdoor, 0x58) = { 0 };
s32 D_8080090C_chbosskogsdoor[3] BT_DATA(4, overlays_ch_bosskogsdoor, 0x5C) = { 1246434, 655462, 0 };
ActorData D_80800918_chbosskogsdoor [1] BT_DATA(4, overlays_ch_bosskogsdoor, 0x68) = { { 280, 1021, 2176, 1, 0, (void (*)(struct Actor *))func_80800090_chbosskogsdoor, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 0, 3072, 0, 0, 0, 0, (void (*)(struct Actor *))func_80800000_chbosskogsdoor, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32760, 1026, (void (*)(struct Actor *, long, long))func_80800458_chbosskogsdoor, 0 } };
u8 D_80800960_chbosskogsdoor[40] BT_DATA(4, overlays_ch_bosskogsdoor, 0xB0) = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x00, 0x00, 0x00, 0x00, 0xD4, 0x00, 0x44, 0x3F, 0x80, 0x00, 0x00, 0x00, 0xD4, 0x00, 0x42, 0x3F, 0x00, 0x00, 0x00, 0x00, 0xD4, 0x00, 0x84, 0x3F, 0x00, 0x00, 0x00, 0x00, 0xD4, 0x00, 0x84 };
s32 D_80800988_chbosskogsdoor[3] BT_DATA(4, overlays_ch_bosskogsdoor, 0xD8) = { 1246294, 655564, 0 };
s32 D_80800994_chbosskogsdoor[3] BT_DATA(4, overlays_ch_bosskogsdoor, 0xE4) = { 1246491, 655488, 0 };
s32 D_808009A0_chbosskogsdoor[4] BT_DATA(4, overlays_ch_bosskogsdoor, 0xF0) = { 1246492, 655667, 65736, 393216000 };
s32 D_808009B0_chbosskogsdoor[15] BT_DATA(4, overlays_ch_bosskogsdoor, 0x100) = { 1903049, 2818560, 50331682, 16777600, 50332672, 1376256, 3342349, 6553625, 7, 2949100, 1310740, 1310760, 1310752, -2106695552, 0 };
ActorData D_808009EC_chbosskogsdoor [1] BT_DATA(4, overlays_ch_bosskogsdoor, 0x13C) = { { 281, 1020, 2174, 1, (void *)D_80800960_chbosskogsdoor, (void (*)(struct Actor *))func_80800544_chbosskogsdoor, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 0, 3080, 0, (BtIntPtr)func_80108ED0, 0, 0, (void (*)(struct Actor *))func_808004F4_chbosskogsdoor, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32760, 9216, (void (*)(struct Actor *, long, long))func_80800714_chbosskogsdoor, 0 } };
