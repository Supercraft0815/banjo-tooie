#include "bs_script.h"
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
    s32 func_80091E48(BtIntPtr, s32);
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

void func_808000D0_bssilowait(BtIntPtr arg0) {
    void bs_setState(void *self, s32 nextState);
    void func_80099AA8(void *arg0);
    s32 func_8009E6EC(BT_NATIVE_ONLY(struct player_state_s *));
    void func_8009E830(void *arg0, s32 arg1);
    if (func_8009E6EC(BT_NATIVE_ONLY((struct player_state_s *)arg0)) == 0x90) {
        bs_setState(arg0, 1);
        func_8009E830(arg0, 2);
        return;
    }
    func_80099AA8(arg0);
}

void func_80800120_bssilowait(s32 arg0) 
{
}
BsScript bssilowait_entrypoint_0(BsScriptType arg0) {
    extern BtIntPtr D_80800140_bssilowait[];
    return (BsScript)D_80800140_bssilowait[arg0];
}
/* data_to_c.py: from asm/data/overlays/bs/silowait.data.s */
BtIntPtr D_80800140_bssilowait [4] BT_DATA(4, overlays_bs_silowait, 0x0) = { (BtIntPtr)func_80800000_bssilowait, (BtIntPtr)func_8080003C_bssilowait, (BtIntPtr)func_80800120_bssilowait, (BtIntPtr)func_808000D0_bssilowait };
