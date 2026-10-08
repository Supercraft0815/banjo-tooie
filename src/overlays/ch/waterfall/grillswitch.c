#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/waterfall/grillswitch/func_80800000_chwaterfallgrillswitch.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/waterfall/grillswitch/func_80800054_chwaterfallgrillswitch.s")

OSThread *chwaterfallgrillswitch_entrypoint_0(void)
{
    extern u8 D_80800090_chwaterfallgrillswitch[];

    return (OSThread *) D_80800090_chwaterfallgrillswitch;
}
