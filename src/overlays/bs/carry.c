#include "common.h"
#include "overlays/ba/playerstate.h"

void func_80800000_bscarry(PlayerState *arg0) {
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

void func_808000D0_bscarry(s32 arg0) {
    s32 _bsdrone_entrypoint_3(s32);
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
void baanim_playForDuration_loopSmooth(PlayerState *, s32, f32);
void func_8008C9F0(PlayerState *, f32, f32, f32, f32);
void func_8009FFD8(PlayerState *, enum baanim_update_type_e, enum yaw_type_e, s32, enum ba_physics_type_e);

void func_8080029C_bscarry(PlayerState *arg0) {
    func_80800208_bscarry(arg0);
    baanim_playForDuration_loopSmooth(arg0, 0x28, 0.8f);
    func_8009FFD8(arg0, 2, 1, 1, 2);
    func_8008C9F0(arg0, 30.0f, 60.0f, 1.8f, 1.2f);
}

void func_80800310_bscarry(PlayerState *arg0) {
    Unk80132ED0 *_bahold_entrypoint_5(s32);
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

s32 bscarry_entrypoint_0(s32 arg0) {
    extern s32 D_808007B0_bscarry[];
    return ((s32 *)&D_808007B0_bscarry)[arg0];
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
    Unk80132ED0 *_bahold_entrypoint_5(s32);
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

s32 bscarry_entrypoint_1(s32 arg0) {
    extern s32 D_808007C0_bscarry[];
    return ((s32 *)&D_808007C0_bscarry)[arg0];
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
    Unk80132ED0 *_bahold_entrypoint_5(s32);
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

s32 bscarry_entrypoint_2(s32 arg0) {
    extern s32 D_808007D0_bscarry[];
    return ((s32 *)&D_808007D0_bscarry)[arg0];
}

void func_8080065C_bscarry(s32 arg0)
{
    _bsdrone_entrypoint_2();
    func_808001D4_bscarry(arg0);
}
void func_80800684_bscarry(s32 arg0)
{
    func_80800208_bscarry(arg0);
    _bsdrone_entrypoint_0(arg0);
}
void func_808006AC_bscarry(PlayerState* self)
{
    _bsdrone_entrypoint_1(self);
}
s32 bscarry_entrypoint_3(s32 arg0) {
    extern s32 D_808007E0_bscarry[];
    return ((s32 *)&D_808007E0_bscarry)[arg0];
}

void func_808006E0_bscarry(s32 arg0)
{
    _bsrest_entrypoint_14();
    func_808001D4_bscarry(arg0);
}
void func_80800708_bscarry(s32 arg0)
{
    func_80800208_bscarry(arg0);
    _bsrest_entrypoint_16(arg0);
}
/* extern */

void func_80800730_bscarry(s32 arg0) {
    s32 _bsrest_entrypoint_20();
    void bs_setState(PlayerState *, s32);
    Unk80132ED0 *_bahold_entrypoint_5(s32);
    s32 sp1C;

    sp1C = 0;
    if (_bsrest_entrypoint_20() != 0) {
        sp1C = 0x3A;
    }
    if (_bahold_entrypoint_5(arg0) == 0) {
        sp1C = 0x73;
    }
    bs_setState(arg0, sp1C);
}

s32 bscarry_entrypoint_4(s32 arg0) {
    extern s32 D_808007F0_bscarry[];
    return ((s32 *)&D_808007F0_bscarry)[arg0];
}
