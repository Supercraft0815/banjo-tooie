#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/drums/func_80800000_chfactorydrums.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/drums/func_80800130_chfactorydrums.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/drums/func_808002B8_chfactorydrums.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/drums/func_808003A8_chfactorydrums.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/drums/func_808003DC_chfactorydrums.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/drums/chfactorydrums_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/drums/chfactorydrums_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/drums/func_80800CD0_chfactorydrums.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/drums/func_80800D90_chfactorydrums.s")

OSThread *chfactorydrums_entrypoint_2(void)
{
    extern u8 D_8080125C_chfactorydrums[];

    return (OSThread *) D_8080125C_chfactorydrums;
}
