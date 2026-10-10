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

void func_80800018_chflysaucerdoor(Actor *arg0) {
    s32 _chdoormake_entrypoint_3(Actor*, f32, f32, f32, s32, s32);
    void _chdoormake_entrypoint_5(Actor*, f32);
    void _chdoormake_entrypoint_8(void*, u32);
    _chdoormake_entrypoint_3(arg0, arg0->rotation[1], 90.0f, 300.0f, 0x45, 8);
    _chdoormake_entrypoint_5(arg0, 3.5f);
    _chdoormake_entrypoint_8(arg0, 0x10U);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flysaucerdoor/func_8080006C_chflysaucerdoor.s")

void func_80800140_chflysaucerdoor(s32 arg0)
{
    _chswitch_entrypoint_14(arg0,FLAG0_008_UNK);
}

