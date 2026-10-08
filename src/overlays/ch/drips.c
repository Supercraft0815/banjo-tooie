#include "common.h"

OSThread *chdrips_entrypoint_0(void)
{
    extern u8 D_80800610_chdrips[];

    return (OSThread *) D_80800610_chdrips;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/drips/chdrips_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/drips/chdrips_entrypoint_2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/drips/func_80800260_chdrips.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/drips/func_80800394_chdrips.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/drips/func_808005CC_chdrips.s")
