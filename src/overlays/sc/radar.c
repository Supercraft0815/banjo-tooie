#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/sc/radar/func_80800000_scradar.s")

void func_8080074C_scradar(void *arg0, s8 arg1, s8 arg2, s8 arg3) {
    (*(s8 *)((s8 *)(arg0) + (0))) = arg1;
    (*(s8 *)((s8 *)(arg0) + (1))) = arg2;
    (*(s8 *)((s8 *)(arg0) + (2))) = arg3;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/sc/radar/func_80800768_scradar.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/sc/radar/func_808007D4_scradar.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/sc/radar/scradar_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/sc/radar/scradar_entrypoint_1.s")
