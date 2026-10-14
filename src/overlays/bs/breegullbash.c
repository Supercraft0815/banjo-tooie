#include "common.h"

struct player_state_s;

/* extern */

void func_80800000_bsbreegullbash(struct player_state_s *arg0, f32 arg1, f32 arg2, f32 arg3) {
    void _babackpack_entrypoint_5(struct player_state_s *, f32 *, s32);
    void _badust_entrypoint_2(struct player_state_s *, f32 *, f32 *, f32, f32, f32);
    void func_800EFCD8(f32 *, f32, f32);
    f32 sp2C[3];
    f32 sp20[3];

    arg2 *= 0.51f;
    _babackpack_entrypoint_5(arg0, sp20, 2);
    sp20[1] -= 20.0f;
    func_800EFCD8(sp2C, arg1, arg2);
    sp2C[1] = arg3;
    _badust_entrypoint_2(arg0, sp20, sp2C, 0.1f, 0.8f, 0.7f);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/breegullbash/func_808000A4_bsbreegullbash.s")

void func_808001B4_bsbreegullbash(s32 arg0)
{
    _babackpack_set_state(arg0,0x7);
}

s32 func_808001D4_bsbreegullbash(s32 arg0) {
    void func_8009E4E0(void *, s32, s32);
    void func_8009E55C(struct player_state_s *, s32, f32);
    if (_babackpack_get_state() != 1) {
        _babackpack_set_state(arg0, 1);
        func_8009E4E0(arg0, 2, 0);
        func_8009E55C(arg0, 2, 0.0f);
    }
}

/* extern */

void bsbreegullbash_entrypoint_0(s32 arg0) {
    s32 baflag_clear(s32, s32);
    s32 func_8009E474();
    s32 func_808001D4_bsbreegullbash(s32);
    func_8009E474();
    func_808001D4_bsbreegullbash(arg0);
    baflag_clear(arg0, 0x3E);
}

/* extern */

void bsbreegullbash_entrypoint_1(struct player_state_s *arg0) {
    void baanim_playForDuration_onceSmooth(struct player_state_s *, s32, f32);
    void baphysics_set_target_horizontal_velocity(struct player_state_s *, f32);
    void baphysics_set_target_yaw(struct player_state_s *, f32);
    void func_8009E4AC(struct player_state_s *);
    void func_8009E4E0(void *, s32, s32);
    void func_8009E55C(struct player_state_s *, s32, f32);
    void func_8009FFD8(struct player_state_s *, s32, s32, s32, s32);
    f32 yaw_getIdeal(struct player_state_s *);
    baanim_playForDuration_onceSmooth(arg0, 0x20, 1.75f);
    func_8009FFD8(arg0, 1, 1, 3, 6);
    baphysics_set_target_yaw(arg0, yaw_getIdeal(arg0));
    func_8009E4AC(arg0);
    func_8009E4E0(arg0, 2, 0);
    func_8009E55C(arg0, 2, 0.0f);
    baphysics_set_target_horizontal_velocity(arg0, 0.0f);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/breegullbash/bsbreegullbash_entrypoint_2.s")

s32 bsbreegullbash_entrypoint_3(s32 arg0) {
    extern s32 D_80800560_bsbreegullbash[];
    return ((s32 *)&D_80800560_bsbreegullbash)[arg0];
}
