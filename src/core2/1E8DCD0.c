#include "common.h"

void func_800B43E0(void) {
    extern u8 D_80127F00[3];
    u8 func_800B5758(s32);
    s32 i;
    for (i = 0; i < 3; i++) {
        D_80127F00[i] = func_800B5758(0x20);
    }
}

void func_800B4428(void) {
    extern u8 D_80127F00[3];
    void func_800B58D4(u8);
    s32 i;
    for (i = 0; i < 3; i++) {
        func_800B58D4(D_80127F00[i]);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E8DCD0/func_800B4470.s")
