#include "common.h"

OSThread *chfairgroundworker_entrypoint_0(void)
{
    extern u8 D_80800308_chfairgroundworker[];

    return (OSThread *) D_80800308_chfairgroundworker;
}

OSThread *chfairgroundworker_entrypoint_1(void)
{
    extern u8 D_80800350_chfairgroundworker[];

    return (OSThread *) D_80800350_chfairgroundworker;
}

OSThread *chfairgroundworker_entrypoint_2(void)
{
    extern u8 D_80800398_chfairgroundworker[];

    return (OSThread *) D_80800398_chfairgroundworker;
}

OSThread *chfairgroundworker_entrypoint_3(void)
{
    extern u8 D_808003E0_chfairgroundworker[];

    return (OSThread *) D_808003E0_chfairgroundworker;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fair/groundworker/func_80800030_chfairgroundworker.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fair/groundworker/func_80800098_chfairgroundworker.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fair/groundworker/func_808000FC_chfairgroundworker.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fair/groundworker/func_8080013C_chfairgroundworker.s")
