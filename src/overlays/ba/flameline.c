#include "common.h"

s32 baflameline_entrypoint_0() 
{
    return 0x28;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/flameline/baflameline_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/flameline/func_80800184_baflameline.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/flameline/baflameline_entrypoint_2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/flameline/baflameline_entrypoint_3.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/flameline/baflameline_entrypoint_4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/flameline/baflameline_entrypoint_5.s")

void baflameline_entrypoint_6(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 132) + 24) = arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/flameline/baflameline_entrypoint_7.s")
