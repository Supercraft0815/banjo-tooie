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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/blongleg/func_80800064_bsblongleg.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/blongleg/func_808000C8_bsblongleg.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/blongleg/func_8080013C_bsblongleg.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/blongleg/func_80800204_bsblongleg.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/blongleg/func_808002D8_bsblongleg.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/blongleg/bsblongleg_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/blongleg/bsblongleg_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/blongleg/bsblongleg_entrypoint_2.s")

s32 bsblongleg_entrypoint_3(s32 arg0) {
    extern s32 D_80801470_bsblongleg[];
    return ((s32 *)&D_80801470_bsblongleg)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/blongleg/bsblongleg_entrypoint_4.s")

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

void bsblongleg_entrypoint_8(s32 arg0) {
    s32 anctrl_reset(s32);
    s32 anctrl_setIndex(s32, s32);
    s32 anctrl_setPlaybackType(s32, s32);
    s32 anctrl_start(s32);
    s32 baanim_getAnimCtrlPtr();
    s32 func_8008C9F0(s32, s32, s32, s32, f32);
    s32 func_8009FFD8(s32, s32, s32, s32, s32);
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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/blongleg/bsblongleg_entrypoint_12.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/blongleg/bsblongleg_entrypoint_13.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/blongleg/bsblongleg_entrypoint_14.s")

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
void bsblongleg_entrypoint_25(s32 arg0)
{
    func_8080013C_bsblongleg();
    _bsrest_entrypoint_16(arg0);
}
void bsblongleg_entrypoint_26(PlayerState *arg0) {
    s32 _bsrest_entrypoint_13(PlayerState *);
    s32 _bsrest_entrypoint_20(PlayerState *);
    void bs_setState(PlayerState *, int);
    void func_8009D3A8(PlayerState *, s32);
    s32 func_808000C8_bsblongleg(PlayerState *);
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

void bsblongleg_entrypoint_28(s32 arg0)
{
    func_8080013C_bsblongleg();
    _bsdrone_entrypoint_0(arg0);
}
/* extern */

void bsblongleg_entrypoint_29(PlayerState *arg0) {
    s32 _bsdrone_entrypoint_1(s32);
    s32 bastatetimer_isDone(s32, s32);
    void bs_setState(PlayerState *, int);
    s32 func_808000C8_bsblongleg();
    func_808000C8_bsblongleg();
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
