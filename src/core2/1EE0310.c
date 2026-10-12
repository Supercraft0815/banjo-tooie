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

s32 func_80106C08(void) {
    extern s32 D_80136EF0;
    s32 func_800B3310(s32);

    if (D_80136EF0 == 0) {
        D_80136EF0 = func_800B3310(0x6);
    }
    return D_80136EF0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE0310/func_80106C4C.s")

/* extern */

void func_80106D60(s32 arg0, s32 arg1, s32 *arg2) {
    void func_800B38A8();
    void func_800C87B8(s32 *);
    void func_80106DA4(s32 *, s32 *);
    s32 sp1C[3];

    func_800C87B8(sp1C);
    func_80106DA4(sp1C, arg2);
    func_800B38A8(arg1, sp1C);
}

void func_80106DA4(s32 *arg0, s32 *arg1) {
    s32 i;

    for (i = 0; i < 3; i++) {
        arg0[i] = (arg0[i] * arg1[i]) >> 8;
    }
}
