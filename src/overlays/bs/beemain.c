#include "common.h"

struct player_state_s;
void _babee_entrypoint_2(struct player_state_s *self);
extern s32 _badrone_entrypoint_3(struct player_state_s *self);
extern void _bsdrone_entrypoint_1(struct player_state_s *self);

void func_80800000_bsbeemain(s32 arg0) {
    s32 func_8009DF18(s32, s32, f32, s32);
    func_8009DF18(arg0, 0x41F, 1.4f, 0x1F40);
}

/* extern */

void func_8080002C_bsbeemain(s32 arg0) {
    s32 func_8009D7A4(s32, f32, f32);
    func_8009D7A4(arg0, 1.35f, 1.45f);
}

void func_80800058_bsbeemain(struct player_state_s *arg0) {
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
    baphysics_set_target_horizontal_velocity(arg0, func_800F1214(sp1C, 30.0f, 375.0f));
}

void func_808000C0_bsbeemain(void *arg0) {
    void *self;
    s32 baanim_playForDuration_loopSmooth(void *, s32, s32);
    void baphysics_set_target_horizontal_velocity(struct player_state_s *, f32);
    self = arg0;
    _bsbee_entrypoint_1(self);
    baanim_playForDuration_loopSmooth(self, 0x1DE, 0x40400000);
    func_8009FFD8(self, 1, 1, 1, 2);
    baphysics_set_target_horizontal_velocity(self, 0.0f);
    func_800909CC(self);
}

/* extern */

void func_80800128_bsbeemain(struct player_state_s *arg0) {
    s32 _badrone_entrypoint_24(struct player_state_s *);
    s32 _bsbee_entrypoint_2();
    int bainput_should_enter_first_person(struct player_state_s *);
    int bakey_held(struct player_state_s *, s32);
    int bakey_pressed(struct player_state_s *, s32);
    s32 bastick_getZone(struct player_state_s *);
    s32 bs_setState(s32, s32);
    int func_8008DD04(struct player_state_s *);
    void func_8009D3A8(struct player_state_s *, s32);
    s32 func_800A02DC(struct player_state_s *, s32);
    s32 player_inWater(struct player_state_s *);
    s32 var_s1;

    var_s1 = 0;
    _bsbee_entrypoint_2();
    func_8009D3A8(arg0, 0);
    if (func_8008DD04(arg0) != 0) {
        var_s1 = 0x88;
    }
    if (bakey_held(arg0, 1) != 0) {
        _babee_entrypoint_2(arg0);
    }
    if (bainput_should_enter_first_person(arg0) != 0) {
        var_s1 = _badrone_entrypoint_24(arg0);
    }
    if (bastick_getZone(arg0) > 0) {
        var_s1 = 0x86;
    }
    if (bakey_pressed(arg0, 8) != 0) {
        var_s1 = 0x87;
    }
    if (player_inWater(arg0) != 0) {
        var_s1 = 0x8C;
    }
    bs_setState(arg0, func_800A02DC(arg0, var_s1));
}

void func_808001FC_bsbeemain(s32 arg0)
{
    func_80090A2C();
    _bsbee_entrypoint_0(arg0);
}
s32 bsbeemain_entrypoint_0(s32 arg0) {
    extern s32 D_80801260_bsbeemain[];
    return ((s32 *)&D_80801260_bsbeemain)[arg0];
}

void func_80800238_bsbeemain(struct player_state_s *arg0) {
    s32 baanim_playForDuration_loopSmooth(void *, s32, s32);
    void func_8008C9F0(struct player_state_s *, f32, f32, f32, f32);

    _bsbee_entrypoint_1(arg0);
    baanim_playForDuration_loopSmooth(arg0, 0x1DD, 0x3EC28F5C);
    func_8009FFD8(arg0, 2, 1, 1, 2);
    func_8008C9F0(arg0, 30.0f, 375.0f, 0.6f, 0.4f);
    func_800909CC(arg0);
}

/* extern */

void func_808002C0_bsbeemain(struct player_state_s *arg0) {
    s32 _bsbee_entrypoint_2();
    int bakey_held(struct player_state_s *, s32);
    int bakey_pressed(struct player_state_s *, s32);
    s32 bastick_getZone(struct player_state_s *);
    s32 bs_setState(s32, s32);
    int func_8008DD04(struct player_state_s *);
    s32 func_8009BCD4(struct player_state_s *, f32);
    void func_8009D3A8(struct player_state_s *, s32);
    void func_800A2CE8(struct player_state_s *, f32, s32);
    void func_80800058_bsbeemain(struct player_state_s *);
    s32 player_inWater(struct player_state_s *);
    s32 sp24;

    sp24 = 0;
    _bsbee_entrypoint_2();
    func_8009D3A8(arg0, 0);
    func_80800058_bsbeemain(arg0);
    func_800A2CE8(arg0, 0.94f, 4);
    func_800A2CE8(arg0, 0.44f, 3);
    if (bakey_held(arg0, 1) != 0) {
        _babee_entrypoint_2(arg0);
    }
    if ((bastick_getZone(arg0) == 0) && (func_8009BCD4(arg0, 1.0f) != 0)) {
        sp24 = 0x85;
    }
    if (func_8008DD04(arg0) != 0) {
        sp24 = 0x88;
    }
    if (bakey_pressed(arg0, 8) != 0) {
        sp24 = 0x87;
    }
    if (player_inWater(arg0) != 0) {
        sp24 = 0x8C;
    }
    bs_setState(arg0, sp24);
}

void func_808003B4_bsbeemain(s32 arg0)
{
    func_80090A2C();
    _bsbee_entrypoint_0(arg0);
}
s32 bsbeemain_entrypoint_1(s32 arg0) {
    extern s32 D_80801270_bsbeemain[];
    return ((s32 *)&D_80801270_bsbeemain)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/beemain/func_808003F0_bsbeemain.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/beemain/func_80800548_bsbeemain.s")

void func_80800788_bsbeemain(s32 arg0)
{
    _bsbee_entrypoint_0();
    baphysics_reset_gravity(arg0);
}
s32 bsbeemain_entrypoint_2(s32 arg0) {
    extern s32 D_80801280_bsbeemain[];
    return ((s32 *)&D_80801280_bsbeemain)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/beemain/func_808007C4_bsbeemain.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/beemain/func_80800874_bsbeemain.s")

void func_80800A74_bsbeemain()
{
    _bsbee_entrypoint_0();
}

s32 bsbeemain_entrypoint_3(s32 arg0) {
    extern s32 D_80801290_bsbeemain[];
    return ((s32 *)&D_80801290_bsbeemain)[arg0];
}

void bsbeemain_entrypoint_4(s32 arg0)
{
    _babounce_entrypoint_3();
    _bsbee_entrypoint_0(arg0);
}
void _babounce_entrypoint_5(s32, s32, f32);
void bsbeemain_entrypoint_5(s32 arg0) { _bsbee_entrypoint_1(); _babounce_entrypoint_4(arg0, 1); _babounce_entrypoint_5(arg0, 0x1E0, 0.7518f); }

/* extern */

void bsbeemain_entrypoint_6(s32 arg0) {
    s32 _bsbee_entrypoint_2();
    s32 _babounce_entrypoint_9(s32);
    s32 bs_setState(s32, s32);
    s32 sp1C;

    sp1C = 0;
    _bsbee_entrypoint_2();
    if (_babounce_entrypoint_9(arg0) != 0) {
        sp1C = 0x85;
    }
    bs_setState(arg0, sp1C);
}

s32 bsbeemain_entrypoint_7(s32 arg0) {
    extern s32 D_808012A0_bsbeemain[];
    return ((s32 *)&D_808012A0_bsbeemain)[arg0];
}

void func_80800B68_bsbeemain(s32 arg0)
{
    _babounce_entrypoint_3();
    _bsbee_entrypoint_0(arg0);
}
void func_80800B90_bsbeemain(s32 arg0) { _bsbee_entrypoint_1(); _babounce_entrypoint_4(arg0, 2); _babounce_entrypoint_5(arg0, 0x1E0, 0.7518f); }

/* extern */

void func_80800BD0_bsbeemain(s32 arg0) {
    s32 _bsbee_entrypoint_2();
    s32 _babounce_entrypoint_9(s32);
    s32 bs_setState(s32, s32);
    s32 sp1C;

    sp1C = 0;
    _bsbee_entrypoint_2();
    if (_babounce_entrypoint_9(arg0) != 0) {
        sp1C = 0x85;
    }
    bs_setState(arg0, sp1C);
}

s32 bsbeemain_entrypoint_8(s32 arg0) {
    extern s32 D_808012B0_bsbeemain[];
    return ((s32 *)&D_808012B0_bsbeemain)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/beemain/func_80800C28_bsbeemain.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/beemain/func_80800E0C_bsbeemain.s")

void func_80800FB8_bsbeemain(s32 arg0) { baphysics_reset_gravity(); func_800A4E30(arg0); func_800951B4(arg0); _bsbee_entrypoint_0(arg0); }

/* extern */

void func_80800FF0_bsbeemain(s32 arg0) {
    s32 _basudie_entrypoint_11(s32);
    s32 bs_setState(s32, s32);
    s32 func_80093370(s32, s32);
    f32 func_80099A34(s32);
    s32 func_8009BDAC(s32, f32);
    s32 func_8009E6EC();
    s32 func_8009E830(s32, s32);
    if (func_8009E6EC() == 0x83) {
        func_8009BDAC(arg0, func_80099A34(arg0));
        func_80093370(arg0, 1);
        bs_setState(arg0, 0x85);
        func_8009E830(arg0, 2);
        return;
    }
    _basudie_entrypoint_11(arg0);
}

s32 bsbeemain_entrypoint_9(s32 arg0) {
    extern s32 D_808012C0_bsbeemain[];
    return ((s32 *)&D_808012C0_bsbeemain)[arg0];
}

void func_80801080_bsbeemain(s32 arg0)
{
    _bsbee_entrypoint_1();
    _bsrest_entrypoint_16(arg0);
}
/* extern */

void func_808010A8_bsbeemain(s32 arg0) {
    s32 _bsbee_entrypoint_2();
    s32 _bsrest_entrypoint_13(s32);
    s32 _bsrest_entrypoint_20(s32);
    s32 bs_setState(s32, s32);
    s32 sp1C;

    sp1C = 0;
    _bsbee_entrypoint_2();
    if (_bsrest_entrypoint_20(arg0) != 0) {
        sp1C = _bsrest_entrypoint_13(arg0);
    }
    bs_setState(arg0, sp1C);
}

void func_808010F4_bsbeemain(s32 arg0)
{
    _bsrest_entrypoint_14();
    _bsbee_entrypoint_0(arg0);
}
s32 bsbeemain_entrypoint_10(s32 arg0) {
    extern s32 D_808012D0_bsbeemain[];
    return ((s32 *)&D_808012D0_bsbeemain)[arg0];
}

void func_80801130_bsbeemain(void *arg0) {
    _bsbee_entrypoint_1(arg0);
    _bsdrone_entrypoint_0(arg0);
    if (_badrone_entrypoint_3(arg0) == 2) {
        _bafpctrl_entrypoint_10(arg0, 1);
        func_800947EC(arg0, 2, 1);
    }
}

/* extern */

void func_8080118C_bsbeemain(struct player_state_s *arg0) {
    s32 _bsbee_entrypoint_2();
    _bsbee_entrypoint_2(arg0);
    _bsdrone_entrypoint_1(arg0);
    if ((_badrone_entrypoint_3(arg0) == 2) && (bakey_held(arg0, 1) != 0)) {
        _babee_entrypoint_2(arg0);
    }
}

void func_808011E8_bsbeemain(s32 arg0) {
    if (_badrone_entrypoint_3(arg0) == 2) {
        func_800947EC(arg0, 2, 0);
    }
    _bsdrone_entrypoint_2(arg0);
    _bsbee_entrypoint_0(arg0);
}

s32 bsbeemain_entrypoint_11(s32 arg0) {
    extern s32 D_808012E0_bsbeemain[];
    return ((s32 *)&D_808012E0_bsbeemain)[arg0];
}
