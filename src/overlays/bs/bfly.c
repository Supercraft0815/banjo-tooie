#include "bs_script.h"
#include "common.h"
#include "overlays/ba/playerstate.h"
struct anctrl_s;

void func_8009C128(PlayerState *, f32[3]);

void func_80800000_bsbfly(PlayerState *arg0) {
    BtIntPtr func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    f32 func_800DC178(f32, f32);
    extern s32 D_80801D20_bsbfly[10];
    f32 sp24[3];

    func_8009C128(arg0, sp24);
    sp24[0] += func_800DC178(-30.0f, 30.0f);
    sp24[1] += 50.0f + func_800DC178(0.0f, 30.0f);
    sp24[2] += func_800DC178(-30.0f, 30.0f);
    func_800BBCB8(sp24, NULL, 1.0f, 1, D_80801D20_bsbfly);
}

/* extern */

void func_808000AC_bsbfly(PlayerState *arg0) {
    void _bafly_entrypoint_20(void *);
    void baroll_setAngularVelocity(PlayerState *, f32, f32);
    void func_80093360(PlayerState *, f32);
    void func_800959C8(PlayerState *, f32, f32);
    void func_800961AC(PlayerState *, s32);
    void yaw_setUpdateType(PlayerState *, s32);
    void yaw_setVelocityBounded(PlayerState *, f32, f32);
    func_80093360(arg0, 60.0f);
    yaw_setUpdateType(arg0, 3);
    yaw_setVelocityBounded(arg0, 500.0f, 2.0f);
    baroll_setAngularVelocity(arg0, 500.0f, 2.0f);
    _bafly_entrypoint_20(arg0);
    func_800959C8(arg0, 65.0f, 50.0f);
    func_800961AC(arg0, 4);
}

void func_80800128_bsbfly(PlayerState *arg0) {
    void _baboost_entrypoint_3(PlayerState *);
    void _baboost_entrypoint_4(PlayerState *, s32);
    void _bafly_entrypoint_5(PlayerState *);
    void _bastatemem_entrypoint_0(PlayerState *, s32);
    s32 func_8009E77C(PlayerState *, s32);
    if (func_8009E77C(arg0, 9) == 0) {
        _bastatemem_entrypoint_0(arg0, 0x20);
        _bafly_entrypoint_5(arg0);
        func_808000AC_bsbfly(arg0);
        _baboost_entrypoint_3(arg0);
        _baboost_entrypoint_4(arg0, 1);
    }
}

void func_80800188_bsbfly(PlayerState *arg0) {
    void _baboost_entrypoint_4(PlayerState *, s32);
    void _bafly_entrypoint_4(PlayerState *);
    void _bastatemem_entrypoint_1(void *arg0);
    void baflag_clear(PlayerState *, s32);
    void baphysics_reset_gravity(PlayerState *);
    void baphysics_reset_terminal_velocity(PlayerState *);
    void func_80093360(PlayerState *, f32);
    void func_80095A40(PlayerState *);
    void func_800961AC(PlayerState *, s32);
    s32 func_8009E74C(PlayerState *, s32);
    void func_800A042C(PlayerState *);
    void func_800A0CF4(PlayerState *, s32);
    void func_800A4E30(PlayerState *);
    void yaw_setUpdateType(PlayerState *, s32);
    if (func_8009E74C(arg0, 9) == 0) {
        _bafly_entrypoint_4(arg0);
        _bastatemem_entrypoint_1(arg0);
        baphysics_reset_gravity(arg0);
        baphysics_reset_terminal_velocity(arg0);
        func_800A0CF4(arg0, 0);
        func_80093360(arg0, 0.0f);
        func_800A042C(arg0);
        yaw_setUpdateType(arg0, 1);
        func_800A4E30(arg0);
        func_80095A40(arg0);
        func_800961AC(arg0, 1);
        _baboost_entrypoint_4(arg0, 0);
        baflag_clear(arg0, 0x2F);
        baflag_clear(arg0, 0x30);
    }
}

void func_80800248_bsbfly(PlayerState *arg0) {
    void baanim_playForDuration_once(void *self, s32 anim_id, f32 duration);
    void baphysics_set_gravity(PlayerState *, f32);
    void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
    void baphysics_set_target_yaw(PlayerState *, f32);
    f32 bastick_distance(PlayerState *);
    f32 bastick_getAngleRelativeToBanjo(PlayerState *);
    void func_8009BA9C(PlayerState *, f32 *);
    void func_8009D874(PlayerState *);
    void func_8009FFD8(PlayerState *, s32, s32, s32, s32);
    void func_800A0CF4(PlayerState *, s32);
    f32 yaw_getIdeal(PlayerState *);
    void yaw_setIdeal(PlayerState *, f32);
    baanim_playForDuration_once(arg0, 0x45, 1.4f);
    func_8009FFD8(arg0, 1, 1, 3, 6);
    if (bastick_distance(arg0) != 0.0f) {
        yaw_setIdeal(arg0, bastick_getAngleRelativeToBanjo(arg0));
    }
    baphysics_set_target_yaw(arg0, yaw_getIdeal(arg0));
    func_8009BA9C(arg0, NULL);
    baphysics_set_target_horizontal_velocity(arg0, 0.0f);
    baphysics_set_gravity(arg0, -1200.0f);
    func_800A0CF4(arg0, 1);
    func_8009D874(arg0);
    arg0->unk160.word = 0;
    arg0->unk15C.word = 0;
}

/* extern */

void func_80800320_bsbfly(PlayerState *arg0) {
    int anctrl_isAt(struct anctrl_s *, f32);
    void anctrl_setDuration(struct anctrl_s *, f32);
    struct anctrl_s *baanim_getAnimCtrlPtr(PlayerState *);
    f32 baphysics_get_vertical_velocity(PlayerState *);
    void baphysics_set_vertical_velocity(PlayerState *, f32);
    void bs_setState(PlayerState *, s32);
    void func_8009DE38(PlayerState *, s32, f32);
    s32 sp24;
    struct anctrl_s *sp20;

    sp24 = 0;
    sp20 = baanim_getAnimCtrlPtr(arg0);
    if (arg0->unk160.word == 0) {
        if (anctrl_isAt(sp20, 0.2416f) != 0) {
            anctrl_setDuration(sp20, 2.4f);
            baphysics_set_vertical_velocity(arg0, 1600.0f);
            func_8009DE38(arg0, 0x406, 0.7f);
            arg0->unk160.word = 1;
        }
    } else {
        func_80800000_bsbfly(arg0);
        if (baphysics_get_vertical_velocity(arg0) < 0.0f) {
            sp24 = 0x24;
        }
    }
    bs_setState(arg0, sp24);
}

/* extern */

void func_808003E0_bsbfly(BtIntPtr arg0) {
    void func_800A0CF4(PlayerState *, s32);
    void func_800A4E30(PlayerState *);
    void func_800C6DA0(s32 arg0);
    func_800C6DA0(0x44);
    func_800A0CF4(arg0, 0);
    func_800A4E30(arg0);
}

BsScript bsbfly_entrypoint_0(BsScriptType arg0) {
    extern BtIntPtr D_80801D48_bsbfly[];
    return (BsScript)D_80801D48_bsbfly[arg0];
}

void func_8080042C_bsbfly(PlayerState *arg0)
{
    s32 func_8009E6EC(PlayerState *);
    void func_80801BB4_bsbfly(PlayerState *);
    func_8009E6EC(arg0);
    func_80801BB4_bsbfly(arg0);
}
void func_80800454_bsbfly(PlayerState *arg0) {
    void baflag_clear(PlayerState *, s32);
    void baflag_set(PlayerState *, s32);
    s32 bs_getNextState(PlayerState *);
    s32 _bafpctrl_entrypoint_4(PlayerState *);
    s32 _bafpctrl_entrypoint_5(PlayerState *);
    void _bafpctrl_entrypoint_17(PlayerState *);
    void _bafly_entrypoint_6(PlayerState *, f32);
    void _bafly_entrypoint_7(void *, s32);
    s32 next_state;

    baflag_clear(arg0, 0x2F);
    baflag_clear(arg0, 0x30);
    next_state = bs_getNextState(arg0);
    if (((next_state == 0x18) || (next_state == 0x2A) || (next_state == 0x91)) &&
        (_bafpctrl_entrypoint_4(arg0) == 3)) {
        baflag_set(arg0, 0x2F);
        if (_bafpctrl_entrypoint_5(arg0) != 0) {
            baflag_set(arg0, 0x30);
        }
    }
    _bafpctrl_entrypoint_17(arg0);
    _bafly_entrypoint_6(arg0, 0.0f);
    _bafly_entrypoint_7(arg0, 0);
    func_80800188_bsbfly(arg0);
}

void func_8080050C_bsbfly(PlayerState *arg0) {
    void _bafly_entrypoint_19(PlayerState *);
    void baanim_playForDuration_loopSmooth(PlayerState *, s32, f32);
    int baflag_isTrue(PlayerState *, s32);
    f32 baphysics_get_target_horizontal_velocity(PlayerState *);
    void baphysics_set_gravity(PlayerState *, f32);
    void baphysics_set_horizontal_velocity(PlayerState *, f32, f32);
    void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
    void baphysics_set_target_yaw(PlayerState *, f32);
    void baphysics_set_terminal_velocity(PlayerState *, f32);
    void func_8009FFD8(PlayerState *, s32, s32, s32, s32);
    void func_800A0CF4(PlayerState *, s32);
    void func_800A4DA4(PlayerState *, s32);
    f32 yaw_getIdeal(PlayerState *);
    s32 sp2C;
    f32 sp28;

    baanim_playForDuration_loopSmooth(arg0, 0x38, 0.62f);
    func_8009FFD8(arg0, 1, 1, 3, 3);
    if (baflag_isTrue(arg0, 9)) {
        baphysics_set_target_horizontal_velocity(arg0, 0.0f);
    } else {
        baphysics_set_target_horizontal_velocity(arg0, 600.0f);
    }
    sp28 = yaw_getIdeal(arg0);
    baphysics_set_horizontal_velocity(arg0, sp28, baphysics_get_target_horizontal_velocity(arg0));
    baphysics_set_target_yaw(arg0, yaw_getIdeal(arg0));
    func_800A0CF4(arg0, 1);
    baphysics_set_gravity(arg0, -300.0f);
    baphysics_set_terminal_velocity(arg0, -99.9f);
    func_800A4DA4(arg0, 3);
    func_80800128_bsbfly(arg0);
    *(f32 *)arg0->kazfly = 1.0f;
    arg0->unk160.word = 0;
    ((u8 *)arg0->kazfly)[0x1C] = 0;
    _bafly_entrypoint_19(arg0);
}

void func_80800624_bsbfly(PlayerState *arg0) {
    s32 _baboost_entrypoint_1(void *);
    s32 _baboost_entrypoint_2(PlayerState *self, f32 arg1);
    void _baboost_entrypoint_5(void *);
    void _bafly_entrypoint_10(void *, f32, f32);
    void _bafly_entrypoint_11(void *);
    s32 _bafly_entrypoint_12(void *);
    s32 _bafly_entrypoint_2(void *);
    void _bafly_entrypoint_20(void *);
    void _bafly_entrypoint_21(void *);
    void _bafly_entrypoint_7(void *, s32);
    void _bafly_entrypoint_8(void *, f32, f32, f32, f32, f32, f32, f32);
    void _bafly_entrypoint_9(void *);
    s32 _bafpctrl_entrypoint_4();
    void _chusefeather_entrypoint_1(s32 arg0, s32 arg1);
    int anctrl_isAt(struct anctrl_s *, f32);
    void anctrl_setDuration(struct anctrl_s *, f32);
    struct anctrl_s *baanim_getAnimCtrlPtr(PlayerState *);
    s32 bainput_should_beak_bust(void *);
    s32 bakey_pressed(BtIntPtr, s32);
    void baphysics_set_vertical_velocity(PlayerState *, f32);
    void bs_setState(PlayerState *, s32);
    s32 func_8008D0E0(void *);
    f32 func_800136E4(f32);
    void func_8009BF5C(PlayerState *, f32);
    f32 func_8009BFD8(PlayerState *);
    void func_8009DFD4(void *, s32, f32, f32, s32, s32);
    f32 func_800D8FF8();
    f32 func_800F0E00(f32, f32);
    s32 player_inWater(PlayerState *);
    s32 next_state;
    struct anctrl_s *anim;
    f32 pitch;
    s32 boost;
    s32 flap;

    next_state = 0;
    anim = baanim_getAnimCtrlPtr(arg0);
    _bafly_entrypoint_20(arg0);
    _bafly_entrypoint_9(arg0);
    _bafly_entrypoint_10(arg0, 300.0f, 80.0f);
    _bafly_entrypoint_11(arg0);
    flap = 0;
    if (bakey_pressed((BtIntPtr)arg0, 8)) {
        ((u8 *)arg0->kazfly)[0x1C] = 1;
    }
    if (((u8 *)arg0->kazfly)[0x1C] && func_8001211C() % 3 == 0) {
        ((u8 *)arg0->kazfly)[0x1C] = 0;
        flap = _bafly_entrypoint_12(arg0);
    }
    if (flap || arg0->unk15C.word) {
        if (flap) {
            anctrl_setDuration(anim, 0.3f);
            _chusefeather_entrypoint_1(arg0->unk184, 0);
        }
        if (arg0->unk15C.word) {
            arg0->unk15C.word = 0;
            _baboost_entrypoint_2(arg0, 0.35f);
        } else {
            _baboost_entrypoint_2(arg0, 1.0f);
        }
    }
    boost = _baboost_entrypoint_1(arg0);
    _bafly_entrypoint_7(arg0, 0);
    switch (arg0->unk160.word) {
        case 0:
            if (boost) {
                arg0->unk160.word = 1;
            }
            break;
        case 1:
            _bafly_entrypoint_7(arg0, 1);
            pitch = func_800136E4(func_8009BFD8(arg0) - 30.0f);
            if (pitch > 80.0f && pitch < 300.0f) {
                pitch = 300.0f;
            }
            func_8009BF5C(arg0, pitch);
            _bafly_entrypoint_21(arg0);
            if (boost) {
                baphysics_set_vertical_velocity(arg0, boost * 400.0f);
            }
            if (!boost) {
                anctrl_setDuration(anim, 0.62f);
                _bafly_entrypoint_20(arg0);
                arg0->unk160.word = 0;
            }
            break;
    }
    if (anctrl_isAt(anim, 0.1358f)) {
        func_8009DFD4(arg0, 0x3FF, 0.6f, 0.7f, 10000, 12000);
    }
    _bafly_entrypoint_8(arg0, 300.0f, 80.0f, 600.0f, -300.0f, -99.9f, -700.0f, -1000.0f);
    if (_bafpctrl_entrypoint_4(arg0) != 3 && bainput_should_beak_bust(arg0)) {
        next_state = 0xF;
    }
    *(f32 *)arg0->kazfly = func_800F0E00(*(f32 *)arg0->kazfly - func_800D8FF8(), 0.0f);
    if (*(f32 *)arg0->kazfly == 0.0f && bakey_pressed((BtIntPtr)arg0, 9) && func_8008D0E0(arg0) && _bafly_entrypoint_12(arg0)) {
        next_state = 0x2A;
    }
    if (player_inWater(arg0)) {
        next_state = 0x2D;
    }
    if (_bafly_entrypoint_2(arg0)) {
        next_state = 1;
    }
    _baboost_entrypoint_5(arg0);
    bs_setState((BtIntPtr)arg0, next_state);
}

BsScript bsbfly_entrypoint_1(BsScriptType arg0) {
    extern BtIntPtr D_80801D58_bsbfly[];
    return (BsScript)D_80801D58_bsbfly[arg0];
}

/* extern */

void func_808009D0_bsbfly(PlayerState *arg0) {
    void func_8009C128(PlayerState *, f32[3]);
    void func_800EF04C(f32 *, f32 *);
    void func_800A34AC(PlayerState *, f32[3]);
    void func_8009DF58(PlayerState *, s32, f32);
    f32 sp1C[3];

    func_8009C128(arg0, sp1C);
    func_800EF04C(sp1C, (f32 *)(*(s32 *)((s8 *)arg0 + 0x188) + 0x10));
    func_800A34AC(arg0, sp1C);
    func_8009DF58(arg0, 0x40D, 1.0f);
}

void func_80800A24_bsbfly(PlayerState *arg0, s32 arg1) {
    struct anctrl_s *baanim_getAnimCtrlPtr(PlayerState *);
    void baanim_playForDuration_onceSmooth(PlayerState *, s32, f32);
    void anctrl_setDuration(struct anctrl_s *, f32);
    void baflag_clear(PlayerState *, s32);
    void baflag_set(PlayerState *, s32);
    void baphysics_set_type(void *self, s32 type);
    void baroll_setIdeal(PlayerState *, f32);
    void yaw_setIdeal(PlayerState *, f32);
    void func_8009BF5C(PlayerState *, f32);
    void func_8009DF94(PlayerState *, s32, f32, s32);
    void func_8009E0DC(PlayerState *);
    void func_8009FFD8(PlayerState *, s32, s32, s32, s32);
    void func_800A0CF4(PlayerState *, s32);
    PlayerState *func_800A4CA8(PlayerState *);
    void func_800A4DA4(PlayerState *, s32);
    void _ncbadive_entrypoint_4(PlayerState *, f32 *);
    void _ncbafly_entrypoint_5(PlayerState *, s32);
    void func_8009BA9C(PlayerState *, f32 *);
    void func_8009C128(PlayerState *, f32 *);
    void _bafly_entrypoint_1(PlayerState *, f32 *, f32 *, f32);
    void _batimer_set(PlayerState *, s32, f32);
    void _chusefeather_entrypoint_1(s32 arg0, s32 arg1);
    f32 sp34[3];
    struct anctrl_s *sp30;

    sp30 = baanim_getAnimCtrlPtr(arg0);
    switch (arg1) {
    case 0:
        func_8009E0DC(arg0);
        baflag_clear(arg0, 0x1C);
        break;
    case 1:
        baanim_playForDuration_onceSmooth(arg0, 0x43, 1.0f);
        func_8009FFD8(arg0, 1, 1, 3, 7);
        _bafly_entrypoint_1(arg0, (f32 *)((u8 *)arg0->kazfly + 0x10), sp34, 4200.0f);
        yaw_setIdeal(arg0, sp34[1] + 180.0f);
        func_8009BF5C(arg0, sp34[0]);
        baroll_setIdeal(arg0, 0.0f);
        func_8009BA9C(arg0, (f32 *)((u8 *)arg0->kazfly + 0x10));
        func_800A0CF4(arg0, 1);
        func_800A4DA4(arg0, 4);
        _ncbadive_entrypoint_4(func_800A4CA8(arg0), (f32 *)((u8 *)arg0->kazfly + 0x10));
        _ncbafly_entrypoint_5(func_800A4CA8(arg0), 1);
        func_8009DF94(arg0, 0x439, 1.0f, 0x6D60);
        baflag_clear(arg0, 0x1C);
        func_8009C128(arg0, (f32 *)((u8 *)arg0->kazfly + 4));
        _chusefeather_entrypoint_1(arg0->unk184, 0);
        break;
    case 2:
        baphysics_set_type(arg0, 8);
        func_800A4DA4(arg0, 4);
        _ncbadive_entrypoint_4(func_800A4CA8(arg0), (f32 *)((u8 *)arg0->kazfly + 0x10));
        anctrl_setDuration(sp30, 0.05f);
        func_8009DF94(arg0, 0x4437, 1.3f, 0x7FFF);
        baflag_set(arg0, 0x1C);
        _batimer_set(arg0, 1, 0.0001f);
        break;
    case 3:
        break;
    }
    arg0->unk160.word = arg1;
}

void func_80800C38_bsbfly(PlayerState *arg0) {
    void func_8009BA9C(PlayerState *, f32 *);
    void func_800EF04C(f32 *, f32 *);
    f32 bastick_getX(PlayerState *);
    f32 bastick_getY(PlayerState *);
    f32 *func_800A4C48(PlayerState *);
    void func_800CA9D8(f32 *, f32 *);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF8BC(f32 *, f32 *, f32);
    void func_800EF934(f32 *, f32 *, f32);
    void func_800EFA4C(f32 *, f32, f32, f32);
    f32 sp44[3];
    f32 sp38[3];
    f32 sp2C[3];

    func_800EE7F8(sp38, (f32 *)(*(s32 *)((s8 *)arg0 + 0x188) + 0x10));
    func_800CA9D8(func_800A4C48(arg0), sp2C);
    func_800EFA4C(sp44, bastick_getX(arg0) * 1000.0f, 0.0f, 0.0f);
    func_800EF8BC(sp44, sp44, sp2C[0]);
    func_800EF934(sp44, sp44, sp2C[1]);
    func_800EF04C(sp38, sp44);
    func_800EFA4C(sp44, 0.0f, -bastick_getY(arg0) * 1000.0f, 0.0f);
    func_800EF8BC(sp44, sp44, sp2C[0]);
    func_800EF934(sp44, sp44, sp2C[1]);
    func_800EF04C(sp38, sp44);
    func_8009BA9C(arg0, sp38);
}

void func_80800D50_bsbfly(PlayerState *arg0) { func_80800128_bsbfly(arg0); (arg0->unk160.word) = 0; func_80800A24_bsbfly(arg0, 1); }

s32 func_80800D80_bsbfly(PlayerState *arg0, s32 arg1) {
    int baflag_isTrue(PlayerState *, s32);
    void func_800963C0(PlayerState *, f32 *);
    s32 func_80096434(PlayerState *);
    void func_80096440(PlayerState *, f32 *);
    s32 func_8009650C(PlayerState *);
    s32 func_80096628(PlayerState *);
    s32 func_800A1718(PlayerState *);
    void func_800A17A8(PlayerState *, s32);
    void func_800EE7F8(f32 *, f32 *);
    f32 func_800EEAA4(f32 *, f32 *);
    void func_800EF2A0(f32 *);
    f32 mlAbsF(f32);
    s32 player_inWater(PlayerState *);
    int player_isStable(PlayerState *);
    f32 sp44;
    f32 sp38[3];
    f32 sp2C[3];
    s32 sp28;
    s32 sp24;

    if (player_inWater(arg0)) {
        arg1 = 0x4C;
    }
    sp24 = player_isStable(arg0);
    if (!func_8009650C(arg0) && !sp24) {
        return arg1;
    }
    if (sp24) {
        func_800963C0(arg0, sp38);
        sp28 = func_80096628(arg0);
    } else {
        func_80096440(arg0, sp38);
        sp28 = func_80096434(arg0);
    }
    func_800EE7F8(sp2C, (f32 *)arg0->kazfly + 4);
    func_800EF2A0(sp2C);
    sp44 = mlAbsF(func_800EEAA4(sp38, sp2C));
    if (baflag_isTrue(arg0, 8) || (sp28 & 0x80)) {
        func_808009D0_bsbfly(arg0);
        arg1 = 0x18;
    } else if (sp44 > 0.4f) {
        if (sp38[1] < 0.65f) {
            func_808009D0_bsbfly(arg0);
            func_800A17A8(arg0, -1);
            if (func_800A1718(arg0)) {
                arg1 = 0x59;
            } else {
                arg1 = 0x41;
            }
        } else {
            arg1 = 0x58;
        }
    } else if (sp24) {
        arg1 = 0x58;
    }
    return arg1;
}

void func_80800F10_bsbfly(PlayerState *arg0) {
    void _bafly_entrypoint_11(void *);
    s32 _bafly_entrypoint_12(void *);
    void _bafly_entrypoint_6(PlayerState *, f32);
    s32 _batimer_decrement(void *, s32);
    void _batimer_set(PlayerState *, s32, f32);
    void _chusefeather_entrypoint_1(s32 arg0, s32 arg1);
    int anctrl_isAt(struct anctrl_s *, f32);
    s32 anctrl_isStopped(struct anctrl_s *);
    void anctrl_setDuration(struct anctrl_s *, f32);
    void anctrl_setIndex();
    void anctrl_setPlaybackType(struct anctrl_s *, s32);
    void anctrl_start(struct anctrl_s *);
    struct anctrl_s *baanim_getAnimCtrlPtr(PlayerState *);
    int bakey_held(PlayerState *, s32);
    int bakey_released(PlayerState *, int);
    void bs_setState(PlayerState *, s32);
    void func_8009DDDC(PlayerState *);
    f32 func_800EEFD4(f32 *);
    void func_800EF3DC(f32 *, f32 *);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    s32 next_state = 0;
    struct anctrl_s *anim;
    f32 position[3];
    s32 pad[2];

    anim = baanim_getAnimCtrlPtr(arg0);
    _bafly_entrypoint_11(arg0);
    func_8009DDDC(arg0);
    switch (arg0->unk160.word) {
    case 1:
        if (anctrl_isAt(anim, 0.6905f)) {
            func_80800A24_bsbfly(arg0, 2);
        }
        break;
    case 2:
        func_80800C38_bsbfly(arg0);
        if (anctrl_isStopped(anim)) {
            anctrl_setIndex(anim, 0x47);
            anctrl_setDuration(anim, 0.3f);
            anctrl_setPlaybackType(anim, 2);
            anctrl_start(anim);
        }
        func_8009C128(arg0, position);
        func_800EF3DC(position, (f32 *)arg0->kazfly + 1);
        _bafly_entrypoint_6(arg0, func_800F10B4(func_800EEFD4(position), 0.0f, 16000000.0f, 0.2f, 0.7f));
        if (func_800EEFD4(position) > 16000000.0f) {
            if (bakey_held(arg0, 9)) {
                func_80800A24_bsbfly(arg0, 3);
            } else {
                next_state = 0x57;
            }
        }
        func_80800000_bsbfly(arg0);
        next_state = func_80800D80_bsbfly(arg0, next_state);
        break;
    case 3:
        func_80800C38_bsbfly(arg0);
        if (bakey_released(arg0, 9)) {
            next_state = 0x57;
        } else if (_batimer_decrement(arg0, 1)) {
            if (_bafly_entrypoint_12(arg0)) {
                _chusefeather_entrypoint_1(arg0->unk184, 0);
                _batimer_set(arg0, 1, 1.0f);
            } else {
                next_state = 0x57;
            }
        }
        func_80800000_bsbfly(arg0);
        next_state = func_80800D80_bsbfly(arg0, next_state);
        break;
    }
    bs_setState(arg0, next_state);
}

void func_80801138_bsbfly(BtIntPtr arg0)
{
    func_80800A24_bsbfly(arg0,0);
    func_80800188_bsbfly(arg0);
}

BsScript bsbfly_entrypoint_2(BsScriptType arg0) {
    extern BtIntPtr D_80801D68_bsbfly[];
    return (BsScript)D_80801D68_bsbfly[arg0];
}

void func_80801178_bsbfly(PlayerState *arg0) {
    s32 bs_getNextState(PlayerState *);
    void func_8009DBF0(PlayerState *, s32, f32);
    void func_8009E0DC(PlayerState *);
    void func_8009E100(PlayerState *);
    s32 func_8009E74C(PlayerState *, s32);
    void func_800A0CF4(PlayerState *, s32);
    s32 next_state;

    func_8009E0DC(arg0);
    func_8009E100(arg0);
    if (func_8009E74C(arg0, 9) != 0) {
        func_808000AC_bsbfly(arg0);
    }
    next_state = bs_getNextState(arg0);
    if (next_state == 0x20 || next_state == 0x24 || next_state == 0x2D) {
        func_8009DBF0(arg0, 0x3EA, 1.0f);
    }
    func_80800188_bsbfly(arg0);
    func_800A0CF4(arg0, 0);
}

void func_80801208_bsbfly(PlayerState *arg0) {
    void anctrl_reset(struct anctrl_s *);
    void anctrl_setDuration(struct anctrl_s *, f32);
    void anctrl_setIndex();
    void anctrl_setPlaybackType(struct anctrl_s *, s32);
    void anctrl_start(struct anctrl_s *);
    struct anctrl_s *baanim_getAnimCtrlPtr(PlayerState *);
    void baphysics_reset_gravity(PlayerState *);
    void baphysics_reset_terminal_velocity(PlayerState *);
    void baroll_setIdeal(PlayerState *, f32);
    void func_8008B1C8(struct anctrl_s *, f32);
    void func_80093360(PlayerState *, f32);
    void func_80095A40(PlayerState *);
    void func_800961AC(PlayerState *, s32);
    void func_8009BF5C(PlayerState *, f32);
    void func_8009DB04(PlayerState *, s32, f32, s32);
    void func_8009DF94(PlayerState *, s32, f32, s32);
    void func_8009FFD8();
    void func_800A0CF4(PlayerState *, s32);
    struct anctrl_s *control;

    control = baanim_getAnimCtrlPtr(arg0);
    anctrl_reset(control);
    func_8008B1C8(control, 0.3f);
    anctrl_setIndex(control, 0xCC);
    anctrl_setDuration(control, 0.38f);
    anctrl_setPlaybackType(control, 2);
    anctrl_start(control);
    func_8009FFD8(arg0, 1, 1, 3, 3);
    func_800A0CF4(arg0, 1);
    func_80800128_bsbfly(arg0);
    func_80095A40(arg0);
    func_800961AC(arg0, 1);
    baroll_setIdeal(arg0, 0.0f);
    func_8009BF5C(arg0, 0.0f);
    baphysics_reset_gravity(arg0);
    baphysics_reset_terminal_velocity(arg0);
    func_80093360(arg0, 0.0f);
    func_8009DF94(arg0, 0x420, 1.0f, 0x7FFF);
    func_8009DB04(arg0, 0x444, 1.0f, 0x7FFF);
    *(f32 *)arg0->kazfly = 0.35f;
    arg0->unk160.word = 0;
}

void func_80801334_bsbfly(PlayerState *arg0) {
    void baanim_playForDuration_onceSmoothStartingAt(void *, s32, f32, f32);
    s32 bainput_should_beak_bust(void *);
    void bs_setState(PlayerState *, s32);
    int func_8008DF8C(PlayerState *, s32);
    void func_8009BB24(void *, f32 *);
    void func_8009FE58(PlayerState *);
    f32 func_800D8FF8(void);
    s32 player_inWater(PlayerState *);
    int player_isStable(PlayerState *);
    s32 sp34;
    f32 sp28[3];

    sp34 = 0;
    func_8009BB24(arg0, sp28);
    switch (arg0->unk160.word) {
        case 0:
            if (func_8008DF8C(arg0, 0x5A) != 0) {
                baanim_playForDuration_onceSmoothStartingAt(arg0, 8, 2.0f, 0.6667f);
                arg0->unk160.word = 1;
            }
            break;
        case 1:
            break;
    }
    *(f32 *)arg0->kazfly -= func_800D8FF8();
    if (*(f32 *)arg0->kazfly < 0.0f) {
        arg0->unk15C.word = 1;
        sp34 = 0x24;
    }
    if (bainput_should_beak_bust(arg0) != 0) {
        sp34 = 0xF;
    }
    if (player_isStable(arg0) != 0) {
        func_8009FE58(arg0);
        sp34 = 0x20;
    }
    if (player_inWater(arg0) != 0) {
        sp34 = 0x2D;
    }
    bs_setState(arg0, sp34);
}

BsScript bsbfly_entrypoint_3(BsScriptType arg0) {
    extern BtIntPtr D_80801D78_bsbfly[];
    return (BsScript)D_80801D78_bsbfly[arg0];
}

/* extern */

void func_8080145C_bsbfly(PlayerState *self) {
    void _badust_entrypoint_5(PlayerState *, f32, f32);
    f32 angle;

    for (angle = 0.0f; angle < 360.0f; angle += 45.0f) {
        _badust_entrypoint_5(self, angle, 230.0f);
    }
}

void func_808014E8_bsbfly(PlayerState *arg0) {
    void _bamotor_entrypoint_1(PlayerState *, f32, f32, f32);
    void _basudie_entrypoint_1(PlayerState *);
    void baanim_playForDuration_onceSmooth(PlayerState *, s32, f32);
    void func_8008E944(PlayerState *);
    void func_8009D820(PlayerState *, f32);
    void func_8009DF18(PlayerState *, s32, f32, s32);
    void func_8009FFD8(PlayerState *, s32, s32, s32, s32);
    void func_800A0CF4(PlayerState *, s32);
    s32 func_800A1718(PlayerState *);
    void func_800A17A8(PlayerState *, s32);
    baanim_playForDuration_onceSmooth(arg0, 0x3E, 1.4f);
    func_8009FFD8(arg0, 1, 1, 3, 3);
    func_800A0CF4(arg0, 1);
    func_8009DF18(arg0, 0x417, 0.8f, 0x7FFF);
    func_8009D820(arg0, 1.8f);
    _bamotor_entrypoint_1(arg0, 1.0f, 0.5f, 0.5f);
    func_800A17A8(arg0, -1);
    if (func_800A1718(arg0) == 0) {
        _basudie_entrypoint_1(arg0);
    }
    func_8080145C_bsbfly(arg0);
    func_8008E944(arg0);
    arg0->unk160.word = 0;
}

/* extern */

void func_808015C4_bsbfly(PlayerState *arg0) {
    void _badust_entrypoint_9(void *);
    f32 anctrl_getAnimTimer(struct anctrl_s *);
    int anctrl_isAt(struct anctrl_s *, f32);
    struct anctrl_s *baanim_getAnimCtrlPtr(PlayerState *);
    void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
    void func_8009DF18(PlayerState *, s32, f32, s32);
    struct anctrl_s *sp24;
    struct anctrl_s *temp_v0;

    temp_v0 = baanim_getAnimCtrlPtr(arg0);
    sp24 = temp_v0;
    if (anctrl_isAt(temp_v0, 0.3659f) != 0) {
        func_8009DF18(arg0, 0x417, 1.0f, 0x36B0);
        func_8009DF18(arg0, 0x4454, 1.0f, 0x6D60);
    }
    if (anctrl_isAt(sp24, 0.6862f) != 0) {
        func_8009DF18(arg0, 0x417, 0.8f, 0x4650);
        func_8009DF18(arg0, 0x427, 1.0f, 0x55F0);
    }
    if (anctrl_isAt(sp24, 0.92f) != 0) {
        baphysics_set_target_horizontal_velocity(arg0, 0.0f);
    }
    if (anctrl_getAnimTimer(sp24) < 0.8f) {
        _badust_entrypoint_9(arg0);
    }
}

void func_808016B4_bsbfly(PlayerState *arg0) {
    void _basudie_entrypoint_0(PlayerState *);
    void _basudie_entrypoint_1(PlayerState *);
    s32 _batimer_decrement(void *, s32);
    void _batimer_set(PlayerState *, s32, f32);
    void _ncbadie_entrypoint_3(PlayerState *, f32);
    int anctrl_isAt(struct anctrl_s *, f32);
    s32 anctrl_isStopped(struct anctrl_s *);
    struct anctrl_s *baanim_getAnimCtrlPtr(PlayerState *);
    void baanim_playForDuration_onceSmooth(PlayerState *, s32, f32);
    void bs_setState(PlayerState *, s32);
    int func_8008DD04(PlayerState *);
    void func_8009D3A8(PlayerState *, s32);
    void func_800A0180(PlayerState *);
    PlayerState *func_800A4CA8(PlayerState *);
    void func_800A4DFC(PlayerState *, s32);
    s32 func_800F8B64(void);
    s32 sp24;
    struct anctrl_s *sp20;

    sp24 = 0;
    sp20 = baanim_getAnimCtrlPtr(arg0);
    func_8009D3A8(arg0, 0);
    switch (arg0->unk160.word) {
    case 0:
        func_808015C4_bsbfly(arg0);
        if (anctrl_isAt(sp20, 0.2f) != 0) {
            if (func_800F8B64() != 0) {
                func_800A0180(arg0);
                func_800A4DFC(arg0, 0xA);
                _ncbadie_entrypoint_3(func_800A4CA8(arg0), 30.0f);
                _basudie_entrypoint_1(arg0);
                _batimer_set(arg0, 0, 3.2f);
                arg0->unk160.word = 2;
            }
        } else if (anctrl_isAt(sp20, 0.92f) != 0) {
            baanim_playForDuration_onceSmooth(arg0, 0xD2, 2.25f);
            arg0->unk160.word = 1;
        }
        break;
    case 1:
        if (anctrl_isAt(sp20, 0.63f) != 0) {
            sp24 = 0x20;
        }
        if (anctrl_isStopped(sp20) != 0) {
            sp24 = 1;
        }
        if (func_8008DD04(arg0) != 0) {
            sp24 = 0x2F;
        }
        break;
    case 2:
        func_808015C4_bsbfly(arg0);
        if (_batimer_decrement(arg0, 0) != 0) {
            _basudie_entrypoint_0(arg0);
        }
        break;
    }
    bs_setState(arg0, sp24);
}

/* extern */

void func_8080183C_bsbfly(BtIntPtr arg0) {
    void func_8008E95C(PlayerState *arg0);
    void func_800A042C(PlayerState *);
    void func_800A0CF4(PlayerState *, s32);
    void func_800A4E30(PlayerState *);
    func_800A4E30(arg0);
    func_800A042C(arg0);
    func_800A0CF4(arg0, 0);
    func_8008E95C(arg0);
}

BsScript bsbfly_entrypoint_4(BsScriptType arg0) {
    extern BtIntPtr D_80801D88_bsbfly[];
    return (BsScript)D_80801D88_bsbfly[arg0];
}

/* extern */

void func_8080188C_bsbfly(PlayerState *arg0) {
    s32 _bafly_entrypoint_13(BtIntPtr, s32, s32, s32);
    void func_800A0CF4(PlayerState *, s32);
    func_80800128_bsbfly(arg0);
    _bafly_entrypoint_13(arg0, 0, 0xD3, 0x3F99999A);
    func_800A0CF4(arg0, 1);
}

void func_808018D0_bsbfly(BtIntPtr arg0) {
    void _bafly_entrypoint_14(PlayerState *arg0, s32 arg1, s32 arg2);
    _bafly_entrypoint_14(arg0, 0x24, 2);
}

void func_808018F4_bsbfly(BtIntPtr arg0) { void func_800A0CF4(PlayerState *, s32); func_800A0CF4(arg0, 0); _bafly_entrypoint_15(arg0); func_80800188_bsbfly(arg0); }

BsScript bsbfly_entrypoint_5(BsScriptType arg0) {
    extern BtIntPtr D_80801D98_bsbfly[];
    return (BsScript)D_80801D98_bsbfly[arg0];
}

/* extern */

void func_8080193C_bsbfly(PlayerState *arg0) {
    s32 _bafly_entrypoint_13(BtIntPtr, s32, s32, s32);
    void func_800A0CF4(PlayerState *, s32);
    func_80800128_bsbfly(arg0);
    _bafly_entrypoint_13(arg0, 1, 0xD3, 0x3F99999A);
    func_800A0CF4(arg0, 1);
}

void func_80801980_bsbfly(BtIntPtr arg0) {
    void _bafly_entrypoint_14(PlayerState *arg0, s32 arg1, s32 arg2);
    _bafly_entrypoint_14(arg0, 0x24, 2);
}

void func_808019A4_bsbfly(BtIntPtr arg0) { void func_800A0CF4(PlayerState *, s32); func_800A0CF4(arg0, 0); _bafly_entrypoint_15(arg0); func_80800188_bsbfly(arg0); }

BsScript bsbfly_entrypoint_6(BsScriptType arg0) {
    extern BtIntPtr D_80801DA8_bsbfly[];
    return (BsScript)D_80801DA8_bsbfly[arg0];
}

/* extern */

void func_808019EC_bsbfly(PlayerState *arg0) {
    s32 _bafly_entrypoint_16(BtIntPtr, s32, s32);
    func_80800128_bsbfly(arg0);
    _bafly_entrypoint_16(arg0, 0x10D, 0x3F800000);
}

void func_80801A1C_bsbfly(BtIntPtr arg0) {
    void _bafly_entrypoint_17(PlayerState *arg0, s32 arg1, s32 arg2, s32 *arg3);
    _bafly_entrypoint_17(arg0, 0x24, 0x20, arg0 + 0x15C);
}

void func_80801A44_bsbfly(BtIntPtr arg0)
{
    _bafly_entrypoint_18();
    func_80800188_bsbfly(arg0);
}
BsScript bsbfly_entrypoint_7(BsScriptType arg0) {
    extern BtIntPtr D_80801DB8_bsbfly[];
    return (BsScript)D_80801DB8_bsbfly[arg0];
}

void func_80801A80_bsbfly(PlayerState *arg0) {
    void baanim_playForDuration_loopSmooth(PlayerState *, s32, f32);
    void func_8009FFD8(PlayerState *, s32, s32, s32, s32);
    void func_800A0CF4(PlayerState *, s32);
    void func_800A0024(PlayerState *);

    func_80800128_bsbfly(arg0);
    baanim_playForDuration_loopSmooth(arg0, 0x38, 0.62f);
    func_8009FFD8(arg0, 1, 1, 3, 7);
    func_800A0CF4(arg0, 1);
    func_800A0024(arg0);
}

/* extern */

void func_80801AEC_bsbfly(PlayerState *arg0) {
    int anctrl_isAt(struct anctrl_s *, f32);
    struct anctrl_s *baanim_getAnimCtrlPtr(PlayerState *);
    void bs_setState(PlayerState *, s32);
    s32 func_8009CC68(PlayerState *);
    void func_8009DEC0(PlayerState *, s32, f32, f32, s32, s32);
    void func_800A0024(PlayerState *);
    s32 sp2C;

    sp2C = 0;
    if (anctrl_isAt(baanim_getAnimCtrlPtr(arg0), 0.1358f) != 0) {
        func_8009DEC0(arg0, 0x3FF, 0.6f, 0.7f, 0x2710, 0x2EE0);
    }
    if (func_8009CC68(arg0) == 0) {
        sp2C = 0x24;
    }
    func_800A0024(arg0);
    bs_setState(arg0, sp2C);
}

void func_80801B80_bsbfly(PlayerState *arg0)
{
    func_80800188_bsbfly(arg0);
}

BsScript bsbfly_entrypoint_8(BsScriptType arg0) {
    extern BtIntPtr D_80801DC8_bsbfly[];
    return (BsScript)D_80801DC8_bsbfly[arg0];
}

void func_80801BB4_bsbfly(PlayerState *arg0) {
    s32 _baboost_entrypoint_2(PlayerState *self, f32 arg1);
    void baflag_set(PlayerState *, s32);
    s32 bs_getCurrentState(PlayerState *);
    void func_80099B94(PlayerState *);
    s32 func_8009E6EC(PlayerState *);
    void func_8009E830(PlayerState *, s32);
    void func_800A046C(PlayerState *);

    switch (func_8009E6EC(arg0)) {
    case 9:
        func_8009E830(arg0, 2);
        baflag_set(arg0, 7);
        func_800A046C(arg0);
        break;
    case 24:
        if (bs_getCurrentState(arg0) == 0x24) {
            _baboost_entrypoint_2(arg0, 6.0f);
            func_8009E830(arg0, 2);
        }
        break;
    default:
        func_80099B94(arg0);
        break;
    }
}

/* extern */

void func_80801C58_bsbfly(BtIntPtr arg0) {
    s32 _badrone_entrypoint_3(BtIntPtr);
    void _bsdrone_entrypoint_0(struct player_state_s *arg0);
    void baphysics_set_type(void *self, s32 type);
    func_80800128_bsbfly(arg0);
    _bsdrone_entrypoint_0(arg0);
    if (_badrone_entrypoint_3(arg0) == 0xE) {
        baphysics_set_type(arg0, 7);
    }
}

void func_80801C9C_bsbfly(PlayerState* self)
{
    _bsdrone_entrypoint_1(self);
}
#ifdef BT_NATIVE
struct player_state_s;
void _bsdrone_entrypoint_2(struct player_state_s *);
#endif

void func_80801CBC_bsbfly(BT_NATIVE_ONLY(struct player_state_s *) BT_IDO_ONLY(BtIntPtr) arg0)
{
    _bsdrone_entrypoint_2(BT_NATIVE_ONLY(arg0));
    func_80800188_bsbfly(arg0);
}
BsScript bsbfly_entrypoint_9(BsScriptType arg0) {
    extern BtIntPtr D_80801DD8_bsbfly[];
    return (BsScript)D_80801DD8_bsbfly[arg0];
}
/* data_to_c.py: from asm/data/overlays/bs/bfly.data.s */
void func_80099AA8();
void func_80099B94 ( PlayerState * );
void _bsdrone_entrypoint_3();
s32 D_80801D20_bsbfly[10] BT_DATA(4, overlays_bs_bfly, 0x0) = { 1903076, 1376281, 10027042, 6684761, 1638425, 2556304, 26215200, 52428843, 8388736, 0 };
BtIntPtr D_80801D48_bsbfly [4] BT_DATA(4, overlays_bs_bfly, 0x28) = { (BtIntPtr)func_808003E0_bsbfly, (BtIntPtr)func_80800248_bsbfly, (BtIntPtr)func_80800320_bsbfly, (BtIntPtr)func_80801BB4_bsbfly };
BtIntPtr D_80801D58_bsbfly [4] BT_DATA(4, overlays_bs_bfly, 0x38) = { (BtIntPtr)func_80800454_bsbfly, (BtIntPtr)func_8080050C_bsbfly, (BtIntPtr)func_80800624_bsbfly, (BtIntPtr)func_8080042C_bsbfly };
BtIntPtr D_80801D68_bsbfly [4] BT_DATA(4, overlays_bs_bfly, 0x48) = { (BtIntPtr)func_80801138_bsbfly, (BtIntPtr)func_80800D50_bsbfly, (BtIntPtr)func_80800F10_bsbfly, (BtIntPtr)func_80801BB4_bsbfly };
BtIntPtr D_80801D78_bsbfly [4] BT_DATA(4, overlays_bs_bfly, 0x58) = { (BtIntPtr)func_80801178_bsbfly, (BtIntPtr)func_80801208_bsbfly, (BtIntPtr)func_80801334_bsbfly, (BtIntPtr)func_80801BB4_bsbfly };
BtIntPtr D_80801D88_bsbfly [4] BT_DATA(4, overlays_bs_bfly, 0x68) = { (BtIntPtr)func_8080183C_bsbfly, (BtIntPtr)func_808014E8_bsbfly, (BtIntPtr)func_808016B4_bsbfly, (BtIntPtr)func_80099AA8 };
BtIntPtr D_80801D98_bsbfly [4] BT_DATA(4, overlays_bs_bfly, 0x78) = { (BtIntPtr)func_808018F4_bsbfly, (BtIntPtr)func_8080188C_bsbfly, (BtIntPtr)func_808018D0_bsbfly, (BtIntPtr)func_80801BB4_bsbfly };
BtIntPtr D_80801DA8_bsbfly [4] BT_DATA(4, overlays_bs_bfly, 0x88) = { (BtIntPtr)func_808019A4_bsbfly, (BtIntPtr)func_8080193C_bsbfly, (BtIntPtr)func_80801980_bsbfly, (BtIntPtr)func_80801BB4_bsbfly };
BtIntPtr D_80801DB8_bsbfly [4] BT_DATA(4, overlays_bs_bfly, 0x98) = { (BtIntPtr)func_80801A44_bsbfly, (BtIntPtr)func_808019EC_bsbfly, (BtIntPtr)func_80801A1C_bsbfly, (BtIntPtr)func_80099B94 };
BtIntPtr D_80801DC8_bsbfly [4] BT_DATA(4, overlays_bs_bfly, 0xA8) = { (BtIntPtr)func_80801B80_bsbfly, (BtIntPtr)func_80801A80_bsbfly, (BtIntPtr)func_80801AEC_bsbfly, (BtIntPtr)func_80099B94 };
BtIntPtr D_80801DD8_bsbfly [6] BT_DATA(4, overlays_bs_bfly, 0xB8) = { (BtIntPtr)func_80801CBC_bsbfly, (BtIntPtr)func_80801C58_bsbfly, (BtIntPtr)func_80801C9C_bsbfly, (BtIntPtr)_bsdrone_entrypoint_3, 0, 0 };
