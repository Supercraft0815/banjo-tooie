#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gobi/common/chgobicommon_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gobi/common/func_80800070_chgobicommon.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gobi/common/func_808000EC_chgobicommon.s")

void func_808001AC_chgobicommon(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_3(Actor*, f32*, u32*, f32);
    extern u32 D_80800200_chgobicommon;
    extern u32 D_80800210_chgobicommon;
    f32 *sp1C[2];

    sp1C[1] = (f32 *) ((u8 *) arg0 + 4);
    _subaddieaudioquick_entrypoint_3(arg0, sp1C[1], &D_80800200_chgobicommon, 0.65f);
    _subaddieaudioquick_entrypoint_3(arg0, sp1C[1], &D_80800210_chgobicommon, 0.0f);
}
