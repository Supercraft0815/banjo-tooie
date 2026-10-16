#include "common.h"

s32 func_800A21C0() 
{
    return 0x14;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7BAB0/func_800A21C8.s")

void func_800A22A8(s32 arg0)
{
    func_800A25DC(arg0,0);
}

void func_800A22C8(s32 *arg0, s32 *arg1) {
    s32 i;

    for (i = 0; i < 3; i++) {
        arg0[i] = (arg0[i] * arg1[i]) / 256;
    }
}

/* extern */

void func_800A2314(void *arg0, s32 *arg1) {
    s32 sp1C[3];
    func_800C87B8(sp1C);
    func_800A22C8(sp1C, arg1);
    func_800B38A8(*(s32 *)((u8 *)(*(u32 *)((u8 *)arg0 + 0xB4)) + 4), sp1C);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7BAB0/func_800A235C.s")

void func_800A2534(s32 *arg0)
{
    *(u8 *)(arg0[0xB4 / 4] + 3) = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7BAB0/func_800A2540.s")

u32 func_800A25D0(void *arg0) {
    return *(u8 *)((u8 *)*(void **)((u8 *)arg0 + 180) + 2);
}

int func_800A25DC(s32 arg0, s32 arg1) {
    s32 func_800B3310(s32);
    s32 func_800B3370(s32);
    s32 temp_a0;
    void *temp_v0;

    if (arg1 != 0) {
        *(s8 *)((u8 *)*(void **)(arg0 + 0xB4) + 2) = 1;
    } else {
        *(u8 *)((u8 *)*(void **)(arg0 + 0xB4) + 2) = 0;
    }
    temp_v0 = *(void **)(arg0 + 0xB4);
    if (*(u8 *)((u8 *)temp_v0 + 2) != 0) {
        if (*(s32 *)((u8 *)temp_v0 + 4) == 0) {
            *(s32 *)((u8 *)*(void **)(arg0 + 0xB4) + 4) = func_800B3310(*(s8 *)temp_v0);
        }
    } else {
        temp_a0 = *(s32 *)((u8 *)temp_v0 + 4);
        if (temp_a0 != 0) {
            func_800B3370(temp_a0);
            *(s32 *)((u8 *)*(void **)(arg0 + 0xB4) + 4) = 0;
        }
    }
}

void func_800A266C(u8 *arg0) {
    s32 func_800B38E8(s32);
    s32 temp_a1;

    temp_a1 = (*(s32 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0xB4)))) + (4)));
    if (temp_a1 != 0) {
        (*(s32 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0xB4)))) + (4))) = func_800B38E8(temp_a1);
    }
}
