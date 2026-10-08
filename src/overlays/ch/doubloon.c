#include "ch/doubloon.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/doubloon/func_80800000_chdoubloon.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/doubloon/func_8080000C_chdoubloon.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/doubloon/chdoubloon_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/doubloon/chdoubloon_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/doubloon/func_808001D4_chdoubloon.s")

OSThread *chdoubloon_entrypoint_2(void)
{
    extern u8 D_808002A0_chdoubloon[];

    return (OSThread *) D_808002A0_chdoubloon;
}
