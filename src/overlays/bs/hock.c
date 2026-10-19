#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/hock/bsbshock_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/hock/bsbshock_entrypoint_1.s")

/* extern */

struct player_state_s;
void bsbshock_entrypoint_2(struct player_state_s *arg0) {
    f32 func_80092BF4(struct player_state_s *);
    void func_80093300(void *, f32);
    void func_8009C1B4(void *, f32);
    void func_800A0CE8(struct player_state_s *, s32);
    void func_800A0CF4(struct player_state_s *, s32);
    s32 func_800C2FDC(u8);
    func_800C2FDC((*(u8 *)((s8 *)(arg0) + (0x164))));
    func_800A0CE8(arg0, 0);
    func_800A0CF4(arg0, 0);
    if (func_80092BF4(arg0) != 0.0f) {
        func_80093300(arg0, 0.0f);
        func_8009C1B4(arg0, 87.0f);
    }
}

s32 bsbshock_entrypoint_3(s32 arg0) {
    extern s32 D_80800870_bsbshock[];
    return ((s32 *)&D_80800870_bsbshock)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/hock/bsbshock_entrypoint_4.s")

void bsbshock_entrypoint_5(struct player_state_s *arg0) {
    s32 _bswalk_entrypoint_1();
    int anctrl_isAt(struct anctrl_s *, f32);
    void anctrl_setDuration(struct anctrl_s *, f32);
    struct anctrl_s *baanim_getAnimCtrlPtr(struct player_state_s *);
    int bainput_func_80097DF4(struct player_state_s *);
    s32 bainput_should_beak_bust(void *);
    int bakey_released(struct player_state_s *, int);
    void baphysics_reset_gravity(struct player_state_s *);
    void bs_setState();
    int func_8008DA24(struct player_state_s *);
    s32 func_8008E260(struct player_state_s *);
    void func_8009BB24(void *, f32 *);
    void func_8009FC80(struct player_state_s *);
    int player_isStable(struct player_state_s *);
    s32 next_state;
    f32 velocity[3];
    struct anctrl_s *animCtrl;

    next_state = 0;
    animCtrl = baanim_getAnimCtrlPtr(arg0);
    _bswalk_entrypoint_1(arg0);
    func_8009BB24(arg0, velocity);
    if (anctrl_isAt(animCtrl, 0.7618f) != 0) {
        anctrl_setDuration(animCtrl, 3.0f);
    }
    if ((bakey_released(arg0, 8) != 0) && (velocity[1] > 0.0f)) {
        baphysics_reset_gravity(arg0);
    }
    if (*(s32 *)((u8 *)arg0 + 0x160) == 0) {
        func_8009FC80(arg0);
        if (velocity[1] < 0.0f) {
            next_state = 0x2F;
        }
    }
    if (player_isStable(arg0) == 0) {
        if (func_8008E260(arg0) != 0) {
            next_state = 0x3D;
        }
        if (bainput_func_80097DF4(arg0) != 0) {
            next_state = 0x10;
        }
        if (bainput_should_beak_bust(arg0) != 0) {
            next_state = 0xF;
        }
        if (func_8008DA24(arg0) != 0) {
            next_state = 0xA8;
        }
    }
    bs_setState(arg0, next_state);
}

/* extern */

struct player_state_s;

void bsbshock_entrypoint_6(struct player_state_s *arg0) {
    void baphysics_reset_gravity(struct player_state_s *);
    s32 bs_getNextState(void *);
    void func_80093300(void *, f32);
    void func_8009C1B4(void *, f32);
    void func_800A0CE8(struct player_state_s *, s32);
    void func_800A0CF4(struct player_state_s *, s32);
    if (bs_getNextState(arg0) != 0x11) {
        baphysics_reset_gravity(arg0);
    }
    func_800A0CE8(arg0, 0);
    func_800A0CF4(arg0, 0);
    func_80093300(arg0, 0.0f);
    func_8009C1B4(arg0, 87.0f);
}

s32 bsbshock_entrypoint_7(s32 arg0) {
    extern s32 D_80800880_bsbshock[];
    return ((s32 *)&D_80800880_bsbshock)[arg0];
}
