#include "common.h"

/* extern */

void gcwater_entrypoint_0(void) {
    s32 func_800AAD80(s32);
    s32 func_800B2720(s32);
    s32 func_800BEB28(s32);
    void func_800DA3B8(s32, s32);
    s32 var_a1;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 var_s0;

    var_s0 = 0;
    temp_v0 = func_800BEB28(1);
    if (temp_v0 != 0) {
        temp_v0_2 = func_800B2720(temp_v0);
        if (temp_v0_2 != 0) {
            var_s0 = func_800AAD80(temp_v0_2);
        }
    }
    if (var_s0 == 0) {
        temp_v0_3 = func_800BEB28(0);
        if (temp_v0_3 != 0) {
            temp_v0_4 = func_800B2720(temp_v0_3);
            if (temp_v0_4 != 0) {
                var_s0 = func_800AAD80(temp_v0_4);
            }
        }
    }
    var_a1 = var_s0 != 0 ? 1 : 0;
    func_800DA3B8(0x6B5, var_a1);
}
