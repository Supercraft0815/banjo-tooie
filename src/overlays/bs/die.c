#include "common.h"

/* extern */

struct player_state_s;

void func_80800000_bsdie(struct player_state_s *self) {
    void _badust_entrypoint_5(struct player_state_s *, f32, f32);
    f32 angle;

    for (angle = 0.0f; angle < 360.0f; angle += 45.0f) {
        _badust_entrypoint_5(self, angle, 230.0f);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/die/bsdie_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/die/bsdie_entrypoint_1.s")

/* extern */

void bsdie_entrypoint_2(s32 arg0) {
    s32 baroll_setIdeal(s32, f32);
    s32 _basudie_entrypoint_6();
    void func_8009BF5C(s32, f32);
    s32 func_800A0CF4(s32, s32);
    _basudie_entrypoint_6();
    func_800A0CF4(arg0, 0);
    func_8009BF5C(arg0, 0);
    baroll_setIdeal(arg0, 0);
}

s32 bsdie_entrypoint_3(s32 arg0) {
    extern s32 D_80800960_bsdie[];
    return ((s32 *)&D_80800960_bsdie)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/die/bsdie_entrypoint_4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/die/bsdie_entrypoint_5.s")

/* extern */

void bsdie_entrypoint_6(s32 arg0) {
    s32 baroll_setIdeal(s32, f32);
    s32 _basudie_entrypoint_6();
    void func_8009BF5C(s32, f32);
    s32 func_800A0CF4(s32, s32);
    _basudie_entrypoint_6();
    func_8009BF5C(arg0, 0.0f);
    baroll_setIdeal(arg0, 0.0f);
    func_800A0CF4(arg0, 0);
}

s32 bsdie_entrypoint_7(s32 arg0) {
    extern s32 D_80800970_bsdie[];
    return ((s32 *)&D_80800970_bsdie)[arg0];
}

/* extern */

void bsdie_entrypoint_8(struct player_state_s *arg0) {
    struct anctrl_s;
    enum asset_e;
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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/die/bsdie_entrypoint_9.s")

/* extern */

void bsdie_entrypoint_10(s32 arg0) {
    s32 baroll_setIdeal(s32, f32);
    s32 _basudie_entrypoint_6();
    void func_8009BF5C(s32, f32);
    _basudie_entrypoint_6();
    func_8009BF5C(arg0, 0.0f);
    baroll_setIdeal(arg0, 0.0f);
}

s32 bsdie_entrypoint_11(s32 arg0) {
    extern s32 D_80800980_bsdie[];
    return ((s32 *)&D_80800980_bsdie)[arg0];
}
