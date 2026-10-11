#include "common.h"

OSThread *chchompaslunch_entrypoint_0(void)
{
    extern u8 D_808003E0_chchompaslunch[];

    return (OSThread *) D_808003E0_chchompaslunch;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/ompaslun/func_8080000C_chchompaslunch.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/ompaslun/func_80800070_chchompaslunch.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/ompaslun/func_80800118_chchompaslunch.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/ompaslun/func_8080017C_chchompaslunch.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/ompaslun/func_80800250_chchompaslunch.s")

void func_8080037C_chchompaslunch(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_3(Actor *, f32 *, u32 *, f32);
    extern u32 D_808004A4_chchompaslunch;
    _subaddieaudioquick_entrypoint_3(arg0, arg0->position, &D_808004A4_chchompaslunch, 0.0f);
}
