#include "common.h"

u32 D_80800C30_chboggyboy[];
void func_80101870(Actor *, void *);
void *func_80107C2C(s32 *, s32, void *, s32, void *);
OSThread *func_80108ED0(void);
void func_8080000C_chboggyboy(Actor *arg0);
void func_808000B8_chboggyboy(Actor *arg0);
s32 func_80800570_chboggyboy();
void func_808007F4_chboggyboy(Actor *arg0);
void func_8080086C_chboggyboy(Actor *arg0);

s32 D_80800C00_chboggyboy[] = {
    0x00000601, 0x10880100,
    0x00000601, 0x10890200,
    0xFFFEDFFF, 0x12220300,
};

u8 D_80800C18_chboggyboy[] = {
    0x00, 0x13, 0x05, 0x24, 0x00, 0x0A, 0x00, 0xCC,
    0x00, 0x00, 0x00, 0x00,
};

u8 D_80800C24_chboggyboy[] = {
    0x00, 0x13, 0x05, 0x25, 0x00, 0x0D, 0x00, 0xF3,
    0x01, 0x0C, 0x00, 0x00,
};

u32 D_80800C30_chboggyboy[] = {
    0x00000000, 0x00000000,
    0x4089999A, 0x02420001,
    0x3F266666, 0x02430001,
    0x3F266666, 0x02430001,
    0x4089999A, 0x02420001,
    0x3F266666, 0x02430001,
    0x3F266666, 0x02430001,
    0x3F266666, 0x02430001,
    0x4089999A, 0x02420001,
    0x4089999A, 0x02420001,
    0x4089999A, 0x02420001,
    0x4089999A, 0x02420001,
    0x4089999A, 0x02420001,
    0x4089999A, 0x02420001,
    0x3F4CCCCD, 0x00B70002,
    0x4089999A, 0x02420001,
    0x00000000, 0x00000000,
};

u32 D_80800CB8_chboggyboy[] = {
    0x01920140, 0x07590001,
    (u32)D_80800C30_chboggyboy, (u32)func_808000B8_chboggyboy,
    (u32)func_8080086C_chboggyboy, (u32)func_80101870,
    0x09C40000, 0x3F800000,
    0x008C0000, 0x40040120,
    (u32)func_808007F4_chboggyboy, (u32)func_80108ED0,
    0x00240000, (u32)func_8080000C_chboggyboy,
    (u32)func_80107C2C, 0x80105014,
    (u32)func_80800570_chboggyboy, 0x00000000,
};

u16 D_80800D00_chboggyboy[] = {
    0x00B8, 0x0000, 0x0190, 0x003B,
    0x0000, 0x000E, 0x0000, 0x0400,
};

u32 D_80800D10_chboggyboy[] = {
    0x43200000, 0x430C0000,
    0x430C0000, 0x428C0000,
};

s32 D_80800D20_chboggyboy[] = {
    0x001304A4, 0x000A0140,
    0x00000000, 0x00000000,
};

void *func_80100094(Actor *, u32);

OSThread *chboggyboy_entrypoint_0(void)
{

    return (OSThread *) D_80800CB8_chboggyboy;
}

void func_8080000C_chboggyboy(Actor *arg0) {
    s32 _chboggykids_entrypoint_0(Actor *);
    s32 _subaddieDll_entrypoint_1(Actor *);
    void _subaddierouteDll_entrypoint_3(Actor *, void *, f32 *);
    s32 func_800DA298(s32);
    void func_800FFAB0(Actor *);
    void func_8080082C_chboggyboy(Actor *);
    struct {
        u8 pad0[8];
        u8 route[12];
        s16 timer;
        u8 pad16 : 1;
        u8 active : 1;
        u8 pad16_0 : 6;
    } *temp_s1;

    temp_s1 = func_80100094(arg0, 0U);
    if (_chboggykids_entrypoint_0(arg0) == 0) {
        func_800FFAB0(arg0);
        return;
    }
    ((f32 *)arg0->actorData)[3] = 300.0f;
    if (func_800DA298(0xB8) == 0) {
        func_8010A570(arg0);
    } else {
        temp_s1->active = 1;
    }
    _subaddieDll_entrypoint_1(arg0);
    _subaddierouteDll_entrypoint_3(arg0, temp_s1->route, arg0->position);
    temp_s1->timer = 0;
    func_8080082C_chboggyboy(arg0);
}

void func_808000B8_chboggyboy(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    s32 _subaddiedialog_entrypoint_8(Actor *, f32 *, u16 *, s32 *, s32);
    void _subaddiefx_entrypoint_0(Actor *, s32, u8 *);
    s32 _subaddiefx_entrypoint_1(Actor *, u8 *);
    s32 _subaddierouteDll_entrypoint_4(Actor *);
    void _subaddierouteDll_entrypoint_6(Actor *, void *, s32, s32, f32, s32, s32);
    s32 _subaddierouteDll_entrypoint_7(Actor *, void *, f32, f32, f32, s32);
    void _sudeflect_entrypoint_0(f32 *, f32, f32, s32);
    void _suexpression_entrypoint_10(u32 *, Unk80132ED0 *, u32);
    s32 func_800D90A4(f32 *);
    int func_800D9154(f32 *, f32);
    s32 func_800DA298(s32);
    f32 func_800DC178(f32, f32);
    void func_800EE88C(f32 *, s16 *);
    int func_800F0064(f32 *, f32, f32 *);
    void *func_80100094(Actor *, u32);
    s32 func_80101DDC(Actor *);
    s32 func_801022E4(Actor *);
    void func_80102424(Actor *, s32);
    f32 func_801028C4(Actor *, f32 *, f32, f32, f32);
    void func_80102924(void *, f32);
    void func_80102BF8(Actor *, f32, f32, f32);
    s32 func_80102CF4(Actor *, f32);
    f32 func_80102D78(Actor *, f32 *);
    s32 func_80105230(Actor *, s32);
    void func_801058C4(Actor *, s32, f32, u32);
    void func_80105BAC(Actor *);
    s32 func_8010B990(Actor *, s32);
    void func_8010CE70(Actor *, s32, s32);
    struct {
        s16 position[3];
        s16 animation;
        struct {
            u8 pad[6];
            u16 flags;
            u8 pad8[4];
        } route;
        union {
            struct {
                s16 timer;
                s16 flags;
            } halves;
            struct {
                u32 high : 16;
                u32 active : 1;
                u32 middle : 1;
                u32 flag : 1;
                u32 low : 13;
            } bits;
        } state;
        u8 fx[8];
        f32 audioTimer;
    } *sp5C;
    s32 sp58;
    f32 sp4C[3];
    f32 sp40[3];

    sp5C = func_80100094(arg0, 0U);
    sp58 = func_800D90A4(&arg0->unk58);
    if (func_80100094(arg0, 1U) != NULL) {
        u32 *expression;
        expression = func_80100094(arg0, 1U);
        _suexpression_entrypoint_10(expression, arg0->unk0, 0);
    }
    switch (arg0->unk70_10) {
    case 1:
        if ((_subaddiedialog_entrypoint_8(arg0, arg0->position, &D_80800D00_chboggyboy[0], &D_80800C00_chboggyboy[0], 3) == 0) && (func_800DA298(D_80800D00_chboggyboy[0]) != 0) && (sp58 != 0)) {
            func_80102924(arg0, arg0->rotation[1] + func_800DC178(90.0f, 270.0f));
            func_80102424(arg0, 3);
            sp5C->state.halves.timer = 0;
        }
        break;
    case 4:
        func_8010CE70(arg0, 10, -1);
        break;
    case 3:
        func_80102BF8(arg0, 0.2f, 60.0f, 180.0f);
        if (func_80102CF4(arg0, 15.0f) != 0) {
            arg0->unk58 = func_800DC178(8.0f, 12.0f);
            func_80102424(arg0, 2);
        }
        _subaddiedialog_entrypoint_8(arg0, arg0->position, &D_80800D00_chboggyboy[0], &D_80800C00_chboggyboy[0], 3);
        break;
    case 2:
        func_80105230(arg0, 0);
        if (_subaddiedialog_entrypoint_8(arg0, arg0->position, &D_80800D00_chboggyboy[0], &D_80800C00_chboggyboy[0], 3) == 0) {
            _subaddierouteDll_entrypoint_6(arg0, &sp5C->route, sp5C->state.halves.timer, 7, 0.7f, 8, 12);
            if (_subaddierouteDll_entrypoint_4(arg0) != 0) {
                _subaddierouteDll_entrypoint_7(arg0, &sp5C->route, arg0->rotation[1], arg0->unk54, 200.0f, 0x4000);
                sp5C->state.halves.timer = sp5C->route.flags;
            }
            func_80102BF8(arg0, 0.2f, 30.0f, 180.0f);
            if (func_8010B990(arg0, 0x1305) & 4) {
                func_80102924(arg0, arg0->rotation[1] + 180.0f);
                func_80102424(arg0, 3);
                sp5C->state.halves.timer = 0;
            } else if (sp58 != 0) {
                func_80102424(arg0, 1);
                arg0->unk58 = func_800DC178(4.0f, 6.0f);
            }
        }
        break;
    case 5:
        func_800EE88C(sp4C, sp5C->position);
        if (func_801028C4(arg0, sp4C, 0.2f, 30.0f, 180.0f) < 40.0f) {
            func_80102424(arg0, 6);
        }
        break;
    case 6:
        func_800EE88C(sp40, sp5C->position);
        arg0->unk54 = func_80102D78(arg0, sp40);
        func_80102BF8(arg0, 0.2f, 30.0f, 180.0f);
        func_8010B990(arg0, 0x1005);
        if (func_800F0064(arg0->position, 100.0f, sp40) != 0) {
            func_801058C4(arg0, sp5C->animation, ((f32 *)arg0->actorData)[3], 1);
            func_80105BAC(arg0);
            func_80102424(arg0, 7);
        }
        break;
    case 14:
        _subaddiefx_entrypoint_0(arg0, -1, sp5C->fx);
        if (func_80101DDC(arg0) != 0) {
            _subaddiefx_entrypoint_1(arg0, sp5C->fx);
            func_80102424(arg0, 4);
        }
        break;
    }
    if (sp5C->state.bits.middle) {
        if ((func_801022E4(arg0) == 0x243) && (func_800D9154(&sp5C->audioTimer, 3.0f) != 0)) {
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_80800C24_chboggyboy);
        }
    } else if (sp5C->state.bits.active && (func_800D9154(&sp5C->audioTimer, 2.5f) != 0)) {
        _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_80800C18_chboggyboy);
    }
    _sudeflect_entrypoint_0(arg0->position, 100.0f, 50.0f, 10);
}

typedef union {
    s32 word;
    struct { s16 high; s16 low; } halves;
} BoggyBoyMessage;

s32 func_80800570_chboggyboy(Actor *arg0, s32 arg1, BoggyBoyMessage arg2) {
    void _gcdialogcamera_entrypoint_3(u32 *, f32);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    void _subaddierouteDll_entrypoint_1(Actor *);
    void func_800C9C70(f32, u32, f32, u32, f32 *, f32, f32);
    s32 func_800DA980(s32, s32);
    void func_808006C4_chboggyboy(Actor *, s32, s32);
    void func_80800978_chboggyboy(Actor *, s32);
    void func_80800A64_chboggyboy(Actor *);
    void func_80800AD0_chboggyboy(Actor *);
    f32 *position;

    switch (arg1) {
    case 0x2E:
        func_808006C4_chboggyboy(arg0, arg2.halves.high, arg2.halves.low);
        break;
    case 0x40:
        func_80800978_chboggyboy(arg0, arg2.word);
        break;
    case 0x95:
        _subaddierouteDll_entrypoint_1(arg0);
        break;
    case 0x29:
        func_80800A64_chboggyboy(arg0);
        break;
    case 0x52:
        _gcdialogcamera_entrypoint_3(&D_80800D10_chboggyboy[0], arg0->scale);
        break;
    case 0x2D:
        position = arg0->position;
        _subaddieaudioquick_entrypoint_2(arg0, position, &D_80800D20_chboggyboy[0]);
        func_800C9C70(1.0f, 0x525, 1.05f, 0x55F0, position, 200.0f, 3000.0f);
        break;
    case 0x30:
        return 3 - func_800DA980(0x8C, 3);
    case 0x2A:
        func_80800AD0_chboggyboy(arg0);
        break;
    default:
        return 0;
    }
    return 1;
}

void func_808006C4_chboggyboy(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _subaddieDll_entrypoint_4(void *, s32);
    s32 _subaddiedialog_entrypoint_9(Actor *, s32, s32 *, s32);
    void func_800DA544(GameFlag);
    s32 func_80101180(s32, s32, s32);
    void func_80102424(Actor *, s32);
    void func_80102924(void *, f32);
    void func_8010A590(Actor *);
    void func_808009F4_chboggyboy(Actor *);
    struct {
        u8 pad0[8];
        u8 route[12];
        s16 timer;
        u8 pad16 : 1;
        u8 active : 1;
        u8 dialog : 1;
        u8 pad16_0 : 5;
    } *sp24;

    sp24 = func_80100094(arg0, 0U);
    switch (arg1) {
    case 0x108A:
        func_800DA544(0x8C);
        func_80101180(0x13F, 0x23, 0);
        func_80102424(arg0, 5);
        _subaddieDll_entrypoint_4(arg0, 1);
        func_808009F4_chboggyboy(arg0);
        return;
    case 0x1098:
    case 0x1099:
        sp24->dialog = 0;
        return;
    default:
        switch (_subaddiedialog_entrypoint_9(arg0, arg1, &D_80800C00_chboggyboy[0], 3)) {
        case 1:
            func_8010A590(arg0);
            sp24->active = 1;
        case 2:
            func_80102924(arg0, arg0->rotation[1] + 180.0f);
            func_80102424(arg0, 3);
            sp24->timer = 0;
            return;
        default:
            func_80102424(arg0, 1);
            return;
        }
    }
}

void func_808007F4_chboggyboy(Actor *arg0) {
    s32 _subaddiefx_entrypoint_1(Actor *, u8 *);
    void func_80800AD0_chboggyboy(Actor *);
    _subaddiefx_entrypoint_1(arg0, (u8 *)func_80100094(arg0, 0U) + 0x18);
    func_80800AD0_chboggyboy(arg0);
}

void func_8080082C_chboggyboy(Actor *arg0) {
    s16 _glsplinefind_entrypoint_0(u32, f32 *);
    void func_800EE940(void *, f32 *);
    void *sp24;
    f32 sp18[3];

    sp24 = func_80100094(arg0, 0U);
    ((s16 *)sp24)[3] = _glsplinefind_entrypoint_0(0x3A1U, sp18);
    func_800EE940(sp24, sp18);
}

void func_8080086C_chboggyboy(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    void _sudeflect_entrypoint_0(f32 *, f32, f32, s32);
    int func_800D9154(f32 *, f32);
    void func_800FFAB0(Actor *);
    void func_80102424(Actor *, s32);
    s32 func_80105230();
    void func_80105834(Actor *);
    s32 func_80105A5C(Actor *);
    struct Data {
        u8 pad[0x14];
        u32 high : 16;
        u32 active : 1;
        u32 middle : 1;
        u32 flag : 1;
        u32 low : 13;
        u8 pad18[8];
        f32 timer[1];
    };
    struct Data *sp24;

    sp24 = func_80100094(arg0, 0U);
    if (sp24->active && (func_800D9154(sp24->timer, 1.6f) != 0)) {
        _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_80800C18_chboggyboy);
    }
    if (arg0->unk70_10 == 0x10) {
        if (!sp24->flag) {
            func_800FFAB0(arg0);
        }
    } else {
        func_80105834(arg0);
        _sudeflect_entrypoint_0(arg0->position, 100.0f, 50.0f, 10);
        func_80105230(arg0, 0);
        if (func_80105A5C(arg0) != 0) {
            if (sp24->flag) {
                func_80102424(arg0, 0x10);
                arg0->unk64_16 = 0;
            } else {
                func_800FFAB0(arg0);
            }
        }
    }
}

void func_80800978_chboggyboy(Actor *arg0, s32 arg1) {
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
    void func_80102424(Actor *, s32);
    void *sp2C;
    struct Flags { u8 pad[0x16]; u8 high : 1; u8 flag : 1; u8 low : 6; };

    sp2C = func_80100094(arg0, 0);
    _subaddiedialog_entrypoint_11(arg0->unk0, 0x108A, 0xE, (f32 *)((s8 *)arg0 + 4), 0x3B);
    func_80102424(arg0, 0xE);
    func_8010A570(arg0);
    ((struct Flags *)sp2C)->high = 1;
    ((struct Flags *)sp2C)->flag = 0;
}

void func_808009F4_chboggyboy(Actor *arg0) {
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
    s32 func_800DA980(s32, s32);
    struct Flags { u8 pad[0x16]; u8 high : 2; u8 flag : 1; u8 low : 5; };
    struct Flags *data;
    s32 dialog;

    dialog = (func_800DA980(0x8C, 3) == 3) ? 0x1099 : 0x1098;
    _subaddiedialog_entrypoint_11(arg0->unk0, dialog, 0xF, arg0->position, 0x3B);
    data = func_80100094(arg0, 0);
    data->flag = 1;
}

/* extern */

void func_80800A64_chboggyboy(Actor *arg0) {
    s32 _suexpression_entrypoint_12(void *, s32, s32);
    s32 _suexpression_entrypoint_17(void *, s32);
    s32 _suexpression_entrypoint_7(Actor *, s32, s32);
    if (func_80100094(arg0, 1U) == NULL) {
        _suexpression_entrypoint_7(arg0, 1, 0x3B);
        _suexpression_entrypoint_12(func_80100094(arg0, 1U), 0x42700000, 0x41A00000);
        _suexpression_entrypoint_17(func_80100094(arg0, 1U), 0x3E8);
    }
}

/* extern */

void func_80800AD0_chboggyboy(Actor *arg0) {
    s32 _suexpression_entrypoint_8(Actor *, s32);
    if (func_80100094(arg0, 1U) != NULL) {
        _suexpression_entrypoint_8(arg0, 1);
    }
}
