#include "common.h"

struct anctrl_s;

/* extern */

f32 func_80800000_bssnowball(s32 arg0) {
    f32 _basnowball_entrypoint_3();
    s32 func_8008C990(s32, f32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    f32 func_800F13C4(f32, f32);
    f32 sp20;
    f32 temp_f0;

    temp_f0 = func_800F13C4(func_800F10B4(_basnowball_entrypoint_3(), 0.0f, 360.0f, 0.0f, 1.0f), 1.0f);
    sp20 = temp_f0;
    func_8008C990(arg0, temp_f0);
    return temp_f0;
}

struct player_state_s;
void func_80800064_bssnowball(struct player_state_s *arg0, s32 arg1) {
    void _basnowball_entrypoint_7(struct player_state_s *);
    int bakey_held(struct player_state_s *, s32);
    void baphysics_set_target_horizontal_velocity(struct player_state_s *, f32);
    s32 bastick_getZone(struct player_state_s *);
    f32 bastick_getZonePosition(struct player_state_s *);
    f32 func_800F1214(f32, f32, f32);
    f32 sp24;

    sp24 = bastick_getZonePosition(arg0);
    if ((arg1 != 0) && (bakey_held(arg0, 9) != 0)) {
        baphysics_set_target_horizontal_velocity(arg0, 1400.0f);
        _basnowball_entrypoint_7(arg0);
        return;
    }
    if (bastick_getZone(arg0) == 0) {
        baphysics_set_target_horizontal_velocity(arg0, 0.0f);
        return;
    }
    baphysics_set_target_horizontal_velocity(arg0, func_800F1214(sp24, 30.0f, 700.0f));
}

/* extern */

s32 func_8080010C_bssnowball(s32 arg0, s32 arg1) {
    s32 _badrone_entrypoint_24(s32);
    s32 bainput_should_enter_first_person();
    s32 bakey_pressed(s32, s32);
    if (bainput_should_enter_first_person() != 0) {
        arg1 = _badrone_entrypoint_24(arg0);
    }
    if (bakey_pressed(arg0, 8) != 0) {
        arg1 = 0x17F;
    }
    return arg1;
}

/* extern */

void func_80800164_bssnowball(s32 arg0) {
    s32 yaw_setUpdateType(s32, s32);
    s32 yaw_setVelocityBounded(s32, s32, s32);
    yaw_setUpdateType(arg0, 3);
    yaw_setVelocityBounded(arg0, 0x43960000, 0x40C00000);
}

typedef struct player_state_s PlayerState;

void bssnowball_entrypoint_0(PlayerState *arg0) {
    void _basnowball_entrypoint_1(PlayerState *);
    void baflag_clear(PlayerState *, s32);
    void baroll_resetAngularVelocity(PlayerState *);
    void baroll_setIdeal(PlayerState *, f32);
    void bastick_popZone(PlayerState *);
    void func_80092864(PlayerState *, f32);
    void func_800947EC(PlayerState *, s32, s32);
    void func_8009BF5C(PlayerState *, f32);
    void func_8009C000(PlayerState *);
    s32 func_8009E74C(PlayerState *, s32);
    if (func_8009E74C(arg0, 0x16) == 0) {
        func_800947EC(arg0, 1, 0);
        func_8009BF5C(arg0, 0.0f);
        baroll_setIdeal(arg0, 0.0f);
        func_8009C000(arg0);
        baroll_resetAngularVelocity(arg0);
        bastick_popZone(arg0);
        baflag_clear(arg0, 3);
        baflag_clear(arg0, 4);
        _basnowball_entrypoint_1(arg0);
        func_80092864(arg0, 1.0f);
    }
}

void bssnowball_entrypoint_1(PlayerState *arg0) {
    void _basnowball_entrypoint_2(PlayerState *);
    void baflag_set(PlayerState *, s32);
    void baroll_setAngularVelocity(PlayerState *, f32, f32);
    void bastick_pushZone(PlayerState *);
    void bastick_setZoneMax(PlayerState *, s32, f32);
    void func_80092864(PlayerState *, f32);
    void func_800947EC(PlayerState *, s32, s32);
    void func_8009BFE4(PlayerState *, f32, f32);
    s32 func_8009E77C(PlayerState *, s32);
    if (func_8009E77C(arg0, 0x16) == 0) {
        _basnowball_entrypoint_2(arg0);
        func_8009BFE4(arg0, 1000.0f, 12.0f);
        baroll_setAngularVelocity(arg0, 1000.0f, 12.0f);
        bastick_pushZone(arg0);
        bastick_setZoneMax(arg0, 0, 0.12f);
        bastick_setZoneMax(arg0, 1, 1.0f);
        baflag_set(arg0, 3);
        baflag_set(arg0, 4);
        func_800947EC(arg0, 1, 1);
        *(u8 *)((u8 *)arg0 + 0x165) = 0;
        func_80092864(arg0, 1.0999908447265625f);
    }
}

/* extern */

void bssnowball_entrypoint_2(void *arg0) {
    s32 _basnowball_entrypoint_12(void *);
    s32 _basnowball_entrypoint_8(void *, s32);
    s32 _basnowball_entrypoint_9(void *, f32);
    f32 baphysics_get_target_horizontal_velocity(void *);
    f32 func_8009BB5C(void *);
    s32 func_800A3274();
    if (func_800A3274() == 2) {
        if ((*(u8 *)((s8 *)(arg0) + (0x165))) != 0) {
            _basnowball_entrypoint_9(arg0, 0.0f);
        } else {
            _basnowball_entrypoint_9(arg0, func_8009BB5C(arg0));
        }
        if (((*(u8 *)((s8 *)(arg0) + (0x165))) != 0) || (baphysics_get_target_horizontal_velocity(arg0) == 0.0f)) {
            _basnowball_entrypoint_8(arg0, 1);
        } else {
            _basnowball_entrypoint_8(arg0, 0);
        }
        _basnowball_entrypoint_12(arg0);
    }
}

void func_808003B0_bssnowball(s32 arg0)
{
    _basudie_entrypoint_8();
    bssnowball_entrypoint_0(arg0);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/snowball/func_808003D8_bssnowball.s")

void func_808004AC_bssnowball()
{
    _basudie_entrypoint_10();
}

s32 bssnowball_entrypoint_3(s32 arg0) {
    extern s32 D_80801054_bssnowball[];
    return ((s32 *)&D_80801054_bssnowball)[arg0];
}

void func_808004E0_bssnowball(s32 arg0)
{
    _bsdrone_entrypoint_2();
    bssnowball_entrypoint_0(arg0);
}
void func_80800508_bssnowball(s32 arg0)
{
    bssnowball_entrypoint_1(arg0);
    _bsdrone_entrypoint_0(arg0);
}
void func_80800530_bssnowball(s32 arg0)
{
    _bsdrone_entrypoint_1();
    bssnowball_entrypoint_2(arg0);
}
s32 bssnowball_entrypoint_4(s32 arg0) {
    extern s32 D_80801064_bssnowball[];
    return ((s32 *)&D_80801064_bssnowball)[arg0];
}

/* extern */

void func_8080056C_bssnowball(s32 arg0) {
    void func_8009BF5C(struct player_state_s *, f32);
    void baroll_setIdeal(struct player_state_s *, f32);
    func_8009BF5C(arg0, 0.0f);
    baroll_setIdeal(arg0, 0.0f);
    bssnowball_entrypoint_0(arg0);
}

void func_808005A4_bssnowball(s32 arg0) {
    void anctrl_setPlaybackType(struct anctrl_s *, s32);
    struct anctrl_s *baanim_getAnimCtrlPtr(struct player_state_s *);
    s32 baanim_playForDuration_loopSmooth(s32, s32, s32);
    void func_8009FFD8();
    bssnowball_entrypoint_1(arg0);
    baanim_playForDuration_loopSmooth(arg0, 0x5F, 0x41200000);
    func_8009FFD8(arg0, 2, 3, 1, 0xE);
    anctrl_setPlaybackType(baanim_getAnimCtrlPtr(arg0), 3);
    func_80800164_bssnowball(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/snowball/func_80800614_bssnowball.s")

s32 bssnowball_entrypoint_5(s32 arg0) {
    extern s32 D_80801074_bssnowball[];
    return ((s32 *)&D_80801074_bssnowball)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/snowball/func_808006BC_bssnowball.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/snowball/func_808007D8_bssnowball.s")

void func_8080089C_bssnowball(s32 arg0) {
    void func_8009BF5C(struct player_state_s *, f32);
    void baroll_setIdeal(struct player_state_s *, f32);
    baphysics_reset_gravity();
    func_8009BF5C(arg0, 0.0f);
    baroll_setIdeal(arg0, 0.0f);
    bssnowball_entrypoint_0(arg0);
}

s32 bssnowball_entrypoint_6(s32 arg0) {
    extern s32 D_80801084_bssnowball[];
    return ((s32 *)&D_80801084_bssnowball)[arg0];
}

void func_808008F0_bssnowball()
{
    func_80099B94();
}

void func_80800910_bssnowball(struct player_state_s *arg0)
{
    bssnowball_entrypoint_0(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/snowball/func_80800930_bssnowball.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/snowball/func_808009B0_bssnowball.s")

s32 bssnowball_entrypoint_7(s32 arg0) {
    extern s32 D_80801094_bssnowball[];
    return ((s32 *)&D_80801094_bssnowball)[arg0];
}

void func_80800B44_bssnowball(s32 arg0) { _baspin_entrypoint_1(); *(u8 *)(arg0 + 0x165) = 0; bssnowball_entrypoint_0(arg0); }

void func_80800B70_bssnowball(s32 arg0) { bssnowball_entrypoint_1(arg0); *(u8 *)(arg0 + 0x165) = 1; _basnowball_entrypoint_10(arg0); _baspin_entrypoint_2(arg0, 0x5E, 0x3FE66666, 3, 0); }

/* extern */

void func_80800BBC_bssnowball(s32 arg0) {
    s32 _baspin_entrypoint_3(s32);
    s32 bs_setState(s32, s32);
    s32 sp1C;

    sp1C = 0;
    bssnowball_entrypoint_2(arg0);
    if (_baspin_entrypoint_3(arg0) == 2) {
        sp1C = 0x17D;
    }
    bs_setState(arg0, sp1C);
}

s32 bssnowball_entrypoint_8(s32 arg0) {
    extern s32 D_808010A4_bssnowball[];
    return ((s32 *)&D_808010A4_bssnowball)[arg0];
}

void func_80800C18_bssnowball(s32 arg0)
{
    _babounce_entrypoint_3();
    bssnowball_entrypoint_0(arg0);
}
/* extern */

void func_80800C40_bssnowball(struct player_state_s *arg0) {
    void _babounce_entrypoint_4(struct player_state_s *, s32);
    void _babounce_entrypoint_5(struct player_state_s *, s32, f32);
    struct anctrl_s *baanim_getAnimCtrlPtr(struct player_state_s *);
    void func_8008B10C(struct anctrl_s *, f32);
    bssnowball_entrypoint_1(arg0);
    _babounce_entrypoint_4(arg0, 2);
    _babounce_entrypoint_5(arg0, 0x5E, 0.5128f);
    func_8008B10C(baanim_getAnimCtrlPtr(arg0), 0.1026f);
}

/* extern */

void func_80800C98_bssnowball(s32 arg0) {
    s32 _babounce_entrypoint_2();
    s32 _babounce_entrypoint_9(s32);
    s32 bs_setState(s32, s32);
    void func_80800064_bssnowball(struct player_state_s *, s32);
    s32 sp1C;

    sp1C = 0;
    if (_babounce_entrypoint_2() != 0) {
        func_80800064_bssnowball(arg0, 0);
    }
    if (_babounce_entrypoint_9(arg0) != 0) {
        sp1C = 0x17D;
    }
    bs_setState(arg0, sp1C);
}

s32 bssnowball_entrypoint_9(s32 arg0) {
    extern s32 D_808010B4_bssnowball[];
    return ((s32 *)&D_808010B4_bssnowball)[arg0];
}

void func_80800D00_bssnowball(s32 arg0)
{
    _bsrest_entrypoint_14();
    bssnowball_entrypoint_0(arg0);
}
void func_80800D28_bssnowball(s32 arg0)
{
    bssnowball_entrypoint_1(arg0);
    _bsrest_entrypoint_16(arg0);
}
/* extern */

void func_80800D50_bssnowball(s32 arg0) {
    s32 _bsrest_entrypoint_13(s32);
    s32 _bsrest_entrypoint_20();
    s32 bs_setState(s32, s32);
    s32 sp1C;

    sp1C = 0;
    if (_bsrest_entrypoint_20() != 0) {
        sp1C = _bsrest_entrypoint_13(arg0);
    }
    bssnowball_entrypoint_2(arg0);
    bs_setState(arg0, sp1C);
}

s32 bssnowball_entrypoint_10(s32 arg0) {
    extern s32 D_808010C4_bssnowball[];
    return ((s32 *)&D_808010C4_bssnowball)[arg0];
}

void func_80800DB0_bssnowball(s32 arg0)
{
    func_80090A2C();
    bssnowball_entrypoint_0(arg0);
}
void func_80800DD8_bssnowball(s32 arg0) {
    void func_8009FFD8();
    s32 baanim_playForDuration_loopSmooth(s32, s32, s32);
    void baphysics_set_target_horizontal_velocity(struct player_state_s *, f32);
    void func_800909CC(struct player_state_s *);
    bssnowball_entrypoint_1(arg0);
    baanim_playForDuration_loopSmooth(arg0, 0x5E, 0x3F99999A);
    func_8009FFD8(arg0, 1, 3, 1, 2);
    func_80800164_bssnowball(arg0);
    baphysics_set_target_horizontal_velocity(arg0, 0.0f);
    func_800909CC(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/snowball/func_80800E4C_bssnowball.s")

s32 bssnowball_entrypoint_11(s32 arg0) {
    extern s32 D_808010D4_bssnowball[];
    return ((s32 *)&D_808010D4_bssnowball)[arg0];
}
