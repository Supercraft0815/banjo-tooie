#include "bs_script.h"
#include "common.h"
BT_NATIVE_ONLY(struct player_state_s; int _babounce_entrypoint_2(struct player_state_s *); void _babounce_entrypoint_3(struct player_state_s *); void _bsrest_entrypoint_14(struct player_state_s *); s32 _bsrest_entrypoint_20(struct player_state_s *);) struct anctrl_s;
#include "transformations.h"
/* extern */

f32 func_80800000_bssnowball(BtIntPtr arg0) {
    f32 _basnowball_entrypoint_3(BT_NATIVE_ONLY(void *));
    void func_8008C990(void *self, f32 arg1);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    f32 func_800F13C4(f32, f32);
    f32 sp20;
    f32 temp_f0;

    temp_f0 = func_800F13C4(func_800F10B4(_basnowball_entrypoint_3(BT_NATIVE_ONLY((void *)arg0)), 0.0f, 360.0f, 0.0f, 1.0f), 1.0f);
    sp20 = temp_f0;
    func_8008C990(arg0, temp_f0);
    return temp_f0;
}

struct player_state_s;
void func_80800064_bssnowball(struct player_state_s *arg0, s32 arg1) {
    void _basnowball_entrypoint_7(struct player_state_s *);
    int bakey_held(struct player_state_s *, s32);
    void baphysics_set_target_horizontal_velocity(struct player_state_s *, f32);
    s32 bastick_getZone(struct player_state_s *);
    f32 bastick_getZonePosition(struct player_state_s *);
    f32 func_800F1214(f32, f32, f32);
    f32 sp24;

    sp24 = bastick_getZonePosition(arg0);
    if ((arg1 != 0) && (bakey_held(arg0, 9) != 0)) {
        baphysics_set_target_horizontal_velocity(arg0, 1400.0f);
        _basnowball_entrypoint_7(arg0);
        return;
    }
    if (bastick_getZone(arg0) == 0) {
        baphysics_set_target_horizontal_velocity(arg0, 0.0f);
        return;
    }
    baphysics_set_target_horizontal_velocity(arg0, func_800F1214(sp24, 30.0f, 700.0f));
}

/* extern */

s32 func_8080010C_bssnowball(BtIntPtr arg0, s32 arg1) {
    s32 _badrone_entrypoint_24(BtIntPtr);
    BT_NATIVE_ONLY(int bainput_should_enter_first_person(struct player_state_s *);) BT_IDO_ONLY(s32 bainput_should_enter_first_person();)
    s32 bakey_pressed(BtIntPtr, s32);
    if (bainput_should_enter_first_person(BT_NATIVE_ONLY((struct player_state_s *)arg0)) != 0) {
        arg1 = _badrone_entrypoint_24(arg0);
    }
    if (bakey_pressed(arg0, 8) != 0) {
        arg1 = 0x17F;
    }
    return arg1;
}

/* extern */

void func_80800164_bssnowball(BtIntPtr arg0) {
    s32 yaw_setUpdateType(BtIntPtr, s32);
    s32 yaw_setVelocityBounded(BtIntPtr, s32, s32);
    yaw_setUpdateType(arg0, 3);
    yaw_setVelocityBounded(arg0, 0x43960000, 0x40C00000);
}

typedef struct player_state_s PlayerState;

void bssnowball_entrypoint_0(PlayerState *arg0) {
    void _basnowball_entrypoint_1(PlayerState *);
    void baflag_clear(PlayerState *, s32);
    void baroll_resetAngularVelocity(PlayerState *);
    void baroll_setIdeal(PlayerState *, f32);
    void bastick_popZone(PlayerState *);
    void func_80092864(PlayerState *, f32);
    void func_800947EC(PlayerState *, s32, s32);
    void func_8009BF5C(PlayerState *, f32);
    void func_8009C000(PlayerState *);
    s32 func_8009E74C(PlayerState *, s32);
    if (func_8009E74C(arg0, 0x16) == 0) {
        func_800947EC(arg0, 1, 0);
        func_8009BF5C(arg0, 0.0f);
        baroll_setIdeal(arg0, 0.0f);
        func_8009C000(arg0);
        baroll_resetAngularVelocity(arg0);
        bastick_popZone(arg0);
        baflag_clear(arg0, 3);
        baflag_clear(arg0, 4);
        _basnowball_entrypoint_1(arg0);
        func_80092864(arg0, 1.0f);
    }
}

void bssnowball_entrypoint_1(PlayerState *arg0) {
    void _basnowball_entrypoint_2(PlayerState *);
    void baflag_set(PlayerState *, s32);
    void baroll_setAngularVelocity(PlayerState *, f32, f32);
    void bastick_pushZone(PlayerState *);
    void bastick_setZoneMax(PlayerState *, s32, f32);
    void func_80092864(PlayerState *, f32);
    void func_800947EC(PlayerState *, s32, s32);
    void func_8009BFE4(PlayerState *, f32, f32);
    s32 func_8009E77C(PlayerState *, s32);
    if (func_8009E77C(arg0, 0x16) == 0) {
        _basnowball_entrypoint_2(arg0);
        func_8009BFE4(arg0, 1000.0f, 12.0f);
        baroll_setAngularVelocity(arg0, 1000.0f, 12.0f);
        bastick_pushZone(arg0);
        bastick_setZoneMax(arg0, 0, 0.12f);
        bastick_setZoneMax(arg0, 1, 1.0f);
        baflag_set(arg0, 3);
        baflag_set(arg0, 4);
        func_800947EC(arg0, 1, 1);
        *(u8 *)((u8 *)arg0 + 0x165) = 0;
        func_80092864(arg0, 1.0999908447265625f);
    }
}

/* extern */

void bssnowball_entrypoint_2(void *arg0) {
    void _basnowball_entrypoint_12(void *arg0);
    void _basnowball_entrypoint_8(BtIntPtr arg0, s32 arg1);
    void _basnowball_entrypoint_9(void *arg0, f32 arg1);
    f32 baphysics_get_target_horizontal_velocity(PlayerState *);
    f32 func_8009BB5C(void *);
    BT_NATIVE_ONLY(TransformationId func_800A3274(struct player_state_s *);) BT_IDO_ONLY(s32 func_800A3274();)
    if (func_800A3274(BT_NATIVE_ONLY(arg0)) == 2) {
        if ((*(u8 *)((s8 *)(arg0) + (0x165))) != 0) {
            _basnowball_entrypoint_9(arg0, 0.0f);
        } else {
            _basnowball_entrypoint_9(arg0, func_8009BB5C(arg0));
        }
        if (((*(u8 *)((s8 *)(arg0) + (0x165))) != 0) || (baphysics_get_target_horizontal_velocity(arg0) == 0.0f)) {
            _basnowball_entrypoint_8(arg0, 1);
        } else {
            _basnowball_entrypoint_8(arg0, 0);
        }
        _basnowball_entrypoint_12(arg0);
    }
}

void func_808003B0_bssnowball(BtIntPtr arg0)
{
    _basudie_entrypoint_8();
    bssnowball_entrypoint_0(arg0);
}
void func_808003D8_bssnowball(PlayerState *arg0) {
    void _basudie_entrypoint_9(struct player_state_s *arg0, f32 arg1);
    void func_8009C128(PlayerState *, f32[3]);
    void func_8009DB04(PlayerState *, s32, f32, s32);
    BtIntPtr func_800B53A4(s32);
    BtIntPtr func_800BABB8(BtIntPtr, f32[3], f32[3], f32, s32[]);
    BtIntPtr func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    extern s32 D_80800F30_bssnowball[];
    extern s32 D_80800F84_bssnowball[];
    extern s32 D_80801028_bssnowball[];
    f32 sp2C[3];
    BtIntPtr sp28;

    sp28 = func_800B53A4(0x32);
    bssnowball_entrypoint_1(arg0);
    _basudie_entrypoint_9(arg0, 90.0f);
    func_8009C128(arg0, sp2C);
    func_8009DB04(arg0, 0x694, 1.0f, 0x7FFF);
    func_8009D9D4(arg0);
    func_800BBCB8(sp2C, NULL, 1.0f, 1, D_80801028_bssnowball);
    func_800BBCB8(sp2C, NULL, 1.0f, 1, D_80800F30_bssnowball);
    func_800BABB8(sp28, sp2C, sp2C, 1.0f, D_80800F84_bssnowball);
    _basnowball_entrypoint_10(arg0);
}

void func_808004AC_bssnowball(BT_NATIVE_ONLY(s32 bt_a0))
{
    _basudie_entrypoint_10(BT_NATIVE_ONLY(bt_a0));
}

BsScript bssnowball_entrypoint_3(BsScriptType arg0) {
    extern BtIntPtr D_80801054_bssnowball[];
    return (BsScript)D_80801054_bssnowball[arg0];
}

#ifdef BT_NATIVE
struct player_state_s;
void _bsdrone_entrypoint_2(struct player_state_s *);
#endif

void func_808004E0_bssnowball(BT_NATIVE_ONLY(struct player_state_s *) BT_IDO_ONLY(BtIntPtr) arg0)
{
    _bsdrone_entrypoint_2(BT_NATIVE_ONLY(arg0));
    bssnowball_entrypoint_0(arg0);
}
void func_80800508_bssnowball(BtIntPtr arg0)
{
    bssnowball_entrypoint_1(arg0);
    _bsdrone_entrypoint_0(arg0);
} BT_NATIVE_ONLY(struct player_state_s; void _bsdrone_entrypoint_1(struct player_state_s *); void func_80090A2C(struct player_state_s *);)
void func_80800530_bssnowball(BT_NATIVE_ONLY(struct player_state_s *) BT_IDO_ONLY(BtIntPtr) arg0)
{
    _bsdrone_entrypoint_1(BT_NATIVE_ONLY(arg0));
    bssnowball_entrypoint_2(arg0);
}
BsScript bssnowball_entrypoint_4(BsScriptType arg0) {
    extern BtIntPtr D_80801064_bssnowball[];
    return (BsScript)D_80801064_bssnowball[arg0];
}

/* extern */

void func_8080056C_bssnowball(BtIntPtr arg0) {
    void func_8009BF5C(struct player_state_s *, f32);
    void baroll_setIdeal(struct player_state_s *, f32);
    func_8009BF5C(arg0, 0.0f);
    baroll_setIdeal(arg0, 0.0f);
    bssnowball_entrypoint_0(arg0);
}

void func_808005A4_bssnowball(BtIntPtr arg0) {
    void anctrl_setPlaybackType(struct anctrl_s *, s32);
    struct anctrl_s *baanim_getAnimCtrlPtr(struct player_state_s *);
    void baanim_playForDuration_loopSmooth(PlayerState *, s32, f32);
    void func_8009FFD8();
    bssnowball_entrypoint_1(arg0);
    baanim_playForDuration_loopSmooth(arg0, 0x5F, 10.0f);
    func_8009FFD8(arg0, 2, 3, 1, 0xE);
    anctrl_setPlaybackType(baanim_getAnimCtrlPtr(arg0), 3);
    func_80800164_bssnowball(arg0);
}

void func_80800614_bssnowball(PlayerState *arg0) {
    void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
    s32 bs_setState(BtIntPtr, s32);
    int func_8008DF8C(PlayerState *, s32);
    void func_8009D3A8(PlayerState *, s32);
    void func_800A2EAC(void *);
    int player_isStable(PlayerState *);
    s32 sp24;

    sp24 = 0;
    func_80800064_bssnowball(arg0, 1);
    func_80800000_bssnowball(arg0);
    if (func_8008DF8C(arg0, 0xC8) != 0) {
        func_8009D3A8(arg0, 0);
    }
    if (player_isStable(arg0) != 0) {
        func_800A2EAC(arg0);
        baphysics_set_target_horizontal_velocity(arg0, 0.0f);
        sp24 = 0x17E;
    }
    bssnowball_entrypoint_2(arg0);
    bs_setState(arg0, sp24);
}

BsScript bssnowball_entrypoint_5(BsScriptType arg0) {
    extern BtIntPtr D_80801074_bssnowball[];
    return (BsScript)D_80801074_bssnowball[arg0];
}

void func_808006BC_bssnowball(PlayerState *arg0) {
    void anctrl_setPlaybackType(struct anctrl_s *, s32);
    struct anctrl_s *baanim_getAnimCtrlPtr(PlayerState *);
    void baanim_playForDuration_loopSmooth(PlayerState *, s32, f32);
    f32 baphysics_get_target_horizontal_velocity(PlayerState *);
    void baphysics_set_gravity(PlayerState *, f32);
    void baphysics_set_horizontal_velocity(PlayerState *, f32, f32);
    void baphysics_set_target_yaw(PlayerState *, f32);
    void baphysics_set_vertical_velocity(PlayerState *, f32);
    f32 bastick_distance(PlayerState *);
    f32 bastick_getAngleRelativeToBanjo(PlayerState *);
    void func_8009D7A4(PlayerState *, f32, f32);
    void func_8009FFD8();
    f32 yaw_getIdeal(PlayerState *);
    void yaw_setIdeal(PlayerState *, f32);
    f32 sp2C[3];

    bssnowball_entrypoint_1(arg0);
    baanim_playForDuration_loopSmooth(arg0, 0x5F, 10.0f);
    func_8009FFD8(arg0, 2, 3, 1, 0xE);
    anctrl_setPlaybackType(baanim_getAnimCtrlPtr(arg0), 3);
    func_80800164_bssnowball(arg0);
    if (bastick_distance(arg0) != 0.0f) {
        yaw_setIdeal(arg0, bastick_getAngleRelativeToBanjo(arg0));
    }
    baphysics_set_target_yaw(arg0, yaw_getIdeal(arg0));
    func_80800064_bssnowball(arg0, 1);
    sp2C[0] = yaw_getIdeal(arg0);
    baphysics_set_horizontal_velocity(arg0, sp2C[0], baphysics_get_target_horizontal_velocity(arg0));
    baphysics_set_vertical_velocity(arg0, 693.5f);
    baphysics_set_gravity(arg0, -2400.0f);
    func_8009D7A4(arg0, 1.35f, 1.45f);
}

void func_808007D8_bssnowball(PlayerState *arg0) {
    int bakey_released(PlayerState *, int);
    f32 baphysics_get_vertical_velocity(PlayerState *);
    s32 bs_setState(BtIntPtr, s32);
    int func_8008DF8C(PlayerState *, s32);
    void func_8009D3A8(PlayerState *, s32);
    void func_800A2EAC(void *);
    int player_isStable(PlayerState *);
    s32 sp24;

    sp24 = 0;
    func_80800064_bssnowball(arg0, 1);
    func_80800000_bssnowball(arg0);
    if ((bakey_released(arg0, 8) != 0) && (baphysics_get_vertical_velocity(arg0) > 0.0f)) {
        baphysics_reset_gravity(arg0);
    }
    if (func_8008DF8C(arg0, 0xC8) != 0) {
        func_8009D3A8(arg0, 0);
    }
    if (player_isStable(arg0) != 0) {
        func_800A2EAC(arg0);
        sp24 = 0x17E;
    }
    bssnowball_entrypoint_2(arg0);
    bs_setState(arg0, sp24);
}

void func_8080089C_bssnowball(BtIntPtr arg0) {
    void func_8009BF5C(struct player_state_s *, f32);
    void baroll_setIdeal(struct player_state_s *, f32);
    baphysics_reset_gravity();
    func_8009BF5C(arg0, 0.0f);
    baroll_setIdeal(arg0, 0.0f);
    bssnowball_entrypoint_0(arg0);
}

BsScript bssnowball_entrypoint_6(BsScriptType arg0) {
    extern BtIntPtr D_80801084_bssnowball[];
    return (BsScript)D_80801084_bssnowball[arg0];
}

void func_808008F0_bssnowball(BT_NATIVE_ONLY(s32 bt_a0))
{
    func_80099B94(BT_NATIVE_ONLY(bt_a0));
}

void func_80800910_bssnowball(struct player_state_s *arg0)
{
    bssnowball_entrypoint_0(arg0);
}

void func_80800930_bssnowball(PlayerState *arg0) {
    void anctrl_setPlaybackType(struct anctrl_s *, s32);
    struct anctrl_s *baanim_getAnimCtrlPtr(PlayerState *);
    void baanim_playForDuration_loopSmooth(PlayerState *, s32, f32);
    void func_8009FFD8();
    bssnowball_entrypoint_1(arg0);
    baanim_playForDuration_loopSmooth(arg0, 0x5F, 10.0f);
    func_8009FFD8(arg0, 2, 3, 1, 0xE);
    anctrl_setPlaybackType(baanim_getAnimCtrlPtr(arg0), 3);
    func_80800164_bssnowball(arg0);
    *(s8 *)((u8 *)arg0 + 0x164) = 0;
    *(f32 *)((u8 *)arg0 + 0x174) = 1.0f;
}

void func_808009B0_bssnowball(PlayerState *arg0) {
    f32 _basnowball_entrypoint_3(BT_NATIVE_ONLY(void *));
    s32 bakey_pressed(BtIntPtr, s32);
    s32 bastick_getZone(PlayerState *);
    s32 bs_setState(BtIntPtr, s32);
    int func_8008DD04(PlayerState *);
    f32 func_8009BB5C(void *);
    void func_8009D3A8(PlayerState *, s32);
    void func_8009DBB0(PlayerState *, s32, f32, f32, s32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    s32 sp2C;
    f32 sp28;
    f32 temp;
    f32 pitch;

    sp2C = 0;
    func_8009D3A8(arg0, 0);
    func_80800064_bssnowball(arg0, 1);
    sp28 = func_80800000_bssnowball((BtIntPtr)arg0);
    if (sp28 > 0.67f && *(f32 *)((u8 *)arg0 + 0x174) < 0.67f) {
        temp = func_800F10B4(func_8009BB5C(arg0), 0.0f, 700.0f, 0.9f, 1.1f);
        if (*(u8 *)((u8 *)arg0 + 0x164)) {
            pitch = temp - 0.1f;
        } else {
            pitch = temp + 0.1f;
        }
        func_8009DBB0(arg0, 0x5F2, pitch - 0.03f, pitch + 0.03f, 0x6D60);
        *(u8 *)((u8 *)arg0 + 0x164) ^= 1;
    }
    *(f32 *)((u8 *)arg0 + 0x174) = sp28;
    if (bastick_getZone(arg0) == 0 && _basnowball_entrypoint_3(arg0) == 0.0f) {
        sp2C = 0x17D;
    }
    if (func_8008DD04(arg0)) {
        sp2C = 0x180;
    }
    if (bakey_pressed(arg0, 8)) {
        sp2C = 0x17F;
    }
    bssnowball_entrypoint_2(arg0);
    bs_setState((BtIntPtr)arg0, sp2C);
}

BsScript bssnowball_entrypoint_7(BsScriptType arg0) {
    extern BtIntPtr D_80801094_bssnowball[];
    return (BsScript)D_80801094_bssnowball[arg0];
}

void func_80800B44_bssnowball(BtIntPtr arg0) { _baspin_entrypoint_1(); *(u8 *)(arg0 + 0x165) = 0; bssnowball_entrypoint_0(arg0); }

void func_80800B70_bssnowball(BtIntPtr arg0) { bssnowball_entrypoint_1(arg0); *(u8 *)(arg0 + 0x165) = 1; _basnowball_entrypoint_10(arg0); _baspin_entrypoint_2(arg0, 0x5E, 0x3FE66666, 3, 0); }

/* extern */

void func_80800BBC_bssnowball(BtIntPtr arg0) {
    s32 _baspin_entrypoint_3(BtIntPtr);
    s32 bs_setState(BtIntPtr, s32);
    s32 sp1C;

    sp1C = 0;
    bssnowball_entrypoint_2(arg0);
    if (_baspin_entrypoint_3(arg0) == 2) {
        sp1C = 0x17D;
    }
    bs_setState(arg0, sp1C);
}

BsScript bssnowball_entrypoint_8(BsScriptType arg0) {
    extern BtIntPtr D_808010A4_bssnowball[];
    return (BsScript)D_808010A4_bssnowball[arg0];
}

void func_80800C18_bssnowball(BtIntPtr arg0)
{
    _babounce_entrypoint_3(BT_NATIVE_ONLY((struct player_state_s *)arg0));
    bssnowball_entrypoint_0(arg0);
}
/* extern */

void func_80800C40_bssnowball(struct player_state_s *arg0) {
    void _babounce_entrypoint_4(struct player_state_s *, s32);
    void _babounce_entrypoint_5(struct player_state_s *, s32, f32);
    struct anctrl_s *baanim_getAnimCtrlPtr(struct player_state_s *);
    void func_8008B10C(struct anctrl_s *, f32);
    bssnowball_entrypoint_1(arg0);
    _babounce_entrypoint_4(arg0, 2);
    _babounce_entrypoint_5(arg0, 0x5E, 0.5128f);
    func_8008B10C(baanim_getAnimCtrlPtr(arg0), 0.1026f);
}

/* extern */

void func_80800C98_bssnowball(BtIntPtr arg0) {
    BT_IDO_ONLY(s32 _babounce_entrypoint_2();)
    s32 _babounce_entrypoint_9(BtIntPtr);
    s32 bs_setState(BtIntPtr, s32);
    void func_80800064_bssnowball(struct player_state_s *, s32);
    s32 sp1C;

    sp1C = 0;
    if (_babounce_entrypoint_2(BT_NATIVE_ONLY((struct player_state_s *)arg0)) != 0) {
        func_80800064_bssnowball(arg0, 0);
    }
    if (_babounce_entrypoint_9(arg0) != 0) {
        sp1C = 0x17D;
    }
    bs_setState(arg0, sp1C);
}

BsScript bssnowball_entrypoint_9(BsScriptType arg0) {
    extern BtIntPtr D_808010B4_bssnowball[];
    return (BsScript)D_808010B4_bssnowball[arg0];
}

void func_80800D00_bssnowball(BtIntPtr arg0)
{
    _bsrest_entrypoint_14(BT_NATIVE_ONLY((struct player_state_s *)arg0));
    bssnowball_entrypoint_0(arg0);
}
void func_80800D28_bssnowball(BtIntPtr arg0)
{
    bssnowball_entrypoint_1(arg0);
    _bsrest_entrypoint_16(arg0);
}
/* extern */

void func_80800D50_bssnowball(BtIntPtr arg0) {
    s32 _bsrest_entrypoint_13(BtIntPtr);
    BT_IDO_ONLY(s32 _bsrest_entrypoint_20();)
    s32 bs_setState(BtIntPtr, s32);
    s32 sp1C;

    sp1C = 0;
    if (_bsrest_entrypoint_20(BT_NATIVE_ONLY((struct player_state_s *)arg0)) != 0) {
        sp1C = _bsrest_entrypoint_13(arg0);
    }
    bssnowball_entrypoint_2(arg0);
    bs_setState(arg0, sp1C);
}

BsScript bssnowball_entrypoint_10(BsScriptType arg0) {
    extern BtIntPtr D_808010C4_bssnowball[];
    return (BsScript)D_808010C4_bssnowball[arg0];
}

void func_80800DB0_bssnowball(BT_NATIVE_ONLY(struct player_state_s *) BT_IDO_ONLY(BtIntPtr) arg0)
{
    func_80090A2C(BT_NATIVE_ONLY(arg0));
    bssnowball_entrypoint_0(arg0);
}
void func_80800DD8_bssnowball(BtIntPtr arg0) {
    void func_8009FFD8();
    void baanim_playForDuration_loopSmooth(PlayerState *, s32, f32);
    void baphysics_set_target_horizontal_velocity(struct player_state_s *, f32);
    void func_800909CC(struct player_state_s *);
    bssnowball_entrypoint_1(arg0);
    baanim_playForDuration_loopSmooth(arg0, 0x5E, 1.2f);
    func_8009FFD8(arg0, 1, 3, 1, 2);
    func_80800164_bssnowball(arg0);
    baphysics_set_target_horizontal_velocity(arg0, 0.0f);
    func_800909CC(arg0);
}

void func_80800E4C_bssnowball(PlayerState *arg0) {
    f32 baphysics_get_target_horizontal_velocity(PlayerState *);
    s32 bs_setState(BtIntPtr, s32);
    int func_8008DD04(PlayerState *);
    void func_8009D3A8(PlayerState *, s32);
    s32 func_800A02DC(PlayerState *, s32);
    s32 var_s1;

    var_s1 = 0;
    func_80800064_bssnowball(arg0, 1);
    func_8009D3A8(arg0, 0);
    if (func_8008DD04(arg0) != 0) {
        var_s1 = 0x180;
    }
    if (baphysics_get_target_horizontal_velocity(arg0) > 0.0f) {
        var_s1 = 0x17E;
    }
    var_s1 = func_8080010C_bssnowball(arg0, var_s1);
    var_s1 = func_800A02DC(arg0, var_s1);
    bssnowball_entrypoint_2(arg0);
    bs_setState(arg0, var_s1);
}

BsScript bssnowball_entrypoint_11(BsScriptType arg0) {
    extern BtIntPtr D_808010D4_bssnowball[];
    return (BsScript)D_808010D4_bssnowball[arg0];
}
/* data_to_c.py: from asm/data/overlays/bs/snowball.data.s */
void _basudie_entrypoint_11();
void _bsdrone_entrypoint_3();
void func_80099AA8();
s32 D_80800F30_bssnowball [21] BT_DATA(4, overlays_bs_snowball, 0x0) = { 1902947, 1441794, 1376256, 16580638, 1966110, 3080100, 800, -6028953, 52428827, -98239964, 197655, 917504008, 15073561, 262323, 458767, 2819328, 83886118, 58982600, 900, 13107200, 0 };
s32 D_80800F84_bssnowball [41] BT_DATA(4, overlays_bs_snowball, 0x54) = { 1902944, 1441794, 720926, 3276880, 1966101, 179, 1833508, -98303996, 10027015, 393259, 58721228, 2555404, -32702964, 32768500, 32768046, -3932160, 13172696, 23527824, 2228864, 45286016, 41944090, 3080122, 400, -3931801, 29491234, 25166259, 25166208, 102367278, -5570560, 45940661, 23528274, 2228480, 20119808, 16781338, 3080107, 800, -1310361, 72089634, 10027264, 13369548, 404357120 };
s32 D_80801028_bssnowball [11] BT_DATA(4, overlays_bs_snowball, 0xF8) = { 1903062, 1376256, 4980758, 268435486, 1966110, 1638400, 34, 16777472, 67109888, 2818176, 8388608 };
BtIntPtr D_80801054_bssnowball [4] BT_DATA(4, overlays_bs_snowball, 0x124) = { (BtIntPtr)func_808003B0_bssnowball, (BtIntPtr)func_808003D8_bssnowball, (BtIntPtr)func_808004AC_bssnowball, (BtIntPtr)_basudie_entrypoint_11 };
BtIntPtr D_80801064_bssnowball [4] BT_DATA(4, overlays_bs_snowball, 0x134) = { (BtIntPtr)func_808004E0_bssnowball, (BtIntPtr)func_80800508_bssnowball, (BtIntPtr)func_80800530_bssnowball, (BtIntPtr)_bsdrone_entrypoint_3 };
BtIntPtr D_80801074_bssnowball [4] BT_DATA(4, overlays_bs_snowball, 0x144) = { (BtIntPtr)func_8080056C_bssnowball, (BtIntPtr)func_808005A4_bssnowball, (BtIntPtr)func_80800614_bssnowball, (BtIntPtr)func_808008F0_bssnowball };
BtIntPtr D_80801084_bssnowball [4] BT_DATA(4, overlays_bs_snowball, 0x154) = { (BtIntPtr)func_8080089C_bssnowball, (BtIntPtr)func_808006BC_bssnowball, (BtIntPtr)func_808007D8_bssnowball, (BtIntPtr)func_808008F0_bssnowball };
BtIntPtr D_80801094_bssnowball [4] BT_DATA(4, overlays_bs_snowball, 0x164) = { (BtIntPtr)func_80800910_bssnowball, (BtIntPtr)func_80800930_bssnowball, (BtIntPtr)func_808009B0_bssnowball, (BtIntPtr)func_808008F0_bssnowball };
BtIntPtr D_808010A4_bssnowball [4] BT_DATA(4, overlays_bs_snowball, 0x174) = { (BtIntPtr)func_80800B44_bssnowball, (BtIntPtr)func_80800B70_bssnowball, (BtIntPtr)func_80800BBC_bssnowball, (BtIntPtr)func_80099AA8 };
BtIntPtr D_808010B4_bssnowball [4] BT_DATA(4, overlays_bs_snowball, 0x184) = { (BtIntPtr)func_80800C18_bssnowball, (BtIntPtr)func_80800C40_bssnowball, (BtIntPtr)func_80800C98_bssnowball, (BtIntPtr)func_808008F0_bssnowball };
BtIntPtr D_808010C4_bssnowball [4] BT_DATA(4, overlays_bs_snowball, 0x194) = { (BtIntPtr)func_80800D00_bssnowball, (BtIntPtr)func_80800D28_bssnowball, (BtIntPtr)func_80800D50_bssnowball, (BtIntPtr)func_808008F0_bssnowball };
BtIntPtr D_808010D4_bssnowball [7] BT_DATA(4, overlays_bs_snowball, 0x1A4) = { (BtIntPtr)func_80800DB0_bssnowball, (BtIntPtr)func_80800DD8_bssnowball, (BtIntPtr)func_80800E4C_bssnowball, (BtIntPtr)func_808008F0_bssnowball, 0, 0, 0 };
