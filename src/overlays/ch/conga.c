#include "ch/conga.h"

OSThread *chconga_entrypoint_0(void)
{
    extern u8 D_808006A0_chconga[];

    return (OSThread *) D_808006A0_chconga;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/conga/func_8080000C_chconga.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/conga/func_80800118_chconga.s")

void func_80800280_chconga(Actor* arg0) 
{
    _suexpression_entrypoint_8(arg0, 1);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/conga/func_808002A0_chconga.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/conga/func_80800374_chconga.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/conga/func_80800478_chconga.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/conga/func_808004BC_chconga.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/conga/func_80800538_chconga.s")

void func_80800618_chconga(Actor *arg0) {
    extern u32 D_80800714_chconga;
    extern u32 D_80800724_chconga;
    _subaddieaudioquick_entrypoint_4(arg0, arg0->position, &D_80800714_chconga, &D_80800724_chconga);
}
