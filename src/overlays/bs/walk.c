#include "common.h"
#include "overlays/bs/walk.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/walk/func_80800000_bswalk.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/walk/func_8080016C_bswalk.s")

void func_808001D8_bswalk(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)arg0 + 364) = arg1;
}

void func_808001E4_bswalk(u8 *arg0) {
    f32 func_800D8FF8(void);
    f32 func_800F0E00(f32, f32);
    (*(f32 *)((s8 *)(arg0) + (0x16C))) = func_800F0E00(0.0f, (*(f32 *)((s8 *)(arg0) + (0x16C))) - func_800D8FF8());
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/walk/func_80800220_bswalk.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/walk/func_80800248_bswalk.s")

f32 bswalk_entrypoint_0(s32 arg0) {
    return 500.0f;
}

void bswalk_entrypoint_1()
{
    func_80800000_bswalk();
}

void bswalk_entrypoint_2(u8 *arg0) {
    s32 _bapackctrl_entrypoint_5(s32, s32);
    s32 func_8008E0E8();
    void func_800A2EDC(void *arg0, f32 arg1);
    func_800A2EDC(arg0, 1.0f);
    if (func_8008E0E8(arg0) != 0) {
        _bapackctrl_entrypoint_5((s32) arg0, 3);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/walk/bswalk_entrypoint_3.s")

void bswalk_entrypoint_4(PlayerState *self) {
    f32 bastick_distance(PlayerState *);
    f32 yaw_get(PlayerState *);
    void yaw_setIdeal(PlayerState *, f32);
    void func_800A2CE8(PlayerState *, f32, s32);
    s32 func_8009BCD4(PlayerState *, f32);
    f32 baphysics_get_target_horizontal_velocity(PlayerState *);
    s32 _badrone_entrypoint_24(PlayerState *);
    s32 _badrone_entrypoint_25(PlayerState *);
    void _baduo_entrypoint_12(PlayerState *);
    s32 func_80800248_bswalk(PlayerState *, s32);
    int func_8008E148(PlayerState *);
    s32 next_state;

    next_state = 0;
    func_8080016C_bswalk();
    if (bastick_distance(self) == 0.0f) {
        yaw_setIdeal(self, yaw_get(self));
    }
    func_800A2CE8(self, 0.47f, 4);
    func_800A2CE8(self, 0.97f, 3);
    func_80800000_bswalk(self);
    switch (bastick_getZone(self)) {
        case 0:
            if (func_8009BCD4(self, 1.0f)) {
                next_state = 1;
            }
            break;
        case 2:
            next_state = 2;
            break;
        case 3:
            next_state = 3;
            break;
        case 4:
            next_state = 4;
            break;
    }
    if (func_8008DE24(self)) {
        next_state = 0x7A;
    }
    if (bainput_should_enter_first_person(self)) {
        next_state = _badrone_entrypoint_24(self);
    }
    if (func_8008DD04(self)) {
        next_state = 0x2F;
    }
    if (bakey_held(self, 1)) {
        next_state = 7;
    }
    next_state = func_80800248_bswalk(self, next_state);
    if (bakey_pressed(self, 8)) {
        next_state = bs_getTypeOfJump(self);
        if (baphysics_get_target_horizontal_velocity(self) == 0.0f) {
            if (func_8008D714(self)) {
                next_state = 0xB8;
            } else if (func_8008D790(self)) {
                _baduo_entrypoint_12(self);
                return;
            }
        }
    }
    if (func_8008E148(self)) {
        next_state = _badrone_entrypoint_25(self);
    }
    if (player_inWater(self)) {
        next_state = 0x2D;
    }
    bs_setState(self, func_800A02DC(self, next_state));
}

s32 bswalk_entrypoint_5(s32 arg0) {
    extern s32 D_80801520_bswalk[];
    return ((s32 *)&D_80801520_bswalk)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/walk/bswalk_entrypoint_6.s")

void bswalk_entrypoint_7(PlayerState *self) {
    f32 bastick_distance(PlayerState *);
    f32 yaw_get(PlayerState *);
    void yaw_setIdeal(PlayerState *, f32);
    void func_800A2CE8(PlayerState *, f32, s32);
    s32 func_8009BCD4(PlayerState *, f32);
    f32 baphysics_get_target_horizontal_velocity(PlayerState *);
    s32 _badrone_entrypoint_24(PlayerState *);
    s32 _badrone_entrypoint_25(PlayerState *);
    void _baduo_entrypoint_12(PlayerState *);
    s32 func_80800248_bswalk(PlayerState *, s32);
    int func_8008E148(PlayerState *);
    s32 next_state = 0;

    func_8080016C_bswalk();
    if (bastick_distance(self) == 0.0f) {
        yaw_setIdeal(self, yaw_get(self));
    }
    func_800A2CE8(self, 0.4f, 4);
    func_800A2CE8(self, 0.9f, 3);
    func_80800000_bswalk(self);
    switch (bastick_getZone(self)) {
        case 0:
            if (func_8009BCD4(self, 3.0f)) {
                next_state = 1;
            }
            break;
        case 1:
            next_state = 0x1F;
            break;
        case 3:
            next_state = 3;
            break;
        case 4:
            next_state = 4;
            break;
    }
    if (func_8008DE24(self)) {
        next_state = 0x7A;
    }
    if (bainput_should_enter_first_person(self)) {
        next_state = _badrone_entrypoint_24(self);
    }
    if (func_8008DD04(self)) {
        next_state = 0x2F;
    }
    if (bakey_held(self, 1)) {
        next_state = 7;
    }
    next_state = func_80800248_bswalk(self, next_state);
    if (bakey_pressed(self, 8)) {
        next_state = bs_getTypeOfJump(self);
        if (baphysics_get_target_horizontal_velocity(self) == 0.0f) {
            if (func_8008D714(self)) {
                next_state = 0xB8;
            } else if (func_8008D790(self)) {
                _baduo_entrypoint_12(self);
                return;
            }
        }
    }
    if (func_8008E148(self)) {
        next_state = _badrone_entrypoint_25(self);
    }
    if (player_inWater(self)) {
        next_state = 0x2D;
    }
    bs_setState(self, func_800A02DC(self, next_state));
}

/* extern */

void bswalk_entrypoint_8(s32 arg0) {
    s32 _bapackctrl_entrypoint_5(s32, s32);
    s32 func_8008E0E8();
    if (func_8008E0E8() != 0) {
        _bapackctrl_entrypoint_5(arg0, 3);
    }
}

s32 bswalk_entrypoint_9(s32 arg0) {
    extern s32 D_80801530_bswalk[];
    return ((s32 *)&D_80801530_bswalk)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/walk/bswalk_entrypoint_10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/walk/bswalk_entrypoint_11.s")

/* extern */

void bswalk_entrypoint_12(s32 arg0) {
    s32 _bapackctrl_entrypoint_5(s32, s32);
    s32 func_8008E0E8();
    if (func_8008E0E8() != 0) {
        _bapackctrl_entrypoint_5(arg0, 3);
    }
}

s32 bswalk_entrypoint_13(s32 arg0) {
    extern s32 D_80801540_bswalk[];
    return ((s32 *)&D_80801540_bswalk)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/walk/bswalk_entrypoint_14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/walk/bswalk_entrypoint_15.s")

void bswalk_entrypoint_16(PlayerState *arg0) {
    s32 _bapackctrl_entrypoint_5(s32, s32);
    s32 baroll_setIdeal(s32, f32);
    s32 func_8008E0E8();
    void func_8009BF5C(PlayerState *, f32);
    func_8009BF5C(arg0, 0.0f);
    baroll_setIdeal((s32) arg0, 0.0f);
    if (func_8008E0E8(arg0) != 0) {
        _bapackctrl_entrypoint_5((s32) arg0, 3);
    }
}

s32 bswalk_entrypoint_17(s32 arg0) {
    extern s32 D_80801550_bswalk[];
    return ((s32 *)&D_80801550_bswalk)[arg0];
}

void bswalk_entrypoint_18(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/walk/bswalk_entrypoint_19.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/walk/bswalk_entrypoint_20.s")

s32 bswalk_entrypoint_21(s32 arg0) {
    extern s32 D_80801560_bswalk[];
    return ((s32 *)&D_80801560_bswalk)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/walk/bswalk_entrypoint_22.s")
