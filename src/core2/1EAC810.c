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

s32 func_800D3724(s32 arg0) {
    s32 func_800D6C34(s16);
    extern u8 D_8011B560[];
    s32 var_v1;
    u8 *temp_v0;

    temp_v0 = D_8011B560 + arg0 * 8;
    if ((*(s32 *)((s8 *)temp_v0 + 4)) != 0) {
        var_v1 = func_800D6C34(*(s16 *)(temp_v0 + 0));
    } else {
        var_v1 = 1;
    }
    return var_v1;
}
