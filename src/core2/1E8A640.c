#include "common.h"

s32 func_800B0D50(s16 *arg0) {
    return arg0[0];
}

s32 func_800B0D58(s16 *arg0) {
    return arg0[1];
}

void *func_800B0D60(void *arg0)
{
    u8 *result = arg0;
    result += *(s32 *)(result + 8);
    return result;
}

void *func_800B0D6C(void *arg0, s32 arg1) {
    return (u8 *)arg0 + (arg1 * 8) + 0xC;
}
