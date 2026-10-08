#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fair/coin/func_80800000_chfaircoin.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fair/coin/chfaircoin_entrypoint_0.s")

OSThread *chfaircoin_entrypoint_1(void)
{
    extern u8 D_8080015C_chfaircoin[];

    return (OSThread *) D_8080015C_chfaircoin;
}
