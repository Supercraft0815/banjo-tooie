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

/* extern */

typedef struct player_state_s PlayerState;

void func_808001F4_bsdroneslide(PlayerState *arg0, f32 arg1) {
    s32 pad;
    void baphysics_set_target_yaw(PlayerState *, f32);
    f32 bastick_distance(PlayerState *);
    f32 bastick_getAngleRelativeToBanjo(PlayerState *);
    f32 func_8009BB18(void *);
    void func_800A4DA4(PlayerState *, s32);
    f32 func_800D8FF8(void);
    f32 func_800F0DC0(f32, f32);
    f32 func_800F1DCC(f32, f32);
    f32 sp28;
    f32 sp24;
    s32 pad2;

    if (bastick_distance(arg0) != 0.0f) {
        arg1 += func_800F0DC0(func_800F1DCC(bastick_getAngleRelativeToBanjo(arg0), arg1), 60.0f);
    }
    sp28 = func_8009BB18(arg0);
    sp24 = sp28;
    sp28 = func_800F1DCC(arg1, sp28);
    sp28 *= func_800D8FF8();
    sp24 += sp28;
    baphysics_set_target_yaw(arg0, sp24);
    func_800A4DA4(arg0, 8);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/drone/slide/bsdroneslide_entrypoint_1.s")

/* extern */

void bsdroneslide_entrypoint_2(s32 arg0) {
    void func_8009BF5C(s32, f32);
    s32 func_800A4E30(s32);
    func_8009BF5C(arg0, 0.0f);
    func_800A4E30(arg0);
}
