#include "common.h"
#ifdef BT_NATIVE // complete the enum forward declarations below
#include "overlays/ba/assets.h"
#endif
#include "overlays/ba/playerstate.h"
struct player_state_s; 
void func_80800000_bsvan(struct player_state_s *arg0) {
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
    baphysics_set_target_horizontal_velocity(arg0, func_800F1214(sp1C, 30.0f, 900.0f));
}

/* extern */

struct player_state_s;

s32 func_80800064_bsvan(struct player_state_s *arg0, s32 arg1) {
    s32 _badrone_entrypoint_24(struct player_state_s *);
    int bainput_should_enter_first_person(struct player_state_s *);
    int bakey_pressed(struct player_state_s *, int);
    if (bainput_should_enter_first_person(arg0) != 0) {
        arg1 = _badrone_entrypoint_24(arg0);
    }
    if (bakey_pressed(arg0, 8) != 0) {
        arg1 = 0x115;
    }
    return arg1;
}

void func_808000BC_bsvan(u8 *arg0) {
    int bakey_pressed(struct player_state_s *, int);
    if (bakey_pressed(arg0, 9) != 0) {
        _bavan_entrypoint_1(arg0);
    }
}

void bsvan_entrypoint_0(struct player_state_s *arg0) {
    void _bastatemem_entrypoint_1(void *arg0);
    void _bavan_entrypoint_2(void *self);
    void baflag_clear(struct player_state_s *, s32);
    void baroll_resetAngularVelocity(struct player_state_s *);
    void baroll_setIdeal(struct player_state_s *, f32);
    void bastick_popZone(struct player_state_s *);
    void func_80092864(struct player_state_s *, f32);
    void func_800947EC(struct player_state_s *, s32, s32);
    void func_80095A40(struct player_state_s *);
    void func_8009BF5C(struct player_state_s *, f32);
    void func_8009C000(struct player_state_s *);
    void func_8009E474(struct player_state_s *);
    s32 func_8009E74C(struct player_state_s *, s32);

    if (func_8009E74C(arg0, 0xD) == 0) {
        _bastatemem_entrypoint_1(arg0);
        func_80092864(arg0, 1.0f);
        func_800947EC(arg0, 1, 0);
        func_8009BF5C(arg0, 0.0f);
        baroll_setIdeal(arg0, 0.0f);
        func_8009C000(arg0);
        baroll_resetAngularVelocity(arg0);
        bastick_popZone(arg0);
        func_80095A40(arg0);
        func_8009E474(arg0);
        baflag_clear(arg0, 3);
        baflag_clear(arg0, 4);
        _bavan_entrypoint_2(arg0);
    }
}

void bsvan_entrypoint_1(struct player_state_s *arg0) {
    void _bastatemem_entrypoint_0(struct player_state_s *, s32);
    void _batimer_set(struct player_state_s *, s32, f32);
    void _bavan_entrypoint_3(struct player_state_s *);
    void baflag_set(struct player_state_s *, s32);
    void baroll_setAngularVelocity(struct player_state_s *, f32, f32);
    void bastick_pushZone(struct player_state_s *);
    void bastick_setZoneMax(struct player_state_s *, s32, f32);
    void func_80092864(struct player_state_s *, f32);
    void func_800947EC(struct player_state_s *, s32, s32);
    void func_8009590C(struct player_state_s *, f32);
    void func_800959C8(struct player_state_s *, f32, f32);
    void func_8009BFE4(struct player_state_s *, f32, f32);
    void func_8009E4AC(struct player_state_s *);
    void func_8009E55C(struct player_state_s *, s32, f32);
    s32 func_8009E77C(struct player_state_s *, s32);
    if (func_8009E77C(arg0, 0xD) == 0) {
        _bastatemem_entrypoint_0(arg0, 0x14);
        _bavan_entrypoint_3(arg0);
        **(s32 **)((u8 *)arg0 + 0x188) = 0;
        arg0->unk174 = 1.0f;
        _batimer_set(arg0, 2, 0.0f);
        func_80092864(arg0, 2.29998779296875f);
        func_8009BFE4(arg0, 1000.0f, 12.0f);
        baroll_setAngularVelocity(arg0, 1000.0f, 12.0f);
        bastick_pushZone(arg0);
        bastick_setZoneMax(arg0, 0, 0.12f);
        bastick_setZoneMax(arg0, 1, 1.0f);
        func_800959C8(arg0, 110.0f, 65.0f);
        func_8009590C(arg0, 110.0f);
        func_8009E4AC(arg0);
        func_8009E55C(arg0, 0, 70.0f);
        func_8009E55C(arg0, 1, 78.0f);
        baflag_set(arg0, 3);
        baflag_set(arg0, 4);
        func_800947EC(arg0, 1, 1);
    }
}

void bsvan_entrypoint_2(struct player_state_s *arg0) {
    BtIntPtr func_800B5BE4(s32);
    BtIntPtr func_800BABB8(BtIntPtr, f32[3], f32[3], f32, s32[]);
    void func_8009C128(struct player_state_s *, f32[3]);
    extern s32 D_80801B90_bsvan[44];
    f32 sp24[3];
    BtIntPtr sp20;

    sp20 = func_800B5BE4(8);
    func_8009C128(arg0, sp24);
    func_800BABB8(sp20, sp24, NULL, 1.0f, D_80801B90_bsvan);
}

void func_8080032C_bsvan(void *arg0) {
    void func_80092C90(void *, f32[3], s32);
    BtIntPtr func_800B5BE4(s32);
    void func_800BA22C(BtIntPtr, s32);
    void func_800BA77C(BtIntPtr, s16, s16, s16);
    BtIntPtr func_800BABB8(BtIntPtr, f32[3], f32[3], f32, s32[]);
    f32 func_800DC178(f32, f32);
    extern s32 D_80801C40_bsvan[19];
    f32 sp2C[3];
    BtIntPtr sp28;
    BtIntPtr temp_v0;

    func_80092C90(arg0, sp2C, 4);
    temp_v0 = func_800B5BE4(8);
    sp28 = temp_v0;
    func_800BABB8(temp_v0, sp2C, NULL, 1.0f, D_80801C40_bsvan);
    func_800BA77C(sp28, 0, 0, (s16) (s32) func_800DC178(0.0f, 359.0f));
    func_800BA22C(sp28, 1);
}

/* extern */

void bsvan_entrypoint_3(struct player_state_s *arg0) {
    void _bavan_entrypoint_4(struct player_state_s *, f32);
    void _bavan_entrypoint_5(struct player_state_s *, f32);
    void _bavan_entrypoint_6(struct player_state_s *, f32);
    void _bavan_entrypoint_8(struct player_state_s *);
    f32 func_8009BB5C(struct player_state_s *);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    f32 func_800F13F0(f32, f32);
    f32 func_800F1DCC(f32, f32);
    int player_isStable(struct player_state_s *);
    f32 yaw_get(struct player_state_s *);
    f32 yaw_getIdeal(struct player_state_s *);
    f32 var_f2;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 var_f12;
    f32 sp2C;

    sp2C = yaw_getIdeal(arg0);
    _bavan_entrypoint_5(arg0, func_800F1DCC(sp2C, yaw_get(arg0)));
    temp_f0 = func_8009BB5C(arg0);
    if (temp_f0 > 1.0f) {
        temp_f0 = func_800F10B4(temp_f0, 30.0f, 900.0f, 45.0f, 1350.0f);
    } else {
        temp_f0 = 0.0f;
    }
    _bavan_entrypoint_6(arg0, temp_f0);
    temp_f0_2 = func_8009BB5C(arg0);
    if (temp_f0_2 > 0.0f) {
        var_f2 = func_800F10B4(temp_f0_2, 30.0f, 900.0f, 0.8f, 1.25f);
    } else {
        var_f2 = 0.8f;
    }
    if (player_isStable(arg0) == 0) {
        var_f2 = func_800F13F0(1.9f, var_f2 + 0.3f);
    }
    _bavan_entrypoint_4(arg0, var_f2);
    _bavan_entrypoint_8(arg0);
}

void func_808004F8_bsvan(BtIntPtr arg0)
{
    _basudie_entrypoint_6();
    bsvan_entrypoint_0(arg0);
}
struct anctrl_s;
enum asset_e;
void func_80800520_bsvan(struct player_state_s *arg0) {
    void _basudie_entrypoint_2(BtIntPtr arg0, f32 arg1, f32 arg2, f32 arg3);
    void anctrl_reset(struct anctrl_s *);
    void anctrl_setDuration(struct anctrl_s *, f32);
    void anctrl_setIndex(struct anctrl_s *, enum asset_e);
    void anctrl_setPlaybackType(struct anctrl_s *, s32);
    void anctrl_setSmoothTransition(struct anctrl_s *, s32);
    void anctrl_setSubrange(struct anctrl_s *, f32, f32);
    void anctrl_start(struct anctrl_s *);
    struct anctrl_s *baanim_getAnimCtrlPtr(struct player_state_s *);
    void func_8009D820(struct player_state_s *, f32);
    struct anctrl_s *control;

    control = baanim_getAnimCtrlPtr(arg0);
    bsvan_entrypoint_1(arg0);
    arg0->unk16C = 250.0f;
    _basudie_entrypoint_2(arg0, 250.0f, 420.0f, -1200.0f);
    anctrl_reset(control);
    anctrl_setSmoothTransition(control, 0);
    anctrl_setIndex(control, 0xD7);
    anctrl_setSubrange(control, 0.0f, 0.3966f);
    anctrl_setDuration(control, 1.7f);
    anctrl_setPlaybackType(control, 1);
    anctrl_start(control);
    func_8009D820(arg0, 1.8f);
    arg0->unk15C.word = 0;
}

void func_808005E4_bsvan(struct player_state_s *arg0) {
    void bs_setState(struct player_state_s *, int);
    void _basudie_entrypoint_5(struct player_state_s *);
    void baanim_setEnd(struct player_state_s *, f32);
    void baphysics_set_target_horizontal_velocity(struct player_state_s *, f32);
    void baphysics_set_vertical_velocity(struct player_state_s *, f32);
    void func_8009DF18(struct player_state_s *, s32, f32, s32);
    f32 func_800F0E00(f32, f32);
    int player_isStable(struct player_state_s *);
    f32 velocity;

    _basudie_entrypoint_5(arg0);
    baphysics_set_target_horizontal_velocity(arg0, arg0->unk16C);
    switch (arg0->unk15C.word) {
        case 0:
            if (player_isStable(arg0)) {
                baanim_setEnd(arg0, 0.7453f);
                func_8009DF18(arg0, 0x417, 0.8f, 0x4650);
                func_8009DF18(arg0, 0x428, 1.8f, 0x4650);
                baphysics_set_vertical_velocity(arg0, 400.0f);
                arg0->unk15C.word = 1;
            }
            break;
        case 1:
            if (player_isStable(arg0)) {
                baanim_setEnd(arg0, 1.0f);
                func_8009DF18(arg0, 0x417, 0.8f, 0x4650);
                func_8009DF18(arg0, 0x428, 1.8f, 0x4650);
                arg0->unk15C.word = 2;
            }
            break;
        case 2:
            arg0->unk15C.word = 3;
            break;
        case 3:
            velocity = arg0->unk16C;
            if (velocity > 0.0f) {
                arg0->unk16C = func_800F0E00(0.0f, velocity - 10.0f);
            }
            break;
    }
    bsvan_entrypoint_3(arg0);
    bs_setState(arg0, 0);
}

s32 bsvan_entrypoint_4(s32 arg0) {
    extern BtIntPtr D_80801C8C_bsvan[];
    return ((s32 *)&D_80801C8C_bsvan)[arg0];
}

void func_80800760_bsvan(BtIntPtr arg0)
{
    _bsdrone_entrypoint_2();
    bsvan_entrypoint_0(arg0);
}
void func_80800788_bsvan(struct player_state_s *arg0)
{
    bsvan_entrypoint_1(arg0);
    _bsdrone_entrypoint_0(arg0);
}
void func_808007B0_bsvan(BtIntPtr arg0)
{
    _bsdrone_entrypoint_1();
    bsvan_entrypoint_3(arg0);
}
s32 bsvan_entrypoint_5(s32 arg0) {
    extern BtIntPtr D_80801C9C_bsvan[];
    return ((s32 *)&D_80801C9C_bsvan)[arg0];
}

/* extern */

void func_808007EC_bsvan(struct player_state_s *arg0) {
    void func_8009BF5C(struct player_state_s *, f32);
    void baroll_setIdeal(struct player_state_s *, f32);
    func_8009BF5C(arg0, 0.0f);
    baroll_setIdeal(arg0, 0.0f);
    bsvan_entrypoint_0(arg0);
}

struct anctrl_s;     
void func_80800824_bsvan(struct player_state_s *arg0) {
    void anctrl_reset(struct anctrl_s *);
    void anctrl_setIndex(struct anctrl_s *, enum asset_e);
    void anctrl_setStart(struct anctrl_s *, f32);
    void anctrl_setDuration(struct anctrl_s *, f32);
    void anctrl_setPlaybackType(struct anctrl_s *, s32);
    void anctrl_start(struct anctrl_s *);
    struct anctrl_s *baanim_getAnimCtrlPtr(struct player_state_s *);
    void func_8009FFD8();
    void yaw_setVelocityBounded(struct player_state_s *, f32, f32);
    struct anctrl_s *control;

    bsvan_entrypoint_1(arg0);
    control = baanim_getAnimCtrlPtr(arg0);
    anctrl_reset(control);
    anctrl_setIndex(control, 0xED);
    anctrl_setStart(control, 0.359f);
    anctrl_setDuration(control, 0.7f);
    anctrl_setPlaybackType(control, 3);
    anctrl_start(control);
    func_8009FFD8(arg0, 1, 3, 3, 6);
    yaw_setVelocityBounded(arg0, 300.0f, 6.5f);
    arg0->unk15C.word = 0;
}

void func_808008D4_bsvan(struct player_state_s *arg0) {
    s32 _badrone_entrypoint_28(struct player_state_s *);
    s32 anctrl_isStopped(struct anctrl_s *);
    struct anctrl_s *baanim_getAnimCtrlPtr(struct player_state_s *);
    void baanim_setEnd(struct player_state_s *, f32);
    void baanim_setEndAndDuration(struct player_state_s *, f32, f32);
    int baflag_isTrue(struct player_state_s *, s32);
    void baphysics_set_target_horizontal_velocity(struct player_state_s *, f32);
    s32 bastick_getZone(struct player_state_s *);
    void bs_setState(struct player_state_s *, int);
    int func_8008DF8C(struct player_state_s *, s32);
    void func_8009BB24(void *, f32 *);
    void func_8009D3A8(struct player_state_s *, s32);
    void func_800A2EAC(void *);
    s32 player_inWater(struct player_state_s *);
    int player_isStable(struct player_state_s *);
    s32 sp34;
    struct anctrl_s *sp30;
    f32 sp24[3];

    sp34 = 0;
    sp30 = baanim_getAnimCtrlPtr(arg0);
    func_8009D3A8(arg0, 0);
    func_80800000_bsvan(arg0);
    func_8009BB24(arg0, sp24);
    switch (arg0->unk15C.word) {
        case 0:
            if (func_8008DF8C(arg0, 0x82)) {
                baanim_setEnd(arg0, 0.6939f);
                arg0->unk15C.word = 1;
            }
            break;
        case 1:
            if (player_isStable(arg0)) {
                func_800A2EAC(arg0);
                baphysics_set_target_horizontal_velocity(arg0, 0.0f);
                baanim_setEndAndDuration(arg0, 1, 1.0f);
                arg0->unk15C.word = 2;
            }
            break;
        case 2:
            break;
    }
    if (player_isStable(arg0) &&
        (bastick_getZone(arg0) > 0 ||
         (arg0->unk15C.word == 2 && anctrl_isStopped(sp30)))) {
        if (baflag_isTrue(arg0, 0x19)) {
            sp34 = _badrone_entrypoint_28(arg0);
        } else {
            sp34 = 0x11A;
        }
    }
    if (player_inWater(arg0)) {
        sp34 = 0x11D;
    }
    func_808000BC_bsvan((u8 *)arg0);
    bsvan_entrypoint_3(arg0);
    bs_setState(arg0, sp34);
}

s32 bsvan_entrypoint_6(s32 arg0) {
    extern BtIntPtr D_80801CAC_bsvan[];
    return ((s32 *)&D_80801CAC_bsvan)[arg0];
}

void func_80800A5C_bsvan(struct player_state_s *arg0) {
    void anctrl_reset(struct anctrl_s *);
    void anctrl_setDuration(struct anctrl_s *, f32);
    void anctrl_setIndex(struct anctrl_s *, enum asset_e);
    void anctrl_setPlaybackType(struct anctrl_s *, s32);
    void anctrl_setSmoothTransition(struct anctrl_s *, s32);
    void anctrl_setStart(struct anctrl_s *, f32);
    void anctrl_setSubrange(struct anctrl_s *, f32, f32);
    void anctrl_start(struct anctrl_s *);
    struct anctrl_s *baanim_getAnimCtrlPtr(struct player_state_s *);
    f32 baphysics_get_target_horizontal_velocity(struct player_state_s *);
    void baphysics_set_gravity(struct player_state_s *, f32);
    void baphysics_set_horizontal_velocity(struct player_state_s *, f32, f32);
    void baphysics_set_target_yaw(struct player_state_s *, f32);
    void baphysics_set_vertical_velocity(struct player_state_s *, f32);
    f32 bastick_distance(struct player_state_s *);
    f32 bastick_getAngleRelativeToBanjo(struct player_state_s *);
    f32 yaw_getIdeal(struct player_state_s *);
    void yaw_setIdeal(struct player_state_s *, f32);
    void yaw_setVelocityBounded(struct player_state_s *, f32, f32);
    void func_8009FFD8();
    void func_8009D7A4(struct player_state_s *, f32, f32);
    void _bavan_entrypoint_7(struct player_state_s *, f32);
    s32 pad[2];
    f32 sp2C;
    struct anctrl_s *control;

    bsvan_entrypoint_1(arg0);
    control = baanim_getAnimCtrlPtr(arg0);
    anctrl_reset(control);
    anctrl_setSmoothTransition(control, 0);
    anctrl_setIndex(control, 0xED);
    anctrl_setSubrange(control, 0.0f, 0.359f);
    anctrl_setDuration(control, 1.0f);
    anctrl_setStart(control, 0.15f);
    anctrl_setPlaybackType(control, 1);
    anctrl_start(control);
    func_8009FFD8(arg0, 1, 3, 1, 6);
    yaw_setVelocityBounded(arg0, 300.0f, 6.5f);
    if (bastick_distance(arg0) != 0.0f) {
        yaw_setIdeal(arg0, bastick_getAngleRelativeToBanjo(arg0));
    }
    baphysics_set_target_yaw(arg0, yaw_getIdeal(arg0));
    func_80800000_bsvan(arg0);
    sp2C = yaw_getIdeal(arg0);
    baphysics_set_horizontal_velocity(arg0, sp2C, baphysics_get_target_horizontal_velocity(arg0));
    baphysics_set_vertical_velocity(arg0, 693.5f);
    baphysics_set_gravity(arg0, -1200.0f);
    func_8009D7A4(arg0, 1.35f, 1.45f);
    _bavan_entrypoint_7(arg0, 0.0f);
    arg0->unk15C.word = 0;
}

void func_80800BDC_bsvan(struct player_state_s *arg0) {
    struct anctrl_s *baanim_getAnimCtrlPtr(struct player_state_s *);
    s32 anctrl_isStopped(struct anctrl_s *);
    void baanim_setEndAndDuration(struct player_state_s *, f32, f32);
    int bakey_pressed(struct player_state_s *, int);
    int bakey_released(struct player_state_s *, int);
    int func_8008DF8C(struct player_state_s *, s32);
    void func_8009D2D8(struct player_state_s *, s32);
    void func_8009D3A8(struct player_state_s *, s32);
    int player_isStable(struct player_state_s *);
    void bs_setState(struct player_state_s *, int);
    void func_8009BB24(void *, f32 *);
    f32 func_8009BB5C(struct player_state_s *);
    void func_800A2EAC(void *);
    f32 baphysics_get_vertical_velocity(struct player_state_s *);
    s32 player_inWater(struct player_state_s *);
    s32 sp34;
    struct anctrl_s *sp30;
    f32 sp24[3];

    sp34 = 0;
    sp30 = baanim_getAnimCtrlPtr(arg0);
    func_8080032C_bsvan(arg0);
    func_80800000_bsvan(arg0);
    func_8009BB24(arg0, sp24);
    if (bakey_released(arg0, 8) && sp24[1] > 0.0f) {
        baphysics_reset_gravity(arg0);
    }
    switch (arg0->unk15C.word) {
    case 0:
        if (func_8008DF8C(arg0, 0x82)) {
            baanim_setEndAndDuration(arg0,
                1.0f + 0.0f,
                0.7f);
            arg0->unk15C.word = 2;
        } else if (anctrl_isStopped(sp30)) {
            baanim_setEndAndDuration(arg0, 0.69f, 3.0f);
            arg0->unk15C.word = 1;
        }
        break;
    case 1:
        if (func_8008DF8C(arg0, 0x82)) {
            baanim_setEndAndDuration(arg0,
                1.0f + 0.0f,
                1.0f);
            arg0->unk15C.word = 2;
        }
        break;
    case 2:
        func_8009D3A8(arg0, 0);
        if (player_isStable(arg0)) {
            func_800A2EAC(arg0);
            baanim_setEndAndDuration(arg0,
                1.0f + 0.0f,
                1.0f);
            arg0->unk15C.word = 3;
        }
        break;
    case 3:
        func_8009D2D8(arg0, 3);
        func_8009D3A8(arg0, 0);
        if (func_8009BB5C(arg0) > 0.0f) {
            sp34 = 0x116;
        } else if (anctrl_isStopped(sp30)) {
            sp34 = 0x11A;
        }
        if (bakey_pressed(arg0, 8)) {
            sp34 = 0x115;
        }
        break;
    }
    if (baphysics_get_vertical_velocity(arg0) < 0.0f && player_inWater(arg0)) {
        sp34 = 0x11D;
    }
    func_808000BC_bsvan((u8 *)arg0);
    bsvan_entrypoint_3(arg0);
    bs_setState(arg0, sp34);
}

void func_80800E0C_bsvan(struct player_state_s *arg0) {
    void func_8009BF5C(struct player_state_s *, f32);
    void baroll_setIdeal(struct player_state_s *, f32);
    baphysics_reset_gravity();
    func_8009BF5C(arg0, 0.0f);
    baroll_setIdeal(arg0, 0.0f);
    bsvan_entrypoint_0(arg0);
}

s32 bsvan_entrypoint_7(s32 arg0) {
    extern BtIntPtr D_80801CBC_bsvan[];
    return ((s32 *)&D_80801CBC_bsvan)[arg0];
} typedef struct { BtIntPtr unk0; } Objvan_func_80800E60_bsvan_temp_v1; /* offsets.py genstruct: fields from raw offsets on temp_v1; rename once understood */

/* extern */

void func_80800E60_bsvan(u8 *arg0, s32 (*arg1)(u8 *)) {
    s32 _chfaircoinbox_entrypoint_0(Unk80132ED0 *arg0, f32 *arg1);
    void bs_setState(struct player_state_s *, int);
    BtIntPtr func_80099A4C(u8 *);
    s32 func_8009E6EC();
    void func_8009E830(void *arg0, s32 arg1);
    s32 temp_v0;
    u8 *temp_v1;

    temp_v0 = func_8009E6EC(arg0);
    switch (temp_v0) {
    case 0x46:
        (*(s32 *)((s8 *)((((PlayerState *)arg0)->state_mem)) + (0))) = func_80099A4C(arg0);
        temp_v1 = (((PlayerState *)arg0)->state_mem);
        (*(s32 *)((s8 *)((((PlayerState *)arg0)->state_mem)) + (0x10))) = _chfaircoinbox_entrypoint_0((((Objvan_func_80800E60_bsvan_temp_v1 *)temp_v1)->unk0), temp_v1 + 4);
        func_8009E830(arg0, 2);
        bs_setState(arg0, 0x121);
        return;
    default:
        arg1(arg0);
        /* fallthrough */
    case 0x1F:
    case 0x20:
    case 0x21:
    case 0x2E:
    case 0x4E:
    case 0x51:
    case 0x52:
        return;
    }
}

void bsvan_entrypoint_8(s32 *arg0) {
    extern s32 func_80099B94;
    func_80800E60_bsvan(arg0, &func_80099B94);
}

void bsvan_entrypoint_9(s32 *arg0) {
    extern s32 _bsdrone_entrypoint_3;
    func_80800E60_bsvan(arg0, &_bsdrone_entrypoint_3);
}

void func_80800F50_bsvan(struct player_state_s *arg0)
{
    bsvan_entrypoint_0(arg0);
}

void func_80800F70_bsvan(struct player_state_s *arg0) {
    void baanim_playForDuration_loopSmooth(struct player_state_s *, s32, f32);
    void baanim_setDurationRange(struct player_state_s *, f32, f32);
    void baroll_setAngularVelocity(struct player_state_s *, f32, f32);
    void func_8008C9F0(struct player_state_s *, f32, f32, f32, f32);
    void func_8008CA30(struct player_state_s *, f32);
    void func_8009BFE4(struct player_state_s *, f32, f32);
    void func_8009FFD8();
    void yaw_setVelocityBounded(struct player_state_s *, f32, f32);

    bsvan_entrypoint_1(arg0);
    baanim_playForDuration_loopSmooth(arg0, 0xEC, 1.0f);
    func_8009FFD8(arg0, 2, 3, 1, 0xE);
    baanim_setDurationRange(arg0, 0.3f, 1.5f);
    func_8008C9F0(arg0, 30.0f, 900.0f, 1.0f, 0.4f);
    func_8008CA30(arg0, 1.0f);
    yaw_setVelocityBounded(arg0, 300.0f, 6.5f);
    func_8009BFE4(arg0, 1000.0f, 12.0f);
    baroll_setAngularVelocity(arg0, 1000.0f, 12.0f);
}

void func_80801034_bsvan(struct player_state_s *arg0) {
    s32 _badrone_entrypoint_25(struct player_state_s *);
    int bakey_pressed(struct player_state_s *, int);
    s32 bastick_getZone(struct player_state_s *);
    int func_8008DD04(struct player_state_s *);
    int func_8008E148(struct player_state_s *);
    void func_8009D3A8(struct player_state_s *, s32);
    s32 player_inWater(struct player_state_s *);
    void bs_setState(struct player_state_s *, int);
    s32 var_s1;

    var_s1 = 0;
    func_8009D3A8(arg0, 0);
    func_80800000_bsvan(arg0);
    func_8080032C_bsvan(arg0);
    if (bastick_getZone(arg0) == 0) {
        var_s1 = 0x11A;
    }
    if (func_8008E148(arg0) != 0) {
        var_s1 = _badrone_entrypoint_25(arg0);
    }
    if (func_8008DD04(arg0) != 0) {
        var_s1 = 0x114;
    }
    func_808000BC_bsvan((u8 *) arg0);
    if (bakey_pressed(arg0, 8) != 0) {
        var_s1 = 0x115;
    }
    if (player_inWater(arg0) != 0) {
        var_s1 = 0x11B;
    }
    bsvan_entrypoint_3(arg0);
    bs_setState(arg0, var_s1);
}

s32 bsvan_entrypoint_10(s32 arg0) {
    extern BtIntPtr D_80801CCC_bsvan[];
    return ((s32 *)&D_80801CCC_bsvan)[arg0];
}

void func_80801118_bsvan(BtIntPtr arg0)
{
    _babounce_entrypoint_3();
    bsvan_entrypoint_0(arg0);
}
/* extern */

struct anctrl_s;

void func_80801140_bsvan(struct player_state_s *arg0) {
    void _babounce_entrypoint_4(struct player_state_s *, s32);
    void _babounce_entrypoint_5(struct player_state_s *, s32, f32);
    struct anctrl_s *baanim_getAnimCtrlPtr(struct player_state_s *);
    void func_8008B10C(struct anctrl_s *, f32);
    bsvan_entrypoint_1(arg0);
    _babounce_entrypoint_4(arg0, 1);
    _babounce_entrypoint_5(arg0, 0xEF, 0.5128f);
    func_8008B10C(baanim_getAnimCtrlPtr(arg0), 0.1026f);
}

void func_80801198_bsvan(struct player_state_s *arg0) {
    void bs_setState(struct player_state_s *, int);
    int _babounce_entrypoint_2(struct player_state_s *);
    s32 _babounce_entrypoint_9(struct player_state_s *);
    int baanim_isAt(struct player_state_s *, f32);
    void func_800951B4(struct player_state_s *);
    s32 sp24;

    sp24 = 0;
    if (baanim_isAt(arg0, 0.5f) != 0) {
        func_800951B4(arg0);
    }
    if (_babounce_entrypoint_2(arg0) != 0) {
        func_80800000_bsvan(arg0);
    }
    if (_babounce_entrypoint_9(arg0) != 0) {
        sp24 = 0x11A;
    }
    bs_setState(arg0, sp24);
}

s32 bsvan_entrypoint_11(s32 arg0) {
    extern BtIntPtr D_80801CDC_bsvan[];
    return ((s32 *)&D_80801CDC_bsvan)[arg0];
}

void func_80801224_bsvan(BtIntPtr arg0)
{
    _babounce_entrypoint_3();
    bsvan_entrypoint_0(arg0);
}
void func_8080124C_bsvan(struct player_state_s *arg0) {
    void _babounce_entrypoint_4(struct player_state_s *, s32);
    void _babounce_entrypoint_5(struct player_state_s *, s32, f32);
    struct anctrl_s *baanim_getAnimCtrlPtr(struct player_state_s *);
    void func_8008B10C(struct anctrl_s *, f32);
    bsvan_entrypoint_1(arg0);
    _babounce_entrypoint_4(arg0, 2);
    _babounce_entrypoint_5(arg0, 0xEF, 0.5128f);
    func_8008B10C(baanim_getAnimCtrlPtr(arg0), 0.1026f);
}

/* extern */

void func_808012A4_bsvan(BtIntPtr arg0) {
    void bs_setState(struct player_state_s *, int);
    int _babounce_entrypoint_2();
    s32 _babounce_entrypoint_9(struct player_state_s *);
    void func_80800000_bsvan(struct player_state_s *);
    s32 sp1C;

    sp1C = 0;
    if (_babounce_entrypoint_2() != 0) {
        func_80800000_bsvan(arg0);
    }
    if (_babounce_entrypoint_9(arg0) != 0) {
        sp1C = 0x11A;
    }
    bs_setState(arg0, sp1C);
}

s32 bsvan_entrypoint_12(s32 arg0) {
    extern BtIntPtr D_80801CEC_bsvan[];
    return ((s32 *)&D_80801CEC_bsvan)[arg0];
}

void func_8080130C_bsvan(BtIntPtr arg0)
{
    _bsrest_entrypoint_14();
    bsvan_entrypoint_0(arg0);
}
void func_80801334_bsvan(struct player_state_s *arg0)
{
    bsvan_entrypoint_1(arg0);
    _bsrest_entrypoint_16(arg0);
}
void func_8080135C_bsvan(u8 *arg0) {
    void bs_setState(struct player_state_s *, int);
    s32 _bsrest_entrypoint_13(BtIntPtr);
    s32 _bsrest_entrypoint_20();
    s32 sp1C;

    sp1C = 0;
    if (_bsrest_entrypoint_20() != 0) {
        sp1C = _bsrest_entrypoint_13(arg0);
    }
    bsvan_entrypoint_3(arg0);
    bs_setState(arg0, sp1C);
}

s32 bsvan_entrypoint_13(s32 arg0) {
    extern BtIntPtr D_80801CFC_bsvan[];
    return ((s32 *)&D_80801CFC_bsvan)[arg0];
}

void func_808013BC_bsvan(struct player_state_s *arg0)
{
    bsvan_entrypoint_0(arg0);
    func_80090A2C(arg0);
}
void func_808013E4_bsvan(struct player_state_s *arg0) {
    void func_8009FFD8();
    void yaw_setVelocityBounded(struct player_state_s *, f32, f32);
    void baanim_playForDuration_loopSmooth(struct player_state_s *, s32, f32);
    void baphysics_set_target_horizontal_velocity(struct player_state_s *, f32);
    void func_800909CC(struct player_state_s *);

    bsvan_entrypoint_1(arg0);
    baanim_playForDuration_loopSmooth(arg0, 0xEE, 1.0f);
    func_8009FFD8(arg0, 1, 3, 1, 2);
    yaw_setVelocityBounded(arg0, 300.0f, 6.5f);
    baphysics_set_target_horizontal_velocity(arg0, 0.0f);
    func_800909CC(arg0);
}

void func_8080145C_bsvan(struct player_state_s *arg0) {
    s32 _badrone_entrypoint_25(struct player_state_s *);
    int baanim_isAt(struct player_state_s *, f32);
    s32 bastick_getZone(struct player_state_s *);
    void bs_setState(struct player_state_s *, int);
    int func_8008E148(struct player_state_s *);
    void func_80092C90(void *, f32[3], s32);
    void func_8009C128(struct player_state_s *, f32[3]);
    void func_8009D3A8(struct player_state_s *, s32);
    BtIntPtr func_800B5BE4(s32);
    void func_800BA77C(BtIntPtr, s16, s16, s16);
    void func_800BA994(u8 *, s16, s16, s16, s16, s16, s16);
    BtIntPtr func_800BABB8(BtIntPtr, f32[3], f32[3], f32, s32[]);
    f32 func_800DC178(f32, f32);
    void func_800EFB24(void *, void *, void *);
    void func_800F1A88(f32 *, f32 *);
    s32 player_inWater(struct player_state_s *);
    extern s32 D_80801D0C_bsvan[];
    s32 sp6C;
    f32 sp64[2];
    f32 sp58[3];
    f32 sp4C[3];
    f32 sp40[3];
    BtIntPtr sp3C;

    sp6C = 0;
    func_8009D3A8(arg0, 0);
    if (baanim_isAt(arg0, 0.0122f) || baanim_isAt(arg0, 0.5122f)) {
        sp3C = func_800B5BE4(8);
        func_8009C128(arg0, sp58);
        func_80092C90(arg0, sp40, 4);
        func_800EFB24(sp4C, sp40, sp58);
        func_800F1A88(sp4C, sp64);
        sp64[0] = -sp64[0] - 10;
        func_800BA994(sp3C, (s16)sp64[0], (s16)(sp64[1] - 10.0f), 150,
                     (s16)sp64[0], (s32)(sp64[1] + 10.0f), 200);
        func_800BA77C(sp3C, 0, 0, (s16)func_800DC178(0.0f, 359.0f));
        func_800BABB8(sp3C, sp40, NULL, 1.0f, D_80801D0C_bsvan);
    }
    func_808000BC_bsvan(arg0);
    if (bastick_getZone(arg0) > 0) {
        sp6C = 0x116;
    }
    if (func_8008E148(arg0)) {
        sp6C = _badrone_entrypoint_25(arg0);
    }
    if (player_inWater(arg0)) {
        sp6C = 0x11D;
    }
    sp6C = func_800A02DC(arg0, func_80800064_bsvan(arg0, sp6C));
    bsvan_entrypoint_3(arg0);
    bs_setState(arg0, sp6C);
}

s32 bsvan_entrypoint_14(s32 arg0) {
    extern BtIntPtr D_80801D70_bsvan[];
    return ((s32 *)&D_80801D70_bsvan)[arg0];
}

s32 func_8080164C_bsvan(void *arg0, s32 arg1) {
    void _batimer_set(struct player_state_s *, s32, f32);
    void baanim_playForDuration_onceSmooth(struct player_state_s *, s32, f32);
    void func_8009C128(struct player_state_s *, f32[3]);
    f32 func_800F1DF4(f32 *, f32 *);
    void yaw_setIdeal(struct player_state_s *, f32);
    f32 sp24[3];

    func_8009C128(arg0, sp24);
    switch (arg1) {
    case 1:
        yaw_setIdeal(arg0, func_800F1DF4(sp24, *(f32 **)((s8 *)arg0 + 0x188) + 1) + 180.0f);
        break;
    case 2:
        baanim_playForDuration_onceSmooth(arg0, 0xF1, 1.2f);
        break;
    case 3:
        if (((PlayerState *)arg0)->unk15C.word == 2) {
            _batimer_set(arg0, 3, 0.001f);
        } else {
            _batimer_set(arg0, 3, 0.5f);
        }
        break;
    case 4:
        baanim_playForDuration_onceSmooth(arg0, 0xF2, 1.3f);
        break;
    case 5:
        yaw_setIdeal(arg0, func_800F1DF4(sp24, *(f32 **)((s8 *)arg0 + 0x188) + 1));
        break;
    }
    ((PlayerState *)arg0)->unk15C.word = arg1; BT_NATIVE_ONLY(return 0;)
}

void func_80801770_bsvan(void *arg0) { void _chfaircoinbox_entrypoint_1(Unk80132ED0 *arg0); _chfaircoinbox_entrypoint_1(*(*(s32 **)((s8 *)(arg0) + 0x188))); bsvan_entrypoint_0(arg0); }

void func_808017A0_bsvan(register void *arg0) {
    void func_8009FFD8();
    void yaw_setVelocityBounded(struct player_state_s *, f32, f32);
    void baanim_playForDuration_loopSmooth(struct player_state_s *, s32, f32);
    s32 func_8080164C_bsvan(void *, s32);
    bsvan_entrypoint_1(arg0);
    baanim_playForDuration_loopSmooth(arg0, 0xEE, 1.0f);
    func_8009FFD8(arg0, 1, 3, 3, 2);
    yaw_setVelocityBounded(arg0, 300.0f, 6.5f);
    ((PlayerState *)arg0)->unk15C.word = 0;
    func_8080164C_bsvan(arg0, 1);
}

/* extern */

void bsvan_entrypoint_15(s32 arg0) {
    u8 *_chfaircoin_entrypoint_0(BtIntPtr arg0, BtIntPtr arg1, f32 arg2);
    void func_8009C128(struct player_state_s *, f32[3]);
    void func_800EE7F8(f32 *, f32 *);
    struct player_state_s *func_800F53D0(BtIntPtr);
    struct player_state_s *sp34;
    f32 sp28[3];
    f32 sp1C[3];

    sp34 = func_800F53D0(arg0);
    func_8009C128(sp34, sp28);
    func_800EE7F8(sp1C, *(f32 **)((s8 *)sp34 + 0x188) + 1);
    sp28[1] += 20.0f;
    sp1C[1] += 40.0f;
    _chfaircoin_entrypoint_0(sp28, sp1C, 0.5f);
}

void func_80801890_bsvan(struct player_state_s *arg0) {
    s32 _batimer_decrement(void *, s32);
    void _chbaddiesetup_entrypoint_1(s32 *, BtIntPtr);
    int baanim_isAt(struct player_state_s *, f32);
    int baanim_isStopped(struct player_state_s *);
    void bs_setState(struct player_state_s *, int);
    s32 func_8008E124(struct player_state_s *);
    void func_8009D3A8(struct player_state_s *, s32);
    void func_8009DF18(struct player_state_s *, s32, f32, s32);
    s32 func_8080164C_bsvan(void *, s32);
    f32 yaw_get(struct player_state_s *);
    f32 yaw_getIdeal(struct player_state_s *);
#ifndef BT_NATIVE
    extern s32 _bsvan_entrypoint_15;
#endif
    s32 sp24;
    f32 sp20;
    s32 *temp_v0;

    sp24 = 0;
    func_8009D3A8(arg0, 0);
    switch (arg0->unk15C.word) {
    case 1:
        sp20 = yaw_get(arg0);
        if (yaw_getIdeal(arg0) == sp20) {
            func_8080164C_bsvan(arg0, 2);
        }
        break;
    case 2:
        if (baanim_isAt(arg0, 0.08f)) {
            func_8009DF18(arg0, 0x56D, 1.0f, 0x55F0);
        }
        if (baanim_isAt(arg0, 0.5049f)) {
            func_8080164C_bsvan(arg0, 3);
        }
        break;
    case 3:
        if (_batimer_decrement(arg0, 3)) {
            _chbaddiesetup_entrypoint_1(&_bsvan_entrypoint_15, arg0->unk184);
            temp_v0 = *(s32 **)((s8 *)arg0 + 0x188);
            temp_v0[4]--;
            if ((*(s32 **)((s8 *)arg0 + 0x188))[4]) {
                func_8080164C_bsvan(arg0, 3);
            } else {
                func_8080164C_bsvan(arg0, 4);
            }
        }
        break;
    case 4:
        if (baanim_isStopped(arg0)) {
            func_8080164C_bsvan(arg0, 5);
        }
        break;
    case 5:
        sp20 = yaw_get(arg0);
        if (yaw_getIdeal(arg0) == sp20) {
            if (func_8008E124(arg0)) {
                sp24 = 0x119;
            } else {
                sp24 = 0x11A;
            }
        }
        break;
    }
    bsvan_entrypoint_3(arg0);
    bs_setState(arg0, sp24);
}

s32 bsvan_entrypoint_16(s32 arg0) {
    extern BtIntPtr D_80801D80_bsvan[];
    return ((s32 *)&D_80801D80_bsvan)[arg0];
}
/* data_to_c.py: from asm/data/overlays/bs/van.data.s */
void _basudie_entrypoint_11();
void _bsvan_entrypoint_9();
void _bsvan_entrypoint_8();
void func_80099AA8();
s32 D_80801B90_bsvan[44] BT_DATA(4, overlays_bs_van, 0x0) = { 1903068, 2949080, 3342296, 2621540, 2621461, 1310822, 2158832, -263192542, 25166233, 41943808, 1445888, 1572864, 196608, 43, 25166233, 2162688, 0, 720816, 3932160, -5242820, 282, 2818457, 28508193, 0, 5898250, 5242940, 80, 3932160, 18481195, 28508620, 2162688, 180, 655360, 3997616, 60, -5242598, 2818508, 31850529, 0, 17694730, 60, 5242880, 3932240, 18481152 };
s32 D_80801C40_bsvan[19] BT_DATA(4, overlays_bs_van, 0xB0) = { 1903068, 655360, 0, 0, 44, -1310470, -1310700, 22937620, 1376276, 6684704, -252645296, 2228275, 6684876, 20119574, 268435480, 6, 0, 2818201, 11730944 };
BtIntPtr D_80801C8C_bsvan [4] BT_DATA(4, overlays_bs_van, 0xFC) = { (BtIntPtr)func_808004F8_bsvan, (BtIntPtr)func_80800520_bsvan, (BtIntPtr)func_808005E4_bsvan, (BtIntPtr)_basudie_entrypoint_11 };
BtIntPtr D_80801C9C_bsvan [4] BT_DATA(4, overlays_bs_van, 0x10C) = { (BtIntPtr)func_80800760_bsvan, (BtIntPtr)func_80800788_bsvan, (BtIntPtr)func_808007B0_bsvan, (BtIntPtr)_bsvan_entrypoint_9 };
BtIntPtr D_80801CAC_bsvan [4] BT_DATA(4, overlays_bs_van, 0x11C) = { (BtIntPtr)func_808007EC_bsvan, (BtIntPtr)func_80800824_bsvan, (BtIntPtr)func_808008D4_bsvan, (BtIntPtr)_bsvan_entrypoint_8 };
BtIntPtr D_80801CBC_bsvan [4] BT_DATA(4, overlays_bs_van, 0x12C) = { (BtIntPtr)func_80800E0C_bsvan, (BtIntPtr)func_80800A5C_bsvan, (BtIntPtr)func_80800BDC_bsvan, (BtIntPtr)_bsvan_entrypoint_8 };
BtIntPtr D_80801CCC_bsvan [4] BT_DATA(4, overlays_bs_van, 0x13C) = { (BtIntPtr)func_80800F50_bsvan, (BtIntPtr)func_80800F70_bsvan, (BtIntPtr)func_80801034_bsvan, (BtIntPtr)_bsvan_entrypoint_8 };
BtIntPtr D_80801CDC_bsvan [4] BT_DATA(4, overlays_bs_van, 0x14C) = { (BtIntPtr)func_80801118_bsvan, (BtIntPtr)func_80801140_bsvan, (BtIntPtr)func_80801198_bsvan, (BtIntPtr)func_80099AA8 };
BtIntPtr D_80801CEC_bsvan [4] BT_DATA(4, overlays_bs_van, 0x15C) = { (BtIntPtr)func_80801224_bsvan, (BtIntPtr)func_8080124C_bsvan, (BtIntPtr)func_808012A4_bsvan, (BtIntPtr)func_80099AA8 };
BtIntPtr D_80801CFC_bsvan [4] BT_DATA(4, overlays_bs_van, 0x16C) = { (BtIntPtr)func_8080130C_bsvan, (BtIntPtr)func_80801334_bsvan, (BtIntPtr)func_8080135C_bsvan, (BtIntPtr)_bsvan_entrypoint_8 };
s32 D_80801D0C_bsvan [25] BT_DATA(4, overlays_bs_van, 0x17C) = { 1903068, 1376276, 6684694, 268435466, 0, 0, 0, 2228249, 3342515, 13369376, -926351536, 1572864, 131072, 43, 13369574, 18481186, 3342412, 20119884, 2158832, -263192552, 196614, 0, 2818329, 20119834, 0 };
BtIntPtr D_80801D70_bsvan [4] BT_DATA(4, overlays_bs_van, 0x1E0) = { (BtIntPtr)func_808013BC_bsvan, (BtIntPtr)func_808013E4_bsvan, (BtIntPtr)func_8080145C_bsvan, (BtIntPtr)_bsvan_entrypoint_8 };
BtIntPtr D_80801D80_bsvan [4] BT_DATA(4, overlays_bs_van, 0x1F0) = { (BtIntPtr)func_80801770_bsvan, (BtIntPtr)func_808017A0_bsvan, (BtIntPtr)func_80801890_bsvan, (BtIntPtr)_bsvan_entrypoint_8 };
