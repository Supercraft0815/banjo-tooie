#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/claw/bsclaw_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/claw/bsclaw_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/claw/bsclaw_entrypoint_2.s")

s32 bsclaw_entrypoint_3(s32 arg0) {
    extern s32 D_80800400_bsclaw[];
    return ((s32 *)&D_80800400_bsclaw)[arg0];
}
