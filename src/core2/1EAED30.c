#include "common.h"

extern s32 D_8012B7E8;

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAED30/func_800D5440.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAED30/func_800D54F0.s")

void func_800D55A0(void) {
    s32 vector_new(s32, s32);
    extern s32 D_8012B7F0;
    extern s32 D_8012B7F4;
    D_8012B7F0 = vector_new(8, 0x10);
    D_8012B7F4 = vector_new(8, 0x10);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAED30/func_800D55DC.s")

void func_800D5688(void) {
    s32 vector_defrag(s32);
    extern s32 D_8012B7F0;
    extern s32 D_8012B7F4;
    (*(s32 *)((s8 *)(&D_8012B7F0) + (0))) = vector_defrag((*(s32 *)((s8 *)(&D_8012B7F0) + (0))));
    D_8012B7F4 = vector_defrag((*(s32 *)((s8 *)(&D_8012B7F0) + (4))));
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAED30/func_800D56C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAED30/func_800D5804.s")

void func_800D58AC()
{
    func_800D5688();
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAED30/func_800D58CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAED30/func_800D58FC.s")

s32 func_800D593C() 
{
    return 0x3666;
}

s32 func_800D5944()
{
    return D_8012B7E8;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAED30/func_800D5950.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAED30/func_800D59C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAED30/func_800D5A04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAED30/func_800D5A6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAED30/func_800D5AB4.s")

void func_800D5B24(void) {
    extern s8 D_8012B7E6;
    D_8012B7E6 = 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAED30/func_800D5B34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAED30/func_800D5D70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAED30/func_800D5DB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAED30/func_800D5E28.s")

void func_800D5E54()
{
    func_800D5440();
}

void func_800D5E74(void) 
{
    func_800D55DC();
}

void func_800D5E94()
{
    func_800D54F0();
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAED30/func_800D5EB4.s")

void func_800D5FDC(s32 arg0) {
    *(s32 *)((u8 *)&D_8012B7E8 + 0) = arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAED30/func_800D5FE8.s")
