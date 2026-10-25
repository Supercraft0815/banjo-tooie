#include "common.h"
#include "core2/1EB5980.h"
#include "core2/1ED8C80.h"
#include "su/baddieaudioquick.h"

extern f32 D_80800F40_chcablecar[3];
extern s16 D_80800F4C_chcablecar[];
extern s16 D_80800F58_chcablecar[];

typedef struct {
    u8 pad0[0xC];
    f32 unkC;
    u8 unk10;
} cablecarMemory;

OSThread *chcablecar_entrypoint_0(void)
{
    extern u8 D_80800EB0_chcablecar[];

    return (OSThread *) D_80800EB0_chcablecar;
}

OSThread *chcablecar_entrypoint_1(void)
{
    extern u8 D_80800EF8_chcablecar[];

    return (OSThread *) D_80800EF8_chcablecar;
}

void func_80800018_chcablecar(Actor *arg0) {
    void _subaddieDll_entrypoint_4(Actor *, u32);
    s32 _susubgame_entrypoint_4(Actor *, u32 *);
    f32 func_800D8FF8(void);
    s32 func_800DA298(s32);
    s32 func_800DA524(s32);
    s32 func_800DA544(s32);
    void func_800EE7F8(f32 *, f32 *);
    f32 func_800EEB40(f32 *, f32 *);
    void func_80101FDC(Actor *, u32);
    void func_8010D254(f32 *);
    void func_80800598_chcablecar(Actor *);
    void func_808005E0_chcablecar(Actor *);
    void func_8080069C_chcablecar(Actor *);
    s32 func_8080070C_chcablecar(Actor *, f32);
    void func_808007C8_chcablecar(Actor *, u32, u32);
    void func_80800914_chcablecar(Actor *);
    void func_80800AF4_chcablecar(Actor *, u32);
    s32 func_80800BD0_chcablecar(Actor *);
    void func_80800D14_chcablecar(Actor *, s32);
    typedef struct {
        s16 position[3];
        s16 rotation[3];
        f32 progress;
        u8 wave[0x1C];
        u32 subgame;
    } CablecarUpdateMemory;
    typedef struct {
        u8 pad[0x28];
        u32 upper : 19;
        u32 flag : 1;
        u32 lower : 12;
    } CablecarUpdateFlags;
    CablecarUpdateMemory *sp44;
    f32 sp40;
    s32 sp3C;
    f32 sp30[3];
    f32 sp24[3];

    sp44 = func_80100094(arg0, 0);
    sp40 = func_800D8FF8();
    sp3C = 0;
    func_80800598_chcablecar(arg0);
    func_8080069C_chcablecar(arg0);
    switch (arg0->unk70_10) {
    case 1:
        if (func_800DA298(0xD4)) {
            func_808007C8_chcablecar(arg0, 1, 4);
        }
        func_808005E0_chcablecar(arg0);
        break;
    case 2:
        if (func_80800BD0_chcablecar(arg0)) {
            func_808007C8_chcablecar(arg0, 2, 5);
        }
        func_808005E0_chcablecar(arg0);
        break;
    case 3:
        if (!((CablecarUpdateFlags *)arg0->unk0)->flag) {
            func_8010D254(sp30);
            func_800EE7F8(sp24, arg0->position);
            sp24[1] -= 400.0f;
            if (func_800EEB40(sp24, sp30) > 3062500.0f) {
                func_800DA524(0x67E);
                func_80101FDC(arg0, 6);
            }
        } else if (func_80800BD0_chcablecar(arg0)) {
            func_808007C8_chcablecar(arg0, 4, 4);
        }
        func_808005E0_chcablecar(arg0);
        break;
    case 4:
        sp3C = 1;
        if (func_8080070C_chcablecar(arg0, sp44->progress - sp40 * 0.045f)) {
            _susubgame_entrypoint_4(arg0, &sp44->subgame);
            func_800DA524(0x67E);
            func_80800AF4_chcablecar(arg0, 2);
        }
        break;
    case 5:
        sp3C = 1;
        if (func_8080070C_chcablecar(arg0, sp44->progress + sp40 * 0.045f)) {
            _susubgame_entrypoint_4(arg0, &sp44->subgame);
            func_800DA544(0x67E);
            func_80800AF4_chcablecar(arg0, 3);
            _subaddieDll_entrypoint_4(arg0, 1);
        }
        break;
    case 6:
        sp3C = 1;
        if (func_8080070C_chcablecar(arg0, sp44->progress - sp40 * 0.045f)) {
            _subaddieDll_entrypoint_4(arg0, 0);
            func_80101FDC(arg0, 2);
        }
        break;
    case 7:
        func_808005E0_chcablecar(arg0);
        break;
    }
    func_80800D14_chcablecar(arg0, sp3C);
    func_80800914_chcablecar(arg0);
    ((CablecarUpdateFlags *)arg0->unk0)->flag = 0;
}

void func_808002E0_chcablecar(Actor *arg0) {
    void _mlwave_entrypoint_0(void *, f32, f32);
    void _subaddieDll_entrypoint_4(Actor *, u32);
    s32 _susubgame_entrypoint_0(Actor *, u32 *, s32);
    s32 func_800DA298(s32);
    s32 func_800EA05C(void);
    void func_800EE940(s16 *, f32 *);
    void func_800EFA6C(void *, s16, s16, s16);
    void func_80101FDC(Actor *, u32);
    void func_8010A624(Actor *);
    s32 func_8080070C_chcablecar(Actor *, f32);
    typedef struct {
        s16 position[3];
        s16 rotation[3];
        f32 progress;
        u8 wave[0x1C];
        u32 subgame;
    } CablecarInitMemory;
    typedef struct {
        u8 pad[0x7C];
        u32 upper : 17;
        u32 flag : 1;
        u32 lower : 14;
    } CablecarInitFlags;
    s32 temp;
    s32 sp20;
    CablecarInitMemory *mem;

    mem = func_80100094(arg0, 0);
    _susubgame_entrypoint_0(arg0, &mem->subgame, 0);
    if (func_800EA05C() == 0x124) {
        func_8010A624(arg0);
        ((CablecarInitFlags *)arg0)->flag = 0;
    }
    func_800EE940(mem->position, arg0->position);
    func_800EFA6C(mem->rotation, -0x206C, 0xA73, 0);
    arg0->actorData[4] = 0;
    sp20 = func_800DA298(0x67E);
    temp = func_800DA298(0xD4);
    if (sp20 == 0 && temp != 0) {
        mem->progress = 0.0f;
        func_8080070C_chcablecar(arg0, 0.0f);
        func_80101FDC(arg0, 2);
    } else if (sp20 != 0) {
        mem->progress = 1.0f;
        func_8080070C_chcablecar(arg0, 1.0f);
        func_80101FDC(arg0, 3);
        _subaddieDll_entrypoint_4(arg0, 1);
    } else {
        mem->progress = 0.1f;
        func_8080070C_chcablecar(arg0, 0.1f);
    }
    _mlwave_entrypoint_0(mem->wave, 100.0f, 15.0f);
}

s32 func_80800424_chcablecar(Actor *arg0, s32 arg1, s32 arg2) {
    s32 func_800EA05C(void);
    void func_80108B04(Actor *, u32);
    void func_808004EC_chcablecar(Actor *);
    void func_80800B74_chcablecar(s32, s32, s32);
    void func_80800DC8_chcablecar(Actor *);
    typedef struct {
        u32 upper : 19;
        u32 flag : 1;
        u32 lower : 12;
    } CablecarEventFlags;

    switch (arg1) {
        case 0x3D:
            func_80800DC8_chcablecar(arg0);
            break;
        case 0x2E:
            func_80800B74_chcablecar((s32)arg0, ((s16 *)&arg2)[0], ((s16 *)&arg2)[1]);
            break;
        case 0x1F:
            func_808004EC_chcablecar(arg0);
            break;
        case 0x95:
            if (func_800EA05C() == 0xD6) {
                func_80108B04(arg0, 0);
            }
            break;
        case 0x91:
            ((CablecarEventFlags *)&arg0->unk0->unk28)->flag = 1;
            break;
        default:
            return 0;
    }
    return 1;
}

/* extern */

void func_808004EC_chcablecar(Actor *arg0) {
    void func_800DF6BC(s32, s32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    s32 func_801015D0(Actor *);
    f32 temp_f0;
    s32 var_a2;
    void *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    temp_f0 = (*(f32 *)((s8 *)(temp_v0) + (0xC)));
    if (temp_f0 < 0.4f) {
        var_a2 = 0;
    } else if (temp_f0 > 0.6f) {
        var_a2 = 0xFF;
    } else {
        var_a2 = (s32) func_800F10B4((*(f32 *)((s8 *)(temp_v0) + (0xC))), 0.4f, 0.6f, 0.0f, 255.0f);
    }
    func_801015D0(arg0);
    func_800DF6BC(var_a2, 0xFF);
}

void func_80800598_chcablecar(Actor *arg0) {
    f32 _mlwave_entrypoint_5(u8 *, f32, f32);
    s32 pad;
    u8 *temp_a0;
    cablecarMemory *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    temp_a0 = &temp_v0->unk10;
    _mlwave_entrypoint_1(temp_a0);
    arg0->rotation[0] = _mlwave_entrypoint_5(temp_a0, -5.0f, 5.0f);
}

void func_808005E0_chcablecar(Actor* arg0) {
    void* temp_a0;
    cablecarMemory* temp_v0;

    temp_v0 = func_80100094(arg0, 0);
    temp_a0 = &temp_v0->unk10;
    if (temp_v0->unkC < 0.5f) {
        if ((_mlwave_entrypoint_9(temp_a0, D_80800F40_chcablecar) != 0) && (func_800DC298(0.8f) != 0)) {
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_80800F4C_chcablecar);
        }
    } else if ((_mlwave_entrypoint_9(temp_a0, D_80800F40_chcablecar) != 0) && (func_800DC298(0.8f) != 0)) {
        _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_80800F58_chcablecar);
    }
}

void func_8080069C_chcablecar(Actor *arg0) {
    s32 _subaddieaudioloop_entrypoint_4(Actor *, f32 *, u32, u32 *);
    extern u32 D_80800F68_chcablecar;
    u32 var_a2;

    switch (arg0->unk70_10) {
        case 4:
        case 5:
        case 6:
            var_a2 = 1;
            break;
        default:
            var_a2 = 0;
            break;
    }
    if ((var_a2 != 0) || ((var_a2 == 0) && (arg0->unk5F != 0))) {
        _subaddieaudioloop_entrypoint_4(arg0, arg0->position, var_a2, &D_80800F68_chcablecar);
    }
}

s32 func_8080070C_chcablecar(Actor *arg0, f32 arg1) {
    void func_800EE88C(f32 *, s16 *);
    void func_800EFE50(f32 *, f32 *, f32 *, f32);
    typedef struct {
        s16 start[3];
        s16 end[3];
        f32 fraction;
    } CablecarPath;
    CablecarPath *data;
    s32 clamped;
    f32 end[3];
    f32 start[3];

    data = func_80100094(arg0, 0);
    clamped = 0;
    if (arg1 < 0.0f) {
        arg1 = 0.0f;
        clamped = 1;
    } else if (arg1 > 1.0f) {
        arg1 = 1.0f;
        clamped = 1;
    }
    func_800EE88C(end, data->end);
    func_800EE88C(start, data->start);
    func_800EFE50(arg0->position, start, end, arg1);
    data->fraction = arg1;
    return clamped;
}

void func_808007C8_chcablecar(Actor *arg0, u32 arg1, u32 arg2) {
    void _subaddieDll_entrypoint_4(Actor *, u32);
    void _susubgame_entrypoint_6(Actor *, void *, s32, s32, s32);
    void _susubgame_entrypoint_8(Actor *, void *, s32, s32, s32);
    void func_80015178(s32);
    s32 func_800DA9E4(s32, s32);
    void func_80101FDC(Actor *, u32);
    u8 *func_801039E4(Unk80132ED0 *);
    void func_80103D48(void **);
    typedef struct {
        u32 upper : 18;
        u32 active : 1;
        u32 lower : 13;
    } CablecarFlags;
    u8 *data;
    s32 game;

    data = func_80100094(arg0, 0);
    _subaddieDll_entrypoint_4(arg0, 1);
    func_801039E4(arg0->unk0);
    func_80103D48((void **)arg0);
    if (arg1 == 2 && func_800DA9E4(0xBF, 1)) {
        arg1 = 3;
    }
    switch (arg1) {
        case 3: goto game3;
        case 4: goto game4;
        default: goto other;
    }
game3:
            _susubgame_entrypoint_8(arg0, data + 0x2C, 0x2F, 0x10010, 0);
            goto done;
game4:
            _susubgame_entrypoint_8(arg0, data + 0x2C, 0x2E, 0x10010, 0);
            goto done;
other:
            if (arg1 != 1) goto notOne;
            game = 0x1D;
            goto selected;
notOne:
            game = 0x21;
selected:
            func_80015178(3);
            ((CablecarFlags *)&arg0->unk0->unk28)->active = 1;
            _susubgame_entrypoint_6(arg0, data + 0x2C, game, 0x10070, 0);
done:
    arg0->actorData[4] = arg1;
    func_80101FDC(arg0, arg2);
}

void func_80800914_chcablecar(Actor *arg0) {
    void _susubgame_entrypoint_8(Actor *, void *, s32, s32, s32);
    void func_800EF04C(f32 *, f32 *);
    void func_800EFA4C(f32 *, f32, f32, f32);
    u32 func_800F54E4(void);
    void func_800F8294(s32, f32 *);
    void func_800F8444(s32, f32 *);
    typedef struct {
        s16 start[3];
        s16 end[3];
        f32 fraction;
    } CablecarPath;
    CablecarPath *data;
    s32 player;
    f32 position3[3];
    f32 rotation3[3];
    f32 position4[3];
    f32 rotation4[3];

    data = func_80100094(arg0, 0);
    player = func_800F54E4();
    switch (arg0->actorData[4]) {
        case 3:
            if (data->fraction > 0.15f && !arg0->unk64_19) {
                func_8080070C_chcablecar(arg0, 0.85f);
                arg0->unk64_19 = 1;
                _susubgame_entrypoint_8(arg0, (u8 *)data + 0x2C, 0x2E, 0x12010, 0);
                func_800EFA4C(position3, -80.0f, -425.0f, 0.0f);
                func_800EF04C(position3, arg0->position);
                func_800F8294(player, position3);
                func_800EFA4C(rotation3, 0.0f, 270.0f, 0.0f);
                func_800F8444(player, rotation3);
            }
            break;
        case 4:
            if (data->fraction < 0.85f && !arg0->unk64_19) {
                func_8080070C_chcablecar(arg0, 0.15f);
                arg0->unk64_19 = 1;
                _susubgame_entrypoint_8(arg0, (u8 *)data + 0x2C, 0x2F, 0x12010, 0);
                func_800EFA4C(position4, 60.0f, -425.0f, 0.0f);
                func_800EF04C(position4, arg0->position);
                func_800F8294(player, position4);
                func_800EFA4C(rotation4, 0.0f, 90.0f, 0.0f);
                func_800F8444(player, rotation4);
            }
            break;
    }
}

void func_80800AF4_chcablecar(Actor *arg0, u32 arg1) {
    void _subaddieDll_entrypoint_4(Actor *, u32);
    void func_80015178(s32);
    void func_80101FDC(Actor *, u32);
    void func_80103D70(void **);
    typedef struct {
        u32 upper : 18;
        u32 active : 1;
        u32 lower : 13;
    } CablecarFlags;

    _subaddieDll_entrypoint_4(arg0, 0);
    func_80103D70((void **)arg0);
    func_80101FDC(arg0, arg1);
    if (((CablecarFlags *)&arg0->unk0->unk28)->active) {
        func_80015178(2);
        ((CablecarFlags *)&arg0->unk0->unk28)->active = 0;
    }
    arg0->actorData[4] = 0;
    arg0->unk64_19 = 0;
}

/* extern */

void func_80800B74_chcablecar(s32 arg0, s32 arg1, s32 arg2) {
    void _subaddieDll_entrypoint_4(Actor*, u32);
    s32 func_800DA298(s32);
    void func_80101FDC(Actor *, u32);
    if (func_800DA298(0x67E) == 0) {
        func_80101FDC(arg0, 2);
        return;
    }
    func_80101FDC(arg0, 3);
    _subaddieDll_entrypoint_4(arg0, 1);
}

s32 func_80800BD0_chcablecar(Actor *arg0) {
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
    s32 func_80016B30(s32, s32);
    s32 func_800DA298(s32);
    s32 func_800DA544(s32);
    s32 func_800F4BB8(u32, u32, s32);
    s32 func_800F5410(s32);
    u32 func_800F54E4(void);
    s32 func_800F6438(u32);
    int func_800F6B40(s32);
    s32 func_800F6C5C(s32);
    void func_80101FDC(Actor *, u32);
    typedef struct {
        u32 upper : 19;
        u32 active : 1;
        u32 lower : 12;
    } CablecarFlags;
    u32 sp24;

    sp24 = func_800F54E4();
    if (func_800F6438(sp24) == 0 ||
        !((CablecarFlags *)&arg0->unk0->unk28)->active ||
        func_800F6C5C(sp24) == 0) {
        return 0;
    }
    if (func_800DA298(0x67F) == 0) {
        _subaddiedialog_entrypoint_11(arg0->unk0, 0x10BA, 0xE, NULL, 0x22);
        func_80101FDC(arg0, 7);
        func_800DA544(0x67F);
        return 0;
    }
    if (func_80016B30(0, 1) != 1) {
        return 0;
    }
    if (func_800F6B40(sp24) != 0) {
        return 0;
    }
    if (func_800F4BB8(sp24, -1, 0) == 0) {
        return 0;
    }
    if (func_800F5410(sp24) != 1) {
        _subaddiedialog_entrypoint_11(arg0->unk0, 0x10B9, 0xF, NULL, 0x22);
        func_80101FDC(arg0, 7);
        return 0;
    }
    return 1;
}

void func_80800D14_chcablecar(Actor *arg0, s32 arg1) {
    void _subaddieDll_entrypoint_4(Actor *, u32);
    void func_800EE7F8(f32 *, f32 *);
    s32 func_800F4F34(u32, f32 *, f32, f32);
    u32 func_800F54E4(void);
    s32 func_800F6C88(s32);
    s32 func_800F76B0(s32, s32, s32);
    void func_80103014(u8 *);
    Actor *func_80106790(Unk80132ED0 *);
    union {
        Actor *actor;
        struct {
            u8 reserved[0x7C];
            u16 flags;
        } *fields;
    } view;
    u32 sp20;
    Actor *actor;

    if (arg0->unk3C != NULL) {
        sp20 = func_800F54E4();
        actor = func_80106790(arg0->unk3C);
        actor->rotation[0] = arg0->rotation[0];
        func_800EE7F8(actor->position, arg0->position);
        func_80103014((u8 *)actor);
        view.actor = arg0;
        _subaddieDll_entrypoint_4(actor, view.fields->flags);
        if (func_800F6C88(sp20) && func_800F4F34(sp20, actor->position, 0.0f, 80.0f) && arg1) {
            func_800F76B0(sp20, 10, (s32)actor->unk0);
        }
    }
}

void func_80800DC8_chcablecar(Actor *arg0) {
    void _subaddieDll_entrypoint_4(Actor*, u32);
    void func_80102FDC(Actor*, f32);
    Actor* func_801084B0(s32, Actor**);
    Actor *sp1C;
    union {
        Actor *actor;
        struct {
            u8 reserved[0x7C];
            u16 flags;
        } *fields;
    } view;
    sp1C = func_801084B0(0x33F, &arg0);
    func_80102FDC(sp1C, arg0->scale);
    view.actor = arg0;
    _subaddieDll_entrypoint_4(sp1C, view.fields->flags);
    sp1C->rotation[0] = arg0->rotation[0];
    arg0->unk3C = sp1C->unk0;
}

/* extern */

void func_80800E30_chcablecar(s32 arg0) {
    s32 _chswitch_entrypoint_7(s32, s32);
    s32 _chswitch_entrypoint_9(s32);
    _chswitch_entrypoint_7(arg0, 0xD4);
    _chswitch_entrypoint_9(arg0);
}
