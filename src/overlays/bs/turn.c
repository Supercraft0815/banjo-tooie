#include "bs_script.h"
#include "common.h"
struct player_state_s;
struct anctrl_s;

void bsturn_entrypoint_0(struct player_state_s *self) {
    struct anctrl_s *baanim_getAnimCtrlPtr(struct player_state_s *);
    void anctrl_reset(struct anctrl_s *);
    void anctrl_setIndex(struct anctrl_s *, int);
    void anctrl_setDuration(struct anctrl_s *, f32);
    void func_8008B1C8(struct anctrl_s *, f32);
    void anctrl_setPlaybackType(struct anctrl_s *, s32);
    void anctrl_start(struct anctrl_s *);
    void baphysics_set_type(struct player_state_s *, int);
    void func_8008CA4C(struct player_state_s *, int);
    void func_8009BB24(struct player_state_s *, f32 *);
    void func_8009D2D8(struct player_state_s *, s32);
    void func_8009DEC0(struct player_state_s *, s32, f32, f32, s32, s32);
    void yaw_setUpdateType(struct player_state_s *, int);
    f32 sqrtf(f32);
    struct anctrl_s *control;
    f32 velocity[3];

    control = baanim_getAnimCtrlPtr(self);
    anctrl_reset(control);
    anctrl_setIndex(control, 0xE);
    anctrl_setDuration(control, 0.3f);
    func_8008B1C8(control, 0.1f);
    anctrl_setPlaybackType(control, 1);
    anctrl_start(control);
    func_8008CA4C(self, 1);
    yaw_setUpdateType(self, 1);
    func_8009D2D8(self, 2);
    baphysics_set_type(self, 3);
    func_8009BB24(self, velocity);
    *(f32 *)((u8 *)self + 0x16C) = sqrtf(velocity[0] * velocity[0] + velocity[2] * velocity[2]);
    func_8009DEC0(self, 0x411, 0.95f, 1.05f, 30000, 32000);
    *(s32 *)((u8 *)self + 0x15C) = 0;
}

void bsturn_entrypoint_1(struct player_state_s *self) {
    struct anctrl_s *baanim_getAnimCtrlPtr(struct player_state_s *);
    f32 anctrl_getAnimTimer(struct anctrl_s *);
    s32 anctrl_isStopped(struct anctrl_s *);
    void baphysics_set_target_horizontal_velocity(struct player_state_s *, f32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    f32 func_8009BB18(void *);
    f32 func_8009BB5C(struct player_state_s *);
    void _badust_entrypoint_3(struct player_state_s *, f32, f32);
    int bakey_held(struct player_state_s *, s32);
    int bakey_pressed(struct player_state_s *, int);
    s32 func_800A055C(struct player_state_s *, s32);
    s32 bs_getTypeOfJump(struct player_state_s *);
    void bs_setState(void *self, s32 nextState);
    s32 next_state;
    f32 timer;
    f32 angle;

    next_state = 0;
    timer = anctrl_getAnimTimer(baanim_getAnimCtrlPtr(self));
    baphysics_set_target_horizontal_velocity(self, func_800F10B4(timer, 0.18f, 1.0f, *(f32 *)((u8 *)self + 0x16C), 0.0f));
    (*(s32 *)((u8 *)self + 0x15C))++;
    if (*(s32 *)((u8 *)self + 0x15C) >= 6) {
        *(s32 *)((u8 *)self + 0x15C) = -1;
    }
    switch (*(s32 *)((u8 *)self + 0x15C)) {
        case -1:
            angle = func_8009BB18(self);
            _badust_entrypoint_3(self, angle - 10.0f, func_8009BB5C(self) * 0.88f);
            break;
        case 0:
            angle = func_8009BB18(self);
            _badust_entrypoint_3(self, angle, func_8009BB5C(self));
            break;
        case 1:
            angle = func_8009BB18(self);
            _badust_entrypoint_3(self, angle + 10.0f, func_8009BB5C(self) * 0.88f);
            break;
    }
    if (anctrl_isStopped(baanim_getAnimCtrlPtr(self))) {
        next_state = 4;
    }
    if (bakey_held(self, 1)) {
        next_state = 7;
    }
    if (bakey_pressed(self, 9)) {
        next_state = func_800A055C(self, next_state);
    }
    if (bakey_pressed(self, 8)) {
        next_state = bs_getTypeOfJump(self);
    }
    bs_setState(self, next_state);
}

/* extern */

void bsturn_entrypoint_2(BtIntPtr arg0) {
    void baroll_setIdeal(void *self, f32 arg1);
    f32 func_800136E4(f32);
    void func_8009BF5C(BtIntPtr, f32);
    f32 yaw_get(BT_NATIVE_ONLY(struct player_state_s *));
    void yaw_set(void *self, f32 arg1);
    yaw_set(arg0, func_800136E4(yaw_get(BT_NATIVE_ONLY((struct player_state_s *)arg0)) - 180.0f));
    func_8009BF5C(arg0, 0.0f);
    baroll_setIdeal(arg0, 0.0f);
}

BsScript bsturn_entrypoint_3(BsScriptType arg0) {
    extern BtIntPtr D_80800360_bsturn[];
    return (BsScript)D_80800360_bsturn[arg0];
}
/* data_to_c.py: from asm/data/overlays/bs/turn.data.s */
void _bsturn_entrypoint_2();
void _bsturn_entrypoint_0();
void _bsturn_entrypoint_1();
void func_8009AB78();
BtIntPtr D_80800360_bsturn [4] BT_DATA(4, overlays_bs_turn, 0x0) = { (BtIntPtr)_bsturn_entrypoint_2, (BtIntPtr)_bsturn_entrypoint_0, (BtIntPtr)_bsturn_entrypoint_1, (BtIntPtr)func_8009AB78 };
