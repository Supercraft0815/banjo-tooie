#include "common.h"

f32 func_800D8840(s32 arg0) {
    extern f32 D_8011B964[][2];
    return D_8011B964[arg0][0];
}

s32 func_800D8854(s32 arg0) {
    extern u8 D_8011B961[];
    return D_8011B961[arg0 * 8] & 1;
}

void func_800D8870(void) {
    s32 freelist_new(s32, s32);
    extern s32 D_8012C020;
    D_8012C020 = freelist_new(0x70, 0);
}

void func_800D8898(void) {
    s32 freelist_free(s32);
    extern s32 D_8012C020;
    freelist_free(D_8012C020);
    D_8012C020 = 0;
}

void func_800D88C0(void) {
    s32 freelist_defrag(s32);
    extern s32 D_8012C020;
    if (D_8012C020 != 0) {
        D_8012C020 = freelist_defrag(D_8012C020);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EB2130/func_800D88F8.s")

void func_800D8954(s16 arg0) {
    s32 freelist_erase(s32, s16);
    extern s32 D_8012C020;
    freelist_erase(D_8012C020, arg0);
}

s32 func_800D8988(s16 arg0, s32 arg1) {
    s32 freelist_at(s32, s16);
    extern s32 D_8012C020;
    return freelist_at(D_8012C020, arg0) + (arg1 * 0x1C);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EB2130/func_800D89C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EB2130/func_800D8B80.s")

void * func_800D8F40(void) {
    extern u8 D_8012C030;
    return &D_8012C030;
}
