#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/traindoorswitch/func_80800000_chdinotraindoorswitch.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/traindoorswitch/func_8080003C_chdinotraindoorswitch.s")

OSThread *chdinotraindoorswitch_entrypoint_0(void)
{
    extern u8 D_80800080_chdinotraindoorswitch[];

    return (OSThread *) D_80800080_chdinotraindoorswitch;
}
