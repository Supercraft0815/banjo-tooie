#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EB2130/func_800D8840.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EB2130/func_800D8854.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EB2130/func_800D88C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EB2130/func_800D88F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EB2130/func_800D8954.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EB2130/func_800D8988.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EB2130/func_800D89C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EB2130/func_800D8B80.s")

void * func_800D8F40(void) {
    extern u8 D_8012C030;
    return &D_8012C030;
}
