#include "core2/1E82660.h"

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E82660/func_800A8D70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E82660/func_800A8E9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E82660/func_800A8EF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E82660/func_800A8F68.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E82660/func_800A8FDC.s")

s32 func_800A9010(void) {
    extern u8 D_801276D4;
    extern u8 D_801276D5;
    extern u8 D_801276D6;
    extern u8 D_801276D7;
    if (D_801276D4 == 0) {
        return 0;
    }
    if (D_801276D5 == 0) {
        return 1;
    }
    if (D_801276D6 == 0) {
        return 2;
    }
    if (D_801276D7 == 0) {
        return 3;
    }
    return -1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E82660/func_800A907C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E82660/func_800A91A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E82660/func_800A91F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E82660/func_800A92A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E82660/func_800A9318.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E82660/func_800A9378.s")

s32 func_800A93E4(s32 arg0) {
    extern s32 D_80127728[];
    return ((s32 *)&D_80127728)[arg0];
}

s32 func_800A93F8(s32 arg0) {
    extern s32 D_80127708[];
    return ((s32 *)&D_80127708)[arg0];
}

s32 func_800A940C(s32 arg0) {
    extern s32 D_801276E8[];
    return ((s32 *)&D_801276E8)[arg0];
}

s32 func_800A9420(s32 arg0) {
    extern s16 D_801276D0;
    s32 func_800A8984(s32);
    return *(s32 *)((u8 *)&D_801276D0 + arg0 * 4 + 0x38) ==
        func_800A8984(*(s32 *)((u8 *)&D_801276D0 + arg0 * 4 + 0x18));
}

s32 func_800A9460(void) {
    extern s16 D_801276D0;
    return *(s16 *)((u8 *)&D_801276D0 + 0);
}

s32 func_800A946C(void) {
    extern s16 D_801276D2;
    return *(s16 *)((u8 *)&D_801276D2 + 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E82660/func_800A9478.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E82660/func_800A9514.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E82660/func_800A95C4.s")

s32 func_800A965C(void) {
    extern s16 D_801276D2;
    return 4 - D_801276D2;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E82660/func_800A9670.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E82660/func_800A96F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E82660/func_800A9768.s")

/* extern */

void func_800A9800(void) {
    s32 func_800A9828(s32, s32, s32);
    func_800A9828(0, 0, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E82660/func_800A9828.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E82660/func_800A989C.s")
