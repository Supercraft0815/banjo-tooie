#include "common.h"

/* extern */

void func_80800000_dbshift(s32 arg0, s32 *arg1, s32 arg2, s32 *arg3, void *arg4) {
    f32 func_800F2290(s32 *, s32 *);
    s32 func_800F2388(s32 *, s32, s32);
    f32 sp24;
    s32 sp1C[2];

    sp24 = func_800F2290(arg1, arg3);
    func_800F2388(sp1C, arg2, arg0);
    (*(f32 *)((s8 *)(arg4) + (0))) = (f32) (func_800F2290(sp1C, arg3) / sp24);
    (*(f32 *)((s8 *)(arg4) + (4))) = (f32) (func_800F2290(sp1C, arg1) / sp24);
}

s32 dbshift_entrypoint_0(s32 *arg0) {
    return arg0[0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/db/shift/dbshift_entrypoint_1.s")
