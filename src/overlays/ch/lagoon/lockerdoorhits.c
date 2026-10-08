#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lagoon/lockerdoorhits/func_80800000_chlagoonlockerdoorhits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lagoon/lockerdoorhits/func_8080010C_chlagoonlockerdoorhits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lagoon/lockerdoorhits/func_808001B0_chlagoonlockerdoorhits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lagoon/lockerdoorhits/func_8080022C_chlagoonlockerdoorhits.s")

OSThread *chlagoonlockerdoorhits_entrypoint_0(void)
{
    extern u8 D_8080045C_chlagoonlockerdoorhits[];

    return (OSThread *) D_8080045C_chlagoonlockerdoorhits;
}
