#include "common.h"

/* extern */

void func_80800000_bamovethrust(s32 arg0, f32 *arg1, f32 arg2) {
    void func_800EF4E4(f32[3], f32, f32, f32, f32, f32);
    f32 func_8009BFCC();
    f32 yaw_get(s32);
    f32 sp24;

    sp24 = func_8009BFCC();
    func_800EF4E4(arg1, sp24, yaw_get(arg0), 0.0f, 0.0f, arg2);
}

void bamovethrust_entrypoint_0(s32 arg0) 
{
}
void bamovethrust_entrypoint_1(void *arg0) {
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0xC8)))) + (0x8C))) = 1.0f;
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0xC8)))) + (0x84))) = 1.0f;
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0xC8)))) + (0x88))) = 1.0f;
}

void bamovethrust_entrypoint_2(void *arg0, f32 arg1) {
    func_80800000_bamovethrust((s32) arg0, (*(s32 *)((s8 *)(arg0) + (0xC8))) + 0x10, arg1);
}

void bamovethrust_entrypoint_3(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 200) + 140) = arg1;
}

void bamovethrust_entrypoint_4(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 200) + 132) = arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/move/thrust/bamovethrust_entrypoint_5.s")

f32 bamovethrust_entrypoint_6(void *arg0) {
    return *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 200) + 140);
}
