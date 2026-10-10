#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/audioquick/subaddieaudioquick_entrypoint_0.s")

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
