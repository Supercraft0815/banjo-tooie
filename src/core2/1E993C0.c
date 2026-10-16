#include "common.h"

void func_800BFAD0(s32 arg0, f32 *arg1, f32 *arg2, f32 arg3, s32 arg4) {
    s32 func_800BFC34(s32);
    s32 func_800D2F20(void);
    u8 func_800D731C(s32);
    void *func_800DE448(f32 *, f32 *, f32, f32 *, s32);
    void func_800DF3E0(void);
    f32 func_800DF428(f32);
    void func_800DF470(s32);
    void func_800DF7E8(u8);
    void func_800DF830(s32);
    s32 model;

    model = func_800BFC34(arg4);
    func_800DF428((f32)func_800D2F20());
    func_800DF470(1);
    func_800DF830(1);
    func_800DF3E0();
    func_800DF7E8(func_800D731C(arg4));
    func_800DE448(arg1, arg2, arg3, NULL, model);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E993C0/func_800BFB58.s")

s32 func_800BFC34(s32 arg0)
{
    return func_800D674C(arg0);
}

void func_800BFC54()
{
    func_800D6B0C();
}

void func_800BFC74()
{
    func_800D62E4();
}

void func_800BFC94()
{
    func_800D674C();
}

void func_800BFCB4(void) {
}

void func_800BFCBC(void) {
}

void func_800BFCC4(s32 arg0) {
}
