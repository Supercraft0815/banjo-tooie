#include "common.h"

void func_80800000_badeathmatch(void *arg0) {
    (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x158)))) + (0x20))) = 1;
    (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x158)))) + (0x21))) = 0;
    (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x158)))) + (0x22))) = 0;
    (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x158)))) + (0x23))) = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/deathmatch/func_80800028_badeathmatch.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/deathmatch/badeathmatch_entrypoint_0.s")

/* extern */

void badeathmatch_entrypoint_1(void *arg0) {
    s32 aligned8_memset(s32, s32, s32);
    s32 func_800EA068(s32);
    s32 heap_alloc(s32);
    s32 temp_v0;

    if (func_800EA068(0x40) != 0) {
        temp_v0 = heap_alloc(0x30);
        (*(s32 *)((s8 *)(arg0) + (0x158))) = temp_v0;
        aligned8_memset(temp_v0, 0, 0x30);
        func_80800000_badeathmatch(arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/deathmatch/badeathmatch_entrypoint_2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/deathmatch/badeathmatch_entrypoint_3.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/deathmatch/badeathmatch_entrypoint_4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/deathmatch/badeathmatch_entrypoint_5.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/deathmatch/badeathmatch_entrypoint_6.s")

void badeathmatch_entrypoint_7(void *arg0, s32 arg1) {
    *(s8 *)((u8 *)*(void **)((u8 *)arg0 + 344) + 32) = arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/deathmatch/badeathmatch_entrypoint_8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/deathmatch/badeathmatch_entrypoint_9.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/deathmatch/badeathmatch_entrypoint_10.s")

void badeathmatch_entrypoint_11(void *arg0, s32 arg1, s32 arg2) {
    void *temp_v0;
    void *temp_v0_2;

    if (arg2 != 0) {
        temp_v0 = (*(void **)((s8 *)(arg0) + (0x158)));
        (*(u8 *)((s8 *)(temp_v0) + (0x23))) = (u8) ((*(u8 *)((s8 *)(temp_v0) + (0x23))) | arg1);
        return;
    }
    temp_v0_2 = (*(void **)((s8 *)(arg0) + (0x158)));
    (*(u8 *)((s8 *)(temp_v0_2) + (0x23))) = (u8) ((*(u8 *)((s8 *)(temp_v0_2) + (0x23))) & ~arg1);
}
