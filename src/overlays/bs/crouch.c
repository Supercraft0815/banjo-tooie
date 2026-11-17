#include "common.h"

typedef struct { u8 pad0[0x15C]; s32 unk15C; u8 pad160[0xC]; f32 unk16C; } Objcrouch_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */ void func_80800000_bscrouch(BtIntPtr arg0) {
    s32 baanim_playForDuration_loopSmooth(BtIntPtr, s32, s32);
    baanim_playForDuration_loopSmooth(arg0, 0x10C, 0x3F000000);
    (((Objcrouch_arg0 *)arg0)->unk15C) = 4;
}

void func_80800034_bscrouch(BtIntPtr arg0) {
    s32 baanim_playForDuration_onceSmooth(BtIntPtr, s32, s32);
    baanim_playForDuration_onceSmooth(arg0, 0x116, 0x40000000);
    (((Objcrouch_arg0 *)arg0)->unk15C) = 2;
}

/* extern */

void func_80800068_bscrouch(void *arg0) {
    void _batimer_set(void *, s32, f32);
    void baanim_playForDuration_onceSmoothStartingAt(void *, s32, f32, f32);
    baanim_playForDuration_onceSmoothStartingAt(arg0, 0x10C, 0.5f, 0.9999f);
    _batimer_set(arg0, 2, 2.0f);
    (((Objcrouch_arg0 *)arg0)->unk15C) = 1;
}

/* extern */

void func_808000B4_bscrouch(BtIntPtr arg0, f32 arg1) {
    f32 func_800F10B4(f32 value, f32 in_min, f32 in_max, f32 out_min, f32 out_max);
    void anctrl_setDuration(void *arg0, f32 arg1);
    anctrl_setDuration(arg0, func_800F10B4(arg1, 0.0f, 180.0f, 0.5f, 0.2f));
}

void func_808000FC_bscrouch(void *arg0, BtIntPtr arg1) {
    struct player_state_s;
    void func_800A2CE8(struct player_state_s *, f32, s32);
    func_800A2CE8(arg0, 0.41f, 4);
    func_800A2CE8(arg0, 0.91f, 3);
}

struct player_state_s;
void func_8009D658(struct player_state_s *);

void bscrouch_entrypoint_0(void *arg0) {
    void _batimer_set(void *, s32, f32);
    void anctrl_reset(BtIntPtr);
    void anctrl_setDuration(void *arg0, f32 arg1);
    void anctrl_setIndex(BtIntPtr, s32);
    void anctrl_setPlaybackType(void *arg0, s32 arg1);
    void anctrl_setStart(void *arg0, f32 arg1);
    void anctrl_start(BtIntPtr);
    void * baanim_getAnimCtrlPtr(void *self);
    void baphysics_set_target_yaw(void *, f32);
    void baphysics_set_type(void *self, s32 type);
    s32 bs_getPreviousState(void *);
    void func_8008CA4C(void *self, s32 arg1);
    void func_8009BB24(void *, f32 *);
    void func_8009CFD8(void *, f32);
    void func_8009D2D8(void *, s32);
    int func_800F1EA4(f32 *, f32 *);
    void yaw_setUpdateType(void *self, s32 type);
    void yaw_setVelocityBounded(void *, f32, f32);
    f32 sqrtf(f32);
    BtIntPtr anim;
    f32 velocity[3];
    f32 start;
    f32 yaw;
    s32 previous;
    f32 speed;

    anim = baanim_getAnimCtrlPtr(arg0);
    previous = bs_getPreviousState(arg0);
    if (previous != 9 && previous != 0xA && previous != 0x1A) {
        start = 0.0f;
    } else {
        start = 0.5357f;
    }
    anctrl_reset(anim);
    anctrl_setIndex(anim, 1);
    anctrl_setDuration(anim, 0.5f);
    anctrl_setPlaybackType(anim, 1);
    anctrl_setStart(anim, start);
    anctrl_start(anim);
    func_8008CA4C(arg0, 1);
    yaw_setUpdateType(arg0, 3);
    yaw_setVelocityBounded(arg0, 350.0f, 14.0f);
    func_8009D2D8(arg0, 7);
    func_8009CFD8(arg0, 8.0f);
    baphysics_set_type(arg0, 3);
    _batimer_set(arg0, 0, 0.7f);
    _batimer_set(arg0, 1, 0.2f);
    func_8009BB24(arg0, velocity);
    speed = sqrtf(velocity[0] * velocity[0] + velocity[2] * velocity[2]);
    ((Objcrouch_arg0 *)arg0)->unk16C = speed;
    if (speed > 140.0f) {
        func_8009D658(arg0);
    }
    if (func_800F1EA4(velocity, &yaw)) {
        baphysics_set_target_yaw(arg0, yaw);
    }
    ((Objcrouch_arg0 *)arg0)->unk15C = 0;
}

void bscrouch_entrypoint_1(void *arg0) {
    s32 _badrone_entrypoint_25(void *);
    void _badust_entrypoint_9(void *);
    s32 _batimer_decrement(void *, s32);
    f32 _batimer_get(void *, s32);
    s32 _batimer_isNonzero(void *, s32);
    s32 _batimer_isZero(void *, s32);
    void _batimer_set(void *, s32, f32);
    f32 anctrl_getAnimTimer(BtIntPtr);
    s32 anctrl_isStopped(BtIntPtr);
    void anctrl_setPlaybackType(void *arg0, s32 arg1);
    void anctrl_setSubrange(BtIntPtr, f32, f32);
    void * baanim_getAnimCtrlPtr(void *self);
    void baphysics_set_target_horizontal_velocity(void *, f32);
    f32 bastick_distance(void *);
    void bs_setState(void *self, s32 nextState);
    s32 bscrouch_entrypoint_4(void *, s32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    f32 func_800F1DCC(f32, f32);
    void func_80800068_bscrouch(void *);
    void func_808000FC_bscrouch(void *, BtIntPtr);
    f32 mlAbsF(f32);
    f32 yaw_get(void *);
    f32 yaw_getIdeal(void *);
    void yaw_setIdeal(void *, f32);
    s32 next_state;
    f32 speed;
    BtIntPtr anim;
    f32 angle;

    next_state = 0;
    anim = baanim_getAnimCtrlPtr(arg0);
    _batimer_decrement(arg0, 0);
    _batimer_decrement(arg0, 1);
    speed = func_800F10B4(_batimer_get(arg0, 0), 0.0f, 0.3f, 0.0f,
                        ((Objcrouch_arg0 *)arg0)->unk16C);
    baphysics_set_target_horizontal_velocity(arg0, speed);
    if (speed > 220.0f) {
        _badust_entrypoint_9(arg0);
    }
    if (speed > 160.0f) {
        func_8009D658(arg0);
    }
    if (bastick_distance(arg0) == 0.0f) {
        yaw_setIdeal(arg0, yaw_get(arg0));
    }
    angle = func_800F1DCC(yaw_getIdeal(arg0), yaw_get(arg0));
    angle = mlAbsF(angle);
    switch (*(u32 *)((u8 *)arg0 + 0x15C)) {
    case 0:
        if (speed == 0.0f) {
            _batimer_set(arg0, 2, 2.0f);
            *(u32 *)((u8 *)arg0 + 0x15C) = 1;
        }
        break;
    case 1:
        if (angle != 0.0f) {
            func_80800000_bscrouch((BtIntPtr)arg0);
        } else {
            _batimer_decrement(arg0, 2);
            if (_batimer_isZero(arg0, 2)) {
                func_80800034_bscrouch((BtIntPtr)arg0);
            }
        }
        break;
    case 2:
        if (angle != 0.0f) {
            func_80800000_bscrouch((BtIntPtr)arg0);
        } else if (anctrl_isStopped(anim)) {
            func_80800068_bscrouch(arg0);
        }
        break;
    case 4:
        func_808000B4_bscrouch(anim, angle);
        func_808000FC_bscrouch(arg0, anim);
        if (angle == 0.0f) {
            if (anctrl_getAnimTimer(anim) <= 0.5f) {
                anctrl_setSubrange(anim, 0.0f, 0.5f);
            } else {
                anctrl_setSubrange(anim, 0.0f, 1.0f);
            }
            anctrl_setPlaybackType(anim, 1);
            *(u32 *)((u8 *)arg0 + 0x15C) = 3;
        }
        break;
    case 3:
        func_808000B4_bscrouch(anim, angle);
        func_808000FC_bscrouch(arg0, anim);
        if (angle != 0.0f) {
            anctrl_setSubrange(anim, 0.0f, 1.0f);
            anctrl_setPlaybackType(anim, 2);
            *(u32 *)((u8 *)arg0 + 0x15C) = 4;
        } else if (anctrl_isStopped(anim)) {
            yaw_setIdeal(arg0, yaw_get(arg0));
            func_80800068_bscrouch(arg0);
        }
        break;
    }
    if (func_8008E148(arg0)) {
        next_state = _badrone_entrypoint_25(arg0);
    }
    if (func_8008DD04(arg0)) {
        next_state = 0x2F;
    }
    next_state = bscrouch_entrypoint_4(arg0, next_state);
    if (next_state == 1 && _batimer_isNonzero(arg0, 1)) {
        next_state = 0;
    }
    if (player_inWater(arg0)) {
        next_state = 0x2D;
    }
    bs_setState((BtIntPtr)arg0, next_state);
}

void bscrouch_entrypoint_2(s32 arg0) 
{
}
s32 bscrouch_entrypoint_3(s32 arg0) {
    extern BtIntPtr D_80800990_bscrouch[];
    return ((s32 *)&D_80800990_bscrouch)[arg0];
}

/* extern */

s32 func_808006A4_bscrouch(void *arg0) {
    s32 _bapackctrl_entrypoint_1(void *);
    void func_8009C128(void *, f32[3]);
    s32 func_800CB7C4(s32, f32 *, f32 *);
    f32 func_800F1DF4(f32 *, f32 *);
    void yaw_setIdeal(void *, f32);
    f32 sp34[3];
    f32 sp28[3];
    s32 sp24;
    s32 sp20;
    s32 temp_v0;

    sp24 = _bapackctrl_entrypoint_1(arg0);
    func_8009C128(arg0, sp34);
    temp_v0 = func_800CB7C4(sp24, sp34, sp28);
    sp20 = temp_v0;
    if (temp_v0 == 2) {
        yaw_setIdeal(arg0, func_800F1DF4(sp34, sp28));
    }
    return sp20;
}

s32 bscrouch_entrypoint_4(void *arg0, s32 arg1) {
    struct player_state_s;
    int bs_getTypeOfJump(struct player_state_s *);
    void _suinv_entrypoint_0(s32* arg0, s32 failure, s32 success, s32 itemType, s32 amountToRemove);
    int bakey_pressed(struct player_state_s *, int);
    int bakey_released(struct player_state_s *, int);
    int bainput_should_wonderwing(struct player_state_s *);
    int bainput_should_trot(struct player_state_s *);
    int bainput_should_poop_egg(struct player_state_s *);
    int bainput_should_shoot_egg(struct player_state_s *);
    int bainput_should_flap_flip(struct player_state_s *);
    int bainput_should_beak_barge(struct player_state_s *);
    s32 func_8008E0C8(struct player_state_s *);
    s32 func_8008E23C(struct player_state_s *);
    s32 func_80094B14(struct player_state_s *);
    s32 func_800A055C(struct player_state_s *, s32);
    int func_800C6E38(s32);
    s32 temp_v0;

    if (bakey_released(arg0, 1) != 0) {
        arg1 = 1;
        if (bakey_pressed(arg0, 9) != 0) {
            arg1 = func_800A055C(arg0, arg1);
        }
        if (bakey_pressed(arg0, 8) != 0) {
            arg1 = bs_getTypeOfJump(arg0);
        }
        return arg1;
    } else if (func_8008E23C(arg0) != 0) {
        if ((bakey_pressed(arg0, 0xB) != 0) && (func_800C6E38(0x21) != 0)) {
            arg1 = 0x16A;
        } else if ((bakey_pressed(arg0, 0xC) != 0) && (func_800C6E38(0x2A) != 0)) {
            arg1 = 0x163;
        } else if ((bakey_pressed(arg0, 0xD) != 0) && (func_800C6E38(0x23) != 0)) {
            arg1 = 0x171;
        } else if ((bakey_pressed(arg0, 0xA) != 0) && (func_800C6E38(0x27) != 0)) {
            if (func_8008E0C8(arg0) == 0) {
                arg1 = 0x122;
            } else {
                temp_v0 = func_808006A4_bscrouch(arg0);
                switch (temp_v0) {
                case 0:
                    break;
                case 1:
                    arg1 = 0x129;
                    break;
                case 2:
                    arg1 = 0x128;
                    break;
                }
            }
        }
        if (bakey_pressed(arg0, 8) != 0) {
            arg1 = 0x6C;
        }
        return arg1;
    } else {
        if (bainput_should_wonderwing(arg0) != 0) {
            _suinv_entrypoint_0(&arg1, -1, 0x1A, 0x47, 1);
        }
        if (bainput_should_trot(arg0) != 0) {
            arg1 = 0x14;
        }
        if ((bainput_should_poop_egg(arg0) != 0) && (func_80094B14(arg0) != 0)) {
            arg1 = 0xA;
        }
        if ((bainput_should_shoot_egg(arg0) != 0) && (func_80094B14(arg0) != 0)) {
            arg1 = 9;
        }
        if (bainput_should_flap_flip(arg0) != 0) {
            arg1 = 0x12;
        }
        if (bainput_should_beak_barge(arg0) != 0) {
            arg1 = 0x13;
        }
    }
    return arg1;
}
/* data_to_c.py: from asm/data/overlays/bs/crouch.data.s */
void _bscrouch_entrypoint_2();
void _bscrouch_entrypoint_0();
void _bscrouch_entrypoint_1();
void func_8009AB78();
BtIntPtr D_80800990_bscrouch [4] BT_DATA(4, overlays_bs_crouch, 0x0) = { (BtIntPtr)_bscrouch_entrypoint_2, (BtIntPtr)_bscrouch_entrypoint_0, (BtIntPtr)_bscrouch_entrypoint_1, (BtIntPtr)func_8009AB78 };
