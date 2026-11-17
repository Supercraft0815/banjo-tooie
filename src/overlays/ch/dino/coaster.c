#include "common.h"

OSThread *chdinocoaster_entrypoint_0(void)
{
    extern ActorData D_808004E0_chdinocoaster[];

    return (OSThread *) D_808004E0_chdinocoaster;
}                typedef struct { u8 pad0[0x28]; f32 unk28; u8 pad2C[0xC]; f32 unk38; u8 pad3C[0x14]; f32 unk50; } Objcoaster_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

/* extern */

void func_8080000C_chdinocoaster(void *arg0) {
    s32 _sucoaster_entrypoint_0(void *, s32);
    void func_80102FDC(void *arg0, f32 arg1);
    _sucoaster_entrypoint_0(arg0, 0);
    func_80102FDC(arg0, (((Objcoaster_arg0 *)arg0)->unk38) * 1.25f);
    (((Objcoaster_arg0 *)arg0)->unk50) = 0.0f;
    (((Objcoaster_arg0 *)arg0)->unk28) = 0.0f;
}

void func_80800064_chdinocoaster(Actor *arg0) {
    extern s32 D_80800528_chdinocoaster[];
    s32 _subaddiedialog_entrypoint_7(BtIntPtr, BtIntPtr, s32 *);
    s32 _sucoaster_entrypoint_10(Actor *, s32);
    void _sucoaster_entrypoint_2(Actor *arg0);
    void _sucoaster_entrypoint_22(void *arg0);
    f32 func_800D8FF8(void);
    f32 func_800F1FF0(f32, f32, f32, f32, f32);
    int func_800F20BC(f32, f32, f32);
    s32 func_80101E14(Actor *, f32);
    void func_80102BF8(void *, f32, f32, f32);
    void func_8010A570(Actor *);
    f32 func_8010CD28(Actor *);
    void func_808002CC_chdinocoaster(Actor *);
    f32 dt;

    switch (arg0->unk70_10) {
        case 19:
            arg0->unk54 = func_8010CD28(arg0);
            func_80102BF8(arg0, 0.1f, 1.5f, 400.0f);
            _sucoaster_entrypoint_22(arg0);
            break;
        case 20:
            dt = func_800D8FF8();
            arg0->rotation[1] = func_800F1FF0(arg0->rotation[1],
                ((f32 *)arg0->actorData)[5], 0.12f, dt * 8.0f, dt * 200.0f);
            if (func_800F20BC(arg0->rotation[1], ((f32 *)arg0->actorData)[5], 4.0f)) {
                _sucoaster_entrypoint_10(arg0, 3);
            }
            _sucoaster_entrypoint_22(arg0);
            break;
        case 9:
            if (func_80101E14(arg0, 0.4f)) {
                ((f32 *)arg0->actorData)[3] = 800.0f;
            }
            _sucoaster_entrypoint_2(arg0);
            break;
        default:
            if (!_subaddiedialog_entrypoint_7((BtIntPtr)arg0, (BtIntPtr)arg0->position, D_80800528_chdinocoaster)) {
                _sucoaster_entrypoint_2(arg0);
            } else {
                ((f32 *)arg0->actorData)[5] = arg0->rotation[1];
                func_8010A570(arg0);
            }
            break;
    }
    func_808002CC_chdinocoaster(arg0);
}

s32 func_808001C8_chdinocoaster(Actor *arg0, s32 arg1, s32 arg2) {
    extern s32 D_80800468_chdinocoaster[];
    extern s32 D_80800544_chdinocoaster[];
    void _gcdialogcamera_entrypoint_3(f32 *arg0, f32 arg1);
    void _gcdialogcamera_entrypoint_5(BtIntPtr arg0);
    s32 _sucoaster_entrypoint_21(Actor *, s32, s32);
    void func_8009032C(s32);
    void func_800EFA4C(f32 *, f32, f32, f32);
    void func_80101074(void *);
    void func_80101FDC(Actor *, u32);
    void func_8010A590(Actor *);
    f32 func_8010CD28(Actor *);
    f32 sp2C[3];

    switch (arg1) {
        case 0x2E:
            func_80101FDC(arg0, 0x14);
            func_8010A590(arg0);
            if (((s16 *)&arg2)[0] == 0x17B8) {
                func_8009032C(0x20);
            }
            break;
        case 0x38:
            func_80101074(D_80800468_chdinocoaster);
            return 0xA;
        case 0x52:
            func_800EFA4C(sp2C, 0.0f, func_8010CD28(arg0), 0.0f);
            _gcdialogcamera_entrypoint_3(D_80800544_chdinocoaster, arg0->scale);
            _gcdialogcamera_entrypoint_5(sp2C);
            break;
        case 0x95:
            arg0->unk64_20 = 0;
        default:
            return _sucoaster_entrypoint_21(arg0, arg1, arg2);
    }
    return 1;
}

void func_808002CC_chdinocoaster(Actor *arg0) {
    f32 func_800D8FF8(void);
    s32 func_800F1B78(f32 *, f32 *, f32, f32);
    f32 func_800F1F38(f32, f32, f32);
    s32 func_801051C8(Actor *, f32 *);
    f32 sp34[3];
    f32 sp28[3];
    f32 sp24;

    func_801051C8(arg0, sp28);
    if (func_800F1B78(sp34, sp28, arg0->rotation[1], 1.0f)) {
        arg0->unk50 = sp34[0];
        ((f32 *)arg0->actorData)[4] = sp34[2];
    } else {
        arg0->unk50 = 0.0f;
        ((f32 *)arg0->actorData)[4] = 0.0f;
    }
    if (!arg0->unk64_20) {
        arg0->unk64_20 = 1;
        arg0->rotation[0] = arg0->unk50;
        arg0->rotation[2] = ((f32 *)arg0->actorData)[4];
    } else {
        sp24 = func_800D8FF8();
        arg0->rotation[0] = func_800F1F38(arg0->rotation[0], arg0->unk50, sp24 * 30.0f);
        arg0->rotation[2] = func_800F1F38(arg0->rotation[2], ((f32 *)arg0->actorData)[4], sp24 * 30.0f);
    }
}
/* data_to_c.py: from asm/data/overlays/ch/dino/coaster.data.s */
extern u8 D_808003C0_chdinocoaster[];
void func_80105834(Actor*);
void _sucoaster_entrypoint_20();
void _sucoaster_entrypoint_1();
OSThread *_sucoasterhit_entrypoint_0(void);
void func_80107C2C();
u8 D_808003C0_chdinocoaster[168] BT_DATA(4, overlays_ch_dino_coaster, 0x0) = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x41, 0x05, 0x47, 0xAE, 0x04, 0x01, 0x00, 0x01, 0x41, 0x05, 0x47, 0xAE, 0x04, 0x01, 0x00, 0x01, 0x3F, 0x80, 0x00, 0x00, 0x04, 0x07, 0x00, 0x01, 0x3F, 0xB3, 0x33, 0x33, 0x04, 0x03, 0x00, 0x01, 0x3F, 0x80, 0x00, 0x00, 0x04, 0x07, 0x00, 0x01, 0x3F, 0x80, 0x00, 0x00, 0x04, 0x07, 0x00, 0x01, 0x3F, 0x35, 0xC2, 0x8F, 0x04, 0x02, 0x00, 0x02, 0x3F, 0xB3, 0x33, 0x33, 0x04, 0x03, 0x00, 0x01, 0x3F, 0x90, 0xA3, 0xD7, 0x04, 0x04, 0x00, 0x02, 0x3F, 0xB3, 0x33, 0x33, 0x04, 0x03, 0x00, 0x01, 0x3F, 0x07, 0xAE, 0x14, 0x04, 0x05, 0x00, 0x02, 0x3F, 0x9A, 0xE1, 0x48, 0x04, 0x06, 0x00, 0x02, 0x3F, 0x9A, 0xE1, 0x48, 0x04, 0x06, 0x00, 0x84, 0x41, 0x05, 0x47, 0xAE, 0x04, 0x01, 0x00, 0x01, 0x3F, 0xB3, 0x33, 0x33, 0x04, 0x03, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x41, 0x05, 0x47, 0xAE, 0x04, 0x01, 0x00, 0x01, 0x3F, 0xB3, 0x33, 0x33, 0x04, 0x03, 0x00, 0x01, 0x41, 0x05, 0x47, 0xAE, 0x04, 0x01, 0x00, 0x01, 0x3F, 0x80, 0x00, 0x00, 0x04, 0x07, 0x00, 0x01 };
s32 D_80800468_chdinocoaster [30] BT_DATA(4, overlays_ch_dino_coaster, 0xA8) = { 42, 1066192077, 65536, 30, 1061158912, 35389440, 16, 1061158912, 34471936, 20, 1061158912, 35127296, 6, 1061158912, 34209792, 1, 1072064102, 1179648, 44, 1066192077, 36372480, 68, 1067030938, 33619968, 72, 1069547520, 33619968, 78, 1067030938, 33619968 };
ActorData D_808004E0_chdinocoaster [1] BT_DATA(4, overlays_ch_dino_coaster, 0x120) = { { 766, 923, 1798, 1, (void *)D_808003C0_chdinocoaster, (void (*)(struct Actor *))func_80800064_chdinocoaster, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))_sucoaster_entrypoint_20, 196608000, 1069547520, 0, 0, 17285, 801, (void (*)(struct Actor *))_sucoaster_entrypoint_1, (BtIntPtr)_sucoasterhit_entrypoint_0, 0, 0, (void (*)(struct Actor *))func_8080000C_chdinocoaster, (void (*)(void *, long, void *, long, void *))func_80107C2C, -31694, 20509, (void (*)(struct Actor *, long, long))func_808001C8_chdinocoaster, -2146286256 } };
s32 D_80800528_chdinocoaster [7] BT_DATA(4, overlays_ch_dino_coaster, 0x168) = { 15139316, 397940665, 131072, 0, 5767168, 917504, 318767104 };
s32 D_80800544_chdinocoaster [7] BT_DATA(4, overlays_ch_dino_coaster, 0x184) = { 1123024896, 1117782016, 1126170624, 1101004800, 0, 0, 0 };
