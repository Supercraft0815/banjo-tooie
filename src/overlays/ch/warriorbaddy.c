#include "common.h"

OSThread *chwarriorbaddy_entrypoint_0(void)
{
    extern u8 D_80800128_chwarriorbaddy[];

    return (OSThread *) D_80800128_chwarriorbaddy;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/warriorbaddy/func_8080000C_chwarriorbaddy.s")
