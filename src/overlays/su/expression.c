#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/expression/suexpression_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/expression/suexpression_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/expression/suexpression_entrypoint_2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/expression/suexpression_entrypoint_3.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/expression/suexpression_entrypoint_4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/expression/suexpression_entrypoint_5.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/expression/suexpression_entrypoint_6.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/expression/suexpression_entrypoint_7.s")

/* extern */

void suexpression_entrypoint_8(void *arg0, s32 arg1) {
    s32 func_80100074(void *, s32, s32);
    s32 func_80100094();
    if (func_80100094() != 0) {
        func_80100074(arg0, arg1, 0);
    }
    (*(u8 *)((s8 *)(arg0) + (0x95))) = (u8) ((*(u8 *)((s8 *)(arg0) + (0x95))) & 0xFFF3);
}

void suexpression_entrypoint_9(void *arg0) {
    *(u8 *)((u8 *)arg0 + 0x12) = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/expression/suexpression_entrypoint_10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/expression/suexpression_entrypoint_11.s")

void suexpression_entrypoint_12(void *arg0, f32 arg1, f32 arg2) {
    (*(s16 *)((s8 *)(arg0) + (6))) = (s16) (s32) arg1;
    (*(s16 *)((s8 *)(arg0) + (0xA))) = (s16) (s32) arg2;
}

void suexpression_entrypoint_13(void *arg0, f32 *arg1, f32 *arg2) {
    *arg1 = (f32) (*(s16 *)((s8 *)(arg0) + (4)));
    *arg2 = (f32) (*(s16 *)((s8 *)(arg0) + (8)));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/expression/suexpression_entrypoint_14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/expression/suexpression_entrypoint_15.s")

void suexpression_entrypoint_16(void *arg0, s32 arg1) {
    (*(s16 *)((s8 *)(arg0) + (4))) = (s16) (s32) ((f32) (*(s16 *)((s8 *)(arg0) + (4))) * 0.97f);
    (*(s16 *)((s8 *)(arg0) + (8))) = (s16) (s32) ((f32) (*(s16 *)((s8 *)(arg0) + (8))) * 0.97f);
}

void suexpression_entrypoint_17(s16 *arg0, s32 arg1) {
    arg0[7] = arg1;
}

void suexpression_entrypoint_18(s8 *arg0, s32 arg1) {
    arg0[19] = arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/expression/suexpression_entrypoint_19.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/expression/suexpression_entrypoint_20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/expression/func_80800CF4_suexpression.s")
