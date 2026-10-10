#include "fx/twinkle.h"

void fxtwinkle_entrypoint_0(s32 arg0)
{
    fxtwinkle_entrypoint_1(arg0, GOLD_SPARKLE);
}

void fxtwinkle_entrypoint_1(f32 *arg0, enum asset_e arg1) {
    s32 func_800B53A4(s32);
    s32 func_800BA22C(s32, s32);
    s32 func_800BA3FC(s32, s16);
    s32 func_800BABB8(s32, f32 *, s32, s32, s32 *);
    extern s32 D_808000F0_fxtwinkle;
    s32 sp24;
    s32 temp_v0;

    temp_v0 = func_800B53A4(1);
    sp24 = temp_v0;
    func_800BABB8(temp_v0, arg0, 0, 0x3F800000, &D_808000F0_fxtwinkle);
    func_800BA3FC(sp24, (s16) arg1);
    func_800BA22C(sp24, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/fx/twinkle/fxtwinkle_entrypoint_2.s")
