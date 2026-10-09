#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bpeck/bsbpeck_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bpeck/func_80800168_bsbpeck.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bpeck/bsbpeck_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bpeck/bsbpeck_entrypoint_2.s")

s32 bsbpeck_entrypoint_3(s32 arg0) {
    extern s32 D_808004A0_bsbpeck[];
    return ((s32 *)&D_808004A0_bsbpeck)[arg0];
}
