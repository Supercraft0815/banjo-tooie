#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stadiumdoors/func_80800000_chstadiumdoors.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stadiumdoors/func_808000FC_chstadiumdoors.s")

OSThread *chstadiumdoors_entrypoint_0(void)
{
    extern u8 D_80800280_chstadiumdoors[];

    return (OSThread *) D_80800280_chstadiumdoors;
}
