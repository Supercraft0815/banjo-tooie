#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E44B60/func_8002D030.s")

s32 func_8002D328(u8 *arg0, s32 arg1, s32 arg2) {
    s32 func_8002CC9C(void *, s32, s32);
    f32 *value;

    value = (f32 *)&arg2;
    switch (arg1) {
        case 4:
            *(s16 *)(arg0 + 0x92) = 0;
            func_8002CC9C(arg0, 4, arg2);
            break;
        case 18:
            *(s16 *)(arg0 + 0x92) = arg2;
            *(s32 *)(arg0 + 0xB8) |= 2;
            break;
        case 19:
            *(s16 *)(arg0 + 0x90) = (s32)*value;
            *(s32 *)(arg0 + 0xB8) |= 2;
            break;
        case 17:
            *(s8 *)(arg0 + 0x8C) = arg2;
            break;
        default:
            func_8002CC9C(arg0, arg1, arg2);
            break;
    }
    return 0;
}
