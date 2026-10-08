#include "common.h"

OSThread *changlerbossdoor_entrypoint_0(void)
{
    extern u8 D_80800110_changlerbossdoor[];

    return (OSThread *) D_80800110_changlerbossdoor;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/anglerboss/door/func_8080000C_changlerbossdoor.s")
