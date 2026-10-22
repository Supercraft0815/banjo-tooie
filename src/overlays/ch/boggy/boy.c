#include "common.h"

void *func_80100094(Actor *, u32);

OSThread *chboggyboy_entrypoint_0(void)
{
    extern u8 D_80800CB8_chboggyboy[];

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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/boggy/boy/func_808000B8_chboggyboy.s")

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
    extern u32 D_80800D10_chboggyboy;
    extern s32 D_80800D20_chboggyboy;
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
        _gcdialogcamera_entrypoint_3(&D_80800D10_chboggyboy, arg0->scale);
        break;
    case 0x2D:
        position = arg0->position;
        _subaddieaudioquick_entrypoint_2(arg0, position, &D_80800D20_chboggyboy);
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
    extern s32 D_80800C00_chboggyboy;
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
        switch (_subaddiedialog_entrypoint_9(arg0, arg1, &D_80800C00_chboggyboy, 3)) {
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
    extern u8 D_80800C18_chboggyboy[];
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
