#include "core2/1E75620.h"

s32 func_8009BD30() 
{
    return 0x1;
}

void func_8009BD38(void *arg0, s32 arg1) {
    *(s8 *)((u8 *)*(void **)((u8 *)arg0 + 212) + 0) = arg1;
}

u32 func_8009BD44(void *arg0) {
    return *(u8 *)((u8 *)*(void **)((u8 *)arg0 + 212) + 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E75620/func_8009BD50.s")

void func_8009BD88(PlayerState *arg0) {
    func_8009BDAC(arg0, 0.6f);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E75620/func_8009BDAC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E75620/func_8009BDE4.s")
