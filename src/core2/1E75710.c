#include "core2/1E75710.h"

s32 func_8009BE20() 
{
    return 0x10;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E75710/func_8009BE28.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E75710/func_8009BF04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E75710/func_8009BF34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E75710/func_8009BF5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E75710/func_8009BF8C.s")

void func_8009BFBC(void *arg0) {
    void *temp_v0;

    temp_v0 = (*(void **)((s8 *)(arg0) + (0xDC)));
    (*(f32 *)((s8 *)(temp_v0) + (0))) = (f32) (*(f32 *)((s8 *)(temp_v0) + (4)));
}

f32 func_8009BFCC(PlayerState *arg0) {
    return **(f32 **)((u8 *)arg0 + 0xDC);
}

f32 func_8009BFD8(PlayerState *arg0) {
    return (*(f32 **)((u8 *)arg0 + 0xDC))[1];
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E75710/func_8009BFE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E75710/func_8009C000.s")
