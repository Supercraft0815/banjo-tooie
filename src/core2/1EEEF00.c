#include "core2/1EEEF00.h"

s32 func_80115610() 
{
    return 0x38;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EEEF00/func_80115618.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EEEF00/func_80115750.s")

void func_80115828(void *arg0, f32 arg1, f32 arg2) {
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x3C)))) + (0))) = arg1;
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x3C)))) + (4))) = arg2;
    (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x3C)))) + (0x11))) = 1;
    (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x3C)))) + (0x12))) = 1;
}

void func_80115858(void *arg0, s32 arg1) {
    *(s32 *)((u8 *)*(void **)((u8 *)arg0 + 60) + 12) = arg1;
}

void func_80115864(void *arg0, s32 arg1) {
    *(s8 *)((u8 *)*(void **)((u8 *)arg0 + 60) + 28) = arg1;
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
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x3C)))) + (0x14))) = arg1;
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x3C)))) + (0x18))) = arg2;
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

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EEEF00/func_80115A9C.s")

void func_80115C40(void *arg0, f32 arg1) {
    f32 temp_f0;
    void *temp_v0;

    temp_v0 = (*(void **)((s8 *)(arg0) + (0x3C)));
    if (((*(u8 *)((s8 *)(temp_v0) + (0x11))) == 0) || !(arg1 < (*(f32 *)((s8 *)(temp_v0) + (0))))) {
        if ((*(u8 *)((s8 *)(temp_v0) + (0x12))) != 0) {
            temp_f0 = (*(f32 *)((s8 *)(temp_v0) + (4)));
            if (temp_f0 < arg1) {
                arg1 = temp_f0;
            }
        }
        (*(f32 *)((s8 *)(temp_v0) + (0))) = arg1;
        (*(u8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x3C)))) + (0x11))) = 1U;
    }
}

void func_80115CA4(void *arg0, f32 arg1) {
    f32 temp_f0;
    void *temp_v0;

    temp_v0 = (*(void **)((s8 *)(arg0) + (0x3C)));
    if (((*(u8 *)((s8 *)(temp_v0) + (0x12))) == 0) || !((*(f32 *)((s8 *)(temp_v0) + (4))) < arg1)) {
        if ((*(u8 *)((s8 *)(temp_v0) + (0x11))) != 0) {
            temp_f0 = (*(f32 *)((s8 *)(temp_v0) + (0)));
            if (arg1 < temp_f0) {
                arg1 = temp_f0;
            }
        }
        (*(f32 *)((s8 *)(temp_v0) + (4))) = arg1;
        (*(u8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x3C)))) + (0x12))) = 1U;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EEEF00/func_80115D08.s")

void func_80115D88(PlayerState *arg0) { void func_801107F0(void *, f32 *); void func_800EFB24(void *, void *, void *); f32 sp34[3]; f32 sp28[3]; f32 sp1C[3]; func_801107F0(arg0, sp34); func_801158CC(arg0, sp1C); func_800EFB24(sp28, sp34, sp1C); func_800F1884(sp28, (u8 *)arg0->state_timer + 0x24); (*(f32 *)((s8 *)(arg0->state_timer) + 0x28)) = 0.0f; }

void func_80115DEC(PlayerState *arg0, f32 arg1, f32 arg2) {
    f32 func_800F1DCC(f32, f32);
    f32 mlAbsF(f32);
    extern f32 D_80126614;
    void *var_v0;

    var_v0 = (*(void **)((s8 *)(arg0) + (0x3C)));
    if ((*(u8 *)((s8 *)(var_v0) + (0x1D))) == 0) {
        func_80115D88(arg0);
        var_v0 = (*(void **)((s8 *)(arg0) + (0x3C)));
    }
    (*(f32 *)((s8 *)(var_v0) + (0x20))) = arg1;
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x3C)))) + (0x2C))) = 0.0f;
    var_v0 = (*(void **)((s8 *)(arg0) + (0x3C)));
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x3C)))) + (0x30))) = (f32) ((mlAbsF(func_800F1DCC((*(f32 *)((s8 *)(var_v0) + (0x20))), (*(f32 *)((s8 *)(var_v0) + (0x24))))) * D_80126614) / arg2);
    (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x3C)))) + (0x1D))) = 1;
}

f32 func_80115E88(void *arg0) {
    return *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 60) + 24);
}
