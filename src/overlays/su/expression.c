#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/expression/suexpression_entrypoint_0.s")

u8 suexpression_entrypoint_1(u8 arg0) {
    void *func_80800CF4_suexpression(s32 arg0);
    void *temp_v0;

    temp_v0 = func_80800CF4_suexpression(arg0);
    if (temp_v0 == NULL) {
        return 0U;
    }
    return *((u8 *) temp_v0 + 4);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/expression/suexpression_entrypoint_2.s")

/* extern */

void suexpression_entrypoint_3(s16 arg0, s32 *arg1, s32 *arg2, s32 *arg3) {
    s32 _suexpressjoint_entrypoint_0(s16);
    s32 _suexpressmorph_entrypoint_0(s16);
    *arg3 = 0x14;
    *arg1 = _suexpressmorph_entrypoint_0(arg0);
    *arg2 = _suexpressjoint_entrypoint_0(arg0);
    *arg3 = (*arg3 + 3) & 0x7FFFFFFC;
    *arg1 = (*arg1 + 3) & 0x7FFFFFFC;
    *arg2 = (*arg2 + 3) & 0x7FFFFFFC;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/expression/suexpression_entrypoint_4.s")

/* extern */

void suexpression_entrypoint_5(u8 *arg0) {
    s32 _suexpressmorph_entrypoint_4(void *);
    s16 temp_v0;

    temp_v0 = (*(s16 *)((s8 *)(arg0) + (2)));
    if (temp_v0 != 0) {
        _suexpressmorph_entrypoint_4((void *)((s8 *)arg0 + temp_v0));
    }
}

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

/* extern */

void suexpression_entrypoint_11(u8 *arg0) {
    s32 _suexpressmorph_entrypoint_2(void *);
    s16 temp_v0;

    temp_v0 = (*(s16 *)((s8 *)(arg0) + (2)));
    if (temp_v0 != 0) {
        _suexpressmorph_entrypoint_2((void *)((s8 *)arg0 + temp_v0));
    }
}

void suexpression_entrypoint_12(void *arg0, f32 arg1, f32 arg2) {
    (*(s16 *)((s8 *)(arg0) + (6))) = (s16) (s32) arg1;
    (*(s16 *)((s8 *)(arg0) + (0xA))) = (s16) (s32) arg2;
}

void suexpression_entrypoint_13(void *arg0, f32 *arg1, f32 *arg2) {
    *arg1 = (f32) (*(s16 *)((s8 *)(arg0) + (4)));
    *arg2 = (f32) (*(s16 *)((s8 *)(arg0) + (8)));
}

void suexpression_entrypoint_14(void *arg0, f32 arg1, f32 arg2) {
    (*(s8 *)((s8 *)(arg0) + (0x10))) = (s8) (u32) (100.0f * arg1);
    (*(s8 *)((s8 *)(arg0) + (0x11))) = (s8) (u32) (100.0f * arg2);
}

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

void *func_80800CF4_suexpression(s32 arg0) {
    extern s32 D_80800D60_suexpression;
    u32 temp_v1;

    temp_v1 = arg0 - 0xC;
    if (temp_v1 >= 0xC6U) {
        return NULL;
    }
    return (u8 *) &D_80800D60_suexpression + temp_v1 * 6;
}
