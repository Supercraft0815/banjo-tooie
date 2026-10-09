#include "common.h"

s32 baflameline_entrypoint_0() 
{
    return 0x28;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/flameline/baflameline_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/flameline/func_80800184_baflameline.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/flameline/baflameline_entrypoint_2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/flameline/baflameline_entrypoint_3.s")

/* extern */

void baflameline_entrypoint_4(void *arg0) {
    s32 func_800EE7F8(s32);
    func_800EE7F8((*(s32 *)((s8 *)(arg0) + (0x84))));
}

/* extern */

void baflameline_entrypoint_5(void *arg0) {
    s32 func_800EE7F8(s32);
    s32 func_800EF2A0(s32);
    func_800EE7F8((*(s32 *)((s8 *)(arg0) + (0x84))) + 0xC);
    func_800EF2A0((*(s32 *)((s8 *)(arg0) + (0x84))) + 0xC);
}

void baflameline_entrypoint_6(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 132) + 24) = arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/flameline/baflameline_entrypoint_7.s")
