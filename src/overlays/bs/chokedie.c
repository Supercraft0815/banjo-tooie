#include "common.h"

/* extern */

void bschokedie_entrypoint_0(struct player_state_s *arg0) {
    typedef struct player_state_s PlayerState;
    void _basudie_entrypoint_1(PlayerState *);
    void _batimer_set(PlayerState *, s32, f32);
    void _ncbadie_entrypoint_3(PlayerState *, f32);
    void baanim_playForDuration_onceSmooth(PlayerState *, s32, f32);
    void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
    void func_8008E944(PlayerState *);
    void func_80090A0C(PlayerState *);
    void func_8009BA9C(PlayerState *, f32 *);
    void func_8009FFD8(PlayerState *, s32, s32, s32, s32);
    void func_800A0180(PlayerState *);
    PlayerState *func_800A4CA8(PlayerState *);
    void func_800A4DFC(PlayerState *, s32);
    baanim_playForDuration_onceSmooth(arg0, 0xF0, 4.2f);
    func_8009FFD8(arg0, 1, 1, 2, 3);
    func_8009BA9C(arg0, 0);
    baphysics_set_target_horizontal_velocity(arg0, 0.0f);
    func_800A4DFC(arg0, 0xA);
    _ncbadie_entrypoint_3(func_800A4CA8(arg0), 30.0f);
    func_800A0180(arg0);
    _batimer_set(arg0, 0, 3.8f);
    func_8008E944(arg0);
    func_80090A0C(arg0);
    _basudie_entrypoint_1(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/chokedie/bschokedie_entrypoint_1.s")

/* extern */

void bschokedie_entrypoint_2(s32 arg0) {
    s32 baroll_setIdeal(s32, f32);
    s32 func_800951B4();
    s32 func_8009BF5C(s32, f32);
    s32 func_800A4E30(s32);
    func_800951B4();
    func_8009BF5C(arg0, 0.0f);
    baroll_setIdeal(arg0, 0.0f);
    func_800A4E30(arg0);
}

s32 bschokedie_entrypoint_3(s32 arg0) {
    extern s32 D_808002B0_bschokedie[];
    return ((s32 *)&D_808002B0_bschokedie)[arg0];
}
