#include "common.h"

void func_800CB840(s32 arg0, s32 arg1) {
    extern s32 D_8012AE70;
    (*(s16 *)((s8 *)(&D_8012AE70) + (0))) = arg0;
    (*(s32 *)((s8 *)(&D_8012AE70) + (4))) = arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA5130/func_800CB854.s")

void func_800CB870(void) {
    extern s32 D_8012AE70;
    (*(s16 *)((s8 *)(&D_8012AE70) + (0))) = 0;
    (*(s32 *)((s8 *)(&D_8012AE70) + (4))) = 0;
}
