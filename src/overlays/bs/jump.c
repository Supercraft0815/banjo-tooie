#include "common.h"

struct player_state_s;

/* extern */

void func_80800000_bsjump(s32 arg0) {
    s32 func_8009D7A4(s32, f32, f32);
    func_8009D7A4(arg0, 0.91f, 1.09f);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/jump/bsjump_entrypoint_0.s")

void bsjump_entrypoint_1(void *arg0) {
    s32 _bswalk_entrypoint_1();
    void baanim_setEndAndDuration(void *, f32, f32);
    s32 baflag_isTrue(void *, s32);
    s32 bakey_released(void *, s32);
    f32 baphysics_get_target_horizontal_velocity(void *);
    s32 bs_setState(s32, s32);
    void func_8009B7C0(void *);
    void func_8009BB24(void *, f32 *);
    f32 func_8009C150(void *);
    f32 func_800964DC(void *);
    s32 next_state;
    f32 velocity[3];
    f32 height_difference;

    next_state = 0;
    if (*(s32 *)((u8 *)arg0 + 0x164) != 0) {
        func_8009FC80(arg0);
    }
    if (baflag_isTrue(arg0, 0xF) != 0) {
        func_8009B7C0(arg0);
    } else {
        _bswalk_entrypoint_1(arg0);
    }
    func_8009BB24(arg0, velocity);
    if (((bakey_released(arg0, 8) != 0) && (velocity[1] > 0.0f) &&
         (*(s32 *)((u8 *)arg0 + 0x164) == 0)) || (func_8008D544(arg0) == 0)) {
        baphysics_reset_gravity(arg0);
    }
    switch (*(s32 *)((u8 *)arg0 + 0x15C)) {
    case 0:
        if (baanim_isStopped(arg0) != 0) {
            baanim_setEndAndDuration(arg0, 0.6667f, 4.0f);
            *(s32 *)((u8 *)arg0 + 0x15C) = 1;
        }
        if (func_8008DF8C(arg0, 0x82) != 0) {
            baanim_setEndAndDuration(arg0, 1.0f, 1.4f);
            *(s32 *)((u8 *)arg0 + 0x15C) = 2;
        }
        break;
    case 1:
        if (baanim_isStopped(arg0) != 0) {
            next_state = 0x2F;
        }
        if (*(s32 *)((u8 *)arg0 + 0x164) != 0) {
            *(s32 *)((u8 *)arg0 + 0x164) = 0;
            next_state = 0x21;
        }
        if (func_8008DF8C(arg0, 0x5A) != 0) {
            baanim_setEndAndDuration(arg0, 1.0f, 2.0f);
            *(s32 *)((u8 *)arg0 + 0x15C) = 2;
        }
        break;
    case 2:
        break;
    }
    if (func_8008E260(arg0) != 0) {
        next_state = 0x3D;
    }
    if (bakey_released(arg0, 8) != 0) {
        *(s32 *)((u8 *)arg0 + 0x164) = 0;
    }
    switch (func_800A3274(arg0)) {
    case 1:
        if (bainput_func_80097DF4(arg0) != 0) {
            next_state = 0x10;
        }
        if (bainput_func_80097F08(arg0) != 0) {
            height_difference = func_8009C150(arg0) - func_800964DC(arg0);
            if ((*(s32 *)((u8 *)arg0 + 0x160) != 0 && ((height_difference > 2.0f) != 0)) ||
                *(s32 *)((u8 *)arg0 + 0x160) == 0) {
                next_state = 0x11;
            }
        }
        if (bainput_should_beak_bust(arg0) != 0) {
            next_state = 0xF;
        }
        break;
    case 10:
        if (bainput_func_80097EC8(arg0) != 0) {
            next_state = 0xE4;
        }
        break;
    }
    if (func_8008DA24(arg0) != 0) {
        next_state = 0xA8;
    }
    if (player_isStable(arg0) != 0) {
        func_8009FE58(arg0);
        if (baphysics_get_target_horizontal_velocity(arg0) != 0.0f) {
            next_state = 4;
        } else {
            next_state = 0x20;
        }
    }
    if (velocity[1] < 0.0f && player_inWater(arg0) != 0) {
        next_state = 0x4C;
    }
    bs_setState((s32)arg0, next_state);
}

void bsjump_entrypoint_2(s32 arg0) { s32 bs_getNextState(struct player_state_s *); if (func_800C6E38(0xA) != 0) { func_800C6DA0(0x3C); } if (bs_getNextState(arg0) != 0x11) { baphysics_reset_gravity(arg0); } }

s32 bsjump_entrypoint_3(s32 arg0) {
    extern s32 D_80801110_bsjump[];
    return ((s32 *)&D_80801110_bsjump)[arg0];
}

/* extern */

void bsjump_entrypoint_4(void *arg0) {
    struct anctrl_s;
    void anctrl_reset(struct anctrl_s *);
    void anctrl_setDuration(struct anctrl_s *, f32);
    void anctrl_setIndex(struct anctrl_s *, enum asset_e);
    void anctrl_start(struct anctrl_s *);
    struct anctrl_s *baanim_getAnimCtrlPtr(struct player_state_s *);
    s32 baflag_isTrue(void *, s32);
    f32 baphysics_get_vertical_velocity(void *);
    void baphysics_set_vertical_velocity(struct player_state_s *, f32);
    void func_8008B1C8(struct anctrl_s *, f32);
    void func_8009FFD8();
    struct anctrl_s *temp_s0;

    temp_s0 = baanim_getAnimCtrlPtr(arg0);
    if ((baflag_isTrue(arg0, 7) != 0) && (baphysics_get_vertical_velocity(arg0) > 700.0f)) {
        baphysics_set_vertical_velocity(arg0, 700.0f);
    }
    anctrl_reset(temp_s0);
    anctrl_setIndex(temp_s0, 0xB0);
    func_8008B1C8(temp_s0, 0.3f);
    anctrl_setDuration(temp_s0, 0.38f);
    anctrl_start(temp_s0);
    func_8009FFD8(arg0, 1, 1, 3, 6);
    (*(s32 *)((s8 *)(arg0) + (0x15C))) = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/jump/bsjump_entrypoint_5.s")

void bsjump_entrypoint_6(s32 arg0) 
{
}
s32 bsjump_entrypoint_7(s32 arg0) {
    extern s32 D_80801120_bsjump[];
    return ((s32 *)&D_80801120_bsjump)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/jump/bsjump_entrypoint_8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/jump/bsjump_entrypoint_9.s")

void bsjump_entrypoint_10(s32 arg0)
{
    func_800961AC(arg0,0x1);
    baphysics_reset_gravity(arg0);
}

s32 bsjump_entrypoint_11(s32 arg0) {
    extern s32 D_80801130_bsjump[];
    return ((s32 *)&D_80801130_bsjump)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/jump/bsjump_entrypoint_12.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/jump/bsjump_entrypoint_13.s")

void bsjump_entrypoint_14()
{
    func_8008E95C();
}

s32 bsjump_entrypoint_15(s32 arg0) {
    extern s32 D_80801140_bsjump[];
    return ((s32 *)&D_80801140_bsjump)[arg0];
}

s32 bsjump_entrypoint_16(s32 *arg0) {
    return arg0[88];
}

/* extern */

void bsjump_entrypoint_17(struct player_state_s *arg0) {
    void _batimer_set(struct player_state_s *, s32, f32);
    void baanim_playForDuration_loop(struct player_state_s *, s32, f32);
    void func_80093360(struct player_state_s *, f32);
    s32 func_8009557C(struct player_state_s *);
    void func_8009DF18(struct player_state_s *, s32, f32, s32);
    void func_8009FFD8(struct player_state_s *, enum baanim_update_type_e, enum yaw_type_e, s32, enum ba_physics_type_e);
    baanim_playForDuration_loop(arg0, 0x68, 0.35f);
    func_8009FFD8(arg0, 1, 1, 3, 6);
    func_80093360(arg0, 60.0f);
    if (func_8009557C(arg0) == 1) {
        _batimer_set(arg0, 0, 0.5f);
        _batimer_set(arg0, 1, 0.41f);
        func_8009DF18(arg0, 0x439, 1.0f, 0x55F0);
    } else {
        _batimer_set(arg0, 0, 0.0f);
        _batimer_set(arg0, 1, 0.01f);
    }
    (*(s32 *)((s8 *)(arg0) + (0x15C))) = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/jump/bsjump_entrypoint_18.s")

/* extern */

void bsjump_entrypoint_19(struct player_state_s *arg0) {
    s32 bs_getNextState(struct player_state_s *);
    void func_80093360(struct player_state_s *, f32);
    void func_80095588(struct player_state_s *, s32);
    void func_8009E0DC(struct player_state_s *);
    void func_800A042C(struct player_state_s *);
    s32 temp_v0;

    temp_v0 = bs_getNextState(arg0);
    if ((temp_v0 == 0xF) || (temp_v0 == 0x10) || (temp_v0 == 0x11)) {
        func_80095588(arg0, 3);
    }
    func_800A042C(arg0);
    func_80093360(arg0, 0.0f);
    func_8009E0DC(arg0);
}

s32 bsjump_entrypoint_20(s32 arg0) {
    extern s32 D_80801150_bsjump[];
    return ((s32 *)&D_80801150_bsjump)[arg0];
}
