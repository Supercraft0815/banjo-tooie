#include "common.h"

void func_80800000_chskeletonexplode(Actor *arg0) {
    void* func_80100094(Actor*, u32);
    f32 *temp_v0;

    temp_v0 = func_80100094(arg0, 1U);
    arg0->unk58 = 0.0f;
    *temp_v0 = 0.0f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/skeletonexplode/func_80800034_chskeletonexplode.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/skeletonexplode/func_8080007C_chskeletonexplode.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/skeletonexplode/func_808001BC_chskeletonexplode.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/skeletonexplode/func_808004DC_chskeletonexplode.s")

void func_80800594_chskeletonexplode(void *arg0) {
    (*(f32 *)((s8 *)(arg0) + (0x30))) = 15.0f;
    (*(f32 *)((s8 *)(arg0) + (0x18))) = 15.0f;
    (*(f32 *)((s8 *)(arg0) + (0x28))) = 800.0f;
    (*(f32 *)((s8 *)(arg0) + (0x2C))) = 1000.0f;
    (*(f32 *)((s8 *)(arg0) + (0x34))) = -2000.0f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/skeletonexplode/func_808005CC_chskeletonexplode.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/skeletonexplode/func_80800894_chskeletonexplode.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/skeletonexplode/chskeletonexplode_entrypoint_0.s")

void chskeletonexplode_entrypoint_1(void *arg0, f32 arg1, f32 arg2) {
    (*(f32 *)((s8 *)(arg0) + (0x28))) = arg1;
    (*(f32 *)((s8 *)(arg0) + (0x2C))) = arg2;
}

void chskeletonexplode_entrypoint_2(void *arg0, f32 arg1, f32 arg2) {
    (*(f32 *)((s8 *)(arg0) + (0x30))) = arg1;
    (*(f32 *)((s8 *)(arg0) + (0x18))) = arg2;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/skeletonexplode/chskeletonexplode_entrypoint_3.s")

void chskeletonexplode_entrypoint_4(Actor *arg0, s32 arg1) {
    void* func_80100094(Actor*, u32);
    (*(s8 *)((s8 *)(func_80100094(arg0, 1U)) + (0xF4))) = (s8) arg1;
}

void chskeletonexplode_entrypoint_5(Actor *arg0, s32 arg1) {
    void* func_80100094(Actor*, u32);
    (*(s8 *)((s8 *)(func_80100094(arg0, 1U)) + (0xF5))) = (s8) arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/skeletonexplode/chskeletonexplode_entrypoint_6.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/skeletonexplode/chskeletonexplode_entrypoint_7.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/skeletonexplode/chskeletonexplode_entrypoint_8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/skeletonexplode/func_80800E88_chskeletonexplode.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/skeletonexplode/func_8080100C_chskeletonexplode.s")

OSThread *chskeletonexplode_entrypoint_9(void)
{
    extern u8 D_80801138_chskeletonexplode[];

    return (OSThread *) D_80801138_chskeletonexplode;
}
