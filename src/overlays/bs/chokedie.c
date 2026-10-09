#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/chokedie/bschokedie_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/chokedie/bschokedie_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/chokedie/bschokedie_entrypoint_2.s")

s32 bschokedie_entrypoint_3(s32 arg0) {
    extern s32 D_808002B0_bschokedie[];
    return ((s32 *)&D_808002B0_bschokedie)[arg0];
}
