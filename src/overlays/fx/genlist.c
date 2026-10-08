#include "common.h"

OSThread *fxgenlist_entrypoint_0(void)
{
    extern u8 D_80800030_fxgenlist[];

    return (OSThread *) D_80800030_fxgenlist;
}

OSThread *fxgenlist_entrypoint_1(void)
{
    extern u8 D_8080005C_fxgenlist[];

    return (OSThread *) D_8080005C_fxgenlist;
}

OSThread *fxgenlist_entrypoint_2(void)
{
    extern u8 D_808000A0_fxgenlist[];

    return (OSThread *) D_808000A0_fxgenlist;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/fx/genlist/fxgenlist_entrypoint_3.s")
