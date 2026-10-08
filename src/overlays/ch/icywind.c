#include "common.h"

OSThread *chicywind_entrypoint_0(void)
{
    extern u8 D_80800300_chicywind[];

    return (OSThread *) D_80800300_chicywind;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/icywind/func_8080000C_chicywind.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/icywind/func_80800044_chicywind.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/icywind/func_808001AC_chicywind.s")
