#include "bs_script.h"
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
    void _baflamethrower_entrypoint_1(BtIntPtr arg0);
    void _baflamethrower_entrypoint_2(BtIntPtr arg0, BtIntPtr arg1);
    void _baflamethrower_entrypoint_3(BtIntPtr arg0);
    void _baflamethrower_entrypoint_4(BtIntPtr arg0);
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

void bsbkflamethrower_entrypoint_1(BtIntPtr arg0)
{
    func_80800094_bsbkflamethrower(arg0,0);
}

void bsbkflamethrower_entrypoint_2(s32 *arg0) { arg0[87] = 0; func_80800094_bsbkflamethrower(arg0, 1); }

void bsbkflamethrower_entrypoint_3(struct player_state_s *arg0) {
    s32 _batimer_decrement(void *, s32);
    f32 _batimer_get(void *, s32);
    int _batimer_isZero(struct player_state_s *, s32);
    int bakey_pressed(struct player_state_s *, int);
    int bakey_released(struct player_state_s *, int);
    int baanim_isAt(struct player_state_s *, f32);
    int baanim_isStopped(struct player_state_s *);
    f32 baanim_getTimer(struct player_state_s *);
    void func_8009DF18(struct player_state_s *, s32, f32, s32);
    s32 _bsstand_entrypoint_8(struct player_state_s *, s32);
    void _baflamethrower_entrypoint_5(struct player_state_s *);
    void bs_setState(void *self, s32 nextState);
    s32 sp24;

    sp24 = 0;
    if (_batimer_get(arg0, 0) != 0.0f && bakey_pressed(arg0, 9)) {
        sp24 = 0x189;
    }
    _batimer_decrement(arg0, 0);
    switch (((s32 *)arg0)[87]) {
    case 1:
        if (baanim_isAt(arg0, 0.22f)) {
            func_8009DF18(arg0, 0x459F, 1.0f, 0x6590);
        }
        if (baanim_isAt(arg0, 0.4f)) {
            func_80800094_bsbkflamethrower(arg0, 2);
        }
        break;
    case 2:
        _batimer_decrement(arg0, 2);
        if (_batimer_isZero(arg0, 2) && bakey_released(arg0, 9)) {
            func_80800094_bsbkflamethrower(arg0, 3);
        }
        break;
    case 3:
        if (_batimer_decrement(arg0, 1)) {
            func_80800094_bsbkflamethrower(arg0, 4);
        }
        break;
    case 4:
        if (baanim_isStopped(arg0)) {
            sp24 = 1;
        }
        if (baanim_getTimer(arg0) > 0.7f) {
            sp24 = _bsstand_entrypoint_8(arg0, sp24);
        }
        break;
    }
    _baflamethrower_entrypoint_5(arg0);
    bs_setState(arg0, sp24);
}

BsScript bsbkflamethrower_entrypoint_4(BsScriptType arg0) {
    extern BtIntPtr D_80800450_bsbkflamethrower[];
    return (BsScript)D_80800450_bsbkflamethrower[arg0];
}
/* data_to_c.py: from asm/data/overlays/bs/bkflamethrower.data.s */
void _bsbkflamethrower_entrypoint_1();
void _bsbkflamethrower_entrypoint_2();
void _bsbkflamethrower_entrypoint_3();
void func_80099B94();
BtIntPtr D_80800450_bsbkflamethrower [4] BT_DATA(4, overlays_bs_bkflamethrower, 0x0) = { (BtIntPtr)_bsbkflamethrower_entrypoint_1, (BtIntPtr)_bsbkflamethrower_entrypoint_2, (BtIntPtr)_bsbkflamethrower_entrypoint_3, (BtIntPtr)func_80099B94 };
