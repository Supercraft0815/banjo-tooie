#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/drone/slide/func_80800000_bsdroneslide.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/drone/slide/func_80800080_bsdroneslide.s")

/* extern */

void func_80800110_bsdroneslide(s32 arg0, s32 arg1, s32 arg2) {
    void func_800963C0(s32 *, f32 *);
    void func_800F1988(f32 *, s32, s32);
    f32 sp1C[3];

    func_800963C0((s32 *)arg0, sp1C);
    func_800F1988(sp1C, arg1, arg2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/drone/slide/bsdroneslide_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/drone/slide/func_808001F4_bsdroneslide.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/drone/slide/bsdroneslide_entrypoint_1.s")

/* extern */

void bsdroneslide_entrypoint_2(s32 arg0) {
    void func_8009BF5C(s32, f32);
    s32 func_800A4E30(s32);
    func_8009BF5C(arg0, 0.0f);
    func_800A4E30(arg0);
}
