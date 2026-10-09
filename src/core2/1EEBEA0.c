#include "common.h"

s32 func_801125B0() 
{
    return 0x10;
}

void func_801125B8(void *arg0) {
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x4C)))) + (0))) = 0.0f;
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x4C)))) + (4))) = 0.0f;
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x4C)))) + (8))) = 0.0f;
}

void func_801125D8(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 76) + 8) = arg1;
}

f32 func_801125E8(void *arg0) {
    return *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 76) + 12);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EEBEA0/func_801125F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EEBEA0/func_80112648.s")

f32 func_80112788(void *arg0) {
    return *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 76) + 8);
}
