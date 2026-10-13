#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bkflamethrower/bsbkflamethrower_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bkflamethrower/func_80800094_bsbkflamethrower.s")

void bsbkflamethrower_entrypoint_1(s32 arg0)
{
    func_80800094_bsbkflamethrower(arg0,0);
}

void bsbkflamethrower_entrypoint_2(s32 *arg0) { arg0[87] = 0; func_80800094_bsbkflamethrower(arg0, 1); }

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bkflamethrower/bsbkflamethrower_entrypoint_3.s")

s32 bsbkflamethrower_entrypoint_4(s32 arg0) {
    extern s32 D_80800450_bsbkflamethrower[];
    return ((s32 *)&D_80800450_bsbkflamethrower)[arg0];
}
