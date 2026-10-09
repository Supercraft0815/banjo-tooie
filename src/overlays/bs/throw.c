#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/throw/bsthrow_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/throw/bsthrow_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/throw/bsthrow_entrypoint_2.s")

s32 bsthrow_entrypoint_3(s32 arg0) {
    extern s32 D_808002F0_bsthrow[];
    return ((s32 *)&D_808002F0_bsthrow)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/throw/bsthrow_entrypoint_4.s")
