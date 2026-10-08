#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/fx/leaves/func_80800000_fxleaves.s")

void func_80800288_fxleaves(s8 *arg0, s32 arg1) {
    arg0[34] = arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/fx/leaves/fxleaves_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/fx/leaves/fxleaves_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/fx/leaves/fxleaves_entrypoint_2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/fx/leaves/fxleaves_entrypoint_3.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/fx/leaves/fxleaves_entrypoint_4.s")

void fxleaves_entrypoint_5(s32 arg0)
{
    func_80800288_fxleaves(arg0,1);
}

void fxleaves_entrypoint_6(s32 arg0)
{
    func_80800288_fxleaves(arg0,0x2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/fx/leaves/fxleaves_entrypoint_7.s")
