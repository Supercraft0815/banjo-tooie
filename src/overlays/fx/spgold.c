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

void fxspgold_entrypoint_2(s32 arg0) {
    s32 func_800B56D0(u8);
    s32 func_800BABB8(s32, s32, s32, s32, s32 *);
    extern s32 D_80127115;
    extern s32 D_80800090_fxspgold;
    func_800BABB8(func_800B56D0((*(u8 *)((s8 *)(&D_80127115) + (0xB)))), arg0, 0, 0x3F800000, &D_80800090_fxspgold);
}
