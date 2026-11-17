#include "common.h"
#ifdef BT_NATIVE // complete the enum forward declarations below
#include "overlays/ba/assets.h"
#endif

/* extern */

struct player_state_s;

void func_80800000_bsdie(struct player_state_s *self) {
    void _badust_entrypoint_5(struct player_state_s *, f32, f32);
    f32 angle;

    for (angle = 0.0f; angle < 360.0f; angle += 45.0f) {
        _badust_entrypoint_5(self, angle, 230.0f);
    }
}

/* extern */

struct anctrl_s;
enum asset_e;
void bsdie_entrypoint_0(struct player_state_s *arg0) {
    void _basudie_entrypoint_4(struct player_state_s *, f32, f32, f32, f32, f32);
    void anctrl_reset(struct anctrl_s *);
    void anctrl_setDuration(struct anctrl_s *, f32);
    void anctrl_setIndex(struct anctrl_s *, enum asset_e);
    void anctrl_setPlaybackType(struct anctrl_s *, s32);
    void anctrl_setSmoothTransition(struct anctrl_s *, s32);
    void anctrl_setSubrange(struct anctrl_s *, f32, f32);
    void anctrl_start(struct anctrl_s *);
    struct anctrl_s *baanim_getAnimCtrlPtr(struct player_state_s *);
    void func_8009BFE4(struct player_state_s *, f32, f32);
    void func_8009D820(struct player_state_s *, f32);
    void func_800A0CF4(struct player_state_s *, s32);
    struct anctrl_s *temp_v0;

    temp_v0 = baanim_getAnimCtrlPtr(arg0);
    anctrl_reset(temp_v0);
    anctrl_setSmoothTransition(temp_v0, 0);
    anctrl_setIndex(temp_v0, 9);
    anctrl_setSubrange(temp_v0, 0.0f, 0.3356f);
    anctrl_setDuration(temp_v0, 2.0f);
    anctrl_setPlaybackType(temp_v0, 1);
    anctrl_start(temp_v0);
    (*(f32 *)((s8 *)(arg0) + (0x16C))) = 250.0f;
    _basudie_entrypoint_4(arg0, *(f32 *)((s8 *)arg0 + 0x16C), 510.0f, -1400.0f, 25.0f, 3.5f);
    func_800A0CF4(arg0, 1);
    func_8009D820(arg0, 1.0f);
    func_8009BFE4(arg0, 1000.0f, 12.0f);
    (*(s32 *)((s8 *)(arg0) + (0x15C))) = 0;
}

void bsdie_entrypoint_1(struct player_state_s *arg0) {
    void _basudie_entrypoint_5(struct player_state_s *);
    s32 _basudie_entrypoint_7(struct player_state_s *);
    void _bamotor_entrypoint_1(struct player_state_s *, f32, f32, f32);
    void _badust_entrypoint_9(struct player_state_s *);
    struct anctrl_s *baanim_getAnimCtrlPtr(struct player_state_s *);
    void baphysics_set_target_horizontal_velocity(struct player_state_s *, f32);
    void baphysics_set_vertical_velocity(struct player_state_s *, f32);
    void anctrl_setSubrange(struct anctrl_s *, f32, f32);
    void anctrl_setPlaybackType(struct anctrl_s *, s32);
    void anctrl_setDuration(struct anctrl_s *, f32);
    int anctrl_isAt(struct anctrl_s *, f32);
    s32 anctrl_isStopped(struct anctrl_s *);
    int player_isStable(struct player_state_s *);
    void func_8009DF18(struct player_state_s *, s32, f32, s32);
    void func_8009E058(struct player_state_s *);
    void func_8009E084(struct player_state_s *);
    f32 func_800F0E00(f32, f32);
    void bs_setState(void *self, s32 nextState);
    struct anctrl_s *sp24;
    s32 sp20;

    sp24 = baanim_getAnimCtrlPtr(arg0);
    sp20 = 0;
    _basudie_entrypoint_5(arg0);
    baphysics_set_target_horizontal_velocity(arg0, *(f32 *)((s8 *)arg0 + 0x16C));
    switch (*(s32 *)((s8 *)arg0 + 0x15C)) {
    case 0:
        if (player_isStable(arg0)) {
            anctrl_setSubrange(sp24, 0.0f, 1.0f);
            anctrl_setPlaybackType(sp24, 1);
            baphysics_set_vertical_velocity(arg0, 400.0f);
            func_8009E058(arg0);
            func_8009DF18(arg0, 0x428, 1.0f, 0x4650);
            _bamotor_entrypoint_1(arg0, 1.0, 1.0, 0.4f);
            func_80800000_bsdie(arg0);
            *(s32 *)((s8 *)arg0 + 0x15C) = 1;
        }
        break;
    case 1:
        if (player_isStable(arg0)) {
            func_8009E084(arg0);
            func_8009DF18(arg0, 0x427, 1.0f, 0x4650);
            _bamotor_entrypoint_1(arg0, 1.0f, 0.5f, 0.4f);
            *(s32 *)((s8 *)arg0 + 0x15C) = 2;
        }
        break;
    case 2:
        *(f32 *)((s8 *)arg0 + 0x16C) = func_800F0E00(*(f32 *)((s8 *)arg0 + 0x16C) - 12.0f, 0.0f);
        if (*(f32 *)((s8 *)arg0 + 0x16C) > 140.0f) {
            _badust_entrypoint_9(arg0);
        }
        if (anctrl_isAt(sp24, 0.6538f)) {
            anctrl_setDuration(sp24, 4.0f);
        }
        if (anctrl_isStopped(sp24)) {
            *(s32 *)((s8 *)arg0 + 0x15C) = 3;
            *(f32 *)((s8 *)arg0 + 0x16C) = 0.0f;
        }
        break;
    case 3:
        break;
    }
    if (_basudie_entrypoint_7(arg0)) {
        sp20 = 0x54;
    }
    bs_setState(arg0, sp20);
}

/* extern */

void bsdie_entrypoint_2(BtIntPtr arg0) {
    void baroll_setIdeal(void *self, f32 arg1);
    s32 _basudie_entrypoint_6();
    void func_8009BF5C(BtIntPtr, f32);
    void func_800A0CF4(struct player_state_s *, s32);
    _basudie_entrypoint_6();
    func_800A0CF4(arg0, 0);
    func_8009BF5C(arg0, 0);
    baroll_setIdeal(arg0, 0);
}

s32 bsdie_entrypoint_3(s32 arg0) {
    extern BtIntPtr D_80800960_bsdie[];
    return ((s32 *)&D_80800960_bsdie)[arg0];
}

/* extern */

void bsdie_entrypoint_4(struct player_state_s *arg0) {
    void _basudie_entrypoint_4(struct player_state_s *, f32, f32, f32, f32, f32);
    void anctrl_reset(struct anctrl_s *);
    void anctrl_setDuration(struct anctrl_s *, f32);
    void anctrl_setIndex(struct anctrl_s *, enum asset_e);
    void anctrl_setPlaybackType(struct anctrl_s *, s32);
    void anctrl_setSmoothTransition(struct anctrl_s *, s32);
    void anctrl_setSubrange(struct anctrl_s *, f32, f32);
    void anctrl_start(struct anctrl_s *);
    struct anctrl_s *baanim_getAnimCtrlPtr(struct player_state_s *);
    void func_8009BFE4(struct player_state_s *, f32, f32);
    void func_8009D820(struct player_state_s *, f32);
    void func_800A0CF4(struct player_state_s *, s32);
    struct anctrl_s *temp_v0;

    temp_v0 = baanim_getAnimCtrlPtr(arg0);
    anctrl_reset(temp_v0);
    anctrl_setSmoothTransition(temp_v0, 0);
    anctrl_setIndex(temp_v0, 0xD8);
    anctrl_setSubrange(temp_v0, 0.0f, 0.0932f);
    anctrl_setDuration(temp_v0, 4.7f);
    anctrl_setPlaybackType(temp_v0, 1);
    anctrl_start(temp_v0);
    (*(f32 *)((s8 *)(arg0) + (0x16C))) = 250.0f;
    _basudie_entrypoint_4(arg0, *(f32 *)((s8 *)arg0 + 0x16C), 510.0f, -1400.0f, 30.0f, 4.0f);
    func_800A0CF4(arg0, 1);
    func_8009BFE4(arg0, 1000.0f, 12.0f);
    func_8009D820(arg0, 1.0f);
    (*(s32 *)((s8 *)(arg0) + (0x15C))) = 0;
}

void bsdie_entrypoint_5(struct player_state_s *arg0) {
    void _basudie_entrypoint_5(struct player_state_s *);
    s32 _basudie_entrypoint_7(struct player_state_s *);
    void _bamotor_entrypoint_1(struct player_state_s *, f32, f32, f32);
    void _badust_entrypoint_9(struct player_state_s *);
    void baphysics_set_target_horizontal_velocity(struct player_state_s *, f32);
    struct anctrl_s *baanim_getAnimCtrlPtr(struct player_state_s *);
    void baanim_setEnd(struct player_state_s *, f32);
    void func_8009DF18(struct player_state_s *, s32, f32, s32);
    void func_8009E058(struct player_state_s *);
    f32 func_800F0E00(f32, f32);
    void bs_setState(void *self, s32 nextState);
    int func_8008DF8C(struct player_state_s *, s32);
    int player_isStable(struct player_state_s *);
    s32 anctrl_isStopped(struct anctrl_s *);
    struct anctrl_s *control;
    s32 next_state;
    f32 speed;

    control = baanim_getAnimCtrlPtr(arg0);
    next_state = 0;
    _basudie_entrypoint_5(arg0);
    baphysics_set_target_horizontal_velocity(arg0, (*(f32 *)((s8 *)arg0 + 0x16C)));
    switch (*(s32 *)((s8 *)arg0 + 0x15C)) {
        case 0:
            if (func_8008DF8C(arg0, 0x96)) {
                baanim_setEnd(arg0, 0.1863f);
                *(s32 *)((s8 *)arg0 + 0x15C) = 1;
            }
            break;
        case 1:
            if (player_isStable(arg0)) {
                func_8009DF18(arg0, 0x428, 1.0f, 0x4650);
                _bamotor_entrypoint_1(arg0, 1.0f, 1.0f, 0.4f);
                func_80800000_bsdie(arg0);
                func_8009E058(arg0);
                baanim_setEnd(arg0, 0.3333f);
                *(s32 *)((s8 *)arg0 + 0x15C) = 2;
            }
            break;
        case 2:
            speed = func_800F0E00((*(f32 *)((s8 *)arg0 + 0x16C)) - 12.0f, 0.0f);
            (*(f32 *)((s8 *)arg0 + 0x16C)) = speed;
            if (speed > 140.0f) {
                _badust_entrypoint_9(arg0);
            }
            if (anctrl_isStopped(control)) {
                baanim_setEnd(arg0, 1.0f);
                *(s32 *)((s8 *)arg0 + 0x15C) = 3;
                (*(f32 *)((s8 *)arg0 + 0x16C)) = 0.0f;
            }
            break;
        case 3:
            break;
    }
    if (_basudie_entrypoint_7(arg0)) {
        next_state = 0x54;
    }
    bs_setState(arg0, next_state);
}

/* extern */

void bsdie_entrypoint_6(BtIntPtr arg0) {
    void baroll_setIdeal(void *self, f32 arg1);
    s32 _basudie_entrypoint_6();
    void func_8009BF5C(BtIntPtr, f32);
    void func_800A0CF4(struct player_state_s *, s32);
    _basudie_entrypoint_6();
    func_8009BF5C(arg0, 0.0f);
    baroll_setIdeal(arg0, 0.0f);
    func_800A0CF4(arg0, 0);
}

s32 bsdie_entrypoint_7(s32 arg0) {
    extern BtIntPtr D_80800970_bsdie[];
    return ((s32 *)&D_80800970_bsdie)[arg0];
}

/* extern */

void bsdie_entrypoint_8(struct player_state_s *arg0) {


    void _basudie_entrypoint_4(struct player_state_s *, f32, f32, f32, f32, f32);
    void anctrl_reset(struct anctrl_s *);
    void anctrl_setDuration(struct anctrl_s *, f32);
    void anctrl_setIndex(struct anctrl_s *, enum asset_e);
    void anctrl_setPlaybackType(struct anctrl_s *, s32);
    void anctrl_setSmoothTransition(struct anctrl_s *, s32);
    void anctrl_setSubrange(struct anctrl_s *, f32, f32);
    void anctrl_start(struct anctrl_s *);
    struct anctrl_s *baanim_getAnimCtrlPtr(struct player_state_s *);
    void func_8009BFE4(struct player_state_s *, f32, f32);
    void func_8009D820(struct player_state_s *, f32);
    struct anctrl_s *control;

    control = baanim_getAnimCtrlPtr(arg0);
    *(f32 *)((s8 *)arg0 + 0x16C) = 250.0f;
    anctrl_reset(control);
    anctrl_setSmoothTransition(control, 0);
    anctrl_setIndex(control, 0xD7);
    anctrl_setSubrange(control, 0.0f, 0.0981f);
    anctrl_setDuration(control, 3.8f);
    anctrl_setPlaybackType(control, 1);
    anctrl_start(control);
    _basudie_entrypoint_4(arg0, *(f32 *)((s8 *)arg0 + 0x16C), 510.0f, -1400.0f, 30.0f, 3.3999999f);
    func_8009BFE4(arg0, 1000.0f, 12.0f);
    func_8009D820(arg0, 1.0f);
    *(s32 *)((s8 *)arg0 + 0x15C) = 0;
}

void bsdie_entrypoint_9(struct player_state_s *arg0) {
    void _basudie_entrypoint_5(struct player_state_s *);
    s32 _basudie_entrypoint_7(struct player_state_s *);
    void _bamotor_entrypoint_1(struct player_state_s *, f32, f32, f32);
    void _badust_entrypoint_9(struct player_state_s *);
    void baphysics_set_target_horizontal_velocity(struct player_state_s *, f32);
    struct anctrl_s *baanim_getAnimCtrlPtr(struct player_state_s *);
    void baanim_setEnd(struct player_state_s *, f32);
    void baanim_setEndAndDuration(struct player_state_s *, f32, f32);
    void func_8009DF18(struct player_state_s *, s32, f32, s32);
    void func_8009E058(struct player_state_s *);
    f32 func_800F0E00(f32, f32);
    void bs_setState(void *self, s32 nextState);
    int func_8008DF8C(struct player_state_s *, s32);
    int player_isStable(struct player_state_s *);
    s32 anctrl_isStopped(struct anctrl_s *);
    struct anctrl_s *control;
    s32 next_state;
    f32 speed;

    control = baanim_getAnimCtrlPtr(arg0);
    next_state = 0;
    _basudie_entrypoint_5(arg0);
    baphysics_set_target_horizontal_velocity(arg0, *(f32 *)((s8 *)arg0 + 0x16C));
    switch (*(s32 *)((s8 *)arg0 + 0x15C)) {
        case 0:
            if (func_8008DF8C(arg0, 200)) {
                baanim_setEndAndDuration(arg0, 0.1961f, 3.1f);
                *(s32 *)((s8 *)arg0 + 0x15C) = 1;
            }
            break;
        case 1:
            if (player_isStable(arg0)) {
                func_8009DF18(arg0, 0x428, 1.0f, 0x4650);
                _bamotor_entrypoint_1(arg0, 1.0f, 1.0f, 0.4f);
                func_80800000_bsdie(arg0);
                func_8009E058(arg0);
                baanim_setEnd(arg0, 0.75f);
                *(s32 *)((s8 *)arg0 + 0x15C) = 2;
            }
            break;
        case 2:
            speed = func_800F0E00(*(f32 *)((s8 *)arg0 + 0x16C) - 7.0f, 0.0f);
            *(f32 *)((s8 *)arg0 + 0x16C) = speed;
            if (speed > 140.0f) {
                _badust_entrypoint_9(arg0);
            }
            if (anctrl_isStopped(control)) {
                baanim_setEnd(arg0, 1.0f);
                *(s32 *)((s8 *)arg0 + 0x15C) = 3;
                *(f32 *)((s8 *)arg0 + 0x16C) = 0.0f;
            }
            break;
        case 3:
            break;
    }
    if (_basudie_entrypoint_7(arg0)) {
        next_state = 0x54;
    }
    bs_setState((BtIntPtr)arg0, next_state);
}

/* extern */

void bsdie_entrypoint_10(BtIntPtr arg0) {
    void baroll_setIdeal(void *self, f32 arg1);
    s32 _basudie_entrypoint_6();
    void func_8009BF5C(BtIntPtr, f32);
    _basudie_entrypoint_6();
    func_8009BF5C(arg0, 0.0f);
    baroll_setIdeal(arg0, 0.0f);
}

s32 bsdie_entrypoint_11(s32 arg0) {
    extern BtIntPtr D_80800980_bsdie[];
    return ((s32 *)&D_80800980_bsdie)[arg0];
}
/* data_to_c.py: from asm/data/overlays/bs/die.data.s */
void _bsdie_entrypoint_2();
void _bsdie_entrypoint_0();
void _bsdie_entrypoint_1();
void _basudie_entrypoint_11();
void _bsdie_entrypoint_6();
void _bsdie_entrypoint_4();
void _bsdie_entrypoint_5();
void _bsdie_entrypoint_10();
void _bsdie_entrypoint_8();
void _bsdie_entrypoint_9();
BtIntPtr D_80800960_bsdie [4] BT_DATA(4, overlays_bs_die, 0x0) = { (BtIntPtr)_bsdie_entrypoint_2, (BtIntPtr)_bsdie_entrypoint_0, (BtIntPtr)_bsdie_entrypoint_1, (BtIntPtr)_basudie_entrypoint_11 };
BtIntPtr D_80800970_bsdie [4] BT_DATA(4, overlays_bs_die, 0x10) = { (BtIntPtr)_bsdie_entrypoint_6, (BtIntPtr)_bsdie_entrypoint_4, (BtIntPtr)_bsdie_entrypoint_5, (BtIntPtr)_basudie_entrypoint_11 };
BtIntPtr D_80800980_bsdie [4] BT_DATA(4, overlays_bs_die, 0x20) = { (BtIntPtr)_bsdie_entrypoint_10, (BtIntPtr)_bsdie_entrypoint_8, (BtIntPtr)_bsdie_entrypoint_9, (BtIntPtr)_basudie_entrypoint_11 };
