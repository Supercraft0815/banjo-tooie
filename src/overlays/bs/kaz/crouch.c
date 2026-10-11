#include "common.h"

#include "overlays/bs/kaz/crouch.h"

extern s32 D_808007C0_bskazcrouch[];

void func_80800000_bskazcrouch(PlayerState *self) {
    baanim_playForDuration_loopSmooth(self, ASSET_28F_ANIM_BSKAZCROUCH_UNKNOWN, 0.5f);
    self->unk15C.word = 4;
}

void func_80800034_bskazcrouch(PlayerState *self) {
    baanim_playForDuration_onceSmooth(self, ASSET_141_ANIM_BSKAZCROUCH_UNKNOWN, 3.5f);
    self->unk15C.word = 2;
}

void func_80800068_bskazcrouch(PlayerState *self) {
    baanim_playForDuration_onceSmoothStartingAt(self, ASSET_28F_ANIM_BSKAZCROUCH_UNKNOWN, 0.5f, 0.9999f);
    _batimer_set(self, 2, 2.0f);
    self->unk15C.word = 1;
}

void func_808000B4_bskazcrouch(AnimCtrl *anim_ctrl, f32 arg1) {
    anctrl_setDuration(anim_ctrl, func_800F10B4(arg1, 0, 180, 0.5, 0.2));
}

void func_808000FC_bskazcrouch(PlayerState *self, s32 arg1) {
    func_800A2CE8(self, 0.41f, 4);
    func_800A2CE8(self, 0.91f, 3);
}

BanjoStateId bskazcrouch_entrypoint_0(PlayerState* self, BanjoStateId arg1) {
    if (bakey_released(self, BUTTON_Z) != 0) {
        arg1 = BS_STATE_BB;
        if (bakey_pressed(self, BUTTON_A) != 0) {
            arg1 = _bskaz_entrypoint_3(self);
        }
    } else {
        if ((bakey_pressed(self, BUTTON_B) != 0) && (func_800C6E38(0x28) != 0)) {
            arg1 = BS_STATE_C5;
        }
        if (bakey_pressed(self, BUTTON_A) != 0) {
            arg1 = _bskaz_entrypoint_3(self);
        }
        if ((bainput_should_poop_egg(self) != 0) && (func_80094B14(self) != 0)) {
            arg1 = BS_STATE_68;
        }
        if ((bainput_should_shoot_egg(self) != 0) && (func_80094B14(self) != 0)) {
            arg1 = BS_STATE_67;
        }
    }

    return arg1;
}

void bskazcrouch_entrypoint_1(PlayerState *self) {
    AnimCtrl* animCtrl;
    f32 unk0;
    f32 pad0;
    f32 unk1;
    f32 animStart;
    f32 targetYaw;
    s32 unk2;
    f32 unk3;

    animCtrl = baanim_getAnimCtrlPtr(self);
    _bskaz_entrypoint_1(self);
    unk2 = bs_getPreviousState(self);
    if ((unk2 != 0x67) && (unk2 != 0x68)) {
        animStart = 0;
    } else {
        animStart = 0.8;
    }
    anctrl_reset(animCtrl);
    anctrl_setIndex(animCtrl, ASSET_A8_ANIM_BSKAZCROUCH_UNKNOWN);
    anctrl_setDuration(animCtrl, 0.5);
    anctrl_setPlaybackType(animCtrl, 1);
    anctrl_setStart(animCtrl, animStart);
    anctrl_start(animCtrl);
    func_8008CA4C(self, 1);
    yaw_setUpdateType(self, 3);
    yaw_setVelocityBounded(self, 350.0f , 14.0f );
    func_8009D2D8(self, 7);
    func_8009CFD8(self, 8.0f);
    baphysics_set_type(self, 3);
    _batimer_set(self, 0, 0.7f);
    _batimer_set(self, 1, 0.2f);
    func_8009BB24(self, &unk1);
    unk3 = sqrtf((unk0 * unk0) + (unk1 * unk1));
    self->unk16C = unk3;
    if (unk3 > 140.0f) {
        func_8009D658(self);
    }
    if (func_800F1EA4(&unk1, &targetYaw) != 0) {
        baphysics_set_target_yaw(self, targetYaw);
    }
    self->unk15C.word = NULL;
}


/* extern */

void bskazcrouch_entrypoint_2(PlayerState *arg0) {
    s32 _batimer_isNonzero(PlayerState *, s32);
    f32 mlAbsF(f32);
    enum bs_state_e sp3C;
    f32 sp38;
    AnimCtrl *sp34;
    f32 sp30;
    f32 yawDiff;
    f32 idealYaw;

    sp3C = BS_STATE_0_INVALID;
    sp34 = baanim_getAnimCtrlPtr(arg0);
    _batimer_decrement(arg0, 0);
    _batimer_decrement(arg0, 1);
    sp38 = func_800F10B4(_batimer_get(arg0, 0), 0.0f, 0.3f, 0.0f, arg0->unk16C);
    baphysics_set_target_horizontal_velocity(arg0, sp38);
    if (sp38 > 220.0f) {
        _badust_entrypoint_9(arg0);
    }
    if (sp38 > 160.0f) {
        func_8009D658(arg0);
    }
    if (bastick_distance(arg0) == 0.0f) {
        yaw_setIdeal(arg0, yaw_get(arg0));
    }
    idealYaw = yaw_getIdeal(arg0);
    yawDiff = func_800F1DCC(idealYaw, yaw_get(arg0));
    sp30 = mlAbsF(yawDiff);
    switch (arg0->unk15C.word) {
    case 0:
        if (sp38 == 0.0f) {
            _batimer_set(arg0, 2, 2.0f);
            arg0->unk15C.word = 1;
        }
        break;
    case 1:
        if (sp30 != 0.0f) {
            func_80800000_bskazcrouch(arg0);
        } else {
            _batimer_decrement(arg0, 2);
            if (_batimer_isZero(arg0, 2) != 0) {
                func_80800034_bskazcrouch(arg0);
            }
        }
        break;
    case 2:
        if (sp30 != 0.0f) {
            func_80800000_bskazcrouch(arg0);
        } else if (anctrl_isStopped(sp34) != 0) {
            func_80800068_bskazcrouch(arg0);
        }
        break;
    case 4:
        func_808000B4_bskazcrouch(sp34, sp30);
        func_808000FC_bskazcrouch(arg0, (s32) sp34);
        if (sp30 == 0.0f) {
            if (anctrl_getAnimTimer(sp34) <= 0.5f) {
                anctrl_setSubrange(sp34, 0.0f, 0.5f);
            } else {
                anctrl_setSubrange(sp34, 0.0f, 1.0f);
            }
            anctrl_setPlaybackType(sp34, 1);
            arg0->unk15C.word = 3;
        }
        break;
    case 3:
        func_808000B4_bskazcrouch(sp34, sp30);
        func_808000FC_bskazcrouch(arg0, (s32) sp34);
        if (sp30 != 0.0f) {
            anctrl_setSubrange(sp34, 0.0f, 1.0f);
            anctrl_setPlaybackType(sp34, 2);
            arg0->unk15C.word = 4;
        } else if (anctrl_isStopped(sp34) != 0) {
            yaw_setIdeal(arg0, yaw_get(arg0));
            func_80800068_bskazcrouch(arg0);
        }
        break;
    }
    if (func_8008DF18(arg0) != 0) {
        sp3C = _badrone_entrypoint_25(arg0);
    }
    sp3C = bskazcrouch_entrypoint_0(arg0, sp3C);
    if ((sp3C == BS_STATE_BB) && (_batimer_isNonzero(arg0, 1) != 0)) {
        sp3C = BS_STATE_0_INVALID;
    }
    if (player_inWater(arg0) != 0) {
        sp3C = BS_STATE_15D;
    }
    bs_setState(arg0, sp3C);
}

void bskazcrouch_entrypoint_3(PlayerState *self) {
    _bskaz_entrypoint_2(self);
}


s32 bskazcrouch_entrypoint_4(s32 idx) {
    return D_808007C0_bskazcrouch[idx];
}
