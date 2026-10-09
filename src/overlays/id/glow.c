#include "common.h"

void idglow_entrypoint_0(s32 arg0, u8 *arg1, u8 *arg2, s32 arg3, f32 *arg4) {
    f32 scale = *arg4;
    u8 *end = arg1 + arg3 * 0x10;

    for (; arg1 < end; arg1 += 0x10, arg2 += 0x10) {
        arg2[12] = (u32)((f32)(u32)arg1[12] * scale);
        arg2[13] = (u32)((f32)(u32)arg1[13] * scale);
        arg2[14] = (u32)((f32)(u32)arg1[14] * scale);
    }
}

void idglow_entrypoint_1(s32 arg0) 
{
}
void idglow_entrypoint_2(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    (*(f32 *)((s8 *)(arg0) + (0))) = 0.5f;
    (*(f32 *)((s8 *)(arg0) + (4))) = (f32) (((f32) arg1 + 1.0f) * 0.01f);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/id/glow/idglow_entrypoint_3.s")
