#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/worlddoors/func_80800000_chworlddoors.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/worlddoors/func_80800068_chworlddoors.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/worlddoors/func_80800214_chworlddoors.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/worlddoors/func_80800388_chworlddoors.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/worlddoors/func_808006A8_chworlddoors.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/worlddoors/func_80800750_chworlddoors.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/worlddoors/func_80800798_chworlddoors.s")

OSThread *chworlddoors_entrypoint_0(void)
{
    extern u8 D_80800A04_chworlddoors[];

    return (OSThread *) D_80800A04_chworlddoors;
}
