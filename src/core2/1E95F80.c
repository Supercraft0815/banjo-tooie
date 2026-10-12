#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E95F80/func_800BC690.s")

void func_800BC8A0(void) {
    s32 heap_free(s32);
    extern s32 D_801282E0;
    if ((*(u8 *)((s8 *)(&D_801282E0) + (0xD))) != 0) {
        heap_free((*(s32 *)((s8 *)(&D_801282E0) + (0))));
        heap_free((*(s32 *)((s8 *)(&D_801282E0) + (4))));
        (*(s32 *)((s8 *)(&D_801282E0) + (4))) = 0;
        (*(s32 *)((s8 *)(&D_801282E0) + (0))) = 0;
        (*(u8 *)((s8 *)(&D_801282E0) + (0xD))) = 0U;
    }
}

/* extern */

void func_800BC8F8(s32 *arg0) {
    extern s32 D_801282E0;
    s32 func_800E42E4(s32);
    if ((*(u8 *)((s8 *)(&D_801282E0) + (0xD))) != 0) {
        (*(s32 *)((s8 *)(&D_801282E0) + (8))) = (s32) *arg0;
        *arg0 = (&D_801282E0)[(*(u8 *)((s8 *)(&D_801282E0) + (0xC)))];
        func_800E42E4(1);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E95F80/func_800BC948.s")

void func_800BCC28(s32 arg0, s32 arg1) {
    s32 func_800F23D0(s32 *, s32, s32);
    extern s32 D_801282F4;
    func_800F23D0(&D_801282F4, arg0, arg1);
}

int func_800BCC58(void) {
    extern s32 D_801282E0;
    return ((*(u8 *)((s8 *)(&D_801282E0) + (0xD))) != 0) && ((*(u8 *)((s8 *)(&D_801282E0) + (0x10))) != 0);
}

u32 func_800BCC84(void) {
    extern u8 D_801282ED;
    return *(u8 *)((u8 *)&D_801282ED + 0);
}

void func_800BCC90(Gfx **arg0) {
    extern s32 D_80128338;
    gSPMatrix((*arg0)++, &D_80128338 - 0x20000000,
              G_MTX_PROJECTION | G_MTX_MUL | G_MTX_NOPUSH);
}
