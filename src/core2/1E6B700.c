#include "common.h"

s32 func_80091E10(void)
{
	return 0x4;
}

void func_80091E18(s32 arg0) 
{
}
void func_80091E20(u8 *arg0) {
    s32 func_80091E48(s32, s32);
    (*(s8 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x48)))) + (3))) = 0;
    func_80091E48((s32) arg0, 0x7F);
}

s32 func_80091E48(s32 arg0, s32 arg1) {
    u8 *data;

    data = *(u8 **)(arg0 + 0x48);
    data[data[3]] = arg1;
    data = *(u8 **)(arg0 + 0x48);
    data[3]++;
}

void func_80091E6C(void *arg0) {
    void *temp_v0;

    temp_v0 = (*(void **)((s8 *)(arg0) + (0x48)));
    (*(u8 *)((s8 *)(temp_v0) + (3))) = (u8) ((*(u8 *)((s8 *)(temp_v0) + (3))) - 1);
}

s32 func_80091E80(u8 *arg0, s32 arg1) {
    struct Data { u8 bytes[256]; };
    struct Data *temp_v1;

    temp_v1 = *(struct Data **)(arg0 + 0x48);
    return arg1 == (temp_v1->bytes[temp_v1->bytes[3] - 1] & arg1);
}

s32 func_80091EA0(void)
{
	return 0x1;
}

void func_80091EA8(s32 arg0)
{
    func_80091F74(arg0,0);
}

void func_80091EC8(void *arg0) {
    **(u8 **)((u8 *)arg0 + 0x4C) = 0;
    func_80091F74(arg0, 1);
}

void func_80091EF0(s32 arg0) {
    s32 func_80091FE4(void);
    if (func_80091FE4() != 0) {
        func_80091F74(arg0, 3);
    } else {
        func_80091F74(arg0, 2);
    }
}

void func_80091F30(void *arg0) {
    s32 func_80091FE4(void);
    if (**(u8 **)((u8 *)arg0 + 0x4C) == 2 && func_80091FE4() != 0) {
        func_80091F74(arg0, 3);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6B700/func_80091F74.s")

/* extern */

s32 func_80091FE4(void) {
    s32 func_800DB9B0();
    return func_800DB9B0() == 0;
}
