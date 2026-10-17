#include "common.h"
typedef struct anctrl_s AnimCtrl;

void bs_setState();

/* extern */

typedef struct PlayerState PlayerState;
void baanim_playForDuration_loopSmooth(PlayerState *, s32, f32);
s32 bs_getNextState(struct player_state_s *);
s32 func_80800000_bsbtrot(PlayerState *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 func_8008E3E8(PlayerState *);
    s32 func_8008E40C(PlayerState *);
    s32 func_8008E430(PlayerState *);
    if (func_8008E40C(arg0) != 0) {
        return arg4;
    }
    if (func_8008E3E8(arg0) != 0) {
        return arg2;
    }
    if (func_8008E430(arg0) != 0) {
        return arg3;
    }
    return arg1;
}

/* extern */

f32 func_80800070_bsbtrot(PlayerState *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4) {
    s32 func_8008E3E8(PlayerState *);
    s32 func_8008E40C(PlayerState *);
    s32 func_8008E430(PlayerState *);

    if (func_8008E40C(arg0) != 0) {
        return arg4;
    }
    if (func_8008E3E8(arg0) != 0) {
        return arg2;
    }
    if (func_8008E430(arg0) != 0) {
        return arg3;
    }
    return arg1;
}

/* extern */

void func_8009D3A8(PlayerState *, s32);
s32 func_8008E260(PlayerState *);
s32 player_inWater(PlayerState *);
void func_800951B4(PlayerState *);

void func_808000DC_bsbtrot(PlayerState *arg0, s32 arg1) {
    void func_8009DE38(PlayerState *, s32, f32);
    if (arg1 != 0) {
        func_8009DE38(arg0, 0x4433, 0.96f);
        return;
    }
    func_8009DE38(arg0, 0x4433, 1.04f);
}

void func_80800120_bsbtrot(s32 arg0) {
    s32 bakey_pressed(s32, s32);
    s32 func_8008E39C();
    if ((bakey_pressed(arg0, 9) != 0) && (func_8008E39C(arg0) != 0)) {
        _bashoes_entrypoint_6(arg0, 2);
    }
}

/* extern */

f32 func_80800164_bsbtrot(PlayerState *arg0) {
    s32 func_8008DE24();
    f32 func_80800070_bsbtrot(PlayerState *, f32, f32, f32, f32);
    if (func_8008DE24() != 0) {
        return 300.0f;
    }
    return func_80800070_bsbtrot(arg0, 700.0f, 1000.0f, 700.0f, 700.0f);
}

f32 func_808001B8_bsbtrot(PlayerState *arg0) { f32 func_80800070_bsbtrot(PlayerState *, f32, f32, f32, f32); return func_80800070_bsbtrot(arg0, 30.0f, 80.0f, 30.0f, 30.0f); }

/* extern */

f32 func_808001EC_bsbtrot(PlayerState *arg0) {
    s32 func_8008DE24();
    f32 func_80800070_bsbtrot(PlayerState *, f32, f32, f32, f32);
    if (func_8008DE24() != 0) {
        return 0.7f;
    }
    return func_80800070_bsbtrot(arg0, 0.34f, 0.29f, 0.7f, 0.53f);
}

/* extern */

f32 func_80800248_bsbtrot(PlayerState *arg0) {
    s32 func_8008DE24();
    f32 func_80800070_bsbtrot(PlayerState *, f32, f32, f32, f32);
    if (func_8008DE24() != 0) {
        return 0.8f;
    }
    return func_80800070_bsbtrot(arg0, 0.56f, 0.51f, 1.2f, 1.4f);
}

/* extern */

void func_808002A4_bsbtrot(PlayerState *arg0, s32 arg1) {
    f32 anctrl_getAnimTimer(AnimCtrl *);
    int anctrl_getIndex(AnimCtrl *);
    void anctrl_setIndex(AnimCtrl *, s32);
    void anctrl_setStart(AnimCtrl *, f32);
    void anctrl_start(AnimCtrl *);
    AnimCtrl *baanim_getAnimCtrlPtr(PlayerState *);
    AnimCtrl *temp_v0;

    temp_v0 = baanim_getAnimCtrlPtr(arg0);
    if (anctrl_getIndex(temp_v0) != arg1) {
        anctrl_setIndex(temp_v0, arg1);
        anctrl_setStart(temp_v0, anctrl_getAnimTimer(temp_v0));
        anctrl_start(temp_v0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/btrot/func_80800308_bsbtrot.s")

/* extern */

void func_808003F0_bsbtrot(void *arg0) {
    s32 func_80099B94(void *);
    s32 func_8009E6EC();
    s32 func_80800308_bsbtrot(void *);
    if (func_8009E6EC() == 0x8D) {
        (*(s32 *)((s8 *)(arg0) + (0x164))) = 1;
        func_80800308_bsbtrot(arg0);
        return;
    }
    func_80099B94(arg0);
}

/* extern */

void func_80800438_bsbtrot(PlayerState *arg0) {
    void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
    s32 bastick_getZone(PlayerState *);
    f32 bastick_getZonePosition(PlayerState *);
    f32 func_800F1214(f32, f32, f32);
    f32 func_80800164_bsbtrot(PlayerState *);
    f32 func_808001B8_bsbtrot(PlayerState *);
    f32 sp2C;
    f32 maxVelocity;
    f32 velocity;
    f32 sp20;

    sp2C = bastick_getZonePosition(arg0);
    if (bastick_getZone(arg0) == 0) {
        baphysics_set_target_horizontal_velocity(arg0, 0.0f);
        return;
    }
    sp20 = func_808001B8_bsbtrot(arg0);
    maxVelocity = func_80800164_bsbtrot(arg0);
    velocity = func_800F1214(sp2C, sp20, maxVelocity);
    baphysics_set_target_horizontal_velocity(arg0, velocity);
}

void func_808004B4_bsbtrot(PlayerState *arg0) {
    s32 bastick_getZone(PlayerState *);
    f32 bastick_getZonePosition(PlayerState *);
    s32 func_8008E3E8(PlayerState *);
    void func_800962B0(PlayerState *, s32);
    if ((func_8008E3E8(arg0) != 0) && (bastick_getZone(arg0) == 1) && (bastick_getZonePosition(arg0) > 0.8f)) {
        func_800962B0(arg0, 1);
        return;
    }
    func_800962B0(arg0, 0);
}

/* extern */

void func_800931AC(PlayerState *, s32);

void func_80800538_bsbtrot(void *arg0) {
    void _bashoes_entrypoint_15();
    void baflag_set(PlayerState *, s32);
    void baroll_setAngularVelocity(PlayerState *, f32, f32);
    void bastick_setZoneMax(PlayerState *, s32, f32);
    s32 bs_getPreviousState(PlayerState *);
    void func_80094F14(u8 *, s32, s32, f32);
    void func_8009BFE4(PlayerState *, f32, f32);
    s32 func_8009CA70(PlayerState *, s32, s32);
    void func_8009E4AC(PlayerState *);
    void func_800A0CE8(PlayerState *, s32);
    void func_800A0CF4(PlayerState *, s32);
    if (func_8009CA70(arg0, bs_getPreviousState(arg0), 0x40) == 0) {
        _bashoes_entrypoint_15(arg0);
        bastick_setZoneMax(arg0, 0, 0.03f);
        bastick_setZoneMax(arg0, 1, 1.0f);
        func_800A0CF4(arg0, 1);
        func_800A0CE8(arg0, 1);
        func_8009BFE4(arg0, 1000.0f, 12.0f);
        baroll_setAngularVelocity(arg0, 1000.0f, 12.0f);
        baflag_set(arg0, 3);
        func_80094F14(arg0, 4, 1, 0.24f);
        func_800931AC(arg0, 2);
        func_8009E4AC(arg0);
        (*(s32 *)((s8 *)(arg0) + (0x160))) = 0;
        (*(s32 *)((s8 *)(arg0) + (0x164))) = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/btrot/func_8080061C_bsbtrot.s")

/* extern */

s32 func_80800710_bsbtrot(void *arg0) {
    s32 bakey_released(void *, s32);
    s32 func_8008E39C();
    if ((*(s32 *)((s8 *)(arg0) + (0x164))) != 0) {
        return 1;
    }
    if (func_8008E39C() != 0) {
        return 0;
    }
    return bakey_released(arg0, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/btrot/func_8080075C_bsbtrot.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/btrot/func_808007E0_bsbtrot.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/btrot/func_808008D0_bsbtrot.s")

void bsbtrot_entrypoint_0(PlayerState *arg0) {
    void baanim_playForDuration_once(void *, s32, f32);
    void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
    void func_8009D874(PlayerState *);

    func_80800538_bsbtrot(arg0);
    func_808004B4_bsbtrot(arg0);
    baanim_playForDuration_once(arg0, func_80800000_bsbtrot(arg0, 0x16, 0x16, 0x29F, 0xA0), 1.0f);
    func_8009FFD8(arg0, 1, 1, 2, 2);
    baphysics_set_target_horizontal_velocity(arg0, 0.0f);
    func_8009D874(arg0);
    bainput_enable(arg0, 0, 0);
}

/* extern */

void bsbtrot_entrypoint_1(PlayerState *arg0) {
    f32 anctrl_getAnimTimer(AnimCtrl *);
    s32 anctrl_isStopped(AnimCtrl *);
    AnimCtrl *baanim_getAnimCtrlPtr(PlayerState *);
    s32 func_808007E0_bsbtrot(PlayerState *, s32);
    s32 pad;
    AnimCtrl *sp20;
    s32 var_s0;

    var_s0 = 0;
    sp20 = baanim_getAnimCtrlPtr(arg0);
    bainput_enable(arg0, 0, 1);
    func_8009D3A8(arg0, 1);
    if (anctrl_isStopped(sp20) != 0) {
        var_s0 = 0x15;
    }
    if (anctrl_getAnimTimer(sp20) > 0.5f) {
        var_s0 = func_808007E0_bsbtrot(arg0, var_s0);
    }
    bs_setState(arg0, var_s0);
}

void bsbtrot_entrypoint_2(s32 arg0) { bainput_enable(arg0, 0, 1); func_8080061C_bsbtrot(arg0); }

s32 bsbtrot_entrypoint_3(s32 arg0) {
    extern s32 D_80802E50_bsbtrot[];
    return ((s32 *)&D_80802E50_bsbtrot)[arg0];
}

void func_80800C20_bsbtrot(s32 arg0) {
    func_80800000_bsbtrot(arg0, 0x26, 0x26, 0x29B, 0x86);
}

void bsbtrot_entrypoint_4(PlayerState *arg0) {
    void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
    s32 func_8008E40C(PlayerState *);
    s32 func_8008E430(PlayerState *);

    if (func_8008E430(arg0) != 0) {
        baanim_playForDuration_loopSmooth(arg0, 0x29B, 1.3f);
    } else if (func_8008E40C(arg0) != 0) {
        baanim_playForDuration_loopSmooth(arg0, 0x86, 1.3f);
    } else {
        baanim_playForDuration_loopSmooth(arg0, 0x26, 1.2f);
    }
    func_8009FFD8(arg0, 1, 1, 1, 2);
    baphysics_set_target_horizontal_velocity(arg0, 0.0f);
    func_80800538_bsbtrot(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/btrot/bsbtrot_entrypoint_5.s")

void bsbtrot_entrypoint_6()
{
    func_8080061C_bsbtrot();
}

s32 bsbtrot_entrypoint_7(s32 arg0) {
    extern s32 D_80802E60_bsbtrot[];
    return ((s32 *)&D_80802E60_bsbtrot)[arg0];
}

s32 func_80800DC4_bsbtrot(s32 arg0) {
    return func_80800000_bsbtrot(arg0, 0x15, 0x44, 0x29C, 0xA1);
}

/* extern */

void func_80800DF4_bsbtrot(s32 arg0) {
    s32 pad[2];
    s32 func_8008C9F0(s32, f32, f32, f32, f32);
    s32 func_8008CA30(s32, f32);
    s32 func_8008E1A0(s32);
    f32 func_8009BBB8(s32);
    f32 func_800F10B4(f32, f32, f32, s32, f32);
    f32 func_80800164_bsbtrot(PlayerState *);
    f32 func_808001B8_bsbtrot();
    f32 func_80800248_bsbtrot(PlayerState *);
    f32 sp34;
    f32 sp30;
    f32 sp2C;

    sp2C = func_808001B8_bsbtrot();
    sp30 = func_80800164_bsbtrot(arg0);
    sp34 = func_80800248_bsbtrot(arg0);
    func_8008C9F0(arg0, sp2C, sp30, sp34, func_808001EC_bsbtrot(arg0));
    if (func_8008E1A0(arg0) != 0) {
        func_8008CA30(arg0, func_800F10B4(func_8009BBB8(arg0), 0.0f, 1.0f, 0x3F19999A, 0.9f));
        return;
    }
    func_8008CA30(arg0, 1.0f);
}

void bsbtrot_entrypoint_8(s32 arg0) {
    baanim_playForDuration_loopSmooth(arg0, func_80800DC4_bsbtrot(arg0), 0.53f);
    func_8009FFD8(arg0, 2, 1, 1, 2);
    func_80800538_bsbtrot(arg0);
    func_80800DF4_bsbtrot(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/btrot/bsbtrot_entrypoint_9.s")

void bsbtrot_entrypoint_10()
{
    func_8080061C_bsbtrot();
}

s32 bsbtrot_entrypoint_11(s32 arg0) {
    extern s32 D_80802E70_bsbtrot[];
    return ((s32 *)&D_80802E70_bsbtrot)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/btrot/bsbtrot_entrypoint_12.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/btrot/bsbtrot_entrypoint_13.s")

void bsbtrot_entrypoint_14(s32 arg0)
{
    baphysics_reset_gravity();
    func_8080061C_bsbtrot(arg0);
}
s32 bsbtrot_entrypoint_15(s32 arg0) {
    extern s32 D_80802E80_bsbtrot[];
    return ((s32 *)&D_80802E80_bsbtrot)[arg0];
}

/* extern */

void func_8080163C_bsbtrot(s32 arg0) {
    s32 func_8009E6EC();
    s32 func_80099B94(void *);
    s32 temp_v0;

    temp_v0 = func_8009E6EC();
    if ((temp_v0 != 0x1A) && (temp_v0 != 0x1B) && (temp_v0 != 0x29) && (temp_v0 != 0x2B)) {
        func_80099B94(arg0);
    }
}

/* extern */

void bsbtrot_entrypoint_16(s32 arg0) {
    void baanim_playForDuration_once(void *, s32, f32);
    void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
    baanim_playForDuration_once((void *)arg0, 7, 0.6f);
    func_8008CA4C(arg0, 1);
    baphysics_set_target_horizontal_velocity((PlayerState *)arg0, 0.0f);
    func_800931AC((void *)arg0, 1);
}

/* extern */

void bsbtrot_entrypoint_17(PlayerState *arg0) {
    s32 _badata_entrypoint_30(PlayerState *, s32);
    f32 baanim_getTimer(PlayerState *);
    int baanim_isStopped(PlayerState *);
    s32 bastick_getZone(PlayerState *);
    int func_8008DD04(PlayerState *);
    s32 func_8008E124(PlayerState *);
    s32 func_8009CC68(PlayerState *);
    s32 var_s1;

    var_s1 = 0;
    if (baanim_isStopped(arg0) != 0) {
        var_s1 = 1;
    }
    if ((baanim_getTimer(arg0) > 0.3f) && (bastick_getZone(arg0) != 0)) {
        var_s1 = 2;
    }
    if (func_8008DD04(arg0) != 0) {
        var_s1 = 0x2F;
    }
    if (func_8008E124(arg0) != 0) {
        var_s1 = _badata_entrypoint_30(arg0, func_8009CC68(arg0));
    }
    bs_setState(arg0, var_s1);
}

void bsbtrot_entrypoint_18(s32 arg0) {
    s32 func_8009CA70(PlayerState *, s32, s32);
    if (func_8009CA70((PlayerState *)arg0, bs_getNextState((PlayerState *)arg0), 0x40) != 0) {
        func_800931AC((PlayerState *)arg0, 2);
    }
    func_8080061C_bsbtrot(arg0);
}

s32 bsbtrot_entrypoint_19(s32 arg0) {
    extern s32 D_80802E90_bsbtrot[];
    return ((s32 *)&D_80802E90_bsbtrot)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/btrot/bsbtrot_entrypoint_20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/btrot/bsbtrot_entrypoint_21.s")

void bsbtrot_entrypoint_22()
{
    func_8080061C_bsbtrot();
}

s32 bsbtrot_entrypoint_23(s32 arg0) {
    extern s32 D_80802EA0_bsbtrot[];
    return ((s32 *)&D_80802EA0_bsbtrot)[arg0];
}

void bsbtrot_entrypoint_24(PlayerState *arg0) {
    void anctrl_reset(AnimCtrl *);
    void anctrl_setDuration(AnimCtrl *, f32);
    void anctrl_setIndex(AnimCtrl *, s32);
    void anctrl_setPlaybackType(AnimCtrl *, s32);
    void anctrl_setStart(AnimCtrl *, f32);
    void anctrl_start(AnimCtrl *);
    AnimCtrl *baanim_getAnimCtrlPtr(PlayerState *);
    f32 baphysics_get_target_horizontal_velocity(PlayerState *);
    void baphysics_set_horizontal_velocity(PlayerState *, f32, f32);
    void baphysics_set_target_yaw(PlayerState *, f32);
    f32 yaw_getIdeal(PlayerState *);
    f32 yaw[3];
    AnimCtrl *anim_ctrl;

    anim_ctrl = baanim_getAnimCtrlPtr(arg0);
    anctrl_reset(anim_ctrl);
    anctrl_setIndex(anim_ctrl, 0x27);
    anctrl_setDuration(anim_ctrl, 1.4f);
    anctrl_setStart(anim_ctrl, 0.4653f);
    anctrl_setPlaybackType(anim_ctrl, 3);
    anctrl_start(anim_ctrl);
    func_80800538_bsbtrot(arg0);
    func_8009FFD8(arg0, 1, 1, 3, 6);
    baphysics_set_target_yaw(arg0, yaw_getIdeal(arg0));
    func_80800438_bsbtrot(arg0);
    yaw[0] = yaw_getIdeal(arg0);
    baphysics_set_horizontal_velocity(arg0, yaw[0], baphysics_get_target_horizontal_velocity(arg0));
    *(s32 *)((u8 *)arg0 + 0x15C) = 0;
}

void bsbtrot_entrypoint_25(void *arg0) {
    s32 func_8008E3E8(PlayerState *);
    s32 bakey_pressed(s32, s32);
    AnimCtrl *baanim_getAnimCtrlPtr(PlayerState *);
    void anctrl_setSubrange(AnimCtrl *, f32, f32);
    void anctrl_setDuration(AnimCtrl *, f32);
    void anctrl_setPlaybackType(AnimCtrl *, s32);
    s32 anctrl_isStopped(AnimCtrl *);
    f32 baphysics_get_target_horizontal_velocity(PlayerState *);
    void func_8009BB24(void *, f32 *);
    s32 next_state;
    AnimCtrl *anim_ctrl;
    f32 velocity[3];

    next_state = 0;
    anim_ctrl = baanim_getAnimCtrlPtr(arg0);
    func_808004B4_bsbtrot(arg0);
    if (func_8008E3E8((s32)arg0) != 0) {
        _bashoes_entrypoint_20(arg0);
    }
    if (baflag_isTrue(arg0, 0xF) != 0) {
        func_8009B7C0(arg0);
    } else {
        func_80800438_bsbtrot(arg0);
    }
    func_8009BB24(arg0, velocity);
    switch (*(u32 *)((u8 *)arg0 + 0x15C)) {
        case 0:
            if (func_8008DF8C(arg0, 0x8C) != 0) {
                anctrl_setSubrange(anim_ctrl, 0.0f, 0.7328f);
                anctrl_setDuration(anim_ctrl, 1.4f);
                anctrl_setPlaybackType(anim_ctrl, 1);
                *(u32 *)((u8 *)arg0 + 0x15C) = 1;
            }
            break;
        case 1:
            func_8009D3A8(arg0, 1);
            if (player_isStable(arg0) != 0) {
                func_8009FE58(arg0);
                anctrl_setSubrange(anim_ctrl, 0.0f, 0.8798f);
                anctrl_setDuration(anim_ctrl, 0.9f);
                anctrl_setPlaybackType(anim_ctrl, 1);
                func_8009D2D8(arg0, 1);
                if (baphysics_get_target_horizontal_velocity(arg0) > 220.0f) {
                    func_8009D658(arg0);
                }
                _badust_entrypoint_1(arg0);
                *(u32 *)((u8 *)arg0 + 0x15C) = 2;
            }
            break;
        case 2:
            if (baphysics_get_target_horizontal_velocity(arg0) > 220.0f) {
                func_8009D658(arg0);
            }
            func_8009D3A8(arg0, 1);
            if (anctrl_isStopped(anim_ctrl) != 0) {
                anctrl_setSubrange(anim_ctrl, 0.0f, 0.8898f);
                anctrl_setDuration(anim_ctrl, 2.0f);
                anctrl_setPlaybackType(anim_ctrl, 1);
                *(u32 *)((u8 *)arg0 + 0x15C) = 3;
            }
            _badust_entrypoint_1(arg0);
            break;
        case 3:
            if (baphysics_get_target_horizontal_velocity(arg0) > 220.0f) {
                func_8009D658(arg0);
            }
            func_8009D3A8(arg0, 1);
            if (anctrl_isStopped(anim_ctrl) != 0) {
                anctrl_setSubrange(anim_ctrl, 0.0f, 1.0f);
                anctrl_setDuration(anim_ctrl, 1.2f);
                anctrl_setPlaybackType(anim_ctrl, 1);
                *(u32 *)((u8 *)arg0 + 0x15C) = 4;
            }
            _badust_entrypoint_1(arg0);
            break;
        case 4:
            if (baphysics_get_target_horizontal_velocity(arg0) > 220.0f) {
                func_8009D658(arg0);
            }
            func_8009D3A8(arg0, 1);
            if (anctrl_isStopped(anim_ctrl) != 0) {
                next_state = 0x15;
            }
            break;
    }
    if (player_inWater(arg0) != 0) {
        next_state = 0x4C;
    }
    if (player_isStable(arg0) != 0) {
        if (bakey_pressed((s32)arg0, 8) != 0) {
            next_state = func_8080075C_bsbtrot(arg0, next_state);
        }
        if (func_8008DF18(arg0) != 0) {
            next_state = 0x45;
        }
    }
    if (func_8008E260(arg0) != 0) {
        next_state = 0x3D;
    }
    bs_setState(arg0, next_state);
}

void bsbtrot_entrypoint_26()
{
    func_8080061C_bsbtrot();
}

s32 bsbtrot_entrypoint_27(s32 arg0) {
    extern s32 D_80802EB0_bsbtrot[];
    return ((s32 *)&D_80802EB0_bsbtrot)[arg0];
}

void bsbtrot_entrypoint_28(s32 arg0)
{
    _bsrest_entrypoint_14();
    func_8080061C_bsbtrot(arg0);
}
void bsbtrot_entrypoint_29(PlayerState *arg0) {
    void _bsrest_entrypoint_18(PlayerState *);
    s32 func_8008E40C(PlayerState *);
    s32 func_8008E430(PlayerState *);

    func_80800538_bsbtrot(arg0);
    _bsrest_entrypoint_18(arg0);
    if (func_8008E430(arg0) != 0) {
        baanim_playForDuration_loopSmooth(arg0, 0x29B, 1.3f);
    } else if (func_8008E40C(arg0) != 0) {
        baanim_playForDuration_loopSmooth(arg0, 0x86, 1.3f);
    } else {
        baanim_playForDuration_loopSmooth(arg0, 0x26, 1.2f);
    }
    func_800931AC(arg0, 2);
}

/* extern */

void bsbtrot_entrypoint_30(PlayerState *arg0) {
    s32 _bsrest_entrypoint_13(PlayerState *);
    s32 _bsrest_entrypoint_20(PlayerState *);
    s32 sp24;

    sp24 = 0;
    func_808004B4_bsbtrot(arg0);
    func_8009D3A8(arg0, 1);
    if ((*(s32 *)((s8 *)(arg0) + (0x164))) != 0) {
        sp24 = 0x17;
    } else if (_bsrest_entrypoint_20(arg0) != 0) {
        sp24 = _bsrest_entrypoint_13(arg0);
    }
    bs_setState(arg0, sp24);
}

s32 bsbtrot_entrypoint_31(s32 arg0) {
    extern s32 D_80802EC0_bsbtrot[];
    return ((s32 *)&D_80802EC0_bsbtrot)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/btrot/bsbtrot_entrypoint_32.s")

/* extern */

void bsbtrot_entrypoint_33(PlayerState *arg0) {
    s32 _bareact_entrypoint_2();
    s32 anctrl_isStopped(AnimCtrl *);
    AnimCtrl *baanim_getAnimCtrlPtr(PlayerState *);
    int baanim_isAt(PlayerState *, f32);
    int baanim_isStopped(PlayerState *);
    s32 func_8008E260(PlayerState *);
    void func_800951B4(PlayerState *);
    s32 player_inWater(PlayerState *);
    int player_isStable(PlayerState *);
    s32 sp24;

    sp24 = 0;
    if (_bareact_entrypoint_2() == 2) {
        func_80800438_bsbtrot(arg0);
    }
    if (baanim_isAt(arg0, 0.3f) != 0) {
        func_800951B4(arg0);
    }
    if (func_8008E260(arg0) != 0) {
        sp24 = 0x3D;
    }
    if ((player_isStable(arg0) != 0) && (baanim_isStopped(arg0) != 0)) {
        sp24 = 0x15;
    }
    if ((anctrl_isStopped(baanim_getAnimCtrlPtr(arg0)) != 0) && (player_inWater(arg0) != 0)) {
        sp24 = 0x2D;
    }
    bs_setState(arg0, sp24);
}

void bsbtrot_entrypoint_34(void *arg0) {
    void func_8009BD88(void *);
    func_8009BD88(arg0);
    baphysics_reset_gravity(arg0);
    func_8008E95C(arg0);
    func_800951B4(arg0);
    func_8080061C_bsbtrot(arg0);
}

s32 bsbtrot_entrypoint_35(s32 arg0) {
    extern s32 D_80802ED0_bsbtrot[];
    return ((s32 *)&D_80802ED0_bsbtrot)[arg0];
}

void bsbtrot_entrypoint_36(PlayerState *arg0)
{
    func_808004B4_bsbtrot(arg0);
    func_80800538_bsbtrot(arg0);
    _bsdrone_entrypoint_0(arg0);
}

void bsbtrot_entrypoint_37(s32 arg0)
{
    _bsdrone_entrypoint_1();
    func_808004B4_bsbtrot(arg0);
}
void bsbtrot_entrypoint_38(s32 arg0)
{
    _bsdrone_entrypoint_2();
    func_8080061C_bsbtrot(arg0);
}
s32 bsbtrot_entrypoint_39(s32 arg0) {
    extern s32 D_80802EE0_bsbtrot[];
    return ((s32 *)&D_80802EE0_bsbtrot)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/btrot/func_80802380_bsbtrot.s")

void bsbtrot_entrypoint_40(PlayerState *arg0) { func_80802380_bsbtrot(arg0, 0); _bashoes_entrypoint_6(arg0, 2); _bashoes_entrypoint_5(arg0, 0); func_8080061C_bsbtrot(arg0); }

void bsbtrot_entrypoint_41(PlayerState *arg0) { func_80800538_bsbtrot(arg0); _bashoes_entrypoint_5(arg0, 1); *(s32 *)((s8 *)arg0 + 0x15C) = 0; func_80802380_bsbtrot(arg0, 1); }

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/btrot/bsbtrot_entrypoint_42.s")

s32 bsbtrot_entrypoint_43(s32 arg0) {
    extern s32 D_80802EF0_bsbtrot[];
    return ((s32 *)&D_80802EF0_bsbtrot)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/btrot/func_808025D8_bsbtrot.s")

void bsbtrot_entrypoint_44(s32 arg0)
{
    baphysics_reset_gravity();
    func_8080061C_bsbtrot(arg0);
}
/* extern */

void bsbtrot_entrypoint_45(s32 arg0) {
    s32 func_808025D8_bsbtrot(s32, s32);
    func_80800538_bsbtrot(arg0);
    (*(s32 *)((s8 *)(arg0) + (0x15C))) = 0;
    func_808025D8_bsbtrot(arg0, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/btrot/bsbtrot_entrypoint_46.s")

s32 bsbtrot_entrypoint_47(s32 arg0) {
    extern s32 D_80802F00_bsbtrot[];
    return ((s32 *)&D_80802F00_bsbtrot)[arg0];
}

/* extern */

void func_808029D8_bsbtrot(void *arg0) {
    s32 _bashoessuck_entrypoint_3(void *);
    s32 bs_getPreviousState();
    void func_80092880(PlayerState *, s32);
    s32 func_8009CA70(PlayerState *, s32, s32);
    void func_800A2018(PlayerState *, s32);
    s32 func_800A4DA4(void *, s32);
    if (func_8009CA70(arg0, bs_getPreviousState(), 0x800) == 0) {
        _bashoessuck_entrypoint_3(arg0);
        (*(s32 *)((s8 *)(arg0) + (0x160))) = 1;
        func_80092880(arg0, 0);
        func_800A2018(arg0, 3);
        func_800A4DA4(arg0, 0x19);
    }
}

void func_80802A4C_bsbtrot(void *arg0) {
    void _bashoessuck_entrypoint_2(void *);
    s32 func_8009CA70(PlayerState *, s32, s32);
    void func_80092880(PlayerState *, s32);
    void func_800A2018(PlayerState *, s32);
    void func_800A4E30(PlayerState *);
    if (func_8009CA70(arg0, bs_getNextState(arg0), 0x800) == 0) {
        _bashoessuck_entrypoint_2(arg0);
        (*(s32 *)((s8 *)arg0 + 0x160)) = 0;
        func_80092880(arg0, 1);
        func_800A2018(arg0, -1);
        func_800A4E30(arg0);
    }
}

void bsbtrot_entrypoint_48(void *arg0) {
    func_80800538_bsbtrot(arg0);
    func_808029D8_bsbtrot(arg0);
    baanim_playForDuration_loopSmooth(arg0, func_80800DC4_bsbtrot((s32)arg0), 0.53f);
    func_8009FFD8(arg0, 2, 1, 9, 0x12);
    func_80800DF4_bsbtrot((s32)arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/btrot/bsbtrot_entrypoint_49.s")

void bsbtrot_entrypoint_50(s32 arg0)
{
    func_80802A4C_bsbtrot((void *)arg0);
    func_8080061C_bsbtrot(arg0);
}
s32 bsbtrot_entrypoint_51(s32 arg0) {
    extern s32 D_80802F10_bsbtrot[];
    return ((s32 *)&D_80802F10_bsbtrot)[arg0];
}

void bsbtrot_entrypoint_52(void *arg0) {
    void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
    func_80800538_bsbtrot(arg0);
    func_808029D8_bsbtrot(arg0);
    baanim_playForDuration_loopSmooth(arg0, 0x86, 1.3f);
    func_8009FFD8(arg0, 1, 1, 9, 0x12);
    baphysics_set_target_horizontal_velocity(arg0, 0.0f);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/btrot/bsbtrot_entrypoint_53.s")

void bsbtrot_entrypoint_54(s32 arg0)
{
    func_80802A4C_bsbtrot((void *)arg0);
    func_8080061C_bsbtrot(arg0);
}
s32 bsbtrot_entrypoint_55(s32 arg0) {
    extern s32 D_80802F20_bsbtrot[];
    return ((s32 *)&D_80802F20_bsbtrot)[arg0];
}
