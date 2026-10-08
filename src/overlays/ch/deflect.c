#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/deflect/func_80800000_chdeflect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/deflect/func_80800034_chdeflect.s")

OSThread *chdeflect_entrypoint_0(void)
{
    extern u8 D_80800090_chdeflect[];

    return (OSThread *) D_80800090_chdeflect;
}
