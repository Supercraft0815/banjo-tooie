#include "bs_script.h"
#include "common.h"
#ifdef BT_NATIVE
#include "overlays/ba/yaw.h" // enums for the prototypes below
#include "overlays/ba/physics.h"
#endif
#ifdef BT_NATIVE // complete the enum forward declarations below
#include "overlays/ba/assets.h"
#include "overlays/ba/anim.h"
#endif
struct anctrl_s;
enum asset_e;
struct player_state_s;
BT_NATIVE_ONLY(struct player_state_s; void baphysics_reset_gravity(struct player_state_s *);)
void func_80800000_bstaxi(struct player_state_s *arg0) {
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
    baphysics_set_target_horizontal_velocity(arg0, func_800F1214(sp1C, 30.0f, 200.0f));
}

/* extern */

s32 func_80800064_bstaxi(struct player_state_s *arg0, s32 arg1) {
    int bakey_pressed(struct player_state_s *, int);
    int bakey_released(struct player_state_s *, int);
    if (bakey_released(arg0, 1) != 0) {
        arg1 = 0x127;
    }
    if (bakey_pressed(arg0, 9) != 0) {
        arg1 = 0x124;
    }
    if (bakey_pressed(arg0, 8) != 0) {
        arg1 = 0x126;
    }
    return arg1;
}

void bstaxi_entrypoint_0(struct player_state_s *arg0) {
    typedef struct player_state_s PlayerState;
    void _babackpack_set_state(void *, s32);
    void baroll_setIdeal(PlayerState *, f32);
    void bastick_popZone(PlayerState *);
    void func_8009BF5C(PlayerState *, f32);
    void func_8009E474(PlayerState *);
    s32 func_8009E74C(PlayerState *, s32);
    void func_800A0CD0(void *, s32);
    if (func_8009E74C(arg0, 0xE) == 0) {
        func_800A0CD0(arg0, 1);
        _babackpack_set_state(arg0, 1);
        func_8009BF5C(arg0, 0.0f);
        baroll_setIdeal(arg0, 0.0f);
        bastick_popZone(arg0);
        func_8009E474(arg0);
    }
}

/* extern */

void bstaxi_entrypoint_1(void *arg0) {
    typedef struct player_state_s PlayerState;
    s32 func_8009E77C(PlayerState *, s32);
    void func_8009E4AC(PlayerState *);
    void bastick_pushZone(PlayerState *);
    void bastick_setZoneMax(PlayerState *, s32, f32);
    if (func_8009E77C(arg0, 0xE) == 0) {
        bastick_pushZone(arg0);
        bastick_setZoneMax(arg0, 0, 0.12f);
        bastick_setZoneMax(arg0, 1, 1.0f);
        func_8009E4AC(arg0);
    }
}    typedef struct { u8 pad0[0x15C]; u8 unk15C; u8 unk15D; u8 pad15E[0x2]; BtIntPtr unk160; u8 pad164[0x8]; f32 unk16C; } Objtaxi_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

void bstaxi_entrypoint_2(void *arg0) {
    ((Objtaxi_arg0 *)arg0)->unk160 = 0;
    bstaxi_entrypoint_0(arg0);
}

/* extern */

struct player_state_s;
enum baanim_update_type_e;
enum yaw_type_e;
enum ba_physics_type_e;
void func_8009FFD8(struct player_state_s *, enum baanim_update_type_e, enum yaw_type_e, s32, enum ba_physics_type_e);

void bstaxi_entrypoint_3(void *arg0) {
#ifndef BT_NATIVE
    BT_IDO_ONLY(s32 baanim_playForDuration_onceSmooth(void *, s32, s32);)
#endif
    void bainput_enable(void *self, s32 id, s32 value);
    void baphysics_set_target_horizontal_velocity(struct player_state_s *, f32);
    bstaxi_entrypoint_1(arg0);
    baanim_playForDuration_onceSmooth(arg0, 0x129, BT_IDO_ONLY(0x40A00000) BT_NATIVE_ONLY(5.0f));
    func_8009FFD8(arg0, 1, 1, 3, 2);
    baphysics_set_target_horizontal_velocity(arg0, 0.0f);
    bainput_enable(arg0, 0, 0);
}

void bstaxi_entrypoint_4(struct player_state_s *arg0) {
    void _babackpack_entrypoint_6(void *self, BtIntPtr arg1, s32 arg2);
    void _babackpack_set_state(void *, s32);
    s32 _bapackctrl_entrypoint_1(void *);
    void _bapackctrl_entrypoint_4(void *, s32);
    f32 baanim_getTimer(struct player_state_s *);
#ifndef BT_NATIVE
    s32 baanim_isAt(void *, f32);
#endif
#ifndef BT_NATIVE
    s32 baanim_isStopped(void *);
#endif
    void bainput_enable(void *self, s32 id, s32 value);
    s32 bastick_getZone(struct player_state_s *);
    void bs_setState(void *self, s32 nextState);
    void func_8009D3A8(void *, s32);
    s32 func_8009D454(struct player_state_s *, volatile u8, s32 *);
    void func_8009DB04(struct player_state_s *, s32, f32, s32);
    void func_800A0CD0(void *, s32);
    void func_800CB598(s32, f32 *, f32);
    f32 yaw_get(struct player_state_s *);
    extern s32 D_808020D0_bstaxi[];
    extern s32 D_808020F0_bstaxi[];
    extern s32 D_80802110_bstaxi[];
    s32 next_state;
    f32 position[3];
    s32 pack;

    next_state = 0;
    bainput_enable(arg0, 0, 1);
    func_8009D3A8(arg0, 0);
    if (baanim_isAt(arg0, 0.0161f)) {
        _babackpack_set_state(arg0, 3);
        func_800A0CD0(arg0, 0);
    }
    if (baanim_isAt(arg0, 0.33f)) {
        func_8009D454(arg0, 0, D_808020D0_bstaxi);
    }
    if (baanim_isAt(arg0, 0.435f)) {
        func_8009D454(arg0, 0, D_808020F0_bstaxi);
    }
    if (baanim_isAt(arg0, 0.545f)) {
        func_8009D454(arg0, 0, D_80802110_bstaxi);
    }
    if (baanim_isAt(arg0, 0.5662f)) {
        _babackpack_entrypoint_6(arg0, position, 0);
        pack = _bapackctrl_entrypoint_1(arg0);
        _bapackctrl_entrypoint_4(arg0, 0);
        func_8009DB04(arg0, 0x5C2, 1.8f, 0x7FFF);
        func_800CB598(pack, position, yaw_get(arg0));
    }
    if (baanim_isAt(arg0, 0.8153f)) {
        _babackpack_set_state(arg0, 1);
        func_800A0CD0(arg0, 1);
    }
    if (baanim_isStopped(arg0)) {
        next_state = 1;
    }
    if (baanim_getTimer(arg0) > 0.8153f && bastick_getZone(arg0) > 0) {
        next_state = 2;
    }
    bs_setState(arg0, next_state);
}

BsScript bstaxi_entrypoint_5(BsScriptType arg0) {
    extern BtIntPtr D_80802130_bstaxi[];
    return (BsScript)D_80802130_bstaxi[arg0];
}

s32 func_80800420_bstaxi(struct player_state_s *arg0) {
    s32 _bapackctrl_entrypoint_1(void *);
    void _bapackctrl_entrypoint_4(void *, s32);
    void func_8009C128(struct player_state_s *, f32[3]);
    void func_8009DB04(struct player_state_s *, s32, f32, s32);
    void func_800CB598(s32, f32 *, f32);
    f32 yaw_get(struct player_state_s *);
    f32 position[3];
    s32 pack;

    func_8009C128(arg0, position);
    position[1] += 50.0f;
    pack = _bapackctrl_entrypoint_1(arg0);
    _bapackctrl_entrypoint_4(arg0, 0);
    func_8009DB04(arg0, 0x5C2, 1.8f, 0x7FFF);
    func_800CB598(pack, position, yaw_get(arg0)); BT_NATIVE_ONLY(return pack;)
}

/* extern */

void func_808004A8_bstaxi(struct player_state_s *arg0) {
    void func_80099B94(void *arg0);
    s32 func_8009E6EC(BT_NATIVE_ONLY(struct player_state_s *));
    s32 func_80800420_bstaxi(struct player_state_s *);
    s32 temp_v0;

    temp_v0 = func_8009E6EC(BT_NATIVE_ONLY(arg0));
    switch (temp_v0) {
    case 0x1F:
    case 0x20:
    case 0x21:
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
        func_80800420_bstaxi(arg0);
        func_80099B94(arg0);
        return;
    case 0x15:
    case 0x1C:
    case 0x1D:
    case 0x1E:
    case 0x25:
    case 0x43:
        func_80800420_bstaxi(arg0);
        func_80099B94(arg0);
        return;
    default:
        func_80099B94(arg0);
        return;
    }
}

void func_80800524_bstaxi(struct player_state_s *arg0) {
    void _bamovehover_entrypoint_4(u8 *arg0, BtIntPtr arg1);
    f32 bastick_distance(struct player_state_s *);
    f32 bastick_getAngleRelativeToBanjo(struct player_state_s *);
    void func_800EEB9C(f32[3], f32, f32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    f32 distance;
    union {
        struct {
            f32 velocity[3];
            f32 angle;
        } values;
        f64 alignment;
    } movement;

    distance = bastick_distance(arg0);
    if (distance == 0.0f) {
        _bamovehover_entrypoint_4(arg0, NULL);
        return;
    }
    movement.values.angle = bastick_getAngleRelativeToBanjo(arg0);
    distance = func_800F10B4(distance, 0.0f, 1.0f, 0.0f, 400.0f);
    func_800EEB9C(movement.values.velocity, movement.values.angle, distance);
    _bamovehover_entrypoint_4(arg0, movement.values.velocity);
}

/* extern */

void func_808005B8_bstaxi(struct player_state_s *arg0) {
    void baroll_setIdeal(struct player_state_s *, f32);
    void func_8009BF5C(struct player_state_s *, f32);
    baroll_setIdeal(arg0, 0.0f);
    func_8009BF5C(arg0, 0.0f);
    bstaxi_entrypoint_0(arg0);
}

/* extern */

void func_808005F0_bstaxi(void *arg0) {
    typedef struct player_state_s PlayerState;
    typedef struct anctrl_s AnimCtrl;
    enum asset_e;
    void _bamovehover_entrypoint_3(PlayerState *, f32[3]);
    void _batimer_set(PlayerState *, s32, f32);
    void anctrl_reset(AnimCtrl *);
    void anctrl_setDuration(AnimCtrl *, f32);
#ifndef BT_NATIVE
    void anctrl_setIndex(AnimCtrl *, enum asset_e);
#endif
    void anctrl_setPlaybackType(AnimCtrl *, s32);
    void anctrl_start(AnimCtrl *);
    AnimCtrl *baanim_getAnimCtrlPtr(PlayerState *);
    void func_8008B1C8(AnimCtrl *, f32);
    f32 func_80096364(PlayerState *);
    void func_8009C128(PlayerState *, f32[3]);
    void yaw_setVelocityBounded(PlayerState *, f32, f32);
    f32 height;
    f32 position[3];
    AnimCtrl *animCtrl;

    bstaxi_entrypoint_1(arg0);
    _batimer_set(arg0, 0, ((Objtaxi_arg0 *)arg0)->unk16C);
    animCtrl = baanim_getAnimCtrlPtr(arg0);
    anctrl_reset(animCtrl);
    anctrl_setIndex(animCtrl, 0x24A);
    anctrl_setDuration(animCtrl, 3.0f);
    func_8008B1C8(animCtrl, 0.6f);
    anctrl_setPlaybackType(animCtrl, 2);
    anctrl_start(animCtrl);
    func_8009FFD8(arg0, 1, 3, 1, 0x13);
    yaw_setVelocityBounded(arg0, 300.0f, 3.5f);
    func_8009C128(arg0, position);
    height = func_80096364(arg0) + 200.0f;
    if (height < position[1]) {
        height = position[1] + 200.0f;
    }
    position[1] = height;
    _bamovehover_entrypoint_3(arg0, position);
}

void func_808006F4_bstaxi(struct player_state_s *arg0) {
    int _batimer_decrement(struct player_state_s *, s32);
    f32 _batimer_get(struct player_state_s *, s32);
    int _batimer_isZero(struct player_state_s *, s32);
    int bakey_pressed(struct player_state_s *, int);
    void bs_setState(void *self, s32 nextState);
    s32 func_8001210C(s32);
    BtIntPtr func_800B5BE4(s32);
    void func_800BA22C(BtIntPtr, s32);
    BtIntPtr func_800BABB8(BtIntPtr, f32[3], f32[3], f32, s32[]);
    s32 func_800D2498(u32 itemDisplayUI, s32 value, u32 a2);
    void func_800F3BB0(struct player_state_s *, f32[3]);
    s32 func_80800420_bstaxi(struct player_state_s *);
    void func_80800524_bstaxi(struct player_state_s *);
    extern s32 D_80802140_bstaxi[];
    s32 sp44;
    s32 sp40;
    BtIntPtr sp3C;
    f32 sp30[3];

    sp44 = 0;
    sp40 = 0;
    _batimer_decrement(arg0, 0);
    func_800D2498(0x100, (s32) _batimer_get(arg0, 0), 0);
    func_80800524_bstaxi(arg0);
    if (func_8001210C(1) != 0) {
        sp3C = func_800B5BE4(0x1C);
        func_800F3BB0(arg0, sp30);
        func_800BABB8(sp3C, sp30, sp30, 1.0f, D_80802140_bstaxi);
        func_800BA22C(sp3C, 1);
    }
    if (_batimer_isZero(arg0, 0) != 0) {
        sp40 = 1;
        sp44 = 0x2F;
    } else if (bakey_pressed(arg0, 9) != 0) {
        sp40 = 1;
        sp44 = 0x2F;
    }
    if (sp40 != 0) {
        func_80800420_bstaxi(arg0);
    }
    bs_setState(arg0, sp44);
}

BsScript bstaxi_entrypoint_6(BsScriptType arg0) {
    extern BtIntPtr D_80802188_bstaxi[];
    return (BsScript)D_80802188_bstaxi[arg0];
}

void bstaxi_entrypoint_7(struct player_state_s *arg0)
{
    bstaxi_entrypoint_0(arg0);
}

void bstaxi_entrypoint_8(void *arg0) {
#ifndef BT_NATIVE
    BT_IDO_ONLY(s32 baanim_playForDuration_onceSmooth(void *, s32, s32);)
#endif
    void bainput_enable(void *self, s32 id, s32 value);
    void baphysics_set_target_horizontal_velocity(struct player_state_s *, f32);
    bstaxi_entrypoint_1(arg0);
    baanim_playForDuration_onceSmooth(arg0, 0xF3, BT_IDO_ONLY(0x3F8CCCCD) BT_NATIVE_ONLY(1.1f));
    func_8009FFD8(arg0, 1, 1, 3, 2);
    baphysics_set_target_horizontal_velocity(arg0, 0.0f);
    bainput_enable(arg0, 0, 0);
}

void bstaxi_entrypoint_9(struct player_state_s *arg0) {
    void _babackpack_set_state(void *, s32);
    f32 baanim_getTimer(struct player_state_s *);
#ifndef BT_NATIVE
    s32 baanim_isAt(void *, f32);
#endif
#ifndef BT_NATIVE
    s32 baanim_isStopped(void *);
#endif
    void bainput_enable(void *self, s32 id, s32 value);
    int bakey_pressed(struct player_state_s *, int);
    int bakey_released(struct player_state_s *, int);
    s32 bastick_getZone(struct player_state_s *);
    void bs_setState(void *self, s32 nextState);
    void func_8009D3A8(void *, s32);
    void func_8009DEC0(struct player_state_s *, s32, f32, f32, s32, s32);
    void func_800A0CD0(void *, s32);
    s32 sp2C;
    f32 sp28;

    sp2C = 0;
    bainput_enable(arg0, 0, 1);
    if (baanim_isAt(arg0, 0.3f) != 0) {
        func_8009DEC0(arg0, 0x588, 0.95f, 1.05f, 0x4E20, 0x55F0);
    }
    func_8009D3A8(arg0, 0);
    if (baanim_isAt(arg0, 0.084f) != 0) {
        _babackpack_set_state(arg0, 3);
        func_800A0CD0(arg0, 0);
    }
    if (baanim_isStopped(arg0) != 0) {
        sp2C = 0x125;
    }
    sp28 = baanim_getTimer(arg0);
    if (sp28 > 0.6723f) {
        if (bastick_getZone(arg0) > 0) {
            sp2C = 0x123;
        }
        if (bakey_released(arg0, 1) != 0) {
            sp2C = 0x127;
        }
    }
    if ((sp28 > 0.2f) && (bakey_pressed(arg0, 9) != 0)) {
        sp2C = 0x124;
    }
    bs_setState(arg0, sp2C);
}

BsScript bstaxi_entrypoint_10(BsScriptType arg0) {
    extern BtIntPtr D_80802198_bstaxi[];
    return (BsScript)D_80802198_bstaxi[arg0];
}

/* extern */

void func_80800A18_bstaxi(void *arg0, u32 arg1) {
    void _bapackctrl_entrypoint_5(BtIntPtr arg0, s32 arg1);
#ifndef BT_NATIVE
    BT_IDO_ONLY(s32 baanim_playForDuration_loopSmooth(void *, s32, s32);)
#endif
#ifndef BT_NATIVE
    BT_IDO_ONLY(s32 baanim_playForDuration_onceSmooth(void *, s32, s32);)
#endif
    void bainput_enable(void *self, s32 id, s32 value);
    switch (arg1) {
    case 0:
        if ((((Objtaxi_arg0 *)arg0)->unk15C) == 3) {
            _bapackctrl_entrypoint_5(arg0, 2);
        }
        break;
    case 1:
        (*(s8 *)((s8 *)(arg0) + (0x15D))) = 0;
        baanim_playForDuration_onceSmooth(arg0, 0x121, BT_IDO_ONLY(0x3F8CCCCD) BT_NATIVE_ONLY(1.1f));
        bainput_enable(arg0, 0, 0);
        break;
    case 2:
        baanim_playForDuration_loopSmooth(arg0, 0x12B, BT_IDO_ONLY(0x40900000) BT_NATIVE_ONLY(4.5f));
        break;
    case 3:
        baanim_playForDuration_onceSmooth(arg0, 0x12D, BT_IDO_ONLY(0x40333333) BT_NATIVE_ONLY(2.8f));
        break;
    case 4:
        baanim_playForDuration_onceSmooth(arg0, 0x12C, BT_IDO_ONLY(0x3FB33333) BT_NATIVE_ONLY(1.4f));
        break;
    }
    (((Objtaxi_arg0 *)arg0)->unk15C) = (u8) arg1;
}

void bstaxi_entrypoint_11(BtIntPtr arg0)
{
    func_80800A18_bstaxi(arg0,0);
    bstaxi_entrypoint_0(arg0);
}

/* extern */

void bstaxi_entrypoint_12(void *arg0) {
    void baphysics_set_target_horizontal_velocity(struct player_state_s *, f32);
    bstaxi_entrypoint_1(arg0);
    func_8009FFD8(arg0, 1, 1, 3, 2);
    baphysics_set_target_horizontal_velocity(arg0, 0.0f);
    func_80800A18_bstaxi(arg0, 1U);
}

void bstaxi_entrypoint_13(void *arg0) {
    typedef struct player_state_s PlayerState;
    void _babackpack_entrypoint_6(void *self, BtIntPtr arg1, s32 arg2);
    void _babackpack_set_state(void *, s32);
    s32 _bapackctrl_entrypoint_1(void *);
    void _bapackctrl_entrypoint_4(void *, s32);
    f32 baanim_getTimer(struct player_state_s *);
#ifndef BT_NATIVE
    s32 baanim_isAt(void *, f32);
#endif
#ifndef BT_NATIVE
    s32 baanim_isStopped(void *);
#endif
    void bainput_enable(void *self, s32 id, s32 value);
    int bakey_pressed(struct player_state_s *, int);
    int bakey_released(PlayerState *, int);
    void func_8009C128(PlayerState *, f32 *);
    void func_8009D3A8(void *, s32);
    void func_8009DEC0(PlayerState *, s32, f32, f32, s32, s32);
    void func_800A0CD0(void *, s32);
    void *func_800C6C94(f32 *, f32, f32 *, u32);
    void func_800CB5D4(s32, f32 *, f32);
    void func_800EF1B8(f32 *, f32, f32);
    void func_800FC6B0(u32);
    f32 yaw_get(struct player_state_s *);
    void bs_setState(void *self, s32 nextState);
    s32 sp5C;
    f32 sp58;
    f32 sp4C[3];
    f32 sp40[3];
    f32 sp34[3];
    s32 sp30;

    sp5C = 0;
    sp58 = baanim_getTimer(arg0);
    func_8009D3A8(arg0, 0);
    switch (((Objtaxi_arg0 *)arg0)->unk15C) {
    case 1:
        bainput_enable(arg0, 0, 1);
        if (baanim_isAt(arg0, 0.084f)) {
            _babackpack_set_state(arg0, 3);
            func_800A0CD0(arg0, 0);
        }
        if (bakey_pressed(arg0, 9)) {
            ((Objtaxi_arg0 *)arg0)->unk15D = 1;
        }
        if ((sp58 > 0.3883f && ((Objtaxi_arg0 *)arg0)->unk15D) || baanim_isStopped(arg0)) {
            func_80800A18_bstaxi(arg0, 2U);
        }
        break;
    case 2:
        if (bakey_pressed(arg0, 9) || ((Objtaxi_arg0 *)arg0)->unk15D) {
            ((Objtaxi_arg0 *)arg0)->unk15D = 0;
            func_8009C128(arg0, sp4C);
            func_800EF1B8(sp4C, yaw_get(arg0), 45.0f);
            sp4C[1] += 80.0f;
            if (func_800C6C94(sp4C, 40.0f, sp40, 0x420020)) {
                func_800FC6B0(0xF);
            } else {
                func_80800A18_bstaxi(arg0, 3U);
            }
        }
        if (bakey_released(arg0, 1)) {
            func_80800A18_bstaxi(arg0, 4U);
        }
        break;
    case 3:
        if (baanim_isAt(arg0, 0.16f)) {
            _babackpack_entrypoint_6(arg0, sp34, 0);
            sp30 = _bapackctrl_entrypoint_1(arg0);
            _bapackctrl_entrypoint_4(arg0, 0);
            func_8009DEC0(arg0, 0x53C, 0.95f, 1.05f, 0x6978, 0x6D60);
            func_800CB5D4(sp30, sp34, yaw_get(arg0));
        }
        if (baanim_isAt(arg0, 0.6511f)) {
            _babackpack_set_state(arg0, 1);
            func_800A0CD0(arg0, 1);
        }
        if (sp58 > 0.6511f) {
            sp5C = 0x20;
        }
        break;
    case 4:
        if (baanim_isAt(arg0, 0.48f)) {
            func_8009DEC0(arg0, 0x584, 0.95f, 1.05f, 0x55F0, 0x55F0);
        }
        if (baanim_isAt(arg0, 0.5053f)) {
            _babackpack_set_state(arg0, 1);
            func_800A0CD0(arg0, 1);
        }
        if (sp58 > 0.5053f) {
            sp5C = 0x20;
        }
        break;
    }
    bs_setState(arg0, sp5C);
}

BsScript bstaxi_entrypoint_14(BsScriptType arg0) {
    extern BtIntPtr D_808021A8_bstaxi[];
    return (BsScript)D_808021A8_bstaxi[arg0];
}

void bstaxi_entrypoint_15(struct player_state_s *arg0) {
    void anctrl_reset(struct anctrl_s *);
    void anctrl_setDuration(struct anctrl_s *, f32);
#ifndef BT_NATIVE
    void anctrl_setIndex(struct anctrl_s *, enum asset_e);
#endif
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
    void func_8009D7A4(struct player_state_s *, f32, f32);
    f32 yaw_getIdeal(struct player_state_s *);
    void yaw_setIdeal(struct player_state_s *, f32);
    s32 pad[2];
    f32 sp2C;
    struct anctrl_s *control;

    bstaxi_entrypoint_1(arg0);
    control = baanim_getAnimCtrlPtr(arg0);
    anctrl_reset(control);
    anctrl_setSmoothTransition(control, 0);
    anctrl_setIndex(control, 0x125);
    anctrl_setStart(control, 0.1522f);
    anctrl_setSubrange(control, 0.0f, 0.3824f);
    anctrl_setDuration(control, 1.0f);
    anctrl_setPlaybackType(control, 1);
    anctrl_start(control);
    func_8009FFD8(arg0, 1, 1, 3, 6);
    if (bastick_distance(arg0) != 0.0f) {
        yaw_setIdeal(arg0, bastick_getAngleRelativeToBanjo(arg0));
    }
    baphysics_set_target_yaw(arg0, yaw_getIdeal(arg0));
    func_80800000_bstaxi(arg0);
    sp2C = yaw_getIdeal(arg0);
    baphysics_set_horizontal_velocity(arg0, sp2C, baphysics_get_target_horizontal_velocity(arg0));
    baphysics_set_vertical_velocity(arg0, 500.0f);
    baphysics_set_gravity(arg0, -1900.0f);
    func_8009D7A4(arg0, 0.91f, 1.09f);
    *(u8 *)((u8 *)arg0 + 0x15C) = 0;
}

void bstaxi_entrypoint_16(struct player_state_s *arg0) {
    struct anctrl_s *baanim_getAnimCtrlPtr(struct player_state_s *);
    s32 anctrl_isStopped(struct anctrl_s *);
    void baanim_setEndAndDuration(struct player_state_s *, f32, f32);
    int bakey_pressed(struct player_state_s *, int);
    int bakey_released(struct player_state_s *, int);
    int func_8008DF8C(struct player_state_s *, s32);
    void func_8009D2D8(struct player_state_s *, s32);
    void func_8009D3A8(void *, s32);
    int player_isStable(struct player_state_s *);
    void bs_setState(void *self, s32 nextState);
#ifndef BT_NATIVE
    void func_8009BB24(void *, f32 *);
#endif
    f32 func_8009BB5C(struct player_state_s *);
    void func_8009FE58(void *);
    f32 baphysics_get_vertical_velocity(struct player_state_s *);
    s32 player_inWater(struct player_state_s *);
    int func_8008E148(struct player_state_s *);
    s32 func_8008E260(struct player_state_s *);
    void baphysics_set_target_horizontal_velocity(struct player_state_s *, f32);
    s32 sp3C;
    struct anctrl_s *sp38;
    f32 sp2C[3];

    sp3C = 0;
    sp38 = baanim_getAnimCtrlPtr(arg0);
    func_80800000_bstaxi(arg0);
    func_8009BB24(arg0, sp2C);
    if (bakey_released(arg0, 8) && sp2C[1] > 0.0f) {
        baphysics_reset_gravity(arg0);
    }
    switch (*(u8 *)((u8 *)arg0 + 0x15C)) {
    case 0:
        if (func_8008DF8C(arg0, 0x82)) {
            baanim_setEndAndDuration(arg0,
                1.0f + 0.0f,
                0.7f);
            *(u8 *)((u8 *)arg0 + 0x15C) = 2;
        } else if (anctrl_isStopped(sp38)) {
            baanim_setEndAndDuration(arg0, 0.472f, 3.0f);
            *(u8 *)((u8 *)arg0 + 0x15C) = 1;
        }
        break;
    case 1:
        if (func_8008DF8C(arg0, 0x82)) {
            baanim_setEndAndDuration(arg0,
                1.0f + 0.0f,
                1.0f);
            *(u8 *)((u8 *)arg0 + 0x15C) = 2;
        }
        break;
    case 2:
        func_8009D3A8(arg0, 0);
        if (player_isStable(arg0)) {
            func_8009FE58(arg0);
            baanim_setEndAndDuration(arg0,
                1.0f + 0.0f,
                1.0f);
            *(u8 *)((u8 *)arg0 + 0x15C) = 3;
        }
        break;
    case 3:
        baphysics_set_target_horizontal_velocity(arg0, func_8009BB5C(arg0) * 0.25f);
        func_8009D2D8(arg0, 3);
        func_8009D3A8(arg0, 0);
        if (func_8009BB5C(arg0) > 0.0f) {
            sp3C = 0x123;
        } else if (anctrl_isStopped(sp38)) {
            sp3C = 0x125;
        }
        if (bakey_pressed(arg0, 9)) {
            sp3C = 0x124;
        }
        break;
    }
    if (baphysics_get_vertical_velocity(arg0) < 0.0f && player_inWater(arg0)) {
        sp3C = 0x4C;
    }
    if (player_isStable(arg0) && bakey_pressed(arg0, 8)) {
        sp3C = 0x126;
    }
    if (func_8008E148(arg0)) {
        sp3C = 1;
    }
    if (func_8008E260(arg0)) {
        sp3C = 0x3D;
    }
    bs_setState(arg0, sp3C);
}

void bstaxi_entrypoint_17(struct player_state_s *arg0) {
    void func_8009BF5C(struct player_state_s *, f32);
    void baroll_setIdeal(struct player_state_s *, f32);
#ifdef BT_NATIVE
    baphysics_reset_gravity(arg0);
#else
    baphysics_reset_gravity();
#endif
    func_8009BF5C(arg0, 0.0f);
    baroll_setIdeal(arg0, 0.0f);
    bstaxi_entrypoint_0(arg0);
}

BsScript bstaxi_entrypoint_18(BsScriptType arg0) {
    extern BtIntPtr D_808021B8_bstaxi[];
    return (BsScript)D_808021B8_bstaxi[arg0];
}

void bstaxi_entrypoint_19(struct player_state_s *arg0)
{
    bstaxi_entrypoint_0(arg0);
}

void bstaxi_entrypoint_20(struct player_state_s *arg0) {
#ifndef BT_NATIVE
    BT_IDO_ONLY(s32 baanim_playForDuration_loopSmooth(void *, s32, s32);)
#endif
    void baanim_setDurationRange(struct player_state_s *, f32, f32);
    void func_8008C9F0(struct player_state_s *, f32, f32, f32, f32);
    void func_8008CA30(struct player_state_s *, f32);

    bstaxi_entrypoint_1(arg0);
    baanim_playForDuration_loopSmooth(arg0, 0xF4, BT_IDO_ONLY(0x3F800000) BT_NATIVE_ONLY(1.0f));
    func_8009FFD8(arg0, 2, 1, 1, 2);
    baanim_setDurationRange(arg0, 0.3f, 1.5f);
    func_8008C9F0(arg0, 30.0f, 200.0f, 1.1f, 0.53f);
    func_8008CA30(arg0, 1.0f);
}

/* extern */

void bstaxi_entrypoint_21(struct player_state_s *arg0) {
    s32 bastick_getZone(struct player_state_s *);
    void bs_setState(void *self, s32 nextState);
    int func_8008E148(struct player_state_s *);
    s32 func_8008E260(struct player_state_s *);
    void func_8009D3A8(void *, s32);
    s32 func_800A02DC(struct player_state_s *, s32);
    void func_800A2CE8(struct player_state_s *, f32, s32);
    s32 player_inWater(struct player_state_s *);
    s32 var_s1;

    var_s1 = 0;
    func_8009D3A8(arg0, 0);
    func_800A2CE8(arg0, 0.1f, 4);
    func_800A2CE8(arg0, 0.6f, 3);
    func_80800000_bstaxi(arg0);
    if (bastick_getZone(arg0) == 0) {
        var_s1 = 0x125;
    }
    var_s1 = func_80800064_bstaxi(arg0, var_s1);
    if (func_8008E148(arg0) != 0) {
        var_s1 = 1;
    }
    if (func_8008E260(arg0) != 0) {
        var_s1 = 0x3D;
    }
    if (player_inWater(arg0) != 0) {
        var_s1 = 0x4C;
    }
    bs_setState(arg0, func_800A02DC(arg0, var_s1));
}

BsScript bstaxi_entrypoint_22(BsScriptType arg0) {
    extern BtIntPtr D_808021C8_bstaxi[];
    return (BsScript)D_808021C8_bstaxi[arg0];
}

void bstaxi_entrypoint_23(struct player_state_s *arg0)
{
    bstaxi_entrypoint_0(arg0);
}

void bstaxi_entrypoint_24(void *arg0) {
#ifndef BT_NATIVE
    BT_IDO_ONLY(s32 baanim_playForDuration_onceSmooth(void *, s32, s32);)
#endif
    void baphysics_set_target_horizontal_velocity(struct player_state_s *, f32);

    bstaxi_entrypoint_1(arg0);
    baanim_playForDuration_onceSmooth(arg0, 0x128, BT_IDO_ONLY(0x3FB33333) BT_NATIVE_ONLY(1.4f));
    func_8009FFD8(arg0, 1, 1, 3, 2);
    baphysics_set_target_horizontal_velocity(arg0, 0.0f);
}

/* extern */

void bstaxi_entrypoint_25(void *arg0) {
    void _babackpack_set_state(void *, s32);
    f32 baanim_getTimer(struct player_state_s *);
#ifndef BT_NATIVE
    s32 baanim_isAt(void *, f32);
#endif
    void bs_setState(void *self, s32 nextState);
    void func_8009D3A8(void *, s32);
    void func_8009DEC0(struct player_state_s *, s32, f32, f32, s32, s32);
    void func_800A0CD0(void *, s32);
    s32 sp2C;

    sp2C = 0;
    func_8009D3A8(arg0, 0);
    if (baanim_isAt(arg0, 0.5053f) != 0) {
        _babackpack_set_state(arg0, 1);
        func_800A0CD0(arg0, 1);
    }
    if (baanim_isAt(arg0, 0.48f) != 0) {
        func_8009DEC0(arg0, 0x584, 0.95f, 1.05f, 0x55F0, 0x55F0);
    }
    if (baanim_getTimer(arg0) > 0.5053f) {
        sp2C = 0x20;
    }
    bs_setState(arg0, sp2C);
}

BsScript bstaxi_entrypoint_26(BsScriptType arg0) {
    extern BtIntPtr D_808021D8_bstaxi[];
    return (BsScript)D_808021D8_bstaxi[arg0];
}

void func_80801600_bstaxi(void *arg0, u32 arg1) {
    void _babackpack_entrypoint_6(void *self, BtIntPtr arg1, s32 arg2);
    void _bapackctrl_entrypoint_4(void *, s32);
    void _bapackctrl_entrypoint_5(BtIntPtr arg0, s32 arg1);
    void _batimer_set(struct player_state_s *, s32, f32);
    void _subaddietaxi_entrypoint_7(Unk80132ED0 *arg0);
    BT_IDO_ONLY(s32 baanim_playForDuration_onceSmooth(void *, s32, s32);)
    void baflag_clear(void *self, s32 id);
    s32 func_8008E0C8(struct player_state_s *);
    void func_8009C128(struct player_state_s *, f32[3]);
    void func_8009DBB0(struct player_state_s *, s32, f32, f32, s32);
    void func_8009E4E0(void *, s32, BtIntPtr);
    void func_8009E55C(void *, s32, f32);
    s32 func_800CB698(s32, s32);
    void func_800FFA88(Unk80132ED0 *);
    f32 position[3];
    Unk80132ED0 *marker;

    switch (arg1) {
    case 0:
        if (func_8008E0C8(arg0) != 0) {
            _bapackctrl_entrypoint_5(arg0, 1);
        }
        baflag_clear(arg0, 0x33);
        func_8009E55C(arg0, 2, 0.0f);
        marker = *(Unk80132ED0 **)((u8 *)arg0 + 0x160);
        if (marker != NULL) {
            func_800FFA88(marker);
            *(Unk80132ED0 **)((u8 *)arg0 + 0x160) = NULL;
        }
        break;
    case 1:
        *(Unk80132ED0 **)((u8 *)arg0 + 0x160) = NULL;
        *(f32 *)((u8 *)arg0 + 0x16C) = 0.0f;
        func_8009E55C(arg0, 2, 50.0f);
        func_8009E4E0(arg0, 2, _babackpack_entrypoint_6);
        break;
    case 2:
        _bapackctrl_entrypoint_4(arg0, *((u8 *)arg0 + 0x164));
        baflag_clear(arg0, 0x33);
        _batimer_set(arg0, 0, 0.5f);
        func_8009C128(arg0, position);
        _subaddietaxi_entrypoint_7(*(s32 *)((u8 *)arg0 + 0x160));
        break;
    case 3:
        func_8009DBB0(arg0, 0x5AD, 0.9f, 1.1f, 0x3E80);
        break;
    case 4:
        func_800CB698(*((u8 *)arg0 + 0x164), 2);
        func_800FFA88(*(Unk80132ED0 **)((u8 *)arg0 + 0x160));
        *(Unk80132ED0 **)((u8 *)arg0 + 0x160) = NULL;
        break;
    case 5:
        baanim_playForDuration_onceSmooth(arg0, 0x126, BT_IDO_ONLY(0x40200000) BT_NATIVE_ONLY(2.5f));
        break;
    }
    *(s8 *)((u8 *)arg0 + 0x15C) = arg1;
}

void bstaxi_entrypoint_27(BtIntPtr arg0)
{
    func_80801600_bstaxi(arg0,0);
    bstaxi_entrypoint_0(arg0);
}

void bstaxi_entrypoint_28(void *arg0) {
    BT_IDO_ONLY(s32 baanim_playForDuration_onceSmooth(void *, s32, s32);)
    bstaxi_entrypoint_1(arg0);
    baanim_playForDuration_onceSmooth(arg0, 0xF5, BT_IDO_ONLY(0x3F333333) BT_NATIVE_ONLY(0.7f));
    func_8009FFD8(arg0, 1, 1, 3, 2);
    *(s8 *)((u8 *)arg0 + 0x15C) = 0;
    func_80801600_bstaxi(arg0, 1);
}

/* extern */

void bstaxi_entrypoint_29(struct player_state_s *arg0) {
    f32 func_80099A34(struct player_state_s *);
    BtIntPtr func_80099A4C(struct player_state_s *);
    s32 func_80099A58(void *self);
    void func_80099B94(void *arg0);
    s32 func_8009E6EC(BT_NATIVE_ONLY(struct player_state_s *));
    void func_8009E830(void *arg0, s32 arg1);
    s32 temp_v0;

    temp_v0 = func_8009E6EC(BT_NATIVE_ONLY(arg0));
    switch (temp_v0) {
    case 0x1F:
    case 0x20:
    case 0x21:
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
        if ((*(f32 *)((s8 *)(arg0) + (0x16C))) > 0.0f) {
            func_808004A8_bstaxi(arg0);
            return;
        }
        if ((*(s32 *)((s8 *)(arg0) + (0x160))) == 0) {
            func_80099B94(arg0);
            return;
        }
        return;
    case 0x15:
    case 0x1C:
    case 0x1D:
    case 0x1E:
    case 0x25:
    case 0x43:
        if ((*(f32 *)((s8 *)(arg0) + (0x16C))) > 0.0f) {
            func_808004A8_bstaxi(arg0);
            return;
        }
        break;
    case 0x48:
        if ((*(s32 *)((s8 *)(arg0) + (0x160))) != 0) {
            func_8009E830(arg0, 1);
            return;
        }
        (*(s32 *)((s8 *)(arg0) + (0x160))) = func_80099A4C(arg0);
        (*(s8 *)((s8 *)(arg0) + (0x164))) = func_80099A58(arg0);
        func_80801600_bstaxi(arg0, 2U);
        func_8009E830(arg0, 2);
        return;
    case 0x6E:
        (*(f32 *)((s8 *)(arg0) + (0x16C))) = func_80099A34(arg0);
        func_8009E830(arg0, 2);
        return;
    default:
        func_80099B94(arg0);
        break;
    }
}

void bstaxi_entrypoint_30(void *arg0) {
    void _babackpack_entrypoint_6(void *self, BtIntPtr arg1, s32 arg2);
    void _babackpack_set_state(void *, s32);
    s32 _bapackctrl_entrypoint_1(void *);
    void _bapackctrl_entrypoint_5(BtIntPtr arg0, s32 arg1);
    int _batimer_decrement(struct player_state_s *, s32);
    f32 _batimer_get(struct player_state_s *, s32);
    void _subaddietaxi_entrypoint_8(Unk80132ED0 *arg0, f32 *arg1, f32 arg2, f32 arg3, s32 arg4);
#ifndef BT_NATIVE
    s32 baanim_isAt(void *, f32);
#endif
#ifndef BT_NATIVE
    s32 baanim_isStopped(void *);
#endif
    void baflag_clear(void *self, s32 id);
    s32 baflag_isTrue(void *, s32);
    void baflag_set(void *self, s32 id);
    void baphysics_set_target_horizontal_velocity(struct player_state_s *, f32);
    void bs_setState(void *self, s32 nextState);
    void func_8009D3A8(void *, s32);
    void func_8009DC98(void *, s32, f32, f32);
    void func_8009DF18(void *, s32, f32, s32);
    void func_8009DFD4(void *, s32, f32, f32, s32, s32);
    void func_8009E55C(void *, s32, f32);
    void func_800A0CD0(void *, s32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    s32 next_state;
    f32 position[3];
    f32 progress;
    f32 scale;

    next_state = 0;
    func_8009D3A8(arg0, 0);
    switch (((Objtaxi_arg0 *)arg0)->unk15C) {
    case 1:
        func_80800000_bstaxi(arg0);
        if (baflag_isTrue(arg0, 0x33)) {
            baflag_clear(arg0, 0x33);
        }
        if (baanim_isAt(arg0, 0.2f)) {
            baflag_set(arg0, 0x33);
        }
        if (baanim_isAt(arg0, 0.35f)) {
            func_80801600_bstaxi(arg0, 3);
        }
        break;
    case 2:
        if (baanim_isAt(arg0, 0.44f)) {
            func_8009DC98(arg0, 0x5AC, 0.95f, 1.05f);
        }
        if (baanim_isAt(arg0, 0.64f)) {
            baphysics_set_target_horizontal_velocity(arg0, 0.0f);
        }
        _babackpack_entrypoint_6(arg0, position, 0);
        scale = func_800F10B4(_batimer_get(arg0, 0), 0.0f, 0.5f, 0.0f, 1.0f);
        progress = func_800F10B4(_batimer_get(arg0, 0), 0.19999999f, 0.5f, 0.0f, 1.0f);
        _subaddietaxi_entrypoint_8(((Objtaxi_arg0 *)arg0)->unk160, position, progress, scale, _bapackctrl_entrypoint_1(arg0));
        if (_batimer_decrement(arg0, 0)) {
            func_80801600_bstaxi(arg0, 4);
        }
        break;
    case 3:
        if (baanim_isAt(arg0, 0.64f)) {
            baphysics_set_target_horizontal_velocity(arg0, 0.0f);
        }
        if (baanim_isStopped(arg0)) {
            next_state = 0x125;
        }
        break;
    case 4:
        if (baanim_isStopped(arg0)) {
            func_80801600_bstaxi(arg0, 5);
        }
        break;
    case 5:
        if (baanim_isAt(arg0, 0.1f)) {
            func_8009DF18(arg0, 0x5AF, 1.0f, 0x6D60);
        }
        if (baanim_isAt(arg0, 0.3f)) {
            func_8009DF18(arg0, 0x5AF, 0.9f, 0x6D60);
        }
        if (baanim_isAt(arg0, 0.5f)) {
            func_8009DFD4(arg0, 0x5AE, 0.95f, 1.05f, 0x4E20, 0x55F0);
        }
        if (baanim_isAt(arg0, 0.707f)) {
            _babackpack_set_state(arg0, 1);
            func_800A0CD0(arg0, 1);
            _bapackctrl_entrypoint_5(arg0, 5);
            func_8009E55C(arg0, 2, 0.0f);
        }
        if (baanim_isStopped(arg0)) {
            if (((Objtaxi_arg0 *)arg0)->unk16C != 0.0f) {
                next_state = 0x6F;
            } else {
                next_state = 1;
            }
        }
        break;
    }
    bs_setState(arg0, next_state);
}

BsScript bstaxi_entrypoint_31(BsScriptType arg0) {
    extern BtIntPtr D_808021E8_bstaxi[];
    return (BsScript)D_808021E8_bstaxi[arg0];
}
BT_NATIVE_ONLY(struct player_state_s; void func_80090A2C(struct player_state_s *);)
void bstaxi_entrypoint_32(BT_NATIVE_ONLY(struct player_state_s *) BT_IDO_ONLY(BtIntPtr) arg0)
{
    func_80090A2C(BT_NATIVE_ONLY(arg0));
    bstaxi_entrypoint_0(arg0);
}
void bstaxi_entrypoint_33(void *arg0) {
    void *self;
    BT_IDO_ONLY(s32 baanim_playForDuration_loopSmooth(void *, s32, s32);)
    void baphysics_set_target_horizontal_velocity(struct player_state_s *, f32);
    self = arg0;
    bstaxi_entrypoint_1(self);
    baanim_playForDuration_loopSmooth(self, 0x124, BT_IDO_ONLY(0x40C00000) BT_NATIVE_ONLY(6.0f));
    func_8009FFD8(self, 1, 1, 1, 2);
    baphysics_set_target_horizontal_velocity(self, 0.0f);
    func_800909CC(self);
}

/* extern */

void bstaxi_entrypoint_34(struct player_state_s *arg0) {
    s32 bastick_getZone(struct player_state_s *);
    void bs_setState(void *self, s32 nextState);
    int func_8008E148(struct player_state_s *);
    s32 func_8008E260(struct player_state_s *);
    void func_8009D3A8(void *, s32);
    s32 func_800A02DC(struct player_state_s *, s32);
    s32 player_inWater(struct player_state_s *);
    s32 var_s0;

    var_s0 = 0;
    func_8009D3A8(arg0, 0);
    if (bastick_getZone(arg0) > 0) {
        var_s0 = 0x123;
    }
    var_s0 = func_80800064_bstaxi(arg0, var_s0);
    if (func_8008E148(arg0) != 0) {
        var_s0 = 1;
    }
    if (func_8008E260(arg0) != 0) {
        var_s0 = 0x3D;
    }
    if (player_inWater(arg0) != 0) {
        var_s0 = 0x4C;
    }
    bs_setState(arg0, func_800A02DC(arg0, var_s0));
}

BsScript bstaxi_entrypoint_35(BsScriptType arg0) {
    extern BtIntPtr D_808021F8_bstaxi[];
    return (BsScript)D_808021F8_bstaxi[arg0];
}
/* data_to_c.py: from asm/data/overlays/bs/taxi.data.s */
void _bstaxi_entrypoint_2();
void _bstaxi_entrypoint_3();
void _bstaxi_entrypoint_4();
void func_80099B94(void *arg0);
void _bstaxi_entrypoint_7();
void _bstaxi_entrypoint_8();
void _bstaxi_entrypoint_9();
void _bstaxi_entrypoint_11();
void _bstaxi_entrypoint_12();
void _bstaxi_entrypoint_13();
void _bstaxi_entrypoint_17();
void _bstaxi_entrypoint_15();
void _bstaxi_entrypoint_16();
void _bstaxi_entrypoint_19();
void _bstaxi_entrypoint_20();
void _bstaxi_entrypoint_21();
void _bstaxi_entrypoint_23();
void _bstaxi_entrypoint_24();
void _bstaxi_entrypoint_25();
void _bstaxi_entrypoint_27();
void _bstaxi_entrypoint_28();
void _bstaxi_entrypoint_30();
void _bstaxi_entrypoint_29();
void _bstaxi_entrypoint_32();
void _bstaxi_entrypoint_33();
void _bstaxi_entrypoint_34();
s32 D_808020D0_bstaxi [8] BT_DATA(4, overlays_bs_taxi, 0x0) = { 50724883, 69009429, 64, 1638422, 1376256012, 64, 13369625, 1114112 };
s32 D_808020F0_bstaxi [8] BT_DATA(4, overlays_bs_taxi, 0x20) = { 50724883, 69009429, 64, 1638422, 1572864012, 64, 13369651, 1114112 };
s32 D_80802110_bstaxi [8] BT_DATA(4, overlays_bs_taxi, 0x40) = { 50724883, 69009429, 64, 1638422, 1769472012, 64, 15073638, 1114112 };
BtIntPtr D_80802130_bstaxi [4] BT_DATA(4, overlays_bs_taxi, 0x60) = { (BtIntPtr)_bstaxi_entrypoint_2, (BtIntPtr)_bstaxi_entrypoint_3, (BtIntPtr)_bstaxi_entrypoint_4, (BtIntPtr)func_80099B94 };
s32 D_80802140_bstaxi [18] BT_DATA(4, overlays_bs_taxi, 0x70) = { 1903078, 1834308, 19660845, 6553800, 851998, 1445890, 2555904, 6553600, 13107234, 0, 4980889, 1376307, 11730987, 12583168, 262297, 458755, 3276790, -655360 };
BtIntPtr D_80802188_bstaxi [4] BT_DATA(4, overlays_bs_taxi, 0xB8) = { (BtIntPtr)func_808005B8_bstaxi, (BtIntPtr)func_808005F0_bstaxi, (BtIntPtr)func_808006F4_bstaxi, (BtIntPtr)func_808004A8_bstaxi };
BtIntPtr D_80802198_bstaxi [4] BT_DATA(4, overlays_bs_taxi, 0xC8) = { (BtIntPtr)_bstaxi_entrypoint_7, (BtIntPtr)_bstaxi_entrypoint_8, (BtIntPtr)_bstaxi_entrypoint_9, (BtIntPtr)func_80099B94 };
BtIntPtr D_808021A8_bstaxi [4] BT_DATA(4, overlays_bs_taxi, 0xD8) = { (BtIntPtr)_bstaxi_entrypoint_11, (BtIntPtr)_bstaxi_entrypoint_12, (BtIntPtr)_bstaxi_entrypoint_13, (BtIntPtr)func_80099B94 };
BtIntPtr D_808021B8_bstaxi [4] BT_DATA(4, overlays_bs_taxi, 0xE8) = { (BtIntPtr)_bstaxi_entrypoint_17, (BtIntPtr)_bstaxi_entrypoint_15, (BtIntPtr)_bstaxi_entrypoint_16, (BtIntPtr)func_80099B94 };
BtIntPtr D_808021C8_bstaxi [4] BT_DATA(4, overlays_bs_taxi, 0xF8) = { (BtIntPtr)_bstaxi_entrypoint_19, (BtIntPtr)_bstaxi_entrypoint_20, (BtIntPtr)_bstaxi_entrypoint_21, (BtIntPtr)func_80099B94 };
BtIntPtr D_808021D8_bstaxi [4] BT_DATA(4, overlays_bs_taxi, 0x108) = { (BtIntPtr)_bstaxi_entrypoint_23, (BtIntPtr)_bstaxi_entrypoint_24, (BtIntPtr)_bstaxi_entrypoint_25, (BtIntPtr)func_80099B94 };
BtIntPtr D_808021E8_bstaxi [4] BT_DATA(4, overlays_bs_taxi, 0x118) = { (BtIntPtr)_bstaxi_entrypoint_27, (BtIntPtr)_bstaxi_entrypoint_28, (BtIntPtr)_bstaxi_entrypoint_30, (BtIntPtr)_bstaxi_entrypoint_29 };
BtIntPtr D_808021F8_bstaxi [6] BT_DATA(4, overlays_bs_taxi, 0x128) = { (BtIntPtr)_bstaxi_entrypoint_32, (BtIntPtr)_bstaxi_entrypoint_33, (BtIntPtr)_bstaxi_entrypoint_34, (BtIntPtr)func_80099B94, 0, 0 };
