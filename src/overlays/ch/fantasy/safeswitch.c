#include "common.h"

void func_80800000_chfantasysafeswitch(Actor *arg0) {
    void func_80103110(Actor*, u32);
    (*(u8 *)((s8 *)(arg0) + (0x65))) = (u8) ((*(u8 *)((s8 *)(arg0) + (0x65))) & 0xFFEF);
    func_80103110(arg0, 0U);
}

void func_8080002C_chfantasysafeswitch(Actor *arg0) {
    s32 func_80101DDC(Actor *);
    void func_80102424(Actor *, s32);
    if (arg0->unk70_10 == 2 && func_80101DDC(arg0) != 0) {
        func_80102424(arg0, 3);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fantasy/safeswitch/func_80800070_chfantasysafeswitch.s")

OSThread *chfantasysafeswitch_entrypoint_0(void)
{
    extern u8 D_80800288_chfantasysafeswitch[];

    return (OSThread *) D_80800288_chfantasysafeswitch;
}
