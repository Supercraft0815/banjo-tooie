#include "common.h"

OSThread *chlightdemon_entrypoint_0(void)
{
    extern u8 D_80800140_chlightdemon[];

    return (OSThread *) D_80800140_chlightdemon;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/light/demon/func_8080000C_chlightdemon.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/light/demon/func_8080003C_chlightdemon.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/light/demon/func_80800060_chlightdemon.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/light/demon/func_808000D8_chlightdemon.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/light/demon/chlightdemon_entrypoint_1.s")
