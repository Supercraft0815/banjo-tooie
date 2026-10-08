#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/stationdoors/func_80800000_chfactorystationdoors.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/stationdoors/func_80800054_chfactorystationdoors.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/stationdoors/func_80800158_chfactorystationdoors.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/stationdoors/func_8080019C_chfactorystationdoors.s")

OSThread *chfactorystationdoors_entrypoint_0(void)
{
    extern u8 D_80800268_chfactorystationdoors[];

    return (OSThread *) D_80800268_chfactorystationdoors;
}
