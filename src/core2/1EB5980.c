#include "core2/1EB5980.h"

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EB5980/func_800DC090.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EB5980/func_800DC0C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EB5980/func_800DC128.s")

f32 func_800DC178(f32 arg0, f32 arg1) {
    return (func_800DC0C0() * (arg1 - arg0)) + arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EB5980/func_800DC1AC.s")

/* extern */

s32 func_800DC214(s32 arg0, s32 arg1) {
    f32 func_800DC1AC();
    return (s32) ((func_800DC1AC() * (f32) (arg1 - arg0)) + (f32) arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EB5980/func_800DC264.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EB5980/func_800DC298.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EB5980/func_800DC2D4.s")

void func_800DC310(void) {
    extern s32 D_8012C7F0;
    D_8012C7F0 = 0xEAA0C7;
}

void func_800DC324(s32 arg0) {
    extern s32 D_8012C7F0;
    *(s32 *)((u8 *)&D_8012C7F0 + 0) = arg0;
}

void func_800DC330(void) {
    extern s32 D_8012C7F0;
    extern s32 D_8012C7F4;
    extern s32 D_8012C7F8;
    extern s32 D_8012C7FC;
    D_8012C7F8 = D_8012C7F0;
    D_8012C7FC = D_8012C7F4;
}

void func_800DC354(void) {
    extern s32 D_8012C7F8;
    extern s32 D_8012C7FC;
    extern s32 D_8012C7F0;
    extern s32 D_8012C7F4;
    D_8012C7F0 = D_8012C7F8;
    D_8012C7F4 = D_8012C7FC;
}
