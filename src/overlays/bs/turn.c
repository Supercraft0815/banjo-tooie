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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/turn/bsturn_entrypoint_1.s")

/* extern */

void bsturn_entrypoint_2(s32 arg0) {
    s32 baroll_setIdeal(s32, f32);
    f32 func_800136E4(f32);
    void func_8009BF5C(s32, f32);
    f32 yaw_get();
    s32 yaw_set(s32, f32);
    yaw_set(arg0, func_800136E4(yaw_get() - 180.0f));
    func_8009BF5C(arg0, 0.0f);
    baroll_setIdeal(arg0, 0.0f);
}

s32 bsturn_entrypoint_3(s32 arg0) {
    extern s32 D_80800360_bsturn[];
    return ((s32 *)&D_80800360_bsturn)[arg0];
}
