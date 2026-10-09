#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/id/glow/idglow_entrypoint_0.s")

void idglow_entrypoint_1(s32 arg0) 
{
}
void idglow_entrypoint_2(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    (*(f32 *)((s8 *)(arg0) + (0))) = 0.5f;
    (*(f32 *)((s8 *)(arg0) + (4))) = (f32) (((f32) arg1 + 1.0f) * 0.01f);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/id/glow/idglow_entrypoint_3.s")
