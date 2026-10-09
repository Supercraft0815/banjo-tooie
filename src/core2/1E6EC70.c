#include "core2/1E6EC70.h"

s32 func_80095380(void)
{
	return 0x18;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6EC70/func_80095388.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6EC70/func_800953E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6EC70/func_80095490.s")

/* extern */

s32 func_800954E8(void *arg0, s32 *arg1) {
    s32 func_800D3E40(s32);
    if (func_800D3E40(3) != 0) {
        *arg1 = 0;
    } else {
        *arg1 = (*(s32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x7C)))) + (0x10)));
    }
    return (*(s32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x7C)))) + (0x14)));
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6EC70/func_80095534.s")

s32 func_8009557C(PlayerState *arg0) {
    return ((u8 *) *(void **)((u8 *)arg0 + 0x7C))[0xC];
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6EC70/func_80095588.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6EC70/func_800955CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6EC70/func_8009561C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6EC70/func_800956B8.s")
