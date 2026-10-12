#include "core2/1ED3900.h"

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED3900/func_800FA010.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED3900/func_800FA130.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED3900/func_800FA240.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED3900/func_800FA2C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED3900/func_800FA508.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED3900/func_800FA608.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED3900/func_800FA660.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED3900/func_800FA6B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED3900/func_800FA708.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED3900/func_800FA818.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED3900/func_800FA874.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED3900/func_800FA8E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED3900/func_800FA934.s")

void func_800FA9A8(s32 arg0) {
    extern u8 D_801357B0;
    D_801357B0 = arg0;
}

void func_800FA9B4(s32 arg0, s32 arg1) {
    s32 _scinfobar_entrypoint_9(s32, s32);
    extern s32 D_80123898[][7];
    s32 temp_a2;

    temp_a2 = D_80123898[arg0][0];
    if (temp_a2 != 0) {
        _scinfobar_entrypoint_9(temp_a2, arg1);
    }
}

void func_800FA9F4(s32 arg0, s32 arg1) {
    s32 _scinfobar_entrypoint_4(s32, s32);
    extern s32 D_80123898[][7];
    s32 temp_a2;

    temp_a2 = D_80123898[arg0][0];
    if (temp_a2 != 0) {
        _scinfobar_entrypoint_4(temp_a2, arg1);
    }
}

void func_800FAA34(s32 arg0) {
    s32 _scinfobar_entrypoint_5(s32, s32);
    extern s32 D_80123898[][7];
    s32 temp_a2;

    temp_a2 = D_80123898[arg0][0];
    if (temp_a2 != 0) {
        _scinfobar_entrypoint_5(temp_a2, 1);
    }
}

void func_800FAA74(s32 arg0) {
    s32 _scinfobar_entrypoint_5(s32, s32);
    extern s32 D_80123898[][7];
    s32 temp_a2;

    temp_a2 = D_80123898[arg0][0];
    if (temp_a2 != 0) {
        _scinfobar_entrypoint_5(temp_a2, 2);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED3900/func_800FAAB4.s")
