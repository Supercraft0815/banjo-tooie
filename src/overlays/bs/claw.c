#include "bs_script.h"
#include "common.h"
#if defined(BT_NATIVE)
struct anctrl_s;
struct player_state_s;
#endif
/* extern */

struct player_state_s;
void bsclaw_entrypoint_0(struct player_state_s *arg0) {
    void baflag_clear(struct player_state_s *, s32);
    BT_NATIVE_ONLY(void) BT_IDO_ONLY(s32) func_8009E474(BT_NATIVE_ONLY(struct player_state_s *));
    void func_800A0CF4(struct player_state_s *, s32);
    void func_800C6DA0(s32 arg0);
    func_8009E474(BT_NATIVE_ONLY(arg0));
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

/* extern */

void bsclaw_entrypoint_2(BT_NATIVE_ONLY(struct player_state_s *) BT_IDO_ONLY(BtIntPtr) arg0) {

    s32 _batimer_decrement(BT_NATIVE_ONLY(struct player_state_s *) BT_IDO_ONLY(BtIntPtr), s32);
    f32 _batimer_get(BT_NATIVE_ONLY(struct player_state_s *) BT_IDO_ONLY(BtIntPtr), s32);
    f32 anctrl_getAnimTimer(BT_NATIVE_ONLY(struct anctrl_s *) BT_IDO_ONLY(BtIntPtr));
    s32 anctrl_isAt(BT_NATIVE_ONLY(struct anctrl_s *) BT_IDO_ONLY(BtIntPtr), BT_NATIVE_ONLY(f32) BT_IDO_ONLY(s32));
    s32 anctrl_isStopped(BT_NATIVE_ONLY(struct anctrl_s *) BT_IDO_ONLY(BtIntPtr));
    #if defined(BT_NATIVE)
    struct anctrl_s *baanim_getAnimCtrlPtr(struct player_state_s *);
    #else
    s32 baanim_getAnimCtrlPtr(BT_NATIVE_ONLY(struct player_state_s *));
    #endif
    void baflag_clear(struct player_state_s *, s32);
    BT_NATIVE_ONLY(void) BT_IDO_ONLY(s32) baflag_set(BT_NATIVE_ONLY(struct player_state_s *) BT_IDO_ONLY(BtIntPtr), s32);
    s32 bakey_pressed(BT_NATIVE_ONLY(struct player_state_s *) BT_IDO_ONLY(BtIntPtr), s32);
    BT_NATIVE_ONLY(void) BT_IDO_ONLY(s32) baphysics_set_horizontal_velocity(BT_NATIVE_ONLY(struct player_state_s *) BT_IDO_ONLY(BtIntPtr), f32, BT_NATIVE_ONLY(f32) BT_IDO_ONLY(s32));
    void baphysics_set_target_horizontal_velocity(struct player_state_s *, f32);
    s32 bs_getTypeOfJump(BT_NATIVE_ONLY(struct player_state_s *) BT_IDO_ONLY(BtIntPtr));
    BT_NATIVE_ONLY(void) BT_IDO_ONLY(s32) bs_setState(BT_NATIVE_ONLY(struct player_state_s *) BT_IDO_ONLY(BtIntPtr), s32);
    BT_NATIVE_ONLY(void) BT_IDO_ONLY(s32) func_8009DE38(BT_NATIVE_ONLY(struct player_state_s *) BT_IDO_ONLY(BtIntPtr), s32, BT_NATIVE_ONLY(f32) BT_IDO_ONLY(s32));
    s32 player_inWater(BT_NATIVE_ONLY(struct player_state_s *) BT_IDO_ONLY(BtIntPtr));
    f32 yaw_get(BT_NATIVE_ONLY(struct player_state_s *) BT_IDO_ONLY(BtIntPtr));
    BT_NATIVE_ONLY(struct anctrl_s *) BT_IDO_ONLY(s32) sp24;
    s32 sp20;
    f32 sp1C;
    BT_NATIVE_ONLY(struct anctrl_s *) BT_IDO_ONLY(s32) temp_v0;

    temp_v0 = baanim_getAnimCtrlPtr(BT_NATIVE_ONLY((struct player_state_s *)(BtIntPtr)arg0));
    sp24 = temp_v0;
    sp20 = 0;
    sp1C = anctrl_getAnimTimer(temp_v0);
    if ((_batimer_get(arg0, 0) != 0.0f) && (bakey_pressed(arg0, 9) != 0)) {
        sp20 = 0x189;
    }
    _batimer_decrement(arg0, 0);
    if (anctrl_isAt(sp24, BT_DATA_FIELD(0.5128999948501587f, 0x3F034D6A)) != 0) {
        baphysics_set_horizontal_velocity(arg0, yaw_get(arg0), BT_DATA_FIELD(360.0f, 0x43B40000));
    }
    if (anctrl_isAt(sp24, BT_DATA_FIELD(0.6539000272750854f, 0x3F2765FE)) != 0) {
        baphysics_set_target_horizontal_velocity(arg0, 0);
    }
    if ((anctrl_isAt(sp24, BT_DATA_FIELD(0.14880000054836273f, 0x3E185F07)) != 0) || ((sp1C > 0.0488f) && (sp1C < 0.24880001f)) || (anctrl_isAt(sp24, BT_DATA_FIELD(0.3287999927997589f, 0x3EA85879)) != 0) || ((sp1C > 0.2288f) && (sp1C < 0.4288f)) || (anctrl_isAt(sp24, BT_DATA_FIELD(0.5788000226020813f, 0x3F142C3D)) != 0) || ((sp1C > 0.47880003f) && (sp1C < 0.67880005f))) {
        baflag_set(arg0, 0x1F);
    } else {
        baflag_clear(arg0, 0x1F);
    }
    if (anctrl_isAt(sp24, BT_DATA_FIELD(0.5788000226020813f, 0x3F142C3D)) != 0) {
        baphysics_set_target_horizontal_velocity(arg0, 0);
    }
    if (anctrl_isAt(sp24, BT_DATA_FIELD(0.11879999935626984f, 0x3DF34D6A)) != 0) {
        func_8009DE38(arg0, 0x442C, BT_DATA_FIELD(1.13f, 0x3F90A3D7));
    }
    if (anctrl_isAt(sp24, BT_DATA_FIELD(0.2888000011444092f, 0x3E93DD98)) != 0) {
        func_8009DE38(arg0, 0x442C, BT_DATA_FIELD(1.1f, 0x3F8CCCCD));
    }
    if (anctrl_isAt(sp24, BT_DATA_FIELD(0.5f, 0x3F000000)) != 0) {
        func_8009DE38(arg0, 0x442C, BT_DATA_FIELD(1.32f, 0x3FA8F5C3));
    }
    if (anctrl_isStopped(sp24) != 0) {
        sp20 = 1;
    }
    if (player_inWater(arg0) != 0) {
        sp20 = 0x4C;
    }
    if (bakey_pressed(arg0, 8) != 0) {
        sp20 = bs_getTypeOfJump(arg0);
    }
    bs_setState(arg0, sp20);
}

BsScript bsclaw_entrypoint_3(BsScriptType arg0) {
    extern BtIntPtr D_80800400_bsclaw[];
    return (BsScript)D_80800400_bsclaw[arg0];
}
/* data_to_c.py: from asm/data/overlays/bs/claw.data.s */
void _bsclaw_entrypoint_0();
void _bsclaw_entrypoint_1();
void _bsclaw_entrypoint_2();
void func_80099B94();
BtIntPtr D_80800400_bsclaw [4] BT_DATA(4, overlays_bs_claw, 0x0) = { (BtIntPtr)_bsclaw_entrypoint_0, (BtIntPtr)_bsclaw_entrypoint_1, (BtIntPtr)_bsclaw_entrypoint_2, (BtIntPtr)func_80099B94 };
