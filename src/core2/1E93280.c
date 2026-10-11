#include "common.h"

void func_800B9990(Gfx **arg0) {
    void func_800D2CC4(void);
    extern u8 D_8011A6E0[];
    gSPDisplayList((*arg0)++, D_8011A6E0 - 0x80000000);
    func_800D2CC4();
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E93280/func_800B99CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E93280/func_800B9A24.s")
