#include "common.h"

void func_80800000_fxkern(u8 arg0, u8 arg1, s32 *arg2, s32 *arg3) {
    typedef struct { u8 first; u8 key; s8 value2; s8 value3; } KernEntry;
    extern KernEntry D_80800420_fxkern[];
    s32 key = arg0;
    s32 i;

    *arg3 = 0;
    *arg2 = 0;
    for (i = 0; D_80800420_fxkern[i].first != 0; i++) {
            if (key == D_80800420_fxkern[i].key && (D_80800420_fxkern[i].first == arg1 || D_80800420_fxkern[i].first == 0x2A)) {
                *arg2 = D_80800420_fxkern[i].value2;
                *arg3 = D_80800420_fxkern[i].value3;
                return;
            }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/fx/kern/func_80800084_fxkern.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/fx/kern/func_80800224_fxkern.s")

/* extern */

void fxkern_entrypoint_0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 func_80800084_fxkern(s32);
    s32 func_80800224_fxkern(s32, s32, s32, s32, s32);
    func_80800224_fxkern(arg0, arg1, arg2, arg3, func_80800084_fxkern(arg3));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/fx/kern/fxkern_entrypoint_1.s")

void fxkern_entrypoint_2(void) {
    s32 func_800B8C50();
    extern f32 B_80800480_fxkern;
    func_800B8C50();
    B_80800480_fxkern = 1.0f;
}

void fxkern_entrypoint_3(f32 arg0) {
    s32 func_800B8CF0(f32);
    extern f32 B_80800480_fxkern;
    func_800B8CF0(arg0);
    B_80800480_fxkern = arg0;
}
