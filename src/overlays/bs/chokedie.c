#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/chokedie/bschokedie_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/chokedie/bschokedie_entrypoint_1.s")

/* extern */

void bschokedie_entrypoint_2(s32 arg0) {
    s32 baroll_setIdeal(s32, f32);
    s32 func_800951B4();
    s32 func_8009BF5C(s32, f32);
    s32 func_800A4E30(s32);
    func_800951B4();
    func_8009BF5C(arg0, 0.0f);
    baroll_setIdeal(arg0, 0.0f);
    func_800A4E30(arg0);
}

s32 bschokedie_entrypoint_3(s32 arg0) {
    extern s32 D_808002B0_bschokedie[];
    return ((s32 *)&D_808002B0_bschokedie)[arg0];
}
