#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/turn/bsturn_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/turn/bsturn_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/turn/bsturn_entrypoint_2.s")

s32 bsturn_entrypoint_3(s32 arg0) {
    extern s32 D_80800360_bsturn[];
    return ((s32 *)&D_80800360_bsturn)[arg0];
}
