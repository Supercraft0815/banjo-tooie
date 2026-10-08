#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bottles/dead/func_80800000_chbottlesdead.s")

void func_80800034_chbottlesdead()
{
    func_8010C964();
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bottles/dead/func_80800054_chbottlesdead.s")

OSThread *chbottlesdead_entrypoint_0(void)
{
    extern u8 D_808000C0_chbottlesdead[];

    return (OSThread *) D_808000C0_chbottlesdead;
}
