#include "common.h"

void func_80106A20(void) {
}

void func_80106A28(void) {
    s32 func_800B3370(s32);
    extern s32 D_80136EF0;
    if (D_80136EF0 != 0) {
        func_800B3370(D_80136EF0);
        D_80136EF0 = 0;
    }
}

void func_80106A60(void) {
    s32 func_800B38E8(s32);
    extern s32 D_80136EF0;
    if (D_80136EF0 != 0) {
        D_80136EF0 = func_800B38E8(D_80136EF0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE0310/func_80106A98.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE0310/func_80106C08.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE0310/func_80106C4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE0310/func_80106D60.s")

void func_80106DA4(s32 *arg0, s32 *arg1) {
    s32 i;

    for (i = 0; i < 3; i++) {
        arg0[i] = (arg0[i] * arg1[i]) >> 8;
    }
}
