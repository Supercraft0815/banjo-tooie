#include "common.h"

s32 func_800E4730(s32 arg0) {
    extern void *D_8012D560;
    extern void *D_8012D564;
    extern void *D_8012D568;
    extern void *D_8012D56C;
    if ((D_8012D560 != NULL) && (arg0 == (*(s16 *)((s8 *)(D_8012D560) + (0x3A))))) {
        return 0;
    }
    if ((D_8012D564 != NULL) && (arg0 == (*(s16 *)((s8 *)(D_8012D564) + (0x3A))))) {
        return 1;
    }
    if ((D_8012D568 != NULL) && (arg0 == (*(s16 *)((s8 *)(D_8012D568) + (0x3A))))) {
        return 2;
    }
    if ((D_8012D56C != NULL) && (arg0 == (*(s16 *)((s8 *)(D_8012D56C) + (0x3A))))) {
        return 3;
    }
    return -1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBE020/func_800E47CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBE020/func_800E488C.s")

/* extern */

s32 func_800E4AF0(void) {
    s32 func_800E4730();
    if (func_800E4730() < 0) {
        return 0;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBE020/func_800E4B1C.s")

/* extern */

s32 func_800E4BB8(void) {
    s32 func_800E4730();
    s32 func_800E4B1C(s32);
    s32 temp_v0;

    temp_v0 = func_800E4730();
    if (temp_v0 < 0) {
        return 0;
    }
    func_800E4B1C(temp_v0);
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBE020/func_800E4BF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBE020/func_800E4C7C.s")

/* extern */

void func_800E4CE8(void) {
    s32 func_800E4B1C(s32);
    s32 var_s0;

    var_s0 = 0;
    do {
        func_800E4B1C(var_s0);
        var_s0 += 1;
    } while (var_s0 != 4);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBE020/func_800E4D28.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBE020/func_800E4E54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBE020/func_800E5390.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBE020/func_800E589C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBE020/func_800E5EC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBE020/func_800E659C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBE020/func_800E6728.s")

void func_800E692C(void) {
    s32 heap_alloc(s32);
    extern s32 D_8012D570;
    D_8012D570 = heap_alloc(0x40);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBE020/func_800E6950.s")

u32 func_800E6A00(void) {
    extern u8 D_801275E0;
    return *(u8 *)((u8 *)&D_801275E0 + 0);
}
