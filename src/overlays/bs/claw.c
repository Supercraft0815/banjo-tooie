#include "common.h"

/* extern */

struct player_state_s;
void bsclaw_entrypoint_0(struct player_state_s *arg0) {
    void baflag_clear(struct player_state_s *, s32);
    s32 func_8009E474();
    void func_800A0CF4(struct player_state_s *, s32);
    s32 func_800C6DA0(s32);
    func_8009E474();
    func_800C6DA0(0x47);
    baflag_clear(arg0, 0x1F);
    func_800A0CF4(arg0, 0);
}

/* extern */

void bsclaw_entrypoint_1(struct player_state_s *arg0) {
    void _batimer_set(struct player_state_s *, s32, f32);
    void baanim_playForDuration_onceSmooth(struct player_state_s *, s32, f32);
    void baflag_clear(struct player_state_s *, s32);
    void baphysics_set_target_horizontal_velocity(struct player_state_s *, f32);
    void baphysics_set_target_yaw(struct player_state_s *, f32);
    void func_8009E4AC(struct player_state_s *);
    void func_8009E55C(struct player_state_s *, s32, f32);
    void func_8009E5A4(struct player_state_s *, s32, s32);
    void func_8009FFD8(struct player_state_s *, s32, s32, s32, s32);
    void func_800A0CF4(struct player_state_s *, s32);
    int func_800C6E38(s32);
    f32 yaw_getIdeal(struct player_state_s *);
    f32 var_f0;

    baanim_playForDuration_onceSmooth(arg0, 5, 1.4f);
    func_8009FFD8(arg0, 1, 1, 1, 2);
    baphysics_set_target_yaw(arg0, yaw_getIdeal(arg0));
    baphysics_set_target_horizontal_velocity(arg0, 80.0f);
    baflag_clear(arg0, 0x1F);
    func_800A0CF4(arg0, 1);
    if (func_800C6E38(0x32) != 0) {
        var_f0 = 0.24f;
    } else {
        var_f0 = 0.0f;
    }
    _batimer_set(arg0, 0, var_f0);
    func_8009E4AC(arg0);
    func_8009E5A4(arg0, 2, 3);
    func_8009E55C(arg0, 2, 40.0f);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/claw/bsclaw_entrypoint_2.s")

s32 bsclaw_entrypoint_3(s32 arg0) {
    extern s32 D_80800400_bsclaw[];
    return ((s32 *)&D_80800400_bsclaw)[arg0];
}
