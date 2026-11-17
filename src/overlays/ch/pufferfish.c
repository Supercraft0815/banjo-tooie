#include "common.h"

/* extern */

typedef struct { u8 pad0[0x34]; f32 unk34; f32 unk38; } Objpufferfish_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */ void func_80800000_chpufferfish(void *arg0) {
    s32 _subaddieDll_entrypoint_1();
    void func_800FFAB0(Actor *);
    if (_subaddieDll_entrypoint_1() == 0) {
        func_800FFAB0(arg0);
        return;
    }
    (((Objpufferfish_arg0 *)arg0)->unk34) = (f32) (((Objpufferfish_arg0 *)arg0)->unk38);
}

void func_80800040_chpufferfish(Actor *arg0) {
    s32 func_8008FCC8(Unk80132ED0 *);
    s32 func_8010BA80(Actor *volatile, volatile s32, s32);
    s32 func_8010C500(void *);
    void func_8010D690(u8 *);
    void func_80800274_chpufferfish(Actor *, s32);
    void func_80800518_chpufferfish(Actor *);
    void func_80800AB0_chpufferfish(void *, s32, f32, f32);
    void func_80800E20_chpufferfish(Actor *);
    void func_80800F30_chpufferfish(Actor *);

    func_80800518_chpufferfish(arg0);
    func_8010D690(arg0);
    switch (arg0->unk79_4) {
    case 0:
        if (arg0->unk64_29) {
            func_80800F30_chpufferfish(arg0);
            return;
        }
        func_80800AB0_chpufferfish(arg0, 1, 300.0f, 300.0f);
        func_80800E20_chpufferfish(arg0);
        if (func_8010BA80(arg0, 0x26, 0x10)) {
            arg0->unk54 += 10.0f;
        }
        if (func_8010C500(arg0) && arg0->unk58 == 0.0f) {
            if (func_8008FCC8(arg0->unk0) == 0x14) {
                func_80800274_chpufferfish(arg0, 2);
                return;
            }
            func_80800274_chpufferfish(arg0, 1);
            return;
        }
    default:
    case 3:
    case 4:
        return;
    case 1:
        func_80800AB0_chpufferfish(arg0, 2, 600.0f, 600.0f);
        func_80800E20_chpufferfish(arg0);
        if (func_8010BA80(arg0, 0x26, 0x10)) {
            arg0->unk54 += 10.0f;
        }
        if (!func_8010C500(arg0)) {
            func_80800274_chpufferfish(arg0, 0);
            return;
        }
        break;
    case 2:
        func_80800AB0_chpufferfish(arg0, 4, 450.0f, 550.0f);
        func_80800E20_chpufferfish(arg0);
        if (func_8010BA80(arg0, 0x26, 0x10)) {
            arg0->unk54 += 10.0f;
        }
        if ((!func_8010C500(arg0) || func_8008FCC8(arg0->unk0) != 0x14) && arg0->unk58 == 0.0f) {
            func_80800274_chpufferfish(arg0, 0);
        }
        break;
    }
}

void func_80800274_chpufferfish(Actor *arg0, s32 arg1) {
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    BtIntPtr func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    void func_800FFAB0(Actor *);
    void func_80101CDC(Actor *, f32);
    s32 func_80107070(Actor *, s32);
    void func_8010A570(Actor *);
    void func_8080086C_chpufferfish(Actor *, s32);
    extern s32 D_8080119C_chpufferfish[];
    extern s32 D_808011D0_chpufferfish[];
    extern s32 D_80801204_chpufferfish[];
    extern s32 D_80801238_chpufferfish[];
    extern s32 D_80801288_chpufferfish[];
    f32 *position;

    switch (arg1) {
        case 1:
            break;
        case 0:
            arg0->unk58 = 5.0f;
            break;
        case 3:
            func_8080086C_chpufferfish(arg0, 2);
            func_80101CDC(arg0, 0.5f);
            func_8010A570(arg0);
            break;
        case 4:
            position = arg0->position;
            _subaddieaudioquick_entrypoint_2(arg0, position, D_80801288_chpufferfish);
            func_800BBCB8(position, position, arg0->scale, 10, D_80801238_chpufferfish);
            func_800BBCB8(position, position, arg0->scale, 2, D_8080119C_chpufferfish);
            func_800BBCB8(position, position, arg0->scale, 16, D_808011D0_chpufferfish);
            func_800BBCB8(position, position, arg0->scale, 6, D_80801204_chpufferfish);
            if (func_80107070(arg0, 3) == 0) {
                func_800FFAB0(arg0);
            }
            break;
    }
    arg0->unk79_4 = arg1;
}

s32 func_808003C8_chpufferfish(Actor *arg0, s32 arg1, s32 arg2) {
    struct PufferRoute {
        u8 pad[0x70];
        u32 region : 7;
        u32 : 15;
        u32 node : 6;
        u32 : 4;
    };
    BtIntPtr func_800CC63C(s32, s32);
    void func_80102924(void *, f32);
    f32 func_80102D78(void *, void *);
    s32 func_80107070(Actor *, s32);
    void func_8080086C_chpufferfish(Actor *, s32);

    switch (arg1) {
        case 0x3E:
            func_80102924(arg0, func_80102D78(arg0, func_800CC63C(((struct PufferRoute *)arg0)->region - 1, ((struct PufferRoute *)arg0)->node - 1)));
            func_80800274_chpufferfish(arg0, 2);
            return 1;
        case 0x40:
            func_80800274_chpufferfish(arg0, 3);
            return 1;
        case 0x8F:
            switch (arg2) {
                case 1:
                case 4:
                    func_80800274_chpufferfish(arg0, 0);
                    func_8080086C_chpufferfish(arg0, 1);
                    break;
                case 2:
                case 3:
                    break;
            }
            return 1;
        case 1:
            func_80800274_chpufferfish(arg0, 0);
            if ((s32)arg0->unk70_10 != 1) {
                func_8080086C_chpufferfish(arg0, 4);
            }
            ((f32 *)arg0->actorData)[5] = 2.0f;
            return 1;
        case 2:
            func_80800274_chpufferfish(arg0, 0);
            func_80107070(arg0, 1);
            return 1;
        default:
            return 0;
    }
}

void func_80800518_chpufferfish(Actor *arg0) {
    struct PufferFlags {
        u32 : 2;
        u32 active : 1;
        u32 : 29;
    };
    void _subaddieaudioloop_entrypoint_0(Actor *, f32);
    void _subaddieaudioloop_entrypoint_2(Actor *);
    s32 _subaddieaudioloop_entrypoint_4(Actor *, f32 *, u32, u32 *);
    s32 _subaddiejoy_entrypoint_6(u8 *, s32);
    s32 func_800D90A4(f32 *);
    f32 func_800DC0C0(void);
    f32 func_800F1214(f32, f32, f32);
    s32 func_80101DDC(Actor *);
    s32 func_80101E14(Actor *, f32);
    f32 func_80101F24(Actor *);
    s32 func_8010C9B0(f32 *, s32);
    void func_80800274_chpufferfish(Actor *, s32);
    void func_8080086C_chpufferfish(Actor *, s32);
    void func_8080093C_chpufferfish(Actor *, s32);
    extern u32 D_80801298_chpufferfish[4];
    f32 sp24;
    f32 sp20;
    f32 value;
    f32 scale;

    switch ((u32)*(u16 *)((u8 *)arg0 + 0x72) >> 10) {
    case 1:
        if (func_80101F24(arg0) > 0.1f && func_80101F24(arg0) < 0.7f && func_800DC0C0() < 0.5f) {
            func_8080093C_chpufferfish(arg0, 1);
        }
        if (((struct PufferFlags *)((u8 *)arg0 + 0x64))->active) {
            if (func_800D90A4((f32 *)((u8 *)arg0 + 0x2C)) && _subaddiejoy_entrypoint_6((u8 *)arg0, 1)) {
                func_8080086C_chpufferfish(arg0, 2);
            }
        } else {
            if (func_800D90A4(&arg0->unk58) && func_8010C9B0(&arg0->position[0], 500)) {
                func_8080086C_chpufferfish(arg0, 2);
            }
        }
        break;
    case 3:
        if (func_80101F24(arg0) > 0.1f && func_80101F24(arg0) < 0.7f && func_800DC0C0() < 0.5f) {
            func_8080093C_chpufferfish(arg0, 1);
        }
        if (((struct PufferFlags *)((u8 *)arg0 + 0x64))->active) {
            if (_subaddiejoy_entrypoint_6((u8 *)arg0, 0)) {
                func_8080086C_chpufferfish(arg0, 4);
            }
        } else if (func_80101E14(arg0, 0.999f)) {
            func_8080086C_chpufferfish(arg0, 4);
        }
        break;
    case 2:
        value = func_80101F24(arg0);
        sp24 = value;
        scale = *(f32 *)((u8 *)arg0 + 0x34);
        arg0->scale = func_800F1214(value, scale, 2.0f * scale);
        if (func_80101DDC(arg0)) {
            _subaddieaudioloop_entrypoint_2(arg0);
            if (((u32)*(u8 *)((u8 *)arg0 + 0x79) >> 4) == 3) {
                func_80800274_chpufferfish(arg0, 4);
            } else {
                func_8080086C_chpufferfish(arg0, 3);
            }
        } else {
            _subaddieaudioloop_entrypoint_4(arg0, &arg0->position[0], 1, D_80801298_chpufferfish);
            _subaddieaudioloop_entrypoint_0(arg0, func_800F1214(sp24, 0.8f, 1.4f));
        }
        break;
    case 4:
        value = func_80101F24(arg0);
        sp20 = value;
        scale = *(f32 *)((u8 *)arg0 + 0x34);
        arg0->scale = func_800F1214(value, scale, 2.0f * scale);
        if (func_80101E14(arg0, 0.1f)) {
            _subaddieaudioloop_entrypoint_2(arg0);
            func_8080086C_chpufferfish(arg0, 1);
        } else {
            _subaddieaudioloop_entrypoint_4(arg0, &arg0->position[0], 1, D_80801298_chpufferfish);
            _subaddieaudioloop_entrypoint_0(arg0, func_800F1214(sp20, 0.8f, 1.4f));
        }
        func_8080093C_chpufferfish(arg0, 1);
        break;
    }
}

void func_8080086C_chpufferfish(Actor *arg0, s32 arg1) {
    void func_80102424(Actor *, s32);
    void func_80101EE4(Actor *, f32);
    s32 previousState;

    previousState = arg0->unk70_10;
    func_80102424(arg0, arg1);
    switch (arg1) {
    case 1:
        arg0->scale = *(f32 *)&arg0->actorData[7];
        break;
    case 2:
        if (previousState == 1) {
            func_80101EE4(arg0, 0.0f);
        }
        break;
    case 3:
        arg0->scale = 2.0f * *(f32 *)&arg0->actorData[7];
        break;
    case 4:
        if (previousState == 3) {
            func_80101EE4(arg0, 0.999f);
        }
        arg0->unk58 = 5.0f;
        *(f32 *)&arg0->actorData[5] = 2.0f;
        break;
    }
}

void func_8080093C_chpufferfish(Actor *arg0, s32 arg1) {
    BtIntPtr _fxairbub_entrypoint_1(f32 *, f32, f32, f32);
    s32 _subaddieskeleton_entrypoint_2(Unk80132ED0 *, s32, f32 *);
    void func_800BA22C(BtIntPtr, s32);
    void func_800BA994(u8 *, s16, s16, s16, s16, s16, s16);
    f32 func_800DC178(f32, f32);
    void func_800EFA4C(f32 *, f32, f32, f32);
    f32 position[3];
    BtIntPtr emitter;

    if (_subaddieskeleton_entrypoint_2(arg0->unk0, 4, position)) {
        func_800EFA4C(position, position[0] + func_800DC178(-20.0f, 20.0f),
                     position[1] + func_800DC178(-20.0f, 20.0f),
                     position[2] + func_800DC178(-20.0f, 20.0f));
        emitter = _fxairbub_entrypoint_1(position, 1.0f, position[1] + 1000.0f, arg0->scale);
        func_800BA994((u8 *)emitter, arg0->rotation[0], arg0->rotation[1] - 35.0f,
                     *(f32 *)&arg0->actorData[3] * 1.5f, arg0->rotation[0],
                     arg0->rotation[1] + 35.0f, 2.0f * *(f32 *)&arg0->actorData[3]);
        func_800BA22C(emitter, arg1);
    }
}

void func_80800AB0_chpufferfish(void *arg0, s32 arg1, f32 arg2, f32 arg3) {
    s32 _subaddieDll_entrypoint_11(void *, s32, s32);
    f32 func_800136E4(f32);
    BtIntPtr func_800CC63C(s32, s32);
    s32 func_800D90A4(f32 *);
    f32 func_800DC178(f32, f32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    f32 func_800F1DCC(f32, f32);
    f32 func_800F1FF0(f32, f32, f32, f32, f32);
    void func_80102924(void *, f32);
    void func_80102950(void *, f32);
    void func_80102BAC(void *, f32, f32, f32);
    void func_80102C58(void *, f32, f32, f32);
    f32 func_80102D78(void *, void *);
    void func_8010CE28(void *, f32 *);
    f32 rotation[3];
    s32 atBoundary;
    u8 *region;

    region = (u8 *)func_800CC63C((*(u32 *)((u8 *)arg0 + 0x70) >> 25) - 1, ((*(u32 *)((u8 *)arg0 + 0x70) << 22) >> 26) - 1);
    if (*(f32 *)((u8 *)arg0 + 8) >= *(s16 *)(region + 0xE) + *(f32 *)(region + 4)) {
        atBoundary = 1;
        func_80102950(arg0, 355.0f);
    } else if (*(f32 *)((u8 *)arg0 + 8) <= *(f32 *)(region + 4) - *(s16 *)(region + 0xE)) {
        atBoundary = 1;
        func_80102950(arg0, 5.0f);
    } else {
        atBoundary = 0;
    }
    if (arg1 & 6) {
        func_8010CE28(arg0, rotation);
        if (arg1 & 2) {
            func_80102924(arg0, rotation[1]);
        } else {
            func_80102924(arg0, func_800136E4(rotation[1] - 180.0f));
        }
        rotation[0] = func_800136E4(-rotation[0]);
        if (rotation[0] > 25.0f && rotation[0] < 180.0f) {
            rotation[0] = 25.0f;
        } else if (rotation[0] < 335.0f && rotation[0] > 180.0f) {
            rotation[0] = 335.0f;
        }
        func_80102950(arg0, rotation[0]);
    }
    if (func_800D90A4((f32 *)((u8 *)arg0 + 0x20))) {
        *(f32 *)((u8 *)arg0 + 0x20) = *(f32 *)((u8 *)arg0 + 0x28) = func_800DC178(2.0f, 4.0f);
        *(f32 *)((u8 *)arg0 + 0x18) = func_800DC178(arg2, arg3);
        if (!atBoundary) {
            func_80102950(arg0, func_800DC178(-8.333333f, 8.333333f));
        }
        if (arg1 & 5) {
            func_80102924(arg0, func_800DC178(-35.0f, 35.0f) + *(f32 *)((u8 *)arg0 + 0x48));
        }
    }
    if (!_subaddieDll_entrypoint_11(arg0, (s32)*(f32 *)((u8 *)arg0 + 0x54), (s32)(*(f32 *)((u8 *)arg0 + 0x24) * (*(f32 *)((u8 *)arg0 + 0x38) * 3.0f)))) {
        func_80102924(arg0, func_80102D78(arg0, region));
        *(f32 *)((u8 *)arg0 + 0x20) = *(f32 *)((u8 *)arg0 + 0x28) = func_800DC178(2.0f, 4.0f);
    }
    *(f32 *)((u8 *)arg0 + 0x1C) = func_800136E4(func_800F10B4(func_800F1DCC(*(f32 *)((u8 *)arg0 + 0x48), *(f32 *)((u8 *)arg0 + 0x54)), -180.0f, 180.0f, -15.0f, 15.0f));
    func_80102BAC(arg0, 0.05f, 0.05f, 4.0f);
    func_80102C58(arg0, 0.05f, 0.01f, 0.5f);
    *(f32 *)((u8 *)arg0 + 0x4C) = func_800F1FF0(*(f32 *)((u8 *)arg0 + 0x4C), *(f32 *)((u8 *)arg0 + 0x1C), 0.01f, 0.005f, 0.1f);
}

void func_80800E20_chpufferfish(Actor *arg0) {
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    f32 func_800F15F8(f32, f32, f32);
    f32 progress;
    f32 value;

    progress = func_800F10B4(((f32 *)arg0->actorData)[2], ((f32 *)arg0->actorData)[4], 0.0f, 0.0f, 1.0f);
    if (progress < 0.2f) {
        value = func_800F10B4(progress, 0.0f, 0.2f, 0.0f, ((f32 *)arg0->actorData)[0]);
    } else if (progress < 0.5f) {
        value = func_800F10B4(progress, 0.2f, 0.5f, ((f32 *)arg0->actorData)[0], ((f32 *)arg0->actorData)[0] * 0.75f);
    } else {
        value = func_800F10B4(progress, 0.5f, 1.0f, ((f32 *)arg0->actorData)[0] * 0.75f, 0.0f);
    }
    ((f32 *)arg0->actorData)[3] = func_800F15F8(((f32 *)arg0->actorData)[3], value, 4.0f);
}

void func_80800F30_chpufferfish(Actor *arg0) {
    f32 _subaddiejoy_entrypoint_3();
    f32 func_800136E4(f32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    f32 func_800F1828(f32 *, f32 *);
    f32 func_800F1DCC(f32, f32);
    f32 func_800F1FF0(f32, f32, f32, f32, f32);
    void func_80102BAC(void *, f32, f32, f32);
    void func_80102C58(void *, f32, f32, f32);
    s32 func_8010BA80(Actor *volatile, volatile s32, s32);
    void func_8010D254(f32 *);
    f32 position[3];
    f32 speed;

    speed = _subaddiejoy_entrypoint_3() * 300.0f;
    func_8010D254(position);
    arg0->unk50 = func_800F1828(arg0->position, position);
    if (arg0->unk50 > 30.0f && arg0->unk50 <= 180.0f) {
        arg0->unk50 = 30.0f;
    } else if (arg0->unk50 > 180.0f && arg0->unk50 <= 330.0f) {
        arg0->unk50 = 330.0f;
    }
    if (((f32 *)arg0->actorData)[3] <= speed) {
        ((f32 *)arg0->actorData)[3] = speed;
    } else {
        ((f32 *)arg0->actorData)[3] -= ((f32 *)arg0->actorData)[3] * 0.02f;
        if (((f32 *)arg0->actorData)[3] < 30.0f) {
            ((f32 *)arg0->actorData)[3] = 0.0f;
        }
    }
    ((f32 *)arg0->actorData)[0] = ((f32 *)arg0->actorData)[3];
    ((f32 *)arg0->actorData)[1] = func_800136E4(func_800F10B4(func_800F1DCC(arg0->rotation[1], arg0->unk54), -180.0f, 180.0f, -15.0f, 15.0f));
    func_80102BAC(arg0, 0.5, 0.5f, 5.0f);
    func_80102C58(arg0, 0.5, 0.5f, 5.0f);
    arg0->rotation[2] = func_800F1FF0(arg0->rotation[2], ((f32 *)arg0->actorData)[1], 0.01f, 0.005f, 0.1f);
    func_8010BA80(arg0, 0x200006, 0x20);
}

OSThread *chpufferfish_entrypoint_0(void)
{
    extern ActorData D_808012A8_chpufferfish[];

    return (OSThread *) D_808012A8_chpufferfish;
}
/* data_to_c.py: from asm/data/overlays/ch/pufferfish.data.s */
extern u8 D_80801174_chpufferfish[];
void func_80105834(Actor*);
void func_80101870(Actor* arg0, void* arg1);
OSThread *func_80108ED0(void);
void func_80107C2C();
extern u8 D_80801160_chpufferfish[];
u8 D_80801160_chpufferfish[20] BT_DATA(4, overlays_ch_pufferfish, 0x0) = { 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00 };
u8 D_80801174_chpufferfish[40] BT_DATA(4, overlays_ch_pufferfish, 0x14) = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x80, 0x00, 0x00, 0x01, 0xC8, 0x00, 0x49, 0x3F, 0xB3, 0x33, 0x33, 0x01, 0xC9, 0x00, 0x0A, 0x3F, 0x40, 0x00, 0x00, 0x01, 0xCA, 0x00, 0x49, 0x3F, 0xB3, 0x33, 0x33, 0x01, 0xC9, 0x00, 0x12 };
s32 D_8080119C_chpufferfish [13] BT_DATA(4, overlays_ch_pufferfish, 0x3C) = { 1903069, 2818560, 67108898, 25166336, 75499008, 1376256, 2490393, 7, 2949170, 6553632, -555819298, 917654, 9830400 };
s32 D_808011D0_chpufferfish [13] BT_DATA(4, overlays_ch_pufferfish, 0x70) = { 1902311, 1310742, 335806509, 29491750, 1769472, 34, 16777472, 8388761, 1966100, 1310734, 9830550, 1376256, 16580608 };
s32 D_80801204_chpufferfish [13] BT_DATA(4, overlays_ch_pufferfish, 0xA4) = { 1902320, 1310742, 335806509, 29491750, 1769472, 34, 13369497, 6684748, 1966100, 1310734, 9830550, 1376256, 16580608 };
s32 D_80801238_chpufferfish [20] BT_DATA(4, overlays_ch_pufferfish, 0xD8) = { 1903065, 1445892, 1769622, 9830421, 204, 2818560, 50331692, 0, 0, 6553600, 2162687, -16842718, 786455, 786455, 917604, 13107247, 4194368, 0, 167772160, 3342336 };
s32 D_80801288_chpufferfish [4] BT_DATA(4, overlays_ch_pufferfish, 0x128) = { 1246459, 655564, 1471792, 1769472 };
u32 D_80801298_chpufferfish[4] BT_DATA(4, overlays_ch_pufferfish, 0x138) = { 0x1305B1, 0x1B0001, 0x3E80BB8, 0 };
ActorData D_808012A8_chpufferfish [1] BT_DATA(4, overlays_ch_pufferfish, 0x148) = { { 304, 666, 1766, 1, (void *)D_80801174_chpufferfish, (void (*)(struct Actor *))func_80800040_chpufferfish, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 393216000, 0, 0, 0, 32, 353, 0, (BtIntPtr)func_80108ED0, 0, 0, (void (*)(struct Actor *))func_80800000_chpufferfish, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32704, 21517, (void (*)(struct Actor *, long, long))func_808003C8_chpufferfish, (BtIntPtr)D_80801160_chpufferfish } };
