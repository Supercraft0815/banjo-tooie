#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E837B0/func_800A9EC0.s")

s32 func_800A9F14(s32 arg0) {
    if (arg0 == 2) {
        return 3;
    }
    return 0x12;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E837B0/func_800A9F30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E837B0/func_800A9F60.s")

/* extern */

void func_800A9F80(s32 arg0) {
    s32 func_800DA298(s32);
    func_800DA298(arg0 + 0xD1B);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E837B0/func_800A9FA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E837B0/func_800AA00C.s")

void func_800AA054(s32 arg0)
{
    func_800A9F60(arg0,1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E837B0/func_800AA074.s")

u32 func_800AA0B8(void) {
    extern u8 D_80127783;
    return *(u8 *)((u8 *)&D_80127783 + 0);
}

s32 func_800AA0C4(void) {
    extern s16 D_80127780;
    return *(s16 *)((u8 *)&D_80127780 + 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E837B0/func_800AA0D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E837B0/func_800AA120.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E837B0/func_800AA148.s")

s32 func_800AA16C(s32 arg0) {
    extern s16 D_80127784[];
    return ((s16 *)&D_80127784)[arg0];
}

s32 func_800AA180(s32 arg0) {
    extern s16 D_8012778C[];
    return ((s16 *)&D_8012778C)[arg0];
}

u32 func_800AA194(void) {
    extern u8 D_80127782;
    return *(u8 *)((u8 *)&D_80127782 + 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E837B0/func_800AA1A0.s")

void func_800AA200(s32 arg0) {
    extern u8 D_80127782;
    D_80127782 = arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E837B0/func_800AA20C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E837B0/func_800AA220.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E837B0/func_800AA240.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E837B0/func_800AA274.s")
