#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4440/func_800FAB50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4440/func_800FABF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4440/func_800FACA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4440/func_800FAD68.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4440/func_800FAE44.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4440/func_800FAF78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4440/func_800FB040.s")

/* extern */

void func_800FB1B0(s32 arg0, f32 *arg1, s32 arg2) {
    s32 func_800C6A7C(s32, f32 *, f32 *, s32);
    void func_800EE7F8(f32 *, f32 *);
    f32 sp24[3];
    f32 sp18[3];

    func_800EE7F8(sp18, arg1);
    func_800C6A7C(arg0, sp18, sp24, arg2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4440/func_800FB1EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4440/func_800FB2AC.s")

s32 func_800FB338(void *arg0, s32 arg1, s32 arg2, f32 *arg3) {
    *arg3 = (*(f32 *)((s8 *)(arg0) + (4)));
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4440/func_800FB350.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4440/func_800FB3C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4440/func_800FB434.s")

void func_800FB508(void *arg0, void *arg1) {
    (*(u16 *)((s8 *)(arg0) + (0))) = (u16) (*(u16 *)((s8 *)(arg1) + (0)));
    (*(u16 *)((s8 *)(arg0) + (2))) = (u16) (*(u16 *)((s8 *)(arg1) + (2)));
    (*(u16 *)((s8 *)(arg0) + (4))) = (u16) (*(u16 *)((s8 *)(arg1) + (4)));
    (*(s32 *)((s8 *)(arg0) + (8))) = (s32) (*(s32 *)((s8 *)(arg1) + (8)));
    (*(s16 *)((s8 *)(arg0) + (6))) = (s16) (*(s16 *)((s8 *)(arg1) + (6)));
}
