#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/waterfall/grill/func_80800000_chwaterfallgrill.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/waterfall/grill/func_8080008C_chwaterfallgrill.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/waterfall/grill/func_808001E0_chwaterfallgrill.s")

/* extern */

void chwaterfallgrill_entrypoint_0(s32 arg0, s32 arg1) {
    s32 func_800DA524(s32);
    s32 func_800EA05C();
    s32 func_80101180(s32, s32, s32);
    if (func_800EA05C() == 0xC7) {
        func_80101180(0x11B, 8, 0);
        return;
    }
    func_800DA524(0x9F2);
}

OSThread *chwaterfallgrill_entrypoint_1(void)
{
    extern u8 D_80800330_chwaterfallgrill[];

    return (OSThread *) D_80800330_chwaterfallgrill;
}
