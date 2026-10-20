#include "common.h"

void func_80800000_cheggnormal(void *arg0) {
    void *func_80100094(Actor *, u32);
    f32 func_800D8FF8(void);
    f32 func_800DC0C0(void);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EFA20(void *, void *, f32);
    void _fxegg_entrypoint_1(f32 *, f32);
    void _fxegg_entrypoint_2(f32 *, f32);
    void _fxegg_entrypoint_7(f32 *, f32 *, f32);
    void _fxegg_entrypoint_8(f32 *, f32 *, f32);
    f32 interval;
    struct EggData {
        u8 pad0[0x28];
        f32 timer;
        f32 unk2C;
        f32 duration;
        u32 unk34;
        u32 pad38 : 11;
        u32 flag : 1;
        u32 rest : 20;
    } *data;
    f32 position[3];
    f32 velocity[3];
    Actor *actor = arg0;

    data = func_80100094(arg0, 0);
    data->timer -= func_800D8FF8();
    interval = func_800F10B4(data->duration, 0, 2.0f, 0.0333f, 0.1f);
    if (data->timer <= 0.0f) {
      do {
        data->timer += interval;
        func_800EE7F8(position, actor->position);
        if (data->flag) {
            func_800EFA20(velocity, &actor->actorData[4], 0.125f);
            if (func_800DC0C0() < 0.5f) {
                _fxegg_entrypoint_7(position, velocity, actor->scale);
            } else {
                _fxegg_entrypoint_8(position, velocity, actor->scale);
            }
        } else if (func_800DC0C0() < 0.5f) {
            _fxegg_entrypoint_2(position, actor->scale);
        } else {
            _fxegg_entrypoint_1(position, actor->scale);
        }
      } while (data->timer <= 0.0f);
    }
}

void func_80800194_cheggnormal(void *arg0) {
    void *func_80100094(Actor *, u32);
    s32 func_800EEEA8(s32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    s32 _suegg_entrypoint_8(void *);
    s32 _suegg_entrypoint_12(void *);
    s32 _suegg_entrypoint_13(void *);
    s32 _suegg_entrypoint_14(void *);
    void _suegg_entrypoint_16(void *);
    void _suegg_entrypoint_23(void *);
    void _suegg_entrypoint_3(void *);
    void _sueggmisc_entrypoint_1(void *);
    s32 _sueggmove_entrypoint_3(void *);
    void func_80800000_cheggnormal(void *);
    struct FireData {
        u8 pad[0x39];
        u8 flag : 1;
        u8 rest : 7;
    } *data;

    data = func_80100094(arg0, 0);
    switch ((u32)*(u16 *)((u8 *)arg0 + 0x72) >> 10) {
    case 1:
        if (_suegg_entrypoint_8(arg0) == 0) {
            if (func_800EEEA8((s32)((u8 *)arg0 + 0x28)) != 0) {
                data->flag = 1;
            } else {
                func_80800000_cheggnormal(arg0);
                _suegg_entrypoint_16(arg0);
                if (_suegg_entrypoint_14(arg0) != 0) {
                    data->flag = 1;
                }
            }
        }
        break;
    case 2:
        if (_suegg_entrypoint_8(arg0) == 0) {
            *(f32 *)((u8 *)arg0 + 0x38) = func_800F10B4(*(f32 *)((u8 *)data + 0x30), 0.0f, 0.134f, 0.1f, 0.25f);
            if (_sueggmove_entrypoint_3(arg0) != 0) {
                _suegg_entrypoint_23(arg0);
            }
            if (_suegg_entrypoint_13(arg0) != 0) {
                data->flag = 1;
            } else if (_suegg_entrypoint_12(arg0) != 0) {
                _sueggmisc_entrypoint_1(arg0);
            } else {
                func_80800000_cheggnormal(arg0);
                _suegg_entrypoint_16(arg0);
            }
        }
        break;
    }
    if (data->flag) {
        _suegg_entrypoint_3(arg0);
    }
}

OSThread *cheggnormal_entrypoint_0(void)
{
    extern u8 D_808004D0_cheggnormal[];

    return (OSThread *) D_808004D0_cheggnormal;
}

void *cheggnormal_entrypoint_1(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 _suegg_entrypoint_1(void *, f32);
    void *_suegg_entrypoint_11(s32, s32, s32);
    s32 _sueggmove_entrypoint_10(s32);
    s32 _sueggmove_entrypoint_5(void *, s32);
    s32 _sueggmove_entrypoint_6(void *, f32, f32);
    s32 _sueggmove_entrypoint_7(void *, s32);
    void *func_80100094(Actor *, u32);
    Actor *temp_v0;
    struct NormalData {
        u8 pad[0x38];
        u8 unk38;
        u8 pad39_5 : 3;
        u8 unk39_4 : 1;
        u8 pad39_0 : 4;
    } *data;

    _sueggmove_entrypoint_10(arg0);
    temp_v0 = _suegg_entrypoint_11(0x15A, arg1, arg3);
    data = func_80100094(temp_v0, 0);
    data->unk38 = 1;
    temp_v0->scale = 0.134f;
    _suegg_entrypoint_1(temp_v0, 30.0f);
    _sueggmove_entrypoint_5(temp_v0, 1);
    _sueggmove_entrypoint_6(temp_v0, -2200.0f, -22000.0f);
    _sueggmove_entrypoint_7(temp_v0, arg2);
    temp_v0->unk70_10 = 2;
    data->unk39_4 = 0;
    return temp_v0;
}

void *cheggnormal_entrypoint_2(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    void *func_80100094(Actor *, u32);
    s32 _suegg_entrypoint_1(void *, f32);
    void *_suegg_entrypoint_11(s32, s32, s32);
    s32 _sueggmove_entrypoint_10(s32);
    s32 _sueggmove_entrypoint_5(void *, s32);
    s32 _sueggmove_entrypoint_6(void *, f32, f32);
    s32 _sueggmove_entrypoint_7(void *, s32);
    s32 func_800F693C(s32);
    Actor *actor;
    struct NormalData {
        u8 pad[0x38];
        u8 unk38;
        u8 pad39_5 : 3;
        u8 unk39_4 : 1;
        u8 pad39_0 : 4;
    } *data;

    _sueggmove_entrypoint_10(arg0);
    actor = _suegg_entrypoint_11(0x15A, arg1, arg3);
    data = func_80100094(actor, 0);
    actor->scale = 0.25f;
    _sueggmove_entrypoint_5(actor, 0);
    _sueggmove_entrypoint_6(actor, 0.0f, -100000.0f);
    _suegg_entrypoint_1(actor, 30.0f);
    _sueggmove_entrypoint_7(actor, arg2);
    actor->unk70_10 = 1;
    if (func_800F693C(arg3) != 0) {
        data->unk39_4 = 1;
    } else {
        data->unk39_4 = 0;
    }
    return actor;
}
