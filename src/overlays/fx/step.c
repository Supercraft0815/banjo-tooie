#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/fx/step/func_80800000_fxstep.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/fx/step/func_80800078_fxstep.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/fx/step/func_8080012C_fxstep.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/fx/step/func_80800210_fxstep.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/fx/step/func_808002B4_fxstep.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/fx/step/func_80800344_fxstep.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/fx/step/func_808003B4_fxstep.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/fx/step/fxstep_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/fx/step/fxstep_entrypoint_1.s")

void fxstep_entrypoint_2(s8 *arg0, s32 arg1) {
    arg0[38] = arg1;
}

void fxstep_entrypoint_3(s8 *arg0, s32 arg1) {
    arg0[39] = arg1;
}

void fxstep_entrypoint_4(void *arg0, s32 arg1, s32 arg2) {
    (*(s32 *)((s8 *)(arg0) + (0x1C))) = arg1;
    (*(s32 *)((s8 *)(arg0) + (0x20))) = arg2;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/fx/step/fxstep_entrypoint_5.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/fx/step/fxstep_entrypoint_6.s")

void fxstep_entrypoint_7(void *arg0, s32 arg1, s32 arg2) {
    (*(s32 *)((s8 *)(arg0) + (0x14))) = arg1;
    (*(s32 *)((s8 *)(arg0) + (0x18))) = arg2;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/fx/step/fxstep_entrypoint_8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/fx/step/fxstep_entrypoint_9.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/fx/step/fxstep_entrypoint_10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/fx/step/fxstep_entrypoint_11.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/fx/step/fxstep_entrypoint_12.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/fx/step/fxstep_entrypoint_13.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/fx/step/fxstep_entrypoint_14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/fx/step/fxstep_entrypoint_15.s")
