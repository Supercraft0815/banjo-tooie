#include "common.h"

OSThread *chdinocoaster_entrypoint_0(void)
{
    extern u8 D_808004E0_chdinocoaster[];

    return (OSThread *) D_808004E0_chdinocoaster;
}

/* extern */

void func_8080000C_chdinocoaster(void *arg0) {
    s32 _sucoaster_entrypoint_0(void *, s32);
    s32 func_80102FDC(void *, f32);
    _sucoaster_entrypoint_0(arg0, 0);
    func_80102FDC(arg0, (*(f32 *)((s8 *)(arg0) + (0x38))) * 1.25f);
    (*(f32 *)((s8 *)(arg0) + (0x50))) = 0.0f;
    (*(f32 *)((s8 *)(arg0) + (0x28))) = 0.0f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/coaster/func_80800064_chdinocoaster.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/coaster/func_808001C8_chdinocoaster.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/coaster/func_808002CC_chdinocoaster.s")
