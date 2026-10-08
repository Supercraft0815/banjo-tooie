#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/boggy/fish/func_80800000_chboggyfish.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/boggy/fish/func_80800064_chboggyfish.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/boggy/fish/func_8080018C_chboggyfish.s")

OSThread *chboggyfish_entrypoint_0(void)
{
    extern u8 D_80800220_chboggyfish[];

    return (OSThread *) D_80800220_chboggyfish;
}
