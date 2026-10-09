#include "common.h"

void gspropprop_entrypoint_0(void *arg0, void *arg1) {
    (*(s32 *)((s8 *)(arg1) + (0))) = (s32) (*(s16 *)((s8 *)(arg0) + (4)));
    (*(s32 *)((s8 *)(arg1) + (4))) = (s32) (*(s16 *)((s8 *)(arg0) + (6)));
    (*(s32 *)((s8 *)(arg1) + (8))) = (s32) (*(s16 *)((s8 *)(arg0) + (8)));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gs/propprop/func_8080001C_gspropprop.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gs/propprop/func_80800050_gspropprop.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gs/propprop/gspropprop_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gs/propprop/gspropprop_entrypoint_2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gs/propprop/gspropprop_entrypoint_3.s")
