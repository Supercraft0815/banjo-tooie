#include "common.h"

OSThread *chswitch_entrypoint_0(void)
{
    extern u8 D_80800DB0_chswitch[];

    return (OSThread *) D_80800DB0_chswitch;
}

OSThread *chswitch_entrypoint_1(void)
{
    extern u8 D_80800DC4_chswitch[];

    return (OSThread *) D_80800DC4_chswitch;
}

OSThread *chswitch_entrypoint_2(void)
{
    extern u8 D_80800DD8_chswitch[];

    return (OSThread *) D_80800DD8_chswitch;
}

/* extern */

void func_80800024_chswitch(Unk80132ED0 *arg0, s32 arg1) {
    s32 func_8008FCC8(Unk80132ED0 *);
    void func_80103110(void *, s32);
    Actor *func_80106790(Unk80132ED0 *);
    Actor *actor;

    actor = func_80106790(arg0);
    if (!(actor->unk58 > 0.0f)) {
        if (func_8008FCC8(arg0) == 2) {
            actor->unk64_20 = (s32)actor->unk64_20 ^ 1;
            actor->unk58 = 2.0f;
            func_80103110(actor, 1);
        }
    }
}

/* extern */

void func_808000B8_chswitch(Unk80132ED0 *arg0, s32 arg1) {
    void func_80103110(void *, s32);
    Actor *func_80106790(Unk80132ED0 *);
    Actor *actor;

    actor = func_80106790(arg0);
    if (!(actor->unk58 > 0.0f)) {
        actor->unk64_20 = (s32)actor->unk64_20 ^ 1;
        actor->unk58 = 2.0f;
        func_80103110(actor, 1);
    }
}

/* extern */

void func_8080012C_chswitch(Unk80132ED0 *arg0, u16 *arg1) {
    int _gcaudiolist_entrypoint_0();
    s32 func_8008FCC8(Unk80132ED0 *);
    s32 func_800F7F98(s32, u32);
    void func_80102424(Actor *, s32);
    Actor *func_80106790(Unk80132ED0 *);
    Actor *actor;

    actor = func_80106790(arg0);
    if ((func_8008FCC8(arg0) == 1) && ((s32)actor->unk70_10 == 1)) {
            _gcaudiolist_entrypoint_0(0);
            func_80102424(actor, 2);
            actor->actorData[4] = (u32)arg1[13] >> 5;
            func_800F7F98(actor->actorData[4], 1);
    }
}

/* extern */

s32 chswitch_entrypoint_3(void *arg0, s32 arg1) {
    s32 func_800DA298(s32);
    s32 func_80102E08(void *);
    void func_80103110(void *, s32);
    s32 sp1C;
    s32 temp_v0;

    temp_v0 = func_800DA298(arg1);
    sp1C = temp_v0;
    (*(s32 *)((s8 *)(arg0) + (0x34))) = arg1;
    func_80103110(arg0, 0);
    (*(f32 *)((s8 *)(arg0) + (0x54))) = 0.75f;
    func_80102E08(arg0);
    return sp1C;
}

void chswitch_entrypoint_4(Actor *arg0) {
    s32 func_800D9078(f32 *);
    s32 func_800DA544(s32);
    s32 func_800F7F98(s32, u32);
    s32 func_8010108C(Actor *, s32, s32);
    s32 func_80101DDC(Actor *);
    void func_80102424(Actor *, s32);
    void func_80103110(void *, s32);

    if (arg0->unk70_10 == 2 && func_80101DDC(arg0) != 0 &&
        !arg0->unk64_20 && func_800D9078(&arg0->unk54) != 0) {
        arg0->unk64_20 = 1;
        func_80102424(arg0, 3);
        func_80103110(arg0, 0);
        func_800F7F98(arg0->actorData[4], 0);
        func_800DA544(arg0->actorData[7]);
        func_8010108C(arg0, 7, 0);
    }
}

/* extern */

void func_808002B4_chswitch(Unk80132ED0 *arg0, u16 *arg1) {
    int _gcaudiolist_entrypoint_0();
    s32 func_8008FCF4(Unk80132ED0 *);
    s32 func_800F7F98(s32, u32);
    void func_80102424(Actor *, s32);
    void func_80103110(void *, s32);
    Actor *func_80106790(Unk80132ED0 *);
    void func_8010A570(Actor *);
    Actor *actor;

    actor = func_80106790(arg0);
    if (func_8008FCF4(arg0) == 1) {
        _gcaudiolist_entrypoint_0(0);
        func_80102424(actor, 2);
        func_8010A570(actor);
        func_80103110(actor, 1);
        actor->actorData[4] = (u32)arg1[13] >> 5;
        func_800F7F98(actor->actorData[4], 1);
    }
}

s32 chswitch_entrypoint_5(Actor *arg0, s32 arg1, u32 arg2) {
    int _gcaudiolist_entrypoint_0();
    s32 func_800DA298(s32);
    s32 func_800F7F98(s32, u32);
    void func_80102424(Actor *, s32);
    void func_80103110(void *, s32);
    void func_8010A570(Actor *);
    s32 func_8080093C_chswitch(Actor *);

    switch (arg1) {
    case 0x29:
        return func_8080093C_chswitch(arg0);
    case 0x91:
        if (arg0->unk70_10 == 1) {
            _gcaudiolist_entrypoint_0(0);
            func_80102424(arg0, 2);
            func_8010A570(arg0);
            func_80103110(arg0, 1);
            arg0->actorData[4] = arg2;
            func_800F7F98(arg2, 1);
            break;
        }
        return 0;
    case 0x95:
        if (func_800DA298(arg0->actorData[7])) {
            func_80102424(arg0, 3);
            arg0->unk64_20 = 1;
            func_8010A570(arg0);
        } else {
            func_80102424(arg0, 1);
        }
        break;
    default:
        return 0;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/swit/chswitch_entrypoint_6.s")

/* extern */

s32 chswitch_entrypoint_7(void *arg0, s32 arg1) {
    s32 func_800DA298(s32);
    void func_80102424(Actor *, s32);
    s32 func_80102E08(void *);
    s32 sp24;
    s32 temp_v0;

    temp_v0 = func_800DA298(arg1);
    sp24 = temp_v0;
    (*(s32 *)((s8 *)(arg0) + (0x34))) = arg1;
    if (temp_v0 != 0) {
        (*(f32 *)((s8 *)(arg0) + (0x54))) = 0.0f;
        func_80102424(arg0, 3);
    } else {
        (*(f32 *)((s8 *)(arg0) + (0x54))) = 0.375f;
        func_80102424(arg0, 1);
    }
    (*(s32 *)((s8 *)(arg0) + (0x2C))) = -1;
    (*(s32 *)((s8 *)(arg0) + (0x50))) = 0;
    (*(s32 *)((s8 *)(arg0) + (0x30))) = 0;
    func_80102E08(arg0);
    return sp24;
}

void chswitch_entrypoint_8(s32 *arg0, s32 arg1) {
    arg0[11] = arg1;
}

void chswitch_entrypoint_9(void *arg0) {
    (*(s32 *)((s8 *)(arg0) + (0x30))) = 1;
}

void func_80800694_chswitch(Actor *arg0) {
    s32 _plsu_entrypoint_0(f32 *, f32 *);
    s32 func_800DA298(s32);
    s32 func_800F5410(s32);
    void func_80102424(Actor *, s32);
    void func_80103110(void *, s32);
    f32 sp2C[3];
    s32 sp28;
    s32 pad[2];

    if (func_800DA298(arg0->actorData[7]) != 0) {
        sp28 = _plsu_entrypoint_0(sp2C, arg0->position);
        func_80103110(arg0, arg0->actorData[6] == 0);
        if (!arg0->unk6C_0) {
            func_80102424(arg0, 3);
            if (arg0->actorData[6] == 0 && sp28 != -1) {
                arg0->unk64_20 = 1;
                *(s32 *)&arg0->unk50 = func_800F5410(sp28);
                arg0->unk6C_0 = 1;
            }
        } else {
            *(s32 *)&arg0->unk50 = func_800F5410(sp28);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/swit/chswitch_entrypoint_10.s")

/* extern */

s32 func_8080093C_chswitch(Actor *arg0) {
    s16 func_800CB854(s32 *);
    s32 func_800DA298(s32);
    void func_80100120(Actor *);
    void func_80102204(Actor *);
    void func_80102424(Actor *, s32);
    s32 sp24;

    if (func_800CB854(&sp24) == 1) {
        func_80100120(arg0);
        if (!arg0->unk64_17 && func_800DA298(arg0->actorData[7]) != 0) {
            func_80102424(arg0, 3);
            func_80102204(arg0);
            arg0->unk64_20 = 1;
            arg0->unk6C_0 = 1;
        }
    }
    return 1;
}

void chswitch_entrypoint_11(Actor *arg0) {
    int _gcaudiolist_entrypoint_0();
    s32 func_800DA298(s32);
    void func_800DA524(s32);
    s32 func_800DA544(s32);
    s32 func_800F7F98(s32, u32);
    s32 func_8010108C(Actor *, s32, s32);
    s32 func_80101DDC(Actor *);
    void func_80102424(Actor *, s32);

    switch (arg0->unk70_10) {
        case 1:
            break;
        case 2:
            if (func_80101DDC(arg0)) {
                func_800DA544(arg0->actorData[7]);
                func_80102424(arg0, 3);
                func_800F7F98(arg0->actorData[4], 0);
                func_8010108C(arg0, 7, 0);
            }
            break;
        case 3:
            if (func_800DA298(arg0->actorData[5])) {
                func_800DA524(arg0->actorData[5]);
                _gcaudiolist_entrypoint_0(0);
                func_80102424(arg0, 4);
            }
            break;
        case 4:
            if (func_80101DDC(arg0)) {
                func_800DA524(arg0->actorData[7]);
                func_80102424(arg0, 1);
                func_8010108C(arg0, 8, 0);
            }
            break;
    }
}

/* extern */

void chswitch_entrypoint_12(Actor *arg0, s32 arg1, s32 arg2) {
    s32 func_800DA298(s32);
    void func_800DA524(s32);
    void func_80102424(Actor *, s32);
    s32 func_80102E08(void *);
    s32 var_v1;
    s32 var_a1;

    var_v1 = func_800DA298(arg1);
    arg0->actorData[7] = arg1;
    arg0->actorData[5] = arg2;
    if (arg2 != -1) {
        func_800DA524(arg2);
    }
    var_a1 = var_v1 ? 3 : 1;
    func_80102424(arg0, var_a1);
    func_80102E08(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/swit/chswitch_entrypoint_13.s")

/* extern */

s32 chswitch_entrypoint_14(Actor *arg0, s32 arg1) {
    s32 func_800DA298(s32);
    void func_80101EE4(Actor *, f32);
    void func_80102424(Actor *, s32);
    void func_80103110(void *, s32);
    s32 sp24;
    s32 temp_v0;

    temp_v0 = func_800DA298(arg1);
    sp24 = temp_v0;
    arg0->actorData[7] = arg1;
    if (temp_v0 != 0) {
        func_80102424(arg0, 3);
        func_80101EE4(arg0, 0.5f);
    } else {
        func_80102424(arg0, 1);
    }
    arg0->unk64_20 = sp24;
    func_80103110(arg0, 0);
    return sp24;
}
