#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/perspexbox/func_80800000_chperspexbox.s")

OSThread *chperspexbox_entrypoint_0(void)
{
    extern u8 D_80800138_chperspexbox[];

    return (OSThread *) D_80800138_chperspexbox;
}
