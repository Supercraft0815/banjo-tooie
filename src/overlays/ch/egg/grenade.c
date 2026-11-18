#include "common.h"

void func_80800000_chegggrenade(Actor *arg0) {
    BtIntPtr _fxegg_entrypoint_5(f32 arg0[3], f32 arg1[3], f32 arg2);
    void _suegg_entrypoint_20(Actor *, f32 *);
    f32 func_800D8FF8(void);
    void func_800EE7F8(f32 *, f32 *);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    void *func_80100094(Actor *, u32);
    f32 *temp_s0;
    f32 *temp_s1;
    f32 sp64[3];
    f32 sp58[3];
    f32 temp_f22;

    temp_s1 = func_80100094(arg0, 0);
    temp_s1[10] -= func_800D8FF8();
    temp_f22 = func_800F10B4(temp_s1[12], 0, 2.0f, 0.0333f, 0.1f);
    _suegg_entrypoint_20(arg0, sp58);
    temp_s0 = arg0->position;
    if (temp_s1[10] <= 0.0f) {
        do {
            temp_s1[10] += temp_f22;
            func_800EE7F8(sp64, temp_s0);
            _fxegg_entrypoint_5(temp_s0, sp58, arg0->scale);
        } while (temp_s1[10] <= 0.0f);
    }
}    typedef struct { u8 pad0[0x24]; u32 unk24; } Objgrenade_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

/* extern */

void chegggrenade_entrypoint_0(void *arg0) {
    void _cheggsplode_entrypoint_1(Actor **arg0, s32 arg1, s32 arg2);
    s32 _gcegg_entrypoint_0(u32);
    void _suegg_entrypoint_4(Actor *arg0, s32 arg1);
    void *func_80100094(Actor *, u32);
    BtIntPtr func_80106790();
    BtIntPtr sp24;
    BtIntPtr temp_v0;
    s32 sp1C;

    temp_v0 = func_80106790();
    sp24 = temp_v0;
    sp1C = (s32) (*(s16 *)((s8 *)(func_80100094(temp_v0, 0)) + (0x3A)));
    _cheggsplode_entrypoint_1(&sp24, sp1C, _gcegg_entrypoint_0((u32) (((Objgrenade_arg0 *)arg0)->unk24) >> 0x16));
    _suegg_entrypoint_4(sp24, 0);
}

void func_80800164_chegggrenade(void *arg0) {
    void *func_80100094(Actor *, u32);
    int func_800EEEA8(f32 *);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    s32 _suegg_entrypoint_8(void *);
    s32 _suegg_entrypoint_12(void *);
    s32 _suegg_entrypoint_13(void *);
    s32 _suegg_entrypoint_14(void *);
    void _suegg_entrypoint_16(void *);
    void _suegg_entrypoint_23(void *);
    void _sueggmisc_entrypoint_1(void *);
    u8 _sueggmove_entrypoint_3(Actor *arg0);
    s32 _chbaddiesetup_entrypoint_1(s32 *, BtIntPtr);
#ifndef BT_NATIVE
    extern s32 _chegggrenade_entrypoint_0;
#endif
    struct GrenadeData {
        u8 pad[0x30];
        f32 time;
        u32 pad34;
        union {
            u32 value;
            struct {
                u8 pad38;
                u8 flag : 1;
                u8 rest : 7;
            } byte;
            struct {
                u32 pad : 9;
                u32 blocked : 1;
                u32 rest : 22;
            } word;
        } flags;
    };
    struct FlagData {
        u8 pad[0x39];
        u8 flag : 1;
        u8 rest : 7;
    } *data[1];

    data[0] = func_80100094(arg0, 0);
    switch ((u32)((Actor *)arg0)->unk70_10) {
    case 1:
        if (_suegg_entrypoint_8(arg0) == 0) {
            if (func_800EEEA8((f32 *)&((Actor *)arg0)->actorData[4]) != 0) {
                data[0]->flag = 1;
            } else {
                func_80800000_chegggrenade(arg0);
                _suegg_entrypoint_16(arg0);
                if (_suegg_entrypoint_14(arg0) != 0) {
                    data[0]->flag = 1;
                }
            }
        }
        break;
    case 2:
        if (_suegg_entrypoint_8(arg0) == 0) {
            ((Actor *)arg0)->scale = func_800F10B4(((struct GrenadeData *)data[0])->time, 0.0f, 0.134f, 0.1f, 0.25f);
            if (_sueggmove_entrypoint_3(arg0) != 0) {
                _suegg_entrypoint_23(arg0);
            }
            if (_suegg_entrypoint_13(arg0) != 0) {
                data[0]->flag = 1;
            } else if (_suegg_entrypoint_12(arg0) != 0) {
                _sueggmisc_entrypoint_1(arg0);
            } else {
                func_80800000_chegggrenade(arg0);
                _suegg_entrypoint_16(arg0);
            }
        }
        break;
    }
    if (data[0]->flag && !((struct GrenadeData *)data[0])->flags.word.blocked) {
        _chbaddiesetup_entrypoint_1(&_chegggrenade_entrypoint_0, (BtIntPtr)((Actor *)arg0)->unk0);
    }
}

OSThread *chegggrenade_entrypoint_1(void)
{
    extern ActorData D_80800450_chegggrenade[];

    return (OSThread *) D_80800450_chegggrenade;
}

/* extern */

void *chegggrenade_entrypoint_2(s32 arg0, BtIntPtr arg1, s32 arg2, s32 arg3) {
    void _suegg_entrypoint_1(Actor *arg0, f32 arg1);
    Actor *_suegg_entrypoint_11(u32 arg0, f32 *arg1, s32 arg2);
    s32 _sueggmove_entrypoint_10(BtIntPtr);
    void _sueggmove_entrypoint_5(Actor *arg0, s32 arg1);
    void _sueggmove_entrypoint_6(void *arg0, f32 arg1, f32 arg2);
    s32 _sueggmove_entrypoint_7(void *, BtIntPtr);
    Actor *temp_v0;

    _sueggmove_entrypoint_10(arg0);
    temp_v0 = _suegg_entrypoint_11(0x15D, arg1, arg3);
    temp_v0->scale = 0.134f;
    _suegg_entrypoint_1(temp_v0, 30.0f);
    _sueggmove_entrypoint_5(temp_v0, 1);
    _sueggmove_entrypoint_6(temp_v0, -2200.0f, -22000.0f);
    _sueggmove_entrypoint_7(temp_v0, arg2);
    temp_v0->unk70_10 = 2;
    return temp_v0;
}

/* extern */

void *chegggrenade_entrypoint_3(s32 arg0, BtIntPtr arg1, s32 arg2, s32 arg3) {
    void _suegg_entrypoint_1(Actor *arg0, f32 arg1);
    Actor *_suegg_entrypoint_11(u32 arg0, f32 *arg1, s32 arg2);
    s32 _sueggmove_entrypoint_10(BtIntPtr);
    void _sueggmove_entrypoint_5(Actor *arg0, s32 arg1);
    void _sueggmove_entrypoint_6(void *arg0, f32 arg1, f32 arg2);
    s32 _sueggmove_entrypoint_7(void *, BtIntPtr);
    Actor *temp_v0;

    _sueggmove_entrypoint_10(arg0);
    temp_v0 = _suegg_entrypoint_11(0x15D, arg1, arg3);
    temp_v0->scale = 0.25f;
    _sueggmove_entrypoint_5(temp_v0, 0);
    _sueggmove_entrypoint_6(temp_v0, 0.0f, -100000.0f);
    _suegg_entrypoint_1(temp_v0, 30.0f);
    _sueggmove_entrypoint_7(temp_v0, arg2);
    temp_v0->unk70_10 = 1;
    return temp_v0;
}
/* data_to_c.py: from asm/data/overlays/ch/egg/grenade.data.s */
void func_80105834(Actor*);
void _subaddiedraw25d_entrypoint_2();
void _suegg_entrypoint_2();
OSThread *_suegg_entrypoint_0(void);
void _suegg_entrypoint_5();
void func_80107C2C();
s32 _suegg_entrypoint_17(Actor *arg0, s32 arg1, s32 arg2);
ActorData D_80800450_chegggrenade [1] BT_DATA(4, overlays_ch_egg_grenade, 0x0) = { { 623, 349, 2498, 1, 0, (void (*)(struct Actor *))func_80800164_chegggrenade, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))_subaddiedraw25d_entrypoint_2, 0, 1065353216, 0, 0, 0, 4, (void (*)(struct Actor *))_suegg_entrypoint_2, (BtIntPtr)_suegg_entrypoint_0, 76, 0, (void (*)(struct Actor *))_suegg_entrypoint_5, (void (*)(void *, long, void *, long, void *))func_80107C2C, -30720, 0, (void (*)(struct Actor *, long, long))_suegg_entrypoint_17, 0 } };
