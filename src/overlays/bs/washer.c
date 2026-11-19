#include "common.h"
#ifdef BT_NATIVE
#include "overlays/ba/anim_smooth.h"
#endif
#ifdef BT_NATIVE // complete the enum forward declarations below
#include "overlays/ba/assets.h"
#endif
#include "bs_script.h"
struct player_state_s; 
s32 func_8009D454(struct player_state_s *, volatile u8, s32 *);

void _basudie_entrypoint_11();
void _bsdrone_entrypoint_3();
void func_80099AA8();
void func_80800590_bswasher(BtIntPtr arg0);
void func_808005B8_bswasher(struct player_state_s *arg0);
void func_80800608_bswasher(struct player_state_s *arg0);
void func_80800714_bswasher(BtIntPtr arg0);
void func_80800770_bswasher(struct player_state_s *arg0);
void func_808007DC_bswasher(struct player_state_s *arg0);
void func_808008BC_bswasher(BtIntPtr arg0);
void func_808008F4_bswasher(struct player_state_s *arg0);
void func_8080099C_bswasher(struct player_state_s *arg0);
void func_80800B08_bswasher(struct player_state_s *arg0);
void func_80800C70_bswasher(struct player_state_s *arg0);
void func_80800E74_bswasher(BtIntPtr arg0);
void func_80800EC8_bswasher(u8 *arg0);
void func_8080100C_bswasher(BtIntPtr arg0);
void func_80801034_bswasher(struct player_state_s *arg0);
void func_808010DC_bswasher(struct player_state_s *arg0);
void func_808011B4_bswasher(BtIntPtr arg0);
void func_808011DC_bswasher(BtIntPtr arg0);
void func_80801218_bswasher(struct player_state_s *arg0);
void func_80801294_bswasher(BtIntPtr arg0);
void func_808012BC_bswasher(struct player_state_s *arg0);
void func_80801314_bswasher(BtIntPtr arg0);
void func_8080137C_bswasher(BtIntPtr arg0);
void func_808013A4_bswasher(BtIntPtr arg0);
void func_808013CC_bswasher(BtIntPtr arg0);
void func_8080142C_bswasher(BtIntPtr arg0);
void func_80801454_bswasher(BtIntPtr arg0);
void func_808014C8_bswasher(struct player_state_s *arg0);
void func_80801744_bswasher(BtIntPtr arg0);
void func_80801770_bswasher(BtIntPtr arg0);
void func_808017A0_bswasher(u8 *arg0);
void func_80801B10_bswasher(struct player_state_s *arg0);
void func_80801B30_bswasher(struct player_state_s *arg0);
void func_80801BA4_bswasher(struct player_state_s *arg0);

s32 D_80801D60_bswasher[] = {
    0x001D09DC, 0x002CFFD8, 0x0032FFD8, 0x00280064,
    0x00280015, 0x00140066, 0x0020F0F0, 0xF0500022,
    0x01800199, 0x02000280, 0x00161000, 0x00180000,
    0x00030000, 0x0000002B, 0x01800199, 0x00210000,
    0x00000000, 0x000AFFB0, 0x003C0000, 0xFFB0003C,
    0x0000011A, 0x002B0199, 0x01B30021, 0x00000000,
    0x005A000A, 0x0050003C, 0x00000050, 0x003C0000,
    0x011A002B, 0x01B301CC, 0x00210000, 0x000000B4,
    0x000A0000, 0x003CFFB0, 0x0000003C, 0xFFB0011A,
    0x002B01CC, 0x01E60021, 0x00000000, 0x010E000A,
    0x0000003C, 0x00500000, 0x003C0050, 0x011A0000,
};

BtFnWord D_80801E10_bswasher[] = {
    (BtFnWord)func_80800590_bswasher, (BtFnWord)func_808005B8_bswasher, (BtFnWord)func_80800608_bswasher, (BtFnWord)_basudie_entrypoint_11,
};

BtFnWord D_80801E20_bswasher[] = {
    (BtFnWord)func_80800714_bswasher, (BtFnWord)func_80800770_bswasher, (BtFnWord)func_808007DC_bswasher, (BtFnWord)_bsdrone_entrypoint_3,
};

BtFnWord D_80801E30_bswasher[] = {
    (BtFnWord)func_808008BC_bswasher, (BtFnWord)func_808008F4_bswasher, (BtFnWord)func_8080099C_bswasher, (BtFnWord)func_80800EC8_bswasher,
};

BtFnWord D_80801E40_bswasher[] = {
    (BtFnWord)func_80800E74_bswasher, (BtFnWord)func_80800B08_bswasher, (BtFnWord)func_80800C70_bswasher, (BtFnWord)func_80800EC8_bswasher,
};

s32 D_80801E50_bswasher[] = {
    0x03060016, 0x2EE00013, 0x05E80011, 0x00000000,
};

BtFnWord D_80801E60_bswasher[] = {
    (BtFnWord)func_8080100C_bswasher, (BtFnWord)func_80801034_bswasher, (BtFnWord)func_808010DC_bswasher, (BtFnWord)func_80800EC8_bswasher,
};

BtFnWord D_80801E70_bswasher[] = {
    (BtFnWord)func_808011B4_bswasher, (BtFnWord)func_808011DC_bswasher, (BtFnWord)func_80801218_bswasher, (BtFnWord)func_80099AA8,
};

BtFnWord D_80801E80_bswasher[] = {
    (BtFnWord)func_80801294_bswasher, (BtFnWord)func_808012BC_bswasher, (BtFnWord)func_80801314_bswasher, (BtFnWord)func_80800EC8_bswasher,
};

BtFnWord D_80801E90_bswasher[] = {
    (BtFnWord)func_8080137C_bswasher, (BtFnWord)func_808013A4_bswasher, (BtFnWord)func_808013CC_bswasher, (BtFnWord)func_80800EC8_bswasher,
};

BtFnWord D_80801EA0_bswasher[] = {
    (BtFnWord)func_8080142C_bswasher, (BtFnWord)func_80801454_bswasher, (BtFnWord)func_808014C8_bswasher, (BtFnWord)func_80800EC8_bswasher,
};

s32 D_80801EB0_bswasher[] = {
    0x03060016, 0x6D60000A, 0x00CC0013, 0x05E60011,
    0x00000000,
};

BtFnWord D_80801EC4_bswasher[] = {
    (BtFnWord)func_80801744_bswasher, (BtFnWord)func_80801770_bswasher, (BtFnWord)func_808017A0_bswasher, (BtFnWord)func_80800EC8_bswasher,
};

BtFnWord D_80801ED4_bswasher[] = {
    (BtFnWord)func_80801B10_bswasher, (BtFnWord)func_80801B30_bswasher, (BtFnWord)func_80801BA4_bswasher, (BtFnWord)func_80800EC8_bswasher,
    0x00000000, 0x00000000, 0x00000000,
};

void func_80800000_bswasher(struct player_state_s *arg0) {
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

s32 func_80800064_bswasher(BtIntPtr arg0, s32 arg1) {
    s32 _badrone_entrypoint_24(BtIntPtr);
    s32 bainput_should_enter_first_person();
    int bakey_pressed(struct player_state_s *, int);
    if (bainput_should_enter_first_person() != 0) {
        arg1 = _badrone_entrypoint_24(arg0);
    }
    if (bakey_pressed(arg0, 8) != 0) {
        arg1 = 0x35;
    }
    return arg1;
}

/* extern */

void func_808000BC_bswasher(BtIntPtr arg0) {
    s32 yaw_setUpdateType(BtIntPtr, s32);
    s32 yaw_setVelocityBounded(BtIntPtr, s32, s32);
    yaw_setUpdateType(arg0, 3);
    yaw_setVelocityBounded(arg0, 0x43960000, 0x40C00000);
}

void func_800947EC(struct player_state_s *, s32, s32);

void func_808000F0_bswasher(struct player_state_s *arg0) {
    void _bawasher_entrypoint_1(struct player_state_s *);
    void baflag_clear(struct player_state_s *, s32);
    void baroll_resetAngularVelocity(struct player_state_s *);
    void baroll_setIdeal(struct player_state_s *, f32);
    void bastick_popZone(struct player_state_s *);
    void func_80092864(struct player_state_s *, f32);
    void func_80095964(void *, s32);
    void func_80095A40(struct player_state_s *);
    void func_8009BF5C(struct player_state_s *, f32);
    void func_8009C000(struct player_state_s *);
    void func_8009E474(struct player_state_s *);
    s32 func_8009E74C(struct player_state_s *, s32);

    if (func_8009E74C(arg0, 0x15) == 0) {
        func_800947EC(arg0, 1, 0);
        func_8009BF5C(arg0, 0.0f);
        baroll_setIdeal(arg0, 0.0f);
        func_8009C000(arg0);
        baroll_resetAngularVelocity(arg0);
        bastick_popZone(arg0);
        func_80095A40(arg0);
        func_80095964(arg0, 0);
        func_8009E474(arg0);
        baflag_clear(arg0, 3);
        baflag_clear(arg0, 4);
        _bawasher_entrypoint_1(arg0);
        func_80092864(arg0, 1.0f);
    }
}

void func_808001A8_bswasher(struct player_state_s *arg0) {
    void _bawasher_entrypoint_2(struct player_state_s *);
    void baflag_set(struct player_state_s *, s32);
    void baroll_setAngularVelocity(struct player_state_s *, f32, f32);
    void bastick_pushZone(struct player_state_s *);
    void bastick_setZoneMax(struct player_state_s *, s32, f32);
    void func_80092864(struct player_state_s *, f32);
    void func_800947EC(struct player_state_s *, s32, s32);
    void func_80095964(void *, s32);
    void func_800959C8(struct player_state_s *, f32, f32);
    void func_8009BFE4(struct player_state_s *, f32, f32);
    void func_8009E4AC(struct player_state_s *);
    void func_8009E55C(struct player_state_s *, s32, f32);
    s32 func_8009E77C(struct player_state_s *, s32);
    if (func_8009E77C(arg0, 0x15) == 0) {
        _bawasher_entrypoint_2(arg0);
        func_8009BFE4(arg0, 1000.0f, 12.0f);
        baroll_setAngularVelocity(arg0, 1000.0f, 12.0f);
        bastick_pushZone(arg0);
        bastick_setZoneMax(arg0, 0, 0.12f);
        bastick_setZoneMax(arg0, 1, 1.0f);
        func_800959C8(arg0, 100.0f, 52.0f);
        func_80095964(arg0, 1);
        func_8009E4AC(arg0);
        func_8009E55C(arg0, 0, 70.0f);
        func_8009E55C(arg0, 1, 78.0f);
        baflag_set(arg0, 3);
        baflag_set(arg0, 4);
        func_800947EC(arg0, 1, 1);
        func_80092864(arg0, 1.79998779296875f);
    }
}

void bswasher_entrypoint_0(BtIntPtr arg0) {
    BtIntPtr func_800B5BE4(s32);
    BtIntPtr func_800BABB8(BtIntPtr, f32[3], f32[3], f32, s32[]);
    void func_8009C128(struct player_state_s *, f32[3]);

    f32 sp24[3];
    BtIntPtr sp20;

    sp20 = func_800B5BE4(8);
    func_8009C128(arg0, sp24);
    func_800BABB8(sp20, sp24, NULL, 1.0f, D_80801D60_bswasher);
}

s32 func_80800300_bswasher(BtIntPtr arg0) {
    void _bawasher_entrypoint_4(struct player_state_s *, f32);
    void _bawasher_entrypoint_5(struct player_state_s *, f32);
    void _bawasher_entrypoint_9(struct player_state_s *);
    f32 func_8009BB5C(struct player_state_s *);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    f32 func_800F13F0(f32, f32);
    f32 func_800F1DCC(f32, f32);
    int player_isStable(struct player_state_s *);
    f32 yaw_get(struct player_state_s *);
    f32 yaw_getIdeal(struct player_state_s *);
    f32 rate2;
    f32 speed;
    f32 speed2;
    f32 rate;
    f32 angle;

    angle = yaw_getIdeal(arg0);
    _bawasher_entrypoint_4(arg0, func_800F1DCC(angle, yaw_get(arg0)));
    speed = func_8009BB5C(arg0);
    if (speed > 1.0f) {
        speed = func_800F10B4(speed, 30.0f, 900.0f, 45.0f, 1350.0f);
    } else {
        speed = 0.0f;
    }
    _bawasher_entrypoint_5(arg0, speed);
    speed2 = func_8009BB5C(arg0);
    if (speed2 > 0.0f) {
        rate2 = func_800F10B4(speed2, 30.0f, 900.0f, 0.8f, 1.25f);
    } else {
        rate2 = 0.8f;
    }
    if (!player_isStable(arg0)) {
        func_800F13F0(1.9f, rate2 + 0.3f);
    }
    _bawasher_entrypoint_9(arg0);
BT_NATIVE_ONLY(return 0;) }

struct anctrl_s;
enum asset_e;
s32 func_8080042C_bswasher(struct player_state_s *arg0, s32 arg1) {
    void anctrl_reset(struct anctrl_s *);
    void anctrl_setDuration(struct anctrl_s *, f32);
    void anctrl_setIndex(struct anctrl_s *, enum asset_e);
    void anctrl_setPlaybackType(struct anctrl_s *, s32);
    void anctrl_setSmoothTransition(struct anctrl_s *, s32);
    void anctrl_setSubrange(struct anctrl_s *, f32, f32);
    void anctrl_start(struct anctrl_s *);
    struct anctrl_s *baanim_getAnimCtrlPtr(struct player_state_s *);
    void baanim_setEnd(struct player_state_s *, f32);
    void baphysics_set_vertical_velocity(struct player_state_s *, f32);
    void func_8009D820(struct player_state_s *, f32);
    void func_8009DF18(struct player_state_s *, s32, f32, s32);
    void func_8009DF94(struct player_state_s *, s32, f32, s32);
    struct anctrl_s *control;

    switch (arg1) {
        case 1:
            control = baanim_getAnimCtrlPtr(arg0);
            anctrl_reset(control);
            anctrl_setSmoothTransition(control, 0);
            anctrl_setIndex(control, 0x32);
            anctrl_setSubrange(control, 0.0f, 0.2541f);
            anctrl_setDuration(control, 2.5f);
            anctrl_setPlaybackType(control, 1);
            anctrl_start(control);
            func_8009D820(arg0, 1.8f);
            break;
        case 2:
            baanim_setEnd(arg0, 0.5741f);
            func_8009DF94(arg0, 0x417, 0.8f, 0x4650);
            func_8009DF18(arg0, 0x428, 1.8f, 0x4650);
            baphysics_set_vertical_velocity(arg0, 400.0f);
            break;
        case 3:
            baanim_setEnd(arg0, 1.0f);
            func_8009DF94(arg0, 0x417, 0.8f, 0x4650);
            func_8009DF18(arg0, 0x428, 1.8f, 0x4650);
            break;
        case 4:
            break;
    }
    *(s32 *)((s8 *)arg0 + 0x15C) = arg1;
BT_NATIVE_ONLY(return 0;) }

void func_80800590_bswasher(BtIntPtr arg0)
{
    _basudie_entrypoint_6();
    func_808000F0_bswasher(arg0);
}

void func_808005B8_bswasher(struct player_state_s *arg0) {
    void _basudie_entrypoint_2(BtIntPtr arg0, f32 arg1, f32 arg2, f32 arg3);
    s32 func_8080042C_bswasher(struct player_state_s *, s32);

    func_808001A8_bswasher(arg0);
    _basudie_entrypoint_2(arg0, *(f32 *)((s8 *)arg0 + 0x16C), 420.0f, -1200.0f);
    *(s32 *)((s8 *)arg0 + 0x15C) = 0;
    *(f32 *)((s8 *)arg0 + 0x16C) = 250.0f;
    func_8080042C_bswasher(arg0, 1);
}

void func_80800608_bswasher(struct player_state_s *arg0) {
    void _basudie_entrypoint_5(struct player_state_s *);
    void baphysics_set_target_horizontal_velocity(struct player_state_s *, f32);
    int player_isStable(struct player_state_s *);
    f32 func_800F0E00(f32, f32);
    void bs_setState(struct player_state_s *, int);
    f32 velocity;

    _basudie_entrypoint_5(arg0);
    baphysics_set_target_horizontal_velocity(arg0, *(f32 *)((s8 *)arg0 + 0x16C));
    switch (*(s32 *)((s8 *)arg0 + 0x15C)) {
        case 1:
            if (player_isStable(arg0)) {
                func_8080042C_bswasher(arg0, 2);
            }
            break;
        case 2:
            if (player_isStable(arg0)) {
                func_8080042C_bswasher(arg0, 3);
            }
            break;
        case 3:
            func_8080042C_bswasher(arg0, 4);
            break;
        case 4:
            velocity = *(f32 *)((s8 *)arg0 + 0x16C);
            if (velocity > 0.0f) {
                *(f32 *)((s8 *)arg0 + 0x16C) = func_800F0E00(0.0f, velocity - 10.0f);
            }
            break;
    }
    func_80800300_bswasher((BtIntPtr)arg0);
    bs_setState(arg0, 0);
}

BsScript bswasher_entrypoint_1(BsScriptType arg0) {

    return (BsScript)D_80801E10_bswasher[arg0];
}

void func_80800714_bswasher(BtIntPtr arg0) { if (_badrone_entrypoint_3(arg0) == 2) { _bafpctrl_entrypoint_10(arg0, 0); func_800947EC(arg0, 2, 0); } func_808000F0_bswasher(arg0); _bsdrone_entrypoint_2(arg0); }

void func_80800770_bswasher(struct player_state_s *arg0) {
    void _batimer_set(struct player_state_s *, s32, f32);

    func_808001A8_bswasher(arg0);
    _bsdrone_entrypoint_0(arg0);
    _batimer_set(arg0, 2, 0.0f);
    if (_badrone_entrypoint_3(arg0) == 2) {
        func_800947EC(arg0, 2, 1);
        _bafpctrl_entrypoint_10(arg0, 1);
    }
}

void func_808007DC_bswasher(struct player_state_s *arg0) {
    int bakey_pressed(struct player_state_s *, int);
    s32 func_80800300_bswasher(BtIntPtr);
    void _bsdrone_entrypoint_1(struct player_state_s *);
    int _batimer_decrement(struct player_state_s *, s32);
    int _batimer_isZero(struct player_state_s *, s32);
    void _batimer_set(struct player_state_s *, s32, f32);
    void func_8009DBB0(struct player_state_s *, s32, f32, f32, s32);

    _bsdrone_entrypoint_1(arg0);
    func_80800300_bswasher(arg0);
    if (_badrone_entrypoint_3(arg0) == 2) {
        _batimer_decrement(arg0, 2);
        if (bakey_pressed(arg0, 1) && _batimer_isZero(arg0, 2)) {
            func_8009DBB0(arg0, 0x573, 1.05f, 1.15f, 20000);
            func_8009DBB0(arg0, 0x406, 0.85f, 0.95f, 20000);
            _bawasher_entrypoint_7(arg0);
            _batimer_set(arg0, 2, 0.5f);
        }
    }
}

BsScript bswasher_entrypoint_2(BsScriptType arg0) {

    return (BsScript)D_80801E20_bswasher[arg0];
}

/* extern */

void func_808008BC_bswasher(BtIntPtr arg0) {
    void func_8009BF5C(struct player_state_s *, f32);
    void baroll_setIdeal(struct player_state_s *, f32);
    func_8009BF5C(arg0, 0.0f);
    baroll_setIdeal(arg0, 0.0f);
    func_808000F0_bswasher(arg0);
}

struct anctrl_s;

void func_808008F4_bswasher(struct player_state_s *arg0) {
    enum asset_e;
    void anctrl_reset(struct anctrl_s *);
#ifndef BT_NATIVE
    void anctrl_setIndex(struct anctrl_s *, enum asset_e);
#endif
    void anctrl_setStart(struct anctrl_s *, f32);
    void anctrl_setDuration(struct anctrl_s *, f32);
    void anctrl_setPlaybackType(struct anctrl_s *, s32);
    void anctrl_start(struct anctrl_s *);
    struct anctrl_s *baanim_getAnimCtrlPtr(struct player_state_s *);
    void func_8009FFD8();
    struct anctrl_s *control;

    func_808001A8_bswasher(arg0);
    control = baanim_getAnimCtrlPtr(arg0);
    anctrl_reset(control);
    anctrl_setIndex(control, 0x355);
    anctrl_setStart(control, 0.5036f);
    anctrl_setDuration(control, 0.7f);
    anctrl_setPlaybackType(control, 3);
    anctrl_start(control);
    func_8009FFD8(arg0, 1, 3, 3, 6);
    func_808000BC_bswasher((BtIntPtr)arg0);
    *(s32 *)((u8 *)arg0 + 0x15C) = 0;
}

void func_8080099C_bswasher(struct player_state_s *arg0) {
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
    int player_isStable(struct player_state_s *);
    s32 next_state;
    struct anctrl_s *control;
    f32 velocity[3];

    next_state = 0;
    control = baanim_getAnimCtrlPtr(arg0);
    func_8009D3A8(arg0, 0);
    func_80800000_bswasher(arg0);
    func_8009BB24(arg0, velocity);
    switch (*(s32 *)((u8 *)arg0 + 0x15C)) {
        case 0:
            if (func_8008DF8C(arg0, 0x82)) {
                baanim_setEnd(arg0, 0.706f);
                *(s32 *)((u8 *)arg0 + 0x15C) = 1;
            }
            break;
        case 1:
            if (player_isStable(arg0)) {
                func_800A2EAC(arg0);
                baphysics_set_target_horizontal_velocity(arg0, 0.0f);
                baanim_setEndAndDuration(arg0, 1.0f, 1);
                *(s32 *)((u8 *)arg0 + 0x15C) = 2;
            }
            break;
        case 2:
            break;
    }
    if (player_isStable(arg0) && (bastick_getZone(arg0) > 0 ||
        (*(s32 *)((u8 *)arg0 + 0x15C) == 2 && anctrl_isStopped(control)))) {
        if (baflag_isTrue(arg0, 0x19)) {
            next_state = _badrone_entrypoint_28(arg0);
        } else {
            next_state = 0x32;
        }
    }
    func_80800300_bswasher((BtIntPtr)arg0);
    bs_setState(arg0, next_state);
}

BsScript bswasher_entrypoint_3(BsScriptType arg0) {

    return (BsScript)D_80801E30_bswasher[arg0];
}

void func_80800B08_bswasher(struct player_state_s *arg0) {
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
    void func_8009D7A4(struct player_state_s *, f32, f32);
    void func_8009FFD8();
    s32 pad[2];
    f32 sp2C;
    struct anctrl_s *control;

    func_808001A8_bswasher(arg0);
    control = baanim_getAnimCtrlPtr(arg0);
    anctrl_reset(control);
    anctrl_setSmoothTransition(control, 0);
    anctrl_setIndex(control, 0x355);
    anctrl_setSubrange(control, 0.0f, 0.5f);
    anctrl_setDuration(control, 1.0f);
    anctrl_setStart(control, 0.15f);
    anctrl_setPlaybackType(control, 1);
    anctrl_start(control);
    func_8009FFD8(arg0, 1, 3, 1, 6);
    func_808000BC_bswasher((BtIntPtr)arg0);
    if (bastick_distance(arg0) != 0.0f) {
        yaw_setIdeal(arg0, bastick_getAngleRelativeToBanjo(arg0));
    }
    baphysics_set_target_yaw(arg0, yaw_getIdeal(arg0));
    func_80800000_bswasher(arg0);
    sp2C = yaw_getIdeal(arg0);
    baphysics_set_horizontal_velocity(arg0, sp2C, baphysics_get_target_horizontal_velocity(arg0));
    baphysics_set_vertical_velocity(arg0, 693.5f);
    baphysics_set_gravity(arg0, -2400.0f);
    func_8009D7A4(arg0, 1.35f, 1.45f);
    *(s32 *)((u8 *)arg0 + 0x15C) = 0;
}

void func_80800C70_bswasher(struct player_state_s *arg0) {
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
    s32 sp34;
    struct anctrl_s *sp30;
    f32 sp24[3];

    sp34 = 0;
    sp30 = baanim_getAnimCtrlPtr(arg0);
    func_80800000_bswasher(arg0);
    func_8009BB24(arg0, sp24);
    if (bakey_released(arg0, 8) && sp24[1] > 0.0f) {
        baphysics_reset_gravity(arg0);
    }
    switch (*(s32 *)((u8 *)arg0 + 0x15C)) {
    case 0:
        if (func_8008DF8C(arg0, 0x82)) {
            baanim_setEndAndDuration(arg0,
                1.0f + 0.0f,
                0.7f);
            *(s32 *)((u8 *)arg0 + 0x15C) = 2;
        } else if (anctrl_isStopped(sp30)) {
            baanim_setEndAndDuration(arg0, 0.706f, 3.0f);
            *(s32 *)((u8 *)arg0 + 0x15C) = 1;
        }
        break;
    case 1:
        if (func_8008DF8C(arg0, 0x82)) {
            baanim_setEndAndDuration(arg0,
                1.0f + 0.0f,
                1.0f);
            *(s32 *)((u8 *)arg0 + 0x15C) = 2;
        }
        break;
    case 2:
        func_8009D3A8(arg0, 0);
        if (player_isStable(arg0)) {
            func_800A2EAC(arg0);
            baanim_setEndAndDuration(arg0,
                1.0f + 0.0f,
                1.0f);
            *(s32 *)((u8 *)arg0 + 0x15C) = 3;
        }
        break;
    case 3:
        func_8009D2D8(arg0, 3);
        func_8009D3A8(arg0, 0);
        if (func_8009BB5C(arg0) > 0.0f) {
            sp34 = 0x33;
        } else if (anctrl_isStopped(sp30)) {
            sp34 = 0x32;
        }
        if (bakey_pressed(arg0, 8)) {
            sp34 = 0x35;
        }
        break;
    }
    if (bakey_pressed(arg0, 1)) {
        sp34 = 0x38;
    }
    func_80800300_bswasher((BtIntPtr)arg0);
    bs_setState(arg0, sp34);
}

void func_80800E74_bswasher(BtIntPtr arg0) {
    void func_8009BF5C(struct player_state_s *, f32);
    void baroll_setIdeal(struct player_state_s *, f32);
    baphysics_reset_gravity();
    func_8009BF5C(arg0, 0.0f);
    baroll_setIdeal(arg0, 0.0f);
    func_808000F0_bswasher(arg0);
}

BsScript bswasher_entrypoint_4(BsScriptType arg0) {

    return (BsScript)D_80801E40_bswasher[arg0];
}                typedef struct { u8 pad0[0x15C]; s32 unk15C; BtIntPtr unk160; } Objwasher_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

/* extern */

void func_80800EC8_bswasher(u8 *arg0) {
    void bs_setState(struct player_state_s *, int);
    BtIntPtr func_80099A4C(void *);
    s32 func_80099B94(u8 *);
    s32 func_8009E6EC();
    if (func_8009E6EC(arg0) == 0x65) {
        (((Objwasher_arg0 *)arg0)->unk160) = func_80099A4C(arg0);
        bs_setState((BtIntPtr) arg0, 0x37);
    }
    func_80099B94(arg0);
}

void func_80800F1C_bswasher(BtIntPtr arg0) {
    s32 func_800C2FDC(u8 index);
    u8 temp;

    temp = ((u8 *)arg0)[0x165];
    if (temp != 0) {
        func_800C2FDC(temp);
        ((u8 *)arg0)[0x165] = 0;
    }
}

void func_80800F54_bswasher(void *arg0) {

    (*(s8 *)((s8 *)(arg0) + (0x165))) = func_8009D454(arg0, 0, D_80801E50_bswasher);
}

/* extern */

void func_80800F88_bswasher(struct player_state_s *arg0) {
    f32 func_8009BB5C(struct player_state_s *);
    void func_8009C128(struct player_state_s *, f32[3]);
    void func_800C31DC(u8, f32);
    void func_800C35E8(u8, f32[3]);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    s32 pad;
    f32 sp38;
    f32 sp2C[3];

    if ((*(u8 *)((s8 *)(arg0) + (0x165))) != 0) {
        sp38 = func_8009BB5C(arg0);
        func_8009C128(arg0, sp2C);
        func_800C35E8((*(u8 *)((s8 *)(arg0) + (0x165))), sp2C);
        func_800C31DC((*(u8 *)((s8 *)(arg0) + (0x165))), func_800F10B4(sp38, 0.0f, 900.0f, 0.9f, 1.2f));
    }
}

void func_8080100C_bswasher(BtIntPtr arg0)
{
    func_80800F1C_bswasher(arg0);
    func_808000F0_bswasher(arg0);
}
void func_80801034_bswasher(struct player_state_s *arg0) {
    BT_IDO_ONLY(s32 baanim_playForDuration_loopSmooth(BtIntPtr, s32, s32);)
    void baanim_setDurationRange(struct player_state_s *, f32, f32);
    void func_8008C9F0(struct player_state_s *, f32, f32, f32, f32);
    void func_8008CA30(struct player_state_s *, f32);
    void func_8009FFD8();

    func_808001A8_bswasher(arg0);
    baanim_playForDuration_loopSmooth(arg0, 0x359, BT_IDO_ONLY(0x3F800000) BT_NATIVE_ONLY(1.0f));
    func_8009FFD8(arg0, 2, 3, 1, 0xE);
    baanim_setDurationRange(arg0, 0.3f, 1.5f);
    func_8008C9F0(arg0, 30.0f, 900.0f, 0.7f, 0.3f);
    func_8008CA30(arg0, 1.0f);
    func_808000BC_bswasher((BtIntPtr)arg0);
    func_80800F54_bswasher(arg0);
}

/* extern */

void func_808010DC_bswasher(struct player_state_s *arg0) {
    s32 _badrone_entrypoint_25(struct player_state_s *);
    int bakey_pressed(struct player_state_s *, int);
    s32 bastick_getZone(struct player_state_s *);
    void bs_setState(struct player_state_s *, int);
    int func_8008DD04(struct player_state_s *);
    int func_8008E148(struct player_state_s *);
    void func_8009D3A8(struct player_state_s *, s32);
    void func_80800000_bswasher(struct player_state_s *);
    s32 func_80800300_bswasher(BtIntPtr);
    s32 var_s1;

    var_s1 = 0;
    func_80800F88_bswasher(arg0);
    func_8009D3A8(arg0, 0);
    func_80800000_bswasher(arg0);
    if (bastick_getZone(arg0) == 0) {
        var_s1 = 0x32;
    }
    if (func_8008DD04(arg0) != 0) {
        var_s1 = 0x36;
    }
    if (bakey_pressed(arg0, 8) != 0) {
        var_s1 = 0x35;
    }
    if (bakey_pressed(arg0, 1) != 0) {
        var_s1 = 0x38;
    }
    if (func_8008E148(arg0) != 0) {
        var_s1 = _badrone_entrypoint_25(arg0);
    }
    func_80800300_bswasher(arg0);
    bs_setState(arg0, var_s1);
}

BsScript bswasher_entrypoint_5(BsScriptType arg0) {

    return (BsScript)D_80801E60_bswasher[arg0];
}

void func_808011B4_bswasher(BtIntPtr arg0)
{
    _baspin_entrypoint_1();
    func_808000F0_bswasher(arg0);
}
void func_808011DC_bswasher(BtIntPtr arg0) { func_808001A8_bswasher(arg0); _baspin_entrypoint_2(arg0, 0x358, 0x3FE66666, 2, 0); }

/* extern */

void func_80801218_bswasher(struct player_state_s *arg0) {
    s32 _baspin_entrypoint_3(struct player_state_s *);
    void bs_setState(struct player_state_s *, int);
    int func_8009640C(struct player_state_s *);
    void func_800A2EAC(void *);
    s32 func_80800300_bswasher(BtIntPtr);
    s32 sp24;
    struct player_state_s *self;

    self = arg0;
    sp24 = 0;
    func_80800300_bswasher(self);
    if (func_8009640C(self) != 0) {
        func_800A2EAC(self);
    }
    if (_baspin_entrypoint_3(self) == 2) {
        sp24 = 0x32;
    }
    bs_setState(self, sp24);
}

BsScript bswasher_entrypoint_6(BsScriptType arg0) {

    return (BsScript)D_80801E70_bswasher[arg0];
}

void func_80801294_bswasher(BtIntPtr arg0)
{
    _babounce_entrypoint_3();
    func_808000F0_bswasher(arg0);
}
/* extern */

void func_808012BC_bswasher(struct player_state_s *arg0) {
    void _babounce_entrypoint_4(struct player_state_s *, s32);
    void _babounce_entrypoint_5(struct player_state_s *, s32, f32);
    struct anctrl_s *baanim_getAnimCtrlPtr(struct player_state_s *);
    void func_8008B10C(struct anctrl_s *, f32);
    func_808001A8_bswasher(arg0);
    _babounce_entrypoint_4(arg0, 2);
    _babounce_entrypoint_5(arg0, 0x358, 0.5128f);
    func_8008B10C(baanim_getAnimCtrlPtr(arg0), 0.1026f);
}

/* extern */

void func_80801314_bswasher(BtIntPtr arg0) {
    s32 _babounce_entrypoint_2();
    s32 _babounce_entrypoint_9(BtIntPtr);
    void bs_setState(struct player_state_s *, int);
    void func_80800000_bswasher(struct player_state_s *);
    s32 sp1C;

    sp1C = 0;
    if (_babounce_entrypoint_2() != 0) {
        func_80800000_bswasher(arg0);
    }
    if (_babounce_entrypoint_9(arg0) != 0) {
        sp1C = 0x32;
    }
    bs_setState(arg0, sp1C);
}

BsScript bswasher_entrypoint_7(BsScriptType arg0) {

    return (BsScript)D_80801E80_bswasher[arg0];
}

void func_8080137C_bswasher(BtIntPtr arg0)
{
    _bsrest_entrypoint_14();
    func_808000F0_bswasher(arg0);
}
void func_808013A4_bswasher(BtIntPtr arg0)
{
    func_808001A8_bswasher(arg0);
    _bsrest_entrypoint_16(arg0);
}
/* extern */

void func_808013CC_bswasher(BtIntPtr arg0) {
    s32 _bsrest_entrypoint_13(BtIntPtr);
    s32 _bsrest_entrypoint_20();
    void bs_setState(struct player_state_s *, int);
    s32 func_80800300_bswasher(BtIntPtr);
    s32 sp1C;

    sp1C = 0;
    if (_bsrest_entrypoint_20() != 0) {
        sp1C = _bsrest_entrypoint_13(arg0);
    }
    func_80800300_bswasher(arg0);
    bs_setState(arg0, sp1C);
}

BsScript bswasher_entrypoint_8(BsScriptType arg0) {

    return (BsScript)D_80801E90_bswasher[arg0];
}

void func_8080142C_bswasher(BtIntPtr arg0)
{
    func_808000F0_bswasher(arg0);
    func_80090A2C(arg0);
}
void func_80801454_bswasher(BtIntPtr arg0) {
    void func_8009FFD8();
    BT_IDO_ONLY(s32 baanim_playForDuration_loopSmooth(BtIntPtr, s32, s32);)
    void baphysics_set_target_horizontal_velocity(struct player_state_s *, f32);
    void func_800909CC(struct player_state_s *);
    func_808001A8_bswasher(arg0);
    baanim_playForDuration_loopSmooth(arg0, 0x356, BT_IDO_ONLY(0x4079999A) BT_NATIVE_ONLY(3.9f));
    func_8009FFD8(arg0, 1, 3, 1, 2);
    func_808000BC_bswasher(arg0);
    baphysics_set_target_horizontal_velocity(arg0, 0.0f);
    func_800909CC(arg0);
}

/* extern */

void func_808014C8_bswasher(struct player_state_s *arg0) {
    s32 _badrone_entrypoint_25(struct player_state_s *);
    int baanim_isAt(struct player_state_s *, f32);
    int bakey_pressed(struct player_state_s *, int);
    s32 bastick_getZone(struct player_state_s *);
    void bs_setState(struct player_state_s *, int);
    int func_8008DD04(struct player_state_s *);
    int func_8008E148(struct player_state_s *);
    void func_8009D3A8(struct player_state_s *, s32);
    void func_8009DEC0(struct player_state_s *, s32, f32, f32, s32, s32);
    s32 func_800A02DC(struct player_state_s *, s32);
    s32 func_80800064_bswasher(BtIntPtr, s32);
    s32 func_80800300_bswasher(BtIntPtr);
    s32 var_s1;

    var_s1 = 0;
    func_8009D3A8(arg0, 0);
    if ((baanim_isAt(arg0, 0.1487f) != 0) || (baanim_isAt(arg0, 0.2737f) != 0)) {
        func_8009DEC0(arg0, 0x4A1, 0.9f, 1.1f, 0xBB8, 0xFA0);
    }
    if (func_8008E148(arg0) != 0) {
        var_s1 = _badrone_entrypoint_25(arg0);
    }
    if (func_8008DD04(arg0) != 0) {
        var_s1 = 0x36;
    }
    if (bastick_getZone(arg0) != 0) {
        var_s1 = 0x33;
    }
    var_s1 = func_800A02DC(arg0, func_80800064_bswasher(arg0, var_s1));
    if (bakey_pressed(arg0, 1) != 0) {
        var_s1 = 0x38;
    }
    func_80800300_bswasher(arg0);
    bs_setState(arg0, var_s1);
}

BsScript bswasher_entrypoint_9(BsScriptType arg0) {

    return (BsScript)D_80801EA0_bswasher[arg0];
}

void func_808015EC_bswasher(BtIntPtr arg0, u32 arg1) {
    BT_IDO_ONLY(void baanim_playForDuration_onceSmooth(struct player_state_s *, s32, f32);)
    void func_8009DBB0(struct player_state_s *, s32, f32, f32, s32);
    void func_8009FFD8();
    s32 func_800C2FDC(u8);
    f32 yaw_get(struct player_state_s *);
    void yaw_setIdeal(struct player_state_s *, f32);
    struct player_state_s *self = (struct player_state_s *)arg0;
    u8 index;

    if (*(u32 *)((u8 *)self + 0x15C) == 3) {
        index = *((u8 *)self + 0x164);
        if (index != 0) {
            func_800C2FDC(index);
            *((u8 *)self + 0x164) = 0;
        }
    }
    *(u32 *)((u8 *)self + 0x15C) = arg1;
    switch (arg1) {
    case 0:
        break;
    case 1:
        baanim_playForDuration_onceSmooth(self, 0x354, 6.7f);
        func_8009FFD8(self, 1, 3, 2, 2);
        func_808000BC_bswasher(arg0);
        yaw_setIdeal(self, yaw_get(self));
        *((u8 *)self + 0x164) = 0;
        break;
    case 2:
        _chfactoryworkerdirty_entrypoint_1(*(s32 *)((u8 *)self + 0x160), 1);
        break;
    case 3:
        _chfactoryworkerdirty_entrypoint_1(*(s32 *)((u8 *)self + 0x160), 2);
        break;
    case 4:
        func_8009DBB0(self, 0x573, 1.05f, 1.15f, 0x4E20);
        func_8009DBB0(self, 0x406, 0.85f, 0.95f, 0x4E20);
        _chfactoryworkerdirty_entrypoint_1(*(s32 *)((u8 *)self + 0x160), 3);
        break;
    case 5:
        _chfactoryworkerdirty_entrypoint_1(*(s32 *)((u8 *)self + 0x160), 4);
        break;
    }
}

void func_80801744_bswasher(BtIntPtr arg0)
{
    func_808015EC_bswasher(arg0,0);
    func_808000F0_bswasher(arg0);
}

void func_80801770_bswasher(BtIntPtr arg0) { func_808001A8_bswasher(arg0); ((Objwasher_arg0 *)arg0)->unk15C = 0; func_808015EC_bswasher(arg0, 1); }

void func_808017A0_bswasher(u8 *arg0) {
    void _bawasher_entrypoint_3(u8 *, f32 *);
    void _chfactoryworkerdirty_entrypoint_2(Unk80132ED0 *arg0, BtIntPtr arg1, f32 arg2);
    void _chfactoryworkerdirty_entrypoint_3(Unk80132ED0 *arg0, f32 arg1);
    f32 baanim_getTimer();
    int baanim_isAt(struct player_state_s *, f32);
    int baanim_isStopped(struct player_state_s *);
    void bs_setState(struct player_state_s *, int);
    s32 func_8009D454(struct player_state_s *, volatile u8, s32 *);
    void func_8009DB04(u8 *, s32, f32, s32);
    void func_800C31DC(u8, f32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);

    s32 next_state;
    f32 timer;
    f32 position[3];
    f32 speed;
    s32 at_sound;

    next_state = 0;
    at_sound = baanim_isAt(arg0, 0.0001f);
    if (at_sound != 0) {
        func_8009DB04(arg0, 0x5E7, 1.1f, 20000);
    }
    if (baanim_isAt(arg0, 0.1052f) != 0) {
        func_8009DB04(arg0, 0x519, 1.1f, 20000);
    }
    if (baanim_isAt(arg0, 0.275f) != 0) {
        func_8009DB04(arg0, 0x5E7, 0.9f, 20000);
    }
    if (baanim_isAt(arg0, 0.8572f) != 0) {
        func_8009DB04(arg0, 0x5E7, 1.1f, 20000);
    }
    at_sound = baanim_isAt(arg0, 0.93f);
    if (at_sound != 0) {
        func_8009DB04(arg0, 0x5E7, 0.85f, 20000);
    }
    switch (*(s32 *)(arg0 + 0x15C)) {
        case 1:
            if (baanim_isAt(arg0, 0.07f) != 0) {
                func_808015EC_bswasher(arg0, 2);
            }
            break;
        case 2:
            _bawasher_entrypoint_3(arg0, position);
            _chfactoryworkerdirty_entrypoint_2(*(s32 *)(arg0 + 0x160), position,
                func_800F10B4(baanim_getTimer(arg0), 0.07f, 0.12f, 0.0f, 1.0f));
            if (baanim_isAt(arg0, 0.12f) != 0) {
                func_808015EC_bswasher(arg0, 3);
            }
            break;
        case 3:
            if (baanim_isAt(arg0, 0.2949f) != 0) {
                *(u8 *)(arg0 + 0x164) = func_8009D454((void *)arg0, 0, D_80801EB0_bswasher);
            }
            timer = baanim_getTimer(arg0);
            if (timer < 0.77f) {
                speed = func_800F10B4(timer, 0.2949f, 0.77f, 0.0f, 1400.0f);
            } else {
                speed = func_800F10B4(timer, 0.84f, 0.77f, 0.0f, 1400.0f);
            }
            _chfactoryworkerdirty_entrypoint_3(*(s32 *)(arg0 + 0x160), speed);
            if (*(u8 *)(arg0 + 0x164) != 0) {
                func_800C31DC(*(u8 *)(arg0 + 0x164),
                    func_800F10B4(speed, 0.0f, 800.0f, 0.8f, 1.9f));
            }
            if (baanim_isAt(arg0, 0.89f) != 0) {
                func_808015EC_bswasher(arg0, 4);
            }
            break;
        case 4:
            _bawasher_entrypoint_3(arg0, position);
            _chfactoryworkerdirty_entrypoint_2(*(s32 *)(arg0 + 0x160), position,
                func_800F10B4(baanim_getTimer(arg0), 0.89f, 0.94f, 1.0f, 0.0f));
            if (baanim_isAt(arg0, 0.94f) != 0) {
                func_808015EC_bswasher(arg0, 5);
            }
            break;
        case 5:
            if (baanim_isStopped(arg0) != 0) {
                next_state = 0x32;
            }
            break;
    }
    bs_setState((BtIntPtr)arg0, next_state);
}

BsScript bswasher_entrypoint_10(BsScriptType arg0) {

    return (BsScript)D_80801EC4_bswasher[arg0];
}

void func_80801B10_bswasher(struct player_state_s *arg0)
{
    func_808000F0_bswasher(arg0);
}

void func_80801B30_bswasher(struct player_state_s *arg0) {
    BT_IDO_ONLY(void baanim_playForDuration_onceSmooth(struct player_state_s *, s32, f32);)
    void func_8009FFD8();
    f32 yaw_get(struct player_state_s *);
    void yaw_setIdeal(struct player_state_s *, f32);
    func_808001A8_bswasher(arg0);
    baanim_playForDuration_onceSmooth(arg0, 0x357, 0.8f);
    func_8009FFD8(arg0, 1, 3, 2, 2);
    func_808000BC_bswasher((BtIntPtr)arg0);
    yaw_setIdeal(arg0, yaw_get(arg0));
}

void func_80801BA4_bswasher(struct player_state_s *arg0) {
    f32 baanim_getTimer(struct player_state_s *);
    int baanim_isAt(struct player_state_s *, f32);
    int baanim_isStopped(struct player_state_s *);
    int bakey_pressed(struct player_state_s *, int);
    f32 baphysics_get_target_horizontal_velocity(struct player_state_s *);
    void baphysics_set_target_horizontal_velocity(struct player_state_s *, f32);
    s32 bastick_getZone(struct player_state_s *);
    void bs_setState(struct player_state_s *, int);
    void func_8009D2D8(struct player_state_s *, s32);
    void func_8009DBB0(struct player_state_s *, s32, f32, f32, s32);
    f32 func_800D8FF8(void);
    s32 sp34;
    f32 sp30;
    f32 sp2C;
    f32 sp28;

    sp34 = 0;
    sp2C = baphysics_get_target_horizontal_velocity(arg0);
    baphysics_set_target_horizontal_velocity(arg0, (0.028f / func_800D8FF8()) * sp2C);
    if (baanim_isAt(arg0, 0.1309f)) {
        func_8009DBB0(arg0, 0x573, 1.05f, 1.15f, 20000);
        func_8009DBB0(arg0, 0x406, 0.85f, 0.95f, 20000);
        _bawasher_entrypoint_7(arg0);
        func_8009D2D8(arg0, 1);
    }
    if (baanim_isStopped(arg0)) {
        sp34 = 0x32;
    }
    if (baanim_getTimer(arg0) > 0.8f) {
        if (bastick_getZone(arg0)) {
            sp34 = 0x33;
        }
        if (bakey_pressed(arg0, 1)) {
            sp34 = 0x38;
        }
    }
    bs_setState(arg0, sp34);
}

BsScript bswasher_entrypoint_11(BsScriptType arg0) {

    return (BsScript)D_80801ED4_bswasher[arg0];
}
