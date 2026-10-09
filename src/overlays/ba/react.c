#include "common.h"

s32 bareact_entrypoint_0() 
{
    return 0x4;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/react/bareact_entrypoint_1.s")

u8 bareact_entrypoint_2(void *arg0) {
    return (*(u8 *)((s8 *)(*(*(void ***)((s8 *)(arg0) + (0xEC)))) + (1)));
}

f32 bareact_entrypoint_3(void *arg0) {
    return (*(f32 *)((s8 *)(*(*(void ***)((s8 *)(arg0) + (0xEC)))) + (4)));
}

f32 bareact_entrypoint_4(void *arg0) {
    return (*(f32 *)((s8 *)(*(*(void ***)((s8 *)(arg0) + (0xEC)))) + (0xC)));
}

f32 bareact_entrypoint_5(void *arg0) {
    return (*(f32 *)((s8 *)(*(*(void ***)((s8 *)(arg0) + (0xEC)))) + (8)));
}
