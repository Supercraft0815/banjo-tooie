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

void func_80800224_fxkern(Gfx **arg0, s32 arg1, s32 arg2, u8 *arg3, s32 arg4) {
    void func_800B7F14(Gfx **);
    void func_800B811C(Gfx **);
    void func_800B8DEC(Gfx **, s32, s32, u8);
    extern f32 B_80800488_fxkern[][2];

    func_800B8C98(1);
    func_800B7F14(arg0);
    for (; arg4 >= 0; arg4--) {
        func_800B8DEC(arg0, (s32) (B_80800488_fxkern[arg4][0] + (f32) arg1), (s32) (B_80800488_fxkern[arg4][1] + (f32) arg2), arg3[arg4]);
    }
    func_800B811C(arg0);
}

/* extern */

void fxkern_entrypoint_0(Gfx **arg0, s32 arg1, s32 arg2, u8 *arg3) {
    s32 func_80800084_fxkern(u8 *);
    void func_80800224_fxkern(Gfx **, s32, s32, u8 *, s32);
    func_80800224_fxkern(arg0, arg1, arg2, arg3, func_80800084_fxkern(arg3));
}

void fxkern_entrypoint_1(Gfx **arg0, s32 arg1, u8 *arg2) {
    s32 func_80800084_fxkern(u8 *);
    void func_80800224_fxkern(Gfx **, s32, s32, u8 *, s32);
    extern f32 B_80800488_fxkern[][2];
    s32 temp_v0;
    f32 divisor = 2.0f;

    temp_v0 = func_80800084_fxkern(arg2);
    func_80800224_fxkern(arg0, (s32) ((304.0f - B_80800488_fxkern[temp_v0][0]) / divisor), arg1, arg2, temp_v0);
}

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
