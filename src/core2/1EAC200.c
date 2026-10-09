#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAC200/func_800D2910.s")

void func_800D2970(void) {
    extern s32 D_8012B320;
    (*(s8 *)((s8 *)(&D_8012B320) + (0x18))) = 0;
    (*(s8 *)((s8 *)(&D_8012B320) + (4))) = 0;
    (*(s8 *)((s8 *)(&D_8012B320) + (1))) = 0;
    (*(s8 *)((s8 *)(&D_8012B320) + (0))) = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAC200/func_800D298C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAC200/func_800D2A44.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAC200/func_800D2C54.s")

void func_800D2CC4(void) {
    extern u8 D_8012B321;

    D_8012B321 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAC200/func_800D2CD0.s")

void func_800D2E4C(void) {
    s32 heap_free(s32);
    extern s32 D_8012B360;
    if ((*(s32 *)((s8 *)(&D_8012B360) + (0))) != 0) {
        heap_free((*(s32 *)((s8 *)(&D_8012B360) + (0))));
        (*(s32 *)((s8 *)(&D_8012B360) + (0))) = 0;
    }
    (*(s32 *)((s8 *)(&D_8012B360) + (4))) = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAC200/func_800D2E90.s")

void func_800D2EE4(void) {
    s32 defrag(s32);
    extern s32 D_8012B360;
    if (D_8012B360 != 0) {
        D_8012B360 = defrag(D_8012B360);
    }
}
