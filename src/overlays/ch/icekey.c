#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/icekey/func_80800000_chicekey.s")

OSThread *chicekey_entrypoint_0(void)
{
    extern u8 D_808000EC_chicekey[];

    return (OSThread *) D_808000EC_chicekey;
}
