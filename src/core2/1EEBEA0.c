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

int func_801125F4(s32 arg0) {
    struct player_state_s;
    struct player_state_s *func_800F53D0(s32);
    s32 func_8009BAF4(void *);
    s32 func_8009D2E4(void *);
    void *sp1C;
    int sp18;
    int temp_v0_2;
    int temp_v1;
    int var_v0;

    sp1C = func_800F53D0(arg0);
    sp18 = func_8009D2E4(sp1C);
    temp_v1 = func_8009BAF4(sp1C);
    return sp18 == 1 && temp_v1 == 2;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EEBEA0/func_80112648.s")

f32 func_80112788(void *arg0) {
    return *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 76) + 8);
}
