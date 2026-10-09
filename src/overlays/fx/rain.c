#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/fx/rain/func_80800000_fxrain.s")

void func_808001E8_fxrain(s32 *arg0, s32 arg1) {
    arg0[10] = arg1;
}

/* extern */

void fxrain_entrypoint_0(void *arg0) {
    s32 vector_clear(s32);
    vector_clear((*(s32 *)((s8 *)(arg0) + (0x20))));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/fx/rain/fxrain_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/fx/rain/fxrain_entrypoint_2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/fx/rain/fxrain_entrypoint_3.s")

/* extern */

void fxrain_entrypoint_4(u8 *arg0) {
    s32 func_800C2FDC(s32, u8 *, u8);
    s32 heap_free(u8 *);
    s32 vector_free(s32, u8 *);
    u8 temp_a2;

    temp_a2 = (*(u8 *)((s8 *)(arg0) + (0)));
    if (temp_a2 != 0) {
        func_800C2FDC(temp_a2 & 0xFF, arg0, temp_a2);
        (*(u8 *)((s8 *)(arg0) + (0))) = 0;
    }
    vector_free((*(s32 *)((s8 *)(arg0) + (0x20))), arg0);
    heap_free(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/fx/rain/fxrain_entrypoint_5.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/fx/rain/fxrain_entrypoint_6.s")

void fxrain_entrypoint_7(s32 arg0)
{
    func_808001E8_fxrain(arg0,1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/fx/rain/fxrain_entrypoint_8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/fx/rain/fxrain_entrypoint_9.s")
