#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/pl/su/plsu_entrypoint_0.s")

/* extern */

s32 plsu_entrypoint_1(s32 arg0) {
    s32 func_800F5410(s32);
    s32 func_800F5898();
    s32 func_800F6BE4(s32);
    s32 var_s0;

    var_s0 = 0;
    if (func_800F5898() > 0) {
loop_1:
        if ((func_800F6BE4(var_s0) != 0) && (func_800F5410(var_s0) == arg0)) {
            return var_s0;
        }
        var_s0 += 1;
        if (var_s0 >= func_800F5898()) {
            goto block_5;
        }
        goto loop_1;
    }
block_5:
    return -1;
}

/* extern */

s32 plsu_entrypoint_2(void) {
    s32 plsu_entrypoint_1(s32);
    if (plsu_entrypoint_1(0xA) == -1) {
        return 0;
    }
    if (plsu_entrypoint_1(0xB) == -1) {
        return 0;
    }
    return 1;
}

/* extern */

s32 plsu_entrypoint_3(s32 arg0) {
    s32 func_800F55D0(s32);
    s32 func_800F5898();
    s32 func_800F6BE4(s32);
    s32 func_800F6C5C(s32);
    s32 var_s0;

    var_s0 = 0;
    if (func_800F5898() > 0) {
loop_1:
        if ((func_800F6BE4(var_s0) != 0) && (func_800F6C5C(var_s0) != 0) && (func_800F55D0(var_s0) == arg0)) {
            return var_s0;
        }
        var_s0 += 1;
        if (var_s0 >= func_800F5898()) {
            goto block_6;
        }
        goto loop_1;
    }
block_6:
    return -1;
}
