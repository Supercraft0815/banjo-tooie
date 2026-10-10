#include "common.h"

OSThread *chdrips_entrypoint_0(void)
{
    extern u8 D_80800610_chdrips[];

    return (OSThread *) D_80800610_chdrips;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/drips/chdrips_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/drips/chdrips_entrypoint_2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/drips/func_80800260_chdrips.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/drips/func_80800394_chdrips.s")

void func_808005CC_chdrips(Actor *arg0) {
    u32* func_80100074(Actor*, u32, u32);
    func_80100074(arg0, 0U, 0U);
}
