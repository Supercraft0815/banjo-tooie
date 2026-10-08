#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/smalltrexdoor/func_80800000_chsmalltrexdoor.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/smalltrexdoor/func_80800150_chsmalltrexdoor.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/smalltrexdoor/func_80800244_chsmalltrexdoor.s")

OSThread *chsmalltrexdoor_entrypoint_0(void)
{
    extern u8 D_808002E0_chsmalltrexdoor[];

    return (OSThread *) D_808002E0_chsmalltrexdoor;
}
