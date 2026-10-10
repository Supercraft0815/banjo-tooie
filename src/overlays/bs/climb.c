#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/climb/func_80800000_bsclimb.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/climb/func_8080005C_bsclimb.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/climb/func_808000E8_bsclimb.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/climb/func_808001D0_bsclimb.s")

/* extern */

void func_80800258_bsclimb(void *arg0, f32 arg1, f32 arg2) {
    f32 func_800DC0C0();
    (*(f32 *)((s8 *)(arg0) + (0x16C))) = (f32) ((func_800DC0C0() * arg2) + arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/climb/func_80800298_bsclimb.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/climb/bsclimb_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/climb/bsclimb_entrypoint_1.s")

void bsclimb_entrypoint_2()
{
    func_808001D0_bsclimb();
}

s32 bsclimb_entrypoint_3(s32 arg0) {
    extern s32 D_808008FC_bsclimb[];
    return ((s32 *)&D_808008FC_bsclimb)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/climb/bsclimb_entrypoint_4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/climb/bsclimb_entrypoint_5.s")

void bsclimb_entrypoint_6()
{
    func_808001D0_bsclimb();
}

s32 bsclimb_entrypoint_7(s32 arg0) {
    extern s32 D_8080090C_bsclimb[];
    return ((s32 *)&D_8080090C_bsclimb)[arg0];
}

/* extern */

void bsclimb_entrypoint_8(s32 arg0) {
    s32 baanim_playForDuration_loopSmooth(s32, s32, s32);
    s32 baphysics_set_type(s32, s32);
    s32 func_8008CA4C(s32, s32);
    s32 func_808000E8_bsclimb(s32);
    baanim_playForDuration_loopSmooth(arg0, 0xB2, 0x4028F5C3);
    func_8008CA4C(arg0, 1);
    func_808000E8_bsclimb(arg0);
    baphysics_set_type(arg0, 7);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/climb/bsclimb_entrypoint_9.s")

void bsclimb_entrypoint_10()
{
    func_808001D0_bsclimb();
}

s32 bsclimb_entrypoint_11(s32 arg0) {
    extern s32 D_8080091C_bsclimb[];
    return ((s32 *)&D_8080091C_bsclimb)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/climb/bsclimb_entrypoint_12.s")
