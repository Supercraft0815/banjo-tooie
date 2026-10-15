#include "common.h"

/* extern */

s32 func_80800000_fxripple(f32 arg0[3], s32 *arg1, void *arg2) {
    void *func_800FB2AC(f32 arg0[3], f32 arg1);
    s32 func_800FB338(void *, void *, s32 *, f32 *);
    f32 sp1C;

    *arg1 = 0;
    if (arg2 != 0) {
        arg0[1] += 1.0f;
    } else {
        arg2 = func_800FB2AC(arg0, 50.0f);
        if (arg2 == 0) {
            return 0;
        }
    }
    if (func_800FB338(arg0, arg2, arg1, &sp1C) != 0) {
        arg0[1] = sp1C;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/fx/ripple/func_80800094_fxripple.s")

void fxripple_entrypoint_0(s32 arg0, s32 arg1) {
    s32 temp_v0;
    temp_v0 = func_80800094_fxripple(arg0, arg1, 0);
    if (temp_v0 != 0) {
        func_800BA22C(temp_v0, 1);
    }
}

void fxripple_entrypoint_1(void) {
    s32 temp_v0;
    temp_v0 = func_80800094_fxripple();
    if (temp_v0 != 0) {
        func_800BA22C(temp_v0, 1);
    }
}

void fxripple_entrypoint_2(s32 arg0, s32 arg1) {
    func_80800094_fxripple(arg0, arg1, 0);
}

void fxripple_entrypoint_3()
{
    func_80800094_fxripple();
}

/* extern */

void fxripple_entrypoint_4(f32 arg0) {
    s32 func_800B5BE4(s32);
    s32 func_800BA5D0(s32, s16);
    func_800BA5D0(func_800B5BE4(3), (s16) (s32) arg0);
}
