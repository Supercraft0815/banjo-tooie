#include "common.h"

/* extern */

void func_800A0CF4(struct player_state_s *, s32);

void bstimeout_entrypoint_0(struct player_state_s *arg0) {
    void _ncbadie_entrypoint_3(struct player_state_s *, f32);
    void baanim_playForDuration_onceSmooth(struct player_state_s *, s32, f32);
    void baphysics_set_target_horizontal_velocity(struct player_state_s *, f32);
    void func_8008E944(struct player_state_s *);
    f32 func_8009F308(struct player_state_s *);
    void func_8009FFD8(struct player_state_s *, s32, s32, s32, s32);
    struct player_state_s *func_800A4CA8(struct player_state_s *);
    void func_800A4DA4(struct player_state_s *, s32);
    void func_800FC6B0(u32);
    void yaw_setIdeal(struct player_state_s *, f32);
    baanim_playForDuration_onceSmooth(arg0, 0x77, 3.2f);
    func_8009FFD8(arg0, 1, 1, 3, 2);
    baphysics_set_target_horizontal_velocity(arg0, 0.0f);
    func_800A4DA4(arg0, 0xA);
    yaw_setIdeal(arg0, func_8009F308(arg0) + 35.0f);
    _ncbadie_entrypoint_3(func_800A4CA8(arg0), 80.0f);
    func_800FC6B0(0x17);
    func_800A0CF4(arg0, 1);
    func_8008E944(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/timeout/bstimeout_entrypoint_1.s")

void bstimeout_entrypoint_2(s32 arg0)
{
    func_800951B4();
    func_800A4E30(arg0);
}
s32 bstimeout_entrypoint_3(s32 arg0) {
    extern s32 D_80800330_bstimeout[];
    return ((s32 *)&D_80800330_bstimeout)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/timeout/bstimeout_entrypoint_4.s")

void bstimeout_entrypoint_5(u8 *arg0) {
    s32 _batimer_decrement(void *, s32);
    s32 func_800A05DC();
    if (_batimer_decrement(arg0, 0) != 0) {
        func_800A05DC(arg0);
    }
}

void bstimeout_entrypoint_6(void *arg0) { func_800A0CF4(arg0, 0); func_800A4E30(arg0); func_800FC7C4(); }

s32 bstimeout_entrypoint_7(s32 arg0) {
    extern s32 D_80800340_bstimeout[];
    return ((s32 *)&D_80800340_bstimeout)[arg0];
}
