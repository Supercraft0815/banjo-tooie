#include "common.h"

s32 func_80091E10(void)
{
	return 0x4;
}

void func_80091E18(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6B700/func_80091E20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6B700/func_80091E48.s")

void func_80091E6C(void *arg0) {
    void *temp_v0;

    temp_v0 = (*(void **)((s8 *)(arg0) + (0x48)));
    (*(u8 *)((s8 *)(temp_v0) + (3))) = (u8) ((*(u8 *)((s8 *)(temp_v0) + (3))) - 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6B700/func_80091E80.s")

s32 func_80091EA0(void)
{
	return 0x1;
}

void func_80091EA8(s32 arg0)
{
    func_80091F74(arg0,0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6B700/func_80091EC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6B700/func_80091EF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6B700/func_80091F30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6B700/func_80091F74.s")

/* extern */

s32 func_80091FE4(void) {
    s32 func_800DB9B0();
    return func_800DB9B0() == 0;
}
