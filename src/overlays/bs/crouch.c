#include "common.h"

void func_80800000_bscrouch(s32 arg0) {
    s32 baanim_playForDuration_loopSmooth(s32, s32, s32);
    baanim_playForDuration_loopSmooth(arg0, 0x10C, 0x3F000000);
    (*(s32 *)((s8 *)(arg0) + (0x15C))) = 4;
}

void func_80800034_bscrouch(s32 arg0) {
    s32 baanim_playForDuration_onceSmooth(s32, s32, s32);
    baanim_playForDuration_onceSmooth(arg0, 0x116, 0x40000000);
    (*(s32 *)((s8 *)(arg0) + (0x15C))) = 2;
}

/* extern */

void func_80800068_bscrouch(void *arg0) {
    void _batimer_set(void *, s32, f32);
    void baanim_playForDuration_onceSmoothStartingAt(void *, s32, f32, f32);
    baanim_playForDuration_onceSmoothStartingAt(arg0, 0x10C, 0.5f, 0.9999f);
    _batimer_set(arg0, 2, 2.0f);
    (*(s32 *)((s8 *)(arg0) + (0x15C))) = 1;
}

/* extern */

void func_808000B4_bscrouch(s32 arg0, f32 arg1) {
    f32 func_800F10B4(f32 value, f32 in_min, f32 in_max, f32 out_min, f32 out_max);
    s32 anctrl_setDuration(s32, f32);
    anctrl_setDuration(arg0, func_800F10B4(arg1, 0.0f, 180.0f, 0.5f, 0.2f));
}

void func_808000FC_bscrouch(void *arg0, s32 arg1) {
    struct player_state_s;
    void func_800A2CE8(struct player_state_s *, f32, s32);
    func_800A2CE8(arg0, 0.41f, 4);
    func_800A2CE8(arg0, 0.91f, 3);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/crouch/bscrouch_entrypoint_0.s")

void bscrouch_entrypoint_1(void *arg0) {
    s32 _badrone_entrypoint_25(void *);
    void _badust_entrypoint_9(void *);
    s32 _batimer_decrement(void *, s32);
    f32 _batimer_get(void *, s32);
    s32 _batimer_isNonzero(void *, s32);
    s32 _batimer_isZero(void *, s32);
    void _batimer_set(void *, s32, f32);
    f32 anctrl_getAnimTimer(s32);
    s32 anctrl_isStopped(s32);
    s32 anctrl_setPlaybackType(s32, s32);
    void anctrl_setSubrange(s32, f32, f32);
    s32 baanim_getAnimCtrlPtr();
    void baphysics_set_target_horizontal_velocity(void *, f32);
    f32 bastick_distance(void *);
    s32 bs_setState(s32, s32);
    s32 bscrouch_entrypoint_4(void *, s32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    f32 func_800F1DCC(f32, f32);
    void func_80800068_bscrouch(void *);
    void func_808000FC_bscrouch(void *, s32);
    f32 mlAbsF(f32);
    f32 yaw_get(void *);
    f32 yaw_getIdeal(void *);
    void yaw_setIdeal(void *, f32);
    s32 next_state;
    f32 speed;
    s32 anim;
    f32 angle;

    next_state = 0;
    anim = baanim_getAnimCtrlPtr(arg0);
    _batimer_decrement(arg0, 0);
    _batimer_decrement(arg0, 1);
    speed = func_800F10B4(_batimer_get(arg0, 0), 0.0f, 0.3f, 0.0f,
                        *(f32 *)((u8 *)arg0 + 0x16C));
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
            func_80800000_bscrouch((s32)arg0);
        } else {
            _batimer_decrement(arg0, 2);
            if (_batimer_isZero(arg0, 2)) {
                func_80800034_bscrouch((s32)arg0);
            }
        }
        break;
    case 2:
        if (angle != 0.0f) {
            func_80800000_bscrouch((s32)arg0);
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
    bs_setState((s32)arg0, next_state);
}

void bscrouch_entrypoint_2(s32 arg0) 
{
}
s32 bscrouch_entrypoint_3(s32 arg0) {
    extern s32 D_80800990_bscrouch[];
    return ((s32 *)&D_80800990_bscrouch)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/crouch/func_808006A4_bscrouch.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/crouch/bscrouch_entrypoint_4.s")
