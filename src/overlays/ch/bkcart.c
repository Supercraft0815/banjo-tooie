#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bkcart/func_80800000_chbkcart.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bkcart/func_80800130_chbkcart.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bkcart/func_808004DC_chbkcart.s")

OSThread *chbkcart_entrypoint_0(void)
{
    extern u8 D_80800880_chbkcart[];

    return (OSThread *) D_80800880_chbkcart;
}
