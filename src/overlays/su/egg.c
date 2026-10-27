#include "common.h"
#include "gameflags.h"

void *func_80100094(Actor *, u32);

OSThread *suegg_entrypoint_0(void)
{
    extern u8 D_80800E40_suegg[];

    return (OSThread *) D_80800E40_suegg;
}

void func_8080000C_suegg(Actor *arg0) {
    s32 func_800AF5A0(s16 *);
    s32 func_800EC3E8(u8 *);
    void *sp1C;

    sp1C = func_80100094(arg0, 0);
    *(f32 *)((s8 *)sp1C + 4) = 0.0f;
    *(s32 *)((s8 *)sp1C + 8) = func_800AF5A0((s16 *)func_800EC3E8((u8 *)arg0->unk0));
    *(f32 *)((s8 *)sp1C + 0) = 1.0f;
}

/* extern */

void func_80800064_suegg(Actor *arg0) {
    f32 func_800D8FF8(void);
    f32 func_800F13C4(f32, f32);
    struct {
        f32 speed;
        f32 frame;
        s32 frameCount;
    } *sp1C;
    f32 temp_f0;
    struct {
        u8 unk0[10];
        u8 frame : 5;
        u8 unkA_5 : 3;
    } *temp_v0;

    sp1C = func_80100094(arg0, 0U);
    temp_f0 = func_800D8FF8();
    temp_f0 *= sp1C->speed;
    temp_f0 += sp1C->frame;
    temp_f0 = func_800F13C4(temp_f0, (f32) sp1C->frameCount);
    sp1C->frame = temp_f0;
    temp_v0 = (void *)arg0->unk0->unk0;
    temp_v0->frame = (s32) temp_f0 % sp1C->frameCount;
}

void suegg_entrypoint_1(Actor *arg0, f32 arg1) { *(f32 *)func_80100094(arg0, 0) = arg1; }

void suegg_entrypoint_2(Actor *arg0) {
    s32 _chlightfader_entrypoint_1(s32, f32, s32);
    void func_800C8B84(volatile s32);
    void func_800C8CB8(s32, f32 *);
    void suegg_entrypoint_15(s32);
    struct {
        u32 pad[14];
        u32 unk38_0 : 10;
        u32 unk38_10 : 1;
        u32 unk38_11 : 21;
        s32 unk3C;
    } *data;

    data = func_80100094(arg0, 0);
    if (data->unk3C != 0) {
        if (data->unk38_10) {
            func_800C8B84(data->unk3C);
        } else {
            func_800C8CB8(data->unk3C, arg0->position);
            data->unk3C = _chlightfader_entrypoint_1(data->unk3C, 1.0f, 2);
        }
        data->unk3C = 0;
    }
    suegg_entrypoint_15((s32)arg0);
}

void suegg_entrypoint_4(Actor *, s32);

void suegg_entrypoint_3(Actor *arg0)
{
    suegg_entrypoint_4(arg0,1);
}

void suegg_entrypoint_4(Actor *arg0, s32 arg1) {
    s32 _fxegg_entrypoint_0(u32, f32 *, f32);
    s32 _gcegg_entrypoint_1(u32);
    void func_800FFAB0(Actor *);
    s32 func_8010D930(s32, s32, f32 *, s32 *);
    extern s32 D_80800E54_suegg;
    f32 *position[3];
    s32 flag;
    struct {
        u32 pad[14];
        u32 pad38 : 8;
        u32 flag23 : 1;
        u32 flag22 : 1;
        u32 rest38 : 22;
    } *data;

    data = func_80100094(arg0, 0);
    if (!arg0->unk64_17) {
        if (!data->flag22) {
            data->flag23 = 0;
            flag = *(u32 *)((u8 *)arg0 + 0x70);
            func_8010D930(0, (u8)(flag & 1), position[0] = arg0->position, &D_80800E54_suegg);
            if (arg1 != 0) {
                _fxegg_entrypoint_0(_gcegg_entrypoint_1(arg0->unk6C_9), position[0], arg0->scale);
            }
        }
        func_800FFAB0(arg0);
    }
}

/* extern */

void suegg_entrypoint_5(Actor *arg0) {
    s32 func_80800DC0_suegg(Actor *, s32);
    Unk80132ED0 *temp_v0;

    if (func_80800DC0_suegg(arg0, (*(s16 *)((s8 *)(func_80100094(arg0, 0U)) + (0x3A)))) == 0) {
        temp_v0 = arg0->unk0;
        (*(u8 *)((s8 *)(temp_v0) + (0x2A))) = (u8) (((*(u8 *)((s8 *)(temp_v0) + (0x2A))) & ~4) | 4);
    }
}

s16 suegg_entrypoint_6(Unk80132ED0 *arg0, f32 *arg1, s32 *arg2) {
    s32 _gcegg_entrypoint_0(u32);
    Actor *func_80106790(Unk80132ED0 *);
    void func_800EFB24(void *, void *, void *);
    Actor *sp1C;
    void *sp18;

    sp1C = func_80106790(arg0);
    sp18 = func_80100094(sp1C, 0);
    func_800EFB24(arg1, sp1C->position, sp1C->actorData);
    *arg2 = _gcegg_entrypoint_0(arg0->unk24 >> 22);
    return *(s16 *)((u8 *)sp18 + 0x3A);
}

/* extern */

s16 suegg_entrypoint_7(void) {
    Actor *func_80106790();
    return (*(s16 *)((s8 *)(func_80100094(func_80106790(), 0)) + (0x3A)));
}

s32 func_80800390_suegg(Actor *arg0) {
    struct player_state_s;
    void _bsfirstp_entrypoint_7(struct player_state_s *, f32 *, f32 *);
    s32 func_800EA068(s32);
    void func_800EE7F8(f32 *, f32 *);
    f32 func_800EEB40(f32 *, f32 *);
    s32 func_800F0734(f32 *, f32 *, f32 *, f32, f32, f32 *, f32 *);
    struct player_state_s *func_800F53D0(s32);
    void func_800F551C(s32, f32 *, f32 *, f32 *);
    s32 func_800F5898(void);
    void func_800F5A00(s32, f32 *);
    s32 func_800F6438(u32);
    void suegg_entrypoint_18(s32, s32);
    struct EggData {
        u8 pad[0x3A];
        s16 player;
    } *data;
    s32 firstPerson;
    s32 i;
    s32 best;
    f32 origin[3];
    f32 position[3];
    f32 hit[3];
    f32 distance;
    f32 height;
    f32 bestDistance;
    f32 target[3];
    f32 radius;
    f32 range;

    data = func_80100094(arg0, 0);
    best = -1;
    if (func_800EA068(0x4000)) {
        suegg_entrypoint_18((s32)arg0, (s32)origin);
        func_800EE7F8(position, arg0->position);
        bestDistance = 0.0f;
        firstPerson = func_800EA068(8);
        for (i = 0; i < func_800F5898(); i++) {
            if (func_800F6438(i) && i != data->player) {
                func_800F5A00(i, target);
                distance = func_800EEB40(target, origin);
                if (best < 0 || distance < bestDistance) {
                    if (firstPerson) {
                        _bsfirstp_entrypoint_7(func_800F53D0(i), &radius, &range);
                    } else {
                        func_800F551C(i, &radius, &height, &range);
                    }
                    if (func_800F0734(origin, position, target, radius, range, hit, hit)) {
                        best = i;
                        bestDistance = distance;
                    }
                }
            }
        }
    }
    return best;
}

void suegg_entrypoint_8(s32 arg0)
{
    suegg_entrypoint_9(arg0,1);
}

int suegg_entrypoint_9(Actor *arg0, s32 arg1) {
    struct Flags {
        u8 pad[0x39];
        u8 active : 1;
        u8 rest : 7;
    };
    void _glhittableDll_entrypoint_1(Unk80132ED0 *, void *);
    void func_800CB840(s32, s32);
    void func_800CB870(void);
    u8 *func_800CD820(u8 *, f32 *, f32 *, f32);
    f32 func_800EEB40(f32 *, f32 *);
    void func_800F5A00(s32, f32 *);
    void func_800F7BC8(s32, s32, Unk80132ED0 *);
    Actor *func_80106790(Unk80132ED0 *);
    void func_8010A570(Actor *);
    void func_8010A590(Actor *);
    void suegg_entrypoint_18(s32, s32);
    struct Flags *sp4C;
    void *sp48;
    Unk80132ED0 *sp44;
    f32 sp38[3];
    s32 sp34;
    Actor *hitActor;
    f32 sp2C;
    f32 sp20[3];

    sp4C = func_80100094(arg0, 0);
    sp44 = arg0->unk0;
    sp34 = func_80800390_suegg(arg0);
    func_800CB840(3, (s32)arg0);
    *(s16 *)&sp44->unk20 = 0;
    suegg_entrypoint_18((s32)arg0, (s32)sp38);
    func_8010A590(arg0);
    sp48 = func_800CD820((u8 *)sp44, sp38, arg0->position, 38.0f);
    if (sp48 != NULL && sp34 >= 0) {
        hitActor = func_80106790(sp48);
        sp2C = func_800EEB40(sp38, hitActor->position);
        func_800F5A00(sp34, sp20);
        if (func_800EEB40(sp38, sp20) < sp2C) {
            sp48 = NULL;
        } else {
            sp34 = -1;
        }
    }
    if (sp48 != NULL) {
        if (arg1 != 0) {
            _glhittableDll_entrypoint_1(sp44, sp48);
        } else {
            sp4C->active = 1;
        }
    }
    if (sp34 >= 0) {
        func_800F7BC8(sp34, 0x47, sp44);
        sp4C->active = 1;
    }
    func_800CB870();
    func_8010A570(arg0);
    return sp4C->active;
}

/* extern */

void suegg_entrypoint_10(Unk80132ED0 *arg0, s32 arg1, s32 arg2) {
    struct Flags {
        u8 pad[0x39];
        u8 active : 1;
        u8 rest : 7;
    };
    s32 _glhittableDll_entrypoint_6(s32);
    s32 _glhittableDll_entrypoint_9(s32);
    Actor *func_80106790(Unk80132ED0 *);
    struct Flags *temp_v0;

    if ((_glhittableDll_entrypoint_6(arg2) != 0) && (_glhittableDll_entrypoint_9(arg2) != 0)) {
        temp_v0 = func_80100094(func_80106790(arg0), 0);
        temp_v0->active = 1;
    }
}

Actor *suegg_entrypoint_11(u32 arg0, f32 *arg1, s32 arg2) {
    void _sueggmove_entrypoint_4(Actor *);
    void _sumissilehome_entrypoint_0(s32, u8 *);
    void _sumissilehome_entrypoint_1(s32, void *, s32);
    void _sumissilehome_entrypoint_2(s32, void *, f32);
    void _sumissilehome_entrypoint_3(s32, s8 *, s32);
    s32 func_800D3E40(s32);
    s32 func_800DA298(GameFlag);
    s32 func_800F690C(s32);
    s32 func_800F693C(s32);
    Actor *func_80108474(u32, f32 *, s32);
    void func_8010A570(Actor *);
    Actor *actor;
    struct {
        u8 pad0[0x14];
        u8 homing[0x14];
        f32 unk28;
        f32 unk2C;
        f32 unk30;
        s32 unk34;
        s8 unk38;
        u8 unk39;
        s16 unk3A;
    } *data;
    void *homing;

    actor = func_80108474(arg0, arg1, 0);
    data = func_80100094(actor, 0U);
    func_8080000C_suegg(actor);
    data->unk3A = arg2;
    data->unk34 = 0;
    data->unk38 = 1;
    if (1) {} /* Preserve IDO register allocation. */
    if (1) {}
    data->unk28 = 0.0f;
    data->unk30 = 0.0f;
    if (func_800D3E40(0xC) && (!func_800DA298(0xA31))) {
        homing = data->homing;
        _sumissilehome_entrypoint_0((s32)actor, homing);
        _sumissilehome_entrypoint_3((s32)actor, homing, data->unk3A);
        _sumissilehome_entrypoint_1((s32)actor, homing, -1);
        _sumissilehome_entrypoint_2((s32)actor, homing, 6000.0f);
        data->unk38 = 2;
    }
    _sueggmove_entrypoint_4(actor);
    func_8010A570(actor);
    if (func_800F693C(arg2) != 0) {
        *((u8 *) (((u8 *) actor) + 0x75)) &= ~0x10;
    } else if (func_800F690C(arg2)) {
        *((u8 *) (((u8 *) actor) + 0x75)) &= ~0x10;
    }
    return actor;
}

int suegg_entrypoint_12(Actor *arg0) {
    s32 func_800D3948(void);
    void func_800EFB24(void *, void *, void *);
    void func_8010D254(f32 *);
    void *data;
    f32 position[3];
    f32 delta[3];

    data = func_80100094(arg0, 0U);
    if (func_800D3948() != 0) {
        return 0;
    }
    if (*(f32 *)((u8 *)data + 0x30) < 0.6f) {
        return 0;
    }
    func_8010D254(position);
    func_800EFB24(delta, position, arg0->position);
    return position[1] < arg0->position[1] &&
        arg0->position[1] < position[1] + 100.0f &&
        delta[0] * delta[0] + delta[2] * delta[2] < 4900.0f;
}

/* extern */
int suegg_entrypoint_13(Actor *arg0) {
    s32 _sueggmove_entrypoint_3(void *);
    void *data;

    data = func_80100094(arg0, 0U);
    return (*(f32 *)((u8 *)data + 0x30) > 2.8f) &&
        (_sueggmove_entrypoint_3(arg0) || *(f32 *)((u8 *)data + 0x30) > 3.5f);
}

/* extern */

int suegg_entrypoint_14(Actor *arg0) {
    s32 func_800A940C(s32);
    f32 func_800C5190(s32);
    s32 func_800DA298(GameFlag);
    void *sp1C;
    f32 temp_f0;
    f32 var_f2;
    void *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    sp1C = temp_v0;
    temp_f0 = func_800C5190(func_800A940C((*(s16 *)((s8 *)(temp_v0) + (0x3A)))));
    var_f2 = temp_f0;
    if (temp_f0 > 2.0f) {
        var_f2 = 2.0f;
    }
    return (2.0f * var_f2) < (*(f32 *)((s8 *)(sp1C) + (0x30))) ||
        func_800DA298(0x662) == 0;
}

void suegg_entrypoint_15(s32 arg0) 
{
}
void suegg_entrypoint_16(Actor *arg0) {
    void _sueggmove_entrypoint_9(Actor *);
    void _sumissilehome_entrypoint_5(Actor *, void *, f32, f32);
    void _sumissilehome_entrypoint_6(Actor *, void *);
    void suegg_entrypoint_22(Actor *);
    f32 func_800D8FF8(void);
    u8 *data;
    u8 state;

    data = func_80100094(arg0, 0);
    state = data[0x38];
    if (state != 1) {
        if (state == 2) {
            data[0x38] = 3;
            _sumissilehome_entrypoint_5(arg0, data + 0x14, 4500.0f, 1400.0f);
        }
        _sumissilehome_entrypoint_6(arg0, data + 0x14);
    }
    _sueggmove_entrypoint_9(arg0);
    func_80800064_suegg(arg0);
    suegg_entrypoint_22(arg0);
    *(f32 *)(data + 0x30) += func_800D8FF8();
}

s32 suegg_entrypoint_17(Actor *arg0, s32 arg1, s32 arg2) {
    void func_8010A570(Actor *);
    void func_800FFAB0(Actor *);
    s32 func_80800DC0_suegg(Actor *, s32);
    struct SueggEventData {
        u8 pad[0x39];
        u8 flag80 : 1;
        u8 flag40 : 1;
        u8 flag20 : 1;
        u8 rest : 5;
    } *data;

    data = func_80100094(arg0, 0);
    switch (arg1) {
        case 5:
            data->flag80 = 1;
            func_8010A570(arg0);
            return 1;
        case 0x2C:
            data->flag40 = 1;
            func_8010A570(arg0);
            func_800FFAB0(arg0);
            return 1;
        case 0x92:
            data->flag20 = 1;
            break;
        case 0x98:
            data->flag40 = 1;
            break;
        case 0x9F:
            func_80800DC0_suegg(arg0, arg2);
            return 1;
        default:
            return 0;
    }
    return 1;
}

/* extern */

void suegg_entrypoint_18(s32 arg0, s32 arg1) {
    void func_800EFB24();
    func_800EFB24(arg1, arg0 + 0x4, arg0 + 0x18, arg0);
}

void suegg_entrypoint_19(void *arg0, f32 *arg1) {
    void func_800EE7F8();
    func_800EE7F8(arg1, (u8 *)arg0 + 0x18);
}

void suegg_entrypoint_20(void *arg0, f32 *arg1) {
    void func_800EE7F8();
    func_800EE7F8(arg1, (u8 *)arg0 + 0x28);
}

void suegg_entrypoint_21(Actor *arg0, u32 *arg1) {
    s8 func_800BF8E4(void);
    s32 func_800C8A98(void);
    void func_800C8CB8(s32, f32 *);
    void func_800C8E84(s32, u32 *);
    void func_800C8E54(s32, f32, f32);
    void func_800EE7F8(f32 *, f32 *);
    struct SueggPositionData {
        u8 pad[0x3C];
        s32 handle;
        f32 position[3];
    } *data = func_80100094(arg0, 0);
    if (func_800BF8E4() > 0) {
        data->handle = func_800C8A98();
        func_800C8CB8(data->handle, arg0->position);
        func_800C8E84(data->handle, arg1);
        func_800C8E54(data->handle, 80.0f, 450.0f);
        func_800EE7F8(data->position, arg0->position);
    }
}

/* extern */

void suegg_entrypoint_22(Actor *arg0) {
    void func_800C8CB8(s32, f32 *);
    s32 func_800E3E8C(f32 *, f32);
    void func_800EE7F8(f32 *, f32 *);
    struct SueggPositionData {
        u8 pad[0x3C];
        s32 handle;
        f32 position[3];
    } *sp24;

    sp24 = func_80100094(arg0, 0);
    if (sp24->handle) {
        if (func_800E3E8C(arg0->position, 450.0f) || func_800E3E8C(sp24->position, 450.0f)) {
            func_800C8CB8(sp24->handle, arg0->position); func_800EE7F8(sp24->position, arg0->position);
        }
    }
}

void suegg_entrypoint_23(Actor *arg0) {
    s32 func_8010D930(s32, s32, f32 *, s32 *);
    extern s32 D_80800E64_suegg;
    func_8010D930(8, 0, arg0->position, &D_80800E64_suegg);
}

/* extern */

s32 func_80800DC0_suegg(Actor *arg0, s32 arg1) {
    s32 func_800D3948(void);
    s32 func_800F6CC8(s32);
    struct {
        u8 pad[0x39];
        u8 : 1;
        u8 active : 1;
        u8 : 6;
    } *temp_v0;

    if ((func_800D3948() == 0) && (func_800F6CC8(arg1) != 0)) {
        temp_v0 = func_80100094(arg0, 0);
        temp_v0->active = 1;
        suegg_entrypoint_3(arg0);
        return 1;
    }
    return 0;
}
