#include "core2/1ECD070.h"

/* extern */

f32 func_800F3780(f32 arg0, u8 *arg1, s16 arg2) {
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    s32 temp_v0;
    s32 var_a0;
    s32 var_t0;
    s32 var_v0;
    f32 *temp_v0_3;
    f32 *temp_v1;

    var_t0 = arg2 - 1;
    var_a0 = 0;
    if (arg0 < *(f32 *)arg1) {
        var_a0 = arg2 - 1;
        var_t0 = 0;
    } else if (*(f32 *)(arg2 * 8 + arg1 - 8) < arg0) {
        var_a0 = arg2 - 1;
        var_t0 = 0;
    } else if (var_t0 >= 2) {
        do {
            temp_v0 = ((s32) (var_t0 - var_a0) / 2) + var_a0;
            if (*(f32 *)(temp_v0 * 8 + arg1) <= arg0) {
                var_a0 = temp_v0;
                var_v0 = temp_v0 + 1;
            } else {
                var_t0 = temp_v0;
                var_v0 = var_a0 + 1;
            }
        } while (var_v0 < var_t0);
    }
    temp_v0_3 = (f32 *)(var_a0 * 8 + arg1);
    temp_v1 = (f32 *)(var_t0 * 8 + arg1);
    return func_800F10B4(arg0, temp_v0_3[0], temp_v1[0], temp_v0_3[1], temp_v1[1]);
}
