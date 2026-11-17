#include "common.h"

OSThread *chklungospiral_entrypoint_0(void)
{
    extern ActorData D_80800620_chklungospiral[];

    return (OSThread *) D_80800620_chklungospiral;
}

/* extern */

void func_8080000C_chklungospiral(Actor *arg0) {
    void _subaddiemarker_entrypoint_1(Actor *, s32, s32, f32 *, s32);
    s32 _subaddieDll_entrypoint_2(Actor *arg0, f32 (*arg1)[3]);
    void func_80105A9C(Actor *, f32);
    void func_80105BAC(Actor *);
    f32 sp20[6];

    _subaddiemarker_entrypoint_1(arg0, 0x154, 0x33, sp20, 1);
    _subaddieDll_entrypoint_2(arg0, sp20);
    func_80105A9C(arg0, 300.0f);
    func_80105BAC(arg0);
}

void func_80800060_chklungospiral(Actor *arg0) {
    void _suexpression_entrypoint_10(u32 *, Unk80132ED0 *, BtUIntPtr);
    void func_800DA544(GameFlag);
    void func_800FFAB0(Actor *);
    void *func_80100094(Actor *, u32);
    void func_80102424(Actor *, s32);
    s32 func_80105230();
    void func_80105834(Actor *);
    s32 func_80105A5C(Actor *);
    s32 func_8010C500(Actor *);
    void func_808003AC_chklungospiral(Actor *, s32, s32);
    int func_80800430_chklungospiral(void *);
    void func_80800480_chklungospiral(Actor *);
    extern u8 D_80800668_chklungospiral[];

    switch (arg0->unk70_10) {
        case 1:
            if (func_8010C500(arg0) != 0) {
                func_80102424(arg0, 2);
                func_808003AC_chklungospiral(arg0, 0xF, 0x30);
            }
            break;
        case 2:
            func_80800480_chklungospiral(arg0);
            break;
        case 3:
            func_80105834(arg0);
            func_80105230(arg0, D_80800668_chklungospiral);
            if (func_80105A5C(arg0) != 0) {
                func_80800430_chklungospiral(arg0);
                func_800FFAB0(arg0);
                func_800DA544(0x3C);
            }
            break;
    }
    if (func_80100094(arg0, 1) != NULL) {
        _suexpression_entrypoint_10(func_80100094(arg0, 1), arg0->unk0, 0);
    }
}

s32 func_8080015C_chklungospiral(Actor *arg0, s32 arg1, s32 arg2) {
    u32 _subaddiedialog_entrypoint_11(Unk80132ED0* arg0, u32 DialogId, u32 arg2, f32* CameraTarget, s16 arg4);
    void *_suexpression_entrypoint_7(Actor *arg0, s32 arg1, s16 arg2);
    void _suexpression_entrypoint_8(void *arg0, s32 arg1);
    void func_800DF744(s32, s32);
    s32 func_801015D0(Actor *);
    void func_80102424(Actor *, s32);
    s32 func_808002A0_chklungospiral(void *, s32, s32);
    void func_808002FC_chklungospiral(Actor *, s32, s32);
    void func_808003AC_chklungospiral(Actor *, s32, s32);

    switch (arg1) {
        case 11:
            if (arg2 == 0xF) {
                func_808002FC_chklungospiral(arg0, 3, 1);
                _subaddiedialog_entrypoint_11(arg0->unk0, 0x1638, 0xE, NULL, 0xAB);
                return 4;
            }
            return 3;
        case 46:
            func_808003AC_chklungospiral(arg0, 0x16, 0x30);
            func_80102424(arg0, 3);
            break;
        case 87:
            return func_808002A0_chklungospiral(arg0, arg2 & 0xFFFF, (u32)(arg2 & 0xFFFF0000) >> 16);
        case 41:
            _suexpression_entrypoint_7(arg0, 1, 0xAB);
            break;
        case 42:
            _suexpression_entrypoint_8(arg0, 1);
            break;
        case 31:
            func_801015D0(arg0);
            func_800DF744(3, 0);
            break;
        default:
            return 0;
    }
    return 1;
}

/* extern */

s32 func_808002A0_chklungospiral(void *arg0, s32 arg1, s32 arg2) {
    s32 _gcdialogcamera_entrypoint_0(s32, s32);
    void func_808002FC_chklungospiral(Actor *, s32, s32);
    if (_gcdialogcamera_entrypoint_0(arg1, arg2) != 0) {
        if (((*(s32 *)((s8 *)(arg0) + (0x6C))) & 0x1FF) != 2) {
            func_808002FC_chklungospiral(arg0, 2, 1);
        }
        return 2;
    }
    return 1;
}

void func_808002FC_chklungospiral(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _capod_entrypoint_2(BtIntPtr arg0, s32 arg1, s32 arg2);
    void _capod_entrypoint_7(s32, s32);
    void _capod_entrypoint_8(s32);
    void _gcdialogcamera_entrypoint_3(u32 *, f32);
    void _gcdialogcamera_entrypoint_4(BtIntPtr arg0);
    void _gcdialogcamera_entrypoint_5(BtIntPtr arg0);
    void _gcdialogcamera_entrypoint_8(void);
    extern u32 D_808005F0_chklungospiral[4];

    switch (arg0->unk6C_0) {
        case 0:
            _capod_entrypoint_2(arg0->unk0, 0xC, 0);
        case 1:
            _capod_entrypoint_8(1);
            arg0->unk6C_0 = 2;
            _gcdialogcamera_entrypoint_3(D_808005F0_chklungospiral, arg0->scale);
            _gcdialogcamera_entrypoint_4(arg0->position);
            _gcdialogcamera_entrypoint_5(arg0->rotation);
            _gcdialogcamera_entrypoint_8();
        case 2:
            _capod_entrypoint_7(arg1, arg2);
            break;
    }
}

void func_808003AC_chklungospiral(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _capod_entrypoint_2(BtIntPtr arg0, s32 arg1, s32 arg2);
    s32 _capod_entrypoint_6(BtIntPtr arg0, s32 arg1, s32 arg2);

    switch (arg0->unk6C_0) {
        case 0:
            _capod_entrypoint_2(arg0->unk0, 0xC, arg2);
        case 2:
            arg0->unk6C_0 = 1;
        case 1:
            _capod_entrypoint_6(arg0->unk0, arg1, arg2);
            break;
    }
}

int func_80800430_chklungospiral(void *arg0) {
    s32 _capod_entrypoint_3(s32, void *);
    if ((*(s32 *)((s8 *)(arg0) + (0x6C))) & 0x1FF) {
        _capod_entrypoint_3(0, arg0);
        (*(u16 *)((s8 *)(arg0) + (0x6E))) = (u16) ((*(u16 *)((s8 *)(arg0) + (0x6E))) & 0xFE00);
        return 1;
    }
    return 0;
}

void func_80800480_chklungospiral(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    void func_80018820(s32, f32, f32);
    s32 func_800E15CC(s32, f32, f32);
    s32 func_80101E14(Actor *, f32);
    s32 func_80101E4C(Actor *, f32 *);
    extern s32 D_80800674_chklungospiral[5];
    extern f32 D_80800688_chklungospiral[6];
    if (arg0->unk7C_12) {
        if (func_80101E4C(arg0, D_80800688_chklungospiral) != 0) {
            func_80018820(0, 0.8f, 0.3f);
            func_800E15CC(0, 5.0f, 0.7f);
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_80800674_chklungospiral);
            return;
        }
        if (func_80101E14(arg0, 0.7f) != 0) {
            func_80018820(0, 1.0f, 0.4f);
            func_800E15CC(0, 10.0f, 0.8f);
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_80800674_chklungospiral);
        }
    }
}
/* data_to_c.py: from asm/data/overlays/ch/klungo/spiral.data.s */
extern u8 D_80800600_chklungospiral[];
void func_80102EC0();
void func_801018A4();
void func_80107C2C();
u32 D_808005F0_chklungospiral[4] BT_DATA(4, overlays_ch_klungo_spiral, 0x0) = { 0x43340000, 0x43480000, 0x43480000, 0x43020000 };
u8 D_80800600_chklungospiral[32] BT_DATA(4, overlays_ch_klungo_spiral, 0x10) = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0xF5, 0x70, 0xA4, 0x02, 0x5C, 0x00, 0x01, 0x40, 0xF5, 0x70, 0xA4, 0x02, 0x5C, 0x00, 0x01, 0x3F, 0x33, 0x33, 0x33, 0x02, 0x64, 0x00, 0x01 };
ActorData D_80800620_chklungospiral [1] BT_DATA(4, overlays_ch_klungo_spiral, 0x30) = { { 344, 1260, 1799, 1, (void *)D_80800600_chklungospiral, (void (*)(struct Actor *))func_80102EC0, (void (*)(struct Actor *))func_80800060_chklungospiral, (void (*)(long, long))func_801018A4, 0, 1073741824, 60, 0, 16388, 288, 0, 0, 0, 0, (void (*)(struct Actor *))func_8080000C_chklungospiral, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 5142, (void (*)(struct Actor *, long, long))func_8080015C_chklungospiral, 0 } };
u8 D_80800668_chklungospiral [12] BT_DATA(4, overlays_ch_klungo_spiral, 0x78) = { 0, 0, 0, 0, 0x3F, 0, 0, 0, 0xBF, 0x80, 0, 0 };
s32 D_80800674_chklungospiral[5] BT_DATA(4, overlays_ch_klungo_spiral, 0x84) = { 1246231, 852211, 17563649, 52436300, 0 };
f32 D_80800688_chklungospiral[6] BT_DATA(4, overlays_ch_klungo_spiral, 0x98) = { 0.06f, 0.15f, 0.24f, 0.53f, 0.61f, -1.0f };
