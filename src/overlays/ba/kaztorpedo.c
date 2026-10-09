#include "common.h"

s32 bakaztorpedo_entrypoint_0() 
{
    return 0x20;
}

f32 bakaztorpedo_entrypoint_1(void *arg0) {
    return *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 176) + 16);
}

/* extern */

void bakaztorpedo_entrypoint_2(void *arg0) {
    s32 func_8009EA08(f32);
    s32 func_800C2FDC(u8);
    func_8009EA08((*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0xB0)))) + (0x10))));
    func_800C2FDC((*(u8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0xB0)))) + (0x1C))));
}

void bakaztorpedo_entrypoint_3(void *arg0) {
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0xB0)))) + (0x10))) = 20.0f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/kaztorpedo/bakaztorpedo_entrypoint_4.s")

void bakaztorpedo_entrypoint_5(void *arg0, f32 arg1, f32 arg2) {
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0xB0)))) + (4))) = arg1;
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0xB0)))) + (8))) = arg2;
}

void bakaztorpedo_entrypoint_6(void *arg0, s32 arg1) {
    *(s8 *)((u8 *)*(void **)((u8 *)arg0 + 176) + 12) = arg1;
}

void bakaztorpedo_entrypoint_7(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 176) + 24) = arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/kaztorpedo/bakaztorpedo_entrypoint_8.s")
