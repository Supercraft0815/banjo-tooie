#include "common.h"
#include "overlays/ba/playerstate.h"
struct anctrl_s;
#include "bs_script.h"
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
    _cheggclockwork_entrypoint_3(sp24, sp1C[0], _bababykaz_entrypoint_4(arg0), (((PlayerState *)arg0)->unk160.word));
}

void func_80800050_bsbabykaz(void *arg0) {
    (((PlayerState *)arg0)->unk170) = 0.0f;
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
    func_800E0AFC(sp24, 0x5D, 1.0f, 0.0f, (((PlayerState *)arg0)->unk170), 0.0f);
    (((PlayerState *)arg0)->unk170) += func_800D8FF8() * 500.0f;
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
    s32 bs_setState(BtIntPtr, s32);
    void func_800F82C0(s32);
    void func_800F9AFC(void);
    void func_8009C128(u8 *, f32[3]);
    s32 func_801013A8(f32 *, s32, s32);
    f32 sp1C[3];

    func_8009C128(arg0, sp1C);
    func_801013A8(&sp1C, 0x39, 0);
    bs_setState(arg0, 0x5A);
    _bababykaz_entrypoint_9(arg0);
    func_800F82C0((((PlayerState *)arg0)->unk184));
    func_800F9AFC();
}

void bsbabykaz_entrypoint_1(struct player_state_s *arg0) {
    void _batimer_set(struct player_state_s *, s32, f32);
    s32 bs_setState(BtIntPtr, s32);
    void func_80099B94(struct player_state_s *);
    s32 func_8009E6EC(struct player_state_s *);
    void func_8009E830(struct player_state_s *, s32);

    switch (func_8009E6EC(arg0)) {
    case 0x1F:
    case 0x20:
    case 0x21:
    case 0x23:
    case 0x24:
    case 0x2D:
    case 0x2E:
    case 0x45:
    case 0x4E:
    case 0x51:
    case 0x52:
    case 0x59:
    case 0x5A:
    case 0x5B:
    case 0x5C:
    case 0x91:
        bs_setState(arg0, 0x94);
        func_8009E830(arg0, 2);
        break;
    case 0x66:
        func_8009E830(arg0, 1);
        break;
    case 0x87:
        bs_setState(arg0, 0x94);
        func_8009E830(arg0, 2);
        _batimer_set(arg0, 0, 0.0f);
        break;
    case 0x86:
        func_80800214_bsbabykaz(arg0);
        func_8009E830(arg0, 2);
        break;
    case 0x8E:
        arg0->unk160.word = 0;
        bs_setState(arg0, 0x94);
        func_8009E830(arg0, 2);
        _batimer_set(arg0, 0, 0.0f);
        break;
    default:
        func_80099B94(arg0);
        break;
    }
}

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

void func_80800438_bsbabykaz(BtIntPtr arg0) {
    int baanim_isStopped(struct player_state_s *);
    s32 bs_setState(BtIntPtr, s32);
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

BsScript bsbabykaz_entrypoint_2(BsScriptType arg0) {
    extern BtFnWord D_80801730_bsbabykaz[4];
    return (BsScript)D_80801730_bsbabykaz[arg0];
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
        arg0->unk160.word = 1;
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

void func_8080072C_bsbabykaz(BtIntPtr arg0)
{
    bsbabykaz_entrypoint_3(arg0);
    _bsdrone_entrypoint_2(arg0);
}
void func_80800754_bsbabykaz(BtIntPtr arg0)
{
    bsbabykaz_entrypoint_4(arg0);
    _bsdrone_entrypoint_0(arg0);
}
/* extern */

void func_8080077C_bsbabykaz(struct player_state_s *arg0) {
    s32 _bababykaz_entrypoint_3(struct player_state_s *);
    s32 _badrone_entrypoint_3(struct player_state_s *);
    void _bsdrone_entrypoint_1(struct player_state_s *);
    s32 bs_setState(BtIntPtr, s32);
    void bsbabykaz_entrypoint_5();
    _bsdrone_entrypoint_1(arg0);
    bsbabykaz_entrypoint_5(arg0);
    if ((_bababykaz_entrypoint_3(arg0) != 0) && (_badrone_entrypoint_3(arg0) != 1)) {
        bs_setState(arg0, 0x94);
    }
}

BsScript bsbabykaz_entrypoint_6(BsScriptType arg0) {
    extern BtFnWord D_80801740_bsbabykaz[4];
    return (BsScript)D_80801740_bsbabykaz[arg0];
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
    ((PlayerState *)arg0)->unk15C.word = 0;
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
    s32 bs_setState(BtIntPtr, s32);
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
    switch (arg0->unk15C.word) {
        case 0:
            if (func_8008DF8C(arg0, 0x5A)) {
                anctrl_reset(anim_ctrl);
                anctrl_setIndex(anim_ctrl, 0xA9);
                anctrl_setStart(anim_ctrl, 0.6667f);
                anctrl_setDuration(anim_ctrl, 2.0f);
                anctrl_setPlaybackType(anim_ctrl, 1);
                anctrl_start(anim_ctrl);
                arg0->unk15C.word = 1;
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

BsScript bsbabykaz_entrypoint_7(BsScriptType arg0) {
    extern BtFnWord D_80801750_bsbabykaz[4];
    return (BsScript)D_80801750_bsbabykaz[arg0];
}

void func_808009C4_bsbabykaz(BtIntPtr arg0)
{
    baphysics_reset_gravity();
    bsbabykaz_entrypoint_3(arg0);
}
void func_808009EC_bsbabykaz(struct player_state_s *arg0) {
    struct anctrl_s *baanim_getAnimCtrlPtr(struct player_state_s *);
    void anctrl_reset(struct anctrl_s *);
    void anctrl_setIndex(struct anctrl_s *, s32);
    void anctrl_setDuration(struct anctrl_s *, f32);
    void func_8008B1C8(struct anctrl_s *, f32);
    void anctrl_setStart(struct anctrl_s *, f32);
    void anctrl_setSubrange(struct anctrl_s *, f32, f32);
    void anctrl_setPlaybackType(struct anctrl_s *, s32);
    void anctrl_start(struct anctrl_s *);
    void func_8009FFD8(void *, s32, s32, s32, s32);
    f32 bastick_distance(struct player_state_s *);
    f32 bastick_getAngleRelativeToBanjo(struct player_state_s *);
    f32 yaw_getIdeal(struct player_state_s *);
    void yaw_setIdeal(struct player_state_s *, f32);
    void baphysics_set_target_yaw(struct player_state_s *, f32);
    f32 baphysics_get_target_horizontal_velocity(struct player_state_s *);
    void baphysics_set_horizontal_velocity(struct player_state_s *, f32, f32);
    void baphysics_set_vertical_velocity(struct player_state_s *, f32);
    void baphysics_set_gravity(struct player_state_s *, f32);
    void func_8009DE38(struct player_state_s *, s32, f32);
    s32 pad[2];
    f32 sp2C;
    struct anctrl_s *control;

    control = baanim_getAnimCtrlPtr(arg0);
    bsbabykaz_entrypoint_4(arg0);
    anctrl_reset(control);
    anctrl_setIndex(control, 0xA9);
    anctrl_setDuration(control, 1.9f);
    func_8008B1C8(control, 0.134f);
    anctrl_setStart(control, 0.3f);
    anctrl_setSubrange(control, 0.0f, 0.5042f);
    anctrl_setPlaybackType(control, 1);
    anctrl_start(control);
    func_8009FFD8(arg0, 1, 1, 3, 6);
    if (bastick_distance(arg0) != 0.0f) {
        yaw_setIdeal(arg0, bastick_getAngleRelativeToBanjo(arg0));
    }
    baphysics_set_target_yaw(arg0, yaw_getIdeal(arg0));
    func_80800134_bsbabykaz(arg0);
    sp2C = yaw_getIdeal(arg0);
    baphysics_set_horizontal_velocity(arg0, sp2C, baphysics_get_target_horizontal_velocity(arg0));
    baphysics_set_vertical_velocity(arg0, 475.0f);
    baphysics_set_gravity(arg0, -1200.0f);
    arg0->unk15C.word = 0;
    func_8009DE38(arg0, 0x432, 1.4f);
}

void func_80800B54_bsbabykaz(struct player_state_s *arg0) {
    s32 anctrl_isStopped(struct anctrl_s *);
    struct anctrl_s *baanim_getAnimCtrlPtr(struct player_state_s *);
    int baanim_isStopped(struct player_state_s *);
    void baanim_setEndAndDuration(struct player_state_s *, f32, f32);
    int baflag_isTrue(struct player_state_s *, s32);
    int bakey_released(struct player_state_s *, int);
    s32 bs_setState(BtIntPtr, s32);
    s32 func_8008D544(struct player_state_s *);
    int func_8008DF8C(struct player_state_s *, s32);
    void func_8009B7C0(struct player_state_s *);
    void func_8009BB24(void *, f32 *);
    void func_8009FE58(struct player_state_s *);
    int player_isStable(struct player_state_s *);
    s32 sp34;
    struct anctrl_s *sp30;
    f32 sp24[3];

    sp34 = 0;
    sp30 = baanim_getAnimCtrlPtr(arg0);
    bsbabykaz_entrypoint_5(arg0);
    if (baflag_isTrue(arg0, 0xF) != 0) {
        func_8009B7C0(arg0);
    } else {
        func_80800134_bsbabykaz(arg0);
    }
    func_8009BB24(arg0, sp24);
    if (((bakey_released(arg0, 8) != 0) && (sp24[1] > 0.0f)) || (func_8008D544(arg0) == 0)) {
        baphysics_reset_gravity(arg0);
    }
    switch (arg0->unk15C.word) {
    case 0:
        if (anctrl_isStopped(sp30) != 0) {
            baanim_setEndAndDuration(arg0, 0.6667f, 4.0f);
            arg0->unk15C.word = 1;
        }
        if (func_8008DF8C(arg0, 0x82) != 0) {
            baanim_setEndAndDuration(arg0, 1.0f, 1.4f);
            arg0->unk15C.word = 2;
        }
        break;
    case 1:
        if (baanim_isStopped(arg0) != 0) {
            sp34 = 0x133;
        }
        if (func_8008DF8C(arg0, 0x5A) != 0) {
            baanim_setEndAndDuration(arg0, 1.0f, 2.0f);
            arg0->unk15C.word = 2;
        }
        break;
    case 2:
        break;
    }
    if (player_isStable(arg0) != 0) {
        func_8009FE58(arg0);
        sp34 = 0x132;
    }
    if (func_808000F8_bsbabykaz(arg0) != 0) {
        sp34 = 0x94;
    }
    bs_setState(arg0, sp34);
}

BsScript bsbabykaz_entrypoint_8(BsScriptType arg0) {
    extern BtFnWord D_80801760_bsbabykaz[4];
    return (BsScript)D_80801760_bsbabykaz[arg0];
}

void func_80800D18_bsbabykaz(BtIntPtr arg0)
{
    _bsrest_entrypoint_14();
    bsbabykaz_entrypoint_3(arg0);
}
void func_80800D40_bsbabykaz(BtIntPtr arg0)
{
    bsbabykaz_entrypoint_4(arg0);
    _bsrest_entrypoint_16(arg0);
}
/* extern */

void func_80800D68_bsbabykaz(BtIntPtr arg0) {
    s32 _bababykaz_entrypoint_3(struct player_state_s *);
    s32 _bsrest_entrypoint_20();
    s32 bs_setState(BtIntPtr, s32);
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

BsScript bsbabykaz_entrypoint_9(BsScriptType arg0) {
    extern BtFnWord D_80801770_bsbabykaz[4];
    return (BsScript)D_80801770_bsbabykaz[arg0];
}

/* extern */

void func_80800DD4_bsbabykaz(BtIntPtr arg0) {
    void func_8009BF5C(BtIntPtr, f32);
    void baroll_setIdeal(BtIntPtr, f32);
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
    s32 _badrone_entrypoint_25(BtIntPtr);
    int baanim_isAt(struct player_state_s *, f32);
    int bakey_pressed(struct player_state_s *, int);
    int bastick_getZone(struct player_state_s *);
    s32 bs_setState(BtIntPtr, s32);
    int func_8008DD04(struct player_state_s *);
    int func_8008E148(BtIntPtr);
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

BsScript bsbabykaz_entrypoint_10(BsScriptType arg0) {
    extern BtFnWord D_80801780_bsbabykaz[4];
    return (BsScript)D_80801780_bsbabykaz[arg0];
}

void func_80801014_bsbabykaz(BtIntPtr arg0)
{
    func_80090A2C();
    func_800951B4(arg0);
    bsbabykaz_entrypoint_3(arg0);
}

void func_80801044_bsbabykaz(BtIntPtr arg0) {
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

void func_808010AC_bsbabykaz(BtIntPtr arg0) {
    s32 _badrone_entrypoint_25(BtIntPtr);
    s32 bs_setState(BtIntPtr, s32);
    void bsbabykaz_entrypoint_5();
    int func_8008DD04(struct player_state_s *);
    int func_8008E148(BtIntPtr);
    s32 func_808001A8_bsbabykaz(struct player_state_s *, s32);
    s32 sp24;

    sp24 = 0;
#ifdef BT_NATIVE
    ((void (*)())bsbabykaz_entrypoint_5)();
#else
    bsbabykaz_entrypoint_5();
#endif
    if (func_8008E148(arg0) != 0) {
        sp24 = _badrone_entrypoint_25(arg0);
    }
    if (func_8008DD04(arg0) != 0) {
        sp24 = 0x133;
    }
    bs_setState(arg0, func_808001A8_bsbabykaz(arg0, sp24));
}

BsScript bsbabykaz_entrypoint_11(BsScriptType arg0) {
    extern BtFnWord D_80801790_bsbabykaz[4];
    return (BsScript)D_80801790_bsbabykaz[arg0];
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
    arg0->unk15C.word = arg1;
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
            if (arg0->unk15C.word == 2) {
                func_800F9B54();
                func_80801134_bsbabykaz(arg0, 3);
            }
            break;
    }
}

void func_808012C4_bsbabykaz(BtIntPtr arg0)
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

void func_80801384_bsbabykaz(struct player_state_s *arg0) {
    extern u8 D_8012762C;
    s32 _batimer_decrement(void *, s32);
    int _batimer_isZero(struct player_state_s *, s32);
    s32 func_8009CC68(struct player_state_s *);
    int func_800DB9B0(void);
    void func_800F3BB0(struct player_state_s *, f32[3]);
    u32 func_800F54E4(void);
    s32 func_800F6D24(BtIntPtr);
    void func_800F9ADC(void);
    s32 func_80101180(s32, s32, BtIntPtr);
    s32 func_801013A8(f32 *, s32, s32);
    s32 expired;
    f32 pos1[3];
    s32 result;
    f32 pos2[3];

    if (arg0->unk15C.word == 3) {
        return;
    }
    _batimer_decrement(arg0, 0);
    expired = _batimer_isZero(arg0, 0);
    if (func_8009CC68(arg0) != 0 || func_800DB9B0() != 0 ||
        func_800F6D24(func_800F54E4()) != 0) {
        return;
    }
    switch (arg0->unk15C.word) {
        case 1:
            if (expired != 0) {
                func_800F3BB0(arg0, pos1);
                if (D_8012762C == 0x18) {
                    result = func_80101180(0x418, 0x39, 0);
                } else {
                    result = 0;
                }
                if (result != 1) {
                    func_800F9ADC();
                }
                func_80801134_bsbabykaz(arg0, 3);
            }
            break;
        case 2:
            if (expired != 0) {
                func_800F3BB0(arg0, pos2);
                func_801013A8(pos2, 0x39, 0);
                func_800F9ADC();
                func_80801134_bsbabykaz(arg0, 3);
            }
            break;
        case 3:
            break;
    }
}

BsScript bsbabykaz_entrypoint_12(BsScriptType arg0) {
    extern BtFnWord D_808017A0_bsbabykaz[4];
    return (BsScript)D_808017A0_bsbabykaz[arg0];
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

static BtFnWord D_lever[] = { (BtFnWord)bsbabykaz_entrypoint_1 };
