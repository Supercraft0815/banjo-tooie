#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mole/_training/func_80800000_chmole_training.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mole/_training/func_80800034_chmole_training.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mole/_training/func_80800088_chmole_training.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mole/_training/func_80800270_chmole_training.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mole/_training/func_808003D4_chmole_training.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mole/_training/func_808004D0_chmole_training.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mole/_training/chmole_training_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mole/_training/func_808008E4_chmole_training.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mole/_training/func_80800988_chmole_training.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mole/_training/func_80800A48_chmole_training.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mole/_training/func_80800BA8_chmole_training.s")

void func_80800C28_chmole_training(void *arg0) {
    (*(u8 *)((s8 *)(arg0) + (0x72))) = (u8) (((*(u8 *)((s8 *)(arg0) + (0x72))) & 0xFF03) | 0x34);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mole/_training/func_80800C3C_chmole_training.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mole/_training/func_80800C70_chmole_training.s")

OSThread *chmole_training_entrypoint_1(void)
{
    extern u8 D_80800F30_chmole_training[];

    return (OSThread *) D_80800F30_chmole_training;
}
