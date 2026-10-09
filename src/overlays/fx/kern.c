#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/fx/kern/func_80800000_fxkern.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/fx/kern/func_80800084_fxkern.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/fx/kern/func_80800224_fxkern.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/fx/kern/fxkern_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/fx/kern/fxkern_entrypoint_1.s")

void fxkern_entrypoint_2(void) {
    s32 func_800B8C50();
    extern f32 B_80800480_fxkern;
    func_800B8C50();
    B_80800480_fxkern = 1.0f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/fx/kern/fxkern_entrypoint_3.s")
