#include "common.h"

OSThread *chweldarbossdoors_entrypoint_0(void)
{
    extern u8 D_80800270_chweldarbossdoors[];

    return (OSThread *) D_80800270_chweldarbossdoors;
}

OSThread *chweldarbossdoors_entrypoint_1(void)
{
    extern u8 D_808002B8_chweldarbossdoors[];

    return (OSThread *) D_808002B8_chweldarbossdoors;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/weldarboss/doors/func_80800018_chweldarbossdoors.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/weldarboss/doors/func_808000E0_chweldarbossdoors.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/weldarboss/doors/func_80800140_chweldarbossdoors.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/weldarboss/doors/func_80800194_chweldarbossdoors.s")
