#include "common.h"

extern u32 D_80800070_chjiggybeam;

void * chjiggybeam_entrypoint_0(void) {
    return &D_80800070_chjiggybeam;
}

void func_8080000C_chjiggybeam(void *arg0) {
    (*(f32 *)((s8 *)(arg0) + (0x18))) = 1.0f;
}

void func_8080001C_chjiggybeam(void) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jiggy/beam/func_80800024_chjiggybeam.s")

s32 func_80800058_chjiggybeam(s32 arg0, u32 arg1, u32 arg2) {
    return 0;
}