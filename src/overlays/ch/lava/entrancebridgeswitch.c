#include "ch/lavaentrancebridgeswitch.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lava/entrancebridgeswitch/func_80800000_chlavaentrancebridgeswitch.s")

void func_8080005C_chlavaentrancebridgeswitch(s32 arg0)
{
    _chswitch_entrypoint_7(arg0,FLAG_391_PROGRESS_IoH_HFP_BRIDGE_EXTENDED);
    _chswitch_entrypoint_9(arg0);
}

OSThread *chlavaentrancebridgeswitch_entrypoint_0(void)
{
    extern u8 D_808000A0_chlavaentrancebridgeswitch[];

    return (OSThread *) D_808000A0_chlavaentrancebridgeswitch;
}
