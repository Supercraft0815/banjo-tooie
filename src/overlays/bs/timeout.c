#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/timeout/bstimeout_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/timeout/bstimeout_entrypoint_1.s")

void bstimeout_entrypoint_2(s32 arg0)
{
    func_800951B4();
    func_800A4E30(arg0);
}
s32 bstimeout_entrypoint_3(s32 arg0) {
    extern s32 D_80800330_bstimeout[];
    return ((s32 *)&D_80800330_bstimeout)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/timeout/bstimeout_entrypoint_4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/timeout/bstimeout_entrypoint_5.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/timeout/bstimeout_entrypoint_6.s")

s32 bstimeout_entrypoint_7(s32 arg0) {
    extern s32 D_80800340_bstimeout[];
    return ((s32 *)&D_80800340_bstimeout)[arg0];
}
