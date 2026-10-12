#include "common.h"

/* extern */

s32 func_80800000_bsbtrot(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 func_8008E3E8(s32);
    s32 func_8008E40C();
    s32 func_8008E430(s32);
    if (func_8008E40C() != 0) {
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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/btrot/func_80800070_bsbtrot.s")

/* extern */

typedef struct PlayerState PlayerState;

void func_808000DC_bsbtrot(PlayerState *arg0, s32 arg1) {
    void func_8009DE38(PlayerState *, s32, f32);
    if (arg1 != 0) {
        func_8009DE38(arg0, 0x4433, 0.96f);
        return;
    }
    func_8009DE38(arg0, 0x4433, 1.04f);
}

void func_80800120_bsbtrot(s32 arg0) {
    s32 _bashoes_entrypoint_6(s32, s32);
    s32 bakey_pressed(s32, s32);
    s32 func_8008E39C();
    if ((bakey_pressed(arg0, 9) != 0) && (func_8008E39C(arg0) != 0)) {
        _bashoes_entrypoint_6(arg0, 2);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/btrot/func_80800164_bsbtrot.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/btrot/func_808001B8_bsbtrot.s")

/* extern */

f32 func_808001EC_bsbtrot(s32 arg0) {
    s32 func_8008DE24();
    f32 func_80800070_bsbtrot(s32, s32, s32, s32, f32);
    if (func_8008DE24() != 0) {
        return 0.7f;
    }
    return func_80800070_bsbtrot(arg0, 0x3EAE147B, 0x3E947AE1, 0x3F333333, 0.53f);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/btrot/func_80800248_bsbtrot.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/btrot/func_808002A4_bsbtrot.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/btrot/func_80800438_bsbtrot.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/btrot/func_808004B4_bsbtrot.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/btrot/func_80800538_bsbtrot.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/btrot/bsbtrot_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/btrot/bsbtrot_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/btrot/bsbtrot_entrypoint_2.s")

s32 bsbtrot_entrypoint_3(s32 arg0) {
    extern s32 D_80802E50_bsbtrot[];
    return ((s32 *)&D_80802E50_bsbtrot)[arg0];
}

void func_80800C20_bsbtrot(s32 arg0) {
    func_80800000_bsbtrot(arg0, 0x26, 0x26, 0x29B, 0x86);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/btrot/bsbtrot_entrypoint_4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/btrot/bsbtrot_entrypoint_5.s")

void bsbtrot_entrypoint_6()
{
    func_8080061C_bsbtrot();
}

s32 bsbtrot_entrypoint_7(s32 arg0) {
    extern s32 D_80802E60_bsbtrot[];
    return ((s32 *)&D_80802E60_bsbtrot)[arg0];
}

void func_80800DC4_bsbtrot(s32 arg0) {
    func_80800000_bsbtrot(arg0, 0x15, 0x44, 0x29C, 0xA1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/btrot/func_80800DF4_bsbtrot.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/btrot/bsbtrot_entrypoint_8.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/btrot/bsbtrot_entrypoint_16.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/btrot/bsbtrot_entrypoint_17.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/btrot/bsbtrot_entrypoint_18.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/btrot/bsbtrot_entrypoint_24.s")

void bsbtrot_entrypoint_25(void *arg0) {
    s32 func_8008E3E8(s32);
    s32 bakey_pressed(s32, s32);
    s32 baanim_getAnimCtrlPtr();
    void anctrl_setSubrange(s32, f32, f32);
    void anctrl_setDuration(s32, f32);
    s32 anctrl_setPlaybackType(s32, s32);
    s32 anctrl_isStopped(s32);
    f32 baphysics_get_target_horizontal_velocity(void *);
    void func_8009BB24(void *, f32 *);
    s32 next_state;
    s32 anim_ctrl;
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
                anctrl_setPlaybackType((s32)anim_ctrl, 1);
                *(u32 *)((u8 *)arg0 + 0x15C) = 1;
            }
            break;
        case 1:
            func_8009D3A8(arg0, 1);
            if (player_isStable(arg0) != 0) {
                func_8009FE58(arg0);
                anctrl_setSubrange(anim_ctrl, 0.0f, 0.8798f);
                anctrl_setDuration(anim_ctrl, 0.9f);
                anctrl_setPlaybackType((s32)anim_ctrl, 1);
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
                anctrl_setPlaybackType((s32)anim_ctrl, 1);
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
                anctrl_setPlaybackType((s32)anim_ctrl, 1);
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
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/btrot/bsbtrot_entrypoint_29.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/btrot/bsbtrot_entrypoint_30.s")

s32 bsbtrot_entrypoint_31(s32 arg0) {
    extern s32 D_80802EC0_bsbtrot[];
    return ((s32 *)&D_80802EC0_bsbtrot)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/btrot/bsbtrot_entrypoint_32.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/btrot/bsbtrot_entrypoint_33.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/btrot/bsbtrot_entrypoint_34.s")

s32 bsbtrot_entrypoint_35(s32 arg0) {
    extern s32 D_80802ED0_bsbtrot[];
    return ((s32 *)&D_80802ED0_bsbtrot)[arg0];
}

void bsbtrot_entrypoint_36(s32 arg0)
{
    func_808004B4_bsbtrot();
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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/btrot/bsbtrot_entrypoint_40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/btrot/bsbtrot_entrypoint_41.s")

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
    s32 func_80092880(void *, s32);
    s32 func_8009CA70(void *, s32, s32);
    s32 func_800A2018(void *, s32);
    s32 func_800A4DA4(void *, s32);
    if (func_8009CA70(arg0, bs_getPreviousState(), 0x800) == 0) {
        _bashoessuck_entrypoint_3(arg0);
        (*(s32 *)((s8 *)(arg0) + (0x160))) = 1;
        func_80092880(arg0, 0);
        func_800A2018(arg0, 3);
        func_800A4DA4(arg0, 0x19);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/btrot/func_80802A4C_bsbtrot.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/btrot/bsbtrot_entrypoint_48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/btrot/bsbtrot_entrypoint_49.s")

void bsbtrot_entrypoint_50(s32 arg0)
{
    func_80802A4C_bsbtrot();
    func_8080061C_bsbtrot(arg0);
}
s32 bsbtrot_entrypoint_51(s32 arg0) {
    extern s32 D_80802F10_bsbtrot[];
    return ((s32 *)&D_80802F10_bsbtrot)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/btrot/bsbtrot_entrypoint_52.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/btrot/bsbtrot_entrypoint_53.s")

void bsbtrot_entrypoint_54(s32 arg0)
{
    func_80802A4C_bsbtrot();
    func_8080061C_bsbtrot(arg0);
}
s32 bsbtrot_entrypoint_55(s32 arg0) {
    extern s32 D_80802F20_bsbtrot[];
    return ((s32 *)&D_80802F20_bsbtrot)[arg0];
}
