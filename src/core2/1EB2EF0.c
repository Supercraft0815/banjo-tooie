#include "common.h"

void func_800D9600(void *arg0, void *arg1) {
    (*(f32 *)((s8 *)(arg0) + (0))) = (f32) (*(f32 *)((s8 *)(arg1) + (0)));
    (*(f32 *)((s8 *)(arg0) + (4))) = (f32) (*(f32 *)((s8 *)(arg1) + (4)));
    (*(f32 *)((s8 *)(arg0) + (8))) = (f32) (*(f32 *)((s8 *)(arg1) + (8)));
    (*(f32 *)((s8 *)(arg0) + (0xC))) = (f32) (*(f32 *)((s8 *)(arg1) + (0xC)));
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EB2EF0/func_800D9624.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EB2EF0/func_800D965C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EB2EF0/func_800D97E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EB2EF0/func_800D9888.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EB2EF0/func_800D9AD4.s")

void func_800D9C34(void *arg0) {
    (*(s32 *)((s8 *)(arg0) + (0))) = 0;
    (*(s32 *)((s8 *)(arg0) + (4))) = 0;
    (*(s32 *)((s8 *)(arg0) + (8))) = 0;
    (*(s32 *)((s8 *)(arg0) + (0xC))) = 0x3F800000;
}

int func_800D9C4C(f32 arg0[4]){
    return ((arg0[0] == 0.0f)
        && (arg0[1] == 0.0f)
        && (arg0[2] == 0.0f)
        && (arg0[3] == 1.0f));
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EB2EF0/func_800D9CE8.s")
