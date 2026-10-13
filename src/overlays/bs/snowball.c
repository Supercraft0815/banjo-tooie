#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/snowball/func_80800000_bssnowball.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/snowball/func_80800064_bssnowball.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/snowball/bssnowball_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/snowball/bssnowball_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/snowball/bssnowball_entrypoint_2.s")

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
    bssnowball_entrypoint_1();
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
    void func_8009BF5C(s32, f32);
    void baroll_setIdeal(s32, f32);
    func_8009BF5C(arg0, 0.0f);
    baroll_setIdeal(arg0, 0.0f);
    bssnowball_entrypoint_0(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/snowball/func_808005A4_bssnowball.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/snowball/func_80800614_bssnowball.s")

s32 bssnowball_entrypoint_5(s32 arg0) {
    extern s32 D_80801074_bssnowball[];
    return ((s32 *)&D_80801074_bssnowball)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/snowball/func_808006BC_bssnowball.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/snowball/func_808007D8_bssnowball.s")

void func_8080089C_bssnowball(s32 arg0) {
    void func_8009BF5C(s32, f32);
    void baroll_setIdeal(s32, f32);
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

void func_80800910_bssnowball()
{
    bssnowball_entrypoint_0();
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/snowball/func_80800930_bssnowball.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/snowball/func_808009B0_bssnowball.s")

s32 bssnowball_entrypoint_7(s32 arg0) {
    extern s32 D_80801094_bssnowball[];
    return ((s32 *)&D_80801094_bssnowball)[arg0];
}

void func_80800B44_bssnowball(s32 arg0) { _baspin_entrypoint_1(); *(u8 *)(arg0 + 0x165) = 0; bssnowball_entrypoint_0(arg0); }

void func_80800B70_bssnowball(s32 arg0) { bssnowball_entrypoint_1(); *(u8 *)(arg0 + 0x165) = 1; _basnowball_entrypoint_10(arg0); _baspin_entrypoint_2(arg0, 0x5E, 0x3FE66666, 3, 0); }

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
    struct anctrl_s;
    void _babounce_entrypoint_4(struct player_state_s *, s32);
    void _babounce_entrypoint_5(struct player_state_s *, s32, f32);
    struct anctrl_s *baanim_getAnimCtrlPtr(struct player_state_s *);
    void func_8008B10C(struct anctrl_s *, f32);
    bssnowball_entrypoint_1();
    _babounce_entrypoint_4(arg0, 2);
    _babounce_entrypoint_5(arg0, 0x5E, 0.5128f);
    func_8008B10C(baanim_getAnimCtrlPtr(arg0), 0.1026f);
}

/* extern */

void func_80800C98_bssnowball(s32 arg0) {
    s32 _babounce_entrypoint_2();
    s32 _babounce_entrypoint_9(s32);
    s32 bs_setState(s32, s32);
    s32 func_80800064_bssnowball(s32, s32);
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
    bssnowball_entrypoint_1();
    _bsrest_entrypoint_16(arg0);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/snowball/func_80800D50_bssnowball.s")

s32 bssnowball_entrypoint_10(s32 arg0) {
    extern s32 D_808010C4_bssnowball[];
    return ((s32 *)&D_808010C4_bssnowball)[arg0];
}

void func_80800DB0_bssnowball(s32 arg0)
{
    func_80090A2C();
    bssnowball_entrypoint_0(arg0);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/snowball/func_80800DD8_bssnowball.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/snowball/func_80800E4C_bssnowball.s")

s32 bssnowball_entrypoint_11(s32 arg0) {
    extern s32 D_808010D4_bssnowball[];
    return ((s32 *)&D_808010D4_bssnowball)[arg0];
}
