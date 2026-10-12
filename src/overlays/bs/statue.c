#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/statue/func_80800000_bsstatue.s")

/* extern */

f32 func_80800050_bsstatue(s32 arg0) {
    s32 func_800CEA84(s32);
    return (f32) func_800CEA84(2);
}

void func_80800078_bsstatue(s32 arg0)
{
    func_800CEAD0(0x2);
}

void func_8080009C_bsstatue(s32 arg0)
{
    func_800CEAA8(0x2);
}

/* extern */

void func_808000C0_bsstatue(s32 arg0, f32 arg1) {
    void func_800CE88C(s32, s32);
    void func_800CE8D8(s32, f32, s32);
    func_800CE8D8(2, arg1, (s32) arg1);
    func_800CE88C(2, 1);
}

/* extern */

s32 func_80800104_bsstatue(void *arg0) {
    s32 func_8001211C();
    return func_8001211C() == (*(s32 *)((s8 *)(arg0) + (0x168)));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/statue/func_80800130_bsstatue.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/statue/func_808001FC_bsstatue.s")

/* extern */

void bsstatue_entrypoint_0(s32 arg0) {
    s32 baflag_set(s32, s32);
    if (func_80800050_bsstatue(arg0) <= 1.0f) {
        baflag_set(arg0, 0x3F);
    }
}

/* extern */

void bsstatue_entrypoint_1(s32 arg0) {
    func_808000C0_bsstatue(arg0, 75.0f);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/statue/func_808003B4_bsstatue.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/statue/func_80800474_bsstatue.s")

/* extern */

void func_808004B4_bsstatue(s32 arg0) {
    s32 _badrone_entrypoint_31(s32);
    s32 _bsdrone_entrypoint_0(s32);
    s32 func_80800000_bsstatue(s32, s32);
    s32 func_808001FC_bsstatue();
    func_808001FC_bsstatue();
    _bsdrone_entrypoint_0(arg0);
    if (_badrone_entrypoint_31(arg0) != 0) {
        func_80800000_bsstatue(arg0, 0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/statue/func_808004F4_bsstatue.s")

s32 bsstatue_entrypoint_2(s32 arg0) {
    extern s32 D_808015A0_bsstatue[];
    return ((s32 *)&D_808015A0_bsstatue)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/statue/func_8080054C_bsstatue.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/statue/func_80800790_bsstatue.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/statue/func_808007D4_bsstatue.s")

/* extern */

void func_8080081C_bsstatue(void *arg0) {
    s32 func_808001FC_bsstatue();
    s32 func_8080054C_bsstatue(void *, s32);
    func_808001FC_bsstatue();
    (*(s8 *)((s8 *)(arg0) + (0x15C))) = 0;
    func_8080054C_bsstatue(arg0, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/statue/func_8080084C_bsstatue.s")

s32 bsstatue_entrypoint_3(s32 arg0) {
    extern s32 D_808015B0_bsstatue[];
    return ((s32 *)&D_808015B0_bsstatue)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/statue/func_808009C0_bsstatue.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/statue/func_80800A24_bsstatue.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/statue/func_80800AA8_bsstatue.s")

s32 bsstatue_entrypoint_4(s32 arg0) {
    extern s32 D_808015C0_bsstatue[];
    return ((s32 *)&D_808015C0_bsstatue)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/statue/func_80800BEC_bsstatue.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/statue/func_80800C64_bsstatue.s")

/* extern */

void func_80800C98_bsstatue(s32 arg0) {
    s32 _bsrest_entrypoint_16(s32);
    s32 func_80800000_bsstatue(s32, s32);
    s32 func_808001FC_bsstatue();
    func_808001FC_bsstatue();
    _bsrest_entrypoint_16(arg0);
    func_80800000_bsstatue(arg0, 0);
}

/* extern */

void func_80800CCC_bsstatue(s32 arg0) {
    s32 _bsrest_entrypoint_13(s32);
    s32 bs_setState(s32, s32);
    s32 _bsrest_entrypoint_20();
    s32 var_a1;
    s32 sp1C;

    sp1C = 0;
    var_a1 = sp1C;
    if (_bsrest_entrypoint_20() != 0) {
        var_a1 = _bsrest_entrypoint_13(arg0);
    }
    bs_setState(arg0, var_a1);
}

s32 bsstatue_entrypoint_5(s32 arg0) {
    extern s32 D_808015D0_bsstatue[];
    return ((s32 *)&D_808015D0_bsstatue)[arg0];
}

/* extern */

void func_80800D20_bsstatue(void *arg0) {
    s32 func_80099A58(void *);
    s32 func_8009E6EC();
    s32 func_8009E830(void *, s32);
    s32 func_808003B4_bsstatue(void *);
    if (func_8009E6EC() == 0x81) {
        if (func_80099A58(arg0) == 0x11E8) {
            (*(s32 *)((s8 *)(arg0) + (0x164))) = (s32) ((*(s32 *)((s8 *)(arg0) + (0x164))) + 1);
        }
        func_8009E830(arg0, 2);
        return;
    }
    func_808003B4_bsstatue(arg0);
}

/* extern */

void func_80800D84_bsstatue(s32 arg0) {
    s32 baflag_set(s32, s32);
    s32 func_8009EBD0();
    s32 func_800A05DC();
    func_800A05DC();
    func_8009EBD0();
    baflag_set(arg0, 0x40);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/statue/func_80800DB8_bsstatue.s")

void func_80800EAC_bsstatue(s32 arg0)
{
    func_8008E95C();
    func_80800130_bsstatue(arg0);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/statue/func_80800ED4_bsstatue.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/statue/func_80800F3C_bsstatue.s")

s32 bsstatue_entrypoint_6(s32 arg0) {
    extern s32 D_808015E0_bsstatue[];
    return ((s32 *)&D_808015E0_bsstatue)[arg0];
}

void func_80800FCC_bsstatue()
{
    func_80800130_bsstatue();
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/statue/func_80800FEC_bsstatue.s")

/* extern */

void func_80801060_bsstatue(s32 arg0) {
    s32 baanim_isAt(s32, s32);
    s32 func_8080147C_bsstatue();
    func_8080147C_bsstatue();
    if (baanim_isAt(arg0, 0x3F666666) != 0) {
        func_80800D84_bsstatue(arg0);
    }
}

s32 bsstatue_entrypoint_7(s32 arg0) {
    extern s32 D_808015F0_bsstatue[];
    return ((s32 *)&D_808015F0_bsstatue)[arg0];
}

void func_808010B4_bsstatue()
{
    func_80800130_bsstatue();
}

void func_808010D4_bsstatue(register void *arg0) {
    void baphysics_set_target_horizontal_velocity(void *, f32);
    s32 baanim_playForDuration_loopSmooth(void *, s32, s32);
    s32 func_8009FFD8(void *, s32, s32, s32, s32);
    s32 func_808001FC_bsstatue();
    s32 yaw_setVelocityBounded(void *, s32, s32);

    func_808001FC_bsstatue(arg0);
    baanim_playForDuration_loopSmooth(arg0, 0x1EE, 0x40D00000);
    func_8009FFD8(arg0, 1, 3, 1, 2);
    yaw_setVelocityBounded(arg0, 0x43960000, 0x40600000);
    baphysics_set_target_horizontal_velocity(arg0, 0.0f);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/statue/func_80801144_bsstatue.s")

s32 bsstatue_entrypoint_8(s32 arg0) {
    extern s32 D_80801600_bsstatue[];
    return ((s32 *)&D_80801600_bsstatue)[arg0];
}

void func_80801218_bsstatue()
{
    func_80800130_bsstatue();
}

/* extern */

void func_80801238_bsstatue(void *arg0) {
    s32 baanim_playForDuration_loopSmooth(void *, s32, s32);
    s32 baanim_setDurationRange(void *, s32, s32);
    s32 func_8008C9F0(void *, s32, s32, s32, f32);
    s32 func_8008CA30(void *, s32);
    s32 func_8009FFD8(void *, s32, s32, s32, s32);
    s32 func_808001FC_bsstatue();
    s32 yaw_setVelocityBounded(void *, s32, s32);
    func_808001FC_bsstatue();
    baanim_playForDuration_loopSmooth(arg0, 0x1E5, 0x3FB0A3D7);
    func_8009FFD8(arg0, 2, 3, 1, 2);
    yaw_setVelocityBounded(arg0, 0x43960000, 0x40600000);
    baanim_setDurationRange(arg0, 0x3E99999A, 0x40800000);
    func_8008C9F0(arg0, 0x42C80000, 0x44228000, 0x40000000, 0.9f);
    func_8008CA30(arg0, 0x3F800000);
    (*(s32 *)((s8 *)(arg0) + (0x160))) = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/statue/func_808012E8_bsstatue.s")

s32 bsstatue_entrypoint_9(s32 arg0) {
    extern s32 D_80801610_bsstatue[];
    return ((s32 *)&D_80801610_bsstatue)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/statue/func_8080147C_bsstatue.s")
