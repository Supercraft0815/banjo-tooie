#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/ufoextdoor/func_80800000_chufoextdoor.s")

OSThread *chufoextdoor_entrypoint_0(void)
{
    extern u8 D_80800148_chufoextdoor[];

    return (OSThread *) D_80800148_chufoextdoor;
}
