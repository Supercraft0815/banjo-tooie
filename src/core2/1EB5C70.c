#include "common.h"

void func_800DC380(void) {
    s32 func_80012EDC(s32 *);
    s32 func_8001EB10(s32 *);
    extern s32 D_8012C800;
    (*(s32 *)((s8 *)(&D_8012C800) + (0))) = 0x32;
    (*(s32 *)((s8 *)(&D_8012C800) + (4))) = 0x100;
    (*(s16 *)((s8 *)(&D_8012C800) + (0x10))) = 0x40;
    (*(s32 *)((s8 *)(&D_8012C800) + (8))) = 0x18;
    (*(s32 *)((s8 *)(&D_8012C800) + (0xC))) = func_80012EDC(&D_8012C800);
    func_8001EB10(&D_8012C800);
}

/* extern */

void func_800DC3D4(s32 arg0, f32 arg1, u16 arg2, u8 arg3, u8 arg4, s32 arg5) {
    void func_80020790(s16, u16, u8, f32, u8, u8, s32);
    func_80020790((s16) (arg0 + 1), arg2, arg3, arg1, arg4, 0, arg5);
}

void func_800DC42C(s32 arg0, volatile s32 arg1) { func_80020C08(arg0, 0x10, arg1); }

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EB5C70/func_800DC454.s")

void func_800DC48C(s32 arg0,s32 arg1)
{
    func_80020C08(arg0,0x100,arg1);
}

void func_800DC4B0(s32 arg0,s32 arg1)
{
    func_80020C08(arg0,0x4,arg1);
}

void func_800DC4D4(s32 arg0) { if (arg0 != 0) { if (func_80020760() != 0) func_80020A60(arg0); } }

void func_800DC508()
{
    func_80020760();
}

void func_800DC528(void) {
    func_800E9054(NULL);
}

/* extern */

s32 func_800DC548(void) { u8 *func_800E9320(); if ((*(s32 *)((s8 *)(func_800E9320()) + 4)) == -1) { return 1; } else { return 0; } }
