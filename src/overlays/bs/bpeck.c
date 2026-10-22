#include "common.h"

struct player_state_s;
void bsbpeck_entrypoint_0(struct player_state_s *self) {
    s32 baanim_playForDuration_once(void *, s32, f32);
    s32 baflag_set(struct player_state_s *, s32);
    s32 func_800A0CF4();
    void baphysics_set_gravity(struct player_state_s *, f32);
    void baphysics_set_vertical_velocity(struct player_state_s *, f32);
    s32 bs_getPreviousState(struct player_state_s *);
    s32 func_8009557C(struct player_state_s *);
    void func_80095588(struct player_state_s *, s32);
    void func_8009E4AC(struct player_state_s *);
    void func_8009E4FC(void *, s32, f32, f32, f32);
    void func_8009E55C(struct player_state_s *, s32, f32);
    void func_8009FFD8();
    void yaw_setVelocityBounded(struct player_state_s *, f32, f32);
    s32 previous;

    ((s32 *)self)[0x59] = 0;
    previous = bs_getPreviousState(self);
    if (previous != 5 && (previous == 8 ||
        (previous != 0x2F && previous != 0x3D &&
         previous != 0x57 && previous == 0x95))) {
        ((s32 *)self)[0x59]++;
    }
    if (func_8009557C(self) == 1) {
        func_80095588(self, 2);
    }
    baanim_playForDuration_once(self, 0x1A, 0.2f);
    func_8009FFD8(self, 1, 3, 1, 6);
    yaw_setVelocityBounded(self, 1200.0f, 10.0f);
    func_800A0CF4(self, 1);
    baphysics_set_gravity(self, -1400.0f);
    baphysics_set_vertical_velocity(self, 120.0f);
    func_8009E4AC(self);
    func_8009E55C(self, 0, 35.0f);
    func_8009E55C(self, 1, 42.0f);
    func_8009E4FC(self, 1, -38.0f, 0.0f, 105.0f);
    func_8009E4FC(self, 0, -38.0f, 0.0f, -7.0f);
    ((s32 *)self)[0x58] = 0;
    ((s32 *)self)[0x57] = 0;
    baflag_set(self, 0x2A);
}

typedef struct player_state_s PlayerState;

void func_80800168_bsbpeck(PlayerState *self) {
    s32 baflag_set(PlayerState *, s32);
    void func_8009DE38(PlayerState *, s32, f32);
    void baphysics_set_vertical_velocity(PlayerState *, f32);
    f32 rate = 1.0f;

    switch (((s32 *)self)[0x58]) {
        case 0:
            rate = 1.13f;
            break;
        case 1:
            rate = 1.1f;
            break;
        case 2:
            rate = 1.32f;
            break;
    }
    baflag_set(self, 5);
    func_8009DE38(self, 0x442C, rate);
    baphysics_set_vertical_velocity(self, 120.0f);
    ((s32 *)self)[0x58]++;
}

void bsbpeck_entrypoint_1(PlayerState *self) {
    typedef struct anctrl_s AnimCtrl;
    int anctrl_isAt(AnimCtrl *, f32);
    s32 anctrl_isStopped(AnimCtrl *);
    void anctrl_reset(AnimCtrl *);
    void anctrl_setDuration(AnimCtrl *, f32);
    void anctrl_setIndex();
    void anctrl_setPlaybackType(AnimCtrl *, s32);
    void anctrl_setSmoothTransition(AnimCtrl *, s32);
    void anctrl_setStart(AnimCtrl *, f32);
    void anctrl_start(AnimCtrl *);
    void func_8008B188(AnimCtrl *, s32);
    s32 _bswalk_entrypoint_1();
    AnimCtrl *baanim_getAnimCtrlPtr(PlayerState *);
    f32 baphysics_get_target_horizontal_velocity(PlayerState *);
    void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
    void func_8009FE58(PlayerState *);
    f32 func_800D8FF8(void);
    s32 nextState = 0;
    AnimCtrl *control = baanim_getAnimCtrlPtr(self);

    _bswalk_entrypoint_1(self);
    if (((s32 *)self)[0x59] != 0) {
        baphysics_set_target_horizontal_velocity(self, baphysics_get_target_horizontal_velocity(self) * 0.1f);
    }
    switch (((s32 *)self)[0x57]) {
        case 0:
            if (anctrl_isAt(control, 0.9126f)) {
                anctrl_setIndex(control, 0x19);
                anctrl_setStart(control, 0.0f);
                anctrl_setDuration(control, 0.35f);
                anctrl_setPlaybackType(control, 2);
                anctrl_start(control);
                ((s32 *)self)[0x57] = 1;
                ((f32 *)self)[0x5B] = 0.5f;
            }
            break;
        case 1:
            if (anctrl_isAt(control, 0.1621f)) {
                func_80800168_bsbpeck(self);
            }
            if (anctrl_isAt(control, 0.7f)) {
                func_80800168_bsbpeck(self);
            }
            ((f32 *)self)[0x5B] -= func_800D8FF8();
            if (((f32 *)self)[0x5B] < 0.0f) {
                anctrl_reset(control);
                anctrl_setSmoothTransition(control, 0);
                anctrl_setIndex(control, 0x1A);
                func_8008B188(control, 0);
                anctrl_setDuration(control, 0.2f);
                anctrl_setPlaybackType(control, 1);
                anctrl_start(control);
                ((s32 *)self)[0x57] = 2;
            }
            break;
        case 2:
            if (anctrl_isStopped(control)) {
                nextState = 0x2F;
            }
            break;
    }
    if (player_isStable(self)) {
        func_8009FE58(self);
        nextState = 1;
    }
    if (player_inWater(self)) {
        nextState = 0x4C;
    }
    bs_setState(self, nextState);
}

/* extern */

void bsbpeck_entrypoint_2(s32 arg0) {
    s32 baflag_clear(s32, s32);
    void func_800C6DA0(s32);
    s32 baphysics_reset_gravity(s32);
    s32 func_8009E474(s32);
    s32 func_800A0CF4(s32, s32);
    baflag_clear(arg0, 0x2A);
    func_800C6DA0(0x46);
    func_8009E474(arg0);
    func_800A0CF4(arg0, 0);
    baphysics_reset_gravity(arg0);
}

s32 bsbpeck_entrypoint_3(s32 arg0) {
    extern s32 D_808004A0_bsbpeck[];
    return ((s32 *)&D_808004A0_bsbpeck)[arg0];
}
