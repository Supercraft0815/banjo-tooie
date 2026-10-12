#include "common.h"

void func_80800000_sukickball(s32 arg0, s32 arg1, f32 *arg2, f32 arg3) {
    void *func_800DE448(f32 *, f32 *, f32, f32 *, s32);
    void func_800DF830(s32);
    s32 func_801039E4(s32);
    struct kickball_vector { f32 v[3]; };
    extern struct kickball_vector D_80801200_sukickball;
    struct kickball_vector sp24 = D_80801200_sukickball;

    func_800DF830(3);
    func_800DE448(arg2, sp24.v, arg3, NULL, func_801039E4(arg0));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/kickball/sukickball_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/kickball/sukickball_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/kickball/sukickball_entrypoint_2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/kickball/sukickball_entrypoint_3.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/kickball/sukickball_entrypoint_4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/kickball/sukickball_entrypoint_5.s")

/* extern */

s32 sukickball_entrypoint_6(Actor *arg0, s32 arg1) {
    void* func_80100094(Actor*, u32);
    return (*(u8 *)((s8 *)((s32)func_80100094(arg0, 0U) + arg1 + 0xA))) == 2;
}

/* extern */

s32 sukickball_entrypoint_7(Actor *arg0, s32 arg1) {
    void* func_80100094(Actor*, u32);
    return (*(u8 *)((s8 *)((s32)func_80100094(arg0, 0U) + arg1 + 0xA))) == 1;
}

/* extern */

s32 sukickball_entrypoint_8(Actor *arg0, s32 arg1) {
    void* func_80100094(Actor*, u32);
    return ((s32 *)func_80100094(arg0, 0U))[arg1 + 4];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/kickball/sukickball_entrypoint_9.s")

/* extern */
void sukickball_entrypoint_10(Actor *arg0, s32 arg1, s32 arg2) {
    void* func_80100094(Actor*, u32);
    (*(s8 *)((s8 *)func_80100094(arg0, 0U) + arg1 + 0x34)) = (s8)arg2;
}

/* extern */

void sukickball_entrypoint_11(Actor *arg0, s32 arg1) {
    void* func_80100094(Actor*, u32);
    (*(s8 *)((s8 *)func_80100094(arg0, 0U) + arg1 + 0x34)) = 0;
}

/* extern */

u8 sukickball_entrypoint_12(Actor *arg0, s32 arg1) {
    void* func_80100094(Actor*, u32);
    return ((u8 *)func_80100094(arg0, 0))[arg1 + 0x34];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/kickball/sukickball_entrypoint_13.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/kickball/sukickball_entrypoint_14.s")

f32 sukickball_entrypoint_15(s32 arg0) {
    extern f32 D_80801234_sukickball[];
    return ((f32 *)&D_80801234_sukickball)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/kickball/sukickball_entrypoint_16.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/kickball/sukickball_entrypoint_17.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/kickball/sukickball_entrypoint_18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/kickball/sukickball_entrypoint_19.s")
