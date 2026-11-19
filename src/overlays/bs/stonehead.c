#include "common.h"
#ifdef BT_NATIVE
#include "overlays/ba/anim_smooth.h"
#endif
#include "overlays/ba/playerstate.h"
#include "bs_script.h"
#include "overlays/ba/assets.h"

enum baanim_update_type_e {
    BAANIM_UPDATE_0_NONE,
    BAANIM_UPDATE_1_NORMAL,
    BAANIM_UPDATE_2_SCALE_HORZ,
    BAANIM_UPDATE_3_SCALE_VERT,
    BAANIM_UPDATE_4_UNKOWN
};

enum yaw_type_e {
    YAW_TYPE_0_NONE,
    YAW_TYPE_1_DEFAULT,
    YAW_TYPE_2_UNBOUNDED,
    YAW_TYPE_3_BOUNDED
};

enum ba_physics_type_e {
    BA_PHYSICS_0_NONE,
    BA_PHYSICS_1_UNKNOWN,
    BA_PHYSICS_2_NORMAL,
    BA_PHYSICS_3_LOCKED_ROTATION,
    BA_PHYSICS_4_UNKNOWN,
    BA_PHYSICS_5_INVERTED_YAW,
    BA_PHYSICS_6_AIRBORN,
    BA_PHYSICS_7_FREEZE,
    BA_PHYSICS_8_UNKNOWN,
    BA_PHYSICS_9_NO_GRAVITY,
    BA_PHYSICS_A_CLIMB,
    BA_PHYSICS_B_TRANSFORM,
    BA_PHYSICS_C_GOTO,
    BA_PHYSICS_D_END,
    BA_PHYSICS_E_UNKNOWN
};

struct anctrl_s;
void func_80092864(PlayerState *, f32);
void func_800947EC(PlayerState *, s32, s32);
void func_80095A40(PlayerState *);
void func_80095A74(void *, s32);
s32 func_8009E74C(PlayerState *, s32);
void func_800959C8(PlayerState *, f32, f32);
s32 func_8009E77C(PlayerState *, s32);
s32 _baattach_entrypoint_1(PlayerState *);
void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
s32 bastick_getZone(PlayerState *);
f32 bastick_getZonePosition(PlayerState *);
s32 func_8008DE24(PlayerState *);
f32 func_800F1214(f32, f32, f32);
s32 func_800DA298(s32);
s32 _badrone_entrypoint_24(PlayerState *);
int bainput_should_enter_first_person(PlayerState *);
void _basudie_entrypoint_2(BtIntPtr arg0, f32 arg1, f32 arg2, f32 arg3);
struct anctrl_s *baanim_getAnimCtrlPtr(PlayerState *);
void baanim_setEnd(PlayerState *, f32);
void anctrl_reset(struct anctrl_s *);
void anctrl_setSmoothTransition(struct anctrl_s *, s32);
void anctrl_setIndex(struct anctrl_s *, enum asset_e);
void anctrl_setSubrange(struct anctrl_s *, f32, f32);
void anctrl_setDuration(struct anctrl_s *, f32);
void anctrl_setPlaybackType(struct anctrl_s *, s32);
void anctrl_start(struct anctrl_s *);
void func_8009D820(PlayerState *, f32);
void func_8009DF94(PlayerState *, s32, f32, s32);
void func_8009DF18(PlayerState *, s32, f32, s32);
void _basudie_entrypoint_5(PlayerState *);
f32 func_800F0E00(f32, f32);
void anctrl_setStart(struct anctrl_s *, f32);
void baanim_setEndAndDuration(PlayerState *, f32, f32);
void func_800A2E18(PlayerState *);
void _baattach_entrypoint_6(PlayerState *, s32, s32, s32);
f32 baphysics_get_target_horizontal_velocity(PlayerState *);
void baphysics_set_gravity(PlayerState *, f32);
void baphysics_set_horizontal_velocity(PlayerState *, f32, f32);
void baphysics_set_target_yaw(PlayerState *, f32);
void baphysics_set_vertical_velocity(PlayerState *, f32);
f32 bastick_distance(PlayerState *);
f32 bastick_getAngleRelativeToBanjo(PlayerState *);
void func_8009D7A4(PlayerState *, f32, f32);
f32 yaw_getIdeal(PlayerState *);
void yaw_setIdeal(PlayerState *, f32);
void baanim_playForDuration_loopStartingAt(struct player_state_s *, enum asset_e, f32, f32);
void func_8008C9F0(PlayerState *, f32, f32, f32, f32);
s32 _badrone_entrypoint_25(PlayerState *);
s32 bakey_func_80091940(PlayerState *, s32, s32);
int bakey_newlyReleased(PlayerState *, s32);
int bakey_pressed(PlayerState *, s32);
int func_8008DD04(PlayerState *);
int func_8008E148(PlayerState *);
s32 func_8009BCD4(PlayerState *, f32);
void func_800A2CE8(PlayerState *, f32, s32);
s32 _baspin_entrypoint_3(BtIntPtr);
void _babounce_entrypoint_4(PlayerState *, s32);
void _babounce_entrypoint_5(PlayerState *, s32, f32);
s32 _babounce_entrypoint_9(BtIntPtr);
s32 _bsrest_entrypoint_13(BtIntPtr);
void _batimer_set(PlayerState *, s32, f32);
s32 _batimer_decrement(void *, s32);
f32 _batimer_get(void *, s32);
f32 func_800D8FF8(void);
f32 func_800F10B4(f32, f32, f32, f32, f32);
void yaw_applyIdeal(PlayerState *self);
s32 func_800A02DC(PlayerState *, s32);

int baanim_isStopped(PlayerState *);
int bakey_released(PlayerState *, int);
f32 baphysics_get_vertical_velocity(PlayerState *);
void baphysics_reset_gravity(PlayerState *);
int func_8008DF8C(PlayerState *, s32);
void func_8009D3A8(PlayerState *, s32);
int player_isStable(PlayerState *);
void bs_setState(void *self, s32 nextState);
void func_80800000_bsstonehead(PlayerState *);
void func_80800060_bsstonehead(PlayerState *);
void func_808000CC_bsstonehead(PlayerState *);
int func_808003B8_bsstonehead(PlayerState *);
s32 func_808003F4_bsstonehead(PlayerState *, s32);
void func_808005F0_bsstonehead(PlayerState *, s32);
void func_808008CC_bsstonehead(PlayerState *, s32);
void func_80800B38_bsstonehead(PlayerState *, u32);

void func_80800000_bsstonehead(PlayerState *arg0) {
    void func_80092864(PlayerState *, f32);
    void func_800947EC(PlayerState *, s32, s32);
    void func_80095A40(PlayerState *);
    void func_80095A74(void *, s32);
    s32 func_8009E74C(PlayerState *, s32);
    if (func_8009E74C(arg0, 3) == 0) {
        func_800947EC(arg0, 1, 0);
        func_80095A40(arg0);
        func_80092864(arg0, 1.0f);
        func_80095A74(arg0, 0);
    }
}

void func_80800060_bsstonehead(PlayerState *arg0) {
    void func_80092864(PlayerState *, f32);
    void func_800947EC(PlayerState *, s32, s32);
    void func_800959C8(PlayerState *, f32, f32);
    void func_80095A74(void *, s32);
    s32 func_8009E77C(PlayerState *, s32);
    if (func_8009E77C(arg0, 3) == 0) {
        func_800959C8(arg0, 65.0f, 35.0f);
        func_80092864(arg0, 0.8999939f);
        func_800947EC(arg0, 1, 1);
        func_80095A74(arg0, 1);
    }
}

void func_808000CC_bsstonehead(PlayerState *arg0) {
    s32 _baattach_entrypoint_1(PlayerState *);
    void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
    s32 bastick_getZone(PlayerState *);
    f32 bastick_getZonePosition(PlayerState *);
    s32 func_8008DE24(PlayerState *);
    f32 func_800F1214(f32, f32, f32);
    int player_isStable(PlayerState *);
    f32 sp24;
    f32 sp20;

    sp24 = bastick_getZonePosition(arg0);
    if (_baattach_entrypoint_1(arg0) != 0) {
        sp20 = 250.0f;
    } else if (func_8008DE24(arg0) != 0 && player_isStable(arg0) != 0) {
        sp20 = 80.0f;
    } else {
        sp20 = 400.0f;
    }
    if (bastick_getZone(arg0) == 0) {
        baphysics_set_target_horizontal_velocity(arg0, 0.0f);
    } else {
        baphysics_set_target_horizontal_velocity(arg0, func_800F1214(sp24, 30.0f, sp20));
    }
}

void func_80800194_bsstonehead(PlayerState *arg0, s32 arg1) {
    void func_8009FFD8(PlayerState *, enum baanim_update_type_e, enum yaw_type_e, s32, enum ba_physics_type_e);
    void _batimer_set(PlayerState *, s32, f32);
    f32 yaw_getIdeal(PlayerState *);
    struct anctrl_s *sp34;
    f32 unused[2];
    f32 sp28;

    sp34 = baanim_getAnimCtrlPtr(arg0);
    if (arg0->unk15C.word == 0) {
        func_80800060_bsstonehead(arg0);
    }
    arg0->unk15C.word = arg1;
    switch (arg1) {
    case 1:
        if (func_8008DE24(arg0) != 0 && player_isStable(arg0) != 0) {
            arg0->unk16C = 150.0f;
        } else {
            arg0->unk16C = 600.0f;
        }
        func_8009DF94(arg0, 0x5A7, 1.4f, 0x55F0);
        baflag_set(arg0, 0x20);
        _batimer_set(arg0, 0, 0.01f);
        func_8009FFD8(arg0, 1, 1, 3, 3);
        _badust_entrypoint_12(arg0, 2);
        baphysics_set_target_yaw(arg0, yaw_getIdeal(arg0));
        baphysics_set_target_horizontal_velocity(arg0, arg0->unk16C);
        sp28 = yaw_getIdeal(arg0);
        baphysics_set_horizontal_velocity(arg0, sp28, baphysics_get_target_horizontal_velocity(arg0));
        anctrl_reset(sp34);
        anctrl_setIndex(sp34, 0x64);
        anctrl_setDuration(sp34, 1.0f);
        anctrl_setSubrange(sp34, 0.0f, 0.26f);
        anctrl_setPlaybackType(sp34, 1);
        anctrl_start(sp34);
        return;
    case 2:
        anctrl_setDuration(sp34, 5.0f);
        baanim_setEnd(arg0, 0.3078f);
        return;
    case 3:
        _badust_entrypoint_12(arg0, 1);
        baflag_clear(arg0, 0x20);
        anctrl_setDuration(sp34, 1.0f);
        baanim_setEnd(arg0, 1.0f);
        return;
    case 0:
        _badust_entrypoint_12(arg0, 1);
        baflag_clear(arg0, 0x20);
        func_80800000_bsstonehead(arg0);
        return;
    }
}

int func_808003B8_bsstonehead(PlayerState *arg0) {
    int bakey_pressed();
    s32 func_800DA298(s32);
    return bakey_pressed(arg0, 8) && !func_800DA298(0x65A);
}

/* extern */

s32 func_808003F4_bsstonehead(PlayerState *arg0, s32 arg1) {
    s32 _badrone_entrypoint_24(PlayerState *);
    int bainput_should_enter_first_person(PlayerState *);
    s32 bastick_getZone();

    if (bainput_should_enter_first_person(arg0) != 0) {
        arg1 = _badrone_entrypoint_24(arg0);
    }
    if (bastick_getZone(arg0) > 0) {
        arg1 = 0xB2;
    }
    if (func_808003B8_bsstonehead(arg0) != 0) {
        arg1 = 0xAE;
    }
    return arg1;
}

void bsstonehead_entrypoint_0(BtIntPtr arg0)
{
    func_80800194_bsstonehead(arg0,0);
}

void bsstonehead_entrypoint_1(s32 *arg0) { arg0[87] = 0; func_80800194_bsstonehead(arg0, 1); }

void bsstonehead_entrypoint_2(PlayerState *arg0) {
    int _batimer_isZero(PlayerState *, s32);
    f32 baanim_getTimer(PlayerState *);
    int baanim_isStopped(PlayerState *);
    void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
    s32 func_800F1574(f32 *, f32);
    void bs_setState(void *self, s32 nextState);
    s32 next_state = 0;

    switch (arg0->unk15C.word) {
        case 1:
            if (baanim_isStopped(arg0) != 0) {
                func_80800194_bsstonehead(arg0, 2);
            }
            break;
        case 2:
            _batimer_decrement(arg0, 0);
            if (_batimer_isZero(arg0, 0) != 0) {
                arg0->unk16C -= 80.0f;
                baphysics_set_target_horizontal_velocity(arg0, arg0->unk16C);
                if (arg0->unk16C < 200.0f) {
                    func_80800194_bsstonehead(arg0, 3);
                }
            }
            break;
        case 3:
            func_800F1574(&arg0->unk16C, 0.8f);
            if (baanim_isStopped(arg0) != 0) {
                next_state = 0xB3;
            }
            if (baanim_getTimer(arg0) > 0.8f) {
                next_state = func_808003F4_bsstonehead(arg0, next_state);
            }
            break;
    }
    bs_setState((BtIntPtr)arg0, next_state);
}

BsScript bsstonehead_entrypoint_3(BsScriptType arg0) {
    extern BtIntPtr D_80801630_bsstonehead[];
    return (BsScript)D_80801630_bsstonehead[arg0];
}

struct anctrl_s;
enum asset_e;

void func_808005F0_bsstonehead(PlayerState *arg0, s32 arg1) {
    void _basudie_entrypoint_2(BtIntPtr arg0, f32 arg1, f32 arg2, f32 arg3);
    struct anctrl_s *baanim_getAnimCtrlPtr(PlayerState *);
    void baanim_setEnd(PlayerState *, f32);
    void anctrl_reset(struct anctrl_s *);
    void anctrl_setSmoothTransition(struct anctrl_s *, s32);
    void anctrl_setIndex(struct anctrl_s *, enum asset_e);
    void anctrl_setSubrange(struct anctrl_s *, f32, f32);
    void anctrl_setDuration(struct anctrl_s *, f32);
    void anctrl_setPlaybackType(struct anctrl_s *, s32);
    void anctrl_start(struct anctrl_s *);
    void func_8009D820(PlayerState *, f32);
    void func_8009DF94(PlayerState *, s32, f32, s32);
    void func_8009DF18(PlayerState *, s32, f32, s32);
    struct anctrl_s *animCtrl;

    switch (arg1) {
        case 3:
            break;
        case 1:
            animCtrl = baanim_getAnimCtrlPtr(arg0);
            arg0->unk16C = 250.0f;
            _basudie_entrypoint_2(arg0, 250.0f, 420.0f, -1200.0f);
            anctrl_reset(animCtrl);
            anctrl_setSmoothTransition(animCtrl, 0);
            anctrl_setIndex(animCtrl, 0x33);
            anctrl_setSubrange(animCtrl, 0.0f, 0.46f);
            anctrl_setDuration(animCtrl, 2.5f);
            anctrl_setPlaybackType(animCtrl, 1);
            anctrl_start(animCtrl);
            func_8009D820(arg0, 1.8f);
            break;
        case 2:
            baanim_setEnd(arg0, 1.0f);
            func_8009DF94(arg0, 0x417, 0.8f, 0x4650);
            func_8009DF18(arg0, 0x428, 1.8f, 0x4650);
            break;
    }
    arg0->unk15C.word = arg1;
}

/* extern */

void bsstonehead_entrypoint_4(BtIntPtr arg0) {
    void func_808005F0_bsstonehead(PlayerState *, s32);
    func_80800060_bsstonehead(arg0);
    (((PlayerState *)arg0)->unk15C.word) = 0;
    func_808005F0_bsstonehead(arg0, 1);
}

void bsstonehead_entrypoint_5(PlayerState *arg0) {
    void _basudie_entrypoint_5(PlayerState *);
    void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
    int player_isStable(PlayerState *);
    f32 func_800F0E00(f32, f32);
    void bs_setState(void *self, s32 nextState);
    f32 velocity;

    _basudie_entrypoint_5(arg0);
    baphysics_set_target_horizontal_velocity(arg0, arg0->unk16C);
    switch (arg0->unk15C.word) {
        case 1:
            if (player_isStable(arg0)) {
                func_808005F0_bsstonehead(arg0, 2);
            }
            break;
        case 2:
            func_808005F0_bsstonehead(arg0, 3);
            break;
        case 3:
            velocity = arg0->unk16C;
            if (velocity > 0.0f) {
                arg0->unk16C = func_800F0E00(0.0f, velocity - 10.0f);
            }
            break;
    }
    bs_setState(arg0, 0);
}

void bsstonehead_entrypoint_6(BT_NATIVE_ONLY(s32 bt_a0))
{
    _basudie_entrypoint_6(BT_NATIVE_ONLY(bt_a0));
}

BsScript bsstonehead_entrypoint_7(BsScriptType arg0) {
    extern BtIntPtr D_80801640_bsstonehead[];
    return (BsScript)D_80801640_bsstonehead[arg0];
}

void bsstonehead_entrypoint_8(PlayerState *arg0)
{
    func_80800060_bsstonehead(arg0);
    _bsdrone_entrypoint_0(arg0);
}
void bsstonehead_entrypoint_9(PlayerState* self)
{
    _bsdrone_entrypoint_1(self);
}
void bsstonehead_entrypoint_10(PlayerState *arg0)
{
    func_80800000_bsstonehead(arg0);
    _bsdrone_entrypoint_2(arg0);
}
BsScript bsstonehead_entrypoint_11(BsScriptType arg0) {
    extern BtIntPtr D_80801650_bsstonehead[];
    return (BsScript)D_80801650_bsstonehead[arg0];
}

struct anctrl_s;
enum asset_e;
enum baanim_update_type_e;
enum yaw_type_e;
enum ba_physics_type_e;

void func_808008CC_bsstonehead(PlayerState *arg0, s32 arg1)
{
    void func_8009FFD8(PlayerState *, enum baanim_update_type_e, enum yaw_type_e, s32, enum ba_physics_type_e);
    void anctrl_reset(struct anctrl_s *);
    void anctrl_setIndex(struct anctrl_s *, enum asset_e);
    void anctrl_setStart(struct anctrl_s *, f32);
    void anctrl_setSubrange(struct anctrl_s *, f32, f32);
    void anctrl_setDuration(struct anctrl_s *, f32);
    void anctrl_setPlaybackType(struct anctrl_s *, s32);
    void anctrl_start(struct anctrl_s *);
    struct anctrl_s *baanim_getAnimCtrlPtr(PlayerState *);
    void baanim_setEndAndDuration(PlayerState *, f32, f32);
    void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
    void func_800A2E18(PlayerState *);
    struct anctrl_s *control;

    switch (arg1) {
        case 0:
            break;
        case 1:
            control = baanim_getAnimCtrlPtr(arg0);
            anctrl_reset(control);
            anctrl_setIndex(control, 0x122);
            anctrl_setStart(control, 0.6364f);
            anctrl_setSubrange(control, 0.6364f, 0.7576f);
            anctrl_setDuration(control, 4.0f);
            anctrl_setPlaybackType(control, 1);
            anctrl_start(control);
            func_8009FFD8(arg0, 1, 1, 3, 6);
            break;
        case 2:
            baanim_setEndAndDuration(arg0, 1.0f, 0.8f);
            break;
        case 3:
            func_800A2E18(arg0);
            baphysics_set_target_horizontal_velocity(arg0, 0.0f);
            break;
    }
    (arg0->unk15C.word) = arg1;
}

void bsstonehead_entrypoint_12(PlayerState *arg0)
{
    func_808008CC_bsstonehead(arg0,0);
    func_80800000_bsstonehead(arg0);
}

void bsstonehead_entrypoint_13(PlayerState *arg0) { func_80800060_bsstonehead(arg0); (arg0->unk15C.word) = 1; func_808008CC_bsstonehead(arg0, 1); }

void bsstonehead_entrypoint_14(PlayerState *arg0) {
    int baanim_isStopped(PlayerState *);
    int player_isStable(PlayerState *);
    int func_8008DF8C(PlayerState *, s32);
    void func_8009D3A8(PlayerState *, s32);
    void bs_setState(void *self, s32 nextState);
    s32 sp24;

    sp24 = 0;
    func_808000CC_bsstonehead(arg0);
    func_8009D3A8(arg0, 0);
    switch (arg0->unk15C.word) {
        case 1:
            if (func_8008DF8C(arg0, 0x82)) {
                func_808008CC_bsstonehead(arg0, 2);
            }
            break;
        case 2:
            if (player_isStable(arg0)) {
                func_808008CC_bsstonehead(arg0, 3);
            }
            break;
        case 3:
            if (baanim_isStopped(arg0)) {
                sp24 = 0xB3;
            }
            break;
    }
    if (player_isStable(arg0)) {
        sp24 = func_808003F4_bsstonehead(arg0, sp24);
    }
    bs_setState(arg0, sp24);
}

BsScript bsstonehead_entrypoint_15(BsScriptType arg0) {
    extern BtIntPtr D_80801660_bsstonehead[];
    return (BsScript)D_80801660_bsstonehead[arg0];
}

void func_80800B38_bsstonehead(PlayerState *arg0, u32 arg1) {
    void _baattach_entrypoint_6(PlayerState *, s32, s32, s32);
    void anctrl_reset(struct anctrl_s *);
    void anctrl_setDuration(struct anctrl_s *, f32);
    void anctrl_setIndex(struct anctrl_s *, enum asset_e);
    void anctrl_setPlaybackType(struct anctrl_s *, s32);
    void anctrl_setSubrange(struct anctrl_s *, f32, f32);
    void anctrl_start(struct anctrl_s *);
    struct anctrl_s *baanim_getAnimCtrlPtr(PlayerState *);
    void baanim_setEndAndDuration(PlayerState *, f32, f32);
    f32 baphysics_get_target_horizontal_velocity(PlayerState *);
    void baphysics_reset_gravity(PlayerState *);
    void baphysics_set_gravity(PlayerState *, f32);
    void baphysics_set_horizontal_velocity(PlayerState *, f32, f32);
    void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
    void baphysics_set_target_yaw(PlayerState *, f32);
    void baphysics_set_vertical_velocity(PlayerState *, f32);
    f32 bastick_distance(PlayerState *);
    f32 bastick_getAngleRelativeToBanjo(PlayerState *);
    void func_8009D7A4(PlayerState *, f32, f32);
    void func_8009FFD8(PlayerState *, enum baanim_update_type_e, enum yaw_type_e, s32, enum ba_physics_type_e);
    void func_800A2E18(PlayerState *);
    f32 yaw_getIdeal(PlayerState *);
    void yaw_setIdeal(PlayerState *, f32);
    struct anctrl_s *sp34;
    s32 pad30;
    f32 sp2C;
    s32 pad28;

    switch (arg1) {
    case 0:
        baphysics_set_target_horizontal_velocity(arg0, 0.0f);
        baphysics_reset_gravity(arg0);
        break;
    case 1:
        sp34 = baanim_getAnimCtrlPtr(arg0);
        _baattach_entrypoint_6(arg0, 3, 0, 0);
        anctrl_reset(sp34);
        anctrl_setIndex(sp34, 0x122);
        anctrl_setDuration(sp34, 0.8f);
        anctrl_setSubrange(sp34, 0.0f, 0.6364f);
        anctrl_setPlaybackType(sp34, 1);
        anctrl_start(sp34);
        func_8009FFD8(arg0, 1, 1, 3, 6);
        if (bastick_distance(arg0) != 0.0f) {
            yaw_setIdeal(arg0, bastick_getAngleRelativeToBanjo(arg0));
        }
        baphysics_set_target_yaw(arg0, yaw_getIdeal(arg0));
        func_808000CC_bsstonehead(arg0);
        sp2C = yaw_getIdeal(arg0);
        baphysics_set_horizontal_velocity(arg0, sp2C, baphysics_get_target_horizontal_velocity(arg0));
        baphysics_set_vertical_velocity(arg0, 576.0f);
        baphysics_set_gravity(arg0, -1200.0f);
        func_8009D7A4(arg0, 1.35f, 1.45f);
        break;
    case 2:
        baanim_setEndAndDuration(arg0, 0.7576f, 4.0f);
        break;
    case 3:
        baanim_setEndAndDuration(arg0, 1.0f, 0.8f);
        break;
    case 4:
        func_800A2E18(arg0);
        break;
    }
    arg0->unk15C.word = arg1;
}

void bsstonehead_entrypoint_16(PlayerState *arg0)
{
    func_80800B38_bsstonehead(arg0,0);
    func_80800000_bsstonehead(arg0);
}

void bsstonehead_entrypoint_17(PlayerState *arg0) { func_80800060_bsstonehead(arg0); (arg0->unk15C.word) = 0; func_80800B38_bsstonehead(arg0, 1); }

void bsstonehead_entrypoint_18(PlayerState *arg0) {
    s32 next_state;

    next_state = 0;
    func_808000CC_bsstonehead(arg0);
    if (bakey_released(arg0, 8) && baphysics_get_vertical_velocity(arg0) > 0.0f) {
        baphysics_reset_gravity(arg0);
    }
    switch (arg0->unk15C.word) {
    case 1:
        if (func_8008DF8C(arg0, 0x82)) {
            func_80800B38_bsstonehead(arg0, 3);
        } else if (baanim_isStopped(arg0)) {
            func_80800B38_bsstonehead(arg0, 2);
        }
        break;
    case 2:
        if (func_8008DF8C(arg0, 0x82)) {
            func_80800B38_bsstonehead(arg0, 3);
        }
        break;
    case 3:
        func_8009D3A8(arg0, 0);
        if (player_isStable(arg0)) {
            func_80800B38_bsstonehead(arg0, 4);
        }
        break;
    case 4:
        func_8009D3A8(arg0, 0);
        if (baanim_isStopped(arg0)) {
            next_state = 0xB3;
        }
        break;
    }
    if (player_isStable(arg0)) {
        next_state = func_808003F4_bsstonehead(arg0, next_state);
    }
    bs_setState(arg0, next_state);
}

BsScript bsstonehead_entrypoint_19(BsScriptType arg0) {
    extern BtIntPtr D_80801670_bsstonehead[];
    return (BsScript)D_80801670_bsstonehead[arg0];
}

enum baanim_update_type_e;
enum yaw_type_e;
enum ba_physics_type_e;
void func_800909CC(PlayerState *);
void func_8009FFD8(PlayerState *, enum baanim_update_type_e, enum yaw_type_e, s32, enum ba_physics_type_e);

void bsstonehead_entrypoint_20(PlayerState *arg0) {
    void baanim_playForDuration_loopStartingAt(struct player_state_s *, enum asset_e, f32, f32);
    void func_8008C9F0(PlayerState *, f32, f32, f32, f32);
    func_80800060_bsstonehead(arg0);
    baanim_playForDuration_loopStartingAt(arg0, 0x62, 0.8f, 0.4f);
    func_8009FFD8(arg0, 2, 1, 1, 2);
    func_8008C9F0(arg0, 30.0f, 400.0f, 1.0f, 0.45f);
    func_800909CC(arg0);
}

/* extern */

void bsstonehead_entrypoint_21(PlayerState *arg0) {
    void _baattach_entrypoint_6(PlayerState *, s32, s32, s32);
    s32 _badrone_entrypoint_25(PlayerState *);
    s32 bakey_func_80091940(PlayerState *, s32, s32);
    int bakey_newlyReleased(PlayerState *, s32);
    int bakey_pressed(PlayerState *, s32);
    s32 bastick_getZone(PlayerState *);
    void bs_setState(void *self, s32 nextState);
    int func_8008DD04(PlayerState *);
    int func_8008E148(PlayerState *);
    s32 func_8009BCD4(PlayerState *, f32);
    void func_8009D3A8(PlayerState *, s32);
    void func_800A2CE8(PlayerState *, f32, s32);
    void func_808000CC_bsstonehead(PlayerState *);
    int func_808003B8_bsstonehead(PlayerState *);
    s32 sp24;

    sp24 = 0;
    func_8009D3A8(arg0, 0);
    func_808000CC_bsstonehead(arg0);
    func_800A2CE8(arg0, 0.1f, 4);
    func_800A2CE8(arg0, 0.6f, 3);
    if ((bastick_getZone(arg0) == 0) && (func_8009BCD4(arg0, 1.0f) != 0)) {
        sp24 = 0xB3;
    }
    if (func_8008E148(arg0) != 0) {
        sp24 = _badrone_entrypoint_25(arg0);
    }
    if (func_8008DD04(arg0) != 0) {
        sp24 = 0xAD;
    }
    if (func_808003B8_bsstonehead(arg0) != 0) {
        sp24 = 0xAE;
    }
    if (bakey_pressed(arg0, 9) != 0) {
        sp24 = 0xB4;
    }
    if (bakey_newlyReleased(arg0, 1) != 0) {
        _baattach_entrypoint_6(arg0, 1, bakey_func_80091940(arg0, 1, 1), 0);
    }
    bs_setState(arg0, sp24);
}

void bsstonehead_entrypoint_22(PlayerState *arg0)
{
    func_80800000_bsstonehead(arg0);
    func_80090A2C(arg0);
}
BsScript bsstonehead_entrypoint_23(BsScriptType arg0) {
    extern BtIntPtr D_80801680_bsstonehead[];
    return (BsScript)D_80801680_bsstonehead[arg0];
}

void bsstonehead_entrypoint_24(PlayerState *arg0)
{
    _baspin_entrypoint_1();
    func_80800000_bsstonehead(arg0);
}
void bsstonehead_entrypoint_25(PlayerState *arg0) { void _baattach_entrypoint_6(PlayerState *, s32, s32, s32); void _baspin_entrypoint_2(PlayerState *, s32, f32, s32, s32); func_80800060_bsstonehead(arg0); _baattach_entrypoint_6(arg0, 3, 0, 0); _baspin_entrypoint_2(arg0, 0x63, 1.8f, 2, 0); }

void bsstonehead_entrypoint_26(BtIntPtr arg0) {
    s32 _baspin_entrypoint_3(BtIntPtr);
    void bs_setState(void *self, s32 nextState);
    s32 var_a1;
    s32 sp1C;

    sp1C = 0;
    var_a1 = sp1C;
    if (_baspin_entrypoint_3(arg0) == 2) {
        var_a1 = 0xB3;
    }
    bs_setState(arg0, var_a1);
}

BsScript bsstonehead_entrypoint_27(BsScriptType arg0) {
    extern BtIntPtr D_80801690_bsstonehead[];
    return (BsScript)D_80801690_bsstonehead[arg0];
}

void bsstonehead_entrypoint_28(PlayerState *arg0)
{
    _babounce_entrypoint_3();
    func_80800000_bsstonehead(arg0);
}
void bsstonehead_entrypoint_29(PlayerState *arg0) {
    void _baattach_entrypoint_6(PlayerState *, s32, s32, s32);
    void _babounce_entrypoint_4(PlayerState *, s32);
    void _babounce_entrypoint_5(PlayerState *, s32, f32);
    func_80800060_bsstonehead(arg0);
    _baattach_entrypoint_6(arg0, 3, 0, 0);
    _babounce_entrypoint_4(arg0, 2);
    _babounce_entrypoint_5(arg0, 0x122, 0.7518f);
}

/* extern */

void bsstonehead_entrypoint_30(BtIntPtr arg0) {
    s32 _babounce_entrypoint_2();
    s32 _babounce_entrypoint_9(BtIntPtr);
    void bs_setState(void *self, s32 nextState);
    void func_808000CC_bsstonehead(PlayerState *);
    s32 sp1C;

    sp1C = 0;
    if (_babounce_entrypoint_2() != 0) {
        func_808000CC_bsstonehead(arg0);
    }
    if (_babounce_entrypoint_9(arg0) != 0) {
        sp1C = 0xB3;
    }
    bs_setState(arg0, sp1C);
}

BsScript bsstonehead_entrypoint_31(BsScriptType arg0) {
    extern BtIntPtr D_808016A0_bsstonehead[];
    return (BsScript)D_808016A0_bsstonehead[arg0];
}

void bsstonehead_entrypoint_32(PlayerState *arg0)
{
    _bsrest_entrypoint_14();
    func_80800000_bsstonehead(arg0);
}
void bsstonehead_entrypoint_33(PlayerState *arg0)
{
    func_80800060_bsstonehead(arg0);
    _bsrest_entrypoint_16(arg0);
}
/* extern */

void bsstonehead_entrypoint_34(BtIntPtr arg0) {
    s32 _bsrest_entrypoint_13(BtIntPtr);
    void bs_setState(void *self, s32 nextState);
    s32 _bsrest_entrypoint_20();
    s32 var_a1;
    s32 sp1C;

    sp1C = 0;
    var_a1 = sp1C;
    if (_bsrest_entrypoint_20() != 0) {
        var_a1 = _bsrest_entrypoint_13(arg0);
    }
    bs_setState(arg0, var_a1);
}

BsScript bsstonehead_entrypoint_35(BsScriptType arg0) {
    extern BtIntPtr D_808016B0_bsstonehead[];
    return (BsScript)D_808016B0_bsstonehead[arg0];
}

void bsstonehead_entrypoint_36(PlayerState *arg0)
{
    func_80800000_bsstonehead(arg0);
}

void bsstonehead_entrypoint_37(PlayerState *arg0) {
    void _batimer_set(PlayerState *, s32, f32);
    void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
    func_80800060_bsstonehead(arg0);
    baanim_playForDuration_loopSmooth(arg0, 0x63, BT_IDO_ONLY(0x40C33333) BT_NATIVE_ONLY(6.1f));
    func_8009FFD8(arg0, 1, 1, 3, 3);
    baphysics_set_target_horizontal_velocity(arg0, 0.0f);
    _batimer_set(arg0, 1, 3.0f);
}

/* extern */

void bsstonehead_entrypoint_38(PlayerState *arg0) {
    s32 _batimer_decrement(void *, s32);
    f32 _batimer_get(void *, s32);
    void bs_setState(void *self, s32 nextState);
    f32 func_800D8FF8(void);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    void yaw_applyIdeal(PlayerState *self);
    f32 yaw_getIdeal(PlayerState *);
    void yaw_setIdeal(PlayerState *, f32);
    s32 sp34;
    f32 sp30;
    f32 sp2C;

    sp34 = 0;
    sp2C = func_800F10B4(_batimer_get(arg0, 1), 0.0f, 3.0f, 30.0f, 800.0f);
    sp30 = func_800D8FF8() * sp2C;
    yaw_setIdeal(arg0, yaw_getIdeal(arg0) + sp30);
    yaw_applyIdeal(arg0);
    if (_batimer_decrement(arg0, 1) != 0) {
        sp34 = 0xB3;
    }
    bs_setState(arg0, sp34);
}

BsScript bsstonehead_entrypoint_39(BsScriptType arg0) {
    extern BtIntPtr D_808016C0_bsstonehead[];
    return (BsScript)D_808016C0_bsstonehead[arg0];
}

void bsstonehead_entrypoint_40(PlayerState *arg0)
{
    func_80800000_bsstonehead(arg0);
    func_80090A2C(arg0);
}
void bsstonehead_entrypoint_41(PlayerState *arg0) {
    void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
    func_80800060_bsstonehead(arg0);
    baanim_playForDuration_loopSmooth(arg0, 0x63, BT_IDO_ONLY(0x40C33333) BT_NATIVE_ONLY(6.1f));
    func_8009FFD8(arg0, 1, 1, 1, 2);
    baphysics_set_target_horizontal_velocity(arg0, 0.0f);
    func_800909CC(arg0);
}

/* extern */

void bsstonehead_entrypoint_42(PlayerState *arg0) {
    void _baattach_entrypoint_6(PlayerState *, s32, s32, s32);
    s32 _badrone_entrypoint_24(PlayerState *);
    s32 _badrone_entrypoint_25(PlayerState *);
    int bainput_should_enter_first_person(PlayerState *);
    s32 bakey_func_80091940(PlayerState *, s32, s32);
    int bakey_newlyReleased(PlayerState *, s32);
    int bakey_pressed(PlayerState *, s32);
    void bs_setState(void *self, s32 nextState);
    int func_8008DD04(PlayerState *);
    int func_8008E148(PlayerState *);
    s32 func_800A02DC(PlayerState *, s32);
    s32 var_s1;

    var_s1 = 0;
    if (func_8008DD04(arg0) != 0) {
        var_s1 = 0xAD;
    }
    var_s1 = func_808003F4_bsstonehead(arg0, var_s1);
    if (func_8008E148(arg0) != 0) {
        var_s1 = _badrone_entrypoint_25(arg0);
    }
    if (bakey_pressed(arg0, 9) != 0) {
        var_s1 = 0xB4;
    }
    if (bakey_newlyReleased(arg0, 1) != 0) {
        _baattach_entrypoint_6(arg0, 1, bakey_func_80091940(arg0, 1, 1), 0);
    }
    if (bainput_should_enter_first_person(arg0) != 0) {
        var_s1 = _badrone_entrypoint_24(arg0);
    }
    bs_setState(arg0, func_800A02DC(arg0, var_s1));
}

BsScript bsstonehead_entrypoint_43(BsScriptType arg0) {
    extern BtIntPtr D_808016D0_bsstonehead[];
    return (BsScript)D_808016D0_bsstonehead[arg0];
}
/* data_to_c.py: from asm/data/overlays/bs/stonehead.data.s */
void _bsstonehead_entrypoint_0();
void _bsstonehead_entrypoint_1();
void _bsstonehead_entrypoint_2();
void func_80099B94(PlayerState *);
void _bsstonehead_entrypoint_6();
void _bsstonehead_entrypoint_4();
void _bsstonehead_entrypoint_5();
void _basudie_entrypoint_11();
void _bsstonehead_entrypoint_10();
void _bsstonehead_entrypoint_8();
void _bsstonehead_entrypoint_9();
void _bsdrone_entrypoint_3();
void _bsstonehead_entrypoint_12();
void _bsstonehead_entrypoint_13();
void _bsstonehead_entrypoint_14();
void _bsstonehead_entrypoint_16();
void _bsstonehead_entrypoint_17();
void _bsstonehead_entrypoint_18();
void _bsstonehead_entrypoint_22();
void _bsstonehead_entrypoint_20();
void _bsstonehead_entrypoint_21();
void _bsstonehead_entrypoint_24();
void _bsstonehead_entrypoint_25();
void _bsstonehead_entrypoint_26();
void func_80099AA8();
void _bsstonehead_entrypoint_28();
void _bsstonehead_entrypoint_29();
void _bsstonehead_entrypoint_30();
void _bsstonehead_entrypoint_32();
void _bsstonehead_entrypoint_33();
void _bsstonehead_entrypoint_34();
void _bsstonehead_entrypoint_36();
void _bsstonehead_entrypoint_37();
void _bsstonehead_entrypoint_38();
void _bsstonehead_entrypoint_40();
void _bsstonehead_entrypoint_41();
void _bsstonehead_entrypoint_42();
BtIntPtr D_80801630_bsstonehead [4] BT_DATA(4, overlays_bs_stonehead, 0x0) = { (BtIntPtr)_bsstonehead_entrypoint_0, (BtIntPtr)_bsstonehead_entrypoint_1, (BtIntPtr)_bsstonehead_entrypoint_2, (BtIntPtr)func_80099B94 };
BtIntPtr D_80801640_bsstonehead [4] BT_DATA(4, overlays_bs_stonehead, 0x10) = { (BtIntPtr)_bsstonehead_entrypoint_6, (BtIntPtr)_bsstonehead_entrypoint_4, (BtIntPtr)_bsstonehead_entrypoint_5, (BtIntPtr)_basudie_entrypoint_11 };
BtIntPtr D_80801650_bsstonehead [4] BT_DATA(4, overlays_bs_stonehead, 0x20) = { (BtIntPtr)_bsstonehead_entrypoint_10, (BtIntPtr)_bsstonehead_entrypoint_8, (BtIntPtr)_bsstonehead_entrypoint_9, (BtIntPtr)_bsdrone_entrypoint_3 };
BtIntPtr D_80801660_bsstonehead [4] BT_DATA(4, overlays_bs_stonehead, 0x30) = { (BtIntPtr)_bsstonehead_entrypoint_12, (BtIntPtr)_bsstonehead_entrypoint_13, (BtIntPtr)_bsstonehead_entrypoint_14, (BtIntPtr)func_80099B94 };
BtIntPtr D_80801670_bsstonehead [4] BT_DATA(4, overlays_bs_stonehead, 0x40) = { (BtIntPtr)_bsstonehead_entrypoint_16, (BtIntPtr)_bsstonehead_entrypoint_17, (BtIntPtr)_bsstonehead_entrypoint_18, (BtIntPtr)func_80099B94 };
BtIntPtr D_80801680_bsstonehead [4] BT_DATA(4, overlays_bs_stonehead, 0x50) = { (BtIntPtr)_bsstonehead_entrypoint_22, (BtIntPtr)_bsstonehead_entrypoint_20, (BtIntPtr)_bsstonehead_entrypoint_21, (BtIntPtr)func_80099B94 };
BtIntPtr D_80801690_bsstonehead [4] BT_DATA(4, overlays_bs_stonehead, 0x60) = { (BtIntPtr)_bsstonehead_entrypoint_24, (BtIntPtr)_bsstonehead_entrypoint_25, (BtIntPtr)_bsstonehead_entrypoint_26, (BtIntPtr)func_80099AA8 };
BtIntPtr D_808016A0_bsstonehead [4] BT_DATA(4, overlays_bs_stonehead, 0x70) = { (BtIntPtr)_bsstonehead_entrypoint_28, (BtIntPtr)_bsstonehead_entrypoint_29, (BtIntPtr)_bsstonehead_entrypoint_30, (BtIntPtr)func_80099B94 };
BtIntPtr D_808016B0_bsstonehead [4] BT_DATA(4, overlays_bs_stonehead, 0x80) = { (BtIntPtr)_bsstonehead_entrypoint_32, (BtIntPtr)_bsstonehead_entrypoint_33, (BtIntPtr)_bsstonehead_entrypoint_34, (BtIntPtr)func_80099B94 };
BtIntPtr D_808016C0_bsstonehead [4] BT_DATA(4, overlays_bs_stonehead, 0x90) = { (BtIntPtr)_bsstonehead_entrypoint_36, (BtIntPtr)_bsstonehead_entrypoint_37, (BtIntPtr)_bsstonehead_entrypoint_38, (BtIntPtr)func_80099B94 };
BtIntPtr D_808016D0_bsstonehead [4] BT_DATA(4, overlays_bs_stonehead, 0xA0) = { (BtIntPtr)_bsstonehead_entrypoint_40, (BtIntPtr)_bsstonehead_entrypoint_41, (BtIntPtr)_bsstonehead_entrypoint_42, (BtIntPtr)func_80099B94 };
