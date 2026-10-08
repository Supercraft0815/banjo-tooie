#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lava/entrancebridge/func_80800000_chlavaentrancebridge.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lava/entrancebridge/func_80800010_chlavaentrancebridge.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lava/entrancebridge/func_8080008C_chlavaentrancebridge.s")

OSThread *chlavaentrancebridge_entrypoint_0(void)
{
    extern u8 D_80800230_chlavaentrancebridge[];

    return (OSThread *) D_80800230_chlavaentrancebridge;
}
