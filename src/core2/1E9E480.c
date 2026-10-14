#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9E480/func_800C4B90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9E480/func_800C4C34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9E480/func_800C4E58.s")

/* extern */

void func_800C5008(s32 arg0, f32 *arg1, f32 *arg2) {
    void func_800A8A04(s32, s32 *, s32 *, s32 *, s32 *);
    s32 sp2C;
    s32 sp28;
    s32 sp24;
    s32 sp20;

    func_800A8A04(arg0, &sp2C, &sp28, &sp24, &sp20);
    arg2[0] = arg1[0] * ((f32) sp24 / 304.0f);
    arg2[1] = arg1[1] * ((f32) sp20 / 228.0f);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9E480/func_800C5094.s")

/* extern */

void func_800C5148(s32 arg0, f32 arg1) {
    extern f32 D_8012A9F0[];
    s32 func_800C5094(s32, f32);
    D_8012A9F0[arg0] = arg1;
    func_800C5094(arg0, arg1);
}

f32 func_800C517C(s32 arg0) {
    extern f32 D_8012A9F0[];
    return ((f32 *)&D_8012A9F0)[arg0];
}

f32 func_800C5190(s32 arg0) {
    extern f32 D_8012AA04[];
    return ((f32 *)&D_8012AA04)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9E480/func_800C51A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9E480/func_800C524C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9E480/func_800C52F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9E480/func_800C53EC.s")

/* extern */

void func_800C54CC(s32, f32, f32);

void func_800C5464(void) {
    f32 var_f20 = 40.0f;
    f32 var_f22 = 1.0f;
    s32 var_s0;
    for (var_s0 = 0; var_s0 != 5; var_s0++) {
        func_800C54CC(var_s0, var_f20, var_f22);
    }
}

void func_800C54CC(s32 arg0, f32 arg1, f32 arg2) {
    extern f32 D_8012A9A0[];
    f32 *p = D_8012A9A0 + arg0;
    p[20] = arg1;
    p[25] = arg2;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9E480/func_800C54F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9E480/func_800C5668.s")
