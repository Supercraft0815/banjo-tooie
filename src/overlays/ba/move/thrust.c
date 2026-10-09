#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/move/thrust/func_80800000_bamovethrust.s")

void bamovethrust_entrypoint_0(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/move/thrust/bamovethrust_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/move/thrust/bamovethrust_entrypoint_2.s")

void bamovethrust_entrypoint_3(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 200) + 140) = arg1;
}

void bamovethrust_entrypoint_4(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 200) + 132) = arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/move/thrust/bamovethrust_entrypoint_5.s")

f32 bamovethrust_entrypoint_6(void *arg0) {
    return *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 200) + 140);
}
