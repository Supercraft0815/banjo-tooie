#include "core2/1E76500.h"

s32 func_8009CC10() 
{
    return 0x84;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E76500/func_8009CC18.s")

s32 func_8009CC68(PlayerState *self) {
    u8 temp_a1;
    u8 *temp_v1;

    temp_v1 = (*(u8 **)((s8 *)(self) + (0xF0)));
    temp_a1 = (*(u8 *)((s8 *)(temp_v1) + (0x80)));
    if (temp_a1 == 0) {
        return 0;
    }
    return (s32) (*(u8 *)((s8 *)((u8 *)temp_v1 + ((u32)temp_a1 << 4)) - 0x10));
}

void func_8009CC90(void *arg0) {
    (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0xF0)))) + (0x81))) = 0;
    (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0xF0)))) + (0x80))) = 0;
}

void func_8009CCA4(PlayerState *arg0) {
    void func_8009BDAC(PlayerState *, f32);
    int temp_v1;
    u8 *temp_v0;

    temp_v0 = (*(u8 **)((s8 *)(arg0) + (0xF0)));
    temp_v1 = (*(u8 *)((s8 *)(temp_v0) + (0x80)));
    if (temp_v1 != 0) {
        (*(u8 *)((s8 *)(temp_v0) + (0x80))) = (u8) (temp_v1 - 1);
        if ((*(u8 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0xF0)))) + (0x80))) == 0) {
            func_8009BDAC(arg0, 1.2f);
            (*(s8 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0xF0)))) + (0x81))) = 0;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E76500/func_8009CCFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E76500/func_8009CD70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E76500/func_8009CDE0.s")

void func_8009CEE8(void *arg0) {
    void *temp_v0;

    temp_v0 = (*(void **)((s8 *)(arg0) + (0xF0)));
    if ((*(u8 *)((s8 *)(temp_v0) + (0x80))) != 0) {
        (*(s8 *)((s8 *)(temp_v0) + (0x81))) = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E76500/func_8009CF04.s")
