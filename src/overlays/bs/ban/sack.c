#include "common.h"
#include "overlays/ba/playerstate.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/sack/func_80800000_bsbansack.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/sack/func_80800084_bsbansack.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/sack/func_80800100_bsbansack.s")

s32 func_80800168_bsbansack(s32 arg0) {
    s32 func_80800100_bsbansack();
    s32 func_80099B94(s32);
    func_80800100_bsbansack(arg0, &func_80099B94);
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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/sack/func_808001D4_bsbansack.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/sack/func_80800238_bsbansack.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/sack/func_808002D4_bsbansack.s")

void func_80800368_bsbansack(PlayerState *arg0) {
    s32 baroll_setIdeal(s32, f32);
    s32 func_8008DF8C(PlayerState *, s32);
    void func_8009BF5C(PlayerState *, f32);
    void func_8009D2F0(PlayerState *, s32, f32);
    if (func_8008DF8C(arg0, 0x1E) != 0) {
        func_8009D2F0(arg0, 0, 0.5f);
        return;
    }
    func_8009BF5C(arg0, 0.0f);
    baroll_setIdeal((s32) arg0, 0.0f);
}

void func_808003C0_bsbansack(PlayerState *arg0) {
    void baphysics_set_gravity(PlayerState *arg0, f32 arg1);
    void baphysics_set_terminal_velocity(PlayerState *arg0, f32 arg1);
    void func_800961AC(PlayerState *, s32);
    baphysics_set_gravity(arg0, 100.0f);
    baphysics_set_terminal_velocity(arg0, 133.33f);
    func_800961AC(arg0, 3);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/sack/func_80800400_bsbansack.s")

void func_80800434_bsbansack(s32 arg0)
{
    func_80800400_bsbansack();
    func_80800238_bsbansack(arg0);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/sack/func_8080045C_bsbansack.s")

/* extern */

void func_808004B0_bsbansack(s32 arg0) {
    s32 bs_setState(s32, s32);
    s32 bastick_getZone();
    s32 func_80800084_bsbansack(s32, s32);
    s32 var_a1;
    s32 sp1C;

    sp1C = 0;
    var_a1 = sp1C;
    if (bastick_getZone() > 0) {
        var_a1 = 0x166;
    }
    bs_setState(arg0, func_80800084_bsbansack(arg0, var_a1));
}

s32 bsbansack_entrypoint_0(s32 arg0) {
    extern s32 D_80801E10_bsbansack[];
    return ((s32 *)&D_80801E10_bsbansack)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/sack/func_80800508_bsbansack.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/sack/func_80800540_bsbansack.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/sack/func_808005BC_bsbansack.s")

s32 bsbansack_entrypoint_1(s32 arg0) {
    extern s32 D_80801E20_bsbansack[];
    return ((s32 *)&D_80801E20_bsbansack)[arg0];
}

/* extern */

void func_80800710_bsbansack(s32 arg0) {
    f32 anctrl_getAnimTimer(s32);
    s32 baanim_getAnimCtrlPtr(s32);
    s32 func_80099B94(s32);
    s32 func_8009E6EC();
    s32 func_80800168_bsbansack(s32);
    if (func_8009E6EC() == 0xC) {
        if (anctrl_getAnimTimer(baanim_getAnimCtrlPtr(arg0)) > 0.42f) {
            func_80099B94(arg0);
        }
    } else {
        func_80800168_bsbansack(arg0);
    }
}

void func_8080077C_bsbansack(s32 arg0)
{
    baphysics_reset_gravity();
    func_80800238_bsbansack(arg0);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/sack/func_808007A4_bsbansack.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/sack/func_80800810_bsbansack.s")

s32 bsbansack_entrypoint_2(s32 arg0) {
    extern s32 D_80801E30_bsbansack[];
    return ((s32 *)&D_80801E30_bsbansack)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/sack/func_80800A14_bsbansack.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/sack/func_80800A78_bsbansack.s")

int func_80800AA4_bsbansack(PlayerState *arg0) {
    f32 baphysics_get_vertical_velocity(PlayerState *);
    s32 player_inWater(PlayerState *);
    return player_inWater(arg0) && baphysics_get_vertical_velocity(arg0) < 0.0f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/sack/func_80800AF4_bsbansack.s")

void func_80800D4C_bsbansack(s32 arg0)
{
    func_80800AF4_bsbansack(arg0,0);
    func_80800238_bsbansack(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/sack/func_80800D78_bsbansack.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/sack/func_80800DAC_bsbansack.s")

s32 bsbansack_entrypoint_3(s32 arg0) {
    extern s32 D_80801E40_bsbansack[];
    return ((s32 *)&D_80801E40_bsbansack)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/sack/func_8080101C_bsbansack.s")

void func_80801158_bsbansack(s32 arg0)
{
    func_8080101C_bsbansack(arg0,0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/sack/func_80801178_bsbansack.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/sack/func_8080119C_bsbansack.s")

void func_80801318_bsbansack(s32 arg0)
{
    func_80801158_bsbansack(arg0);
    _babounce_entrypoint_3(arg0);
    func_80800238_bsbansack(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/sack/func_80801348_bsbansack.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/sack/func_80801390_bsbansack.s")

s32 bsbansack_entrypoint_4(s32 arg0) {
    extern s32 D_80801E50_bsbansack[];
    return ((s32 *)&D_80801E50_bsbansack)[arg0];
}

void func_8080143C_bsbansack(s32 arg0)
{
    func_80801158_bsbansack(arg0);
    _babounce_entrypoint_3(arg0);
    func_80800238_bsbansack(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/sack/func_8080146C_bsbansack.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/sack/func_808014B4_bsbansack.s")

s32 bsbansack_entrypoint_5(s32 arg0) {
    extern s32 D_80801E60_bsbansack[];
    return ((s32 *)&D_80801E60_bsbansack)[arg0];
}

void func_80801560_bsbansack(s32 arg0)
{
    _bsdrone_entrypoint_2();
    func_80800238_bsbansack(arg0);
}
void func_80801588_bsbansack(s32 arg0)
{
    func_808002D4_bsbansack();
    _bsdrone_entrypoint_0(arg0);
}
void func_808015B0_bsbansack(PlayerState* self)
{
    _bsdrone_entrypoint_1(self);
}
s32 bsbansack_entrypoint_6(s32 arg0) {
    extern s32 D_80801E70_bsbansack[];
    return ((s32 *)&D_80801E70_bsbansack)[arg0];
}

void func_808015E4_bsbansack(s32 arg0)
{
    _bsrest_entrypoint_14();
    func_80800238_bsbansack(arg0);
}
void func_8080160C_bsbansack(s32 arg0)
{
    func_808002D4_bsbansack();
    _bsrest_entrypoint_16(arg0);
}
/* extern */

void func_80801634_bsbansack(s32 arg0) {
    s32 _bsrest_entrypoint_20();
    s32 bs_setState(s32, s32);
    s32 sp1C;

    sp1C = 0;
    if (_bsrest_entrypoint_20() != 0) {
        sp1C = 0x165;
    }
    bs_setState(arg0, sp1C);
}

s32 bsbansack_entrypoint_7(s32 arg0) {
    extern s32 D_80801E80_bsbansack[];
    return ((s32 *)&D_80801E80_bsbansack)[arg0];
}

void func_80801680_bsbansack(s32 arg0, s32 arg1) {
    void anctrl_reset(s32);
    void anctrl_setDuration(s32, f32);
    void anctrl_setIndex(s32, s32);
    s32 anctrl_setPlaybackType(s32, s32);
    void anctrl_setSubrange(s32, f32, f32);
    s32 anctrl_start(s32);
    s32 baanim_getAnimCtrlPtr(s32);
    void baanim_setEndAndDuration(void *, f32, f32);
    f32 baphysics_get_target_horizontal_velocity(PlayerState *);
    void baphysics_set_horizontal_velocity(PlayerState *, f32, f32);
    void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
    void baphysics_set_target_yaw(PlayerState *, f32);
    void baphysics_set_vertical_velocity(PlayerState *, f32);
    s32 baroll_setIdeal(s32, f32);
    f32 bastick_distance(PlayerState *);
    f32 bastick_getAngleRelativeToBanjo(PlayerState *);
    f32 func_8009BB5C(PlayerState *);
    void func_8009BF5C(PlayerState *, f32);
    void func_8009D2D8(PlayerState *, s32);
    void func_8009DB04(s32, s32, f32, s32);
    void func_8009FFD8(PlayerState *, s32, s32, s32, s32);
    void func_800A2EEC(s32, s32);
    void func_800A2FCC(s32, s32);
    f32 func_800DC178(f32, f32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    s32 player_inWater(PlayerState *);
    s32 player_isStable(PlayerState *);
    f32 yaw_getIdeal(PlayerState *);
    void yaw_setIdeal(PlayerState *, f32);
    s32 sp4C;
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
        func_80800A78_bsbansack(arg0, sp3C, sp30);
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
        anctrl_setPlaybackType((s32)sp4C, 1);
        anctrl_start((s32)sp4C);
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

void func_80801A04_bsbansack(s32 arg0)
{
    func_80801680_bsbansack(arg0,0);
    func_80800238_bsbansack(arg0);
}

void func_80801A30_bsbansack(PlayerState *arg0) { func_808002D4_bsbansack(); *(u8 *)((u8 *)arg0 + 0x15D) = 0; *(u8 *)((u8 *)arg0 + 0x15C) = 0; func_80801680_bsbansack(arg0, 1); }

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/sack/func_80801A64_bsbansack.s")

s32 bsbansack_entrypoint_8(s32 arg0) {
    extern s32 D_80801E90_bsbansack[];
    return ((s32 *)&D_80801E90_bsbansack)[arg0];
}

void func_80801CB4_bsbansack()
{
    func_80800238_bsbansack();
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/sack/func_80801CD4_bsbansack.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/sack/func_80801D20_bsbansack.s")

s32 bsbansack_entrypoint_9(s32 arg0) {
    extern s32 D_80801EA0_bsbansack[];
    return ((s32 *)&D_80801EA0_bsbansack)[arg0];
}
