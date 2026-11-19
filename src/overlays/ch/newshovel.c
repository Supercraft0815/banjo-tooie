#include "common.h"

OSThread *chnewshovel_entrypoint_0(void)
{
    extern ActorData D_80800FB4_chnewshovel[];

    return (OSThread *) D_80800FB4_chnewshovel;
}

/* extern */

void func_8080000C_chnewshovel(Actor *arg0) {
    void _subaddierouteDll_entrypoint_3(BtIntPtr arg0, void *arg1, f32 *arg2);
    void* func_80100094(Actor*, u32);
    s32 func_808007F8_chnewshovel(Actor *, s32);
    _subaddierouteDll_entrypoint_3(arg0, func_80100094(arg0, 0U), arg0->position);
    func_808007F8_chnewshovel(arg0, 0);
}

void func_8080004C_chnewshovel(Actor *arg0) {
    typedef struct {
        u32 preceding[30];
        BT_BITFIELD_ORDER(u32 precedingFlags : 29, u32 remainingFlags : 2);
        u32 inactive : 1;
        BT_BITFIELD_ORDER(u32 remainingFlags : 2, u32 precedingFlags : 29);
    } ShovelFlags;
    typedef struct {
        f32 unk18[3];
        f32 unk24;
        f32 velocity[3];
        f32 acceleration;
    } ShovelMotion;
    typedef struct {
        s16 unk0[6];
        s16 state;
    } ShovelState;
    void *func_80100094(Actor *, u32);
    void _suexpression_entrypoint_10(u32 *, Unk80132ED0 *, BtUIntPtr);
    BtIntPtr _suexpression_entrypoint_20();
    void func_800F5A00(BtIntPtr, f32 *);
    s32 func_80101DDC(Actor *);
    BtIntPtr func_8010D290(s32);
    void func_80800570_chnewshovel(BtIntPtr);
    s32 func_80800610_chnewshovel(void *);
    s32 func_808006B0_chnewshovel(Actor *, s32);
    s32 func_80800930_chnewshovel(Actor *);
    s32 func_80800B5C_chnewshovel(BtIntPtr);
    s32 func_80800BC0_chnewshovel(Actor *);
    int func_80800C58_chnewshovel(Actor *);
    s32 sp24;
    ShovelState *sp20;

    sp20 = func_80100094(arg0, 0);
    if (!((ShovelFlags *)arg0)->inactive) {
        _suexpression_entrypoint_10((u32 *)_suexpression_entrypoint_20(arg0), arg0->unk0, 0);
        sp24 = func_80800930_chnewshovel(arg0);
        func_80800570_chnewshovel((BtIntPtr)arg0);
        switch (arg0->unk70_10) {
        case 1:
            if (func_80800610_chnewshovel(arg0)) {
                func_808006B0_chnewshovel(arg0, 2);
            }
            break;
        case 2:
            if (func_80101DDC(arg0)) {
                func_808006B0_chnewshovel(arg0, func_80800610_chnewshovel(arg0) ? 3 : 1);
            }
            break;
        case 3:
            func_80800BC0_chnewshovel(arg0);
            if (func_80800610_chnewshovel(arg0)) {
                func_800F5A00(func_8010D290(0x10000), ((ShovelMotion *)arg0->actorData)->unk18);
                if (sp20->state == 2) {
                    func_808006B0_chnewshovel(arg0, func_80800C58_chnewshovel(arg0) ? 4 : 3);
                }
            } else if (sp20->state == 2) {
                func_808006B0_chnewshovel(arg0, 6);
            }
            break;
        case 4:
            if (func_80800610_chnewshovel(arg0)) {
                func_800F5A00(func_8010D290(0x10000), ((ShovelMotion *)arg0->actorData)->unk18);
            }
            if (sp24 & 8) {
                ((ShovelMotion *)arg0->actorData)->unk24 = 0.0f;
            }
            if (sp20->state == 2) {
                func_808006B0_chnewshovel(arg0, 5);
            }
            break;
        case 5:
            if (func_80101DDC(arg0)) {
                func_808006B0_chnewshovel(arg0, func_80800610_chnewshovel(arg0) ? 3 : (func_80800B5C_chnewshovel((BtIntPtr)arg0) ? 1 : 6));
            }
            break;
        case 6:
            if (func_80800610_chnewshovel(arg0)) {
                if (sp20->state == 2) {
                    func_808006B0_chnewshovel(arg0, 3);
                }
            } else {
                if (func_80800B5C_chnewshovel((BtIntPtr)arg0)) {
                    ((ShovelMotion *)arg0->actorData)->unk24 *= 0.9f;
                }
                if (sp20->state == 2) {
                    func_808006B0_chnewshovel(arg0, func_80800B5C_chnewshovel((BtIntPtr)arg0) ? 1 : 6);
                }
            }
            break;
        }
    }
}

void func_80800310_chnewshovel(Actor* arg0) 
{
    _suexpression_entrypoint_8(arg0, 1);
}
void _subaddieaudioquick_entrypoint_2(Actor *, f32 *, void *);
s32 func_80800330_chnewshovel(Actor *arg0, s32 arg1, s32 *arg2) {
    void _chskeletonexplode_entrypoint_3(Actor *, s32, s32);
    void _chskeletonexplode_entrypoint_8(Actor *, s32);
    s32 _subaddieDll_entrypoint_3(Actor *);
    void _subaddiefade_entrypoint_3(Actor *);
    void _subaddiejoy_entrypoint_10(void *, s32, s32);
    void _subaddierouteDll_entrypoint_1(Actor *);
    s32 _suexpression_entrypoint_12(void *, s32, s32);
    void _suexpression_entrypoint_13(void *, f32 *, f32 *);
    void _suexpression_entrypoint_14(void *, f32, f32);
    BtIntPtr _suexpression_entrypoint_20();
    BtIntPtr _suexpression_entrypoint_7(Actor *, s32, s32);
    void func_800DF744(s32, s32);
    void func_800EFD24(f32 *);
    void func_800FFAB0(Actor *);
    void func_80101010(f32 *);
    void *func_80101080(void);
    s32 func_801015D0(Actor *);
    Actor *func_80106790(Unk80132ED0 *);
    s32 func_80107070(Actor *, u32);
    void func_8010A570(Actor *);
    s32 func_808006B0_chnewshovel(Actor *, s32);
    s32 func_80800DC8_chnewshovel(BtIntPtr);
    extern u8 D_80800FFC_chnewshovel[];
    void *sp3C;
    void *temp;
    s32 **data = &arg2;
    s32 *ptr;
    f32 sp2C;
    f32 sp28;

    switch (arg1) {
    case 0x1F:
        func_801015D0(arg0);
        func_800DF744(3, 1);
        break;
    case 0x95:
        sp3C = (void *)_suexpression_entrypoint_7(arg0, 1, 0x5A);
        _suexpression_entrypoint_12(sp3C, 0x428C0000, 0x41200000);
        _suexpression_entrypoint_14(sp3C, 1.0f, 1.0f);
        _subaddierouteDll_entrypoint_1(arg0);
        break;
    case 0x40:
        {
            ptr = *data;
            _chskeletonexplode_entrypoint_8(arg0, *ptr + 4);
        }
        func_8010A570(arg0);
        _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_80800FFC_chnewshovel);
        _subaddiejoy_entrypoint_10(arg0, 0x3F800000, 0x3E800000);
        arg0->unk64_24 = 0;
        break;
    case 0xF:
        _chskeletonexplode_entrypoint_3(func_80106790(func_80101080()), 3, 2);
        if (func_80107070(arg0, 3) == 0) {
            func_800FFAB0(arg0);
        }
        break;
    case 0x8F:
        if (arg2 == NULL) {
            func_808006B0_chnewshovel(arg0, 1);
        }
        break;
    case 0x2:
        if (_subaddieDll_entrypoint_3(arg0) == 0) {
            if (func_80107070(arg0, 1) == 0) {
                _subaddiefade_entrypoint_3(arg0);
            }
        } else {
            func_808006B0_chnewshovel(arg0, 6);
        }
        break;
    case 0x38:
        return func_80800DC8_chnewshovel((BtIntPtr)arg0);
    case 0x94:
        temp = (void *)_suexpression_entrypoint_20(arg0);
        if (temp == NULL) {
            return 0;
        }
        func_800EFD24(&sp28);
        _suexpression_entrypoint_13(temp, &sp2C, &sp28);
        func_80101010(&sp28);
        break;
    default:
        return 0;
    case 1:
        break;
    }
    return 1;
}

void func_80800570_chnewshovel(BtIntPtr arg0) {
    s32 _subaddieaudioquick_entrypoint_3(BtIntPtr, s32, s32 *, s32);
    s32 _subaddieaudioquick_entrypoint_4(BtIntPtr, BtIntPtr, s32 *, s32 *);
    s32 func_80101E14(BtIntPtr, s32);
    s32 func_801022E4();
    s32 func_80800CC4_chnewshovel(BtIntPtr);
    s32 func_80800D18_chnewshovel(BtIntPtr);
    extern s32 D_80801008_chnewshovel[4];
    extern s32 D_80801018_chnewshovel[3];
    extern s32 D_80801024_chnewshovel[4];
    s32 temp_v0;

    temp_v0 = func_801022E4();
    if (temp_v0 != 0x1BA) {
        if (temp_v0 == 0x1BB) {
            _subaddieaudioquick_entrypoint_4(arg0, arg0 + 4, D_80801008_chnewshovel, D_80801018_chnewshovel);
            if (func_80101E14(arg0, 0x3F333333) != 0) {
                func_80800CC4_chnewshovel(arg0);
                func_80800D18_chnewshovel(arg0);
            }
        }
    } else {
        _subaddieaudioquick_entrypoint_3(arg0, arg0 + 4, D_80801024_chnewshovel, 0x3ECCCCCD);
    }
}

/* extern */

s32 func_80800610_chnewshovel(void *arg0) {
    s32 _suchase_entrypoint_1(void *);
    s32 func_800F6478(BtIntPtr);
    s32 func_8010C550(void *, BtIntPtr);
    BtIntPtr func_8010D290(s32);
    BtIntPtr temp_v0;
    BtIntPtr sp1C;

    if (((Actor *)arg0)->unk64_29) {
        return 1;
    }
    temp_v0 = func_8010D290(0x10000);
    if (temp_v0 == -1) {
        return 0;
    }
    sp1C = temp_v0;
    if (func_800F6478(sp1C) == 0) {
        return 0;
    }
    if (func_8010C550(arg0, sp1C) == 0) {
        return 0;
    }
    if (_suchase_entrypoint_1(arg0) == 0) {
        return 0;
    }
    return 1;
}

s32 func_808006B0_chnewshovel(Actor *arg0, s32 arg1) {
    typedef struct {
        s16 unk0[8];
        s16 timer;
    } ShovelState;
    void *func_80100094(Actor *, u32);
    void func_80102424(Actor *, s32);
    void func_800F5A00(BtIntPtr, f32 *);
    s32 func_80107B70(BtIntPtr, f32 *);
    BtIntPtr func_8010D290(s32);
    s32 func_808007F8_chnewshovel(Actor *, s32);
    ShovelState *state;

    state = func_80100094(arg0, 0);
    state->timer = 0;
    switch (arg1) {
    case 1:
        func_80102424(arg0, arg1);
        func_808007F8_chnewshovel(arg0, 0);
        break;
    case 2:
        func_80102424(arg0, arg1);
        break;
    case 3:
        func_80102424(arg0, arg1);
        func_808007F8_chnewshovel(arg0, 1);
        break;
    case 4:
        func_800F5A00(func_8010D290(0x10000), (f32 *)arg0->actorData);
        func_80102424(arg0, arg1);
        func_808007F8_chnewshovel(arg0, 3);
        break;
    case 5:
        func_80102424(arg0, arg1);
        func_808007F8_chnewshovel(arg0, 0);
        break;
    case 6:
        func_80107B70((BtIntPtr)arg0, (f32 *)arg0->actorData);
        func_80102424(arg0, arg1);
        func_808007F8_chnewshovel(arg0, 1);
        break;
    default:
        func_80102424(arg0, arg1);
        break;
    }
    return 1;
}

s32 func_808007F8_chnewshovel(Actor *arg0, s32 arg1) {
    typedef struct {
        f32 unk18[3];
        f32 unk24;
        f32 velocity[3];
        f32 acceleration;
    } ShovelMotion;
    typedef struct {
        s16 unk0[6];
        s16 state;
    } ShovelState;
    void *func_80100094(Actor *, u32);
    void func_800EFA4C(f32 *, f32, f32, f32);
    s32 func_80800D18_chnewshovel(BtIntPtr);
    s32 func_80800CC4_chnewshovel(BtIntPtr);
    ShovelState *sp24;
    f32 sp20;

    sp24 = func_80100094(arg0, 0);
    switch (arg1) {
        case 0:
            ((ShovelMotion *)arg0->actorData)->unk24 = 0;
            ((ShovelMotion *)arg0->actorData)->velocity[1] = 0;
            break;
        case 1:
            sp20 = arg0->scale * 450.0f;
            func_800EFA4C(((ShovelMotion *)arg0->actorData)->velocity, 0.0f, sp20, 0.0f);
            ((ShovelMotion *)arg0->actorData)->acceleration = (-sp20 - sp20) / 0.6f;
            break;
        case 2:
            func_80800D18_chnewshovel((BtIntPtr)arg0);
            func_80800CC4_chnewshovel((BtIntPtr)arg0);
            ((ShovelMotion *)arg0->actorData)->unk24 = 0;
            ((ShovelMotion *)arg0->actorData)->velocity[1] = 0;
            break;
        case 3:
            sp20 = arg0->scale * 550.0f;
            func_800EFA4C(((ShovelMotion *)arg0->actorData)->velocity, 0.0f, sp20, 0.0f);
            ((ShovelMotion *)arg0->actorData)->acceleration = (-sp20 - sp20) / 0.765f;
            break;
    }
    sp24->state = arg1;
    return 1;
}

s32 func_80800930_chnewshovel(Actor *arg0) {
    typedef struct {
        f32 unk18[3];
        f32 unk24;
        f32 velocity[3];
        f32 acceleration;
    } ShovelMotion;
    typedef struct {
        s16 unk0[6];
        s16 state;
    } ShovelState;
    void *func_80100094(Actor *, u32);
    f32 func_800F3780(f32, u8 *, s16);
    f32 func_80101F24(Actor *);
    s32 func_80101DDC(Actor *);
    s32 func_80800A50_chnewshovel(Actor *);
    extern u8 D_80801034_chnewshovel[];
    extern u8 D_8080104C_chnewshovel[];
    ShovelState *state;
    s32 sp20;

    state = func_80100094(arg0, 0);
    sp20 = 0;
    switch (state->state) {
        case 0:
        case 2:
            break;
        case 1:
            ((ShovelMotion *)arg0->actorData)->unk24 = func_800F3780(func_80101F24(arg0), D_80801034_chnewshovel, 3) * 550.0f;
            sp20 = func_80800A50_chnewshovel(arg0);
            if (func_80101DDC(arg0) && (sp20 & 8)) {
                func_808007F8_chnewshovel(arg0, 2);
            }
            break;
        case 3:
            ((ShovelMotion *)arg0->actorData)->unk24 = func_800F3780(func_80101F24(arg0), D_8080104C_chnewshovel, 3) * 600.0f;
            sp20 = func_80800A50_chnewshovel(arg0);
            if (func_80101DDC(arg0) && (sp20 & 8)) {
                func_808007F8_chnewshovel(arg0, 2);
            }
            break;
    }
    return sp20;
}

s32 func_80800A50_chnewshovel(Actor *arg0) {
    typedef union {
        Actor actor;
        struct {
            u32 header[25];
            BT_BITFIELD_ORDER(u32 pad64_30 : 2, u32 : 29);
            BT_BITFIELD_ORDER(u32 unk64_29 : 1, u32 unk64_29 : 1; u32 pad64_30 : 2);
        } flags;
    } NewShovelActor;
    void *func_80100094(Actor *, u32);
    f32 _subaddiejoy_entrypoint_9(void *, void *, s32);
    void _subaddierouteDll_entrypoint_7(Actor *, void *, f32, f32, f32, s32);
    void func_80102BF8(void *, f32, f32, f32);
    f32 func_80102D78(Actor *, f32 *);
    s32 func_8010B990(Actor *, s32);
    s32 func_8010C3A8(Actor *, u32, f32);
    s32 sp34;
    void *sp30;
    f32 sp2C;
    f32 temp_f0;
    s32 result;
    s32 var_v0;

    sp30 = func_80100094(arg0, 0);
    if (((NewShovelActor *)arg0)->flags.unk64_29) {
        sp2C = _subaddiejoy_entrypoint_9(arg0, &arg0->unk54, 3);
        func_80102BF8(arg0, 0.12f, 5.0f, 180.0f);
        sp34 = func_8010C3A8(arg0, 0x200025, sp2C);
        var_v0 = func_8010B990(arg0, 0x4004);
        sp34 |= var_v0;
    } else {
        temp_f0 = func_80102D78(arg0, (f32 *)arg0->actorData);
        arg0->unk54 = temp_f0;
        _subaddierouteDll_entrypoint_7(arg0, sp30, arg0->rotation[1], temp_f0, 200.0f, 0x5000);
        func_80102BF8(arg0, 0.12f, 5.0f, 180.0f);
        sp34 = func_8010B990(arg0, 0x325);
        var_v0 = func_8010B990(arg0, 0x4004);
        sp34 |= var_v0;
    }
    return sp34;
}

/* extern */

s32 func_80800B5C_chnewshovel(BtIntPtr arg0) {
    f32 func_800EEB40(f32 *, f32 *);
    s32 func_80107B70(BtIntPtr, f32 *);
    f32 sp1C[3];

    if (func_80107B70(arg0, sp1C) != 0) {
        return func_800EEB40((f32 *)(arg0 + 4), sp1C) < 10000.0f;
    }
    return 0;
}

s32 func_80800BC0_chnewshovel(Actor *arg0) {
    typedef union {
        Actor actor;
        struct {
            u32 header[25];
            BT_BITFIELD_ORDER(u32 pad64_30 : 2, u32 : 29);
            BT_BITFIELD_ORDER(u32 unk64_29 : 1, u32 unk64_29 : 1; u32 pad64_30 : 2);
        } flags;
    } NewShovelActor;
    typedef struct {
        u8 pad0[0x10];
        s16 unk10;
    } NewShovelData;
    void *func_80100094(Actor *, u32);
    s32 _subaddiejoy_entrypoint_6(u8 *, s32);
    s32 _subaddiejoy_entrypoint_7(u8 *, s32);
    NewShovelData *sp24;

    sp24 = func_80100094(arg0, 0);
    if (!((NewShovelActor *)arg0)->flags.unk64_29) {
        return 0;
    }
    if ((_subaddiejoy_entrypoint_6((u8 *)arg0, 0) == 1) ||
        (_subaddiejoy_entrypoint_6((u8 *)arg0, 1) == 1) ||
        (_subaddiejoy_entrypoint_7((u8 *)arg0, 0) == 1)) {
        sp24->unk10 = 1;
    }
    return sp24->unk10;
}

/* extern */

int func_80800C58_chnewshovel(Actor *arg0) {
    typedef union {
        Actor actor;
        struct {
            u32 header[25];
            BT_BITFIELD_ORDER(u32 pad64_30 : 2, u32 : 29);
            BT_BITFIELD_ORDER(u32 unk64_29 : 1, u32 unk64_29 : 1; u32 pad64_30 : 2);
        } flags;
    } NewShovelActor;
    f32 func_800EEB40(f32 *, f32 *);
    s32 func_80800BC0_chnewshovel(Actor *);
    NewShovelActor *actor = (NewShovelActor *)arg0;
    f32 *temp_a1;

    temp_a1 = (f32 *)actor->actor.actorData;
    if (actor->flags.unk64_29) {
        return func_80800BC0_chnewshovel(&actor->actor);
    }
    if (func_800EEB40(actor->actor.position, temp_a1) > 40000.0f) {
        return 0;
    }
    return 1;
}

s32 func_80800CC4_chnewshovel(BtIntPtr arg0) {
    s32 func_800DC298(f32);
    extern s32 D_80801064_chnewshovel[4]; BT_NATIVE_ONLY(s32 result;)
    BT_NATIVE_ONLY(result =) func_800C4B7C(func_800DC298(0.5f) ? 0x517 : 0x518);
    _subaddieaudioquick_entrypoint_2((Actor *) arg0, (f32 *) (arg0 + 4), D_80801064_chnewshovel); BT_NATIVE_ONLY(return result;)
}

s32 func_80800D18_chnewshovel(BtIntPtr arg0)
{
  BtIntPtr func_800B53A4(s32);
  void func_800BA22C(BtIntPtr, s32);
  void func_800BAB60(s32, void *);
  BtIntPtr func_800BABB8(BtIntPtr, f32 [3], f32 [3], f32, s32 []);
  void func_800EE7F8(f32 *, f32 *);
  void func_800F2EA0(void *, void *);
  extern s32 D_80801074_chnewshovel[];
  struct 
  {
    f32 *source;
    s32 emitter;
    u8 color[4];
    f32 position[3];
  } particle;
  if (((Actor *) arg0)->unk7C_12)
  {
    func_800F2EA0(particle.color, &((Actor *) arg0)->pad98);
    particle.color[3] = 0xFF;
    particle.source = ((Actor *) arg0)->position;
    func_800EE7F8(particle.position, particle.source);
    particle.position[1] -= 20.0f;
    particle.emitter = func_800B53A4(3);
    func_800BABB8(particle.emitter, particle.source, particle.position, 0.8f, D_80801074_chnewshovel);
    if (particle.source)
    {
    }
    func_800BAB60(particle.emitter, particle.color);
    func_800BA22C(particle.emitter, 3);
  } BT_NATIVE_ONLY(return 0;)
}

s32 func_80800DC8_chnewshovel(BtIntPtr arg0) {
    s32 func_80101074(s32 *);
    extern s32 D_808010B0_chnewshovel[8];
    func_80101074(D_808010B0_chnewshovel);
    return 2;
}
/* data_to_c.py: from asm/data/overlays/ch/newshovel.data.s */
extern u8 D_80800F50_chnewshovel[];
void func_80102EC0();
void func_801018A4();
OSThread *func_80108ED0(void);
void func_80107C2C();
extern u8 D_80800FA0_chnewshovel[];
u8 D_80800F50_chnewshovel[80] BT_DATA(4, overlays_ch_newshovel, 0x0) = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x70, 0xA3, 0xD7, 0x01, 0xB8, 0x00, 0x44, 0x3F, 0x70, 0xA3, 0xD7, 0x01, 0xB8, 0x00, 0x42, 0x3F, 0x19, 0x99, 0x9A, 0x01, 0xB9, 0x00, 0x42, 0x3F, 0x66, 0x66, 0x66, 0x01, 0xBA, 0x00, 0x02, 0x40, 0x40, 0x00, 0x00, 0x01, 0xBB, 0x00, 0x02, 0x3F, 0x19, 0x99, 0x9A, 0x01, 0xB9, 0x00, 0x42, 0x3F, 0x70, 0xA3, 0xD7, 0x01, 0xB8, 0x00, 0x44, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x70, 0xA3, 0xD7, 0x01, 0xB8, 0x00, 0x44 };
u8 D_80800FA0_chnewshovel[20] BT_DATA(4, overlays_ch_newshovel, 0x50) = { 0x00, 0x01, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x09, 0x00, 0x00 };
ActorData D_80800FB4_chnewshovel [1] BT_DATA(4, overlays_ch_newshovel, 0x64) = { { 10, 282, 1647, 1, (void *)D_80800F50_chnewshovel, (void (*)(struct Actor *))func_8080004C_chnewshovel, (void (*)(struct Actor *))func_80102EC0, (void (*)(long, long))func_801018A4, 131072000, 1058642330, 0, 0, 17157, 801, (void (*)(struct Actor *))func_80800310_chnewshovel, (BtIntPtr)func_80108ED0, 20, 0, (void (*)(struct Actor *))func_8080000C_chnewshovel, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32736, 5149, (void (*)(struct Actor *, long, long))func_80800330_chnewshovel, (BtIntPtr)D_80800FA0_chnewshovel } };
u8 D_80800FFC_chnewshovel [12] BT_DATA(4, overlays_ch_newshovel, 0xAC) = { 0, 0x13, 4, 7, 0, 0xD, 0, 0xF3, 1, 0xC, 0, 0 };
s32 D_80801008_chnewshovel[4] BT_DATA(4, overlays_ch_newshovel, 0xB8) = { 1246237, 852300, 23461910, 983040000 };
s32 D_80801018_chnewshovel[3] BT_DATA(4, overlays_ch_newshovel, 0xC8) = { 1041865114, 1053609165, -1082130432 };
s32 D_80801024_chnewshovel[4] BT_DATA(4, overlays_ch_newshovel, 0xD4) = { 1246207, 852147, 13369366, 1048576000 };
u8 D_80801034_chnewshovel [24] BT_DATA(4, overlays_ch_newshovel, 0xE4) = { 0, 0, 0, 0, 0x3E, 0x19, 0x99, 0x9A, 0x3F, 0, 0, 0, 0x3F, 0x80, 0, 0, 0x3F, 0x80, 0, 0, 0x3E, 0x19, 0x99, 0x9A };
u8 D_8080104C_chnewshovel [24] BT_DATA(4, overlays_ch_newshovel, 0xFC) = { 0, 0, 0, 0, 0, 0, 0, 0, 0x3F, 0, 0, 0, 0x3F, 0x80, 0, 0, 0x3F, 0x59, 0x99, 0x9A, 0, 0, 0, 0 };
s32 D_80801064_chnewshovel[4] BT_DATA(4, overlays_ch_newshovel, 0x114) = { 2162701, 15925516, 1459792, 0 };
s32 D_80801074_chnewshovel [15] BT_DATA(4, overlays_ch_newshovel, 0x124) = { 1902244, 1445888, 1834408, -39321561, -39256664, 39322200, 2949270, 13107234, 786457, 0, 2818201, 13369365, 179, 917514, 983040 };
s32 D_808010B0_chnewshovel[8] BT_DATA(4, overlays_ch_newshovel, 0x160) = { 3, 1065353216, 65536, 107, 1068708659, 34734080, 0, 0 };
