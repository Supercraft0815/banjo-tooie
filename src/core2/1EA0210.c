#include "common.h"

extern s32 D_8012AAC4;

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA0210/func_800C6920.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA0210/func_800C696C.s")

s32 func_800C69FC()
{
    return D_8012AAC4;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA0210/func_800C6A08.s")

void func_800C6A28(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    extern s32 D_8012AA40;
    (*(s32 *)((s8 *)((*(u8 **)((s8 *)(&D_8012AA40) + (0x80)))) + (0))) = arg0;
    (*(s32 *)((s8 *)((*(u8 **)((s8 *)(&D_8012AA40) + (0x80)))) + (4))) = arg1;
    (*(s32 *)((s8 *)((*(u8 **)((s8 *)(&D_8012AA40) + (0x80)))) + (8))) = arg2;
    (*(s32 *)((s8 *)((*(u8 **)((s8 *)(&D_8012AA40) + (0x80)))) + (0xC))) = arg3;
    (*(u8 **)((s8 *)(&D_8012AA40) + (0x80))) = (u8 *) ((*(u8 **)((s8 *)(&D_8012AA40) + (0x80))) + 0x10);
}

void func_800C6A60(void) {
}

void func_800C6A68(void) {
    extern s32 D_8012AA40;
    (*(s32 **)((s8 *)(&D_8012AA40) + (0x80))) = &D_8012AA40;
    (*(s32 *)((s8 *)(&D_8012AA40) + (0x84))) = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA0210/func_800C6A7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA0210/func_800C6B78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA0210/func_800C6C94.s")
