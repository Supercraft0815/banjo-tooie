#include "common.h"

void chblink_entrypoint_0(u8 *arg0, s32 arg1) {
    u8 func_800DC128(s32, s32);
    f32 func_800DC178(f32, f32);
    (*(s32 *)((s8 *)(arg0) + (0x28))) = arg1;
    (*(f32 *)((s8 *)(arg0) + (0x18))) = func_800DC178(0.0f, 5.0f);
    (*(s32 *)((s8 *)(arg0) + (0x1C))) = func_800DC128(0, 0x14);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/blink/chblink_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/blink/func_808000CC_chblink.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/blink/func_80800118_chblink.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/blink/chblink_entrypoint_2.s")

/* extern */

void chblink_entrypoint_3(s16 arg0) {
    s32 func_8001B754(s16);
    func_8001B754(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/blink/chblink_entrypoint_4.s")
