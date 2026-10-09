#include "common.h"

s32 bsjig_entrypoint_0(s32 arg0) {
    return arg0 == 0x44;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/jig/bsjig_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/jig/bsjig_entrypoint_2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/jig/bsjig_entrypoint_3.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/jig/bsjig_entrypoint_4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/jig/bsjig_entrypoint_5.s")

s32 bsjig_entrypoint_6(s32 arg0) {
    extern s32 D_808005B0_bsjig[];
    return ((s32 *)&D_808005B0_bsjig)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/jig/bsjig_entrypoint_7.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/jig/bsjig_entrypoint_8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/jig/bsjig_entrypoint_9.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/jig/bsjig_entrypoint_10.s")

s32 bsjig_entrypoint_11(s32 arg0) {
    extern s32 D_808005C0_bsjig[];
    return ((s32 *)&D_808005C0_bsjig)[arg0];
}
