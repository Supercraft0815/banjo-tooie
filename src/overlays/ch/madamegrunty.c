#include "common.h"

OSThread *chmadamegrunty_entrypoint_0(void)
{
    extern u8 D_80800B50_chmadamegrunty[];

    return (OSThread *) D_80800B50_chmadamegrunty;
}

OSThread *chmadamegrunty_entrypoint_1(void)
{
    extern u8 D_80800B98_chmadamegrunty[];

    return (OSThread *) D_80800B98_chmadamegrunty;
}

/* extern */

void func_80800018_chmadamegrunty(void *arg0) {
    s32 func_800DA298(s32);
    s32 func_80101FDC(void *, s32);
    if (func_800DA298(0xA02) != 0) {
        func_80101FDC(arg0, 7);
        (*(f32 *)((s8 *)(arg0) + (0x58))) = 20.0f;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/madamegrunty/func_8080005C_chmadamegrunty.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/madamegrunty/func_80800198_chmadamegrunty.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/madamegrunty/func_80800200_chmadamegrunty.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/madamegrunty/func_808002BC_chmadamegrunty.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/madamegrunty/func_808003B0_chmadamegrunty.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/madamegrunty/func_80800460_chmadamegrunty.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/madamegrunty/func_80800564_chmadamegrunty.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/madamegrunty/func_80800670_chmadamegrunty.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/madamegrunty/func_80800784_chmadamegrunty.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/madamegrunty/func_8080082C_chmadamegrunty.s")

s32 func_80800898_chmadamegrunty(f32 arg0, f32 arg1, f32 arg2) {
    if ((arg0 <= arg2) && (arg2 < arg1)) {
        return 1;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/madamegrunty/func_808008D4_chmadamegrunty.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/madamegrunty/func_808009AC_chmadamegrunty.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/madamegrunty/func_80800A30_chmadamegrunty.s")
