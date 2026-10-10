#include "common.h"

/* extern */

void func_800F9F90(s32 arg0, void *arg1) {
    s32 defrag(s32);
    s32 temp_a0;
    u32 temp_s1;
    u32 var_s0;

    var_s0 = arg0 + 8;
    temp_s1 = ((*(s32 *)((s8 *)(arg1) + (0x2C))) * 8) + arg0 + 8;
    if (var_s0 < temp_s1) {
        do {
            temp_a0 = (*(s32 *)((s8 *)(var_s0) + (4)));
            if (temp_a0 != 0) {
                (*(s32 *)((s8 *)(var_s0) + (4))) = defrag(temp_a0);
            }
            var_s0 += 8;
        } while (var_s0 < temp_s1);
    }
    defrag(arg0);
}
