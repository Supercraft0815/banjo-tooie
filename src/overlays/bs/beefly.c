#include "common.h"

typedef struct player_state_s PlayerState;
void func_8009C128(PlayerState *, f32[3]);

void func_80800000_bsbeefly(PlayerState *arg0) {
    s32 func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    f32 func_800DC178(f32, f32);
    extern s32 D_80800DC0_bsbeefly;
    f32 sp24[3];

    func_8009C128(arg0, sp24);
    sp24[0] += func_800DC178(-30.0f, 30.0f);
    sp24[1] += 30.0f + func_800DC178(0.0f, 30.0f);
    sp24[2] += func_800DC178(-30.0f, 30.0f);
    func_800BBCB8(sp24, NULL, 1.0f, 1, &D_80800DC0_bsbeefly);
}

void func_808000A4_bsbeefly(s32 arg0) {
    s32 func_800BABB8(s32, f32 *, s32, s32, s32 *);
    extern s32 D_80800DE8_bsbeefly;
    f32 sp24[3];
    s32 sp20;

    sp20 = func_800B5BE4(0x22);
    func_8009C128(arg0, sp24);
    *(f32 *)((s8 *)sp24 + 4) += 45.0f;
    func_800BABB8(sp20, sp24, 0, 0x3F800000, &D_80800DE8_bsbeefly);
}

/* extern */

void func_8080010C_bsbeefly(PlayerState *arg0) {
    s32 _bsbee_entrypoint_1();
    s32 baanim_playForDuration_once(void *, s32, f32);
    void baphysics_set_gravity(PlayerState *, f32);
    void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
    void baphysics_set_target_yaw(PlayerState *, f32);
    f32 bastick_distance(PlayerState *);
    f32 bastick_getAngleRelativeToBanjo(PlayerState *);
    void func_8009FFD8(PlayerState *, s32, s32, s32, s32);
    f32 yaw_getIdeal(PlayerState *);
    void yaw_setIdeal(PlayerState *, f32);
    _bsbee_entrypoint_1();
    baanim_playForDuration_once(arg0, 0x1DF, 1.5f);
    func_8009FFD8(arg0, 1, 1, 3, 6);
    if (bastick_distance(arg0) != 0.0f) {
        yaw_setIdeal(arg0, bastick_getAngleRelativeToBanjo(arg0));
    }
    baphysics_set_target_yaw(arg0, yaw_getIdeal(arg0));
    baphysics_set_target_horizontal_velocity(arg0, 0.0f);
    baphysics_set_gravity(arg0, -1200.0f);
    (*(s32 *)((s8 *)(arg0) + (0x15C))) = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/beefly/func_808001C4_bsbeefly.s")

void func_808002B0_bsbeefly()
{
    _bsbee_entrypoint_0();
}

s32 bsbeefly_entrypoint_0(s32 arg0) {
    extern s32 D_80800E18_bsbeefly[];
    return ((s32 *)&D_80800E18_bsbeefly)[arg0];
}

void func_808002E4_bsbeefly(PlayerState *arg0) {
    void _babee_entrypoint_5(PlayerState *);
    void _baboost_entrypoint_4(PlayerState *, s32);
    void _babuzz_entrypoint_1(PlayerState *);
    void _bafly_entrypoint_4(PlayerState *);
    s32 _bafpctrl_entrypoint_18(PlayerState *, s32);
    void baphysics_reset_gravity(PlayerState *);
    void baphysics_reset_terminal_velocity(PlayerState *);
    void baroll_setIdeal(PlayerState *, f32);
    s32 bs_getNextState(PlayerState *);
    void func_80093360(PlayerState *, f32);
    void func_800947EC(PlayerState *, s32, s32);
    void func_8009BF5C(PlayerState *, f32);
    s32 func_8009CA70(PlayerState *, s32, s32);
    void func_800A4E30(PlayerState *);
    if (func_8009CA70(arg0, bs_getNextState(arg0), 0x4000) == 0) {
        func_80093360(arg0, 0.0f);
        baroll_setIdeal(arg0, 0.0f);
        func_8009BF5C(arg0, 0.0f);
        func_800A4E30(arg0);
        baphysics_reset_gravity(arg0);
        baphysics_reset_terminal_velocity(arg0);
        _baboost_entrypoint_4(arg0, 0);
        _babuzz_entrypoint_1(arg0);
        _babee_entrypoint_5(arg0);
        _bafly_entrypoint_4(arg0);
        _bafpctrl_entrypoint_18(arg0, 0);
        func_800947EC(arg0, 1, 1);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/beefly/func_8080039C_bsbeefly.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/beefly/func_80800480_bsbeefly.s")

/* extern */

void func_808005B0_bsbeefly(s32 arg0) {
    s32 _baboost_entrypoint_2(s32, s32);
    s32 func_80099B94(s32);
    s32 func_8009E6EC();
    s32 func_8009E830(s32, s32);
    if (func_8009E6EC() == 0x18) {
        _baboost_entrypoint_2(arg0, 0x3F800000);
        func_8009E830(arg0, 2);
        return;
    }
    func_80099B94(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/beefly/func_80800600_bsbeefly.s")

void func_80800708_bsbeefly(void *arg0) {
    extern f32 D_80800E28_bsbeefly[];
    extern f32 D_80800E3C_bsbeefly[];
    s32 _bsbee_entrypoint_2();
    s32 bs_setState(s32, s32);
    s32 _baboost_entrypoint_1(void *);
    s32 _baboost_entrypoint_2(s32, s32);
    void _baboost_entrypoint_5(void *);
    void _babuzz_entrypoint_3(void *);
    void _babuzz_entrypoint_4(void *, f32);
    s32 _bafly_entrypoint_2(void *);
    void _bafly_entrypoint_8(void *, f32, f32, f32, f32, f32, f32, f32);
    void _bafly_entrypoint_10(void *, f32, f32);
    void _bafly_entrypoint_11(void *);
    void _bafly_entrypoint_20(void *);
    void _bafly_entrypoint_21(void *);
    s32 baanim_getAnimCtrlPtr(void *);
    void anctrl_setDuration(s32, f32);
    f32 baphysics_get_target_horizontal_velocity(void *);
    f32 baphysics_get_vertical_velocity(void *);
    void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
    void baphysics_set_vertical_velocity(void *, f32);
    void func_8009BF5C(PlayerState *, f32);
    f32 func_8009BFCC(void *);
    f32 func_8009BFD8(void *);
    f32 func_8009C150(void *);
    f32 func_800136E4(f32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    s32 next_state;
    s32 anctrl;
    s32 boost;
    f32 buzz;
    f32 pitch;
    f32 target_pitch;
    f32 buzz_offset;
    f32 fall_speed;
    f32 terminal_speed;

    next_state = 0;
    anctrl = baanim_getAnimCtrlPtr(arg0);
    _bsbee_entrypoint_2(arg0);
    _bafly_entrypoint_20(arg0);
    func_80800480_bsbeefly(arg0);
    _bafly_entrypoint_10(arg0, 300.0f, 80.0f);
    _bafly_entrypoint_11(arg0);
    func_8009BFCC(arg0);
    if (bakey_pressed(arg0, 8) && func_8009C150(arg0) < 27500.0f) {
        _baboost_entrypoint_2((s32)arg0, 0x3F800000);
    }
    if (!_baboost_entrypoint_1(arg0) && player_inWater(arg0)) {
        _baboost_entrypoint_2((s32)arg0, 0x3F800000);
    }
    boost = _baboost_entrypoint_1(arg0);
    anctrl_setDuration(anctrl, D_80800E28_bsbeefly[boost]);
    buzz = 0.9f;
    buzz += D_80800E3C_bsbeefly[boost];
    pitch = func_8009BFCC(arg0);
    buzz_offset = 0.0f;
    if (baphysics_get_vertical_velocity(arg0) < 0) {
        if (pitch < 300.0f) {
            buzz_offset = func_800F10B4(pitch, 0, 80.0f, 0.0f, 0.23f);
        }
        if (pitch > 80.0f) {
            buzz_offset = func_800F10B4(pitch, 300.0f, 360.0f, -0.2f, 0.0f);
        }
    }
    buzz += buzz_offset;
    if (boost == 0 && bakey_held(arg0, 9)) {
        buzz += 0.12f;
    }
    _babuzz_entrypoint_4(arg0, buzz);
    _babuzz_entrypoint_3(arg0);
    switch (*(s32 *)((u8 *)arg0 + 0x15C)) {
    case 0:
        if (boost != 0) {
            *(s32 *)((u8 *)arg0 + 0x15C) = 1;
        }
        break;
    case 1:
        target_pitch = func_800136E4(func_8009BFD8(arg0) - 30.0f);
        if (target_pitch > 80.0f && target_pitch < 300.0f) {
            target_pitch = 300.0f;
        }
        func_8009BF5C(arg0, target_pitch);
        _bafly_entrypoint_21(arg0);
        if (boost != 0) {
            baphysics_set_vertical_velocity(arg0, (f32)boost * 400.0f);
            func_80800000_bsbeefly(arg0);
        }
        if (boost == 0) {
            _bafly_entrypoint_20(arg0);
            *(s32 *)((u8 *)arg0 + 0x15C) = 0;
        }
        break;
    }
    if (bakey_held(arg0, 9)) {
        fall_speed = -1500.0f;
        terminal_speed = -1800.0f;
    } else {
        fall_speed = -700.0f;
        terminal_speed = -1000.0f;
    }
    _bafly_entrypoint_8(arg0, 300.0f, 80.0f, 600.0f, -300.0f, -99.9f, fall_speed, terminal_speed);
    if (bakey_held(arg0, 9)) {
        func_808000A4_bsbeefly(arg0);
        baphysics_set_target_horizontal_velocity(arg0, baphysics_get_target_horizontal_velocity(arg0) * 3.5f);
    }
    if (bakey_held(arg0, 1)) {
        _babee_entrypoint_2(arg0);
    }
    if (_bafly_entrypoint_2(arg0) && !player_inWater(arg0)) {
        next_state = 0x85;
    }
    _baboost_entrypoint_5(arg0);
    bs_setState((s32)arg0, next_state);
}

void func_80800B18_bsbeefly(PlayerState *arg0)
{
    func_808002E4_bsbeefly(arg0);
    _bsbee_entrypoint_0(arg0);
}
s32 bsbeefly_entrypoint_1(s32 arg0) {
    extern s32 D_80800E50_bsbeefly[];
    return ((s32 *)&D_80800E50_bsbeefly)[arg0];
}

/* extern */

void func_80800B54_bsbeefly(void *arg0) {
    extern s32 _bsbee_entrypoint_1();
    extern s32 _bsrest_entrypoint_16(void *);
    extern void baphysics_set_gravity(PlayerState *, f32);
    extern void func_8009BA9C(void *, f32 *);
    extern s32 func_8080039C_bsbeefly(s32);
    void *self = arg0;
    _bsbee_entrypoint_1(self);
    func_8080039C_bsbeefly((s32)self);
    _bsrest_entrypoint_16(self);
    baphysics_set_gravity(self, 0.0f);
    func_8009BA9C(self, 0);
}

/* extern */

void func_80800BA4_bsbeefly(s32 arg0) {
    s32 _bsbee_entrypoint_2();
    s32 _bsrest_entrypoint_20(s32);
    s32 bs_setState(s32, s32);
    s32 sp1C;

    sp1C = 0;
    _bsbee_entrypoint_2();
    if (_bsrest_entrypoint_20(arg0) != 0) {
        sp1C = 0x8C;
    }
    bs_setState(arg0, sp1C);
}

void func_80800BE8_bsbeefly(s32 arg0)
{
    _bsrest_entrypoint_14();
    func_808002E4_bsbeefly(arg0);
    _bsbee_entrypoint_0(arg0);
}

s32 bsbeefly_entrypoint_2(s32 arg0) {
    extern s32 D_80800E60_bsbeefly[];
    return ((s32 *)&D_80800E60_bsbeefly)[arg0];
}

void func_80800C2C_bsbeefly(s32 arg0)
{
    _bafly_entrypoint_18();
    func_808002E4_bsbeefly(arg0);
    _bsbee_entrypoint_0(arg0);
}

/* extern */

void func_80800C5C_bsbeefly(s32 arg0) {
    s32 _bafly_entrypoint_16(s32, s32, s32);
    s32 _bsbee_entrypoint_1();
    s32 func_8080039C_bsbeefly(s32);
    _bsbee_entrypoint_1();
    func_8080039C_bsbeefly(arg0);
    _bafly_entrypoint_16(arg0, 0x1E0, 0x3F800000);
}

/* extern */

void func_80800C94_bsbeefly(s32 arg0) {
    s32 _bafly_entrypoint_17(s32, s32, s32, s32 *);
    s32 _bsbee_entrypoint_2();
    s32 sp1C;

    sp1C = 0;
    _bsbee_entrypoint_2();
    _bafly_entrypoint_17(arg0, 0x8C, 0x85, &sp1C);
}

s32 bsbeefly_entrypoint_3(s32 arg0) {
    extern s32 D_80800E70_bsbeefly[];
    return ((s32 *)&D_80800E70_bsbeefly)[arg0];
}

void func_80800CE0_bsbeefly(s32 arg0)
{
    _bafly_entrypoint_15();
    func_808002E4_bsbeefly(arg0);
    _bsbee_entrypoint_0(arg0);
}

/* extern */

void func_80800D10_bsbeefly(s32 arg0) {
    s32 _bafly_entrypoint_13(s32, s32, s32, s32);
    s32 _bsbee_entrypoint_1();
    s32 func_8080039C_bsbeefly(s32);
    _bsbee_entrypoint_1();
    func_8080039C_bsbeefly(arg0);
    _bafly_entrypoint_13(arg0, 1, 0xD3, 0x3F99999A);
}

/* extern */

void func_80800D50_bsbeefly(s32 arg0) {
    s32 _bafly_entrypoint_14(s32, s32, s32);
    s32 _bsbee_entrypoint_2();
    _bsbee_entrypoint_2();
    _bafly_entrypoint_14(arg0, 0x8C, 0x85);
}

s32 bsbeefly_entrypoint_4(s32 arg0) {
    extern s32 D_80800E80_bsbeefly[];
    return ((s32 *)&D_80800E80_bsbeefly)[arg0];
}
