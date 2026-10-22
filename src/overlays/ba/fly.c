#include "common.h"

s32 bafly_entrypoint_0() 
{
    return 0x10;
}

struct player_state_s;

void bafly_entrypoint_1(struct player_state_s *arg0, f32 *arg1, s32 *arg2, f32 arg3) {
    void _baeggfire_entrypoint_3(struct player_state_s *, f32 *, f32 *);
    int baflag_isTrue(struct player_state_s *, s32);
    f32 *func_800A4C48(struct player_state_s *);
    void func_800CA740(void *, f32 *);
    void func_800CA9D8(f32 *, s32 *);
    void func_800EF334(f32 *, f32);
    f32 sp24[3];

    if (baflag_isTrue(arg0, 0x30) != 0) {
        _baeggfire_entrypoint_3(arg0, sp24, arg1);
        func_800EF334(arg1, arg3);
        func_800CA9D8(func_800A4C48(arg0), arg2);
        return;
    }
    func_800CA740(func_800A4C48(arg0), arg1);
    func_800EF334(arg1, arg3);
    func_800CA9D8(func_800A4C48(arg0), arg2);
}

/* extern */

typedef struct player_state_s PlayerState;

int bafly_entrypoint_2(PlayerState *arg0) {
    int player_isStable(PlayerState *);
    s32 func_80096628(PlayerState *);

    if (player_isStable(arg0) == 0) {
        return 0;
    }
    if (func_80096628(arg0) & 0x100000) {
        return 0;
    }
    return 1;
}

u32 bafly_entrypoint_3(void *arg0) {
    return *(u8 *)((u8 *)*(void **)((u8 *)arg0 + 140) + 8);
}

/* extern */

void bafly_entrypoint_4(void *arg0) {
    s32 func_800C2FDC(s32, u8, void *);
    u8 temp_a1;

    temp_a1 = (*(u8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x8C)))) + (9)));
    if (temp_a1 != 0) {
        func_800C2FDC(temp_a1 & 0xFF, temp_a1, arg0);
        (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x8C)))) + (9))) = 0;
    }
}

/* extern */

void bafly_entrypoint_5(void *arg0) {
    s32 _gcstatusDll_entrypoint_11();
    u8 func_800C2E04();
    s32 func_800C3418(u8, s32);
    s32 func_800EA05C();
    s32 temp_v0;

    if (_gcstatusDll_entrypoint_11() >= 2) {
        (*(u8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x8C)))) + (9))) = 0U;
    } else {
        (*(u8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x8C)))) + (9))) = func_800C2E04();
        func_800C3418((*(u8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x8C)))) + (9))), 0);
    }
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x8C)))) + (4))) = 1.0f;
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x8C)))) + (0))) = 0.0f;
    (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x8C)))) + (8))) = 0;
    temp_v0 = func_800EA05C();
    if ((temp_v0 != 0xE4) && (temp_v0 != 0x17B)) {
        (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x8C)))) + (0xE))) = 0;
        return;
    }
    (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x8C)))) + (0xE))) = 1;
}

void bafly_entrypoint_6(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 140) + 0) = arg1;
}

void bafly_entrypoint_7(void *arg0, s32 arg1) {
    *(s8 *)((u8 *)*(void **)((u8 *)arg0 + 140) + 8) = arg1;
}

void bafly_entrypoint_8(PlayerState *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7) {
    int baflag_isTrue(PlayerState *, s32);
    void baphysics_set_gravity(PlayerState *, f32);
    void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
    void baphysics_set_target_yaw(PlayerState *, f32);
    void baphysics_set_terminal_velocity(PlayerState *, f32);
    void func_80096394(PlayerState *, f32 *);
    s32 func_8009650C(PlayerState *);
    void func_8009BA9C(PlayerState *, f32 *);
    f32 func_8009BFCC(PlayerState *);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    f32 yaw_get(PlayerState *);
    f32 sp44[3];
    f32 temp_f20;
    f32 sp3C;

    temp_f20 = func_8009BFCC(arg0);
    baphysics_set_gravity(arg0, arg4);
    bafly_entrypoint_6(arg0, 0.0f);
    if (baflag_isTrue(arg0, 9) != 0) {
        baphysics_set_terminal_velocity(arg0, 0.0f);
        func_8009BA9C(arg0, 0);
        sp3C = 0.0f;
    } else if (temp_f20 <= arg2) {
        baphysics_set_terminal_velocity(arg0, func_800F10B4(temp_f20, arg2 - 20.0f, arg2, arg5, arg7));
        baphysics_set_gravity(arg0, func_800F10B4(temp_f20, arg2 - 20.0f, arg2, arg4, arg6));
        sp3C = func_800F10B4(temp_f20, arg2 - 20.0f, arg2, arg3, arg3 / 10.0f);
        bafly_entrypoint_6(arg0, func_800F10B4(temp_f20, arg2 - 20.0f, arg2, 0.0f, 0.35f));
    } else {
        baphysics_set_terminal_velocity(arg0, func_800F10B4(temp_f20, arg1, arg1 + 10.0f, -399.99f, arg5));
        sp3C = func_800F10B4(temp_f20, arg1, arg1 + 40.0f, 0.0f, arg3);
        bafly_entrypoint_6(arg0, func_800F10B4(temp_f20, arg1, arg1 + 40.0f, -0.25f, 0.0f));
    }
    func_80096394(arg0, sp44);
    if ((func_8009650C(arg0) != 0) && (sp44[1] > -1.0f)) {
        sp3C = 0.0f;
    }
    baphysics_set_target_yaw(arg0, yaw_get(arg0));
    baphysics_set_target_horizontal_velocity(arg0, sp3C);
}

/* extern */

void bafly_entrypoint_9(s32 arg0) {
    f32 _bafpctrl_entrypoint_3(PlayerState *);
    s32 bakey_held(s32, s32);
    s32 baroll_setIdeal(s32, f32);
    f32 bastick_getX(s32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    f32 yaw_getIdeal(s32);
    s32 yaw_setIdeal(s32, f32);
    s32 yaw_setVelocityBounded(s32, s32, s32);
    f32 sp34;
    f32 var_f2;
    f32 var_f0;
    f32 sp28;

    sp28 = bastick_getX(arg0);
    if (bakey_held(arg0, 3) != 0) {
        yaw_setVelocityBounded(arg0, 0x43FA0000, 0x41F00000);
        var_f2 = 6.0f;
        var_f0 = 85.0f;
    } else {
        yaw_setVelocityBounded(arg0, 0x43FA0000, 0x40000000);
        var_f2 = 3.0f;
        var_f0 = 75.0f;
    }
    baroll_setIdeal(arg0, func_800F10B4(sp28, -1.0f, 1.0f, -var_f0, var_f0));
    sp34 = func_800F10B4(sp28, -1.0f, 1.0f, var_f2, -var_f2);
    sp34 *= _bafpctrl_entrypoint_3(arg0);
    yaw_setIdeal(arg0, yaw_getIdeal(arg0) + sp34);
}

void bafly_entrypoint_10(PlayerState *arg0, f32 arg1, f32 arg2) {
    f32 bastick_getY(PlayerState *);
    void func_8009BF5C(PlayerState *, f32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    f32 temp_f0;

    temp_f0 = bastick_getY(arg0);
    if (temp_f0 < 0.0f) {
        func_8009BF5C(arg0, func_800F10B4(temp_f0, -1.0f, 0.0f, arg1, 360.0f));
    } else {
        func_8009BF5C(arg0, func_800F10B4(temp_f0, 0.0f, 1.0f, 0.0f, arg2));
    }
}

void bafly_entrypoint_11(PlayerState *arg0) {
    PlayerState *func_800A4CA8(PlayerState *);
    void func_800C301C(u8, s32);
    void func_800C3058(u8, s32);
    void func_800C31DC(u8, f32);
    void func_800C330C(u8, s32);
    void func_800C3BDC(u8);
    int func_800C3D78(u8);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    f32 func_800F1DCC(f32, f32);
    void func_80110818(void *, f32 *);
    f32 mlAbsF(f32);
    f32 yaw_get(PlayerState *);
    u8 id;
    f32 delta;
    f32 volume;
    f32 rotation[3];
    PlayerState *entity;

    volume = 1.2f;
    if ((*(u8 **)((u8 *)arg0 + 0x8C))[8] != 0) {
        volume += 0.4f;
    }
    entity = func_800A4CA8(arg0);
    func_80110818(entity, rotation);
    delta = yaw_get(arg0);
    delta = func_800F1DCC(rotation[1] + 180.0f, delta);
    delta = func_800F10B4(mlAbsF(delta), 0.0f, 50.0f, 0.0f, 0.4f);
    volume -= delta;
    volume += *(f32 *)(*(u8 **)((u8 *)arg0 + 0x8C));
    delta = volume - *(f32 *)(*(u8 **)((u8 *)arg0 + 0x8C) + 4);
    if (mlAbsF(delta) > 0.01f) {
        if (delta > 0.0f) {
            delta = 0.01f;
        } else {
            delta = -0.01f;
        }
    }
    *(f32 *)(*(u8 **)((u8 *)arg0 + 0x8C) + 4) += delta;
    id = (*(u8 **)((u8 *)arg0 + 0x8C))[9];
    if (id != 0) {
        func_800C31DC(id, *(f32 *)(*(u8 **)((u8 *)arg0 + 0x8C) + 4));
        func_800C31DC(id, *(f32 *)(*(u8 **)((u8 *)arg0 + 0x8C) + 4));
        func_800C3058(id, 6000);
        if (func_800C3D78(id) == 0) {
            func_800C301C(id, 0x4A3);
            func_800C330C(id, 3);
            func_800C3BDC(id);
        }
    }
}

/* extern */

s32 bafly_entrypoint_12(void *arg0) {
    s32 _suinv_entrypoint_0(s32 *, s32, s32, s32, s32);
    s32 sp24;

    if ((*(u8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x8C)))) + (0xE))) != 0) {
        return 1;
    }
    _suinv_entrypoint_0(&sp24, 0, 1, 0x46, 1);
    return sp24;
}

void bafly_entrypoint_13(PlayerState *arg0, s32 arg1, s32 arg2, f32 arg3) {
    void _bamotor_entrypoint_1(PlayerState *, f32, f32, f32);
    void _ncbafly_entrypoint_4(PlayerState *, f32, f32, f32);
    s32 baanim_playForDuration_once(void *, s32, f32);
    f32 baphysics_get_target_horizontal_velocity(PlayerState *);
    void baphysics_set_gravity(PlayerState *, f32);
    void baphysics_set_horizontal_velocity(PlayerState *, f32, f32);
    void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
    void baphysics_set_target_yaw(PlayerState *, f32);
    void baphysics_set_terminal_velocity(PlayerState *, f32);
    void baphysics_set_vertical_velocity(PlayerState *, f32);
    f32 func_800136E4(f32);
    void func_8008E944(PlayerState *);
    void func_8009C128(PlayerState *, f32[3]);
    void func_8009D9D4(PlayerState *);
    void func_8009FFD8();
    void func_800A32C4(PlayerState *, f32[3]);
    PlayerState *func_800A4CA8(PlayerState *);
    void func_800A4DA4(PlayerState *, s32);
    s32 func_800E1610(s32, f32, f32, f32 *);
    s32 func_800F1E6C(f32 *, f32 *, f32 *);
    void yaw_applyIdeal(PlayerState *);
    s32 yaw_setIdeal(s32, f32);
    f32 sp54[3];
    f32 sp48[3];
    f32 sp44;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp30[2];

    if (arg1 == 0) {
        sp44 = -2200.0f;
        sp38 = 800.0f;
    } else {
        sp44 = -1200.0f;
        sp38 = 400.0f;
    }
    func_8009C128(arg0, sp54);
    func_800E1610(2, 100.0f, 0.85f, sp54);
    baanim_playForDuration_once(arg0, arg2, arg3);
    func_8009D9D4(arg0);
    _bamotor_entrypoint_1(arg0, 1.0f, 0.5f, 0.5f);
    func_800A32C4(arg0, sp48);
    func_800F1E6C(sp48, sp54, &sp40);
    yaw_setIdeal(arg0, func_800136E4(sp40 + 180.0f));
    yaw_applyIdeal(arg0);
    baphysics_set_target_horizontal_velocity(arg0, sp38);
    baphysics_set_target_yaw(arg0, sp40);
    baphysics_set_horizontal_velocity(arg0, sp40, baphysics_get_target_horizontal_velocity(arg0));
    func_8009FFD8(arg0, 1, 1, 2, 3);
    baphysics_set_vertical_velocity(arg0, 800.0f);
    baphysics_set_gravity(arg0, sp44);
    baphysics_set_terminal_velocity(arg0, -4000.0f);
    func_800A4DA4(arg0, 3);
    _ncbafly_entrypoint_4(func_800A4CA8(arg0), 12.0f, 10000.0f, 800.0f);
    func_8008E944(arg0);
}

/* extern */

void bafly_entrypoint_14(PlayerState *arg0, s32 arg1, s32 arg2) {
    s32 anctrl_isStopped(s32);
    s32 baanim_getAnimCtrlPtr();
    void bs_setState(PlayerState *, s32);
    int player_isStable(PlayerState *);
    s32 sp1C;

    sp1C = 0;
    if (anctrl_isStopped(baanim_getAnimCtrlPtr()) != 0) {
        sp1C = arg1;
    }
    if (player_isStable(arg0) != 0) {
        sp1C = arg2;
    }
    bs_setState(arg0, sp1C);
}

void bafly_entrypoint_15(s32 arg0) { func_8009BC34(); func_8008E95C(arg0); func_8009BD88(arg0); func_800A4E30(arg0); }

/* extern */

void bafly_entrypoint_16(PlayerState *arg0, s32 arg1, f32 arg2) {
    void _ncbafly_entrypoint_4(PlayerState *, f32, f32, f32);
    s32 baanim_playForDuration_once(void *, s32, f32);
    f32 baphysics_get_target_horizontal_velocity(PlayerState *);
    void baphysics_set_gravity(PlayerState *, f32);
    void baphysics_set_horizontal_velocity(PlayerState *, f32, f32);
    void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
    void baphysics_set_target_yaw(PlayerState *, f32);
    void baphysics_set_vertical_velocity(PlayerState *, f32);
    f32 func_800136E4(f32);
    void func_8008E944(PlayerState *);
    void func_8009C128(PlayerState *, f32[3]);
    void func_8009DA40(PlayerState *);
    void func_8009FFD8(PlayerState *, enum baanim_update_type_e, enum yaw_type_e, s32, enum ba_physics_type_e);
    void func_800A32C4(PlayerState *, f32[3]);
    PlayerState *func_800A4CA8(PlayerState *);
    void func_800A4DA4(PlayerState *, s32);
    s32 func_800E1610(s32, f32, f32, f32 *);
    s32 func_800F1E6C(f32 *, f32 *, f32 *);
    void yaw_applyIdeal(PlayerState *);
    s32 yaw_setIdeal(s32, f32);
    f32 sp4C;
    f32 sp40[3];
    f32 sp34[3];

    func_8009C128(arg0, sp40);
    func_800E1610(2, 100.0f, 0.85f, sp40);
    baanim_playForDuration_once(arg0, arg1, arg2);
    func_8009DA40(arg0);
    func_800A32C4(arg0, sp34);
    func_800F1E6C(sp34, sp40, &sp4C);
    yaw_setIdeal(arg0, func_800136E4(sp4C + 180.0f));
    yaw_applyIdeal(arg0);
    baphysics_set_target_horizontal_velocity(arg0, 1300.0f);
    baphysics_set_target_yaw(arg0, sp4C);
    baphysics_set_horizontal_velocity(arg0, sp4C, baphysics_get_target_horizontal_velocity(arg0));
    func_8009FFD8(arg0, 1, 1, 2, 3);
    baphysics_set_vertical_velocity(arg0, 400.0f);
    baphysics_set_gravity(arg0, -1800.0f);
    func_8008E944(arg0);
    func_800A4DA4(arg0, 3);
    _ncbafly_entrypoint_4(func_800A4CA8(arg0), 12.0f, 10000.0f, 800.0f);
}

/* extern */

void bafly_entrypoint_17(PlayerState *arg0, s32 arg1, s32 arg2, s32 *arg3) {
    s32 anctrl_isStopped(s32);
    s32 baanim_getAnimCtrlPtr();
    void bs_setState(PlayerState *, s32);
    int func_8008DD04(PlayerState *);
    s32 func_8009650C(PlayerState *);
    int player_isStable(PlayerState *);
    s32 sp24;
    s32 sp20;

    sp24 = 0;
    sp20 = baanim_getAnimCtrlPtr(arg0);
    if (player_isStable(arg0) != 0) {
        sp24 = arg2;
    }
    if ((anctrl_isStopped(sp20) != 0) && ((func_8008DD04(arg0) != 0) || (func_8009650C(arg0) != 0))) {
        *arg3 = 1;
        sp24 = arg1;
    }
    bs_setState(arg0, sp24);
}

void bafly_entrypoint_18(s32 arg0)
{
    baphysics_reset_gravity();
    func_8008E95C(arg0);
}
/* extern */

void bafly_entrypoint_19(s32 arg0) {
    s32 _bafpctrl_entrypoint_11(s32, s32, s32);
    s32 _bafpctrl_entrypoint_14(s32, s32);
    s32 _bafpctrl_entrypoint_4();
    s32 _bafpctrl_entrypoint_9(s32, s32);
    int baflag_isTrue(PlayerState *, s32);
    s32 func_800C6E38(s32);
    if (_bafpctrl_entrypoint_4() != 3) {
        if (baflag_isTrue(arg0, 0x2F) != 0) {
            _bafpctrl_entrypoint_14(arg0, 3);
        } else {
            _bafpctrl_entrypoint_14(arg0, 2);
        }
        _bafpctrl_entrypoint_9(arg0, 1);
        if (func_800C6E38(0x1B) == 0) {
            _bafpctrl_entrypoint_11(arg0, 4, 1);
        }
    }
}

void bafly_entrypoint_20(PlayerState *arg0) {
    f32 _bafpctrl_entrypoint_3(PlayerState *);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    void func_8009BFE4(PlayerState *, f32, f32);
    f32 value;

    value = _bafpctrl_entrypoint_3(arg0);
    value = func_800F10B4(value, 0.1f, 1.0f, value * value, 1.0f);
    func_8009BFE4(arg0, 500.0f * value, 1.2f);
}

void bafly_entrypoint_21(PlayerState *arg0) {
    f32 _bafpctrl_entrypoint_3(PlayerState *);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    void func_8009BFE4(PlayerState *, f32, f32);
    f32 value;

    value = _bafpctrl_entrypoint_3(arg0);
    value = func_800F10B4(value, 0.1f, 1.0f, value * value, 1.0f);
    func_8009BFE4(arg0, 1000.0f * value, 2.2f);
}
