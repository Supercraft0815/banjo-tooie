#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/taxi/func_80800000_bstaxi.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/taxi/bstaxi_entrypoint_0.s")

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
}

void bstaxi_entrypoint_2(void *arg0) {
    *(s32 *)((u8 *)arg0 + 0x160) = 0;
    bstaxi_entrypoint_0();
}

/* extern */

struct player_state_s;
enum baanim_update_type_e;
enum yaw_type_e;
enum ba_physics_type_e;
void func_8009FFD8(struct player_state_s *, enum baanim_update_type_e, enum yaw_type_e, s32, enum ba_physics_type_e);

void bstaxi_entrypoint_3(void *arg0) {
    s32 baanim_playForDuration_onceSmooth(void *, s32, s32);
    s32 bainput_enable(void *, s32, s32);
    void baphysics_set_target_horizontal_velocity(struct player_state_s *, f32);
    bstaxi_entrypoint_1(arg0);
    baanim_playForDuration_onceSmooth(arg0, 0x129, 0x40A00000);
    func_8009FFD8(arg0, 1, 1, 3, 2);
    baphysics_set_target_horizontal_velocity(arg0, 0.0f);
    bainput_enable(arg0, 0, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/taxi/bstaxi_entrypoint_4.s")

s32 bstaxi_entrypoint_5(s32 arg0) {
    extern s32 D_80802130_bstaxi[];
    return ((s32 *)&D_80802130_bstaxi)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/taxi/func_80800420_bstaxi.s")

/* extern */

void func_808004A8_bstaxi(s32 arg0) {
    s32 func_80099B94(s32);
    s32 func_8009E6EC();
    s32 func_80800420_bstaxi(s32);
    s32 temp_v0;

    temp_v0 = func_8009E6EC();
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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/taxi/func_80800524_bstaxi.s")

/* extern */

void func_808005B8_bstaxi(s32 arg0) {
    void baroll_setIdeal(s32, f32);
    void func_8009BF5C(s32, f32);
    baroll_setIdeal(arg0, 0.0f);
    func_8009BF5C(arg0, 0.0f);
    bstaxi_entrypoint_0(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/taxi/func_808005F0_bstaxi.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/taxi/func_808006F4_bstaxi.s")

s32 bstaxi_entrypoint_6(s32 arg0) {
    extern s32 D_80802188_bstaxi[];
    return ((s32 *)&D_80802188_bstaxi)[arg0];
}

void bstaxi_entrypoint_7()
{
    bstaxi_entrypoint_0();
}

void bstaxi_entrypoint_8(void *arg0) {
    s32 baanim_playForDuration_onceSmooth(void *, s32, s32);
    s32 bainput_enable(void *, s32, s32);
    void baphysics_set_target_horizontal_velocity(struct player_state_s *, f32);
    bstaxi_entrypoint_1(arg0);
    baanim_playForDuration_onceSmooth(arg0, 0xF3, 0x3F8CCCCD);
    func_8009FFD8(arg0, 1, 1, 3, 2);
    baphysics_set_target_horizontal_velocity(arg0, 0.0f);
    bainput_enable(arg0, 0, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/taxi/bstaxi_entrypoint_9.s")

s32 bstaxi_entrypoint_10(s32 arg0) {
    extern s32 D_80802198_bstaxi[];
    return ((s32 *)&D_80802198_bstaxi)[arg0];
}

/* extern */

void func_80800A18_bstaxi(void *arg0, u32 arg1) {
    s32 _bapackctrl_entrypoint_5(void *, s32);
    s32 baanim_playForDuration_loopSmooth(void *, s32, s32);
    s32 baanim_playForDuration_onceSmooth(void *, s32, s32);
    s32 bainput_enable(void *, s32, s32);
    switch (arg1) {
    case 0:
        if ((*(u8 *)((s8 *)(arg0) + (0x15C))) == 3) {
            _bapackctrl_entrypoint_5(arg0, 2);
        }
        break;
    case 1:
        (*(s8 *)((s8 *)(arg0) + (0x15D))) = 0;
        baanim_playForDuration_onceSmooth(arg0, 0x121, 0x3F8CCCCD);
        bainput_enable(arg0, 0, 0);
        break;
    case 2:
        baanim_playForDuration_loopSmooth(arg0, 0x12B, 0x40900000);
        break;
    case 3:
        baanim_playForDuration_onceSmooth(arg0, 0x12D, 0x40333333);
        break;
    case 4:
        baanim_playForDuration_onceSmooth(arg0, 0x12C, 0x3FB33333);
        break;
    }
    (*(u8 *)((s8 *)(arg0) + (0x15C))) = (u8) arg1;
}

void bstaxi_entrypoint_11(s32 arg0)
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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/taxi/bstaxi_entrypoint_13.s")

s32 bstaxi_entrypoint_14(s32 arg0) {
    extern s32 D_808021A8_bstaxi[];
    return ((s32 *)&D_808021A8_bstaxi)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/taxi/bstaxi_entrypoint_15.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/taxi/bstaxi_entrypoint_16.s")

void bstaxi_entrypoint_17(s32 arg0) {
    void func_8009BF5C(s32, f32);
    void baroll_setIdeal(s32, f32);
    baphysics_reset_gravity();
    func_8009BF5C(arg0, 0.0f);
    baroll_setIdeal(arg0, 0.0f);
    bstaxi_entrypoint_0(arg0);
}

s32 bstaxi_entrypoint_18(s32 arg0) {
    extern s32 D_808021B8_bstaxi[];
    return ((s32 *)&D_808021B8_bstaxi)[arg0];
}

void bstaxi_entrypoint_19()
{
    bstaxi_entrypoint_0();
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/taxi/bstaxi_entrypoint_20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/taxi/bstaxi_entrypoint_21.s")

s32 bstaxi_entrypoint_22(s32 arg0) {
    extern s32 D_808021C8_bstaxi[];
    return ((s32 *)&D_808021C8_bstaxi)[arg0];
}

void bstaxi_entrypoint_23()
{
    bstaxi_entrypoint_0();
}

void bstaxi_entrypoint_24(void *arg0) {
    s32 baanim_playForDuration_onceSmooth(void *, s32, s32);
    void baphysics_set_target_horizontal_velocity(struct player_state_s *, f32);

    bstaxi_entrypoint_1(arg0);
    baanim_playForDuration_onceSmooth(arg0, 0x128, 0x3FB33333);
    func_8009FFD8(arg0, 1, 1, 3, 2);
    baphysics_set_target_horizontal_velocity(arg0, 0.0f);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/taxi/bstaxi_entrypoint_25.s")

s32 bstaxi_entrypoint_26(s32 arg0) {
    extern s32 D_808021D8_bstaxi[];
    return ((s32 *)&D_808021D8_bstaxi)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/taxi/func_80801600_bstaxi.s")

void bstaxi_entrypoint_27(s32 arg0)
{
    func_80801600_bstaxi(arg0,0);
    bstaxi_entrypoint_0(arg0);
}

void bstaxi_entrypoint_28(void *arg0) {
    s32 baanim_playForDuration_onceSmooth(void *, s32, s32);
    bstaxi_entrypoint_1(arg0);
    baanim_playForDuration_onceSmooth(arg0, 0xF5, 0x3F333333);
    func_8009FFD8(arg0, 1, 1, 3, 2);
    *(s8 *)((u8 *)arg0 + 0x15C) = 0;
    func_80801600_bstaxi(arg0, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/taxi/bstaxi_entrypoint_29.s")

void bstaxi_entrypoint_30(void *arg0) {
    void _babackpack_entrypoint_6(void *, f32 *, s32);
    void _babackpack_set_state(void *, s32);
    s32 _bapackctrl_entrypoint_1(void *);
    s32 _bapackctrl_entrypoint_5(void *, s32);
    s32 _batimer_decrement(void *, s32);
    f32 _batimer_get(void *, s32);
    void _subaddietaxi_entrypoint_8(s32, f32 *, f32, f32, s32);
    s32 baanim_isAt(void *, f32);
    s32 baanim_isStopped(void *);
    s32 baflag_clear(void *, s32);
    s32 baflag_isTrue(void *, s32);
    s32 baflag_set(void *, s32);
    void baphysics_set_target_horizontal_velocity(struct player_state_s *, f32);
    s32 bs_setState(void *, s32);
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
    switch (*(u8 *)((u8 *)arg0 + 0x15C)) {
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
        _subaddietaxi_entrypoint_8(*(s32 *)((u8 *)arg0 + 0x160), position, progress, scale, _bapackctrl_entrypoint_1(arg0));
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
            if (*(f32 *)((u8 *)arg0 + 0x16C) != 0.0f) {
                next_state = 0x6F;
            } else {
                next_state = 1;
            }
        }
        break;
    }
    bs_setState(arg0, next_state);
}

s32 bstaxi_entrypoint_31(s32 arg0) {
    extern s32 D_808021E8_bstaxi[];
    return ((s32 *)&D_808021E8_bstaxi)[arg0];
}

void bstaxi_entrypoint_32(s32 arg0)
{
    func_80090A2C();
    bstaxi_entrypoint_0(arg0);
}
void bstaxi_entrypoint_33(void *arg0) {
    void *self;
    s32 baanim_playForDuration_loopSmooth(void *, s32, s32);
    void baphysics_set_target_horizontal_velocity(struct player_state_s *, f32);
    self = arg0;
    bstaxi_entrypoint_1(self);
    baanim_playForDuration_loopSmooth(self, 0x124, 0x40C00000);
    func_8009FFD8(self, 1, 1, 1, 2);
    baphysics_set_target_horizontal_velocity(self, 0.0f);
    func_800909CC(self);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/taxi/bstaxi_entrypoint_34.s")

s32 bstaxi_entrypoint_35(s32 arg0) {
    extern s32 D_808021F8_bstaxi[];
    return ((s32 *)&D_808021F8_bstaxi)[arg0];
}
