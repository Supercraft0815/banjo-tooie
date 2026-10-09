#include "common.h"

void func_8001E2A0()
{
    func_8001DA60(func_80014F00());
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E35DD0/func_8001E2C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E35DD0/func_8001E304.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E35DD0/func_8001E34C.s")

void func_8001E380()
{
    func_8001E2A0();
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E35DD0/func_8001E3A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E35DD0/func_8001E3E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E35DD0/func_8001E418.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E35DD0/func_8001E44C.s")

void func_8001E490(void) {
    osDestroyThread(NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E35DD0/func_8001E4B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E35DD0/func_8001E578.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E35DD0/func_8001E5DC.s")

s32 func_8001E7A0(s32 arg0) {
    extern s32 D_8007E95C[];
    return ((s32 *)&D_8007E95C)[arg0];
}

void func_8001E7B4(s32 arg0) {
    extern s16 D_8007DB80;

    D_8007DB80 = arg0;
}

s16 func_8001E7C0(void) {
    extern s16 D_8007DB80;

    return D_8007DB80;
}

s32 func_8001E7CC(void) {
    extern s32 D_8007E948;

    return D_8007E948;
}
