#include "common.h"
#include "overlays/ba/playerstate.h"

BtIntPtr func_80800000_bsstand(s32 *arg0) {
    extern BtIntPtr D_80800D90_bsstand[];
    return D_80800D90_bsstand[arg0[0x160 / 4]];
}

s32 func_80800018_bsstand(s32 *arg0, s32 arg1) {
    arg1++;
    if (arg1 >= arg0[0x164 / 4]) {
        arg1 = 0;
    }
    return arg1;
}

s32 func_80800038_bsstand(BT_NATIVE_ONLY(PlayerState *) self, BT_NATIVE_ONLY(s32) next_state) {
    s32 _badrone_entrypoint_24(PlayerState *);
    s32 _badrone_entrypoint_25(PlayerState *);
    void _baduo_entrypoint_12(PlayerState *);
    s32 bainput_should_enter_first_person();
    int bakey_held(PlayerState *, s32);
    int bakey_pressed(PlayerState *, int);
    s32 bastick_getZone(PlayerState *);
    int bs_getTypeOfJump(PlayerState *);
    int func_8008D714(PlayerState *);
    int func_8008D790(PlayerState *);
    int func_8008E148(PlayerState *);
    int func_800A02DC(PlayerState *, int);
    s32 func_800A055C(PlayerState *, s32);
    s32 player_inWater(PlayerState *);

    switch (bastick_getZone(self)) {
        case 1: next_state = 0x1F; break;
        case 2: next_state = 2; break;
        case 3: next_state = 3; break;
        case 4: next_state = 4; break;
    }
    if (bakey_held(self, 1)) {
        next_state = 7;
    }
    if (bakey_pressed(self, 9)) {
        next_state = func_800A055C(self, next_state);
    }
    if (bakey_pressed(self, 8)) {
        next_state = bs_getTypeOfJump(self);
        if (func_8008D714(self)) {
            next_state = 0xB8;
        } else if (func_8008D790(self)) {
            _baduo_entrypoint_12(self);
            return 0;
        }
    }
    if (bainput_should_enter_first_person(self)) {
        next_state = _badrone_entrypoint_24(self);
    }
    if (func_8008E148(self)) {
        next_state = _badrone_entrypoint_25(self);
    }
    if (player_inWater(self)) {
        next_state = 0x2D;
    }
    return func_800A02DC(self, next_state);
}

/* extern */

void bsstand_entrypoint_0(void *arg0) {
    void baanim_playForDuration_once(void *self, s32 anim_id, f32 duration);
    void baanim_playForDuration_onceSmooth(PlayerState *, s32, f32);
    void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
    s32 bs_getPreviousState(PlayerState *);
    s32 func_8008E23C(PlayerState *);
    void func_800909CC(PlayerState *);
    void func_80098840(u8 *);
    s16 func_8009CBDC(PlayerState *, s32);
    void func_8009FFD8(PlayerState *, s32, s32, s32, s32);
    s32 sp2C;
    s32 temp_v0;

    temp_v0 = bs_getPreviousState(arg0);
    sp2C = temp_v0;
    if (func_8009CBDC(arg0, temp_v0) == 0xA) {
        func_80098840(arg0);
    }
    if (sp2C == 0x5B) {
        baanim_playForDuration_once(arg0, 0x6F, 5.5f);
    } else {
        baanim_playForDuration_onceSmooth(arg0, 0x6F, 5.5f);
    }
    func_8009FFD8(arg0, 1, 1, 1, 2);
    baphysics_set_target_horizontal_velocity(arg0, 0.0f);
    func_800909CC(arg0);
    if (func_8008E23C(arg0) != 0) {
        (((PlayerState *)arg0)->unk160.word) = 0;
        (((PlayerState *)arg0)->unk164.word) = 6;
    } else {
        (((PlayerState *)arg0)->unk160.word) = 1;
        (((PlayerState *)arg0)->unk164.word) = 0x15;
    }
    (((PlayerState *)arg0)->unk15C.word) = 0;
    (((PlayerState *)arg0)->unk168.word) = 0;
}

struct anctrl_s;
void func_80800274_bsstand(PlayerState *arg0, struct anctrl_s *anim) {
    void _bamotor_entrypoint_1(PlayerState *, f32, f32, f32);
    int anctrl_isAt(struct anctrl_s *, f32);
    void func_8009514C(PlayerState *);
    void func_800951B4();
    void func_800909EC(PlayerState *);
    void func_8009DF58(PlayerState *, s32, f32);
    void func_8009DF94(PlayerState *, s32, f32, s32);

    if (anctrl_isAt(anim, 0.2057f)) {
        func_8009DF94(arg0, 0x418, 1.8f, 16000);
        _bamotor_entrypoint_1(arg0, 0.5f, 0.25f, 0.4f);
    }
    if (anctrl_isAt(anim, 0.2057f)) {
        func_8009514C(arg0);
    }
    if (anctrl_isAt(anim, 0.2555f)) {
        func_8009DF94(arg0, 0x418, 1.8f, 16000);
        _bamotor_entrypoint_1(arg0, 0.5f, 0.25f, 0.4f);
    }
    if (anctrl_isAt(anim, 0.2896f)) {
        func_8009DF94(arg0, 0x418, 1.8f, 16000);
        _bamotor_entrypoint_1(arg0, 0.5f, 0.25f, 0.4f);
    }
    if (anctrl_isAt(anim, 0.3f)) {
        func_8009DF94(arg0, 0x445, 1.0f, 28000);
    }
    if (anctrl_isAt(anim, 0.3607f)) {
        func_800951B4(arg0);
    }
    if (anctrl_isAt(anim, 0.4183f)) {
        func_8009DF58(arg0, 0x43EF, 1.6f);
    }
    if (anctrl_isAt(anim, 0.455f)) {
        func_8009DF58(arg0, 0x43EF, 1.45f);
    }
    if (anctrl_isAt(anim, 0.49f)) {
        func_8009DF58(arg0, 0x43EF, 1.4f);
    }
    if (anctrl_isAt(anim, 0.5397f)) {
        func_800909EC(arg0);
    }
    if (anctrl_isAt(anim, 0.6619f)) {
        func_8009DF94(arg0, 0x418, 1.8f, 16000);
        _bamotor_entrypoint_1(arg0, 0.5f, 0.25f, 0.4f);
    }
    if (anctrl_isAt(anim, 0.6688f)) {
        func_8009514C(arg0);
    }
    if (anctrl_isAt(anim, 0.6964f)) {
        func_8009DF94(arg0, 0x418, 1.8f, 16000);
        _bamotor_entrypoint_1(arg0, 0.5f, 0.25f, 0.4f);
    }
    if (anctrl_isAt(anim, 0.7747f)) {
        func_800951B4(arg0);
    }
    if (anctrl_isAt(anim, 0.7822f)) {
        func_8009DF94(arg0, 0x449, 1.0f, 14000);
    }
    if (anctrl_isAt(anim, 0.8322f)) {
        func_8009DF94(arg0, 0x449, 1.0f, 14000);
    }
    if (anctrl_isAt(anim, 0.8669f)) {
        func_8009DF94(arg0, 0x449, 1.0f, 14000);
    }
    if (anctrl_isAt(anim, 0.9048f)) {
        func_8009DF94(arg0, 0x449, 1.0f, 14000);
    }
    if (anctrl_isAt(anim, 0.9649f)) {
        func_800909EC(arg0);
    }
}

struct anctrl_s;
void bsstand_entrypoint_1(PlayerState *arg0) {
    struct anctrl_s *baanim_getAnimCtrlPtr(PlayerState *);
    f32 anctrl_getAnimTimer(void *);
    int anctrl_getIndex(struct anctrl_s *);
    int anctrl_isAt(struct anctrl_s *, f32);
    void anctrl_reset(void *);
    void anctrl_setDuration(void *, f32);
    void anctrl_setIndex(void *, s32);
    void anctrl_setPlaybackType(void *, s32);
    void anctrl_setStart(void *, f32);
    void anctrl_start(void *);
    void baanim_playForDuration_onceSmooth(PlayerState *, s32, f32);
    f32 bastick_distance(PlayerState *);
    s32 bastick_getZone(PlayerState *);
    void bs_setState(PlayerState *, s32);
    void func_8008B1C8(void *, f32);
    s32 func_8008DD04(PlayerState *);
    void func_800909CC(PlayerState *);
    void func_80090A2C(PlayerState *self);
    void func_8009D874(PlayerState *);
    void func_8009DF18(PlayerState *, s32, f32, s32);
    void func_8009DF94(PlayerState *, s32, f32, s32);
    void func_800A0CF4(PlayerState* arg0, s32 arg1);
    f32 yaw_get(PlayerState *);
    void yaw_setIdeal(PlayerState *, f32);
    void yaw_setUpdateType(PlayerState *, s32);
    void yaw_setVelocityBounded(PlayerState *, f32, f32);
    s32 next_state;
    void *anim;
    f32 start;
    s32 flags;

    anim = baanim_getAnimCtrlPtr(arg0);
    if (bastick_getZone(arg0) == 0 && bastick_distance(arg0) > 0.0f) {
        ((s32 *)arg0)[0x168 / 4] = 1;
        yaw_setUpdateType(arg0, 3);
        yaw_setVelocityBounded(arg0, 200.0f, 14.0f);
    } else {
        if (((s32 *)arg0)[0x168 / 4] != 0) {
            yaw_setIdeal(arg0, yaw_get(arg0));
        }
        ((s32 *)arg0)[0x168 / 4] = 0;
        yaw_setUpdateType(arg0, 1);
    }
    next_state = func_80800038_bsstand(arg0, 0);
    flags = *(u8 *)(((s32 *)arg0)[0x15C / 4] + func_80800000_bsstand((s32 *)arg0));
    if (flags & 8) {
        if (flags & 4) {
            if (anctrl_isAt(anim, 0.0909f)) {
                func_8009D874(arg0);
            }
            if (anctrl_isAt(anim, 0.0909f)) {
                func_800A0CF4(arg0, 1);
            }
            if (anctrl_isAt(anim, 0.6818f)) {
                func_800A0CF4(arg0, 0);
            }
        }
        if (flags & 2) {
            if (anctrl_isAt(anim, 0.7727f)) {
                func_800A0CF4(arg0, 1);
            }
            if (anctrl_isAt(anim, 0.9999f)) {
                func_800A0CF4(arg0, 0);
            }
        }
    } else if (flags & 0x20) {
        if (anctrl_getIndex(anim) == 0x95) {
            func_80800274_bsstand(arg0, anim);
            if (anctrl_isAt(anim, 0.37f)) {
                anctrl_reset(anim);
                func_8008B1C8(anim, 0.1f);
                anctrl_setIndex(anim, 0xF6);
                anctrl_setDuration(anim, 5.0f);
                anctrl_setPlaybackType(anim, 1);
                anctrl_start(anim);
            }
        } else {
            if (anctrl_isAt(anim, 0.069f)) {
                func_8009DF94(arg0, 0x434, 1.4f, 0x4650);
            }
            if (anctrl_isAt(anim, 0.1677f)) {
                func_8009DF94(arg0, 0x4454, 1.0f, 0x4650);
            }
            if (anctrl_isAt(anim, 0.2441f)) {
                func_8009DF94(arg0, 0x4454, 1.03f, 0x4650);
            }
            if (anctrl_isAt(anim, 0.3141f)) {
                func_8009DF94(arg0, 0x4454, 1.06f, 0x4650);
            }
            if (anctrl_isAt(anim, 0.3859f)) {
                func_8009DF94(arg0, 0x4454, 1.5f, 0x7D00);
            }
            if (anctrl_isAt(anim, 0.414f)) {
                func_8009DF18(arg0, 0x41E, 1.0f, 0x4650);
            }
            if (anctrl_isAt(anim, 0.6187f)) {
                func_8009DF94(arg0, 0x445B, 1.7f, 0x4650);
            }
            if (anctrl_isAt(anim, 0.7108f)) {
                func_8009DF94(arg0, 0x445B, 1.6f, 0x4650);
            }
            if (anctrl_isAt(anim, 0.7927f)) {
                func_8009DF94(arg0, 0x445B, 1.5f, 0x4650);
            }
        }
    } else if (flags & 0x10) {
        func_80800274_bsstand(arg0, anim);
    }
    if (anctrl_isAt(anim, 0.9999f)) {
        ((s32 *)arg0)[0x15C / 4] = func_80800018_bsstand(arg0, ((s32 *)arg0)[0x15C / 4]);
        flags = *(u8 *)(((s32 *)arg0)[0x15C / 4] + func_80800000_bsstand((s32 *)arg0));
        if (flags & 0x10) {
            baanim_playForDuration_onceSmooth(arg0, 0x95, 5.5f);
            anctrl_start(anim);
            func_800A0CF4(arg0, 1);
            func_80090A2C(arg0);
        } else if (flags & 0x40) {
            baanim_playForDuration_onceSmooth(arg0, 0xAE, 4.3f);
            anctrl_start(anim);
            func_800A0CF4(arg0, 0);
            func_80090A2C(arg0);
        } else if (flags & 0x20) {
            baanim_playForDuration_onceSmooth(arg0, 0x95, 5.5f);
            func_800A0CF4(arg0, 1);
            func_80090A2C(arg0);
        } else if (flags & 8) {
            if (anctrl_getIndex(anim) == 0x6F) {
                start = anctrl_getAnimTimer(anim);
            } else {
                start = 0.0f;
                func_800909CC(arg0);
            }
            anctrl_reset(anim);
            anctrl_setIndex(anim, 0x6F);
            anctrl_setDuration(anim, 5.5f);
            anctrl_setPlaybackType(anim, 2);
            anctrl_setStart(anim, start);
            anctrl_start(anim);
            func_800A0CF4(arg0, 0);
        }
    }
    if (func_8008DD04(arg0)) {
        next_state = 0x2F;
    }
    bs_setState(arg0, next_state);
}

void bsstand_entrypoint_2(PlayerState *arg0) {
    void func_800A0CF4(PlayerState* arg0, s32 arg1);
    void func_80090A2C(PlayerState *self);
    void func_800951B4(void* mem);
    func_800A0CF4(arg0, 0);
    func_80090A2C(arg0);
    func_800951B4(arg0);
}

s32 bsstand_entrypoint_3(s32 arg0) {
    extern BtIntPtr D_80800D98_bsstand[];
    return ((s32 *)&D_80800D98_bsstand)[arg0];
}

/* extern */

void bsstand_entrypoint_4(PlayerState *arg0) {
    void baphysics_set_target_horizontal_velocity(PlayerState *arg0, f32 vel);
    void func_8009FFD8(PlayerState *, s32, s32, s32, s32);
    func_8009FFD8(arg0, 1, 1, 1, 2);
    baphysics_set_target_horizontal_velocity(arg0, 0.0f);
}

void bsstand_entrypoint_5(PlayerState *arg0) {
    struct anctrl_s *baanim_getAnimCtrlPtr(PlayerState *);
    int anctrl_getIndex(struct anctrl_s *);
    int anctrl_isAt(struct anctrl_s *, f32);
    s32 anctrl_isStopped(struct anctrl_s *);
    void func_8009DF18(PlayerState *, s32, f32, s32);
    void bs_setState(PlayerState *, s32);
    s32 sp24 = 0;
    struct anctrl_s *sp20 = baanim_getAnimCtrlPtr(arg0);

    if (anctrl_getIndex(sp20) == 0xD2) {
        if (anctrl_isAt(sp20, 0.8264f)) {
            func_8009DF18(arg0, 0x449, 1.0f, 0x36B0);
        }
        if (anctrl_isAt(sp20, 0.8864f)) {
            func_8009DF18(arg0, 0x449, 1.0f, 0x36B0);
        }
    }
    if (anctrl_isStopped(sp20)) {
        sp24 = 1;
    }
    bs_setState(arg0, func_80800038_bsstand(arg0, sp24));
}

void bsstand_entrypoint_6(s32 arg0) 
{
}
s32 bsstand_entrypoint_7(s32 arg0) {
    extern BtIntPtr D_80800DA8_bsstand[];
    return ((s32 *)&D_80800DA8_bsstand)[arg0];
}

BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) bsstand_entrypoint_8(BT_NATIVE_ONLY(PlayerState *bt_a0) BT_PASS2(, s32 bt_a1))
{
    BT_NATIVE_ONLY(return) func_80800038_bsstand(BT_PASS2(bt_a0, bt_a1));
}



void bsstand_entrypoint_9(BT_NATIVE_ONLY(s32 bt_a0))
{
    _bsdrone_entrypoint_0(BT_NATIVE_ONLY(bt_a0));
}

void bsstand_entrypoint_10(PlayerState* self)
{
    _bsdrone_entrypoint_1(self);
}
void bsstand_entrypoint_11(s32 arg0)
{
    _bafpctrl_entrypoint_10(arg0,0);
    _bsdrone_entrypoint_2(arg0);
}

s32 bsstand_entrypoint_12(s32 arg0) {
    extern BtIntPtr D_80800DB8_bsstand[];
    return ((s32 *)&D_80800DB8_bsstand)[arg0];
}
/* data_to_c.py: from asm/data/overlays/bs/stand.data.s */
extern u8 D_80800D70_bsstand[];
extern u8 D_80800D78_bsstand[];
void _bsstand_entrypoint_2();
void _bsstand_entrypoint_0();
void _bsstand_entrypoint_1();
void func_8009AB78(PlayerState *);
void _bsstand_entrypoint_6();
void _bsstand_entrypoint_4();
void _bsstand_entrypoint_5();
void _bsstand_entrypoint_11();
void _bsstand_entrypoint_9();
void _bsstand_entrypoint_10();
void _bsdrone_entrypoint_3();
u8 D_80800D70_bsstand[8] BT_DATA(4, overlays_bs_stand, 0x0) = { 0x08, 0x08, 0x08, 0x40, 0x08, 0x08, 0x00, 0x00 };
u8 D_80800D78_bsstand[24] BT_DATA(4, overlays_bs_stand, 0x8) = { 0x09, 0x0A, 0x0C, 0x10, 0x09, 0x09, 0x0A, 0x09, 0x20, 0x09, 0x0A, 0x0C, 0x10, 0x09, 0x09, 0x0A, 0x09, 0x10, 0x09, 0x0A, 0x20, 0x00, 0x00, 0x00 };
BtIntPtr D_80800D90_bsstand [2] BT_DATA(4, overlays_bs_stand, 0x20) = { (BtIntPtr)D_80800D70_bsstand, (BtIntPtr)D_80800D78_bsstand };
BtIntPtr D_80800D98_bsstand [4] BT_DATA(4, overlays_bs_stand, 0x28) = { (BtIntPtr)_bsstand_entrypoint_2, (BtIntPtr)_bsstand_entrypoint_0, (BtIntPtr)_bsstand_entrypoint_1, (BtIntPtr)func_8009AB78 };
BtIntPtr D_80800DA8_bsstand [4] BT_DATA(4, overlays_bs_stand, 0x38) = { (BtIntPtr)_bsstand_entrypoint_6, (BtIntPtr)_bsstand_entrypoint_4, (BtIntPtr)_bsstand_entrypoint_5, (BtIntPtr)func_8009AB78 };
BtIntPtr D_80800DB8_bsstand [6] BT_DATA(4, overlays_bs_stand, 0x48) = { (BtIntPtr)_bsstand_entrypoint_11, (BtIntPtr)_bsstand_entrypoint_9, (BtIntPtr)_bsstand_entrypoint_10, (BtIntPtr)_bsdrone_entrypoint_3, 0, 0 };
