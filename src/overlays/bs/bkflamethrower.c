#include "common.h"

struct player_state_s;

void bsbkflamethrower_entrypoint_0(struct player_state_s *arg0, f32 arg1[3], f32 arg2[3]) {
    f32 func_8009BFCC(struct player_state_s *);
    void func_8009C128(struct player_state_s *, f32 *);
    void func_800EEC30(f32 *, f32, f32, f32);
    void func_800EF04C(f32 *, f32 *);
    void func_800EFA98(f32 *, f32 *, f32);
    f32 yaw_get(struct player_state_s *);
    f32 sp24[3];
    f32 sp20;
    f32 sp1C;

    sp1C = func_8009BFCC(arg0);
    func_800EEC30(arg2, -sp1C, yaw_get(arg0), 1.0f);
    func_8009C128(arg0, arg1);
    func_800EFA98(sp24, arg2, 40.0f);
    func_800EF04C(arg1, sp24);
    arg1[1] += 94.0f;
}

void func_80800094_bsbkflamethrower(struct player_state_s *arg0, u32 arg1) {
    struct anctrl_s;
    void func_8009FFD8();
    s32 _baflamethrower_entrypoint_1(struct player_state_s *);
    s32 _baflamethrower_entrypoint_2(struct player_state_s *, void (*)(struct player_state_s *, f32 [3], f32 [3]));
    s32 _baflamethrower_entrypoint_3(struct player_state_s *);
    s32 _baflamethrower_entrypoint_4(struct player_state_s *);
    void _batimer_set(struct player_state_s *, s32, f32);
    void anctrl_setPlaybackType(struct anctrl_s *, s32);
    void anctrl_setSubrange(struct anctrl_s *, f32, f32);
    struct anctrl_s *baanim_getAnimCtrlPtr(struct player_state_s *);
    void baanim_playForDuration_onceSmooth(struct player_state_s *, s32, f32);
    void baanim_setEnd(struct player_state_s *, f32);
    void baphysics_set_target_horizontal_velocity(struct player_state_s *, f32);
    void func_8009D874(struct player_state_s *);
    void func_800A0CF4(struct player_state_s *, s32);
    s32 func_800C6E38(s32);
    void yaw_setVelocityBounded(struct player_state_s *, f32, f32);
    void _bsbkflamethrower_entrypoint_0(struct player_state_s *, f32 [3], f32 [3]);
    struct anctrl_s *temp_a0;

    temp_a0 = baanim_getAnimCtrlPtr(arg0);
    (*(u32 *)((s8 *)arg0 + 0x15C)) = arg1;
    switch (arg1) {
    case 1:
        baanim_playForDuration_onceSmooth(arg0, 0xE0, 1.0f);
        func_8009FFD8(arg0, 1, 3, 8, 2);
        yaw_setVelocityBounded(arg0, 300.0f, 1.6f);
        baphysics_set_target_horizontal_velocity(arg0, 0.0f);
        func_800A0CF4(arg0, 1);
        func_8009D874(arg0);
        _batimer_set(arg0, 0, func_800C6E38(0x32) != 0 ? 0.24f : 0.0f);
        _baflamethrower_entrypoint_2(arg0, &_bsbkflamethrower_entrypoint_0);
        return;
    case 2:
        anctrl_setSubrange(temp_a0, 0.4f, 0.6f);
        anctrl_setPlaybackType(temp_a0, 4);
        _batimer_set(arg0, 2, 0.14f);
        _baflamethrower_entrypoint_3(arg0);
        return;
    case 3:
        _baflamethrower_entrypoint_4(arg0);
        _batimer_set(arg0, 1, 0.05f);
        return;
    case 4:
        anctrl_setPlaybackType(temp_a0, 1);
        baanim_setEnd(arg0, 1.0f);
        return;
    case 0:
        _baflamethrower_entrypoint_1(arg0);
        func_800A0CF4(arg0, 0);
        /* fallthrough */
    default:
        return;
    }
}

void bsbkflamethrower_entrypoint_1(s32 arg0)
{
    func_80800094_bsbkflamethrower(arg0,0);
}

void bsbkflamethrower_entrypoint_2(s32 *arg0) { arg0[87] = 0; func_80800094_bsbkflamethrower(arg0, 1); }

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bkflamethrower/bsbkflamethrower_entrypoint_3.s")

s32 bsbkflamethrower_entrypoint_4(s32 arg0) {
    extern s32 D_80800450_bsbkflamethrower[];
    return ((s32 *)&D_80800450_bsbkflamethrower)[arg0];
}
