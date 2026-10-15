#include "common.h"

/* extern */

void bsbabykaz_entrypoint_0(u8 *arg0) {
    s32 _bababykaz_entrypoint_4(u8 *);
    s32 _cheggclockwork_entrypoint_3(f32 *, f32, s32, s32);
    void func_8009C128(u8 *, f32[3]);
    f32 yaw_get(u8 *);
    f32 sp24[3];
    f32 sp1C[2];

    func_8009C128(arg0, sp24);
    sp1C[0] = yaw_get(arg0);
    _cheggclockwork_entrypoint_3(sp24, sp1C[0], _bababykaz_entrypoint_4(arg0), (*(s32 *)((s8 *)(arg0) + (0x160))));
}

void func_80800050_bsbabykaz(void *arg0) {
    (*(f32 *)((s8 *)(arg0) + (0x170))) = 0.0f;
}

/* extern */

void func_8080005C_bsbabykaz(void *arg0) {
    void *func_80092AD8(void *);
    f32 func_800D8FF8(void);
    void func_800E0AF0(void *, f32);
    void func_800E0AFC(void *, u8, f32, f32, f32, f32);
    void *sp24;
    void *temp_v0;

    temp_v0 = func_80092AD8(arg0);
    sp24 = temp_v0;
    func_800E0AF0(temp_v0, 1.0f);
    func_800E0AFC(sp24, 0x5B, 1.0f, -50.0f, 0.0f, 0.0f);
    func_800E0AFC(sp24, 0x5D, 1.0f, 0.0f, (*(f32 *)((s8 *)(arg0) + (0x170))), 0.0f);
    (*(f32 *)((s8 *)(arg0) + (0x170))) += func_800D8FF8() * 500.0f;
}

/* extern */

struct player_state_s;
int bakey_pressed(struct player_state_s *, int);
int bastick_getZone(struct player_state_s *);

s32 func_808000F8_bsbabykaz(struct player_state_s *arg0) {
    s32 _bababykaz_entrypoint_3(struct player_state_s *);
    if (bakey_pressed(arg0, 9) != 0) {
        _bababykaz_entrypoint_7(arg0, 1);
    }
    return _bababykaz_entrypoint_3(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/babykaz/func_80800134_bsbabykaz.s")

/* extern */

s32 func_808001A8_bsbabykaz(struct player_state_s *arg0, s32 arg1) {
    if (bastick_getZone(arg0) == 1) {
        arg1 = 0x135;
    }
    if (bakey_pressed(arg0, 8) != 0) {
        arg1 = 0x134;
    }
    if (func_808000F8_bsbabykaz(arg0) != 0) {
        arg1 = 0x94;
    }
    return arg1;
}

/* extern */

void func_80800214_bsbabykaz(u8 *arg0) {
    s32 _bababykaz_entrypoint_9(s32);
    s32 bs_setState(s32, s32);
    void func_800F82C0(s32);
    s32 func_800F9AFC();
    void func_8009C128(u8 *, f32[3]);
    s32 func_801013A8(f32 *, s32, s32);
    f32 sp1C[3];

    func_8009C128(arg0, sp1C);
    func_801013A8(&sp1C, 0x39, 0);
    bs_setState(arg0, 0x5A);
    _bababykaz_entrypoint_9(arg0);
    func_800F82C0((*(s32 *)((s8 *)(arg0) + (0x184))));
    func_800F9AFC();
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/babykaz/bsbabykaz_entrypoint_1.s")

void func_808003D0_bsbabykaz()
{
    bsbabykaz_entrypoint_3();
}

/* extern */

void func_808003F0_bsbabykaz(void *arg0) {
    void baphysics_set_target_horizontal_velocity(void *, f32);
    void func_8009FFD8(void *, s32, s32, s32, s32);
    bsbabykaz_entrypoint_4();
    func_8009FFD8(arg0, 1, 1, 1, 2);
    baphysics_set_target_horizontal_velocity(arg0, 0.0f);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/babykaz/func_80800438_bsbabykaz.s")

s32 bsbabykaz_entrypoint_2(s32 arg0) {
    extern s32 D_80801730_bsbabykaz[];
    return ((s32 *)&D_80801730_bsbabykaz)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/babykaz/bsbabykaz_entrypoint_3.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/babykaz/bsbabykaz_entrypoint_4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/babykaz/bsbabykaz_entrypoint_5.s")

void func_8080072C_bsbabykaz(s32 arg0)
{
    bsbabykaz_entrypoint_3();
    _bsdrone_entrypoint_2(arg0);
}
void func_80800754_bsbabykaz(s32 arg0)
{
    bsbabykaz_entrypoint_4();
    _bsdrone_entrypoint_0(arg0);
}
/* extern */

void func_8080077C_bsbabykaz(struct player_state_s *arg0) {
    s32 _bababykaz_entrypoint_3(struct player_state_s *);
    s32 _badrone_entrypoint_3(struct player_state_s *);
    void _bsdrone_entrypoint_1(struct player_state_s *);
    s32 bs_setState(s32, s32);
    s32 bsbabykaz_entrypoint_5(s32);
    _bsdrone_entrypoint_1(arg0);
    bsbabykaz_entrypoint_5(arg0);
    if ((_bababykaz_entrypoint_3(arg0) != 0) && (_badrone_entrypoint_3(arg0) != 1)) {
        bs_setState(arg0, 0x94);
    }
}

s32 bsbabykaz_entrypoint_6(s32 arg0) {
    extern s32 D_80801740_bsbabykaz[];
    return ((s32 *)&D_80801740_bsbabykaz)[arg0];
}

void func_808007EC_bsbabykaz()
{
    bsbabykaz_entrypoint_3();
}

void func_8080080C_bsbabykaz(void *arg0) {
    void func_8009FFD8(void *, s32, s32, s32, s32);
    bsbabykaz_entrypoint_4();
    baanim_playForDuration_loopSmooth(arg0, 0xA9, 0x3EC28F5C);
    func_8009FFD8(arg0, 1, 1, 3, 6);
    *(s32 *)((s8 *)arg0 + 0x15C) = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/babykaz/func_80800864_bsbabykaz.s")

s32 bsbabykaz_entrypoint_7(s32 arg0) {
    extern s32 D_80801750_bsbabykaz[];
    return ((s32 *)&D_80801750_bsbabykaz)[arg0];
}

void func_808009C4_bsbabykaz(s32 arg0)
{
    baphysics_reset_gravity();
    bsbabykaz_entrypoint_3(arg0);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/babykaz/func_808009EC_bsbabykaz.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/babykaz/func_80800B54_bsbabykaz.s")

s32 bsbabykaz_entrypoint_8(s32 arg0) {
    extern s32 D_80801760_bsbabykaz[];
    return ((s32 *)&D_80801760_bsbabykaz)[arg0];
}

void func_80800D18_bsbabykaz(s32 arg0)
{
    _bsrest_entrypoint_14();
    bsbabykaz_entrypoint_3(arg0);
}
void func_80800D40_bsbabykaz(s32 arg0)
{
    bsbabykaz_entrypoint_4();
    _bsrest_entrypoint_16(arg0);
}
/* extern */

void func_80800D68_bsbabykaz(s32 arg0) {
    s32 _bababykaz_entrypoint_3(struct player_state_s *);
    s32 _bsrest_entrypoint_20();
    s32 bs_setState(s32, s32);
    s32 bsbabykaz_entrypoint_5(s32);
    s32 sp1C;

    sp1C = 0;
    if (_bsrest_entrypoint_20() != 0) {
        sp1C = 0x136;
    }
    bsbabykaz_entrypoint_5(arg0);
    if (_bababykaz_entrypoint_3(arg0) != 0) {
        sp1C = 0x94;
    }
    bs_setState(arg0, sp1C);
}

s32 bsbabykaz_entrypoint_9(s32 arg0) {
    extern s32 D_80801770_bsbabykaz[];
    return ((s32 *)&D_80801770_bsbabykaz)[arg0];
}

/* extern */

void func_80800DD4_bsbabykaz(s32 arg0) {
    void func_8009BF5C(s32, f32);
    void baroll_setIdeal(s32, f32);
    func_8009BF5C(arg0, 0.0f);
    baroll_setIdeal(arg0, 0.0f);
    bsbabykaz_entrypoint_3(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/babykaz/func_80800E0C_bsbabykaz.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/babykaz/func_80800EC8_bsbabykaz.s")

s32 bsbabykaz_entrypoint_10(s32 arg0) {
    extern s32 D_80801780_bsbabykaz[];
    return ((s32 *)&D_80801780_bsbabykaz)[arg0];
}

void func_80801014_bsbabykaz(s32 arg0)
{
    func_80090A2C();
    func_800951B4(arg0);
    bsbabykaz_entrypoint_3(arg0);
}

void func_80801044_bsbabykaz(s32 arg0) {
    void baphysics_set_target_horizontal_velocity(void *, f32);
    void func_8009FFD8(void *, s32, s32, s32, s32);
    bsbabykaz_entrypoint_4(arg0);
    baanim_playForDuration_loopSmooth(arg0, 0xA4, 0x40D00000);
    func_8009FFD8(arg0, 1, 1, 1, 2);
    baphysics_set_target_horizontal_velocity(arg0, 0.0f);
    func_800909CC(arg0);
}

/* extern */

void func_808010AC_bsbabykaz(s32 arg0) {
    s32 _badrone_entrypoint_25(s32);
    s32 bs_setState(s32, s32);
    s32 bsbabykaz_entrypoint_5();
    s32 func_8008DD04(s32);
    int func_8008E148(s32);
    s32 func_808001A8_bsbabykaz(struct player_state_s *, s32);
    s32 sp24;

    sp24 = 0;
    bsbabykaz_entrypoint_5();
    if (func_8008E148(arg0) != 0) {
        sp24 = _badrone_entrypoint_25(arg0);
    }
    if (func_8008DD04(arg0) != 0) {
        sp24 = 0x133;
    }
    bs_setState(arg0, func_808001A8_bsbabykaz(arg0, sp24));
}

s32 bsbabykaz_entrypoint_11(s32 arg0) {
    extern s32 D_80801790_bsbabykaz[];
    return ((s32 *)&D_80801790_bsbabykaz)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/babykaz/func_80801134_bsbabykaz.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/babykaz/func_808011EC_bsbabykaz.s")

void func_808012C4_bsbabykaz(s32 arg0)
{
    func_80091E6C();
    bsbabykaz_entrypoint_3(arg0);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/babykaz/func_808012EC_bsbabykaz.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/babykaz/func_80801384_bsbabykaz.s")

s32 bsbabykaz_entrypoint_12(s32 arg0) {
    extern s32 D_808017A0_bsbabykaz[];
    return ((s32 *)&D_808017A0_bsbabykaz)[arg0];
}

void bsbabykaz_entrypoint_13(s32 arg0)
{
    _bababykaz_entrypoint_7(arg0,1);
}

/* extern */

s32 bsbabykaz_entrypoint_14(f32 *arg0) {
    void *func_800C6A7C(f32 *, f32 *, f32 *, u32);
    void *func_800C6C94(f32 *, f32, f32 *, u32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EFA4C(f32 *, f32, f32, f32);
    s32 pad;
    f32 sp48[3];
    f32 sp3C[3];
    f32 sp30[3];
    f32 sp24[3];

    func_800EE7F8(sp48, arg0);
    func_800EFA4C(sp30, arg0[0], arg0[1] + 35.0f, arg0[2]);
    if (func_800C6A7C(sp30, sp48, sp3C, 0x400005) != 0) {
        return 0;
    }
    func_800EE7F8(sp48, arg0);
    func_800EE7F8(sp24, sp30);
    if (func_800C6A7C(sp48, sp30, sp3C, 0x400005) != 0) {
        return 0;
    }
    func_800EE7F8(sp30, sp24);
    if (func_800C6C94(sp30, 12.0f, sp3C, 0x400005) != 0) {
        return 0;
    }
    return 1;
}
