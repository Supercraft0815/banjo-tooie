#include "common.h"

s32 bareact_entrypoint_0() 
{
    return 0x4;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/react/bareact_entrypoint_1.s")

u8 bareact_entrypoint_2(void *arg0) {
    return (*(u8 *)((s8 *)(*(*(void ***)((s8 *)(arg0) + (0xEC)))) + (1)));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/react/bareact_entrypoint_3.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/react/bareact_entrypoint_4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/react/bareact_entrypoint_5.s")
