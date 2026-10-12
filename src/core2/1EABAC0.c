#include "core2/1EABAC0.h"

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EABAC0/func_800D21D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EABAC0/func_800D21F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EABAC0/func_800D225C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EABAC0/func_800D22C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EABAC0/func_800D22E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EABAC0/func_800D2398.s")

/* extern */

int func_800D23E8(void *arg0, s32 arg1) {
    s32 func_800D21F0(s32, u8);
    s32 func_800FA874(s32, u8);
    s32 temp_v0;

    temp_v0 = func_800D21F0(arg1, (*(u8 *)((s8 *)(arg0) + (0))));
    return temp_v0 >= 0 && func_800FA874(temp_v0, (*(u8 *)((s8 *)(arg0) + (1)))) == 1;
}

void func_800D2438(void) { extern s32 D_8011AFB0; extern s32 D_8011B3F4; extern s32 D_8012B2C0; extern s32 D_8012B320; u32 end; u32 ptr; end = (u32)&D_8011B3F4;
    ptr = (u32)&D_8011AFB0; for (;;) { *(s16 *)(ptr + 4) = -1; *(s16 *)(ptr + 6) = 0; *(f32 *)(ptr + 8) = 0.0f; ptr += 12; if (ptr >= end) break; } end = (u32)&D_8012B320; ptr = (u32)&D_8012B2C0; for (;;) { ptr += 8; *(s16 *)(ptr - 6) = -1; *(s16 *)(ptr - 4) = -1; *(s16 *)(ptr - 2) = -1; *(s16 *)(ptr - 8) = -1; if (ptr == end) break; } }

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EABAC0/func_800D2498.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EABAC0/func_800D24E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EABAC0/func_800D2574.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EABAC0/func_800D2748.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EABAC0/func_800D2770.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EABAC0/func_800D27A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EABAC0/func_800D27C8.s")

void func_800D27F4(s32 arg0)
{
    func_800D23E8(func_800D21D0(),arg0);
}

void func_800D2820(s32 arg0)
{
    func_800D2398(func_800D21D0(),arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EABAC0/func_800D284C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EABAC0/func_800D28A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EABAC0/func_800D28E8.s")
