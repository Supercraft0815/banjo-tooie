#include "common.h"

s32 func_80094E70(void)
{
	return 0x1C;
}

void func_80094E78()
{
    func_800964D0();
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6E760/func_80094E98.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6E760/func_80094EEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6E760/func_80094F14.s")

void func_80094F38(u8 *arg0) {
    s32 i;
    for (i = 0; i < 5; i++) {
        (*(u8 **)(arg0 + 0x74))[i] = 0;
    }
}
