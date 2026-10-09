#include "su/quiz.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/quiz/func_80800000_suquiz.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/quiz/func_80800074_suquiz.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/quiz/func_8080009C_suquiz.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/quiz/func_808000C4_suquiz.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/quiz/suquiz_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/quiz/suquiz_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/quiz/suquiz_entrypoint_2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/quiz/suquiz_entrypoint_3.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/quiz/suquiz_entrypoint_4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/quiz/suquiz_entrypoint_5.s")

s8 suquiz_entrypoint_6(void) {
    extern void *D_80127614;
    if (func_800DA298(FLAG2_6B6_UNK) != 0) {
        return (*(s8 *)((s8 *)(D_80127614) + (0x28)));
    }
    return -1;
}

u8 suquiz_entrypoint_7(void) {
    extern void *D_80127614;
    if (func_800DA298(FLAG2_6B6_UNK) != 0) {
        return (*(u8 *)((s8 *)(D_80127614) + (0x25)));
    }
    return 6U;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/quiz/suquiz_entrypoint_8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/quiz/suquiz_entrypoint_9.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/quiz/suquiz_entrypoint_10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/quiz/suquiz_entrypoint_11.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/quiz/suquiz_entrypoint_12.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/quiz/suquiz_entrypoint_13.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/quiz/suquiz_entrypoint_14.s")

s8 suquiz_entrypoint_15(s32 arg0) {
    extern void *D_80127614;
    if (func_800DA298(FLAG2_6B6_UNK) != 0) {
        return (*(s8 *)((s8 *)(D_80127614) + (0x27)));
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/quiz/suquiz_entrypoint_16.s")

s32 suquiz_entrypoint_17()
{
    return func_800DA298(FLAG2_6E3_UNK);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/quiz/suquiz_entrypoint_18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/quiz/suquiz_entrypoint_19.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/quiz/suquiz_entrypoint_20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/quiz/suquiz_entrypoint_21.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/quiz/suquiz_entrypoint_22.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/quiz/suquiz_entrypoint_23.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/quiz/suquiz_entrypoint_24.s")

/* extern */

void suquiz_entrypoint_25(void) {
    s32 _glcutDll_entrypoint_17();
    if (func_800DA298(FLAG2_6EB_UNK) == 0) {
        _glcutDll_entrypoint_17();
        func_800DA544(FLAG2_6EB_UNK);
    }
}

s16 suquiz_entrypoint_26(void) {
    extern void *D_80127614;
    return (*(s16 *)((s8 *)(D_80127614) + (0x34)));
}

void suquiz_entrypoint_27(void) {
    s32 func_80108474(s32, s32 *, s32);
    extern s32 D_808010F0_suquiz;
    func_80108474(0x217, &D_808010F0_suquiz, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/quiz/suquiz_entrypoint_28.s")
