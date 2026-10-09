#include "common.h"

s32 bapulse_entrypoint_0() 
{
    return 0xC;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/pulse/bapulse_entrypoint_1.s")

void bapulse_entrypoint_2(s32 arg0) 
{
}
void bapulse_entrypoint_3(void *arg0, f32 arg1, f32 arg2) {
    (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0xE8)))) + (0))) = 0;
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0xE8)))) + (8))) = arg1;
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0xE8)))) + (4))) = arg2;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/pulse/bapulse_entrypoint_4.s")
