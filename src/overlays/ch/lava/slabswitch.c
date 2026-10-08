#include "ch/lavaslabswitch.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lava/slabswitch/func_80800000_chlavaslabswitch.s")

void func_8080005C_chlavaslabswitch(s32 arg0)
{
    _chswitch_entrypoint_7(arg0,FLAG_38F_UNK);
    _chswitch_entrypoint_9(arg0);
}

OSThread *chlavaslabswitch_entrypoint_0(void)
{
    extern u8 D_808000A0_chlavaslabswitch[];

    return (OSThread *) D_808000A0_chlavaslabswitch;
}
