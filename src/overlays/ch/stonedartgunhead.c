#include "common.h"

void func_80800000_chstonedartgunhead(Actor *arg0)
{
  Prop *_gccubesearch_entrypoint_1(u32, f32 [3]);
  s32 _gccubesearch_entrypoint_13(f32 *, u32, f32 *);
  s32 _gspropctrl_entrypoint_12(Prop *);
  s32 _gspropctrl_entrypoint_13(Prop *);
  f32 func_800EFB8C(f32 *, f32 *);
  struct StoneDartGunHeadData
  {
    f32 distance;
    f32 count;
    f32 unk8;
    f32 unkC;
    f32 speed;
  };
  struct StoneDartGunHeadMarker
  {
    u32 pad[10];
    u32 pad28_14 : 18;
    u32 unk28_13 : 1;
    u32 pad28_0 : 13;
  };
  Prop *sp34;
  f32 sp28[3];
  f32 * volatile sp24;
  if (((!arg0) && (!arg0)) && (!arg0))
  {
  }
  sp24 = arg0->position;
  _gccubesearch_entrypoint_13(sp28, 0x122, arg0->position);
  ((struct StoneDartGunHeadData *) arg0->actorData)->distance = func_800EFB8C(sp24, sp28);
  sp34 = _gccubesearch_entrypoint_1(0x122, sp28);
  ((struct StoneDartGunHeadData *) arg0->actorData)->count = ((f32) _gspropctrl_entrypoint_12(sp34)) + 1.0f;
  ((struct StoneDartGunHeadData *) arg0->actorData)->speed = (f32) _gspropctrl_entrypoint_13(sp34);
  arg0->unk64_24 = 1;
  ((struct StoneDartGunHeadMarker *) arg0->unk0)->unk28_13 = 1;
}

void func_808000A8_chstonedartgunhead(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    f32 func_80013728(f32);
    f32 func_800F1828(f32 *, f32 *);
    Actor *func_801084B0(BtIntPtr, Actor **);
    void func_8010D254(f32 *);
    extern s32 D_80800E78_chstonedartgunhead;
    struct StoneDartGunHeadData {
        f32 distance;
        f32 count;
        f32 unk8;
        f32 unkC;
        f32 speed;
    };
    f32 sp2C[3];
    f32 angle;
    Actor *actor;

    actor = func_801084B0(0x123, &arg0);
    actor->rotation[1] = arg0->rotation[1];
    ((struct StoneDartGunHeadData *)actor->actorData)->unkC =
        ((struct StoneDartGunHeadData *)arg0->actorData)->speed * 0.125f * 30.0f;
    actor->position[1] += 104.0f * arg0->scale;
    func_8010D254(sp2C);
    sp2C[1] += 60.0f;
    angle = func_80013728(func_800F1828(actor->position, sp2C));
    actor->rotation[0] = angle;
    if (angle > 10.0f) {
        actor->rotation[0] = 10.0f;
    } else if (actor->rotation[0] < -10.0f) {
        actor->rotation[0] = -10.0f;
    }
    _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_80800E78_chstonedartgunhead);
}

/* extern */

void func_808001B4_chstonedartgunhead(Actor *arg0) {
    f32 func_800136E4(f32);
    s32 sp1C;

    sp1C = (s32) arg0->rotation[1];
    arg0->rotation[1] = func_800136E4(arg0->rotation[1] + (*(f32 *)((s8 *)arg0 + 0x2C)) * (*(f32 *)((s8 *)arg0 + 0x30)));
    if (sp1C != (s32) arg0->rotation[1]) {
        (*(f32 *)((s8 *)(arg0) + (0x34))) = 0.2f;
    }
}

void func_80800224_chstonedartgunhead(Actor *arg0, s32 arg1) {
    void _subaddieDll_entrypoint_4(void *arg0, s32 arg1);
    s32 func_800E3AA4(f32);
    void func_80101EE4(Actor *, f32);
    void func_80102424(Actor *, s32);
    struct StoneDartGunHeadTurnData {
        f32 pad[5];
        f32 direction;
        f32 speed;
    };

    if (arg0->unk70_10 == 8) {
        _subaddieDll_entrypoint_4(arg0, 0);
    }
    func_80102424(arg0, arg1);
    switch (arg0->unk70_10) {
    case 4:
        arg0->unk58 = 0.75f;
        break;
    case 5:
        func_80101EE4(arg0, 0.856f);
        break;
    case 3:
        func_80101EE4(arg0, 0.856f);
        break;
    case 6:
        if ((f32)func_800E3AA4(arg0->rotation[1]) < 180.0f) {
            ((struct StoneDartGunHeadTurnData *)arg0->actorData)->direction = -1.0f;
        } else {
            ((struct StoneDartGunHeadTurnData *)arg0->actorData)->direction = 1.0f;
        }
        ((struct StoneDartGunHeadTurnData *)arg0->actorData)->speed = 20.0f;
        arg0->unk58 = 1.159988403f;
        _subaddieDll_entrypoint_4(arg0, 1);
        break;
    case 8:
        arg0->unk58 = 20.0f;
        break;
    }
}

void func_80800364_chstonedartgunhead(Actor *arg0) {
    void _subaddieaudioloop_entrypoint_0(Actor *, f32);
    s32 _subaddieaudioloop_entrypoint_4(Actor *, f32 *, s32, s32 *);
    s32 _subaddieaudioquick_entrypoint_3(Actor *arg0, f32 arg1[3], void *arg2, f32 arg3);
    s32 _subaddiejoy_entrypoint_6(Actor *, s32);
    void func_80016068(u32, f32 *);
    f32 func_800D8FF8();
    u8 func_800D9078(f32 *);
    f32 func_800F11E4(f32, f32, f32, f32, f32);
    s32 func_80101E14(Actor *, f32);
    f32 func_80101F24(Actor *);
    void func_80102B2C(Actor *, f32);
    s32 func_80102CF4(Actor *, f32);
    void func_80108B04(Actor *, s32);
    void func_8010C820(Actor *, s32, s32);
    s32 func_8010CB0C(f32 *, s32, s32, s32);
    f32 func_8010CD28(Actor *);
    s32 func_8010D248();
    void func_808001B4_chstonedartgunhead(Actor *);
    void func_80800224_chstonedartgunhead(Actor *, s32);
    extern s32 D_80800E80_chstonedartgunhead[3];
    extern s32 D_80800E8C_chstonedartgunhead[4];
    extern s32 D_80800E9C_chstonedartgunhead[4];
    extern s32 D_80800EAC_chstonedartgunhead[4];
    typedef struct {
        u8 pad[0x2A];
        u8 pad2A:2;
        u8 enabled:1;
        u8 pad2B:5;
    } HeadMarker;
    typedef struct {
        u32 pad:2;
        u32 controlled:1;
        u32 player:2;
        u32 rest:27;
    } HeadFlags;
    typedef struct {
        f32 yaw;
        f32 limit;
        f32 count;
        f32 unused[3];
        f32 tilt;
        f32 soundTimer;
    } HeadData;
    s32 sp4C;
    f32 sp44[2];
    f32 sp3C[2];
    s32 sp38;
    f32 sp34;
    s32 padding;

    func_8010C820(arg0, 0x154, 0x64);
    (*(HeadMarker **)arg0)->enabled = 1;
    switch (arg0->unk70_10) {
    case 1:
        if (func_8010CB0C(arg0->position, (s32) ((HeadData *)arg0->actorData)->yaw, 0x190, -0x190) != 0) {
            func_80800224_chstonedartgunhead(arg0, 2);
        }
        break;
    case 2:
        if (func_80101E14(arg0, 0.856f) != 0) {
            func_80800224_chstonedartgunhead(arg0, 3);
        }
        break;
    case 3:
        if (func_8010CB0C(arg0->position, (s32) ((HeadData *)arg0->actorData)->yaw, 0x190, -0x190) == 0) {
            func_80800224_chstonedartgunhead(arg0, 5);
        } else {
            sp4C = (s32) arg0->rotation[1];
            if (((HeadFlags *)((u8 *)arg0 + 0x64))->controlled) {
                func_80016068(((HeadFlags *)((u8 *)arg0 + 0x64))->player, sp44);
                arg0->unk54 = arg0->rotation[1] + sp44[0] * 4.0f;
            } else {
                arg0->unk54 = func_8010CD28(arg0);
            }
            func_80102B2C(arg0, 4.0f);
            if (sp4C != (s32) arg0->rotation[1]) {
                ((HeadData *)arg0->actorData)->soundTimer = 0.2f;
            }
            if (((HeadFlags *)((u8 *)arg0 + 0x64))->controlled) {
                if ((_subaddiejoy_entrypoint_6(arg0, 1) != 0) && (arg0->unk58 <= 0.0f)) {
                    func_80800224_chstonedartgunhead(arg0, 4);
                }
            } else if ((arg0->unk58 <= 0.0f) && (func_80102CF4(arg0, 15.0f) != 0) && (func_8010D248() != 0)) {
                ((HeadData *)arg0->actorData)->count += 1.0f;
                if (((HeadData *)arg0->actorData)->count >= ((HeadData *)arg0->actorData)->limit) {
                    ((HeadData *)arg0->actorData)->count = 0.0f;
                    func_80800224_chstonedartgunhead(arg0, 4);
                }
            }
        }
        break;
    case 4:
        _subaddieaudioquick_entrypoint_3(arg0, arg0->position, D_80800E80_chstonedartgunhead, 0.45f);
        _subaddieaudioquick_entrypoint_3(arg0, arg0->position, D_80800E8C_chstonedartgunhead, 0.7f);
        _subaddieaudioquick_entrypoint_3(arg0, arg0->position, D_80800E9C_chstonedartgunhead, 0.989f);
        if (((HeadFlags *)((u8 *)arg0 + 0x64))->controlled) {
            sp38 = (s32) arg0->rotation[1];
            if ((func_80101F24(arg0) >= 0.2f) && (arg0->unk58 <= 0.0f) && (_subaddiejoy_entrypoint_6(arg0, 1) != 0)) {
                func_80800224_chstonedartgunhead(arg0, 4);
            }
            func_80016068(((HeadFlags *)((u8 *)arg0 + 0x64))->player, sp3C);
            arg0->unk54 = arg0->rotation[1] + sp3C[0] * 4.0f;
            func_80102B2C(arg0, 4.0f);
            if (sp38 != (s32) arg0->rotation[1]) {
                ((HeadData *)arg0->actorData)->soundTimer = 0.2f;
            }
        }
        if (func_80101E14(arg0, 0.999f) != 0) {
            func_80800224_chstonedartgunhead(arg0, 3);
            break;
        }
        if (func_80101E14(arg0, 0.052f) != 0) {
            func_80108B04(arg0, 0);
        }
        break;
    case 5:
        if (func_80101E14(arg0, 0.999f) != 0) {
            func_80800224_chstonedartgunhead(arg0, 1);
        }
        break;
    case 6:
        (*(HeadMarker **)arg0)->enabled = 0;
        func_808001B4_chstonedartgunhead(arg0);
        ((HeadData *)arg0->actorData)->tilt += 7.4444447f;
        if (((HeadData *)arg0->actorData)->tilt > 87.0f) {
            ((HeadData *)arg0->actorData)->tilt = 87.0f;
            func_80800224_chstonedartgunhead(arg0, 7);
        }
        break;
    case 7:
        (*(HeadMarker **)arg0)->enabled = 0;
        func_808001B4_chstonedartgunhead(arg0);
        if (arg0->unk58 <= 0.0f) {
            ((HeadData *)arg0->actorData)->tilt -= 1.74f;
            if (((HeadData *)arg0->actorData)->tilt < 0.0f) {
                func_80800224_chstonedartgunhead(arg0, 8);
            }
        }
        break;
    case 8:
        (*(HeadMarker **)arg0)->enabled = 0;
        if (arg0->unk58 <= 0.0f) {
            func_80800224_chstonedartgunhead(arg0, 1);
        }
        break;
    }
    if (((HeadData *)arg0->actorData)->soundTimer > 0) {
        sp34 = func_800F11E4(((HeadData *)arg0->actorData)->tilt, 0, 87.0f, 0.7f, 1.0f);
        _subaddieaudioloop_entrypoint_4(arg0, arg0->position, 1, D_80800EAC_chstonedartgunhead);
        _subaddieaudioloop_entrypoint_0(arg0, sp34);
        ((HeadData *)arg0->actorData)->soundTimer = ((HeadData *)arg0->actorData)->soundTimer - func_800D8FF8();
    }
    func_800D9078(&arg0->unk58);
}

void func_80800908_chstonedartgunhead(Actor *arg0, BtIntPtr arg1) {
    void func_800BA22C(BtIntPtr, s32);
    void func_800BA4D0(s16 *, s16);
    BtIntPtr func_800BABB8(BtIntPtr, f32[3], f32[3], f32, s32[]);
    BtIntPtr func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    void func_800C4104(s32, f32, s32, BtIntPtr, f32, f32);
    void func_800EC398(Unk80132ED0 *, f32 *);
    s32 func_800EE7F8();
    void func_800FFAB0(Actor *);
    extern s32 D_80800EBC_chstonedartgunhead[];
    extern s32 D_80800EE0_chstonedartgunhead[];
    f32 position[3];
    f32 rotation[3];
    f32 scale;
    BtIntPtr emitter;
    s32 i;

    scale = arg0->scale;
    func_800EC398(arg1, rotation);
    func_800EE7F8(position, arg0->position);
    position[1] += 70.0f * scale;
    for (i = 0; i < 4; i++) {
        emitter = func_800BABB8(0, position, rotation, scale, D_80800EBC_chstonedartgunhead);
        func_800BA4D0(emitter, (s16)(s32)(arg0->position[1] - 5.0f));
        func_800BA22C(emitter, 8);
        func_800BBCB8(position, rotation, scale, 1, D_80800EE0_chstonedartgunhead);
        position[1] += 115.0f;
        scale -= 0.19f;
    }
    func_800C4104(0x413, 0.7f, 0x7D00, arg0->position, 1250.0f, 2500.0f);
    func_800FFAB0(arg0);
}

s32 func_80800AA4_chstonedartgunhead(Actor *arg0, s32 arg1, volatile s32 arg2) {
    void func_808000A8_chstonedartgunhead(Actor *);
    void func_80800224_chstonedartgunhead(Actor *, s32);
    void func_80800908_chstonedartgunhead(Actor *, BtIntPtr);
    s32 state;

    switch (arg1) {
    case 0x3D:
        func_808000A8_chstonedartgunhead(arg0);
        return 1;
    case 0x3F:
        state = arg0->unk70_10;
        if ((state < 6 || state >= 10) &&
            ((arg0->unk0->unk18 << 11) >> 28) == 1 &&
            state != 6 && state != 7) {
            func_80800224_chstonedartgunhead(arg0, 6);
        }
        break;
    case 0x40:
        func_80800908_chstonedartgunhead(arg0, arg2);
        return 1;
    default:
        return 0;
    }
    return 1;
}

/* extern */

void func_80800B6C_chstonedartgunhead(Actor *arg0, void *arg1) {
    void func_800DF744(s32, s32);
    void func_80101870(Actor *, void *);
    s32 var_a1;

    func_800DF744(2, 1);
    func_800DF744(3, 0);
    if ((s32)(arg0->unk0->unk28 << 18) >> 31) {
        var_a1 = 1;
    } else {
        var_a1 = 2;
    }
    func_800DF744(4, var_a1);
    func_80101870(arg0, arg1);
}

OSThread *chstonedartgunhead_entrypoint_0(void)
{
    extern ActorData D_80800F10_chstonedartgunhead[];

    return (OSThread *) D_80800F10_chstonedartgunhead;
}    typedef struct { u8 pad0[0x58]; f32 unk58; } Objstonedartgunhead_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

/* extern */

void func_80800BE8_chstonedartgunhead(u8 *arg0) {
    s32 func_800EE7F8(s32, s32, u8 *);
    func_800EE7F8(arg0 + 0x18, arg0 + 4, arg0);
    (((Objstonedartgunhead_arg0 *)arg0)->unk58) = 4.0f;
}

void func_80800C28_chstonedartgunhead(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    BtIntPtr func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    f32 func_800D8FF8(void);
    u8 func_800D9078(f32 *);
    f32 func_800EEB40(f32 *, f32 *);
    void func_800EF214(f32 *, f32, f32, f32);
    void func_800FFAB0(Actor *);
    void func_80101FDC(Actor *, u32);
    void func_80102424(Actor *, s32);
    s32 func_8010B990(Actor *, s32);
    extern s32 D_80800F58_chstonedartgunhead[];
    extern u8 D_80800FA0_chstonedartgunhead[];

    switch (arg0->unk70_10) {
        case 1:
            func_800EF214(arg0->position, arg0->rotation[0], arg0->rotation[1],
                         ((f32 *)arg0->actorData)[3] * func_800D8FF8());
            if (func_800EEB40((f32 *)arg0->actorData, arg0->position) > 22500.0f) {
                func_80101FDC(arg0, 10);
            }
            break;
        case 10:
            if (func_800D9078(&arg0->unk58) || func_8010B990(arg0, 0x100006)) {
                func_80102424(arg0, 9);
            }
            break;
        case 9:
            func_800BBCB8(arg0->position, NULL, arg0->scale, 2, D_80800F58_chstonedartgunhead);
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_80800FA0_chstonedartgunhead);
            func_800FFAB0(arg0);
            break;
    }
}

int func_80800D50_chstonedartgunhead(Actor *arg0, s32 arg1, u8 *arg2) {
    void func_80102424(Actor*, s32);
    u8 **ptr = &arg2;
    switch (arg1) {
        case 0x40:
            if (((u32) (*(u32 *)((s8 *)(*ptr) + 0x24)) >> 22) == 0) {
                func_80102424(arg0, 9);
            }
            break;
        default:
            return 0;
    }
    return 1;
}

OSThread *chstonedartgunhead_entrypoint_1(void)
{
    extern ActorData D_80800FB0_chstonedartgunhead[];

    return (OSThread *) D_80800FB0_chstonedartgunhead;
}
/* data_to_c.py: from asm/data/overlays/ch/stonedartgunhead.data.s */
extern u8 D_80800E20_chstonedartgunhead[];
void func_80105834(Actor*);
void func_80108ED0();
void func_80107C2C();
void func_80101870 ( Actor * , void * );
u8 D_80800E20_chstonedartgunhead[88] BT_DATA(4, overlays_ch_stonedartgunhead, 0x0) = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xA2, 0x00, 0x84, 0x40, 0x40, 0x00, 0x00, 0x01, 0xA2, 0x00, 0x92, 0x00, 0x00, 0x00, 0x00, 0x01, 0xA2, 0x00, 0x0C, 0x3F, 0x80, 0x00, 0x00, 0x01, 0xA1, 0x00, 0x42, 0x40, 0x40, 0x00, 0x00, 0x01, 0xA2, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x01, 0xA2, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x01, 0xA2, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x01, 0xA2, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x01, 0xA2, 0x00, 0x4A, 0x00, 0x00, 0x00, 0x00, 0x01, 0xA2, 0x00, 0x04 };
s32 D_80800E78_chstonedartgunhead BT_DATA(4, overlays_ch_stonedartgunhead, 0x58) = 1246380;
u8 D_80800E78_chstonedartgunhead__gap[4] BT_DATA(4, overlays_ch_stonedartgunhead, 0x5C) = { 0 };
s32 D_80800E80_chstonedartgunhead[3] BT_DATA(4, overlays_ch_stonedartgunhead, 0x60) = { 1246394, 852147, 11796480 };
s32 D_80800E8C_chstonedartgunhead[4] BT_DATA(4, overlays_ch_stonedartgunhead, 0x6C) = { 1246394, 1461792, 852121, 10092544 };
s32 D_80800E9C_chstonedartgunhead[4] BT_DATA(4, overlays_ch_stonedartgunhead, 0x7C) = { 1246394, 1456792, 852096, 8454144 };
s32 D_80800EAC_chstonedartgunhead[4] BT_DATA(4, overlays_ch_stonedartgunhead, 0x8C) = { 1246381, 1466792, 65786, 176947200 };
s32 D_80800EBC_chstonedartgunhead [9] BT_DATA(4, overlays_ch_stonedartgunhead, 0x9C) = { 135266333, 107479060, 2949920, 65536027, -65471264, 2228403, 13369523, 11730956, 6553600 };
s32 D_80800EE0_chstonedartgunhead [12] BT_DATA(4, overlays_ch_stonedartgunhead, 0xC0) = { 1903069, 2819584, 134217762, 50332416, 109053952, 1376256, 2490393, 7, 2949470, 29491232, -1431655681, 0 };
ActorData D_80800F10_chstonedartgunhead [1] BT_DATA(4, overlays_ch_stonedartgunhead, 0xF0) = { { 347, 275, 1635, 1, (void *)D_80800E20_chstonedartgunhead, (void (*)(struct Actor *))func_80800364_chstonedartgunhead, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80800B6C_chstonedartgunhead, 163840000, 0, 0, 0, 16384, 2210, 0, (BtIntPtr)func_80108ED0, 0, 0, (void (*)(struct Actor *))func_80800000_chstonedartgunhead, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 8209, (void (*)(struct Actor *, long, long))func_80800AA4_chstonedartgunhead, 0 } };
s32 D_80800F58_chstonedartgunhead [18] BT_DATA(4, overlays_ch_stonedartgunhead, 0x138) = { 1441796, 1903049, 2153692, -593493982, 3342438, 10027212, 2818124, 8388629, 1638476, 2949070, 3997646, 3276900, 3276810, -655360, -655350, 10, 1834988, 1966080 };
u8 D_80800FA0_chstonedartgunhead [16] BT_DATA(4, overlays_ch_stonedartgunhead, 0x180) = { 0, 0x13, 4, 7, 0, 0x16, 0x32, 0xC8, 0, 0xD, 1, 0xB3, 1, 0xCC, 0, 0 };
ActorData D_80800FB0_chstonedartgunhead [1] BT_DATA(4, overlays_ch_stonedartgunhead, 0x190) = { { 353, 291, 1636, 1, 0, (void (*)(struct Actor *))func_80800C28_chstonedartgunhead, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 0, 0, 0, (BtIntPtr)func_80108ED0, 0, 0, (void (*)(struct Actor *))func_80800BE8_chstonedartgunhead, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32704, 0, (void (*)(struct Actor *, long, long))func_80800D50_chstonedartgunhead, 0 } };
