#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBAA10/func_800E1120.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBAA10/func_800E119C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBAA10/func_800E1218.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBAA10/func_800E1294.s")

f32 func_800E1338(s32 arg0) {
    extern f32 D_8012CFB8[];
    return *(f32 *)((s32)&D_8012CFB8 + ((arg0 * 31) * 4));
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBAA10/func_800E1354.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBAA10/func_800E1378.s")

void func_800E13F0(s32 arg0, f32 arg1) {
    extern f32 D_8012CFB8[];
    *(f32 *)((s32)&D_8012CFB8 + ((arg0 * 31) * 4)) = arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBAA10/func_800E1410.s")

void func_800E144C(s32 arg0, f32 arg1) {
    extern f32 D_8012CFAC[];
    *(f32 *)((s32)&D_8012CFAC + ((arg0 * 31) * 4)) = arg1;
}

void func_800E146C(s32 arg0, f32 arg1) {
    extern f32 D_8012CFA4[];
    *(f32 *)((s32)&D_8012CFA4 + ((arg0 * 31) * 4)) = arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBAA10/func_800E148C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBAA10/func_800E14B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBAA10/func_800E14F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBAA10/func_800E1540.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBAA10/func_800E15CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBAA10/func_800E1610.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBAA10/func_800E1664.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBAA10/func_800E1720.s")

/* extern */

void func_800E1748(void) {
    s32 func_800E1720(s32);
    s32 var_s0;

    var_s0 = 0;
    do {
        func_800E1720(var_s0);
        var_s0 += 1;
    } while (var_s0 != 0xA);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBAA10/func_800E1788.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBAA10/func_800E1804.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBAA10/func_800E1A58.s")
