#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/fx/ripple/func_80800000_fxripple.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/fx/ripple/func_80800094_fxripple.s")

void fxripple_entrypoint_0(s32 arg0, s32 arg1) {
    s32 temp_v0;
    temp_v0 = func_80800094_fxripple(arg0, arg1, 0);
    if (temp_v0 != 0) {
        func_800BA22C(temp_v0, 1);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/fx/ripple/fxripple_entrypoint_1.s")

void fxripple_entrypoint_2(s32 arg0, s32 arg1) {
    func_80800094_fxripple(arg0, arg1, 0);
}

void fxripple_entrypoint_3()
{
    func_80800094_fxripple();
}

/* extern */

void fxripple_entrypoint_4(f32 arg0) {
    s32 func_800B5BE4(s32);
    s32 func_800BA5D0(s32, s16);
    func_800BA5D0(func_800B5BE4(3), (s16) (s32) arg0);
}
