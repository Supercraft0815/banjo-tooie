#include "bs_script.h"
#include "common.h"
#include "overlays/ba/playerstate.h"
BT_NATIVE_ONLY(struct player_state_s; int _babounce_entrypoint_2(struct player_state_s *); void _bsrest_entrypoint_14(struct player_state_s *); s32 _bsrest_entrypoint_20(struct player_state_s *);) void baanim_playForDuration_onceSmooth(PlayerState *, s32, f32);

/* extern */

s32 func_80800000_bsbansack(PlayerState *arg0, s32 arg1, s32 arg2) {
    int bakey_pressed(PlayerState *, int);
    int bakey_released(PlayerState *, int);
    int func_8008E148(PlayerState *);

    if (arg2 != 0) {
        if (bakey_pressed(arg0, 8) != 0) {
            arg1 = 0x169;
        }
    }
    if (func_8008E148(arg0) != 0) {
        arg1 = 1;
    }
    if ((arg0->unk15C.bytes[3]) == 0) {
        if (bakey_released(arg0, 1) != 0) {
            arg1 = 0x164;
        }
    }
    return arg1;
}

/* extern */

s32 func_80800084_bsbansack(PlayerState *arg0, s32 arg1) {
    int bakey_pressed(PlayerState *, int);
    int bakey_released(PlayerState *, int);
    int func_8008E148(PlayerState *);

    if (bakey_pressed(arg0, 8) != 0) {
        arg1 = 0x169;
    }
    if (func_8008E148(arg0) != 0) {
        arg1 = 1;
    }
    if ((arg0->unk15C.bytes[3]) == 0) {
        if (bakey_released(arg0, 1) != 0) {
            arg1 = 0x164;
        }
    }
    return arg1;
}

s32 func_80800100_bsbansack(PlayerState *arg0, void (*arg1)(PlayerState *)) {
    s32 func_8009E6EC(PlayerState *);

    switch (func_8009E6EC(arg0)) {
        case 0x7F:
            *((u8 *)arg0 + 0x15F) = 1;
            break;
        case 0x80:
            *((u8 *)arg0 + 0x15F) = 0;
            break;
        default:
            arg1(arg0);
            break;
        case 0xC:
            break;
    } BT_NATIVE_ONLY(return 0;)
}

s32 func_80800168_bsbansack(BtIntPtr arg0) {
    s32 func_80800100_bsbansack();
    void func_80099B94(PlayerState *arg0);
    BT_NATIVE_ONLY(return) func_80800100_bsbansack(arg0, &func_80099B94);
}

void func_8080018C_bsbansack(s32 *arg0) {
    s32 func_80800100_bsbansack();
    extern s32 _bsdrone_entrypoint_3;
    func_80800100_bsbansack(arg0, &_bsdrone_entrypoint_3);
}

void func_808001B0_bsbansack(s32 *arg0) {
    s32 func_80800100_bsbansack();
    extern s32 func_80099AA8;
    func_80800100_bsbansack(arg0, &func_80099AA8);
}

void func_808001D4_bsbansack(PlayerState *arg0) {
    void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
    s32 bastick_getZone(PlayerState *);
    f32 bastick_getZonePosition(PlayerState *);
    f32 func_800F1214(f32, f32, f32);
    f32 sp1C;

    sp1C = bastick_getZonePosition(arg0);
    if (bastick_getZone(arg0) == 0) {
        baphysics_set_target_horizontal_velocity(arg0, 0.0f);
        return;
    }
    baphysics_set_target_horizontal_velocity(arg0, func_800F1214(sp1C, 100.0f, 500.0f));
}

void func_80800238_bsbansack(PlayerState *arg0) {
    int _babackpack_get_state();
    void _babackpack_set_state(void *, s32);
    void bastick_popZone(PlayerState *);
    s32 func_8009E74C(PlayerState *, s32);
    void func_800A0CD0(void *, s32);
    void func_800A1040(PlayerState *);

    if (func_8009E74C(arg0, 0x12) != 0) {
        if (_babackpack_get_state(arg0) != 4) {
            func_800A0CD0(arg0, 0);
            _babackpack_set_state(arg0, 4);
        }
    } else {
        if (_babackpack_get_state(arg0) != 1) {
            _babackpack_set_state(arg0, 1);
        }
        func_800A0CD0(arg0, 1);
        bastick_popZone(arg0);
        func_800A1040(arg0);
    }
}

void func_808002D4_bsbansack(PlayerState *arg0) {
    void _babackpack_set_state(void *, s32);
    void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
    void bastick_pushZone(PlayerState *);
    void bastick_setZoneMax(PlayerState *, s32, f32);
    s32 func_8009E77C(PlayerState *, s32);
    void func_800A0CD0(void *, s32);
    void func_800A106C(PlayerState *, f32, f32);

    if (func_8009E77C(arg0, 0x12) == 0) {
        func_800A0CD0(arg0, 0);
        _babackpack_set_state(arg0, 4);
        bastick_pushZone(arg0);
        bastick_setZoneMax(arg0, 0, 0.12f);
        bastick_setZoneMax(arg0, 1, 1.0f);
        func_800A106C(arg0, -10.0f, 10.0f);
        baphysics_set_target_horizontal_velocity(arg0, 0.0f);
        *(s8 *)((u8 *)arg0 + 0x15F) = 0;
    }
}

void func_80800368_bsbansack(PlayerState *arg0) {
    void baroll_setIdeal(PlayerState *self, f32 arg1);
    s32 func_8008DF8C(PlayerState *, s32);
    void func_8009BF5C(PlayerState *, f32);
    void func_8009D2F0(PlayerState *, s32, f32);
    if (func_8008DF8C(arg0, 0x1E) != 0) {
        func_8009D2F0(arg0, 0, 0.5f);
        return;
    }
    func_8009BF5C(arg0, 0.0f);
    baroll_setIdeal((BtIntPtr) arg0, 0.0f);
}

void func_808003C0_bsbansack(PlayerState *arg0) {
    void baphysics_set_gravity(PlayerState *arg0, f32 arg1);
    void baphysics_set_terminal_velocity(PlayerState *arg0, f32 arg1);
    void func_800961AC(PlayerState *, s32);
    baphysics_set_gravity(arg0, 100.0f);
    baphysics_set_terminal_velocity(arg0, 133.33f);
    func_800961AC(arg0, 3);
}

void func_80800400_bsbansack(PlayerState *arg0) {
    void baphysics_reset_terminal_velocity(PlayerState *);
    void baphysics_reset_gravity(PlayerState *);
    void func_800961AC(PlayerState *, s32);
    baphysics_reset_terminal_velocity(arg0);
    baphysics_reset_gravity(arg0);
    func_800961AC(arg0, 1);
}

void func_80800434_bsbansack(BtIntPtr arg0)
{
    func_80800400_bsbansack(arg0);
    func_80800238_bsbansack(arg0);
}
void func_8080045C_bsbansack(PlayerState *arg0) {
    void baanim_playForDuration_loopSmooth(PlayerState *, s32, f32);
    void func_8009FFD8(PlayerState *, s32, s32, s32, s32);
    func_808002D4_bsbansack(arg0);
    baanim_playForDuration_loopSmooth(arg0, 0x28B, 1.5f);
    func_8009FFD8(arg0, 1, 1, 1, 2);
    func_808003C0_bsbansack(arg0);
}

/* extern */

void func_808004B0_bsbansack(PlayerState *arg0) {
    void bs_setState(PlayerState *, int);
    s32 bastick_getZone();
    s32 func_80800084_bsbansack(PlayerState *, s32);
    s32 var_a1;
    s32 sp1C;

    sp1C = 0;
    var_a1 = sp1C;
    if (bastick_getZone() > 0) {
        var_a1 = 0x166;
    }
    bs_setState(arg0, func_80800084_bsbansack(arg0, var_a1));
}

BsScript bsbansack_entrypoint_0(BsScriptType arg0) {
    extern BtIntPtr D_80801E10_bsbansack[];
    return (BsScript)D_80801E10_bsbansack[arg0];
}

void func_80800508_bsbansack(PlayerState *arg0) { if (arg0->unk15C.bytes[2] == 0) func_808002D4_bsbansack(arg0); func_80800238_bsbansack(arg0); }

/* extern */

void func_80800540_bsbansack(PlayerState *arg0) {
    void bainput_enable(PlayerState *, s32, s32);
    void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
    void func_8009DE38(PlayerState *, s32, f32);
    void func_8009FFD8(PlayerState *, s32, s32, s32, s32);
    (*(s8 *)((s8 *)(arg0) + (0x15E))) = 0;
    baanim_playForDuration_onceSmooth(arg0, 0x143, 2.0f);
    func_8009FFD8(arg0, 1, 1, 3, 2);
    baphysics_set_target_horizontal_velocity(arg0, 0.0f);
    func_8009DE38(arg0, 0x583, 1.0f);
    bainput_enable(arg0, 2, 0);
}

struct anctrl_s;
void func_808005BC_bsbansack(PlayerState *arg0) {
    void _babackpack_set_state(void *, s32);
    int anctrl_isAt(struct anctrl_s *, f32);
    struct anctrl_s *baanim_getAnimCtrlPtr(PlayerState *);
    int baanim_isStopped(PlayerState *);
    void bainput_enable(PlayerState *, s32, s32);
    void bs_setState(PlayerState *, int);
    void func_8009DBF0(PlayerState *, s32, f32);
    void func_8009DE38(PlayerState *, s32, f32);
    void func_8009FE58(PlayerState *);
    void func_800A0CD0(void *, s32);
    struct anctrl_s *sp24;
    s32 sp20;

    sp24 = baanim_getAnimCtrlPtr(arg0);
    sp20 = 0;
    bainput_enable(arg0, 2, 1);
    if (anctrl_isAt(sp24, 0.19f) != 0) {
        func_8009DE38(arg0, 0x57C, 1.0f);
    }
    if (anctrl_isAt(sp24, 0.2f) != 0) {
        func_8009DBF0(arg0, 0x3FF, 0.9f);
    }
    if (anctrl_isAt(sp24, 0.48f) != 0) {
        func_8009FE58(arg0);
    }
    if (anctrl_isAt(sp24, 0.52f) != 0) {
        func_8009DE38(arg0, 0x584, 1.0f);
    }
    if (anctrl_isAt(sp24, 0.123f) != 0) {
        func_800A0CD0(arg0, 0);
        _babackpack_set_state(arg0, 2);
    }
    if (anctrl_isAt(sp24, 0.5145f) != 0) {
        arg0->unk15C.bytes[2] = 1;
        func_808002D4_bsbansack(arg0);
    }
    if (baanim_isStopped(arg0) != 0) {
        sp20 = 0x165;
    }
    bs_setState(arg0, sp20);
}

BsScript bsbansack_entrypoint_1(BsScriptType arg0) {
    extern BtIntPtr D_80801E20_bsbansack[];
    return (BsScript)D_80801E20_bsbansack[arg0];
}

/* extern */

void func_80800710_bsbansack(BtIntPtr arg0) {
    f32 anctrl_getAnimTimer(BtIntPtr);
    struct anctrl_s *baanim_getAnimCtrlPtr(PlayerState *);
    void func_80099B94(PlayerState *arg0);
    s32 func_8009E6EC();
    s32 func_80800168_bsbansack(BtIntPtr);
    if (func_8009E6EC() == 0xC) {
        if (anctrl_getAnimTimer(baanim_getAnimCtrlPtr(arg0)) > 0.42f) {
            func_80099B94(arg0);
        }
    } else {
        func_80800168_bsbansack(arg0);
    }
}

void func_8080077C_bsbansack(BtIntPtr arg0)
{
    void baphysics_reset_gravity(PlayerState *);
    baphysics_reset_gravity(arg0);
    func_80800238_bsbansack(arg0);
}
void func_808007A4_bsbansack(PlayerState *arg0) {
    void baphysics_set_gravity(PlayerState *, f32);
    void baphysics_set_vertical_velocity(PlayerState *, f32);
    void func_8009FFD8(PlayerState *, s32, s32, s32, s32);
    func_808002D4_bsbansack(arg0);
    baanim_playForDuration_onceSmooth(arg0, 0x28A, 1.0f);
    func_8009FFD8(arg0, 1, 1, 3, 6);
    baphysics_set_gravity(arg0, -800.0f);
    baphysics_set_vertical_velocity(arg0, 300.0f);
}

void func_80800810_bsbansack(PlayerState *arg0) {
    void _babackpack_set_state(void *, s32);
    f32 anctrl_getAnimTimer(BtIntPtr);
    int anctrl_isAt(struct anctrl_s *, f32);
    struct anctrl_s *baanim_getAnimCtrlPtr(PlayerState *);
    int baanim_isStopped(PlayerState *);
    void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
    s32 bastick_getZone(PlayerState *);
    void bs_setState(PlayerState *, int);
    f32 func_80096364(PlayerState *);
    f32 func_800964DC(PlayerState *);
    void func_8009DBF0(PlayerState *, s32, f32);
    void func_8009DE38(PlayerState *, s32, f32);
    void func_8009FE58(PlayerState *);
    void func_800A0CD0(void *, s32);
    s32 player_inWater(PlayerState *);
    struct anctrl_s *sp2C;
    s32 sp28;
    s32 sp24;
    f32 sp20;

    sp2C = baanim_getAnimCtrlPtr(arg0);
    sp28 = 0;
    if (anctrl_isAt(sp2C, 0.2f)) {
        func_8009DE38(arg0, 0x583, 1.1f);
    }
    if (anctrl_isAt(sp2C, 0.2f)) {
        func_8009DBF0(arg0, 0x3FF, 0.9f);
    }
    if (anctrl_isAt(sp2C, 0.73f)) {
        func_8009FE58(arg0);
    }
    if (anctrl_isAt(sp2C, 0.77f)) {
        func_8009DE38(arg0, 0x584, 1.1f);
    }
    if (anctrl_getAnimTimer(sp2C) < 0.515f) {
        func_808001D4_bsbansack(arg0);
    } else {
        baphysics_set_target_horizontal_velocity(arg0, 0.0f);
    }
    if (anctrl_isAt(sp2C, 0.7307f)) {
        _babackpack_set_state(arg0, 1);
        func_800A0CD0(arg0, 1);
    }
    if (baanim_isStopped(arg0)) {
        sp28 = 1;
    }
    if (anctrl_getAnimTimer(sp2C) > 0.8f && bastick_getZone(arg0) > 0) {
        sp28 = 4;
    }
    if (anctrl_getAnimTimer(sp2C) > 0.95f && player_inWater(arg0)) {
        sp20 = func_800964DC(arg0);
        if (sp20 - func_80096364(arg0) > 80.0f) {
            sp28 = 0x4C;
        }
    }
    bs_setState(arg0, sp28);
}

BsScript bsbansack_entrypoint_2(BsScriptType arg0) {
    extern BtIntPtr D_80801E30_bsbansack[];
    return (BsScript)D_80801E30_bsbansack[arg0];
}

/* extern */

void func_80800A14_bsbansack(PlayerState *arg0) {
    f32 baphysics_get_vertical_velocity(PlayerState *);
    void baphysics_set_vertical_velocity(PlayerState *, f32);
    if ((arg0->unk15C.bytes[1]) == 0) {
        (arg0->unk15C.bytes[1]) = 1U;
        if (baphysics_get_vertical_velocity(arg0) < 0.0f) {
            baphysics_set_vertical_velocity(arg0, 0.0f);
        }
        func_808003C0_bsbansack(arg0);
    }
}

void func_80800A78_bsbansack(BtIntPtr arg0) {
    if (*((u8 *)arg0 + 0x15D) != 0) {
        *((u8 *)arg0 + 0x15D) = 0;
        func_80800400_bsbansack(arg0);
    }
}

int func_80800AA4_bsbansack(PlayerState *arg0) {
    f32 baphysics_get_vertical_velocity(PlayerState *);
    s32 player_inWater(PlayerState *);
    return player_inWater(arg0) && baphysics_get_vertical_velocity(arg0) < 0.0f;
}

void func_80800AF4_bsbansack(PlayerState *arg0, s32 arg1) {
    void anctrl_reset(BtIntPtr);
    void anctrl_setDuration(BtIntPtr, f32);
    void anctrl_setIndex(BtIntPtr, s32);
    void anctrl_setPlaybackType(void *arg0, s32 arg1);
    void anctrl_setSubrange(BtIntPtr, f32, f32);
    void anctrl_start(void *control);
    struct anctrl_s *baanim_getAnimCtrlPtr(PlayerState *);
    void baanim_setEndAndDuration(void *, f32, f32);
    void baphysics_reset_gravity(PlayerState *);
    void baphysics_set_gravity(PlayerState *, f32);
    void baphysics_set_horizontal_velocity(PlayerState *, f32, f32);
    void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
    void baphysics_set_target_yaw(PlayerState *, f32);
    void baphysics_set_vertical_velocity(PlayerState *, f32);
    void baroll_setIdeal(PlayerState *self, f32 arg1);
    f32 bastick_distance(PlayerState *);
    f32 bastick_getAngleRelativeToBanjo(PlayerState *);
    f32 func_8009BB5C(PlayerState *);
    void func_8009BF5C(PlayerState *, f32);
    void func_8009D2D8(PlayerState *, s32);
    void func_8009DB04(BtIntPtr, s32, f32, s32);
    void func_8009FFD8(PlayerState *, s32, s32, s32, s32);
    s32 func_800A2FCC(PlayerState *arg0, s32 arg1);
    f32 func_800DC178(f32, f32);
    s32 player_inWater(PlayerState *);
    f32 yaw_getIdeal(PlayerState *);
    void yaw_setIdeal(PlayerState *, f32);
    struct anctrl_s *control;
    f32 velocity;

    arg0->unk15C.bytes[0] = arg1;
    switch (arg1) {
    case 1:
        control = baanim_getAnimCtrlPtr(arg0);
        func_80800A78_bsbansack((BtIntPtr)arg0);
        func_8009DB04(arg0, 0x3F0, func_800DC178(0.96f, 1.04f), 0x2710);
        func_8009FFD8(arg0, 1, 1, 1, 2);
        baphysics_set_gravity(arg0, -1350.0f);
        if (bastick_distance(arg0) != 0.0f) {
            yaw_setIdeal(arg0, bastick_getAngleRelativeToBanjo(arg0));
        }
        velocity = func_8009BB5C(arg0);
        baphysics_set_target_horizontal_velocity(arg0, velocity);
        baphysics_set_target_yaw(arg0, yaw_getIdeal(arg0));
        baphysics_set_horizontal_velocity(arg0, yaw_getIdeal(arg0), velocity);
        anctrl_reset(control);
        anctrl_setIndex(control, 0x144);
        anctrl_setSubrange(control, 0.0f, 0.35f);
        anctrl_setDuration(control, 0.7f);
        anctrl_setPlaybackType(control, 1);
        anctrl_start(control);
        baphysics_set_vertical_velocity(arg0, 710.0f);
        break;
    case 2:
        baanim_setEndAndDuration(arg0, 0.65f, 3.0f);
        break;
    case 3:
        if (player_inWater(arg0)) {
            func_80800A14_bsbansack(arg0);
        }
        baanim_setEndAndDuration(arg0, 0.98f, 0.7f);
        break;
    case 4:
        if (player_inWater(arg0)) {
            func_80800A14_bsbansack(arg0);
        }
        func_8009D2D8(arg0, 3);
        func_800A2FCC(arg0, 0);
        baanim_setEndAndDuration(arg0, 0.98f, 0.7f);
        break;
    case 0:
        func_80800A78_bsbansack((BtIntPtr)arg0);
        baphysics_reset_gravity(arg0);
        func_8009BF5C(arg0, 0.0f);
        baroll_setIdeal(arg0, 0.0f);
        break;
    }
}

void func_80800D4C_bsbansack(BtIntPtr arg0)
{
    func_80800AF4_bsbansack(arg0,0);
    func_80800238_bsbansack(arg0);
}

void func_80800D78_bsbansack(PlayerState *arg0) { func_808002D4_bsbansack(arg0); arg0->unk15C.bytes[1] = 0; arg0->unk15C.bytes[0] = 0; func_80800AF4_bsbansack(arg0, 1); }

void func_80800DAC_bsbansack(PlayerState *arg0) {
    struct anctrl_s *baanim_getAnimCtrlPtr(PlayerState *);
    int baanim_isAt(PlayerState *, f32);
    s32 anctrl_isStopped(struct anctrl_s *);
    int bakey_released(PlayerState *, int);
    f32 baphysics_get_vertical_velocity(PlayerState *);
    void baphysics_reset_gravity(PlayerState *);
    f32 baphysics_get_target_horizontal_velocity(PlayerState *);
    void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
    s32 func_8008DF8C(PlayerState *, s32);
    s32 func_8008E260(PlayerState *);
    void func_8009D7A4(PlayerState *, f32, f32);
    s32 player_isStable(PlayerState *);
    s32 player_inWater(PlayerState *);
    void bs_setState(PlayerState *, int);
    s32 sp24;
    struct anctrl_s *sp20;

    sp24 = 0;
    sp20 = baanim_getAnimCtrlPtr(arg0);
    if (bakey_released(arg0, 8) && baphysics_get_vertical_velocity(arg0) > 0.0f) {
        baphysics_reset_gravity(arg0);
    }
    func_808001D4_bsbansack(arg0);
    switch (arg0->unk15C.bytes[0]) {
    case 1:
        if (baanim_isAt(arg0, 0.1f)) {
            func_8009D7A4(arg0, 0.95f, 1.05f);
        }
        if (func_8008DF8C(arg0, 0x82) || func_80800AA4_bsbansack(arg0)) {
            func_80800AF4_bsbansack(arg0, 3);
        } else if (anctrl_isStopped(sp20)) {
            func_80800AF4_bsbansack(arg0, 2);
        }
        sp24 = func_80800000_bsbansack(arg0, 0, 0);
        break;
    case 2:
        if (func_8008DF8C(arg0, 0x5A) || func_80800AA4_bsbansack(arg0)) {
            func_80800AF4_bsbansack(arg0, 3);
        }
        sp24 = func_80800000_bsbansack(arg0, 0, 0);
        break;
    case 3:
        func_80800368_bsbansack(arg0);
        if (player_isStable(arg0) || player_inWater(arg0)) {
            func_80800AF4_bsbansack(arg0, 4);
        }
        sp24 = func_80800000_bsbansack(arg0, 0, 0);
        break;
    case 4:
        func_80800368_bsbansack(arg0);
        if (anctrl_isStopped(sp20)) {
            if (baphysics_get_target_horizontal_velocity(arg0) > 0.0f) {
                sp24 = 0x166;
            } else if (player_inWater(arg0)) {
                sp24 = 0x167;
            } else {
                sp24 = 0x165;
            }
        } else {
            baphysics_set_target_horizontal_velocity(arg0, 0.0f);
        }
        sp24 = func_80800084_bsbansack(arg0, sp24);
        break;
    }
    if (func_8008E260(arg0)) {
        sp24 = 0x3D;
    }
    bs_setState(arg0, sp24);
}

BsScript bsbansack_entrypoint_3(BsScriptType arg0) {
    extern BtIntPtr D_80801E40_bsbansack[];
    return (BsScript)D_80801E40_bsbansack[arg0];
}

void func_8080101C_bsbansack(PlayerState *arg0, s32 arg1) {
    void _batimer_set(PlayerState *, s32, f32);
    f32 func_80092BE8(PlayerState *);
    void func_800931AC(PlayerState *, s32);
    void func_8009328C(PlayerState *, f32);
    f32 func_800F1DCC(f32, f32);
    void yaw_applyIdeal(PlayerState *);
    f32 yaw_get(PlayerState *);
    void yaw_setIdeal(PlayerState *, f32);
    f32 angle;
    f32 difference;

    switch (arg1) {
    case 0:
        yaw_setIdeal(arg0, arg0->unk174);
        yaw_applyIdeal(arg0);
        func_800931AC(arg0, 1);
        break;
    case 1:
        angle = yaw_get(arg0);
        arg0->unk174 = angle;
        func_8009328C(arg0, angle);
        func_800931AC(arg0, 3);
        _batimer_set(arg0, 0, 1.2f);
        break;
    case 2:
        angle = func_80092BE8(arg0);
        arg0->unk170 = angle;
        angle = func_800F1DCC(arg0->unk174, angle);
        difference = angle;
        if (angle < 0.0f) {
            difference = 360.0f + angle;
        }
        if (difference < 180.0f) {
            difference += 360.0f;
        }
        arg0->unk174 = arg0->unk170 + difference;
        _batimer_set(arg0, 0, 0.5f);
        break;
    }
    *(s8 *)((u8 *)arg0 + 0x15C) = arg1;
}

void func_80801158_bsbansack(BtIntPtr arg0)
{
    func_8080101C_bsbansack(arg0,0);
}

void func_80801178_bsbansack(PlayerState *arg0) { arg0->unk15C.bytes[0] = 0; func_8080101C_bsbansack(arg0, 1); }

s32 func_8080119C_bsbansack(PlayerState *arg0) {
    int _batimer_decrement(PlayerState *, s32);
    f32 _batimer_get(PlayerState *, s32);
    f32 func_80013970(f32);
    s32 func_8008DF8C(PlayerState *, s32);
    f32 func_80092BE8(PlayerState *);
    void func_8009328C(PlayerState *, f32);
    f32 func_800D8FF8(void);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    f32 difference;
    f32 phase;
    f32 speed;
    f32 delta;
    f32 angle;

    angle = func_80092BE8(arg0);
    delta = func_800D8FF8();
    _batimer_decrement(arg0, 0);
    switch (arg0->unk15C.bytes[0]) {
    case 1:
        speed = func_800F10B4(_batimer_get(arg0, 0), 0.0f, 1.2f, 700.0f, 1400.0f);
        angle += speed * delta;
        func_8009328C(arg0, angle);
        if (func_8008DF8C(arg0, 1) != 0) {
            arg0->unk16C = speed;
            func_8080101C_bsbansack(arg0, 2);
        }
        return 0;
    case 2:
        phase = func_800F10B4(_batimer_get(arg0, 0), 0.0f, 0.5f, 1.0f, 0.0f) * 90.0f;
        difference = arg0->unk174 - arg0->unk170;
        angle = func_80013970(phase) * difference;
        angle += arg0->unk170;
        func_8009328C(arg0, angle);
        if (_batimer_get(arg0, 0) != 0.0f) {
            return 0;
        }
        return 1;
    default:
        return 0;
    }
}

void func_80801318_bsbansack(BtIntPtr arg0)
{
    func_80801158_bsbansack(arg0);
    _babounce_entrypoint_3(arg0);
    func_80800238_bsbansack(arg0);
}

/* extern */

void func_80801348_bsbansack(PlayerState *arg0) { func_808002D4_bsbansack(arg0); baanim_playForDuration_onceSmooth(arg0, 0x28C, 1.2f); _babounce_entrypoint_4(arg0, 1); func_80801178_bsbansack(arg0); }

void func_80801390_bsbansack(PlayerState *arg0) {
    s32 _babounce_entrypoint_10();
    BT_IDO_ONLY(s32 _babounce_entrypoint_2();)
    s32 bastick_getZone(PlayerState *);
    void bs_setState(PlayerState *, int);
    s32 func_8008DF8C(PlayerState *, s32);
    s32 func_8080119C_bsbansack(PlayerState *);
    s32 var_s1;

    var_s1 = 0;
    if (_babounce_entrypoint_2(BT_NATIVE_ONLY(arg0)) != 0) {
        func_808001D4_bsbansack(arg0);
    }
    _babounce_entrypoint_10(arg0);
    if (func_8080119C_bsbansack(arg0) != 0) {
        var_s1 = 0x165;
    }
    if (func_8008DF8C(arg0, 1) != 0) {
        if (bastick_getZone(arg0) > 0) {
            var_s1 = 0x166;
        }
        var_s1 = func_80800084_bsbansack(arg0, var_s1);
    }
    bs_setState(arg0, var_s1);
}

BsScript bsbansack_entrypoint_4(BsScriptType arg0) {
    extern BtIntPtr D_80801E50_bsbansack[];
    return (BsScript)D_80801E50_bsbansack[arg0];
}

void func_8080143C_bsbansack(BtIntPtr arg0)
{
    func_80801158_bsbansack(arg0);
    _babounce_entrypoint_3(arg0);
    func_80800238_bsbansack(arg0);
}

/* extern */

void func_8080146C_bsbansack(PlayerState *arg0) { func_808002D4_bsbansack(arg0); baanim_playForDuration_onceSmooth(arg0, 0x28C, 1.2f); _babounce_entrypoint_4(arg0, 2); func_80801178_bsbansack(arg0); }

void func_808014B4_bsbansack(PlayerState *arg0) {
    s32 _babounce_entrypoint_10();
    BT_IDO_ONLY(s32 _babounce_entrypoint_2();)
    s32 bastick_getZone(PlayerState *);
    void bs_setState(PlayerState *, int);
    s32 func_8008DF8C(PlayerState *, s32);
    s32 func_8080119C_bsbansack(PlayerState *);
    s32 var_s1;

    var_s1 = 0;
    if (_babounce_entrypoint_2(BT_NATIVE_ONLY(arg0)) != 0) {
        func_808001D4_bsbansack(arg0);
    }
    _babounce_entrypoint_10(arg0);
    if (func_8080119C_bsbansack(arg0) != 0) {
        var_s1 = 0x165;
    }
    if (func_8008DF8C(arg0, 1) != 0) {
        if (bastick_getZone(arg0) > 0) {
            var_s1 = 0x166;
        }
        var_s1 = func_80800084_bsbansack(arg0, var_s1);
    }
    bs_setState(arg0, var_s1);
}

BsScript bsbansack_entrypoint_5(BsScriptType arg0) {
    extern BtIntPtr D_80801E60_bsbansack[];
    return (BsScript)D_80801E60_bsbansack[arg0];
}

#ifdef BT_NATIVE
struct player_state_s;
void _bsdrone_entrypoint_2(struct player_state_s *);
#endif

void func_80801560_bsbansack(BT_NATIVE_ONLY(struct player_state_s *) BT_IDO_ONLY(BtIntPtr) arg0)
{
    _bsdrone_entrypoint_2(BT_NATIVE_ONLY(arg0));
    func_80800238_bsbansack(arg0);
}
void func_80801588_bsbansack(PlayerState *arg0)
{
    func_808002D4_bsbansack(arg0);
    _bsdrone_entrypoint_0(arg0);
}
void func_808015B0_bsbansack(PlayerState* self)
{
    _bsdrone_entrypoint_1(self);
}
BsScript bsbansack_entrypoint_6(BsScriptType arg0) {
    extern BtIntPtr D_80801E70_bsbansack[];
    return (BsScript)D_80801E70_bsbansack[arg0];
}

void func_808015E4_bsbansack(BtIntPtr arg0)
{
    _bsrest_entrypoint_14(BT_NATIVE_ONLY((struct player_state_s *)arg0));
    func_80800238_bsbansack(arg0);
}
void func_8080160C_bsbansack(PlayerState *arg0)
{
    func_808002D4_bsbansack(arg0);
    _bsrest_entrypoint_16(arg0);
}
/* extern */

void func_80801634_bsbansack(BtIntPtr arg0) {
    void bs_setState(PlayerState *, int);
    BT_IDO_ONLY(s32 _bsrest_entrypoint_20();)
    s32 sp1C;

    sp1C = 0;
    if (_bsrest_entrypoint_20(BT_NATIVE_ONLY((struct player_state_s *)arg0)) != 0) {
        sp1C = 0x165;
    }
    bs_setState(arg0, sp1C);
}

BsScript bsbansack_entrypoint_7(BsScriptType arg0) {
    extern BtIntPtr D_80801E80_bsbansack[];
    return (BsScript)D_80801E80_bsbansack[arg0];
}

void func_80801680_bsbansack(BtIntPtr arg0, s32 arg1) {
    void anctrl_reset(BtIntPtr);
    void anctrl_setDuration(BtIntPtr, f32);
    void anctrl_setIndex(BtIntPtr, s32);
    void anctrl_setPlaybackType(void *arg0, s32 arg1);
    void anctrl_setSubrange(BtIntPtr, f32, f32);
    void anctrl_start(void *control);
    struct anctrl_s *baanim_getAnimCtrlPtr(PlayerState *);
    void baanim_setEndAndDuration(void *, f32, f32);
    f32 baphysics_get_target_horizontal_velocity(PlayerState *);
    void baphysics_set_horizontal_velocity(PlayerState *, f32, f32);
    void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
    void baphysics_set_target_yaw(PlayerState *, f32);
    void baphysics_set_vertical_velocity(PlayerState *, f32);
    void baroll_setIdeal(PlayerState *self, f32 arg1);
    f32 bastick_distance(PlayerState *);
    f32 bastick_getAngleRelativeToBanjo(PlayerState *);
    f32 func_8009BB5C(PlayerState *);
    void func_8009BF5C(PlayerState *, f32);
    void func_8009D2D8(PlayerState *, s32);
    void func_8009DB04(BtIntPtr, s32, f32, s32);
    void func_80800A78_bsbansack();
    void func_8009FFD8(PlayerState *, s32, s32, s32, s32);
    void func_800A2EEC(BtIntPtr, s32);
    s32 func_800A2FCC(PlayerState *arg0, s32 arg1);
    f32 func_800DC178(f32, f32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    s32 player_inWater(PlayerState *);
    s32 player_isStable(PlayerState *);
    f32 yaw_getIdeal(PlayerState *);
    void yaw_setIdeal(PlayerState *, f32);
    BtIntPtr sp4C;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    s32 sp3C;
    s32 sp30;
    f32 sp34;

    ((u8 *)arg0)[0x15C] = arg1;
    switch (arg1) {
    case 1:
        sp4C = baanim_getAnimCtrlPtr(arg0);
        sp3C = player_inWater((PlayerState *)arg0);
        sp30 = player_isStable((PlayerState *)arg0) || sp3C;
#ifdef BT_NATIVE
        ((void (*)())func_80800A78_bsbansack)(arg0, sp3C, sp30);
#else
        func_80800A78_bsbansack(arg0, sp3C, sp30);
#endif
        func_8009DB04(arg0, 0x3F0, func_800DC178(0.96f, 1.04f), 0x2710);
        func_800A2EEC(arg0, 4);
        func_8009FFD8((PlayerState *)arg0, 1, 1, 1, 2);
        if (bastick_distance((PlayerState *)arg0) != 0.0f) {
            yaw_setIdeal((PlayerState *)arg0, bastick_getAngleRelativeToBanjo((PlayerState *)arg0));
        }
        func_808001D4_bsbansack(arg0);
        sp48 = baphysics_get_target_horizontal_velocity((PlayerState *)arg0);
        if (sp3C != 0) {
            sp44 = func_800F10B4(sp48, 100.0f, 500.0f, 0.35f, 0.42000002f);
            sp40 = func_800F10B4(sp48, 100.0f, 500.0f, 346.75f, 416.1f);
        } else {
            sp44 = func_800F10B4(sp48, 100.0f, 500.0f, 0.35f, 0.7f);
            sp40 = func_800F10B4(sp48, 100.0f, 500.0f, 346.75f, 693.5f);
        }
        baphysics_set_target_yaw((PlayerState *)arg0, yaw_getIdeal((PlayerState *)arg0));
        baphysics_set_horizontal_velocity((PlayerState *)arg0, yaw_getIdeal((PlayerState *)arg0), sp48);
        anctrl_reset(sp4C);
        anctrl_setIndex(sp4C, 0x144);
        anctrl_setSubrange(sp4C, 0.0f, 0.6466f);
        anctrl_setDuration(sp4C, sp44);
        anctrl_setPlaybackType((BtIntPtr)sp4C, 1);
        anctrl_start((BtIntPtr)sp4C);
        if (sp30 != 0) {
            baphysics_set_vertical_velocity((PlayerState *)arg0, sp40);
        }
        break;
    case 2:
        baanim_setEndAndDuration((void *)arg0, 0.7965f, 3.0f);
        break;
    case 3:
        if (player_inWater((PlayerState *)arg0) != 0) {
            func_80800A14_bsbansack(arg0);
        }
        baanim_setEndAndDuration((void *)arg0, 0.98f, 0.7f);
        break;
    case 4:
        sp34 = 1.0f;
        *(f32 *)(arg0 + 0x16C) = func_8009BB5C((PlayerState *)arg0) * 0.25f;
        func_8009D2D8((PlayerState *)arg0, 3);
        baphysics_set_target_horizontal_velocity((PlayerState *)arg0, *(f32 *)(arg0 + 0x16C));
        func_800A2FCC(arg0, 0);
        if (player_inWater((PlayerState *)arg0) != 0) {
            func_80800A14_bsbansack(arg0);
            sp34 = 0.4f;
        }
        baanim_setEndAndDuration((void *)arg0, 0.98f, 0.7f * sp34);
        break;
    case 0:
        func_80800A78_bsbansack(arg0);
        func_8009BF5C((PlayerState *)arg0, 0.0f);
        baroll_setIdeal(arg0, 0.0f);
        break;
    }
}

void func_80801A04_bsbansack(BtIntPtr arg0)
{
    func_80801680_bsbansack(arg0,0);
    func_80800238_bsbansack(arg0);
}

void func_80801A30_bsbansack(PlayerState *arg0) { func_808002D4_bsbansack(arg0); arg0->unk15C.bytes[1] = 0; arg0->unk15C.bytes[0] = 0; func_80801680_bsbansack(arg0, 1); }

void func_80801A64_bsbansack(PlayerState *arg0) {
    struct anctrl_s *baanim_getAnimCtrlPtr(PlayerState *);
    int baanim_isAt(PlayerState *, f32);
    s32 anctrl_isStopped(struct anctrl_s *);
    s32 func_8008DF8C(PlayerState *, s32);
    s32 func_8008E260(PlayerState *);
    void func_8009DEC0(PlayerState *, s32, f32, f32, s32, s32);
    f32 baphysics_get_target_horizontal_velocity(PlayerState *);
    void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
    s32 player_isStable(PlayerState *);
    s32 player_inWater(PlayerState *);
    void bs_setState(PlayerState *, int);
    s32 sp2C;
    struct anctrl_s *sp28;

    sp2C = 0;
    sp28 = baanim_getAnimCtrlPtr(arg0);
    func_808001D4_bsbansack(arg0);
    switch (arg0->unk15C.bytes[0]) {
    case 1:
        if (baanim_isAt(arg0, 0.05f)) {
            func_8009DEC0(arg0, 0x58A, 0.95f, 1.05f, 0x2328, 0x2AF8);
        }
        if (func_8008DF8C(arg0, 0x82) || func_80800AA4_bsbansack(arg0)) {
            func_80801680_bsbansack((BtIntPtr)arg0, 3);
        } else if (anctrl_isStopped(sp28)) {
            func_80801680_bsbansack((BtIntPtr)arg0, 2);
        }
        sp2C = func_80800000_bsbansack(arg0, 0, 1);
        break;
    case 2:
        if (func_8008DF8C(arg0, 0x82) || func_80800AA4_bsbansack(arg0)) {
            func_80801680_bsbansack((BtIntPtr)arg0, 3);
        }
        sp2C = func_80800000_bsbansack(arg0, 0, 1);
        break;
    case 3:
        func_80800368_bsbansack(arg0);
        if (player_isStable(arg0) || player_inWater(arg0)) {
            func_80801680_bsbansack((BtIntPtr)arg0, 4);
        }
        sp2C = func_80800000_bsbansack(arg0, 0, 1);
        break;
    case 4:
        func_80800368_bsbansack(arg0);
        if (anctrl_isStopped(sp28)) {
            if (baphysics_get_target_horizontal_velocity(arg0) > 0.0f) {
                func_80801680_bsbansack((BtIntPtr)arg0, 1);
            } else if (player_inWater(arg0)) {
                sp2C = 0x167;
            } else {
                sp2C = 0x165;
            }
        } else {
            baphysics_set_target_horizontal_velocity(arg0, arg0->unk16C);
        }
        sp2C = func_80800084_bsbansack(arg0, sp2C);
        break;
    }
    if (func_8008E260(arg0)) {
        sp2C = 0x3D;
    }
    bs_setState(arg0, sp2C);
}

BsScript bsbansack_entrypoint_8(BsScriptType arg0) {
    extern BtIntPtr D_80801E90_bsbansack[];
    return (BsScript)D_80801E90_bsbansack[arg0];
}

void func_80801CB4_bsbansack(PlayerState *arg0)
{
    func_80800238_bsbansack(arg0);
}

void func_80801CD4_bsbansack(PlayerState *arg0) {
    void baanim_playForDuration_loopSmooth(PlayerState *, s32, f32);
    void func_8009FFD8(PlayerState *, s32, s32, s32, s32);
    func_808002D4_bsbansack(arg0);
    baanim_playForDuration_loopSmooth(arg0, 0x289, 1.0f);
    func_8009FFD8(arg0, 1, 1, 1, 2);
}

/* extern */

void func_80801D20_bsbansack(PlayerState *arg0) {
    s32 bastick_getZone();
    void bs_setState(PlayerState *, int);
    s32 func_8008E260(PlayerState *);
    s32 player_inWater(PlayerState *);
    s32 var_s0;

    var_s0 = 0;
    if (bastick_getZone(arg0) > 0) {
        var_s0 = 0x166;
    }
    if (player_inWater(arg0) != 0) {
        var_s0 = 0x167;
    }
    var_s0 = func_80800084_bsbansack(arg0, var_s0);
    if (func_8008E260(arg0) != 0) {
        var_s0 = 0x3D;
    }
    bs_setState(arg0, var_s0);
}

BsScript bsbansack_entrypoint_9(BsScriptType arg0) {
    extern BtIntPtr D_80801EA0_bsbansack[];
    return (BsScript)D_80801EA0_bsbansack[arg0];
}
/* data_to_c.py: from asm/data/overlays/bs/ban/sack.data.s */
BtIntPtr D_80801E10_bsbansack [4] BT_DATA(4, overlays_bs_ban_sack, 0x0) = { (BtIntPtr)func_80800434_bsbansack, (BtIntPtr)func_8080045C_bsbansack, (BtIntPtr)func_808004B0_bsbansack, (BtIntPtr)func_80800168_bsbansack };
BtIntPtr D_80801E20_bsbansack [4] BT_DATA(4, overlays_bs_ban_sack, 0x10) = { (BtIntPtr)func_80800508_bsbansack, (BtIntPtr)func_80800540_bsbansack, (BtIntPtr)func_808005BC_bsbansack, (BtIntPtr)func_80800168_bsbansack };
BtIntPtr D_80801E30_bsbansack [4] BT_DATA(4, overlays_bs_ban_sack, 0x20) = { (BtIntPtr)func_8080077C_bsbansack, (BtIntPtr)func_808007A4_bsbansack, (BtIntPtr)func_80800810_bsbansack, (BtIntPtr)func_80800710_bsbansack };
BtIntPtr D_80801E40_bsbansack [4] BT_DATA(4, overlays_bs_ban_sack, 0x30) = { (BtIntPtr)func_80800D4C_bsbansack, (BtIntPtr)func_80800D78_bsbansack, (BtIntPtr)func_80800DAC_bsbansack, (BtIntPtr)func_80800168_bsbansack };
BtIntPtr D_80801E50_bsbansack [4] BT_DATA(4, overlays_bs_ban_sack, 0x40) = { (BtIntPtr)func_80801318_bsbansack, (BtIntPtr)func_80801348_bsbansack, (BtIntPtr)func_80801390_bsbansack, (BtIntPtr)func_808001B0_bsbansack };
BtIntPtr D_80801E60_bsbansack [4] BT_DATA(4, overlays_bs_ban_sack, 0x50) = { (BtIntPtr)func_8080143C_bsbansack, (BtIntPtr)func_8080146C_bsbansack, (BtIntPtr)func_808014B4_bsbansack, (BtIntPtr)func_808001B0_bsbansack };
BtIntPtr D_80801E70_bsbansack [4] BT_DATA(4, overlays_bs_ban_sack, 0x60) = { (BtIntPtr)func_80801560_bsbansack, (BtIntPtr)func_80801588_bsbansack, (BtIntPtr)func_808015B0_bsbansack, (BtIntPtr)func_8080018C_bsbansack };
BtIntPtr D_80801E80_bsbansack [4] BT_DATA(4, overlays_bs_ban_sack, 0x70) = { (BtIntPtr)func_808015E4_bsbansack, (BtIntPtr)func_8080160C_bsbansack, (BtIntPtr)func_80801634_bsbansack, (BtIntPtr)func_80800168_bsbansack };
BtIntPtr D_80801E90_bsbansack [4] BT_DATA(4, overlays_bs_ban_sack, 0x80) = { (BtIntPtr)func_80801A04_bsbansack, (BtIntPtr)func_80801A30_bsbansack, (BtIntPtr)func_80801A64_bsbansack, (BtIntPtr)func_80800168_bsbansack };
BtIntPtr D_80801EA0_bsbansack [4] BT_DATA(4, overlays_bs_ban_sack, 0x90) = { (BtIntPtr)func_80801CB4_bsbansack, (BtIntPtr)func_80801CD4_bsbansack, (BtIntPtr)func_80801D20_bsbansack, (BtIntPtr)func_80800168_bsbansack };
