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

/* extern */

void func_800BFF70(void) {
    f32 func_800D8FF8();
    (*(f32 *)((s8 *)(&D_80128770) + 0x134)) += func_800D8FF8();
}

s32 func_800BFFA0(s32 arg0) {
    extern s32 D_80128778[];
    return ((s32 *)&D_80128778)[arg0];
}

/* extern */

s32 func_800BFFB4(s32 arg0, s32 arg1, s32 arg2) {
    void func_800DBEFC(s32 *, s32, s32);
    s32 temp_a3;
    s32 var_v0;

    temp_a3 = (&D_80128770)[arg0];
    var_v0 = 0;
    if (temp_a3 != 0) {
        func_800DBEFC((s32 *)temp_a3, arg1, arg2);
        return 1;
    }
    return var_v0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E995C0/func_800BFFF4.s")

/* extern */

void func_800C0064(s32 arg0) {
    s32 _gcskyDll_entrypoint_2(s32 *, s32);
    _gcskyDll_entrypoint_2(&D_80128770, arg0);
}
