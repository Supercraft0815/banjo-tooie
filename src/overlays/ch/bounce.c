#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bounce/chbounce_entrypoint_0.s")

void chbounce_entrypoint_1(void) {
}

void chbounce_entrypoint_2(f32 arg0) {
    extern f32 D_8012716C;
    *(f32 *)((u8 *)&D_8012716C + 28) = arg0;
}

void chbounce_entrypoint_3(f32 arg0) {
    extern f32 D_8012716C;
    *(f32 *)((u8 *)&D_8012716C + 36) = arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bounce/chbounce_entrypoint_4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bounce/func_80800078_chbounce.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bounce/func_80800190_chbounce.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bounce/chbounce_entrypoint_5.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bounce/chbounce_entrypoint_6.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bounce/chbounce_entrypoint_7.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bounce/func_808007B8_chbounce.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bounce/chbounce_entrypoint_8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bounce/chbounce_entrypoint_9.s")

s32 chbounce_entrypoint_10(Actor *arg0) {
    void* func_80100094(Actor*, u32);
    return ((u32) (*(u32 *)((s8 *)(func_80100094(arg0, 2U)) + (0x24))) >> 0x1F) == 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bounce/func_80800F74_chbounce.s")
