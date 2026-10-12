#include "su/quiz.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/quiz/func_80800000_suquiz.s")

f32 func_80800074_suquiz(s32 arg0, s32 arg1, s32 arg2) {
    extern f32 D_80801050_suquiz[][3][2];
    return D_80801050_suquiz[arg1][arg2][0];
}

f32 func_8080009C_suquiz(s32 arg0, s32 arg1, s32 arg2) {
    extern f32 D_80801054_suquiz[][3][2];
    return D_80801054_suquiz[arg1][arg2][0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/quiz/func_808000C4_suquiz.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/quiz/suquiz_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/quiz/suquiz_entrypoint_1.s")

void suquiz_entrypoint_2(void) {
    extern void *D_80127614;
    void heap_free(void* mem);
    if (D_80127614 != NULL) {
        func_800DA524(FLAG2_6B6_UNK);
        heap_free(D_80127614);
        D_80127614 = NULL;
    }
}

s32 suquiz_entrypoint_3(void) {
    u32 temp_v0;

    if (func_800DA298(FLAG_441_UNK) != 0) {
        return 4;
    }
    if (func_800DA298(FLAG2_6E3_UNK) != 0) {
        func_800DA524(FLAG2_6E3_UNK);
        func_800DA524(FLAG2_6EB_UNK);
        return 5;
    }
    temp_v0 = func_800DA564(FLAG_442_UNK, 3);
    switch (temp_v0) {
    case 0:
        return 0;
    case 1:
        return 1;
    case 2:
        return 2;
    case 3:
        return 3;
    case 4:
        return 6;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/quiz/suquiz_entrypoint_4.s")

s32 suquiz_entrypoint_5(void) {
    extern void *D_80127614;
    if (func_800DA298(FLAG2_6B6_UNK) != 0) {
        return ((*(s8 *)((s8 *)(D_80127614) + (0x28))) + 1) != 0;
    }
    return 0;
}

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

s32 suquiz_entrypoint_9(s32 arg0) {
    if (arg0 != 0) {
        if (arg0 == 1) {
            return func_800DA298(FLAG_582_UNK);
        }
    } else {
        return func_800DA298(FLAG_583_UNK);
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/quiz/suquiz_entrypoint_10.s")

/* extern */

s32 suquiz_entrypoint_11(s32 arg0) {
    s32 suquiz_entrypoint_10(s32);
    if (func_800DA298(FLAG2_6B6_UNK) != 0) {
        return (suquiz_entrypoint_10(arg0) + 1) != 0;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/quiz/suquiz_entrypoint_12.s")

void suquiz_entrypoint_13(f32 *arg0) {
    extern void *D_80127614;
    void func_800EE7F8(f32 dst[3], f32 src[3]);
    func_800EE7F8(arg0, (f32 *) D_80127614);
}

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

/* extern */

void suquiz_entrypoint_18(u32 arg0) {
    s32 _gcfrontend_entrypoint_9(s32);
    switch (arg0) {
    case 0:
        func_800DA524(FLAG_441_UNK);
        func_800DA7A8(FLAG_442_UNK, 0, 3);
        return;
    case 1:
        func_800DA524(FLAG_441_UNK);
        func_800DA7A8(FLAG_442_UNK, 1, 3);
        _gcfrontend_entrypoint_9(0x74);
        return;
    case 2:
        func_800DA524(FLAG_441_UNK);
        func_800DA7A8(FLAG_442_UNK, 2, 3);
        _gcfrontend_entrypoint_9(0x75);
        return;
    case 3:
        func_800DA524(FLAG_441_UNK);
        func_800DA7A8(FLAG_442_UNK, 3, 3);
        _gcfrontend_entrypoint_9(0x76);
        return;
    case 4:
        func_800DA544(FLAG_441_UNK);
        func_800DA7A8(FLAG_442_UNK, 4, 3);
        _gcfrontend_entrypoint_9(0x84);
        /* fallthrough */
    default:
        return;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/quiz/suquiz_entrypoint_19.s")

void suquiz_entrypoint_20(s32 arg0) {
    if (arg0 != 0) {
        if (arg0 == 1) {
            func_800DA544(FLAG_582_UNK);
        }
    } else {
        func_800DA544(FLAG_583_UNK);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/quiz/suquiz_entrypoint_21.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/quiz/suquiz_entrypoint_22.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/quiz/suquiz_entrypoint_23.s")

void suquiz_entrypoint_24(u32 arg0, s32 arg1) {
    extern void *D_80127614;
    void _glcutDll_entrypoint_6(u32, u32);
    (*(s16 *)((s8 *)(D_80127614) + (0x34))) = arg1;
    func_800DA544(FLAG2_6E3_UNK);
    func_800DA524(FLAG2_6EB_UNK);
    _glcutDll_entrypoint_6(arg0, 0x8AU);
}

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
