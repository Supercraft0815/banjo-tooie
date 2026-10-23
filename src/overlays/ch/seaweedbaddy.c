#include "common.h"

OSThread *chseaweedbaddy_entrypoint_0(void)
{
    extern u8 D_80800EB4_chseaweedbaddy[];

    return (OSThread *) D_80800EB4_chseaweedbaddy;
}

OSThread *chseaweedbaddy_entrypoint_1(void)
{
    extern u8 D_80800EFC_chseaweedbaddy[];

    return (OSThread *) D_80800EFC_chseaweedbaddy;
}

void func_80800018_chseaweedbaddy(Actor *arg0) {
    s32 _subaddieaudioquick_entrypoint_3(Actor *, f32 *, u32 *, f32);
    f32 _subaddiejoy_entrypoint_9(void *, void *, s32);
    s32 _subaddierouteDll_entrypoint_4(Actor *);
    s32 _subaddierouteDll_entrypoint_7(Actor *, void *, f32, f32, f32, s32);
    f32 func_800136E4(f32);
    f32 func_800D8FF8(void);
    s32 func_800D9078(f32 *);
    f32 func_800EEB40(f32 *, f32 *);
    void func_800EEB9C(f32 *, f32, f32);
    f32 func_800F15F8(f32, f32, f32);
    f32 func_800F1FF0(f32, f32, f32, f32, f32);
    void *func_80100094(Actor *, u32);
    s32 func_80101DDC(Actor *);
    f32 func_80102D78(Actor *, f32 *);
    s32 func_8010B990(Actor *, s32);
    void func_8010D254(f32 *);
    void func_80800710_chseaweedbaddy(u8 *, s32);
    s32 func_8080082C_chseaweedbaddy(Actor *);
    s32 func_80800910_chseaweedbaddy(Actor *);
    void func_80800CE0_chseaweedbaddy(Actor *, f32);
    extern u32 D_80800F44_chseaweedbaddy[];
    extern u32 D_80800F50_chseaweedbaddy[];
    struct SeaweedRoute {
        u16 unk0;
        u16 unk2;
        u16 unk4;
        u16 index;
        u32 unk8;
    };
    struct SeaweedData {
        f32 position[3];
        f32 angle;
        s32 index;
        struct SeaweedRoute route;
    };
    union SeaweedActor {
        Actor actor;
        struct {
            u32 reserved[30];
            u32 : 29;
            u32 inactive : 1;
            u32 : 2;
        } flags;
    };
    f32 delta;
    f32 speed;
    struct SeaweedData *data;
    f32 distance;
    f32 *position;
    struct SeaweedRoute *route;
    f32 oldYaw;

    speed = 0.0f;
    data = func_80100094(arg0, 1);
    if (!((union SeaweedActor *)arg0)->flags.inactive) {
        delta = func_800D8FF8();
        func_800D9078(&arg0->unk58);
        switch (arg0->unk70_10) {
        case 1:
            if (func_8080082C_chseaweedbaddy(arg0)) {
                func_80800710_chseaweedbaddy((u8 *)arg0, 2);
            }
            break;
        case 2:
            speed = 700.0f;
            _subaddieaudioquick_entrypoint_3(arg0, arg0->position, D_80800F44_chseaweedbaddy, 0.2f);
            if (func_80101DDC(arg0)) {
                func_80800710_chseaweedbaddy((u8 *)arg0, 3);
            }
            break;
        case 3:
            position = (f32 *)arg0->actorData;
            speed = 700.0f;
            func_8010D254(position);
            if (arg0->unk64_29) {
                distance = _subaddiejoy_entrypoint_9(arg0, &arg0->unk54, 3) * 350.0f;
                data->angle = arg0->unk54;
                func_800EEB9C((f32 *)&arg0->actorData[4], data->angle, distance);
                func_8010B990(arg0, 0x205027);
            } else {
                if (_subaddierouteDll_entrypoint_4(arg0)) {
                    arg0->unk54 = func_80102D78(arg0, position);
                    route = &data->route;
                    _subaddierouteDll_entrypoint_7(arg0, route, data->angle, arg0->unk54, 100.0f, 0x5000);
                    data->index = route->index;
                }
                data->angle = func_800F1FF0(data->angle, arg0->unk54, 0.2f, 2.0f, func_800D8FF8() * 450.0f);
                func_800EEB9C((f32 *)&arg0->actorData[4], data->angle, 350.0f);
                func_8010B990(arg0, 0x5307);
            }
            if (func_80800910_chseaweedbaddy(arg0)) {
                func_80800710_chseaweedbaddy((u8 *)arg0, 6);
            }
            break;
        case 4:
            if (func_80101DDC(arg0)) {
                func_80800710_chseaweedbaddy((u8 *)arg0, 5);
            }
            break;
        case 5:
            _subaddieaudioquick_entrypoint_3(arg0, arg0->position, D_80800F50_chseaweedbaddy, 0.2f);
            if (func_80101DDC(arg0)) {
                func_80800710_chseaweedbaddy((u8 *)arg0, 6);
            }
            break;
        case 6:
            speed = 300.0f;
            if (_subaddierouteDll_entrypoint_4(arg0)) {
                arg0->unk54 = func_80102D78(arg0, (f32 *)arg0->actorData);
                route = &data->route;
                _subaddierouteDll_entrypoint_7(arg0, route, data->angle, arg0->unk54, 100.0f, 0x5000);
                data->index = route->index;
            }
            position = (f32 *)arg0->actorData;
            data->angle = func_800F1FF0(data->angle, arg0->unk54, 0.2f, 2.0f, func_800D8FF8() * 450.0f);
            func_800EEB9C((f32 *)&arg0->actorData[4], data->angle, 350.0f);
            func_8010B990(arg0, 0x5307);
            if (func_800EEB40(arg0->position, position) < 6400.0f) {
                func_80800710_chseaweedbaddy((u8 *)arg0, 7);
            } else if (func_8080082C_chseaweedbaddy(arg0)) {
                func_80800710_chseaweedbaddy((u8 *)arg0, 3);
            }
            break;
        case 7:
            if (func_80101DDC(arg0)) {
                func_80800710_chseaweedbaddy((u8 *)arg0, 1);
            }
            break;
        }
        oldYaw = arg0->rotation[1];
        arg0->unk50 = func_800F15F8(arg0->unk50, speed, delta * 800.0f);
        arg0->rotation[1] = func_800136E4(arg0->rotation[1] + arg0->unk50 * delta);
        func_80800CE0_chseaweedbaddy(arg0, oldYaw);
    }
}

void func_8080043C_chseaweedbaddy(Actor *arg0) {
    void _sudeflect_entrypoint_1(f32 *, f32, f32, f32, s32);
    _sudeflect_entrypoint_1(arg0->position, arg0->scale * 120.0f, arg0->scale * 100.0f, 0.0f, 0xA);
}

void func_80800498_chseaweedbaddy(Actor *arg0) {
    s32 _subaddieDll_entrypoint_1(Actor *);
    void _subaddierouteDll_entrypoint_3(Actor *, void *, f32 *);
    f32 func_800DC0C0(void);
    int func_800DC298(f32);
    void func_800EE7F8(f32 *, f32 *);
    void *func_80100094(Actor *, u32);
    void func_80101EE4(Actor *, f32);
    void func_80102FDC(Actor *, f32);
    void func_80107200(void *);
    void func_808009BC_chseaweedbaddy(Actor *);
    struct SeaweedData {
        f32 position[3];
        s32 unkC;
        s32 unk10;
        f32 route[3];
    } *sp2C;

    if (func_800DC298(0.4f)) {
        func_808009BC_chseaweedbaddy(arg0);
    }
    _subaddieDll_entrypoint_1(arg0);
    func_80107200(arg0);
    sp2C = func_80100094(arg0, 1);
    _subaddierouteDll_entrypoint_3(arg0, sp2C->route, arg0->position);
    sp2C->unk10 = 0;
    func_800EE7F8(sp2C->position, arg0->position);
    func_80102FDC(arg0, arg0->scale * 0.7f);
    arg0->unk50 = 0.0f;
    func_80101EE4(arg0, func_800DC0C0());
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/seaweedbaddy/func_80800554_chseaweedbaddy.s")

void func_8080065C_chseaweedbaddy(Actor *arg0) {
    f32 func_800DC0C0(void);
    void func_80101EE4(Actor *, f32);
    void func_80102FDC(Actor*, f32);
    func_80102FDC(arg0, arg0->scale * 0.7f);
    func_80101EE4(arg0, func_800DC0C0());
}

/* extern */

void func_808006A8_chseaweedbaddy(s32 arg0, s32 arg1) {
    s32 func_800DF744(s32, s32);
    s32 func_80101870(s32, s32);
    func_800DF744(1, 0);
    func_800DF744(2, 0);
    func_800DF744(3, 1);
    func_800DF744(4, 0);
    func_800DF744(5, 1);
    func_80101870(arg0, arg1);
}

void func_80800710_chseaweedbaddy(u8 *arg0, s32 arg1) {
    s32 _subaddieDll_entrypoint_4(void *, s32);
    void func_800EE7F8(f32 *, f32 *);
    void *func_80100094(Actor *, u32);
    void func_80102424(Actor *, s32);
    f32 func_8010CD28(Actor *);
    void func_8010D254(f32 *);
    f32 *data;
    Actor *actor = (Actor *)arg0;

    data = func_80100094(actor, 1);
    switch (arg1) {
    case 1:
        _subaddieDll_entrypoint_4(actor, 0);
        break;
    case 2:
        _subaddieDll_entrypoint_4(actor, 1);
        break;
    case 3:
        func_8010D254((f32 *)actor->actorData);
        data[3] = func_8010CD28(actor);
        break;
    case 6:
        func_800EE7F8((f32 *)actor->actorData, data);
        actor->unk58 = 1.4f;
        break;
    case 7:
        actor->unk58 = 1.4f;
        break;
    }
    func_80102424(actor, arg1);
}

/* extern */

void func_808007E4_chseaweedbaddy(u8 *arg0, s32 arg1) {
    struct Flags {
        unsigned int : 29;
        unsigned int active : 1;
        unsigned int : 2;
    };
    void func_80800710_chseaweedbaddy(u8 *, s32);
    if (!((struct Flags *)(arg0 + 0x78))->active &&
        (((u32)*(u16 *)(arg0 + 0x72) >> 10) != 4)) {
        func_80800710_chseaweedbaddy(arg0, 4);
    }
}

s32 func_8080082C_chseaweedbaddy(Actor *arg0) {
    s32 _subaddierouteDll_entrypoint_4(Actor *);
    Unk80132ED0 *_suchase_entrypoint_0(void);
    s32 func_801072A8(void *);
    s32 func_8010C668(Actor *, f32 *, f32, f32);
    s32 func_8010C9FC(f32 *, s32, s32, s32);
    union FlowerBaddieActor {
        Actor actor;
        struct {
            u32 reserved[25];
            u32 : 2;
            u32 blocked : 1;
            u32 : 29;
        } flags;
    };

    if (arg0->unk58 > 0.0f) {
        return 0;
    }
    if (((union FlowerBaddieActor *)arg0)->flags.blocked) {
        return 1;
    }
    if (func_801072A8(arg0) != 0) {
        return 0;
    }
    if (_subaddierouteDll_entrypoint_4(arg0) == 0) {
        return 0;
    }
    if (func_8010C9FC(arg0->position, 0x3E8, 0x1F4, -0x32) == 0) {
        return 0;
    }
    if (func_8010C668(arg0, arg0->position, 1000.0f, -200.0f) == 0) {
        return 0;
    }
    return _suchase_entrypoint_0() == arg0->unk0;
}

/* extern */

s32 func_80800910_chseaweedbaddy(Actor *arg0) {
    s32 _subaddierouteDll_entrypoint_4(Actor *);
    Unk80132ED0 *_suchase_entrypoint_0(void);
    s32 func_8010C668(Actor *, f32 *, f32, f32);
    s32 func_8010C9FC(f32 *, s32, s32, s32);
    union FlowerBaddieActor {
        Actor actor;
        struct {
            u32 reserved[25];
            u32 : 2;
            u32 blocked : 1;
            u32 : 29;
        } flags;
    };

    if (((union FlowerBaddieActor *)arg0)->flags.blocked) {
        return 0;
    }
    if (_subaddierouteDll_entrypoint_4(arg0) == 0) {
        return 0;
    }
    if (func_8010C9FC(arg0->position, 0x3E8, 0x1F4, -0x32) == 0) {
        return 1;
    }
    if (func_8010C668(arg0, arg0->position, 1000.0f, -200.0f) == 0) {
        return 1;
    }
    return _suchase_entrypoint_0() != arg0->unk0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/seaweedbaddy/func_808009BC_chseaweedbaddy.s")

void func_80800BCC_chseaweedbaddy(Actor *arg0) {
    void _chexploder_entrypoint_10(Actor *, s32 *);
    s32 _chexploder_entrypoint_14(Actor *, s32);
    s32 _chexploder_entrypoint_6(Actor *, f32, f32);
    s32 _chexploder_entrypoint_9(Actor *, s32, s32);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    s32 func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    void func_800FFAB0(Actor *);
    void *func_80101080(void);
    void func_80103DFC(Actor *, f32 *);
    Actor *func_80106790(Unk80132ED0 *);
    s32 func_80107070(Actor *, s32);
    extern s32 D_80800F5C_chseaweedbaddy;
    extern s32 D_80800F90_chseaweedbaddy;
    extern s32 D_80800F9C_chseaweedbaddy;
    f32 sp30[4];
    Actor *temp_v0;

    temp_v0 = func_80106790(func_80101080());
    _chexploder_entrypoint_9(temp_v0, 1, 0);
    _chexploder_entrypoint_9(temp_v0, 2, 0);
    _chexploder_entrypoint_9(temp_v0, 3, 0);
    _chexploder_entrypoint_9(temp_v0, 4, 1);
    _chexploder_entrypoint_9(temp_v0, 5, 0);
    _chexploder_entrypoint_10(temp_v0, &D_80800F9C_chseaweedbaddy);
    _chexploder_entrypoint_6(temp_v0, 500.0f, 600.0f);
    _chexploder_entrypoint_14(temp_v0, 3);
    func_80103DFC(arg0, sp30);
    func_800BBCB8(sp30, sp30, arg0->scale, 4, &D_80800F5C_chseaweedbaddy);
    _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_80800F90_chseaweedbaddy);
    if (func_80107070(arg0, 3) == 0) {
        func_800FFAB0(arg0);
    }
}

void func_80800CE0_chseaweedbaddy(Actor *arg0, f32 arg1) {
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    f32 func_80013728(f32);
    void func_800C4B64(f32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    extern f32 D_80800FAC_chseaweedbaddy[2];
    extern f32 D_80800FB4_chseaweedbaddy;
    f32 distance;
    s32 found;
    f32 *angle;
    f32 *end;

    found = 0;
    for (angle = D_80800FAC_chseaweedbaddy, end = angle + 2; angle != end; angle++) {
        if (func_80013728(arg1) <= *angle && *angle < func_80013728(arg0->rotation[1])) {
            found = 1;
            break;
        }
    }
    if (found) {
        distance = arg0->unk50;
        if (distance > 100.0f) {
            func_800C4B64(func_800F10B4(distance, 100.0f, 700.0f, 1.0f, 1.15f));
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_80800FB4_chseaweedbaddy);
        }
    }
}
