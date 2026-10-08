#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/fx/rain/func_80800000_fxrain.s")

void func_808001E8_fxrain(s32 *arg0, s32 arg1) {
    arg0[10] = arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/fx/rain/fxrain_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/fx/rain/fxrain_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/fx/rain/fxrain_entrypoint_2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/fx/rain/fxrain_entrypoint_3.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/fx/rain/fxrain_entrypoint_4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/fx/rain/fxrain_entrypoint_5.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/fx/rain/fxrain_entrypoint_6.s")

void fxrain_entrypoint_7(s32 arg0)
{
    func_808001E8_fxrain(arg0,1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/fx/rain/fxrain_entrypoint_8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/fx/rain/fxrain_entrypoint_9.s")
