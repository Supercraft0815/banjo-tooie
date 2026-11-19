#include "common.h"

void func_80800000_cheggfire(void *arg0) {
    void *func_80100094(Actor *, u32);
    f32 func_800D8FF8(void);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    s32 _fxegg_entrypoint_3(f32 *, f32);
    struct FireTimer {
        u8 pad[0x28];
        f32 timer;
        f32 unk2C;
        f32 value;
    } *data;
    f32 interval;
    f32 zero;

    data = func_80100094(arg0, 0);
    data->timer -= func_800D8FF8();
    interval = func_800F10B4(data->value, 0.0f, 2.0f, 0.0333f, 0.1f);
    zero = 0.0f;
    if (data->timer <= zero) {
        do {
            data->timer += interval;
        } while (data->timer <= zero);
    }
    if (func_8001210C(1) != 0) {
        return;
    }
    _fxegg_entrypoint_3(((Actor *)arg0)->position, ((Actor *)arg0)->scale);
}                typedef struct { u8 pad0[0x38]; f32 unk38; u8 pad3C[0x36]; u16 unk72; } Objfire_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

void func_808000B8_cheggfire(void *arg0) {
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
    BT_IDO_ONLY(s32) BT_NATIVE_ONLY(u8) _sueggmove_entrypoint_3(void *);
    void func_80800000_cheggfire(void *);
    struct FireData {
        u8 pad[0x39];
        BT_BITFIELD_ORDER(u8 flag : 1, u8 rest : 7);
        BT_BITFIELD_ORDER(u8 rest : 7, u8 flag : 1);
    } *data;

    data = func_80100094(arg0, 0);
    switch ((u32)*&((Objfire_arg0 *)arg0)->unk72 >> 10) {
    case 1:
        if (_suegg_entrypoint_8(arg0) == 0) {
            if (func_800EEEA8((BtIntPtr)((u8 *)arg0 + 0x28)) != 0) {
                data->flag = 1;
            } else {
                func_80800000_cheggfire(arg0);
                _suegg_entrypoint_16(arg0);
                if (_suegg_entrypoint_14(arg0) != 0) {
                    data->flag = 1;
                }
            }
        }
        break;
    case 2:
        if (_suegg_entrypoint_8(arg0) == 0) {
            ((Objfire_arg0 *)arg0)->unk38 = func_800F10B4(*(f32 *)((u8 *)data + 0x30), 0.0f, 0.134f, 0.1f, 0.25f);
            if (_sueggmove_entrypoint_3(arg0) != 0) {
                _suegg_entrypoint_23(arg0);
            }
            if (_suegg_entrypoint_13(arg0) != 0) {
                data->flag = 1;
            } else if (_suegg_entrypoint_12(arg0) != 0) {
                _sueggmisc_entrypoint_1(arg0);
            } else {
                func_80800000_cheggfire(arg0);
                _suegg_entrypoint_16(arg0);
            }
        }
        break;
    }
    if (data->flag) {
        _suegg_entrypoint_3(arg0);
    }
}

void func_80800228_cheggfire(BtIntPtr arg0) {
    void _suegg_entrypoint_21(Actor *arg0, u32 *arg1);
    s32 _suegg_entrypoint_5();
    extern s32 D_808003B0_cheggfire[3];
    _suegg_entrypoint_5();
    _suegg_entrypoint_21(arg0, D_808003B0_cheggfire);
}

OSThread *cheggfire_entrypoint_0(void)
{
    extern ActorData D_808003BC_cheggfire[];

    return (OSThread *) D_808003BC_cheggfire;
}

/* extern */

void *cheggfire_entrypoint_1(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 _suegg_entrypoint_1(void *, f32);
    void *_suegg_entrypoint_11(s32, s32, s32);
    s32 _sueggmove_entrypoint_10(BtIntPtr);
    s32 _sueggmove_entrypoint_5(void *, s32);
    s32 _sueggmove_entrypoint_6(void *, f32, f32);
    s32 _sueggmove_entrypoint_7(void *, BtIntPtr);
    Actor *temp_v0;

    _sueggmove_entrypoint_10(arg0);
    temp_v0 = _suegg_entrypoint_11(0x15B, arg1, arg3);
    temp_v0->scale = 0.134f;
    _suegg_entrypoint_1(temp_v0, 30.0f);
    _sueggmove_entrypoint_5(temp_v0, 1);
    _sueggmove_entrypoint_6(temp_v0, -2200.0f, -22000.0f);
    _sueggmove_entrypoint_7(temp_v0, arg2);
    temp_v0->unk70_10 = 2;
    return temp_v0;
}

/* extern */

void *cheggfire_entrypoint_2(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 _suegg_entrypoint_1(void *, f32);
    void *_suegg_entrypoint_11(s32, s32, s32);
    s32 _sueggmove_entrypoint_10(BtIntPtr);
    s32 _sueggmove_entrypoint_5(void *, s32);
    s32 _sueggmove_entrypoint_6(void *, f32, f32);
    s32 _sueggmove_entrypoint_7(void *, BtIntPtr);
    Actor *temp_v0;

    _sueggmove_entrypoint_10(arg0);
    temp_v0 = _suegg_entrypoint_11(0x15B, arg1, arg3);
    temp_v0->scale = 0.25f;
    _sueggmove_entrypoint_5(temp_v0, 0);
    _sueggmove_entrypoint_6(temp_v0, 0.0f, -100000.0f);
    _suegg_entrypoint_1(temp_v0, 30.0f);
    _sueggmove_entrypoint_7(temp_v0, arg2);
    temp_v0->unk70_10 = 1;
    return temp_v0;
}
/* data_to_c.py: from asm/data/overlays/ch/egg/fire.data.s */
void func_80105834(Actor*);
void _subaddiedraw25d_entrypoint_2();
void _suegg_entrypoint_2();
OSThread *_suegg_entrypoint_0(void);
void func_80107C2C();
s32 _suegg_entrypoint_17(Actor *arg0, s32 arg1, s32 arg2);
s32 D_808003B0_cheggfire[3] BT_DATA(4, overlays_ch_egg_fire, 0x0) = { 224, 192, 100 };
ActorData D_808003BC_cheggfire [1] BT_DATA(4, overlays_ch_egg_fire, 0xC) = { { 621, 347, 2497, 1, 0, (void (*)(struct Actor *))func_808000B8_cheggfire, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))_subaddiedraw25d_entrypoint_2, 0, 1065353216, 0, 0, 0, 4, (void (*)(struct Actor *))_suegg_entrypoint_2, (BtIntPtr)_suegg_entrypoint_0, 76, 0, (void (*)(struct Actor *))func_80800228_cheggfire, (void (*)(void *, long, void *, long, void *))func_80107C2C, -30720, 0, (void (*)(struct Actor *, long, long))_suegg_entrypoint_17, 0 } };
