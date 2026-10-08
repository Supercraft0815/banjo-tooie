#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/waterfall/grill/func_80800000_chwaterfallgrill.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/waterfall/grill/func_8080008C_chwaterfallgrill.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/waterfall/grill/func_808001E0_chwaterfallgrill.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/waterfall/grill/chwaterfallgrill_entrypoint_0.s")

OSThread *chwaterfallgrill_entrypoint_1(void)
{
    extern u8 D_80800330_chwaterfallgrill[];

    return (OSThread *) D_80800330_chwaterfallgrill;
}
