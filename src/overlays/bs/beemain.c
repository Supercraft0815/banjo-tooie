#include "common.h"

struct player_state_s;
void _babee_entrypoint_2(struct player_state_s *self);
extern s32 _badrone_entrypoint_3(struct player_state_s *self);
extern void _bsdrone_entrypoint_1(struct player_state_s *self);

void func_80800000_bsbeemain(s32 arg0) {
    s32 func_8009DF18(s32, s32, f32, s32);
    func_8009DF18(arg0, 0x41F, 1.4f, 0x1F40);
}

/* extern */

void func_8080002C_bsbeemain(s32 arg0) {
    s32 func_8009D7A4(s32, f32, f32);
    func_8009D7A4(arg0, 1.35f, 1.45f);
}

void func_80800058_bsbeemain(struct player_state_s *arg0) {
    void baphysics_set_target_horizontal_velocity(struct player_state_s *, f32);
    s32 bastick_getZone(struct player_state_s *);
    f32 bastick_getZonePosition(struct player_state_s *);
    f32 func_800F1214(f32, f32, f32);
    f32 sp1C;

    sp1C = bastick_getZonePosition(arg0);
    if (bastick_getZone(arg0) == 0) {
        baphysics_set_target_horizontal_velocity(arg0, 0.0f);
        return;
    }
    baphysics_set_target_horizontal_velocity(arg0, func_800F1214(sp1C, 30.0f, 375.0f));
}

void func_808000C0_bsbeemain(void *arg0) {
    void *self;
    s32 baanim_playForDuration_loopSmooth(void *, s32, s32);
    void baphysics_set_target_horizontal_velocity(struct player_state_s *, f32);
    self = arg0;
    _bsbee_entrypoint_1(self);
    baanim_playForDuration_loopSmooth(self, 0x1DE, 0x40400000);
    func_8009FFD8(self, 1, 1, 1, 2);
    baphysics_set_target_horizontal_velocity(self, 0.0f);
    func_800909CC(self);
}

/* extern */

void func_80800128_bsbeemain(struct player_state_s *arg0) {
    s32 _badrone_entrypoint_24(struct player_state_s *);
    s32 _bsbee_entrypoint_2();
    int bainput_should_enter_first_person(struct player_state_s *);
    int bakey_held(struct player_state_s *, s32);
    int bakey_pressed(struct player_state_s *, s32);
    s32 bastick_getZone(struct player_state_s *);
    s32 bs_setState(s32, s32);
    int func_8008DD04(struct player_state_s *);
    void func_8009D3A8(struct player_state_s *, s32);
    s32 func_800A02DC(struct player_state_s *, s32);
    s32 player_inWater(struct player_state_s *);
    s32 var_s1;

    var_s1 = 0;
    _bsbee_entrypoint_2();
    func_8009D3A8(arg0, 0);
    if (func_8008DD04(arg0) != 0) {
        var_s1 = 0x88;
    }
    if (bakey_held(arg0, 1) != 0) {
        _babee_entrypoint_2(arg0);
    }
    if (bainput_should_enter_first_person(arg0) != 0) {
        var_s1 = _badrone_entrypoint_24(arg0);
    }
    if (bastick_getZone(arg0) > 0) {
        var_s1 = 0x86;
    }
    if (bakey_pressed(arg0, 8) != 0) {
        var_s1 = 0x87;
    }
    if (player_inWater(arg0) != 0) {
        var_s1 = 0x8C;
    }
    bs_setState(arg0, func_800A02DC(arg0, var_s1));
}

void func_808001FC_bsbeemain(s32 arg0)
{
    func_80090A2C();
    _bsbee_entrypoint_0(arg0);
}
s32 bsbeemain_entrypoint_0(s32 arg0) {
    extern s32 D_80801260_bsbeemain[];
    return ((s32 *)&D_80801260_bsbeemain)[arg0];
}

void func_80800238_bsbeemain(struct player_state_s *arg0) {
    s32 baanim_playForDuration_loopSmooth(void *, s32, s32);
    void func_8008C9F0(struct player_state_s *, f32, f32, f32, f32);

    _bsbee_entrypoint_1(arg0);
    baanim_playForDuration_loopSmooth(arg0, 0x1DD, 0x3EC28F5C);
    func_8009FFD8(arg0, 2, 1, 1, 2);
    func_8008C9F0(arg0, 30.0f, 375.0f, 0.6f, 0.4f);
    func_800909CC(arg0);
}

/* extern */

void func_808002C0_bsbeemain(struct player_state_s *arg0) {
    s32 _bsbee_entrypoint_2();
    int bakey_held(struct player_state_s *, s32);
    int bakey_pressed(struct player_state_s *, s32);
    s32 bastick_getZone(struct player_state_s *);
    s32 bs_setState(s32, s32);
    int func_8008DD04(struct player_state_s *);
    s32 func_8009BCD4(struct player_state_s *, f32);
    void func_8009D3A8(struct player_state_s *, s32);
    void func_800A2CE8(struct player_state_s *, f32, s32);
    void func_80800058_bsbeemain(struct player_state_s *);
    s32 player_inWater(struct player_state_s *);
    s32 sp24;

    sp24 = 0;
    _bsbee_entrypoint_2();
    func_8009D3A8(arg0, 0);
    func_80800058_bsbeemain(arg0);
    func_800A2CE8(arg0, 0.94f, 4);
    func_800A2CE8(arg0, 0.44f, 3);
    if (bakey_held(arg0, 1) != 0) {
        _babee_entrypoint_2(arg0);
    }
    if ((bastick_getZone(arg0) == 0) && (func_8009BCD4(arg0, 1.0f) != 0)) {
        sp24 = 0x85;
    }
    if (func_8008DD04(arg0) != 0) {
        sp24 = 0x88;
    }
    if (bakey_pressed(arg0, 8) != 0) {
        sp24 = 0x87;
    }
    if (player_inWater(arg0) != 0) {
        sp24 = 0x8C;
    }
    bs_setState(arg0, sp24);
}

void func_808003B4_bsbeemain(s32 arg0)
{
    func_80090A2C();
    _bsbee_entrypoint_0(arg0);
}
s32 bsbeemain_entrypoint_1(s32 arg0) {
    extern s32 D_80801270_bsbeemain[];
    return ((s32 *)&D_80801270_bsbeemain)[arg0];
}

struct anctrl_s;
void anctrl_reset(struct anctrl_s *);
void anctrl_setIndex(struct anctrl_s *, s32);
void anctrl_setSmoothTransition(struct anctrl_s *, s32);
void anctrl_setStart(struct anctrl_s *, f32);
void anctrl_setDuration(struct anctrl_s *, f32);
void anctrl_setSubrange(struct anctrl_s *, f32, f32);
void anctrl_setPlaybackType(struct anctrl_s *, s32);
void anctrl_start(struct anctrl_s *);
struct anctrl_s *baanim_getAnimCtrlPtr(struct player_state_s *);
void func_808003F0_bsbeemain(struct player_state_s *arg0) {
    f32 bastick_distance(struct player_state_s *);
    f32 bastick_getAngleRelativeToBanjo(struct player_state_s *);
    f32 yaw_getIdeal(struct player_state_s *);
    void yaw_setIdeal(struct player_state_s *, f32);
    void baphysics_set_target_yaw(struct player_state_s *, f32);
    f32 baphysics_get_target_horizontal_velocity(struct player_state_s *);
    void baphysics_set_horizontal_velocity(struct player_state_s *, f32, f32);
    void baphysics_set_vertical_velocity(struct player_state_s *, f32);
    void baphysics_set_gravity(struct player_state_s *, f32);
    s32 pad[2];
    f32 sp2C;
    struct anctrl_s *control;

    control = baanim_getAnimCtrlPtr(arg0);
    _bsbee_entrypoint_1(arg0);
    anctrl_reset(control);
    anctrl_setSmoothTransition(control, 0);
    anctrl_setIndex(control, 0x1E2);
    anctrl_setSubrange(control, 0.0f, 0.34f);
    anctrl_setStart(control, 0.1f);
    anctrl_setDuration(control, 1.2f);
    anctrl_setPlaybackType(control, 1);
    anctrl_start(control);
    func_8009FFD8(arg0, 1, 1, 3, 6);
    if (bastick_distance(arg0) != 0.0f) {
        yaw_setIdeal(arg0, bastick_getAngleRelativeToBanjo(arg0));
    }
    baphysics_set_target_yaw(arg0, yaw_getIdeal(arg0));
    func_80800058_bsbeemain(arg0);
    sp2C = yaw_getIdeal(arg0);
    baphysics_set_horizontal_velocity(arg0, sp2C, baphysics_get_target_horizontal_velocity(arg0));
    baphysics_set_vertical_velocity(arg0, 693.5f);
    baphysics_set_gravity(arg0, -1200.0f);
    func_8080002C_bsbeemain((s32)arg0);
    ((s32 *)arg0)[0x57] = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/beemain/func_80800548_bsbeemain.s")

void func_80800788_bsbeemain(s32 arg0)
{
    _bsbee_entrypoint_0();
    baphysics_reset_gravity(arg0);
}
s32 bsbeemain_entrypoint_2(s32 arg0) {
    extern s32 D_80801280_bsbeemain[];
    return ((s32 *)&D_80801280_bsbeemain)[arg0];
}

void func_808007C4_bsbeemain(struct player_state_s *arg0) {
    struct anctrl_s *baanim_getAnimCtrlPtr(struct player_state_s *);
    void anctrl_reset(struct anctrl_s *);
    void anctrl_setIndex(struct anctrl_s *, s32);
    void anctrl_setStart(struct anctrl_s *, f32);
    void anctrl_setDuration(struct anctrl_s *, f32);
    void anctrl_setSubrange(struct anctrl_s *, f32, f32);
    void anctrl_setPlaybackType(struct anctrl_s *, s32);
    void anctrl_start(struct anctrl_s *);
    struct anctrl_s *control;

    control = baanim_getAnimCtrlPtr(arg0);
    _bsbee_entrypoint_1(arg0);
    anctrl_reset(control);
    anctrl_setIndex(control, 0x1E2);
    anctrl_setStart(control, 0.34f);
    anctrl_setDuration(control, 8.0f);
    anctrl_setSubrange(control, 0.0f, 0.51f);
    anctrl_setPlaybackType(control, 1);
    anctrl_start(control);
    func_8009FFD8(arg0, 1, 1, 3, 6);
    ((s32 *)arg0)[0x57] = 0;
}

void func_80800874_bsbeemain(struct player_state_s *arg0) {
    s32 func_800A02DC(struct player_state_s *, s32);
    s32 player_inWater(struct player_state_s *);
    int player_isStable(struct player_state_s *);
    int func_8008DF8C(struct player_state_s *, s32);
    void func_8009D3A8(struct player_state_s *, s32);
    struct anctrl_s *baanim_getAnimCtrlPtr(struct player_state_s *);
    s32 _badrone_entrypoint_28(struct player_state_s *);
    s32 _bsbee_entrypoint_2();
    s32 anctrl_isStopped(struct anctrl_s *);
    void baanim_setEndAndDuration(struct player_state_s *, f32, f32);
    int baflag_isFalse(struct player_state_s *, s32);
    int baflag_isTrue(struct player_state_s *, s32);
    int bakey_held(struct player_state_s *, s32);
    int bakey_pressed(struct player_state_s *, s32);
    void baphysics_set_target_horizontal_velocity(struct player_state_s *, f32);
    s32 bastick_getZone(struct player_state_s *);
    s32 bs_setState(s32, s32);
    void func_8009BB24(void *, f32 *);
    s32 sp34;
    struct anctrl_s *sp30;
    f32 sp24[3];

    sp34 = 0;
    sp30 = baanim_getAnimCtrlPtr(arg0);
    _bsbee_entrypoint_2(arg0);
    func_8009D3A8(arg0, 0);
    func_80800058_bsbeemain(arg0);
    func_8009BB24(arg0, sp24);
    switch (((s32 *)arg0)[0x57]) {
    case 0:
        if (func_8008DF8C(arg0, 0x82)) {
            baanim_setEndAndDuration(arg0, 0.715f, 0.7f);
            ((s32 *)arg0)[0x57] = 1;
        }
        break;
    case 1:
        func_8009D3A8(arg0, 0);
        if (player_isStable(arg0)) {
            func_80800000_bsbeemain((s32)arg0);
            baphysics_set_target_horizontal_velocity(arg0, 0.0f);
            baanim_setEndAndDuration(arg0, 1.0f, 0.7f);
            ((s32 *)arg0)[0x57] = 2;
        }
        break;
    case 2:
        func_8009D3A8(arg0, 0);
        if (anctrl_isStopped(sp30)) {
            baphysics_set_target_horizontal_velocity(arg0, 0.0f);
            sp34 = 0x85;
        }
        break;
    }
    if (bakey_held(arg0, 1)) {
        _babee_entrypoint_2(arg0);
    }
    if (player_isStable(arg0)) {
        if (baflag_isTrue(arg0, 0x19)) {
            sp34 = _badrone_entrypoint_28(arg0);
        } else {
            if (bastick_getZone(arg0) > 0) {
                sp34 = 0x86;
            }
            if (bakey_pressed(arg0, 8)) {
                sp34 = 0x87;
            }
            sp34 = func_800A02DC(arg0, sp34);
        }
    } else if (baflag_isFalse(arg0, 0xF) && bakey_pressed(arg0, 8)) {
        sp34 = 0x8C;
    }
    if (player_inWater(arg0)) {
        sp34 = 0x8C;
    }
    bs_setState((s32)arg0, sp34);
}

void func_80800A74_bsbeemain()
{
    _bsbee_entrypoint_0();
}

s32 bsbeemain_entrypoint_3(s32 arg0) {
    extern s32 D_80801290_bsbeemain[];
    return ((s32 *)&D_80801290_bsbeemain)[arg0];
}

void bsbeemain_entrypoint_4(s32 arg0)
{
    _babounce_entrypoint_3();
    _bsbee_entrypoint_0(arg0);
}
void _babounce_entrypoint_5(s32, s32, f32);
void bsbeemain_entrypoint_5(s32 arg0) { _bsbee_entrypoint_1(); _babounce_entrypoint_4(arg0, 1); _babounce_entrypoint_5(arg0, 0x1E0, 0.7518f); }

/* extern */

void bsbeemain_entrypoint_6(s32 arg0) {
    s32 _bsbee_entrypoint_2();
    s32 _babounce_entrypoint_9(s32);
    s32 bs_setState(s32, s32);
    s32 sp1C;

    sp1C = 0;
    _bsbee_entrypoint_2();
    if (_babounce_entrypoint_9(arg0) != 0) {
        sp1C = 0x85;
    }
    bs_setState(arg0, sp1C);
}

s32 bsbeemain_entrypoint_7(s32 arg0) {
    extern s32 D_808012A0_bsbeemain[];
    return ((s32 *)&D_808012A0_bsbeemain)[arg0];
}

void func_80800B68_bsbeemain(s32 arg0)
{
    _babounce_entrypoint_3();
    _bsbee_entrypoint_0(arg0);
}
void func_80800B90_bsbeemain(s32 arg0) { _bsbee_entrypoint_1(); _babounce_entrypoint_4(arg0, 2); _babounce_entrypoint_5(arg0, 0x1E0, 0.7518f); }

/* extern */

void func_80800BD0_bsbeemain(s32 arg0) {
    s32 _bsbee_entrypoint_2();
    s32 _babounce_entrypoint_9(s32);
    s32 bs_setState(s32, s32);
    s32 sp1C;

    sp1C = 0;
    _bsbee_entrypoint_2();
    if (_babounce_entrypoint_9(arg0) != 0) {
        sp1C = 0x85;
    }
    bs_setState(arg0, sp1C);
}

s32 bsbeemain_entrypoint_8(s32 arg0) {
    extern s32 D_808012B0_bsbeemain[];
    return ((s32 *)&D_808012B0_bsbeemain)[arg0];
}

void func_80800C28_bsbeemain(struct player_state_s *arg0) {
    void func_8009BFE4(struct player_state_s *, f32, f32);
    void func_8009D820(struct player_state_s *, f32);
    void _basudie_entrypoint_1(struct player_state_s *);
    void _batimer_set(struct player_state_s *, s32, f32);
    void _ncbadie_entrypoint_3(struct player_state_s *, f32);
    f32 baphysics_get_target_horizontal_velocity(struct player_state_s *);
    void baphysics_set_gravity(struct player_state_s *, f32);
    void baphysics_set_horizontal_velocity(struct player_state_s *, f32, f32);
    void baphysics_set_target_horizontal_velocity(struct player_state_s *, f32);
    void baphysics_set_target_yaw(struct player_state_s *, f32);
    void baphysics_set_vertical_velocity(struct player_state_s *, f32);
    f32 func_800136E4(f32);
    void yaw_setIdeal(struct player_state_s *, f32);
    void yaw_applyIdeal(struct player_state_s *);
    struct anctrl_s *sp4C;
    f32 sp48;
    f32 sp3C[3];
    f32 sp30[3];

    sp4C = baanim_getAnimCtrlPtr(arg0);
    if ((*(s32 *)((s8 *)arg0 + 0x160) = func_800EA068(0x40)) != 0) {
        func_800FC660(0x19);
    } else {
        _basudie_entrypoint_1(arg0);
        func_8008E944(arg0);
        func_8009514C(arg0);
        func_800A4DA4(arg0, 0xA);
        _ncbadie_entrypoint_3(func_800A4CA8(arg0), 30.0f);
        func_800A0180(arg0);
    }
    _bsbee_entrypoint_1(arg0);
    anctrl_reset(sp4C);
    anctrl_setSmoothTransition(sp4C, 0);
    anctrl_setIndex(sp4C, 0x1E1);
    anctrl_setSubrange(sp4C, 0.0f, 0.3966f);
    anctrl_setDuration(sp4C, 1.7f);
    anctrl_setPlaybackType(sp4C, 1);
    anctrl_start(sp4C);
    func_8009FFD8(arg0, 1, 1, 2, 3);
    func_8009C128(arg0, sp3C);
    func_800A32C4(arg0, sp30);
    func_800F1E6C(sp30, sp3C, &sp48);
    yaw_setIdeal(arg0, func_800136E4(sp48 + 180.0f));
    yaw_applyIdeal(arg0);
    *(f32 *)((s8 *)arg0 + 0x16C) = 250.0f;
    baphysics_set_target_horizontal_velocity(arg0, 250.0f);
    baphysics_set_target_yaw(arg0, sp48);
    baphysics_set_horizontal_velocity(arg0, sp48, baphysics_get_target_horizontal_velocity(arg0));
    baphysics_set_vertical_velocity(arg0, 420.0f);
    baphysics_set_gravity(arg0, -1200.0f);
    func_8009BFE4(arg0, 1000.0f, 12.0f);
    func_8009D820(arg0, 1.8f);
    _batimer_set(arg0, 0, 2.9f);
    *(s32 *)((s8 *)arg0 + 0x15C) = 0;
}

void func_80800E0C_bsbeemain(struct player_state_s *arg0) {
    s32 _bsbee_entrypoint_2();
    void baphysics_set_target_horizontal_velocity(struct player_state_s *, f32);
    void baphysics_set_vertical_velocity(struct player_state_s *, f32);
    void func_8009D3A8(struct player_state_s *, s32);
    void baanim_setEnd(struct player_state_s *, f32);
    s32 func_8009DF18(s32, s32, f32, s32);
    int player_isStable(struct player_state_s *);
    f32 func_800F0E00(f32, f32);
    s32 _batimer_decrement(void *, s32);
    s32 func_80101180(s32, s32, s32);
    void _basudie_entrypoint_0(struct player_state_s *);
    s32 bs_setState(s32, s32);
    f32 velocity;

    _bsbee_entrypoint_2();
    baphysics_set_target_horizontal_velocity(arg0, *(f32 *)((s8 *)arg0 + 0x16C));
    func_8009D3A8(arg0, 0);
    switch (*(s32 *)((s8 *)arg0 + 0x15C)) {
        case 0:
            if (player_isStable(arg0)) {
                baanim_setEnd(arg0, 0.7453f);
                func_8009DF18(arg0, 0x417, 0.8f, 0x4650);
                func_8009DF18(arg0, 0x428, 1.8f, 0x4650);
                baphysics_set_vertical_velocity(arg0, 400.0f);
                *(s32 *)((s8 *)arg0 + 0x15C) = 1;
            }
            break;
        case 1:
            if (player_isStable(arg0)) {
                baanim_setEnd(arg0, 1.0f);
                func_8009DF18(arg0, 0x417, 0.8f, 0x4650);
                func_8009DF18(arg0, 0x428, 1.8f, 0x4650);
                *(s32 *)((s8 *)arg0 + 0x15C) = 2;
            }
            break;
        case 2:
            *(s32 *)((s8 *)arg0 + 0x15C) = 3;
            break;
        case 3:
            velocity = *(f32 *)((s8 *)arg0 + 0x16C);
            if (velocity > 0.0f) {
                *(f32 *)((s8 *)arg0 + 0x16C) = func_800F0E00(0.0f, velocity - 10.0f);
            }
            break;
    }
    if (_batimer_decrement(arg0, 0)) {
        if (*(s32 *)((s8 *)arg0 + 0x160)) {
            func_80101180(0x2C4, 0x71, *(s32 *)((s8 *)arg0 + 0x184));
        } else {
            _basudie_entrypoint_0(arg0);
        }
    }
    bs_setState(arg0, 0);
}

void func_80800FB8_bsbeemain(s32 arg0) { baphysics_reset_gravity(); func_800A4E30(arg0); func_800951B4(arg0); _bsbee_entrypoint_0(arg0); }

/* extern */

void func_80800FF0_bsbeemain(s32 arg0) {
    s32 _basudie_entrypoint_11(s32);
    s32 bs_setState(s32, s32);
    s32 func_80093370(s32, s32);
    f32 func_80099A34(s32);
    s32 func_8009BDAC(s32, f32);
    s32 func_8009E6EC();
    s32 func_8009E830(s32, s32);
    if (func_8009E6EC() == 0x83) {
        func_8009BDAC(arg0, func_80099A34(arg0));
        func_80093370(arg0, 1);
        bs_setState(arg0, 0x85);
        func_8009E830(arg0, 2);
        return;
    }
    _basudie_entrypoint_11(arg0);
}

s32 bsbeemain_entrypoint_9(s32 arg0) {
    extern s32 D_808012C0_bsbeemain[];
    return ((s32 *)&D_808012C0_bsbeemain)[arg0];
}

void func_80801080_bsbeemain(s32 arg0)
{
    _bsbee_entrypoint_1();
    _bsrest_entrypoint_16(arg0);
}
/* extern */

void func_808010A8_bsbeemain(s32 arg0) {
    s32 _bsbee_entrypoint_2();
    s32 _bsrest_entrypoint_13(s32);
    s32 _bsrest_entrypoint_20(s32);
    s32 bs_setState(s32, s32);
    s32 sp1C;

    sp1C = 0;
    _bsbee_entrypoint_2();
    if (_bsrest_entrypoint_20(arg0) != 0) {
        sp1C = _bsrest_entrypoint_13(arg0);
    }
    bs_setState(arg0, sp1C);
}

void func_808010F4_bsbeemain(s32 arg0)
{
    _bsrest_entrypoint_14();
    _bsbee_entrypoint_0(arg0);
}
s32 bsbeemain_entrypoint_10(s32 arg0) {
    extern s32 D_808012D0_bsbeemain[];
    return ((s32 *)&D_808012D0_bsbeemain)[arg0];
}

void func_80801130_bsbeemain(void *arg0) {
    _bsbee_entrypoint_1(arg0);
    _bsdrone_entrypoint_0(arg0);
    if (_badrone_entrypoint_3(arg0) == 2) {
        _bafpctrl_entrypoint_10(arg0, 1);
        func_800947EC(arg0, 2, 1);
    }
}

/* extern */

void func_8080118C_bsbeemain(struct player_state_s *arg0) {
    s32 _bsbee_entrypoint_2();
    _bsbee_entrypoint_2(arg0);
    _bsdrone_entrypoint_1(arg0);
    if ((_badrone_entrypoint_3(arg0) == 2) && (bakey_held(arg0, 1) != 0)) {
        _babee_entrypoint_2(arg0);
    }
}

void func_808011E8_bsbeemain(s32 arg0) {
    if (_badrone_entrypoint_3(arg0) == 2) {
        func_800947EC(arg0, 2, 0);
    }
    _bsdrone_entrypoint_2(arg0);
    _bsbee_entrypoint_0(arg0);
}

s32 bsbeemain_entrypoint_11(s32 arg0) {
    extern s32 D_808012E0_bsbeemain[];
    return ((s32 *)&D_808012E0_bsbeemain)[arg0];
}
