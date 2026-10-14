#include "common.h"

/* extern */

s32 plsu_entrypoint_0(f32 *arg0, f32 *arg1) {
    void func_800EE7F8(f32 *, f32 *);
    f32 func_800EEB40(f32 *, f32 *);
    s32 func_800F5898();
    void func_800F5A00(s32, f32 *);
    s32 func_800F6BE4(s32);
    f32 sp44[3];
    f32 temp_f0;
    f32 var_f20;
    s32 var_s0;
    s32 sp34;

    var_f20 = 3.4028235e38f;
    var_s0 = 0;
    if (func_800F5898() > 0) {
        do {
            if (func_800F6BE4(var_s0) != 0) {
                func_800F5A00(var_s0, sp44);
                temp_f0 = func_800EEB40(sp44, arg1);
                if (temp_f0 < var_f20) {
                    var_f20 = temp_f0;
                    sp34 = var_s0;
                    func_800EE7F8(arg0, sp44);
                }
            }
            var_s0 += 1;
        } while (var_s0 < func_800F5898());
    }
    return sp34;
}

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
