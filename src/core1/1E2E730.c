#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E2E730/func_80016C00.s")

/* extern */

void func_80016DA0(s32 arg0, s32 arg1) {
    s32 func_800D5B24();
    s32 func_800D674C(s32);
    s32 func_800D70D0(s32);
    s32 func_800D71F4(s32);
    s32 func_800D73CC(s32);
    s32 sp1C;
    s32 temp_a0;

    temp_a0 = arg0 + 0x1DDD;
    sp1C = temp_a0;
    if (func_800D73CC(temp_a0) == 0) {
        if (arg1 != 0) {
            func_800D5B24();
        }
        func_800D674C(sp1C);
        func_800D70D0(1);
        func_800D71F4(1);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E2E730/func_80016DF8.s")

void func_80016E7C(void) {
    s32 func_80016DF8(s32);
    extern u16 D_8007AE78;
    s32 var_s0;

    var_s0 = 0;
    if ((s32) D_8007AE78 > 0) {
        do {
            func_80016DF8(var_s0);
            var_s0 += 1;
        } while (var_s0 < (s32) D_8007AE78);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E2E730/func_80016ED0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E2E730/func_80017070.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E2E730/func_800170D4.s")

s16 func_80017108(u8 arg0) {
    extern s16 D_8007A20C;
    return *(s16 *)((u8 *)&D_8007A20C + arg0 * 0x274);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E2E730/func_8001713C.s")

s32 func_80017210(u8 index) {
    typedef struct { s32 state; u8 pad[0x270]; } MusicSlotSeqp;
    extern MusicSlotSeqp D_8007A1AC[];
    return D_8007A1AC[index].state;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E2E730/func_80017244.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E2E730/func_800172D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E2E730/func_80017330.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E2E730/func_800173B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E2E730/func_80017404.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E2E730/func_800174C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E2E730/func_80017534.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E2E730/func_800175A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E2E730/func_800175F0.s")

u32 func_80017764(s32 arg0) {
    extern u16 D_8003F600[];
    return ((u16 *)&D_8003F600)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E2E730/func_80017778.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E2E730/func_800177C4.s")

u8 *func_80017810(s32 arg0) {
    extern s32 D_80079FA0;
    return (u8 *)((arg0 * 0x274) + 0x1E0 + (s32)&D_80079FA0);
}

void func_80017840(void) {
}