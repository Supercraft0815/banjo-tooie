#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/pufferfish/func_80800000_chpufferfish.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/pufferfish/func_80800040_chpufferfish.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/pufferfish/func_80800274_chpufferfish.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/pufferfish/func_808003C8_chpufferfish.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/pufferfish/func_80800518_chpufferfish.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/pufferfish/func_8080086C_chpufferfish.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/pufferfish/func_8080093C_chpufferfish.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/pufferfish/func_80800AB0_chpufferfish.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/pufferfish/func_80800E20_chpufferfish.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/pufferfish/func_80800F30_chpufferfish.s")

OSThread *chpufferfish_entrypoint_0(void)
{
    extern u8 D_808012A8_chpufferfish[];

    return (OSThread *) D_808012A8_chpufferfish;
}
