#include "common.h"

OSThread *chbadshad_entrypoint_0(void)
{
    extern u8 D_80800A10_chbadshad[];

    return (OSThread *) D_80800A10_chbadshad;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bad/shad/func_8080000C_chbadshad.s")

void func_8080082C_chbadshad(Actor *arg0);

void func_80800090_chbadshad(Actor *arg0) { if (!arg0->unk64_17 && (s32) arg0->actorData[0] < func_8001211C() - 1) func_8080082C_chbadshad(arg0); }

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bad/shad/func_808000E0_chbadshad.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bad/shad/func_8080028C_chbadshad.s")

/* extern */

void chbadshad_entrypoint_1(void *arg0, void *arg1, f32 arg2) {
    Actor *func_80800664_chbadshad(void *, void *);
    Actor *temp_v0;

    temp_v0 = func_80800664_chbadshad(arg0, arg1);
    if (temp_v0 != NULL) {
        temp_v0->scale = arg2;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bad/shad/chbadshad_entrypoint_2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bad/shad/chbadshad_entrypoint_3.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bad/shad/chbadshad_entrypoint_4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bad/shad/func_80800664_chbadshad.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bad/shad/func_8080078C_chbadshad.s")

void func_8080082C_chbadshad(Actor *arg0) {
    void func_800FFAB0(Actor*);
    Actor* func_80106790(Unk80132ED0 *);
    Unk80132ED0 *temp_a1;

    temp_a1 = arg0->pad40;
    if (temp_a1 != NULL) {
        func_80106790(temp_a1)->pad40 = 0;
    }
    func_800FFAB0(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bad/shad/func_8080086C_chbadshad.s")
