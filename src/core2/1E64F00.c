#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E64F00/func_8008B610.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E64F00/func_8008B64C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E64F00/func_8008B6E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E64F00/func_8008B768.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E64F00/func_8008B850.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E64F00/func_8008B8E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E64F00/func_8008B90C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E64F00/func_8008B954.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E64F00/func_8008B9C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E64F00/func_8008BA5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E64F00/func_8008BAC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E64F00/func_8008BBC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E64F00/func_8008BBF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E64F00/func_8008BC2C.s")

void func_8008BC4C(s32 arg0)
{
    func_8008BBF0(arg0,0x2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E64F00/func_8008BC6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E64F00/func_8008BC94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E64F00/func_8008BCB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E64F00/func_8008BCEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E64F00/func_8008BD1C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E64F00/func_8008BD3C.s")

void func_8008BD74(s32 arg0)
{
    func_8008BCEC(arg0,0x2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E64F00/func_8008BD94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E64F00/func_8008BEB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E64F00/func_8008C038.s")

void func_8008C0AC(s8 *arg0)
{
    arg0[0x1B] = 1;
}

s32 func_8008C0B8(void)
{
	return 0x20;
}

s32 func_8008C0C0(s16 *arg0)
{
    return arg0[12];
}

f32 func_8008C0C8(f32 *arg0)
{
    return arg0[4];
}

f32 func_8008C0D0(f32 *arg0)
{
    return arg0[5];
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E64F00/func_8008C0D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E64F00/func_8008C124.s")

void func_8008C1B8(s16 *arg0, s32 arg1) {
    arg0[12] = arg1;
}

void func_8008C1C0(f32 *arg0, f32 arg1) {
    arg0[4] = arg1;
}

void func_8008C1CC(s8 *arg0, s32 arg1) {
    arg0[30] = arg1;
}

void func_8008C1D4(s32 *arg0, s32 arg1) {
    arg0[0] = arg1;
}

void func_8008C1DC(s32 *arg0, s32 arg1) {
    arg0[1] = arg1;
}

void func_8008C1E4(f32 *arg0, f32 arg1) {
    arg0[5] = arg1;
}

void func_8008C1F0(void *arg0, s32 arg1) {
    (*(s8 *)((s8 *)(arg0) + (0x1A))) = 1;
}

/* extern */

void func_8008C200(s16 arg0, s32 arg1, s32 arg2) {
    s32 func_8008BD1C(s32);
    s32 func_800AE1E8(s16, s32, s32);
    func_800AE1E8(arg0, arg1, func_8008BD1C(arg2));
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E64F00/func_8008C238.s")

void func_8008C270(s8 *arg0) {
    arg0[0x1B] = 2;
}

/* extern */

void func_8008C27C(void) {
    s32 func_8008BD1C();
    func_8008BD1C();
}
