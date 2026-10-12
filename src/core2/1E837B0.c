#include "common.h"

void func_800A9EC0(s32 arg0) {
    extern s32 D_80127770;
    extern s16 D_8011A480[][2];
    extern s16 D_8011A498[][2];
    s32 i;

    D_80127770 = 0x3E800;
    i = 0;
loop_1:
    if (arg0 == D_8011A480[i][0]) {
        D_80127770 = D_8011A480[i][1] << 10;
        return;
    }
    i++;
    if (D_8011A498 != &D_8011A480[i]) {
        goto loop_1;
    }
}

s32 func_800A9F14(s32 arg0) {
    if (arg0 == 2) {
        return 3;
    }
    return 0x12;
}

s32 func_800A9F30(void) {
    s32 func_8001BDAC(s32 *, s32);
    extern s32 D_80127770;
    s32 sp1C;

    func_8001BDAC(&sp1C, 1);
    return D_80127770 < sp1C;
}

void func_800A9F60(s32 arg0, s32 arg1) {
    void func_800DA3B8(s32, s32);
    func_800DA3B8(arg0 + 0xD1B, arg1);
}

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

void func_800AA148(void) {
    s32 func_800A9FA0(s16);
    extern s16 D_80127780;
    func_800A9FA0(D_80127780);
}

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

void func_800AA20C(s32 arg0, s32 arg1) {
    extern s16 D_8012778C[];
    D_8012778C[arg0] = arg1;
}

void func_800AA220(s32 arg0, s32 arg1) {
    extern s16 D_80127780;
    s16 *temp_v0;

    temp_v0 = &(&D_80127780)[arg0];
    (*(s16 *)((s8 *)(temp_v0) + (4))) = (s16) ((*(s16 *)((s8 *)(temp_v0) + (4))) + arg1);
}

/* extern */

s32 func_800AA240(void) {
    s32 func_800AA0D0();
    s32 sp1C;

    sp1C = func_800AA0C4();
    return sp1C >= (func_800AA0D0() - 1);
}

void func_800AA274(s32 arg0) {
    func_800A9F80(arg0);
}
