#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/climbbase/func_80800000_chclimbbase.s")

/* extern */

s32 func_808000FC_chclimbbase(void) {
    s32 _gclevel_entrypoint_4(s32);
    if (_gclevel_entrypoint_4(0x80) != 0) {
        return 2;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/climbbase/func_80800128_chclimbbase.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/climbbase/func_80800200_chclimbbase.s")

OSThread *chclimbbase_entrypoint_0(void)
{
    extern u8 D_808003D0_chclimbbase[];

    return (OSThread *) D_808003D0_chclimbbase;
}

OSThread *chclimbbase_entrypoint_1(void)
{
    extern u8 D_80800418_chclimbbase[];

    return (OSThread *) D_80800418_chclimbbase;
}
