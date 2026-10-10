#include "common.h"

void func_80800000_bscrouch(s32 arg0) {
    s32 baanim_playForDuration_loopSmooth(s32, s32, s32);
    baanim_playForDuration_loopSmooth(arg0, 0x10C, 0x3F000000);
    (*(s32 *)((s8 *)(arg0) + (0x15C))) = 4;
}

void func_80800034_bscrouch(s32 arg0) {
    s32 baanim_playForDuration_onceSmooth(s32, s32, s32);
    baanim_playForDuration_onceSmooth(arg0, 0x116, 0x40000000);
    (*(s32 *)((s8 *)(arg0) + (0x15C))) = 2;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/crouch/func_80800068_bscrouch.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/crouch/func_808000B4_bscrouch.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/crouch/func_808000FC_bscrouch.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/crouch/bscrouch_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/crouch/bscrouch_entrypoint_1.s")

void bscrouch_entrypoint_2(s32 arg0) 
{
}
s32 bscrouch_entrypoint_3(s32 arg0) {
    extern s32 D_80800990_bscrouch[];
    return ((s32 *)&D_80800990_bscrouch)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/crouch/func_808006A4_bscrouch.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/crouch/bscrouch_entrypoint_4.s")
