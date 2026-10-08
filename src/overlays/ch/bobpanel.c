#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bobpanel/func_80800000_chbobpanel.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bobpanel/func_8080004C_chbobpanel.s")

OSThread *chbobpanel_entrypoint_0(void)
{
    extern u8 D_808000C0_chbobpanel[];

    return (OSThread *) D_808000C0_chbobpanel;
}
