#include "common.h"

u8 *func_800B26F0(u8 *arg0) {
    s32 temp_v1;

    temp_v1 = (*(s32 *)((s8 *)(arg0) + (0x28)));
    if (temp_v1 == 0) {
        return NULL;
    }
    return arg0 + temp_v1;
}

s32 func_800B270C(s16 *arg0) {
    return arg0[5];
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E8BFE0/func_800B2714.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E8BFE0/func_800B2720.s")

u8 *func_800B274C(u8 *arg0) {
    s32 temp_v1;

    temp_v1 = (*(s32 *)((s8 *)(arg0) + (0x24)));
    if (temp_v1 == 0) {
        return NULL;
    }
    return arg0 + temp_v1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E8BFE0/func_800B2768.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E8BFE0/func_800B2784.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E8BFE0/func_800B27A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E8BFE0/func_800B27BC.s")

f32 func_800B27D8(f32 *arg0) {
    return arg0[18];
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E8BFE0/func_800B27E0.s")

s32 func_800B27FC(s32 arg0) {
    arg0 += ((s16 *)arg0)[4];
    return arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E8BFE0/func_800B2808.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E8BFE0/func_800B2824.s")

s32 func_800B2840(s32 arg0) {
    arg0 += ((s32 *)arg0)[4];
    return arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E8BFE0/func_800B284C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E8BFE0/func_800B2868.s")
