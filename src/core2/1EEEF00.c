#include "core2/1EEEF00.h"

s32 func_80115610() 
{
    return 0x38;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EEEF00/func_80115618.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EEEF00/func_80115750.s")

void func_80115828(void *arg0, f32 arg1, f32 arg2) {
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x3C)))) + (0))) = arg1;
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x3C)))) + (4))) = arg2;
    (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x3C)))) + (0x11))) = 1;
    (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x3C)))) + (0x12))) = 1;
}

void func_80115858(void *arg0, s32 arg1) {
    *(s32 *)((u8 *)*(void **)((u8 *)arg0 + 60) + 12) = arg1;
}

void func_80115864(void *arg0, s32 arg1) {
    *(s8 *)((u8 *)*(void **)((u8 *)arg0 + 60) + 28) = arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EEEF00/func_80115870.s")

void func_801158B0(void *arg0, f32 arg1, f32 arg2) {
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x3C)))) + (0x14))) = arg1;
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x3C)))) + (0x18))) = arg2;
}

void func_801158CC(PlayerState* arg0, f32* arg1)
{
    func_80112550(arg0, arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EEEF00/func_801158EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EEEF00/func_80115A9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EEEF00/func_80115C40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EEEF00/func_80115CA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EEEF00/func_80115D08.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EEEF00/func_80115D88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EEEF00/func_80115DEC.s")

f32 func_80115E88(void *arg0) {
    return *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 60) + 24);
}
