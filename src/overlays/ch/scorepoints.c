#include "common.h"

OSThread *chscorepoints_entrypoint_0(void)
{
    extern u8 D_808003C0_chscorepoints[];

    return (OSThread *) D_808003C0_chscorepoints;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/scorepoints/func_8080000C_chscorepoints.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/scorepoints/func_808000BC_chscorepoints.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/scorepoints/func_8080019C_chscorepoints.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/scorepoints/chscorepoints_entrypoint_1.s")

void chscorepoints_entrypoint_2(s32 arg0, s32 arg1, void *arg2, s32 arg3) {
    s32 _chbaddiesetup_entrypoint_6(s32 *, s32, s32, s32, s32, s32, s32);
    extern s32 _chscorepoints_entrypoint_1;
    _chbaddiesetup_entrypoint_6(&_chscorepoints_entrypoint_1, arg0, arg1, (s32) (*(f32 *)((s8 *)(arg2) + (0))), (s32) (*(f32 *)((s8 *)(arg2) + (4))), (s32) (*(f32 *)((s8 *)(arg2) + (8))), arg3);
}
