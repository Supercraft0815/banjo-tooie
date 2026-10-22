#include "common.h"

OSThread *chnewshovel_entrypoint_0(void)
{
    extern u8 D_80800FB4_chnewshovel[];

    return (OSThread *) D_80800FB4_chnewshovel;
}

/* extern */

void func_8080000C_chnewshovel(Actor *arg0) {
    void _subaddierouteDll_entrypoint_3(Actor*, void*, f32*);
    void* func_80100094(Actor*, u32);
    s32 func_808007F8_chnewshovel(Actor *, s32);
    _subaddierouteDll_entrypoint_3(arg0, func_80100094(arg0, 0U), arg0->position);
    func_808007F8_chnewshovel(arg0, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/newshovel/func_8080004C_chnewshovel.s")

void func_80800310_chnewshovel(Actor* arg0) 
{
    _suexpression_entrypoint_8(arg0, 1);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/newshovel/func_80800330_chnewshovel.s")

void func_80800570_chnewshovel(s32 arg0) {
    s32 _subaddieaudioquick_entrypoint_3(s32, s32, s32 *, s32);
    s32 _subaddieaudioquick_entrypoint_4(s32, s32, s32 *, s32 *);
    s32 func_80101E14(s32, s32);
    s32 func_801022E4();
    s32 func_80800CC4_chnewshovel(s32);
    s32 func_80800D18_chnewshovel(s32);
    extern s32 D_80801008_chnewshovel;
    extern s32 D_80801018_chnewshovel;
    extern s32 D_80801024_chnewshovel;
    s32 temp_v0;

    temp_v0 = func_801022E4();
    if (temp_v0 != 0x1BA) {
        if (temp_v0 == 0x1BB) {
            _subaddieaudioquick_entrypoint_4(arg0, arg0 + 4, &D_80801008_chnewshovel, &D_80801018_chnewshovel);
            if (func_80101E14(arg0, 0x3F333333) != 0) {
                func_80800CC4_chnewshovel(arg0);
                func_80800D18_chnewshovel(arg0);
            }
        }
    } else {
        _subaddieaudioquick_entrypoint_3(arg0, arg0 + 4, &D_80801024_chnewshovel, 0x3ECCCCCD);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/newshovel/func_80800610_chnewshovel.s")

s32 func_808006B0_chnewshovel(Actor *arg0, s32 arg1) {
    typedef struct {
        s16 unk0[8];
        s16 timer;
    } ShovelState;
    void *func_80100094(Actor *, u32);
    void func_80102424(Actor *, s32);
    void func_800F5A00(s32, f32 *);
    s32 func_80107B70(s32, f32 *);
    s32 func_8010D290(s32);
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
        func_80107B70((s32)arg0, (f32 *)arg0->actorData);
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
    s32 func_80800D18_chnewshovel(s32);
    s32 func_80800CC4_chnewshovel(s32);
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
            func_80800D18_chnewshovel((s32)arg0);
            func_80800CC4_chnewshovel((s32)arg0);
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
            u32 pad64_30 : 2;
            u32 unk64_29 : 1;
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

s32 func_80800B5C_chnewshovel(s32 arg0) {
    f32 func_800EEB40(f32 *, f32 *);
    s32 func_80107B70(s32, f32 *);
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
            u32 pad64_30 : 2;
            u32 unk64_29 : 1;
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
            u32 pad64_30 : 2;
            u32 unk64_29 : 1;
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

s32 func_80800CC4_chnewshovel(s32 arg0) {
    s32 func_800DC298(f32);
    extern s32 D_80801064_chnewshovel;
    func_800C4B7C(func_800DC298(0.5f) ? 0x517 : 0x518);
    _subaddieaudioquick_entrypoint_2((Actor *) arg0, (f32 *) (arg0 + 4), &D_80801064_chnewshovel);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/newshovel/func_80800D18_chnewshovel.s")

s32 func_80800DC8_chnewshovel(s32 arg0) {
    s32 func_80101074(s32 *);
    extern s32 D_808010B0_chnewshovel;
    func_80101074(&D_808010B0_chnewshovel);
    return 2;
}
