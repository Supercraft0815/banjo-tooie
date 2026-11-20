#include "bs_script.h"
#include "common.h"
#ifdef BT_NATIVE
#include "overlays/ba/yaw.h" // enums for the prototypes below
#include "overlays/ba/physics.h"
#endif
#include "overlays/ba/playerstate.h"
#ifdef BT_NATIVE // complete the enum forward declarations below
#include "overlays/ba/anim.h"
#endif
BT_NATIVE_ONLY(struct player_state_s; void _bsrest_entrypoint_14(struct player_state_s *); s32 _bsrest_entrypoint_20(struct player_state_s *);) void func_80800000_bscarry(PlayerState *arg0) {
    int bastatetimer_isDone(PlayerState *, s32);
    void bs_setState(PlayerState *, s32);
    s32 func_8008E9AC(void *);
    void func_8008F6B8(PlayerState *, s32);
    void func_80099B94(PlayerState *);
    s32 func_8009E6EC(PlayerState *);
    void func_8009E830(PlayerState *, s32);

    switch (func_8009E6EC(arg0)) {
    case 8:
        func_8009E830(arg0, 2);
        bs_setState(arg0, 0x3C);
        break;
    case 18:
        func_8008F6B8(arg0, func_8008E9AC(arg0));
        break;
    case 22:
        if (bastatetimer_isDone(arg0, 1)) {
            bs_setState(arg0, 0x5B);
            func_8009E830(arg0, 2);
        } else {
            func_8009E830(arg0, 1);
        }
        break;
    default:
        func_80099B94(arg0);
        break;
    }
}

/* extern */

void func_808000D0_bscarry(BtIntPtr arg0) {
    void _bsdrone_entrypoint_3(struct player_state_s *arg0);
    s32 func_8009E6EC();
    void func_80800000_bscarry(PlayerState *);
    s32 temp_v0;

    temp_v0 = func_8009E6EC();
    if ((temp_v0 == 8) || (temp_v0 == 0x12) || (temp_v0 == 0x16)) {
        func_80800000_bscarry(arg0);
        return;
    }
    _bsdrone_entrypoint_3(arg0);
}

void func_80800128_bscarry(PlayerState *arg0) {
    void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
    s32 bastick_getZone(PlayerState *);
    f32 bastick_getZonePosition(PlayerState *);
    f32 func_800F1214(f32, f32, f32);
    f32 sp24;

    sp24 = bastick_getZonePosition(arg0);
    switch (bastick_getZone(arg0)) {
        case 0:
            baphysics_set_target_horizontal_velocity(arg0, 0.0f);
            break;
        case 1:
            baphysics_set_target_horizontal_velocity(arg0, func_800F1214(sp24, 30.0f, 60.0f));
            break;
        case 2:
            baphysics_set_target_horizontal_velocity(arg0, func_800F1214(sp24, 60.0f, 300.0f));
            break;
    }
}

/* extern */

void func_808001D4_bscarry(PlayerState *arg0) {
    s32 func_8009E69C(PlayerState *, s32);
    void bastick_popZone(PlayerState *);
    if (func_8009E69C(arg0, 0x400) == 0) {
        bastick_popZone(arg0);
    }
}

/* extern */
void func_80800208_bscarry(PlayerState *arg0) {
    s32 func_8009E6C4(PlayerState *, s32);
    void bastick_pushZone(PlayerState *);
    void bastick_setZoneMax(PlayerState *, s32, f32);
    if (func_8009E6C4(arg0, 0x400) == 0) {
        bastick_pushZone(arg0);
        bastick_setZoneMax(arg0, 0, 0.03f);
        bastick_setZoneMax(arg0, 1, 0.2f);
        bastick_setZoneMax(arg0, 2, 1.0f);
    }
}

void func_8080027C_bscarry(PlayerState *arg0)
{
    func_808001D4_bscarry(arg0);
}

/* extern */

enum baanim_update_type_e;
enum yaw_type_e;
enum ba_physics_type_e;
#ifndef BT_NATIVE
BT_IDO_ONLY(void baanim_playForDuration_loopSmooth(PlayerState *, s32, f32);)
#endif
void func_8008C9F0(PlayerState *, f32, f32, f32, f32);
void func_8009FFD8(PlayerState *, enum baanim_update_type_e, enum yaw_type_e, s32, enum ba_physics_type_e);

void func_8080029C_bscarry(PlayerState *arg0) {
    func_80800208_bscarry(arg0);
    baanim_playForDuration_loopSmooth(arg0, 0x28, 0.8f);
    func_8009FFD8(arg0, 2, 1, 1, 2);
    func_8008C9F0(arg0, 30.0f, 60.0f, 1.8f, 1.2f);
}

void func_80800310_bscarry(PlayerState *arg0) {
    Unk80132ED0 *_bahold_entrypoint_5(BtIntPtr);
    s32 bastick_getZone(PlayerState *);
    void bs_setState(PlayerState *, s32);
    s32 func_8009BCD4(PlayerState *, f32);
    void func_800A2CE8(PlayerState *, f32, s32);
    s32 next_state = 0;

    func_800A2CE8(arg0, 0.4f, 4);
    func_800A2CE8(arg0, 0.9f, 3);
    func_80800128_bscarry(arg0);
    switch (bastick_getZone(arg0)) {
        case 0:
            if (func_8009BCD4(arg0, 1.0f)) {
                next_state = 0x3A;
            }
            break;
        case 2:
            next_state = 0x3B;
            break;
    }
    if (!_bahold_entrypoint_5(arg0)) {
        next_state = 1;
    }
    bs_setState(arg0, next_state);
}

BsScript bscarry_entrypoint_0(BsScriptType arg0) {
    extern BtIntPtr D_808007B0_bscarry[];
    return (BsScript)D_808007B0_bscarry[arg0];
}

void func_808003D8_bscarry(PlayerState *arg0)
{
    func_808001D4_bscarry(arg0);
}

void func_808003F8_bscarry(PlayerState *arg0) {
    void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
    void func_8009BFE4(PlayerState *, f32, f32);
    void baroll_setAngularVelocity(PlayerState *, f32, f32);
    func_80800208_bscarry(arg0);
    baanim_playForDuration_loopSmooth(arg0, 0x72, 1.2f);
    func_8009FFD8(arg0, 1, 1, 1, 2);
    baphysics_set_target_horizontal_velocity(arg0, 0.0f);
    func_8009BFE4(arg0, 1000.0f, 12.0f);
    baroll_setAngularVelocity(arg0, 1000.0f, 12.0f);
}

void func_8080047C_bscarry(PlayerState *arg0) {
    Unk80132ED0 *_bahold_entrypoint_5(BtIntPtr);
    s32 bastick_getZone(PlayerState *);
    void bs_setState(PlayerState *, s32);
    s32 next_state = 0;

    switch (bastick_getZone(arg0)) {
        case 1:
            next_state = 0x9F;
            break;
        case 2:
            next_state = 0x3B;
            break;
    }
    if (!_bahold_entrypoint_5(arg0)) {
        next_state = 1;
    }
    bs_setState(arg0, next_state);
}

BsScript bscarry_entrypoint_1(BsScriptType arg0) {
    extern BtIntPtr D_808007C0_bscarry[];
    return (BsScript)D_808007C0_bscarry[arg0];
}

void func_80800500_bscarry(PlayerState *arg0)
{
    func_808001D4_bscarry(arg0);
}

void func_80800520_bscarry(PlayerState *arg0) {
    func_80800208_bscarry(arg0);
    baanim_playForDuration_loopSmooth(arg0, 0x73, 0.8f);
    func_8009FFD8(arg0, 2, 1, 1, 2);
    func_8008C9F0(arg0, 60.0f, 300.0f, 0.84f, 0.4f);
}

void func_80800594_bscarry(PlayerState *arg0) {
    Unk80132ED0 *_bahold_entrypoint_5(BtIntPtr);
    s32 bastick_getZone(PlayerState *);
    void bs_setState(PlayerState *, s32);
    s32 func_8009BCD4(PlayerState *, f32);
    void func_800A2CE8(PlayerState *, f32, s32);
    s32 next_state = 0;

    func_800A2CE8(arg0, 0.4f, 4);
    func_800A2CE8(arg0, 0.9f, 3);
    func_80800128_bscarry(arg0);
    switch (bastick_getZone(arg0)) {
        case 0:
            if (func_8009BCD4(arg0, 1.0f)) {
                next_state = 0x3A;
            }
            break;
        case 1:
            next_state = 0x9F;
            break;
    }
    if (!_bahold_entrypoint_5(arg0)) {
        next_state = 1;
    }
    bs_setState(arg0, next_state);
}

BsScript bscarry_entrypoint_2(BsScriptType arg0) {
    extern BtIntPtr D_808007D0_bscarry[];
    return (BsScript)D_808007D0_bscarry[arg0];
}

#ifdef BT_NATIVE
struct player_state_s;
void _bsdrone_entrypoint_2(struct player_state_s *);
#endif

void func_8080065C_bscarry(BT_NATIVE_ONLY(struct player_state_s *) BT_IDO_ONLY(BtIntPtr) arg0)
{
    _bsdrone_entrypoint_2(BT_NATIVE_ONLY(arg0));
    func_808001D4_bscarry(arg0);
}
void func_80800684_bscarry(BtIntPtr arg0)
{
    func_80800208_bscarry(arg0);
    _bsdrone_entrypoint_0(arg0);
}
void func_808006AC_bscarry(PlayerState* self)
{
    _bsdrone_entrypoint_1(self);
}
BsScript bscarry_entrypoint_3(BsScriptType arg0) {
    extern BtIntPtr D_808007E0_bscarry[];
    return (BsScript)D_808007E0_bscarry[arg0];
}

void func_808006E0_bscarry(BtIntPtr arg0)
{
    _bsrest_entrypoint_14(BT_NATIVE_ONLY((struct player_state_s *)arg0));
    func_808001D4_bscarry(arg0);
}
void func_80800708_bscarry(BtIntPtr arg0)
{
    func_80800208_bscarry(arg0);
    _bsrest_entrypoint_16(arg0);
}
/* extern */

void func_80800730_bscarry(BtIntPtr arg0) {
    BT_IDO_ONLY(s32 _bsrest_entrypoint_20();)
    void bs_setState(PlayerState *, s32);
    Unk80132ED0 *_bahold_entrypoint_5(BtIntPtr);
    s32 sp1C;

    sp1C = 0;
    if (_bsrest_entrypoint_20(BT_NATIVE_ONLY((struct player_state_s *)arg0)) != 0) {
        sp1C = 0x3A;
    }
    if (_bahold_entrypoint_5(arg0) == 0) {
        sp1C = 0x73;
    }
    bs_setState(arg0, sp1C);
}

BsScript bscarry_entrypoint_4(BsScriptType arg0) {
    extern BtIntPtr D_808007F0_bscarry[];
    return (BsScript)D_808007F0_bscarry[arg0];
}
/* data_to_c.py: from asm/data/overlays/bs/carry.data.s */
BtIntPtr D_808007B0_bscarry [4] BT_DATA(4, overlays_bs_carry, 0x0) = { (BtIntPtr)func_8080027C_bscarry, (BtIntPtr)func_8080029C_bscarry, (BtIntPtr)func_80800310_bscarry, (BtIntPtr)func_80800000_bscarry };
BtIntPtr D_808007C0_bscarry [4] BT_DATA(4, overlays_bs_carry, 0x10) = { (BtIntPtr)func_808003D8_bscarry, (BtIntPtr)func_808003F8_bscarry, (BtIntPtr)func_8080047C_bscarry, (BtIntPtr)func_80800000_bscarry };
BtIntPtr D_808007D0_bscarry [4] BT_DATA(4, overlays_bs_carry, 0x20) = { (BtIntPtr)func_80800500_bscarry, (BtIntPtr)func_80800520_bscarry, (BtIntPtr)func_80800594_bscarry, (BtIntPtr)func_80800000_bscarry };
BtIntPtr D_808007E0_bscarry [4] BT_DATA(4, overlays_bs_carry, 0x30) = { (BtIntPtr)func_8080065C_bscarry, (BtIntPtr)func_80800684_bscarry, (BtIntPtr)func_808006AC_bscarry, (BtIntPtr)func_808000D0_bscarry };
BtIntPtr D_808007F0_bscarry [4] BT_DATA(4, overlays_bs_carry, 0x40) = { (BtIntPtr)func_808006E0_bscarry, (BtIntPtr)func_80800708_bscarry, (BtIntPtr)func_80800730_bscarry, (BtIntPtr)func_80800000_bscarry };
