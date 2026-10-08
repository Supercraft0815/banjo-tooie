#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dummyjigsaw/func_80800000_chdummyjigsaw.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dummyjigsaw/func_80800128_chdummyjigsaw.s")

OSThread *chdummyjigsaw_entrypoint_0(void)
{
    extern u8 D_80800190_chdummyjigsaw[];

    return (OSThread *) D_80800190_chdummyjigsaw;
}
