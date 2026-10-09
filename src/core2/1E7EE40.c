#include "common.h"

extern s32 D_80119540;

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7EE40/func_800A5550.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7EE40/func_800A5598.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7EE40/func_800A55E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7EE40/func_800A5608.s")

void func_800A5630()
{
    _cadbmgrDll_entrypoint_1(&D_80119540);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7EE40/func_800A5654.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7EE40/func_800A56A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7EE40/func_800A5790.s")

s32 func_800A57EC(s32 arg0) {
    extern s32 D_8011951C[];
    return ((s32 *)&D_8011951C)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7EE40/func_800A5800.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7EE40/func_800A5854.s")

s32 func_800A586C(void) {
    return (*(s32 *)((s8 *)(D_80119540) + (0x34)));
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7EE40/func_800A587C.s")

s32 func_800A5898(void) {
    return (*(s32 *)((s8 *)(D_80119540) + (0x30)));
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7EE40/func_800A58A8.s")

s32 func_800A58F0(void) {
    return (*(s32 *)((s8 *)(D_80119540) + (0x38))) + 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7EE40/func_800A5904.s")
