#include "common.h"

/* extern */

struct player_state_s;

void bssplat_entrypoint_0(struct player_state_s *arg0) {
    s32 _badust_entrypoint_8(struct player_state_s *);
    s32 _bashake_entrypoint_0(struct player_state_s *, s32, s32);
    s32 func_800954E8(void *, s32 *);
    s32 func_80096694(struct player_state_s *);
    void func_8009DB04(struct player_state_s *, s32, f32, s32);
    void func_800A17A8(struct player_state_s *, s32);
    s32 sp24;

    func_800954E8(arg0, &sp24);
    func_800A17A8(arg0, -sp24);
    if (func_80096694(arg0) == 3) {
        func_8009DB04(arg0, 0x417, 0.8f, 0x7FFF);
    } else {
        func_8009DB04(arg0, 0x417, 0.8f, 0x7FFF);
    }
    _badust_entrypoint_8(arg0);
    _bashake_entrypoint_0(arg0, 3, 2);
}

/* extern */

void func_8080009C_bssplat(void *arg0) {
    s32 baanim_playForDuration_once(void *, s32, f32);
    void bssplat_entrypoint_0(struct player_state_s *);
    s32 func_8008E944(void *);
    s32 func_8009DF18(void *, s32, f32, s32);
    s32 func_8009FFD8(void *, s32, s32, s32, s32);
    baanim_playForDuration_once(arg0, 0x46, 1.1f);
    func_8009FFD8(arg0, 1, 1, 3, 3);
    bssplat_entrypoint_0(arg0);
    func_8009DF18(arg0, 0x427, 1.0f, 0x6D60);
    (*(s32 *)((s8 *)(arg0) + (0x15C))) = 0;
    func_8008E944(arg0);
}

void func_80800114_bssplat(struct player_state_s *arg0) {
    void _badust_entrypoint_9(void *);
    struct anctrl_s *baanim_getAnimCtrlPtr(struct player_state_s *);
    void baanim_playForDuration_onceSmooth(struct player_state_s *, s32, f32);
    f32 baphysics_get_target_horizontal_velocity(struct player_state_s *);
    void baphysics_set_target_horizontal_velocity(struct player_state_s *, f32);
    int anctrl_isAt(struct anctrl_s *, f32);
    s32 anctrl_isStopped(struct anctrl_s *);
    int func_8008DD04(struct player_state_s *);
    s32 func_800A1718(struct player_state_s *);
    s32 player_inWater(struct player_state_s *);
    int player_isStable(struct player_state_s *);
    s32 bs_setState(s32, s32);
    f32 func_800F0E00(f32, f32);
    s32 sp24;
    struct anctrl_s *sp20;

    sp24 = 0;
    sp20 = baanim_getAnimCtrlPtr(arg0);
    baphysics_set_target_horizontal_velocity(arg0, func_800F0E00(0.0f, baphysics_get_target_horizontal_velocity(arg0) - 15.0f));
    switch (*(s32 *)((s8 *)arg0 + 0x15C)) {
    case 0:
        if (baphysics_get_target_horizontal_velocity(arg0) > 140.0f) {
            _badust_entrypoint_9(arg0);
        }
        if (func_8008DD04(arg0) != 0) {
            sp24 = 0x2F;
        }
        if (anctrl_isStopped(sp20) != 0) {
            baanim_playForDuration_onceSmooth(arg0, 0xD2, 2.25f);
            *(s32 *)((s8 *)arg0 + 0x15C) = 1;
        }
        break;
    case 1:
        if (anctrl_isAt(sp20, 0.63f) != 0) {
            sp24 = 0x20;
        }
        if (anctrl_isStopped(sp20) != 0) {
            sp24 = 1;
        }
        if (func_8008DD04(arg0) != 0) {
            sp24 = 0x2F;
        }
        break;
    }
    if ((player_isStable(arg0) == 0) && (player_inWater(arg0) != 0)) {
        sp24 = 0x2D;
    }
    if (func_800A1718(arg0) == 0) {
        sp24 = 0x41;
    }
    bs_setState((s32)arg0, sp24);
}

void func_80800274_bssplat(s32 arg0)
{
    func_8008E95C();
    func_8009BD88(arg0);
}
s32 bssplat_entrypoint_1(s32 arg0) {
    extern s32 D_808002B0_bssplat[];
    return ((s32 *)&D_808002B0_bssplat)[arg0];
}
