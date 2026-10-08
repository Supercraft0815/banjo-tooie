#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/traindoor/func_80800000_chdinotraindoor.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/traindoor/func_80800120_chdinotraindoor.s")

OSThread *chdinotraindoor_entrypoint_0(void)
{
    extern u8 D_808001D0_chdinotraindoor[];

    return (OSThread *) D_808001D0_chdinotraindoor;
}
