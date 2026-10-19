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

void func_80800134_bsbabykaz(struct player_state_s *arg0) {
    void baphysics_set_target_horizontal_velocity(struct player_state_s *, f32);
    f32 bastick_getZonePosition(struct player_state_s *);
    f32 func_800F1214(f32, f32, f32);
    f32 sp1C;

    sp1C = bastick_getZonePosition(arg0);
    switch (bastick_getZone(arg0)) {
        case 0:
            baphysics_set_target_horizontal_velocity(arg0, 0.0f);
            return;
        case 1:
            baphysics_set_target_horizontal_velocity(arg0, func_800F1214(sp1C, 80.0f, 400.0f));
            return;
    }
}

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
    s32 _bababykaz_entrypoint_9(struct player_state_s *);
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

void bsbabykaz_entrypoint_3(struct player_state_s *arg0);

void func_808003D0_bsbabykaz(struct player_state_s *arg0)
{
    bsbabykaz_entrypoint_3(arg0);
}

/* extern */

void func_808003F0_bsbabykaz(void *arg0) {
    void bsbabykaz_entrypoint_4(struct player_state_s *);
    void baphysics_set_target_horizontal_velocity(struct player_state_s *, f32);
    void func_8009FFD8(void *, s32, s32, s32, s32);
    bsbabykaz_entrypoint_4(arg0);
    func_8009FFD8(arg0, 1, 1, 1, 2);
    baphysics_set_target_horizontal_velocity(arg0, 0.0f);
}

/* extern */

void func_80800438_bsbabykaz(s32 arg0) {
    int baanim_isStopped(struct player_state_s *);
    s32 bs_setState(s32, s32);
    void bsbabykaz_entrypoint_5();
    int func_8008DD04(struct player_state_s *);
    s32 sp24;

    sp24 = 0;
    bsbabykaz_entrypoint_5(arg0);
    if (baanim_isStopped(arg0) != 0) {
        sp24 = 0x136;
    }
    if (func_8008DD04(arg0) != 0) {
        sp24 = 0x133;
    }
    bs_setState(arg0, func_808001A8_bsbabykaz(arg0, sp24));
}

s32 bsbabykaz_entrypoint_2(s32 arg0) {
    extern s32 D_80801730_bsbabykaz[];
    return ((s32 *)&D_80801730_bsbabykaz)[arg0];
}

void bsbabykaz_entrypoint_3(struct player_state_s *arg0) {
    void bastick_popZone(struct player_state_s *);
    void func_80092864(struct player_state_s *, f32);
    void func_800947EC(struct player_state_s *, s32, s32);
    void func_8009590C(struct player_state_s *, f32);
    void func_80095A40(struct player_state_s *);
    void func_80095A74(void *, s32);
    void func_8009E474(struct player_state_s *);
    s32 func_8009E69C(struct player_state_s *, s32);
    void func_800A1040(struct player_state_s *);
    void func_800A4D6C(u8 *, f32, f32);

    if (func_8009E69C(arg0, 0x20) == 0) {
        bastick_popZone(arg0);
        func_800A4D6C(arg0, 1.0f, 1.0f);
        func_80095A40(arg0);
        func_8009590C(arg0, 0.0f);
        func_800A1040(arg0);
        func_8009E474(arg0);
        func_800947EC(arg0, 1, 0);
        func_80092864(arg0, 1.0f);
        func_80095A74(arg0, 0);
    }
}

void bsbabykaz_entrypoint_4(struct player_state_s *arg0) {
    s32 _bababykaz_entrypoint_10(struct player_state_s *, s32);
    void bastick_pushZone(struct player_state_s *);
    void bastick_setZoneMax(struct player_state_s *, s32, f32);
    void func_80092864(struct player_state_s *, f32);
    void func_800947EC(struct player_state_s *, s32, s32);
    void func_8009590C(struct player_state_s *, f32);
    void func_800959C8(struct player_state_s *, f32, f32);
    void func_80095A74(void *, s32);
    void func_8009E4AC(struct player_state_s *);
    void func_8009E53C(struct player_state_s *, s32, f32);
    void func_8009E55C(struct player_state_s *, s32, f32);
    s32 func_8009E6C4(struct player_state_s *, s32);
    void func_800A106C(struct player_state_s *, f32, f32);
    void func_800A4D6C(u8 *, f32, f32);

    if (func_8009E6C4(arg0, 0x20) == 0) {
        _bababykaz_entrypoint_7(arg0, 0);
        func_800A106C(arg0, 20.0f, 40.0f);
        bastick_pushZone(arg0);
        bastick_setZoneMax(arg0, 0, 0.12f);
        bastick_setZoneMax(arg0, 1, 1.0f);
        func_800A4D6C(arg0, 0.3299865723f, 0.3299865723f);
        func_800959C8(arg0, 35.0f, 12.0f);
        func_8009590C(arg0, 35.0f);
        func_8009E4AC(arg0);
        func_8009E55C(arg0, 0, 20.0f);
        func_8009E53C(arg0, 0, 0.0f);
        func_8009E55C(arg0, 1, 0.0f);
        _bababykaz_entrypoint_10(arg0, -1);
        _bababykaz_entrypoint_6(arg0);
        func_800947EC(arg0, 1, 1);
        func_80800050_bsbabykaz(arg0);
        *(s32 *)((s8 *)arg0 + 0x160) = 1;
        func_80092864(arg0, 0.29998779296875f);
        func_80095A74(arg0, 1);
    }
}

void bsbabykaz_entrypoint_5(struct player_state_s *arg0) {
    s32 func_8008DD70(struct player_state_s *);
    s32 _bababykaz_entrypoint_5(struct player_state_s *);
    s32 func_800F7180(s32);
    s32 func_80096694();
    int player_isStable(struct player_state_s *);
    s32 temp_v0;

    if (func_8008DD70(arg0) == 0) {
        temp_v0 = _bababykaz_entrypoint_5(arg0);
        if ((temp_v0 != -1) && (func_800F7180(temp_v0) == 0)) {
            _bababykaz_entrypoint_7(arg0, 1);
        }
        if ((player_isStable(arg0) != 0) && (func_80096694(arg0) == 0x14)) {
            _bababykaz_entrypoint_7(arg0, 1);
        }
    }
    func_8080005C_bsbabykaz(arg0);
    _bababykaz_entrypoint_11(arg0);
}

void func_8080072C_bsbabykaz(s32 arg0)
{
    bsbabykaz_entrypoint_3(arg0);
    _bsdrone_entrypoint_2(arg0);
}
void func_80800754_bsbabykaz(s32 arg0)
{
    bsbabykaz_entrypoint_4(arg0);
    _bsdrone_entrypoint_0(arg0);
}
/* extern */

void func_8080077C_bsbabykaz(struct player_state_s *arg0) {
    s32 _bababykaz_entrypoint_3(struct player_state_s *);
    s32 _badrone_entrypoint_3(struct player_state_s *);
    void _bsdrone_entrypoint_1(struct player_state_s *);
    s32 bs_setState(s32, s32);
    void bsbabykaz_entrypoint_5();
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

void func_808007EC_bsbabykaz(struct player_state_s *arg0)
{
    bsbabykaz_entrypoint_3(arg0);
}

void func_8080080C_bsbabykaz(void *arg0) {
    void baanim_playForDuration_loopSmooth(struct player_state_s *, s32, f32);
    void func_8009FFD8(void *, s32, s32, s32, s32);
    bsbabykaz_entrypoint_4(arg0);
    baanim_playForDuration_loopSmooth(arg0, 0xA9, 0.38f);
    func_8009FFD8(arg0, 1, 1, 3, 6);
    *(s32 *)((s8 *)arg0 + 0x15C) = 0;
}

void func_80800864_bsbabykaz(struct player_state_s *arg0) {
    struct anctrl_s *baanim_getAnimCtrlPtr(struct player_state_s *);
    int baflag_isTrue(struct player_state_s *, s32);
    void func_8009BB24(void *, f32 *);
    void func_8009B7C0(struct player_state_s *);
    void func_8009FE58(struct player_state_s *);
    u32 anctrl_getPlaybackType(u8 *);
    void anctrl_reset(struct anctrl_s *);
    void anctrl_setIndex(struct anctrl_s *, s32);
    void anctrl_setStart(struct anctrl_s *, f32);
    void anctrl_setDuration(struct anctrl_s *, f32);
    void anctrl_setPlaybackType(struct anctrl_s *, s32);
    void anctrl_start(struct anctrl_s *);
    int func_8008DF8C(struct player_state_s *, s32);
    int player_isStable(struct player_state_s *);
    s32 bs_setState(s32, s32);
    s32 next_state;
    struct anctrl_s *anim_ctrl;
    f32 velocity[3];

    next_state = 0;
    anim_ctrl = baanim_getAnimCtrlPtr(arg0);
    bsbabykaz_entrypoint_5(arg0);
    if (baflag_isTrue(arg0, 0xF)) {
        func_8009B7C0(arg0);
    } else {
        func_80800134_bsbabykaz(arg0);
    }
    func_8009BB24(arg0, velocity);
    switch (*(s32 *)((s8 *)arg0 + 0x15C)) {
        case 0:
            if (func_8008DF8C(arg0, 0x5A)) {
                anctrl_reset(anim_ctrl);
                anctrl_setIndex(anim_ctrl, 0xA9);
                anctrl_setStart(anim_ctrl, 0.6667f);
                anctrl_setDuration(anim_ctrl, 2.0f);
                anctrl_setPlaybackType(anim_ctrl, 1);
                anctrl_start(anim_ctrl);
                *(s32 *)((s8 *)arg0 + 0x15C) = 1;
            }
            break;
        case 1:
            break;
    }
    if (player_isStable(arg0)) {
        func_8009FE58(arg0);
        if (anctrl_getPlaybackType(anim_ctrl) == 1) {
            next_state = 0x132;
        } else {
            next_state = 0x136;
        }
    }
    if (func_808000F8_bsbabykaz(arg0)) {
        next_state = 0x94;
    }
    bs_setState(arg0, next_state);
}

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
    bsbabykaz_entrypoint_4(arg0);
    _bsrest_entrypoint_16(arg0);
}
/* extern */

void func_80800D68_bsbabykaz(s32 arg0) {
    s32 _bababykaz_entrypoint_3(struct player_state_s *);
    s32 _bsrest_entrypoint_20();
    s32 bs_setState(s32, s32);
    void bsbabykaz_entrypoint_5();
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

void func_80800E0C_bsbabykaz(struct player_state_s *arg0) {
    void baanim_playForDuration_loopSmooth(struct player_state_s *, s32, f32);
    void baanim_setDurationRange(struct player_state_s *, f32, f32);
    void baroll_setAngularVelocity(struct player_state_s *, f32, f32);
    void func_8008C9F0(struct player_state_s *, f32, f32, f32, f32);
    void func_8008CA30(struct player_state_s *, f32);
    void func_8009BFE4(struct player_state_s *, f32, f32);
    void func_8009FFD8(void *, s32, s32, s32, s32);

    bsbabykaz_entrypoint_4(arg0);
    baanim_playForDuration_loopSmooth(arg0, 0xA6, 0.66f);
    func_8009FFD8(arg0, 2, 1, 1, 2);
    baanim_setDurationRange(arg0, 0.3f, 1.5f);
    func_8008C9F0(arg0, 80.0f, 400.0f, 0.54f, 0.35f);
    func_8008CA30(arg0, 1.0f);
    func_8009BFE4(arg0, 1000.0f, 12.0f);
    baroll_setAngularVelocity(arg0, 1000.0f, 12.0f);
}

void func_80800EC8_bsbabykaz(struct player_state_s *arg0) {
    s32 _badrone_entrypoint_25(s32);
    int baanim_isAt(struct player_state_s *, f32);
    int bakey_pressed(struct player_state_s *, int);
    int bastick_getZone(struct player_state_s *);
    s32 bs_setState(s32, s32);
    int func_8008DD04(struct player_state_s *);
    int func_8008E148(s32);
    s32 func_8009BCD4(struct player_state_s *, f32);
    void func_8009D2F0(struct player_state_s *, s32, f32);
    void func_8009DBB0(struct player_state_s *, s32, f32, f32, s32);
    s32 sp2C;

    sp2C = 0;
    bsbabykaz_entrypoint_5(arg0);
    func_8009D2F0(arg0, 0, 0.5f);
    if (baanim_isAt(arg0, 0.47f) != 0) {
        func_8009DBB0(arg0, 0x555, 1.25f, 1.35f, 0x2710);
    }
    if (baanim_isAt(arg0, 0.97f) != 0) {
        func_8009DBB0(arg0, 0x556, 1.25f, 1.35f, 0x2710);
    }
    func_80800134_bsbabykaz(arg0);
    if ((bastick_getZone(arg0) == 0) && (func_8009BCD4(arg0, 3.0f) != 0)) {
        sp2C = 0x136;
    }
    if (func_8008E148(arg0) != 0) {
        sp2C = _badrone_entrypoint_25(arg0);
    }
    if (func_8008DD04(arg0) != 0) {
        sp2C = 0x133;
    }
    if (bakey_pressed(arg0, 8) != 0) {
        sp2C = 0x134;
    }
    if (func_808000F8_bsbabykaz(arg0) != 0) {
        sp2C = 0x94;
    }
    bs_setState(arg0, sp2C);
}

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
    void baanim_playForDuration_loopSmooth(struct player_state_s *, s32, f32);
    void baphysics_set_target_horizontal_velocity(struct player_state_s *, f32);
    void func_8009FFD8(void *, s32, s32, s32, s32);
    bsbabykaz_entrypoint_4(arg0);
    baanim_playForDuration_loopSmooth(arg0, 0xA4, 6.5f);
    func_8009FFD8(arg0, 1, 1, 1, 2);
    baphysics_set_target_horizontal_velocity(arg0, 0.0f);
    func_800909CC(arg0);
}

/* extern */

void func_808010AC_bsbabykaz(s32 arg0) {
    s32 _badrone_entrypoint_25(s32);
    s32 bs_setState(s32, s32);
    void bsbabykaz_entrypoint_5();
    int func_8008DD04(struct player_state_s *);
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

void func_80801134_bsbabykaz(struct player_state_s *arg0, s32 arg1) {
    void _batimer_set(struct player_state_s *, s32, f32);
    s32 func_800EA068(s32);
    f32 duration;

    switch (arg1) {
        case 1:
            if (func_800EA068(0x400) != 0) {
                duration = 0.3f;
            } else {
                duration = 2.0f;
            }
            _batimer_set(arg0, 0, duration);
            break;
        case 2:
            if (func_800EA068(0x400) != 0) {
                duration = 0.3f;
            } else {
                duration = 2.0f;
            }
            _batimer_set(arg0, 0, duration);
            break;
    }
    *(s32 *)((u8 *)arg0 + 0x15C) = arg1;
}

void func_808011EC_bsbabykaz(struct player_state_s *arg0) {
    void _batimer_set(struct player_state_s *, s32, f32);
    s32 func_8009E6EC(struct player_state_s *);
    s32 func_80099A58(struct player_state_s *);
    void func_8009E830(struct player_state_s *, s32);
    void func_800F9BA4(void);
    void func_800F9B54(void);

    switch (func_8009E6EC(arg0)) {
        case 0x87:
            _batimer_set(arg0, 0, 0.0f);
            func_8009E830(arg0, 2);
            break;
        case 0x17:
            if (func_80099A58(arg0) == 1) {
                func_800F9BA4();
                func_80801134_bsbabykaz(arg0, 3);
                func_8009E830(arg0, 2);
            }
            break;
        case 0x86:
            break;
        case 0x94:
            if (*(s32 *)((u8 *)arg0 + 0x15C) == 2) {
                func_800F9B54();
                func_80801134_bsbabykaz(arg0, 3);
            }
            break;
    }
}

void func_808012C4_bsbabykaz(s32 arg0)
{
    func_80091E6C();
    bsbabykaz_entrypoint_3(arg0);
}
void func_808012EC_bsbabykaz(struct player_state_s *arg0) {
    s32 _bababykaz_entrypoint_10(struct player_state_s *, s32);
    s32 _bababykaz_entrypoint_5(struct player_state_s *);
    s32 _bababykaz_entrypoint_9(struct player_state_s *);
    s32 func_80091E48(void *, s32);
    void func_800F80D8(u32);
    void func_800F8EBC(s32);
    s32 sp24;

    bsbabykaz_entrypoint_4(arg0);
    sp24 = _bababykaz_entrypoint_5(arg0);
    _bababykaz_entrypoint_10(arg0, sp24);
    bsbabykaz_entrypoint_0((u8 *)arg0);
    _bababykaz_entrypoint_9(arg0);
    func_80091E48(arg0, 0x20);
    if (sp24 < 0) {
        func_80801134_bsbabykaz(arg0, 1);
        return;
    }
    func_800F80D8(sp24);
    func_800F8EBC(sp24);
    func_80801134_bsbabykaz(arg0, 2);
}

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
