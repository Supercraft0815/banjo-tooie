#include "common.h"

struct player_state_s;
struct anctrl_s;
enum asset_e;
void bsbshock_entrypoint_0(struct player_state_s *arg0) {
    s32 _bswalk_entrypoint_1();
    struct anctrl_s *baanim_getAnimCtrlPtr(struct player_state_s *);
    void anctrl_reset(struct anctrl_s *);
    void anctrl_setIndex(struct anctrl_s *, enum asset_e);
    void func_8008B1C8(struct anctrl_s *, f32);
    void anctrl_setDuration(struct anctrl_s *, f32);
    void anctrl_setSubrange(struct anctrl_s *, f32, f32);
    void anctrl_setPlaybackType(struct anctrl_s *, s32);
    void anctrl_start(struct anctrl_s *);
    void func_8009FFD8();
    f32 bastick_distance(struct player_state_s *);
    f32 bastick_getAngleRelativeToBanjo(struct player_state_s *);
    void yaw_setIdeal(struct player_state_s *, f32);
    f32 yaw_getIdeal(struct player_state_s *);
    void baphysics_set_target_yaw(struct player_state_s *, f32);
    f32 baphysics_get_target_horizontal_velocity(struct player_state_s *);
    void baphysics_set_horizontal_velocity(struct player_state_s *, f32, f32);
    void func_800A0CE8(struct player_state_s *, s32);
    void func_800A0CF4(struct player_state_s *, s32);
    void func_8009D874(struct player_state_s *);
    u8 func_800C2E04(void);
    void func_800C3418(u8, s32);
    void func_800C2E40(u8);
    void func_800C330C(u8, s32);
    void func_800C301C(u8, s32);
    void func_800C3730(u8, f32, f32, f32);
    void func_80093300(void *, f32);
    void func_8009C1B4(void *, f32);
    struct anctrl_s *animCtrl;
    s32 pad;
    f32 yaw;

    animCtrl = baanim_getAnimCtrlPtr(arg0);
    anctrl_reset(animCtrl);
    anctrl_setIndex(animCtrl, 0x48);
    func_8008B1C8(animCtrl, 0.4f);
    anctrl_setDuration(animCtrl, 4.2f);
    anctrl_setSubrange(animCtrl, 0.0f, 0.1061f);
    anctrl_setPlaybackType(animCtrl, 1);
    anctrl_start(animCtrl);
    func_8009FFD8(arg0, 1, 1, 3, 6);
    if (bastick_distance(arg0) != 0.0f) {
        yaw_setIdeal(arg0, bastick_getAngleRelativeToBanjo(arg0));
    }
    baphysics_set_target_yaw(arg0, yaw_getIdeal(arg0));
    _bswalk_entrypoint_1(arg0);
    yaw = yaw_getIdeal(arg0);
    baphysics_set_horizontal_velocity(arg0, yaw, baphysics_get_target_horizontal_velocity(arg0));
    func_800A0CE8(arg0, 1);
    func_800A0CF4(arg0, 1);
    func_8009D874(arg0);
    *(u8 *)((u8 *)arg0 + 0x164) = func_800C2E04();
    func_800C3418(*(u8 *)((u8 *)arg0 + 0x164), 0);
    func_800C2E40(*(u8 *)((u8 *)arg0 + 0x164));
    func_800C330C(*(u8 *)((u8 *)arg0 + 0x164), 3);
    func_800C301C(*(u8 *)((u8 *)arg0 + 0x164), 0x41D);
    func_800C3730(*(u8 *)((u8 *)arg0 + 0x164), 1.4f, 0.4f, -1.2f);
    func_80093300(arg0, -87.0f);
    func_8009C1B4(arg0, -87.0f);
    *(s32 *)((u8 *)arg0 + 0x15C) = 1;
    *(s32 *)((u8 *)arg0 + 0x160) = 0;
}

void bsbshock_entrypoint_1(struct player_state_s *arg0) {
    s32 _bswalk_entrypoint_1();
    struct anctrl_s *baanim_getAnimCtrlPtr(struct player_state_s *);
    f32 anctrl_getAnimTimer(struct anctrl_s *);
    int anctrl_isAt(struct anctrl_s *, f32);
    s32 anctrl_isStopped(struct anctrl_s *);
    void anctrl_setDuration(struct anctrl_s *, f32);
    void anctrl_setPlaybackType(struct anctrl_s *, s32);
    void anctrl_setSubrange(struct anctrl_s *, f32, f32);
    int bainput_func_80097DF4(struct player_state_s *);
    s32 bainput_should_beak_bust(void *);
    int bakey_released(struct player_state_s *, int);
    void baphysics_reset_gravity(struct player_state_s *);
    void baphysics_set_target_horizontal_velocity(struct player_state_s *, f32);
    void baphysics_set_vertical_velocity(struct player_state_s *, f32);
    void bs_setState(struct player_state_s *, s32);
    int func_8008DF8C(struct player_state_s *, s32);
    s32 func_8008E260(struct player_state_s *);
    void func_8009FC80(struct player_state_s *);
    s32 player_inWater(struct player_state_s *);
    int player_isStable(struct player_state_s *);
    s32 func_8001211C(void);
    void func_8009BB24(void *, f32 *);
    void func_80093300(void *, f32);
    void func_8009C1B4(void *, f32);
    void func_800C3BDC(u8);
    s32 next_state;
    struct anctrl_s *animCtrl;
    f32 velocity[3];

    next_state = 0;
    animCtrl = baanim_getAnimCtrlPtr(arg0);
    if (player_isStable(arg0)) {
        if (func_8001211C() % 2) {
            func_8009FC80(arg0);
        }
    } else {
        func_8009FC80(arg0);
    }
    _bswalk_entrypoint_1(arg0);
    func_8009BB24(arg0, velocity);
    if (bakey_released(arg0, 8) && velocity[1] > 0.0f) {
        baphysics_reset_gravity(arg0);
    }
    switch (*(s32 *)((u8 *)arg0 + 0x160)) {
        case 0:
            if (func_8008E260(arg0)) {
                next_state = 0x3D;
            }
            if (func_8008DF8C(arg0, 0x82)) {
                anctrl_setSubrange(animCtrl, 0.0f, 1.0f);
                anctrl_setDuration(animCtrl, 2.8f);
                anctrl_setPlaybackType(animCtrl, 1);
                *(s32 *)((u8 *)arg0 + 0x160) = 1;
            }
            break;
        case 1:
            if (anctrl_isAt(animCtrl, 0.11f)) {
                func_800C3BDC(*(u8 *)((u8 *)arg0 + 0x164));
            }
            if (anctrl_isAt(animCtrl, 0.4036f)) {
                anctrl_setDuration(animCtrl, 1.4f);
            }
            if (anctrl_isStopped(animCtrl)) {
                next_state = 1;
            }
            break;
    }
    if (func_8008DF8C(arg0, 0x3C)) {
        if (anctrl_getAnimTimer(animCtrl) < 0.3637f && bakey_released(arg0, 8)) {
            *(s32 *)((u8 *)arg0 + 0x15C) = 0;
        }
        if (player_isStable(arg0)) {
            baphysics_set_target_horizontal_velocity(arg0, 0.0f);
        }
    } else {
        if (bainput_func_80097DF4(arg0)) {
            next_state = 0x10;
        }
        if (bainput_should_beak_bust(arg0)) {
            next_state = 0xF;
        }
    }
    if (anctrl_isAt(animCtrl, 0.3637f) && *(s32 *)((u8 *)arg0 + 0x15C)) {
        next_state = 0x22;
    }
    if (anctrl_isAt(animCtrl, 0.4653f)) {
        baphysics_set_vertical_velocity(arg0, 180.0f);
        func_80093300(arg0, 0.0f);
        func_8009C1B4(arg0, 87.0f);
    }
    if (velocity[1] < 0.0f && player_inWater(arg0)) {
        next_state = 0x4C;
    }
    bs_setState(arg0, next_state);
}

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

struct anctrl_s;
enum asset_e;
void bsbshock_entrypoint_4(struct player_state_s *arg0) {
    s32 _bswalk_entrypoint_1();
    struct anctrl_s *baanim_getAnimCtrlPtr(struct player_state_s *);
    void anctrl_reset(struct anctrl_s *);
    void anctrl_setSmoothTransition(struct anctrl_s *, s32);
    void anctrl_setIndex(struct anctrl_s *, enum asset_e);
    void anctrl_setDuration(struct anctrl_s *, f32);
    void anctrl_setStart(struct anctrl_s *, f32);
    void anctrl_setSubrange(struct anctrl_s *, f32, f32);
    void anctrl_setPlaybackType(struct anctrl_s *, s32);
    void anctrl_start(struct anctrl_s *);
    void func_8009FFD8();
    f32 bastick_distance(struct player_state_s *);
    f32 bastick_getAngleRelativeToBanjo(struct player_state_s *);
    void yaw_setIdeal(struct player_state_s *, f32);
    f32 yaw_getIdeal(struct player_state_s *);
    void baphysics_set_target_yaw(struct player_state_s *, f32);
    f32 baphysics_get_target_horizontal_velocity(struct player_state_s *);
    void baphysics_set_horizontal_velocity(struct player_state_s *, f32, f32);
    void baphysics_set_vertical_velocity(struct player_state_s *, f32);
    void baphysics_set_gravity(struct player_state_s *, f32);
    void func_8009DBF0(struct player_state_s *, s32, f32);
    void func_8009DF58(struct player_state_s *, s32, f32);
    void func_800A0CE8(struct player_state_s *, s32);
    void func_800A0CF4(struct player_state_s *, s32);
    void func_800C6DA0(s32);
    void func_80093300(void *, f32);
    void func_8009C1B4(void *, f32);
    struct anctrl_s *animCtrl;
    s32 pad;
    f32 yaw;

    animCtrl = baanim_getAnimCtrlPtr(arg0);
    anctrl_reset(animCtrl);
    anctrl_setSmoothTransition(animCtrl, 0);
    anctrl_setIndex(animCtrl, 0x49);
    anctrl_setDuration(animCtrl, 0.8f);
    anctrl_setStart(animCtrl, 0.6739f);
    anctrl_setSubrange(animCtrl, 0.0f, 1.0f);
    anctrl_setPlaybackType(animCtrl, 1);
    anctrl_start(animCtrl);
    func_8009FFD8(arg0, 1, 1, 3, 6);
    if (bastick_distance(arg0) != 0.0f) {
        yaw_setIdeal(arg0, bastick_getAngleRelativeToBanjo(arg0));
    }
    baphysics_set_target_yaw(arg0, yaw_getIdeal(arg0));
    _bswalk_entrypoint_1(arg0);
    yaw = yaw_getIdeal(arg0);
    baphysics_set_horizontal_velocity(arg0, yaw, baphysics_get_target_horizontal_velocity(arg0));
    baphysics_set_vertical_velocity(arg0, 1250.0f);
    baphysics_set_gravity(arg0, -1200.0f);
    func_8009DBF0(arg0, 0x408, 1.0f);
    func_800A0CE8(arg0, 1);
    func_800A0CF4(arg0, 1);
    func_800C6DA0(0x45);
    func_80093300(arg0, -87.0f);
    func_8009C1B4(arg0, -87.0f);
    func_8009DF58(arg0, 0x43A, 1.0f);
    *(s32 *)((u8 *)arg0 + 0x160) = 0;
}

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
