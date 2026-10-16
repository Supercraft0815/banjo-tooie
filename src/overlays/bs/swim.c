#include "common.h"

/* extern */

s32 func_80800000_bsswim(void) {
    s32 func_8008E23C();
    s32 var_v1;

    if (func_8008E23C() != 0) {
        var_v1 = 0x6D;
    } else {
        var_v1 = 0x30;
    }
    return var_v1;
}

/* extern */

void func_80800030_bsswim(void *arg0) {
    void func_80092C00(void *, f32 *);
    void func_80092C24(void *, f32 *);
    s32 func_80096544(void *);
    s32 func_8009FBB0(void *, f32 *, f32);
    void func_800BA22C(s32, s32);
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

void func_808000E0_bsswim(u32 *arg0, struct anctrl_s *arg1) {
    f32 anctrl_getAnimTimer(struct anctrl_s *);
    int anctrl_getIndex(struct anctrl_s *);
    void anctrl_setIndex(struct anctrl_s *, enum asset_e);
    void anctrl_setStart(struct anctrl_s *, f32);
    void anctrl_start(struct anctrl_s *);
    extern s16 D_80800B90_bsswim[];
    s32 sp24;

    sp24 = D_80800B90_bsswim[arg0[0x57]];
    if (anctrl_getIndex(arg1) != sp24) {
        anctrl_setStart(arg1, anctrl_getAnimTimer(arg1));
        anctrl_setIndex(arg1, sp24);
        anctrl_start(arg1);
    }
    arg0[0x57]++;
    if (arg0[0x57] >= 0xAU) {
        arg0[0x57] = 0U;
    }
}

void func_80800178_bsswim(struct player_state_s *arg0) {
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
    baphysics_set_target_horizontal_velocity(arg0, func_800F1214(sp1C, 30.0f, 300.0f));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/swim/func_808001DC_bsswim.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/swim/func_80800270_bsswim.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/swim/func_808002E0_bsswim.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/swim/func_808004C4_bsswim.s")

void func_80800688_bsswim(s32 arg0)
{
    func_80800270_bsswim();
    func_800A4E30(arg0);
}
s32 bsswim_entrypoint_0(s32 arg0) {
    extern s32 D_80800BA4_bsswim[];
    return ((s32 *)&D_80800BA4_bsswim)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/swim/func_808006C4_bsswim.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/swim/func_808007F8_bsswim.s")

void func_808009F0_bsswim()
{
    func_80800270_bsswim();
}

s32 bsswim_entrypoint_1(s32 arg0) {
    extern s32 D_80800BB4_bsswim[];
    return ((s32 *)&D_80800BB4_bsswim)[arg0];
}

void func_80800A24_bsswim(s32 arg0)
{
    _bsrest_entrypoint_14();
    func_80800270_bsswim(arg0);
}
void func_80800A4C_bsswim(s32 arg0)
{
    func_808001DC_bsswim();
    _bsrest_entrypoint_16(arg0);
}
/* extern */

void func_80800A74_bsswim(s32 arg0) {
    s32 _bsrest_entrypoint_13(s32);
    s32 bs_setState(s32, s32);
    s32 _bsrest_entrypoint_20();
    s32 var_a1;
    s32 sp1C;

    sp1C = 0;
    var_a1 = sp1C;
    if (_bsrest_entrypoint_20() != 0) {
        var_a1 = _bsrest_entrypoint_13(arg0);
    }
    bs_setState(arg0, var_a1);
}

s32 bsswim_entrypoint_2(s32 arg0) {
    extern s32 D_80800BC4_bsswim[];
    return ((s32 *)&D_80800BC4_bsswim)[arg0];
}

void func_80800AC8_bsswim(s32 arg0)
{
    func_808001DC_bsswim();
    _bsdrone_entrypoint_0(arg0);
}
/* extern */

void func_80800AF0_bsswim(s32 arg0) {
    s32 _badrone_entrypoint_30();
    s32 _bsdrone_entrypoint_1(s32);
    s32 bs_setState(s32, s32);
    s32 sp1C;

    sp1C = 0;
    if (_badrone_entrypoint_30() != 0) {
        sp1C = 1;
    }
    _bsdrone_entrypoint_1(arg0);
    bs_setState(arg0, sp1C);
}

void func_80800B34_bsswim(s32 arg0)
{
    _bsdrone_entrypoint_2();
    func_80800270_bsswim(arg0);
}
s32 bsswim_entrypoint_3(s32 arg0) {
    extern s32 D_80800BD4_bsswim[];
    return ((s32 *)&D_80800BD4_bsswim)[arg0];
}
