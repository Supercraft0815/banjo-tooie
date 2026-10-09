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

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EEE680/func_80114DD8.s")
