#include "bs/blongleg.h"

s32 func_80800000_bsblongleg(PlayerState* arg0)
{
    return player_inWater(arg0);
}

void func_80800020_bsblongleg(PlayerState *arg0, s32 arg1) {
    void func_8009DE38(PlayerState *, s32, f32);
    if (arg1 != 0) {
        func_8009DE38(arg0, 0x4433, 0.88f);
        return;
    }
    func_8009DE38(arg0, 0x4433, 0.96f);
}

void func_80800064_bsblongleg(PlayerState *arg0) {
    void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
    s32 bastick_getZone(PlayerState *);
    f32 bastick_getZonePosition(PlayerState *);
    f32 func_800F1214(f32, f32, f32);
    f32 sp1C;

    sp1C = bastick_getZonePosition(arg0);
    if (bastick_getZone(arg0) == 0) {
        baphysics_set_target_horizontal_velocity(arg0, 0.0f);
        return;
    }
    baphysics_set_target_horizontal_velocity(arg0, func_800F1214(sp1C, 80.0f, 500.0f));
}

void func_808000C8_bsblongleg(PlayerState *arg0) {
    void _baalarm_entrypoint_3(PlayerState *, f32, f32);
    f32 bastatetimer_get(PlayerState *, int);
    f32 bastatetimer_getPrevious(PlayerState *, int);
    int bastatetimer_isAt(PlayerState *, int, f32);
    void func_8009DE38(PlayerState *, s32, f32);
    f32 sp20[2];

    sp20[0] = bastatetimer_getPrevious(arg0, 2);
    _baalarm_entrypoint_3(arg0, sp20[0], bastatetimer_get(arg0, 2));
    if (bastatetimer_isAt(arg0, 2, 0.01f) != 0) {
        func_8009DE38(arg0, 0x3EB, 1.0f);
    }
}

void func_800931AC(PlayerState *, s32);

void func_8080013C_bsblongleg(PlayerState *arg0) {
    void _baalarm_new(PlayerState *);
    void baflag_set(PlayerState *, s32);
    void baroll_setAngularVelocity(PlayerState *, f32, f32);
    void bastick_setZoneMax(PlayerState *, s32, f32);
    void func_8009BFE4(PlayerState *, f32, f32);
    void func_8009E53C(PlayerState *, s32, f32);
    s32 func_8009E77C(PlayerState *, s32);
    void func_800A0CE8(PlayerState *, s32);
    void func_800A0CF4(PlayerState *, s32);
    void func_800A0DD0(PlayerState *, s32);
    if (func_8009E77C(arg0, 8) == 0) {
        func_8009E53C(arg0, 1, -50.0f);
        bastick_setZoneMax(arg0, 0, 0.03f);
        bastick_setZoneMax(arg0, 1, 1.0f);
        func_800A0CF4(arg0, 1);
        func_800A0CE8(arg0, 1);
        func_800A0DD0(arg0, 1);
        func_8009BFE4(arg0, 1000.0f, 12.0f);
        baroll_setAngularVelocity(arg0, 1000.0f, 12.0f);
        baflag_set(arg0, 3);
        func_800931AC(arg0, 2);
        _baalarm_new(arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/blongleg/func_80800204_bsblongleg.s")

/* extern */

void func_808002D8_bsblongleg(void *arg0) {
    s32 anctrl_reset(s32);
    s32 anctrl_setDuration(s32, s32);
    s32 anctrl_setIndex(s32, s32);
    s32 anctrl_setPlaybackType(s32, s32);
    s32 anctrl_setSmoothTransition(s32, s32);
    s32 anctrl_start(s32);
    s32 baanim_getAnimCtrlPtr();
    s32 bastatetimer_set(void *, s32, f32);
    f32 func_800A3394(void *);
    s32 func_800C3BDC(u8);
    s32 func_800C77DC(s32);
    s32 temp_v0;

    temp_v0 = baanim_getAnimCtrlPtr(arg0);
    anctrl_reset(temp_v0);
    anctrl_setSmoothTransition(temp_v0, 0);
    anctrl_setIndex(temp_v0, 0x40);
    anctrl_setDuration(temp_v0, 0x3F800000);
    anctrl_setPlaybackType(temp_v0, 1);
    anctrl_start(temp_v0);
    bastatetimer_set(arg0, 2, func_800A3394(arg0));
    func_800C77DC(2);
    func_800C3BDC((*(u8 *)((s8 *)(arg0) + (0x160))));
    (*(s32 *)((s8 *)(arg0) + (0x15C))) = 1;
}

/* extern */

void func_80800378_bsblongleg(void *arg0) {
    s32 anctrl_reset(s32);
    s32 anctrl_setDuration(s32, s32);
    s32 anctrl_setIndex(s32, s32);
    s32 anctrl_setPlaybackType(s32, s32);
    s32 anctrl_setSmoothTransition(s32, s32);
    s32 anctrl_start(s32);
    s32 baanim_getAnimCtrlPtr();
    s32 temp_v0;

    temp_v0 = baanim_getAnimCtrlPtr();
    anctrl_reset(temp_v0);
    anctrl_setSmoothTransition(temp_v0, 0);
    anctrl_setIndex(temp_v0, 0x16);
    anctrl_setDuration(temp_v0, 0x3F000000);
    anctrl_setPlaybackType(temp_v0, 1);
    anctrl_start(temp_v0);
    (*(s32 *)((s8 *)(arg0) + (0x15C))) = 0;
}

void bsblongleg_entrypoint_0(PlayerState *arg0) {
    void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
    s32 bs_getPreviousState(PlayerState *);
    s32 func_8009CA70(PlayerState *, s32, s32);
    void func_8009D874(PlayerState *);
    void func_8009FFD8(PlayerState *, s32, s32, s32, s32);
    s32 func_800C2E04(void);
    void func_800C301C(u8, s32);
    void func_800C330C(u8, s32);
    void func_800C3730(u8, f32, f32, f32);
    s32 temp_v0;

    temp_v0 = func_800C2E04();
    arg0->unk160.bytes[0] = temp_v0;
    func_800C301C(temp_v0, 0x41D);
    func_800C330C(arg0->unk160.bytes[0], 3);
    func_800C3730(arg0->unk160.bytes[0], 0.8f, 1.9f, 1.2f);
    baflag_clear(arg0, 0xE);
    if (func_8009CA70(arg0, bs_getPreviousState(arg0), 0x40) != 0) {
        func_808002D8_bsblongleg(arg0);
    } else {
        func_80800378_bsblongleg(arg0);
    }
    func_8009FFD8(arg0, 1, 1, 3, 2);
    baphysics_set_target_horizontal_velocity(arg0, 0.0f);
    func_8080013C_bsblongleg(arg0);
    func_8009D874(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/blongleg/bsblongleg_entrypoint_1.s")

void bsblongleg_entrypoint_2(void *arg0) { func_80800204_bsblongleg(arg0); func_800C2FDC((*(u8 *)((s8 *)(arg0) + 0x160))); }

s32 bsblongleg_entrypoint_3(s32 arg0) {
    extern s32 D_80801470_bsblongleg[];
    return ((s32 *)&D_80801470_bsblongleg)[arg0];
}

void bsblongleg_entrypoint_4(PlayerState *arg0) {
    void baanim_playForDuration_loopSmooth(PlayerState *, s32, f32);
    void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
    void func_8009FFD8(PlayerState *, s32, s32, s32, s32);
    void func_800931AC(PlayerState *, s32);
    baanim_playForDuration_loopSmooth(arg0, 0x41, 1.0f);
    func_8009FFD8(arg0, 1, 1, 1, 2);
    baphysics_set_target_horizontal_velocity(arg0, 0.0f);
    func_800931AC(arg0, 2);
    func_8080013C_bsblongleg(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/blongleg/bsblongleg_entrypoint_5.s")

void bsblongleg_entrypoint_6()
{
    func_80800204_bsblongleg();
}

s32 bsblongleg_entrypoint_7(s32 arg0) {
    extern s32 D_80801480_bsblongleg[];
    return ((s32 *)&D_80801480_bsblongleg)[arg0];
}

/* extern */

void bsblongleg_entrypoint_8(PlayerState *arg0) {
    s32 anctrl_reset(s32);
    s32 anctrl_setIndex(s32, s32);
    s32 anctrl_setPlaybackType(s32, s32);
    s32 anctrl_start(s32);
    s32 baanim_getAnimCtrlPtr();
    s32 func_8008C9F0(s32, s32, s32, s32, f32);
    void func_8009FFD8(PlayerState *, s32, s32, s32, s32);
    s32 sp24;
    s32 temp_v0;

    temp_v0 = baanim_getAnimCtrlPtr();
    sp24 = temp_v0;
    anctrl_reset(temp_v0);
    anctrl_setIndex(sp24, 0x42);
    anctrl_setPlaybackType(sp24, 2);
    anctrl_start(sp24);
    func_8009FFD8(arg0, 2, 1, 1, 2);
    func_8008C9F0(arg0, 0x42A00000, 0x43FA0000, 0x3F800000, 0.8f);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/blongleg/bsblongleg_entrypoint_9.s")

void bsblongleg_entrypoint_10()
{
    func_80800204_bsblongleg();
}

s32 bsblongleg_entrypoint_11(s32 arg0) {
    extern s32 D_80801490_bsblongleg[];
    return ((s32 *)&D_80801490_bsblongleg)[arg0];
}

/* extern */

void func_80800994_bsblongleg(void *arg0) {
    s32 anctrl_reset(s32);
    s32 anctrl_setDuration(s32, s32);
    s32 anctrl_setIndex(s32, s32);
    s32 anctrl_setPlaybackType(s32, s32);
    s32 anctrl_setSmoothTransition(s32, s32);
    s32 anctrl_start(s32);
    s32 baanim_getAnimCtrlPtr();
    s32 func_8008B188(s32, s32);
    s32 temp_v0;

    temp_v0 = baanim_getAnimCtrlPtr();
    anctrl_reset(temp_v0);
    anctrl_setSmoothTransition(temp_v0, 0);
    func_8008B188(temp_v0, 0);
    anctrl_setIndex(temp_v0, 0x40);
    anctrl_setDuration(temp_v0, 0x3ECCCCCD);
    anctrl_setPlaybackType(temp_v0, 1);
    anctrl_start(temp_v0);
    (*(s32 *)((s8 *)(arg0) + (0x15C))) = 0;
}

/* extern */

void func_80800A18_bsblongleg(void *arg0) {
    s32 anctrl_reset(s32);
    s32 anctrl_setDuration(s32, s32);
    s32 anctrl_setIndex(s32, s32);
    s32 anctrl_setPlaybackType(s32, s32);
    s32 anctrl_setSmoothTransition(s32, s32);
    s32 anctrl_start(s32);
    s32 baanim_getAnimCtrlPtr();
    s32 temp_v0;

    temp_v0 = baanim_getAnimCtrlPtr();
    anctrl_reset(temp_v0);
    anctrl_setSmoothTransition(temp_v0, 0);
    anctrl_setIndex(temp_v0, 7);
    anctrl_setDuration(temp_v0, 0x3E99999A);
    anctrl_setPlaybackType(temp_v0, 1);
    anctrl_start(temp_v0);
    (*(s32 *)((s8 *)(arg0) + (0x15C))) = 1;
}

void bsblongleg_entrypoint_12(PlayerState *arg0) {
    void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
    s32 func_8008CA4C(void *, s32);
    void func_8009D2D8(PlayerState *, s32);
    s32 func_800C2E04(void);
    void func_800C301C(u8, s32);
    void func_800C330C(u8, s32);
    void func_800C3730(u8, f32, f32, f32);
    u8 index;

    func_80800994_bsblongleg(arg0);
    func_8008CA4C(arg0, 1);
    func_8009D2D8(arg0, 2);
    baphysics_set_target_horizontal_velocity(arg0, 0.0f);
    index = func_800C2E04();
    *(u8 *)((s8 *)arg0 + 0x160) = index;
    func_800C301C(index, 0x41D);
    func_800C330C(*(u8 *)((s8 *)arg0 + 0x160), 3);
    func_800C3730(*(u8 *)((s8 *)arg0 + 0x160), 1.4f, 0.4f, -1.2f);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/blongleg/bsblongleg_entrypoint_13.s")

void bsblongleg_entrypoint_14(void *arg0) { func_800C2FDC((*(u8 *)((s8 *)(arg0) + 0x160))); func_80800204_bsblongleg(arg0); }

s32 bsblongleg_entrypoint_15(s32 arg0) {
    extern s32 D_808014A0_bsblongleg[];
    return ((s32 *)&D_808014A0_bsblongleg)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/blongleg/bsblongleg_entrypoint_16.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/blongleg/bsblongleg_entrypoint_17.s")

void bsblongleg_entrypoint_18(s32 arg0)
{
    baphysics_reset_gravity();
    func_80800204_bsblongleg(arg0);
}
s32 bsblongleg_entrypoint_19(s32 arg0) {
    extern s32 D_808014B0_bsblongleg[];
    return ((s32 *)&D_808014B0_bsblongleg)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/blongleg/bsblongleg_entrypoint_20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/blongleg/bsblongleg_entrypoint_21.s")

void bsblongleg_entrypoint_22()
{
    func_80800204_bsblongleg();
}

s32 bsblongleg_entrypoint_23(s32 arg0) {
    extern s32 D_808014C0_bsblongleg[];
    return ((s32 *)&D_808014C0_bsblongleg)[arg0];
}

void bsblongleg_entrypoint_24(s32 arg0)
{
    _bsrest_entrypoint_14();
    func_80800204_bsblongleg(arg0);
}
void bsblongleg_entrypoint_25(PlayerState *arg0)
{
    func_8080013C_bsblongleg(arg0);
    _bsrest_entrypoint_16(arg0);
}
void bsblongleg_entrypoint_26(PlayerState *arg0) {
    s32 _bsrest_entrypoint_13(PlayerState *);
    s32 _bsrest_entrypoint_20(PlayerState *);
    void bs_setState(PlayerState *, int);
    void func_8009D3A8(PlayerState *, s32);
    void func_808000C8_bsblongleg(PlayerState *);
    s32 sp24;

    sp24 = 0;
    func_808000C8_bsblongleg(arg0);
    func_8009D3A8(arg0, 1);
    if (_bsrest_entrypoint_20(arg0) != 0) {
        sp24 = _bsrest_entrypoint_13(arg0);
    }
    bs_setState(arg0, sp24);
}

s32 bsblongleg_entrypoint_27(s32 arg0) {
    extern s32 D_808014D0_bsblongleg[];
    return ((s32 *)&D_808014D0_bsblongleg)[arg0];
}

void bsblongleg_entrypoint_28(PlayerState *arg0)
{
    func_8080013C_bsblongleg(arg0);
    _bsdrone_entrypoint_0(arg0);
}
/* extern */

void bsblongleg_entrypoint_29(PlayerState *arg0) {
    s32 _bsdrone_entrypoint_1(s32);
    s32 bastatetimer_isDone(s32, s32);
    void bs_setState(PlayerState *, int);
    void func_808000C8_bsblongleg(PlayerState *);
    func_808000C8_bsblongleg(arg0);
    _bsdrone_entrypoint_1(arg0);
    if (bastatetimer_isDone(arg0, 2) != 0) {
        bs_setState(arg0, 0x29);
    }
}

void bsblongleg_entrypoint_30(s32 arg0)
{
    _bsdrone_entrypoint_2();
    func_80800204_bsblongleg(arg0);
}
s32 bsblongleg_entrypoint_31(s32 arg0) {
    extern s32 D_808014E0_bsblongleg[];
    return ((s32 *)&D_808014E0_bsblongleg)[arg0];
}
