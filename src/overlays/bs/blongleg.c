#include "bs/blongleg.h"

struct anctrl_s;

s32 func_80800000_bsblongleg(PlayerState* arg0)
{
    return player_inWater(arg0);
}

void func_80800020_bsblongleg(PlayerState *arg0, s32 arg1) {
    void func_8009DE38(PlayerState *, s32, f32);
    if (arg1 != 0) {
        func_8009DE38(arg0, 0x4433, 0.88f);
        return;
    }
    func_8009DE38(arg0, 0x4433, 0.96f);
}

void func_80800064_bsblongleg(PlayerState *arg0) {
    void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
    s32 bastick_getZone(PlayerState *);
    f32 bastick_getZonePosition(PlayerState *);
    f32 func_800F1214(f32, f32, f32);
    f32 sp1C;

    sp1C = bastick_getZonePosition(arg0);
    if (bastick_getZone(arg0) == 0) {
        baphysics_set_target_horizontal_velocity(arg0, 0.0f);
        return;
    }
    baphysics_set_target_horizontal_velocity(arg0, func_800F1214(sp1C, 80.0f, 500.0f));
}

void func_808000C8_bsblongleg(PlayerState *arg0) {
    void _baalarm_entrypoint_3(PlayerState *, f32, f32);
    f32 bastatetimer_get(PlayerState *, int);
    f32 bastatetimer_getPrevious(PlayerState *, int);
    int bastatetimer_isAt(PlayerState *, int, f32);
    void func_8009DE38(PlayerState *, s32, f32);
    f32 sp20[2];

    sp20[0] = bastatetimer_getPrevious(arg0, 2);
    _baalarm_entrypoint_3(arg0, sp20[0], bastatetimer_get(arg0, 2));
    if (bastatetimer_isAt(arg0, 2, 0.01f) != 0) {
        func_8009DE38(arg0, 0x3EB, 1.0f);
    }
}

void func_800931AC(PlayerState *, s32);

void func_8080013C_bsblongleg(PlayerState *arg0) {
    void _baalarm_new(PlayerState *);
    void baflag_set(PlayerState *, s32);
    void baroll_setAngularVelocity(PlayerState *, f32, f32);
    void bastick_setZoneMax(PlayerState *, s32, f32);
    void func_8009BFE4(PlayerState *, f32, f32);
    void func_8009E53C(PlayerState *, s32, f32);
    s32 func_8009E77C(PlayerState *, s32);
    void func_800A0CE8(PlayerState *, s32);
    void func_800A0CF4(PlayerState *, s32);
    void func_800A0DD0(PlayerState *, s32);
    if (func_8009E77C(arg0, 8) == 0) {
        func_8009E53C(arg0, 1, -50.0f);
        bastick_setZoneMax(arg0, 0, 0.03f);
        bastick_setZoneMax(arg0, 1, 1.0f);
        func_800A0CF4(arg0, 1);
        func_800A0CE8(arg0, 1);
        func_800A0DD0(arg0, 1);
        func_8009BFE4(arg0, 1000.0f, 12.0f);
        baroll_setAngularVelocity(arg0, 1000.0f, 12.0f);
        baflag_set(arg0, 3);
        func_800931AC(arg0, 2);
        _baalarm_new(arg0);
    }
}

void baflag_clear(PlayerState *, int);

void func_80800204_bsblongleg(PlayerState *arg0) {
    void _baalarm_free(PlayerState *);
    void _batimer_incrementBy(PlayerState *, s32, f32);
    void baroll_setIdeal(PlayerState *, f32);
    s32 bastatetimer_clear(void *, s32);
    void bastick_resetZones(PlayerState *);
    void func_8009BF5C(PlayerState *, f32);
    void func_8009E53C(PlayerState *, s32, f32);
    s32 func_8009E74C(PlayerState *, s32);
    void func_800A0CE8(PlayerState *, s32);
    void func_800A0CF4(PlayerState *, s32);
    void func_800A0DD0(PlayerState *, s32);
    s32 func_800C77DC(s32);

    if (func_8009E74C(arg0, 8) == 0) {
        _baalarm_free(arg0);
        func_8009E53C(arg0, 1, 0.0f);
        bastick_resetZones(arg0);
        func_800A0CF4(arg0, 0);
        func_800A0CE8(arg0, 0);
        func_800A0DD0(arg0, 0);
        func_800931AC(arg0, 1);
        func_8009BF5C(arg0, 0.0f);
        baroll_setIdeal(arg0, 0.0f);
        bastatetimer_clear(arg0, 2);
        func_800C77DC(1);
        baflag_clear(arg0, 3);
        _batimer_incrementBy(arg0, 4, 0.5f);
        func_808000C8_bsblongleg(arg0);
    }
}

/* extern */

void func_808002D8_bsblongleg(void *arg0) {
    void anctrl_reset(struct anctrl_s *);
    s32 anctrl_setDuration(s32, s32);
    void anctrl_setIndex(struct anctrl_s *, s32);
    void anctrl_setPlaybackType(struct anctrl_s *, s32);
    s32 anctrl_setSmoothTransition(s32, s32);
    void anctrl_start(struct anctrl_s *);
    struct anctrl_s *baanim_getAnimCtrlPtr(PlayerState *);
    s32 bastatetimer_set(void *, s32, f32);
    f32 func_800A3394(void *);
    void func_800C3BDC(u8);
    s32 func_800C77DC(s32);
    s32 temp_v0;

    temp_v0 = baanim_getAnimCtrlPtr(arg0);
    anctrl_reset(temp_v0);
    anctrl_setSmoothTransition(temp_v0, 0);
    anctrl_setIndex(temp_v0, 0x40);
    anctrl_setDuration(temp_v0, 0x3F800000);
    anctrl_setPlaybackType(temp_v0, 1);
    anctrl_start(temp_v0);
    bastatetimer_set(arg0, 2, func_800A3394(arg0));
    func_800C77DC(2);
    func_800C3BDC((*(u8 *)((s8 *)(arg0) + (0x160))));
    (*(s32 *)((s8 *)(arg0) + (0x15C))) = 1;
}

/* extern */

void func_80800378_bsblongleg(void *arg0) {
    void anctrl_reset(struct anctrl_s *);
    s32 anctrl_setDuration(s32, s32);
    void anctrl_setIndex(struct anctrl_s *, s32);
    void anctrl_setPlaybackType(struct anctrl_s *, s32);
    s32 anctrl_setSmoothTransition(s32, s32);
    void anctrl_start(struct anctrl_s *);
    struct anctrl_s *baanim_getAnimCtrlPtr();
    s32 temp_v0;

    temp_v0 = baanim_getAnimCtrlPtr();
    anctrl_reset(temp_v0);
    anctrl_setSmoothTransition(temp_v0, 0);
    anctrl_setIndex(temp_v0, 0x16);
    anctrl_setDuration(temp_v0, 0x3F000000);
    anctrl_setPlaybackType(temp_v0, 1);
    anctrl_start(temp_v0);
    (*(s32 *)((s8 *)(arg0) + (0x15C))) = 0;
}

void bsblongleg_entrypoint_0(PlayerState *arg0) {
    void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
    s32 bs_getPreviousState(PlayerState *);
    s32 func_8009CA70(PlayerState *, s32, s32);
    void func_8009D874(PlayerState *);
    void func_8009FFD8(PlayerState *, s32, s32, s32, s32);
    s32 func_800C2E04(void);
    void func_800C301C(u8, s32);
    void func_800C330C(u8, s32);
    void func_800C3730(u8, f32, f32, f32);
    s32 temp_v0;

    temp_v0 = func_800C2E04();
    arg0->unk160.bytes[0] = temp_v0;
    func_800C301C(temp_v0, 0x41D);
    func_800C330C(arg0->unk160.bytes[0], 3);
    func_800C3730(arg0->unk160.bytes[0], 0.8f, 1.9f, 1.2f);
    baflag_clear(arg0, 0xE);
    if (func_8009CA70(arg0, bs_getPreviousState(arg0), 0x40) != 0) {
        func_808002D8_bsblongleg(arg0);
    } else {
        func_80800378_bsblongleg(arg0);
    }
    func_8009FFD8(arg0, 1, 1, 3, 2);
    baphysics_set_target_horizontal_velocity(arg0, 0.0f);
    func_8080013C_bsblongleg(arg0);
    func_8009D874(arg0);
}

void bsblongleg_entrypoint_1(PlayerState *arg0) {
    struct anctrl_s *baanim_getAnimCtrlPtr(PlayerState *);
    s32 anctrl_isStopped(struct anctrl_s *);
    void bs_setState(PlayerState *, int);
    void func_8009D2F0(PlayerState *, s32, f32);
    s32 next_state;
    struct anctrl_s *anim_ctrl;

    next_state = 0;
    anim_ctrl = baanim_getAnimCtrlPtr(arg0);
    func_808000C8_bsblongleg(arg0);
    func_8009D2F0(arg0, 1, 0.5f);
    switch (arg0->unk15C.word) {
        case 0:
            if (anctrl_isStopped(anim_ctrl)) {
                func_808002D8_bsblongleg(arg0);
            }
            break;
        case 1:
            if (anctrl_isStopped(anim_ctrl)) {
                next_state = 0x26;
            }
            break;
    }
    bs_setState(arg0, next_state);
}

void bsblongleg_entrypoint_2(void *arg0) { func_80800204_bsblongleg(arg0); func_800C2FDC((*(u8 *)((s8 *)(arg0) + 0x160))); }

s32 bsblongleg_entrypoint_3(s32 arg0) {
    extern s32 D_80801470_bsblongleg[];
    return ((s32 *)&D_80801470_bsblongleg)[arg0];
}

void bsblongleg_entrypoint_4(PlayerState *arg0) {
    void baanim_playForDuration_loopSmooth(PlayerState *, s32, f32);
    void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
    void func_8009FFD8(PlayerState *, s32, s32, s32, s32);
    void func_800931AC(PlayerState *, s32);
    baanim_playForDuration_loopSmooth(arg0, 0x41, 1.0f);
    func_8009FFD8(arg0, 1, 1, 1, 2);
    baphysics_set_target_horizontal_velocity(arg0, 0.0f);
    func_800931AC(arg0, 2);
    func_8080013C_bsblongleg(arg0);
}

void bsblongleg_entrypoint_5(PlayerState *arg0) {
    s32 _badrone_entrypoint_24(PlayerState *);
    s32 bainput_should_enter_first_person();
    int bakey_pressed(PlayerState *, int);
    s32 bastatetimer_clear(void *, s32);
    s32 bastatetimer_isDone();
    s32 bastick_getZone(PlayerState *);
    void bs_setState(PlayerState *, int);
    int func_8008DF18(PlayerState *);
    void func_8009D2F0(PlayerState *, s32, f32);
    s32 var_s1;

    var_s1 = 0;
    func_808000C8_bsblongleg(arg0);
    func_8009D2F0(arg0, 1, 0.5f);
    if (bainput_should_enter_first_person(arg0) != 0) {
        var_s1 = _badrone_entrypoint_24(arg0);
    }
    if (bakey_pressed(arg0, 9) != 0) {
        bastatetimer_clear(arg0, 2);
    }
    if (bastick_getZone(arg0) > 0) {
        var_s1 = 0x27;
    }
    if (func_8008DF18(arg0) != 0) {
        var_s1 = 0x55;
    }
    if ((bakey_pressed(arg0, 8) != 0) && (player_isStable(arg0) != 0)) {
        var_s1 = 0x28;
    }
    if (bastatetimer_isDone(arg0, 2) != 0) {
        var_s1 = 0x29;
    }
    if (func_80800000_bsblongleg(arg0) != 0) {
        var_s1 = 0x4C;
    }
    bs_setState(arg0, var_s1);
}

void bsblongleg_entrypoint_6(PlayerState *arg0)
{
    func_80800204_bsblongleg(arg0);
}

s32 bsblongleg_entrypoint_7(s32 arg0) {
    extern s32 D_80801480_bsblongleg[];
    return ((s32 *)&D_80801480_bsblongleg)[arg0];
}

/* extern */

void bsblongleg_entrypoint_8(PlayerState *arg0) {
    void anctrl_reset(struct anctrl_s *);
    void anctrl_setIndex(struct anctrl_s *, s32);
    void anctrl_setPlaybackType(struct anctrl_s *, s32);
    void anctrl_start(struct anctrl_s *);
    struct anctrl_s *baanim_getAnimCtrlPtr();
    s32 func_8008C9F0(s32, s32, s32, s32, f32);
    void func_8009FFD8(PlayerState *, s32, s32, s32, s32);
    s32 sp24;
    s32 temp_v0;

    temp_v0 = baanim_getAnimCtrlPtr();
    sp24 = temp_v0;
    anctrl_reset(temp_v0);
    anctrl_setIndex(sp24, 0x42);
    anctrl_setPlaybackType(sp24, 2);
    anctrl_start(sp24);
    func_8009FFD8(arg0, 2, 1, 1, 2);
    func_8008C9F0(arg0, 0x42A00000, 0x43FA0000, 0x3F800000, 0.8f);
}

void bsblongleg_entrypoint_9(PlayerState *arg0) {
    int anctrl_isAt(struct anctrl_s *, f32);
    struct anctrl_s *baanim_getAnimCtrlPtr(PlayerState *);
    int bakey_pressed(PlayerState *, int);
    f32 baphysics_get_target_horizontal_velocity(PlayerState *);
    s32 bastatetimer_clear(void *, s32);
    s32 bastatetimer_isDone();
    s32 bastick_getZone(PlayerState *);
    void bs_setState(PlayerState *, int);
    int func_8008DF18(PlayerState *);
    s32 func_8009BCD4(PlayerState *, f32);
    void func_8009D2F0(PlayerState *, s32, f32);
    void func_800A2CE8(PlayerState *, f32, s32);
    int player_isStable(PlayerState *);
    s32 sp24;
    struct anctrl_s *sp20;

    sp24 = 0;
    sp20 = baanim_getAnimCtrlPtr(arg0);
    func_808000C8_bsblongleg(arg0);
    func_8009D2F0(arg0, 1, 0.5f);
    func_800A2CE8(arg0, 0.47f, 4);
    func_800A2CE8(arg0, 0.97f, 3);
    if (anctrl_isAt(sp20, 0.7781f)) {
        func_80800020_bsblongleg(arg0, 0);
    }
    if (anctrl_isAt(sp20, 0.2781f)) {
        func_80800020_bsblongleg(arg0, 1);
    }
    func_80800064_bsblongleg(arg0);
    if (bakey_pressed(arg0, 9) && baphysics_get_target_horizontal_velocity(arg0) == 0.0f) {
        bastatetimer_clear(arg0, 2);
    }
    if (bastick_getZone(arg0) == 0 && func_8009BCD4(arg0, 1.0f)) {
        sp24 = 0x26;
    }
    if (func_8008DF18(arg0)) {
        sp24 = 0x55;
    }
    if (bakey_pressed(arg0, 8) && player_isStable(arg0)) {
        sp24 = 0x28;
    }
    if (bastatetimer_isDone(arg0, 2)) {
        sp24 = 0x29;
    }
    if (func_80800000_bsblongleg(arg0)) {
        sp24 = 0x4C;
    }
    bs_setState(arg0, sp24);
}

void bsblongleg_entrypoint_10(PlayerState *arg0)
{
    func_80800204_bsblongleg(arg0);
}

s32 bsblongleg_entrypoint_11(s32 arg0) {
    extern s32 D_80801490_bsblongleg[];
    return ((s32 *)&D_80801490_bsblongleg)[arg0];
}

/* extern */

void func_80800994_bsblongleg(void *arg0) {
    void anctrl_reset(struct anctrl_s *);
    s32 anctrl_setDuration(s32, s32);
    void anctrl_setIndex(struct anctrl_s *, s32);
    void anctrl_setPlaybackType(struct anctrl_s *, s32);
    s32 anctrl_setSmoothTransition(s32, s32);
    void anctrl_start(struct anctrl_s *);
    struct anctrl_s *baanim_getAnimCtrlPtr();
    s32 func_8008B188(s32, s32);
    s32 temp_v0;

    temp_v0 = baanim_getAnimCtrlPtr();
    anctrl_reset(temp_v0);
    anctrl_setSmoothTransition(temp_v0, 0);
    func_8008B188(temp_v0, 0);
    anctrl_setIndex(temp_v0, 0x40);
    anctrl_setDuration(temp_v0, 0x3ECCCCCD);
    anctrl_setPlaybackType(temp_v0, 1);
    anctrl_start(temp_v0);
    (*(s32 *)((s8 *)(arg0) + (0x15C))) = 0;
}

/* extern */

void func_80800A18_bsblongleg(void *arg0) {
    void anctrl_reset(struct anctrl_s *);
    s32 anctrl_setDuration(s32, s32);
    void anctrl_setIndex(struct anctrl_s *, s32);
    void anctrl_setPlaybackType(struct anctrl_s *, s32);
    s32 anctrl_setSmoothTransition(s32, s32);
    void anctrl_start(struct anctrl_s *);
    struct anctrl_s *baanim_getAnimCtrlPtr();
    s32 temp_v0;

    temp_v0 = baanim_getAnimCtrlPtr();
    anctrl_reset(temp_v0);
    anctrl_setSmoothTransition(temp_v0, 0);
    anctrl_setIndex(temp_v0, 7);
    anctrl_setDuration(temp_v0, 0x3E99999A);
    anctrl_setPlaybackType(temp_v0, 1);
    anctrl_start(temp_v0);
    (*(s32 *)((s8 *)(arg0) + (0x15C))) = 1;
}

void bsblongleg_entrypoint_12(PlayerState *arg0) {
    void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
    s32 func_8008CA4C(void *, s32);
    void func_8009D2D8(PlayerState *, s32);
    s32 func_800C2E04(void);
    void func_800C301C(u8, s32);
    void func_800C330C(u8, s32);
    void func_800C3730(u8, f32, f32, f32);
    u8 index;

    func_80800994_bsblongleg(arg0);
    func_8008CA4C(arg0, 1);
    func_8009D2D8(arg0, 2);
    baphysics_set_target_horizontal_velocity(arg0, 0.0f);
    index = func_800C2E04();
    *(u8 *)((s8 *)arg0 + 0x160) = index;
    func_800C301C(index, 0x41D);
    func_800C330C(*(u8 *)((s8 *)arg0 + 0x160), 3);
    func_800C3730(*(u8 *)((s8 *)arg0 + 0x160), 1.4f, 0.4f, -1.2f);
}

void bsblongleg_entrypoint_13(PlayerState *arg0) {
    struct anctrl_s *baanim_getAnimCtrlPtr(PlayerState *);
    int anctrl_isAt(struct anctrl_s *, f32);
    s32 anctrl_isStopped(struct anctrl_s *);
    void func_8009D3A8(PlayerState *, s32);
    void func_800C3BDC(u8);
    void bs_setState(PlayerState *, int);
    s32 next_state;
    struct anctrl_s *anim_ctrl;

    next_state = 0;
    anim_ctrl = baanim_getAnimCtrlPtr(arg0);
    func_8009D3A8(arg0, 1);
    switch (*(s32 *)((s8 *)arg0 + 0x15C)) {
        case 0:
            if (anctrl_isAt(anim_ctrl, 0.68f)) {
                func_800C3BDC(*(u8 *)((s8 *)arg0 + 0x160));
            }
            if (anctrl_isStopped(anim_ctrl)) {
                func_80800A18_bsblongleg(arg0);
            }
            break;
        case 1:
            if (anctrl_isStopped(anim_ctrl)) {
                next_state = 1;
            }
            break;
    }
    if (func_80800000_bsblongleg(arg0)) {
        next_state = 0x4C;
    }
    bs_setState(arg0, next_state);
}

void bsblongleg_entrypoint_14(void *arg0) { func_800C2FDC((*(u8 *)((s8 *)(arg0) + 0x160))); func_80800204_bsblongleg(arg0); }

s32 bsblongleg_entrypoint_15(s32 arg0) {
    extern s32 D_808014A0_bsblongleg[];
    return ((s32 *)&D_808014A0_bsblongleg)[arg0];
}

void bsblongleg_entrypoint_16(PlayerState *arg0) {
    void anctrl_reset(struct anctrl_s *);
    s32 anctrl_setDuration(s32, s32);
    void anctrl_setIndex(struct anctrl_s *, s32);
    void anctrl_setPlaybackType(struct anctrl_s *, s32);
    void anctrl_setStart(struct anctrl_s *, f32);
    void anctrl_setSubrange(struct anctrl_s *, f32, f32);
    void anctrl_start(struct anctrl_s *);
    struct anctrl_s *baanim_getAnimCtrlPtr(PlayerState *);
    void func_8008B1C8(struct anctrl_s *, f32);
    f32 baphysics_get_target_horizontal_velocity(PlayerState *);
    void baphysics_set_gravity(PlayerState *, f32);
    void baphysics_set_horizontal_velocity(PlayerState *, f32, f32);
    void baphysics_set_target_yaw(PlayerState *, f32);
    void baphysics_set_vertical_velocity(PlayerState *, f32);
    f32 bastick_distance(PlayerState *);
    f32 bastick_getAngleRelativeToBanjo(PlayerState *);
    f32 yaw_getIdeal(PlayerState *);
    void yaw_setIdeal(PlayerState *, f32);
    void func_8009FFD8(PlayerState *, s32, s32, s32, s32);
    void func_8009DE38(PlayerState *, s32, f32);
    s32 pad[2];
    f32 yaw;
    struct anctrl_s *control;

    control = baanim_getAnimCtrlPtr(arg0);
    arg0->unk16C = 0.14f;
    anctrl_reset(control);
    anctrl_setIndex(control, 0x3D);
    func_8008B1C8(control, 0.134f);
    anctrl_setDuration(control, 0x3F800000);
    anctrl_setStart(control, arg0->unk16C);
    anctrl_setSubrange(control, 0.0f, 0.42f);
    anctrl_setPlaybackType(control, 1);
    anctrl_start(control);
    func_8009FFD8(arg0, 1, 1, 3, 6);
    if (bastick_distance(arg0) != 0.0f) {
        yaw_setIdeal(arg0, bastick_getAngleRelativeToBanjo(arg0));
    }
    baphysics_set_target_yaw(arg0, yaw_getIdeal(arg0));
    func_80800064_bsblongleg(arg0);
    yaw = yaw_getIdeal(arg0);
    baphysics_set_horizontal_velocity(arg0, yaw, baphysics_get_target_horizontal_velocity(arg0));
    baphysics_set_vertical_velocity(arg0, 400.0f);
    baphysics_set_gravity(arg0, -800.0f);
    func_8009DE38(arg0, 0x4432, 0.9f);
    arg0->unk15C.word = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/blongleg/bsblongleg_entrypoint_17.s")

void bsblongleg_entrypoint_18(s32 arg0)
{
    baphysics_reset_gravity();
    func_80800204_bsblongleg(arg0);
}
s32 bsblongleg_entrypoint_19(s32 arg0) {
    extern s32 D_808014B0_bsblongleg[];
    return ((s32 *)&D_808014B0_bsblongleg)[arg0];
}

void bsblongleg_entrypoint_20(PlayerState *arg0) {
    void anctrl_reset(struct anctrl_s *);
    void anctrl_setIndex(struct anctrl_s *, s32);
    void anctrl_setPlaybackType(struct anctrl_s *, s32);
    void anctrl_start(struct anctrl_s *);
    struct anctrl_s *baanim_getAnimCtrlPtr(PlayerState *);
    void _batimer_set(PlayerState *, s32, f32);
    void anctrl_setStart(struct anctrl_s *, f32);
    f32 yaw_getIdeal(PlayerState *);
    f32 baphysics_get_target_horizontal_velocity(PlayerState *);
    void baphysics_set_target_yaw(PlayerState *, f32);
    void baphysics_set_horizontal_velocity(PlayerState *, f32, f32);
    void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
    void baroll_setAngularVelocity(PlayerState *, f32, f32);
    void func_8009BFE4(PlayerState *, f32, f32);
    void func_8009D658(PlayerState *);
    void func_8009FFD8(PlayerState *, s32, s32, s32, s32);
    void func_800A0CE8(PlayerState *, s32);
    void func_800A0CF4(PlayerState *, s32);
    struct anctrl_s *anim_ctrl;
    f32 velocity;
    f32 yaw;

    anim_ctrl = baanim_getAnimCtrlPtr(arg0);
    anctrl_reset(anim_ctrl);
    anctrl_setIndex(anim_ctrl, 0x3D);
    anctrl_setPlaybackType(anim_ctrl, 3);
    anctrl_setStart(anim_ctrl, 0.0865f);
    anctrl_start(anim_ctrl);
    func_8009FFD8(arg0, 1, 1, 3, 3);
    baphysics_set_target_yaw(arg0, yaw_getIdeal(arg0));
    yaw = yaw_getIdeal(arg0);
    velocity = baphysics_get_target_horizontal_velocity(arg0);
    baphysics_set_horizontal_velocity(arg0, yaw, velocity);
    func_800A0CF4(arg0, 1);
    func_800A0CE8(arg0, 1);
    func_8009BFE4(arg0, 1000.0f, 12.0f);
    baroll_setAngularVelocity(arg0, 1000.0f, 12.0f);
    baphysics_set_target_horizontal_velocity(arg0, 0.0f);
    func_8009D658(arg0);
    _batimer_set(arg0, 0, 1.0f);
    func_8080013C_bsblongleg(arg0);
}

void bsblongleg_entrypoint_21(PlayerState *arg0) {
    void _badust_entrypoint_1(PlayerState *);
    void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
    s32 _batimer_decrement(void *, s32);
    int _batimer_isZero(PlayerState *, s32);
    int bakey_pressed(PlayerState *, int);
    void bs_setState(PlayerState *, int);
    int func_8008E148(PlayerState *);
    void func_800963C0(PlayerState *, f32 *);
    f32 func_8009BFD8(PlayerState *);
    void func_8009D2F0(PlayerState *, s32, f32);
    void func_8009D658(PlayerState *);
    void baphysics_set_target_yaw(PlayerState *, f32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    int func_800F1EA4(f32 *, f32 *);
    s32 sp44;
    f32 sp38[3];
    f32 sp34;

    sp44 = 0;
    func_808000C8_bsblongleg(arg0);
    func_8009D658(arg0);
    _batimer_decrement(arg0, 0);
    if (func_8008E148(arg0) != 0) {
        func_800963C0(arg0, sp38);
        func_800F1EA4(sp38, &sp34);
        func_8009D2F0(arg0, 1, 0.5f);
        baphysics_set_target_horizontal_velocity(arg0, func_800F10B4(func_8009BFD8(arg0), 20.0f, 60.0f, 550.0f, 700.0f));
        baphysics_set_target_yaw(arg0, sp34);
        _badust_entrypoint_1(arg0);
    } else {
        sp44 = 0x26;
    }
    if ((_batimer_isZero(arg0, 0) != 0) && (bakey_pressed(arg0, 8) != 0)) {
        sp44 = 0x28;
    }
    if (func_80800000_bsblongleg(arg0) != 0) {
        sp44 = 0x4C;
    }
    bs_setState(arg0, sp44);
}

void bsblongleg_entrypoint_22(PlayerState *arg0)
{
    func_80800204_bsblongleg(arg0);
}

s32 bsblongleg_entrypoint_23(s32 arg0) {
    extern s32 D_808014C0_bsblongleg[];
    return ((s32 *)&D_808014C0_bsblongleg)[arg0];
}

void bsblongleg_entrypoint_24(s32 arg0)
{
    _bsrest_entrypoint_14();
    func_80800204_bsblongleg(arg0);
}
void bsblongleg_entrypoint_25(PlayerState *arg0)
{
    func_8080013C_bsblongleg(arg0);
    _bsrest_entrypoint_16(arg0);
}
void bsblongleg_entrypoint_26(PlayerState *arg0) {
    s32 _bsrest_entrypoint_13(PlayerState *);
    s32 _bsrest_entrypoint_20(PlayerState *);
    void bs_setState(PlayerState *, int);
    void func_8009D3A8(PlayerState *, s32);
    void func_808000C8_bsblongleg(PlayerState *);
    s32 sp24;

    sp24 = 0;
    func_808000C8_bsblongleg(arg0);
    func_8009D3A8(arg0, 1);
    if (_bsrest_entrypoint_20(arg0) != 0) {
        sp24 = _bsrest_entrypoint_13(arg0);
    }
    bs_setState(arg0, sp24);
}

s32 bsblongleg_entrypoint_27(s32 arg0) {
    extern s32 D_808014D0_bsblongleg[];
    return ((s32 *)&D_808014D0_bsblongleg)[arg0];
}

void bsblongleg_entrypoint_28(PlayerState *arg0)
{
    func_8080013C_bsblongleg(arg0);
    _bsdrone_entrypoint_0(arg0);
}
/* extern */

void bsblongleg_entrypoint_29(PlayerState *arg0) {
    s32 _bsdrone_entrypoint_1(s32);
    s32 bastatetimer_isDone(s32, s32);
    void bs_setState(PlayerState *, int);
    void func_808000C8_bsblongleg(PlayerState *);
    func_808000C8_bsblongleg(arg0);
    _bsdrone_entrypoint_1(arg0);
    if (bastatetimer_isDone(arg0, 2) != 0) {
        bs_setState(arg0, 0x29);
    }
}

void bsblongleg_entrypoint_30(s32 arg0)
{
    _bsdrone_entrypoint_2();
    func_80800204_bsblongleg(arg0);
}
s32 bsblongleg_entrypoint_31(s32 arg0) {
    extern s32 D_808014E0_bsblongleg[];
    return ((s32 *)&D_808014E0_bsblongleg)[arg0];
}
