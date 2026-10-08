#include "common.h"

OSThread *chboilerbossdoor_entrypoint_0(void)
{
    extern u8 D_808000F0_chboilerbossdoor[];

    return (OSThread *) D_808000F0_chboilerbossdoor;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/boiler/bossdoor/func_8080000C_chboilerbossdoor.s")
