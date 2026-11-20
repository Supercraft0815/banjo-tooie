#include "common.h"

OSThread *cheggproximity_entrypoint_0(void)
{
    extern ActorData D_80800CE0_cheggproximity[];

    return (OSThread *) D_80800CE0_cheggproximity;
}

/* extern */

void *cheggproximity_entrypoint_1(BT_NATIVE_ONLY(f32 *) BT_IDO_ONLY(s32) arg0, BT_NATIVE_ONLY(f32 *) BT_IDO_ONLY(BtIntPtr) arg1, BT_NATIVE_ONLY(f32 *) BT_IDO_ONLY(BtIntPtr) arg2, s32 arg3) {
    void _suegg_entrypoint_1(Actor *arg0, f32 arg1);
    Actor *_suegg_entrypoint_11(u32 arg0, f32 *arg1, s32 arg2);
    BT_NATIVE_ONLY(void *) BT_IDO_ONLY(s32) _sueggmove_entrypoint_10(BT_NATIVE_ONLY(f32 *) BT_IDO_ONLY(BtIntPtr) BT_PASS2(, f32 *));
    void _sueggmove_entrypoint_5(Actor *arg0, s32 arg1);
    void _sueggmove_entrypoint_6(void *arg0, f32 arg1, f32 arg2);
    BT_NATIVE_ONLY(void) BT_IDO_ONLY(s32) _sueggmove_entrypoint_7(BT_NATIVE_ONLY(Actor *) BT_IDO_ONLY(void *), BT_NATIVE_ONLY(f32 *) BT_IDO_ONLY(BtIntPtr));
    f32 func_80013B7C(f32, f32);
    Actor *temp_v0;
    f32 *position = (f32 *)arg2;

    _sueggmove_entrypoint_10(arg0 BT_PASS2(, arg1));
    temp_v0 = _suegg_entrypoint_11(0x160, arg1, arg3);
    temp_v0->scale = 0.25f;
    temp_v0->rotation[1] = func_80013B7C(position[0], position[2]);
    _sueggmove_entrypoint_5(temp_v0, 0);
    _sueggmove_entrypoint_6(temp_v0, 0.0f, -22000.0f);
    _sueggmove_entrypoint_7(temp_v0, arg2);
    _suegg_entrypoint_1(temp_v0, 30.0f);
    return temp_v0;
}

s32 func_808000A8_cheggproximity(Actor *arg0, s32 arg1, s32 arg2) {
    void func_800FFAB0(Actor *);
    void *func_80100094(Actor *, u32);
    s32 func_80800718_cheggproximity(BtIntPtr, s32);
    struct ProximityData {
        u8 pad0[0x39];
        BT_BITFIELD_ORDER(u8 active : 1, u8 unused : 7);
        BT_BITFIELD_ORDER(u8 unused : 7, u8 active : 1);
        u8 pad3A[0x6A];
        s32 triggered;
    } *data;

    data = func_80100094(arg0, 0);
    switch (arg1) {
    case 0x4F:
        func_800FFAB0(arg0);
        return 1;
    case 0x45:
    case 0x78:
        ((struct ProximityData *)func_80100094(arg0, 1))->triggered = 1;
        break;
    case 0x40:
        func_80800718_cheggproximity(arg0, 6);
        data->active = 1;
        break;
    default:
        return 0;
    }
    return 1;
}

/* extern */

typedef union {
    Actor actor;
    struct {
        u8 prefix[0x78];
        BT_BITFIELD_ORDER(u16 unused : 14, u16 flags : 2);
        BT_BITFIELD_ORDER(u16 flags : 2, u16 unused : 14);
    } proximity;
} ProximityActor;

void func_80800164_cheggproximity(ProximityActor *arg0 BT_PASS2(, s32 bt_a1)) {
    s32 _subaddiedraw25d_entrypoint_1();
    s32 sp1C;

    sp1C = arg0->proximity.flags;
    if (arg0->actor.alpha != 0xFF) {
        arg0->proximity.flags = 1;
    }
    _subaddiedraw25d_entrypoint_1();
    arg0->proximity.flags = sp1C;
}

void func_808001CC_cheggproximity(Actor *arg0) {
    BtIntPtr _fxegg_entrypoint_5(f32 arg0[3], f32 arg1[3], f32 arg2);
    void _suegg_entrypoint_20(Actor *, f32 *);
    f32 func_800D8FF8(void);
    void func_800EE7F8(f32 *, f32 *);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    void *func_80100094(Actor *, u32);
    f32 *temp_s0;
    f32 *temp_s1;
    f32 sp64[3];
    f32 sp58[3];
    f32 temp_f22;

    temp_s1 = func_80100094(arg0, 0);
    temp_s1[10] -= func_800D8FF8();
    temp_f22 = func_800F10B4(temp_s1[12], 0, 2.0f, 0.0333f, 0.1f);
    _suegg_entrypoint_20(arg0, sp58);
    temp_s0 = arg0->position;
    if (temp_s1[10] <= 0.0f) {
        do {
            temp_s1[10] += temp_f22;
            func_800EE7F8(sp64, temp_s0);
            _fxegg_entrypoint_5(temp_s0, sp58, arg0->scale);
        } while (temp_s1[10] <= 0.0f);
    }
}    typedef struct { u8 pad0[0x24]; u32 unk24; } Objproximity_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

/* extern */

void cheggproximity_entrypoint_2(void *arg0) {
    void _cheggsplode_entrypoint_1(Actor **arg0, s32 arg1, s32 arg2);
    s32 _gcegg_entrypoint_0(u32);
    void _suegg_entrypoint_4(Actor *arg0, s32 arg1);
    void *func_80100094(Actor *, u32);
    BtIntPtr func_80106790();
    BtIntPtr sp24;
    BtIntPtr temp_v0;
    s32 sp1C;

    temp_v0 = func_80106790();
    sp24 = temp_v0;
    sp1C = (s32) (*(s16 *)((s8 *)(func_80100094((Actor *)temp_v0, 0)) + (0x3A)));
    _cheggsplode_entrypoint_1(&sp24, sp1C, _gcegg_entrypoint_0((u32) (((Objproximity_arg0 *)arg0)->unk24) >> 0x16));
    _suegg_entrypoint_4(sp24, 0);
}

void func_80800330_cheggproximity(Actor *arg0) {
    s32 _chbaddiesetup_entrypoint_1(s32 *, BtIntPtr);
    s32 _suegg_entrypoint_8(void *);
    void func_800FFAB0(Actor *);
    void *func_80100094(Actor *, u32);
    s32 func_80101180(s32, s32, BtIntPtr);
    void func_8080048C_cheggproximity(BtIntPtr, void *);
    void func_80800510_cheggproximity(BtIntPtr, void *);
    void func_80800588_cheggproximity(BtIntPtr, BtIntPtr);
    void func_808005EC_cheggproximity(BtIntPtr, BtIntPtr);
    void func_80800650_cheggproximity(BtIntPtr, BtIntPtr);
    void func_808006A4_cheggproximity(Actor *, u8 *);
#ifndef BT_NATIVE
    extern s32 _cheggproximity_entrypoint_2;
#endif
    struct ProximityFlags {
        u8 pad[0x38];
        BT_BITFIELD_ORDER(u32 unused31_24:8, u32 unused21_0 : 22);
        BT_BITFIELD_ORDER(u32 flag23:1, u32 flag22 : 1);
        BT_BITFIELD_ORDER(u32 flag22:1, u32 flag23 : 1);
        BT_BITFIELD_ORDER(u32 unused21_0:22, u32 unused31_24 : 8);
    };
    u8 *data;

    data = func_80100094(arg0, 0);
    switch (arg0->unk70_10) {
    case 1:
        if (_suegg_entrypoint_8(arg0) == 0) {
            func_8080048C_cheggproximity((BtIntPtr)arg0, data);
        }
        break;
    case 2:
        if (_suegg_entrypoint_8(arg0) == 0) {
            func_80800510_cheggproximity((BtIntPtr)arg0, data);
        }
        break;
    case 3:
        func_80800588_cheggproximity((BtIntPtr)arg0, (BtIntPtr)data);
        break;
    case 4:
        func_808005EC_cheggproximity((BtIntPtr)arg0, (BtIntPtr)data);
        break;
    case 5:
        func_80800650_cheggproximity((BtIntPtr)arg0, (BtIntPtr)data);
        break;
    case 6:
        func_808006A4_cheggproximity(arg0, data);
        break;
    }
    if (((struct ProximityFlags *)data)->flag23 && !((struct ProximityFlags *)data)->flag22) {
        if (*(s32 *)((u8 *)func_80100094(arg0, 1) + 0xA8) != 0) {
            func_80101180(0x2C4, 0x74, (BtIntPtr)arg0->unk0);
        }
        if (arg0->unk70_10 == 6) {
            _chbaddiesetup_entrypoint_1(&_cheggproximity_entrypoint_2, (BtIntPtr)arg0->unk0);
            return;
        }
        func_800FFAB0(arg0);
    }
}    typedef struct { u8 pad0[0x30]; f32 unk30; } Objproximity_arg1; /* offsets.py genstruct: fields from raw offsets on arg1; rename once understood */

/* extern */

void func_8080048C_cheggproximity(BtIntPtr arg0, void *arg1) {
    void _suegg_entrypoint_16(Actor *arg0);
    int func_800EEEA8(f32 vec[3]);
    void func_808001CC_cheggproximity(Actor *);
    s32 func_80800718_cheggproximity(BtIntPtr, s32);
    if (func_800EEEA8(arg0 + 0x28) != 0) {
        func_80800718_cheggproximity(arg0, 3);
        return;
    }
    func_808001CC_cheggproximity(arg0);
    _suegg_entrypoint_16(arg0);
    if ((((Objproximity_arg1 *)arg1)->unk30) > 0.19999695f) {
        func_80800718_cheggproximity(arg0, 2);
    }
}

/* extern */

void func_80800510_cheggproximity(BtIntPtr arg0, void *arg1) {
    s32 _suegg_entrypoint_14(BtIntPtr);
    void _suegg_entrypoint_16(Actor *arg0);
    int func_800EEEA8(f32 vec[3]);
    void func_808001CC_cheggproximity(Actor *);
    s32 func_80800718_cheggproximity(BtIntPtr, s32);
    if (func_800EEEA8(arg0 + 0x28) != 0) {
        func_80800718_cheggproximity(arg0, 3);
        return;
    }
    func_808001CC_cheggproximity(arg0);
    _suegg_entrypoint_16(arg0);
    if (_suegg_entrypoint_14(arg0) != 0) {
        ((struct { u8 pad[0x39]; BT_BITFIELD_ORDER(u8 flag : 1, u8  : 7); BT_BITFIELD_ORDER(u8 : 7, u8 flag : 1); } *)arg1)->flag = 1;
    }
}

/* extern */

void func_80800588_cheggproximity(BtIntPtr arg0, BtIntPtr arg1) {
    s32 func_800D9078(f32 *);
    void *func_80100094(Actor *, u32);
    s32 func_80800718_cheggproximity(BtIntPtr, s32);
    s32 func_80800874_cheggproximity(BtIntPtr);
    s32 func_80800BF4_cheggproximity(Actor *);
    if ((*(s32 *)((s8 *)(func_80100094((Actor *)arg0, 1)) + (0xA4))) == 0) {
        func_80800874_cheggproximity(arg0);
        if ((func_80800BF4_cheggproximity((Actor *)arg0) == 0) && (func_800D9078((f32 *)(arg1 + 0x30)) != 0)) {
            func_80800718_cheggproximity(arg0, 4);
        }
    }
}

/* extern */

void func_808005EC_cheggproximity(BtIntPtr arg0, BtIntPtr arg1) {
    s32 func_800D9078(f32 *);
    void *func_80100094(Actor *, u32);
    s32 func_80800718_cheggproximity(BtIntPtr, s32);
    s32 func_80800874_cheggproximity(BtIntPtr);
    s32 func_80800BF4_cheggproximity(Actor *);
    if ((*(s32 *)((s8 *)(func_80100094((Actor *)arg0, 1)) + (0xA4))) == 0) {
        func_80800874_cheggproximity(arg0);
        if ((func_80800BF4_cheggproximity((Actor *)arg0) == 0) && (func_800D9078((f32 *)(arg1 + 0x30)) != 0)) {
            func_80800718_cheggproximity(arg0, 5);
        }
    }
}

/* extern */

void func_80800650_cheggproximity(BtIntPtr arg0, BtIntPtr arg1) {
    s32 func_80800718_cheggproximity(BtIntPtr, s32);
    s32 func_80800874_cheggproximity(BtIntPtr);
    void func_80800AFC_cheggproximity(Actor *);
    func_80800874_cheggproximity(arg0); func_80800AFC_cheggproximity((Actor *)arg0); if (((Actor *)arg0)->alpha < 0x79) {
        func_80800718_cheggproximity(arg0, 6);
        return;
    }
    ((Actor *)arg0)->alpha -= 8;
}    typedef struct { u8 pad0[0xA0]; s32 unkA0; } Objproximity_func_808006A4_cheggproximity_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

/* extern */

void func_808006A4_cheggproximity(Actor *arg0, u8 *arg1) {
    struct ProximityFlags {
        u8 pad[0x39];
        BT_BITFIELD_ORDER(u8 triggered : 1, u8 other : 7);
        BT_BITFIELD_ORDER(u8 other : 7, u8 triggered : 1);
    };
    void* func_80100094(Actor*, u32);
    s32 func_80800874_cheggproximity(BtIntPtr);
    void func_80800AFC_cheggproximity(Actor *);
    s32 *sp1C;
    s32 sp18;
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 1U);
    sp1C = temp_v0;
    sp18 = (((Objproximity_func_808006A4_cheggproximity_temp_v0 *)temp_v0)->unkA0);
    func_80800874_cheggproximity((BtIntPtr)arg0);
    func_80800AFC_cheggproximity(arg0);
    if (((Actor *)((BtIntPtr)sp1C + (sp18 << 2)))->pad40 == 1) {
        ((struct ProximityFlags *)arg1)->triggered = 1;
    }
}

s32 func_80800718_cheggproximity(BtIntPtr arg0, s32 arg1) {
    struct EggData {
        u8 pad[0x30];
        f32 timer;
    };
    struct ProximityData {
        u8 pad[0x40];
        s32 states[8];
        s32 players[8];
        f32 timers[8];
        s32 index;
        s32 disabled;
        s32 active;
    };
    void *func_80100094(Actor *, u32);
    void func_80101FDC(Actor *, u32);
    void func_8010A590(Actor *);
    void _suegg_entrypoint_23(void *);
    void _sueggmove_entrypoint_6(void *arg0, f32 arg1, f32 arg2);
    s32 func_80101180(s32, s32, BtIntPtr);
    s32 func_8010D930(s32, s32, f32 *, s32 *);
    extern s32 D_80800D28_cheggproximity[6];
    struct EggData *egg;
    struct ProximityData *data;
    s32 i;
    Actor *actor = (Actor *)arg0;

    egg = func_80100094(actor, 0);
    data = func_80100094(actor, 1);
    func_80101FDC(actor, arg1);
    switch (arg1) {
    case 1:
        data->active = 0;
        break;
    case 2:
        _sueggmove_entrypoint_6(actor, -3000.0f, -22000.0f);
        break;
    case 3:
        func_8010A590(actor);
        data->active = 1;
        _suegg_entrypoint_23(actor);
        egg->timer = 1.0f;
        func_80101180(0x2C4, 0x73, (BtIntPtr)actor->unk0);
        break;
    case 4:
        egg->timer = 3.5f;
        break;
    case 5:
        for (i = 0; i < 8; i++) {
            data->states[i] = data->players[i] = -1;
        }
        func_8010D930(4, actor->unk70_0, actor->position, D_80800D28_cheggproximity);
        break;
    case 6:
        break;
    } BT_NATIVE_ONLY(return 0;)
}

s32 func_80800874_cheggproximity(BtIntPtr arg0) {
    struct EggData {
        u8 pad[0x3A];
        s16 owner;
    };
    struct ProximityData {
        f32 heights[8];
        f32 distances[8];
        s32 states[8];
        s32 players[8];
        f32 timers[8];
        s32 index;
        s32 disabled;
    };
    f32 func_800EFC7C(void *, void *);
    s32 func_800F5898(void);
    void func_800F5A00(BtIntPtr, f32 *);
    s32 func_800F6438(BtUIntPtr);
    s32 func_800F6CC8(BtIntPtr);
    void *func_80100094(Actor *, u32);
    struct EggData *egg;
    f32 distance;
    f32 height;
    s32 state;
    s32 i;
    f32 position[3];
    s32 nearest; BT_NATIVE_ONLY(s32 player_count;)
    struct ProximityData *data;

    egg = func_80100094((Actor *)arg0, 0);
    data = func_80100094((Actor *)arg0, 1);
    nearest = -1;
    for (i = 0; i < BT_NATIVE_ONLY((player_count = func_800F5898())) BT_IDO_ONLY(func_800F5898()); i++) {
        state = -1;
        if ((((Actor *)arg0)->unk70_10 != 3 || i != egg->owner) && data->disabled == 0) {
            if (func_800F6438(i) && !func_800F6CC8(i)) {
                func_800F5A00(i, position);
                distance = func_800EFC7C(position, ((Actor *)arg0)->position);
                height = position[1] - ((Actor *)arg0)->position[1];
                data->distances[i] = distance;
                data->heights[i] = height;
                if (!(distance > 160000.0f)) {
                    if (distance > 90000.0f) {
                        state = 0;
                    } else if (distance > 3600.0f) {
                        state = 1;
                    } else {
                        state = 2;
                    }
                }
                switch (state) {
                case 2:
                    if (-height < 175.0f && height < 100.0f) break;
                    state = 1;
                case 1:
                    if (-height < 300.0f && height < 300.0f) break;
                    state = 0;
                case 0:
                    if (-height < 400.0f && height < 400.0f) break;
                    state = -1;
                }
                if (state != -1) {
                    if (nearest < 0) {
                        nearest = i;
                    } else if (data->distances[i] < data->distances[nearest]) {
                        nearest = i;
                    }
                }
            }
            data->players[i] = data->states[i];
            data->states[i] = state;
        }
    }
    data->index = nearest; BT_NATIVE_ONLY(return player_count;)
}

void func_80800AFC_cheggproximity(Actor *arg0) {
    typedef struct player_state_s PlayerState;
    struct ProximityData {
        u8 pad[0x40];
        s32 states[8];
        s32 players[8];
        f32 timers[8];
        s32 index;
        s32 disabled;
    };
    void _bamotor_entrypoint_0(PlayerState *, f32, f32);
    s32 func_800D9078(f32 *);
    PlayerState *func_800F53D0(BtIntPtr);
    s32 func_800F5898(void);
    void *func_80100094(Actor *, u32);
    struct ProximityData *data;
    s32 i;

    data = func_80100094(arg0, 1);
    if (data->disabled == 0) {
        for (i = 0; i < func_800F5898(); i++) {
            if (data->states[i] != -1) {
                if (data->players[i] == -1) {
                    data->timers[i] = 1.0f;
                    _bamotor_entrypoint_0(func_800F53D0(i), 1.0f, 0.25f);
                } else if (func_800D9078(&data->timers[i])) {
                    data->timers[i] = 1.0f;
                    _bamotor_entrypoint_0(func_800F53D0(i), 1.0f, 0.25f);
                }
            }
        }
    }
}

s32 func_80800BF4_cheggproximity(Actor *arg0) {
    struct ProximityData {
        u8 pad[0x40];
        s32 states[24];
        s32 index;
        s32 unkA4;
        s32 active;
    };
    void *func_80100094(Actor *, u32);
    s32 func_80101180(s32, s32, BtIntPtr);
    void func_800F7664(s32, s32, s32);
    s32 _sueggmisc_entrypoint_2(f32 *, s32);
    void func_800FFAB0(Actor *);
    struct ProximityData *data;
    s32 index;

    data = func_80100094(arg0, 1);
    index = data->index;
    if (index >= 0 && data->states[index] == 2) {
        if (((struct ProximityData *)func_80100094(arg0, 1))->active != 0) {
            func_80101180(0x2C4, 0x74, (BtIntPtr)arg0->unk0);
        }
        func_800F7664(index, 0x45, 1);
        _sueggmisc_entrypoint_2(arg0->position, 6);
        func_800FFAB0(arg0);
        return 1;
    }
    return 0;
}
/* data_to_c.py: from asm/data/overlays/ch/egg/proximity.data.s */
void func_80105834(Actor*);
void _suegg_entrypoint_2();
OSThread *func_80108ED0(void);
void _suegg_entrypoint_5();
void func_80107C2C();
ActorData D_80800CE0_cheggproximity [1] BT_DATA(4, overlays_ch_egg_proximity, 0x0) = { { 365, 352, 2501, 1, 0, (void (*)(struct Actor *))func_80800330_cheggproximity, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80800164_cheggproximity, 0, 1065353216, 0, 0, 0, 4, (void (*)(struct Actor *))_suegg_entrypoint_2, (BtIntPtr)func_80108ED0, 76, 172, (void (*)(struct Actor *))_suegg_entrypoint_5, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 16, (void (*)(struct Actor *, long, long))func_808000A8_cheggproximity, 0 } };
s32 D_80800D28_cheggproximity[6] BT_DATA(4, overlays_ch_egg_proximity, 0x48) = { 1246814, 1455792, 65836, 131072000, 0, 0 };
