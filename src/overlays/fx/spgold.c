#include "common.h"

void fxspgold_entrypoint_0(void) {
    s32 func_800B58D4(u8);
    extern s32 D_80127115;
    func_800B58D4((*(u8 *)((s8 *)(&D_80127115) + (0xB))));
}

void fxspgold_entrypoint_1(void) {
    s8 func_800B5758(s32);
    extern s32 D_80127115;
    (*(s8 *)((s8 *)(&D_80127115) + (0xB))) = func_800B5758(0x14);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/fx/spgold/fxspgold_entrypoint_2.s")
