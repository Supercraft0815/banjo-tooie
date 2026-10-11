#include "common.h"

void func_80800000_chlavaentrancebridge(void *arg0) {
    (*(f32 *)((s8 *)(arg0) + (0x58))) = -2750.0f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lava/entrancebridge/func_80800010_chlavaentrancebridge.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lava/entrancebridge/func_8080008C_chlavaentrancebridge.s")

OSThread *chlavaentrancebridge_entrypoint_0(void)
{
    extern u8 D_80800230_chlavaentrancebridge[];

    return (OSThread *) D_80800230_chlavaentrancebridge;
}
