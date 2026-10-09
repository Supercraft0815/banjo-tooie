#include "common.h"

extern s32 D_80128770;

void func_800BFCD0(s32 arg0, s32 arg1) {
    (*(s32 *)((s8 *)(&(&D_80128770)[arg0]) + (0x30))) = arg1;
    if ((*(s32 *)((s8 *)(&D_80128770) + (0x30))) < arg0) {
        (*(s32 *)((s8 *)(&D_80128770) + (0x30))) = arg0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E995C0/func_800BFD00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E995C0/func_800BFD6C.s")

void func_800BFF28()
{
    _gcskyDll_entrypoint_0(&D_80128770);
}

void func_800BFF4C()
{
    _gcskyDll_entrypoint_1(&D_80128770);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E995C0/func_800BFF70.s")

s32 func_800BFFA0(s32 arg0) {
    extern s32 D_80128778[];
    return ((s32 *)&D_80128778)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E995C0/func_800BFFB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E995C0/func_800BFFF4.s")

/* extern */

void func_800C0064(s32 arg0) {
    s32 _gcskyDll_entrypoint_2(s32 *, s32);
    _gcskyDll_entrypoint_2(&D_80128770, arg0);
}
