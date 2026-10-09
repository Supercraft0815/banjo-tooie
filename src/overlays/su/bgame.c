#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/bgame/susubgame_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/bgame/susubgame_entrypoint_1.s")

u8 susubgame_entrypoint_2(s32 arg0, u8 *arg1) {
    return *arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/bgame/susubgame_entrypoint_3.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/bgame/susubgame_entrypoint_4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/bgame/susubgame_entrypoint_5.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/bgame/susubgame_entrypoint_6.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/bgame/susubgame_entrypoint_7.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/bgame/susubgame_entrypoint_8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/bgame/susubgame_entrypoint_9.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/bgame/susubgame_entrypoint_10.s")

/* extern */

void susubgame_entrypoint_11(s32 arg0) {
    s32 func_800CE88C(s32, s32);
    s32 func_800CEAA8();
    if (func_800CEAA8() != 0) {
        func_800CE88C(arg0, 0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/bgame/func_8080078C_susubgame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/bgame/func_80800814_susubgame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/bgame/func_808008DC_susubgame.s")

void susubgame_entrypoint_12(void *arg0, void *arg1) {
    (*(f32 *)((s8 *)(arg0) + (8))) = (f32) (*(f32 *)((s8 *)(arg1) + (0)));
    (*(f32 *)((s8 *)(arg0) + (0xC))) = (f32) (*(f32 *)((s8 *)(arg1) + (4)));
    (*(f32 *)((s8 *)(arg0) + (0x10))) = (f32) (*(f32 *)((s8 *)(arg1) + (8)));
    (*(f32 *)((s8 *)(arg0) + (0x14))) = (f32) (*(f32 *)((s8 *)(arg1) + (0xC)));
}
