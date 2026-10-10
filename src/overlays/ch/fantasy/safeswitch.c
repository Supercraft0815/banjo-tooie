#include "common.h"

void func_80800000_chfantasysafeswitch(Actor *arg0) {
    void func_80103110(Actor*, u32);
    (*(u8 *)((s8 *)(arg0) + (0x65))) = (u8) ((*(u8 *)((s8 *)(arg0) + (0x65))) & 0xFFEF);
    func_80103110(arg0, 0U);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fantasy/safeswitch/func_8080002C_chfantasysafeswitch.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fantasy/safeswitch/func_80800070_chfantasysafeswitch.s")

OSThread *chfantasysafeswitch_entrypoint_0(void)
{
    extern u8 D_80800288_chfantasysafeswitch[];

    return (OSThread *) D_80800288_chfantasysafeswitch;
}
