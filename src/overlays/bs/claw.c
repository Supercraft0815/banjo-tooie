#include "common.h"

/* extern */

void bsclaw_entrypoint_0(s32 arg0) {
    s32 baflag_clear(s32, s32);
    s32 func_8009E474();
    s32 func_800A0CF4(s32, s32);
    s32 func_800C6DA0(s32);
    func_8009E474();
    func_800C6DA0(0x47);
    baflag_clear(arg0, 0x1F);
    func_800A0CF4(arg0, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/claw/bsclaw_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/claw/bsclaw_entrypoint_2.s")

s32 bsclaw_entrypoint_3(s32 arg0) {
    extern s32 D_80800400_bsclaw[];
    return ((s32 *)&D_80800400_bsclaw)[arg0];
}
