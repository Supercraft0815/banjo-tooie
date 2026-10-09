#include "common.h"

extern s32 D_80137074;

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE7960/func_8010E070.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE7960/func_8010E204.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE7960/func_8010E2C4.s")

/* extern */

void func_8010E334(void) {
    s32 func_800B3310(s32);
    D_80137074 = func_800B3310(0x4);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE7960/func_8010E358.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE7960/func_8010E390.s")

s32 func_8010E3B8()
{
    return D_80137074;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE7960/func_8010E3C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE7960/func_8010E4C4.s")

void func_8010E7F4(void) {
    extern s32 D_80137060;
    (*(s32 *)((s8 *)(&D_80137060) + (0))) = 0;
    (*(s32 *)((s8 *)(&D_80137060) + (0x18))) = 0;
    (*(s32 *)((s8 *)(&D_80137060) + (0x1C))) = 0;
}
