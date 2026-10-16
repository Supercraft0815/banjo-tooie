#include "common.h"

struct player_state_s;

void func_800BA22C(s32, s32);

void func_80800000_bsvanswim(struct player_state_s *arg0) {
    void func_80092C00(struct player_state_s *, f32 *);
    void func_80092C24(struct player_state_s *, f32 *);
    s32 func_80096544(struct player_state_s *);
    s32 func_8009FBB0(struct player_state_s *, f32 *, f32);
    void func_800BA930(s32, s16, s16, s16, s16, s16, s16);
    f32 func_800DC0C0(void);
    f32 sp2C[3];
    s32 sp28;

    if (func_80096544(arg0) != 0) {
        if (func_800DC0C0() > 0.5f) {
            func_80092C00(arg0, sp2C);
        } else {
            func_80092C24(arg0, sp2C);
        }
        sp28 = func_8009FBB0(arg0, sp2C, 0.0f);
        func_800BA930(sp28, -0x3C, -0x64, -0x3C, 0x3C, 0, 0x3C);
        func_800BA22C(sp28, 1);
    }
}

void func_808000B0_bsvanswim(struct player_state_s *arg0) {
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
    baphysics_set_target_horizontal_velocity(arg0, func_800F1214(sp1C, 30.0f, 200.0f));
}

void func_80800114_bsvanswim(struct player_state_s *arg0) {
    extern void _bsvan_entrypoint_1(struct player_state_s *);
    extern void baphysics_set_gravity(struct player_state_s *, f32);
    extern void baphysics_set_terminal_velocity(struct player_state_s *, f32);
    extern void func_800961AC(struct player_state_s *, s32);
    extern s32 func_8009E6C4(struct player_state_s *, s32);
    _bsvan_entrypoint_1(arg0);
    if (func_8009E6C4(arg0, 1) == 0) {
        baphysics_set_gravity(arg0, 100.0f);
        baphysics_set_terminal_velocity(arg0, 133.33f);
        func_800961AC(arg0, 3);
    }
}

void func_80800174_bsvanswim(struct player_state_s *arg0) {
    s32 func_8009E69C(struct player_state_s *, s32);
    void baphysics_reset_terminal_velocity(struct player_state_s *);
    void baphysics_reset_gravity(struct player_state_s *);
    void func_800961AC(struct player_state_s *, s32);
    s32 _bsvan_entrypoint_0(s32);
    if (func_8009E69C(arg0, 1) == 0) {
        baphysics_reset_terminal_velocity(arg0);
        baphysics_reset_gravity(arg0);
        func_800961AC(arg0, 1);
    }
    _bsvan_entrypoint_0((s32)arg0);
}

/* extern */

void func_808001CC_bsvanswim(struct player_state_s *arg0) {
    s32 _bsvan_entrypoint_0(s32);
    void func_800961AC(struct player_state_s *, s32);
    s32 func_8009BC34();
    func_8009BC34();
    func_800961AC(arg0, 1);
    _bsvan_entrypoint_0((s32)arg0);
}

void func_80800200_bsvanswim(struct player_state_s *arg0) {
    void _bsvan_entrypoint_1(struct player_state_s *);
    void baphysics_set_gravity(struct player_state_s *, f32);
    void baphysics_set_terminal_velocity(struct player_state_s *, f32);
    void baphysics_set_vertical_velocity(void *, f32);
    void func_800961AC(struct player_state_s *, s32);
    void func_8009BC5C(struct player_state_s *, f32);
    void func_800A046C(struct player_state_s *);
    f32 func_800A3298(struct player_state_s *);
    s32 baanim_playForDuration_loopSmooth(struct player_state_s *, s32, s32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    s32 func_8009FFD8(struct player_state_s *, s32, s32, s32, s32);
    f32 speed;
    f32 velocity;

    _bsvan_entrypoint_1(arg0);
    baphysics_set_gravity(arg0, 0.0f);
    baphysics_set_terminal_velocity(arg0, -399.99f);
    func_800961AC(arg0, 3);
    func_8009BC5C(arg0, 2.0f);
    func_800A046C(arg0);
    speed = func_800A3298(arg0);
    baanim_playForDuration_loopSmooth(arg0, 0xE7, 0x40D00000);
    velocity = func_800F10B4(speed, 40.0f, 1000.0f, -300.0f, -1200.0f);
    *(f32 *)((u8 *)arg0 + 0x16C) = velocity;
    baphysics_set_vertical_velocity(arg0, velocity);
    func_8009FFD8(arg0, 1, 3, 3, 6);
}

void func_808002D0_bsvanswim(void *arg0) {
    f32 baphysics_get_vertical_velocity(void *);
    void baphysics_set_vertical_velocity(void *, f32);
    void func_8009C128(void *, f32 *);
    s32 func_8009FBB0(struct player_state_s *, f32 *, f32);
    void func_800BA930(s32, s16, s16, s16, s16, s16, s16);
    f32 func_800F0E00(f32, f32);
    f32 mlAbsF(f32);
    s32 next_state;
    f32 position[3];
    s32 effect;

    next_state = 0;
    func_8009C128(arg0, position);
    position[1] += 60.0f;
    effect = func_8009FBB0(arg0, position, 20.0f);
    func_800BA930(effect, -30, -30, -30, 30, 30, 30);
    func_800BA22C(effect, 1);
    if (*(f32 *)((u8 *)arg0 + 0x16C) < 0.0f) {
        *(f32 *)((u8 *)arg0 + 0x16C) += func_800F0E00(mlAbsF(*(f32 *)((u8 *)arg0 + 0x16C)) * 0.1f, 50.0f);
        baphysics_set_vertical_velocity(arg0, *(f32 *)((u8 *)arg0 + 0x16C));
    }
    if (player_isStable(arg0)) {
        next_state = 0x11B;
    }
    if (!player_inWater(arg0)) {
        next_state = 0x11A;
    }
    if (baphysics_get_vertical_velocity(arg0) >= 0.0f) {
        next_state = 0x11B;
    }
    _bsvan_entrypoint_3(arg0);
    bs_setState(arg0, next_state);
}

s32 bsvanswim_entrypoint_0(s32 arg0) {
    extern s32 D_80800980_bsvanswim[];
    return ((s32 *)&D_80800980_bsvanswim)[arg0];
}

/* extern */

void func_8080042C_bsvanswim(struct player_state_s *arg0) {
    s32 baanim_playForDuration_loopSmooth(struct player_state_s *, s32, s32);
    void baphysics_set_target_horizontal_velocity(struct player_state_s *, f32);
    s32 func_8009FFD8(struct player_state_s *, s32, s32, s32, s32);
    s32 yaw_setVelocityBounded(struct player_state_s *, s32, s32);
    func_80800114_bsvanswim(arg0);
    baanim_playForDuration_loopSmooth(arg0, 0xE7, 0x40D00000);
    func_8009FFD8(arg0, 1, 3, 3, 2);
    yaw_setVelocityBounded(arg0, 0x43FA0000, 0x40A00000);
    baphysics_set_target_horizontal_velocity(arg0, 0.0f);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/vanswim/func_8080049C_bsvanswim.s")

void func_808005E8_bsvanswim(struct player_state_s *arg0)
{
    func_80800174_bsvanswim(arg0);
}

s32 bsvanswim_entrypoint_1(s32 arg0) {
    extern s32 D_80800990_bsvanswim[];
    return ((s32 *)&D_80800990_bsvanswim)[arg0];
}

/* extern */

void func_8080061C_bsvanswim(struct player_state_s *arg0) {
    s32 baanim_playForDuration_loopSmooth(struct player_state_s *, s32, s32);
    s32 baanim_setDurationRange(struct player_state_s *, s32, s32);
    s32 baphysics_set_type(struct player_state_s *, s32);
    s32 func_8008C9F0(struct player_state_s *, s32, s32, s32, f32);
    s32 func_8008CA4C(struct player_state_s *, s32);
    s32 func_8009D2D8(struct player_state_s *, s32);
    s32 yaw_setUpdateType(struct player_state_s *, s32);
    s32 yaw_setVelocityBounded(struct player_state_s *, s32, s32);
    func_80800114_bsvanswim(arg0);
    baanim_playForDuration_loopSmooth(arg0, 0xE8, 0x3F4CCCCD);
    func_8008CA4C(arg0, 2);
    baanim_setDurationRange(arg0, 0x3E99999A, 0x3FC00000);
    func_8008C9F0(arg0, 0x41F00000, 0x43480000, 0x3F4CCCCD, 0.45f);
    yaw_setUpdateType(arg0, 3);
    yaw_setVelocityBounded(arg0, 0x43FA0000, 0x40A00000);
    func_8009D2D8(arg0, 1);
    baphysics_set_type(arg0, 2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/vanswim/func_808006D0_bsvanswim.s")

void func_80800808_bsvanswim(struct player_state_s *arg0)
{
    func_80800174_bsvanswim(arg0);
}

s32 bsvanswim_entrypoint_2(s32 arg0) {
    extern s32 D_808009A0_bsvanswim[];
    return ((s32 *)&D_808009A0_bsvanswim)[arg0];
}

void func_8080083C_bsvanswim(s32 arg0)
{
    _bsrest_entrypoint_14();
    func_80800174_bsvanswim(arg0);
}
void func_80800864_bsvanswim(struct player_state_s *arg0)
{
    func_80800114_bsvanswim(arg0);
    _bsrest_entrypoint_16(arg0);
}
/* extern */

void func_8080088C_bsvanswim(s32 arg0) {
    s32 _bsrest_entrypoint_20();
    s32 sp1C;

    sp1C = 0;
    if (_bsrest_entrypoint_20() != 0) {
        sp1C = 0x11B;
    }
    _bsvan_entrypoint_3(arg0);
    bs_setState(arg0, sp1C);
}

s32 bsvanswim_entrypoint_3(s32 arg0) {
    extern s32 D_808009B0_bsvanswim[];
    return ((s32 *)&D_808009B0_bsvanswim)[arg0];
}

void func_808008E4_bsvanswim(struct player_state_s *arg0)
{
    func_80800114_bsvanswim(arg0);
    _bsdrone_entrypoint_0(arg0);
}
void func_8080090C_bsvanswim(s32 arg0)
{
    _bsdrone_entrypoint_1();
    _bsvan_entrypoint_3(arg0);
}
void func_80800934_bsvanswim(s32 arg0)
{
    _bsdrone_entrypoint_2();
    func_80800174_bsvanswim(arg0);
}
s32 bsvanswim_entrypoint_4(s32 arg0) {
    extern s32 D_808009C0_bsvanswim[];
    return ((s32 *)&D_808009C0_bsvanswim)[arg0];
}
