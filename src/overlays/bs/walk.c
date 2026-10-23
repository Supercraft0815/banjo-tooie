#include "common.h"
#include "overlays/bs/walk.h"

struct anctrl_s;
enum asset_e;
enum baanim_update_type_e;
enum yaw_type_e;
enum ba_physics_type_e;

s32 bastick_getZone(PlayerState *);
s32 func_8008DE24(PlayerState *);

void func_80800000_bswalk();

void func_80800000_bswalk(self) {
    void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
    f32 bastick_distance(PlayerState *);
    f32 bastick_getZonePosition(PlayerState *);
    f32 func_800F1214(f32, f32, f32);
    int player_isStable(PlayerState *);
    f32 position;
    s32 zone;

    position = bastick_getZonePosition(self);
    zone = bastick_getZone(self);
    if (func_8008DE24(self) && player_isStable(self)) {
        if (zone == 0) {
            baphysics_set_target_horizontal_velocity(self, 0.0f);
            return;
        }
        baphysics_set_target_horizontal_velocity(self,
            func_800F1214(bastick_distance(self), 30.0f, 150.0f));
        return;
    }
    switch (zone) {
    case 0:
        baphysics_set_target_horizontal_velocity(self, 0.0f);
        return;
    case 1:
        baphysics_set_target_horizontal_velocity(self, func_800F1214(position, 30.0f, 80.0f));
        return;
    case 2:
        baphysics_set_target_horizontal_velocity(self, func_800F1214(position, 80.0f, 150.0f));
        return;
    case 3:
        baphysics_set_target_horizontal_velocity(self, func_800F1214(position, 150.0f, 225.0f));
        return;
    case 4:
        baphysics_set_target_horizontal_velocity(self, func_800F1214(position, 225.0f, 500.0f));
        return;
    }
}


void func_8080016C_bswalk(PlayerState *self) {
    void func_8008CA30(PlayerState *, f32);
    s32 func_8008E1A0(void);
    f32 func_8009BBB8(PlayerState *);
    f32 func_800F10B4(f32, f32, f32, f32, f32);

    if (func_8008E1A0()) {
        func_8008CA30(self, func_800F10B4(func_8009BBB8(self), 0.0f, 1.0f, 0.5f, 0.9f));
    } else {
        func_8008CA30(self, 1.0f);
    }
}

void func_808001D8_bswalk(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)arg0 + 364) = arg1;
}

void func_808001E4_bswalk(u8 *arg0) {
    f32 func_800D8FF8(void);
    f32 func_800F0E00(f32, f32);
    (*(f32 *)((s8 *)(arg0) + (0x16C))) = func_800F0E00(0.0f, (*(f32 *)((s8 *)(arg0) + (0x16C))) - func_800D8FF8());
}

s32 func_80800220_bswalk(void *arg0) {
    return 0.0f == *(f32 *)((s8 *)arg0 + 0x16C);
}
s32 func_80800248_bswalk(PlayerState *self, s32 state) {
    int bakey_pressed(PlayerState *, ButtonId);
    f32 baphysics_get_target_horizontal_velocity(PlayerState *);
    s32 func_800A04F4(PlayerState *, s32);
    s32 func_800A055C(PlayerState *, s32);

    if (bakey_pressed(self, 9)) {
        if (baphysics_get_target_horizontal_velocity(self) > 225.0f) {
            state = func_800A04F4(self, state);
        } else {
            state = func_800A055C(self, state);
        }
    }
    return state;
}

f32 bswalk_entrypoint_0(s32 arg0) {
    return 500.0f;
}

void bswalk_entrypoint_1()
{
    func_80800000_bswalk();
}

void bswalk_entrypoint_2(PlayerState *arg0) {
    void _bapackctrl_entrypoint_5(PlayerState *, s32);
    int func_8008E0E8(PlayerState *);
    void func_800A2EDC(void *arg0, f32 arg1);
    func_800A2EDC(arg0, 1.0f);
    if (func_8008E0E8(arg0) != 0) {
        _bapackctrl_entrypoint_5(arg0, 3);
    }
}

void bswalk_entrypoint_3(PlayerState *self) {
    struct anctrl_s *baanim_getAnimCtrlPtr(PlayerState *);
    void anctrl_reset(struct anctrl_s *);
    void anctrl_setDuration(struct anctrl_s *, f32);
    void anctrl_setIndex(struct anctrl_s *, enum asset_e);
    void anctrl_setPlaybackType(struct anctrl_s *, s32);
    void anctrl_setStart(struct anctrl_s *, f32);
    void anctrl_start(struct anctrl_s *);
    void baanim_setDurationRange(PlayerState *, f32, f32);
    void bastick_resetZones(PlayerState *);
    s32 bs_getPreviousState(PlayerState *);
    void *func_8008AEDC(void *);
    f32 func_8008C0C8(f32 *);
    void func_8008C9F0(PlayerState *, f32, f32, f32, f32);
    int func_8008E0E8(PlayerState *);
    void func_8009FFD8(PlayerState *, enum baanim_update_type_e, enum yaw_type_e, s32, enum ba_physics_type_e);
    void func_800A2EDC(void *, f32);
    void _bapackctrl_entrypoint_5(PlayerState *, s32);
    struct anctrl_s *control;
    f32 start;

    control = baanim_getAnimCtrlPtr(self);
    if (bs_getPreviousState(self) == 2) {
        start = func_8008C0C8(func_8008AEDC(control));
    } else {
        start = 0.0f;
    }
    anctrl_reset(control);
    anctrl_setIndex(control, 2);
    anctrl_setDuration(control, 0.43f);
    anctrl_setStart(control, start);
    anctrl_setPlaybackType(control, 2);
    anctrl_start(control);
    func_8009FFD8(self, 2, 1, 1, 2);
    baanim_setDurationRange(self, 0.3f, 1.5f);
    func_8008C9F0(self, 30.0f, 80.0f, 1.8f, 1.2f);
    bastick_resetZones(self);
    func_800A2EDC(self, 0.2f);
    if (func_8008E0E8(self) != 0) {
        _bapackctrl_entrypoint_5(self, 2);
    }
}

void bswalk_entrypoint_4(PlayerState *self) {
    f32 bastick_distance(PlayerState *);
    f32 yaw_get(PlayerState *);
    void yaw_setIdeal(PlayerState *, f32);
    void func_800A2CE8(PlayerState *, f32, s32);
    s32 func_8009BCD4(PlayerState *, f32);
    f32 baphysics_get_target_horizontal_velocity(PlayerState *);
    s32 _badrone_entrypoint_24(PlayerState *);
    s32 _badrone_entrypoint_25(PlayerState *);
    void _baduo_entrypoint_12(PlayerState *);
    s32 func_80800248_bswalk(PlayerState *, s32);
    s32 func_8008E148(PlayerState *);
    s32 next_state;

    next_state = 0;
    func_8080016C_bswalk(self);
    if (bastick_distance(self) == 0.0f) {
        yaw_setIdeal(self, yaw_get(self));
    }
    func_800A2CE8(self, 0.47f, 4);
    func_800A2CE8(self, 0.97f, 3);
    func_80800000_bswalk(self);
    switch (bastick_getZone(self)) {
        case 0:
            if (func_8009BCD4(self, 1.0f)) {
                next_state = 1;
            }
            break;
        case 2:
            next_state = 2;
            break;
        case 3:
            next_state = 3;
            break;
        case 4:
            next_state = 4;
            break;
    }
    if (func_8008DE24(self)) {
        next_state = 0x7A;
    }
    if (bainput_should_enter_first_person(self)) {
        next_state = _badrone_entrypoint_24(self);
    }
    if (func_8008DD04(self)) {
        next_state = 0x2F;
    }
    if (bakey_held(self, 1)) {
        next_state = 7;
    }
    next_state = func_80800248_bswalk(self, next_state);
    if (bakey_pressed(self, 8)) {
        next_state = bs_getTypeOfJump(self);
        if (baphysics_get_target_horizontal_velocity(self) == 0.0f) {
            if (func_8008D714(self)) {
                next_state = 0xB8;
            } else if (func_8008D790(self)) {
                _baduo_entrypoint_12(self);
                return;
            }
        }
    }
    if (func_8008E148(self)) {
        next_state = _badrone_entrypoint_25(self);
    }
    if (player_inWater(self)) {
        next_state = 0x2D;
    }
    bs_setState(self, func_800A02DC(self, next_state));
}

s32 bswalk_entrypoint_5(s32 arg0) {
    extern s32 D_80801520_bswalk[];
    return ((s32 *)&D_80801520_bswalk)[arg0];
}


void bswalk_entrypoint_6(PlayerState *self) {
    void anctrl_reset(struct anctrl_s *);
    void anctrl_setDuration(struct anctrl_s *, f32);
    void anctrl_setIndex(struct anctrl_s *, enum asset_e);
    void anctrl_setPlaybackType(struct anctrl_s *, s32);
    void anctrl_setStart(struct anctrl_s *, f32);
    void anctrl_start(struct anctrl_s *);
    struct anctrl_s *baanim_getAnimCtrlPtr(PlayerState *);
    void baanim_setDurationRange(PlayerState *, f32, f32);
    void func_8008C9F0(PlayerState *, f32, f32, f32, f32);
    void func_8009FFD8(PlayerState *, enum baanim_update_type_e, enum yaw_type_e, s32, enum ba_physics_type_e);
    void _bapackctrl_entrypoint_5(PlayerState *, s32);
    void bastick_resetZones(PlayerState *);
    s32 bs_getPreviousState(PlayerState *);
    void *func_8008AEDC(void *);
    f32 func_8008C0C8(f32 *);
    int func_8008E0E8(PlayerState *);
    struct anctrl_s *control;
    f32 start;

    control = baanim_getAnimCtrlPtr(self);
    if (bs_getPreviousState(self) == 3) {
        start = func_8008C0C8(func_8008AEDC(control));
    } else {
        start = 0.0f;
    }
    anctrl_reset(control);
    anctrl_setIndex(control, 3);
    anctrl_setDuration(control, 0.43f);
    anctrl_setStart(control, start);
    anctrl_setPlaybackType(control, 2);
    anctrl_start(control);
    func_8009FFD8(self, 2, 1, 1, 2);
    baanim_setDurationRange(self, 0.3f, 1.5f);
    func_8008C9F0(self, 80.0f, 150.0f, 1.3f, 0.6f);
    bastick_resetZones(self);
    if (func_8008E0E8(self) != 0) {
        _bapackctrl_entrypoint_5(self, 2);
    }
}

void bswalk_entrypoint_7(PlayerState *self) {
    f32 bastick_distance(PlayerState *);
    f32 yaw_get(PlayerState *);
    void yaw_setIdeal(PlayerState *, f32);
    void func_800A2CE8(PlayerState *, f32, s32);
    s32 func_8009BCD4(PlayerState *, f32);
    f32 baphysics_get_target_horizontal_velocity(PlayerState *);
    s32 _badrone_entrypoint_24(PlayerState *);
    s32 _badrone_entrypoint_25(PlayerState *);
    void _baduo_entrypoint_12(PlayerState *);
    s32 func_80800248_bswalk(PlayerState *, s32);
    s32 func_8008E148(PlayerState *);
    s32 next_state = 0;

    func_8080016C_bswalk(self);
    if (bastick_distance(self) == 0.0f) {
        yaw_setIdeal(self, yaw_get(self));
    }
    func_800A2CE8(self, 0.4f, 4);
    func_800A2CE8(self, 0.9f, 3);
    func_80800000_bswalk(self);
    switch (bastick_getZone(self)) {
        case 0:
            if (func_8009BCD4(self, 3.0f)) {
                next_state = 1;
            }
            break;
        case 1:
            next_state = 0x1F;
            break;
        case 3:
            next_state = 3;
            break;
        case 4:
            next_state = 4;
            break;
    }
    if (func_8008DE24(self)) {
        next_state = 0x7A;
    }
    if (bainput_should_enter_first_person(self)) {
        next_state = _badrone_entrypoint_24(self);
    }
    if (func_8008DD04(self)) {
        next_state = 0x2F;
    }
    if (bakey_held(self, 1)) {
        next_state = 7;
    }
    next_state = func_80800248_bswalk(self, next_state);
    if (bakey_pressed(self, 8)) {
        next_state = bs_getTypeOfJump(self);
        if (baphysics_get_target_horizontal_velocity(self) == 0.0f) {
            if (func_8008D714(self)) {
                next_state = 0xB8;
            } else if (func_8008D790(self)) {
                _baduo_entrypoint_12(self);
                return;
            }
        }
    }
    if (func_8008E148(self)) {
        next_state = _badrone_entrypoint_25(self);
    }
    if (player_inWater(self)) {
        next_state = 0x2D;
    }
    bs_setState(self, func_800A02DC(self, next_state));
}

/* extern */

void bswalk_entrypoint_8(PlayerState *arg0) {
    void _bapackctrl_entrypoint_5(PlayerState *, s32);
    int func_8008E0E8(PlayerState *);
    if (func_8008E0E8(arg0) != 0) {
        _bapackctrl_entrypoint_5(arg0, 3);
    }
}

s32 bswalk_entrypoint_9(s32 arg0) {
    extern s32 D_80801530_bswalk[];
    return ((s32 *)&D_80801530_bswalk)[arg0];
}

void bswalk_entrypoint_10(PlayerState *self) {
    struct anctrl_s *baanim_getAnimCtrlPtr(PlayerState *);
    void anctrl_reset();
    void anctrl_setIndex();
    void anctrl_setDuration(struct anctrl_s *, f32);
    void anctrl_setStart(struct anctrl_s *, f32);
    void anctrl_setPlaybackType();
    void anctrl_start();
    void func_8008B1C8(struct anctrl_s *, f32);
    void baanim_setDurationRange(PlayerState *, f32, f32);
    void func_8008C9F0(PlayerState *, f32, f32, f32, f32);
    void func_8009FFD8(PlayerState *, enum baanim_update_type_e, enum yaw_type_e, s32, enum ba_physics_type_e);
    void _bapackctrl_entrypoint_5(PlayerState *, s32);
    void bastick_resetZones(PlayerState *);
    s32 bs_getPreviousState(PlayerState *);
    void *func_8008AEDC(void *);
    f32 func_8008C0C8(f32 *);
    int func_8008E0E8(PlayerState *);
    struct anctrl_s *control;
    f32 start;
    s32 previous;

    control = baanim_getAnimCtrlPtr(self);
    previous = bs_getPreviousState(self);
    if (previous != 2 && previous != 4) {
        start = 0.0f;
    } else {
        start = func_8008C0C8(func_8008AEDC(control));
    }
    anctrl_reset(control);
    anctrl_setIndex(control, 0xC);
    anctrl_setDuration(control, 0.66f);
    func_8008B1C8(control, 0.14f);
    anctrl_setStart(control, start);
    anctrl_setPlaybackType(control, 2);
    anctrl_start(control);
    func_8009FFD8(self, 2, 1, 1, 2);
    baanim_setDurationRange(self, 0.3f, 1.5f);
    func_8008C9F0(self, 150.0f, 225.0f, 0.92f, 0.58f);
    func_808001D8_bswalk(self, 0.3f);
    bastick_resetZones(self);
    if (func_8008E0E8(self) != 0) {
        _bapackctrl_entrypoint_5(self, 2);
    }
}

void bswalk_entrypoint_11(PlayerState *self) {
    void func_800A2CE8(PlayerState *, f32, s32);
    s32 func_8009BCD4(PlayerState *, f32);
    int func_8008E300(PlayerState *);
    f32 func_8009BB5C(PlayerState *);
    s32 _badrone_entrypoint_24(PlayerState *);
    s32 _badrone_entrypoint_25(PlayerState *);
    int func_8008DD04(PlayerState *);
    int bakey_held(PlayerState *, s32);
    int bakey_pressed(PlayerState *, ButtonId);
    f32 baphysics_get_target_horizontal_velocity(PlayerState *);
    int func_8008D714(PlayerState *);
    int func_8008D790(PlayerState *);
    void _baduo_entrypoint_12(PlayerState *);
    s32 func_8008E148(PlayerState *);
    s32 state = 0;

    func_8080016C_bswalk(self);
    func_800A2CE8(self, 0.4f, 4);
    func_800A2CE8(self, 0.9f, 3);
    func_808001E4_bswalk(self);
    func_80800000_bswalk(self);
    switch (bastick_getZone(self)) {
    case 0:
    case 1:
    case 2:
        if (func_8009BCD4(self, 150.0f) && func_80800220_bswalk(self)) {
            state = 2;
        }
        break;
    case 4:
        state = 4;
        break;
    }
    if (func_8008DE24(self)) {
        state = 0x7A;
    }
    if (func_8008E300(self) && func_8009BB5C(self) > 125.0f) {
        state = 0xC;
    }
    if (bainput_should_enter_first_person(self)) {
        state = _badrone_entrypoint_24(self);
    }
    if (func_8008DD04(self)) {
        state = 0x2F;
    }
    if (bakey_held(self, 1)) {
        state = 7;
    }
    state = func_80800248_bswalk(self, state);
    if (bakey_pressed(self, 8)) {
        state = bs_getTypeOfJump(self);
        if (baphysics_get_target_horizontal_velocity(self) == 0.0f) {
            if (func_8008D714(self)) {
                state = 0xB8;
            } else if (func_8008D790(self)) {
                _baduo_entrypoint_12(self);
                return;
            }
        }
    }
    if (func_8008E148(self)) {
        state = _badrone_entrypoint_25(self);
    }
    if (player_inWater(self)) {
        state = 0x2D;
    }
    bs_setState(self, func_800A02DC(self, state));
}

/* extern */

void bswalk_entrypoint_12(PlayerState *arg0) {
    void _bapackctrl_entrypoint_5(PlayerState *, s32);
    int func_8008E0E8(PlayerState *);
    if (func_8008E0E8(arg0) != 0) {
        _bapackctrl_entrypoint_5(arg0, 3);
    }
}

s32 bswalk_entrypoint_13(s32 arg0) {
    extern s32 D_80801540_bswalk[];
    return ((s32 *)&D_80801540_bswalk)[arg0];
}

void bswalk_entrypoint_14(PlayerState *self) {
    struct anctrl_s *baanim_getAnimCtrlPtr(PlayerState *);
    void anctrl_reset(struct anctrl_s *);
    void anctrl_setDuration(struct anctrl_s *, f32);
    void anctrl_setIndex(struct anctrl_s *, enum asset_e);
    void anctrl_setPlaybackType(struct anctrl_s *, s32);
    void anctrl_setSmoothTransition(struct anctrl_s *, s32);
    void anctrl_setStart(struct anctrl_s *, f32);
    void anctrl_start(struct anctrl_s *);
    void func_8008B1C8(struct anctrl_s *, f32);
    void _badust_entrypoint_3(PlayerState *, f32, f32);
    void _bapackctrl_entrypoint_5(PlayerState *, s32);
    void *func_8008AEDC(void *);
    f32 func_8008C0C8(f32 *);
    void baanim_setDurationRange(PlayerState *, f32, f32);
    void func_8008C9F0(PlayerState *, f32, f32, f32, f32);
    void func_8009FFD8(PlayerState *, enum baanim_update_type_e, enum yaw_type_e, s32, enum ba_physics_type_e);
    void bastick_resetZones(PlayerState *);
    s32 bs_getPreviousState(PlayerState *);
    int func_8008E0E8(PlayerState *);
    f32 func_8009BB5C(PlayerState *);
    void func_8009BFE4(PlayerState *, f32, f32);
    void baroll_setAngularVelocity(PlayerState *, f32, f32);
    struct anctrl_s *control;
    f32 start;
    s32 smooth;

    control = baanim_getAnimCtrlPtr(self);
    start = 0.0f;
    smooth = 1;
    switch (bs_getPreviousState(self)) {
        case 1:
        case 2:
            if (func_8009BB5C(self) < 200.0f) {
                _badust_entrypoint_3(self, 0.0f, 0.0f);
            }
            break;
        case 12:
            smooth = 0;
            break;
        case 3:
            start = func_8008C0C8(func_8008AEDC(control));
            break;
    }
    anctrl_reset(control);
    anctrl_setSmoothTransition(control, smooth);
    anctrl_setIndex(control, 12);
    anctrl_setDuration(control, 0.66f);
    func_8008B1C8(control, 0.1f);
    anctrl_setStart(control, start);
    anctrl_setPlaybackType(control, 2);
    anctrl_start(control);
    func_8009FFD8(self, 2, 1, 1, 2);
    baanim_setDurationRange(self, 0.3f, 1.5f);
    func_8008C9F0(self, 225.0f, 500.0f, 0.54f, 0.44f);
    func_8009BFE4(self, 1000.0f, 12.0f);
    baroll_setAngularVelocity(self, 1000.0f, 12.0f);
    func_808001D8_bswalk(self, 0.3f);
    bastick_resetZones(self);
    if (func_8008E0E8(self) != 0) {
        _bapackctrl_entrypoint_5(self, 2);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/walk/bswalk_entrypoint_15.s")

void bswalk_entrypoint_16(PlayerState *arg0) {
    void _bapackctrl_entrypoint_5(PlayerState *, s32);
    s32 baroll_setIdeal(s32, f32);
    int func_8008E0E8(PlayerState *);
    void func_8009BF5C(PlayerState *, f32);
    func_8009BF5C(arg0, 0.0f);
    baroll_setIdeal((s32) arg0, 0.0f);
    if (func_8008E0E8(arg0) != 0) {
        _bapackctrl_entrypoint_5(arg0, 3);
    }
}

s32 bswalk_entrypoint_17(s32 arg0) {
    extern s32 D_80801550_bswalk[];
    return ((s32 *)&D_80801550_bswalk)[arg0];
}

void bswalk_entrypoint_18(s32 arg0) 
{
}
/* extern */

void bswalk_entrypoint_19(PlayerState *arg0) {
    void baanim_playForDuration_loopSmooth(PlayerState *, s32, f32);
    void baanim_setDurationRange(PlayerState *, f32, f32);
    void func_8008C9F0(PlayerState *, f32, f32, f32, f32);
    void func_8009FFD8(PlayerState *, enum baanim_update_type_e, enum yaw_type_e, s32, enum ba_physics_type_e);
    baanim_playForDuration_loopSmooth(arg0, 0xB, 0.43f);
    func_8009FFD8(arg0, 2, 1, 1, 2);
    baanim_setDurationRange(arg0, 0.3f, 1.5f);
    func_8008C9F0(arg0, 30.0f, 150.0f, 1.2f, 0.9f);
}

void bswalk_entrypoint_20(PlayerState *self) {
    void func_800A2CE8(PlayerState *, f32, s32);
    s32 _badrone_entrypoint_24(PlayerState *);
    s32 _badrone_entrypoint_25(PlayerState *);
    s32 func_8008E148(PlayerState *);
    s32 next_state = 0;

    func_8080016C_bswalk(self);
    func_800A2CE8(self, 0.4f, 4);
    func_800A2CE8(self, 0.9f, 3);
    func_80800000_bswalk(self);
    if (!func_8008DE24(self)) {
        next_state = 2;
    }
    if (!bastick_getZone(self)) {
        next_state = 1;
    }
    if (bainput_should_enter_first_person(self)) {
        next_state = _badrone_entrypoint_24(self);
    }
    if (func_8008DD04(self)) {
        next_state = 0x2F;
    }
    if (bakey_held(self, 1)) {
        next_state = 7;
    }
    next_state = func_80800248_bswalk(self, next_state);
    if (bakey_pressed(self, 8)) {
        next_state = bs_getTypeOfJump(self);
    }
    if (func_8008E148(self)) {
        next_state = _badrone_entrypoint_25(self);
    }
    if (player_inWater(self)) {
        next_state = 0x2D;
    }
    next_state = func_800A02DC(self, next_state);
    bs_setState(self, next_state);
}

s32 bswalk_entrypoint_21(s32 arg0) {
    extern s32 D_80801560_bswalk[];
    return ((s32 *)&D_80801560_bswalk)[arg0];
}

/* extern */

void bswalk_entrypoint_22(PlayerState *arg0, f32 arg1) {
    void func_8009FF44(PlayerState *, enum asset_e, f32, f32, f32, f32);
    if (arg1 < 150.0f) {
        func_8009FF44(arg0, 3, 80.0f, 150.0f, 1.3f, 0.6f);
        return;
    }
    func_8009FF44(arg0, 0xC, 225.0f, 500.0f, 0.54f, 0.44f);
}
