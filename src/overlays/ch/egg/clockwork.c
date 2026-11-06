#include "common.h"

void func_80800000_cheggclockwork(Actor *arg0) { void *func_80100094(Actor *, u32); void func_800F7BC8(s32, s32, Unk80132ED0 *); void func_808007B4_cheggclockwork(Actor *); void _suegg_entrypoint_2(Actor *); func_800F7BC8(*(s16 *)((u8 *)func_80100094(arg0, 0U) + 0x3A), 0x4D, arg0->unk0); func_808007B4_cheggclockwork(arg0); _suegg_entrypoint_2(arg0); }

void func_80800048_cheggclockwork(Actor *arg0) {
    void _fxegg_entrypoint_4(f32 *, f32);
    f32 func_800D8FF8(void);
    void func_800EE7F8(f32 *, f32 *);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    void *func_80100094(Actor *, u32);
    f32 *temp_s1;
    f32 temp_f20;
    f32 sp4C[3];

    temp_s1 = func_80100094(arg0, 0);
    temp_s1[10] -= func_800D8FF8();
    temp_f20 = func_800F10B4(temp_s1[12], 0, 2.0f, 0.0333f, 0.1f);
    if (temp_s1[10] <= 0.0f) {
        do {
            temp_s1[10] += temp_f20;
            func_800EE7F8(sp4C, arg0->position);
            _fxegg_entrypoint_4(sp4C, arg0->scale);
        } while (temp_s1[10] <= 0.0f);
    }
}

void func_80800124_cheggclockwork(Actor *arg0) {
    void _suegg_entrypoint_16(void *);
    void _suegg_entrypoint_23(void *);
    void _suegg_entrypoint_3(void *);
    s32 _suegg_entrypoint_9(Actor *, s32);
    s32 _sueggmove_entrypoint_3(void *);
    int func_800EEEA8(f32 *);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    s32 func_800F693C(s32);
    void *func_80100094(Actor *, u32);
    void func_80108B04(Actor *, u32);
    s32 func_80800270_cheggclockwork(Actor *);
    void func_80800850_cheggclockwork(Actor *);
    f32 *sp2C;
    s32 var_s0;

    sp2C = func_80100094(arg0, 0);
    var_s0 = 0;
    if (_suegg_entrypoint_9(arg0, 0) != 0) {
        if (func_800F693C(*(s16 *)((u8 *)sp2C + 0x3A)) != 0) {
            var_s0 = 2;
        } else {
            var_s0 = 1;
        }
    } else {
        arg0->scale = func_800F10B4(sp2C[12], 0.0f, 0.134f, 0.1f, 0.25f);
        if (_sueggmove_entrypoint_3(arg0) != 0) {
            _suegg_entrypoint_23(arg0);
            var_s0 = 1;
        }
        if (func_800EEEA8((f32 *)&arg0->actorData[4]) != 0) {
            var_s0 = 1;
        }
        if (sp2C[12] > 1.0f) {
            _suegg_entrypoint_3(arg0);
            var_s0 = 2;
        }
        func_80800048_cheggclockwork(arg0);
        _suegg_entrypoint_16(arg0);
    }
    if (((var_s0 == 1) || (var_s0 == 2)) && (func_80800270_cheggclockwork(arg0) == 0)) {
        var_s0 = 3;
    }
    if (var_s0 != 0) {
        func_80108B04(arg0, var_s0);
        return;
    }
    func_80800850_cheggclockwork(arg0);
}

/* extern */

s32 func_80800270_cheggclockwork(Actor *arg0) {
    int func_800DB9B0(void);
    s32 func_800F6D24(s32);
    int func_800F8088(s32);
    void *func_80100094(Actor *, u32);
    void *sp1C;

    sp1C = func_80100094(arg0, 0U);
    if (func_800DB9B0() != 0) {
        return 0;
    }
    if (func_800F6D24((*(s16 *)((s8 *)(sp1C) + (0x3A)))) != 0) {
        return 0;
    }
    if (func_800F8088((*(s16 *)((s8 *)(sp1C) + (0x3A)))) != 0) {
        return 0;
    }
    return 1;
}

void func_808002DC_cheggclockwork(Actor *arg0, s32 arg1) {
    void *func_80100094(Actor *, u32);
    void *func_8001B798(s16);
    s32 func_800F7CF4(s32, s32, void *);
    void func_800FFAB0(Actor *);
    void _suegg_entrypoint_3(void *);
    void func_808006E8_cheggclockwork(Actor *);
    void cheggclockwork_entrypoint_3(void *, s32, s32, s32);
    void *sp24;

    sp24 = func_80100094(arg0, 0U);
    switch (arg1) {
        case 1:
            if (func_80800270_cheggclockwork(arg0) != 0) {
                func_808006E8_cheggclockwork(arg0);
                func_800F7CF4(*(s16 *)((u8 *)sp24 + 0x3A), 0x4C, arg0->position);
            }
            _suegg_entrypoint_3(arg0);
            break;
        case 2:
            cheggclockwork_entrypoint_3(func_8001B798(*(s16 *)((u8 *)sp24 + 0x2C)), *(s32 *)&arg0->rotation[1], *(s16 *)((u8 *)sp24 + 0x3A), 1);
            func_800FFAB0(arg0);
            break;
        case 3:
            _suegg_entrypoint_3(arg0);
            break;
    }
}

s32 func_808003B4_cheggclockwork(Actor *arg0, s32 arg1, s32 arg2) {
    void *func_80100094(Actor *, u32);
    struct {
        u8 pad[0x38];
        u32 unk38_0 : 12;
        u32 flag : 1;
        u32 unk38_13 : 19;
    } *data;

    data = func_80100094(arg0, 0U);
    switch (arg1) {
        case 5:
            func_808002DC_cheggclockwork(arg0, 2);
            break;
        case 0x3D:
            if (arg2 == 1 && !data->flag) {
                arg2 = 2;
            }
            func_808002DC_cheggclockwork(arg0, arg2);
            break;
        case 0x2C:
            func_808002DC_cheggclockwork(arg0, 3);
            break;
        case 0x9F:
            func_808002DC_cheggclockwork(arg0, 3);
            break;
        default:
            return 0;
    }
    return 1;
}

OSThread *cheggclockwork_entrypoint_0(void)
{
    extern u8 D_808008C0_cheggclockwork[];

    return (OSThread *) D_808008C0_cheggclockwork;
}

Actor *cheggclockwork_entrypoint_1(f32 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 _suegg_entrypoint_1(void *, f32);
    void *_suegg_entrypoint_11(s32, s32, s32);
    s32 _sueggmove_entrypoint_10(s32);
    s32 _sueggmove_entrypoint_5(void *, s32);
    s32 _sueggmove_entrypoint_6(void *, f32, f32);
    s32 _sueggmove_entrypoint_7(void *, s32);
    void *func_80100094(Actor *, u32);
    void func_808007DC_cheggclockwork(Actor *, f32 *);
    Actor *actor;
    struct {
        u8 pad[0x38];
        u32 unk38_0 : 12;
        u32 flag : 1;
        u32 unk38_13 : 19;
    } *data;

    _sueggmove_entrypoint_10(arg0);
    actor = _suegg_entrypoint_11(0x15E, arg1, arg3);
    data = func_80100094(actor, 0);
    func_808007DC_cheggclockwork(actor, arg0);
    data->flag = arg4;
    actor->scale = 0.134f;
    _suegg_entrypoint_1(actor, 30.0f);
    _sueggmove_entrypoint_5(actor, 1);
    _sueggmove_entrypoint_6(actor, -2200.0f, -100000.0f);
    _sueggmove_entrypoint_7(actor, arg2);
    actor->unk70_10 = 2;
    return actor;
}

/* extern */

void cheggclockwork_entrypoint_2(s32 arg0, s32 arg1, s32 arg2, volatile f32 arg3, s32 arg4, s32 arg5) {
    s32 _cheggsplode_entrypoint_2(s32 *, f32, s32, s32, s32);
    f32 sp24[3];
    f32 scale = arg3;
    sp24[0] = *(f32 *)&arg0;
    sp24[1] = *(f32 *)&arg1;
    sp24[2] = *(f32 *)&arg2;
    _cheggsplode_entrypoint_2((s32 *)sp24, scale, arg4, 5, arg5);
}

void cheggclockwork_entrypoint_3(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 _chbaddiesetup_entrypoint_6(s32 *, s32, s32, s32, s32, s32, s32);
    s32 func_800BBCB8(void *, s32, s32, s32, s32 *);
    s32 func_800C9C70(f32, s32, s32, s32, void *, f32, f32);
    extern s32 D_80800908_cheggclockwork;
    extern s32 D_80800950_cheggclockwork;
    extern s32 D_80800998_cheggclockwork;
    extern s32 D_808009E0_cheggclockwork;
#ifndef BT_NATIVE
    extern s32 _cheggclockwork_entrypoint_2;
#endif
    func_800C9C70(0.4f, 0x5F3, 0x3F800000, 0x4E20, arg0, 250.0f, 5400.0f);
    func_800BBCB8(arg0, 0, 0x3F800000, 1, &D_80800908_cheggclockwork);
    func_800BBCB8(arg0, 0, 0x3F800000, 6, &D_80800950_cheggclockwork);
    func_800BBCB8(arg0, 0, 0x3F800000, 2, &D_80800998_cheggclockwork);
    func_800BBCB8(arg0, 0, 0x3F800000, 1, &D_808009E0_cheggclockwork);
    _chbaddiesetup_entrypoint_6(&_cheggclockwork_entrypoint_2, (*(s32 *)((s8 *)(arg0) + (0))), (*(s32 *)((s8 *)(arg0) + (4))), (*(s32 *)((s8 *)(arg0) + (8))), arg1, arg2, arg3);
}

void func_808006E8_cheggclockwork(Actor *arg0) {
    void *func_8001B798(s16);
    void *func_80100094(Actor *, u32);
    s32 func_800F6DE0(f32 *);
    void func_800EE7F8(f32 *, f32 *);
    f32 *src;

    src = func_8001B798(*(s16 *)((u8 *)func_80100094(arg0, 0U) + 0x2C));
    if (func_800F6DE0(arg0->position) == 0) {
        if (func_800F6DE0(src) != 0) {
            func_800EE7F8(arg0->position, src);
            return;
        }
        if (func_800F6DE0(src + 3) != 0) {
            func_800EE7F8(arg0->position, src + 3);
            return;
        }
        if (func_800F6DE0(src + 6) != 0) {
            func_800EE7F8(arg0->position, src + 6);
            return;
        }
        func_800EE7F8(arg0->position, src + 6);
    }
}

void func_808007B4_cheggclockwork(Actor *arg0) {
    s32 func_8001B754(s16);
    void* func_80100094(Actor*, u32);
    func_8001B754((*(s16 *)((s8 *)(func_80100094(arg0, 0U)) + (0x2C))));
}

/* extern */

void func_808007DC_cheggclockwork(Actor *arg0, f32 *arg1) {
    void *func_8001B798(s16);
    void func_800EE7F8(f32 dst[3], f32 src[3]);
    void* func_80100094(Actor*, u32);
    s16 func_8001B668(s32, s32);
    u8 *sp1C;
    f32 *sp18;
    f32 *temp_v0;

    sp1C = func_80100094(arg0, 0U);
    (*(s16 *)((s8 *)(sp1C) + (0x2C))) = func_8001B668(0, 0x24);
    temp_v0 = func_8001B798((*(s16 *)((s8 *)(sp1C) + (0x2C))));
    sp18 = temp_v0;
    func_800EE7F8((f32 *) temp_v0, arg1);
    func_800EE7F8(sp18 + 3, arg1);
    func_800EE7F8(sp18 + 6, arg1);
}

void func_80800850_cheggclockwork(Actor *arg0) {
    void *func_8001B798(s16);
    void func_800EE7F8(f32 dst[3], f32 src[3]);
    void* func_80100094(Actor*, u32);
    s32 pad;
    f32 *sp18;
    pad = 0;
    sp18 = func_8001B798((*(s16 *)((s8 *)(func_80100094(arg0, 0U)) + (0x2C))));
    func_800EE7F8(sp18 + 6, sp18 + 3);
    func_800EE7F8(sp18 + 3, (f32 *) sp18);
    func_800EE7F8((f32 *) sp18, arg0->position);
}
