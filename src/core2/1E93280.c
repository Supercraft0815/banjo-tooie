#include "common.h"

void func_800B9990(Gfx **arg0) {
    void func_800D2CC4(void);
    extern u8 D_8011A6E0[];
    gSPDisplayList((*arg0)++, D_8011A6E0 - 0x80000000);
    func_800D2CC4();
}

void func_800B99CC(s32 arg0, s32 arg1, s32 arg2) {
    s32 sp[4];

    func_800E7FCC(sp);
    func_800B9A24(arg0, arg1, arg2, sp[0], sp[1], sp[2], sp[3]);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E93280/func_800B9A24.s")
