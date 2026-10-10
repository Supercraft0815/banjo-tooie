#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/waterfall/grillswitch/func_80800000_chwaterfallgrillswitch.s")

void func_80800054_chwaterfallgrillswitch(Actor *arg0) {
    void _chswitch_entrypoint_8(s16 *arg0, s32 arg1);
    void _chswitch_entrypoint_7(Actor*, s32);
    _chswitch_entrypoint_7(arg0, 0);
    _chswitch_entrypoint_8((s16 *) arg0, 0x201);
}

OSThread *chwaterfallgrillswitch_entrypoint_0(void)
{
    extern u8 D_80800090_chwaterfallgrillswitch[];

    return (OSThread *) D_80800090_chwaterfallgrillswitch;
}
