#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/foodwarn/func_80800000_chfoodwarn.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/foodwarn/func_8080003C_chfoodwarn.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/foodwarn/func_80800074_chfoodwarn.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/foodwarn/func_808000D4_chfoodwarn.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/foodwarn/func_808001F4_chfoodwarn.s")

OSThread *chfoodwarn_entrypoint_0(void)
{
    extern u8 D_808002A8_chfoodwarn[];

    return (OSThread *) D_808002A8_chfoodwarn;
}
