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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/fly/bafly_entrypoint_8.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/fly/bafly_entrypoint_11.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/fly/bafly_entrypoint_13.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/fly/bafly_entrypoint_16.s")

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
