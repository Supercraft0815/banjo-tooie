#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dodgemdoors/func_80800000_chdodgemdoors.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dodgemdoors/func_808000A0_chdodgemdoors.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dodgemdoors/func_8080026C_chdodgemdoors.s")

OSThread *chdodgemdoors_entrypoint_0(void)
{
    extern u8 D_80800374_chdodgemdoors[];

    return (OSThread *) D_80800374_chdodgemdoors;
}
