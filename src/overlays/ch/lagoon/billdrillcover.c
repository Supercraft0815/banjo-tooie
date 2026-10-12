#include "common.h"

OSThread *chlagoonbilldrillcover_entrypoint_0(void)
{
    extern u8 D_80800330_chlagoonbilldrillcover[];

    return (OSThread *) D_80800330_chlagoonbilldrillcover;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lagoon/billdrillcover/func_8080000C_chlagoonbilldrillcover.s")

/* extern */

void func_80800094_chlagoonbilldrillcover(Actor *arg0) {
    s32 _subaddieDll_entrypoint_6(Actor*, s32);
    s32 func_8080024C_chlagoonbilldrillcover(Actor *);
    if (((((u32) (*(u16 *)((s8 *)(arg0) + (0x72)))) >> 0xA) == 2) && (_subaddieDll_entrypoint_6(arg0, 0xB) != 0)) {
        func_8080024C_chlagoonbilldrillcover(arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lagoon/billdrillcover/func_808000DC_chlagoonbilldrillcover.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lagoon/billdrillcover/func_8080024C_chlagoonbilldrillcover.s")
