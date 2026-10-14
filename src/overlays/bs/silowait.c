#include "common.h"
struct player_state_s;

/* extern */

void func_80800000_bssilowait(u8 *arg0) {
    void func_80091E6C(void *arg0);
    void baphysics_reset_gravity(u8 *);
    void baphysics_reset_terminal_velocity(u8 *);
    void func_80092880(struct player_state_s *, s32);
    func_80092880(arg0, 1);
    func_80091E6C(arg0);
    baphysics_reset_gravity(arg0);
    baphysics_reset_terminal_velocity(arg0);
}

/* extern */

void func_8080003C_bssilowait(struct player_state_s *arg0) {
    void baanim_playForDuration_loop(struct player_state_s *, s32, f32);
    void baphysics_set_gravity(struct player_state_s *, f32);
    void baphysics_set_target_horizontal_velocity(struct player_state_s *, f32);
    void baphysics_set_terminal_velocity(struct player_state_s *, f32);
    s32 func_80091E48(s32, s32);
    void func_80092880(struct player_state_s *, s32);
    void func_8009BA9C(struct player_state_s *, f32 *);
    void func_8009FFD8(struct player_state_s *, s32, s32, s32, s32);
    baanim_playForDuration_loop(arg0, 0x6F, 5.5f);
    func_8009FFD8(arg0, 1, 1, 3, 6);
    baphysics_set_target_horizontal_velocity(arg0, 0.0f);
    func_8009BA9C(arg0, 0);
    baphysics_set_gravity(arg0, 0.0f);
    baphysics_set_terminal_velocity(arg0, 0.0f);
    func_80091E48(arg0, 0x33);
    func_80092880(arg0, 0);
}

/* extern */

void func_808000D0_bssilowait(s32 arg0) {
    s32 bs_setState(s32, s32);
    s32 func_80099AA8(s32);
    s32 func_8009E6EC();
    s32 func_8009E830(s32, s32);
    if (func_8009E6EC() == 0x90) {
        bs_setState(arg0, 1);
        func_8009E830(arg0, 2);
        return;
    }
    func_80099AA8(arg0);
}

void func_80800120_bssilowait(s32 arg0) 
{
}
s32 bssilowait_entrypoint_0(s32 arg0) {
    extern s32 D_80800140_bssilowait[];
    return ((s32 *)&D_80800140_bssilowait)[arg0];
}
