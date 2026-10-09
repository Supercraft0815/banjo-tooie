#include "core2/1E7B250.h"

s32 func_800A1960() 
{
    return 0x10;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7B250/func_800A1968.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7B250/func_800A1F0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7B250/func_800A1F78.s")

void func_800A2018(PlayerState *arg0, s32 arg1) {
    u8 temp_v1;
    void *temp_v0;
    void *temp_v0_2;

    if (arg1 == -1) {
        temp_v0 = (*(void **)((s8 *)(arg0) + (0x108)));
        (*(u8 *)((s8 *)(temp_v0) + (0))) = (u8) (*(u8 *)((s8 *)(temp_v0) + (1)));
        return;
    }
    temp_v0_2 = (*(void **)((s8 *)(arg0) + (0x108)));
    temp_v1 = (*(u8 *)((s8 *)(temp_v0_2) + (0)));
    if (arg1 != temp_v1) {
        (*(u8 *)((s8 *)(temp_v0_2) + (1))) = temp_v1;
        (*(u8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x108)))) + (0))) = (u8) arg1;
    }
}

void func_800A2058(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7B250/func_800A2060.s")
