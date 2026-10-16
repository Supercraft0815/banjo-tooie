#include "common.h"

s32 func_80114D90() 
{
    return 0x8;
}

void func_80114D98(void *arg0, s32 arg1) {
    s16 *temp_v1;
    s32 temp_v0;

    if ((arg1 == 0) || (arg1 == 1)) {
        temp_v0 = arg1 * 2;
        (*(s16 *)((s8 *)(((*(s32 *)((s8 *)(arg0) + (8))) + temp_v0)) + (4))) = 1;
        temp_v1 = (*(s32 *)((s8 *)(arg0) + (8))) + temp_v0;
        *temp_v1 += 1;
    }
}

void func_80114DD8(void *arg0) {
    void func_80112E50(void *, f32, s32);
    s16 *var_v0;

    var_v0 = *(s16 **)((u8 *)arg0 + 8);
    if (var_v0[2] == 0) {
        if (var_v0[0] >= 5) {
            func_80112E50(arg0, -5.0f, 2);
            var_v0 = *(s16 **)((u8 *)arg0 + 8);
        }
        var_v0[0] = 0;
        var_v0 = *(s16 **)((u8 *)arg0 + 8);
    }
    if (var_v0[3] == 0) {
        if (var_v0[1] >= 5) {
            func_80112E50(arg0, 5.0f, 2);
            var_v0 = *(s16 **)((u8 *)arg0 + 8);
        }
        var_v0[1] = 0;
        var_v0 = *(s16 **)((u8 *)arg0 + 8);
    }
    var_v0[3] = 0;
    var_v0 = *(s16 **)((u8 *)arg0 + 8);
    var_v0[2] = var_v0[3];
}
