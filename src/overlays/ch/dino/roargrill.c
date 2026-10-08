#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/roargrill/func_80800000_chdinoroargrill.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/roargrill/func_80800028_chdinoroargrill.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/roargrill/func_80800124_chdinoroargrill.s")

OSThread *chdinoroargrill_entrypoint_0(void)
{
    extern u8 D_80800258_chdinoroargrill[];

    return (OSThread *) D_80800258_chdinoroargrill;
}
