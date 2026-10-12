#include "common.h"

/* extern */

s32 func_800D2F20(void) {
    s32 func_800BDC5C();
    return func_800BDC5C() * 4;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAC810/func_800D2F44.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAC810/func_800D3104.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAC810/func_800D34A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAC810/func_800D3524.s")

int func_800D3574(s32 arg0) {
    extern u8 D_8011B562[];
    extern f32 D_80125B10;
    return (s32) ((f32) (u32) D_8011B562[arg0 * 8] * D_80125B10);
}

u8 func_800D35BC(s32 arg0) {
    extern u8 D_8011B562[];
    return D_8011B562[arg0 * 8];
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAC810/func_800D35D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAC810/func_800D36A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAC810/func_800D36C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAC810/func_800D3724.s")
