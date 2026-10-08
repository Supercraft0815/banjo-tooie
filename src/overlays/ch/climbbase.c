#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/climbbase/func_80800000_chclimbbase.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/climbbase/func_808000FC_chclimbbase.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/climbbase/func_80800128_chclimbbase.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/climbbase/func_80800200_chclimbbase.s")

OSThread *chclimbbase_entrypoint_0(void)
{
    extern u8 D_808003D0_chclimbbase[];

    return (OSThread *) D_808003D0_chclimbbase;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/climbbase/chclimbbase_entrypoint_1.s")
