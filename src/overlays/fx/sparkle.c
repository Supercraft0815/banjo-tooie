#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/fx/sparkle/fxsparkle_entrypoint_0.s")

void fxsparkle_entrypoint_1(s32 arg0, s32 arg1) {
    s32 _fxspgold_entrypoint_2();
    s32 func_800BABB8(s32, s32, s32, s32, s32);
    extern s32 D_808003AC_fxsparkle[];
    s32 temp_a0;
    s32 temp_v1;

    temp_a0 = _fxspgold_entrypoint_2();
    temp_v1 = D_808003AC_fxsparkle[arg1];
    if (temp_v1 != 0) {
        func_800BABB8(temp_a0, arg0, 0, 0x3F800000, temp_v1);
    }
}

void fxsparkle_entrypoint_2()
{
    _fxspgold_entrypoint_0();
}

/* extern */

void fxsparkle_entrypoint_3(void) {
    s32 _fxspgold_entrypoint_1();
    _fxspgold_entrypoint_1();
}
