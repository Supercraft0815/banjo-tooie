#include "common.h"

extern s32 D_80136F60;
extern s32 D_80136F64;

s32 func_8010C500(void *arg0) {
    s32 func_800CC338(s32 *, s32, s32);
    extern s32 D_80136F50;
    u32 temp_v0;
    u32 temp_v1;

    temp_v0 = (*(u32 *)((s8 *)(arg0) + (0x70)));
    temp_v1 = temp_v0 >> 0x19;
    if (temp_v1 == 0) {
        return 1;
    }
    return (func_800CC338(&D_80136F50, temp_v1 - 1, ((u32) (temp_v0 << 0x16) >> 0x1A) - 1) + 1) != 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE5DF0/func_8010C550.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE5DF0/func_8010C5C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE5DF0/func_8010C668.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE5DF0/func_8010C710.s")

/* extern */

s32 func_8010C754(void) {
    s32 func_8010C710();
    return (s32) sqrtf((f32) func_8010C710());
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE5DF0/func_8010C788.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE5DF0/func_8010C820.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE5DF0/func_8010C878.s")

/* extern */

void func_8010C908(s32 arg0, s32 arg1) {
    f32 func_8010A40C();
    s32 func_8010C878(s32, s32, f32);
    func_8010C878(arg0, arg1, func_8010A40C());
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE5DF0/func_8010C93C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE5DF0/func_8010C964.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE5DF0/func_8010C9B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE5DF0/func_8010C9FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE5DF0/func_8010CA74.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE5DF0/func_8010CAC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE5DF0/func_8010CB0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE5DF0/func_8010CB84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE5DF0/func_8010CBD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE5DF0/func_8010CC10.s")

void func_8010CCE0(void)
{
    extern s32 D_80136F8C;

    D_80136F8C = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE5DF0/func_8010CCEC.s")

void func_8010CD28(s32 arg0) {
    s32 func_800F1DF4(s32, s32 *);
    extern s32 D_80136F50;
    func_800F1DF4(arg0 + 4, &D_80136F50);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE5DF0/func_8010CD50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE5DF0/func_8010CD88.s")

void func_8010CE28(s32 arg0, f32 *arg1) {
    s32 func_800F18FC(s32, s32 *, f32 *);
    extern s32 D_80136F50;
    func_800F18FC(arg0 + 4, &D_80136F50, arg1);
    *arg1 = 360.0f - *arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE5DF0/func_8010CE70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE5DF0/func_8010CEAC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE5DF0/func_8010CEF8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE5DF0/func_8010CFBC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE5DF0/func_8010D09C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE5DF0/func_8010D12C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE5DF0/func_8010D1E8.s")

s32 func_8010D23C(void) {
    extern s16 D_80136F5C;

    return D_80136F5C;
}

s32 func_8010D248(void) {
    extern s16 D_80136F5E;

    return D_80136F5E;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE5DF0/func_8010D254.s")

s32 func_8010D278()
{
    return D_80136F60;
}

s32 func_8010D284()
{
    return D_80136F64;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE5DF0/func_8010D290.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE5DF0/func_8010D350.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE5DF0/func_8010D490.s")

void func_8010D5DC(s32 arg0,s32 arg1)
{
    func_8010114C(arg0,0x32,arg1);
}

/* extern */

void func_8010D600(s32 arg0) {
    s32 func_8008FE68(s32);
    s32 func_800E3980(s32);
    if (func_8010D23C() != 0) {
        func_8008FE68(arg0);
        return;
    }
    func_800E3980(arg0);
}

/* extern */

void func_8010D640(s32 arg0) {
    s32 func_8008FE68(s32);
    s32 func_800DB9B0();
    s32 func_800E3980(s32);
    if ((func_8010D23C() != 0) && (func_800DB9B0() == 0)) {
        func_8008FE68(arg0);
        return;
    }
    func_800E3980(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE5DF0/func_8010D690.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE5DF0/func_8010D6E0.s")
