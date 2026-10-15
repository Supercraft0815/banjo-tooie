#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/tntswim/func_80800000_bstntswim.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/tntswim/func_808000B0_bstntswim.s")

struct player_state_s;
void func_80800114_bstntswim(struct player_state_s *arg0) {
    void _bstnt_entrypoint_3(struct player_state_s *);
    void baphysics_set_gravity(struct player_state_s *, f32);
    void baphysics_set_terminal_velocity(struct player_state_s *, f32);
    void func_800961AC(struct player_state_s *, s32);
    s32 func_8009E6C4(struct player_state_s *, s32);
    _bstnt_entrypoint_3(arg0);
    if (func_8009E6C4(arg0, 1) == 0) {
        baphysics_set_gravity(arg0, 100.0f);
        baphysics_set_terminal_velocity(arg0, 133.33f);
        func_800961AC(arg0, 3);
    }
}

struct player_state_s;

void func_80800174_bstntswim(struct player_state_s *arg0) {
    s32 func_8009E69C(struct player_state_s *, s32);
    void baphysics_reset_terminal_velocity(struct player_state_s *);
    void baphysics_reset_gravity(struct player_state_s *);
    void func_800961AC(struct player_state_s *, s32);
    s32 _bstnt_entrypoint_2(s32);
    if (func_8009E69C(arg0, 1) == 0) {
        baphysics_reset_terminal_velocity(arg0);
        baphysics_reset_gravity(arg0);
        func_800961AC(arg0, 1);
    }
    _bstnt_entrypoint_2((s32)arg0);
}

/* extern */

void func_808001CC_bstntswim(struct player_state_s *arg0) {
    s32 _bstnt_entrypoint_2(s32);
    void func_800961AC(struct player_state_s *, s32);
    s32 func_8009BC34();
    func_8009BC34();
    func_800961AC(arg0, 1);
    _bstnt_entrypoint_2((s32)arg0);
}

void func_80800200_bstntswim(struct player_state_s *arg0) {
    void _bstnt_entrypoint_3(struct player_state_s *);
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

    _bstnt_entrypoint_3(arg0);
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

void func_808002D0_bstntswim(void *arg0) {
    f32 baphysics_get_vertical_velocity(void *);
    void baphysics_set_vertical_velocity(void *, f32);
    void func_8009C128(void *, f32 *);
    s32 func_8009FBB0(void *, f32 *, f32);
    void func_800BA930(s32, s32, s32, s32, s32, s32, s32);
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
        next_state = 0x10F;
    }
    if (!player_inWater(arg0)) {
        next_state = 0x10C;
    }
    if (baphysics_get_vertical_velocity(arg0) >= 0.0f) {
        next_state = 0x10F;
    }
    _bstnt_entrypoint_4(arg0);
    bs_setState(arg0, next_state);
}

s32 bstntswim_entrypoint_0(s32 arg0) {
    extern s32 D_808009B0_bstntswim[];
    return ((s32 *)&D_808009B0_bstntswim)[arg0];
}

/* extern */

void func_8080042C_bstntswim(struct player_state_s *arg0) {
    s32 baanim_playForDuration_loopSmooth(struct player_state_s *, s32, s32);
    void baphysics_set_target_horizontal_velocity(struct player_state_s *, f32);
    s32 func_8009FFD8(struct player_state_s *, s32, s32, s32, s32);
    s32 yaw_setVelocityBounded(struct player_state_s *, s32, s32);
    func_80800114_bstntswim(arg0);
    baanim_playForDuration_loopSmooth(arg0, 0xE7, 0x40D00000);
    func_8009FFD8(arg0, 1, 3, 3, 2);
    yaw_setVelocityBounded(arg0, 0x43FA0000, 0x40A00000);
    baphysics_set_target_horizontal_velocity(arg0, 0.0f);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/tntswim/func_8080049C_bstntswim.s")

void func_808005FC_bstntswim(struct player_state_s *arg0)
{
    func_80800174_bstntswim(arg0);
}

s32 bstntswim_entrypoint_1(s32 arg0) {
    extern s32 D_808009C0_bstntswim[];
    return ((s32 *)&D_808009C0_bstntswim)[arg0];
}

/* extern */

void func_80800630_bstntswim(struct player_state_s *arg0) {
    s32 baanim_playForDuration_loopSmooth(struct player_state_s *, s32, s32);
    s32 baanim_setDurationRange(struct player_state_s *, s32, s32);
    s32 baphysics_set_type(struct player_state_s *, s32);
    s32 func_8008C9F0(struct player_state_s *, s32, s32, s32, f32);
    s32 func_8008CA4C(struct player_state_s *, s32);
    s32 func_8009D2D8(struct player_state_s *, s32);
    s32 yaw_setUpdateType(struct player_state_s *, s32);
    s32 yaw_setVelocityBounded(struct player_state_s *, s32, s32);
    func_80800114_bstntswim(arg0);
    baanim_playForDuration_loopSmooth(arg0, 0xE8, 0x3F4CCCCD);
    func_8008CA4C(arg0, 2);
    baanim_setDurationRange(arg0, 0x3E99999A, 0x3FC00000);
    func_8008C9F0(arg0, 0x41F00000, 0x43480000, 0x3F4CCCCD, 0.45f);
    yaw_setUpdateType(arg0, 3);
    yaw_setVelocityBounded(arg0, 0x43FA0000, 0x40A00000);
    func_8009D2D8(arg0, 1);
    baphysics_set_type(arg0, 2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/tntswim/func_808006E4_bstntswim.s")

void func_80800830_bstntswim(struct player_state_s *arg0)
{
    func_80800174_bstntswim(arg0);
}

s32 bstntswim_entrypoint_2(s32 arg0) {
    extern s32 D_808009D0_bstntswim[];
    return ((s32 *)&D_808009D0_bstntswim)[arg0];
}

void func_80800864_bstntswim(s32 arg0)
{
    _bsrest_entrypoint_14();
    func_80800174_bstntswim(arg0);
}
void func_8080088C_bstntswim(struct player_state_s *arg0)
{
    func_80800114_bstntswim(arg0);
    _bsrest_entrypoint_16(arg0);
}
/* extern */

void func_808008B4_bstntswim(s32 arg0) {
    s32 _bsrest_entrypoint_20();
    s32 sp1C;

    sp1C = 0;
    if (_bsrest_entrypoint_20() != 0) {
        sp1C = 0x10F;
    }
    _bstnt_entrypoint_4(arg0);
    bs_setState(arg0, sp1C);
}

s32 bstntswim_entrypoint_3(s32 arg0) {
    extern s32 D_808009E0_bstntswim[];
    return ((s32 *)&D_808009E0_bstntswim)[arg0];
}

void func_8080090C_bstntswim(struct player_state_s *arg0)
{
    func_80800114_bstntswim(arg0);
    _bsdrone_entrypoint_0(arg0);
}
void func_80800934_bstntswim(s32 arg0)
{
    _bsdrone_entrypoint_1();
    _bstnt_entrypoint_4(arg0);
}
void func_8080095C_bstntswim(s32 arg0)
{
    _bsdrone_entrypoint_2();
    func_80800174_bstntswim(arg0);
}
s32 bstntswim_entrypoint_4(s32 arg0) {
    extern s32 D_808009F0_bstntswim[];
    return ((s32 *)&D_808009F0_bstntswim)[arg0];
}
