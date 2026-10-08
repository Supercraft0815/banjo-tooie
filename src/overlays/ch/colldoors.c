#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/colldoors/func_80800000_chcolldoors.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/colldoors/func_808000B8_chcolldoors.s")

OSThread *chcolldoors_entrypoint_0(void)
{
    extern u8 D_80800280_chcolldoors[];

    return (OSThread *) D_80800280_chcolldoors;
}
