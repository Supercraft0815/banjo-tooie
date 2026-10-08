#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/crackarwall/func_80800000_chcrackarchwall.s")

OSThread *chcrackarchwall_entrypoint_0(void)
{
    extern u8 D_80800144_chcrackarchwall[];

    return (OSThread *) D_80800144_chcrackarchwall;
}
