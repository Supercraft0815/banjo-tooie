#include "common.h"

/* extern */

void fxsplash_entrypoint_0(s32 arg0) {
    s32 _fxripple_entrypoint_0(s32);
    _fxripple_entrypoint_0(0);
}

void fxsplash_entrypoint_1(s32 arg0) {
    s32 func_800BABB8(s32, s32, s32, s32, s32 *);
    s32 fxsplash_entrypoint_2(s32, s32);
    extern s32 D_80800130_fxsplash;
    func_800BABB8(fxsplash_entrypoint_2(arg0, 0x41A00000), 0, 0, 0x3F800000, &D_80800130_fxsplash);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/fx/splash/fxsplash_entrypoint_2.s")
