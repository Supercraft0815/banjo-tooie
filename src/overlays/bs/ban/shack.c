#include "common.h"
#include "overlays/ba/playerstate.h"

/* extern */

s32 func_80800000_bsbanshack(PlayerState *arg0, s32 arg1) { int bakey_pressed(PlayerState *, ButtonId); int bakey_released(PlayerState *, ButtonId); int func_8008E148(PlayerState *); s32 func_8008E260(PlayerState *); s32 var_s0; var_s0 = arg1;
    if (bakey_pressed(arg0, 8) != 0) {
        var_s0 = 0x16E;
    }
    if (func_8008E148(arg0) != 0) {
        var_s0 = 1;
    }
    if (func_8008E260(arg0) != 0) {
        var_s0 = 0x3D;
    }
    if (bakey_released(arg0, 1) != 0) {
        var_s0 = 0x16B;
    }
    return var_s0;
}

/* extern */

s32 func_80800074_bsbanshack(PlayerState *arg0, s32 arg1) {
    int bakey_pressed(PlayerState *, ButtonId);
    int bakey_released(PlayerState *, ButtonId);
    int bastick_getZone(PlayerState *);
    int func_8008E148(PlayerState *);
    s32 func_8008E260(PlayerState *);
    if (bastick_getZone(arg0) > 0) {
        arg1 = 0x16D;
    }
    if (bakey_pressed(arg0, 8) != 0) {
        arg1 = 0x16E;
    }
    if (func_8008E148(arg0) != 0) {
        arg1 = 1;
    }
    if (func_8008E260(arg0) != 0) {
        arg1 = 0x3D;
    }
    if (bakey_released(arg0, 1) != 0) {
        arg1 = 0x16B;
    }
    return arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/shack/func_80800100_bsbanshack.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/shack/func_80800164_bsbanshack.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/shack/func_8080021C_bsbanshack.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/shack/func_808002AC_bsbanshack.s")

/* extern */

void func_8080030C_bsbanshack(PlayerState *arg0) {
    s32 baanim_playForDuration_onceSmooth(void *, s32, s32);
    s32 bainput_enable(void *, s32, s32);
    void baphysics_set_target_horizontal_velocity(PlayerState *arg0, f32 vel);
    s32 func_8009FFD8(PlayerState *, s32, s32, s32, s32);
    arg0->unk15C.bytes[1] = 0;
    baanim_playForDuration_onceSmooth(arg0, 0x145, 0x3FB33333);
    func_8009FFD8(arg0, 1, 1, 3, 2);
    baphysics_set_target_horizontal_velocity(arg0, 0.0f);
    bainput_enable(arg0, 5, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/shack/func_8080037C_bsbanshack.s")

s32 bsbanshack_entrypoint_0(s32 arg0) {
    extern s32 D_80800CB0_bsbanshack[];
    return ((s32 *)&D_80800CB0_bsbanshack)[arg0];
}

void func_80800430_bsbanshack()
{
    func_80800164_bsbanshack();
}

void func_80800450_bsbanshack(PlayerState *arg0) { s32 baanim_playForDuration_onceSmooth(void *, s32, s32); void baphysics_set_target_horizontal_velocity(PlayerState *, f32); s32 func_8009FFD8(PlayerState *, s32, s32, s32, s32); func_8080021C_bsbanshack(); baanim_playForDuration_onceSmooth(arg0, 0x295, 0x3FB33333); func_8009FFD8(arg0, 1, 1, 1, 2); baphysics_set_target_horizontal_velocity(arg0, 0.0f); }

/* extern */

void func_808004AC_bsbanshack(PlayerState *arg0) {
    struct anctrl_s;
    void _babackpack_set_state(void *, s32);
    int anctrl_isAt(struct anctrl_s *, f32);
    struct anctrl_s *baanim_getAnimCtrlPtr(PlayerState *);
    int baanim_isAt(PlayerState *, f32);
    int baanim_isStopped(PlayerState *);
    void baphysics_set_vertical_velocity(PlayerState *, f32);
    s32 bs_setState(PlayerState *, s32);
    void func_8009DEC0(PlayerState *, s32, f32, f32, s32, s32);
    void func_800A0CD0(void *, s32);
    s32 sp2C;
    struct anctrl_s *sp28;
    struct anctrl_s *temp_v0;

    sp2C = 0;
    temp_v0 = baanim_getAnimCtrlPtr(arg0);
    sp28 = temp_v0;
    if (anctrl_isAt(temp_v0, 0.29f) != 0) {
        func_8009DEC0(arg0, 0x583, 0.95f, 1.05f, 0x55F0, 0x55F0);
    }
    if (anctrl_isAt(sp28, 0.74f) != 0) {
        func_8009DEC0(arg0, 0x584, 0.95f, 1.05f, 0x55F0, 0x55F0);
    }
    if (baanim_isAt(arg0, 0.1351f) != 0) {
        baphysics_set_vertical_velocity(arg0, 600.0f);
    }
    if (baanim_isAt(arg0, 0.6757f) != 0) {
        _babackpack_set_state(arg0, 1);
        func_800A0CD0(arg0, 1);
    }
    if (baanim_isStopped(arg0) != 0) {
        sp2C = 1;
    }
    bs_setState(arg0, sp2C);
}

s32 bsbanshack_entrypoint_1(s32 arg0) {
    extern s32 D_80800CC0_bsbanshack[];
    return ((s32 *)&D_80800CC0_bsbanshack)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/shack/func_808005DC_bsbanshack.s")

void func_80800744_bsbanshack(s32 arg0)
{
    func_808005DC_bsbanshack(arg0,0);
    func_80800164_bsbanshack(arg0);
}

void func_80800770_bsbanshack(s32 arg0)
{
    func_8080021C_bsbanshack();
    *(u8 *)((u8 *)arg0 + 0x15C) = 0;
    func_808005DC_bsbanshack(arg0, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/shack/func_808007A0_bsbanshack.s")

s32 bsbanshack_entrypoint_2(s32 arg0) {
    extern s32 D_80800CD0_bsbanshack[];
    return ((s32 *)&D_80800CD0_bsbanshack)[arg0];
}

void func_80800928_bsbanshack()
{
    func_80800164_bsbanshack();
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/shack/func_80800948_bsbanshack.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/shack/func_808009E4_bsbanshack.s")

s32 bsbanshack_entrypoint_3(s32 arg0) {
    extern s32 D_80800CE0_bsbanshack[];
    return ((s32 *)&D_80800CE0_bsbanshack)[arg0];
}

void func_80800AD0_bsbanshack(s32 arg0)
{
    _bsdrone_entrypoint_2();
    func_80800164_bsbanshack(arg0);
}
void func_80800AF8_bsbanshack(s32 arg0)
{
    func_8080021C_bsbanshack();
    _bsdrone_entrypoint_0(arg0);
}
void func_80800B20_bsbanshack(PlayerState* self)
{
    _bsdrone_entrypoint_1(self);
}
s32 bsbanshack_entrypoint_4(s32 arg0) {
    extern s32 D_80800CF0_bsbanshack[];
    return ((s32 *)&D_80800CF0_bsbanshack)[arg0];
}

void func_80800B54_bsbanshack(s32 arg0)
{
    _bsrest_entrypoint_14();
    func_80800164_bsbanshack(arg0);
}
void func_80800B7C_bsbanshack(s32 arg0)
{
    func_8080021C_bsbanshack();
    _bsrest_entrypoint_16(arg0);
}
void func_80800BA4_bsbanshack(PlayerState *arg0) {
    s32 _bsrest_entrypoint_20();
    s32 bs_setState(PlayerState *, s32);
    s32 next_state;
    s32 unused;

    next_state = 0;
    if (_bsrest_entrypoint_20() != 0) {
        next_state = 0x16C;
    }
    bs_setState(arg0, next_state);
}

s32 bsbanshack_entrypoint_5(s32 arg0) {
    extern s32 D_80800D00_bsbanshack[];
    return ((s32 *)&D_80800D00_bsbanshack)[arg0];
}

void func_80800BF0_bsbanshack()
{
    func_80800164_bsbanshack();
}

void func_80800C10_bsbanshack(PlayerState *arg0) { s32 baanim_playForDuration_loopSmooth(void *, s32, s32); void baphysics_set_target_horizontal_velocity(PlayerState *, f32); s32 func_8009FFD8(PlayerState *, s32, s32, s32, s32); func_8080021C_bsbanshack(); baanim_playForDuration_loopSmooth(arg0, 0x293, 0x40ACCCCD); func_8009FFD8(arg0, 1, 1, 1, 2); baphysics_set_target_horizontal_velocity(arg0, 0.0f); }

/* extern */

void func_80800C6C_bsbanshack(PlayerState *arg0) {
    s32 func_80800074_bsbanshack(PlayerState *, s32);
    s32 bs_setState(PlayerState *, s32);
    bs_setState(arg0, func_80800074_bsbanshack(arg0, 0U));
}

s32 bsbanshack_entrypoint_6(s32 arg0) {
    extern s32 D_80800D10_bsbanshack[];
    return ((s32 *)&D_80800D10_bsbanshack)[arg0];
}
