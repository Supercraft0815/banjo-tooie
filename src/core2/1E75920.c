#include "core2/1E75920.h"

s32 func_8009C030() 
{
    return 0x30;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E75920/func_8009C038.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E75920/func_8009C08C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E75920/func_8009C0BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E75920/func_8009C0F8.s")

void func_8009C118(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 228) + 4) = arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E75920/func_8009C128.s")

f32 func_8009C150(PlayerState *arg0) {
    return (*(f32 **)((u8 *)arg0 + 0xE4))[1];
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E75920/func_8009C15C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E75920/func_8009C188.s")

void func_8009C1B4(void *arg0, f32 arg1) {
    void *temp_v0;

    temp_v0 = (*(void **)((s8 *)(arg0) + (0xE4)));
    (*(f32 *)((s8 *)(temp_v0) + (4))) = (f32) ((*(f32 *)((s8 *)(temp_v0) + (4))) + arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E75920/func_8009C1CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E75920/func_8009C1F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E75920/func_8009C21C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E75920/func_8009C25C.s")
