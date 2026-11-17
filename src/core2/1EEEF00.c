#include "core2/1EEEF00.h"

s32 func_80115610() 
{
    return 0x38;
}

void func_80115618(Actor *arg0, f32 arg1, f32 arg2) {
    typedef struct {
        f32 min;
        f32 max;
        f32 rate;
        s32 unkC;
        u8 enabled;
        u8 minEnabled;
        u8 maxEnabled;
        u8 pad13;
        f32 unk14;
        f32 unk18;
        u8 locked;
    } Limits;
    f32 func_80013728(f32);
    f32 func_80013A7C(f32);
    f32 func_800EEAA4(f32 *, f32 *);
    void func_800EF2A0(f32 *);
    void func_800EF3DC(f32 *, f32 *);
    f32 func_800F1DCC(f32, f32);
    void func_800F5680(s32, f32 *);
    s32 func_800F6C5C(BtIntPtr);
    void func_801107B0(void *, f32 *);
    void func_801107F0(void *, f32 *);
    s32 func_80110840(s32 *);
    extern f32 D_80126610;
    f32 sp54[3];
    f32 sp48[3];
    f32 angle;
    f32 dot;
    s32 sp3C;
    f32 min;
    f32 sp2C[3];

    sp3C = func_80110840((s32 *)arg0);
    if (func_800F6C5C(sp3C)) {
        func_800F5680(sp3C, sp54);
        if (D_80126610 < sp54[1]) {
            func_801107B0(arg0, sp48);
            func_801107F0(arg0, sp2C);
            func_800EF3DC(sp48, sp2C);
            func_800EF2A0(sp48);
            dot = func_800EEAA4(sp48, sp54);
            angle = func_800F1DCC(90.0f, func_80013A7C(dot));
            angle = func_80013728(arg1 + angle + arg2);
            if (((Limits *)arg0->unk3C)->minEnabled) {
                if (((Limits *)arg0->unk3C)->min < angle) {
                    ((Limits *)arg0->unk3C)->min = angle;
                }
            } else {
                ((Limits *)arg0->unk3C)->min = angle;
                ((Limits *)arg0->unk3C)->minEnabled = 1;
            }
            if (((Limits *)arg0->unk3C)->maxEnabled) {
                min = ((Limits *)arg0->unk3C)->min;
                if (((Limits *)arg0->unk3C)->max < min) {
                    ((Limits *)arg0->unk3C)->max = min;
                }
            }
        }
    }
}

f32 func_80115750(Actor *arg0, f32 arg1) {
    typedef struct {
        f32 min;
        f32 max;
        f32 rate;
        s32 unkC;
        u8 enabled;
        u8 minEnabled;
        u8 maxEnabled;
        u8 pad13;
        f32 unk14;
        f32 unk18;
        u8 locked;
    } Limits;
    f32 func_800F1DCC(f32, f32);
    void func_80115618(Actor *, f32, f32);
    f32 savedMin;
    Limits *limits;
    f32 min;
    f32 max;

    limits = (Limits *)arg0->unk3C;
    if (limits->enabled && !limits->locked) {
        func_80115618(arg0, arg1, limits->rate);
        limits = (Limits *)arg0->unk3C;
    }
    min = limits->min;
    max = limits->max;
    if (limits->minEnabled) {
        savedMin = min;
        if (func_800F1DCC(arg1, min) < 0.0f) {
            arg1 = savedMin;
        }
    }
    if (((Limits *)arg0->unk3C)->maxEnabled && func_800F1DCC(max, arg1) < 0.0f) {
        arg1 = max;
    }
    return arg1;
}

void func_80115828(void *arg0, f32 arg1, f32 arg2) {
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x3C)))) + (0))) = arg1;
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x3C)))) + (4))) = arg2;
    (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x3C)))) + (0x11))) = 1;
    (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x3C)))) + (0x12))) = 1;
}

void func_80115858(void *arg0, s32 arg1) {
    *(s32 *)((u8 *)*(void **)((u8 *)arg0 + 60) + 12) = arg1;
}    typedef struct { u8 pad0[0x3C]; void * unk3C; } Obj1EEEF00_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

void func_80115864(void *arg0, s32 arg1) {
    *(s8 *)((u8 *)*&((Obj1EEEF00_arg0 *)arg0)->unk3C + 28) = arg1;
}

void func_80115870(void *arg0, f32 arg1) {
    if (arg1 == 0.0f) {
        (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x3C)))) + (0x10))) = 0;
    } else {
        (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x3C)))) + (0x10))) = 1;
    }
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x3C)))) + (8))) = arg1;
}

void func_801158B0(void *arg0, f32 arg1, f32 arg2) {
    (*(f32 *)((s8 *)((((Obj1EEEF00_arg0 *)arg0)->unk3C)) + (0x14))) = arg1;
    (*(f32 *)((s8 *)((((Obj1EEEF00_arg0 *)arg0)->unk3C)) + (0x18))) = arg2;
}

void func_801158CC(PlayerState* arg0, f32* arg1)
{
    func_80112550(arg0, arg1);
}

void func_801158EC(f32 arg0, f32 *arg1, f32 *arg2, f32 arg3, f32 arg4, f32 arg5) {
    f32 func_800136E4(f32);
    f32 func_800D8FF8();
    f32 func_800F1344(f32, f32, f32, f32, f32);
    f32 func_800F1DCC(f32, f32);
    f32 mlAbsF(f32);
    f32 unused;
    f32 sp38;
    f32 acceleration;
    f32 sp30;
    f32 sp2C;
    f32 sp28;

    if (arg0 == *arg1) {
        *arg2 = 0.0f;
        return;
    }
    sp30 = func_800D8FF8();
    sp38 = func_800F1DCC(arg0, *arg1);
    if (mlAbsF(sp38) < arg5) {
        *arg2 = func_800F1344(sp38, 0.0f, arg5, 10.0f, arg4);
    } else {
        acceleration = arg3 * sp30;
        if (sp38 < 0.0f) {
            acceleration = -acceleration;
        }
        *arg2 += acceleration;
        if (*arg2 < 0.0f) {
            if (*arg2 < -arg4) {
                *arg2 = -arg4;
            }
        } else if (arg4 < *arg2) {
            *arg2 = arg4;
        }
    }
    sp2C = *arg2 * sp30;
    sp28 = mlAbsF(sp2C);
    if ((mlAbsF(sp38) < sp28) && ((sp2C * sp38) > 0.0f)) {
        *arg2 = 0.0f;
        sp2C = 0.0f;
        *arg1 = arg0;
    }
    *arg1 = func_800136E4(*arg1 + sp2C);
}

void func_80115A9C(void *arg0) {
    f32 func_800D8FF8(void);
    void func_800EFB24(void *, void *, void *);
    void func_800F1A88(f32 *, f32 *);
    void func_801107F0(void *, f32 *);
    void func_801160DC(PlayerState *, f32);
    f32 mlAbsF(f32);
    f32 position[3];
    f32 difference[3];
    f32 origin[3];
    f32 angles[2];
    s32 done;

    *((u8 *)(*(void **)((u8 *)arg0 + 0x3C)) + 0x12) = 0;
    ((u8 *)(*(void **)((u8 *)arg0 + 0x3C)))[0x11] = ((u8 *)(*(void **)((u8 *)arg0 + 0x3C)))[0x12];
    switch (*(s32 *)(((u8 *)(*(void **)((u8 *)arg0 + 0x3C))) + 0xC)) {
        case 1:
            func_80115828(arg0, *(f32 *)(((u8 *)(*(void **)((u8 *)arg0 + 0x3C))) + 0x14), *(f32 *)(((u8 *)(*(void **)((u8 *)arg0 + 0x3C))) + 0x18));
            break;
        case 2:
            func_80115828(arg0, -80.0f, 80.0f);
            break;
    }
    if (((u8 *)(*(void **)((u8 *)arg0 + 0x3C)))[0x1D]) {
        *(f32 *)((u8 *)(*(void **)((u8 *)arg0 + 0x3C)) + 0x2C) += func_800D8FF8();
        func_801158CC(arg0, position);
        func_801107F0(arg0, origin);
        func_800EFB24(difference, origin, position);
        func_800F1A88(difference, angles);
            if (*(f32 *)(((u8 *)(*(void **)((u8 *)arg0 + 0x3C))) + 0x30) < *(f32 *)(((u8 *)(*(void **)((u8 *)arg0 + 0x3C))) + 0x2C)) {
            angles[0] = *(f32 *)(((u8 *)(*(void **)((u8 *)arg0 + 0x3C))) + 0x20);
        }
        done = mlAbsF(*(f32 *)((u8 *)(*(void **)((u8 *)arg0 + 0x3C)) + 0x20) - angles[0]) < 1.0f;
            func_80115828(arg0, *(f32 *)(((u8 *)(*(void **)((u8 *)arg0 + 0x3C))) + 0x24), *(f32 *)(((u8 *)(*(void **)((u8 *)arg0 + 0x3C))) + 0x20));
            func_801158EC(*(f32 *)(((u8 *)(*(void **)((u8 *)arg0 + 0x3C))) + 0x20), (f32 *)(((u8 *)(*(void **)((u8 *)arg0 + 0x3C))) + 0x24), (f32 *)(((u8 *)(*(void **)((u8 *)arg0 + 0x3C))) + 0x28), 800.0f, 160.0f, 100.0f);
        func_801160DC(arg0, 0.0f);
        if (done) {
            *((u8 *)(*(void **)((u8 *)arg0 + 0x3C)) + 0x1D) = 0;
        }
    }
}    typedef struct { f32 unk0; f32 unk4; u8 pad8[0x9]; u8 unk11; u8 unk12; } Obj1EEEF00_func_80115C40_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

void func_80115C40(void *arg0, f32 arg1) {
    f32 temp_f0;
    void *temp_v0;

    temp_v0 = (((Obj1EEEF00_arg0 *)arg0)->unk3C);
    if (((((Obj1EEEF00_func_80115C40_temp_v0 *)temp_v0)->unk11) == 0) || !(arg1 < (((Obj1EEEF00_func_80115C40_temp_v0 *)temp_v0)->unk0))) {
        if ((((Obj1EEEF00_func_80115C40_temp_v0 *)temp_v0)->unk12) != 0) {
            temp_f0 = (((Obj1EEEF00_func_80115C40_temp_v0 *)temp_v0)->unk4);
            if (temp_f0 < arg1) {
                arg1 = temp_f0;
            }
        }
        (((Obj1EEEF00_func_80115C40_temp_v0 *)temp_v0)->unk0) = arg1;
        (*(u8 *)((s8 *)((((Obj1EEEF00_arg0 *)arg0)->unk3C)) + (0x11))) = 1U;
    }
}    typedef struct { f32 unk0; f32 unk4; u8 pad8[0x9]; u8 unk11; u8 unk12; } Obj1EEEF00_func_80115CA4_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

void func_80115CA4(void *arg0, f32 arg1) {
    f32 temp_f0;
    void *temp_v0;

    temp_v0 = (((Obj1EEEF00_arg0 *)arg0)->unk3C);
    if (((((Obj1EEEF00_func_80115CA4_temp_v0 *)temp_v0)->unk12) == 0) || !((((Obj1EEEF00_func_80115CA4_temp_v0 *)temp_v0)->unk4) < arg1)) {
        if ((((Obj1EEEF00_func_80115CA4_temp_v0 *)temp_v0)->unk11) != 0) {
            temp_f0 = (((Obj1EEEF00_func_80115CA4_temp_v0 *)temp_v0)->unk0);
            if (arg1 < temp_f0) {
                arg1 = temp_f0;
            }
        }
        (((Obj1EEEF00_func_80115CA4_temp_v0 *)temp_v0)->unk4) = arg1;
        (*(u8 *)((s8 *)((((Obj1EEEF00_arg0 *)arg0)->unk3C)) + (0x12))) = 1U;
    }
}

void func_80115D08(void *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4) {
    f32 func_800136E4(f32);
    f32 func_80013B7C(f32, f32);
    f32 sp24;
    f32 temp_f0;
    f32 var_f14;
    f32 var_f12;
    f32 sp1C;

    temp_f0 = func_80013B7C(arg3, arg2);
    if (arg4 >= 0.0f) {
        var_f12 = temp_f0;
        var_f14 = temp_f0 + arg4;
    } else {
        var_f12 = temp_f0 + arg4;
        var_f14 = temp_f0 - arg4;
    }
    sp24 = var_f14;
    sp1C = func_800136E4(var_f12);
    func_801158B0(arg0, sp1C, func_800136E4(sp24));
}

void func_80115D88(PlayerState *arg0) { void func_801107F0(void *, f32 *); void func_800EFB24(void *, void *, void *); f32 sp34[3]; f32 sp28[3]; f32 sp1C[3]; func_801107F0(arg0, sp34); func_801158CC(arg0, sp1C); func_800EFB24(sp28, sp34, sp1C); func_800F1884(sp28, (u8 *)arg0->state_timer + 0x24); (*(f32 *)((s8 *)(arg0->state_timer) + 0x28)) = 0.0f; }    typedef struct { u8 pad0[0x1D]; u8 unk1D; u8 pad1E[0x2]; f32 unk20; f32 unk24; } Obj1EEEF00_func_80115DEC_var_v0; /* offsets.py genstruct: fields from raw offsets on var_v0; rename once understood */

void func_80115DEC(PlayerState *arg0, f32 arg1, f32 arg2) {
    f32 func_800F1DCC(f32, f32);
    f32 mlAbsF(f32);
    extern f32 D_80126614;
    void *var_v0;

    var_v0 = (*(void **)((s8 *)(arg0) + (0x3C)));
    if ((((Obj1EEEF00_func_80115DEC_var_v0 *)var_v0)->unk1D) == 0) {
        func_80115D88(arg0);
        var_v0 = (*(void **)((s8 *)(arg0) + (0x3C)));
    }
    (((Obj1EEEF00_func_80115DEC_var_v0 *)var_v0)->unk20) = arg1;
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x3C)))) + (0x2C))) = 0.0f;
    var_v0 = (*(void **)((s8 *)(arg0) + (0x3C)));
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x3C)))) + (0x30))) = (f32) ((mlAbsF(func_800F1DCC((((Obj1EEEF00_func_80115DEC_var_v0 *)var_v0)->unk20), (((Obj1EEEF00_func_80115DEC_var_v0 *)var_v0)->unk24))) * D_80126614) / arg2);
    (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x3C)))) + (0x1D))) = 1;
}

f32 func_80115E88(void *arg0) {
    return *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 60) + 24);
}
