#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bpeck/bsbpeck_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bpeck/func_80800168_bsbpeck.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bpeck/bsbpeck_entrypoint_1.s")

/* extern */

void bsbpeck_entrypoint_2(s32 arg0) {
    s32 baflag_clear(s32, s32);
    void func_800C6DA0(s32);
    s32 baphysics_reset_gravity(s32);
    s32 func_8009E474(s32);
    s32 func_800A0CF4(s32, s32);
    baflag_clear(arg0, 0x2A);
    func_800C6DA0(0x46);
    func_8009E474(arg0);
    func_800A0CF4(arg0, 0);
    baphysics_reset_gravity(arg0);
}

s32 bsbpeck_entrypoint_3(s32 arg0) {
    extern s32 D_808004A0_bsbpeck[];
    return ((s32 *)&D_808004A0_bsbpeck)[arg0];
}
