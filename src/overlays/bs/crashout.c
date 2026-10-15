#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/crashout/func_80800000_bscrashout.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/crashout/func_808000B0_bscrashout.s")

void bscrashout_entrypoint_0(s32 arg0)
{
    func_8009BD88();
    func_8008E95C(arg0);
    func_800951B4(arg0);
}

/* extern */

void bscrashout_entrypoint_1(void *arg0) {
    s32 _bamotor_entrypoint_1(void *, f32, f32, f32);
    s32 func_8008E944(void *);
    s32 func_8009514C(void *);
    f32 func_80099A34();
    s32 func_8009D89C(void *, f32);
    s32 func_808000B0_bscrashout(void *, s32);
    s32 yaw_applyIdeal(void *);
    s32 yaw_setIdeal(void *, f32);
    yaw_setIdeal(arg0, func_80099A34());
    yaw_applyIdeal(arg0);
    func_8009D89C(arg0, 1.0f);
    _bamotor_entrypoint_1(arg0, 1.0f, 0.5f, 0.5f);
    func_8008E944(arg0);
    func_8009514C(arg0);
    (*(s32 *)((s8 *)(arg0) + (0x15C))) = 0;
    (*(f32 *)((s8 *)(arg0) + (0x16C))) = 600.0f;
    func_808000B0_bscrashout(arg0, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/crashout/bscrashout_entrypoint_2.s")

s32 bscrashout_entrypoint_3(s32 arg0) {
    extern s32 D_808003D0_bscrashout[];
    return ((s32 *)&D_808003D0_bscrashout)[arg0];
}
