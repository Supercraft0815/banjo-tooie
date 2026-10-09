#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fantasy/onion/func_80800000_chfantasyonion.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fantasy/onion/func_808000BC_chfantasyonion.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fantasy/onion/func_80800254_chfantasyonion.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fantasy/onion/func_80800624_chfantasyonion.s")

/* extern */

void func_808006E0_chfantasyonion(void *arg0) {
    s32 func_800E87E0(s32, void *);
    s32 temp_v0;

    temp_v0 = (*(s32 *)((s8 *)(arg0) + (0x18)));
    if (temp_v0 != 0) {
        func_800E87E0(temp_v0 & 0xFF, arg0);
        (*(s32 *)((s8 *)(arg0) + (0x18))) = 0;
    }
}

OSThread *chfantasyonion_entrypoint_0(void)
{
    extern u8 D_80800754_chfantasyonion[];

    return (OSThread *) D_80800754_chfantasyonion;
}
