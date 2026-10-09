#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/quizremotectrl/func_80800000_chquizremotectrl.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/quizremotectrl/func_80800068_chquizremotectrl.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/quizremotectrl/func_8080012C_chquizremotectrl.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/quizremotectrl/func_808001BC_chquizremotectrl.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/quizremotectrl/func_808002C8_chquizremotectrl.s")

void func_808003A0_chquizremotectrl(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/quizremotectrl/func_808003A8_chquizremotectrl.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/quizremotectrl/func_80800410_chquizremotectrl.s")

s32 func_808005E4_chquizremotectrl(s32 arg0, s32 arg1, s32 arg2) {
    if (arg1 == 0xB) {
        return 3;
    }
    return 0;
}

OSThread *chquizremotectrl_entrypoint_0(void)
{
    extern u8 D_80800668_chquizremotectrl[];

    return (OSThread *) D_80800668_chquizremotectrl;
}
