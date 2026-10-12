#include "common.h"

void func_800D2910(s32 arg0, u8 *arg1) {
    extern s32 D_8012B320;
    u8 *temp_v0;

    temp_v0 = (u8 *)&D_8012B320 + (arg0 * 0x14);
    (*(s8 *)((s8 *)(temp_v0) + (4))) = 1;
    (*(s16 *)((s8 *)(temp_v0) + (6))) = (s16) (*(u8 *)((s8 *)(arg1) + (0xC)));
    (*(s16 *)((s8 *)(temp_v0) + (8))) = (s16) (*(u8 *)((s8 *)(arg1) + (0xD)));
    (*(s16 *)((s8 *)(temp_v0) + (0xA))) = (s16) (*(u8 *)((s8 *)(arg1) + (0xE)));
    (*(s16 *)((s8 *)(temp_v0) + (0xC))) = (s16) (*(u8 *)((s8 *)(arg1) + (0xF)));
    (*(f32 *)((s8 *)(temp_v0) + (0x10))) = (f32) (*(f32 *)((s8 *)(arg1) + (4)));
    (*(f32 *)((s8 *)(temp_v0) + (0x14))) = (f32) (*(f32 *)((s8 *)(arg1) + (8)));
    (*(u8 *)&D_8012B320) += 1;
}

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
