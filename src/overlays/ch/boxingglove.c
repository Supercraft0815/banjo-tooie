#include "common.h"

OSThread *chboxingglove_entrypoint_0(void)
{
    extern u8 D_80800708_chboxingglove[];

    return (OSThread *) D_80800708_chboxingglove;
}

OSThread *chboxingglove_entrypoint_1(void)
{
    extern u8 D_80800750_chboxingglove[];

    return (OSThread *) D_80800750_chboxingglove;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/boxingglove/func_80800018_chboxingglove.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/boxingglove/func_80800168_chboxingglove.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/boxingglove/func_808001CC_chboxingglove.s")

void func_808002AC_chboxingglove(void *arg0) {
    f32 temp_f0;

    temp_f0 = (*(f32 *)((s8 *)(arg0) + (8)));
    (*(u8 *)((s8 *)(arg0) + (0x65))) = (u8) ((*(u8 *)((s8 *)(arg0) + (0x65))) & 0xFFFE);
    (*(f32 *)((s8 *)(arg0) + (8))) = (f32) (temp_f0 - 70.0f);
    (*(f32 *)((s8 *)(arg0) + (0x28))) = temp_f0;
    (*(f32 *)((s8 *)(arg0) + (0x58))) = 1.0f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/boxingglove/func_808002E0_chboxingglove.s")

/* extern */

s32 func_808004F8_chboxingglove(void *arg0) {
    s32 func_800DA298(s32);
    s32 func_800FFA88(s32);
    s32 func_800FFAB0(void *);
    if (func_800DA298(0) != 0) {
        func_800FFAB0(arg0);
        func_800FFA88((*(s32 *)((s8 *)(arg0) + (0x3C))));
        return 1;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/boxingglove/func_80800544_chboxingglove.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/boxingglove/func_80800630_chboxingglove.s")
