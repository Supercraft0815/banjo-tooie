#include "common.h"

void func_80800000_chegggolden(Actor *arg0) {
    BtIntPtr _fxegg_entrypoint_6(f32 arg0[3], f32 arg1, f32 arg2[3]);
    s32 func_800A946C(void);
    f32 func_800D8FF8(void);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EFA20(void *, void *, f32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    void *func_80100094(Actor *, u32);
    f32 *temp_s0;
    f32 *temp_s1;
    f32 sp64[3];
    f32 sp58[3];
    f32 temp_f20;

    temp_s1 = func_80100094(arg0, 0);
    if (func_800A946C() < 3) {
        func_800EFA20(sp64, &arg0->actorData[4], 0.5f);
        temp_s1[10] -= func_800D8FF8();
        temp_f20 = func_800F10B4(temp_s1[12], 0, 1.8f, 0.0333f, 0.1f);
        temp_s0 = arg0->position;
        if (temp_s1[10] <= 0.0f) {
            do {
                temp_s1[10] += temp_f20;
                func_800EE7F8(sp58, temp_s0);
                _fxegg_entrypoint_6(temp_s0, arg0->scale, sp64);
            } while (temp_s1[10] <= 0.0f);
        }
    }
}

void func_80800110_chegggolden(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    int func_800EEEA8(f32 *);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    void func_800C4140(u32, f32 *, u32);
    s32 _suegg_entrypoint_8(void *);
    s32 _suegg_entrypoint_12(void *);
    s32 _suegg_entrypoint_13(void *);
    s32 _suegg_entrypoint_14(void *);
    void _suegg_entrypoint_16(void *);
    void _suegg_entrypoint_3(void *);
    void _sueggmisc_entrypoint_1(void *);
    u8 _sueggmove_entrypoint_3(Actor *arg0);
    struct GoldenData {
        u8 pad[0x30];
        f32 time;
        u8 pad34[5];
        BT_BITFIELD_ORDER(u8 flag : 1, u8 rest : 7);
        BT_BITFIELD_ORDER(u8 rest : 7, u8 flag : 1);
    } *data;

    data = func_80100094(arg0, 0);
    switch ((u32)arg0->unk70_10) {
        case 1:
            if (_suegg_entrypoint_8(arg0) == 0) {
                if (func_800EEEA8((f32 *)&arg0->actorData[4]) != 0) {
                    data->flag = 1;
                } else {
                    func_80800000_chegggolden(arg0);
                    _suegg_entrypoint_16(arg0);
                    if (_suegg_entrypoint_14(arg0) != 0) {
                        data->flag = 1;
                    }
                }
            }
            break;
        case 2:
            if (_suegg_entrypoint_8(arg0) == 0) {
                arg0->scale = func_800F10B4(data->time, 0.0f, 0.134f, 0.1f, 0.25f);
                if (_sueggmove_entrypoint_3(arg0) != 0) {
                    func_800C4140(0x7FEBBC18, arg0->position, 0x04B000FA);
                }
                if (_suegg_entrypoint_13(arg0) != 0) {
                    data->flag = 1;
                } else if (_suegg_entrypoint_12(arg0) != 0) {
                    _sueggmisc_entrypoint_1(arg0);
                } else {
                    func_80800000_chegggolden(arg0);
                    _suegg_entrypoint_16(arg0);
                }
            }
            break;
    }
    if (data->flag) {
        _suegg_entrypoint_3(arg0);
    }
}

OSThread *chegggolden_entrypoint_0(void)
{
    extern ActorData D_808003F0_chegggolden[];

    return (OSThread *) D_808003F0_chegggolden;
}

/* extern */

void *chegggolden_entrypoint_1(BT_NATIVE_ONLY(f32 *) BT_IDO_ONLY(s32) arg0, BT_NATIVE_ONLY(f32 *) BT_IDO_ONLY(BtIntPtr) arg1, BT_NATIVE_ONLY(f32 *) BT_IDO_ONLY(s32) arg2, s32 arg3) {
    void _suegg_entrypoint_1(Actor *arg0, f32 arg1);
    Actor *_suegg_entrypoint_11(u32 arg0, f32 *arg1, s32 arg2);
    BT_NATIVE_ONLY(void *) BT_IDO_ONLY(s32) _sueggmove_entrypoint_10(BT_NATIVE_ONLY(f32 *) BT_IDO_ONLY(BtIntPtr) BT_PASS2(, f32 *));
    void _sueggmove_entrypoint_5(Actor *arg0, s32 arg1);
    void _sueggmove_entrypoint_6(void *arg0, f32 arg1, f32 arg2);
    BT_NATIVE_ONLY(void) BT_IDO_ONLY(s32) _sueggmove_entrypoint_7(BT_NATIVE_ONLY(Actor *) BT_IDO_ONLY(void *), BT_NATIVE_ONLY(f32 *) BT_IDO_ONLY(BtIntPtr));
    Actor *temp_v0;

    _sueggmove_entrypoint_10(arg0 BT_PASS2(, arg1));
    temp_v0 = _suegg_entrypoint_11(0x15F, arg1, arg3);
    temp_v0->scale = 0.134f;
    _suegg_entrypoint_1(temp_v0, 30.0f);
    _sueggmove_entrypoint_5(temp_v0, 1);
    _sueggmove_entrypoint_6(temp_v0, -2200.0f, -22000.0f);
    _sueggmove_entrypoint_7(temp_v0, arg2);
    temp_v0->unk70_10 = 2;
    return temp_v0;
}

/* extern */

void *chegggolden_entrypoint_2(BT_NATIVE_ONLY(f32 *) BT_IDO_ONLY(s32) arg0, BT_NATIVE_ONLY(f32 *) BT_IDO_ONLY(BtIntPtr) arg1, BT_NATIVE_ONLY(f32 *) BT_IDO_ONLY(s32) arg2, s32 arg3) {
    void _suegg_entrypoint_1(Actor *arg0, f32 arg1);
    Actor *_suegg_entrypoint_11(u32 arg0, f32 *arg1, s32 arg2);
    BT_NATIVE_ONLY(void *) BT_IDO_ONLY(s32) _sueggmove_entrypoint_10(BT_NATIVE_ONLY(f32 *) BT_IDO_ONLY(BtIntPtr) BT_PASS2(, f32 *));
    void _sueggmove_entrypoint_5(Actor *arg0, s32 arg1);
    void _sueggmove_entrypoint_6(void *arg0, f32 arg1, f32 arg2);
    BT_NATIVE_ONLY(void) BT_IDO_ONLY(s32) _sueggmove_entrypoint_7(BT_NATIVE_ONLY(Actor *) BT_IDO_ONLY(void *), BT_NATIVE_ONLY(f32 *) BT_IDO_ONLY(BtIntPtr));
    Actor *temp_v0;

    _sueggmove_entrypoint_10(arg0 BT_PASS2(, arg1));
    temp_v0 = _suegg_entrypoint_11(0x15F, arg1, arg3);
    temp_v0->scale = 0.25f;
    _sueggmove_entrypoint_5(temp_v0, 0);
    _sueggmove_entrypoint_6(temp_v0, 0.0f, -100000.0f);
    _suegg_entrypoint_1(temp_v0, 30.0f);
    _sueggmove_entrypoint_7(temp_v0, arg2);
    temp_v0->unk70_10 = 1;
    return temp_v0;
}
/* data_to_c.py: from asm/data/overlays/ch/egg/golden.data.s */
void func_80105834(Actor*);
void _subaddiedraw25d_entrypoint_2();
void _suegg_entrypoint_2();
OSThread *_suegg_entrypoint_0(void);
void _suegg_entrypoint_5();
void func_80107C2C();
s32 _suegg_entrypoint_17(Actor *arg0, s32 arg1, s32 arg2);
ActorData D_808003F0_chegggolden [1] BT_DATA(4, overlays_ch_egg_golden, 0x0) = { { 620, 351, 2499, 1, 0, (void (*)(struct Actor *))func_80800110_chegggolden, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))_subaddiedraw25d_entrypoint_2, 0, 1065353216, 0, 0, 0, 4, (void (*)(struct Actor *))_suegg_entrypoint_2, (BtIntPtr)_suegg_entrypoint_0, 76, 0, (void (*)(struct Actor *))_suegg_entrypoint_5, (void (*)(void *, long, void *, long, void *))func_80107C2C, -30720, 0, (void (*)(struct Actor *, long, long))_suegg_entrypoint_17, 0 } };
