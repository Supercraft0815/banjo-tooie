#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/doormake/func_80800000_chdoormake.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/doormake/func_808000B8_chdoormake.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/doormake/chdoormake_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/doormake/chdoormake_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/doormake/chdoormake_entrypoint_2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/doormake/chdoormake_entrypoint_3.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/doormake/chdoormake_entrypoint_4.s")

void chdoormake_entrypoint_5(Actor *arg0, f32 arg1) {
    void* func_80100094(Actor*, u32);
    (*(s16 *)((s8 *)(func_80100094(arg0, 0U)) + (0xA))) = (s16) (s32) (256.0f * arg1);
}

void chdoormake_entrypoint_6(Actor *arg0, f32 arg1) {
    void* func_80100094(Actor*, u32);
    (*(s16 *)((s8 *)(func_80100094(arg0, 0U)) + (0xC))) = (s16) (s32) (256.0f * arg1);
}

void chdoormake_entrypoint_7(Actor *arg0, f32 arg1) {
    void* func_80100094(Actor*, u32);
    (*(s16 *)((s8 *)(func_80100094(arg0, 0U)) + (0xE))) = (s16) (s32) (256.0f * arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/doormake/chdoormake_entrypoint_8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/doormake/chdoormake_entrypoint_9.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/doormake/chdoormake_entrypoint_10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/doormake/chdoormake_entrypoint_11.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/doormake/func_808008C4_chdoormake.s")

void chdoormake_entrypoint_12(Actor *arg0, s32 arg1, u16 arg2) {
    void *func_80100094(Actor *, u32);
    (*(s8 *)((s8 *)func_80100094(arg0, 0U) + (arg1 * 8) + 0x20)) = (s8) arg2;
}
