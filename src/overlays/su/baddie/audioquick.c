#include "common.h"

/* extern */

void subaddieaudioquick_entrypoint_0(u8 arg0, s32 arg1) { void func_800C32C4(u8, s32); void func_800C3418(u8, s32); if (arg1 != 0) { func_800C3418(arg0, 1); func_800C32C4(arg0, 0x40); } else { func_800C3418(arg0, 2); } }

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/audioquick/subaddieaudioquick_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/audioquick/subaddieaudioquick_entrypoint_2.s")

/* extern */

s32 subaddieaudioquick_entrypoint_3(Actor *arg0, s32 arg1, s32 arg2, f32 arg3) {
    s32 func_80101E14(Actor*, f32);
    s32 subaddieaudioquick_entrypoint_2(Actor *, s32, s32);
    if (func_80101E14(arg0, arg3) != 0) {
        subaddieaudioquick_entrypoint_2(arg0, arg1, arg2);
        return 1;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/audioquick/subaddieaudioquick_entrypoint_4.s")
