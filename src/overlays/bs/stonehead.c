#include "common.h"
#include "overlays/ba/playerstate.h"

void func_80800000_bsstonehead(PlayerState *arg0) {
    void func_80092864(PlayerState *, f32);
    void func_800947EC(PlayerState *, s32, s32);
    void func_80095A40(PlayerState *);
    void func_80095A74(void *, s32);
    s32 func_8009E74C(PlayerState *, s32);
    if (func_8009E74C(arg0, 3) == 0) {
        func_800947EC(arg0, 1, 0);
        func_80095A40(arg0);
        func_80092864(arg0, 1.0f);
        func_80095A74(arg0, 0);
    }
}

void func_80800060_bsstonehead(PlayerState *arg0) {
    void func_80092864(PlayerState *, f32);
    void func_800947EC(PlayerState *, s32, s32);
    void func_800959C8(PlayerState *, f32, f32);
    void func_80095A74(void *, s32);
    s32 func_8009E77C(PlayerState *, s32);
    if (func_8009E77C(arg0, 3) == 0) {
        func_800959C8(arg0, 65.0f, 35.0f);
        func_80092864(arg0, 0.8999939f);
        func_800947EC(arg0, 1, 1);
        func_80095A74(arg0, 1);
    }
}

void func_808000CC_bsstonehead(PlayerState *arg0) {
    s32 _baattach_entrypoint_1(PlayerState *);
    void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
    s32 bastick_getZone(PlayerState *);
    f32 bastick_getZonePosition(PlayerState *);
    s32 func_8008DE24(PlayerState *);
    f32 func_800F1214(f32, f32, f32);
    int player_isStable(PlayerState *);
    f32 sp24;
    f32 sp20;

    sp24 = bastick_getZonePosition(arg0);
    if (_baattach_entrypoint_1(arg0) != 0) {
        sp20 = 250.0f;
    } else if (func_8008DE24(arg0) != 0 && player_isStable(arg0) != 0) {
        sp20 = 80.0f;
    } else {
        sp20 = 400.0f;
    }
    if (bastick_getZone(arg0) == 0) {
        baphysics_set_target_horizontal_velocity(arg0, 0.0f);
    } else {
        baphysics_set_target_horizontal_velocity(arg0, func_800F1214(sp24, 30.0f, sp20));
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/stonehead/func_80800194_bsstonehead.s")

int func_808003B8_bsstonehead(PlayerState *arg0) {
    int bakey_pressed();
    s32 func_800DA298(s32);
    return bakey_pressed(arg0, 8) && !func_800DA298(0x65A);
}

/* extern */

s32 func_808003F4_bsstonehead(PlayerState *arg0, s32 arg1) {
    s32 _badrone_entrypoint_24(PlayerState *);
    int bainput_should_enter_first_person(PlayerState *);
    s32 bastick_getZone();

    if (bainput_should_enter_first_person(arg0) != 0) {
        arg1 = _badrone_entrypoint_24(arg0);
    }
    if (bastick_getZone(arg0) > 0) {
        arg1 = 0xB2;
    }
    if (func_808003B8_bsstonehead(arg0) != 0) {
        arg1 = 0xAE;
    }
    return arg1;
}

void bsstonehead_entrypoint_0(s32 arg0)
{
    func_80800194_bsstonehead(arg0,0);
}

void bsstonehead_entrypoint_1(s32 *arg0) { arg0[87] = 0; func_80800194_bsstonehead(arg0, 1); }

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/stonehead/bsstonehead_entrypoint_2.s")

s32 bsstonehead_entrypoint_3(s32 arg0) {
    extern s32 D_80801630_bsstonehead[];
    return ((s32 *)&D_80801630_bsstonehead)[arg0];
}

struct anctrl_s;
enum asset_e;

void func_808005F0_bsstonehead(PlayerState *arg0, s32 arg1) {
    void _basudie_entrypoint_2(PlayerState *, f32, f32, f32);
    struct anctrl_s *baanim_getAnimCtrlPtr(PlayerState *);
    void baanim_setEnd(PlayerState *, f32);
    void anctrl_reset(struct anctrl_s *);
    void anctrl_setSmoothTransition(struct anctrl_s *, s32);
    void anctrl_setIndex(struct anctrl_s *, enum asset_e);
    void anctrl_setSubrange(struct anctrl_s *, f32, f32);
    void anctrl_setDuration(struct anctrl_s *, f32);
    void anctrl_setPlaybackType(struct anctrl_s *, s32);
    void anctrl_start(struct anctrl_s *);
    void func_8009D820(PlayerState *, f32);
    void func_8009DF94(PlayerState *, s32, f32, s32);
    void func_8009DF18(PlayerState *, s32, f32, s32);
    struct anctrl_s *animCtrl;

    switch (arg1) {
        case 3:
            break;
        case 1:
            animCtrl = baanim_getAnimCtrlPtr(arg0);
            arg0->unk16C = 250.0f;
            _basudie_entrypoint_2(arg0, 250.0f, 420.0f, -1200.0f);
            anctrl_reset(animCtrl);
            anctrl_setSmoothTransition(animCtrl, 0);
            anctrl_setIndex(animCtrl, 0x33);
            anctrl_setSubrange(animCtrl, 0.0f, 0.46f);
            anctrl_setDuration(animCtrl, 2.5f);
            anctrl_setPlaybackType(animCtrl, 1);
            anctrl_start(animCtrl);
            func_8009D820(arg0, 1.8f);
            break;
        case 2:
            baanim_setEnd(arg0, 1.0f);
            func_8009DF94(arg0, 0x417, 0.8f, 0x4650);
            func_8009DF18(arg0, 0x428, 1.8f, 0x4650);
            break;
    }
    arg0->unk15C.word = arg1;
}

/* extern */

void bsstonehead_entrypoint_4(s32 arg0) {
    void func_808005F0_bsstonehead(PlayerState *, s32);
    func_80800060_bsstonehead(arg0);
    (*(s32 *)((s8 *)(arg0) + (0x15C))) = 0;
    func_808005F0_bsstonehead(arg0, 1);
}

void bsstonehead_entrypoint_5(PlayerState *arg0) {
    void _basudie_entrypoint_5(PlayerState *);
    void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
    int player_isStable(PlayerState *);
    f32 func_800F0E00(f32, f32);
    s32 bs_setState(s32, s32);
    f32 velocity;

    _basudie_entrypoint_5(arg0);
    baphysics_set_target_horizontal_velocity(arg0, arg0->unk16C);
    switch (arg0->unk15C.word) {
        case 1:
            if (player_isStable(arg0)) {
                func_808005F0_bsstonehead(arg0, 2);
            }
            break;
        case 2:
            func_808005F0_bsstonehead(arg0, 3);
            break;
        case 3:
            velocity = arg0->unk16C;
            if (velocity > 0.0f) {
                arg0->unk16C = func_800F0E00(0.0f, velocity - 10.0f);
            }
            break;
    }
    bs_setState(arg0, 0);
}

void bsstonehead_entrypoint_6()
{
    _basudie_entrypoint_6();
}

s32 bsstonehead_entrypoint_7(s32 arg0) {
    extern s32 D_80801640_bsstonehead[];
    return ((s32 *)&D_80801640_bsstonehead)[arg0];
}

void bsstonehead_entrypoint_8(PlayerState *arg0)
{
    func_80800060_bsstonehead(arg0);
    _bsdrone_entrypoint_0(arg0);
}
void bsstonehead_entrypoint_9(PlayerState* self)
{
    _bsdrone_entrypoint_1(self);
}
void bsstonehead_entrypoint_10(PlayerState *arg0)
{
    func_80800000_bsstonehead(arg0);
    _bsdrone_entrypoint_2(arg0);
}
s32 bsstonehead_entrypoint_11(s32 arg0) {
    extern s32 D_80801650_bsstonehead[];
    return ((s32 *)&D_80801650_bsstonehead)[arg0];
}

struct anctrl_s;
enum asset_e;
enum baanim_update_type_e;
enum yaw_type_e;
enum ba_physics_type_e;

void func_808008CC_bsstonehead(PlayerState *arg0, s32 arg1)
{
    void func_8009FFD8(PlayerState *, enum baanim_update_type_e, enum yaw_type_e, s32, enum ba_physics_type_e);
    void anctrl_reset(struct anctrl_s *);
    void anctrl_setIndex(struct anctrl_s *, enum asset_e);
    void anctrl_setStart(struct anctrl_s *, f32);
    void anctrl_setSubrange(struct anctrl_s *, f32, f32);
    void anctrl_setDuration(struct anctrl_s *, f32);
    void anctrl_setPlaybackType(struct anctrl_s *, s32);
    void anctrl_start(struct anctrl_s *);
    struct anctrl_s *baanim_getAnimCtrlPtr(PlayerState *);
    void baanim_setEndAndDuration(PlayerState *, f32, f32);
    void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
    void func_800A2E18(PlayerState *);
    struct anctrl_s *control;

    switch (arg1) {
        case 0:
            break;
        case 1:
            control = baanim_getAnimCtrlPtr(arg0);
            anctrl_reset(control);
            anctrl_setIndex(control, 0x122);
            anctrl_setStart(control, 0.6364f);
            anctrl_setSubrange(control, 0.6364f, 0.7576f);
            anctrl_setDuration(control, 4.0f);
            anctrl_setPlaybackType(control, 1);
            anctrl_start(control);
            func_8009FFD8(arg0, 1, 1, 3, 6);
            break;
        case 2:
            baanim_setEndAndDuration(arg0, 1.0f, 0.8f);
            break;
        case 3:
            func_800A2E18(arg0);
            baphysics_set_target_horizontal_velocity(arg0, 0.0f);
            break;
    }
    (*(s32 *)((s8 *)arg0 + 0x15C)) = arg1;
}

void bsstonehead_entrypoint_12(PlayerState *arg0)
{
    func_808008CC_bsstonehead(arg0,0);
    func_80800000_bsstonehead(arg0);
}

void bsstonehead_entrypoint_13(PlayerState *arg0) { func_80800060_bsstonehead(arg0); (*(s32 *)((s8 *)(arg0) + 0x15C)) = 1; func_808008CC_bsstonehead(arg0, 1); }

void bsstonehead_entrypoint_14(PlayerState *arg0) {
    int baanim_isStopped(PlayerState *);
    int player_isStable(PlayerState *);
    int func_8008DF8C(PlayerState *, s32);
    void func_8009D3A8(PlayerState *, s32);
    s32 bs_setState(s32, s32);
    s32 sp24;

    sp24 = 0;
    func_808000CC_bsstonehead(arg0);
    func_8009D3A8(arg0, 0);
    switch (*(s32 *)((s8 *)arg0 + 0x15C)) {
        case 1:
            if (func_8008DF8C(arg0, 0x82)) {
                func_808008CC_bsstonehead(arg0, 2);
            }
            break;
        case 2:
            if (player_isStable(arg0)) {
                func_808008CC_bsstonehead(arg0, 3);
            }
            break;
        case 3:
            if (baanim_isStopped(arg0)) {
                sp24 = 0xB3;
            }
            break;
    }
    if (player_isStable(arg0)) {
        sp24 = func_808003F4_bsstonehead(arg0, sp24);
    }
    bs_setState(arg0, sp24);
}

s32 bsstonehead_entrypoint_15(s32 arg0) {
    extern s32 D_80801660_bsstonehead[];
    return ((s32 *)&D_80801660_bsstonehead)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/stonehead/func_80800B38_bsstonehead.s")

void bsstonehead_entrypoint_16(PlayerState *arg0)
{
    func_80800B38_bsstonehead(arg0,0);
    func_80800000_bsstonehead(arg0);
}

void bsstonehead_entrypoint_17(PlayerState *arg0) { func_80800060_bsstonehead(arg0); (*(s32 *)((s8 *)(arg0) + 0x15C)) = 0; func_80800B38_bsstonehead(arg0, 1); }

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/stonehead/bsstonehead_entrypoint_18.s")

s32 bsstonehead_entrypoint_19(s32 arg0) {
    extern s32 D_80801670_bsstonehead[];
    return ((s32 *)&D_80801670_bsstonehead)[arg0];
}

enum baanim_update_type_e;
enum yaw_type_e;
enum ba_physics_type_e;
void func_800909CC(PlayerState *);
void func_8009FFD8(PlayerState *, enum baanim_update_type_e, enum yaw_type_e, s32, enum ba_physics_type_e);

void bsstonehead_entrypoint_20(PlayerState *arg0) {
    void baanim_playForDuration_loopStartingAt(struct player_state_s *, enum asset_e, f32, f32);
    void func_8008C9F0(PlayerState *, f32, f32, f32, f32);
    func_80800060_bsstonehead(arg0);
    baanim_playForDuration_loopStartingAt(arg0, 0x62, 0.8f, 0.4f);
    func_8009FFD8(arg0, 2, 1, 1, 2);
    func_8008C9F0(arg0, 30.0f, 400.0f, 1.0f, 0.45f);
    func_800909CC(arg0);
}

/* extern */

void bsstonehead_entrypoint_21(PlayerState *arg0) {
    void _baattach_entrypoint_6(PlayerState *, s32, s32, s32);
    s32 _badrone_entrypoint_25(PlayerState *);
    s32 bakey_func_80091940(PlayerState *, s32, s32);
    int bakey_newlyReleased(PlayerState *, s32);
    int bakey_pressed(PlayerState *, s32);
    s32 bastick_getZone(PlayerState *);
    s32 bs_setState(s32, s32);
    int func_8008DD04(PlayerState *);
    int func_8008E148(PlayerState *);
    s32 func_8009BCD4(PlayerState *, f32);
    void func_8009D3A8(PlayerState *, s32);
    void func_800A2CE8(PlayerState *, f32, s32);
    void func_808000CC_bsstonehead(PlayerState *);
    int func_808003B8_bsstonehead(PlayerState *);
    s32 sp24;

    sp24 = 0;
    func_8009D3A8(arg0, 0);
    func_808000CC_bsstonehead(arg0);
    func_800A2CE8(arg0, 0.1f, 4);
    func_800A2CE8(arg0, 0.6f, 3);
    if ((bastick_getZone(arg0) == 0) && (func_8009BCD4(arg0, 1.0f) != 0)) {
        sp24 = 0xB3;
    }
    if (func_8008E148(arg0) != 0) {
        sp24 = _badrone_entrypoint_25(arg0);
    }
    if (func_8008DD04(arg0) != 0) {
        sp24 = 0xAD;
    }
    if (func_808003B8_bsstonehead(arg0) != 0) {
        sp24 = 0xAE;
    }
    if (bakey_pressed(arg0, 9) != 0) {
        sp24 = 0xB4;
    }
    if (bakey_newlyReleased(arg0, 1) != 0) {
        _baattach_entrypoint_6(arg0, 1, bakey_func_80091940(arg0, 1, 1), 0);
    }
    bs_setState(arg0, sp24);
}

void bsstonehead_entrypoint_22(PlayerState *arg0)
{
    func_80800000_bsstonehead(arg0);
    func_80090A2C(arg0);
}
s32 bsstonehead_entrypoint_23(s32 arg0) {
    extern s32 D_80801680_bsstonehead[];
    return ((s32 *)&D_80801680_bsstonehead)[arg0];
}

void bsstonehead_entrypoint_24(PlayerState *arg0)
{
    _baspin_entrypoint_1();
    func_80800000_bsstonehead(arg0);
}
void bsstonehead_entrypoint_25(PlayerState *arg0) { void _baattach_entrypoint_6(PlayerState *, s32, s32, s32); void _baspin_entrypoint_2(PlayerState *, s32, f32, s32, s32); func_80800060_bsstonehead(arg0); _baattach_entrypoint_6(arg0, 3, 0, 0); _baspin_entrypoint_2(arg0, 0x63, 1.8f, 2, 0); }

void bsstonehead_entrypoint_26(s32 arg0) {
    s32 _baspin_entrypoint_3(s32);
    s32 bs_setState(s32, s32);
    s32 var_a1;
    s32 sp1C;

    sp1C = 0;
    var_a1 = sp1C;
    if (_baspin_entrypoint_3(arg0) == 2) {
        var_a1 = 0xB3;
    }
    bs_setState(arg0, var_a1);
}

s32 bsstonehead_entrypoint_27(s32 arg0) {
    extern s32 D_80801690_bsstonehead[];
    return ((s32 *)&D_80801690_bsstonehead)[arg0];
}

void bsstonehead_entrypoint_28(PlayerState *arg0)
{
    _babounce_entrypoint_3();
    func_80800000_bsstonehead(arg0);
}
void bsstonehead_entrypoint_29(PlayerState *arg0) {
    void _baattach_entrypoint_6(PlayerState *, s32, s32, s32);
    void _babounce_entrypoint_4(PlayerState *, s32);
    void _babounce_entrypoint_5(PlayerState *, s32, f32);
    func_80800060_bsstonehead(arg0);
    _baattach_entrypoint_6(arg0, 3, 0, 0);
    _babounce_entrypoint_4(arg0, 2);
    _babounce_entrypoint_5(arg0, 0x122, 0.7518f);
}

/* extern */

void bsstonehead_entrypoint_30(s32 arg0) {
    s32 _babounce_entrypoint_2();
    s32 _babounce_entrypoint_9(s32);
    s32 bs_setState(s32, s32);
    void func_808000CC_bsstonehead(PlayerState *);
    s32 sp1C;

    sp1C = 0;
    if (_babounce_entrypoint_2() != 0) {
        func_808000CC_bsstonehead(arg0);
    }
    if (_babounce_entrypoint_9(arg0) != 0) {
        sp1C = 0xB3;
    }
    bs_setState(arg0, sp1C);
}

s32 bsstonehead_entrypoint_31(s32 arg0) {
    extern s32 D_808016A0_bsstonehead[];
    return ((s32 *)&D_808016A0_bsstonehead)[arg0];
}

void bsstonehead_entrypoint_32(PlayerState *arg0)
{
    _bsrest_entrypoint_14();
    func_80800000_bsstonehead(arg0);
}
void bsstonehead_entrypoint_33(PlayerState *arg0)
{
    func_80800060_bsstonehead(arg0);
    _bsrest_entrypoint_16(arg0);
}
/* extern */

void bsstonehead_entrypoint_34(s32 arg0) {
    s32 _bsrest_entrypoint_13(s32);
    s32 bs_setState(s32, s32);
    s32 _bsrest_entrypoint_20();
    s32 var_a1;
    s32 sp1C;

    sp1C = 0;
    var_a1 = sp1C;
    if (_bsrest_entrypoint_20() != 0) {
        var_a1 = _bsrest_entrypoint_13(arg0);
    }
    bs_setState(arg0, var_a1);
}

s32 bsstonehead_entrypoint_35(s32 arg0) {
    extern s32 D_808016B0_bsstonehead[];
    return ((s32 *)&D_808016B0_bsstonehead)[arg0];
}

void bsstonehead_entrypoint_36(PlayerState *arg0)
{
    func_80800000_bsstonehead(arg0);
}

void bsstonehead_entrypoint_37(PlayerState *arg0) {
    void _batimer_set(PlayerState *, s32, f32);
    void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
    func_80800060_bsstonehead(arg0);
    baanim_playForDuration_loopSmooth(arg0, 0x63, 0x40C33333);
    func_8009FFD8(arg0, 1, 1, 3, 3);
    baphysics_set_target_horizontal_velocity(arg0, 0.0f);
    _batimer_set(arg0, 1, 3.0f);
}

/* extern */

void bsstonehead_entrypoint_38(PlayerState *arg0) {
    s32 _batimer_decrement(void *, s32);
    f32 _batimer_get(void *, s32);
    s32 bs_setState(s32, s32);
    f32 func_800D8FF8(void);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    s32 yaw_applyIdeal(void *);
    f32 yaw_getIdeal(PlayerState *);
    void yaw_setIdeal(PlayerState *, f32);
    s32 sp34;
    f32 sp30;
    f32 sp2C;

    sp34 = 0;
    sp2C = func_800F10B4(_batimer_get(arg0, 1), 0.0f, 3.0f, 30.0f, 800.0f);
    sp30 = func_800D8FF8() * sp2C;
    yaw_setIdeal(arg0, yaw_getIdeal(arg0) + sp30);
    yaw_applyIdeal(arg0);
    if (_batimer_decrement(arg0, 1) != 0) {
        sp34 = 0xB3;
    }
    bs_setState(arg0, sp34);
}

s32 bsstonehead_entrypoint_39(s32 arg0) {
    extern s32 D_808016C0_bsstonehead[];
    return ((s32 *)&D_808016C0_bsstonehead)[arg0];
}

void bsstonehead_entrypoint_40(PlayerState *arg0)
{
    func_80800000_bsstonehead(arg0);
    func_80090A2C(arg0);
}
void bsstonehead_entrypoint_41(PlayerState *arg0) {
    void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
    func_80800060_bsstonehead(arg0);
    baanim_playForDuration_loopSmooth(arg0, 0x63, 0x40C33333);
    func_8009FFD8(arg0, 1, 1, 1, 2);
    baphysics_set_target_horizontal_velocity(arg0, 0.0f);
    func_800909CC(arg0);
}

/* extern */

void bsstonehead_entrypoint_42(PlayerState *arg0) {
    void _baattach_entrypoint_6(PlayerState *, s32, s32, s32);
    s32 _badrone_entrypoint_24(PlayerState *);
    s32 _badrone_entrypoint_25(PlayerState *);
    int bainput_should_enter_first_person(PlayerState *);
    s32 bakey_func_80091940(PlayerState *, s32, s32);
    int bakey_newlyReleased(PlayerState *, s32);
    int bakey_pressed(PlayerState *, s32);
    s32 bs_setState();
    int func_8008DD04(PlayerState *);
    int func_8008E148(PlayerState *);
    s32 func_800A02DC(PlayerState *, s32);
    s32 var_s1;

    var_s1 = 0;
    if (func_8008DD04(arg0) != 0) {
        var_s1 = 0xAD;
    }
    var_s1 = func_808003F4_bsstonehead(arg0, var_s1);
    if (func_8008E148(arg0) != 0) {
        var_s1 = _badrone_entrypoint_25(arg0);
    }
    if (bakey_pressed(arg0, 9) != 0) {
        var_s1 = 0xB4;
    }
    if (bakey_newlyReleased(arg0, 1) != 0) {
        _baattach_entrypoint_6(arg0, 1, bakey_func_80091940(arg0, 1, 1), 0);
    }
    if (bainput_should_enter_first_person(arg0) != 0) {
        var_s1 = _badrone_entrypoint_24(arg0);
    }
    bs_setState(arg0, func_800A02DC(arg0, var_s1));
}

s32 bsstonehead_entrypoint_43(s32 arg0) {
    extern s32 D_808016D0_bsstonehead[];
    return ((s32 *)&D_808016D0_bsstonehead)[arg0];
}
