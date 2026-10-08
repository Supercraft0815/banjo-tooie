#include "ch/flysaucerdoor.h"

OSThread *chflysaucerdoor_entrypoint_0(void)
{
    extern u8 D_80800160_chflysaucerdoor[];

    return (OSThread *) D_80800160_chflysaucerdoor;
}

OSThread *chflysaucerdoor_entrypoint_1(void)
{
    extern u8 D_808001A8_chflysaucerdoor[];

    return (OSThread *) D_808001A8_chflysaucerdoor;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flysaucerdoor/func_80800018_chflysaucerdoor.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flysaucerdoor/func_8080006C_chflysaucerdoor.s")

void func_80800140_chflysaucerdoor(s32 arg0)
{
    _chswitch_entrypoint_14(arg0,FLAG0_008_UNK);
}

