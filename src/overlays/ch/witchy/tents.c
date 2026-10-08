#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/witchy/tents/func_80800000_chwitchytents.s")

OSThread *chwitchytents_entrypoint_0(void)
{
    extern u8 D_80800050_chwitchytents[];

    return (OSThread *) D_80800050_chwitchytents;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/witchy/tents/chwitchytents_entrypoint_1.s")
