#include "common.h"

s32 func_800B0D50(s16 *arg0) {
    return arg0[0];
}

s32 func_800B0D58(s16 *arg0) {
    return arg0[1];
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E8A640/func_800B0D60.s")

void *func_800B0D6C(void *arg0, s32 arg1) {
    return (u8 *)arg0 + (arg1 * 8) + 0xC;
}
