#include "common.h"

/* extern */

struct player_state_s;

void bsdronelook_entrypoint_0(struct player_state_s *arg0) {
    void _bafpctrl_entrypoint_13(void *arg0, s32 arg1);
    void _bafpctrl_entrypoint_17(struct player_state_s *);
    s32 _bafpctrl_entrypoint_4(struct player_state_s *);
    s32 _bafpctrl_entrypoint_6(struct player_state_s *);
    s32 func_800A4EC8(void *);
    if (_bafpctrl_entrypoint_4(arg0) == 2) {
        _bafpctrl_entrypoint_13(arg0, 1);
    }
    if (_bafpctrl_entrypoint_6(arg0) != 0) {
        func_800A4EC8(arg0);
        _bafpctrl_entrypoint_17(arg0);
    }
}

void bsdronelook_entrypoint_1(struct player_state_s *arg0) {
    void _badata_entrypoint_3();
    void _bafpctrl_entrypoint_11(struct player_state_s *, s32, s32);
    void _bafpctrl_entrypoint_16(struct player_state_s *, s32);
    s32 _bafpctrl_entrypoint_4(struct player_state_s *);
    void baanim_playForDuration_loopSmooth(struct player_state_s *, s32, f32);
    void baphysics_set_target_horizontal_velocity(struct player_state_s *, f32);
    void func_8009BA9C(struct player_state_s *, f32 *);
    void func_8009FFD8();
    int func_800A3274(struct player_state_s *);
    s32 func_800A4E94(void *);
    f32 sp2C;
    s32 sp28;

    _badata_entrypoint_3(arg0, &sp28, &sp2C);
    baanim_playForDuration_loopSmooth(arg0, sp28, sp2C);
    func_8009FFD8(arg0, 1, 1, 3, 2);
    baphysics_set_target_horizontal_velocity(arg0, 0.0f);
    func_8009BA9C(arg0, 0);
    if (_bafpctrl_entrypoint_4(arg0) != 3) {
        func_800A4E94(arg0);
        switch (func_800A3274(arg0)) {
        case 2:
        case 8:
        case 10:
        case 13:
        case 14:
        case 15:
        case 16:
        case 17:
        case 18:
        case 19:
            _bafpctrl_entrypoint_11(arg0, 4, 1);
            break;
        }
        _bafpctrl_entrypoint_16(arg0, 3);
    }
}

/* extern */

BT_IDO_ONLY(void) BT_NATIVE_ONLY(f32) bsdronelook_entrypoint_2(f32 arg0) {
    f32 func_800F0E00(f32 arg0, f32 arg1);
    f32 func_800F13F0(f32 arg0, f32 arg1);
    if (arg0 > 180.0f) {
        BT_NATIVE_ONLY(return) func_800F0E00(292.0f, arg0);
        BT_IDO_ONLY(return;)
    }
    if (arg0 < -65.0f) {
        BT_NATIVE_ONLY(return) func_800F0E00(-65.0f, arg0);
        BT_IDO_ONLY(return;)
    }
    BT_NATIVE_ONLY(return) func_800F13F0(70.0f, arg0);
}

/* extern */

void bsdronelook_entrypoint_3(BtIntPtr arg0) {
    s32 _badata_entrypoint_34(BtIntPtr);
    s32 _bafpctrl_entrypoint_4();
    void bs_setState(void *self, s32 nextState);
    u32 func_800A3404(void *arg0);
    s32 sp1C;

    sp1C = 0;
    if ((_bafpctrl_entrypoint_4() != 3) && (func_800A3404(arg0) == 0)) {
        sp1C = _badata_entrypoint_34(arg0);
    }
    bs_setState(arg0, sp1C);
}

/* extern */

void bsdronelook_entrypoint_4(BT_PARAM_OR_VOID(s32 bt_a0)) {
    s32 func_80099B94();
    func_80099B94(BT_NATIVE_ONLY(bt_a0));
}
