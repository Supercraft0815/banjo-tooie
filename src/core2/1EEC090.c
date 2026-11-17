#include "core2/1EEC090.h"

s32 func_801127A0()
{
    return 0x24;
}

void func_801127A8(PlayerState* arg0, f32* arg1)
{
    func_80112550(arg0, arg1);
}

void func_801127C8(f32 arg0, f32 *arg1, f32 *arg2, f32 arg3, f32 arg4) {
    f32 func_800136E4(f32);
    f32 func_800D8FF8(void);
    f32 func_800F1DCC(f32, f32);
    f32 func_800FF060(f32, f32 *, f32, f32, f32, f32);
    f32 mlAbsF(f32);
    f32 sp2C;
    f32 sp28;
    f32 sp24;
    sp2C = func_800F1DCC(arg0, *arg1);
    sp28 = mlAbsF(sp2C);
    if (0.1f < sp28) {
        sp24 = func_800FF060(sp2C, arg2, 1000.0f, -560.0f, 75.0f, func_800D8FF8());
        if ((sp28 < mlAbsF(sp24)) && ((*arg2 * sp2C) > 0.0f)) {
            sp24 = sp2C;
            *arg2 = 0.0f;
        }
        *arg1 = func_800136E4(*arg1 + sp24);
        return;
    }
    *arg2 = 0.0f;
    *arg1 = arg0;
}

void func_801128D4(f32 arg0, f32 *arg1, f32 *arg2, f32 arg3, f32 arg4, f32 arg5) {
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

void func_80112A84(PlayerState *arg0) {
    f32 func_800D8FF8(void);
    void func_800EFB24(void *, void *, void *);
    void func_800F1A88(f32 *, f32 *);
    void func_801107F0(void *, f32 *);
    void func_801160DC(PlayerState *, f32);
    void func_80112D08(void *, s32, f32, f32);
    f32 mlAbsF(f32);
    s32 sp6C;
    f32 sp68;
    f32 sp64;
    f32 sp58[3];
    f32 sp4C[3];
    f32 sp40[3];
    f32 sp38[2];
    s32 sp34;

    if (*(s16 *)(*(u8 **)((u8 *)arg0 + 0x60) + 0xC) != 0) {
        sp6C = 5;
        *(f32 *)(*(u8 **)((u8 *)arg0 + 0x60) + 0x1C) += func_800D8FF8();
        func_801127A8(arg0, sp58);
        func_801107F0(arg0, sp40);
        func_800EFB24(sp4C, sp40, sp58);
        func_800F1A88(sp4C, sp38);
        if (*(f32 *)(*(u8 **)((u8 *)arg0 + 0x60) + 0x20) <
            *(f32 *)(*(u8 **)((u8 *)arg0 + 0x60) + 0x1C)) {
            sp38[1] = *(f32 *)(*(u8 **)((u8 *)arg0 + 0x60) + 0x10);
        }
        sp34 = mlAbsF(*(f32 *)(*(u8 **)((u8 *)arg0 + 0x60) + 0x10) - sp38[1]) < 1.0f;
        sp68 = *(f32 *)(*(u8 **)((u8 *)arg0 + 0x60) + 0x14);
        sp64 = *(f32 *)(*(u8 **)((u8 *)arg0 + 0x60) + 0x10);
        if (*(s16 *)(*(u8 **)((u8 *)arg0 + 0x60) + 0xC) == 1) {
            func_801127C8(*(f32 *)(*(u8 **)((u8 *)arg0 + 0x60) + 0x10),
                (f32 *)(*(u8 **)((u8 *)arg0 + 0x60) + 0x14),
                (f32 *)(*(u8 **)((u8 *)arg0 + 0x60) + 0x18), 50.0f, 3.0f);
            func_801160DC(arg0, 0.0f);
        } else {
            func_801128D4(*(f32 *)(*(u8 **)((u8 *)arg0 + 0x60) + 0x10),
                (f32 *)(*(u8 **)((u8 *)arg0 + 0x60) + 0x14),
                (f32 *)(*(u8 **)((u8 *)arg0 + 0x60) + 0x18), 800.0f, 160.0f, 100.0f);
            func_801160DC(arg0, 0.0f);
        }
        if (sp34 != 0) {
            *(s16 *)(*(u8 **)((u8 *)arg0 + 0x60) + 0xC) = 0;
            *(s16 *)(*(u8 **)((u8 *)arg0 + 0x60) + 0xE) = 0;
        }
    } else {
        sp6C = 0;
        sp64 = 0.0f;
        sp68 = 0.0f;
    }
    func_80112D08(arg0, sp6C, sp68, sp64);
}

f32 func_80112C3C(void *arg0, f32 arg1) {
    f32 func_800F1738(f32, f32, f32);
    f32 func_800F1DCC(f32, f32);
    switch (*(s32 *)((u8 *)(*(void **)((u8 *)arg0 + 0x60)) + 8)) {
        case 1:
        case 2:
        case 5:
            arg1 = func_800F1738(arg1, ((f32 *)(*(void **)((u8 *)arg0 + 0x60)))[0], ((f32 *)(*(void **)((u8 *)arg0 + 0x60)))[1]);
            break;
        case 3:
            if (func_800F1DCC(arg1, ((f32 *)(*(void **)((u8 *)arg0 + 0x60)))[0]) < 0.0f) {
                arg1 = ((f32 *)(*(void **)((u8 *)arg0 + 0x60)))[0];
            }
            break;
        case 4:
            if (func_800F1DCC(arg1, ((f32 *)(*(void **)((u8 *)arg0 + 0x60)))[0]) > 0.0f) {
                arg1 = ((f32 *)(*(void **)((u8 *)arg0 + 0x60)))[0];
            }
            break;
    }
    return arg1;
}

void func_80112D08(void *arg0, s32 arg1, f32 arg2, f32 arg3) {
    (*(s32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x60)))) + (8))) = arg1;
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x60)))) + (0))) = arg2;
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x60)))) + (4))) = arg3;
}

void func_80112D2C(PlayerState *arg0) {
    void func_800EFB24(void *arg0, void *arg1, void *arg2);
    s32 func_800F1EA4(f32[3], f32 *);
    void func_801107F0(void *, f32 *);
    f32 sp34[3];
    f32 sp28[3];
    f32 sp1C[3];

    func_801107F0(arg0, sp34);
    func_801127A8(arg0, sp1C);
    func_800EFB24(sp28, sp34, sp1C);
    func_800F1EA4(sp28, (*(u8 **)((s8 *)(arg0) + (0x60))) + 0x14);
    (*(f32 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x60)))) + (0x18))) = 0.0f;
}    typedef struct { u8 pad0[0xC]; s16 unkC; s16 unkE; f32 unk10; f32 unk14; } Obj1EEC090_func_80112D90_var_v0; /* offsets.py genstruct: fields from raw offsets on var_v0; rename once understood */

void func_80112D90(PlayerState *arg0, f32 arg1, f32 arg2, s32 arg3, s32 arg4) {
    f32 func_800F1DCC(f32, f32);
    f32 mlAbsF(f32);
    void *var_v0;

    var_v0 = (*(void **)((s8 *)(arg0) + (0x60)));
    if (arg4 >= (((Obj1EEC090_func_80112D90_var_v0 *)var_v0)->unkE)) {
        if (arg3 != (((Obj1EEC090_func_80112D90_var_v0 *)var_v0)->unkC)) {
            func_80112D2C(arg0);
            var_v0 = (*(void **)((s8 *)(arg0) + (0x60)));
        }
        (((Obj1EEC090_func_80112D90_var_v0 *)var_v0)->unk10) = arg1;
        (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x60)))) + (0x1C))) = 0.0f;
        var_v0 = (*(void **)((s8 *)(arg0) + (0x60)));
        (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x60)))) + (0x20))) = (f32) ((mlAbsF(func_800F1DCC((((Obj1EEC090_func_80112D90_var_v0 *)var_v0)->unk10), (((Obj1EEC090_func_80112D90_var_v0 *)var_v0)->unk14))) * 1.2f) / arg2);
        (*(s16 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x60)))) + (0xC))) = (s16) arg3;
        (*(s16 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x60)))) + (0xE))) = (s16) arg4;
    }
}    typedef struct { u8 pad0[0xC]; s16 unkC; s16 unkE; f32 unk10; f32 unk14; } Obj1EEC090_func_80112E50_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

void func_80112E50(void *arg0, f32 arg1, s32 arg2) {
    void *temp_v0;

    temp_v0 = (*(void **)((s8 *)(arg0) + (0x60)));
    if (((((Obj1EEC090_func_80112E50_temp_v0 *)temp_v0)->unkC) != 0) && (arg2 == (((Obj1EEC090_func_80112E50_temp_v0 *)temp_v0)->unkE))) {
        (((Obj1EEC090_func_80112E50_temp_v0 *)temp_v0)->unk10) = (f32) ((((Obj1EEC090_func_80112E50_temp_v0 *)temp_v0)->unk14) + arg1);
    }
}

s32 func_80112E84(void *arg0) {
    return *(s16 *)((u8 *)*(void **)((u8 *)arg0 + 96) + 12);
}
